#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "yolang.h"

extern int yodebug;

// extern "C" __declspec(dllimport) int mysnprintf(char * buf, size_t size, const char * fmt, ...);
// extern "C" int mysnprintf(char * buf, size_t size, const char * fmt, ...);

struct YoExtern
{
	static int snprintf(char * buf, size_t size, const char * fmt, ...)
	{
		va_list va;
		va_start(va, fmt);
		int r = vsnprintf_s(buf, size, size, fmt, va);
		va_end(va);
		return r;
	}

	static void printf(const char * fmt, ...)
	{
		va_list va;
		va_start(va, fmt);
		int r = vprintf(fmt, va);
		va_end(va);
	}
};

void main()
{
	// LLVMLoadLibraryPermanently("c:\\Sources\\yolang\\win\\yolang-llvm\\yolang-ext-dll.Windows.dll");
	// HANDLE h = LoadLibraryA("yolang-ext-dll.Windows.dll");

#if YYDEBUG
	// yodebug = 1;
#endif

	// const char * filename = "../../yo/test_refs.yo";
	const char * filename = "../../yo/test_funcs.yo";
	// const char * filename = "../../yo/test_fannkuch.yo";
	// const char * filename = "test-llvm.yo";
	// const char * filename = "test-01.yo";

	YoSystem system;
	YoProgCompiler progCompiler(&system);
		
	progCompiler.addSymbol("snprintf", &YoExtern::snprintf);
	progCompiler.addSymbol("printf", &YoExtern::printf);

	if (!progCompiler.run(filename)) {
		progCompiler.dumpError();
		return;
	}
	printf("=== PARSERS\n");
	progCompiler.dumpParsers();
	
	printf("=== PROG COMPILER\n");
	progCompiler.dump();

	YoLLVMCompiler::EBuildType buildType = YoLLVMCompiler::BUILD_RELEASE;
	YoLLVMCompiler llvmCompiler(&system, &progCompiler, "Yolang jit compiler", buildType);
	if (llvmCompiler.run()) {
		printf("=== LLVM COMPILER\n");
		llvmCompiler.llvmModule->dump();
		llvmCompiler.llvmEE->finalizeObject();
		llvm::Function * llvmFunc = llvmCompiler.llvmModule->getFunction("@initProgram");
		if (llvmFunc) {
			void * mainFunc = llvmCompiler.llvmEE->getPointerToFunction(llvmFunc);
			void(__cdecl*initProgramFunc)() = (void(__cdecl*)())mainFunc;
			initProgramFunc();
		}
		llvmFunc = llvmCompiler.llvmModule->getFunction("main");
		if (llvmFunc) {
#if 0
			void * mainFunc = llvmCompiler.llvmEE->getPointerToFunction(llvmFunc);
			void(*func)(void*) = (void(*)(void*))mainFunc;
			func(NULL);
#else
			void * mainFunc = llvmCompiler.llvmEE->getPointerToFunction(llvmFunc);
			double(__cdecl*func)(void*) = (double(__cdecl*)(void*))mainFunc;
			double r = func(NULL);
			printf("\nResult: %lf\n", r);
#endif
		}
		else{
			printf("Main function is not found\n");
		}
	}
	else {
		printf("=== LLVM COMPILER\n");
		llvmCompiler.llvmModule->dump();
		llvmCompiler.dumpError();
	}
}

