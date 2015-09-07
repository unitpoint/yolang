#include "yoparser.h"
#include <stdio.h>
#include <string.h>

// =====================================================================
// =====================================================================
// =====================================================================

// int yywrap() { return 1; }

void yoerror(const char* s) {
	// fprintf(stderr, "Parse error: %s\n", s);
	// exit(1);
}

int yoparse(void*);

const char * yoTokenName(int token)
{
	switch (token) {
	case T_ASSIGN: return "=";
	case T_INIT_ASSIGN: return "INIT =";
	case T_PROP_ASSIGN: return "PROP =";
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
	case T_INT: return "int";
	case T_INTPTR: return "intptr";
	case T_UINT8: return "uint8";
	case T_UINT16: return "uint16";
	case T_UINT32: return "uint32";
	case T_UINT64: return "uint64";
	case T_UINT: return "uint";
	case T_UINTPTR: return "uintptr";
	case T_FLOAT32: return "float32";
	case T_FLOAT64: return "float64";
	case T_STRING: return "string";
	case T_BOOL: return "bool";
	case T_VOID: return "void";
	case T_UNKNOWN_YET: return "?";
	}
	return "<UNKNOWN TOKEN>";
}

// =====================================================================
// =====================================================================
// =====================================================================

template <class T>
bool yoParseInt(const char * str, const char * end, int radix, T& p_val)
{
	T val = 0, prev_val = 0;
	// const char * str = p_str;
	const char * start = str;
	// for (; str < end && *str == '0'; str++);
	for (int cur; str < end; str++) {
		if (*str >= '0' && *str <= '9') {
			cur = (int)(*str - '0');
		}
		else if (*str >= 'a' && *str <= 'z') {
			cur = 10 + (int)(*str - 'a');
		}
		else if (*str >= 'A' && *str <= 'Z') {
			cur = 10 + (int)(*str - 'A');
		}
		else if (*str == '_') {
			start++;
			continue;
		}
		else {
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
	if (start == str || str != end) {
		// p_str = start;
		p_val = 0;
		return false;
	}
	// p_str = str;
	p_val = val;
	return true;
}

template <class T>
static bool parseFloatBuf(const char *& p_str, const char * end, T& p_val)
{
	T val = 0;
	const char * str = p_str;
	const char * start = str;
	// for (; str < end && *str == '0'; str++);
	for (; str < end; str++){
		if (*str >= '0' && *str <= '9') {
			val = val * 10 + (*str - '0');
		}
		else if (*str == '_') {
			start++;
		}
		else {
			break;
		}
	}
	p_val = val;
	p_str = str;
	return str > start;
}

bool parseFloat(const char * str, const char * end, double& p_val)
{
	const char * start = str;
	double dval = 0.0;
	if (!parseFloatBuf(str, end, dval)) {
		p_val = 0;
		return false;
	}
	if (str < end && str[0] == '.' && str[1] >= '0' && str[1] <= '9') {
		dval += (double)(str[1] - '0') * 0.1;
		double m = 0.01;
		for (str += 2; str < end; str++) {
			if (*str >= '0' && *str <= '9') {
				dval += (double)(*str - '0') * m;
				m *= 0.1;
			}
			else if (*str == '_') {
				continue;
			}
			else{
				break;
			}
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
			if (!yoParseInt(str, end, 10, pow)) {
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
	if (start == str || str != end) {
		p_val = 0;
		return false;
	}
	p_val = dval;
	return true;
}

int yoLexIntRadix(YYSTYPE * elem, int radix, int skipEnd, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	const char * str = parser->text;
	const char * end = str + parser->textLen - skipEnd;
	switch (radix) {
	default:
		YO_ASSERT(false);
		// no break

	case 10:
		break;

	case 16:
		YO_ASSERT(str[0] == '0' && str[1] == 'x');
		str += 2;
		break;

	case 8:
		YO_ASSERT(str[0] == '0');
		str += 1;
		break;

	case 2:
		YO_ASSERT(str[0] == '0' && str[1] == 'b');
		str += 2;
		break;
	}
	int bits = 64; // sizeof(int) * 8;
	bool isSigned = true;
	if (skipEnd) {
		YO_ASSERT(skipEnd == 2 || skipEnd == 3);
		YO_ASSERT(end[0] == 'i' || end[0] == 'u');
		isSigned = end[0] == 'i';
		switch (end[1]) {
		case '8':
			YO_ASSERT(skipEnd == 2);
			bits = 8;
			break;

		case '1': // 16
			YO_ASSERT(skipEnd == 3 && end[2] == '6');
			bits = 16;
			break;

		case '3': // 32
			YO_ASSERT(skipEnd == 3 && end[2] == '2');
			bits = 32;
			break;

		default:
			YO_ASSERT(false);
			// no break

		case '6': // 64
			YO_ASSERT(skipEnd == 3 && end[2] == '4');
			bits = 64;
			break;
		}
	}
	YO_U64 val64 = 0;
	YO_U32 val32 = 0;
	YO_U16 val16 = 0;
	YO_BYTE val8 = 0;
	switch (bits) {
	case 8:
		if (!yoParseInt(str, end, radix, val8)) {
			return 0;
		}
		val64 = val8;
		break;

	case 16:
		if (!yoParseInt(str, end, radix, val16)) {
			return 0;
		}
		val64 = val16;
		break;

	case 32:
		if (!yoParseInt(str, end, radix, val32)) {
			return 0;
		}
		val64 = val32;
		break;

	default:
		YO_ASSERT(false);
		// no break

	case 64:
		if (!yoParseInt(str, end, radix, val64)) {
			return 0;
		}
		if (!skipEnd && sizeof(int)*8 == 32) {
			if ((YO_U64)(int)val64 == val64) {
				bits = 32;
			}
		}
		break;
	}
	YoParserNode * node = parser->newNode(YO_NODE_CONST_INT, loc);
	node->data.constInt.val = val64;
	node->data.constInt.bits = bits;
	node->data.constInt.isSigned = isSigned;
	elem->node = node;
	return T_LNUMBER;
}

int yoLexFloat(YYSTYPE * elem, int skipEnd, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	const char * str = parser->text;
	const char * end = str + parser->textLen - skipEnd;
	YO_ASSERT(sizeof(double) * 8 == 64 && sizeof(float) * 8 == 32);
	double fval64 = 0;
	if (!parseFloat(str, end, fval64)) {
		return 0;
	}
	int bits = sizeof(double) * 8;
	if (skipEnd) {
		YO_ASSERT(skipEnd == 3);
		switch (end[1]) {
		case '3': // 32
			YO_ASSERT(skipEnd == 3 && end[2] == '2');
			bits = 32;
			break;

		default:
			YO_ASSERT(false);
			// no break

		case '6': // 64
			YO_ASSERT(skipEnd == 3 && end[2] == '4');
			bits = 64;
			break;
		}
	}
#if 0
	else if((double)(float)fval64 == fval64) {
		bits = 32;
	}
#endif
	if (bits == 32) {
		YoParserNode * node = parser->newNode(YO_NODE_CONST_FLOAT, loc);
		node->data.constFloat.fval = fval64;
		elem->node = node;
	}
	else{
		YO_ASSERT(bits == 64);
		YoParserNode * node = parser->newNode(YO_NODE_CONST_DOUBLE, loc);
		node->data.constFloat.fval = fval64;
		elem->node = node;
	}
	return T_DNUMBER;
}

int yoLexName(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = parser->newNode(YO_NODE_NAME, loc);
	elem->node = node;
	return T_NAME;
}

int yoLexChar(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	return parser->text[0];
}

void yoParserEnableBrace(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!parser->braceEnabled);
	parser->braceEnabled = true;
}

int yoLexOpenBrace(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(parser->text[0] == '{');
	if (parser->braceEnabled) {
		parser->braceEnabled = false;
		return T_BRACE;
	}
	return '{';
}

int yoLexOpenBracket(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	if (parser->braceEnabled) {
		parser->pushBrace();
	}
	return parser->text[0];
}

int yoLexCloseBracket(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	if (parser->lexBraceStack) {
		parser->popBrace();
	}
	return parser->text[0];
}

int yoLexSingleQuotedString(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(parser->text[0] == '\'');
	YO_ASSERT(parser->text + 1 == parser->cursor);
	YO_ASSERT(parser->line == loc->first_line && loc->first_line == loc->last_line);
	YO_ASSERT(loc->token.str == parser->text && loc->token.line == parser->line && loc->token.len == 1);
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
			parser->textLen = loc->token.len = parser->cursor - parser->text;
			YoParserNode * node = parser->newNode(YO_NODE_SINGLE_QUOTED_STRING, loc);
			elem->node = node;
			return T_SSTRING;
		}
		if (parser->cursor[0] == '\n') {
			parser->setLine(parser->cursor + 1, parser->line + 1);
			loc->last_line = parser->line;
		}
		else if (parser->cursor[0] == '\r' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '\n'){
			parser->setLine(parser->cursor + 2, parser->line + 1);
			loc->last_line = parser->line;
			parser->cursor++;
		}
		parser->cursor++;
	}
	elem->node = NULL;
	parser->setLine(lineStart, line);
	return T_SSTRING_NOT_FINISHED;
}

int yoLexQuotedString(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(parser->text[0] == '\"' || parser->text[0] == '}');
	YO_ASSERT(parser->text + 1 == parser->cursor);
	YO_ASSERT(parser->line == loc->first_line && loc->first_line == loc->last_line);
	YO_ASSERT(loc->token.str == parser->text && loc->token.line == parser->line && loc->token.len == 1);
	int saveLine = parser->line;
	const char * saveLineStart = parser->lineStart;
	size_t saveLineCount = parser->lines.size();
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
			parser->textLen = loc->token.len = parser->cursor - parser->text;
			YoParserNode * node = parser->newNode(YO_NODE_QUOTED_STRING, loc);
			elem->node = node;
			return T_QSTRING;
		}
		if (parser->cursor[0] == '$' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '{'){
			parser->cursor++;
			parser->textLen = loc->token.len = parser->cursor - parser->text;
			YoParserNode * node = parser->newNode(YO_NODE_QUOTED_STRING, loc);
			elem->node = node;
			parser->cursor++;
			parser->pushState(yycST_INJECT, parser->text);
			parser->braceCount++;
			return T_QSTRING_INJECT_EXRP;
		}
		if (parser->cursor[0] == '\n') {
			parser->setLine(parser->cursor + 1, parser->line + 1);
			loc->last_line = parser->line;
		}
		else if (parser->cursor[0] == '\r' && parser->cursor + 1 < parser->limit && parser->cursor[1] == '\n'){
			parser->setLine(parser->cursor + 2, parser->line + 1);
			loc->last_line = parser->line;
			parser->cursor++;
		}
		parser->cursor++;
	}
	elem->node = NULL;
	parser->lines.resize(saveLineCount);
	parser->lineStart = saveLineStart;
	parser->line = saveLine;
	return T_QSTRING_NOT_FINISHED;
}

int yoLexInjectOpenBrace(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	parser->braceCount++;
	elem->node = NULL;
	return parser->text[0];
}

int yoLexInjectCloseBrace(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(parser->braceCount > 0);
	parser->braceCount--;
	if (parser->lexStateStack) {
		if (parser->lexStateStack->braceCount == parser->braceCount) {
			parser->popState();
			return yoLexQuotedString(elem, parm, loc);
		}
	}
	else{
		YO_ASSERT(false);
	}
	elem->node = NULL;
	return parser->text[0];
}

void yoLexLineComment(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
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

void yoLexMultiLineComment(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	while (parser->cursor+1 < parser->limit) {
		if (parser->cursor[0] == '*' && parser->cursor[1] == '/') {
			parser->cursor += 2;
			break;
		}
		if (parser->cursor[0] == '\n') {
			parser->setLine(parser->cursor + 1, parser->line + 1);
		}
		else if (parser->cursor[0] == '\r' && parser->cursor[1] == '\n'){
			parser->setLine(parser->cursor + 2, parser->line + 1);
			parser->cursor++;
		}
		parser->cursor++;
	}
}

void yoLexTrackRule(YYSTYPE * elem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	parser->textLen = parser->cursor - parser->text;
	loc->first_line = parser->line;
	loc->first_column = parser->text - parser->lineStart;
	loc->last_line = parser->line;
	loc->last_column = parser->cursor - parser->lineStart;
	loc->token.str = parser->text;
	loc->token.len = parser->textLen;
	loc->token.line = parser->line;
	elem->node = NULL;
	elem->loc = *loc;
	// memset(elem, 0, sizeof(*elem));
}

// =====================================================================
// =====================================================================
// =====================================================================

YoParser::YoParser(const char * input)
{
	init(input);
}

YoParser::YoParser(const char * input, int len)
{
	init(input, len);
}

YoParser::~YoParser()
{
	YO_ASSERT(!lexStateStack);
	while (lexStateStack) {
		LexState * lexState = lexStateStack;
		lexStateStack = lexState->next;
		lexState->next = NULL;
		delete lexState;
	}
	for (size_t i = 0; i < nodes.size(); i++){
		delete nodes[i];
	}
}

void YoParser::init(const char * _input)
{
	init(_input, strlen(input));
}

void YoParser::init(const char * _input, int len)
{
	input = _input;
	limit = input + len;
	lineStart = input;
	line = 1;
	lines.push_back(lineStart);
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
	module = NULL;

	error = ERROR_NOTHING;
	// errorCursor = NULL;
	// errorLineStart = NULL;
	errorLine = 0;
	errorLinePos = 0;
	memset(&errorLoc, 0, sizeof(errorLoc));
}

void YoParser::setLine(const char * str, int p_line)
{
	YO_ASSERT(str > lineStart);
	if (lineStart != str) {
		lineStart = str;
		lines.push_back(str);
	}
	line = p_line;
}

bool YoParser::isError() const
{
	return error != ERROR_NOTHING;
}

void YoParser::dumpErrorLine(const YoParserToken& token)
{
	const char * errorLineStart = lines[token.line-1];
	int pos = token.str - errorLineStart;
	dumpErrorLine(token.line, pos);
}

void YoParser::dumpErrorLine(int line, int linePos)
{
	int errorLine = line;
	const char * errorLineStart = lines[line-1];
	const char * errorCursor = errorLineStart + linePos;
	const char * cursor = errorCursor;
	const char * end = strchr(cursor, '\n');
	if (!end) {
		end = limit;
	}
	bool startCut = false, endCut = false;
	const char * start = cursor - 40;
	if (start < errorLineStart) {
		start = errorLineStart;
		if (start > errorCursor) {
			start = errorCursor;
		}
	}
	// while (*start <= ' ' && start < end) start++;
	if (start > errorLineStart) {
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

	// printf("Error at line: %d, pos: %d\n", errorLine, (int)(cursor - errorLineStart + 1));
	printf("Error at line: %d\n", errorLine);
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
}

void YoParser::dumpError()
{
	if (!isError()) {
		return;
	}
	printf("Parser msg: %s\n", errorMsg.c_str());
	dumpErrorLine(errorLine, errorLinePos);
}

bool YoParser::run()
{
	int i = yoparse(this);
	if (!module && !isError()) {
		error = YoParser::ERROR_SYNTAX;
		errorMsg = "No module";
		errorLoc.first_column = 0;
		errorLoc.first_line = 1;
		errorLoc.last_column = 1;
		errorLoc.last_line = 1;
		errorLoc.token.str = input;
		errorLoc.token.len = 1;
		errorLoc.token.line = 1;
		errorLine = line;
		errorLinePos = text - lineStart;
	}
	return !isError();
}

void YoParser::pushState(int newState, const char * text)
{
	LexState * lexState = new LexState();
	lexState->state = state;
	lexState->text = text;
	lexState->braceCount = braceCount;
	lexState->next = lexStateStack;
	lexStateStack = lexState;
	state = newState;
}

void YoParser::popState()
{
	if (lexStateStack) {
		LexState * lexState = lexStateStack;
		lexStateStack = lexState->next;
		state = lexState->state;
		lexState->next = NULL;
		delete lexState;
	}
	else{
		YO_ASSERT(false);
	}
}

void YoParser::pushBrace()
{
	LexBrace * lexBrace = new LexBrace();
	lexBrace->braceEnabled = braceEnabled;
	lexBrace->next = lexBraceStack;
	lexBraceStack = lexBrace;
	braceEnabled = false;
}

void YoParser::popBrace()
{
	if (lexBraceStack) {
		LexBrace * lexBrace = lexBraceStack;
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

static const char * yoFuncOpStr(int op)
{
	switch (op) {
	default: YO_ASSERT(false); break;
	case T_FUNC: break;
	case T_EXTERN_FUNC: return "EXTERN FUNC";
	case T_GET: return "GET";
	case T_SET: return "SET";
	case T_SUB_FUNC: return "SUB FUNC";
	case T_LAMBDA: return "LAMBDA";
	}
	return "FUNC";
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

	case YO_NODE_MODULE:
		printf("MODULE ");
		yoParserDumpNode(node->data.module.name, depth, YO_NODE_SCOPE_OP);
		printf(";\n");
		yoParserDumpNode(node->data.module.body, depth, YO_NODE_SCOPE_STATEMENT);
		return;

	case YO_NODE_IMPORT:
		printf("IMPORT ");
		if (node->data.import.name) {
			yoParserDumpNode(node->data.import.name, depth, YO_NODE_SCOPE_OP);
			printf(" ");
		}
		yoParserDumpNode(node->data.import.path, depth, YO_NODE_SCOPE_OP);
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

	case YO_NODE_CALL:
		printf("CALL ");
		yoParserDumpNode(node->data.call.name, depth, YO_NODE_SCOPE_OP);
		printf("(");
		yoParserDumpNode(node->data.call.args, depth, YO_NODE_SCOPE_OP);
		printf(")");
		break;

	case YO_NODE_STMT_CATCH:
		printf("TRY STMT ");
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
		name[0] = name[node->token.len - 1] = '\'';
		printf("%s", name);
		break;

	case YO_NODE_QUOTED_STRING:
		name = (char*)alloca(node->token.len + 1);
		memcpy(name, node->token.str, node->token.len);
		name[node->token.len] = '\0';
		name[0] = name[node->token.len-1] = '\"';
		printf("%s", name);
		break;

	case YO_NODE_CONST_INT:
		printf("%s%d %llu", node->data.constInt.isSigned ? "I" : "U", node->data.constInt.bits, node->data.constInt.val);
		break;

	case YO_NODE_CONST_FLOAT:
		printf("F32 %f", (float)node->data.constFloat.fval);
		break;

	case YO_NODE_CONST_DOUBLE:
		printf("F64 %lf", (double)node->data.constFloat.fval);
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

	case YO_NODE_ASSIGN:
		if (scope == YO_NODE_SCOPE_OP) {
			printf("(");
		}
		yoParserDumpNode(node->data.assign.left, depth, YO_NODE_SCOPE_OP);
		printf(" %s ", yoTokenName(node->data.assign.op));
		yoParserDumpNode(node->data.assign.right, depth, YO_NODE_SCOPE_OP);
		if (scope == YO_NODE_SCOPE_OP) {
			printf(")");
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

	case YO_NODE_CONST_NULL:
		printf("NULL");
		break;

	case YO_NODE_CONST_TRUE:
		printf("TRUE");
		break;

	case YO_NODE_CONST_FALSE:
		printf("FALSE");
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
		yoParserDumpNode(node->data.typeName.name, depth, YO_NODE_SCOPE_TYPE);
		if (node->data.typeName.gen) {
			printf(" <");
			yoParserDumpNode(node->data.typeName.gen, depth, YO_NODE_SCOPE_OP);
			printf(">");
		}
		if (node->data.typeName.def) {
			printf("=");
			yoParserDumpNode(node->data.typeName.def, depth, YO_NODE_SCOPE_OP);
		}
		break;

	case YO_NODE_TYPE_CONST:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("const ");
		yoParserDumpNode(node->data.typeConst.type, depth, YO_NODE_SCOPE_TYPE);
		break;

	case YO_NODE_TYPE_MUTABLE:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("mut ");
		yoParserDumpNode(node->data.typeMutable.type, depth, YO_NODE_SCOPE_TYPE);
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

	case YO_NODE_TYPE_REF:
		if (scope != YO_NODE_SCOPE_TYPE) {
			printf("TYPE ");
		}
		printf("&");
		yoParserDumpNode(node->data.typeRef.type, depth, YO_NODE_SCOPE_TYPE);
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

	case YO_NODE_CONCAT:
		printf("CONCAT {");
		yoParserDumpNode(node->data.concat.values, depth, YO_NODE_SCOPE_OP);
		printf("}");
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
		yoParserDumpNode(node->data.declType.name, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declType.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_DECL_VAR:
		printf("DECL VAR %s", node->data.declVar.isMutable ? "MUT " : "");
		yoParserDumpNode(node->data.declVar.name, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declVar.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_DECL_ARG:
		printf("DECL ARG %s", node->data.declVar.isMutable ? "MUT " : "");
		yoParserDumpNode(node->data.declVar.name, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declVar.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_DECL_FUNC:
		printf("DECL %s ", yoFuncOpStr(node->data.func.op));
		if (node->data.func.self) {
			printf("(");
			yoParserDumpNode(node->data.func.self, depth, YO_NODE_SCOPE_OP);
			printf(") ");
		}
		yoParserDumpNode(node->data.func.name, depth, YO_NODE_SCOPE_OP);
		printf(" (");
		yoParserDumpNode(node->data.func.args, depth, YO_NODE_SCOPE_OP);
		printf(")%s", node->data.func.type ? " " : "");
		yoParserDumpNode(node->data.func.type, depth, YO_NODE_SCOPE_OP);
		printf(" {\n");
		yoParserDumpNode(node->data.func.body, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		break;

	case YO_NODE_TYPE_FUNC:
		printf("TYPE %s (", yoFuncOpStr(node->data.func.op));
		if (node->data.func.self) {
			yoParserDumpNode(node->data.func.self, depth, YO_NODE_SCOPE_OP);
			printf(") (");
		}
		yoParserDumpNode(node->data.func.args, depth, YO_NODE_SCOPE_OP);
		printf(")%s", node->data.func.type ? " " : "");
		yoParserDumpNode(node->data.func.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_TYPE_CONTRACT_FUNC:
		printf("%s ", yoFuncOpStr(node->data.func.op));
		yoParserDumpNode(node->data.func.name, depth, YO_NODE_SCOPE_OP);
		printf(" (");
		yoParserDumpNode(node->data.func.args, depth, YO_NODE_SCOPE_OP);
		printf(")%s", node->data.func.type ? " " : "");
		yoParserDumpNode(node->data.func.type, depth, YO_NODE_SCOPE_OP);
		break;

	case YO_NODE_TYPE_CONTRACT:
	case YO_NODE_TYPE_CLASS:
		printf("%s", node->type == YO_NODE_TYPE_CLASS ? "CLASS" : "CONTRACT");
		if (node->data.typeClass.gen) {
			printf(" <");
			yoParserDumpNode(node->data.typeClass.gen, depth, YO_NODE_SCOPE_OP);
			printf(">");
		}
		if (node->data.typeClass.extends) {
			printf(": ");
			yoParserDumpNode(node->data.typeClass.extends, depth, YO_NODE_SCOPE_OP);
		}
		printf(" {%s", node->data.typeClass.body ? "\n" : "");
		yoParserDumpNode(node->data.typeClass.body, depth + 1, YO_NODE_SCOPE_STATEMENT);
		printDepth(depth); printf("}");
		break;

	case YO_NODE_CAST:
		printf("CAST (");
		yoParserDumpNode(node->data.cast.expr, depth, YO_NODE_SCOPE_OP);
		printf(" AS "); yoParserDumpNode(node->data.cast.type, depth + 1, YO_NODE_SCOPE_OP);
		printf(")");
		break;

	case YO_NODE_SIZEOF:
		printf("SIZEOF (");
		yoParserDumpNode(node->data.sizeOf.node, depth, YO_NODE_SCOPE_OP);
		printf(")");
	}

	if (scope == YO_NODE_SCOPE_STATEMENT) {
		// printDepth(depth); 
		printf(";\n");
	}
}

void YoParser::dump()
{
	if (module) {
		// YO_ASSERT(root->type == YO_NODE_STATEMENT);
		yoParserDumpNode(module, 0, YO_NODE_SCOPE_STATEMENT);
	}
	else {
		printf("no module\n");
	}
}

// =====================================================================
// =====================================================================
// =====================================================================

YoParserNode * YoParser::newNode(EYoParserNodeType type, YYLTYPE * loc)
{
	return newNode(type, loc->token);
}

YoParserNode * YoParser::newNode(EYoParserNodeType type, const YoParserToken& token)
{
	YoParserNode * node = new YoParserNode();
	node->type = type;
	node->token = token;
	node->prev = NULL;
	memset(&node->data, 0, sizeof(node->data));
	
	nodes.push_back(node);
	return node;
}

YoParserNode * YoParser::newLocNode(YYLTYPE * loc)
{
	YoParserToken token;
	token.line = loc->last_line;
	token.str = lines[loc->last_line - 1] + loc->last_column - 1;
	token.len = 1;
	return newNode(YO_NODE_LOC, token);
}

// =====================================================================
// =====================================================================
// =====================================================================

YoParserStackElement::YoParserStackElement()
{
	op = 0;
	node = NULL;
}

// =====================================================================
// =====================================================================
// =====================================================================

/* void yoParserEnd(YoParserStackElement * elem, void * parm)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!parser->root);
	parser->root = elem->node;
} */

/* void yoParserLocation(YYSTYPE * elem, YYLTYPE * loc, void * parm)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm); (void*)parser;
	elem->loc = *loc;
} */

void yoParserModule(YYSTYPE * r, YYSTYPE * name, YYSTYPE * body, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!parser->module);
	YO_ASSERT(name && name->node && name->node->type == YO_NODE_NAME); // && body && body->node);
	YO_ASSERT(body);
	YoParserNode * node = parser->newNode(YO_NODE_MODULE, loc);
	node->data.module.name = name->node;
	node->data.module.body = body->node;
	// node->token = name->node->token;
	parser->module = node;
	r->node = node;
}

void yoParserImport(YYSTYPE * r, YYSTYPE * name, YYSTYPE * path, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!name || name->node && name->node->type == YO_NODE_NAME);
	YO_ASSERT(path && path->node && (path->node->type == YO_NODE_SINGLE_QUOTED_STRING || path->node->type == YO_NODE_QUOTED_STRING));
	YoParserNode * node = parser->newNode(YO_NODE_IMPORT, loc);
	node->data.import.name = name ? name->node : NULL;
	node->data.import.path = path->node;
	// node->token = name ? name->node->token : path->node->token;
	r->node = node;
}

void yoParserList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
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

void yoParserAssign(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(op == T_ASSIGN || op == T_INIT_ASSIGN || op == T_PROP_ASSIGN);
	YO_ASSERT(a->node);
	YO_ASSERT(b->node);
	YoParserNode * node = NULL;
	node = parser->newNode(YO_NODE_ASSIGN, loc);
	node->data.assign.op = op;
	node->data.assign.left = a->node;
	node->data.assign.right = b->node;
	r->node = node;
}

void yoParserBinOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(op != T_ASSIGN && op != T_INIT_ASSIGN && op != T_PROP_ASSIGN);
	YO_ASSERT(a->node);
	YO_ASSERT(b->node);
	YoParserNode * node = NULL;
	if (op == T_CONCAT) {
		if (a->node->type == YO_NODE_CONCAT) {
			node = a->node;
			a->node = a->node->data.concat.values;
		}
		if (b->node->type == YO_NODE_CONCAT) {
			if (!node) {
				node = b->node;
			}
			else{
				b->node->type = YO_NODE_EMPTY;
			}
			b->node = b->node->data.concat.values;
		}
		if ((a->node->type == YO_NODE_SINGLE_QUOTED_STRING || a->node->type == YO_NODE_QUOTED_STRING) && a->node->token.len == 2) {
			// it's empty const string, skip concat
			r->node = b->node;
		}
		else if ((b->node->type == YO_NODE_SINGLE_QUOTED_STRING || b->node->type == YO_NODE_QUOTED_STRING) && b->node->token.len == 2) {
			// it's empty const string, skip concat
			r->node = a->node;
		}
		else {
			yoParserList(r, a, b, parm, loc);
		}
		if (!node) {
			node = parser->newNode(YO_NODE_CONCAT, loc);
		}
		node->data.concat.values = r->node;
		// node->token = a->node->token;
		r->node = node;
		return;
	}
	node = parser->newNode(YO_NODE_BIN_OP, loc);
	node->data.binOp.op = op;
	node->data.binOp.left = a->node;
	node->data.binOp.right = b->node;
	// node->token = a->node->token;
	r->node = node;
}

void yoParserConst(YYSTYPE * r, int op, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	switch (op) {
	default:
		YO_ASSERT(false);
		// no break

	case T_NULL:
		r->node = parser->newNode(YO_NODE_CONST_NULL, loc);
		break;

	case T_TRUE:
		r->node = parser->newNode(YO_NODE_CONST_TRUE, loc);
		break;

	case T_FALSE:
		r->node = parser->newNode(YO_NODE_CONST_FALSE, loc);
		break;
	}
}

void yoParserTypeStdName(YYSTYPE * r, int op, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_STD_NAME, loc);
	node->data.typeStdName = op;
	r->node = node;
}

void yoParserTypeName(YYSTYPE * r, YYSTYPE * name, YYSTYPE * gen, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(name && gen);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_NAME, loc);
	node->data.typeName.name = name->node;
	node->data.typeName.gen = gen->node;
	r->node = node;
}

void yoParserTypeNameDef(YYSTYPE * r, YYSTYPE * name, YYSTYPE * def, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(name && def);
	YO_ASSERT(name->node && name->node->type == YO_NODE_TYPE_NAME);
	YoParserNode * node = name->node;
	node->data.typeName.def = def->node;
	r->node = node;
}

void yoParserTypeConst(YYSTYPE * r, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_CONST, loc);
	node->data.typeConst.type = type->node;
	r->node = node;
}

void yoParserTypeMutable(YYSTYPE * r, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_MUTABLE, loc);
	node->data.typeMutable.type = type->node;
	r->node = node;
}

void yoParserTypeChan(YYSTYPE * r, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_CHAN, loc);
	node->data.typeChan.type = type->node;
	r->node = node;
}

void yoParserTypePtr(YYSTYPE * r, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_PTR, loc);
	node->data.typePtr.type = type->node;
	r->node = node;
}

void yoParserTypeRef(YYSTYPE * r, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_REF, loc);
	node->data.typeRef.type = type->node;
	r->node = node;
}

void yoParserTypeSlice(YYSTYPE * r, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_SLICE, loc);
	node->data.typeSlice.type = type->node;
	r->node = node;
}

bool YoParserNode::isType() const
{
	return type == YO_NODE_TYPE_NAME || type == YO_NODE_TYPE_STD_NAME || type == YO_NODE_TYPE_MUTABLE
		|| type == YO_NODE_TYPE_CONST || type == YO_NODE_TYPE_CHAN || type == YO_NODE_TYPE_REF
		|| type == YO_NODE_TYPE_PTR || type == YO_NODE_TYPE_SLICE || type == YO_NODE_TYPE_ARR
		|| type == YO_NODE_TYPE_CLASS || type == YO_NODE_TYPE_CONTRACT || type == YO_NODE_TYPE_FUNC
		|| type == YO_NODE_NAME;
}

void yoParserTypeArr(YYSTYPE * r, YYSTYPE * size, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(size->node && (size->node->type == YO_NODE_CONST_INT || size->node->type == YO_NODE_NAME || size->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_ARR, loc);
	node->data.typeArr.type = type->node;
	node->data.typeArr.size = size->node;
	r->node = node;
}

void yoParserNewArr(YYSTYPE * r, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = parser->newNode(YO_NODE_NEW_ARR_EXPS, loc);
	r->node = node;
}

void yoParserNewArrExps(YYSTYPE * r, YYSTYPE * expr_list, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(expr_list->node);
	YoParserNode * node = parser->newNode(YO_NODE_NEW_ARR_EXPS, loc);
	node->data.arr.values = expr_list->node;
	r->node = node;
}

void yoParserNewObj(YYSTYPE * r, YYSTYPE * name, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YoParserNode * node = parser->newNode(YO_NODE_NEW_OBJ_EXPS, loc);
	node->data.obj.name = name->node;
	r->node = node;
}

void yoParserNewObjExps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * expr_list, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(expr_list->node);
	YoParserNode * node = parser->newNode(YO_NODE_NEW_OBJ_EXPS, loc);
	node->data.obj.name = name->node;
	node->data.obj.values = expr_list->node;
	r->node = node;
}

void yoParserNewObjProps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * prop_list, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(prop_list->node);
	YoParserNode * node = parser->newNode(YO_NODE_NEW_OBJ_PROPS, loc);
	node->data.obj.name = name->node;
	node->data.obj.values = prop_list->node;
	r->node = node;
}

void yoParserDeclVar(YYSTYPE * r, bool isMutable, YYSTYPE * name, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!type || !type->node || (type->node && type->node->isType()));
	YO_ASSERT(name->node && name->node->type == YO_NODE_NAME);
	YoParserNode * node = parser->newNode(YO_NODE_DECL_VAR, loc);
	node->data.declVar.isMutable = isMutable;
	node->data.declVar.type = type ? type->node : NULL;
	node->data.declVar.name = name->node;
	// node->token = name->node->token;
	r->node = node;
}

void yoParserDeclArg(YYSTYPE * r, bool isMutable, YYSTYPE * name, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YO_ASSERT(name->node && name->node->type == YO_NODE_NAME);
	YoParserNode * node = parser->newNode(YO_NODE_DECL_ARG, loc);
	node->data.declVar.isMutable = isMutable;
	node->data.declVar.type = type->node;
	node->data.declVar.name = name->node;
	// node->token = name->node->token;
	r->node = node;
}

void yoParserDeclType(YYSTYPE * r, YYSTYPE * name, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(type->node && type->node->isType());
	YO_ASSERT(name->node && name->node->type == YO_NODE_NAME);
	YoParserNode * node = parser->newNode(YO_NODE_DECL_TYPE, loc);
	node->data.declType.type = type->node;
	node->data.declType.name = name->node;
	// node->token = name->node->token;
	r->node = node;
}

void yoParserSizeOf(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(a && a->node);
	YoParserNode * node = parser->newNode(YO_NODE_SIZEOF, loc);
	node->data.sizeOf.node = a->node;
	r->node = node;
}

void yoParserUnaryOp(YYSTYPE * r, YYSTYPE * a, int op, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(a && a->node);
	YoParserNode * node = parser->newNode(YO_NODE_UNARY_OP, loc);
	node->data.unaryOp.op = op;
	node->data.unaryOp.node = a->node;
	r->node = node;
}

void yoParserDotName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(a->node && (a->node->type == YO_NODE_NAME || a->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(b->node && b->node->type == YO_NODE_NAME);
	// a->node->type = YO_NODE_DOTNAME;
	b->node->type = YO_NODE_DOTNAME;
	b->node->data.dotName.node = a->node;
	r->node = b->node;
}

void yoParserNewLine(void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	parser->setLine(parser->cursor, parser->line + 1);
}

void yoLexNewLine(void * parm, YYLTYPE * loc)
{
	yoParserNewLine(parm, loc);
}

void yoParseEmpty(YYSTYPE * r, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	r->node = NULL;
	r->op = 0;
	// YO_ASSERT(r->node == NULL);
}

void yoParserCast(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(expr && expr->node);
	YO_ASSERT(type && type->node && type->node->isType());
	YoParserNode * node = parser->newNode(YO_NODE_CAST, loc);
	node->data.cast.expr = expr->node;
	node->data.cast.type = type->node;
	// node->token = expr->node->token;
	r->node = node;
}

void yoParserDeclFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, bool isVarArg, EYoCallingConv conv, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(body || op == T_EXTERN_FUNC);
	YO_ASSERT(!type || !type->node || type->node->isType());
	YO_ASSERT(!name || name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	// YO_ASSERT(args->node && args->node->type == );
	// YO_ASSERT(body->node && body->node->type == YO_NODE_TYPE);
	YoParserNode * node = parser->newNode(YO_NODE_DECL_FUNC, loc);
	node->data.func.op = op;
	node->data.func.self = self ? self->node : NULL;
	node->data.func.type = type ? type->node : NULL;
	node->data.func.name = name ? name->node : NULL;
	node->data.func.args = args ? args->node : NULL;
	node->data.func.body = body ? body->node : NULL;
	node->data.func.end = parser->newLocNode(loc);
	node->data.func.isVarArg = isVarArg;
	node->data.func.conv = conv;
	// node->token = name ? name->node->token : args->node->token;
	r->node = node;
}

void yoParserDeclFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, void * parm, YYLTYPE * loc)
{
	yoParserDeclFunc(r, op, self, name, args, type, body, false, YO_CALLING_DEFAULT, parm, loc);
}

void yoParserTypeFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * args, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!type || (type->node && type->node->isType()));
	// YO_ASSERT(args->node && args->node->type == );
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_FUNC, loc);
	node->data.func.op = op;
	node->data.func.self = self ? self->node : NULL;
	node->data.func.type = type ? type->node : NULL;
	node->data.func.args = args->node;
	// node->token = args->node->token;
	r->node = node;
}

void yoParserContractFunc(YYSTYPE * r, int op, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(!type || (type->node && type->node->isType()));
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	// YO_ASSERT(args->node && args->node->type == );
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_CONTRACT_FUNC, loc);
	node->data.func.op = op;
	node->data.func.type = type ? type->node : NULL;
	node->data.func.name = name->node;
	node->data.func.args = args->node;
	// node->token = name->node->token;
	r->node = node;
}

void yoParserCall(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME 
		|| (name->node->type == YO_NODE_BIN_OP && name->node->data.binOp.op == T_DOT)));
	// YO_ASSERT(args->node && args->node->type == );
	YoParserNode * node = parser->newNode(YO_NODE_CALL, loc);
	node->data.call.name = name->node;
	node->data.call.args = args->node;
	// node->token = name->node->token;
	r->node = node;
}

void yoParserCatchElem(YYSTYPE * r, YYSTYPE * name, YYSTYPE * stmt, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(name && name->node && name->node->type == YO_NODE_NAME);
	YO_ASSERT(stmt && stmt->node);
	YoParserNode * node = parser->newNode(YO_NODE_CATCH_ELEM, loc);
	node->data.stmtCatch.catchName = name->node;
	node->data.stmtCatch.catchStmt = stmt->node;
	node->data.stmtCatch.stmt = NULL;
	// node->token = stmt->node->token;
	r->node = node;
}

void yoParserStmtCatch(YYSTYPE * r, YYSTYPE * stmt, YYSTYPE * catchElem, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(catchElem);
	if (catchElem->node) {
		YO_ASSERT(catchElem->node->type == YO_NODE_CATCH_ELEM);
		YoParserNode * node = catchElem->node; //  parser->newNode(YO_NODE_STMT_CATCH, loc);
		node->type = YO_NODE_STMT_CATCH;
		node->data.stmtCatch.stmt = stmt->node;
		node->token = stmt->node->token;
		r->node = node;
	}
	else{
		r->node = stmt->node;
	}
}

void yoParserStmtReturn(YYSTYPE * r, YYSTYPE * expr, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = parser->newNode(YO_NODE_STMT_RETURN, loc);
	node->data.stmtReturn.node = expr ? expr->node : NULL;
	// node->token = expr->node->token;
	r->node = node;
}

/*
void yoParserIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseStmt, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_STMT_IF, parser);
	node->data.stmtIf.ifExpr = ifExpr->node;
	node->data.stmtIf.thenStmt = thenStmt->node;
	node->data.stmtIf.elseStmt = elseStmt->node;
	node->token = ifExpr->node->token;
	r->node = node;
}
*/

void yoParserStmtIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseIfList, YYSTYPE * elseStmt, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	if (elseIfList) {
		while (elseIfList->node) {
			YO_ASSERT(elseIfList->node->type == YO_NODE_ELSEIF);
			YoParserNode * node = elseIfList->node;
			YoParserNode * _ifExpr = node->data.elseIfElem.expr;
			YoParserNode * _thenStmt = node->data.elseIfElem.node;
			node->type = YO_NODE_STMT_IF;
			node->data.stmtIf.ifExpr = _ifExpr;
			node->data.stmtIf.thenStmt = _thenStmt;
			if (!elseStmt->node) {
				node->data.stmtIf.elseStmt = NULL;
			}else if (elseStmt->node->type == YO_NODE_ELSE) {
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
	YoParserNode * node = parser->newNode(YO_NODE_STMT_IF, loc);
	node->data.stmtIf.ifExpr = ifExpr->node;
	node->data.stmtIf.thenStmt = thenStmt->node;
	node->data.stmtIf.elseStmt = elseStmt->node;
	// node->token = ifExpr->node->token;
	r->node = node;
}

void yoParserElseIf(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * stmt, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = parser->newNode(YO_NODE_ELSEIF, loc);
	node->data.elseIfElem.expr = expr->node;
	node->data.elseIfElem.node = stmt->node;
	// node->token = expr->node->token;
	r->node = node;
}

void yoParserElse(YYSTYPE * r, YYSTYPE * stmt, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YoParserNode * node = parser->newNode(YO_NODE_ELSE, loc);
	node->data.elseElem.node = stmt->node;
	// node->token = stmt->node->token;
	r->node = node;
}

void yoParserContract(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * extends, YYSTYPE * body, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(gen && extends && body);
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_CONTRACT, loc);
	node->data.typeClass.gen = gen->node;
	node->data.typeClass.extends = extends->node;
	node->data.typeClass.body = body->node;
	r->node = node;
}

void yoParserClass(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * extends, YYSTYPE * body, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	YO_ASSERT(gen && extends && body);
	YoParserNode * node = parser->newNode(YO_NODE_TYPE_CLASS, loc);
	node->data.typeClass.gen = gen->node;
	node->data.typeClass.extends = extends->node;
	node->data.typeClass.body = body->node;
	r->node = node;
}

void yoParserDebug(YYSTYPE * r, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	int i = 0;
}

void yoParserError(YYSTYPE * r, const char * msg, void * parm, YYLTYPE * loc)
{
	YoParser * parser = dynamic_cast<YoParser*>((YoParser*)parm);
	if (!parser->isError()) {
		parser->error = YoParser::ERROR_SYNTAX;
		parser->errorMsg = msg;
		parser->errorLoc = *loc;
		// parser->errorCursor = parser->text;
		// parser->errorLineStart = parser->lineStart;
		parser->errorLine = parser->line;
		parser->errorLinePos = parser->text - parser->lineStart;
	}

	r->node = NULL;
	r->op = 0;
	parser->cursor = parser->limit;
}

// =====================================================================
// =====================================================================
// =====================================================================
