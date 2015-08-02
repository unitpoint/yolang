#ifndef __YOPARSER_H__
#define __YOPARSER_H__

#define YYDEBUG 1
// #define YYERROR_VERBOSE

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm
#define YYSTYPE YoParserStackElement

#define YO_LEX_MAXFILL 10

#include "yolang-l.h"
#include "yolang-y.h"

struct YoParserNode;

struct YoParserParams {

	struct LexState {
		int state;
		int braceCount;
		const char * text;
		LexState * next;
	};
	LexState * lexStateStack;

	const char * input;
	// int inputLen;
	const char * limit;
	
	const char * lineStart;
	int line;

	int braceCount;
	int state;
	// int condition;
	unsigned char ch;
	int accept;
	const char * cursor;
	const char * text;
	int textLen;
	const char * marker;

	int listSize;
	YoParserNode * list;
	YoParserNode * root;

	void init(const char * input);
	void init(const char * input, int len);
	void shutdown();
	void dump();

	void pushState(int newState, const char * text);
	void popState();
};

enum EYoParserNodeType {
	YO_NODE_EMPTY,
	YO_NODE_NAME,
	YO_NODE_DOTNAME,
	YO_NODE_INT,
	YO_NODE_DOUBLE,
	YO_NODE_BIN_OP,
	YO_NODE_UNARY_OP,
	YO_NODE_CONST,
	YO_NODE_SINGLE_QUOTED_STRING,
	YO_NODE_QUOTED_STRING,
	YO_NODE_TYPE_STD_NAME,
	YO_NODE_TYPE_NAME,
	YO_NODE_TYPE_PTR,
	YO_NODE_TYPE_SLICE,
	YO_NODE_TYPE_ARR,
	YO_NODE_TYPE_FUNC,
	YO_NODE_NEW_ARR_EXPS,
	YO_NODE_NEW_OBJ_EXPS,
	YO_NODE_NEW_OBJ_PROPS,
	// YO_NODE_STD_TYPE_PTR,
	YO_NODE_DECL_VAR,
	YO_NODE_DECL_ARG,
	YO_NODE_DECL_FUNC,
	YO_NODE_DECL_TYPE,
	YO_NODE_INTERFACE,
	YO_NODE_INTERFACE_FUNC,
	YO_NODE_CLASS,
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

	YoParserNode * prev;

	union {
		int ival;
		double dval;

		int constOp;
		int typeStdName;

		struct {
			YoParserNode * type;
		} typeName;

		struct {
			YoParserNode * type;
		} typePtr;

		struct {
			YoParserNode * type;
		} typeSlice;

		struct {
			YoParserNode * size;
			YoParserNode * type;
		} typeArr;

		struct {
			YoParserNode * name;
			YoParserNode * type;
		} declType;

		struct {
			YoParserNode * name;
			YoParserNode * type;
		} declVar;

		struct {
			YoParserNode * name;
			YoParserNode * type;
		} declArg;

		struct {
			int op;
			YoParserNode * left;
			YoParserNode * right;
		} binOp;

		struct {
			int op;
			YoParserNode * node;
		} unaryOp;

		struct {
			YoParserNode * node;
		} dotName;

		struct {
			YoParserNode * values;
		} arr;

		struct {
			YoParserNode * name;
			YoParserNode * values;
		} obj;

		struct {
			YoParserNode * self;
			YoParserNode * name;
			YoParserNode * args;
			YoParserNode * type;
			YoParserNode * body;
		} func;

		struct {
			YoParserNode * node;
		} interface;

		struct {
			YoParserNode * node;
		} typeClass;
	} data;

	YoParserNode(EYoParserNodeType _type, YoParserParams * parser);
	// ~YoParserNode();
	// void reset();

	bool isType() const;
};

struct YoParserStackElement
{
	YoParserNode * node;
	YoParserStackElement();
};

const char * yoTokenName(int token);
int yoParse(YoParserParams*);

#endif // __YOPARSER_H__
