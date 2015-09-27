#ifndef __YOLLVMCOMPILER_H__
#define __YOLLVMCOMPILER_H__

#include "yodef.h"
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/Module.h"
#include "llvm/PassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/CallingConv.h"

class YoSystem;
class YoProgCompiler;
class YoLLVMCompiler
{
public:

	enum Error
	{
		ERROR_NOTHING,
		ERROR_TYPE,
		ERROR_BREAK_CONTINUE,
		// ERROR_VERIFY_FUNC,
		// ERROR_VERIFY_MODULE,
		ERROR_UNREACHABLE,
		ERROR_IN_PROGCOMPILER,
	};

	enum EBuildType
	{
		BUILD_DEBUG,
		BUILD_RELEASE,
	};

	YoSystem * system;
	YoProgCompiler * progCompiler;
	EBuildType buildType;
	
	std::string llvmModuleName;
	llvm::Module * llvmModule;
	llvm::ExecutionEngine * llvmEE;
	llvm::FunctionPassManager * llvmFPM;

	Error error;
	std::string errorMsg;
	YoParserNode * errorNode;

	YoLLVMCompiler(YoSystem*, YoProgCompiler * progCompiler, const std::string& llvmModuleName, EBuildType);
	~YoLLVMCompiler();

	virtual void initFPM();

	void reset();

	void dumpError();
	void resetError();
	void setError(Error, YoParserNode*);
	void setError(Error, YoParserNode*, const char * msg, ...);
	void setError(Error, YoParserNode*, const std::string& msg);
	bool isError() const;

	bool run();


protected:

	/* struct ModuleParams
	{
		YoProgCompiler::Module * progModule;
		std::string name;
		llvm::Module * llvmModule;
		llvm::ExecutionEngine * llvmExecutionEngine;
		llvm::FunctionPassManager * llvmFPM;
	}; */

	struct FuncParams
	{
		YoProgCompiler::Module * progModule;
		// ModuleParams * module;
		std::vector<llvm::Value*> * globalVars;
		std::vector<llvm::AllocaInst*> * vars;
		std::vector<llvm::Value*> * args;
		llvm::IRBuilder<> * builder;
		llvm::Function * llvmFunc;
	};
	
	llvm::LLVMContext * llvmContext;
	std::vector<llvm::Value*> llvmGlobalVars;
	std::vector<llvm::Function*> llvmFuncs;
	std::vector<YoProgCompiler::Function*> progFuncs;

	std::vector<llvm::Type*> llvmTypes;
	std::map<llvm::Type*, YoProgCompiler::Type*> progTypesMap;
	// llvm::ExecutionEngine * executionEngine;
	// llvm::FunctionPassManager * funcPassManager;

	struct LabelBlock
	{
		std::string label;
		llvm::BasicBlock * block;

		LabelBlock(llvm::BasicBlock * b){ block = b; }
	};
	std::vector<LabelBlock> breakLabels;
	std::vector<LabelBlock> continueLabels;

	struct SwitchBlock
	{
		struct CaseElem
		{
			llvm::BasicBlock * bb;
			llvm::ConstantInt * constIntValue;
			YoProgCompiler::Operation * cmpProgOp;
		};

		std::string label;
		llvm::BasicBlock * condBB;
		std::vector<CaseElem> caseElemList;
		int constIntValues;

		llvm::BasicBlock * bodyBB;
		llvm::BasicBlock * testBB;
		llvm::BasicBlock * defaultBB;
		llvm::BasicBlock * afterBB;
	};
	std::vector<SwitchBlock*> switchBlocks;

	void pushLabelBlock(std::vector<LabelBlock>&, const LabelBlock&, YoParserNode*);
	bool popLabelBlock(std::vector<LabelBlock>&, const LabelBlock&, YoParserNode*);

	void pushSwitchBlock(SwitchBlock*, YoParserNode*);
	bool popSwitchBlock(SwitchBlock*, YoParserNode*);

	llvm::CallingConv::ID getCallingConv(EYoCallingConv);

	llvm::Type * getType(YoProgCompiler::Type*);
	llvm::StructType * getStructType(YoProgCompiler::Type*);
	llvm::ArrayType * getArrayType(YoProgCompiler::Type*);
	llvm::FunctionType * getFuncNativeType(YoProgCompiler::Type*);
	llvm::StructType * getFuncDataType(YoProgCompiler::Type*);
	llvm::PointerType * getPtrType(YoProgCompiler::Type*);
	llvm::Instruction::CastOps getCastOp(YoProgCompiler::EOperation progOp, YoParserNode*);
	llvm::Instruction::BinaryOps getBinOp(YoProgCompiler::EOperation progOp, bool isFloat, bool isSigned, YoParserNode*);
	llvm::CmpInst::Predicate getCmpOp(YoProgCompiler::EOperation progOp, bool isFloat, bool isSigned, YoParserNode*);

	// bool compileModule(YoProgCompiler::Module*);
	llvm::Function * compileDeclFunc(YoProgCompiler::Module*, YoProgCompiler::Function*);
	bool compileFuncBody(YoProgCompiler::Module*, YoProgCompiler::Function*, llvm::Function*);
	bool compileScopeBody(FuncParams*, YoProgCompiler::Scope*);
	llvm::AllocaInst * allocaVar(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Variable*);
	llvm::Value * compileOp(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileIf(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileFor(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileSwitchExpr(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileSwitchLogical(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileCaseExpr(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileCaseLogical(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileDefault(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileFallThrough(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileBreakContinue(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileLogical(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
	llvm::Value * compileCall(FuncParams*, YoProgCompiler::Scope*, YoProgCompiler::Operation*);
};

#endif // __YOLLVMCOMPILER_H__
