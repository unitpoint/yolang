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

	YoLLVMCompiler(YoProgCompiler * progCompiler);
	~YoLLVMCompiler();

	bool run();

protected:
	
	YoProgCompiler * progCompiler;

	llvm::LLVMContext * context;
	// llvm::IRBuilder<> * builder;
	llvm::Module * module;
	llvm::ExecutionEngine * executionEngine;
	llvm::FunctionPassManager * funcPassManager;

	llvm::Type * getType(YoProgCompiler::Type*);

	bool compileModule(YoProgCompiler::Module*);
	llvm::Function * compileModuleFunc(YoProgCompiler::Module*, YoProgCompiler::Function*);
	llvm::AllocaInst * allocaVar(llvm::IRBuilder<>*, llvm::Function*, YoProgCompiler::Scope*, YoProgCompiler::Variable*);
	llvm::Value * compileExpr(llvm::IRBuilder<>*, std::vector<llvm::AllocaInst*>& vars, llvm::Function*, YoProgCompiler::Scope*, YoProgCompiler::Expression*);
};

#endif // __YOLLVMCOMPILER_H__
