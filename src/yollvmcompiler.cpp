#include "yolang.h"

#include "llvm/Analysis/Passes.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/MCJIT.h"
#include "llvm/ExecutionEngine/SectionMemoryManager.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/Host.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Target/TargetLibraryInfo.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/DynamicLibrary.h"

using namespace llvm;

static bool llvmInitialized = false;

YoLLVMCompiler::YoLLVMCompiler(YoProgCompiler * p)
{
	progCompiler = p;
	mainFunc = NULL;
	error = ERROR_NOTHING;
	context = NULL;
	// builder = NULL;
	// module = NULL;
	// executionEngine = NULL;
	// funcPassManager = NULL;
}

YoLLVMCompiler::~YoLLVMCompiler()
{
	YO_ASSERT(!context);
	progCompiler = NULL;
}

void YoLLVMCompiler::resetError()
{
	error = ERROR_NOTHING;
	errorMsg = "";
}

void YoLLVMCompiler::setError(Error err)
{
	setError(err, "");
}

void YoLLVMCompiler::setError(Error err, const char * msg, ...)
{
	va_list va;
	va_start(va, msg);
	const size_t BUF_SIZE = 1024 * 10;
	char * buf = new char[BUF_SIZE];
	YO_ASSERT(buf);
	vsprintf_s(buf, BUF_SIZE, msg, va);
	setError(err, std::string(buf));
	delete[] buf;
	va_end(va);
}

void YoLLVMCompiler::setError(Error err, const std::string& msg)
{
	// YO_DEBUG_BREAK;
	if (error != ERROR_NOTHING) {
		YO_ASSERT(false);
		return;
	}
	error = err;
	errorMsg = msg;
}

bool YoLLVMCompiler::isError() const
{
	return error != ERROR_NOTHING;
}

/* void YoLLVMCompiler::setExternFuncs(const std::map<std::string, void*>& p_externFuncs)
{
	externFuncs = p_externFuncs;
} */

bool YoLLVMCompiler::run(EBuildType buildType)
{
	if (progCompiler->isError()) {
		setError(ERROR_IN_PROGCOMPILER, "Error in prog compiler");
		return false;
	}

	if (!llvmInitialized) {
		llvmInitialized = true;
		InitializeNativeTarget();
		InitializeNativeTargetAsmPrinter();
		InitializeNativeTargetAsmParser();
	}
	
	context = &getGlobalContext();
	
	ModuleParams module;
	// module.progModule = progModule;
	module.name = "YO jit module"; // progModule->name;

	std::unique_ptr<Module> owner = make_unique<Module>(module.name.c_str(), *context);
	module.llvmModule = owner.get();

#ifdef _WIN32
	std::string triple = llvm::sys::getProcessTriple();
	module.llvmModule->setTargetTriple(triple + "-elf");
#endif

	std::string errStr;
	module.llvmExecutionEngine =
		EngineBuilder(std::move(owner))
		.setErrorStr(&errStr)
		.setMCJITMemoryManager(llvm::make_unique<SectionMemoryManager>())
		.create();

	if (!module.llvmExecutionEngine) {
		setError(ERROR_UNREACHABLE, "Could not create ExecutionEngine: %s", errStr.c_str());
		return false;
	}
	// module.llvmExecutionEngine->DisableSymbolSearching();

	FunctionPassManager FPM(module.llvmModule);

	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	module.llvmModule->setDataLayout(module.llvmExecutionEngine->getDataLayout());
	FPM.add(new DataLayoutPass());
	FPM.add(new TargetLibraryInfo(Triple(module.llvmModule->getTargetTriple())));
	if (buildType == BUILD_RELEASE) {
		// Provide basic AliasAnalysis support for GVN.
		FPM.add(createBasicAliasAnalysisPass());
		// Do simple "peephole" optimizations and bit-twiddling optzns.
		FPM.add(createInstructionCombiningPass());
		// Reassociate expressions.
		FPM.add(createReassociatePass());
		// Eliminate Common SubExpressions.
		FPM.add(createGVNPass());
		// Simplify the control flow graph (deleting unreachable blocks, etc).
		FPM.add(createCFGSimplificationPass());
	}
	FPM.doInitialization();

	// Set the global so the code gen can use this.
	module.llvmFPM = &FPM;

	// main
	for (int i = (int)progCompiler->modules.size() - 1; i >= 0; i--) {
		YoProgCompiler::Module * progModule = progCompiler->modules[i];
		module.progModule = progModule;
		if (!compileModule(&module)) {
			YO_ASSERT(isError());
			module.llvmModule->dump();
			context = NULL;
			return false;
		}
	}
	
	SmallVector<char, 1000> buf;
	raw_svector_ostream OS(buf);
	if (verifyModule(*module.llvmModule, &OS)) {
		// setError(ERROR_VERIFY_MODULE, "Error verify module %s", module.llvmModule->getName().str().c_str());
		setError(ERROR_VERIFY_MODULE, OS.str());
		module.llvmModule->dump();
		context = NULL;
		return false;
	}

	module.llvmModule->dump();

	module.llvmExecutionEngine->finalizeObject();
	Function * func = module.llvmModule->getFunction("main");
	if (func) {
		mainFunc = module.llvmExecutionEngine->getPointerToFunction(func);
	}

	context = NULL;
	return true;
}

llvm::Type * YoLLVMCompiler::getType(YoProgCompiler::Type * progType)
{
	if (progType->ext.index >= 0) {
		return types[progType->ext.index];
	}
	Type * type;
	switch (progType->etype) {
	case YoProgCompiler::TYPE_VOID: type = Type::getVoidTy(*context); break;
	case YoProgCompiler::TYPE_BOOL: type = Type::getInt1Ty(*context); break;
	case YoProgCompiler::TYPE_INT8: type = Type::getInt8Ty(*context); break;
	case YoProgCompiler::TYPE_INT16: type = Type::getInt16Ty(*context); break;
	case YoProgCompiler::TYPE_INT32: type = Type::getInt32Ty(*context); break;
	case YoProgCompiler::TYPE_INT64: type = Type::getInt64Ty(*context); break;
	case YoProgCompiler::TYPE_UINT8: type = Type::getInt8Ty(*context); break;
	case YoProgCompiler::TYPE_UINT16: type = Type::getInt16Ty(*context); break;
	case YoProgCompiler::TYPE_UINT32: type = Type::getInt32Ty(*context); break;
	case YoProgCompiler::TYPE_UINT64: type = Type::getInt64Ty(*context); break;
	case YoProgCompiler::TYPE_FLOAT32: type = Type::getFloatTy(*context); break;
	case YoProgCompiler::TYPE_FLOAT64: type = Type::getDoubleTy(*context); break;
	case YoProgCompiler::TYPE_FUNC_NATIVE: return getFuncNativeType(progType);
	case YoProgCompiler::TYPE_FUNC_DATA: return getFuncDataType(progType);

	case YoProgCompiler::TYPE_STRUCT: 
	case YoProgCompiler::TYPE_CLASS:
		return getStructType(progType);

	case YoProgCompiler::TYPE_ARRAY: return getArrayType(progType);
	case YoProgCompiler::TYPE_PTR: return getPtrType(progType);
	case YoProgCompiler::TYPE_REF: 
		return getPtrType(progType);

	case YoProgCompiler::TYPE_MUT: 
	case YoProgCompiler::TYPE_CONST:
		return getType(progCompiler->getSubType(progType));

	default:
		setError(ERROR_UNREACHABLE, "Error type: %d\n", (int)progType->etype);
		return NULL;
	}
	progType->ext.index = types.size();
	types.push_back(type);
	return type;
}

llvm::PointerType * YoLLVMCompiler::getPtrType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_PTR || _progType->etype == YoProgCompiler::TYPE_REF);
	YoProgCompiler::SubType * progType = dynamic_cast<YoProgCompiler::SubType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		PointerType * ptrType = dyn_cast<PointerType>(types[progType->ext.index]);
		YO_ASSERT(ptrType);
		return ptrType;
	}
	Type * type;
	// llvm doesn't support pointer to void
	if (progType->subType->etype != YoProgCompiler::TYPE_VOID) {
		type = getType(progType->subType);
	}
	else {
		type = Type::getInt8Ty(*context);
	}
	YO_ASSERT(type);
	PointerType * ptrType = PointerType::get(type, 0);
	YO_ASSERT(ptrType);
	progType->ext.index = types.size();
	types.push_back(ptrType);
	return ptrType;
}

llvm::FunctionType * YoLLVMCompiler::getFuncNativeType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_FUNC_NATIVE);
	YoProgCompiler::FuncNativeType * progType = dynamic_cast<YoProgCompiler::FuncNativeType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		FunctionType * funcType = dyn_cast<FunctionType>(types[progType->ext.index]);
		YO_ASSERT(funcType);
		return funcType;
	}

	std::vector<Type *> argTypes;
	for (int i = 0; i < (int)progType->args.size(); i++) {
		Type * argType = getType(progType->args[i].type);
		YO_ASSERT(argType);
		argTypes.push_back(argType);
	}
	Type * resType = getType(progType->resType);
	FunctionType * funcType = FunctionType::get(resType, argTypes, progType->isVarArg);
	YO_ASSERT(funcType);
	progType->ext.index = types.size();
	types.push_back(funcType);
	progTypesMap[funcType] = progType;
	return funcType;
}

llvm::StructType * YoLLVMCompiler::getFuncDataType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_FUNC_DATA);
	YoProgCompiler::FuncDataType * progType = dynamic_cast<YoProgCompiler::FuncDataType*>(_progType);
	YO_ASSERT(progType);
	return getStructType(progType);
}

llvm::StructType * YoLLVMCompiler::getStructType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_STRUCT || _progType->etype == YoProgCompiler::TYPE_CLASS
		|| _progType->etype == YoProgCompiler::TYPE_FUNC_DATA);
	YoProgCompiler::StructType * progType = dynamic_cast<YoProgCompiler::StructType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		StructType * structType = dyn_cast<StructType>(types[progType->ext.index]);
		YO_ASSERT(structType);
		return structType;
	}

	std::vector<Type*> elements;
	for (int i = 0; i < (int)progType->types.size(); i++) {
		Type * type = getType(progType->types[i]);
		YO_ASSERT(type);
		elements.push_back(type);
	}
	StructType * structType = StructType::get(*context, elements, progType->isPacked);
	YO_ASSERT(structType);
	progType->ext.index = types.size();
	types.push_back(structType);
	return structType;
}

llvm::ArrayType * YoLLVMCompiler::getArrayType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_ARRAY);
	YoProgCompiler::ArrayType * progType = dynamic_cast<YoProgCompiler::ArrayType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		ArrayType * arrayType = dyn_cast<ArrayType>(types[progType->ext.index]);
		YO_ASSERT(arrayType);
		return arrayType;
	}
	Type * elementType = getType(progType->subType);
	YO_ASSERT(elementType);
	ArrayType * arrayType = ArrayType::get(elementType, progType->size);
	YO_ASSERT(arrayType);
	progType->ext.index = types.size();
	types.push_back(arrayType);
	return arrayType;
}

llvm::Instruction::CastOps YoLLVMCompiler::getCastOp(YoProgCompiler::EOperation eop)
{
	switch (eop) {
	case YoProgCompiler::OP_CAST_TRUNC:		return Instruction::Trunc;
	case YoProgCompiler::OP_CAST_ZERO_EXT:	return Instruction::ZExt;
	case YoProgCompiler::OP_CAST_SIGN_EXT:	return Instruction::SExt;
	case YoProgCompiler::OP_CAST_SI_TO_FP:	return Instruction::SIToFP;
	case YoProgCompiler::OP_CAST_UI_TO_FP:	return Instruction::UIToFP;
	case YoProgCompiler::OP_CAST_FP_TO_SI:	return Instruction::FPToSI;
	case YoProgCompiler::OP_CAST_FP_TO_UI:	return Instruction::FPToUI;
	case YoProgCompiler::OP_CAST_FP_TRUNC:	return Instruction::FPTrunc;
	case YoProgCompiler::OP_CAST_FP_EXT:	return Instruction::FPExt;
	}
	setError(ERROR_UNREACHABLE, "Error cast op: %d", (int)eop);
	return Instruction::Trunc;
}

llvm::Instruction::BinaryOps YoLLVMCompiler::getBinOp(YoProgCompiler::EOperation eop, bool isFloat, bool isSigned)
{
	switch (eop) {
	case YoProgCompiler::OP_BIN_ADD:	
		return isFloat ? Instruction::BinaryOps::FAdd : Instruction::BinaryOps::Add;

	case YoProgCompiler::OP_BIN_SUB:
		return isFloat ? Instruction::BinaryOps::FSub : Instruction::BinaryOps::Sub;

	case YoProgCompiler::OP_BIN_MUL:
		return isFloat ? Instruction::BinaryOps::FMul : Instruction::BinaryOps::Mul;

	case YoProgCompiler::OP_BIN_DIV:
		return isFloat ? Instruction::BinaryOps::FDiv : (isSigned ? Instruction::BinaryOps::SDiv : Instruction::BinaryOps::UDiv);

	case YoProgCompiler::OP_BIN_MOD:
		return isFloat ? Instruction::BinaryOps::FRem : (isSigned ? Instruction::BinaryOps::SRem : Instruction::BinaryOps::URem);

	case YoProgCompiler::OP_BIT_OR:
		YO_ASSERT(!isFloat);
		return Instruction::BinaryOps::Or;

	case YoProgCompiler::OP_BIT_AND:
		YO_ASSERT(!isFloat);
		return Instruction::BinaryOps::And;

	case YoProgCompiler::OP_BIT_XOR:
		YO_ASSERT(!isFloat);
		return Instruction::BinaryOps::Xor;
	}
	setError(ERROR_UNREACHABLE, "Error bin op: %d", (int)eop);
	return Instruction::BinaryOps::Add;
}

llvm::CmpInst::Predicate YoLLVMCompiler::getCmpOp(YoProgCompiler::EOperation eop, bool isFloat, bool isSigned)
{
	switch (eop) {
	case YoProgCompiler::OP_CMP_EQ:
		return isFloat ? CmpInst::Predicate::FCMP_OEQ : CmpInst::Predicate::ICMP_EQ;
	case YoProgCompiler::OP_CMP_NE:
		return isFloat ? CmpInst::Predicate::FCMP_ONE : CmpInst::Predicate::ICMP_NE;
	case YoProgCompiler::OP_CMP_LE:
		return isFloat ? CmpInst::Predicate::FCMP_OLE : (isSigned ? CmpInst::Predicate::ICMP_SLE : CmpInst::Predicate::ICMP_ULE);
	case YoProgCompiler::OP_CMP_GE:
		return isFloat ? CmpInst::Predicate::FCMP_OGE : (isSigned ? CmpInst::Predicate::ICMP_SGE : CmpInst::Predicate::ICMP_UGE);
	case YoProgCompiler::OP_CMP_LT:
		return isFloat ? CmpInst::Predicate::FCMP_OLT : (isSigned ? CmpInst::Predicate::ICMP_SLT : CmpInst::Predicate::ICMP_ULT);
	case YoProgCompiler::OP_CMP_GT:
		return isFloat ? CmpInst::Predicate::FCMP_OGT : (isSigned ? CmpInst::Predicate::ICMP_SGT : CmpInst::Predicate::ICMP_UGT);
	}
	setError(ERROR_UNREACHABLE, "Error compare op: %d", (int)eop);
	return isFloat ? CmpInst::Predicate::FCMP_OEQ : CmpInst::Predicate::ICMP_EQ;
}

bool YoLLVMCompiler::compileModule(ModuleParams * module)
{
	// for (int i = 0; i < (int)progModule->funcs.size(); i++) {
	int i, saveFuncsNumber = (int)funcs.size();
	for (i = (int)module->progModule->funcs.size() - 1; i >= 0; i--) {
		YoProgCompiler::Function * progFunc = module->progModule->funcs[i];
		if (!compileDeclFunc(module, progFunc)) {
			return false;
		}
	}
	for (i = saveFuncsNumber; i < (int)funcs.size(); i++) {
		Function * func = funcs[i];
		YoProgCompiler::Function * progFunc = progFuncs[i];
		if (!compileFuncBody(module, progFunc, func)) {
			return false;
		}
	}
	return true;
}

llvm::AllocaInst * YoLLVMCompiler::allocaVar(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::StackValue * stackValue)
{
	return func->builder->CreateAlloca(getType(stackValue->type), NULL, stackValue->name);
}

llvm::Value * YoLLVMCompiler::compileOp(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	struct Lib {
		static Value * emitStackValuePtr(FuncParams * func, YoProgCompiler::StackValue * progSV)
		{
			Value * ptr;
			if (progSV->initStackValue) {
				ptr = emitStackValuePtr(func, progSV->initStackValue);
				YO_ASSERT(ptr);
				if (progSV->initStructElementIndex >= 0) {
					ptr = func->builder->CreateStructGEP(ptr, progSV->initStructElementIndex);
				}
			}
			else{
				ptr = (*func->stackValues)[progSV->ext.index];
			}
			return ptr;
		}
	};

	int i, bits;
	bool isSigned;
	Value * value, *left, *right, *dstPtr, * srcPtr, * noValue;
	YO_U64 size;
	// YoProgCompiler::Operation * progOps[2];
	std::vector<Type *> argTypes;

	switch (progOp->eop) {
	case YoProgCompiler::OP_CONST_NULL:
		YO_ASSERT(progOp->ops.size() == 0);
		return Constant::getNullValue(getType(progOp->type));

	case YoProgCompiler::OP_VALUE_ZERO:
		YO_ASSERT(progOp->ops.size() == 0);
		return Constant::getNullValue(getType(progOp->type));

	case YoProgCompiler::OP_CONST_INT:
		YO_ASSERT(progOp->ops.size() == 0);
		return ConstantInt::get(getType(progOp->type),
			APInt(progOp->constInt.bits, progOp->constInt.val, progOp->constInt.isSigned));

	case YoProgCompiler::OP_CONST_STRING:
		YO_ASSERT(progOp->ops.size() == 0);
		return func->builder->CreateGlobalStringPtr(progCompiler->getConstStr(progOp->strIndex));

	case YoProgCompiler::OP_CONST_FLOAT:
		YO_ASSERT(progOp->ops.size() == 0);
		return ConstantFP::get(getType(progOp->type), progOp->constFloat.fval);

	case YoProgCompiler::OP_LOGICAL_OR:
	case YoProgCompiler::OP_LOGICAL_AND:
		return compileLogical(func, progScope, progOp);

	case YoProgCompiler::OP_CMP_EQ:
	case YoProgCompiler::OP_CMP_NE:
	case YoProgCompiler::OP_CMP_LE:
	case YoProgCompiler::OP_CMP_GE:
	case YoProgCompiler::OP_CMP_LT:
	case YoProgCompiler::OP_CMP_GT:
		YO_ASSERT(progOp->ops.size() == 2);
		YO_ASSERT(progOp->type && progOp->ops[0]->type && progOp->ops[1]->type);
		YO_ASSERT(progOp->ops[0]->type->etype == progOp->ops[1]->type->etype);
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (left->getType()->isFloatingPointTy()) {
			return func->builder->CreateFCmp(getCmpOp(progOp->eop, true, true), left, right);
		}
		if (left->getType()->isIntegerTy()) {
			return func->builder->CreateICmp(getCmpOp(progOp->eop, false, progOp->ops[0]->type->isSigned()), left, right);
		}
		setError(ERROR_TYPE, "Number required");
		return NULL;

	case YoProgCompiler::OP_BIN_ADD:
	case YoProgCompiler::OP_BIN_SUB:
	case YoProgCompiler::OP_BIN_MUL:
	case YoProgCompiler::OP_BIN_DIV:
	case YoProgCompiler::OP_BIN_MOD:
	case YoProgCompiler::OP_BIT_OR:
	case YoProgCompiler::OP_BIT_AND:
	case YoProgCompiler::OP_BIT_XOR:
		YO_ASSERT(progOp->ops.size() == 2);
		YO_ASSERT(progOp->type && progOp->ops[0]->type && progOp->ops[1]->type);
		YO_ASSERT(progOp->ops[0]->type->etype == progOp->ops[1]->type->etype);
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		return func->builder->CreateBinOp(getBinOp(progOp->eop, progOp->ops[0]->type->isFloat(), progOp->ops[0]->type->isSigned()), left, right);

	case YoProgCompiler::OP_BIN_POWI:
	case YoProgCompiler::OP_BIN_POWF: {
		YO_ASSERT(progOp->ops.size() == 2);
		YO_ASSERT(progOp->type && progOp->ops[0]->type && progOp->ops[1]->type);
		YO_ASSERT(progOp->ops[0]->type->isFloat() && progOp->ops[1]->type->isNumber());
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		Intrinsic::ID id = progOp->eop == YoProgCompiler::OP_BIN_POWF ? Intrinsic::pow : Intrinsic::powi;
		/* if (left->getType()->isIntegerTy()) {
			id = Intrinsic::powi;
		} */
		/* if (left->getType()->isFloatingPointTy()) {
			size = func->module->llvmExecutionEngine->getDataLayout()->getTypeStoreSize(Type::getDoubleTy(*context));
			if (!left->getType()->isDoubleTy()) {
				Instruction::CastOps op = Instruction::FPExt;
				if (size < func->module->llvmExecutionEngine->getDataLayout()->getTypeStoreSize(left->getType())) {
					op = Instruction::FPTrunc;
				}
				left = func->builder->CreateCast(op, left, Type::getDoubleTy(*context));
			}
			if (!right->getType()->isDoubleTy()) {
				Instruction::CastOps op = Instruction::FPExt;
				if (size < func->module->llvmExecutionEngine->getDataLayout()->getTypeStoreSize(right->getType())) {
					op = Instruction::FPTrunc;
				}
				right = func->builder->CreateCast(op, right, Type::getDoubleTy(*context));
			}
		} */
		argTypes.push_back(left->getType());
		// argTypes.push_back(right->getType());
		// Type * argTypes[] = { left->getType(), right->getType() };
		// Type * argTypes[] = { left->getType() };
		Value * args[] = { left, right };
		Function * callFunc = Intrinsic::getDeclaration(func->module->llvmModule, id, argTypes);
		return func->builder->CreateCall(callFunc, args);
	}
	case YoProgCompiler::OP_RETURN:
		if (progOp->ops.size() > 0) {
			YO_ASSERT(progOp->ops.size() == 1);
			value = compileOp(func, progScope, progOp->ops[0]);
			if (!value) {
				YO_ASSERT(isError());
				return NULL;
			}
			return func->builder->CreateRet(value);
		}
		return func->builder->CreateRetVoid();

	case YoProgCompiler::OP_CALL_CLOSURE:
	case YoProgCompiler::OP_CALL_FUNC:
		return compileCall(func, progScope, progOp);

	case YoProgCompiler::OP_STACK_VALUE_PTR:
		for (i = 0; i < (int)progOp->ops.size(); i++) {
			value = compileOp(func, progScope, progOp->ops[i]);
			if (!value) {
				YO_ASSERT(isError());
				return NULL;
			}
		}
		return Lib::emitStackValuePtr(func, progOp->stackValue);
		/* if (progOp->stackValue->initStackValue) {
			YoProgCompiler::StackValue * progSV = progOp->stackValue->initStackValue;
			srcPtr = (*func->stackValues)[progOp->stackValue->initStackValue->ext.index];
			YO_ASSERT(srcPtr);
			if (progOp->stackValue->initStructElementIndex >= 0) {
				return func->builder->CreateStructGEP(srcPtr, progOp->stackValue->initStructElementIndex);
			}
			return srcPtr;
		}
		return (*func->stackValues)[progOp->stackValue->ext.index]; */

	case YoProgCompiler::OP_STRUCT_ELEMENT_PTR:
		YO_ASSERT(progOp->ops.size() == 1);
		srcPtr = compileOp(func, progScope, progOp->ops[0]);
		if (!srcPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		return func->builder->CreateStructGEP(srcPtr, progOp->structElementIndex);

	case YoProgCompiler::OP_ELEMENT_PTR: {
		YO_ASSERT(progOp->ops.size() == 2);
		srcPtr = compileOp(func, progScope, progOp->ops[0]);
		value = compileOp(func, progScope, progOp->ops[1]);
		if (!srcPtr || !value) {
			YO_ASSERT(isError());
			return NULL;
		}
		Value * zero = ConstantInt::get(Type::getInt32Ty(*context), 0);
		Value * args[] = { zero, value };
		return func->builder->CreateInBoundsGEP(srcPtr, args);
	}
	case YoProgCompiler::OP_PTR:
		YO_ASSERT(progOp->ops.size() == 1);
		return compileOp(func, progScope, progOp->ops[0]);

	/*case YoProgCompiler::OP_INDIRECT:
		YO_ASSERT(progOp->ops.size() == 1);
		return compileOp(func, progScope, progOp->ops[0]);*/

	case YoProgCompiler::OP_FUNC:
		YO_ASSERT(progOp->ops.size() == 0);
		return funcs[progOp->func->ext.index];

	case YoProgCompiler::OP_LOAD: {
		YO_ASSERT(progOp->ops.size() == 1);
		YoProgCompiler::Operation * op = progOp->ops[0];
		srcPtr = compileOp(func, progScope, op);
		if (!srcPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (op->eop == YoProgCompiler::OP_STACK_VALUE_PTR) {
			YO_ASSERT(!op->stackValue->initStackValue);
			YO_ASSERT(srcPtr == (*func->stackValues)[op->stackValue->ext.index]);
			if (op->stackValue->isArg && !op->stackValue->isChanged) {
				return (*func->argValues)[op->stackValue->ext.index];
			}
		}
		return func->builder->CreateLoad(srcPtr);
	}

	case YoProgCompiler::OP_STORE_VALUE:
	case YoProgCompiler::OP_STORE_PTR:
		YO_ASSERT(progOp->ops.size() == 2);
		dstPtr = compileOp(func, progScope, progOp->ops[1]);	// dst
		if (progOp->eop == YoProgCompiler::OP_STORE_VALUE || progCompiler->isValueOp(progOp->ops[0])){ // src
			/* if (progOp->ops[0]->eop == YoProgCompiler::OP_VALUE_ZERO) {
				if (progOp->ops[1]->eop == YoProgCompiler::OP_STACK_VALUE_PTR) {
					YoProgCompiler::StackValue * progSV = progOp->ops[1]->stackValue;
					if (progSV->initStackValue && progSV->initStructElementIndex >= 0) {
						return dstPtr;
					}
				}
			} */
			value = compileOp(func, progScope, progOp->ops[0]);	// src
			if (!value || !dstPtr) {
				YO_ASSERT(isError());
				return NULL;
			}
			noValue = func->builder->CreateStore(value, dstPtr);
			return progOp->type ? value : noValue;
		}
		// store from ptr
		srcPtr = compileOp(func, progScope, progOp->ops[0]);	// ptr src
		if (!srcPtr || !dstPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (srcPtr == dstPtr) {
			// return progOp->type ? srcPtr : noValue;
			return srcPtr;
		}
		size = func->module->llvmExecutionEngine->getDataLayout()->getTypeStoreSize(dstPtr->getType()->getContainedType(0));
		if (size > sizeof(void*)*4) {
			noValue = func->builder->CreateMemCpy(dstPtr, srcPtr, size, 1);
			return progOp->type ? srcPtr : noValue;
		}
		value = func->builder->CreateLoad(srcPtr);
		noValue = func->builder->CreateStore(value, dstPtr);
		return progOp->type ? srcPtr : noValue;

	case YoProgCompiler::OP_STACK_VALUE_MEMZERO:
		if (progOp->stackValue->initStackValue) {
			int i = 0;
		}
		dstPtr = (*func->stackValues)[progOp->stackValue->ext.index];
		size = func->module->llvmExecutionEngine->getDataLayout()->getTypeStoreSize(dstPtr->getType()->getContainedType(0));
		return func->builder->CreateMemSet(dstPtr, func->builder->getInt8(0), size, 1);

	case YoProgCompiler::OP_CAST_TRUNC:
	case YoProgCompiler::OP_CAST_ZERO_EXT:
	case YoProgCompiler::OP_CAST_SIGN_EXT:
	case YoProgCompiler::OP_CAST_SI_TO_FP:
	case YoProgCompiler::OP_CAST_UI_TO_FP:
	case YoProgCompiler::OP_CAST_FP_TO_SI:
	case YoProgCompiler::OP_CAST_FP_TO_UI:
	case YoProgCompiler::OP_CAST_FP_TRUNC:
	case YoProgCompiler::OP_CAST_FP_EXT:
		YO_ASSERT(progOp->ops.size() == 1);
		value = compileOp(func, progScope, progOp->ops[0]);
		if (!value) {
			return NULL;
		}
		return func->builder->CreateCast(getCastOp(progOp->eop), value, getType(progOp->type));

	case YoProgCompiler::OP_CAST_PTR:
		YO_ASSERT(progOp->ops.size() == 1);
		value = compileOp(func, progScope, progOp->ops[0]);
		if (!value) {
			return NULL;
		}
		return func->builder->CreateBitCast(value, getType(progOp->type));

	case YoProgCompiler::OP_SIZEOF:
		YO_ASSERT(progOp->ops.size() == 1);
		size = func->module->llvmExecutionEngine->getDataLayout()->getTypeAllocSize(getType(progOp->ops[0]->type));
		if (progCompiler->getIntBits(progOp->type, bits, isSigned)) {
			return ConstantInt::get(Type::getIntNTy(*context, bits), size);
		}
		setError(ERROR_UNREACHABLE, "Error sizeof type: %d\n", (int)progOp->type->etype);
		return NULL;

	case YoProgCompiler::OP_IF:
		return compileIf(func, progScope, progOp);

	default:
		setError(ERROR_UNREACHABLE, "Error prog opcode: %d\n", (int)progOp->eop);
	}
	return NULL;
}

llvm::Value * YoLLVMCompiler::compileLogical(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT((progOp->eop == YoProgCompiler::OP_LOGICAL_OR || progOp->eop == YoProgCompiler::OP_LOGICAL_AND) && progOp->ops.size() == 2);

	BasicBlock * leftBB = BasicBlock::Create(*context, "left");
	BasicBlock * rightBB = BasicBlock::Create(*context, "right");
	BasicBlock * afterBB = BasicBlock::Create(*context, "after");

	BasicBlock * curBB = func->builder->GetInsertBlock();
	if (curBB->size() == 0 || !curBB->back().isTerminator()) {
		func->builder->CreateBr(leftBB);
	}

	leftBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(leftBB);
	Value * left = compileOp(func, progScope, progOp->ops[0]);
	if (!left) {
		YO_ASSERT(isError());
		rightBB->insertInto(func->llvmFunc);
		afterBB->insertInto(func->llvmFunc);
		return NULL;
	}
	if (progOp->eop == YoProgCompiler::OP_LOGICAL_OR) {
		func->builder->CreateCondBr(left, afterBB, rightBB);
	}
	else{
		func->builder->CreateCondBr(left, rightBB, afterBB);
	}
	leftBB = func->builder->GetInsertBlock();
	if (leftBB->size() == 0 || !leftBB->back().isTerminator()) {
		func->builder->CreateBr(afterBB);
	}

	rightBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(rightBB);
	Value * right = compileOp(func, progScope, progOp->ops[1]);
	if (!right) {
		YO_ASSERT(isError());
		afterBB->insertInto(func->llvmFunc);
		return NULL;
	}
	rightBB = func->builder->GetInsertBlock();
	if (rightBB->size() == 0 || !rightBB->back().isTerminator()) {
		func->builder->CreateBr(afterBB);
	}

	afterBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(afterBB);

	PHINode * PN = func->builder->CreatePHI(left->getType(), 2, "iftmp");
	PN->addIncoming(left, leftBB);
	PN->addIncoming(right, rightBB);
	return PN;
}

llvm::Value * YoLLVMCompiler::compileIf(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT(progOp->eop == YoProgCompiler::OP_IF && progOp->ops.size() == 0);

	Value * condition = compileOp(func, progScope, progOp->stmtIf.conditionOp);
	if (!condition) {
		YO_ASSERT(isError());
		return NULL;
	}
	BasicBlock * thenBB = BasicBlock::Create(*context, "then");
	BasicBlock * elseBB = BasicBlock::Create(*context, "else");
	BasicBlock * afterBB = BasicBlock::Create(*context, "after");

	func->builder->CreateCondBr(condition, thenBB, elseBB);

	thenBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(thenBB);
	if (!compileScopeBody(func, progOp->stmtIf.thenScope)) {
		YO_ASSERT(isError());
		elseBB->insertInto(func->llvmFunc);
		afterBB->insertInto(func->llvmFunc);
		return NULL;
	}
	// func->builder->SetInsertPoint(thenBB);
	thenBB = func->builder->GetInsertBlock();
	if (thenBB->size() == 0 || !thenBB->back().isTerminator()) {
		func->builder->CreateBr(afterBB);
	}

	elseBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(elseBB);
	if (progOp->stmtIf.elseScope) {
		if (!compileScopeBody(func, progOp->stmtIf.elseScope)) {
			YO_ASSERT(isError());
			afterBB->insertInto(func->llvmFunc);
			return NULL;
		}
	}
	// func->builder->SetInsertPoint(elseBB);
	elseBB = func->builder->GetInsertBlock();
	if (elseBB->size() == 0 || !elseBB->back().isTerminator()) {
		func->builder->CreateBr(afterBB);
	}

	afterBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(afterBB);
	return Constant::getNullValue(Type::getInt8Ty(*context));

	/*
	PHINode * PN = func->builder->CreatePHI(Type::getInt8Ty(*context), 2, "iftmp");
	PN->addIncoming(func->builder->getInt8(1), thenBB);
	PN->addIncoming(func->builder->getInt8(2), elseBB);
	return PN;
	*/
}

llvm::Value * YoLLVMCompiler::compileCall(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT((progOp->eop == YoProgCompiler::OP_CALL_CLOSURE || progOp->eop == YoProgCompiler::OP_CALL_FUNC) && progOp->ops.size() >= 2);

	// YoProgCompiler::FuncDataType * funcDataType = progOp->call.funcDataType;
	// int numArgs = funcDataType->funcNativeType->argTypes.size();
	bool isClosureCall = progOp->eop == YoProgCompiler::OP_CALL_CLOSURE;
	int extraArgs = isClosureCall ? 1 : progOp->callFunc.extraArgs;
	int i, startArg = progOp->ops.size() - (isClosureCall ? progOp->callClosure.args : progOp->callFunc.args) - extraArgs - 1;

	for (i = 0; i < startArg; i++) {
		Value * arg = compileOp(func, progScope, progOp->ops[i]);
		if (!arg) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	
	std::vector<Value*> args;
	Value * funcAddr = compileOp(func, progScope, progOp->ops[startArg + 0]);
	
	if (extraArgs > 0) {
		YO_ASSERT(extraArgs == 1);
		Value * closureAddr = compileOp(func, progScope, progOp->ops[startArg + 1]);
		args.push_back(closureAddr);
	}

	for (i = startArg + 1 + extraArgs; i < (int)progOp->ops.size(); i++) {
		Value * arg = compileOp(func, progScope, progOp->ops[i]);
		if (!arg) {
			YO_ASSERT(isError());
			return NULL;
		}
		args.push_back(arg);
	}
	return func->builder->CreateCall(funcAddr, args);
}

/*
llvm::Value * YoLLVMCompiler::compileSubFunc(llvm::IRBuilder<> * builder, std::vector<llvm::AllocaInst*>& vars, llvm::Function * func,
	YoProgCompiler::Scope * progScope, YoProgCompiler::Expression * progOp)
{
	YO_ASSERT(progOp->op == YoProgCompiler::OP_SUB_FUNC);
	Function * subFunc = funcs[progOp->func->ext.index];
	Value * temp = vars[progOp->temp->ext.index];
	Value * funcAddr = builder->CreateStructGEP(temp, 0, "func_addr");
	// funcAddr = builder->CreateBitCast(funcAddr, subFunc->getType()->getPointerTo());
	builder->CreateStore(subFunc, funcAddr);

	Value * funcClosurePtr = builder->CreateStructGEP(temp, 1, "func_closure_ptr");
	Value * zero = ConstantInt::get(Type::getInt32Ty(*context), 0);
	// zero = builder->CreateIntToPtr(zero, temp->getType()->getStructElementType(1)->getPointerTo());
	funcClosurePtr = builder->CreateBitCast(funcClosurePtr, zero->getType()->getPointerTo());
	builder->CreateStore(zero, funcClosurePtr);

	return temp;
}
*/

llvm::CallingConv::ID YoLLVMCompiler::getCallingConv(EYoCallingConv conv)
{
	switch (conv) {
	case YO_CALLING_DEFAULT:
	case YO_CALLING_C:
		return CallingConv::C;

	case YO_CALLING_STDCALL:
		return CallingConv::X86_StdCall;
	}
	YO_ASSERT(false);
	return CallingConv::C;
}

llvm::Function * YoLLVMCompiler::compileDeclFunc(ModuleParams * module, YoProgCompiler::Function * progFunc)
{
	switch (progFunc->parserNode->data.func.op) {
	case T_FUNC:
		break;
	case T_EXTERN_FUNC:
		break;
	case T_GET:
		break;
	case T_SET:
		break;
	case T_SUB_FUNC:
		break;
	case T_LAMBDA:
		break;
	default:
		setError(ERROR_UNREACHABLE, "Error func op: %d\n", (int)progFunc->parserNode->data.func.op);
		return NULL;
	}
	FunctionType * ft = getFuncNativeType(progFunc->funcNativeType);
	YO_ASSERT(ft);

	std::string name = progFunc->name;
	if (progFunc->funcNativeType->isExtern) {
		name = "_" + name;
	}
	Function * func = Function::Create(ft, Function::ExternalLinkage, name, module->llvmModule);
	YO_ASSERT(func);
	func->setCallingConv(getCallingConv(progFunc->funcNativeType->conv));
	progFunc->ext.index = funcs.size();
	funcs.push_back(func);
	progFuncs.push_back(progFunc);

	int i = 0;
	Function::arg_iterator ait = func->arg_begin();
	for (; i < (int)progFunc->argNames.size(); ++ait, ++i) {
		ait->setName("#" + progFunc->argNames[i]);
	}

	return func;
}

bool YoLLVMCompiler::compileScopeBody(FuncParams * func, YoProgCompiler::Scope * progScope)
{
	YoProgCompiler::Function * progFunc = progCompiler->getFunction(progScope);
	for (int i = 0; i < (int)progScope->ops.size(); i++){
		YoProgCompiler::Operation * progOp = progScope->ops[i];
		if (!compileOp(func, progFunc, progOp)) {
			YO_ASSERT(isError());
			return false;
		}
	}
	return true;
}

bool YoLLVMCompiler::compileFuncBody(ModuleParams * module, YoProgCompiler::Function * progFunc, llvm::Function * func)
{
	if (progFunc->funcNativeType->isExtern && progFunc->externFunc) {
		// YO_ASSERT(progFunc->externFunc);
		// module->llvmExecutionEngine->addGlobalMapping(func, progFunc->externFunc);
		// llvm::sys::DynamicLibrary::AddSymbol(func->getName(), progFunc->externFunc);
		llvm::sys::DynamicLibrary::AddSymbol(progFunc->name, progFunc->externFunc);
		return true;
	}
	// Create a new basic block to start insertion into.
	BasicBlock * bb = BasicBlock::Create(*context, "entry", func);
	
	IRBuilder<> builder(*context);
	builder.SetInsertPoint(bb);

	std::vector<AllocaInst*> stackValues;
	std::vector<llvm::Value*> argValues;
	
	FuncParams funcParams;
	funcParams.module = module;
	funcParams.builder = &builder;
	funcParams.stackValues = &stackValues;
	funcParams.argValues = &argValues;
	funcParams.llvmFunc = func;

	int i;
	Function::arg_iterator funcAI = func->arg_begin();
	for (i = 0; i < (int)progFunc->stackValues.size(); i++) {
		YoProgCompiler::StackValue * stackValue = progFunc->stackValues[i];
		AllocaInst * allocaInst;
		if (0 && stackValue->initStackValue) {
			YO_ASSERT(stackValue->initStackValue->ext.index >= 0);
			stackValue->ext.index = stackValue->initStackValue->ext.index;
			allocaInst = NULL;
		}
		else{
			allocaInst = allocaVar(&funcParams, progFunc, stackValue);
			if (!allocaInst) {
				return false;
			}
			stackValue->ext.index = i;
			stackValues.push_back(allocaInst);
		}

		if (i < (int)progFunc->funcNativeType->args.size()) {
			YO_ASSERT(stackValue->isArg && allocaInst);
			argValues.push_back(funcAI);
			if (stackValue->isChanged) {
				builder.CreateStore(funcAI, allocaInst);
			}
			++funcAI;
		}
		else{
			YO_ASSERT(!stackValue->isArg);
		}
	}

	for (i = 0; i < (int)progFunc->ops.size(); i++){
		YoProgCompiler::Operation * progOp = progFunc->ops[i];
		if (!compileOp(&funcParams, progFunc, progOp)) {
			YO_ASSERT(isError());
			return false;
		}
	}

	SmallVector<char, 1000> buf;
	raw_svector_ostream OS(buf);
	if (!verifyFunction(*func, &OS)) {
		module->llvmFPM->run(*func);
		return true;
	}
	// setError(ERROR_VERIFY_FUNC, "Error verify function %s", func->getName().str().c_str());
	setError(ERROR_VERIFY_FUNC, OS.str());
	return false;
}