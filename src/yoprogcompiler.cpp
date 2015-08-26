#include "yolang.h"

// ==============================================================
// ==============================================================
// ==============================================================

YoProgCompiler::Type::Type(const std::string& p_name, EType p_etype, int p_size, YoParserNode * p_node) : name(p_name)
{
	parserNode = p_node;
	etype = p_etype;
	size = p_size;
	// isGeneric = false;
}

YoProgCompiler::Type::~Type()
{
}

// ==============================================================

YoProgCompiler::SubType::SubType(const std::string& p_name, EType p_etype, int p_size, Type * p_subType, YoParserNode * p_node) :
Type(p_name, p_etype, p_size, p_node)
{
	subType = p_subType;
}

// ==============================================================

YoProgCompiler::Variable::Variable(const std::string& p_name, YoParserNode * p_node): name(p_name)
{
	parserNode = p_node;
	type = NULL;
	index = -1;
	// isClosure = false;
}

// ==============================================================

YoProgCompiler::Scope::Scope(Scope * p_parent, EScope p_escope, YoParserNode * p_node)
{
	parserNode = p_node;
	parent = p_parent;
	escope = p_escope;
}

YoProgCompiler::Scope::~Scope()
{
	std::vector<Variable*>::iterator it = vars.begin();
	for (; it != vars.end(); ++it) {
		delete *it;
	}
	// vars.clear();
}

// ==============================================================

YoProgCompiler::Function::Function(Scope * p_parent, const std::string& p_name, YoParserNode * p_node): 
	Scope(p_parent, SCOPE_FUNCTION, p_node), name(p_name)
{
	resType = NULL;
	argsNumber = 0;
	// isGeneric = false;
}

YoProgCompiler::Function::~Function()
{
}

// ==============================================================

YoProgCompiler::Module::Module(const std::string& p_name, YoParserNode * p_node) : Scope(NULL, SCOPE_MODULE, p_node), name(p_name)
{
}

YoProgCompiler::Module::~Module()
{
	std::vector<Function*>::iterator fit = funcs.begin();
	for (; fit != funcs.end(); ++fit) {
		Function * func = *fit;
		delete func;
	}
}

// ==============================================================

YoProgCompiler::NameAccess::NameAccess()
{
	scope = NULL;
	upCount = 0;
	var = NULL;
	ename = NAME_UNKNOWN;
}

// ==============================================================

YoProgCompiler::Expression::Expression(EOperation p_op, YoParserNode * p_node)
{
	parserNode = p_node;
	type = NULL;
	op = p_op;
}

YoProgCompiler::Expression::~Expression()
{
	std::vector<Expression*>::iterator it = list.begin();
	for (; it != list.end(); ++it) {
		Expression * expr = *it;
		delete expr;
	}
}

// ==============================================================
// ==============================================================
// ==============================================================

YoProgCompiler::YoProgCompiler(YoParser * p)
{
	parser = p;
	initConvertOps();
}

YoProgCompiler::~YoProgCompiler()
{
	// YO_ASSERT(!module);
}

bool YoProgCompiler::run()
{
#if 0
	if (parser->error) {
		set parser error;
		return false;
	}
#endif
	if (parser->module) {
		return compileModule(parser->module);
	}
	// set error: no module
	return false;
}

void YoProgCompiler::collectNodesInReversList(std::vector<YoParserNode*>& out, YoParserNode * node)
{
	int count = 0;
	for (YoParserNode * cur = node; cur; cur = cur->prev){
		count++;
	}
	out.reserve(out.size() + count);
	while (node) {
		out.push_back(node);
		node = node->prev;
	}
}

std::string YoProgCompiler::getTokenStr(YoParserNode * node)
{
	return std::string(node->token.str, node->token.len);
}

bool YoProgCompiler::compileModule(YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_MODULE);
	YO_ASSERT(node->data.module.name && node->data.module.name->type == YO_NODE_NAME);
	Module * module = new Module(getTokenStr(node->data.module.name), node);
	modules.push_back(module);
	
	std::vector<YoParserNode*> list;
	collectNodesInReversList(list, node->data.module.body);

	std::vector<YoParserNode*>::reverse_iterator it = list.rbegin();
	for (; it != list.rend(); ++it){
		YoParserNode * stmt = *it;
		switch (stmt->type) {
		case YO_NODE_DECL_FUNC:
			if (!compileModuleFunc(module, stmt)) {
				return false;
			}
			break;

		default:
			fprintf(stderr, "Error module node: %d\n", (int)stmt->type);
			YO_ASSERT(false);
			exit(1);
		}
	}
	return true;
}

YoProgCompiler::Type * YoProgCompiler::getIntType(int bits, bool isSigned)
{
	switch (bits) {
	case 8: return getPrimitiveType(isSigned ? T_INT8 : T_UINT8);
	case 16: return getPrimitiveType(isSigned ? T_INT16 : T_UINT16);
	case 32: return getPrimitiveType(isSigned ? T_INT32 : T_UINT32);
	case 64: return getPrimitiveType(isSigned ? T_INT64 : T_UINT64);
	}
	YO_ASSERT(false);
	return NULL;
}

YoProgCompiler::Type * YoProgCompiler::getPrimitiveType(int stdType)
{
	std::string name;
	EType etype = TYPE_VOID;
	int size = 0;
	switch (stdType) {
	case T_VOID: name = "void"; etype = TYPE_VOID; size = 0; break;
	case T_BOOL: name = "bool"; etype = TYPE_BOOL; size = 1; break;
	case T_INT8: name = "int8"; etype = TYPE_INT8; size = 1; break;
	case T_INT16: name = "int16"; etype = TYPE_INT16; size = 2; break;
	case T_INT32: name = "int32"; etype = TYPE_INT32; size = 4; break;
	case T_INT64: name = "int64"; etype = TYPE_INT64; size = 8; break;
	case T_UINT8: name = "uint8"; etype = TYPE_UINT8; size = 1; break;
	case T_UINT16: name = "uint16"; etype = TYPE_UINT16; size = 2; break;
	case T_UINT32: name = "uint32"; etype = TYPE_UINT32; size = 4; break;
	case T_UINT64: name = "uint64"; etype = TYPE_UINT64; size = 8; break;
	case T_FLOAT32: name = "float32"; etype = TYPE_FLOAT32; size = 4; break;
	case T_FLOAT64: name = "float64"; etype = TYPE_FLOAT64; size = 8; break;
	default:
		fprintf(stderr, "Error std name type: %d\n", stdType);
		YO_ASSERT(false);
		exit(1);
		break;
	}
	std::map<std::string, Type*>::iterator it = progTypes.find(name);
	if (it == progTypes.end()) {
		Type * type = new Type(name, etype, size, NULL);
		progTypes[name] = type;
		return type;
	}
	YO_ASSERT(it->second->name == name && it->second->etype == etype && it->second->size == size);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getType(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node);
	switch (node->type) {
	case YO_NODE_TYPE_MUTABLE: {
		Type * type = getType(scope, node->data.typeMutable.type);
		if (type) {
			std::string name = std::string("mut ") + type->name;
			std::map<std::string, Type*>::iterator it = progTypes.find(name);
			if (it == progTypes.end()) {
				type = new SubType(name, TYPE_MUT, sizeof(void*), type, node);
				progTypes[name] = type;
				return type;
			}
			YO_ASSERT(dynamic_cast<SubType*>(it->second));
			YO_ASSERT(it->second->name == name && it->second->etype == TYPE_MUT && ((SubType*)it->second)->subType == type);
			return it->second;
		}
		YO_ASSERT(false);
		return NULL;
	}
	case YO_NODE_TYPE_PTR: {
		Type * type = getType(scope, node->data.typePtr.type);
		if (type) {
			std::string name = std::string("*") + type->name;
			std::map<std::string, Type*>::iterator it = progTypes.find(name);
			if (it == progTypes.end()) {
				type = new SubType(name, TYPE_PTR, sizeof(void*), type, node);
				progTypes[name] = type;
				return type;
			}
			YO_ASSERT(dynamic_cast<SubType*>(it->second));
			YO_ASSERT(it->second->name == name && it->second->etype == TYPE_PTR && ((SubType*)it->second)->subType == type);
			return it->second;
		}
		YO_ASSERT(false);
		return NULL;
	}
	case YO_NODE_TYPE_STD_NAME:
		return getPrimitiveType(node->data.typeStdName);
	}
	fprintf(stderr, "Error type: %d\n", (int)node->type);
	YO_ASSERT(false);
	exit(1);
}

bool YoProgCompiler::compileDeclVar(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_VAR);

	YO_ASSERT(node->data.declVar.name && node->data.declVar.name->type == YO_NODE_NAME);
	Variable * var = new Variable(getTokenStr(node->data.declVar.name), node);
	scope->vars.push_back(var);

	YO_ASSERT(node->data.declVar.type && node->data.declVar.type->isType());
	var->type = getType(scope, node->data.declVar.type);
	YO_ASSERT(var->type);

	return true;
}

bool YoProgCompiler::findName(NameAccess& out, Scope * scope, const std::string& name)
{
	for (int upCount = 0; scope; upCount++) {
		std::vector<Variable*>::reverse_iterator it = scope->vars.rbegin();
		for (; it != scope->vars.rend(); ++it) {
			Variable * var = *it;
			if (var->name == name) {
				out.scope = scope;
				out.var = var;
				out.upCount = upCount;
				if (scope->escope == SCOPE_MODULE) {
					out.ename = NAME_MODULE_VAR;
				}else if (upCount > 0) {
					YO_ASSERT(scope->escope == SCOPE_FUNCTION);
					out.ename = NAME_PARENT_FUNC_VAR;
				}
				else{
					out.ename = NAME_FUNC_VAR;
				}
				return true;
			}
		}
		scope = scope->parent;
	}
	out.ename = NAME_UNKNOWN;
	out.scope = NULL;
	out.var = NULL;
	out.upCount = 0;
	return false;
}

YoProgCompiler::Expression * YoProgCompiler::compileExpr(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node);
	std::string name;
	Expression * expr;
	NameAccess nameAccess;
	switch (node->type) {
	case YO_NODE_CONST_INT:
		expr = new Expression(OP_CONST_INT, node);
		expr->constInt.ival64 = node->data.constInt.ival64;
		expr->constInt.bits = node->data.constInt.bits;
		expr->constInt.isSigned = node->data.constInt.isSigned;
		expr->type = getIntType(expr->constInt.bits, expr->constInt.isSigned);
		return expr;

	case YO_NODE_NAME: 
		name = getTokenStr(node);
		if (!findName(nameAccess, scope, name)) {
			// TODO: set error
			fprintf(stderr, "Name not found: %s\n", name.c_str());
			YO_ASSERT(false);
			exit(1);
			return NULL;
		}
		YO_ASSERT(nameAccess.ename == NAME_FUNC_VAR && nameAccess.var);
		expr = new Expression(OP_READ_LOCAL, node);
		expr->nameAccess = nameAccess;
		expr->type = nameAccess.var->type;
		return expr;

	case YO_NODE_BIN_OP:
		return compileBinOp(scope, node);
	}
	fprintf(stderr, "Error node type: %d\n", (int)node->type);
	YO_ASSERT(false);
	exit(1);
	return NULL;
}

bool YoProgCompiler::addStmt(Scope * scope, Expression * expr)
{
	YO_ASSERT(scope->escope != SCOPE_MODULE);
	if (!expr) {
		return false;
	}
	while (scope->escope == SCOPE_BLOCK) {
		scope = scope->parent;
		YO_ASSERT(scope);
	}
	YO_ASSERT(scope->escope == SCOPE_FUNCTION);
	Function * func = dynamic_cast<Function*>(scope);
	YO_ASSERT(func);
	func->ops.push_back(expr);
	return true;
}

YoProgCompiler::Function * YoProgCompiler::getFunction(Scope * scope)
{
	YO_ASSERT(scope->escope != SCOPE_MODULE);
	while (scope->escope == SCOPE_BLOCK) {
		scope = scope->parent;
		YO_ASSERT(scope);
	}
	YO_ASSERT(scope->escope == SCOPE_FUNCTION);
	Function * func = dynamic_cast<Function*>(scope);
	YO_ASSERT(func);
	return func;
}

YoProgCompiler::Expression * YoProgCompiler::compileAssignOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP && node->data.binOp.op == T_ASSIGN);

	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);
	Expression * left = compileExpr(scope, node->data.binOp.left);
	if (!left) {
		return NULL;
	}
	Expression * right = compileExpr(scope, node->data.binOp.right);
	if (!right) {
		delete left;
		return NULL;
	}
	YO_ASSERT(left->op == OP_READ_LOCAL);
	left->op = OP_WRITE_LOCAL;
	left->list.push_back(right);
	return left;
}

YoProgCompiler::Expression * YoProgCompiler::compileBinOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);

	// Expression * expr;
	EOperation op = OP_NOP;
	switch (node->data.binOp.op) {
	case T_ASSIGN:
		return compileAssignOp(scope, node);

	case T_PLUS:
		op = OP_BIN_ADD;
		break;

	default:
		fprintf(stderr, "Error bin op: %d\n", (int)node->data.binOp.op);
		YO_ASSERT(false);
		exit(1);
		return NULL;
	}
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);
	Expression * left = compileExpr(scope, node->data.binOp.left);
	if (!left) {
		return NULL;
	}
	Expression * right = compileExpr(scope, node->data.binOp.right);
	if (!right) {
		delete left;
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	if (left->type != right->type) {
		Type * resType = left->type->etype > right->type->etype ? left->type : right->type;
		Expression * newLeft = convertExprToType(scope, left, resType, false);
		Expression * newRight = convertExprToType(scope, right, resType, false);
		if (!newLeft || !newRight) {
			resType = resType != left->type ? left->type : right->type;
			newLeft = convertExprToType(scope, left, resType, true);
			newRight = convertExprToType(scope, right, resType, true);
			if (!newLeft || !newRight) {
				delete newLeft;
				delete newRight;
				return NULL;
			}
		}
		left = newLeft;
		right = newRight;
	}
	Expression * expr = new Expression(op, node);
	expr->type = left->type;
	expr->list.push_back(left);
	expr->list.push_back(right);
	return expr;
}

bool YoProgCompiler::compileStmtBinOp(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileBinOp(scope, node));
}

bool YoProgCompiler::compileStmtReturn(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_RETURN);
	Expression * value = NULL;
	if (node->data.stmtReturn.node) {
		value = compileExpr(scope, node->data.stmtReturn.node);
		if (!value) {
			return false;
		}
	}
	Expression * expr = new Expression(OP_RETURN, node);
	if (value) {
		YO_ASSERT(value->type); // && value->type == getFunction(scope)->resType);
		value = convertExprToType(scope, value, getFunction(scope)->resType, true);
		if (!value) {
			return false;
		}
		expr->list.push_back(value);
		return addStmt(scope, expr);
	}
	YO_ASSERT(getFunction(scope)->resType == getPrimitiveType(T_VOID));
	return addStmt(scope, expr);
}

int YoProgCompiler::getConvertKey(EType from, EType to)
{
	return (int)from * 1000 + (int)to;
}

void YoProgCompiler::initConvertOps()
{
	YO_ASSERT(convertOps.size() == 0);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT8, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT8)]		= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT16)]	= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT32)]	= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT64)]	= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT8)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT16)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT32)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT64)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_FLOAT32)]	= CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_FLOAT64)]	= CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT16, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT8)]	= CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT16)]	= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT32)]	= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT64)]	= CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT8)]	= CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT16)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT32)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT64)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_FLOAT32)] = CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_FLOAT64)] = CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT32, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT32)] = CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT64)] = CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT32)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT64)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT32, TYPE_FLOAT32)] = CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT32, TYPE_FLOAT64)]	= CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT64, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT32)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT64)] = CastOp(OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT32)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT64)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT64, TYPE_FLOAT32)] = CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT64, TYPE_FLOAT64)] = CastOp(OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT8, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT8)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT16)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT32)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT8)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT16)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT32)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_FLOAT32)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_FLOAT64)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT16, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT16)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT32)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT16)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT32)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_FLOAT32)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_FLOAT64)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT32, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT32)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT32)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_FLOAT32)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_FLOAT64)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT64, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT32)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT64)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT8)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT16)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT32)] = CastOp(OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT64)] = CastOp(OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_FLOAT32)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_FLOAT64)] = CastOp(OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_FLOAT32, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT8)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT16)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT32)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT64)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT8)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT16)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT32)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT64)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_FLOAT32)] = CastOp(OP_CAST_FP_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_FLOAT64)] = CastOp(OP_CAST_FP_EXT);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_FLOAT64, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT8)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT16)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT32)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT64)] = CastOp(OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT8)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT16)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT32)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT64)] = CastOp(OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_FLOAT32)] = CastOp(OP_CAST_FP_TRUNC, CAST_AUTO);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_FLOAT64)] = CastOp(OP_CAST_FP_TRUNC, CAST_AUTO);
}

YoProgCompiler::Expression * YoProgCompiler::convertExprToType(Scope * scope, Expression * expr, Type * type, bool freeOnError)
{
	YO_ASSERT(expr->type);
	if (expr->type == type) {
		return expr;
	}
	std::map<int, CastOp>::iterator it = convertOps.find(getConvertKey(expr->type->etype, type->etype));
	if (it != convertOps.end()) {
		if (it->second.castType == CAST_AUTO) {
			Expression * castExpr = new Expression(it->second.op, expr->parserNode);
			castExpr->list.push_back(expr);
			return castExpr;
		}
		if (freeOnError) {
			fprintf(stderr, "Error auto convert: %s to %s, posible lost value\n", expr->type->name.c_str(), type->name.c_str());
			YO_ASSERT(false);
			exit(1);
			delete expr;
		}
		return NULL;
	}
	if (freeOnError) {
		fprintf(stderr, "Error convert: %s to %s\n", expr->type->name.c_str(), type->name.c_str());
		YO_ASSERT(false);
		exit(1);
		delete expr;
	}
	return NULL;
}

bool YoProgCompiler::compileFuncBody(Function * func, YoParserNode * node)
{
	if (node) {
		std::vector<YoParserNode*> list;
		collectNodesInReversList(list, node);

		std::vector<YoParserNode*>::reverse_iterator it = list.rbegin();
		for (; it != list.rend(); ++it){
			YoParserNode * stmt = *it;
			switch (stmt->type) {
			case YO_NODE_DECL_VAR:
				if (!compileDeclVar(func, stmt)) {
					return false;
				}
				break;

			case YO_NODE_BIN_OP:
				if (!compileStmtBinOp(func, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_RETURN:
				if (!compileStmtReturn(func, stmt)) {
					return false;
				}
				break;

			default:
				fprintf(stderr, "Error func stmt: %d\n", (int)stmt->type);
				YO_ASSERT(false);
				exit(1);
			}
		}
	}
	return true;
}

bool YoProgCompiler::compileModuleFunc(Module * module, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_FUNC);
	YO_ASSERT(node->data.func.op == T_FUNC);

	if (node->data.func.self) {
		YO_ASSERT(false);
	}
	if (node->data.func.args) {
		YO_ASSERT(false);
	}
	std::string name;
	if (node->data.func.name) {
		name = getTokenStr(node->data.func.name);
	}
	else{

	}

	Function * func = new Function(module, name, node);
	func->resType = node->data.func.type ? getType(module, node->data.func.type) : getPrimitiveType(T_VOID);
	if (!compileFuncBody(func, node->data.func.body)) {
		delete func;
		return NULL;
	}

	int index = 0;
	std::vector<Variable*>::iterator vit = func->vars.begin();
	for (; vit != func->vars.end(); ++vit) {
		Variable * var = *vit;
		var->index = index++;
	}

	module->funcs.push_back(func);
	return func;
}