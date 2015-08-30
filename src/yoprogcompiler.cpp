#include "yolang.h"

// ==============================================================
// ==============================================================
// ==============================================================

YoProgCompiler::Type::Type(const std::string& p_name, EType p_etype, YoParserNode * p_node) : name(p_name)
{
	parserNode = p_node;
	etype = p_etype;
	// isMutable = false;
	// isGeneric = false;
	ext.index = -1;
}

YoProgCompiler::Type::~Type()
{
}

bool YoProgCompiler::Type::isFloat() const
{
	switch (etype) {
	case TYPE_FLOAT32:
	case TYPE_FLOAT64:
		return true;
	}
	return false;
}

// ==============================================================

YoProgCompiler::SubType::SubType(const std::string& p_name, EType p_etype, Type * p_subType, YoParserNode * p_node) :
	Type(p_name, p_etype, p_node)
{
	subType = p_subType;
}

YoProgCompiler::SubType::~SubType()
{
}

// ==============================================================

YoProgCompiler::StructType::StructType(const std::string& p_name, YoParserNode * p_node):
	Type(p_name, TYPE_STRUCT, p_node)
{
	isPacked = false;
}

YoProgCompiler::StructType::~StructType()
{
}

// ==============================================================

YoProgCompiler::FuncNativeType::FuncNativeType(const std::string& p_name, YoParserNode * p_node) :
	Type(p_name, TYPE_FUNC_NATIVE, p_node)
{
	resType = NULL;
}

YoProgCompiler::FuncNativeType::~FuncNativeType()
{
}

// ==============================================================

YoProgCompiler::FuncDataType::FuncDataType(const std::string& p_name, YoParserNode * p_node) :
	StructType(p_name, p_node)
{
	etype = TYPE_FUNC_DATA;
	funcNativeType = NULL;
}

YoProgCompiler::FuncDataType::~FuncDataType()
{
}

// ==============================================================
// ==============================================================
// ==============================================================

YoProgCompiler::Value::Value(EValue p_evalue, const std::string& p_name, YoParserNode * p_node) : name(p_name)
{
	evalue = p_evalue;
	parserNode = p_node;
}

YoProgCompiler::Value::~Value()
{
}

// ==============================================================

YoProgCompiler::StackValue::StackValue(Type * p_type, const std::string& p_name, YoParserNode * p_node) : Value(VALUE_STACKVALUE, p_name, p_node)
{
	type = p_type;
	isInitialized = false;
	isUsed = false;
	isTemp = false;
	// isClosure = false;
	ext.index = -1;
}

YoProgCompiler::StackValue::~StackValue()
{
}

// ==============================================================

YoProgCompiler::Scope::Scope(Scope * p_parent, EScope p_escope, const std::string& p_name, YoParserNode * p_node) : 
	// Value(VALUE_SCOPE, p_name, p_node)
	name(p_name), parserNode(p_node)
{
	parent = p_parent;
	escope = p_escope;
}

YoProgCompiler::Scope::~Scope()
{
	if (escope != SCOPE_BLOCK){
		for (size_t i = 0; i < stackValues.size(); i++) {
			delete stackValues[i];
		}
	}
}

// ==============================================================

YoProgCompiler::Function::Function(Scope * p_parent, FuncNativeType * p_funcNativeType, const std::string& p_name, YoParserNode * p_node) :
	Scope(p_parent, SCOPE_FUNCTION, p_name, p_node)
{
	funcNativeType = p_funcNativeType;
	ext.index = -1;
}

YoProgCompiler::Function::~Function()
{
}

// ==============================================================

YoProgCompiler::Module::Module(const std::string& p_name, YoParserNode * p_node) : Scope(NULL, SCOPE_MODULE, p_name, p_node)
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

/* YoProgCompiler::NameInfo::NameInfo()
{
	ename = NAME_UNKNOWN;
	scope = NULL;
	local.upCount = 0;
	local.value = NULL;
} */

// ==============================================================

YoProgCompiler::Operation::Operation(EOperation p_eop, YoParserNode * p_node)
{
	eop = p_eop;
	parserNode = p_node;
	type = NULL;
}

YoProgCompiler::Operation::~Operation()
{
	/* std::vector<Operation*>::iterator it = ops.begin();
	for (; it != ops.end(); ++it) {
		Operation * op = *it;
		delete op;
	} */
}

// ==============================================================
// ==============================================================
// ==============================================================

YoProgCompiler::YoProgCompiler(YoParser * p)
{
	parser = p;
	error = ERROR_NOTHING;
	errorNode = NULL;
	initConvertOps();
}

YoProgCompiler::~YoProgCompiler()
{
	reset();
}

void YoProgCompiler::reset()
{
	size_t i;
	for (i = 0; i < modules.size(); i++) {
		delete modules[i];
	}
	for (i = 0; i < ops.size(); i++) {
		delete ops[i];
	}
	std::map<std::string, Type*>::iterator it = types.begin();
	for (; it != types.end(); ++it) {
		delete it->second;
	}
	resetError();
}

void YoProgCompiler::resetError()
{
	error = ERROR_NOTHING;
	errorMsg = "";
	errorNode = NULL;
}

void YoProgCompiler::setError(Error err)
{
	setError(err, NULL, "");
}

void YoProgCompiler::setError(Error err, YoParserNode * node, const char * msg, ...)
{
	va_list va;
	va_start(va, msg);
	const size_t BUF_SIZE = 1024 * 10;
	char * buf = new char[BUF_SIZE];
	YO_ASSERT(buf);
	vsprintf_s(buf, BUF_SIZE, msg, va);
	setError(err, node, std::string(buf));
	delete[] buf;
	va_end(va);
}

void YoProgCompiler::setError(Error err, YoParserNode * node, const std::string& msg)
{
	// YO_DEBUG_BREAK;
	if (error != ERROR_NOTHING) {
		YO_ASSERT(false);
		return;
	}
	error = err;
	errorMsg = msg;
	errorNode = node;
}

bool YoProgCompiler::isError() const
{
	return error != ERROR_NOTHING;
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
	out.clear();
	out.reserve(count);
	while (node) {
		out.push_back(node);
		node = node->prev;
	}
}

std::string YoProgCompiler::getTokenStr(YoParserNode * node)
{
	return std::string(node->token.str, node->token.len);
}

YoProgCompiler::Type * YoProgCompiler::getIntType(int bits, bool isSigned)
{
	switch (bits) {
	case 8: return getType(isSigned ? TYPE_INT8 : TYPE_UINT8);
	case 16: return getType(isSigned ? TYPE_INT16 : TYPE_UINT16);
	case 32: return getType(isSigned ? TYPE_INT32 : TYPE_UINT32);
	case 64: return getType(isSigned ? TYPE_INT64 : TYPE_UINT64);
	}
	setError(ERROR_UNREACHABLE, NULL, "Error int type bits: %d", bits);
	return NULL;
}

YoProgCompiler::Type * YoProgCompiler::getFloatType(int bits)
{
	switch (bits) {
	case 32: return getType(TYPE_FLOAT32);
	case 64: return getType(TYPE_FLOAT64);
	}
	setError(ERROR_UNREACHABLE, NULL, "Error float type bits: %d", bits);
	return NULL;
}

YoProgCompiler::Type * YoProgCompiler::getVoidPtrType()
{
	return getPtrType(getType(TYPE_VOID));
}

YoProgCompiler::Type * YoProgCompiler::newType(const std::string& name, EType etype, YoParserNode * node)
{
	Type * type = new Type(name, etype, node);
	types[name] = type;
	return type;
}

YoProgCompiler::SubType * YoProgCompiler::newSubType(const std::string& name, EType etype, Type * subType, YoParserNode * node)
{
	SubType * type = new SubType(name, etype, subType, node);
	types[name] = type;
	return type;
}

YoProgCompiler::StructType * YoProgCompiler::newStructType(const std::string& name, YoParserNode * node)
{
	StructType * type = new StructType(name, node);
	types[name] = type;
	return type;
}

YoProgCompiler::FuncDataType * YoProgCompiler::newFuncDataType(const std::string& name, YoParserNode * node)
{
	FuncDataType * type = new FuncDataType(name, node);
	types[name] = type;
	return type;
}

YoProgCompiler::FuncNativeType * YoProgCompiler::newFuncNativeType(const std::string& name, YoParserNode * node)
{
	FuncNativeType * type = new FuncNativeType(name, node);
	types[name] = type;
	return type;
}

YoProgCompiler::Type * YoProgCompiler::getType(EType etype)
{
	std::string name;
	switch (etype) {
	case TYPE_VOID: name = "void"; break;
	case TYPE_BOOL: name = "bool"; break;
	case TYPE_INT8: name = "int8"; break;
	case TYPE_INT16: name = "int16"; break;
	case TYPE_INT32: name = "int32"; break;
	case TYPE_INT64: name = "int64"; break;
	case TYPE_UINT8: name = "uint8"; break;
	case TYPE_UINT16: name = "uint16"; break;
	case TYPE_UINT32: name = "uint32"; break;
	case TYPE_UINT64: name = "uint64"; break;
	case TYPE_FLOAT32: name = "float32"; break;
	case TYPE_FLOAT64: name = "float64"; break;
	default:
		setError(ERROR_UNREACHABLE, NULL, "Error type: %d", (int)etype);
		return NULL;
	}
	std::map<std::string, Type*>::iterator it = types.find(name);
	if (it == types.end()) {
		return newType(name, etype, NULL);
	}
	YO_ASSERT(it->second->name == name && it->second->etype == etype);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getParserStdType(int stdType)
{
	switch (stdType) {
	case T_VOID: return getType(TYPE_VOID);
	case T_BOOL: return getType(TYPE_BOOL);
	case T_INT8: return getType(TYPE_INT8);
	case T_INT16: return getType(TYPE_INT16);
	case T_INT32: return getType(TYPE_INT32);
	case T_INT64: return getType(TYPE_INT64);
	case T_UINT8: return getType(TYPE_UINT8);
	case T_UINT16: return getType(TYPE_UINT16);
	case T_UINT32: return getType(TYPE_UINT32);
	case T_UINT64: return getType(TYPE_UINT64);
	case T_FLOAT32: return getType(TYPE_FLOAT32);
	case T_FLOAT64: return getType(TYPE_FLOAT64);
	}
	setError(ERROR_UNREACHABLE, NULL, "Error parser std type: %d", stdType);
	return NULL;
}

YoProgCompiler::StructType * YoProgCompiler::getStructType(const std::vector<Type*>& elements, YoParserNode * node)
{
	std::string name = "{";
	for (size_t i = 0; i < elements.size(); i++) {
		if (i > 0) {
			name += ",";
		}
		name += elements[i]->name;
	}
	name += "}";
	
	std::map<std::string, Type*>::iterator it = types.find(name);
	if (it == types.end()) {
		StructType * type = newStructType(name, node);
		type->elements = elements;
		return type;
	}
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_STRUCT && dynamic_cast<StructType*>(it->second));
	return dynamic_cast<StructType*>(it->second);
}

YoProgCompiler::FuncDataType * YoProgCompiler::getFuncDataType(FuncNativeType * funcNativeType)
{
	std::vector<Type*> elements;
	Type * closureStructPtr = getPtrType(getStructType(elements, funcNativeType->parserNode));
	Type * funcNativePtr = getPtrType(funcNativeType);

	std::string name = "func{";
	name += funcNativePtr->name;
	name += ",";
	name += closureStructPtr->name;
	name += "}";

	std::map<std::string, Type*>::iterator it = types.find(name);
	if (it == types.end()) {
		FuncDataType * type = newFuncDataType(name, funcNativeType->parserNode);
		type->funcNativeType = funcNativeType;
		type->elements.push_back(funcNativePtr);
		type->elements.push_back(closureStructPtr);
		return type;
	}
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_FUNC_DATA && dynamic_cast<FuncDataType*>(it->second));
	return dynamic_cast<FuncDataType*>(it->second);
}

YoProgCompiler::FuncNativeType * YoProgCompiler::getFuncNativeType(YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_FUNC);
	std::vector<Type*> argTypes;
	std::vector<std::string> argNames;
	std::string name = "func(";

	if (node->data.func.self) {

	}

	Type * closureAddr = getPtrType(getStructType(argTypes, node), node);
	name += closureAddr->name;
	argTypes.push_back(closureAddr);
	argNames.push_back("#closureAddr");

	std::vector<YoParserNode*> argNodes;
	collectNodesInReversList(argNodes, node->data.func.args);

	std::vector<YoParserNode*>::reverse_iterator nait = argNodes.rbegin();
	for (; nait != argNodes.rend(); ++nait) {
		YoParserNode * argNode = *nait;
		YO_ASSERT(argNode->type == YO_NODE_DECL_ARG);

		std::vector<YoParserNode*> nameArgs;
		collectNodesInReversList(nameArgs, argNode->data.declVar.name);

		Type * argType = getParserType(argNode->data.declVar.type);
		YO_ASSERT(argType);
		for (size_t i = 0; i < nameArgs.size(); i++) {
			// if (argTypes.size() > 0) {
				name += ",";
			// }
			name += argType->name;
			argTypes.push_back(argType);

			YO_ASSERT(nameArgs[i]->type == YO_NODE_NAME);
			argNames.push_back(getTokenStr(nameArgs[i]));
		}
	}
	name += ")";
	Type * resType = node->data.func.type ? getParserType(node->data.func.type) : getType(TYPE_VOID);
	name += resType->name;

	std::map<std::string, Type*>::iterator it = types.find(name);
	if (it == types.end()) {
		FuncNativeType * type = newFuncNativeType(name, node);
		type->resType = resType;
		type->argTypes = argTypes;
		type->argNames = argNames;
		return type;
	}
	YO_ASSERT(dynamic_cast<FuncNativeType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_FUNC_NATIVE);
	return dynamic_cast<FuncNativeType*>(it->second);
}

YoProgCompiler::Type * YoProgCompiler::getMutType(Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	std::string name = std::string("mut ") + type->name;
	std::map<std::string, Type*>::iterator it = types.find(name);
	if (it == types.end()) {
		return newSubType(name, TYPE_MUT, type, node ? node : type->parserNode);
	}
	YO_ASSERT(dynamic_cast<SubType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_MUT && ((SubType*)it->second)->subType == type);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getPtrType(Type * type, YoParserNode * node)
{
	if (!type) {
		// YO_ASSERT(isError());
		return NULL;
	}
	std::string name = std::string("*") + type->name;
	std::map<std::string, Type*>::iterator it = types.find(name);
	if (it == types.end()) {
		return newSubType(name, TYPE_PTR, type, node ? node : type->parserNode);
	}
	YO_ASSERT(dynamic_cast<SubType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_PTR && ((SubType*)it->second)->subType == type);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getParserType(YoParserNode * node)
{
	YO_ASSERT(node);
	switch (node->type) {
	case YO_NODE_DECL_FUNC: 
		return getFuncDataType(getFuncNativeType(node));
	
	case YO_NODE_TYPE_MUTABLE:
		return getMutType(getParserType(node->data.typeMutable.type), node);

	case YO_NODE_TYPE_PTR:
		return getPtrType(getParserType(node->data.typePtr.type), node);

	case YO_NODE_TYPE_STD_NAME:
		return getParserStdType(node->data.typeStdName);
	}
	setError(ERROR_UNREACHABLE, node, "Error parser type: %d", (int)node->type);
	return NULL;
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
			if (!compileFunc(module, stmt)) {
				YO_ASSERT(isError());
				return false;
			}
			break;

		default:
			setError(ERROR_UNREACHABLE, stmt, "Error module node: %d", (int)stmt->type);
			return false;
		}
	}
	return true;
}

YoProgCompiler::Function * YoProgCompiler::compileFunc(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_FUNC);
	YO_ASSERT(node->data.func.op == T_FUNC && scope->escope == SCOPE_MODULE || node->data.func.op == T_SUB_FUNC && scope->escope != SCOPE_MODULE);
	YO_ASSERT(!node->data.func.self);

	std::string name;
	if (node->data.func.name) {
		name = getTokenStr(node->data.func.name);
	}
	else{
		static int i = 1;
		char buf[64];
		sprintf_s(buf, sizeof(buf), "subfunc-%d", i++);
		name = buf;
	}

	FuncNativeType * funcNativeType = getFuncNativeType(node);
	Function * func = new Function(scope, funcNativeType, name, node);
	getModule(scope)->funcs.push_back(func);
	
	if (!compileFuncBody(func, node->data.func.body)) {
		YO_ASSERT(isError());
		return NULL;
	}

	std::vector<StackValue*>::iterator vit = func->stackValues.begin();
	while (vit != func->stackValues.end()) {
		StackValue * stackValue = *vit;
		if ((!stackValue->type || !stackValue->isUsed) && !stackValue->isTemp) {
			if (stackValue->name[0] != '_') {
				setError(ERROR_VAR_NOT_USED, stackValue->parserNode, "Variable '%s' is not used", stackValue->name.c_str());
				return NULL;
			}
			// vit = func->stackValues.erase(vit);
			// continue;
		}
		++vit;
	}
	return func;
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

			case YO_NODE_ASSIGN:
				if (!compileStmtAssign(func, stmt)) {
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
				setError(ERROR_UNREACHABLE, stmt, "Error func stmt: %d", (int)stmt->type);
				return false;
			}
		}
	}
	return true;
}

YoProgCompiler::StackValue * YoProgCompiler::compileDeclVar(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_VAR);

	Type * type = NULL;
	if (node->data.declVar.type) {
		YO_ASSERT(node->data.declVar.type && node->data.declVar.type->isType());
		type = getParserType(node->data.declVar.type);
		YO_ASSERT(type);
	}

	YO_ASSERT(node->data.declVar.name && node->data.declVar.name->type == YO_NODE_NAME);
	StackValue * stackValue = new StackValue(type, getTokenStr(node->data.declVar.name), node);
	scope->stackValues.push_back(stackValue);
	if (scope->escope == SCOPE_BLOCK) {
		getFunction(scope)->stackValues.push_back(stackValue);
	}
	return stackValue;
}

bool YoProgCompiler::findName(NameInfo& out, Scope * scope, const std::string& name)
{
	for (int upCount = 0; scope; upCount++) {
		if (scope->escope == SCOPE_MODULE) {
			break;
		}
		YO_ASSERT(scope->escope == SCOPE_FUNCTION);
		std::vector<StackValue*>::reverse_iterator it = scope->stackValues.rbegin();
		for (; it != scope->stackValues.rend(); ++it) {
			StackValue * stackValue = *it;
			if (stackValue->isTemp) {
				continue;
			}
			if (stackValue->name == name) {
				out.scope = scope;
				if (upCount > 0) {
					out.ename = NAME_CLOSUREVALUE;
					out.closureValue.count = upCount;
					out.closureValue.value = stackValue;
				}
				else{
					out.ename = NAME_STACKVALUE;
					out.stackValue = stackValue;
				}
				return true;
			}
		}
		scope = scope->parent;
	}
	out.ename = NAME_UNKNOWN;
	out.scope = NULL;
	return false;
}

YoProgCompiler::Operation * YoProgCompiler::compileValueOp(Scope * scope, YoParserNode * node)
{
	return convertOpToValue(scope, compileOp(scope, node));
}

YoProgCompiler::Operation * YoProgCompiler::compileOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node);
	std::string name;
	Operation * op;
	NameInfo nameInfo;
	switch (node->type) {
	case YO_NODE_CONST_NULL:
		op = newOperation(OP_CONST_NULL, node);
		op->type = getVoidPtrType();
		return op;

	case YO_NODE_CONST_TRUE:
	case YO_NODE_CONST_FALSE:
		op = newOperation(OP_CONST_INT, node);
		op->constInt.val = node->type == YO_NODE_CONST_TRUE ? 1 : 0;
		op->constInt.bits = 8;
		op->constInt.isSigned = false;
		op->type = getIntType(op->constInt.bits, op->constInt.isSigned);
		return op;

	case YO_NODE_CONST_INT:
		op = newOperation(OP_CONST_INT, node);
		op->constInt.val = node->data.constInt.val;
		op->constInt.bits = node->data.constInt.bits;
		op->constInt.isSigned = node->data.constInt.isSigned;
		op->type = getIntType(op->constInt.bits, op->constInt.isSigned);
		return op;

	case YO_NODE_CONST_FLOAT:
		op = newOperation(OP_CONST_FLOAT, node);
		op->constFloat.fval = node->data.constFloat.fval;
		op->type = getType(TYPE_FLOAT32);
		return op;

	case YO_NODE_CONST_DOUBLE:
		op = newOperation(OP_CONST_FLOAT, node);
		op->constFloat.fval = node->data.constFloat.fval;
		op->type = getType(TYPE_FLOAT64);
		return op;

	case YO_NODE_NAME:
		name = getTokenStr(node);
		if (!findName(nameInfo, scope, name)) {
			setError(ERROR_NAME_NOT_FOUND, node, "Name not found: %s", name.c_str());
			return NULL;
		}
		switch (nameInfo.ename) {
		case NAME_STACKVALUE:
			op = newStackValuePtrOp(nameInfo.stackValue, node);
			op->stackValue->isUsed = true;
			return op;

		case NAME_CLOSUREVALUE:
			setError(ERROR_UNREACHABLE, node, "Closure value is not supported yet, error name: %s", name.c_str());
			return NULL;
		}
		setError(ERROR_UNREACHABLE, node, "Error name: %s", name.c_str());
		return NULL;

	case T_ASSIGN:
		return compileAssign(scope, node);

	case YO_NODE_BIN_OP:
		return compileBinOp(scope, node);

	case YO_NODE_DECL_FUNC:
		return compileSubFunc(scope, node);

	case YO_NODE_CALL:
		return compileCall(scope, node);

	case YO_NODE_CAST:
		return convertOpToType(scope, compileOp(scope, node->data.cast.expr), getParserType(node->data.cast.type), CONVERT_BY_HAND);
	}
	setError(ERROR_UNREACHABLE, node, "Error parser node: %d", (int)node->type);
	return NULL;
}

bool YoProgCompiler::addStmt(Scope * scope, Operation * op)
{
	YO_ASSERT(scope && scope->escope != SCOPE_MODULE);
	if (!op) {
		YO_ASSERT(isError());
		return false;
	}
	getFunction(scope)->ops.push_back(op);
	return true;
}

YoProgCompiler::Function * YoProgCompiler::getFunction(Scope * scope)
{
	YO_ASSERT(scope && scope->escope != SCOPE_MODULE);
	while (scope->escope == SCOPE_BLOCK) {
		scope = scope->parent;
		YO_ASSERT(scope);
	}
	YO_ASSERT(scope->escope == SCOPE_FUNCTION);
	Function * func = dynamic_cast<Function*>(scope);
	YO_ASSERT(func);
	return func;
}

YoProgCompiler::Module * YoProgCompiler::getModule(Scope * scope)
{
	YO_ASSERT(scope);
	while (scope->escope != SCOPE_MODULE) {
		scope = scope->parent;
		YO_ASSERT(scope);
	}
	YO_ASSERT(scope->escope == SCOPE_MODULE);
	Module * module = dynamic_cast<Module*>(scope);
	YO_ASSERT(module);
	return module;
}

YoProgCompiler::Operation * YoProgCompiler::compileCall(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_CALL);
	Operation * nameOp = compileOp(scope, node->data.call.name);
	if (!nameOp) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (nameOp->eop == OP_STACKVALUE_PTR) {
		if (!nameOp->stackValue->type){
			setError(ERROR_UNREACHABLE, nameOp->stackValue->parserNode, "Type required");
			return NULL;
		}
		if (nameOp->stackValue->type->etype != TYPE_FUNC_DATA || !dynamic_cast<FuncDataType*>(nameOp->stackValue->type)){
			setError(ERROR_TYPE, nameOp->stackValue->parserNode, "Func type required, found: %s", nameOp->stackValue->type->name.c_str());
			return NULL;
		}
		Operation * funcElemPtrPtr = newStructElementPtrOp(nameOp, 0, node);
		if (!funcElemPtrPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * funcElemPtr = convertOpToValue(scope, funcElemPtrPtr);

		Operation * closureElemPtrPtr = newStructElementPtrOp(nameOp, 1, node);
		if (!closureElemPtrPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * closureElemPtr = convertOpToValue(scope, closureElemPtrPtr);

		FuncDataType * funcDataType = (FuncDataType*)nameOp->stackValue->type;

		Operation * op = newOperation(OP_CALL, node);
		op->call.funcDataType = funcDataType;
		op->type = funcDataType->funcNativeType->resType;
		// op->ops.push_back(newOperation(OP_NOP, node));
		op->ops.push_back(funcElemPtr);
		op->ops.push_back(closureElemPtr);

		std::vector<YoParserNode*> argNodes;
		collectNodesInReversList(argNodes, node->data.call.args);
		op->call.args = argNodes.size();

		YO_ASSERT(funcDataType->funcNativeType->argTypes.size()-1/*closure*/ == argNodes.size());
		for (size_t i = 0; i < argNodes.size(); i++) {
			Operation * argOp = compileOp(scope, argNodes[i]);
			argOp = convertOpToType(scope, argOp, funcDataType->funcNativeType->argTypes[i]);
			if (!argOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->ops.push_back(argOp);
		}
		return op;
	}
	setError(ERROR_UNREACHABLE, node, "Error call");
	return NULL;
}

YoProgCompiler::StackValue * YoProgCompiler::allocTempValue(Scope * scope, Type * type, const std::string& name, YoParserNode * node)
{
	StackValue * temp = new StackValue(type, name, node);
	getFunction(scope)->stackValues.push_back(temp);
	temp->isTemp = true;
	return temp;
}

YoProgCompiler::Operation * YoProgCompiler::newOperation(EOperation eop, YoParserNode * node)
{
	Operation * op = new Operation(eop, node);
	ops.push_back(op);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newStackValuePtrOp(StackValue * value, YoParserNode * node)
{
	Operation * op = newOperation(OP_STACKVALUE_PTR, node);
	op->stackValue = value;
	op->type = getPtrType(value->type);
	return op;
}

YoProgCompiler::Type * YoProgCompiler::getIndirectType(Type * ptrType, YoParserNode * node)
{
	if (!ptrType || ptrType->etype != TYPE_PTR || !dynamic_cast<SubType*>(ptrType) || !((SubType*)ptrType)->subType) {
		setError(ERROR_UNREACHABLE, node, "Pointer required");
		return NULL;
	}
	return ((SubType*)ptrType)->subType;
}

YoProgCompiler::Operation * YoProgCompiler::newStructElementPtrOp(Operation * ptrOp, int index, YoParserNode * node)
{
	Type * type = getIndirectType(ptrOp->type, node);
	if (!type) {
		return NULL;
	}
	if ((type->etype != TYPE_STRUCT && type->etype != TYPE_FUNC_DATA) || !dynamic_cast<StructType*>(type)) {
		setError(ERROR_UNREACHABLE, node, "Struct pointer required");
		return NULL;
	}
	StructType * structType = (StructType*)type;
	if ((size_t)index >= structType->elements.size()) {
		setError(ERROR_UNREACHABLE, node, "Error element index: %d", index);
		return NULL;
	}
	Operation * elemPtr = newOperation(OP_STRUCTELEMENT_PTR, node);
	elemPtr->ops.push_back(ptrOp);
	elemPtr->structElementIndex = index;
	elemPtr->type = getPtrType(structType->elements[index], node);
	return elemPtr;
}

YoProgCompiler::Operation * YoProgCompiler::compileSubFunc(Scope * scope, YoParserNode * node)
{
	Function * func = compileFunc(scope, node);
	if (!func) {
		YO_ASSERT(isError());
		return NULL;
	}
	FuncDataType * funcDataType = getFuncDataType(func->funcNativeType);
	StackValue * temp = allocTempValue(scope, funcDataType, "temp_sub_func", node);

	// Operation * listOp = newOperation(OP_LIST, node);
	Operation * tempOp = newStackValuePtrOp(temp, node);

	// func data element 0
	Operation * funcElemPtrPtr = newStructElementPtrOp(tempOp, 0, node);
	if (!funcElemPtrPtr) {
		YO_ASSERT(isError());
		return NULL;
	}

	Operation * funcOp = newOperation(OP_FUNC, node);
	funcOp->func.func = func;
	funcOp->type = getPtrType(func->funcNativeType);

	Operation * storeOp = newOperation(OP_STORE, node);
	storeOp->ops.push_back(funcElemPtrPtr);
	storeOp->ops.push_back(funcOp);
	storeOp->type = funcOp->type;

	Operation * resultOp = newStackValuePtrOp(temp, node);
	resultOp->ops.push_back(storeOp);

	// func data element 1
	Operation * nullOp = newOperation(OP_CONST_NULL, node);
	nullOp->type = getVoidPtrType();
	
	Operation * closureElemPtrPtr = newStructElementPtrOp(tempOp, 1, node);
	if (!closureElemPtrPtr) {
		YO_ASSERT(isError());
		return NULL;
	}
	closureElemPtrPtr = convertOpToType(scope, closureElemPtrPtr, getPtrType(nullOp->type));

	storeOp = newOperation(OP_STORE, node);
	storeOp->ops.push_back(closureElemPtrPtr);
	storeOp->ops.push_back(nullOp);
	storeOp->type = nullOp->type;

	resultOp->ops.push_back(storeOp);
	return resultOp;
}

YoProgCompiler::Operation * YoProgCompiler::compileAssign(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_ASSIGN); // && node->data.assign.op == T_ASSIGN);

	YO_ASSERT(node->data.assign.left && node->data.assign.right);
	Operation * left = compileOp(scope, node->data.assign.left);
	if (!left) {
		return NULL;
	}
	Operation * right = compileValueOp(scope, node->data.assign.right);
	if (!right) {
		return NULL;
	}
	Operation * op;
	switch (left->eop) {
	case OP_STACKVALUE_PTR:
		if (!left->type) {
			YO_ASSERT(right->type);
			YO_ASSERT(left->stackValue && !left->stackValue->type);
			left->stackValue->type = right->type;
			left->type = getPtrType(right->type);
		}
		else{
			right = convertOpToType(scope, right, left->stackValue->type);
			if (!right) {
				return NULL;
			}
		}
		op = newOperation(OP_STORE, node);
		op->ops.push_back(left);
		op->ops.push_back(right);
		op->type = right->type;
		if (node->data.assign.op == T_INIT_ASSIGN) {
			left->stackValue->isInitialized = true;
			left->stackValue->isUsed = false;
		}
		return op;
	}
	setError(ERROR_OP, left->parserNode, "Not supported assign for left op: %d", (int)left->eop);
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileBinOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);

	// Expression * expr;
	EOperation eop = OP_NOP;
	switch (node->data.binOp.op) {
	case T_PLUS:
		eop = OP_BIN_ADD;
		break;

	default:
		setError(ERROR_OP, node, "Error bin op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);
	Operation * left = compileValueOp(scope, node->data.binOp.left);
	if (!left) {
		return NULL;
	}
	Operation * right = compileValueOp(scope, node->data.binOp.right);
	if (!right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	if (left->type != right->type) {
		std::map<int, CastOp>::iterator it = convertOps.find(getConvertKey(left->type->etype, right->type->etype));
		if (it != convertOps.end()) {
			Type * resType = getType(it->second.extType);
			Operation * newLeft = convertOpToType(scope, left, resType);
			Operation * newRight = convertOpToType(scope, right, resType);
			if (!newLeft || !newRight) {
				return NULL;
			}
			left = newLeft;
			right = newRight;
		}
		else{
			setError(ERROR_TYPE, node, "Error types for bin op: %d, left: %s, right: %s", (int)eop, left->type->name.c_str(), right->type->name.c_str());
			return NULL;
		}
	}
	Operation * op = newOperation(eop, node);
	op->type = left->type;
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

bool YoProgCompiler::compileStmtBinOp(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileBinOp(scope, node));
}

bool YoProgCompiler::compileStmtAssign(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileAssign(scope, node));
}

bool YoProgCompiler::compileStmtReturn(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_RETURN);
	Operation * op = newOperation(OP_RETURN, node);
	if (node->data.stmtReturn.node) {
		Operation * value = compileValueOp(scope, node->data.stmtReturn.node);
		value = convertOpToType(scope, value, getFunction(scope)->funcNativeType->resType);
		if (!value) {
			return false;
		}
		op->ops.push_back(value);
		return addStmt(scope, op);
	}
	YO_ASSERT(getFunction(scope)->funcNativeType->resType == getType(TYPE_VOID));
	return addStmt(scope, op);
}

int YoProgCompiler::getConvertKey(EType from, EType to)
{
	return (int)from * 1000 + (int)to;
}

void YoProgCompiler::initConvertOps()
{
	YO_ASSERT(convertOps.size() == 0);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT8, TYPE_BOOL)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT8)]	= CastOp(TYPE_INT8, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT16)] = CastOp(TYPE_INT16, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT32)] = CastOp(TYPE_INT32, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT8)] = CastOp(TYPE_INT16, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT16)] = CastOp(TYPE_INT32, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT32)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_UINT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT8, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT32, OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT8, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT16, TYPE_BOOL)] = CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT8)] = CastOp(TYPE_INT16, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT16)] = CastOp(TYPE_INT16, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT32)] = CastOp(TYPE_INT32, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT8)] = CastOp(TYPE_INT16, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT16)] = CastOp(TYPE_INT32, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT32)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_UINT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT16, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT32, OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT16, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT32, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT8)] = CastOp(TYPE_INT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT16)] = CastOp(TYPE_INT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT32)] = CastOp(TYPE_INT32, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT32, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT8)] = CastOp(TYPE_INT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT16)] = CastOp(TYPE_INT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT32)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT32, TYPE_UINT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT32, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT64, OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT32, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_INT64, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT8)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT16)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT32)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_SIGN_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT8)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT16)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT32)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_INT64, TYPE_UINT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_INT64, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT64, OP_CAST_SI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_INT64, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_SI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT8, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT8)] = CastOp(TYPE_INT16, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT16)] = CastOp(TYPE_INT32, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT32)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT8)] = CastOp(TYPE_UINT8, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT16)] = CastOp(TYPE_UINT16, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT32)] = CastOp(TYPE_UINT32, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_UINT64)] = CastOp(TYPE_UINT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT32, OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT16, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT8)] = CastOp(TYPE_INT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT16)] = CastOp(TYPE_INT32, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT32)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT8)] = CastOp(TYPE_UINT16, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT16)] = CastOp(TYPE_UINT16, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT32)] = CastOp(TYPE_UINT32, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_UINT64)] = CastOp(TYPE_UINT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT32, OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT16, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT32, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT8)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT16)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT32)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT8)] = CastOp(TYPE_UINT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT16)] = CastOp(TYPE_UINT32, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT32)] = CastOp(TYPE_UINT32, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_UINT64)] = CastOp(TYPE_UINT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT64, OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT32, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_UINT64, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT8)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT16)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT32)] = CastOp(TYPE_INT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_INT64)] = CastOp(TYPE_INT64, OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT8)] = CastOp(TYPE_UINT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT16)] = CastOp(TYPE_UINT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT32)] = CastOp(TYPE_UINT64, OP_CAST_TRUNC);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_UINT64)] = CastOp(TYPE_UINT64, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT64, OP_CAST_UI_TO_FP, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT64, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_UI_TO_FP, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_FLOAT32, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT8)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT16)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT32)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_TO_SI, CAST_AUTO);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_INT64)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT8)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT16)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT32)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_UINT64)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT32, OP_CAST_FP_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_FLOAT32, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_EXT, CAST_AUTO);

	// ------------------------------------------------------------------
	// convertOps[getConvertKey(TYPE_FLOAT64, TYPE_BOOL)]	= CastOp(OP_CAST_ZERO_EXT);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT8)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT16)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT32)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_SI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_INT64)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_SI, CAST_AUTO);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT8)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT16)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT32)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_UINT64)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TO_UI);
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_FLOAT32)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TRUNC, CAST_AUTO); // ???
	convertOps[getConvertKey(TYPE_FLOAT64, TYPE_FLOAT64)] = CastOp(TYPE_FLOAT64, OP_CAST_FP_TRUNC, CAST_AUTO);
}

YoProgCompiler::Operation * YoProgCompiler::convertOpToValue(Scope * scope, Operation * op)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	Type * type;
	Operation * loadOp;
	switch (op->eop) {
	case OP_STACKVALUE_PTR:
	case OP_STRUCTELEMENT_PTR:
		type = getIndirectType(op->type);
		if (!type) {
			YO_ASSERT(isError());
			return NULL;
		}
		loadOp = newOperation(OP_LOAD_BY_PTR, op->parserNode);
		loadOp->ops.push_back(op);
		loadOp->type = type;
		return loadOp;
	}
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::convertOpToType(Scope * scope, Operation * op, Type * type, EConvertType convertType)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(op->type);
	if (op->type == type) {
		return op;
	}
	if (op->type->etype == TYPE_PTR && type->etype == TYPE_PTR) {
		Operation * castOp = newOperation(OP_CAST_PTR, op->parserNode);
		castOp->type = type;
		castOp->ops.push_back(op);
		return castOp;
	}
	if (op->type->etype == TYPE_PTR && type->etype != TYPE_PTR) {
		op = convertOpToValue(scope, op);
		if (!op) {
			return NULL;
		}
	}
	std::map<int, CastOp>::iterator it = convertOps.find(getConvertKey(op->type->etype, type->etype));
	if (it != convertOps.end()) {
		if (it->second.castType == CAST_AUTO || convertType == CONVERT_BY_HAND) {
			Operation * castOp = newOperation(it->second.op, op->parserNode);
			castOp->type = type;
			castOp->ops.push_back(op);
			return castOp;
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error auto convert: %s to %s, posible lost value", op->type->name.c_str(), type->name.c_str());
		return NULL;
	}
	setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), type->name.c_str());
	return NULL;
}
