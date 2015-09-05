#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "yolang.h"

extern int yodebug;

void main()
{
#if YYDEBUG
	// yodebug = 1;
#endif

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
		int i = parser.run();
		if (parser.isError()) {
			parser.dumpError();
			break;
		}
		parser.dump();

		YoProgCompiler progCompiler(&parser);
		progCompiler.run();
		if (progCompiler.isError()) {
			progCompiler.dumpError();
			break;
		}
		// progCompiler.dump();

		printf("\n======================\n\n");

		YoLLVMCompiler llvmCompiler(&progCompiler);
		if (llvmCompiler.run(YoLLVMCompiler::BUILD_DEBUG)) {
			double(*func)(void*) = (double(*)(void*))(intptr_t)llvmCompiler.mainFunc;
			double r = func(NULL);
			printf("\nResult: %lf\n", r);
		}
		if (llvmCompiler.isError()) {
			printf("\n======================\n%s\n", llvmCompiler.errorMsg.c_str());
			break;
		}

		break;
	}

	delete[] buf;
}

