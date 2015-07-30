#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <malloc.h>
#include "../../../src/yolang.h"

void main()
{
	YoParserParams parser;
	parser.init(
		// "abc = 35.1 + 7 * 1.2 - null\n"
		// "i = 3 * -abc + 5 * false\n"
		"bool * pb; string[] slist; char [100] str\n"
		"MyStruct * pb; fmt.Parser slist; json.Object [100] str\n"
		"int32 abc = 35.1 + true * 1.2\n"
		// "float32 i = 3 * -abc + 5 * 1.3\n"
		);
	int i = yoParse(&parser);
	parser.dump();
	parser.shutdown();
}

