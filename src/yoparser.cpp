#include <stdio.h>
#include <string.h>
#include "yolang.h"

// =====================================================================
// =====================================================================
// =====================================================================

// int yywrap() { return 1; }

void yoerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
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

int yoLexChar(void * parm, YYSTYPE * node)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	return parser->text[0];
}

// =====================================================================
// =====================================================================
// =====================================================================

void YoParserParams::init(const char * _input)
{
	input = _input;
	limit = input + strlen(input);
	line = 1;
	state = yycST_IN_YOLANG;
	condition = 0;
	ch = 0;
	accept = 0;
	cursor = input;
	text = input;
	textLen = 0;
	marker = input;
	list = NULL;
	root = NULL;
}

void YoParserParams::shutdown()
{
	while (list) {
		YoParserNode * node = list;
		list = node->parserNext;
		node->parserNext = NULL;
		delete node;
	}
}

enum EYoParserNodeScopeType {
	YO_NODE_SCOPE_OP,
	YO_NODE_SCOPE_STATEMENT,
};

static void yoParserDumpNode(YoParserNode * node, int depth, EYoParserNodeScopeType scope)
{
	if (!node) {
		return;
	}
	int i;
	char * name;

	yoParserDumpNode(node->prev, depth, scope);

	if (scope == YO_NODE_SCOPE_STATEMENT) {
		for (i = 0; i < depth; i++) {
			printf("  ");
		}
	}

	switch (node->type) {
	default:
		YO_ASSERT(false);
		break;

	case YO_NODE_INT:
		printf("INT %d", node->data.ival);
		break;

	case YO_NODE_DOUBLE:
		printf("DOUBLE %lf", node->data.dval);
		break;

	case YO_NODE_NAME:
		name = (char*)alloca(node->token.len + 1);
		memcpy(name, node->token.str, node->token.len);
		name[node->token.len] = '\0';
		printf("NAME '%s'", name);
		break;

	case YO_NODE_BIN_OP:
		if (scope != YO_NODE_SCOPE_STATEMENT) {
			printf("(");
		}
		yoParserDumpNode(node->data.binOp.nodes[0], depth, YO_NODE_SCOPE_OP);
		printf(" %s ", yoTokenName(node->data.binOp.op));
		yoParserDumpNode(node->data.binOp.nodes[1], depth, YO_NODE_SCOPE_OP);
		if (scope != YO_NODE_SCOPE_STATEMENT) {
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

	case YO_NODE_TYPE:
		printf("TYPE ");
		if (node->data.type.stdTypeOp) {
			YO_ASSERT(!node->data.type.name && !node->data.type.pakage);
			printf("%s", yoTokenName(node->data.type.stdTypeOp));
		}
		else {
			if (node->data.type.pakage) {
				YO_ASSERT(node->data.type.pakage->type == YO_NODE_NAME);
				yoParserDumpNode(node->data.type.pakage, depth, YO_NODE_SCOPE_OP);
				printf(" . ");
			}
			YO_ASSERT(node->data.type.name && node->data.type.name->type == YO_NODE_NAME);
			yoParserDumpNode(node->data.type.name, depth, YO_NODE_SCOPE_OP);
		}
		switch (node->data.type.spec) {
		case YO_TYPE_SPEC_VALUE:
			YO_ASSERT(!node->data.type.arrSize);
			break;

		case YO_TYPE_SPEC_PTR:
			YO_ASSERT(!node->data.type.arrSize);
			printf("*");
			break;

		case YO_TYPE_SPEC_SLICE:
			YO_ASSERT(!node->data.type.arrSize);
			printf("[]");
			break;

		case YO_TYPE_SPEC_ARRAY:
			YO_ASSERT(node->data.type.arrSize > 0);
			printf("[%d]", node->data.type.arrSize);
			break;
		}
		break;

	case YO_NODE_DECL_VAR:
		printf("VAR ");
		yoParserDumpNode(node->data.declVar.type, depth, YO_NODE_SCOPE_OP);
		printf(" ");
		yoParserDumpNode(node->data.declVar.name, depth, YO_NODE_SCOPE_OP);
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
	node->data.binOp.nodes[0] = a->node;
	node->data.binOp.nodes[1] = b->node;
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

void yoParserStdTypeName(YYSTYPE * r, int op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_NAME, parser);
	node->data.type.stdTypeOp = op;
	r->node = node;
}

void yoParserTypeName(YYSTYPE * r, YYSTYPE * a, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node && a->node->type == YO_NODE_NAME);
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_NAME, parser);
	node->data.type.name = a->node;
	r->node = node;
}

void yoParserPkgTypeName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node && a->node->type == YO_NODE_NAME);
	YO_ASSERT(b->node && b->node->type == YO_NODE_NAME);
	YoParserNode * node = new YoParserNode(YO_NODE_TYPE_NAME, parser);
	node->data.type.pakage = a->node;
	node->data.type.name = b->node;
	r->node = node;
}

void yoParserTypeSpec(YYSTYPE * r, YYSTYPE * a, EYoParserTypeSpec spec, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node && a->node->type == YO_NODE_TYPE_NAME);
	YoParserNode * node = a->node;
	node->type = YO_NODE_TYPE;
	node->data.type.spec = spec;
	node->data.type.arrSize = 0;
	r->node = node;
}

void yoParserTypeArray(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node && a->node->type == YO_NODE_TYPE_NAME);
	YO_ASSERT(b->node && b->node->type == YO_NODE_INT);
	YoParserNode * node = a->node;
	node->type = YO_NODE_TYPE;
	node->data.type.spec = YO_TYPE_SPEC_ARRAY;
	node->data.type.arrSize = b->node->data.ival;
	r->node = node;
}

void yoParserDeclVar(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node && a->node->type == YO_NODE_TYPE);
	YO_ASSERT(b->node && b->node->type == YO_NODE_NAME);
	YoParserNode * node = new YoParserNode(YO_NODE_DECL_VAR, parser);
	node->data.declVar.type = a->node;
	node->data.declVar.name = b->node;
	node->token = r->node->token;
	r->node = node;
}

void yoParserBeginUnaryOp(YYSTYPE * r, int op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YoParserNode * node = new YoParserNode(YO_NODE_UNARY_OP, parser);
	node->data.unaryOp.op = op;
	r->node = node;
}

void yoParserEndUnaryOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * op, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(a->node);
	YO_ASSERT(op->node && op->node->type == YO_NODE_UNARY_OP);
	YoParserNode * node = op->node;
	node->data.unaryOp.node = a->node;
	r->node = node;
}

void yoParserStatementList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	if (a->node) {
		YoParserNode * cur = b->node;
		while (cur->prev) {
			cur = cur->prev;
		}
		cur->prev = a->node;
	}
	r->node = b->node;
}

/*
void yoParserMakeStatement(YYSTYPE * r, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(r->node);
	YoParserNode * node = new YoParserNode(YO_NODE_STATEMENT, parser);
	node->data.stmt.node = r->node;
	node->token = r->node->token;
	r->node = node;
}
*/

void yoParserNewLine(void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	parser->line++;
}

// =====================================================================
// =====================================================================
// =====================================================================
