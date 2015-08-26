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

using namespace llvm;

static bool llvmInitialized = false;

YoLLVMCompiler::YoLLVMCompiler(YoProgCompiler * p)
{
	progCompiler = p;
	context = NULL;
	// builder = NULL;
	module = NULL;
	executionEngine = NULL;
	funcPassManager = NULL;
}

YoLLVMCompiler::~YoLLVMCompiler()
{
	YO_ASSERT(!context && !module && !executionEngine && !funcPassManager);
	progCompiler = NULL;
}

bool YoLLVMCompiler::run()
{
	if (!llvmInitialized) {
		llvmInitialized = true;
		InitializeNativeTarget();
		InitializeNativeTargetAsmPrinter();
		InitializeNativeTargetAsmParser();
	}
	
	context = &getGlobalContext();
	// IRBuilder<> b(*context);
	// builder = &b;

	// Make the module, which holds all the code.
	std::unique_ptr<Module> owner = make_unique<Module>("test jit", *context);
	module = owner.get();

	std::string errStr;
	executionEngine =
		EngineBuilder(std::move(owner))
		.setErrorStr(&errStr)
		.setMCJITMemoryManager(llvm::make_unique<SectionMemoryManager>())
		.create();
	if (!executionEngine) {
		fprintf(stderr, "Could not create ExecutionEngine: %s\n", errStr.c_str());
		exit(1);
	}

	FunctionPassManager FPM(module);

	// Set up the optimizer pipeline.  Start with registering info about how the
	// target lays out data structures.
	module->setDataLayout(executionEngine->getDataLayout());
	FPM.add(new DataLayoutPass());
#if 0
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
#endif
	FPM.doInitialization();

	// Set the global so the code gen can use this.
	funcPassManager = &FPM;

	// main
	std::vector<YoProgCompiler::Module*>::iterator it = progCompiler->modules.begin();
	for (; it != progCompiler->modules.end(); ++it) {
		YoProgCompiler::Module * progModule = *it;
		if (!compileModule(progModule)) {
			break;
		}
	}

	module->dump();
	
	context = NULL;
	// builder = NULL;
	module = NULL;
	executionEngine = NULL;
	funcPassManager = NULL;
	return 0;
}

llvm::Type * YoLLVMCompiler::getType(YoProgCompiler::Type * progType)
{
	switch (progType->etype) {
	case YoProgCompiler::TYPE_BOOL: return Type::getInt1Ty(*context);
	case YoProgCompiler::TYPE_INT8: return Type::getInt8Ty(*context);
	case YoProgCompiler::TYPE_INT16: return Type::getInt16Ty(*context);
	case YoProgCompiler::TYPE_INT32: return Type::getInt32Ty(*context);
	case YoProgCompiler::TYPE_INT64: return Type::getInt64Ty(*context);
	case YoProgCompiler::TYPE_UINT8: return Type::getInt8Ty(*context);
	case YoProgCompiler::TYPE_UINT16: return Type::getInt16Ty(*context);
	case YoProgCompiler::TYPE_UINT32: return Type::getInt32Ty(*context);
	case YoProgCompiler::TYPE_UINT64: return Type::getInt64Ty(*context);
	case YoProgCompiler::TYPE_FLOAT32: return Type::getFloatTy(*context);
	case YoProgCompiler::TYPE_FLOAT64: return Type::getDoubleTy(*context);
	}
	fprintf(stderr, "Error type: %d\n", (int)progType->etype);
	YO_ASSERT(false);
	exit(1);
	return NULL;
}

bool YoLLVMCompiler::compileModule(YoProgCompiler::Module * progModule)
{
	std::vector<YoProgCompiler::Function*>::iterator it = progModule->funcs.begin();
	for (; it != progModule->funcs.end(); ++it){
		YoProgCompiler::Function * progFunc = *it;
		if (!compileModuleFunc(progModule, progFunc)) {
			return false;
		}
	}
	return true;
}

llvm::AllocaInst * YoLLVMCompiler::allocaVar(llvm::IRBuilder<> * builder, llvm::Function * func, 
	YoProgCompiler::Scope * progScope, YoProgCompiler::Variable * progVar)
{
	// IRBuilder<> b(&func->getEntryBlock(), func->getEntryBlock().begin());
	// return b.CreateAlloca(getType(progVar->type), NULL, progVar->name);
	return builder->CreateAlloca(getType(progVar->type), NULL, progVar->name);
}

#define LLVM_BIN_OP(intAdd, floatAdd) \
	YO_ASSERT(progExpr->list.size() == 2); \
	YO_ASSERT(progExpr->type && progExpr->list[0]->type && progExpr->list[1]->type); \
	YO_ASSERT(progExpr->list[0]->type->etype == progExpr->list[1]->type->etype); \
	left = compileExpr(builder, vars, func, progScope, progExpr->list[0]); \
	right = compileExpr(builder, vars, func, progScope, progExpr->list[1]); \
	if (!left || !right) { \
		return NULL; \
	} \
	switch (progExpr->type->etype) { \
	case YoProgCompiler::TYPE_INT8: \
	case YoProgCompiler::TYPE_INT16: \
	case YoProgCompiler::TYPE_INT32: \
	case YoProgCompiler::TYPE_INT64: \
	case YoProgCompiler::TYPE_UINT8: \
	case YoProgCompiler::TYPE_UINT16: \
	case YoProgCompiler::TYPE_UINT32: \
	case YoProgCompiler::TYPE_UINT64: \
		return builder->intAdd(left, right); \
	case YoProgCompiler::TYPE_FLOAT32: \
	case YoProgCompiler::TYPE_FLOAT64: \
		return builder->floatAdd(left, right); \
	} \
	YO_ASSERT(false); \
	return NULL

llvm::Value * YoLLVMCompiler::compileExpr(llvm::IRBuilder<> * builder, std::vector<llvm::AllocaInst*>& vars, llvm::Function * func,
	YoProgCompiler::Scope * progScope, YoProgCompiler::Expression * progExpr)
{
	Value * value, *left, *right;
	// bool HasNUW = false, bool HasNSW = false;
	// Instruction::BinaryOps binOp;

	switch (progExpr->op) {
	case YoProgCompiler::OP_CONST_INT:
		return ConstantInt::get(getType(progExpr->type), 
			APInt(progExpr->constInt.bits, progExpr->constInt.ival64, progExpr->constInt.isSigned));

	case YoProgCompiler::OP_BIN_ADD:
		LLVM_BIN_OP(CreateAdd, CreateFAdd);

	case YoProgCompiler::OP_RETURN:
		if (progExpr->list.size() > 0) {
			YO_ASSERT(progExpr->list.size() == 1);
			value = compileExpr(builder, vars, func, progScope, progExpr->list[0]);
			if (!value) {
				return NULL;
			}
			return builder->CreateRet(value);
		}
		return builder->CreateRetVoid();

	case YoProgCompiler::OP_READ_LOCAL:
		YO_ASSERT(progExpr->nameAccess.ename == YoProgCompiler::NAME_FUNC_VAR);
		YO_ASSERT(progExpr->nameAccess.upCount == 0);
		return builder->CreateLoad(vars[progExpr->nameAccess.var->index], progExpr->nameAccess.var->name);

	case YoProgCompiler::OP_WRITE_LOCAL:
		YO_ASSERT(progExpr->list.size() == 1);
		value = compileExpr(builder, vars, func, progScope, progExpr->list[0]);
		if (!value) {
			return NULL;
		}
		YO_ASSERT(progExpr->nameAccess.ename == YoProgCompiler::NAME_FUNC_VAR);
		YO_ASSERT(progExpr->nameAccess.upCount == 0);
		return builder->CreateStore(value, vars[progExpr->nameAccess.var->index]);

	default:
		fprintf(stderr, "Error prog opcode: %d\n", (int)progExpr->op);
		YO_ASSERT(false);
		exit(1);
	}
	return NULL;
}

llvm::Function * YoLLVMCompiler::compileModuleFunc(YoProgCompiler::Module * progModule, YoProgCompiler::Function * progFunc)
{
	std::vector<Type *> args;
	if (progFunc->argsNumber > 0) {
		YO_ASSERT(false);
	}
	Type * resType = getType(progFunc->resType);
	FunctionType * ft = FunctionType::get(resType, args, false);
	YO_ASSERT(ft);

	Function * func = Function::Create(ft, Function::ExternalLinkage, progFunc->name, module);
	YO_ASSERT(func);
	
	// Create a new basic block to start insertion into.
	BasicBlock * bb = BasicBlock::Create(*context, "entry", func);
	
	IRBuilder<> builder(*context);
	builder.SetInsertPoint(bb);

	std::vector<AllocaInst*> vars;
	{
		std::vector<YoProgCompiler::Variable*>::iterator it = progFunc->vars.begin();
		for (; it != progFunc->vars.end(); ++it) {
			YoProgCompiler::Variable * var = *it;
			AllocaInst * allocaInst = allocaVar(&builder, func, progFunc, var);
			if (!allocaInst) {
				return NULL;
			}
			vars.push_back(allocaInst);
		}
	}
	{
		std::vector<YoProgCompiler::Expression*>::iterator it = progFunc->ops.begin();
		for (; it != progFunc->ops.end(); ++it){
			YoProgCompiler::Expression * progExpr = *it;
			if (!compileExpr(&builder, vars, func, progFunc, progExpr)) {
				return NULL;
			}
		}
	}
	return func;
}