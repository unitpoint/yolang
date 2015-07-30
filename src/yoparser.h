#ifndef __YOPARSER_H__
#define __YOPARSER_H__

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm
#define YYSTYPE YoParserStackElement

#define YO_LEX_LEN_AHEAD 10

#include "yolang-l.h"
#include "yolang-y.h"

struct YoParserNode;

struct YoParserParams {
	const char * input;
	// int inputLen;
	const char * limit;
	int line;

	int state;
	int condition;
	unsigned char ch;
	int accept;
	const char * cursor;
	const char * text;
	int textLen;
	const char * marker;

	YoParserNode * list;
	YoParserNode * root;

	void init(const char * input);
	void shutdown();
	void dump();
};

enum EYoParserTypeSpec {
	YO_TYPE_SPEC_VALUE,
	YO_TYPE_SPEC_PTR,
	YO_TYPE_SPEC_SLICE,
	YO_TYPE_SPEC_ARRAY
};

enum EYoParserNodeType {
	YO_NODE_EMPTY,
	YO_NODE_NAME,
	YO_NODE_INT,
	YO_NODE_DOUBLE,
	YO_NODE_BIN_OP,
	YO_NODE_UNARY_OP,
	YO_NODE_CONST,
	YO_NODE_TYPE_NAME, // temp
	YO_NODE_TYPE,
	// YO_NODE_STD_TYPE_PTR,
	YO_NODE_DECL_VAR,
	// YO_NODE_STATEMENT,
	// YO_NODE_STATEMENT_LIST,

	// =========================
	__YO_NODE_DUMMY__
};

struct YoParserNode
{
	YoParserNode * parserNext;

	EYoParserNodeType type;

	struct {
		const char * str;
		int len;
		int line;
	} token;

	YoParserNode * prev; // stmt

	union {
		int ival;
		double dval;

		int constOp;

		struct {
			int stdTypeOp;
			YoParserNode * pakage;
			YoParserNode * name;
			int arrSize;
			EYoParserTypeSpec spec;
		} type;

		struct {
			YoParserNode * type;
			YoParserNode * name;
		} declVar;

		struct {
			int op;
			YoParserNode * nodes[2];
		} binOp;

		struct {
			int op;
			YoParserNode * node;
		} unaryOp;

		struct {
			YoParserNode * node;
		} stmt;
	} data;

	YoParserNode(EYoParserNodeType _type, YoParserParams * parser);
	// ~YoParserNode();
	// void reset();
};

struct YoParserStackElement
{
	YoParserNode * node;
	YoParserStackElement();
};

const char * yoTokenName(int token);
int yoParse(YoParserParams*);

#endif // __YOPARSER_H__
