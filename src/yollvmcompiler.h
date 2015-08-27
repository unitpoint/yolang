#ifndef __YOLLVMCOMPILER_H__
#define __YOLLVMCOMPILER_H__

#include "yodef.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/IR/IRBuilder.h"

class YoProgCompiler;
class YoLLVMCompiler
{
public:

	enum Error
	{
		ERROR_NOTHING,
		ERROR_UNREACHABLE,
		ERROR_IN_PROGCOMPILER,
	};

	YoProgCompiler * progCompiler;

	Error error;
	std::string errorMsg;

	YoLLVMCompiler(YoProgCompiler * progCompiler);
	~YoLLVMCompiler();

	void resetError();
	void setError(Error);
	void setError(Error, const char * msg, ...);
	void setError(Error, const std::string& msg);
	bool isError() const;

	bool run();

protected:

	struct ModuleParams
	{
		YoProgCompiler::Module * progModule;
		std::string name;
		llvm::Module * llvmModule;
		llvm::ExecutionEngine * llvmExecutionEngine;
		llvm::FunctionPassManager * llvmFPM;
	};

	struct FuncParams
	{
		ModuleParams * module;
		std::vector<llvm::AllocaInst*> * stackValues;
		llvm::IRBuilder<> * builder;
		llvm::Function * llvmFunc;
	};
	
	llvm::LLVMContext * context;
	// llvm::IRBuilder<> * builder;
	// llvm::Module * module;
	std::vector<llvm::Function*> funcs;
	std::vector<llvm::Type*> types;
	// llvm::ExecutionEngine * executionEngine;
	// llvm::FunctionPassManager * funcPassManager;

	llvm::Type * getType(YoProgCompiler::Type*);
	llvm::StructType * getStructType(YoProgCompiler::Type*);
	llvm::FunctionType * getFuncNativeType(YoProgCompiler::Type*);
	llvm::StructType * getFuncDataType(YoProgCompiler::Type*);
	llvm::PointerType * getPtrType(YoProgCompiler::Type*);
	llvm::Instruction::CastOps getCastOp(YoProgCompiler::EOperation progOp);
	llvm::Instruction::BinaryOps getBinOp(YoProgCompiler::EOperation progOp, bool isFloat);

	bool compileModule(YoProgCompiler::Module*);
	llvm::Function * compileFunc(ModuleParams*, YoProgCompiler::Function*);
	llvm::AllocaInst * allocaVar(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::StackValue*);
	llvm::Value * compileOp(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileCall(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
};

#endif // __YOLLVMCOMPILER_H__