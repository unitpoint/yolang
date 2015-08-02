#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <malloc.h>
#include "../../../src/yolang.h"

extern int yodebug;

void main()
{
#if YYDEBUG
	yodebug = 1;
#endif

	const char * filename = "test.yo";
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

	YoParserParams parser;
	parser.init(buf, size);
		/*
		// "\n\n"
		// "abc = 35.1 + 7 * 1.2 - null\n"
		// "i = 3 * -abc + 5 * false\n"
		"func fmt.Finder.main() {\n"
		"var pb [5][9]***bool\n"
		"var slist []string\n"
		"var c * char\n"
		"var i [10][]byte\n"
		"var arr [3][]int32 = {{1, 2, 3}, {10, 20, 30}}\n"
		// "MyStruct * pb; fmt.Parser slist; json.Object [100] str\n"
		// "obj->method()\n"
		"obj = A{}; obj = A{1, 2, 3*8}[0].Name; obj = A{X = *&B{Arr = {1, 25}}, B.Z = 1 - 8*2}\n"
		"var x, y, z int32 = *&obj.prop[1], *&obj[1].prop + true * 1.2, 25 + abc\n"
		"var x, y, z int32 = obj.prop[1], obj[1].a.b.c + true * 1.2, 25 + *@abc[23].a.b\n"
		"}\n"
		// "func Reader.get@Count(x int32){}\n"
		// "float32 i = 3 * -abc + 5 * 1.3\n"
		);
		*/
	int i = yoParse(&parser);
	parser.dump();
	parser.shutdown();

	delete[] buf;
}

