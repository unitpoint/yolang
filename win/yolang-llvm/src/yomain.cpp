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
		parser.dump();

		YoProgCompiler progCompiler(&parser);
		progCompiler.run();
		if (progCompiler.isError()) {
			printf("\n======================\n%s\n", progCompiler.errorMsg.c_str());
			if (progCompiler.errorNode) {
				printf("line: %d, token: %s\n", progCompiler.errorNode->token.line, YoProgCompiler::getTokenStr(progCompiler.errorNode).c_str());
			}
			break;
		}

		printf("\n======================\n\n");

		YoLLVMCompiler llvmCompiler(&progCompiler);
		if (llvmCompiler.run()) {
			YO_INT32 (*func)(void*) = (YO_INT32(*)(void*))(intptr_t)llvmCompiler.mainFunc;
			YO_INT32 r = func(NULL);
			printf("\nResult: %d\n", r);
		}
		if (llvmCompiler.isError()) {
			printf("\n======================\n%s\n", llvmCompiler.errorMsg.c_str());
			break;
		}

		break;
	}

	delete[] buf;
}

