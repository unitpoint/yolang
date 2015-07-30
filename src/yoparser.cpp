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
	init(_input, strlen(input));
}

void YoParserParams::init(const char * _input, int len)
{
	input = _input;
	limit = input + len;
	lineStart = input;
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
	YO_NODE_SCOPE_STATEMENT,
	YO_NODE_SCOPE_OP,
	YO_NODE_SCOPE_PROPS,
	YO_NODE_SCOPE_TYPE,
	YO_NODE_SCOPE_DOTNAME,
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
	else if (node->prev) {
		printf(", ");
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

void yoParserNewArrExps(YYSTYPE * r, YYSTYPE * exp_list, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(exp_list->node);
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_ARR_EXPS, parser);
	node->data.arr.values = exp_list->node;
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

void yoParserNewObjExps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * exp_list, void * parm)
{
	YoParserParams * parser = dynamic_cast<YoParserParams*>((YoParserParams*)parm);
	YO_ASSERT(name->node && (name->node->type == YO_NODE_NAME || name->node->type == YO_NODE_DOTNAME));
	YO_ASSERT(exp_list->node);
	YoParserNode * node = new YoParserNode(YO_NODE_NEW_OBJ_EXPS, parser);
	node->data.obj.name = name->node;
	node->data.obj.values = exp_list->node;
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

void yoParserError(YYSTYPE * r, void * parm)
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
}

// =====================================================================
// =====================================================================
// =====================================================================
