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
	// const char * filename = "fannkuch.yo";
	const char * filename = "test-llvm.yo";
	// const char * filename = "test-01.yo";
	FILE * f = fopen(filename, "rb");
	if (!f) {
		printf("file %s is not found\n", filename);
		exit(1);
	}
	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);
	char * buf = new char[size + 1 + YO_LEX_MAXFILL];
	if (!buf) {
		printf("error malloc %d bytes\n", size);
		fclose(f);
		exit(1);
	}
	fread(buf, size, 1, f);
	memset(buf + size, 0, 1 + YO_LEX_MAXFILL);
	// buf[size] = '\0';
	fclose(f);

	for(;;){
		YoParser parser(buf, size);
		parser.run();
		if (parser.isError()) {
			parser.dumpError();
			break;
		}
		parser.dump();

		printf("\n======================\n\n");

		YoProgCompiler progCompiler(&parser);
		progCompiler.addSymbol("snprintf", &YoExtern::snprintf);
		progCompiler.addSymbol("printf", &YoExtern::printf);

		progCompiler.run();
		if (progCompiler.isError()) {
			progCompiler.dumpError();
			break;
		}
		progCompiler.dump();

		YoLLVMCompiler::EBuildType buildType = YoLLVMCompiler::BUILD_DEBUG;
		YoLLVMCompiler llvmCompiler(&progCompiler, "Yolang jit compiler", buildType);
		if (llvmCompiler.run()) {
			llvmCompiler.llvmModule->dump();
			llvmCompiler.llvmEE->finalizeObject();
			llvm::Function * llvmFunc = llvmCompiler.llvmModule->getFunction("main");
			if (llvmFunc) {
#if 0
				void * mainFunc = llvmCompiler.llvmEE->getPointerToFunction(llvmFunc);
				void(*func)(void*) = (void(*)(void*))mainFunc;
				func(NULL);
#else
				void * mainFunc = llvmCompiler.llvmEE->getPointerToFunction(llvmFunc);
				double(*func)(void*) = (double(*)(void*))mainFunc;
				double r = func(NULL);
				printf("\nResult: %lf\n", r);
#endif
			}
			else{
				printf("Main function is not found\n");
			}
		}
		if (llvmCompiler.isError()) {
			llvmCompiler.llvmModule->dump();
			printf("\n======================\n%s\n", llvmCompiler.errorMsg.c_str());
			break;
		}

		break;
	}

	delete[] buf;
}

