#include "yolang.h"
#include <sstream>

// ==============================================================
// ==============================================================
// ==============================================================

YoProgCompiler::Type::Type(const std::string& p_name, EType p_etype, YoParserNode * p_node) : name(p_name)
{
	parserNode = p_node;
	etype = p_etype;
	// isMutable = false;
	isUnknownYet = false;
	// isGeneric = false;
	ext.index = -1;
}

YoProgCompiler::Type::~Type()
{
	std::map<std::string, Type*>::iterator it = subTypes.begin();
	for (; it != subTypes.end(); ++it) {
		delete it->second;
	}
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

bool YoProgCompiler::Type::isNumber() const
{
	switch (etype) {
	case TYPE_INT8:
	case TYPE_INT16:
	case TYPE_INT32:
	case TYPE_INT64:
	case TYPE_UINT8:
	case TYPE_UINT16:
	case TYPE_UINT32:
	case TYPE_UINT64:
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

YoProgCompiler::ArrayType::ArrayType(const std::string& p_name, unsigned p_size, Type * p_subType, YoParserNode * p_node) :
	SubType(p_name, TYPE_ARRAY, p_subType, p_node)
{
	size = p_size;
}

YoProgCompiler::ArrayType::~ArrayType()
{
}

// ==============================================================

YoProgCompiler::StructType::StructType(const std::string& p_name, EType p_type, YoParserNode * p_node) :
	Type(p_name, p_type, p_node)
{
	isPacked = false;
}

YoProgCompiler::StructType::~StructType()
{
}

void YoProgCompiler::StructType::updateNameIndices()
{
	nameIndices.clear();
	for (int i = 0; i < (int)names.size(); i++) {
		nameIndices[names[i]] = i;
	}
}

// ==============================================================

YoProgCompiler::FuncNativeType::FuncNativeType(const std::string& p_name, YoParserNode * p_node) :
	Type(p_name, TYPE_FUNC_NATIVE, p_node)
{
	resType = NULL;
	funcDataType = NULL;
}

YoProgCompiler::FuncNativeType::~FuncNativeType()
{
	delete funcDataType;
}

// ==============================================================

YoProgCompiler::FuncDataType::FuncDataType(const std::string& p_name, YoParserNode * p_node) :
	StructType(p_name, TYPE_STRUCT, p_node)
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
	isArg = false;
	isMutable = false;
	isInitialized = false;
	isChanged = false;
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
	std::map<std::string, Type*>::iterator it = types.begin();
	for (; it != types.end(); ++it) {
		Type * type = it->second;
		switch (type->etype) {
		case TYPE_CLASS:
			delete type;
			break;
		}
	}
}

// ==============================================================

YoProgCompiler::Function::Function(Scope * p_parent, FuncNativeType * p_funcNativeType, 
	const std::vector<std::string>& p_argNames, const std::string& p_name, YoParserNode * p_node) :
	Scope(p_parent, SCOPE_FUNCTION, p_name, p_node), argNames(p_argNames)
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
	// initConvertOps();
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
	std::map<std::string, Type*>::iterator it = globalTypes.begin();
	for (; it != globalTypes.end(); ++it) {
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

void YoProgCompiler::dump()
{
	struct Lib {
		YoProgCompiler * self;

		void printDepth(int depth)
		{
			for (int i = 0; i < depth; i++) {
				printf("  ");
			}
		}

		const char * getBinOpName(EOperation eop, bool isFloat)
		{
			switch (eop) {
			case OP_BIN_ADD:
				return isFloat ? "fadd" : "add";
			}
			return "<unknown>";
		}

		void dumpCall(Function * func, Operation * op, int depth)
		{
			YO_ASSERT((op->eop == OP_CALL_CLOSURE || op->eop == OP_CALL_FUNC) && op->ops.size() >= 2);

			// YoProgCompiler::FuncDataType * funcDataType = op->call.funcDataType;
			int i, startArg = op->ops.size() - (op->eop == OP_CALL_CLOSURE ? op->callClosure.args : op->callFunc.args) - 2;

			if (0 < startArg) {
				printDepth(depth); printf("begin prepare CALL\n");
				for (i = 0; i < startArg; i++) {
					dumpOp(func, op->ops[i], depth + 1);
				}
				printDepth(depth); printf("end prepare CALL\n");
			}

			printDepth(depth); printf("begin CALL\n");
			dumpOp(func, op->ops[startArg + 0], depth + 1);
			dumpOp(func, op->ops[startArg + 1], depth + 1);
			for (i = startArg + 2; i < (int)op->ops.size(); i++) {
				dumpOp(func, op->ops[i], depth + 1);
			}
			printDepth(depth); printf("end CALL ");
			dumpType(op->type);
			printf("\n");
		}

		int indexOf(Function * func, StackValue * var)
		{
			std::vector<StackValue*>::iterator it = std::find(func->stackValues.begin(), func->stackValues.end(), var);
			if (it != func->stackValues.end()) {
				return it - func->stackValues.begin();
			}
			return -1;
		}

		void dumpOp(Function * func, Operation * op, int depth)
		{
			int i;
			const char * name;
			switch (op->eop) {
			case YoProgCompiler::OP_CONST_NULL:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); 
				printf("NULL");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CONST_INT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth);
				printf("%llu ", op->constInt.val);
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CONST_FLOAT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth);
				printf("%lf ", op->constFloat.fval);
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_BIN_ADD:
				YO_ASSERT(op->ops.size() == 2);
				YO_ASSERT(op->type && op->ops[0]->type && op->ops[1]->type);
				YO_ASSERT(op->ops[0]->type->etype == op->ops[1]->type->etype);
				printDepth(depth);
				name = getBinOpName(op->eop, op->ops[0]->type->isFloat());
				// printDepth(depth); printf("begin OP_BIN_ADD %s\n", name);
				dumpOp(func, op->ops[0], depth + 1);
				dumpOp(func, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_BIN_ADD %s ", name);
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_RETURN:
				if (op->ops.size() > 0) {
					YO_ASSERT(op->ops.size() == 1);
					dumpOp(func, op->ops[0], depth + 1);
					printDepth(depth); printf("OP_RETURN ");
					dumpType(op->type);
					printf("\n");
					return;
				}
				printDepth(depth); printf("OP_RETURN\n");
				return;

			case YoProgCompiler::OP_CALL_CLOSURE:
			case YoProgCompiler::OP_CALL_FUNC:
				dumpCall(func, op, depth);
				return;

			case YoProgCompiler::OP_STACK_VALUE_PTR:
				for (i = 0; i < (int)op->ops.size(); i++) {
					dumpOp(func, op->ops[i], depth + 1);
				}
				printDepth(depth);
				printf("OP_STACK_VALUE_PTR: %s#%d ", op->stackValue->name.c_str(), indexOf(func, op->stackValue));
				dumpType(op->stackValue->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_STRUCT_ELEMENT_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_STRUCT_ELEMENT_PTR: %d ", op->structElementIndex);
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_ELEMENT_PTR: {
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_ELEMENT_PTR\n");
				dumpOp(func, op->ops[0], depth + 1);
				dumpOp(func, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_ELEMENT_PTR ");
				dumpType(op->type);
				printf("\n");
				return;
			}
			case YoProgCompiler::OP_FUNC:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("OP_FUNC %s ", op->func->name.c_str());
				dumpType(op->func->funcNativeType);
				printf("\n");
				return;

			case YoProgCompiler::OP_LOAD:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_LOAD ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_STORE_VALUE:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE_VALUE\n");
				dumpOp(func, op->ops[0], depth + 1);
				dumpOp(func, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_STORE_VALUE ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_STORE_PTR:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE_PTR\n");
				dumpOp(func, op->ops[0], depth + 1);
				dumpOp(func, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_STORE_PTR ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_STACK_VALUE_MEMZERO:
				printDepth(depth); printf("OP_STACK_VALUE_MEMZERO: %s#%d ", op->stackValue->name.c_str(), indexOf(func, op->stackValue));
				dumpType(op->stackValue->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_VALUE_ZERO:
				printDepth(depth); printf("OP_VALUE_ZERO ");
				dumpType(op->stackValue->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_TRUNC:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_TRUNC ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_ZERO_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_ZERO_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_SIGN_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_SIGN_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_SI_TO_FP:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_SI_TO_FP ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_UI_TO_FP:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_UI_TO_FP ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_FP_TO_SI:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_TO_SI ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_FP_TO_UI:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_TO_UI ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_FP_TRUNC:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_TRUNC ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_FP_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_CAST_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_PTR ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_SIZEOF:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_SIZEOF ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_TYPE:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("OP_TYPE ");
				dumpType(op->type);
				printf("\n");
				return;

			case YoProgCompiler::OP_TYPE_STRUCT_ELEMENT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth + 1); printf("TYPE ");
				dumpType(op->typeStructElement.parent);
				printf("\n");
				printDepth(depth); printf("OP_TYPE_STRUCT_ELEMENT: %d ", op->typeStructElement.index);
				dumpType(op->type);
				printf("\n");
				return;

			default:
				printDepth(depth); printf("<unknown> %d\n", (int)op->eop);
				return;
			}
		}

		void dumpFunc(Function * func)
		{
			printf("begin FUNC %s: %s\n\n", func->name.c_str(), func->funcNativeType->name.c_str());

			int i;
			for (i = 0; i < (int)func->stackValues.size(); i++) {
				StackValue * var = func->stackValues[i];
				printf("  var %s%s#%d ", var->isMutable ? "mut " : "", var->name.c_str(), i);
				dumpType(var->type);
				printf("\n");
			}
			if (i > 0) {
				printf("\n");
			}

			for (i = 0; i < (int)func->ops.size(); i++) {
				Operation * op = func->ops[i];
				dumpOp(func, op, 1);
			}
			printf("end FUNC\n\n");
		}

		void dumpModule(Module * module)
		{
			printf("begin MODULE %s\n\n", module->name.c_str());

			std::map<std::string, Type*>::iterator tit = module->types.begin();
			for (; tit != module->types.end(); ++tit) {
				dumpDeclType(tit->second);
			}
			if (module->types.size() > 0) {
				printf("\n");
			}

			for (int i = 0; i < (int)module->funcs.size(); i++) {
				dumpFunc(module->funcs[i]);
			}
			printf("end MODULE\n\n");
		}

		void dumpType(Type * type)
		{
			if (!type) {
				printf("<NULL>");
				return;
			}
			switch (type->etype) {
			case TYPE_UNKNOWN_YET:
				printf("?");
				break;

			case TYPE_VOID:
				printf("void");
				break;

			case TYPE_BOOL:
				printf("bool");
				break;

			case TYPE_INT8:
				printf("int8");
				break;

			case TYPE_INT16:
				printf("int16");
				break;

			case TYPE_INT32:
				printf("int32");
				break;

			case TYPE_INT64:
				printf("int64");
				break;

			case TYPE_UINT8:
				printf("uint8");
				break;

			case TYPE_UINT16:
				printf("uint16");
				break;

			case TYPE_UINT32:
				printf("uint32");
				break;

			case TYPE_UINT64:
				printf("uint64");
				break;

			case TYPE_FLOAT32:
				printf("float32");
				break;

			case TYPE_FLOAT64:
				printf("float64");
				break;

			case TYPE_STRING:
				printf("string");
				break;

			case TYPE_CLASS:
				printf("class");
				// no break

			case TYPE_STRUCT: {
				YO_ASSERT(dynamic_cast<StructType*>(type));
				StructType * structType = (StructType*)type;
				if (structType->isPacked) {
					printf("packed");
				}
				printf("{");
				for (int i = 0; i < (int)structType->types.size(); i++) {
					if (i > 0) {
						printf(",");
					}
					dumpType(structType->types[i]);
				}
				printf("}");
				break;
			}
			case TYPE_FUNC_NATIVE: {
				YO_ASSERT(dynamic_cast<FuncNativeType*>(type));
				FuncNativeType * funcType = (FuncNativeType*)type;
				printf("func(");
				for (int i = 0; i < (int)funcType->args.size(); i++) {
					if (i > 0) {
						printf(",");
					}
					FuncNativeType::Arg& arg = funcType->args[i];
					if (arg.isMutable) {
						printf("mut ");
					}
					// printf("%s ", arg.name.c_str());
					dumpType(arg.type);
				}
				printf(")");
				dumpType(funcType->resType);
				break;
			}
			case TYPE_FUNC_DATA:
				YO_ASSERT(dynamic_cast<FuncDataType*>(type));
				printf("funcdata{");
				dumpType(((FuncDataType*)type)->funcNativeType);
				printf("}");
				break;

			case TYPE_PTR:
				YO_ASSERT(dynamic_cast<SubType*>(type));
				printf("*");
				dumpType(((SubType*)type)->subType);
				break;

			case TYPE_ARRAY:
				YO_ASSERT(dynamic_cast<ArrayType*>(type));
				printf("[%d]", ((ArrayType*)type)->size);
				dumpType(((ArrayType*)type)->subType);
				break;

			case TYPE_MUT:
				YO_ASSERT(dynamic_cast<SubType*>(type));
				printf("mut ");
				dumpType(((SubType*)type)->subType);
				break;

			case TYPE_CONST:
				YO_ASSERT(dynamic_cast<SubType*>(type));
				printf("const ");
				dumpType(((SubType*)type)->subType);
				break;
			}
		}

		void dumpDeclType(Type * type)
		{
			switch (type->etype) {
			case TYPE_STRUCT:
			case TYPE_CLASS:
				printf("TYPE %s ", type->name.c_str());
				dumpType(type);
				printf("\n");
				break;

			default:
				printf("TYPE %s\n", type->name.c_str());
				break;
			}
		}

	} lib = { this };

	if (isError()) {
		dumpError();
		return;
	}

	std::map<std::string, Type*>::iterator tit = globalTypes.begin();
	for (; tit != globalTypes.end(); ++tit) {
		lib.dumpDeclType(tit->second);
	}
	if (globalTypes.size() > 0) {
		printf("-------------------\n");
	}
	
	int i;
	for (i = 0; i < (int)modules.size(); i++) {
		lib.dumpModule(modules[i]);
	}
}

void YoProgCompiler::dumpError()
{
	if (isError()) {
		printf("Error: %s\n", errorMsg.c_str());
		if (errorNode) {
			parser->dumpErrorLine(errorNode->token);
		}
	}
	else{
		printf("<NO ERROR>\n");
	}
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

void YoProgCompiler::collectDotNameNodesInReversList(std::vector<YoParserNode*>& out, YoParserNode * node)
{
	YO_ASSERT(node->type == YO_NODE_DOTNAME);
	int count = 0;
	for (YoParserNode * cur = node; cur; cur = cur->data.dotName.node){
		count++;
	}
	out.clear();
	out.reserve(count);
	while (node) {
		out.push_back(node);
		node = node->data.dotName.node;
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

/*
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

YoProgCompiler::ArrayType * YoProgCompiler::newArrayType(const std::string& name, unsigned size, Type * subType, YoParserNode * node)
{
	ArrayType * type = new ArrayType(name, size, subType, node);
	types[name] = type;
	return type;
}

YoProgCompiler::StructType * YoProgCompiler::newStructType(const std::string& name, EType et, YoParserNode * node)
{
	StructType * type = new StructType(name, et, node);
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
*/

YoProgCompiler::Type * YoProgCompiler::getType(EType etype)
{
	std::string name;
	switch (etype) {
	case TYPE_UNKNOWN_YET: name = "?"; break;
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
	std::map<std::string, Type*>::iterator it = globalTypes.find(name);
	if (it == globalTypes.end()) {
		// return newType(name, etype, NULL);
		Type * type = new Type(name, etype, NULL);
		globalTypes[name] = type;
		type->isUnknownYet = etype == TYPE_UNKNOWN_YET;
		return type;
	}
	YO_ASSERT(it->second->name == name && it->second->etype == etype);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getParserStdType(int stdType)
{
	switch (stdType) {
	case T_UNKNOWN_YET: return getType(TYPE_UNKNOWN_YET);
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
	std::ostringstream buf;
	buf << "{";
	for (size_t i = 0; i < elements.size(); i++) {
		if (i > 0) {
			buf << ",";
		}
		buf << elements[i]->name;
	}
	buf << "}";
	std::string name = buf.str();
	std::map<std::string, Type*>::iterator it = globalTypes.find(name);
	if (it == globalTypes.end()) {
		StructType * type = new StructType(name, TYPE_STRUCT, node);
		globalTypes[name] = type;
		type->types = elements;
		return type;
	}
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_STRUCT && dynamic_cast<StructType*>(it->second));
	return (StructType*)it->second;
}

YoProgCompiler::FuncDataType * YoProgCompiler::getFuncDataType(FuncNativeType * funcNativeType)
{
	if (funcNativeType->funcDataType) {
		return funcNativeType->funcDataType;
	}

	std::vector<Type*> elements;
	Type * closureStructPtr = getPtrType(getStructType(elements, funcNativeType->parserNode));
	Type * funcNativePtr = getPtrType(funcNativeType);

	std::ostringstream buf;
	buf << "funcdata{" << funcNativePtr->name << "," << closureStructPtr->name << "}";
	std::string name = buf.str();

	FuncDataType * type = new FuncDataType(name, funcNativeType->parserNode);
	// globalTypes[name] = type;
	type->funcNativeType = funcNativeType;
	type->types.push_back(funcNativePtr);
	type->types.push_back(closureStructPtr);
	funcNativeType->funcDataType = type;
	return type;
	
	/*
	std::map<std::string, Type*>::iterator it = globalTypes.find(name);
	if (it == globalTypes.end()) {
		FuncDataType * type = new FuncDataType(name, funcNativeType->parserNode);
		globalTypes[name] = type;
		type->funcNativeType = funcNativeType;
		type->types.push_back(funcNativePtr);
		type->types.push_back(closureStructPtr);
		return type;
	}
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_FUNC_DATA && dynamic_cast<FuncDataType*>(it->second));
	return (FuncDataType*)it->second;
	*/
}

void YoProgCompiler::updateFuncNativeType(FuncNativeType * funcType)
{
	std::map<std::string, Type*>::iterator it = globalTypes.find(funcType->name);
	if (it != globalTypes.end()) {
		globalTypes.erase(it);
	}
	std::ostringstream buf;
	buf << "func(";
	for (int i = 0; i < (int)funcType->args.size(); i++) {
		if (i > 0) {
			buf << ",";
		}
		if (funcType->args[i].isMutable) {
			buf << "mut ";
		}
		buf << funcType->args[i].type->name;
	}
	buf << ")" << funcType->resType->name;
	funcType->name = buf.str();
	globalTypes[funcType->name] = funcType;
}

YoProgCompiler::FuncNativeType * YoProgCompiler::getFuncNativeType(std::vector<std::string>& argNames, Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && (node->type == YO_NODE_DECL_FUNC || node->type == YO_NODE_TYPE_FUNC));
	FuncNativeType * funcType = new FuncNativeType("", node);
	// FuncNativeType::Arg funcArg;
	// std::vector<Type*> argTypes;
	// std::vector<std::string> argNames;

	std::ostringstream buf;
	buf << "func(";

	if (node->data.func.self) {

	}

	std::vector<Type*> emptyTypes;
	Type * closureAddr = getPtrType(getStructType(emptyTypes, node), node);
	buf << closureAddr->name;
	funcType->args.push_back(FuncNativeType::Arg(closureAddr, false));

	argNames.clear();
	argNames.push_back("#closureAddr");

	std::vector<YoParserNode*> argNodes;
	collectNodesInReversList(argNodes, node->data.func.args);

	std::vector<YoParserNode*>::reverse_iterator nait = argNodes.rbegin();
	for (; nait != argNodes.rend(); ++nait) {
		YoParserNode * argNode = *nait;
		YO_ASSERT(argNode->type == YO_NODE_DECL_ARG);

		std::vector<YoParserNode*> nameArgs;
		collectNodesInReversList(nameArgs, argNode->data.declVar.name);

		Type * argType = getParserType(scope, argNode->data.declVar.type);
		if (!argType) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (argType->etype == TYPE_VOID) {
			setError(ERROR_TYPE, argNode->data.declVar.type, "Arg should not be void");
			return NULL;
		}
		bool isMutable = argNode->data.declVar.isMutable;
		for (int i = (int)nameArgs.size()-1; i >= 0; i--) {
			// if (argTypes.size() > 0) {
			buf << ",";
			// }
			if (isMutable) {
				buf << "mut ";
			}
			buf << argType->name;
			// argTypes.push_back(argType);
			YO_ASSERT(nameArgs[i]->type == YO_NODE_NAME);
			// argNames.push_back(getTokenStr(nameArgs[i]));
			std::string argName = getTokenStr(nameArgs[i]);
			for (int j = 0; j < (int)argNames.size(); j++) {
				if (argNames[j] == argName) {
					setError(ERROR_VAR_DUPLICATED, nameArgs[i], "Arg %s is already exist", argName.c_str());
					return NULL;
				}
			}
			funcType->args.push_back(FuncNativeType::Arg(argType, isMutable));
			argNames.push_back(argName);
		}
	}
	buf << ")";
	funcType->resType = node->data.func.type ? getParserType(scope, node->data.func.type) : getType(TYPE_VOID);
	buf << funcType->resType->name;
	funcType->name = buf.str();
	std::map<std::string, Type*>::iterator it = globalTypes.find(funcType->name);
	if (it == globalTypes.end()) {
		globalTypes[funcType->name] = funcType;
		return funcType;
	}
	YO_ASSERT(dynamic_cast<FuncNativeType*>(it->second));
	YO_ASSERT(it->second->name == funcType->name && it->second->etype == TYPE_FUNC_NATIVE);
	delete funcType;
	return (FuncNativeType*)it->second;
}

YoProgCompiler::Type * YoProgCompiler::getMutType(Type * type, YoParserNode * node)
{
	YO_ASSERT(node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	switch (type->etype) {
	case TYPE_MUT:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't muttable, type %s is already muttable", ((SubType*)type)->subType->name.c_str());
		return NULL;
	
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't muttable, type %s is already constant", ((SubType*)type)->subType->name.c_str());
		return NULL;
	}
	std::ostringstream buf;
	buf << "mut " << type->name;
	std::string name = buf.str();
	std::map<std::string, Type*>::iterator it = type->subTypes.find(name);
	if (it == type->subTypes.end()) {
		Type * subType = new SubType(name, TYPE_MUT, type, node);
		type->subTypes[name] = subType;
		subType->isUnknownYet = type->isUnknownYet;
		return subType;
	}
	YO_ASSERT(dynamic_cast<SubType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_MUT && ((SubType*)it->second)->subType == type);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getConstType(Type * type, YoParserNode * node)
{
	YO_ASSERT(node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	switch (type->etype) {
	case TYPE_MUT:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't constant, type %s is already muttable", ((SubType*)type)->subType->name.c_str());
		return NULL;

	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't constant, type %s is already constant", ((SubType*)type)->subType->name.c_str());
		return NULL;
	}
	std::ostringstream buf;
	buf << "const " << type->name;
	std::string name = buf.str();
	std::map<std::string, Type*>::iterator it = type->subTypes.find(name);
	if (it == type->subTypes.end()) {
		Type * subType = new SubType(name, TYPE_CONST, type, node);
		type->subTypes[name] = subType;
		subType->isUnknownYet = type->isUnknownYet;
		return subType;
	}
	YO_ASSERT(dynamic_cast<SubType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_CONST && ((SubType*)it->second)->subType == type);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getPtrType(Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	std::ostringstream buf;
	buf << "*" << type->name;
	std::string name = buf.str();
	std::map<std::string, Type*>::iterator it = type->subTypes.find(name);
	if (it == type->subTypes.end()) {
		Type * subType = new SubType(name, TYPE_PTR, type, node ? node : type->parserNode);
		type->subTypes[name] = subType;
		subType->isUnknownYet = type->isUnknownYet;
		return subType;
	}
	YO_ASSERT(dynamic_cast<SubType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_PTR && ((SubType*)it->second)->subType == type);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getArrayType(unsigned size, Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	std::ostringstream buf;
	buf << "[" << size << "]" << type->name;
	std::string name = buf.str();
	std::map<std::string, Type*>::iterator it = type->subTypes.find(name);
	if (it == type->subTypes.end()) {
		Type * subType = new ArrayType(name, size, type, node ? node : type->parserNode);
		type->subTypes[name] = subType;
		subType->isUnknownYet = type->isUnknownYet;
		return subType;
	}
	YO_ASSERT(dynamic_cast<SubType*>(it->second));
	YO_ASSERT(it->second->name == name && it->second->etype == TYPE_ARRAY && ((ArrayType*)it->second)->subType == type);
	return it->second;
}

YoProgCompiler::Type * YoProgCompiler::getScopeType(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && (node->type == YO_NODE_TYPE_NAME || node->type == YO_NODE_NAME));
	std::string name = getTokenStr(node);
	while (scope) {
		std::map<std::string, Type*>::iterator it = scope->types.find(name);
		if (it != scope->types.end()) {
			return it->second;
		}
		scope = scope->parent;
	}
	setError(ERROR_TYPE, node, "Type %s is not found", name.c_str());
	return NULL;
}

YoProgCompiler::Type * YoProgCompiler::declStructType(Scope * scope, EType etype, const std::string& name, YoParserNode * node)
{
	YO_ASSERT(node && (node->type == YO_NODE_TYPE_CLASS && etype == TYPE_CLASS));
	YO_ASSERT(scope->types.find(name) == scope->types.end());
	if (node->data.typeClass.gen) {
		setError(ERROR_UNREACHABLE, node, "Class templates are not supported yet");
		return NULL;
	}
	if (node->data.typeClass.extends) {
		setError(ERROR_UNREACHABLE, node, "Class extends are not supported yet");
		return NULL;
	}

	StructType * type = new StructType(name, etype, node); // newStructType(name, TYPE_CLASS, node);
	scope->types[name] = type;

	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.typeClass.body);

	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (; it != nodes.rend(); ++it) {
		YoParserNode * fieldNode = *it;
		YO_ASSERT(fieldNode->type == YO_NODE_DECL_ARG);

		std::vector<YoParserNode*> fieldNameNodes;
		collectNodesInReversList(fieldNameNodes, fieldNode->data.declVar.name);

		Type * fieldType = getParserType(scope, fieldNode->data.declVar.type);
		if (!fieldType) {
			YO_ASSERT(isError());
			return NULL;
		}
		for (int i = fieldNameNodes.size() - 1; i >= 0; i--) {
			YO_ASSERT(fieldNameNodes[i]->type == YO_NODE_NAME);
			std::string fieldName = getTokenStr(fieldNameNodes[i]);
			if (type->nameIndices.find(fieldName) != type->nameIndices.end()) {
				setError(ERROR_FIELD_DUPLICATED, fieldNameNodes[i], "Member %s is already exist in %s", fieldName.c_str(), name.c_str());
				return NULL;
			}
			type->nameIndices[fieldName] = type->names.size();
			type->names.push_back(fieldName);
			type->types.push_back(fieldType);
		}
	}
	return type;
}

YoProgCompiler::Type * YoProgCompiler::getParserType(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node);
	unsigned arrSize;
	switch (node->type) {
	case YO_NODE_DECL_FUNC:
	case YO_NODE_TYPE_FUNC: {
		std::vector<std::string> argNames;
		return getFuncDataType(getFuncNativeType(argNames, scope, node));
	}
	case YO_NODE_TYPE_MUTABLE:
		return getMutType(getParserType(scope, node->data.typeMutable.type), node);

	case YO_NODE_TYPE_CONST:
		return getConstType(getParserType(scope, node->data.typeMutable.type), node);

	case YO_NODE_TYPE_PTR:
		return getPtrType(getParserType(scope, node->data.typePtr.type), node);

	case YO_NODE_TYPE_STD_NAME:
		return getParserStdType(node->data.typeStdName);

	case YO_NODE_TYPE_NAME:
	case YO_NODE_NAME:
		return getScopeType(scope, node);

	case YO_NODE_TYPE_ARR:
		switch (node->data.typeArr.size->type) {
		case YO_NODE_CONST_INT:
			arrSize = (unsigned)node->data.typeArr.size->data.constInt.val;
			if ((YO_U64)arrSize != node->data.typeArr.size->data.constInt.val) {
				setError(ERROR_UNREACHABLE, node->data.typeArr.size, "Array size overflow");
				return NULL;
			}
			break;

		default:
			setError(ERROR_UNREACHABLE, node->data.typeArr.size, "Const size required for array");
			return NULL;
		}
		return getArrayType(arrSize, getParserType(scope, node->data.typeArr.type), node);
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

		case YO_NODE_DECL_TYPE:
			if (!compileDeclType(module, stmt)) {
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

	std::vector<std::string> argNames;
	FuncNativeType * funcNativeType = getFuncNativeType(argNames, scope, node);
	Function * func = new Function(scope, funcNativeType, argNames, name, node);
	getModule(scope)->funcs.push_back(func);

	for (int i = 0; i < (int)funcNativeType->args.size(); i++) {
		FuncNativeType::Arg& arg = funcNativeType->args[i];
		for (int j = 0; j < (int)func->stackValues.size(); j++) {
			if (func->stackValues[j]->name == argNames[i]) {
				setError(ERROR_VAR_DUPLICATED, node, "Arg %s is already exist", argNames[i].c_str());
				return NULL;
			}
		}
		if (arg.type->etype == TYPE_VOID) {
			setError(ERROR_TYPE, node, "Variable %s should not be void", argNames[i].c_str());
			return NULL;
		}

		StackValue * stackValue = new StackValue(arg.type, argNames[i], node);
		stackValue->isArg = true;
		stackValue->isMutable = arg.isMutable;
		func->stackValues.push_back(stackValue);
	}
	
	if (!compileFuncBody(func, node->data.func.body)) {
		YO_ASSERT(isError());
		return NULL;
	}

	std::vector<StackValue*>::iterator vit = func->stackValues.begin();
	while (vit != func->stackValues.end()) {
		StackValue * stackValue = *vit;
		if ((!stackValue->type || !stackValue->isUsed) && !stackValue->isTemp) {
#if 0
			if (stackValue->name[0] != '_') {
				setError(ERROR_VAR_NOT_USED, stackValue->parserNode, "Variable '%s' is not used", stackValue->name.c_str());
				return NULL;
			}
#endif
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

			case YO_NODE_DECL_TYPE:
				if (!compileDeclType(func, stmt)) {
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

YoProgCompiler::Type * YoProgCompiler::compileDeclType(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_TYPE);
	YO_ASSERT(node->data.declType.name && node->data.declType.name->type == YO_NODE_NAME);
	YO_ASSERT(node->data.declType.type && node->data.declType.type->isType());
	
	std::string name = getTokenStr(node->data.declType.name);
	std::map<std::string, Type*>::iterator it = scope->types.find(name);
	if (it != scope->types.end()) {
		setError(ERROR_TYPE_DUPLICATED, node, "Type %s is already exist", name.c_str());
		return NULL;
	}

	YoParserNode * typeNode = node->data.declType.type;
	switch (typeNode->type) {
	case YO_NODE_TYPE_CLASS:
		return declStructType(scope, TYPE_CLASS, name, typeNode);
	}
	Type * type = getParserType(scope, typeNode);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	scope->types[name] = type;
	return type;
}

YoProgCompiler::StackValue * YoProgCompiler::compileDeclVar(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DECL_VAR);

	Type * type = NULL;
	if (node->data.declVar.type) {
		YO_ASSERT(node->data.declVar.type && node->data.declVar.type->isType());
		type = getParserType(scope, node->data.declVar.type);
		if (!type) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	else{
		type = getType(TYPE_UNKNOWN_YET);
	}

	YO_ASSERT(node->data.declVar.name && node->data.declVar.name->type == YO_NODE_NAME);

	std::string name = getTokenStr(node->data.declVar.name);
	for (int i = 0; i < (int)scope->stackValues.size(); i++) {
		if (scope->stackValues[i]->name == name) {
			setError(ERROR_VAR_DUPLICATED, node->data.declVar.name, "Variable %s is already exist", name.c_str());
			return NULL;
		}
	}
	if (type->etype == TYPE_VOID) {
		setError(ERROR_TYPE, node->data.declVar.name, "Variable %s should not be void", name.c_str());
		return NULL;
	}

	StackValue * stackValue = new StackValue(type, name, node->data.declVar.name);
	stackValue->isMutable = node->data.declVar.isMutable;
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
		std::vector<StackValue*>::reverse_iterator vit = scope->stackValues.rbegin();
		for (; vit != scope->stackValues.rend(); ++vit) {
			StackValue * stackValue = *vit;
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
		std::map<std::string, Type*>::iterator tit = scope->types.find(name);
		if (tit != scope->types.end()) {
			out.ename = NAME_TYPE;
			out.scope = scope;
			out.type = tit->second;
			return true;
		}
		scope = scope->parent;
	}
	YO_ASSERT(scope->escope == SCOPE_MODULE && dynamic_cast<Module*>(scope));
	Module * module = (Module*)scope;
	std::vector<Function*>::iterator fit = module->funcs.begin();
	for (; fit != module->funcs.end(); ++fit) {
		Function * func = *fit;
		if (func->name == name) {
			out.ename = NAME_MODULE_FUNCTION;
			out.scope = scope;
			out.func = func;
			return true;
		}
	}
	std::map<std::string, Type*>::iterator tit = scope->types.find(name);
	if (tit != scope->types.end()) {
		out.ename = NAME_TYPE;
		out.scope = scope;
		out.type = tit->second;
		return true;
	}
	out.ename = NAME_UNKNOWN;
	out.scope = NULL;
	return false;
}

YoProgCompiler::Operation * YoProgCompiler::compileValue(Scope * scope, YoParserNode * node)
{
	return getValue(scope, compileOp(scope, node));
}

YoProgCompiler::Operation * YoProgCompiler::compileOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node);
	if (isError()) {
		return NULL;
	}
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
		op->constInt.bits = 1;
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

		case NAME_TYPE:
			op = newOperation(OP_TYPE, node);
			op->type = nameInfo.type;
			return op;

		case NAME_MODULE_FUNCTION:
			op = newOperation(OP_FUNC, node);
			op->func = nameInfo.func;
			op->type = getPtrType(nameInfo.func->funcNativeType);
			return op;
		}
		setError(ERROR_UNREACHABLE, node, "Error name: %s", name.c_str());
		return NULL;

	case YO_NODE_ASSIGN:
		return compileAssign(scope, node);

	case YO_NODE_NEW_OBJ_PROPS:
		return compileNewObjProps(scope, node);

	case YO_NODE_NEW_OBJ_EXPS:
		return compileNewObjExprs(scope, node);

	case YO_NODE_BIN_OP:
		return compileBinOp(scope, node);

	case YO_NODE_DECL_FUNC:
		return compileSubFunc(scope, node);

	case YO_NODE_DOTNAME:
		return compileDotName(scope, node);

	case YO_NODE_SIZEOF:
		return compileSizeOf(scope, node);

	case YO_NODE_CALL:
		return compileCall(scope, node);

	case YO_NODE_CAST:
		return convertValueToType(scope, compileOp(scope, node->data.cast.expr), getParserType(scope, node->data.cast.type), CONVERT_BY_HAND, node);
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

YoProgCompiler::Operation * YoProgCompiler::compileDotOp(Scope * scope, Operation * left, YoParserNode * right, YoParserNode * node)
{
	if (right->type != YO_NODE_NAME && right->type != YO_NODE_DOTNAME) {
		setError(ERROR_UNREACHABLE, right, "Member name required: %d", (int)right->type);
		return NULL;
	}
	Type * leftValueType;
	bool isLeftTypeOp = isTypeOp(left);
	if (isLeftTypeOp) {
		leftValueType = left->type;
		if (leftValueType->etype != TYPE_STRUCT && leftValueType->etype != TYPE_CLASS) {
			setError(ERROR_TYPE, node, "Struct or class type required: %s", leftValueType->name.c_str());
			return NULL;
		}
	}
	else if (isValueOp(left)) {
		leftValueType = skipTypeAttrs(left->type);
		if (leftValueType->etype != TYPE_STRUCT && leftValueType->etype != TYPE_CLASS) {
			setError(ERROR_TYPE, node, "Struct or class type required: %s", leftValueType->name.c_str());
			return NULL;
		}
		StackValue * val = allocTempValue(scope, leftValueType, "temp", node);
		Operation * stackValueOp = newStackValuePtrOp(val, node);
		
		Operation * storeOp = newOperation(OP_STORE_VALUE, node);
		storeOp->ops.push_back(left);
		storeOp->ops.push_back(stackValueOp);
		// storeOp->type = left->type;

		stackValueOp->ops.push_back(storeOp);
		left = stackValueOp;
	}
	else{
		leftValueType = skipTypeAttrs(getValueType(left));
		if (leftValueType->etype != TYPE_STRUCT && leftValueType->etype != TYPE_CLASS) {
			setError(ERROR_TYPE, node, "Struct or class type required: %s", leftValueType->name.c_str());
			return NULL;
		}
	}
	std::string fieldName = getTokenStr(right);
	StructType * structType = dynamic_cast<StructType*>(leftValueType);
	YO_ASSERT(structType);
	std::map<std::string, int>::iterator it = structType->nameIndices.find(fieldName);
	if (it != structType->nameIndices.end()) {
		if (isLeftTypeOp) {
			Operation * op = newOperation(OP_TYPE_STRUCT_ELEMENT, node);
			op->typeStructElement.parent = structType;
			op->typeStructElement.index = it->second;
			op->type = structType->types[it->second];
			return op;
		}
		return newStructElementPtrOp(left, it->second, node);
	}
	setError(ERROR_FIELD_NOT_FOUND, node, "Member %s is not found in %s", fieldName.c_str(), structType->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileDotName(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_DOTNAME);

	std::vector<YoParserNode*> nodes;
	collectDotNameNodesInReversList(nodes, node);

	Operation * op = NULL;
	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (; it != nodes.rend(); ++it) {
		YoParserNode * curNode = *it;
		if (!op) {
			op = compileOp(scope, curNode);
		}
		else{
			op = compileDotOp(scope, op, curNode, node);
		}
		if (!op) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compileSizeOf(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_SIZEOF);
	Operation * op = compileValue(scope, node->data.sizeOf.node);
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * sizeOp = newOperation(OP_SIZEOF, node);
	sizeOp->ops.push_back(op);
	sizeOp->type = getIntType(sizeof(int) * 8, false);
	return sizeOp;
}

YoProgCompiler::Operation * YoProgCompiler::compileCall(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_CALL);
	Operation * nameOp = compileOp(scope, node->data.call.name);
	if (!nameOp) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (nameOp->eop == OP_STACK_VALUE_PTR) {
		if (!nameOp->stackValue->type){
			setError(ERROR_UNREACHABLE, nameOp->stackValue->parserNode, "Type required");
			return NULL;
		}
		/* if (nameOp->stackValue->type->etype == TYPE_PTR) {
			Type * funcType = getPtrSubType(nameOp->stackValue->type);
			if (funcType->etype == TYPE_FUNC_NATIVE) {
				YO_ASSERT(dynamic_cast<FuncNativeType*>(funcType));
				FuncNativeType * funcNativeType = (FuncNativeType*)funcType;
				FuncDataType * funcDataType = getFuncDataType(funcNativeType);
				nameOp = convertValueToType(scope, nameOp, funcDataType, CONVERT_AUTO, node);
			}
		} */
		if (nameOp->stackValue->type->etype != TYPE_FUNC_DATA || !dynamic_cast<FuncDataType*>(nameOp->stackValue->type)){
			setError(ERROR_TYPE, nameOp->stackValue->parserNode, "Func type required, found: %s", nameOp->stackValue->type->name.c_str());
			return NULL;
		}
		Operation * funcElemPtrPtr = newStructElementPtrOp(nameOp, 0, node);
		if (!funcElemPtrPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * funcElemPtr = getValue(scope, funcElemPtrPtr);

		Operation * closureElemPtrPtr = newStructElementPtrOp(nameOp, 1, node);
		if (!closureElemPtrPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * closureElemPtr = getValue(scope, closureElemPtrPtr);

		FuncDataType * funcDataType = (FuncDataType*)nameOp->stackValue->type;

		Operation * op = newOperation(OP_CALL_CLOSURE, node);
		op->callClosure.funcDataType = funcDataType;
		op->type = funcDataType->funcNativeType->resType;
		// op->ops.push_back(newOperation(OP_NOP, node));
		op->ops.push_back(funcElemPtr);
		op->ops.push_back(closureElemPtr);

		std::vector<YoParserNode*> argNodes;
		collectNodesInReversList(argNodes, node->data.call.args);
		op->callClosure.args = argNodes.size();

		if (op->callClosure.args != funcDataType->funcNativeType->args.size()-1) {
			setError(ERROR_CALL_ARGS_NUMBER, node, "Error call args number %d, required %d", op->callClosure.args, funcDataType->funcNativeType->args.size()-1);
			return NULL;
		}

		YO_ASSERT(funcDataType->funcNativeType->args.size()-1/*closure*/ == argNodes.size());
		for (int i = 0; i < (int)argNodes.size(); i++) {
			Operation * argOp = compileOp(scope, argNodes[argNodes.size()-1-i]);
			argOp = convertValueToType(scope, argOp, funcDataType->funcNativeType->args[i + 1].type, CONVERT_AUTO, node);
			if (!argOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->ops.push_back(argOp);
		}
		return op;
	}
	if (nameOp->eop == OP_FUNC) {
		Operation * nullOp = newOperation(OP_CONST_NULL, node);
		nullOp->type = getVoidPtrType();
		nullOp = convertPtrToType(scope, nullOp, nameOp->func->funcNativeType->args[0].type, node);
		if (!nullOp) {
			YO_ASSERT(isError());
			return NULL;
		}

		Operation * op = newOperation(OP_CALL_FUNC, node);
		op->callFunc.func = nameOp->func;
		op->type = nameOp->func->funcNativeType->resType;
		// op->ops.push_back(newOperation(OP_NOP, node));
		op->ops.push_back(nameOp);
		op->ops.push_back(nullOp);

		std::vector<YoParserNode*> argNodes;
		collectNodesInReversList(argNodes, node->data.call.args);
		op->callFunc.args = argNodes.size();

		if (op->callFunc.args != nameOp->func->funcNativeType->args.size()-1) {
			setError(ERROR_CALL_ARGS_NUMBER, node, "Error call args number %d, required %d", op->callClosure.args, nameOp->func->funcNativeType->args.size()-1);
			return NULL;
		}

		YO_ASSERT(nameOp->func->funcNativeType->args.size() - 1/*closure*/ == argNodes.size());
		for (int i = 0; i < (int)argNodes.size(); i++) {
			Operation * argOp = compileOp(scope, argNodes[argNodes.size() - 1 - i]);
			argOp = convertValueToType(scope, argOp, nameOp->func->funcNativeType->args[i + 1].type, CONVERT_AUTO, node);
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
	temp->isMutable = true;
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
	Operation * op = newOperation(OP_STACK_VALUE_PTR, node);
	op->stackValue = value;
	op->type = value->type ? getPtrType(value->type) : NULL;
	return op;
}

YoProgCompiler::Type * YoProgCompiler::getPtrSubType(Type * ptrType, YoParserNode * node)
{
	if (!ptrType || ptrType->etype != TYPE_PTR || !dynamic_cast<SubType*>(ptrType) || !((SubType*)ptrType)->subType) {
		setError(ERROR_UNREACHABLE, node ? node : ptrType->parserNode, "Pointer type required");
		return NULL;
	}
	return ((SubType*)ptrType)->subType;
}

YoProgCompiler::Type * YoProgCompiler::getSubType(Type * ptrType, YoParserNode * node)
{
	if (!ptrType || !dynamic_cast<SubType*>(ptrType) || !((SubType*)ptrType)->subType) {
		setError(ERROR_UNREACHABLE, node ? node : ptrType->parserNode, "SubType type required");
		return NULL;
	}
	return ((SubType*)ptrType)->subType;
}

YoProgCompiler::Operation * YoProgCompiler::newStructElementPtrOp(Operation * ptrOp, int index, YoParserNode * node)
{
	Type * type = skipTypeAttrs(getPtrSubType(ptrOp->type, node));
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if ((type->etype != TYPE_STRUCT && type->etype != TYPE_CLASS && type->etype != TYPE_FUNC_DATA) || !dynamic_cast<StructType*>(type)) {
		setError(ERROR_UNREACHABLE, node, "Struct pointer required");
		return NULL;
	}
	StructType * structType = (StructType*)type;
	if ((size_t)index >= structType->types.size()) {
		setError(ERROR_UNREACHABLE, node, "Error element index: %d", index);
		return NULL;
	}
	Operation * elemPtr = newOperation(OP_STRUCT_ELEMENT_PTR, node);
	elemPtr->ops.push_back(ptrOp);
	elemPtr->structElementIndex = index;
	elemPtr->type = getPtrType(structType->types[index], node);
	return elemPtr;
}

YoProgCompiler::Operation * YoProgCompiler::compileSubFunc(Scope * scope, YoParserNode * node)
{
	Function * func = compileFunc(scope, node);
	if (!func) {
		YO_ASSERT(isError());
		return NULL;
	}
	return newFuncDataPtrOp(scope, func, node);
	/*
	FuncDataType * funcDataType = getFuncDataType(func->funcNativeType);
	StackValue * temp = allocTempValue(scope, funcDataType, "temp", node);

	Operation * tempOp = newStackValuePtrOp(temp, node);

	// func data element 0
	Operation * funcElemPtrPtr = newStructElementPtrOp(tempOp, 0, node);
	if (!funcElemPtrPtr) {
		YO_ASSERT(isError());
		return NULL;
	}

	Operation * funcOp = newOperation(OP_FUNC, node);
	funcOp->func = func;
	funcOp->type = getPtrType(func->funcNativeType);

	Operation * storeOp = newOperation(OP_STORE_VALUE, node);
	storeOp->ops.push_back(funcOp);
	storeOp->ops.push_back(funcElemPtrPtr);
	// storeOp->type = funcOp->type;

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
	closureElemPtrPtr = convertPtrToType(scope, closureElemPtrPtr, getPtrType(nullOp->type), node);

	storeOp = newOperation(OP_STORE_VALUE, node);
	storeOp->ops.push_back(nullOp);
	storeOp->ops.push_back(closureElemPtrPtr);
	// storeOp->type = nullOp->type;

	resultOp->ops.push_back(storeOp);
	return resultOp;
	*/
}

YoProgCompiler::Operation * YoProgCompiler::compileNewObjExprs(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_NEW_OBJ_EXPS);

	Type * type = getScopeType(scope, node->data.obj.name);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->etype != TYPE_STRUCT && type->etype != TYPE_CLASS) {
		setError(ERROR_TYPE, node, "Struct or class type required: %s", type->name.c_str());
		return NULL;
	}
	StructType * structType = dynamic_cast<StructType*>(type);
	YO_ASSERT(structType);

	StackValue * temp = allocTempValue(scope, type, "temp", node);
	Operation * resultOp = newStackValuePtrOp(temp, node);

#if 1
	Operation * op = newOperation(OP_STORE_VALUE, node);
	Operation * zeroValue = newOperation(OP_VALUE_ZERO, node);
	zeroValue->type = temp->type;
	op->ops.push_back(zeroValue);
	op->ops.push_back(newStackValuePtrOp(temp, node));
	resultOp->ops.push_back(op);
#else
	Operation * op = newOperation(OP_STACK_VALUE_MEMZERO, node);
	op->stackValue = temp;
	resultOp->ops.push_back(op);
#endif

	// std::map<std::string, bool> initialized;
	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.obj.values);

	int i;
	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (i = 0; it != nodes.rend(); ++it, ++i) {
		Type * dstType = structType->types[i];
		Operation * expr = compileOp(scope, *it);
		if (!expr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * tempOp = newStackValuePtrOp(temp, node);
		Operation * dst = newStructElementPtrOp(tempOp, i, node);
		if (!dst) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (getValueType(expr) != dstType){
			expr = getValue(scope, expr);
			expr = convertValueToType(scope, expr, dstType, CONVERT_AUTO, node);
			if (!expr) {
				return NULL;
			}
			op = newOperation(OP_STORE_VALUE, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
		}
		else{
			op = newOperation(isValueOp(expr) ? OP_STORE_VALUE : OP_STORE_PTR, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
		}
		resultOp->ops.push_back(op);
	}
	return resultOp;
}

YoProgCompiler::Operation * YoProgCompiler::compileNewObjProps(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_NEW_OBJ_PROPS);

	Type * type = getScopeType(scope, node->data.obj.name);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->etype != TYPE_STRUCT && type->etype != TYPE_CLASS) {
		setError(ERROR_TYPE, node, "Struct or class type required: %s", type->name.c_str());
		return NULL;
	}
	StructType * structType = dynamic_cast<StructType*>(type);
	YO_ASSERT(structType);

	StackValue * temp = allocTempValue(scope, type, "temp", node);
	Operation * resultOp = newStackValuePtrOp(temp, node);

	Operation * op = newOperation(OP_STACK_VALUE_MEMZERO, node);
	op->stackValue = temp;
	resultOp->ops.push_back(op);

	// std::map<std::string, bool> initialized;
	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.obj.values);

	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (; it != nodes.rend(); ++it) {
		YoParserNode * propNode = *it;
		YO_ASSERT(propNode->type == YO_NODE_ASSIGN && propNode->data.assign.op == T_PROP_ASSIGN);

		YoParserNode * propNameNode = propNode->data.assign.left;
		YO_ASSERT(propNameNode->type == YO_NODE_NAME);
		std::string fieldName = getTokenStr(propNameNode);
		std::map<std::string, int>::iterator nit = structType->nameIndices.find(fieldName);
		if (nit == structType->nameIndices.end()) {
			setError(ERROR_FIELD_NOT_FOUND, propNameNode, "Member %s is not found in %s", fieldName.c_str(), structType->name.c_str());
			return NULL;
		}
		int i = nit->second;
		Type * dstType = structType->types[i];
		Operation * expr = compileOp(scope, propNode->data.assign.right);
		if (!expr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * tempOp = newStackValuePtrOp(temp, node);
		Operation * dst = newStructElementPtrOp(tempOp, i, node);
		if (!dst) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (getValueType(expr) != dstType){
			expr = getValue(scope, expr);
			expr = convertValueToType(scope, expr, dstType, CONVERT_AUTO, node);
			if (!expr) {
				return NULL;
			}
			op = newOperation(OP_STORE_VALUE, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
		}
		else{
			op = newOperation(isValueOp(expr) ? OP_STORE_VALUE : OP_STORE_PTR, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
		}
		resultOp->ops.push_back(op);
	}
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
	Operation * right = compileOp(scope, node->data.assign.right);
	if (!right) {
		return NULL;
	}
	Operation * op;
	Type * leftValueType;
	switch (left->eop) {
	case OP_STACK_VALUE_PTR:
		if (node->data.assign.op == T_INIT_ASSIGN) {
			left->stackValue->isInitialized = true;
			left->stackValue->isUsed = false;
		}
		else if (!left->stackValue->isMutable) {
			setError(ERROR_MUTABLE_REQUIRED, node, "Variable %s is not mutable", left->stackValue->name.c_str());
			return NULL;
		}
		else{
			left->stackValue->isChanged = true;
		}
		YO_ASSERT(left->type && left->stackValue && left->stackValue->type && right->type);
		if (right->eop == OP_FUNC && left->stackValue->type->etype == TYPE_UNKNOWN_YET) {
			FuncDataType * funcDataType = getFuncDataType(right->func->funcNativeType);
			right = convertValueToType(scope, right, funcDataType, CONVERT_AUTO, node);
		}
		if (matchTypeTemplate(scope, left->stackValue->type, getValueType(right))) {
			if (left->stackValue->type->etype == TYPE_VOID) {
				setError(ERROR_TYPE, left->stackValue->parserNode, "Variable %s should not be void", left->stackValue->name.c_str());
				return NULL;
			}
			left->type = getPtrType(left->stackValue->type);
		}
		if (left->type->isUnknownYet) {
			setError(ERROR_TYPE, left->stackValue->parserNode, "Variable %s has unknown type", left->stackValue->name.c_str());
			return NULL;
		}
		// no break

	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
		YO_ASSERT(node->data.assign.op == T_ASSIGN || node->data.assign.op == T_INIT_ASSIGN && left->eop == OP_STACK_VALUE_PTR);
		leftValueType = getPtrSubType(left->type);
		if (!leftValueType) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (getValueType(right) != leftValueType){
			right = getValue(scope, right);
			right = convertValueToType(scope, right, leftValueType, CONVERT_AUTO, node);
			if (!right) {
				return NULL;
			}
			op = newOperation(OP_STORE_VALUE, node);
			op->ops.push_back(right);	// src
			op->ops.push_back(left);	// dst
			op->type = right->type;
			return op;
		}
		op = newOperation(isValueOp(right) ? OP_STORE_VALUE : OP_STORE_PTR, node);
		op->ops.push_back(right);	// src
		op->ops.push_back(left);	// dst
		op->type = right->type;
		return op;
	}
	setError(ERROR_OP, left->parserNode, "Not supported assign for left op: %d", (int)left->eop);
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileIndexOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP && node->data.binOp.op == T_INDEX);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);

	Operation * left = compileOp(scope, node->data.binOp.left);
	Operation * right = compileValue(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	if (!left->type) {
		setError(ERROR_TYPE_UNKNOWN, left->parserNode, "Type unknown");
		return NULL;
	}
	if (!right->type) {
		setError(ERROR_TYPE_UNKNOWN, right->parserNode, "Type unknown");
		return NULL;
	}
	Type * subType;
	int bits;
	bool isSigned;
	switch (left->eop) {
	case OP_TYPE:
		switch (left->type->etype) {
		case TYPE_ARRAY:
			YO_ASSERT(dynamic_cast<ArrayType*>(left->type));
			subType = ((ArrayType*)left->type)->subType;
			break;
		
		case TYPE_PTR:
			YO_ASSERT(dynamic_cast<SubType*>(left->type));
			subType = ((SubType*)left->type)->subType;
			break;

		default:
			setError(ERROR_TYPE, left->parserNode, "Array or pointer type required");
			return NULL;
		}
		if (getIntBits(right->type, bits, isSigned)) {
			Operation * op = newOperation(OP_TYPE, node);
			op->type = subType;
			return op;
		}
		setError(ERROR_TYPE, right->parserNode, "Integer type required");
		return NULL;
	}
	Type * leftValueType = getPtrSubType(left->type, node);
	if (!leftValueType) {
		return NULL;
	}
	switch (leftValueType->etype) {
	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(leftValueType));
		if (getIntBits(right->type, bits, isSigned)) {
			Operation * op = newOperation(OP_ELEMENT_PTR, node);
			op->type = getPtrType(((ArrayType*)leftValueType)->subType);
			op->ops.push_back(left);
			op->ops.push_back(right);
			return op;
		}
		setError(ERROR_TYPE, right->parserNode, "Integer type required");
		return NULL;
	}
	setError(ERROR_UNREACHABLE, left->parserNode, "Not supported type for index");
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileBinOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);
	EOperation eop = OP_NOP;
	switch (node->data.binOp.op) {
	case T_PLUS:
		eop = OP_BIN_ADD;
		break;

	case T_INDEX:
		return compileIndexOp(scope, node);

	// case T_DOT:
	//	return compileDotOp(scope, node->data.binOp.left, node->data.binOp.right, node);

	default:
		setError(ERROR_OP, node, "Error bin op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileValue(scope, node->data.binOp.left);
	Operation * right = compileValue(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	if (left->type != right->type) {
		Type * resType = getBinOpNumCast(left->type, right->type);
		if (resType) {
			Operation * newLeft = convertValueToType(scope, left, resType, CONVERT_BY_HAND, node);
			Operation * newRight = convertValueToType(scope, right, resType, CONVERT_BY_HAND, node);
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

bool YoProgCompiler::matchTypeTemplate(Scope * scope, Type *& a, Type * b)
{
	if (b->etype == TYPE_UNKNOWN_YET) {
		YO_ASSERT(false);
		return false;
	}
	if (a->etype == TYPE_UNKNOWN_YET) {
		a = b;
		return true;
	}
	SubType * curLeft = dynamic_cast<SubType*>(a);
	SubType * curRight = dynamic_cast<SubType*>(b);
	if (!curLeft || !curRight) {
		return false;
	}
	for (;;) {
		if (curLeft->etype != curRight->etype) {
			return false;
		}
		switch (curLeft->etype) {
		case TYPE_ARRAY:
			YO_ASSERT(dynamic_cast<ArrayType*>(curLeft));
			YO_ASSERT(dynamic_cast<ArrayType*>(curRight));
			if (((ArrayType*)curLeft)->size != ((ArrayType*)curRight)->size) {
				return false;
			}
			break;
		}
		if (curRight->subType->etype == TYPE_UNKNOWN_YET) {
			YO_ASSERT(false);
			return false;
		}
		if (curLeft->subType->etype == TYPE_UNKNOWN_YET) {
			// curLeft->subType = curRight->subType;
			a = b;
			return true;
		}
		curLeft = dynamic_cast<SubType*>(curLeft->subType);
		curRight = dynamic_cast<SubType*>(curRight->subType);
		if (!curLeft || !curRight) {
			return false;
		}
	}
	return false;
}

bool YoProgCompiler::compileStmtReturn(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_RETURN);
	Operation * op = newOperation(OP_RETURN, node);
	if (node->data.stmtReturn.node) {
		Operation * value = compileValue(scope, node->data.stmtReturn.node);
		if (!value) {
			YO_ASSERT(isError());
			return false;
		}
		Function * func = getFunction(scope);
		if (matchTypeTemplate(scope, func->funcNativeType->resType, value->type)) {
			updateFuncNativeType(func->funcNativeType);
		}
		else {
			value = convertValueToType(scope, value, func->funcNativeType->resType, CONVERT_AUTO, node);
			if (!value) {
				return false;
			}
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

bool YoProgCompiler::getIntBits(Type * type, int& bits, bool& isSigned)
{
	switch (type->etype) {
	case TYPE_INT8: bits = 8; isSigned = true; return true;
	case TYPE_INT16: bits = 16; isSigned = true; return true;
	case TYPE_INT32: bits = 32; isSigned = true; return true;
	case TYPE_INT64: bits = 64; isSigned = true; return true;
	case TYPE_UINT8: bits = 8; isSigned = false; return true;
	case TYPE_UINT16: bits = 16; isSigned = false; return true;
	case TYPE_UINT32: bits = 32; isSigned = false; return true;
	case TYPE_UINT64: bits = 64; isSigned = false; return true;
	}
	return false;
}

YoProgCompiler::Type * YoProgCompiler::getBinOpNumCast(Type * a, Type * b)
{
	if (a == b) {
		return a;
	}
	int key = getConvertKey(a->etype, b->etype);
	std::map<int, Type*>::iterator it = binOpNumCastTypes.find(key);
	if (it != binOpNumCastTypes.end()) {
		return it->second;
	}

	Type * resType = NULL;
	for (;;) {
		int bits[2];
		bool isSigned[2];
		bool isInt[2] = {
			getIntBits(a, bits[0], isSigned[0]),
			getIntBits(b, bits[1], isSigned[1]),
		};
		if (isInt[0] && isInt[1]) {
			if (isSigned[0] == isSigned[1]) {
				int resBits = bits[0] > bits[1] ? bits[0] : bits[1];
				bool resSigned = isSigned[0];
				resType = getIntType(resBits, resSigned);
				break;
			}
#if 1
			int resBits = bits[0] > bits[1] ? bits[0] : bits[1];
			bool resSigned = true;
#else
			int resBits;
			bool resSigned = true;
			int maxBits = bits[0] > bits[1] ? bits[0] : bits[1];
			int minBits = bits[0] < bits[1] ? bits[0] : bits[1];
			if (minBits * 2 >= maxBits) {
				resBits = maxBits * 2;
#if 1
				if (resBits > 32) resBits = 32;
				if (resBits < maxBits) resBits = maxBits;
#else
				if (resBits > 64) resBits = 64;
#endif
			}
			else{
				resBits = maxBits;
			}
#endif
			resType = getIntType(resBits, resSigned);
			break;
		}
		bool isFloat[2] = {a->isFloat(), b->isFloat()};
		if (isInt[0] && isFloat[1]) {
			resType = getFloatType(64);
			break;
		}
		if (isInt[1] && isFloat[0]) {
			resType = getFloatType(64);
			break;
		}
		if (isFloat[0] && isFloat[1]) {
			resType = getFloatType(64);
			break;
		}
		return NULL;
	}
	YO_ASSERT(resType);
	binOpNumCastTypes[key] = resType;
	return resType;
}

YoProgCompiler::CastOp YoProgCompiler::getCastOp(Type * from, Type * to)
{
	int key = getConvertKey(from->etype, to->etype);
	std::map<int, CastOp>::iterator it = castOps.find(key);
	if (it != castOps.end()) {
		return it->second;
	}

	CastOp castOp;
	for (;;) {
		int bits[2];
		bool isSigned[2];
		bool isInt[2] = {
			getIntBits(from, bits[0], isSigned[0]),
			getIntBits(to, bits[1], isSigned[1]),
		};
		if (isInt[0] && isInt[1]) {
			int resBits = bits[1];
			bool resSigned = isSigned[1];
			Type * resType = getIntType(resBits, resSigned);
			EOperation eop;
			if (bits[1] <= bits[0]) {
				eop = OP_CAST_TRUNC;
			}
			else if (isSigned[0] && isSigned[1]){
				eop = OP_CAST_SIGN_EXT;
			}
			else{
				eop = OP_CAST_ZERO_EXT;
			}
			castOp = CastOp(to->etype, eop, bits[1] >= bits[0] ? CAST_AUTO : CAST_BY_HAND);
			break;
		}
		bool isFloat[2] = { from->isFloat(), to->isFloat() };
		if (isInt[0] && isFloat[1]) {
			castOp = CastOp(to->etype, isSigned[0] ? OP_CAST_SI_TO_FP : OP_CAST_UI_TO_FP, CAST_BY_HAND);
			break;
		}
		if (isFloat[0] && isInt[1]) {
			castOp = CastOp(to->etype, isSigned[1] ? OP_CAST_FP_TO_SI : OP_CAST_FP_TO_UI, CAST_BY_HAND);
			break;
		}
		if (isFloat[0] && isFloat[1]) {
			bool ext = to->etype == TYPE_FLOAT64;
			castOp = CastOp(to->etype, ext ? OP_CAST_FP_EXT : OP_CAST_FP_TRUNC, ext ? CAST_AUTO : CAST_BY_HAND);
			break;
		}
		castOp = CastOp(to->etype, OP_NOP);
		break;
	}
	castOps[key] = castOp;
	return castOp;
}

/*
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
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT16)] = CastOp(TYPE_INT16, OP_CAST_ZERO_EXT, CAST_AUTO);
	convertOps[getConvertKey(TYPE_UINT8, TYPE_INT32)] = CastOp(TYPE_INT32, OP_CAST_ZERO_EXT, CAST_AUTO);
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
*/

bool YoProgCompiler::isValueOp(Operation * op)
{
	YO_ASSERT(op->type);
	if (!op) {
		return false;
	}
	switch (op->eop) {
	case OP_STACK_VALUE_PTR:
	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
		return false;
	}
	return true;
}

bool YoProgCompiler::isTypeOp(Operation * op)
{
	YO_ASSERT(op->type);
	if (!op) {
		return false;
	}
	switch (op->eop) {
	case OP_TYPE:
	case OP_TYPE_STRUCT_ELEMENT:
		return true;
	}
	return false;
}

YoProgCompiler::Type * YoProgCompiler::getValueType(Operation * op)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(op->type);
	switch (op->eop) {
	case OP_STACK_VALUE_PTR:
	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
		return getPtrSubType(op->type);
	}
	return op->type;
}

YoProgCompiler::Type * YoProgCompiler::skipTypeAttrs(Type * type)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	switch (type->etype) {
	case TYPE_MUT:
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<SubType*>(type) && ((SubType*)type)->subType);
		return ((SubType*)type)->subType;
	}
	return type;
}

YoProgCompiler::Operation * YoProgCompiler::getValue(Scope * scope, Operation * op)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	Type * type;
	Operation * loadOp;
	switch (op->eop) {
	case OP_STACK_VALUE_PTR:
#if 0
		if (!op->stackValue->isInitialized) {
			setError(ERROR_VAR_NOT_INITIALIZED, op->stackValue->parserNode, "Variable %s is not initialized", op->stackValue->name.c_str());
			return NULL;
		}
		// no break
#endif
	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
		type = getPtrSubType(op->type);
		if (!type) {
			YO_ASSERT(isError());
			return NULL;
		}
		loadOp = newOperation(OP_LOAD, op->parserNode);
		loadOp->ops.push_back(op);
		loadOp->type = type;
		return loadOp;
	}
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::convertPtrToType(Scope * scope, Operation * op, Type * type, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(op->type && type);
	if (op->type->etype != TYPE_PTR || type->etype != TYPE_PTR) {
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Pointers required to convert: %s => %s", op->type->name.c_str(), type->name.c_str());
		return NULL;
	}
	Operation * convertOp = newOperation(OP_CAST_PTR, node);
	convertOp->type = type;
	convertOp->ops.push_back(op);
	return convertOp;
}

YoProgCompiler::Operation * YoProgCompiler::convertValueToType(Scope * scope, Operation * op, Type * type, EConvertType convertType, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(op->type && type);
	bool isValue = isValueOp(op);
	Type * valueType = isValue ? op->type : getValueType(op);
	if (valueType == type) {
		return op;
	}
	CastOp castOp = getCastOp(valueType, type);
	if (castOp.eop != OP_NOP) {
		if (castOp.castType == CAST_AUTO || convertType == CONVERT_BY_HAND) {
			Operation * convertOp = newOperation(castOp.eop, op->parserNode);
			convertOp->type = type;
			convertOp->ops.push_back(isValue ? op : getValue(scope, op));
			return convertOp;
		}
		int bits;
		bool isSigned, convertByHand = false;
		switch (op->eop) {
		case OP_CONST_INT:
			if (getIntBits(type, bits, isSigned)) {
				// YO_U64 mask = isSigned ? (YO_U64)-1 : 0;
				YO_U64 mask = ((YO_U64)1 << bits) - 1;
				if ((op->constInt.val & mask) == op->constInt.val) {
					convertByHand = true;
				}
			}
			else{
				switch (type->etype) {
				case TYPE_FLOAT32:
					if ((YO_U64)(float)op->constInt.val == op->constInt.val) {
						convertByHand = true;
					}
					break;

				case TYPE_FLOAT64:
					if ((YO_U64)(double)op->constInt.val == op->constInt.val) {
						convertByHand = true;
					}
					break;
				}
			}
			if (convertByHand) {
				Operation * convertOp = newOperation(castOp.eop, op->parserNode);
				convertOp->type = type;
				convertOp->ops.push_back(isValue ? op : getValue(scope, op));
				return convertOp;
			}
			break;
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error auto convert: %s to %s, posible lost value", op->type->name.c_str(), type->name.c_str());
		return NULL;
	}
	if (type->etype == TYPE_FUNC_DATA && valueType->etype == TYPE_PTR && op->eop == OP_FUNC) {
		YO_ASSERT(op->eop == OP_FUNC);
		Type * funcNativeType = getPtrSubType(valueType);
		if (funcNativeType->etype == TYPE_FUNC_NATIVE) {
			YO_ASSERT(dynamic_cast<FuncDataType*>(type));
			FuncDataType * funcDataType = (FuncDataType*)type;
			if (funcDataType->funcNativeType == funcNativeType) {
				Operation * resultOp = newFuncDataPtrOp(scope, op->func, node);
				// resultOp->ops.insert(resultOp->ops.begin(), op);
				return getValue(scope, resultOp);
			}
		}
	}
	setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), type->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::newFuncDataPtrOp(Scope * scope, Function * func, YoParserNode * node)
{
	FuncDataType * funcDataType = getFuncDataType(func->funcNativeType);
	StackValue * temp = allocTempValue(scope, funcDataType, "temp", node);

	Operation * tempOp = newStackValuePtrOp(temp, node);

	// func data element 0
	Operation * funcElemPtrPtr = newStructElementPtrOp(tempOp, 0, node);
	if (!funcElemPtrPtr) {
		YO_ASSERT(isError());
		return NULL;
	}

	// Function * func = op->func;
	Operation * funcOp = newOperation(OP_FUNC, node);
	funcOp->func = func;
	funcOp->type = getPtrType(func->funcNativeType);

	Operation * storeOp = newOperation(OP_STORE_VALUE, node);
	storeOp->ops.push_back(funcOp);
	storeOp->ops.push_back(funcElemPtrPtr);
	// storeOp->type = funcOp->type;

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
	closureElemPtrPtr = convertPtrToType(scope, closureElemPtrPtr, getPtrType(nullOp->type), node);

	storeOp = newOperation(OP_STORE_VALUE, node);
	storeOp->ops.push_back(nullOp);
	storeOp->ops.push_back(closureElemPtrPtr);
	// storeOp->type = nullOp->type;

	resultOp->ops.push_back(storeOp);
	return resultOp;
}