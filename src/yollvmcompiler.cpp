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

YoLLVMCompiler::YoLLVMCompiler(YoSystem * s, YoProgCompiler * p, const std::string& p_llvmModuleName, EBuildType p_buildType) : llvmModuleName(p_llvmModuleName)
{
	system = s;
	progCompiler = p;
	buildType = p_buildType;
	error = ERROR_NOTHING;
	llvmModule = NULL;
	llvmEE = NULL;
	llvmFPM = NULL;

	if (!llvmInitialized) {
		llvmInitialized = true;
		InitializeNativeTarget();
		InitializeNativeTargetAsmPrinter();
		InitializeNativeTargetAsmParser();
	}
	llvmContext = &getGlobalContext();
}

YoLLVMCompiler::~YoLLVMCompiler()
{
	reset();
	// YO_ASSERT(!llvmContext);
	progCompiler = NULL;
}

void YoLLVMCompiler::reset()
{
	delete llvmFPM; llvmFPM = NULL;
	if (llvmEE) {
		delete llvmEE; llvmEE = NULL;
		// llvmEE is owner of llvmModule so just reset pointer
		llvmModule = NULL;
	}
	else{
		delete llvmModule; llvmModule = NULL;
	}
	resetError();
}

void YoLLVMCompiler::dumpError()
{
	if (isError()) {
		printf("[err-llvmcompiler-%d] %s\n", (int)error, errorMsg.c_str());
		if (errorNode) {
			errorNode->parser->dumpErrorLine(errorNode->token);
		}
	}
	else{
		printf("<NO ERROR>\n");
	}
}

void YoLLVMCompiler::resetError()
{
	error = ERROR_NOTHING;
	errorMsg = "";
}

void YoLLVMCompiler::setError(Error err, YoParserNode * node)
{
	setError(err, node, "");
}

void YoLLVMCompiler::setError(Error err, YoParserNode * node, const char * msg, ...)
{
	va_list va;
	va_start(va, msg);
	const size_t BUF_SIZE = 1024 * 10;
	char * buf = new char[BUF_SIZE];
	YO_ASSERT(buf);
	vsprintf_s(buf, BUF_SIZE, msg, va);
	setError(err, node, std::string(buf));
	delete[] buf;
	va_end(va);
}

void YoLLVMCompiler::setError(Error err, YoParserNode * node, const std::string& msg)
{
	// YO_DEBUG_BREAK;
	if (error != ERROR_NOTHING) {
		YO_ASSERT(false);
		return;
	}
	error = err;
	errorMsg = msg;
	errorNode = node;
}

bool YoLLVMCompiler::isError() const
{
	return error != ERROR_NOTHING;
}

/* void YoLLVMCompiler::setExternFuncs(const std::map<std::string, void*>& p_externFuncs)
{
	externFuncs = p_externFuncs;
} */

void YoLLVMCompiler::initFPM()
{
	YO_ASSERT(!llvmFPM);
	llvmFPM = new FunctionPassManager(llvmModule);

	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	llvmFPM->add(new DataLayoutPass());
	llvmFPM->add(new TargetLibraryInfo(Triple(llvmModule->getTargetTriple())));
	if (buildType == BUILD_RELEASE) {
		// Provide basic AliasAnalysis support for GVN.
		llvmFPM->add(createBasicAliasAnalysisPass());
		// Promote allocas to registers.
		llvmFPM->add(createPromoteMemoryToRegisterPass());
		// Do simple "peephole" optimizations and bit-twiddling optzns.
		llvmFPM->add(createInstructionCombiningPass());
		// Reassociate expressions.
		llvmFPM->add(createReassociatePass());
		// Eliminate Common SubExpressions.
		llvmFPM->add(createGVNPass());
		// Simplify the control flow graph (deleting unreachable blocks, etc).
		llvmFPM->add(createCFGSimplificationPass());
	}
	llvmFPM->doInitialization();
}

bool YoLLVMCompiler::run()
{
	reset();
	if (progCompiler->isError()) {
		setError(ERROR_IN_PROGCOMPILER, progCompiler->errorNode, "Error in prog compiler");
		return false;
	}

	// ModuleParams module;
	// module.progModule = progModule;
	// module.name = "YO jit module"; // progModule->name;

	std::unique_ptr<Module> owner = make_unique<Module>(llvmModuleName.c_str(), *llvmContext);
	llvmModule = owner.get();

#ifdef _WIN32
	std::string triple = llvm::sys::getProcessTriple();
	llvmModule->setTargetTriple(triple + "-elf");
#endif

	std::string errStr;
	llvmEE =
		EngineBuilder(std::move(owner))
		.setErrorStr(&errStr)
		.setMCJITMemoryManager(llvm::make_unique<SectionMemoryManager>())
		.create();
	if (!llvmEE) {
		setError(ERROR_UNREACHABLE, NULL, "Could not create ExecutionEngine: %s", errStr.c_str());
		return false;
	}
	llvmModule->setDataLayout(llvmEE->getDataLayout());
	// llvmEE->DisableSymbolSearching();

	initFPM();

	int i, j, saveFuncsNumber = (int)llvmFuncs.size();
	YoProgCompiler::Module * progModule;
	YoProgCompiler::Function * progFunc;
	for (i = (int)progCompiler->modules.size() - 1; i >= 0; i--) {
		progModule = progCompiler->modules[i];
		/* if (!compileModule(progModule)) {
			YO_ASSERT(isError());
			// llvmModule->dump();
			llvmContext = NULL;
			return false;
		} */
		for (j = 0; j < (int)progModule->vars.size(); j++) {
			YoProgCompiler::Variable * var = progModule->vars[j];
			YO_ASSERT(var->isGlobal);
			Type * type = getType(var->type);
			if (!type) {
				YO_ASSERT(isError());
				return false;
			}
			std::string name = system->getUniqName((progModule->name + "." + var->name + "-%d").c_str());
			GlobalVariable * globalVar = new GlobalVariable(*llvmModule, type, false,
				GlobalVariable::LinkageTypes::InternalLinkage, Constant::getNullValue(type), name);
			var->ext.index = (int)llvmGlobalVars.size();
			llvmGlobalVars.push_back(globalVar);
		}
		YO_ASSERT(progModule->initFunc);
		// for (j = (int)progModule->funcs.size() - 1; i >= 0; i--) {
		for (j = 0; j < (int)progModule->funcs.size(); j++) {
			progFunc = progModule->funcs[j];
			if (!compileDeclFunc(progModule, progFunc)) {
				return false;
			}
		}
	}
	for (i = saveFuncsNumber; i < (int)llvmFuncs.size(); i++) {
		Function * func = llvmFuncs[i];
		progFunc = progFuncs[i];
		YO_ASSERT(progFunc->ext.index == i);
		if (!compileFuncBody(progModule, progFunc, func)) {
			return false;
		}
	}

	SmallVector<char, 1000> buf;
	raw_svector_ostream OS(buf);
	if (verifyModule(*llvmModule, &OS)) {
		setError(ERROR_UNREACHABLE, NULL, OS.str());
		// llvmModule->dump();
		// llvmContext = NULL;
		return false;
	}

	// llvmModule->dump();
	// llvmEE->finalizeObject();

	// llvmContext = NULL;
	return true;
}

llvm::Type * YoLLVMCompiler::getType(YoProgCompiler::Type * progType)
{
	if (progType->ext.index >= 0) {
		return llvmTypes[progType->ext.index];
	}
	Type * type;
	switch (progType->etype) {
	case YoProgCompiler::TYPE_VOID: type = Type::getVoidTy(*llvmContext); break;
	case YoProgCompiler::TYPE_BOOL: type = Type::getInt1Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_INT8: type = Type::getInt8Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_INT16: type = Type::getInt16Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_INT32: type = Type::getInt32Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_INT64: type = Type::getInt64Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_UINT8: type = Type::getInt8Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_UINT16: type = Type::getInt16Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_UINT32: type = Type::getInt32Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_UINT64: type = Type::getInt64Ty(*llvmContext); break;
	case YoProgCompiler::TYPE_FLOAT32: type = Type::getFloatTy(*llvmContext); break;
	case YoProgCompiler::TYPE_FLOAT64: type = Type::getDoubleTy(*llvmContext); break;
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
		return getType(progCompiler->subType(progType, NULL));

	case YoProgCompiler::TYPE_UNKNOWN_YET:
		setError(ERROR_UNREACHABLE, progType->parserNode, "Unknown type");
		return NULL;

	default:
		setError(ERROR_UNREACHABLE, progType->parserNode, "Unknown type: %d", (int)progType->etype);
		return NULL;
	}
	progType->ext.index = llvmTypes.size();
	llvmTypes.push_back(type);
	return type;
}

llvm::PointerType * YoLLVMCompiler::getPtrType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_PTR || _progType->etype == YoProgCompiler::TYPE_REF);
	YoProgCompiler::SubType * progType = dynamic_cast<YoProgCompiler::SubType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		PointerType * ptrType = dyn_cast<PointerType>(llvmTypes[progType->ext.index]);
		YO_ASSERT(ptrType);
		return ptrType;
	}
	Type * type;
	// llvm doesn't support pointer to void
	if (progType->subType->etype != YoProgCompiler::TYPE_VOID) {
		type = getType(progType->subType);
	}
	else {
		type = Type::getInt8Ty(*llvmContext);
	}
	YO_ASSERT(type);
	PointerType * ptrType = PointerType::get(type, 0);
	YO_ASSERT(ptrType);
	progType->ext.index = llvmTypes.size();
	llvmTypes.push_back(ptrType);
	return ptrType;
}

llvm::FunctionType * YoLLVMCompiler::getFuncNativeType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_FUNC_NATIVE);
	YoProgCompiler::FuncNativeType * progType = dynamic_cast<YoProgCompiler::FuncNativeType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		FunctionType * funcType = dyn_cast<FunctionType>(llvmTypes[progType->ext.index]);
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
	progType->ext.index = llvmTypes.size();
	llvmTypes.push_back(funcType);
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
		StructType * structType = dyn_cast<StructType>(llvmTypes[progType->ext.index]);
		YO_ASSERT(structType);
		return structType;
	}

	std::vector<Type*> elements;
	for (int i = 0; i < (int)progType->types.size(); i++) {
		Type * type = getType(progType->types[i]);
		YO_ASSERT(type);
		elements.push_back(type);
	}
	StructType * structType = StructType::get(*llvmContext, elements, progType->isPacked);
	YO_ASSERT(structType);
	progType->ext.index = llvmTypes.size();
	llvmTypes.push_back(structType);
	return structType;
}

llvm::ArrayType * YoLLVMCompiler::getArrayType(YoProgCompiler::Type * _progType)
{
	YO_ASSERT(_progType->etype == YoProgCompiler::TYPE_ARRAY);
	YoProgCompiler::ArrayType * progType = dynamic_cast<YoProgCompiler::ArrayType*>(_progType);
	YO_ASSERT(progType);
	if (progType->ext.index >= 0) {
		ArrayType * arrayType = dyn_cast<ArrayType>(llvmTypes[progType->ext.index]);
		YO_ASSERT(arrayType);
		return arrayType;
	}
	Type * elementType = getType(progType->subType);
	YO_ASSERT(elementType);
	ArrayType * arrayType = ArrayType::get(elementType, progType->size);
	YO_ASSERT(arrayType);
	progType->ext.index = llvmTypes.size();
	llvmTypes.push_back(arrayType);
	return arrayType;
}

llvm::Instruction::CastOps YoLLVMCompiler::getCastOp(YoProgCompiler::EOperation eop, YoParserNode * node)
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
	case YoProgCompiler::OP_CAST_PTR_TO_INT:return Instruction::PtrToInt;
	case YoProgCompiler::OP_CAST_INT_TO_PTR:return Instruction::IntToPtr;
	}
	setError(ERROR_UNREACHABLE, node, "Error cast op: %d", (int)eop);
	return Instruction::Trunc;
}

llvm::Instruction::BinaryOps YoLLVMCompiler::getBinOp(YoProgCompiler::EOperation eop, bool isFloat, bool isSigned, YoParserNode * node)
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

	case YoProgCompiler::OP_BIT_RSH:
		YO_ASSERT(!isFloat);
		return Instruction::BinaryOps::LShr;

	case YoProgCompiler::OP_BIT_LSH:
		YO_ASSERT(!isFloat);
		return Instruction::BinaryOps::Shl;
	}
	setError(ERROR_UNREACHABLE, node, "Error bin op: %d", (int)eop);
	return Instruction::BinaryOps::Add;
}

llvm::CmpInst::Predicate YoLLVMCompiler::getCmpOp(YoProgCompiler::EOperation eop, bool isFloat, bool isSigned, YoParserNode * node)
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
	setError(ERROR_UNREACHABLE, node, "Error compare op: %d", (int)eop);
	return isFloat ? CmpInst::Predicate::FCMP_OEQ : CmpInst::Predicate::ICMP_EQ;
}

#if 0
bool YoLLVMCompiler::compileModule(YoProgCompiler::Module * progModule)
{
	int i;
	for (i = 0; i < (int)progModule->vars.size(); i++) {
		YoProgCompiler::Variable * var = progModule->vars[i];
		YO_ASSERT(var->isGlobal);
		Type * type = getType(var->type);
		if (!type) {
			YO_ASSERT(isError());
			return false;
		}
		std::string name = system->getUniqName((progModule->name + "." + var->name + "-%d").c_str());
		GlobalVariable * globalVar = new GlobalVariable(*llvmModule, type, false,
			GlobalVariable::LinkageTypes::InternalLinkage, Constant::getNullValue(type), name);
		/* Value * globalVar = llvmModule->getOrInsertGlobal(name, type);
		if (!globalVar) {
			YO_ASSERT(false);
		} */
		var->ext.index = (int)llvmGlobalVars.size();
		llvmGlobalVars.push_back(globalVar);
	}
	YO_ASSERT(progModule->initFunc);
	int saveFuncsNumber = (int)llvmFuncs.size();
	YoProgCompiler::Function * progFunc = progModule->initFunc;
	/* if (!compileDeclFunc(progModule, progFunc)) {
		return false;
	} */
	for (i = (int)progModule->funcs.size() - 1; i >= 0; i--) {
		progFunc = progModule->funcs[i];
		/* if (progFunc == progModule->initFunc) {
			continue;
		} */
		if (!compileDeclFunc(progModule, progFunc)) {
			return false;
		}
	}
	for (i = saveFuncsNumber; i < (int)llvmFuncs.size(); i++) {
		Function * func = llvmFuncs[i];
		progFunc = progFuncs[i];
		YO_ASSERT(progFunc->ext.index == i);
		if (!compileFuncBody(progModule, progFunc, func)) {
			return false;
		}
	}
	return true;
}
#endif

llvm::AllocaInst * YoLLVMCompiler::allocaVar(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Variable * var)
{
	Type * type = getType(var->type);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	return func->builder->CreateAlloca(type, NULL, var->name);
}

llvm::Value * YoLLVMCompiler::compileOp(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	struct Lib {
		static Value * emitVarPtr(FuncParams * func, YoProgCompiler::Variable * progVar)
		{
			Value * ptr;
			if (progVar->isGlobal) {
				YO_ASSERT(progVar->ext.index >= 0);
				ptr = (*func->globalVars)[progVar->ext.index];
			}
			else if (progVar->initVar) {
				ptr = emitVarPtr(func, progVar->initVar);
				YO_ASSERT(ptr);
				if (progVar->initStructElementIndex >= 0) {
					ptr = func->builder->CreateStructGEP(ptr, progVar->initStructElementIndex);
				}
			}
			else{
				YO_ASSERT(progVar->ext.index >= 0);
				if (progVar->isArg && !progVar->isChanged) {
					YO_ASSERT(false);
					// ptr = (*func->args)[progVar->ext.index];
				}
				ptr = (*func->vars)[progVar->ext.index];
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

	case YoProgCompiler::OP_ZERO_VALUE:
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
		YO_ASSERT(progCompiler->baseType(progOp->ops[0]->type) == progCompiler->baseType(progOp->ops[1]->type));
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (left->getType()->isFloatingPointTy()) {
			return func->builder->CreateFCmp(getCmpOp(progOp->eop, true, true, progOp->parserNode), left, right);
		}
		if (left->getType()->isIntegerTy()) {
			return func->builder->CreateICmp(getCmpOp(progOp->eop, false, progOp->ops[0]->type->isSigned(), progOp->parserNode), left, right);
		}
		setError(ERROR_TYPE, progOp->parserNode, "Number required");
		return NULL;

	case YoProgCompiler::OP_BIN_ADD:
	case YoProgCompiler::OP_BIN_SUB:
	case YoProgCompiler::OP_BIN_MUL:
	case YoProgCompiler::OP_BIN_DIV:
	case YoProgCompiler::OP_BIN_MOD:
	case YoProgCompiler::OP_BIT_OR:
	case YoProgCompiler::OP_BIT_AND:
	case YoProgCompiler::OP_BIT_XOR:
	case YoProgCompiler::OP_BIT_RSH:
	case YoProgCompiler::OP_BIT_LSH:
		YO_ASSERT(progOp->ops.size() == 2);
		YO_ASSERT(progOp->type && progOp->ops[0]->type && progOp->ops[1]->type);
		YO_ASSERT(progCompiler->baseType(progOp->ops[0]->type) == progCompiler->baseType(progOp->ops[1]->type));
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		return func->builder->CreateBinOp(getBinOp(progOp->eop, progOp->ops[0]->type->isFloat(), progOp->ops[0]->type->isSigned(), progOp->parserNode), left, right);

	// case YoProgCompiler::OP_BIN_POWI:
	// case YoProgCompiler::OP_BIN_POWF: {
	case YoProgCompiler::OP_BIN_POW: {
		YO_ASSERT(progOp->ops.size() == 2);
		YO_ASSERT(progOp->type && progOp->ops[0]->type && progOp->ops[1]->type);
		YO_ASSERT(progOp->ops[0]->type->isFloat() && progOp->ops[1]->type->isNumber());
		left = compileOp(func, progScope, progOp->ops[0]);
		right = compileOp(func, progScope, progOp->ops[1]);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
		// Intrinsic::ID id = progOp->eop == YoProgCompiler::OP_BIN_POWF ? Intrinsic::pow : Intrinsic::powi;
		Intrinsic::ID id = Intrinsic::pow;
		argTypes.push_back(left->getType());
		Value * args[] = { left, right };
		Function * callFunc = Intrinsic::getDeclaration(llvmModule, id, argTypes);
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

	case YoProgCompiler::OP_VAR:
		for (i = 0; i < (int)progOp->ops.size(); i++) {
			value = compileOp(func, progScope, progOp->ops[i]);
			if (!value) {
				YO_ASSERT(isError());
				return NULL;
			}
		}
		return Lib::emitVarPtr(func, progOp->var);

	case YoProgCompiler::OP_STRUCT_ELEMENT:
		YO_ASSERT(progOp->ops.size() == 1);
		srcPtr = compileOp(func, progScope, progOp->ops[0]);
		if (!srcPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		return func->builder->CreateStructGEP(srcPtr, progOp->structElementIndex);

	case YoProgCompiler::OP_ELEMENT: {
		YO_ASSERT(progOp->ops.size() == 2);
		srcPtr = compileOp(func, progScope, progOp->ops[0]);
		value = compileOp(func, progScope, progOp->ops[1]);
		if (!srcPtr || !value) {
			YO_ASSERT(isError());
			return NULL;
		}
		Value * zero = ConstantInt::get(Type::getInt32Ty(*llvmContext), 0);
		Value * args[] = { zero, value };
		return func->builder->CreateInBoundsGEP(srcPtr, args);
	}
	case YoProgCompiler::OP_FUNC:
		YO_ASSERT(progOp->ops.size() == 0);
		return llvmFuncs[progOp->func->ext.index];

	case YoProgCompiler::OP_LOAD: {
		YO_ASSERT(progOp->ops.size() == 1);
		YoProgCompiler::Operation * op = progOp->ops[0];
		srcPtr = compileOp(func, progScope, op);
		if (!srcPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (op->eop == YoProgCompiler::OP_VAR) {
			YO_ASSERT(!op->var->initVar);
			if (op->var->isGlobal) {
				YO_ASSERT(srcPtr == (*func->globalVars)[op->var->ext.index]);
			}
			else{
				YO_ASSERT(srcPtr == (*func->vars)[op->var->ext.index]);
				if (op->var->isArg && !op->var->isChanged) {
					return (*func->args)[op->var->ext.index];
				}
			}
		}
		return func->builder->CreateLoad(srcPtr);
	}

	case YoProgCompiler::OP_STORE_VALUE:
		YO_ASSERT(progOp->ops.size() == 2);
		value = compileOp(func, progScope, progOp->ops[0]);		// value src
		dstPtr = compileOp(func, progScope, progOp->ops[1]);	// ptr dst
		if (!value || !dstPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		noValue = func->builder->CreateStore(value, dstPtr);
		return dstPtr;

	case YoProgCompiler::OP_STORE_REF:
		YO_ASSERT(progOp->ops.size() == 2);
		srcPtr = compileOp(func, progScope, progOp->ops[0]);	// ptr src
		dstPtr = compileOp(func, progScope, progOp->ops[1]);	// ptr dst
		if (!srcPtr || !dstPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (srcPtr == dstPtr) {
			return dstPtr;
		}
		size = llvmEE->getDataLayout()->getTypeStoreSize(dstPtr->getType()->getContainedType(0));
		if (size > sizeof(void*)*4) {
			noValue = func->builder->CreateMemCpy(dstPtr, srcPtr, size, 1);
			return dstPtr;
		}
		value = func->builder->CreateLoad(srcPtr);
		noValue = func->builder->CreateStore(value, dstPtr);
		return dstPtr;

	case YoProgCompiler::OP_VAR_MEMZERO:
		if (progOp->var->initVar) {
			YO_ASSERT(false);
		}
		if (progOp->var->isGlobal) {
			dstPtr = (*func->globalVars)[progOp->var->ext.index];
		}
		else{
			dstPtr = (*func->vars)[progOp->var->ext.index];
		}
		size = llvmEE->getDataLayout()->getTypeStoreSize(dstPtr->getType()->getContainedType(0));
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
	case YoProgCompiler::OP_CAST_PTR_TO_INT:
	case YoProgCompiler::OP_CAST_INT_TO_PTR:
		YO_ASSERT(progOp->ops.size() == 1);
		value = compileOp(func, progScope, progOp->ops[0]);
		if (!value) {
			return NULL;
		}
		return func->builder->CreateCast(getCastOp(progOp->eop, progOp->parserNode), value, getType(progOp->type));

	case YoProgCompiler::OP_CAST_PTR:
		YO_ASSERT(progOp->ops.size() == 1);
		value = compileOp(func, progScope, progOp->ops[0]);
		if (!value) {
			return NULL;
		}
		return func->builder->CreateBitCast(value, getType(progOp->type));

	case YoProgCompiler::OP_SIZEOF:
		YO_ASSERT(progOp->ops.size() == 1);
		size = llvmEE->getDataLayout()->getTypeAllocSize(getType(progOp->ops[0]->type));
		if (progCompiler->getIntBits(progOp->type, bits, isSigned)) {
			return ConstantInt::get(Type::getIntNTy(*llvmContext, bits), size);
		}
		setError(ERROR_UNREACHABLE, progOp->parserNode, "Error sizeof type: %d", (int)progOp->type->etype);
		return NULL;

	case YoProgCompiler::OP_IF:
		return compileIf(func, progScope, progOp);

	case YoProgCompiler::OP_FOR:
		return compileFor(func, progScope, progOp);

	case YoProgCompiler::OP_BREAK:
	case YoProgCompiler::OP_CONTINUE:
		return compileBreakContinue(func, progScope, progOp);

	case YoProgCompiler::OP_SCOPE:
		YO_ASSERT(progOp->ops.size() == 0);
		if (compileScopeBody(func, progOp->scope)) {
			return Constant::getNullValue(Type::getIntNTy(*llvmContext, 1));
		}
		YO_ASSERT(isError());
		return NULL;

	default:
		setError(ERROR_UNREACHABLE, progOp->parserNode, "Error prog opcode: %d", (int)progOp->eop);
	}
	return NULL;
}

llvm::Value * YoLLVMCompiler::compileLogical(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT((progOp->eop == YoProgCompiler::OP_LOGICAL_OR || progOp->eop == YoProgCompiler::OP_LOGICAL_AND) && progOp->ops.size() == 2);

	BasicBlock * leftBB = BasicBlock::Create(*llvmContext, "left");
	BasicBlock * rightBB = BasicBlock::Create(*llvmContext, "right");
	BasicBlock * afterBB = BasicBlock::Create(*llvmContext, "after");

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
	BasicBlock * thenBB = BasicBlock::Create(*llvmContext, "then");
	BasicBlock * elseBB = BasicBlock::Create(*llvmContext, "else");
	BasicBlock * afterBB = BasicBlock::Create(*llvmContext, "after");

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
	return Constant::getNullValue(Type::getInt8Ty(*llvmContext));
}

llvm::Value * YoLLVMCompiler::compileBreakContinue(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT((progOp->eop == YoProgCompiler::OP_BREAK || progOp->eop == YoProgCompiler::OP_CONTINUE) && progOp->ops.size() == 0);
	bool findLabel = progOp->strIndex >= 0;
	std::string reqLabel = findLabel ? progCompiler->getConstStr(progOp->strIndex) : "";
	std::vector<LabelBlock>& labels = progOp->eop == YoProgCompiler::OP_BREAK ? breakLabels : continueLabels;
	std::vector<LabelBlock>::reverse_iterator it = labels.rbegin();
	for (; it != labels.rend(); ++it) {
		if (!findLabel || it->label == reqLabel) {
			BasicBlock * block = it->block;
			func->builder->CreateBr(block);
			return Constant::getNullValue(Type::getInt8Ty(*llvmContext));
		}
	}
	setError(ERROR_BREAK_CONTINUE, progOp->parserNode, "%s block is not found", progOp->eop == YoProgCompiler::OP_BREAK ? "'Break'" : "'Continue'");
	return NULL;
}

void YoLLVMCompiler::pushLabelBlock(std::vector<LabelBlock>& stack, const LabelBlock& b, YoParserNode*)
{
	stack.push_back(b);
}

bool YoLLVMCompiler::popLabelBlock(std::vector<LabelBlock>& stack, const LabelBlock& b, YoParserNode * node)
{
	if (stack.size() < 1 || stack.back().block != b.block || stack.back().label != b.label) {
		setError(ERROR_UNREACHABLE, node, "Label blocks are broken");
		return false;
	}
	stack.pop_back();
	return true;
}

llvm::Value * YoLLVMCompiler::compileFor(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT(progOp->eop == YoProgCompiler::OP_FOR && progOp->ops.size() == 0);

	BasicBlock * condBB = BasicBlock::Create(*llvmContext, "condition");
	BasicBlock * bodyBB = BasicBlock::Create(*llvmContext, "body");
	BasicBlock * stepBB = BasicBlock::Create(*llvmContext, "step");
	BasicBlock * afterBB = BasicBlock::Create(*llvmContext, "after");

	pushLabelBlock(breakLabels, afterBB, progOp->parserNode);
	pushLabelBlock(continueLabels, stepBB, progOp->parserNode);

	BasicBlock * curBB = func->builder->GetInsertBlock();
	if (curBB->size() == 0 || !curBB->back().isTerminator()) {
		func->builder->CreateBr(condBB);
	}
	condBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(condBB);

	if (progOp->stmtFor.conditionOp) {
		Value * condition = compileOp(func, progScope, progOp->stmtFor.conditionOp);
		if (!condition) {
			YO_ASSERT(isError());
			return NULL;
		}
		func->builder->CreateCondBr(condition, bodyBB, afterBB);
	}
	else{
		func->builder->CreateBr(bodyBB);
	}

	bodyBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(bodyBB);
	if (!compileScopeBody(func, progOp->stmtFor.bodyScope)) {
		YO_ASSERT(isError());
		stepBB->insertInto(func->llvmFunc);
		afterBB->insertInto(func->llvmFunc);
		return NULL;
	}
	// func->builder->SetInsertPoint(thenBB);
	bodyBB = func->builder->GetInsertBlock();
	if (bodyBB->size() == 0 || !bodyBB->back().isTerminator()) {
		func->builder->CreateBr(stepBB);
	}

	stepBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(stepBB);
	if (!compileScopeBody(func, progOp->stmtFor.stepScope)) {
		YO_ASSERT(isError());
		afterBB->insertInto(func->llvmFunc);
		return NULL;
	}
	// func->builder->SetInsertPoint(elseBB);
	stepBB = func->builder->GetInsertBlock();
	if (stepBB->size() == 0 || !stepBB->back().isTerminator()) {
		func->builder->CreateBr(condBB);
	}

	afterBB->insertInto(func->llvmFunc);
	func->builder->SetInsertPoint(afterBB);
	
	if (!popLabelBlock(breakLabels, afterBB, progOp->parserNode) || !popLabelBlock(continueLabels, stepBB, progOp->parserNode)) {
		YO_ASSERT(isError());
		return NULL;
	}

	return Constant::getNullValue(Type::getInt8Ty(*llvmContext));
}

llvm::Value * YoLLVMCompiler::compileCall(FuncParams * func, YoProgCompiler::Scope * progScope, YoProgCompiler::Operation * progOp)
{
	YO_ASSERT((progOp->eop == YoProgCompiler::OP_CALL_CLOSURE || progOp->eop == YoProgCompiler::OP_CALL_FUNC) && progOp->ops.size() >= 1);

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
	
	/* if (extraArgs > 0) {
		YO_ASSERT(extraArgs == 1);
		Value * closureAddr = compileOp(func, progScope, progOp->ops[startArg + 1]);
		args.push_back(closureAddr);
	} */

	for (i = startArg + 1; i < (int)progOp->ops.size(); i++) {
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
	Value * zero = ConstantInt::get(Type::getInt32Ty(*llvmContext), 0);
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

llvm::Function * YoLLVMCompiler::compileDeclFunc(YoProgCompiler::Module * progModule, YoProgCompiler::Function * progFunc)
{
	if (progFunc->parserNode->type != YO_NODE_MODULE) {
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
			setError(ERROR_UNREACHABLE, progFunc->parserNode, "Error func op: %d", (int)progFunc->parserNode->data.func.op);
			return NULL;
		}
	}
	FunctionType * ft = getFuncNativeType(progFunc->funcNativeType);
	YO_ASSERT(ft);

	std::string name = progFunc->name;
	if (progFunc->funcNativeType->isExtern) {
		name = "_" + name;
	}
	Function * func = Function::Create(ft, Function::ExternalLinkage, name, llvmModule);
	YO_ASSERT(func);
	func->setCallingConv(getCallingConv(progFunc->funcNativeType->conv));
	progFunc->ext.index = llvmFuncs.size();
	llvmFuncs.push_back(func);
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
	if (!progScope) {
		return true;
	}
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

bool YoLLVMCompiler::compileFuncBody(YoProgCompiler::Module * progModule, YoProgCompiler::Function * progFunc, llvm::Function * func)
{
	if (progFunc->funcNativeType->isExtern && progFunc->externFunc) {
		// YO_ASSERT(progFunc->externFunc);
		// module->llvmExecutionEngine->addGlobalMapping(func, progFunc->externFunc);
		// llvm::sys::DynamicLibrary::AddSymbol(func->getName(), progFunc->externFunc);
		llvm::sys::DynamicLibrary::AddSymbol(progFunc->name, progFunc->externFunc);
		return true;
	}
	// Create a new basic block to start insertion into.
	BasicBlock * bb = BasicBlock::Create(*llvmContext, "entry", func);
	
	IRBuilder<> builder(*llvmContext);
	builder.SetInsertPoint(bb);

	// std::vector<Value*> globalVars;
	std::vector<AllocaInst*> vars;
	std::vector<Value*> args;
	
	FuncParams funcParams;
	funcParams.progModule = progModule;
	funcParams.builder = &builder;
	funcParams.globalVars = &llvmGlobalVars;
	funcParams.vars = &vars;
	funcParams.args = &args;
	funcParams.llvmFunc = func;

	int i;
	Function::arg_iterator funcAI = func->arg_begin();
	for (i = 0; i < (int)progFunc->vars.size(); i++) {
		YoProgCompiler::Variable * var = progFunc->vars[i];
		if (var->isGlobal) {
			Type * type = getType(var->type);
			if (!type) {
				YO_ASSERT(isError());
				return false;
			}
			std::string name = system->getUniqName((var->name + "-%d").c_str());
			GlobalVariable * globalVar = new GlobalVariable(*llvmModule, type, false, 
				GlobalVariable::LinkageTypes::InternalLinkage, Constant::getNullValue(type), name);
			/* Value * globalVar = llvmModule->getOrInsertGlobal(name, type);
			if (!globalVar) {
				YO_ASSERT(false);
			} */
			var->ext.index = (int)llvmGlobalVars.size();
			llvmGlobalVars.push_back(globalVar);
			continue;
		}
		AllocaInst * allocaInst;
		if (0 && var->initVar) {
			YO_ASSERT(var->initVar->ext.index >= 0);
			var->ext.index = var->initVar->ext.index;
			allocaInst = NULL;
		}
		else{
			allocaInst = allocaVar(&funcParams, progFunc, var);
			if (!allocaInst) {
				YO_ASSERT(isError());
				return false;
			}
			var->ext.index = (int)vars.size();
			vars.push_back(allocaInst);
		}

		if (i < (int)progFunc->funcNativeType->args.size()) {
			YO_ASSERT(var->isArg && allocaInst);
			args.push_back(funcAI);
			if (var->isChanged) {
				builder.CreateStore(funcAI, allocaInst);
			}
			++funcAI;
		}
		else{
			YO_ASSERT(!var->isArg);
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
		llvmFPM->run(*func);
		return true;
	}
	// setError(ERROR_VERIFY_FUNC, "Error verify function %s", func->getName().str().c_str());
	setError(ERROR_UNREACHABLE, progFunc->parserNode, OS.str());
	return false;
}