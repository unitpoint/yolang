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
	ptrType = NULL;
	refType = NULL;
	mutType = NULL;
	constType = NULL;
	ext.index = -1;
}

YoProgCompiler::Type::~Type()
{
	delete ptrType;
	delete refType;
	delete mutType;
	delete constType;

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

	case TYPE_MUT:
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<const SubType*>(this));
		return ((SubType*)this)->subType->isFloat();
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

	case TYPE_MUT:
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<const SubType*>(this));
		return ((SubType*)this)->subType->isNumber();
	}
	return false;
}

bool YoProgCompiler::Type::isSigned() const
{
	switch (etype) {
	case TYPE_INT8:
	case TYPE_INT16:
	case TYPE_INT32:
	case TYPE_INT64:
	case TYPE_FLOAT32:
	case TYPE_FLOAT64:
		return true;

	case TYPE_MUT:
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<const SubType*>(this));
		return ((SubType*)this)->subType->isSigned();
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
	isExtern = false;
	isVarArg = false;
	conv = YO_CALLING_DEFAULT;
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
	// isMutable = false;
	isInitialized = false;
	isChanged = false;
	isUsed = false;
	isTemp = false;
	// isClosure = false;
	initStackValue = NULL;
	initStructElementIndex = -1;
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

	if (parent) {
		parent->scopes.push_back(this);
	}
}

YoProgCompiler::Scope::~Scope()
{
	if (escope != SCOPE_BLOCK){
		for (int i = 0; i < (int)stackValues.size(); i++) {
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
	for (int i = 0; i < (int)scopes.size(); i++) {
		delete scopes[i];
	}
}

// ==============================================================

YoProgCompiler::Function::Function(Scope * p_parent, FuncNativeType * p_funcNativeType, 
	const std::vector<std::string>& p_argNames, const std::string& p_name, YoParserNode * p_node) :
	Scope(p_parent, SCOPE_FUNCTION, p_name, p_node), argNames(p_argNames)
{
	funcNativeType = p_funcNativeType;
	externFunc = NULL;
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
	/* std::vector<Function*>::iterator fit = funcs.begin();
	for (; fit != funcs.end(); ++fit) {
		Function * func = *fit;
		delete func;
	} */
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
	setError(ERROR_UNREACHABLE, NULL, "No module");
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

		const char * getBinOpName(EOperation eop, bool isFloat, bool isSigned)
		{
			switch (eop) {
			case OP_BIN_ADD:
				return isFloat ? "fadd" : "add";
			
			case OP_BIN_SUB:
				return isFloat ? "fsub" : "sub";

			case OP_BIN_MUL:
				return isFloat ? "fmul" : "mul";

			case OP_BIN_DIV:
				return isFloat ? "fdiv" : (isSigned ? "sdiv" : "udiv");

			case OP_BIN_MOD:
				return isFloat ? "fmod" : (isSigned ? "smod" : "umod");

			case OP_BIN_POWF:
				YO_ASSERT(isFloat);
				return  "fpow";

			case OP_BIN_POWI:
				YO_ASSERT(isFloat);
				return  "fpowi";

			case OP_CMP_EQ: return "==";
			case OP_CMP_NE: return "!=";
			case OP_CMP_LE: return "<=";
			case OP_CMP_GE: return ">=";
			case OP_CMP_LT: return "<";
			case OP_CMP_GT:	return ">";

			case OP_BIT_OR: return "|";
			case OP_BIT_AND: return "&";
			case OP_BIT_XOR: return "^";

			case OP_LOGICAL_OR: return "||";
			case OP_LOGICAL_AND: return "&&";
			}
			return "<unknown>";
		}

		void dumpCall(Function * func, Scope * scope, Operation * op, int depth)
		{
			YO_ASSERT((op->eop == OP_CALL_CLOSURE || op->eop == OP_CALL_FUNC) && op->ops.size() >= 2);

			bool isClosureCall = op->eop == YoProgCompiler::OP_CALL_CLOSURE;
			int extraArgs = isClosureCall ? 1 : op->callFunc.extraArgs;
			int i, startArg = op->ops.size() - (isClosureCall ? op->callClosure.args : op->callFunc.args) - extraArgs - 1;

			if (0 < startArg) {
				printDepth(depth); printf("begin prepare CALL\n");
				for (i = 0; i < startArg; i++) {
					dumpOp(func, scope, op->ops[i], depth + 1);
				}
				printDepth(depth); printf("end prepare CALL\n");
			}

			printDepth(depth); printf("begin CALL\n");
			dumpOp(func, scope, op->ops[startArg + 0], depth + 1);
			if (extraArgs > 0) {
				dumpOp(func, scope, op->ops[startArg + 1], depth + 1);
			}
			for (i = startArg + 1 + extraArgs; i < (int)op->ops.size(); i++) {
				dumpOp(func, scope, op->ops[i], depth + 1);
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

		void dumpOp(Function * func, Scope * scope, Operation * op, int depth)
		{
			if (!op) {
				return;
			}
			int i;
			const char * name;
			switch (op->eop) {
			case OP_SCOPE:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth);
				printf("BEGIN SCOPE\n");
				dumpScope(func, op->scope, depth + 1);
				printDepth(depth);
				printf("END SCOPE\n");
				return;

			case OP_CONST_NULL:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); 
				printf("NULL");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CONST_INT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth);
				printf("%llu ", op->constInt.val);
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CONST_FLOAT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth);
				printf("%lf ", op->constFloat.fval);
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CONST_STRING:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth);
				printf("'%s'", self->constStrings[op->strIndex].c_str());
				// dumpType(op->type);
				printf("\n");
				return;

			case OP_BIN_ADD:
			case OP_BIN_SUB:
			case OP_BIN_MUL:
			case OP_BIN_DIV:
			case OP_BIN_MOD:
			case OP_BIN_POWF:
			case OP_BIN_POWI:
			case OP_CMP_EQ:
			case OP_CMP_NE:
			case OP_CMP_LE:
			case OP_CMP_GE:
			case OP_CMP_LT:
			case OP_CMP_GT:
			case OP_BIT_OR:
			case OP_BIT_AND:
			case OP_BIT_XOR:
			case OP_LOGICAL_OR:
			case OP_LOGICAL_AND:
				YO_ASSERT(op->ops.size() == 2);
				YO_ASSERT(op->type && op->ops[0]->type && op->ops[1]->type);
#ifdef YO_DEBUG
				{
					bool isMutable[2];
					Type * nakedTypes[2] = { self->removeMut(op->ops[0]->type, isMutable[0]), self->removeMut(op->ops[1]->type, isMutable[1]) };
					if (nakedTypes[0] != nakedTypes[1]) {
						int i = 0;
					}
				}
#endif
				printDepth(depth);
				name = getBinOpName(op->eop, op->ops[0]->type->isFloat(), op->ops[0]->type->isSigned());
				// printDepth(depth); printf("begin OP_BIN_OP %s\n", name);
				dumpOp(func, scope, op->ops[0], depth + 1);
				dumpOp(func, scope, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_BIN_OP %s ", name);
				dumpType(op->type);
				printf("\n");
				return;

			case OP_IF:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("IF\n");
				dumpOp(func, scope, op->stmtIf.conditionOp, depth + 1);
				printDepth(depth); printf("THEN\n");
				dumpScope(func, op->stmtIf.thenScope, depth + 1);
				if (op->stmtIf.elseScope) {
					printDepth(depth); printf("ELSE\n");
					dumpScope(func, op->stmtIf.elseScope, depth + 1);
				}
				printDepth(depth); printf("ENDIF\n");
				return;

			case OP_FOR:
				YO_ASSERT(op->ops.size() == 0);
				if (op->stmtFor.conditionOp) {
					printDepth(depth); printf("FOR CONDITION\n");
					dumpOp(func, scope, op->stmtFor.conditionOp, depth + 1);
				}
				else{
					printDepth(depth); printf("FOR\n");
				}
				if (op->stmtFor.stepScope) {
					printDepth(depth); printf("STEP\n");
					dumpScope(func, op->stmtFor.stepScope, depth + 1);
				}
				if (op->stmtFor.bodyScope) {
					printDepth(depth); printf("BODY\n");
					dumpScope(func, op->stmtFor.bodyScope, depth + 1);
				}
				printDepth(depth); printf("ENDFOR\n");
				return;

			case OP_BREAK:
			case OP_CONTINUE:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("%s", op->eop == OP_BREAK ? "BREAK" : "CONTINUE");
				if (op->strIndex >= 0) {
					printf(" LABEL %s\n", self->getConstStr(op->strIndex).c_str());
				}
				else{
					printf("\n");
				}
				return;

			case OP_RETURN:
				if (op->ops.size() > 0) {
					YO_ASSERT(op->ops.size() == 1);
					dumpOp(func, scope, op->ops[0], depth + 1);
					printDepth(depth); printf("OP_RETURN ");
					dumpType(op->type);
					printf("\n");
					return;
				}
				printDepth(depth); printf("OP_RETURN\n");
				return;

			case OP_CALL_CLOSURE:
			case OP_CALL_FUNC:
				dumpCall(func, scope, op, depth);
				return;

			case OP_STACK_VALUE_PTR:
				for (i = 0; i < (int)op->ops.size(); i++) {
					dumpOp(func, scope, op->ops[i], depth + 1);
				}
				printDepth(depth);
				printf("OP_STACK_VALUE_PTR: %s#%d ", op->stackValue->name.c_str(), indexOf(func, op->stackValue));
				dumpType(op->type);
				printf("\n");
				return;

			case OP_STRUCT_ELEMENT_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_STRUCT_ELEMENT_PTR: %d ", op->structElementIndex);
				dumpType(op->type);
				printf("\n");
				return;

			case OP_ELEMENT_PTR: {
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_ELEMENT_PTR\n");
				dumpOp(func, scope, op->ops[0], depth + 1);
				dumpOp(func, scope, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_ELEMENT_PTR ");
				dumpType(op->type);
				printf("\n");
				return;
			}
			case OP_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_PTR ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_FUNC:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("OP_FUNC %s ", op->func->name.c_str());
				dumpType(op->func->funcNativeType);
				printf("\n");
				return;

			case OP_LOAD:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_LOAD ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_STORE_VALUE:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE_VALUE\n");
				dumpOp(func, scope, op->ops[0], depth + 1);
				dumpOp(func, scope, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_STORE_VALUE ");
				if (op->type) dumpType(op->type);
				printf("\n");
				return;

			case OP_STORE_PTR:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE_PTR\n");
				dumpOp(func, scope, op->ops[0], depth + 1);
				dumpOp(func, scope, op->ops[1], depth + 1);
				printDepth(depth); printf("OP_STORE_PTR ");
				if (op->type) dumpType(op->type);
				printf("\n");
				return;

			case OP_STACK_VALUE_MEMZERO:
				printDepth(depth); printf("OP_STACK_VALUE_MEMZERO: %s#%d ", op->stackValue->name.c_str(), indexOf(func, op->stackValue));
				dumpType(op->stackValue->type);
				printf("\n");
				return;

			case OP_VALUE_ZERO:
				printDepth(depth); printf("OP_VALUE_ZERO ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_TRUNC:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_TRUNC ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_ZERO_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_ZERO_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_SIGN_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_SIGN_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_SI_TO_FP:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_SI_TO_FP ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_UI_TO_FP:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_UI_TO_FP ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_TO_SI:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_TO_SI ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_TO_UI:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_TO_UI ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_TRUNC:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_TRUNC ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_FP_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_CAST_PTR ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_SIZEOF:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 1);
				printDepth(depth); printf("OP_SIZEOF ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_TYPE:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("OP_TYPE ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_TYPE_STRUCT_ELEMENT:
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

		void dumpScope(Function * func, Scope * scope, int depth)
		{
			for (int i = 0; i < (int)scope->ops.size(); i++) {
				Operation * op = scope->ops[i];
				dumpOp(func, scope, op, depth);
			}
		}

		void dumpFunc(Function * func)
		{
			printf("begin FUNC %s: %s\n\n", func->name.c_str(), func->funcNativeType->name.c_str());

			int i;
			for (i = 0; i < (int)func->stackValues.size(); i++) {
				StackValue * var = func->stackValues[i];
				// printf("  var %s%s#%d ", var->isMutable ? "mut " : "", var->name.c_str(), i);
				printf("  var %s#%d ", var->name.c_str(), i);
				dumpType(var->type);
				printf("\n");
			}
			if (i > 0) {
				printf("\n");
			}
			dumpScope(func, func, 1);
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

		void dumpType(Type * type, bool full = false)
		{
			if (!type) {
				printf("<<<NULL>>>");
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
				if (!full) {
					printf("%s", type->name.c_str());
					break;
				}
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
				printf("%s", type->name.c_str());
				/* FuncNativeType * funcType = (FuncNativeType*)type;
				printf("func(");
				for (int i = 0; i < (int)funcType->args.size(); i++) {
					if (i > 0) {
						printf(",");
					}
					FuncNativeType::Arg& arg = funcType->args[i];
					dumpType(arg.type);
				}
				printf(")");
				dumpType(funcType->resType); */
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

			case TYPE_REF:
				YO_ASSERT(dynamic_cast<SubType*>(type));
				printf("&");
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
				dumpType(type, true);
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
	case 1: return getType(TYPE_BOOL);
	case 8: return getType(isSigned ? TYPE_INT8 : TYPE_UINT8);
	case 16: return getType(isSigned ? TYPE_INT16 : TYPE_UINT16);
	case 32: return getType(isSigned ? TYPE_INT32 : TYPE_UINT32);
	case 64: return getType(isSigned ? TYPE_INT64 : TYPE_UINT64);
	}
	setError(ERROR_UNREACHABLE, NULL, "Error int type bits: %d", bits);
	return NULL;
}

YoProgCompiler::Type * YoProgCompiler::getIntType(bool isSigned)
{
	const int bits = sizeof(int) * 8;
	return getIntType(bits < 32 ? 32 : bits, isSigned);
}

YoProgCompiler::Type * YoProgCompiler::getIntPtrType(bool isSigned)
{
	return getIntType(sizeof(intptr_t) * 8, isSigned);
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
	// case TYPE_INT: return getIntType(sizeof(int) * 8, true);
	// case TYPE_UINT: return getIntType(sizeof(int) * 8, false);
	// case TYPE_INTPTR: return getIntType(sizeof(intptr_t) * 8, true);
	// case TYPE_UINTPTR: return getIntType(sizeof(intptr_t) * 8, false);
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
	case T_INT: return getIntType(true);
	case T_INTPTR: return getIntPtrType(true);
	case T_UINT8: return getType(TYPE_UINT8);
	case T_UINT16: return getType(TYPE_UINT16);
	case T_UINT32: return getType(TYPE_UINT32);
	case T_UINT64: return getType(TYPE_UINT64);
	case T_UINT: return getIntType(false);
	case T_UINTPTR: return getIntPtrType(false);
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

std::string YoProgCompiler::getFuncNativeTypeName(FuncNativeType * funcType)
{
	std::ostringstream buf;
	if (funcType->isExtern) {
		buf << "extern ";
	}
	switch (funcType->conv) {
	case YO_CALLING_C:
		buf << "\"C\" ";
		break;

	case YO_CALLING_STDCALL:
		buf << "\"stdcall\" ";
		break;

	case YO_CALLING_DEFAULT:
		break;

	default:
		setError(ERROR_UNREACHABLE, funcType->parserNode, "Error calling conv: %d", (int)funcType->conv);
		return "<<<error>>>";
	}

	buf << "func(";
	for (int i = 0; i < (int)funcType->args.size(); i++) {
		if (i > 0) {
			buf << ",";
		}
		buf << funcType->args[i].type->name;
	}
	if (funcType->isVarArg) {
		YO_ASSERT(funcType->isExtern);
		buf << ",...";
	}
	buf << ")" << funcType->resType->name;
	return buf.str();
}

void YoProgCompiler::updateFuncNativeType(FuncNativeType * funcType)
{
	std::map<std::string, Type*>::iterator it = globalTypes.find(funcType->name);
	if (it != globalTypes.end()) {
		globalTypes.erase(it);
	}
	funcType->name = getFuncNativeTypeName(funcType);
	globalTypes[funcType->name] = funcType;
}

YoProgCompiler::FuncNativeType * YoProgCompiler::getFuncNativeType(std::vector<std::string>& argNames, Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && (node->type == YO_NODE_DECL_FUNC || node->type == YO_NODE_TYPE_FUNC));
	FuncNativeType * funcType = new FuncNativeType("", node);
	funcType->isExtern = node->data.func.op == T_EXTERN_FUNC;
	funcType->isVarArg = node->data.func.isVarArg;
	funcType->conv = node->data.func.conv;

	if (node->data.func.self) {

	}

	if (!funcType->isExtern) {
		std::vector<Type*> emptyTypes;
		Type * closureAddr = getPtrType(getStructType(emptyTypes, node), node);
		// funcType->args.push_back(FuncNativeType::Arg(closureAddr, false));
		funcType->args.push_back(FuncNativeType::Arg(closureAddr));

		argNames.clear();
		argNames.push_back("#closureAddr");
	}

	std::vector<YoParserNode*> argNodes;
	collectNodesInReversList(argNodes, node->data.func.args);

	std::vector<YoParserNode*>::reverse_iterator nait = argNodes.rbegin();
	for (; nait != argNodes.rend(); ++nait) {
		YoParserNode * argNode = *nait;
		YO_ASSERT(argNode->type == YO_NODE_DECL_ARG);

		std::vector<YoParserNode*> nameArgs;
		collectNodesInReversList(nameArgs, argNode->data.declVar.name);

		Type * argType = getParserType(scope, argNode->data.declVar.type);
		bool isMutable = argNode->data.declVar.isMutable;
		if (isMutable) {
			argType = getMutType(argType, argNode->data.declVar.type);
		}
		if (!argType) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (argType->etype == TYPE_VOID) {
			setError(ERROR_TYPE, argNode->data.declVar.type, "Arg should not be void");
			return NULL;
		}
		for (int i = (int)nameArgs.size()-1; i >= 0; i--) {
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
			// funcType->args.push_back(FuncNativeType::Arg(argType, isMutable));
			funcType->args.push_back(FuncNativeType::Arg(argType));
			argNames.push_back(argName);
		}
	}
	if (node->data.func.type) {
		funcType->resType = getParserType(scope, node->data.func.type);
	}
	else if(node->data.func.op == T_LAMBDA){
		funcType->resType = getType(TYPE_UNKNOWN_YET);
	}
	else{
		funcType->resType = getType(TYPE_VOID);
	}
	funcType->name = getFuncNativeTypeName(funcType);
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
	// YO_ASSERT(node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->mutType) {
		return type->mutType;
	}
	ArrayType * arrType;
	switch (type->etype) {
#if 1
	case TYPE_REF:
		return getRefType(getMutType(getRefSubType(type, node), node), node);

	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(type));
		arrType = (ArrayType*)type;
		return getArrayType(arrType->size, getMutType(arrType->subType, node), node);
#endif

	case TYPE_MUT:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't mutable, type %s is already mutable", ((SubType*)type)->subType->name.c_str());
		return NULL;
	
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't mutable, type %s is already constant", ((SubType*)type)->subType->name.c_str());
		return NULL;

	case TYPE_VOID:
		setError(ERROR_TYPE, node, "Can't mutable void");
		return NULL;
	}
	std::string name = "mut " + type->name;
	type->mutType = new SubType(name, TYPE_MUT, type, node ? node : type->parserNode);
	type->mutType->isUnknownYet = type->isUnknownYet;
	return type->mutType;
}

bool YoProgCompiler::isMutable(Type * type)
{
	if (!type) {
		YO_ASSERT(isError());
		return false;
	}
	ArrayType * arrType;
	switch (type->etype) {
#if 1
	case TYPE_REF:
		return isMutable(getRefSubType(type));

	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(type));
		arrType = (ArrayType*)type;
		return isMutable(arrType->subType);
#endif

	case TYPE_MUT:
		return true;

	case TYPE_CONST:
		return false;
	}
	return false;
}

YoProgCompiler::Type * YoProgCompiler::getConstType(Type * type, YoParserNode * node)
{
	// YO_ASSERT(node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->constType) {
		return type->constType;
	}
	ArrayType * arrType;
	switch (type->etype) {
#if 1
	case TYPE_REF:
		return getRefType(getConstType(getRefSubType(type, node), node), node);

	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(type));
		arrType = (ArrayType*)type;
		return getArrayType(arrType->size, getConstType(arrType->subType, node), node);
#endif

	case TYPE_MUT:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't constant, type %s is already mutable", ((SubType*)type)->subType->name.c_str());
		return NULL;

	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't constant, type %s is already constant", ((SubType*)type)->subType->name.c_str());
		return NULL;

	case TYPE_VOID:
		setError(ERROR_TYPE, node, "Can't constant void");
		return NULL;
	}
	std::string name = "const " + type->name;
	type->constType = new SubType(name, TYPE_CONST, type, node ? node : type->parserNode);
	type->constType->isUnknownYet = type->isUnknownYet;
	return type->constType;
}

YoProgCompiler::Type * YoProgCompiler::getPtrType(Type * type, YoParserNode * node)
{
	// YO_ASSERT(node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->ptrType) {
		return type->ptrType;
	}
	std::string name = "*" + type->name;
	type->ptrType = new SubType(name, TYPE_PTR, type, node ? node : type->parserNode);
	type->ptrType->isUnknownYet = type->isUnknownYet;
	return type->ptrType;
}

YoProgCompiler::Type * YoProgCompiler::getRefType(Type * type, YoParserNode * node)
{
	// YO_ASSERT(node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->refType) {
		return type->refType;
	}
	switch (type->etype) {
	case TYPE_REF:
		YO_ASSERT(dynamic_cast<SubType*>(type));
		setError(ERROR_TYPE, node, "Can't reference, type %s is already reference", ((SubType*)type)->subType->name.c_str());
		return NULL;
	}
	std::string name = "&" + type->name;
	type->refType = new SubType(name, TYPE_REF, type, node ? node : type->parserNode);
	type->refType->isUnknownYet = type->isUnknownYet;
	return type->refType;
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

	case YO_NODE_TYPE_REF:
		return getRefType(getParserType(scope, node->data.typeRef.type), node);

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
	YO_ASSERT(node->data.func.op == T_FUNC && scope->escope == SCOPE_MODULE 
		|| node->data.func.op == T_EXTERN_FUNC && scope->escope == SCOPE_MODULE
		|| node->data.func.op == T_SUB_FUNC && scope->escope != SCOPE_MODULE
		|| node->data.func.op == T_LAMBDA && scope->escope != SCOPE_MODULE);
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

	if (funcNativeType->isExtern) {
		if (node->data.func.body) {
			setError(ERROR_UNREACHABLE, node, "Extern function %s should not have body", name.c_str());
			return NULL;
		}
#if 1
		std::map<std::string, void*>::iterator it = symbols.find(name);
		if (it == symbols.end() || !it->second) {
			// setError(ERROR_LINK_EXTERN_FUNC, node, "Error to link extern function %s", name.c_str());
			// return NULL;
		}
		else{
			func->externFunc = it->second;
		}
#endif
		return func;
	}

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
		// stackValue->isMutable = arg.isMutable;
		func->stackValues.push_back(stackValue);
	}
	
	if (!compileFuncBody(func, node)) {
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

bool YoProgCompiler::compileFuncBody(Function * func, YoParserNode * funcNode)
{
	YO_ASSERT(funcNode->type == YO_NODE_DECL_FUNC);
	if (compileScopeBody(func, funcNode->data.func.body)) {
		if (func->ops.size() == 0 || func->ops.back()->eop != OP_RETURN) {
			Operation * op;
			switch (func->funcNativeType->resType->etype) {
			case TYPE_UNKNOWN_YET:
				func->funcNativeType->resType = getType(TYPE_VOID);
				updateFuncNativeType(func->funcNativeType);
				// setError(ERROR_TYPE, funcNode, "Unknown return type");
				// return false;
				// no break

			case TYPE_VOID:
				op = newOperation(OP_RETURN, funcNode);
				op->type = getType(TYPE_VOID);
				func->ops.push_back(op);
				break;

			default:
				setError(ERROR_RETURN_REQUIRED, funcNode->data.func.end, "Return stmt required");
				return false;
			}
		}
		return optimizeScopePass1(func);
	}
	return false;
}

bool YoProgCompiler::compileScopeBody(Scope * scope, YoParserNode * node)
{
	if (node) {
		std::vector<YoParserNode*> list;
		collectNodesInReversList(list, node);

		YoParserNode * retStmt = NULL;
		std::vector<YoParserNode*>::reverse_iterator it = list.rbegin();
		for (; it != list.rend(); ++it){
			YoParserNode * stmt = *it;
			if (retStmt) {
				setError(ERROR_RETURN_IN_MIDDLE, retStmt, "Return statement should be the last in block");
				return false;
			}
			switch (stmt->type) {
			case YO_NODE_DECL_VAR:
				if (!compileDeclVar(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_DECL_TYPE:
				if (!compileDeclType(scope, stmt)) {
					return false;
				}
				break;
			
			case YO_NODE_ASSIGN:
				if (!compileStmtAssign(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_BIN_OP:
				if (!compileStmtBinOp(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_UNARY_OP:
				if (!compileStmtUnaryOp(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_POST_UNARY_OP:
				if (!compileStmtPostUnaryOp(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_CALL:
				if (!compileStmtCall(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_IF:
				if (!compileStmtIf(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_FOR:
				if (!compileStmtFor(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_BREAK:
				if (!compileStmtBreak(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_RETURN:
				if (!compileStmtReturn(scope, stmt)) {
					return false;
				}
				retStmt = stmt;
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
	}
	else{
		type = getType(TYPE_UNKNOWN_YET);
	}
	if (node->data.declVar.isMutable) {
		type = getMutType(type, node);
	}
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
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
	// stackValue->isMutable = node->data.declVar.isMutable;
	scope->stackValues.push_back(stackValue);
	if (scope->escope == SCOPE_BLOCK) {
		getFunction(scope)->stackValues.push_back(stackValue);
	}
	return stackValue;
}

bool YoProgCompiler::findName(NameInfo& out, Scope * scope, const std::string& name)
{
	YO_ASSERT(scope);
	for (int upCount = 0; scope;) {
		if (scope->escope == SCOPE_MODULE) {
			break;
		}
		// YO_ASSERT(scope->escope == SCOPE_FUNCTION);
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
		if (scope->escope == SCOPE_FUNCTION) {
			upCount++;
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
	return getValue(scope, compileOp(scope, node), node);
}

std::string YoProgCompiler::getConstStr(int i)
{
	return constStrings[i];
}

int YoProgCompiler::addConstStr(const std::string& str)
{
	int strIndex;
	std::map<std::string, int>::iterator it = constStringsMap.find(str);
	if (it == constStringsMap.end()) {
		constStringsMap[str] = strIndex = constStrings.size();
		constStrings.push_back(str);
	}
	else{
		strIndex = it->second;
	}
	return strIndex;
}

YoProgCompiler::Operation * YoProgCompiler::compileQuotedString(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_QUOTED_STRING);

	const char * s = node->token.str + 1;
	const char * end = s + (node->token.len - 2);
	std::ostringstream buf;
	for (; s < end;) {
		if (*s == '\\') {
			YO_BYTE c;
			const char * hexEnd;
			switch (s[1]) {
			case 'r': buf << '\r'; break;
			case 'n': buf << '\n'; break;
			case 't': buf << '\t'; break;
			case 'v': buf << '\v'; break;
			case 'b': buf << '\b'; break;
			case 'f': buf << '\f'; break;
			case '\"': buf << '\"'; break;
			case '\\': buf << '\\'; break;
			default: buf << s[1]; break;
			case 'x':
				if (s + 2 < end) {
					s += 2;
					hexEnd = s + 2 > end ? end : s + 2;
					if (yoParseInt(s, hexEnd, 16, c)) {
						buf << c;
						s = hexEnd;
						continue;
					}
				}
				setError(ERROR_ESCAPE_CHAR, node, "Error hex char");
				return NULL;
			}
			s += 2;
		}
		else{
			buf << *s++;
		}
	}
	Operation * op = newOperation(OP_CONST_STRING, node);
	op->strIndex = addConstStr(buf.str());
	op->type = getPtrType(getType(TYPE_UINT8));
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compileSingleQuotedString(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_SINGLE_QUOTED_STRING);

	const char * s = node->token.str + 1;
	const char * end = s + (node->token.len - 2);
	std::ostringstream buf;
	for (; s < end;) {
		if (*s == '\\') {
			const char * hexEnd;
			switch (s[1]) {
			case '\'': buf << '\''; break;
			case '\\': buf << '\\'; break;
			default: buf << s[1]; break;
			}
			s += 2;
		}
		else{
			buf << *s++;
		}
	}
	Operation * op = newOperation(OP_CONST_STRING, node);
	op->strIndex = addConstStr(buf.str());
	op->type = getPtrType(getType(TYPE_UINT8));
	return op;
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

	case YO_NODE_QUOTED_STRING:
		return compileQuotedString(scope, node);

	case YO_NODE_SINGLE_QUOTED_STRING:
		return compileSingleQuotedString(scope, node);

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

	case YO_NODE_UNARY_OP:
		return compileUnaryOp(scope, node);

	case YO_NODE_POST_UNARY_OP:
		return compilePostUnaryOp(scope, node);

	case YO_NODE_DECL_FUNC:
		return compileSubFunc(scope, node);

	case YO_NODE_DOTNAME:
		return compileDotName(scope, node);

	case YO_NODE_SIZEOF:
		return compileSizeOf(scope, node);

	case YO_NODE_CALL:
		return compileCall(scope, node);

	case YO_NODE_CAST:
		return convertOpToType(scope, compileOp(scope, node->data.cast.expr), getParserType(scope, node->data.cast.type), CONVERT_BY_HAND, node);
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
	scope->ops.push_back(op);
	return true;
}

YoProgCompiler::Function * YoProgCompiler::getFunction(Scope * scope)
{
	if (!(scope && scope->escope != SCOPE_MODULE)) {
		int i = 0;
	}
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
	bool isMutable = false;
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
		leftValueType = removeMut(left->type, isMutable);
		if (leftValueType->etype != TYPE_STRUCT && leftValueType->etype != TYPE_CLASS) {
			setError(ERROR_TYPE, node, "Struct or class type required: %s", leftValueType->name.c_str());
			return NULL;
		}
		StackValue * val = allocTempValue(scope, addMut(leftValueType, isMutable), "#temp", node);
		Operation * stackValueOp = newStackValuePtrOp(val, node);
		
		Operation * storeOp = newOperation(OP_STORE_VALUE, node);
		storeOp->ops.push_back(left);
		storeOp->ops.push_back(stackValueOp);
		storeOp->type = stackValueOp->type;

		stackValueOp->ops.push_back(storeOp);
		left = stackValueOp;
	}
	else{
		bool isMutable = false;
		leftValueType = removeMut(getValueType(left), isMutable);
		if (leftValueType->etype == TYPE_PTR || leftValueType->etype == TYPE_REF) {
			Operation * loadOp = newOperation(OP_LOAD, node);
			loadOp->ops.push_back(left);
			// loadOp->type = addMut(leftValueType, isMutable);
			loadOp->type = leftValueType;
			leftValueType = removeMut(getPtrOrRefSubType(leftValueType), isMutable);
			left = loadOp;
		}
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
		if (nameOp->stackValue->type->etype != TYPE_FUNC_DATA || !dynamic_cast<FuncDataType*>(nameOp->stackValue->type)){
			setError(ERROR_TYPE, nameOp->stackValue->parserNode, "Func type required, found: %s", nameOp->stackValue->type->name.c_str());
			return NULL;
		}
		Operation * funcElemPtrPtr = newStructElementPtrOp(nameOp, 0, node);
		if (!funcElemPtrPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * funcElemPtr = getValue(scope, funcElemPtrPtr, node);

		Operation * closureElemPtrPtr = newStructElementPtrOp(nameOp, 1, node);
		if (!closureElemPtrPtr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * closureElemPtr = getValue(scope, closureElemPtrPtr, node);

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
			argOp = convertOpToType(scope, argOp, funcDataType->funcNativeType->args[i + 1].type, CONVERT_AUTO, node);
			if (!argOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->ops.push_back(argOp);
		}
		return op;
	}
	if (nameOp->eop == OP_FUNC) {
		Operation * op = newOperation(OP_CALL_FUNC, node);
		op->callFunc.func = nameOp->func;
		op->type = nameOp->func->funcNativeType->resType;
		// op->ops.push_back(newOperation(OP_NOP, node));
		op->ops.push_back(nameOp);

		int extraArgs = 1;
		if (!nameOp->func->funcNativeType->isExtern) {
			Operation * nullOp = newOperation(OP_CONST_NULL, node);
			nullOp->type = getVoidPtrType();
			nullOp = convertPtrToType(scope, nullOp, nameOp->func->funcNativeType->args[0].type, node);
			if (!nullOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->ops.push_back(nullOp);
		}
		else{
			extraArgs = 0;
		}
		op->callFunc.extraArgs = extraArgs;

		std::vector<YoParserNode*> argNodes;
		collectNodesInReversList(argNodes, node->data.call.args);
		op->callFunc.args = argNodes.size();

		int minArgsNumber = nameOp->func->funcNativeType->args.size() - extraArgs;
		if (op->callFunc.args < minArgsNumber || (!nameOp->func->funcNativeType->isVarArg && op->callFunc.args != minArgsNumber)) {
			setError(ERROR_CALL_ARGS_NUMBER, node, "Error call args number %d, required %d", op->callClosure.args, nameOp->func->funcNativeType->args.size() - extraArgs);
			return NULL;
		}
		if (nameOp->func->funcNativeType->isVarArg) {
			if (nameOp->func->funcNativeType->isExtern) {
				// it's OK already
			}
			else{
				if (op->callFunc.args > minArgsNumber) {
					setError(ERROR_UNREACHABLE, node, "Var args is not supported yet, args number %d, required %d", op->callClosure.args, nameOp->func->funcNativeType->args.size() - extraArgs);
					return NULL;
				}
			}
		}

		bool isExtern = nameOp->func->funcNativeType->isExtern;
		for (int i = 0; i < (int)argNodes.size(); i++) {
			// in reverse order
			Operation * argOp = compileOp(scope, argNodes[argNodes.size() - 1 - i]);
			Type * destType = NULL;
			if (i + extraArgs < (int)nameOp->func->funcNativeType->args.size()) {
				destType = nameOp->func->funcNativeType->args[i + extraArgs].type;
			}
			argOp = convertArgToType(scope, argOp, destType, isExtern, node);
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
	// temp->isMutable = true;
	temp->isTemp = true;
	return temp;
}

void YoProgCompiler::addSymbol(const std::string& name, void * addr)
{
	symbols[name] = addr;
}

YoProgCompiler::Operation * YoProgCompiler::newOperation(EOperation eop, YoParserNode * node)
{
	Operation * op = new Operation(eop, node);
	ops.push_back(op);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newOperation(EOperation eop, Operation * sub, Type * type, YoParserNode * node)
{
	Operation * op = newOperation(eop, node);
	op->type = type;
	op->ops.push_back(sub);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstIntOp(Scope * scope, YO_U64 val, int bits, bool isSigned, YoParserNode * node)
{
	Operation * op = newOperation(OP_CONST_INT, node);
	op->constInt.bits = bits;
	op->constInt.isSigned = isSigned;
	op->constInt.val = val;
	op->type = getIntType(bits, isSigned);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstIntOp(Scope * scope, YO_U64 val, YoParserNode * node)
{
	return newConstIntOp(scope, val, sizeof(val) * 8, false, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstIntOp(Scope * scope, YO_U64 val, Type * type, YoParserNode * node)
{
	Operation * op = newConstIntOp(scope, val, node);
	return convertOpToType(scope, op, type, CONVERT_AUTO, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstFloatOp(Scope * scope, double val, int bits, YoParserNode * node)
{
	Operation * op = newOperation(OP_CONST_FLOAT, node);
	op->constFloat.fval = val;
	op->type = getFloatType(bits);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstFloatOp(Scope * scope, double val, YoParserNode * node)
{
	return newConstFloatOp(scope, val, sizeof(val) * 8, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstFloatOp(Scope * scope, double val, Type * type, YoParserNode * node)
{
	Operation * op = newConstFloatOp(scope, val, node);
	return convertOpToType(scope, op, type, CONVERT_AUTO, node);
}

YoProgCompiler::Operation * YoProgCompiler::newStackValuePtrOp(StackValue * value, YoParserNode * node)
{
	YO_ASSERT(value && value->type);
	Operation * op = newOperation(OP_STACK_VALUE_PTR, node);
	op->stackValue = value;
	op->type = getPtrType(value->type);
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

YoProgCompiler::Type * YoProgCompiler::getRefSubType(Type * refType, YoParserNode * node)
{
	if (!refType || refType->etype != TYPE_REF || !dynamic_cast<SubType*>(refType) || !((SubType*)refType)->subType) {
		setError(ERROR_UNREACHABLE, node ? node : refType->parserNode, "Pointer type required");
		return NULL;
	}
	return ((SubType*)refType)->subType;
}

YoProgCompiler::Type * YoProgCompiler::getPtrOrRefSubType(Type * type, YoParserNode * node)
{
	if (!type || (type->etype != TYPE_PTR && type->etype != TYPE_REF) || !dynamic_cast<SubType*>(type) || !((SubType*)type)->subType) {
		setError(ERROR_UNREACHABLE, node ? node : type->parserNode, "Pointer or reference type required");
		return NULL;
	}
	return ((SubType*)type)->subType;
}

YoProgCompiler::Type * YoProgCompiler::getRefFromPtrType(Type * type, YoParserNode * node)
{
	type = getPtrSubType(type, node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	return getRefType(type, node);
}

YoProgCompiler::Type * YoProgCompiler::getPtrFromRefType(Type * type, YoParserNode * node)
{
	type = getRefSubType(type, node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	return getPtrType(type, node);
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
	bool isMutable;
	Type * type = removeMut(getPtrOrRefSubType(ptrOp->type, node), isMutable);
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
	elemPtr->type = getPtrType(addMut(structType->types[index], isMutable), node);
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

	StackValue * temp = allocTempValue(scope, type, "#temp", node);
	Operation * resultOp = newStackValuePtrOp(temp, node), * op;

	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.obj.values);

#if 1
	if (nodes.size() != structType->names.size()) {
		Operation * initZeroOp = newOperation(OP_STORE_VALUE, node);
		Operation * zeroValue = newOperation(OP_VALUE_ZERO, node);
		zeroValue->type = temp->type;
		initZeroOp->ops.push_back(zeroValue);
		initZeroOp->ops.push_back(newStackValuePtrOp(temp, node));
		initZeroOp->type = initZeroOp->ops[1]->type;
		resultOp->ops.push_back(initZeroOp);
	}
	else{
		int i = 0;
	}
#else
	Operation * op = newOperation(OP_STACK_VALUE_MEMZERO, node);
	op->stackValue = temp;
	resultOp->ops.push_back(op);
#endif

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
			// expr = getValue(scope, expr);
			expr = convertOpToType(scope, expr, dstType, CONVERT_AUTO, node);
			if (!expr) {
				return NULL;
			}
			op = newOperation(isValueOp(expr) ? OP_STORE_VALUE : OP_STORE_PTR, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
			op->type = dst->type;
		}
		else{
			if (expr->eop == OP_STACK_VALUE_PTR && expr->stackValue->isTemp) {
				YO_ASSERT(!expr->stackValue->initStackValue);
				expr->stackValue->initStackValue = temp;
				expr->stackValue->initStructElementIndex = i;
			}
			op = newOperation(isValueOp(expr) ? OP_STORE_VALUE : OP_STORE_PTR, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
			op->type = dst->type;
		}
		resultOp->ops.push_back(op);
	}
	return resultOp;
}

bool YoProgCompiler::optimizeScopePass1(Scope * scope)
{
	if (!scope) {
		return true;
	}
	for (int i = 0; i < (int)scope->ops.size(); i++) {
		Operation * subOp = optimizeOpPass1(scope, scope->ops[i]);
		if (!subOp) {
			YO_ASSERT(isError());
			return false;
		}
		scope->ops[i] = subOp;
	}
	return true;
}

YoProgCompiler::Operation * YoProgCompiler::optimizeOpPass1(Scope * scope, Operation * op)
{
	YO_ASSERT(op);

	int i;
	Operation * subOp;
	for (i = 0; i < (int)op->ops.size(); i++) {
		subOp = optimizeOpPass1(scope, op->ops[i]);
		if (!subOp) {
			YO_ASSERT(isError());
			return NULL;
		}
		op->ops[i] = subOp;
	}

	switch (op->eop) {
	case OP_IF:
		subOp = optimizeOpPass1(scope, op->stmtIf.conditionOp);
		if (!subOp) {
			YO_ASSERT(isError());
			return NULL;
		}
		op->stmtIf.conditionOp = subOp;
		if (!optimizeScopePass1(op->stmtIf.thenScope) || !optimizeScopePass1(op->stmtIf.elseScope)) {
			YO_ASSERT(isError());
			return NULL;
		}
		break;

	case OP_STORE_VALUE:
		YO_ASSERT(op->ops.size() == 2);
		if (!isValueOp(op->ops[0])) {
			int i = 0;
		}
		if (op->ops[0]->eop == YoProgCompiler::OP_VALUE_ZERO) {
			if (op->ops[1]->eop == YoProgCompiler::OP_STACK_VALUE_PTR) {
				YoProgCompiler::StackValue * stackValue = op->ops[1]->stackValue;
				if (stackValue->initStackValue && stackValue->initStructElementIndex >= 0) {
					return op->ops[1];
				}
			}
		}
		break;
	}
	return op;
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

	StackValue * temp = allocTempValue(scope, type, "#temp", node);
	Operation * resultOp = newStackValuePtrOp(temp, node), * op;

#if 1
	// TODO: check if all fields are initialized so ZERO couldn't be needed
	Operation * initZeroOp = newOperation(OP_STORE_VALUE, node);
	Operation * zeroValue = newOperation(OP_VALUE_ZERO, node);
	zeroValue->type = temp->type;
	initZeroOp->ops.push_back(zeroValue);
	initZeroOp->ops.push_back(newStackValuePtrOp(temp, node));
	initZeroOp->type = initZeroOp->ops[1]->type;
	resultOp->ops.push_back(initZeroOp);
#else
	Operation * op = newOperation(OP_STACK_VALUE_MEMZERO, node);
	op->stackValue = temp;
	resultOp->ops.push_back(op);
#endif

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
			// expr = getValue(scope, expr);
			expr = convertOpToType(scope, expr, dstType, CONVERT_AUTO, node);
			if (!expr) {
				return NULL;
			}
			op = newOperation(OP_STORE_VALUE, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
			op->type = dst->type;
		}
		else{
			if (expr->eop == OP_STACK_VALUE_PTR && expr->stackValue->isTemp) {
				YO_ASSERT(!expr->stackValue->initStackValue);
				expr->stackValue->initStackValue = temp;
				expr->stackValue->initStructElementIndex = i;
			}
			op = newOperation(isValueOp(expr) ? OP_STORE_VALUE : OP_STORE_PTR, node);
			op->ops.push_back(expr);
			op->ops.push_back(dst);
			op->type = dst->type;
		}
		resultOp->ops.push_back(op);
	}
	return resultOp;
}

YoProgCompiler::Operation * YoProgCompiler::newSpecAssignOp(Scope * scope, ESpecAssignRet spec, Operation * op, Operation * value, EOperation bin, YoParserNode * node)
{
	if (!op || !value) {
		YO_ASSERT(isError());
		return NULL;
	}
	Type * valueType;
	StackValue * tempPP, * tempV = NULL;
	Operation *binOp, *assignOp, *initTempOp, *resultOp, *saveOp;
	switch (op->eop) {
	case OP_STACK_VALUE_PTR:
		if (!op->stackValue->isInitialized) {
			setError(ERROR_VAR_NOT_INITIALIZED, op->stackValue->parserNode, "Variable %s is not initialized", op->stackValue->name.c_str());
			return NULL;
		}
		if (!isMutable(op->stackValue->type)) {
			setError(ERROR_MUTABLE_REQUIRED, node, "Variable %s is not mutable", op->stackValue->name.c_str());
			return NULL;
		}
		if (op->type->isUnknownYet) {
			setError(ERROR_TYPE, op->stackValue->parserNode, "Variable %s has unknown type", op->stackValue->name.c_str());
			return NULL;
		}
		// no break

	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
	case OP_STORE_VALUE:
	case OP_STORE_PTR:
		valueType = getPtrSubType(op->type);
		if (!valueType) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (!isMutable(valueType)) {
			setError(ERROR_MUTABLE_REQUIRED, op->parserNode, "Mutable value required, found %s", getRefFromPtrType(op->type)->name.c_str());
			return NULL;
		}
		tempPP = allocTempValue(scope, op->type, "#temp", node);
		initTempOp = newOperation(OP_STORE_VALUE, node);
		initTempOp->ops.push_back(op);	// src
		initTempOp->ops.push_back(newStackValuePtrOp(tempPP, node));	// dst
		initTempOp->type = initTempOp->ops[1]->type;
		
		tempV = allocTempValue(scope, valueType, "#temp", node);
		saveOp = newOperation(OP_STORE_VALUE, node);
		saveOp->ops.push_back(loadValue(scope, loadValue(scope, newStackValuePtrOp(tempPP, node), node), node));	// src
		saveOp->ops.push_back(newStackValuePtrOp(tempV, node));	// dst
		saveOp->type = saveOp->ops[1]->type;

		value = convertOpToType(scope, value, valueType, CONVERT_AUTO, node);
		if (!value) {
			YO_ASSERT(isError());
			return NULL;
		}
		binOp = newOperation(bin, node);
		// binOp->ops.push_back(loadValue(scope, loadValue(scope, newStackValuePtrOp(tempPP, node), node), node));
		binOp->ops.push_back(loadValue(scope, newStackValuePtrOp(tempV, node), node));
		binOp->ops.push_back(value);
		binOp->type = valueType;

		assignOp = newOperation(OP_STORE_VALUE, node);
		assignOp->ops.push_back(binOp);	// src
		assignOp->ops.push_back(loadValue(scope, newStackValuePtrOp(tempPP, node), node));	// dst
		assignOp->type = assignOp->ops[1]->type;

		if (spec == SPEC_POST) {
			resultOp = newStackValuePtrOp(tempV, node);
			resultOp->ops.push_back(initTempOp);
			resultOp->ops.push_back(saveOp);
			resultOp->ops.push_back(assignOp);
			return loadValue(scope, resultOp, node);
		}
		resultOp = newStackValuePtrOp(tempPP, node);
		resultOp->ops.push_back(initTempOp);
		resultOp->ops.push_back(saveOp);
		resultOp->ops.push_back(assignOp);
		return loadValue(scope, loadValue(scope, resultOp, node), node);
	}
	setError(ERROR_OP, op->parserNode, "Lvalue required");
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileAssign(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_ASSIGN); // && node->data.assign.op == T_ASSIGN);

	YO_ASSERT(node->data.assign.left && node->data.assign.right);
	Operation * left = compileOp(scope, node->data.assign.left);
	Operation * right = compileOp(scope, node->data.assign.right);
	if (!left || !right) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * op;
	Type * leftValueType, * rightValueType;
	bool allowRightAutoMutable = false;
	bool isInitialized = false;
	switch (left->eop) {
	case OP_PTR:
		YO_ASSERT(left->ops.size() == 1);
		left = left->ops[0];
		YO_ASSERT(!isValueOp(left));
		goto ptr;

	case OP_STACK_VALUE_PTR:
		if (node->data.assign.op == T_INIT_ASSIGN) {
			left->stackValue->isInitialized = isInitialized = true;
			left->stackValue->isUsed = false;
		}
		// else if (!left->stackValue->isMutable) {
		else if (!isMutable(left->stackValue->type)) {
			setError(ERROR_MUTABLE_REQUIRED, node, "Variable %s is not mutable", left->stackValue->name.c_str());
			return NULL;
		}
		else{
			left->stackValue->isChanged = true;
		}
		YO_ASSERT(left->type && left->stackValue && left->stackValue->type && right->type);
		if (right->eop == OP_FUNC && left->stackValue->type->etype == TYPE_UNKNOWN_YET) {
			FuncDataType * funcDataType = getFuncDataType(right->func->funcNativeType);
			right = convertOpToType(scope, right, funcDataType, CONVERT_AUTO, node);
		}
		if (matchTypeTemplate(scope, left->stackValue->type, getValueType(right), node->data.assign.op == T_INIT_ASSIGN)) {
			if (left->stackValue->type->etype == TYPE_VOID) {
				setError(ERROR_TYPE, left->stackValue->parserNode, "Variable %s should not be void", left->stackValue->name.c_str());
				return NULL;
			}
			left->type = getPtrType(left->stackValue->type);
			if (node->data.assign.op == T_INIT_ASSIGN) {
				if (isMutable(left->stackValue->type)) {
					allowRightAutoMutable = true;
				}
			}
		}
		if (left->type->isUnknownYet) {
			setError(ERROR_TYPE, left->stackValue->parserNode, "Variable %s has unknown type", left->stackValue->name.c_str());
			return NULL;
		}
		// no break

ptr:
	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
	case OP_STORE_VALUE:
	case OP_STORE_PTR:
		YO_ASSERT(node->data.assign.op == T_ASSIGN || node->data.assign.op == T_INIT_ASSIGN && left->eop == OP_STACK_VALUE_PTR);
		leftValueType = getPtrSubType(left->type);
		if (!leftValueType) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (!isInitialized && !isMutable(leftValueType)) {
			setError(ERROR_MUTABLE_REQUIRED, left->parserNode, "Mutable value required, found %s", getRefFromPtrType(left->type)->name.c_str());
			return NULL;
		}
		if (leftValueType->etype == TYPE_REF) {
			bool isMutable;
			left = loadValue(scope, left, node);
			leftValueType = removeMut(getRefSubType(left->type), isMutable);
		}
		rightValueType = getValueType(right);
		if (allowRightAutoMutable && !isMutable(rightValueType)) {
			rightValueType = getMutType(rightValueType, node);
		}
		if (rightValueType != leftValueType){
			right = convertOpToType(scope, right, leftValueType, CONVERT_AUTO, node);
			if (!right) {
				YO_ASSERT(isError());
				return NULL;
			}
			// YO_ASSERT(isValueOp(right));
			/* op = newOperation(OP_STORE_VALUE, node);
			op->ops.push_back(right);	// src
			op->ops.push_back(left);	// dst
			op->type = right->type;
			return op; */
		}
		if (node->data.assign.op == T_INIT_ASSIGN && left->eop == OP_STACK_VALUE_PTR && right->eop == OP_STACK_VALUE_PTR && right->stackValue->isTemp) {
			YO_ASSERT(right->stackValue->type == left->stackValue->type || (allowRightAutoMutable && !isMutable(right->stackValue->type) 
				&& getMutType(right->stackValue->type, node) == left->stackValue->type));
			YO_ASSERT(left->ops.size() == 0);
			YO_ASSERT(!right->stackValue->initStackValue);
			right->stackValue->initStackValue = left->stackValue;
			// return right;			
		}
		op = newOperation(isValueOp(right) ? OP_STORE_VALUE : OP_STORE_PTR, node);
		op->ops.push_back(right);	// src
		op->ops.push_back(left);	// dst
		op->type = left->type;
		return op;
	}
	setError(ERROR_OP, left->parserNode, "Lvalue required");
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
	bool isMutable = false;
	Type * leftValueType = removeMut(getPtrSubType(left->type, node), isMutable);
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
	setError(ERROR_UNREACHABLE, left->parserNode, "Not supported type for index: %s", leftValueType->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileLogicalOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);

	EOperation eop = OP_NOP;
	switch (node->data.binOp.op) {
	case T_OROR: eop = OP_LOGICAL_OR; break;
	case T_ANDAND: eop = OP_LOGICAL_AND; break;
	default:
		setError(ERROR_OP, node, "Error logical op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileOp(scope, node->data.binOp.left);
	Operation * right = compileOp(scope, node->data.binOp.right);
	
	left = convertOpToType(scope, left, getType(TYPE_BOOL), CONVERT_AUTO, node);
	right = convertOpToType(scope, right, getType(TYPE_BOOL), CONVERT_AUTO, node);
	
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	Operation * op = newOperation(eop, node);
	op->type = getType(TYPE_BOOL);
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compileCompareOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);

	EOperation eop = OP_NOP;
	switch (node->data.binOp.op) {
	case T_EQ: eop = OP_CMP_EQ; break;
	case T_NE: eop = OP_CMP_NE; break;
	case T_LE: eop = OP_CMP_LE; break;
	case T_GE: eop = OP_CMP_GE; break;
	case T_LT: eop = OP_CMP_LT; break;
	case T_GT: eop = OP_CMP_GT; break;
	default:
		setError(ERROR_OP, node, "Error compare op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileValue(scope, node->data.binOp.left);
	Operation * right = compileValue(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	bool isLeftMutable = false, isRightMutable = false;
	Type * leftType = removeMut(left->type, isLeftMutable);
	Type * rightType = removeMut(right->type, isRightMutable);
	if (leftType != rightType) {
		Type * resType = getBinOpNumCast(leftType, rightType);
		if (resType) {
			Operation * newLeft = convertOpToType(scope, left, resType, CONVERT_BY_HAND, node);
			Operation * newRight = convertOpToType(scope, right, resType, CONVERT_BY_HAND, node);
			if (!newLeft || !newRight) {
				return NULL;
			}
			left = newLeft;
			right = newRight;
		}
		else{
			setError(ERROR_TYPE, node, "Error types for compare op: %d, left: %s, right: %s", (int)eop, leftType->name.c_str(), rightType->name.c_str());
			return NULL;
		}
	}
	Operation * op = newOperation(eop, node);
	op->type = getType(TYPE_BOOL);
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compilePowOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP && node->data.binOp.op == T_POW);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);

	Operation * left = compileValue(scope, node->data.binOp.left);
	Operation * right = compileValue(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	int bits;
	bool isSigned;
	if (getIntBits(left->type, bits, isSigned)) {
		left = convertOpToType(scope, left, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
		if (!left) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	else if (!left->type->isFloat()) {
		setError(ERROR_TYPE, left->parserNode, "Number required");
		return NULL;
	}
	EOperation eop = OP_BIN_POWF;
	if (getIntBits(right->type, bits, isSigned)) {
#if 1
		right = convertOpToType(scope, right, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
#else
		eop = OP_BIN_POWI;
		right = convertOpToType(scope, right, getType(TYPE_INT32), CONVERT_AUTO, node);
#endif
		if (!right) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	else if (!right->type->isFloat()) {
		setError(ERROR_TYPE, right->parserNode, "Number required");
		return NULL;
	}
	if (left->type != right->type) {
		left = convertOpToType(scope, left, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
		right = convertOpToType(scope, right, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	Operation * op = newOperation(eop, node);
	op->type = left->type;
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::getAddr(Scope * scope, Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (isValueOp(op)) {
		// TODO: store local
		setError(ERROR_UNREACHABLE, node, "Lvalue required");
		return NULL;
	}
	if (op->type->etype == TYPE_PTR) {
		return newOperation(OP_PTR, op, op->type, node);
	}
	if (op->type->etype == TYPE_REF) {
		op->type = getPtrFromRefType(op->type);
		return newOperation(OP_PTR, op, op->type, node);
	}
	setError(ERROR_UNREACHABLE, node, "Lvalue required");
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::getIndirect(Scope * scope, Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (op->eop == OP_PTR) {
		YO_ASSERT(op->ops.size() == 1);
		op = op->ops[0];
	}
	else if (isValueOp(op)) {
		YO_ASSERT(op->type->etype == TYPE_PTR);
		/*
		Operation * offsOp = newOperation(OP_CONST_INT, node);
		offsOp->constInt.bits = 8;
		offsOp->constInt.isSigned = false;
		offsOp->constInt.val = 0;
		offsOp->type = getIntType(offsOp->constInt.bits, offsOp->constInt.isSigned);

		Operation * indirectOp = newOperation(OP_ELEMENT_PTR, node);
		indirectOp->type = getPtrSubType(op->type);
		indirectOp->ops.push_back(op);
		indirectOp->ops.push_back(offsOp);
		return indirectOp;
		*/
		/*
		Operation * indirectOp = newOperation(OP_LOAD, node);
		indirectOp->ops.push_back(op);
		indirectOp->type = getPtrSubType(op->type);
		return indirectOp;
		*/
	}
	// type = op->type;
	// op = newOperation(OP_INDIRECT, op, node);
	YO_ASSERT(op->type->etype == TYPE_PTR);
	op->type = getRefFromPtrType(op->type);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compilePostUnaryOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_POST_UNARY_OP);
	YO_ASSERT(node->data.postUnaryOp.node);
	Operation * op, *valueOp;
	switch (node->data.postUnaryOp.op) {
	case T_INC:
	case T_DEC:
		op = compileOp(scope, node->data.postUnaryOp.node);
		valueOp = newConstIntOp(scope, 1, node);
		return newSpecAssignOp(scope, SPEC_POST, op, valueOp, node->data.postUnaryOp.op == T_INC ? OP_BIN_ADD : OP_BIN_SUB, node);
	}
	setError(ERROR_OP, node, "Error post unary op: %d", (int)node->data.postUnaryOp.op);
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileUnaryOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_UNARY_OP);
	YO_ASSERT(node->data.unaryOp.node);
	Type * valueType;
	Operation * op, * valueOp, * binOp;
	int bits; bool isSigned;
	switch (node->data.unaryOp.op) {
	case T_INC:
	case T_DEC:
		op = compileOp(scope, node->data.unaryOp.node);
		valueOp = newConstIntOp(scope, 1, node);
		return newSpecAssignOp(scope, SPEC_PRE, op, valueOp, node->data.unaryOp.op == T_INC ? OP_BIN_ADD : OP_BIN_SUB, node);

	case T_NOT:
		op = compileOp(scope, node->data.unaryOp.node);
		op = convertOpToType(scope, op, getType(TYPE_BOOL), CONVERT_AUTO, node);
		if (!op) {
			YO_ASSERT(isError());
			return NULL;
		}
		binOp = newOperation(OP_BIT_XOR, node);
		valueOp = convertOpToType(scope, newConstIntOp(scope, 1, node), op->type, CONVERT_BY_HAND, node);
		YO_ASSERT(valueOp);
		binOp->ops.push_back(valueOp);
		binOp->ops.push_back(op);
		binOp->type = op->type;
		return binOp;

	case T_PLUS:
	case T_MINUS:
	case T_TILDE:
		op = compileOp(scope, node->data.unaryOp.node);
		valueType = getValueType(op);
		if (valueType->isNumber()) {
			switch (node->data.unaryOp.op) {
			case T_PLUS:
				// nothing to do with number
				return getValue(scope, op, node);

			case T_MINUS:
				binOp = newOperation(OP_BIN_SUB, node);
				valueOp = convertOpToType(scope, newConstFloatOp(scope, 0, node), valueType, CONVERT_BY_HAND, node);
				YO_ASSERT(valueOp);
				binOp->ops.push_back(valueOp);
				binOp->ops.push_back(getValue(scope, op, node));
				binOp->type = valueType;
				return binOp;

			case T_TILDE:
				if (getIntBits(valueType, bits, isSigned)) {
					binOp = newOperation(OP_BIT_XOR, node);
					valueOp = convertOpToType(scope, newConstIntOp(scope, ~0, node), valueType, CONVERT_BY_HAND, node);
					YO_ASSERT(valueOp);
					binOp->ops.push_back(valueOp);
					binOp->ops.push_back(getValue(scope, op, node));
					binOp->type = valueType;
					return binOp;
				}
				setError(ERROR_UNREACHABLE, node, "Integer required");
				return NULL;
			}
		}
		setError(ERROR_UNREACHABLE, node, "Number required");
		return NULL;

	case T_ADDR:
		return getAddr(scope, compileOp(scope, node->data.unaryOp.node), node);

	case T_INDIRECT:
		return getIndirect(scope, compileOp(scope, node->data.unaryOp.node), node);
	}
	setError(ERROR_OP, node, "Error unary op: %d", (int)node->data.unaryOp.op);
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileBinOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);
	EOperation eop = OP_NOP;
	switch (node->data.binOp.op) {
	case T_PLUS: eop = OP_BIN_ADD; break;
	case T_MINUS: eop = OP_BIN_SUB; break;
	case T_MUL: eop = OP_BIN_MUL; break;
	case T_DIV: eop = OP_BIN_DIV; break;
	case T_MOD: eop = OP_BIN_MOD; break;

	case T_POW:
		return compilePowOp(scope, node);

	case T_INDEX:
		return compileIndexOp(scope, node);

	case T_EQ:
	case T_NE:
	case T_LE:
	case T_GE:
	case T_LT:
	case T_GT:
		return compileCompareOp(scope, node);

	case T_OROR:
	case T_ANDAND:
		return compileLogicalOp(scope, node);

	case T_OR:
	case T_AND:
	case T_XOR:
		return compileBitOp(scope, node);

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
	bool isLeftMutable = false, isRightMutable = false;
	Type * leftType = removeMut(left->type, isLeftMutable);
	Type * rightType = removeMut(right->type, isRightMutable);
	if (leftType != rightType) {
		Type * resType = getBinOpNumCast(leftType, rightType);
		if (resType) {
			Operation * newLeft = convertOpToType(scope, left, resType, CONVERT_BY_HAND, node);
			Operation * newRight = convertOpToType(scope, right, resType, CONVERT_BY_HAND, node);
			if (!newLeft || !newRight) {
				return NULL;
			}
			left = newLeft;
			right = newRight;
		}
		else{
			setError(ERROR_TYPE, node, "Error types for bin op: %d, left: %s, right: %s", (int)eop, leftType->name.c_str(), rightType->name.c_str());
			return NULL;
		}
	}
	Operation * op = newOperation(eop, node);
	op->type = leftType;
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compileBitOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);
	EOperation eop = OP_NOP;
	switch (node->data.binOp.op) {
	case T_OR: eop = OP_BIT_OR; break;
	case T_AND: eop = OP_BIT_AND; break;
	case T_XOR: eop = OP_BIT_XOR; break;

	default:
		setError(ERROR_OP, node, "Error bit op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileValue(scope, node->data.binOp.left);
	Operation * right = compileValue(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	bool isLeftMutable = false, isRightMutable = false;
	Type * leftType = removeMut(left->type, isLeftMutable);
	Type * rightType = removeMut(right->type, isRightMutable);
	int bits;
	bool isSigned;
	Type * resType = getBinOpNumCast(leftType, rightType);
	if (resType && getIntBits(resType, bits, isSigned)) {
		Operation * newLeft = convertOpToType(scope, left, resType, CONVERT_BY_HAND, node);
		Operation * newRight = convertOpToType(scope, right, resType, CONVERT_BY_HAND, node);
		if (!newLeft || !newRight) {
			return NULL;
		}
		left = newLeft;
		right = newRight;
	}
	else{
		setError(ERROR_TYPE, node, "Integer required for bit op: %d, left: %s, right: %s", (int)eop, leftType->name.c_str(), rightType->name.c_str());
		return NULL;
	}
	Operation * op = newOperation(eop, node);
	op->type = leftType;
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

bool YoProgCompiler::compileStmtBinOp(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileBinOp(scope, node));
}

bool YoProgCompiler::compileStmtUnaryOp(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileUnaryOp(scope, node));
}

bool YoProgCompiler::compileStmtPostUnaryOp(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compilePostUnaryOp(scope, node));
}

bool YoProgCompiler::compileStmtAssign(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileAssign(scope, node));
}

bool YoProgCompiler::compileStmtCall(Scope * scope, YoParserNode * node)
{
	return addStmt(scope, compileCall(scope, node));
}

bool YoProgCompiler::matchTypeTemplate(Scope * scope, Type *& a, Type * b, bool init)
{
	if (!a->isUnknownYet) {
		return false;
	}
	Type * lt = a, *rt = b;
	for (;;) {
		if (lt->etype == TYPE_MUT && init) {
			lt = getSubType(lt);
			if (matchTypeTemplate(scope, lt, b, false)) {
				a = getMutType(lt, a->parserNode);
				return true;
			}
			return false;
		}
		if (rt->etype == TYPE_UNKNOWN_YET) {
			YO_ASSERT(false);
			return false;
		}
		if (lt->etype == TYPE_UNKNOWN_YET) {
			bool isMutable;
			a = removeMut(b, isMutable);
			return true;
		}
		if (lt->etype != rt->etype) {
			return false;
		}
		if (lt->etype == TYPE_ARRAY) {
			YO_ASSERT(dynamic_cast<ArrayType*>(lt) && dynamic_cast<ArrayType*>(rt));
			ArrayType *la = (ArrayType*)lt, *ra = (ArrayType*)rt;
			if (la->size != ra->size) {
				return false;
			}
			lt = la->subType, rt = ra->subType;
			continue;
		}
		SubType *ls = dynamic_cast<SubType*>(lt), *rs = dynamic_cast<SubType*>(rt);
		if (!ls || !rs) {
			return false;
		}
		lt = ls->subType, rt = rs->subType;
	}
	return false;
	/*
	SubType * curLeft = dynamic_cast<SubType*>(a);
	if (!curLeft) {
		return false;
	}
	bool isLeftMutable = curLeft->etype == TYPE_MUT;
	if (isLeftMutable && b->etype != TYPE_MUT) {
		Type * leftType = curLeft->subType;
		if (leftType == b) {
			return getMutType(b, a->parserNode);
		}
		return false;
	}

	SubType * curRight = dynamic_cast<SubType*>(b);
	if (!curRight) {
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
	*/
}

bool YoProgCompiler::compileStmtFor(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_FOR);

	// for stmt could have local vars so create scope for
	Scope * varScope = new Scope(scope, SCOPE_BLOCK, "varScope", node);
	YO_ASSERT(varScope);

	if (!compileScopeBody(varScope, node->data.stmtFor.init)) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * conditionOp = NULL;
	if (node->data.stmtFor.condition) {
		conditionOp = compileOp(varScope, node->data.stmtFor.condition);
		conditionOp = convertOpToType(varScope, conditionOp, getType(TYPE_BOOL), CONVERT_AUTO, node->data.stmtFor.condition);
		if (!conditionOp) {
			YO_ASSERT(isError());
			return NULL;
		}
	}

	Scope * bodyScope = NULL;
	if (node->data.stmtFor.body) {
		bodyScope = new Scope(varScope, SCOPE_BLOCK, "body", node->data.stmtFor.body);
		YO_ASSERT(bodyScope);
		if (!compileScopeBody(bodyScope, node->data.stmtFor.body)) {
			YO_ASSERT(isError());
			return false;
		}
	}

	Scope * stepScope = NULL;
	if (node->data.stmtFor.step) {
		stepScope = new Scope(varScope, SCOPE_BLOCK, "step", node->data.stmtFor.step);
		YO_ASSERT(stepScope);
		if (!compileScopeBody(stepScope, node->data.stmtFor.step)) {
			YO_ASSERT(isError());
			return false;
		}
	}

	Operation * forOp = newOperation(OP_FOR, node->data.stmtIf.thenStmt);
	forOp->stmtFor.conditionOp = conditionOp;
	forOp->stmtFor.bodyScope = bodyScope;
	forOp->stmtFor.stepScope = stepScope;
	varScope->ops.push_back(forOp);

	Operation * varScopeOp = newOperation(OP_SCOPE, node);
	varScopeOp->scope = varScope;
	return addStmt(scope, varScopeOp);
}

bool YoProgCompiler::compileStmtBreak(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_BREAK);
	Operation * op = newOperation(node->data.stmtBreak.op == T_BREAK ? OP_BREAK : OP_CONTINUE, node);
	op->strIndex = -1;
	if (node->data.stmtBreak.label) {
		YO_ASSERT(node->data.stmtBreak.label->type == YO_NODE_NAME);
		op->strIndex = addConstStr(getTokenStr(node->data.stmtBreak.label));
	}
	return addStmt(scope, op);
}

bool YoProgCompiler::compileStmtIf(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_IF);

	// if stmt could have local vars so create scope for
	Scope * varScope = new Scope(scope, SCOPE_BLOCK, "varScope", node);
	YO_ASSERT(varScope);

	Operation * conditionOp = compileOp(varScope, node->data.stmtIf.ifExpr);
	conditionOp = convertOpToType(varScope, conditionOp, getType(TYPE_BOOL), CONVERT_AUTO, node->data.stmtIf.ifExpr);
	if (!conditionOp) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(node->data.stmtIf.thenStmt);
	Scope * thenScope = new Scope(varScope, SCOPE_BLOCK, "then", node->data.stmtIf.thenStmt);
	YO_ASSERT(thenScope);
	if (!compileScopeBody(thenScope, node->data.stmtIf.thenStmt)) {
		YO_ASSERT(isError());
		return false;
	}
	// Operation * thenOp = newOperation(OP_SCOPE, node->data.stmtIf.thenStmt);
	// thenOp->scope = thenScope;

	Scope * elseScope = NULL;
	// Operation * elseOp = NULL;
	if (node->data.stmtIf.elseStmt) {
		elseScope = new Scope(varScope, SCOPE_BLOCK, "else", node->data.stmtIf.elseStmt);
		YO_ASSERT(elseScope);
		if (!compileScopeBody(elseScope, node->data.stmtIf.elseStmt)) {
			YO_ASSERT(isError());
			return false;
		}
		// elseOp = newOperation(OP_SCOPE, node->data.stmtIf.elseStmt);
		// elseOp->scope = elseScope;
	}

	Operation * ifOp = newOperation(OP_IF, node->data.stmtIf.thenStmt);
	ifOp->stmtIf.conditionOp = conditionOp;
	ifOp->stmtIf.thenScope = thenScope;
	ifOp->stmtIf.elseScope = elseScope;
	varScope->ops.push_back(ifOp);

	Operation * varScopeOp = newOperation(OP_SCOPE, node);
	varScopeOp->scope = varScope;
	return addStmt(scope, varScopeOp);
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
		if (matchTypeTemplate(scope, func->funcNativeType->resType, value->type, false)) {
			updateFuncNativeType(func->funcNativeType);
		}
		else {
			value = convertOpToType(scope, value, func->funcNativeType->resType, CONVERT_AUTO, node);
			if (!value) {
				return false;
			}
		}
		op->type = value->type;
		op->ops.push_back(value);
		return addStmt(scope, op);
	}
	// YO_ASSERT(getFunction(scope)->funcNativeType->resType == getType(TYPE_VOID));
	Function * func = getFunction(scope);
	switch (func->funcNativeType->resType->etype) {
	case TYPE_UNKNOWN_YET:
		func->funcNativeType->resType = getType(TYPE_VOID);
		updateFuncNativeType(func->funcNativeType);
		break;

	case TYPE_VOID:
		break;

	default:
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: void to %s", func->funcNativeType->resType->name.c_str());
		return NULL;
	}
	op->type = getType(TYPE_VOID);
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
	case TYPE_BOOL: bits = 1; isSigned = false; return true;
	case TYPE_UINT8: bits = 8; isSigned = false; return true;
	case TYPE_UINT16: bits = 16; isSigned = false; return true;
	case TYPE_UINT32: bits = 32; isSigned = false; return true;
	case TYPE_UINT64: bits = 64; isSigned = false; return true;
	case TYPE_MUT:
	case TYPE_CONST:
		return getIntBits(getSubType(type), bits, isSigned);
	}
	return false;
}

bool YoProgCompiler::getFloatBits(Type * type, int& bits)
{
	switch (type->etype) {
	case TYPE_FLOAT32: bits = 32; return true;
	case TYPE_FLOAT64: bits = 64; return true;
	case TYPE_MUT:
	case TYPE_CONST:
		return getFloatBits(getSubType(type), bits);
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
			getFloatBits(to, bits[1]);
			castOp = CastOp(to->etype, isSigned[0] ? OP_CAST_SI_TO_FP : OP_CAST_UI_TO_FP, bits[0] < bits[1] ? CAST_AUTO : CAST_BY_HAND);
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
	case OP_STORE_VALUE:
	case OP_STORE_PTR:
		return false;

	/*case OP_INDIRECT:
		YO_ASSERT(false);*/
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
	case OP_STORE_VALUE:
	case OP_STORE_PTR:
		return getPtrOrRefSubType(op->type);
	}
	return op->type;
}

/*
YoProgCompiler::Type * YoProgCompiler::skipTypeMod(Type * type)
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
*/

YoProgCompiler::Type * YoProgCompiler::addMut(Type * type, bool isMutable)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (isMutable && !this->isMutable(type)) {
		return getMutType(type, type->parserNode);
	}
	return type;
}

YoProgCompiler::Type * YoProgCompiler::removeMut(Type * type, bool& isMutable)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->etype == TYPE_MUT || type->etype == TYPE_CONST) {
		isMutable = type->etype == TYPE_MUT;
		YO_ASSERT(dynamic_cast<SubType*>(type) && ((SubType*)type)->subType);
		return ((SubType*)type)->subType;
	}
	isMutable = false;
	return type;
}

YoProgCompiler::Operation * YoProgCompiler::loadValue(Scope * scope, Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	bool isMutable = false;
	Type * valueType = removeMut(getPtrOrRefSubType(op->type), isMutable);
	if (!valueType) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * loadOp = newOperation(OP_LOAD, node);
	loadOp->ops.push_back(op);
	loadOp->type = valueType;
	return loadOp;
}

YoProgCompiler::Operation * YoProgCompiler::getValue(Scope * scope, Operation * op, YoParserNode * node)
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
	case OP_STORE_VALUE:
	case OP_STORE_PTR:
		type = getPtrOrRefSubType(op->type);
		if (!type) {
			YO_ASSERT(isError());
			return NULL;
		}
		loadOp = newOperation(OP_LOAD, node);
		loadOp->ops.push_back(op);
		loadOp->type = type;
		return loadOp;
	}
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::convertPtrToType(Scope * scope, Operation * op, Type * type, YoParserNode * node)
{
	/*
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
	*/
	return convertOpToType(scope, op, type, CONVERT_BY_HAND, node);
}

YoProgCompiler::Operation * YoProgCompiler::convertArgToType(Scope * scope, Operation * op, Type * type, bool isExtern, YoParserNode * node)
{
	if (type) {
		op = convertOpToType(scope, op, type, CONVERT_AUTO, node);
	}
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	bool isVarArg = type == NULL, isMutable = false;
	type = removeMut(getValueType(op), isMutable);
	switch (type->etype) {
	case TYPE_INT8:
	case TYPE_INT16:
	case TYPE_INT32:
		if (isVarArg || isExtern) {
			return convertOpToType(scope, op, getIntType(true), CONVERT_BY_HAND, node);
		}
		// no break
	case TYPE_INT64:
		return op;

	case TYPE_BOOL:
	case TYPE_UINT8:
	case TYPE_UINT16:
	case TYPE_UINT32:
		if (isVarArg || isExtern) {
			return convertOpToType(scope, op, getIntType(false), CONVERT_BY_HAND, node);
		}
		// no break
	case TYPE_UINT64:
		return op;

	case TYPE_FLOAT64:
	case TYPE_PTR:
	// case TYPE_REF:
		return op;

	case TYPE_ARRAY:
		if (isVarArg || isExtern) {
			return convertOpToType(scope, op, getPtrType(getSubType(type)), CONVERT_BY_HAND, node);
		}
		return op;

	case TYPE_FLOAT32:
		if (isExtern) {
			return convertOpToType(scope, op, getType(TYPE_FLOAT64), CONVERT_BY_HAND, node);
		}
		return op;
	}
	setError(ERROR_TYPE, op->parserNode, "Error %stype %s", isExtern ? "extern " : "", type->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::convertOpToType(Scope * scope, Operation * op, Type * type, EConvertType convertType, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(op->type && type);
	/* if (type->etype == TYPE_PTR) {
		return convertPtrToType(scope, op, type, node);
	} */
	bool isValue = isValueOp(op);
	Type * valueType = isValue ? op->type : getValueType(op);
	if (valueType == type) {
		return isValue ? op : getValue(scope, op, node);
	}
	if (type->etype == TYPE_REF) {
		if (!isValue) {
			Type * subType = getRefSubType(type);
			if (subType == valueType) {
				op->type = type;
				return op;
			}
			if (subType->etype != TYPE_MUT && valueType->etype == TYPE_MUT) {
				if (subType == getSubType(valueType)) {
					op->type = type;
					return op;
				}
			}
		}
		/* else {
			Type * subType = getRefSubType(type);
			if (subType == valueType) {
				op->type = type;
				return op;
			}
			if (subType->etype != TYPE_MUT && valueType->etype == TYPE_MUT) {
				if (subType == getSubType(valueType)) {
					op->type = type;
					return op;
				}
			}
		} */
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error auto convert: %s to %s", valueType->name.c_str(), type->name.c_str());
		return NULL;
	}
	if (type->etype == TYPE_PTR) {
		if (valueType->etype == TYPE_ARRAY) {
			if (getPtrSubType(type) == getSubType(valueType)) {
				op = getAddr(scope, op, node);
				return convertOpToType(scope, op, type, CONVERT_BY_HAND, node);
			}
		}
		if (valueType->etype == TYPE_PTR) {
			bool doConvert = true;
			if (convertType == CONVERT_AUTO) {
				doConvert = getPtrSubType(type)->etype == TYPE_VOID;
			}
			if (doConvert) {
				Operation * convertOp = newOperation(OP_CAST_PTR, node);
				convertOp->type = type;
				convertOp->ops.push_back(op);
				return convertOp;
			}
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error auto convert: %s to %s", valueType->name.c_str(), type->name.c_str());
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
				return getValue(scope, resultOp, node);
			}
		}
	}
	bool isSrcMutable = false, isDstMutable = false;
	type = removeMut(type, isDstMutable);
	if (valueType == type) {
		return isValue ? op : getValue(scope, op, node);
	}
	valueType = removeMut(valueType, isSrcMutable);
	CastOp castOp = getCastOp(valueType, type);
	if (castOp.eop != OP_NOP) {
		int bits;
		bool isSigned, doConvert = false;
		if (castOp.castType == CAST_AUTO || convertType == CONVERT_BY_HAND) {
			doConvert = true;
		}
		else{
			switch (op->eop) {
			case OP_CONST_INT:
				if (getIntBits(type, bits, isSigned)) {
					// YO_U64 mask = isSigned ? (YO_U64)-1 : 0;
					YO_U64 mask = ((YO_U64)1 << bits) - 1;
					if ((op->constInt.val & mask) == op->constInt.val) {
						doConvert = true;
					}
				}
				else{
					switch (type->etype) {
					case TYPE_FLOAT32:
						if ((YO_U64)(float)op->constInt.val == op->constInt.val) {
							doConvert = true;
						}
						break;

					case TYPE_FLOAT64:
						if ((YO_U64)(double)op->constInt.val == op->constInt.val) {
							doConvert = true;
						}
						break;
					}
				}
			}
		}
		if (doConvert) {
			Operation * convertOp = newOperation(castOp.eop, op->parserNode);
			convertOp->type = addMut(type, isDstMutable);
			convertOp->ops.push_back(isValue ? op : getValue(scope, op, node));
			return convertOp;
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error auto convert: %s to %s", valueType->name.c_str(), type->name.c_str());
		return NULL;
	}
	setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", valueType->name.c_str(), type->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::newFuncDataPtrOp(Scope * scope, Function * func, YoParserNode * node)
{
	FuncDataType * funcDataType = getFuncDataType(func->funcNativeType);
	StackValue * temp = allocTempValue(scope, funcDataType, "#temp", node);

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
	storeOp->type = funcElemPtrPtr->type;

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
	storeOp->type = closureElemPtrPtr->type;

	resultOp->ops.push_back(storeOp);
	return resultOp;
}