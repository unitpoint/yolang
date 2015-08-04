#include <stdio.h>
#include <string.h>
#include "yolang.h"

// =====================================================================
// =====================================================================
// =====================================================================

// int yywrap() { return 1; }

void yoerror(const char* s) {
	// fprintf(stderr, "Parse error: %s\n", s);
	// exit(1);
}

int yoparse(void*);

int yoParse(YoParserParams * p)
{
	return yoparse(p);
}

const char * yoTokenName(int token)
{
	switch (token) {
	case T_ASSIGN: return "=";
	case T_DECL_ASSIGN: return ":=";
	case T_XORXOR: return "^^";
	case T_OROR: return "||";
	case T_ANDAND: return "&&";
	case T_GT: return ">";
	case T_LT: return "<";
	case T_GE: return ">=";
	case T_LE: return "<=";
	case T_NE: return "!=";
	case T_EQ: return "==";
	case T_CONCAT: return "..";
	case T_XOR: return "^";
	case T_OR: return "|";
	case T_MINUS: return "-";
	case T_PLUS: return "+";
	case T_RSH: return ">>";
	case T_LSH: return "<<";
	case T_AND: return "&";
	case T_MOD: return "%";
	case T_DIV: return "/";
	case T_INDIRECT:
	case T_MUL: return "*";
	case T_POW: return "**";
	case T_ADDR: return "&";
	case T_TILDE: return "~";
	case T_NOT: return "!";
	case T_DOT: return ".";
	case T_INDEX: return "[";
	case T_AT: return "@";
	case T_TRUE: return "true";
	case T_FALSE: return "false";
	case T_NULL: return "null";
	case T_INT8: return "int8";
	case T_INT16: return "int16";
	case T_INT32: return "int32";
	case T_INT64: return "int64";
	case T_UINT8: return "uint8";
	case T_UINT16: return "uint16";
	case T_UINT32: return "uint32";
	case T_UINT64: return "uint64";
	case T_UINTPTR: return "uintptr";
	case T_FLOAT32: return "float32";
	case T_FLOAT64: return "float64";
	case T_STRING: return "string";
	case T_BOOL: return "bool";
	case T_VOID: return "void";
	}
	return "<UNKNOWN>";
}

// =====================================================================
// =====================================================================
// =====================================================================

template <class T>
static bool parseNumber(const char * str, const char * end, T& p_val, int radix)
{
	T val = 0, prev_val = 0;
	const char * start = str;
	// for (; str < end && *str == '0'; str++);
	for (int cur; str < end; str++){
		if (*str >= '0' && *str <= '9'){
			cur = (int)(*str - '0');
		}
		else if (*str >= 'a' && *str <= 'z'){
			cur = 10 + (int)(*str - 'a');
		}
		else if (*str >= 'A' && *str <= 'Z'){
			cur = 10 + (int)(*str - 'A');
		}
		else{
			break;
		}
		if (cur >= radix){
			break;
		}
		val = val * radix + (T)cur;
		if (prev_val > val){
			// p_str = start;
			p_val = 0;
			return false;
		}
		prev_val = val;
	}
	p_val = val;
	// p_str = str;
	// return str > start;
	return str > start && str == end;
}

template <class T>
static bool parseFloatBuf(const char *& p_str, const char * end, T& p_val)
{
	T val = 0;
	const char * str = p_str;
	const char * start = str;
	for (; str < end && *str >= '0' && *str <= '9'; str++){
		val = val * 10 + (*str - '0');
	}
	p_val = val;
	p_str = str;
	return str > start;
}

bool parseFloat(const char * str, const char * end, double& p_val)
{
	const char * start_str = str;
	double dval = 0.0;
	if (*str != '.' && !parseFloatBuf(str, end, dval)) {
		p_val = 0;
		return false;
	}
	if (str < end && *str == '.') {
		double m = 0.1;
		for (str++; str < end && *str >= '0' && *str <= '9'; str++, m *= 0.1) {
			dval += (double)(*str - '0') * m;
		}
		if (str < end && *str == 'e' || *str == 'E') {
			str++;
			bool div = false; // + for default
			if (str < end && *str == '-'){
				div = true;
				str++;
			}
			else if (str < end && *str == '+'){
				// div = false;
				str++;
			}
			int pow;
			if (!parseNumber(str, end, pow, 10)) {
				p_val = 0;
				return false;
			}
			m = 1.0;
			for (int i = 0; i < pow; i++){
				m *= 10.0;
			}
			if (div) {
				dval /= m;
			}
			else {
				dval *= m;
			}
		}
	}
	if (start_str == str || str != end) {
		p_val = 0;
		return false;
	}
	p_val = dval;
	return true;
}

int yoLexNumber(YoParserParams * parser, YYSTYPE * elem, int radix)
{
	double dval;
	if (parseNumber(parser->text, parser->text + parser->textLen, dval, radix)) {
		int ival = (int)dval;
		if ((double)ival == dval) {
			YoParserNode * node = new YoParserNode(YO_NODE_INT, parser);
			node->data.ival = ival;
			elem->node = node;
			return T_LNUMBER;
		}
		YoParserNode * node = new YoParserNode(YO_NODE_DOUBLE, parser);
		node->data.dval = dval;
		elem->node = node;
		return T_DNUMBER;
	}
	return 0;
}

int yoLexDec(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	return yoLexNumber(parser, elem, 10);
}

int yoLexBin(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	return yoLexNumber(parser, elem, 2);
}

int yoLexHex(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	return yoLexNumber(parser, elem, 16);
}

int yoLexFloat(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	double dval;
	if (parseFloat(parser->text, parser->text + parser->textLen, dval)) {
		YoParserNode * node = new YoParserNode(YO_NODE_DOUBLE, parser);
		node->data.dval = dval;
		elem->node = node;
		return T_DNUMBER;
	}
	return 0;
}

int yoLexName(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_NAME, parser);
	elem->node = node;
	return T_NAME;
}

int yoLexChar(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	return parser->text[0];
}

void yoParserEnableBrace(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(!parser->braceEnabled);
	parser->braceEnabled = true;
}

int yoLexOpenBrace(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(parser->text[0] == '{');
	if (parser->braceEnabled) {
		parser->braceEnabled = false;
		return T_BRACE;
	}
	return '{';
}

int yoLexOpenBracket(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	if (parser->braceEnabled) {
		parser->pushBrace();
	}
	return parser->text[0];
}

int yoLexCloseBracket(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	if (parser->lexBraceStack) {
		parser->popBrace();
	}
	return parser->text[0];
}

int yoLexSingleQuotedString(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(parser->text[0] == '\'');
	YO_ASSERT(parser->text + 1 == parser->cursor);
	int line = parser->line;
	const char * lineStart = parser->lineStart;
	while (parser->cursor < parser->limit) {
		if (parser->cursor[0] == '\\') {
			parser->cursor += 2;
			if (parser->cursor > parser->limit) {
				parser->cursor = parser->limit;
			}
			continue;
		}
		if (parser->cursor[0] == '\'') {
			parser->cursor++;
			parser->textLen = parser->cursor - parser->text;
			YoParserNode * node = new YoParserNode(YO_NODE_SINGLE_QUOTED_STRING, parser);
			elem->node = node;
			return T_SSTRING;
		}
		if (parser->cursor[0] == '\n') {
			parser->line++;
			parser->lineStart = parser->cursor + 1;
		}
		else if (parser->cursor[0] == '\r' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '\n'){
			parser->line++;
			parser->lineStart = parser->cursor + 2;
			parser->cursor++;
		}
		parser->cursor++;
	}
	elem->node = NULL;
	parser->line = line;
	parser->lineStart = lineStart;
	return T_SSTRING_NOT_FINISHED;
}

int yoLexQuotedString(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(parser->text[0] == '\"' || parser->text[0] == '}');
	YO_ASSERT(parser->text + 1 == parser->cursor);
	int line = parser->line;
	const char * lineStart = parser->lineStart;
	while (parser->cursor < parser->limit) {
		if (parser->cursor[0] == '\\') {
			parser->cursor += 2;
			if (parser->cursor > parser->limit) {
				parser->cursor = parser->limit;
			}
			continue;
		}
		if (parser->cursor[0] == '\"') {
			parser->cursor++;
			parser->textLen = parser->cursor - parser->text;
			YoParserNode * node = new YoParserNode(YO_NODE_QUOTED_STRING, parser);
			elem->node = node;
			return T_QSTRING;
		}
		if (parser->cursor[0] == '$' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '{'){
			parser->cursor++;
			parser->textLen = parser->cursor - parser->text;
			YoParserNode * node = new YoParserNode(YO_NODE_QUOTED_STRING, parser);
			elem->node = node;
			parser->cursor++;
			parser->pushState(yycST_INJECT, parser->text);
			parser->braceCount++;
			return T_QSTRING_INJECT_EXRP;
		}
		if (parser->cursor[0] == '\n') {
			parser->line++;
			parser->lineStart = parser->cursor + 1;
		}
		else if (parser->cursor[0] == '\r' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '\n'){
			parser->line++;
			parser->lineStart = parser->cursor + 2;
			parser->cursor++;
		}
		parser->cursor++;
	}
	elem->node = NULL;
	parser->line = line;
	parser->lineStart = lineStart;
	return T_QSTRING_NOT_FINISHED;
}

int yoLexInjectOpenBrace(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	parser->braceCount++;
	elem->node = NULL;
	return parser->text[0];
}

int yoLexInjectCloseBrace(void * parm, YYSTYPE * elem)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(parser->braceCount > 0);
	parser->braceCount--;
	if (parser->lexStateStack) {
		if (parser->lexStateStack->braceCount == parser->braceCount) {
			parser->popState();
			return yoLexQuotedString(parm, elem);
		}
	}
	else{
		YO_ASSERT(false);
	}
	elem->node = NULL;
	return parser->text[0];
}

void yoLexLineComment(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	while (parser->cursor < parser->limit) {
		if (parser->cursor[0] == '\n') {
			break;
		}
		if (parser->cursor[0] == '\r' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '\n') {
			break;
		}
		parser->cursor++;
	}
}

void yoLexMultiLineComment(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	while (parser->cursor+1 < parser->limit) {
		if (parser->cursor[0] == '*' && parser->cursor[1] == '/') {
			parser->cursor += 2;
			break;
		}
		if (parser->cursor[0] == '\n') {
			parser->line++;
			parser->lineStart = parser->cursor + 1;
		}
		else if (parser->cursor[0] == '\r' && parser->cursor[1] == '\n'){
			parser->line++;
			parser->lineStart = parser->cursor + 2;
			parser->cursor++;
		}
		parser->cursor++;
	}
}

// =====================================================================
// =====================================================================
// =====================================================================

void YoParserParams::init(const char * _input)
{
	init(_input, strlen(input));
}

void YoParserParams::init(const char * _input, int len)
{
	input = _input;
	limit = input + len;
	lineStart = input;
	line = 1;
	lexStateStack = NULL;
	lexBraceStack = NULL;
	braceEnabled = false;
	braceCount = 0;
	state = yycST_YOLANG;
	// condition = 0;
	ch = 0;
	accept = 0;
	cursor = input;
	text = input;
	textLen = 0;
	marker = input;
	listSize = 0;
	list = NULL;
	root = NULL;
}

void YoParserParams::shutdown()
{
	YO_ASSERT(!lexStateStack);
	while (lexStateStack) {
		LexState * lexState = lexStateStack;
		lexStateStack = lexState->next;
		lexState->next = NULL;
		delete lexState;
	}
	while (list) {
		YoParserNode * node = list;
		list = node->parserNext;
		node->parserNext = NULL;
		delete node;
	}
}

void YoParserParams::pushState(int newState, const char * text)
{
	YoParserParams::LexState * lexState = new YoParserParams::LexState();
	lexState->state = state;
	lexState->text = text;
	lexState->braceCount = braceCount;
	lexState->next = lexStateStack;
	lexStateStack = lexState;
	state = newState;
}

void YoParserParams::popState()
{
	if (lexStateStack) {
		YoParserParams::LexState * lexState = lexStateStack;
		lexStateStack = lexState->next;
		state = lexState->state;
		lexState->next = NULL;
		delete lexState;
	}
	else{
		YO_ASSERT(false);
	}
}

void YoParserParams::pushBrace()
{
	YoParserParams::LexBrace * lexBrace = new YoParserParams::LexBrace();
	lexBrace->braceEnabled = braceEnabled;
	lexBrace->next = lexBraceStack;
	lexBraceStack = lexBrace;
	braceEnabled = false;
}

void YoParserParams::popBrace()
{
	if (lexBraceStack) {
		YoParserParams::LexBrace * lexBrace = lexBraceStack;
		lexBraceStack = lexBrace->next;
		braceEnabled = lexBrace->braceEnabled;
		lexBrace->next = NULL;
		delete lexBrace;
	}
}

enum EYoParserNodeScopeType {
	YO_NODE_SCOPE_STATEMENT,
	YO_NODE_SCOPE_ELEM,
	YO_NODE_SCOPE_OP,
	YO_NODE_SCOPE_PROPS,
	YO_NODE_SCOPE_TYPE,
	YO_NODE_SCOPE_DOTNAME,
};

static void printDepth(int depth)
{
	for (int i = 0; i < depth; i++) {
		printf("  ");
	}
}

static void yoParserDumpNode(YoParserNode * node, int depth, EYoParserNodeScopeType scope)
{
	if (!node) {
		return;
	}
	char * name;
	yoParserDumpNode(node->prev, depth, scope);

	if (scope == YO_NODE_SCOPE_STATEMENT) {
		printDepth(depth);
	}
	else if (node->prev) {
		printf(", ");
	}

	switch (node->type) {
	default:
		YO_ASSERT(false);
		break;

	case YO_NODE_STMT_IF:
		printf("IF ");
		yoParserDumpNode(node->data.stmtIf.ifExpr, depth, YO_NODE_SCOPE_OP);
		printf(" {\n");
		yoParserDumpNode(node->data.stmtIf.thenStmt, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		if (node->data.stmtIf.elseStmt) {
			printf(" ELSE {\n");
			yoParserDumpNode(node->data.stmtIf.elseStmt, depth + 1, YO_NODE_SCOPE_STATEMENT);
			printDepth(depth); printf("}");
		}
		break;

	/*
	case YO_NODE_ELSEIF:
		printf("%sELSE IF ", scope == YO_NODE_SCOPE_ELEM ? " " : "");
		yoParserDumpNode(node->data.elseIfElem.expr, depth, YO_NODE_SCOPE_OP);
		printf(" {\n");
		yoParserDumpNode(node->data.elseIfElem.node, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		break;

	case YO_NODE_ELSE:
		printf("%sELSE {\n", scope == YO_NODE_SCOPE_ELEM ? " " : "");
		yoParserDumpNode(node->data.elseElem.node, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		break;

	case YO_NODE_ELSEIF_LIST:
		printf(" ELSE IF LIST {\n");
		yoParserDumpNode(node->data.elseIfList.nodes[0], depth + 1, YO_NODE_SCOPE_STATEMENT);
		yoParserDumpNode(node->data.elseIfList.nodes[1], depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		break;
	*/

	case YO_NODE_CALL:
		printf("CALL ");
		yoParserDumpNode(node->data.call.name, depth, YO_NODE_SCOPE_OP);
		printf("(");
		yoParserDumpNode(node->data.call.args, depth, YO_NODE_SCOPE_OP);
		printf(")");
		break;

	case YO_NODE_STMT_CATCH:
		printf("STMT CATCH ");
		yoParserDumpNode(node->data.stmtCatch.stmt, depth, YO_NODE_SCOPE_ELEM);
		printf(" CATCH ");
		yoParserDumpNode(node->data.stmtCatch.catchName, depth, YO_NODE_SCOPE_OP);
		printf(" {\n");
		yoParserDumpNode(node->data.stmtCatch.catchStmt, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		break;

	case YO_NODE_STMT_RETURN:
		printf("RETURN ");
		yoParserDumpNode(node->data.stmtReturn.node, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_SINGLE_QUOTED_STRING:
		name = (char*)alloca(node->token.len + 1);
		memcpy(name, node->token.str, node->token.len);
		name[node->token.len] = '\0';
		printf("S%s", name);
		break;

	case YO_NODE_QUOTED_STRING:
		name = (char*)alloca(node->token.len + 1);
		memcpy(name, node->token.str, node->token.len);
		name[node->token.len] = '\0';
		name[0] = '\"';
		name[node->token.len-1] = '\"';
		printf("Q%s", name);
		break;

	case YO_NODE_INT:
		printf("INT %d", node->data.ival);
		break;

	case YO_NODE_DOUBLE:
		printf("DOUBLE %lf", node->data.dval);
		break;

	case YO_NODE_NAME:
	case YO_NODE_DOTNAME:
		name = (char*)alloca(node->token.len + 1);
		memcpy(name, node->token.str, node->token.len);
		name[node->token.len] = '\0';
		if (node->type == YO_NODE_DOTNAME) {
			if (scope != YO_NODE_SCOPE_DOTNAME) {
				printf("DOTNAME ");
			}
			yoParserDumpNode(node->data.dotName.node, depth, YO_NODE_SCOPE_DOTNAME);
			printf(".'%s'", name);
		}
		else{
			if (scope != YO_NODE_SCOPE_DOTNAME) {
				printf("NAME ");
			}
			printf("'%s'", name);
		}
		break;

	case YO_NODE_BIN_OP:
		if (scope == YO_NODE_SCOPE_OP) {
			printf("(");
		}
		yoParserDumpNode(node->data.binOp.left, depth, YO_NODE_SCOPE_OP);
		printf(" %s ", yoTokenName(node->data.binOp.op));
		yoParserDumpNode(node->data.binOp.right, depth, YO_NODE_SCOPE_OP);
		if (node->data.binOp.op == T_INDEX) {
			printf(" ]");
		}
		if (scope == YO_NODE_SCOPE_OP) {
			printf(")");
		}
		break;

	case YO_NODE_UNARY_OP:
		printf("(");
		printf("%s ", yoTokenName(node->data.unaryOp.op));
		yoParserDumpNode(node->data.unaryOp.node, depth, YO_NODE_SCOPE_OP);
		printf(")");
		break;

	case YO_NODE_CONST:
		printf("CONST %s", yoTokenName(node->data.constOp));
		break;

	case YO_NODE_TYPE_STD_NAME:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("%s", yoTokenName(node->data.typeStdName));
		break;

	case YO_NODE_TYPE_NAME:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		yoParserDumpNode(node->data.typeName.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_TYPE_CONST:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("const ");
		yoParserDumpNode(node->data.typeConst.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_TYPE_CHAN:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("chan ");
		yoParserDumpNode(node->data.typeChan.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_TYPE_PTR:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("*");
		yoParserDumpNode(node->data.typePtr.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_TYPE_SLICE:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("[]");
		yoParserDumpNode(node->data.typeSlice.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_TYPE_ARR:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("[");
		yoParserDumpNode(node->data.typeArr.size, depth, YO_NODE_SCOPE_OP);
		printf("]");
		yoParserDumpNode(node->data.typeArr.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_NEW_ARR_EXPS:
		printf("NEW ARR {");
		yoParserDumpNode(node->data.arr.values, depth, YO_NODE_SCOPE_OP);
		printf("}");
		break;

	case YO_NODE_NEW_OBJ_EXPS:
	case YO_NODE_NEW_OBJ_PROPS:
		yoParserDumpNode(node->data.obj.name, depth, YO_NODE_SCOPE_OP);
		printf("NEW OBJ {");
		yoParserDumpNode(node->data.obj.values, depth, YO_NODE_SCOPE_PROPS);
		printf("}");
		break;

	case YO_NODE_DECL_TYPE:
		printf("DECL TYPE ");
		yoParserDumpNode(node->data.declVar.name, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declVar.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_DECL_VAR:
		printf("DECL VAR ");
		yoParserDumpNode(node->data.declVar.name, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declVar.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_DECL_ARG:
		printf("DECL ARG ");
		yoParserDumpNode(node->data.declVar.name, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declVar.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_DECL_FUNC:
		printf("DECL FUNC ");
		if (node->data.func.self) {
			printf("(");
			yoParserDumpNode(node->data.func.self, depth, YO_NODE_SCOPE_OP);
			printf(") ");
		}
		yoParserDumpNode(node->data.func.name, depth, YO_NODE_SCOPE_OP);
		printf(" (");
		yoParserDumpNode(node->data.func.args, depth, YO_NODE_SCOPE_OP);
		printf(")%s", node->data.func.type && node->data.func.type->prev ? " (" : node->data.func.type ? " " : "");
		yoParserDumpNode(node->data.func.type, depth, YO_NODE_SCOPE_OP);
		printf("%s {\n", node->data.func.type && node->data.func.type->prev ? ")" : "");
		yoParserDumpNode(node->data.func.body, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printf("}");
		break;

	case YO_NODE_TYPE_FUNC:
		printf("TYPE FUNC (");
		if (node->data.func.self) {
			yoParserDumpNode(node->data.func.self, depth, YO_NODE_SCOPE_OP);
			printf(") (");
		}
		yoParserDumpNode(node->data.func.args, depth, YO_NODE_SCOPE_OP);
		printf(")%s", node->data.func.type && node->data.func.type->prev ? " (" : node->data.func.type ? " " : "");
		yoParserDumpNode(node->data.func.type, depth, YO_NODE_SCOPE_OP);
		printf("%s", node->data.func.type && node->data.func.type->prev ? ")" : "");
		break;

	case YO_NODE_INTERFACE_FUNC:
		printf("INTERFACE FUNC ");
		yoParserDumpNode(node->data.func.name, depth, YO_NODE_SCOPE_OP);
		printf(" (");
		yoParserDumpNode(node->data.func.args, depth, YO_NODE_SCOPE_OP);
		printf(")%s", node->data.func.type && node->data.func.type->prev ? " (" : node->data.func.type ? " " : "");
		yoParserDumpNode(node->data.func.type, depth, YO_NODE_SCOPE_OP);
		printf("%s", node->data.func.type && node->data.func.type->prev ? ")" : "");
		break;

	case YO_NODE_INTERFACE:
		printf("INTERFACE {%s", node->data.interface.node ? "\n" : "");
		yoParserDumpNode(node->data.interface.node, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printf("}");
		break;

	case YO_NODE_CLASS:
		printf("CLASS {\n");
		yoParserDumpNode(node->data.typeClass.node, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printf("}");
		break;
	}

	if (scope == YO_NODE_SCOPE_STATEMENT) {
		printf(";\n");
	}
}

void YoParserParams::dump()
{
	if (root) {
		// YO_ASSERT(root->type == YO_NODE_STATEMENT);
		yoParserDumpNode(root, 0, YO_NODE_SCOPE_STATEMENT);
	}
	else {
		printf("root EMPTY\n");
	}
}

// =====================================================================
// =====================================================================
// =====================================================================

YoParserNode::YoParserNode(EYoParserNodeType _type, YoParserParams * parser)
{
	type = _type;
	parserNext = parser->list;
	parser->list = this;
	parser->listSize++;
	token.str = parser->text;
	token.len = parser->textLen;
	token.line = parser->line;
	prev = NULL;
	memset(&data, 0, sizeof(data));
}

/*
YoParserNode::~YoParserNode()
{
	reset();
}

void YoParserNode::reset()
{
	switch (type) {
	case YO_NODE_EMPTY:
		return;

	case YO_NODE_NAME:
	case YO_NODE_INT:
	case YO_NODE_DOUBLE:
		break;

	case YO_NODE_BIN_OP:
		// delete data.binOp.nodes[0];
		// delete data.binOp.nodes[1];
		break;

	case YO_NODE_STATEMENT:
		break;
	}
	memset(&data, 0, sizeof(data));
	type = YO_NODE_EMPTY;
}
*/

// =====================================================================
// =====================================================================
// =====================================================================

YoParserStackElement::YoParserStackElement()
{
	node = NULL;
}

// =====================================================================
// =====================================================================
// =====================================================================

void yoParserEnd(YoParserStackElement * elem, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(!parser->root);
	parser->root = elem->node;
}

void yoParserBinOp(YoParserStackElement * r, YoParserStackElement * a, YoParserStackElement * b, int op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node);
	YO_ASSERT(b->node);
	YoParserNode * node = new YoParserNode(YO_NODE_BIN_OP, parser);
	node->data.binOp.op = op;
	node->data.binOp.left = a->node;
	node->data.binOp.right = b->node;
	node->token = a->node->token;
	r->node = node;
}

void yoParserConst(YYSTYPE * r, int op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_CONST, parser);
	node->data.constOp = op;
	r->node = node;
}

void yoParserTypeStdName(YYSTYPE * r, int op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_STD_NAME, parser);
	node->data.typeStdName = op;
	r->node = node;
}

void yoParserTypeName(YYSTYPE * r, YYSTYPE * name, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_NAME, parser);
	node->data.typeName.type = name->node;
	r->node = node;
}

void yoParserTypeConst(YYSTYPE * r, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_CONST, parser);
	node->data.typeConst.type = type->node;
	r->node = node;
}

void yoParserTypeChan(YYSTYPE * r, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_CHAN, parser);
	node->data.typeChan.type = type->node;
	r->node = node;
}

void yoParserTypePtr(YYSTYPE * r, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_PTR, parser);
	node->data.typePtr.type = type->node;
	r->node = node;
}

void yoParserTypeSlice(YYSTYPE * r, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_SLICE, parser);
	node->data.typeSlice.type = type->node;
	r->node = node;
}

bool YoParserNode::isType() const
{
	return type == YO_NODE_TYPE_NAME || type == YO_NODE_TYPE_STD_NAME 
		|| type == YO_NODE_TYPE_CONST || type == YO_NODE_TYPE_CHAN
		|| type == YO_NODE_TYPE_PTR || type == YO_NODE_TYPE_SLICE || type == YO_NODE_TYPE_ARR
		|| type == YO_NODE_CLASS || type == YO_NODE_INTERFACE || type == YO_NODE_TYPE_FUNC;
}

void yoParserTypeArr(YYSTYPE * r, YYSTYPE * size, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(size->node && (size->node->type == YO_NODE_INT || size->node->type == YO_NODE_NAME || size->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_ARR, parser);
	node->data.typeArr.type = type->node;
	node->data.typeArr.size = size->node;
	r->node = node;
}

void yoParserNewArr(YYSTYPE * r, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_ARR_EXPS, parser);
	r->node = node;
}

void yoParserNewArrExps(YYSTYPE * r, YYSTYPE * expr_list, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(expr_list->node);
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_ARR_EXPS, parser);
	node->data.arr.values = expr_list->node;
	r->node = node;
}

void yoParserNewObj(YYSTYPE * r, YYSTYPE * name, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_OBJ_EXPS, parser);
	node->data.obj.name = name->node;
	r->node = node;
}

void yoParserNewObjExps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * expr_list, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(expr_list->node);
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_OBJ_EXPS, parser);
	node->data.obj.name = name->node;
	node->data.obj.values = expr_list->node;
	r->node = node;
}

void yoParserNewObjProps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * prop_list, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(prop_list->node);
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_OBJ_PROPS, parser);
	node->data.obj.name = name->node;
	node->data.obj.values = prop_list->node;
	r->node = node;
}

void yoParserDeclVar(YYSTYPE * r, YYSTYPE * name, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YO_ASSERT(name->node && name->node->type == YO_NODE_NAME);
	YoParserNode * node = new YoParserNode(YO_NODE_DECL_VAR, parser);
	node->data.declVar.type = type->node;
	node->data.declVar.name = name->node;
	node->token = r->node->token;
	r->node = node;
}

void yoParserDeclType(YYSTYPE * r, YYSTYPE * name, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YO_ASSERT(name->node && name->node->type == YO_NODE_NAME);
	YoParserNode * node = new YoParserNode(YO_NODE_DECL_TYPE, parser);
	node->data.declType.type = type->node;
	node->data.declType.name = name->node;
	node->token = r->node->token;
	r->node = node;
}

void yoParserDeclArg(YYSTYPE * r, YYSTYPE * name, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YO_ASSERT(name->node && name->node->type == YO_NODE_NAME);
	YoParserNode * node = new YoParserNode(YO_NODE_DECL_ARG, parser);
	node->data.declVar.type = type->node;
	node->data.declVar.name = name->node;
	node->token = r->node->token;
	r->node = node;
}

void yoParserUnaryOp(YYSTYPE * r, YYSTYPE * a, int op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a && a->node);
	YoParserNode * node = new YoParserNode(YO_NODE_UNARY_OP, parser);
	node->data.unaryOp.op = op;
	node->data.unaryOp.node = a->node;
	r->node = node;
}

void yoParserList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	if (!b->node) {
		r->node = a->node;
		return;
	}
	if (a->node) {
		YO_ASSERT(a && b && b->node && a->node != b->node);
		YoParserNode * cur = b->node;
		while (cur->prev) {
			YO_ASSERT(cur->prev != b->node);
			cur = cur->prev;
		}
		cur->prev = a->node;
	}
	r->node = b->node;
}

void yoParserDotName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node && (a->node->type == YO_NODE_NAME || a->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(b->node && b->node->type == YO_NODE_NAME);
	// a->node->type = YO_NODE_DOTNAME;
	b->node->type = YO_NODE_DOTNAME;
	b->node->data.dotName.node = a->node;
	r->node = b->node;
}

void yoParserNewLine(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	parser->lineStart = parser->cursor;
	parser->line++;
}

void yoLexNewLine(void * parm)
{
	yoParserNewLine(parm);
}

void yoParseEmpty(YYSTYPE * r, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	r->node = NULL;
}

void yoParserDeclFunc(YYSTYPE * r, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(!type || (type->node && type->node->isType()));
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	// YO_ASSERT(args->node && args->node->type == );
	// YO_ASSERT(body->node && body->node->type == YO_NODE_TYPE);
	YoParserNode * node = new YoParserNode(YO_NODE_DECL_FUNC, parser);
	node->data.func.self = self ? self->node : NULL;
	node->data.func.type = type ? type->node : NULL;
	node->data.func.name = name->node;
	node->data.func.args = args->node;
	node->data.func.body = body->node;
	node->token = name->node->token;
	r->node = node;
}

void yoParserTypeFunc(YYSTYPE * r, YYSTYPE * self, YYSTYPE * args, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(!type || (type->node && type->node->isType()));
	// YO_ASSERT(args->node && args->node->type == );
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_FUNC, parser);
	node->data.func.self = self ? self->node : NULL;
	node->data.func.type = type ? type->node : NULL;
	node->data.func.args = args->node;
	node->token = args->node->token;
	r->node = node;
}

void yoParserInterfaceFunc(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(!type || (type->node && type->node->isType()));
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	// YO_ASSERT(args->node && args->node->type == );
	YoParserNode * node = new YoParserNode(YO_NODE_INTERFACE_FUNC, parser);
	node->data.func.type = type ? type->node : NULL;
	node->data.func.name = name->node;
	node->data.func.args = args->node;
	node->token = name->node->token;
	r->node = node;
}

void yoParserCall(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME 
		|| (name->node->type == YO_NODE_BIN_OP && name->node->data.binOp.op == T_DOT)));
	// YO_ASSERT(args->node && args->node->type == );
	YoParserNode * node = new YoParserNode(YO_NODE_CALL, parser);
	node->data.call.name = name->node;
	node->data.call.args = args->node;
	node->token = name->node->token;
	r->node = node;
}

void yoParserCatchElem(YYSTYPE * r, YYSTYPE * name, YYSTYPE * stmt, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(name && name->node && name->node->type == YO_NODE_NAME);
	YO_ASSERT(stmt && stmt->node);
	YoParserNode * node = new YoParserNode(YO_NODE_CATCH_ELEM, parser);
	node->data.stmtCatch.catchName = name->node;
	node->data.stmtCatch.catchStmt = stmt->node;
	node->data.stmtCatch.stmt = NULL;
	node->token = stmt->node->token;
	r->node = node;
}

void yoParserStmtCatch(YYSTYPE * r, YYSTYPE * stmt, YYSTYPE * catchElem, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(catchElem);
	if (catchElem->node) {
		YO_ASSERT(catchElem->node->type == YO_NODE_CATCH_ELEM);
		YoParserNode * node = catchElem->node; //  new YoParserNode(YO_NODE_STMT_CATCH, parser);
		node->type = YO_NODE_STMT_CATCH;
		node->data.stmtCatch.stmt = stmt->node;
		node->token = stmt->node->token;
		r->node = node;
	}
	else{
		r->node = stmt->node;
	}
}

void yoParserStmtReturn(YYSTYPE * r, YYSTYPE * expr, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_STMT_RETURN, parser);
	node->data.stmtReturn.node = expr ? expr->node : NULL;
	node->token = expr->node->token;
	r->node = node;
}

/*
void yoParserIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseStmt, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_STMT_IF, parser);
	node->data.stmtIf.ifExpr = ifExpr->node;
	node->data.stmtIf.thenStmt = thenStmt->node;
	node->data.stmtIf.elseStmt = elseStmt->node;
	node->token = ifExpr->node->token;
	r->node = node;
}
*/

void yoParserStmtIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseIfList, YYSTYPE * elseStmt, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	if (elseIfList) {
		while (elseIfList->node) {
			YO_ASSERT(elseIfList->node->type == YO_NODE_ELSEIF);
			YoParserNode * node = elseIfList->node;
			YoParserNode * _ifExpr = node->data.elseIfElem.expr;
			YoParserNode * _thenStmt = node->data.elseIfElem.node;
			node->type = YO_NODE_STMT_IF;
			node->data.stmtIf.ifExpr = _ifExpr;
			node->data.stmtIf.thenStmt = _thenStmt;
			if (elseStmt->node->type == YO_NODE_ELSE) {
				node->data.stmtIf.elseStmt = elseStmt->node->data.elseElem.node;
			}
			else{
				YO_ASSERT(elseStmt->node->type == YO_NODE_STMT_IF);
				node->data.stmtIf.elseStmt = elseStmt->node;
			}
			elseStmt->node = node;
			elseIfList->node = node->prev;
			node->prev = NULL;
		}
	}
	// yoParserIf(r, ifExpr, thenStmt, elseStmt, parm);
	YoParserNode * node = new YoParserNode(YO_NODE_STMT_IF, parser);
	node->data.stmtIf.ifExpr = ifExpr->node;
	node->data.stmtIf.thenStmt = thenStmt->node;
	node->data.stmtIf.elseStmt = elseStmt->node;
	node->token = ifExpr->node->token;
	r->node = node;
}

void yoParserElseIf(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * stmt, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_ELSEIF, parser);
	node->data.elseIfElem.expr = expr->node;
	node->data.elseIfElem.node = stmt->node;
	node->token = expr->node->token;
	r->node = node;
}

void yoParserElse(YYSTYPE * r, YYSTYPE * stmt, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_ELSE, parser);
	node->data.elseElem.node = stmt->node;
	node->token = stmt->node->token;
	r->node = node;
}

void yoParserInterface(YYSTYPE * r, YYSTYPE * a, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a);
	YoParserNode * node = new YoParserNode(YO_NODE_INTERFACE, parser);
	node->data.interface.node = a->node;
	r->node = node;
}

void yoParserClass(YYSTYPE * r, YYSTYPE * a, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a);
	YoParserNode * node = new YoParserNode(YO_NODE_CLASS, parser);
	node->data.typeClass.node = a->node;
	r->node = node;
}

void yoParserDebug(YYSTYPE * r, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	int i = 0;
}

void yoParserError(YYSTYPE * r, const char * msg, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	const char * cursor = parser->text;
	const char * end = strchr(cursor, '\n');
	if (!end) {
		end = parser->limit;
	}
	bool startCut = false, endCut = false;
	const char * start = cursor - 40;
	if (start < parser->lineStart) {
		start = parser->lineStart;
		if (start > parser->text) {
			start = parser->text;
		}
	}
	while (*start <= ' ' && start < end) start++;
	if (start > parser->lineStart) {
		startCut = true;
	}
	if (end > cursor + 20) {
		end = cursor + 20;
		endCut = true;
	}
	int len = end - start;
	
	char * sub = (char*)alloca(len + 1);
	memcpy(sub, start, len);
	sub[len] = '\0';

	printf("Parse error: %s\n", msg);
	printf("Error at line: %d, pos: %d\n", parser->line, (int)(cursor - parser->lineStart));
	printf("%s%s%s\n", startCut ? "..." : "", sub, endCut ? "..." : "");

	int i, pos = cursor - start;
	if (startCut) {
		for (i = 0; i < 3; i++) {
			printf(" ");
		}
	}
	for (i = 0; i < pos; i++) {
		printf(start[i] == '\t' ? "\t" : " ");
	}
	printf("^\n");

	r->node = NULL;
	parser->cursor = parser->limit;
}

// =====================================================================
// =====================================================================
// =====================================================================
