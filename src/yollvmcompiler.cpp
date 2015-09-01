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
#include "llvm/PassManager.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Support/Host.h"

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

	FunctionPassManager FPM(module.llvmModule);

	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	module.llvmModule->setDataLayout(module.llvmExecutionEngine->getDataLayout());
	FPM.add(new DataLayoutPass());
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
			context = NULL;
			return false;
		}
	}
	
	verifyModule(*module.llvmModule);

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
	case YoProgCompiler::TYPE_STRUCT: return getStructType(progType);
	case YoProgCompiler::TYPE_ARRAY: return getArrayType(progType);
	case YoProgCompiler::TYPE_PTR: return getPtrType(progType);
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
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_PTR);
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
	for (int i = 0; i < (int)progType->argTypes.size(); i++) {
		Type * argType = getType(progType->argTypes[i]);
		YO_ASSERT(argType);
		argTypes.push_back(argType);
	}
	Type * resType = getType(progType->resType);
	FunctionType * funcType = FunctionType::get(resType, argTypes, false);
	YO_ASSERT(funcType);
	progType->ext.index = types.size();
	types.push_back(funcType);
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
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_STRUCT || _progType->etype == YoProgCompiler::TYPE_FUNC_DATA);
	YoProgCompiler::StructType * progType = dynamic_cast<YoProgCompiler::StructType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		StructType * structType = dyn_cast<StructType>(types[progType->ext.index]);
		YO_ASSERT(structType);
		return structType;
	}

	std::vector<Type*> elements;
	for (int i = 0; i < (int)progType->elements.size(); i++) {
		Type * type = getType(progType->elements[i]);
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

llvm::Instruction::BinaryOps YoLLVMCompiler::getBinOp(YoProgCompiler::EOperation eop, bool isFloat)
{
	switch (eop) {
	case YoProgCompiler::OP_BIN_ADD:	
		return isFloat ? Instruction::BinaryOps::FAdd : Instruction::BinaryOps::Add;
	}
	setError(ERROR_UNREACHABLE, "Error bin op: %d", (int)eop);
	return Instruction::BinaryOps::Add;
}

bool YoLLVMCompiler::compileModule(ModuleParams * module)
{
	// for (int i = 0; i < (int)progModule->funcs.size(); i++) {
	for (int i = (int)module->progModule->funcs.size() - 1; i >= 0; i--) {
		YoProgCompiler::Function * progFunc = module->progModule->funcs[i];
		if (!compileFunc(module, progFunc)) {
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
	int i;
	Value * value, *left, *right, *ptr, * ptr2;
	YO_U64 size;

	switch (progOp->eop) {
	case YoProgCompiler::OP_CONST_NULL:
		YO_ASSERT(progOp->ops.size() == 0);
		return Constant::getNullValue(getType(progOp->type));

	case YoProgCompiler::OP_CONST_INT:
		YO_ASSERT(progOp->ops.size() == 0);
		return ConstantInt::get(getType(progOp->type),
			APInt(progOp->constInt.bits, progOp->constInt.val, progOp->constInt.isSigned));

	case YoProgCompiler::OP_CONST_FLOAT:
		YO_ASSERT(progOp->ops.size() == 0);
		return ConstantFP::get(getType(progOp->type), progOp->constFloat.fval);

	case YoProgCompiler::OP_BIN_ADD:
		YO_ASSERT(progOp->ops.size() == 2);
		YO_ASSERT(progOp->type && progOp->ops[0]->type && progOp->ops[1]->type);
		YO_ASSERT(progOp->ops[0]->type->etype == progOp->ops[1]->type->etype);
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		// return builder->CreateBinOp(getBinOp(progOp->op, left->getType()->isFloatingPointTy()), left, right);
		return func->builder->CreateBinOp(getBinOp(progOp->eop, progOp->ops[0]->type->isFloat()), left, right);

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

	case YoProgCompiler::OP_CALL:
		return compileCall(func, progScope, progOp);

	case YoProgCompiler::OP_STACKVALUE_PTR:
		for (i = 0; i < (int)progOp->ops.size(); i++) {
			value = compileOp(func, progScope, progOp->ops[i]);
			if (!value) {
				YO_ASSERT(isError());
				return NULL;
			}
		}
		return (*func->stackValues)[progOp->stackValue->ext.index];

	case YoProgCompiler::OP_STRUCTELEMENT_PTR:
		YO_ASSERT(progOp->ops.size() == 1);
		ptr = compileOp(func, progScope, progOp->ops[0]);
		if (!ptr) {
			YO_ASSERT(isError());
			return NULL;
		}
		return func->builder->CreateStructGEP(ptr, progOp->structElementIndex);

	case YoProgCompiler::OP_ELEMENT_PTR: {
		YO_ASSERT(progOp->ops.size() == 2);
		ptr = compileOp(func, progScope, progOp->ops[0]);
		value = compileOp(func, progScope, progOp->ops[1]);
		if (!ptr || !value) {
			YO_ASSERT(isError());
			return NULL;
		}
		Value * zero = ConstantInt::get(Type::getInt32Ty(*context), 0);
		Value * args[] = { zero, value };
		return func->builder->CreateInBoundsGEP(ptr, args);
	}
	case YoProgCompiler::OP_FUNC:
		YO_ASSERT(progOp->ops.size() == 0);
		return funcs[progOp->func.func->ext.index];

	case YoProgCompiler::OP_LOAD:
		YO_ASSERT(progOp->ops.size() == 1);
		ptr = compileOp(func, progScope, progOp->ops[0]);
		if (!ptr) {
			YO_ASSERT(isError());
			return NULL;
		}
		return func->builder->CreateLoad(ptr);

	case YoProgCompiler::OP_STORE_VALUE:
	case YoProgCompiler::OP_STORE_PTR:
		YO_ASSERT(progOp->ops.size() == 2);
		ptr = compileOp(func, progScope, progOp->ops[1]);	// dst
		if (progOp->eop == YoProgCompiler::OP_STORE_VALUE || progCompiler->isValueOp(progOp->ops[0])){ // src
			value = compileOp(func, progScope, progOp->ops[0]);	// src
			if (!value || !ptr) {
				YO_ASSERT(isError());
				return NULL;
			}
			return func->builder->CreateStore(value, ptr);
		}
		// store from ptr
		ptr2 = compileOp(func, progScope, progOp->ops[0]);	// ptr src
		if (!ptr2 || !ptr) {
			YO_ASSERT(isError());
			return NULL;
		}
		size = func->module->llvmExecutionEngine->getDataLayout()->getTypeStoreSize(ptr->getType()->getContainedType(0));
		if (size > 32) {
			return func->builder->CreateMemCpy(ptr, ptr2, size, 1);
		}
		value = func->builder->CreateLoad(ptr2);
		return func->builder->CreateStore(value, ptr);

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

	default:
		setError(ERROR_UNREACHABLE, "Error prog opcode: %d\n", (int)progOp->eop);
	}
	return NULL;
}

llvm::Value * YoLLVMCompiler::compileCall(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT(progOp->eop == YoProgCompiler::OP_CALL && progOp->ops.size() >= 2);

	YoProgCompiler::FuncDataType * funcDataType = progOp->call.funcDataType;
	// int numArgs = funcDataType->funcNativeType->argTypes.size();
	int i, startArg = progOp->ops.size() - progOp->call.args - 2;

	for (i = 0; i < startArg; i++) {
		Value * arg = compileOp(func, progScope, progOp->ops[i]);
		if (!arg) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	
	Value * funcAddr = compileOp(func, progScope, progOp->ops[startArg + 0]);
	Value * closureAddr = compileOp(func, progScope, progOp->ops[startArg+1]);

	std::vector<Value*> args;
	args.push_back(closureAddr);
	for (i = startArg + 2; i < (int)progOp->ops.size(); i++) {
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

llvm::Function * YoLLVMCompiler::compileFunc(ModuleParams * module, YoProgCompiler::Function * progFunc)
{
	switch (progFunc->parserNode->data.func.op) {
	case T_FUNC:
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
		setError(ERROR_UNREACHABLE, "Error func: %d\n", (int)progFunc->parserNode->data.func.op);
		return NULL;
	}
	FunctionType * ft = getFuncNativeType(progFunc->funcNativeType);
	YO_ASSERT(ft);

	Function * func = Function::Create(ft, Function::ExternalLinkage, progFunc->name, module->llvmModule);
	YO_ASSERT(func);
	progFunc->ext.index = funcs.size();
	funcs.push_back(func);

	int i = 0;
	Function::arg_iterator ait = func->arg_begin();
	for (; i < (int)progFunc->funcNativeType->argNames.size(); ++ait, ++i) {
		ait->setName(progFunc->funcNativeType->argNames[i]);
	}

	// Create a new basic block to start insertion into.
	BasicBlock * bb = BasicBlock::Create(*context, "entry", func);
	
	IRBuilder<> builder(*context);
	builder.SetInsertPoint(bb);

	std::vector<AllocaInst*> stackValues;
	
	FuncParams funcParams;
	funcParams.module = module;
	funcParams.builder = &builder;
	funcParams.stackValues = &stackValues;
	funcParams.llvmFunc = func;

	for (i = 0; i < (int)progFunc->stackValues.size(); i++) {
		YoProgCompiler::StackValue * stackValue = progFunc->stackValues[i];
		AllocaInst * allocaInst = allocaVar(&funcParams, progFunc, stackValue);
		if (!allocaInst) {
			return NULL;
		}
		stackValue->ext.index = i;
		stackValues.push_back(allocaInst);
	}

	for (i = 0; i < (int)progFunc->ops.size(); i++){
		YoProgCompiler::Operation * progOp = progFunc->ops[i];
		if (!compileOp(&funcParams, progFunc, progOp)) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	verifyFunction(*func);
	module->llvmFPM->run(*func);
	return func;
}