#ifndef __YOPARSER_H__
#define __YOPARSER_H__

#include "yodef.h"
#include <vector>

#define YYDEBUG 1
// #define YYERROR_VERBOSE

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm

#define YYSTYPE YoParserStackElement
#define YYLTYPE YoParserLocation

#define YO_LEX_MAXFILL 10

#include "yolang-l.h"
#include "yolang-y.h"

enum EYoParserNodeType {
	YO_NODE_EMPTY,
	YO_NODE_MODULE,
	YO_NODE_IMPORT,
	YO_NODE_NAME,
	YO_NODE_DOTNAME,
	YO_NODE_CONST_INT,
	YO_NODE_CONST_FLOAT,
	YO_NODE_CONST_DOUBLE,
	YO_NODE_ASSIGN,
	YO_NODE_BIN_OP,
	YO_NODE_CONCAT,
	YO_NODE_UNARY_OP,
	YO_NODE_CONST_NULL,
	YO_NODE_CONST_TRUE,
	YO_NODE_CONST_FALSE,
	YO_NODE_SINGLE_QUOTED_STRING,
	YO_NODE_QUOTED_STRING,
	YO_NODE_TYPE_STD_NAME,
	YO_NODE_TYPE_NAME,
	YO_NODE_TYPE_CONST,
	YO_NODE_TYPE_MUTABLE,
	YO_NODE_TYPE_PTR,
	YO_NODE_TYPE_REF,
	YO_NODE_TYPE_CHAN,
	YO_NODE_TYPE_SLICE,
	YO_NODE_TYPE_ARR,
	YO_NODE_TYPE_FUNC,
	YO_NODE_NEW_ARR_EXPS,
	YO_NODE_NEW_OBJ_EXPS,
	YO_NODE_NEW_OBJ_PROPS,
	// YO_NODE_STD_TYPE_PTR,
	YO_NODE_CAST,
	YO_NODE_DECL_VAR,
	YO_NODE_DECL_ARG,
	YO_NODE_DECL_FUNC,
	YO_NODE_LOC,
	YO_NODE_DECL_EXPR_FUNC,
	YO_NODE_DECL_TYPE,
	YO_NODE_TYPE_CONTRACT,
	YO_NODE_TYPE_CONTRACT_FUNC,
	// YO_NODE_STRUCT,
	YO_NODE_TYPE_CLASS,
	YO_NODE_CATCH_ELEM,
	YO_NODE_STMT_CATCH,
	YO_NODE_STMT_RETURN,
	YO_NODE_STMT_IF,
	YO_NODE_ELSEIF,
	// YO_NODE_ELSEIF_LIST,
	YO_NODE_ELSE,
	YO_NODE_CALL,
	YO_NODE_SIZEOF,

	// =========================
	__YO_NODE_DUMMY__
};

struct YoParserNode;

struct YoParserToken
{
	const char * str;
	int len;
	int line;
};

struct YoParserLocation
{
	int first_line;
	int first_column;
	int last_line;
	int last_column;

	YoParserToken token;
};

struct YoParserStackElement
{
	YoParserLocation loc;
	YoParserNode * node;
	YoParserStackElement();
};

class YoParser
{
public:

	enum Error
	{
		ERROR_NOTHING,
		ERROR_SYNTAX,
	};

	struct LexState
	{
		int state;
		int braceCount;
		const char * text;
		LexState * next;
	};
	
	struct LexBrace
	{
		bool braceEnabled;
		LexBrace * next;
	};

	LexState * lexStateStack;

	LexBrace * lexBraceStack;
	bool braceEnabled;

	const char * input;
	// int inputLen;
	const char * limit;
	
	const char * lineStart;
	int line;

	std::vector<const char*> lines;

	int braceCount;
	int state;
	// int condition;
	unsigned char ch;
	int accept;
	const char * cursor;
	const char * text;
	int textLen;
	const char * marker;

	std::vector<YoParserNode*> nodes;
	// int listSize;
	// YoParserNode * list;
	YoParserNode * module;

	Error error;
	std::string errorMsg;
	YoParserLocation errorLoc;
	// const char * errorCursor;
	// const char * errorLineStart;
	int errorLine;
	int errorLinePos;

	YoParser(const char * input);
	YoParser(const char * input, int len);
	~YoParser();

	bool isError() const;
	void dumpError();
	void dumpErrorLine(int line, int pos);
	void dumpErrorLine(const YoParserToken& token);

	int run();
	void dump();

	void setLine(const char*, int line);

	void pushState(int newState, const char * text);
	void popState();

	void pushBrace();
	void popBrace();

	YoParserNode * newNode(EYoParserNodeType type, const YoParserToken& token);
	YoParserNode * newNode(EYoParserNodeType type, YYLTYPE * loc);
	YoParserNode * newLocNode(YYLTYPE * loc);

private:
	
	void init(const char * input);
	void init(const char * input, int len);
};

struct YoParserNode
{
	// YoParserNode * parserNext;

	EYoParserNodeType type;
	YoParserToken token;

	YoParserNode * prev;

	union {
		struct {
			YoParserNode * name;
			YoParserNode * body;
		} module;

		struct {
			YoParserNode * name;
			YoParserNode * path;
		} import;

		struct {
			YO_U64 val;
			YO_BYTE bits;
			bool isSigned;
		} constInt;

		struct {
			// float fval32;
			float fval;
		} constFloat;

		/* struct {
			double fval64;
		} constDouble; */

		// int constOp; // null, true, false
		int typeStdName;

		struct {
			YoParserNode * name;
			YoParserNode * gen;
			YoParserNode * def;
		} typeName;

		struct {
			YoParserNode * type;
		} typeConst;

		struct {
			YoParserNode * type;
		} typeMutable;

		struct {
			YoParserNode * type;
		} typeChan;

		struct {
			YoParserNode * type;
		} typePtr;

		struct {
			YoParserNode * type;
		} typeRef;

		struct {
			YoParserNode * type;
		} typeSlice;

		struct {
			YoParserNode * size;
			YoParserNode * type;
		} typeArr;

		/* struct {
			YoParserNode * node;
		} typeContract; */

		struct {
			YoParserNode * gen;
			YoParserNode * extends;
			YoParserNode * body;
		} typeClass;

		struct {
			YoParserNode * name;
			YoParserNode * type;
		} declType;

		struct {
			bool isMutable;
			YoParserNode * name;
			YoParserNode * type;
		} declVar;

		struct {
			YoParserNode * name;
			YoParserNode * type;
		} declArg;

		struct {
			YoParserNode * expr;
			YoParserNode * type;
		} cast;

		struct {
			YoParserNode * left;
			YoParserNode * right;
			int op;
		} assign;

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
		} sizeOf;

		struct {
			YoParserNode * node;
		} dotName;

		struct {
			YoParserNode * values;
		} concat;

		struct {
			YoParserNode * values;
		} arr;

		struct {
			YoParserNode * name;
			YoParserNode * values;
		} obj;

		struct {
			int op; // func, get, set
			YoParserNode * self;
			YoParserNode * name;
			YoParserNode * args;
			YoParserNode * type;
			YoParserNode * body;
			YoParserNode * end;
		} func;

		struct {
			YoParserNode * name;
			YoParserNode * args;
		} call;

		struct {
			YoParserNode * node;
		} stmtReturn;

		struct {
			YoParserNode * stmt;
			YoParserNode * catchName;
			YoParserNode * catchStmt;
		} stmtCatch;

		struct {
			YoParserNode * ifExpr;
			YoParserNode * thenStmt;
			// YoParserNode * elseIfList;
			YoParserNode * elseStmt;
		} stmtIf;

		struct {
			YoParserNode * node;
		} elseElem;

		struct {
			YoParserNode * expr;
			YoParserNode * node;
		} elseIfElem;

		struct {
			YoParserNode * nodes[2];
		} elseIfList;
	} data;

	// YoParserNode(EYoParserNodeType _type, YoParser * parser);
	// ~YoParserNode();
	// void reset();

	bool isType() const;
};

const char * yoTokenName(int token);
int yoParse(YoParser*);

#endif // __YOPARSER_H__
