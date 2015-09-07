#ifndef __YOLLVMCOMPILER_H__
#define __YOLLVMCOMPILER_H__

#include "yodef.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/CallingConv.h"

class YoProgCompiler;
class YoLLVMCompiler
{
public:

	enum Error
	{
		ERROR_NOTHING,
		ERROR_TYPE,
		ERROR_VERIFY_FUNC,
		ERROR_VERIFY_MODULE,
		ERROR_UNREACHABLE,
		ERROR_IN_PROGCOMPILER,
	};

	enum EBuildType
	{
		BUILD_DEBUG,
		BUILD_RELEASE,
	};

	YoProgCompiler * progCompiler;
	void * mainFunc;

	Error error;
	std::string errorMsg;

	YoLLVMCompiler(YoProgCompiler * progCompiler);
	~YoLLVMCompiler();

	void resetError();
	void setError(Error);
	void setError(Error, const char * msg, ...);
	void setError(Error, const std::string& msg);
	bool isError() const;

	bool run(EBuildType);

	// void setExternFuncs(const std::map<std::string, void*>&);

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
		std::vector<llvm::Value*> * argValues;
		llvm::IRBuilder<> * builder;
		llvm::Function * llvmFunc;
	};
	
	llvm::LLVMContext * context;
	// llvm::IRBuilder<> * builder;
	// llvm::Module * module;
 	// std::map<std::string, void*> externFuncs;
	std::vector<llvm::Function*> funcs;
	std::vector<YoProgCompiler::Function*> progFuncs;

	std::vector<llvm::Type*> types;
	std::map<llvm::Type*, YoProgCompiler::Type*> progTypesMap;
	// llvm::ExecutionEngine * executionEngine;
	// llvm::FunctionPassManager * funcPassManager;

	llvm::CallingConv::ID getCallingConv(EYoCallingConv);

	llvm::Type * getType(YoProgCompiler::Type*);
	llvm::StructType * getStructType(YoProgCompiler::Type*);
	llvm::ArrayType * getArrayType(YoProgCompiler::Type*);
	llvm::FunctionType * getFuncNativeType(YoProgCompiler::Type*);
	llvm::StructType * getFuncDataType(YoProgCompiler::Type*);
	llvm::PointerType * getPtrType(YoProgCompiler::Type*);
	llvm::Instruction::CastOps getCastOp(YoProgCompiler::EOperation progOp);
	llvm::Instruction::BinaryOps getBinOp(YoProgCompiler::EOperation progOp, bool isFloat, bool isSigned);
	llvm::CmpInst::Predicate getCmpOp(YoProgCompiler::EOperation progOp, bool isFloat, bool isSigned);

	bool compileModule(ModuleParams*);
	llvm::Function * compileDeclFunc(ModuleParams*, YoProgCompiler::Function*);
	bool compileFuncBody(ModuleParams*, YoProgCompiler::Function*, llvm::Function*);
	bool compileScopeBody(FuncParams*, YoProgCompiler::Scope*);
	llvm::AllocaInst * allocaVar(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::StackValue*);
	llvm::Value * compileOp(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileIf(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileLogical(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileCall(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
};

#endif // __YOLLVMCOMPILER_H__
