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

bool YoProgCompiler::Type::isInt() const
{
	switch (etype) {
	case TYPE_INT8:
	case TYPE_INT16:
	case TYPE_INT32:
	case TYPE_INT64:
	case TYPE_BOOL:
	case TYPE_UINT8:
	case TYPE_UINT16:
	case TYPE_UINT32:
	case TYPE_UINT64:
		return true;

	case TYPE_MUT:
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<const SubType*>(this));
		return ((SubType*)this)->subType->isInt();
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
	case TYPE_BOOL:
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

bool YoProgCompiler::Type::isPtr() const
{
	switch (etype) {
	case TYPE_PTR:
		return true;

	case TYPE_MUT:
	case TYPE_CONST:
		YO_ASSERT(dynamic_cast<const SubType*>(this));
		return ((SubType*)this)->subType->isPtr();
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

YoProgCompiler::Variable::Variable(Scope * p_scope, Type * p_type, const std::string& p_name, YoParserNode * p_node) : name(p_name)
{
	parserNode = p_node;
	scope = p_scope;
	type = p_type;
	isGlobal = false;
	isArg = false;
	// isMutable = false;
	isInitialized = false;
	isChanged = false;
	isUsed = false;
	isTemp = false;
	// isClosure = false;
	initVar = NULL;
	initStructElementIndex = -1;
	ext.index = -1;
}

YoProgCompiler::Variable::~Variable()
{
}

// ==============================================================

YoProgCompiler::Scope::Scope(Scope * p_parent, EScope p_escope, const std::string& p_name, YoParserNode * p_node) : 
	// Value(VALUE_SCOPE, p_name, p_node)
	name(p_name), parserNode(p_node)
{
	parent = p_parent;
	escope = p_escope;
	allowBreak = false;
	allowContinue = false;
	allowCase = false;
	
	if (parent) {
		parent->scopes.push_back(this);
	}
}

YoProgCompiler::Scope::~Scope()
{
	if (escope != SCOPE_BLOCK){
		for (int i = 0; i < (int)vars.size(); i++) {
			delete vars[i];
		}
	}
	std::map<std::string, Type*>::iterator it = types.begin();
	for (; it != types.end(); ++it) {
		Type * type = it->second;
		switch (type->etype) {
		case TYPE_STRUCT:
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

YoProgCompiler::YoProgCompiler(YoSystem * s)
{
	system = s;
	// parser = NULL;
	error = ERROR_NOTHING;
	errorNode = NULL;
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
	for (i = 0; i < allOps.size(); i++) {
		delete allOps[i];
	}
	std::map<std::string, Type*>::iterator it = globalTypes.begin();
	for (; it != globalTypes.end(); ++it) {
		delete it->second;
	}
	for (i = 0; i < parsers.size(); i++) {
		const ParserData& parserData = parsers[i];
		delete[] parserData.buf;
		delete parserData.parser;
	}
	resetError();
}

void YoProgCompiler::resetError()
{
	error = ERROR_NOTHING;
	errorMsg = "";
	errorNode = NULL;
}

void YoProgCompiler::setError(Error err, YoParserNode * node)
{
	setError(err, node, "");
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
		// YO_ASSERT(false);
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

bool YoProgCompiler::run(const char * filename)
{
	YoSystem::FileHandle * f = system->openFile(filename, "rb");
	if (!f) {
		setError(ERROR_FILE_NOT_OPENED, NULL, "File %s is not opened", filename);
		return false;
	}
	int size = system->seekFile(f, 0, SEEK_END);
	system->seekFile(f, 0, SEEK_SET);
	char * buf = new char[size + 1 + YO_LEX_MAXFILL];
	if (!buf) {
		system->closeFile(f);
		setError(ERROR_UNREACHABLE, NULL, "Error malloc %d bytes reading file %s", size, filename);
		return false;
	}
	system->readFile(buf, size, f);
	memset(buf + size, 0, 1 + YO_LEX_MAXFILL);
	system->closeFile(f);

	YoParser * parser = new YoParser(system, buf, size);
	YO_ASSERT(parser);
	ParserData parserData;
	parserData.buf = buf;
	parserData.parser = parser;
	parsers.push_back(parserData);
	if (!parser->run()) {
		setError(ERROR_IN_PARSER, NULL, "Error parsing file %s", filename);
		return false;
	}
	return run(parser);
}

bool YoProgCompiler::run(YoParser * parser)
{
	/* struct SaveParser {
		YoProgCompiler * progCompiler;
		YoParser * saveParser;
		SaveParser(YoProgCompiler * c, YoParser * p)
		{
			progCompiler = c;
			saveParser = progCompiler->parser;
			progCompiler->parser = p;
		}
		~SaveParser()
		{
			progCompiler->parser = saveParser;
		}
	} saveParser(this, p); */

	if (parser->isError()) {
		setError(ERROR_UNREACHABLE, NULL, "Error in parser");
		return false;
	}
	if (parser->module) {
		if (compileModule(parser->module)) {
			return compileInitProgram();
		}
	}
	else{
		setError(ERROR_UNREACHABLE, NULL, "No module");
	}
	return false;
}

void YoProgCompiler::dumpParsers()
{
	for (int i = 0; i < (int)parsers.size(); i++) {
		parsers[i].parser->dump();
	}
}

void YoProgCompiler::dump()
{
	struct Lib {
		YoProgCompiler * self;

		void printDepth(int depth)
		{
#if 1
			// if (depth > 1) depth = 1;
#endif
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

			case OP_BIN_POW:
				YO_ASSERT(isFloat);
				return  "pow";

			/* case OP_BIN_POWF:
				YO_ASSERT(isFloat);
				return  "fpow";

			case OP_BIN_POWI:
				YO_ASSERT(isFloat);
				return  "fpowi"; */

			case OP_CMP_EQ: return "==";
			case OP_CMP_NE: return "!=";
			case OP_CMP_LE: return "<=";
			case OP_CMP_GE: return ">=";
			case OP_CMP_LT: return "<";
			case OP_CMP_GT:	return ">";

			case OP_BIT_OR: return "|";
			case OP_BIT_AND: return "&";
			case OP_BIT_XOR: return "^";
			case OP_BIT_RSH: return ">>";
			case OP_BIT_LSH: return "<<";

			case OP_LOGICAL_OR: return "||";
			case OP_LOGICAL_AND: return "&&";
			}
			return "<unknown>";
		}

		void dumpCall(Function * func, Scope * scope, Operation * op, int depth)
		{
			YO_ASSERT((op->eop == OP_CALL_CLOSURE || op->eop == OP_CALL_FUNC) && op->ops.size() >= 1);

			bool isClosureCall = op->eop == OP_CALL_CLOSURE;
			int extraArgs = isClosureCall ? 1 : op->callFunc.extraArgs;
			int i, startArg = op->ops.size() - (isClosureCall ? op->callClosure.args : op->callFunc.args) - extraArgs - 1;

			if (startArg > 0) {
				printDepth(depth); printf("begin prepare CALL\n");
				for (i = 0; i < startArg; i++) {
					dumpOp(func, scope, op->ops[i], depth + 1);
				}
				printDepth(depth); printf("end prepare CALL\n");
			}

			printDepth(depth); printf("begin CALL\n");
			for (i = startArg; i < (int)op->ops.size(); i++) {
				dumpOp(func, scope, op->ops[i], depth + 1);
			}
			printDepth(depth); printf("end CALL ");
			dumpType(op->type);
			printf("\n");
		}

		int indexOf(Function * func, Variable * var)
		{
			std::vector<Variable*>::iterator it = std::find(func->vars.begin(), func->vars.end(), var);
			if (it != func->vars.end()) {
				return it - func->vars.begin();
			}
			return -1;
		}

		Variable * emitVar(Variable * var)
		{
			if (var->initVar) {
				return emitVar(var->initVar);
			}
			return var;
		}

		void dumpOp(Function * func, Scope * scope, Operation * op, int depth)
		{
			if (!op) {
				return;
			}
			int i;
			const char * name;
			Variable * var;
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
			case OP_BIN_POW:
			// case OP_BIN_POWF:
			// case OP_BIN_POWI:
			case OP_CMP_EQ:
			case OP_CMP_NE:
			case OP_CMP_LE:
			case OP_CMP_GE:
			case OP_CMP_LT:
			case OP_CMP_GT:
			case OP_BIT_OR:
			case OP_BIT_AND:
			case OP_BIT_XOR:
			case OP_BIT_RSH:
			case OP_BIT_LSH:
			case OP_LOGICAL_OR:
			case OP_LOGICAL_AND:
				YO_ASSERT(op->ops.size() == 2);
				YO_ASSERT(op->type && op->ops[0]->type && op->ops[1]->type);
				YO_ASSERT(self->baseType(op->ops[0]->type) == self->baseType(op->ops[1]->type));
				name = getBinOpName(op->eop, op->ops[0]->type->isFloat(), op->ops[0]->type->isSigned());
				// printDepth(depth); printf("begin OP_BIN_OP %s\n", name);
				dumpOp(func, scope, op->ops[0], depth + 0);
				dumpOp(func, scope, op->ops[1], depth + 0);
				printDepth(depth); printf("BIN OP %s ", name);
				dumpType(op->type);
				printf("\n");
				return;

			case OP_BEGIN_VAR:
				// YO_ASSERT(!op->var->initVar);
				printDepth(depth); printf("BEGIN VAR %s#%d\n", op->var->name.c_str(), indexOf(func, op->var));
				if (op->ops.size() > 0) {
					YO_ASSERT(op->ops.size() == 1);
					dumpOp(func, scope, op->ops[0], depth + 1);
				}
				return;

			case OP_END_VAR:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("END VAR %s#%d\n", op->var->name.c_str(), indexOf(func, op->var));
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

			case OP_SWITCH_EXPR:
			case OP_SWITCH_LOGICAL:
				// YO_ASSERT(op->ops.size() == 0);
				if (op->stmtSwitch.conditionOp) {
					printDepth(depth); printf("SWITCH EXPR\n");
					dumpOp(func, scope, op->stmtSwitch.conditionOp, depth + 1);
				}
				else{
					printDepth(depth); printf("SWITCH LOGICAL\n");
				}
				if (op->stmtSwitch.bodyScope) {
					printDepth(depth); printf("BODY\n");
					dumpScope(func, op->stmtSwitch.bodyScope, depth + 1);
				}
				printDepth(depth); printf("ENDSWITCH\n");
				return;

			case OP_CASE_LOGICAL:
				YO_ASSERT(op->ops.size() == 1);
				printDepth(depth - 1); printf("CASE LOGICAL\n");
				dumpOp(func, scope, op->ops[0], depth);
				printDepth(depth - 1); printf("ENDCASE\n");
				return;

			case OP_CASE_EXPR:
				printDepth(depth - 1); printf("CASE EXPR\n");
				for (i = 0; i < (int)op->ops.size(); i++) {
					if (i > 0) {
						printDepth(depth); printf(i == (int)op->ops.size()/2 ? "----\n" : ",\n");
					}
					dumpOp(func, scope, op->ops[i], depth);
				}
				printDepth(depth - 1); printf("ENDCASE\n");
				return;

			case OP_DEFAULT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth - 1); printf("DEFAULT\n");
				return;

			case OP_FALLTHROUGH:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("FALLTHROUGH\n");
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
					dumpOp(func, scope, op->ops[0], depth + 0);
					printDepth(depth); printf("RETURN ");
					dumpType(op->type);
					printf("\n");
					return;
				}
				printDepth(depth); printf("RETURN\n");
				return;

			case OP_CALL_CLOSURE:
			case OP_CALL_FUNC:
				dumpCall(func, scope, op, depth);
				return;

			case OP_VAR:
				for (i = 0; i < (int)op->ops.size(); i++) {
					dumpOp(func, scope, op->ops[i], depth + 0);
				}
				printDepth(depth); var = emitVar(op->var);
				printf("VAR: %s#%d ", var->name.c_str(), indexOf(func, var));
				dumpType(op->type);
				printf("\n");
				return;

			case OP_STRUCT_ELEMENT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("STRUCT_ELEMENT: %d ", op->structElementIndex);
				dumpType(op->type);
				printf("\n");
				return;

			case OP_ELEMENT: {
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_ELEMENT_PTR\n");
				dumpOp(func, scope, op->ops[0], depth + 0);
				dumpOp(func, scope, op->ops[1], depth + 0);
				printDepth(depth); printf("ELEMENT ");
				dumpType(op->type);
				printf("\n");
				return;
			}

			case OP_FUNC:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("FUNC %s ", op->func->name.c_str());
				dumpType(op->func->funcNativeType);
				printf("\n");
				return;

			case OP_LOAD:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("LOAD ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_STORE:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE\n");
				dumpOp(func, scope, op->ops[0], depth + 0);
				dumpOp(func, scope, op->ops[1], depth + 0);
				printDepth(depth); printf("STORE ");
				// if (op->type) dumpType(op->type);
				printf("\n");
				return;

			case OP_STORE_VALUE:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE_VALUE\n");
				dumpOp(func, scope, op->ops[0], depth + 0);
				dumpOp(func, scope, op->ops[1], depth + 0);
				printDepth(depth); printf("STORE_VALUE ");
				// if (op->type) dumpType(op->type);
				printf("\n");
				return;

			case OP_STORE_REF:
				YO_ASSERT(op->ops.size() == 2);
				// printDepth(depth); printf("begin OP_STORE_REF\n");
				dumpOp(func, scope, op->ops[0], depth + 0);
				dumpOp(func, scope, op->ops[1], depth + 0);
				printDepth(depth); printf("STORE_REF ");
				// if (op->type) dumpType(op->type);
				printf("\n");
				return;

			case OP_VAR_MEMZERO:
				var = emitVar(op->var);
				printDepth(depth); printf("VAR_MEMZERO: %s#%d ", var->name.c_str(), indexOf(func, var));
				dumpType(var->type);
				printf("\n");
				return;

			case OP_ZERO_VALUE:
				printDepth(depth); printf("ZERO_VALUE ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_TRUNC:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_TRUNC ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_ZERO_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_ZERO_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_SIGN_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_SIGN_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_SI_TO_FP:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_SI_TO_FP ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_UI_TO_FP:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_UI_TO_FP ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_TO_SI:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_FP_TO_SI ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_TO_UI:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_FP_TO_UI ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_TRUNC:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_FP_TRUNC ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_FP_EXT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_FP_EXT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_PTR ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_PTR_TO_INT:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_PTR_TO_INT ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_CAST_INT_TO_PTR:
				YO_ASSERT(op->ops.size() == 1);
				dumpOp(func, scope, op->ops[0], depth + 0);
				printDepth(depth); printf("CAST_INT_TO_PTR ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_SIZEOF:
				if (op->ops.size() > 0) {
					YO_ASSERT(op->ops.size() == 1);
					dumpOp(func, scope, op->ops[0], depth + 0);
				}
				printDepth(depth); printf("SIZEOF ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_TYPE:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth); printf("TYPE ");
				dumpType(op->type);
				printf("\n");
				return;

			case OP_TYPE_STRUCT_ELEMENT:
				YO_ASSERT(op->ops.size() == 0);
				printDepth(depth + 1); printf("TYPE ");
				dumpType(op->typeStructElement.parent);
				printf("\n");
				printDepth(depth); printf("TYPE_STRUCT_ELEMENT: %d ", op->typeStructElement.index);
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
			for (i = 0; i < (int)func->vars.size(); i++) {
				Variable * var = func->vars[i];
				// printf("  var %s%s#%d ", var->isMutable ? "mut " : "", var->name.c_str(), i);
				printf("  %s %s#%d ", var->isArg ? "arg" : "var", var->name.c_str(), i);
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
			// case TYPE_CLASS:
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
	if (modules.size() == 0) {
		printf("No module\n");
	}
}

void YoProgCompiler::dumpError()
{
	if (isError()) {
		if (error == ERROR_IN_PARSER) {
			YO_ASSERT(parsers.size());
			parsers.back().parser->dumpError();
		}
		else{
			printf("[err-compiler-%d] %s\n", (int)error, errorMsg.c_str());
			if (errorNode) {
				errorNode->parser->dumpErrorLine(errorNode->token);
			}
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
	return ptrType(getType(TYPE_VOID), NULL);
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
		YO_ASSERT(false);
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

YoProgCompiler::Type * YoProgCompiler::getParserStdType(int stdType, YoParserNode * node)
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
	case T_MUTABLE: return mutType(getType(TYPE_UNKNOWN_YET), node);
	}
	setError(ERROR_UNREACHABLE, node, "Error parser std type: %d", stdType);
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
	Type * closureStructPtr = ptrType(getStructType(elements, funcNativeType->parserNode), funcNativeType->parserNode);
	Type * funcNativePtr = ptrType(funcNativeType, funcNativeType->parserNode);

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
		Type * closurePtr = ptrType(getStructType(emptyTypes, node), node);
		funcType->args.push_back(FuncNativeType::Arg(closurePtr));

		argNames.clear();
		argNames.push_back("#closurePtr");
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
		/* bool isMutable = argNode->data.declVar.isMutable;
		if (isMutable) {
			argType = mutType(argType, argNode->data.declVar.type);
		} */
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
		return isMutable(unrefType(type, NULL));

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

YoProgCompiler::Type * YoProgCompiler::mutType(Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->mutType) {
		return type->mutType;
	}
	if (!node) {
		node = type->parserNode;
	}
	ArrayType * arrType;
	switch (type->etype) {
#if 1
	case TYPE_REF:
		return refType(mutType(unrefType(type, node), node), node);

	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(type));
		arrType = (ArrayType*)type;
		return arrayType(arrType->size, mutType(arrType->subType, node), node);
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
	type->mutType = new SubType(name, TYPE_MUT, type, node);
	type->mutType->isUnknownYet = type->isUnknownYet;
	return type->mutType;
}

YoProgCompiler::Type * YoProgCompiler::constType(Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->constType) {
		return type->constType;
	}
	if (!node) {
		node = type->parserNode;
	}
	ArrayType * arrType;
	switch (type->etype) {
#if 1
	case TYPE_REF:
		return refType(constType(unrefType(type, node), node), node);

	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(type));
		arrType = (ArrayType*)type;
		return arrayType(arrType->size, constType(arrType->subType, node), node);
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
	type->constType = new SubType(name, TYPE_CONST, type, node);
	type->constType->isUnknownYet = type->isUnknownYet;
	return type->constType;
}

YoProgCompiler::Type * YoProgCompiler::ptrType(Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->ptrType) {
		return type->ptrType;
	}
	if (!node) {
		node = type->parserNode;
	}
	std::string name = "*" + type->name;
	type->ptrType = new SubType(name, TYPE_PTR, type, node);
	type->ptrType->isUnknownYet = type->isUnknownYet;
	return type->ptrType;
}

YoProgCompiler::Type * YoProgCompiler::refType(Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (type->refType) {
		return type->refType;
	}
	if (!node) {
		node = type->parserNode;
	}
	std::string name = "&" + type->name;
	type->refType = new SubType(name, TYPE_REF, type, node);
	type->refType->isUnknownYet = type->isUnknownYet;
	return type->refType;
}

YoProgCompiler::Type * YoProgCompiler::arrayType(unsigned size, Type * type, YoParserNode * node)
{
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (!node) {
		node = type->parserNode;
	}
	std::ostringstream buf;
	buf << "[" << size << "]" << type->name;
	std::string name = buf.str();
	std::map<std::string, Type*>::iterator it = type->subTypes.find(name);
	if (it == type->subTypes.end()) {
		Type * subType = new ArrayType(name, size, type, node);
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
	YO_ASSERT(node);
	if (node->type == YO_NODE_TYPE_NAME || node->type == YO_NODE_NAME) {
		std::string name = getTokenStr(node);
		while (scope) {
			std::map<std::string, Type*>::iterator it = scope->types.find(name);
			if (it != scope->types.end()) {
				return it->second;
			}
			scope = scope->parent;
		}
		setError(ERROR_TYPE, node, "Type %s is not found", name.c_str());
	}
	else{
		setError(ERROR_UNREACHABLE, node, "Error type %d", (int)node->type);
	}
	return NULL;
}

YoProgCompiler::Type * YoProgCompiler::declStructType(Scope * scope, EType etype, const std::string& name, YoParserNode * node)
{
	YO_ASSERT(node && (node->type == YO_NODE_TYPE_STRUCT && etype == TYPE_STRUCT));
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
		return mutType(getParserType(scope, node->data.typeMutable.type), node);

	case YO_NODE_TYPE_CONST:
		return constType(getParserType(scope, node->data.typeMutable.type), node);

	case YO_NODE_TYPE_PTR:
		return ptrType(getParserType(scope, node->data.typePtr.type), node);

	case YO_NODE_TYPE_REF:
		return refType(getParserType(scope, node->data.typeRef.type), node);

	case YO_NODE_TYPE_STD_NAME:
		return getParserStdType(node->data.typeStdName, node);

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
		return arrayType(arrSize, getParserType(scope, node->data.typeArr.type), node);
	}
	setError(ERROR_UNREACHABLE, node, "Error parser type: %d", (int)node->type);
	return NULL;
}

bool YoProgCompiler::compileInitProgram()
{
	if (modules.size() == 0) {
		return true;
	}
	YoParserNode * node = modules.back()->parserNode;

	Module * initModule = new Module("@initModule", node);

	FuncNativeType * funcNativeType = new FuncNativeType("", node);
	funcNativeType->resType = getType(TYPE_VOID);
	funcNativeType->name = getFuncNativeTypeName(funcNativeType);

	std::vector<std::string> argNames;
	initModule->initFunc = new Function(initModule, funcNativeType, argNames, "@initProgram", node);
	initModule->funcs.push_back(initModule->initFunc);

	for (int i = 0; i < (int)modules.size(); i++) {
		Module * module = modules[i];
		YO_ASSERT(module->initFunc);
		Operation * funcOp = newOperation(OP_FUNC, module->initFunc->funcNativeType->resType, node);
		funcOp->func = module->initFunc;
		Operation * callOp = newOperation(OP_CALL_FUNC, getType(TYPE_VOID), funcOp, node);
		callOp->callFunc.extraArgs = 0;
		callOp->callFunc.args = 0;
		callOp->callFunc.func = module->initFunc;
		initModule->initFunc->ops.push_back(callOp);
	}
	modules.push_back(initModule);
	return optimizeScopePass1(initModule->initFunc);
}

bool YoProgCompiler::compileModule(YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_MODULE);
	YO_ASSERT(node->data.module.name && node->data.module.name->type == YO_NODE_NAME);
	
	Module * module = new Module(getTokenStr(node->data.module.name), node);
	modules.push_back(module);
	 
	std::string initFuncName = system->getUniqName((std::string("init-") + module->name + "-%d").c_str());
	FuncNativeType * funcNativeType = new FuncNativeType("", node);
	funcNativeType->resType = getType(TYPE_VOID);
	funcNativeType->name = getFuncNativeTypeName(funcNativeType);

	std::vector<std::string> argNames;
	module->initFunc = new Function(module, funcNativeType, argNames, initFuncName, node);
	module->funcs.push_back(module->initFunc);

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

		case YO_NODE_DECL_VAR:
			if (!compileDeclVar(module, stmt)) {
				YO_ASSERT(isError());
				return false;
			}
			break;

		case YO_NODE_ASSIGN:
			if (!compileStmtAssign(module, stmt)) {
				YO_ASSERT(isError());
				return false;
			}
			break;

		default:
			setError(ERROR_UNREACHABLE, stmt, "Error module node: %d", (int)stmt->type);
			return false;
		}
	}
	std::vector<Variable*>::iterator vit = module->vars.begin();
	while (vit != module->vars.end()) {
		Variable * var = *vit;
		YO_ASSERT(var->type);
		if (var->type->etype == TYPE_UNKNOWN_YET) {
			setError(ERROR_TYPE_UNKNOWN, var->parserNode, "Type of variable '%s' is unknown, remove the variable", var->name.c_str());
			return NULL;
			// vit = func->vars.erase(vit);
			// continue;
		}
#if 0
		if (!var->isUsed && !var->isTemp && !var->isArg) {
#if 1
			if (var->name[0] != '_') {
				setError(ERROR_VAR_NOT_USED, var->parserNode, "Variable '%s' is not used, remove the variable", var->name.c_str());
				return NULL;
			}
#endif
			// vit = func->vars.erase(vit);
			// continue;
		}
#endif
		++vit;
	}
	return optimizeScopePass1(module->initFunc);
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
		name = system->getUniqName("subfunc-%d");
	}

	std::vector<std::string> argNames;
	FuncNativeType * funcNativeType = getFuncNativeType(argNames, scope, node);
	Module * module = getModule(scope);
	for (int i = 0; i < (int)module->funcs.size(); i++) {
		Function * func = module->funcs[i];
		if (func->name == name && func->funcNativeType == funcNativeType) {
			setError(ERROR_FUNC_DUPLICATED, node, "Function %s %s is already exist", name.c_str(), funcNativeType->name.c_str());
			return NULL;
		}
	}

	Function * func = new Function(scope, funcNativeType, argNames, name, node);
	module->funcs.push_back(func);

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
		for (int j = 0; j < (int)func->vars.size(); j++) {
			if (func->vars[j]->name == argNames[i]) {
				setError(ERROR_VAR_DUPLICATED, node, "Arg %s is already exist", argNames[i].c_str());
				return NULL;
			}
		}
		if (arg.type->etype == TYPE_VOID) {
			setError(ERROR_TYPE, node, "Variable %s should not be void", argNames[i].c_str());
			return NULL;
		}

		Variable * var = new Variable(func, arg.type, argNames[i], node);
		var->isArg = var->isInitialized = true;
		// var->isMutable = arg.isMutable;
		func->vars.push_back(var);
	}
	
	if (!compileFuncBody(func, node)) {
		YO_ASSERT(isError());
		return NULL;
	}

	std::vector<Variable*>::iterator vit = func->vars.begin();
	while (vit != func->vars.end()) {
		Variable * var = *vit;
		YO_ASSERT(var->type);
		if (var->type->etype == TYPE_UNKNOWN_YET) {
			setError(ERROR_TYPE_UNKNOWN, var->parserNode, "Type of variable '%s' is unknown, remove the variable", var->name.c_str());
			return NULL;
			// vit = func->vars.erase(vit);
			// continue;
		}
		if (!var->isUsed && !var->isTemp && !var->isArg) {
#if 1
			if (var->name[0] != '_') {
				setError(ERROR_VAR_NOT_USED, var->parserNode, "Variable '%s' is not used, remove the variable", var->name.c_str());
				return NULL;
			}
#endif
			// vit = func->vars.erase(vit);
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

			case YO_NODE_STMT_SWITCH:
				if (!compileStmtSwitch(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_CASE:
				if (!compileStmtCase(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_DEFAULT:
				if (!compileStmtDefault(scope, stmt)) {
					return false;
				}
				break;

			case YO_NODE_STMT_FALLTHROUGH:
				if (!compileStmtFallThrough(scope, stmt)) {
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
	case YO_NODE_TYPE_STRUCT:
		return declStructType(scope, TYPE_STRUCT, name, typeNode);
	}
	Type * type = getParserType(scope, typeNode);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	scope->types[name] = type;
	return type;
}

YoProgCompiler::Variable * YoProgCompiler::compileDeclVar(Scope * scope, YoParserNode * node)
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
	/* if (node->data.declVar.isMutable) {
		type = mutType(type, node);
	} */
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}

	YO_ASSERT(node->data.declVar.name && node->data.declVar.name->type == YO_NODE_NAME);

	std::string name = getTokenStr(node->data.declVar.name);
	for (int i = 0; i < (int)scope->vars.size(); i++) {
		if (scope->vars[i]->name == name) {
			setError(ERROR_VAR_DUPLICATED, node->data.declVar.name, "Variable %s is already exist", name.c_str());
			return NULL;
		}
	}
	if (type->etype == TYPE_VOID) {
		setError(ERROR_TYPE, node->data.declVar.name, "Variable %s should not be void", name.c_str());
		return NULL;
	}

	Variable * var = new Variable(scope, type, name, node->data.declVar.name);
	var->isGlobal = scope->escope == SCOPE_MODULE;
	// var->isMutable = node->data.declVar.isMutable;
	scope->vars.push_back(var);
	if (scope->escope == SCOPE_BLOCK) {
		getFunction(scope)->vars.push_back(var);
	}
	Operation * op = newOperation(OP_BEGIN_VAR, NULL, node);
	op->var = var;
	addStmt(scope, op);
	return var;
}

bool YoProgCompiler::findName(NameInfo& out, Scope * scope, const std::string& name)
{
	YO_ASSERT(scope);
	out.funcs.clear();
	for (int upCount = 0; scope;) {
		/* if (scope->escope == SCOPE_MODULE) {
			break;
		} */
		// YO_ASSERT(scope->escope == SCOPE_FUNCTION);
		std::vector<Variable*>::reverse_iterator vit = scope->vars.rbegin();
		for (; vit != scope->vars.rend(); ++vit) {
			Variable * var = *vit;
			if (var->scope != scope || var->isTemp) {
				continue;
			}
			if (var->name == name) {
				out.scope = scope;
				if (scope->escope == SCOPE_MODULE) {
					out.ename = NAME_MODULE_VAR;
					out.var = var;
				}
				else if (upCount > 0) {
					out.ename = NAME_CLOSURE_VAR;
					out.closureValue.count = upCount;
					out.closureValue.value = var;
				}
				else{
					out.ename = NAME_FUNC_VAR;
					out.var = var;
				}
				return true;
			}
		}
		if (scope->escope == SCOPE_MODULE) {
			YO_ASSERT(dynamic_cast<Module*>(scope));
			Module * module = (Module*)scope;
			std::vector<Function*>::iterator fit = module->funcs.begin();
			for (; fit != module->funcs.end(); ++fit) {
				Function * func = *fit;
				if (func->name == name) {
					out.funcs.push_back(func);
				}
			}
			if (out.funcs.size() > 0) {
				out.ename = out.funcs.size() == 1 ? NAME_MODULE_FUNCTION : NAME_MODULE_FUNCTION_LIST;
				out.scope = scope;
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
		/* if (scope->escope == SCOPE_MODULE) {
			YO_ASSERT(!scope->parent);
			break;
		} */
		scope = scope->parent;
	}
	// YO_ASSERT(scope->escope == SCOPE_MODULE && dynamic_cast<Module*>(scope));
	out.ename = NAME_UNKNOWN;
	out.scope = NULL;
	return false;
}

YoProgCompiler::Operation * YoProgCompiler::compileValueOf(Scope * scope, YoParserNode * node)
{
	return valueOf(compileOp(scope, node), node);
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
	return newConstStringOp(scope, buf.str(), node);
}

YoProgCompiler::Operation * YoProgCompiler::compileSingleQuotedString(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_SINGLE_QUOTED_STRING);

	const char * s = node->token.str + 1;
	const char * end = s + (node->token.len - 2);
	std::ostringstream buf;
	for (; s < end;) {
		if (*s == '\\') {
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
	return newConstStringOp(scope, buf.str(), node);
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
		return newConstNullOp(scope, node);

	case YO_NODE_CONST_TRUE:
	case YO_NODE_CONST_FALSE:
		return newConstBoolOp(scope, node->type == YO_NODE_CONST_TRUE, node);

	case YO_NODE_CONST_INT:
		return newConstIntOp(scope, node->data.constInt.val, node->data.constInt.bits, node->data.constInt.isSigned, node);

	case YO_NODE_CONST_FLOAT:
		return newConstFloatOp(scope, node->data.constFloat.fval, getType(TYPE_FLOAT32), node);

	case YO_NODE_CONST_DOUBLE:
		return newConstFloatOp(scope, node->data.constFloat.fval, getType(TYPE_FLOAT64), node);

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
		case NAME_FUNC_VAR:
		case NAME_MODULE_VAR:
			op = newVarOp(nameInfo.var, node);
			op->var->isUsed = true;
			return op;

		case NAME_CLOSURE_VAR:
			setError(ERROR_UNREACHABLE, node, "Closure value is not supported yet, error name: %s", name.c_str());
			return NULL;

		case NAME_TYPE:
			return newOperation(OP_TYPE, nameInfo.type, node);

		case NAME_MODULE_FUNCTION:
			op = newOperation(OP_FUNC, ptrType(nameInfo.funcs[0]->funcNativeType, node), node);
			op->func = nameInfo.funcs[0];
			return op;

		case NAME_MODULE_FUNCTION_LIST:
			op = newOperation(OP_FUNC_AMBIGUOUS, NULL, node);
			op->ambiguousFuncs = nameInfo.funcs;
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

	case YO_NODE_NEW_ARR_EXPS:
		return compileNewArrExprs(scope, node);

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
		return convertToType(scope, compileOp(scope, node->data.cast.expr), getParserType(scope, node->data.cast.type), CONVERT_BY_HAND, node);
	}
	setError(ERROR_UNREACHABLE, node, "Error parser node: %d", (int)node->type);
	return NULL;
}

bool YoProgCompiler::addStmt(Scope * scope, Operation * op)
{
	YO_ASSERT(scope);
	if (!op) {
		YO_ASSERT(isError());
		return false;
	}
	if (scope->escope == SCOPE_MODULE) {
		YO_ASSERT(dynamic_cast<Module*>(scope) && ((Module*)scope)->initFunc);
		scope = ((Module*)scope)->initFunc;
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
	TypeAttrs typeAttrs;
	Type * leftValueType;
	bool isLeftTypeOp = isTypeOp(left);
	if (isLeftTypeOp) {
		leftValueType = left->type;
		if (leftValueType->etype != TYPE_STRUCT && leftValueType->etype != TYPE_CLASS) {
			setError(ERROR_TYPE, node, "Struct or class type required: %s", leftValueType->name.c_str());
			return NULL;
		}
		std::string fieldName = getTokenStr(right);
		StructType * structType = dynamic_cast<StructType*>(leftValueType);
		YO_ASSERT(structType);
		std::map<std::string, int>::iterator it = structType->nameIndices.find(fieldName);
		if (it != structType->nameIndices.end()) {
			Operation * op = newOperation(OP_TYPE_STRUCT_ELEMENT, structType->types[it->second], node);
			op->typeStructElement.parent = structType;
			op->typeStructElement.index = it->second;
			return op;
		}
		setError(ERROR_FIELD_NOT_FOUND, node, "Member %s is not found in %s", fieldName.c_str(), structType->name.c_str());
		return NULL;
	}
	/* else if (!isRefOp(left)) {
		leftValueType = baseType(left->type, typeAttrs);
		YO_ASSERT(!typeAttrs.isRef);
		if (leftValueType->etype != TYPE_STRUCT && leftValueType->etype != TYPE_CLASS) {
			setError(ERROR_TYPE, node, "Struct or class type required: %s", leftValueType->name.c_str());
			return NULL;
		}
		Variable * val = allocTempValue(scope, leftValueType, "#temp", node);
		Operation * varOp = newVarOp(val, node);
		
		Operation * storeOp = newOperation(OP_STORE, varOp->type, node);
		storeOp->ops.push_back(left);
		storeOp->ops.push_back(newVarOp(val, node));
		
		varOp->ops.push_back(storeOp);
		left = varOp;
	} */
	else{
		leftValueType = baseType(left->type, typeAttrs);
		YO_ASSERT(typeAttrs.isRef);
		// left = newOperation(OP_LOAD, leftValueType, left, node);
		if (leftValueType->etype == TYPE_PTR) {
			// left = indirectOf(addrOf(loadValueOf(indirectOf(left, node), node), node), node);
			left = refValueOf(indirectOf(left, node), node);
			leftValueType = baseType(left->type, typeAttrs);
			YO_ASSERT(typeAttrs.isRef);
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
		return newStructElementOp(left, it->second, node);
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
	Operation * op = compileValueOf(scope, node->data.sizeOf.node);
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	return newOperation(OP_SIZEOF, getIntType(sizeof(int) * 8, false), op, node);
}

YoProgCompiler::Operation * YoProgCompiler::compileCall(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_CALL);
	Operation * nameOp = compileOp(scope, node->data.call.name);
	if (!nameOp) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (nameOp->eop == OP_VAR) {
		YO_ASSERT(nameOp->var->type);
		if (nameOp->var->type->etype != TYPE_FUNC_DATA || !dynamic_cast<FuncDataType*>(nameOp->var->type)){
			setError(ERROR_TYPE, nameOp->var->parserNode, "Func type required, found: %s", nameOp->var->type->name.c_str());
			return NULL;
		}
		Operation * funcElemPtrRef = newStructElementOp(nameOp, 0, node);
		if (!funcElemPtrRef) {
			YO_ASSERT(isError());
			return NULL;
		}
		YO_ASSERT(funcElemPtrRef->type->etype == TYPE_REF);
		Operation * funcElemPtr = valueOf(funcElemPtrRef, node);

		Operation * closureElemPtrRef = newStructElementOp(nameOp, 1, node);
		if (!closureElemPtrRef) {
			YO_ASSERT(isError());
			return NULL;
		}
		YO_ASSERT(closureElemPtrRef->type->etype == TYPE_REF);
		Operation * closureElemPtr = valueOf(closureElemPtrRef, node);

		YO_ASSERT(dynamic_cast<FuncDataType*>(nameOp->var->type));
		FuncDataType * funcDataType = (FuncDataType*)nameOp->var->type;

		Operation * op = newOperation(OP_CALL_CLOSURE, funcDataType->funcNativeType->resType, node);
		op->callClosure.funcDataType = funcDataType;
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
			argOp = convertToType(scope, argOp, funcDataType->funcNativeType->args[i + 1].type, CONVERT_AUTO, node);
			if (!argOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->ops.push_back(argOp);
		}
		return op;
	}
	if (nameOp->eop == OP_FUNC_AMBIGUOUS) {
		setError(ERROR_FUNC_AMBIGUOUS, nameOp->parserNode, "Function call ambiguous");
		return NULL;
	}
	if (nameOp->eop == OP_FUNC) {
		Operation * op = newOperation(OP_CALL_FUNC, nameOp->func->funcNativeType->resType, nameOp, node);
		op->callFunc.func = nameOp->func;

		int extraArgs = 1;
		if (!nameOp->func->funcNativeType->isExtern) {
			Operation * nullOp = newConstNullOp(scope, node);
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

YoProgCompiler::Variable * YoProgCompiler::allocTempValue(Scope * scope, Type * type, YoParserNode * node)
{
	return allocTempValue(scope, type, "#temp", node);
}

YoProgCompiler::Variable * YoProgCompiler::allocTempValue(Scope * scope, Type * type, const std::string& name, YoParserNode * node)
{
	Variable * var = new Variable(scope, type, name, node);
	scope->vars.push_back(var);
	if (scope->escope == SCOPE_BLOCK) {
		getFunction(scope)->vars.push_back(var);
	}
	// temp->isMutable = true;
	var->isTemp = true;
	Operation * op = newOperation(OP_BEGIN_VAR, NULL, node);
	op->var = var;
	addStmt(scope, op);
	return var;
}

void YoProgCompiler::addSymbol(const std::string& name, void * addr)
{
	symbols[name] = addr;
}

YoProgCompiler::Operation * YoProgCompiler::newOperation(EOperation eop, Type * type, YoParserNode * node)
{
	if (!node){
		int i = 0;
	}
	YO_ASSERT(node);
	Operation * op = new Operation(eop, node);
	allOps.push_back(op);
	op->type = type;
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newOperation(EOperation eop, Type * type, Operation * sub, YoParserNode * node)
{
	if (!sub) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * op = newOperation(eop, type, node);
	op->ops.push_back(sub);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newStoreOp(Operation * valueOp, Variable * var, YoParserNode * node)
{
	return newStoreOp(valueOp, newVarOp(var, node), node);
}

YoProgCompiler::Operation * YoProgCompiler::newStoreOp(Operation * valueOp, Operation * refOp, YoParserNode * node)
{
	YO_ASSERT(valueOp && refOp && refOp->type->etype == TYPE_REF);
	if (valueOp->eop == OP_VAR && refOp->eop == OP_VAR && valueOp->var->isTemp && !valueOp->var->initVar) { // valueOp->var->initVar == refOp->var) {
		valueOp->var->initVar = refOp->var;
		refOp->ops.push_back(valueOp);
		return refOp;
	}
	if (valueOp->eop == OP_VAR && refOp->eop == OP_STRUCT_ELEMENT && refOp->ops[0]->eop == OP_VAR 
		&& valueOp->var->isTemp && !valueOp->var->initVar) { // valueOp->var->initVar == refOp->var) {
		valueOp->var->initVar = refOp->ops[0]->var;
		valueOp->var->initStructElementIndex = refOp->structElementIndex;
		// refOp->ops.push_back(valueOp);
		// return refOp;
		valueOp->type = refOp->type;
		return valueOp;
	}
	Operation * op = newOperation(OP_STORE, refOp->type, node);
	op->ops.push_back(valueOp);
	op->ops.push_back(refOp);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstNullOp(Scope * scope, YoParserNode * node)
{
	return newOperation(OP_CONST_NULL, getVoidPtrType(), node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstBoolOp(Scope * scope, bool val, YoParserNode * node)
{
	return newConstIntOp(scope, val, 1, false, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstStringOp(Scope * scope, const std::string& val, YoParserNode * node)
{
	Operation * op = newOperation(OP_CONST_STRING, ptrType(getType(TYPE_UINT8), node), node);
	op->strIndex = addConstStr(val);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstIntOp(Scope * scope, YO_U64 val, int bits, bool isSigned, YoParserNode * node)
{
	Type * type = getIntType(bits, isSigned);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * op = newOperation(OP_CONST_INT, type, node);
	op->constInt.bits = bits;
	op->constInt.isSigned = isSigned;
	op->constInt.val = val;
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstIntOp(Scope * scope, YO_U64 val, YoParserNode * node)
{
	return newConstIntOp(scope, val, sizeof(val) * 8, false, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstIntOp(Scope * scope, YO_U64 val, Type * type, YoParserNode * node)
{
	YO_ASSERT(type->isNumber() && !type->isFloat());
	Operation * op = newConstIntOp(scope, val, node);
	return convertToType(scope, op, type, CONVERT_AUTO, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstFloatOp(Scope * scope, double val, int bits, YoParserNode * node)
{
	Type * type = getFloatType(bits);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * op = newOperation(OP_CONST_FLOAT, type, node);
	op->constFloat.fval = val;
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::newConstFloatOp(Scope * scope, double val, YoParserNode * node)
{
	return newConstFloatOp(scope, val, sizeof(val) * 8, node);
}

YoProgCompiler::Operation * YoProgCompiler::newConstFloatOp(Scope * scope, double val, Type * type, YoParserNode * node)
{
	switch (type->etype) {
	case TYPE_FLOAT32:
	case TYPE_FLOAT64:
		Operation * op = newOperation(OP_CONST_FLOAT, type, node);
		op->constFloat.fval = val;
		return op;
	}
	YO_ASSERT(false);
	setError(ERROR_UNREACHABLE, node, "Error const float type %s", type->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::newVarOp(Variable * value, YoParserNode * node)
{
	YO_ASSERT(value && value->type);
	Type * type = refType(value->type, node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * op = newOperation(OP_VAR, type, node);
	op->var = value;
	return op;
}

YoProgCompiler::Type * YoProgCompiler::unptrType(Type * ptrType, YoParserNode * node)
{
	if (!ptrType || ptrType->etype != TYPE_PTR || !dynamic_cast<SubType*>(ptrType) || !((SubType*)ptrType)->subType) {
		setError(ERROR_TYPE, node, "Pointer type required");
		return NULL;
	}
	return ((SubType*)ptrType)->subType;
}

YoProgCompiler::Type * YoProgCompiler::unrefType(Type * refType, YoParserNode * node)
{
	if (!refType || refType->etype != TYPE_REF || !dynamic_cast<SubType*>(refType) || !((SubType*)refType)->subType) {
		setError(ERROR_TYPE, node ? node : refType->parserNode, "Reference type required");
		return NULL;
	}
	return ((SubType*)refType)->subType;
}

YoProgCompiler::Type * YoProgCompiler::ptrToRefType(Type * type, YoParserNode * node)
{
	type = unptrType(type, node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	return refType(type, node);
}

YoProgCompiler::Type * YoProgCompiler::refToPtrType(Type * type, YoParserNode * node)
{
	type = unrefType(type, node);
	if (!type) {
		YO_ASSERT(isError());
		return NULL;
	}
	return ptrType(type, node);
}

YoProgCompiler::Type * YoProgCompiler::subType(Type * ptrType, YoParserNode * node)
{
	if (!ptrType || !dynamic_cast<SubType*>(ptrType) || !((SubType*)ptrType)->subType) {
		setError(ERROR_TYPE, node, "SubType type required");
		return NULL;
	}
	return ((SubType*)ptrType)->subType;
}

YoProgCompiler::Type * YoProgCompiler::unmutType(Type * type, YoParserNode * node)
{
	if (!type || type->etype != TYPE_MUT || !dynamic_cast<SubType*>(type) || !((SubType*)type)->subType) {
		setError(ERROR_TYPE, node, "Mutable type required");
		return NULL;
	}
	return ((SubType*)type)->subType;
}

YoProgCompiler::Type * YoProgCompiler::unconstType(Type * type, YoParserNode * node)
{
	if (!type || type->etype != TYPE_CONST || !dynamic_cast<SubType*>(type) || !((SubType*)type)->subType) {
		setError(ERROR_TYPE, node, "Mutable type required");
		return NULL;
	}
	return ((SubType*)type)->subType;
}

YoProgCompiler::Type * YoProgCompiler::unarrayType(Type * type, YoParserNode * node)
{
	if (!type || type->etype != TYPE_ARRAY || !dynamic_cast<SubType*>(type) || !((SubType*)type)->subType) {
		setError(ERROR_TYPE, node, "Array type required");
		return NULL;
	}
	return ((SubType*)type)->subType;
}

YoProgCompiler::Operation * YoProgCompiler::newStructElementOp(Operation * op, int index, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	TypeAttrs typeAttrs;
	Type * type = baseType(op->type, typeAttrs);
	/* if (!(type && typeAttrs.isRef && typeAttrs.refCount == 1)) {
		int i = 0;
	} */
	YO_ASSERT(type && typeAttrs.isRef); // && typeAttrs.refCount == 1);
	if ((type->etype != TYPE_STRUCT && type->etype != TYPE_CLASS && type->etype != TYPE_FUNC_DATA) || !dynamic_cast<StructType*>(type)) {
		setError(ERROR_UNREACHABLE, node, "Struct pointer required");
		return NULL;
	}
	StructType * structType = (StructType*)type;
	if ((size_t)index >= structType->types.size()) {
		setError(ERROR_UNREACHABLE, node, "Error element index: %d", index);
		return NULL;
	}
	if (typeAttrs.refCount > 1) {
		op = indirectOf(addrOf(op, node), node);
		if (!op) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	typeAttrs.refCount = 1;
	Type * elemOpType = unbaseType(structType->types[index], typeAttrs);
	Operation * elemRef = newOperation(OP_STRUCT_ELEMENT, elemOpType, op, node);
	elemRef->structElementIndex = index;
	return elemRef;
}

YoProgCompiler::Operation * YoProgCompiler::compileSubFunc(Scope * scope, YoParserNode * node)
{
	Function * func = compileFunc(scope, node);
	if (!func) {
		YO_ASSERT(isError());
		return NULL;
	}
	return newFuncDataOp(scope, func, node);
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

	Variable * temp = allocTempValue(scope, type, node);
	Operation * resultOp = newVarOp(temp, node), * op;

	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.obj.values);

#if 1
	if (nodes.size() != structType->names.size()) {
		Operation * initZeroOp = newStoreOp(newOperation(OP_ZERO_VALUE, temp->type, node), temp, node);
		resultOp->ops.push_back(initZeroOp);
	}
	else{
		int i = 0;
	}
#else
	Operation * op = newOperation(OP_STACK_VALUE_MEMZERO, node);
	op->var = temp;
	resultOp->ops.push_back(op);
#endif

	int i;
	TypeAttrs typeAttrs, typeAttrs2;
	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (i = 0; it != nodes.rend(); ++it, ++i) {
		Type * dstType = structType->types[i];
		Operation * expr = compileValueOf(scope, *it);
		if (!expr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * tempOp = newVarOp(temp, node);
		Operation * dst = newStructElementOp(tempOp, i, node);
		if (!dst) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (baseType(expr->type, typeAttrs) != baseType(dstType, typeAttrs2)){
			expr = convertToType(scope, expr, dstType, CONVERT_AUTO, node);
			if (!expr) {
				return NULL;
			}
			op = newStoreOp(expr, dst, node);
		}
		else{
			if (expr->eop == OP_VAR && expr->var->isTemp) {
				YO_ASSERT(!expr->var->initVar);
				expr->var->initVar = temp;
				expr->var->initStructElementIndex = i;
			}
			op = newStoreOp(expr, dst, node);
		}
		resultOp->ops.push_back(op);
	}
	return resultOp;
}

YoProgCompiler::Operation * YoProgCompiler::compileNewArrExprs(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_NEW_ARR_EXPS);

	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.arr.values);

	// std::vector<Type*> nodeTypes;
	std::vector<Operation*> nodeOps;
	
	int i;
	Operation * op;
	bool allNumbers = true, sameTypes = true;
	Type * sameType = NULL, *numberType = NULL;
	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (; it != nodes.rend(); ++it) {
		op = compileOp(scope, *it);
		if (!op) {
			YO_ASSERT(isError());
			return NULL;
		}
		if (allNumbers && op->type->isNumber()) {
			if (!numberType) {
				numberType = op->type;
			}
			else{
				numberType = getBestNumType(numberType, op->type);
			}
		}
		else{
			allNumbers = false;
		}
		if (sameTypes) {
			if (sameType) {
				sameTypes = sameType == op->type;
			}
			sameType = op->type;
		}
		nodeOps.push_back(op);
	}
	if (allNumbers) {
		for (i = 0; i < (int)nodeOps.size(); i++) {
			op = convertToType(scope, valueOf(nodeOps[i], node), numberType, CONVERT_AUTO, node);
			if (!op) {
				YO_ASSERT(isError());
				return NULL;
			}
			nodeOps[i] = op;
		}
		Type * type = arrayType(nodeOps.size(), numberType, node);
		Variable * temp = allocTempValue(scope, type, node);
		Operation * resultOp = newVarOp(temp, node);
		for (i = 0; i < (int)nodeOps.size(); i++) {
			Operation * elemRefOp = newOperation(OP_ELEMENT, refType(numberType, node), node);
			elemRefOp->ops.push_back(newVarOp(temp, node));
			elemRefOp->ops.push_back(newConstIntOp(scope, i, node));
			resultOp->ops.push_back(newStoreOp(nodeOps[i], elemRefOp, node));
		}
		return resultOp;
	}
	if (sameTypes) {
		sameType = baseType(sameType);
		Type * type = arrayType(nodeOps.size(), sameType, node);
		Variable * temp = allocTempValue(scope, type, node);
		Operation * resultOp = newVarOp(temp, node);
		for (i = 0; i < (int)nodeOps.size(); i++) {
#if 0
			Operation * elemRefOp = newOperation(OP_ELEMENT, refType(sameType, node), node);
			elemRefOp->ops.push_back(newVarOp(temp, node));
			elemRefOp->ops.push_back(newConstIntOp(scope, i, node));
			elemRefOp->structElementIndex = i;
#else
			Operation * elemRefOp = newOperation(OP_STRUCT_ELEMENT, refType(sameType, node), node);
			elemRefOp->ops.push_back(newVarOp(temp, node));
			// elemRefOp->ops.push_back(newConstIntOp(scope, i, node));
			elemRefOp->structElementIndex = i;
#endif
			resultOp->ops.push_back(newStoreOp(nodeOps[i], elemRefOp, node));
		}
		return resultOp;
	}
	setError(ERROR_TYPE, node, "Different types in array");
	return NULL;
}

bool YoProgCompiler::optimizeScopePass1(Scope * scope)
{
	if (!scope) {
		return true;
	}
	if (scope->escope == SCOPE_FUNCTION) {
		YO_ASSERT(dynamic_cast<Function*>(scope));
		Function * func = (Function*)scope;
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
				op = newOperation(OP_RETURN, getType(TYPE_VOID), func->parserNode);
				func->ops.push_back(op);
				break;

			default:
				setError(ERROR_RETURN_REQUIRED, func->parserNode->data.func.end, "Return stmt required");
				return false;
			}
		}
	}
	int i;
	for (i = 0; i < (int)scope->ops.size(); i++) {
		Operation * subOp = optimizeOpPass1(scope, scope->ops[i]);
		if (!subOp) {
			YO_ASSERT(isError());
			return false;
		}
		scope->ops[i] = subOp;
	}
	for (i = (int)scope->vars.size() - 1; i >= 0; i--) {
		Variable * var = scope->vars[i];
		if (var->scope == scope) {
			Operation * op = newOperation(OP_END_VAR, NULL, var->parserNode);
			op->var = var;
			op = optimizeOpPass1(scope, op);
			YO_ASSERT(op);
			scope->ops.push_back(op);
		}
	}
	return true;
}

YoProgCompiler::Operation * YoProgCompiler::optimizeOpPass1(Scope * scope, Operation * op)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}

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

	Scope * curScope;
	switch (op->eop) {
	case OP_BEGIN_VAR:
		if (!op->var->isInitialized && !op->var->isTemp) {
			if (op->var->type->etype == TYPE_REF) {
				setError(ERROR_SYNTAX, op->parserNode, "Ref variable %s is not initialized", op->var->name.c_str());
				return NULL;
			}
			Operation * dstOp = newVarOp(op->var, op->parserNode);
			Operation * valueOp = newOperation(OP_ZERO_VALUE, op->var->type, op->parserNode);
			Operation * initOp = newAssignOp(scope, SPEC_INIT, dstOp, valueOp, OP_NOP, op->parserNode);
			initOp = optimizeOpPass1(scope, initOp);
			op->ops.push_back(initOp);
		}
		break;

	case OP_END_VAR:
		// TODO: destruct var
		break;

	// case OP_CASE:
	case OP_CASE_EXPR:
	case OP_CASE_LOGICAL:
	case OP_DEFAULT:
	case OP_FALLTHROUGH:
		for (curScope = scope; curScope; curScope = curScope->parent) {
			if (curScope->allowBreak || curScope->allowContinue || curScope->allowCase) {
				break;
			}
		}
		if (!curScope || !curScope->allowCase) {
			setError(ERROR_SYNTAX, op->parserNode, "Switch scope not found");
			return NULL;
		}
		break;

	case OP_BREAK:
		for (curScope = scope; curScope; curScope = curScope->parent) {
			if (curScope->allowBreak) {
				break;
			}
		}
		if (!curScope) {
			setError(ERROR_SYNTAX, op->parserNode, "Break scope not found");
			return NULL;
		}
		break;

	case OP_CONTINUE:
		for (curScope = scope; curScope; curScope = curScope->parent) {
			if (curScope->allowContinue) {
				break;
			}
		}
		if (!curScope) {
			setError(ERROR_SYNTAX, op->parserNode, "Continue scope not found");
			return NULL;
		}
		break;

	case OP_SCOPE:
		if (!optimizeScopePass1(op->scope)) {
			YO_ASSERT(isError());
			return NULL;
		}
		break;

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

	case OP_FOR:
		if (op->stmtFor.conditionOp) {
			subOp = optimizeOpPass1(scope, op->stmtFor.conditionOp);
			if (!subOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->stmtFor.conditionOp = subOp;
		}
		if (!optimizeScopePass1(op->stmtFor.bodyScope) || !optimizeScopePass1(op->stmtFor.stepScope)) {
			YO_ASSERT(isError());
			return NULL;
		}
		break;

	case OP_SWITCH_EXPR:
	case OP_SWITCH_LOGICAL:
		if (op->stmtSwitch.conditionOp) {
			subOp = optimizeOpPass1(scope, op->stmtSwitch.conditionOp);
			if (!subOp) {
				YO_ASSERT(isError());
				return NULL;
			}
			op->stmtSwitch.conditionOp = subOp;
		}
		if (!optimizeScopePass1(op->stmtSwitch.bodyScope)) {
			YO_ASSERT(isError());
			return NULL;
		}
		break;

	case OP_BIN_ADD:
	case OP_BIN_SUB:
	case OP_BIN_MUL:
	case OP_BIN_DIV:
	case OP_BIN_MOD:
	case OP_BIN_POW:
	// case OP_BIN_POWF:
	// case OP_BIN_POWI:
	case OP_CMP_EQ:
	case OP_CMP_NE:
	case OP_CMP_LE:
	case OP_CMP_GE:
	case OP_CMP_LT:
	case OP_CMP_GT:
	case OP_BIT_OR:
	case OP_BIT_AND:
	case OP_BIT_XOR:
	case OP_BIT_RSH:
	case OP_BIT_LSH:
	case OP_LOGICAL_OR:
	case OP_LOGICAL_AND:
		YO_ASSERT(op->ops.size() == 2);
		if (op->ops[0]->type->etype == TYPE_REF) {
			int i = 0;
		}
		if (op->ops[1]->type->etype == TYPE_REF) {
			int i = 0;
		}
		op->ops[0] = valueOf(op->ops[0], op->ops[0]->parserNode);
		op->ops[1] = valueOf(op->ops[1], op->ops[1]->parserNode);
		break;

	case OP_CAST_TRUNC:
	case OP_CAST_ZERO_EXT:
	case OP_CAST_SIGN_EXT:
	case OP_CAST_SI_TO_FP:
	case OP_CAST_UI_TO_FP:
	case OP_CAST_FP_TO_SI:
	case OP_CAST_FP_TO_UI:
	case OP_CAST_FP_TRUNC:
	case OP_CAST_FP_EXT:
	case OP_CAST_PTR_TO_INT:
	case OP_CAST_INT_TO_PTR:
		// case OP_CAST_PTR:
		YO_ASSERT(op->ops.size() == 1);
		if (op->ops[0]->type->etype == TYPE_REF) {
			int i = 0;
		}
		op->ops[0] = valueOf(op->ops[0], op->ops[0]->parserNode);
		break;

	case OP_LOAD:
		YO_ASSERT(op->ops.size() == 1);
		// YO_ASSERT(isLvalueOp(op->ops[0]));
		subOp = op->ops[0];
		YO_ASSERT(subOp->type->etype == TYPE_REF);
		if (subOp->eop == OP_VAR) {
			if (subOp->var->isArg) {
				subOp->var->isChanged = true;
			}
			subOp->var->isUsed = true;
		}
		/* else if (subOp->eop == OP_VAR && !subOp->var->isInitialized && !subOp->var->isTemp) {
			setError(ERROR_VAR_NOT_INITIALIZED, op->parserNode, "Read not initialized variable %s", op->ops[0]->var->name.c_str());
			return NULL;
		} */
		break;

	case OP_STORE: {
		YO_ASSERT(op->ops.size() == 2);
		YO_ASSERT(op->ops[1]->type->etype == TYPE_REF);
		TypeAttrs srcTypeAttrs, dstTypeAttrs;
		Type * srcValueType = baseType(op->ops[0]->type, srcTypeAttrs, 0);
		Type * dstValueType = baseType(op->ops[1]->type, dstTypeAttrs, 1);
		if (srcValueType == dstValueType && dstTypeAttrs.refCount == 1) {
			if (op->ops[0]->eop == OP_ZERO_VALUE) {
				if (op->ops[1]->eop == OP_VAR) {
					YoProgCompiler::Variable * var = op->ops[1]->var;
					if (var->initVar && var->initStructElementIndex >= 0) {
						return op->ops[1];
					}
				}
			}
			op->eop = OP_STORE_VALUE;
			break;
		}
		srcValueType = baseType(op->ops[0]->type, srcTypeAttrs, 1);
		dstValueType = baseType(op->ops[1]->type, dstTypeAttrs, 2);
		if (dstTypeAttrs.refCount == 2) {
			dstTypeAttrs.isMutable = false;
			dstTypeAttrs.refCount = 1;
			dstValueType = unbaseType(dstValueType, dstTypeAttrs);
		}
		if (srcValueType == dstValueType && srcTypeAttrs.refCount == 1 && dstTypeAttrs.refCount == 1) {
			op->eop = OP_STORE_REF;
			break;
		}
		srcValueType = baseType(op->ops[0]->type, srcTypeAttrs);
		dstValueType = baseType(op->ops[1]->type, dstTypeAttrs);
		if (srcValueType == dstValueType && dstTypeAttrs.refCount == srcTypeAttrs.refCount + 1) {
			op->eop = OP_STORE_VALUE;
			break;
		}
		setError(ERROR_UNREACHABLE, op->parserNode, "Error assign %s to %s", op->ops[1]->type->name.c_str(), op->ops[0]->type->name.c_str());
		// YO_ASSERT(false);
		return NULL;
	} // end case

	case OP_ZERO_VALUE:
	case OP_VAR:
	case OP_CAST_PTR:
	case OP_CONST_NULL:
	case OP_CONST_INT:
	case OP_CONST_FLOAT:
	case OP_CONST_STRING:
	case OP_FUNC:
	case OP_CALL_FUNC:
	case OP_RETURN:
		break;

	default:
		setError(ERROR_UNREACHABLE, op->parserNode, "Error op: %d", (int)op->eop);
		return NULL;
	} // end switch
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

	Variable * temp = allocTempValue(scope, type, node);
	Operation * resultOp = newVarOp(temp, node), * op;

#if 1
	// TODO: check if all fields are initialized so ZERO couldn't be needed
	Operation * initZeroOp = newStoreOp(newOperation(OP_ZERO_VALUE, temp->type, node), temp, node);
	resultOp->ops.push_back(initZeroOp);
#else
	Operation * op = newOperation(OP_STACK_VALUE_MEMZERO, node);
	op->var = temp;
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
		Operation * expr = compileValueOf(scope, propNode->data.assign.right);
		if (!expr) {
			YO_ASSERT(isError());
			return NULL;
		}
		Operation * tempOp = newVarOp(temp, node);
		Operation * dst = newStructElementOp(tempOp, i, node);
		if (!dst) {
			YO_ASSERT(isError());
			return NULL;
		}
		TypeAttrs typeAttrs;
		if (baseType(expr->type, typeAttrs) != dstType){
			// expr = getValue(scope, expr);
			expr = convertToType(scope, expr, dstType, CONVERT_AUTO, node);
			if (!expr) {
				return NULL;
			}
		}
		else if (expr->eop == OP_VAR && expr->var->isTemp) {
			YO_ASSERT(!expr->var->initVar);
			expr->var->initVar = temp;
			expr->var->initStructElementIndex = i;
		}
		op = newStoreOp(expr, dst, node);
		resultOp->ops.push_back(op);
	}
	return resultOp;
}

YoProgCompiler::Operation * YoProgCompiler::newAssignOp(Scope * scope, ESpecAssignRet spec, Operation * left, Operation * right, EOperation bin, YoParserNode * node)
{
	if (!left || !right) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (left->type->etype != TYPE_REF) {
		setError(ERROR_TYPE, left->parserNode, "Lvalue required");
		return NULL;
	}
	bool init = false;
	if (left->eop == OP_VAR) {
		YO_ASSERT(left->type && left->var && left->var->type && right->type);
		if (spec == SPEC_INIT) {
			left->var->isInitialized = init = true;
			left->var->isUsed = false;
		}
		else{
			/* if (spec != SPEC_ASSIGN && !left->var->isInitialized) {
				setError(ERROR_VAR_NOT_INITIALIZED, left->var->parserNode, "Read not initialized variable %s", left->var->name.c_str());
				return NULL;
			} */
			if (!isMutable(left->var->type)) {
				setError(ERROR_MUTABLE_REQUIRED, node, "Variable %s is not mutable", left->var->name.c_str());
				return NULL;
			}
			left->var->isChanged = true;
		}
		if (spec == SPEC_INIT || spec == SPEC_ASSIGN) {
			if (right->eop == OP_FUNC && left->var->type->etype == TYPE_UNKNOWN_YET) {
				FuncDataType * funcDataType = getFuncDataType(right->func->funcNativeType);
				right = convertToType(scope, right, funcDataType, CONVERT_AUTO, node);
			}
			if (left->type->isUnknownYet) {
				if (matchTypeTemplate(scope, left->var->type, right->type, init)) {
					if (left->var->type->etype == TYPE_VOID) {
						setError(ERROR_TYPE, left->var->parserNode, "Variable %s should not be void", left->var->name.c_str());
						return NULL;
					}
					left->type = refType(left->var->type, node);
				}
				else{
					setError(ERROR_TYPE, node, "Error to match type %s to %s", right->type->name.c_str(), left->var->type->name.c_str());
					return NULL;
				}
				YO_ASSERT(!left->type->isUnknownYet);
				/* if (left->type->isUnknownYet) {
				setError(ERROR_TYPE, left->var->parserNode, "Variable %s has unknown type", left->var->name.c_str());
				return NULL;
				} */
			}
		}
		if (left->type->isUnknownYet) {
			setError(ERROR_TYPE, left->var->parserNode, "Variable %s has unknown type", left->var->name.c_str());
			return NULL;
		}
		if (!left->var->isInitialized && left->var->type->etype == TYPE_REF) {
			setError(ERROR_SYNTAX, node, "Ref variable %s is not initialized", left->var->name.c_str());
			return NULL;
		}
	}
	if (!init) {
		left = refValueOf(left, node);
		right = valueOf(right, node);
	}
	TypeAttrs leftTypeAttrs;
	Type * leftValueType = baseType(left->type, leftTypeAttrs);
	if (!leftValueType) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (!init && (!leftTypeAttrs.isRef || !leftTypeAttrs.isMutable)) {
		setError(ERROR_MUTABLE_REQUIRED, left->parserNode, "Mutable value required, found %s", subType(left->type, NULL)->name.c_str());
		return NULL;
	}
	TypeAttrs rightTypeAttrs;
	Type * rightValueType = baseType(right->type, rightTypeAttrs);
	if (leftTypeAttrs.refCount != rightTypeAttrs.refCount + 1) {
		setError(ERROR_TYPE, node, "Error to assign %s to %s", right->type->name.c_str(), left->type->name.c_str());
		return NULL;
	}
	if (init && leftTypeAttrs.refCount > 1) {
		if (leftTypeAttrs.isMutable && !rightTypeAttrs.isMutable) {
			setError(ERROR_MUTABLE_REQUIRED, right->parserNode, "Mutable value required, found %s", right->type->name.c_str());
			return NULL;
		}
		if (right->eop == OP_VAR && right->var->isArg) {
			right->var->isChanged = true;
		}
	}
	if (rightValueType != leftValueType){
		right = convertToType(scope, right, leftValueType, CONVERT_AUTO, node);
		if (!right) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	if (spec == SPEC_INIT || spec == SPEC_ASSIGN) {
#if 0
		if (node->data.assign.op == T_INIT_ASSIGN && left->eop == OP_VAR && right->eop == OP_VAR && right->var->isTemp) {
			// YO_ASSERT(right->var->type == left->var->type || (allowRightAutoMutable && !isMutable(right->var->type)
			//	&& getMutType(right->var->type, node) == left->var->type));
			YO_ASSERT(left->ops.size() == 0);
			YO_ASSERT(!right->var->initVar);
			right->var->initVar = left->var;
		}
#endif
		return newStoreOp(right, left, node);
	}
	Variable * tempR = allocTempValue(scope, left->type, node);
	Operation * initTempOp = newStoreOp(left, tempR, node);

	Variable * tempV = allocTempValue(scope, leftValueType, node);
	Operation * saveOp = newStoreOp(valueOf(tempR, node), tempV, node);

	Operation * binOp = newOperation(bin, leftValueType, node);
	binOp->ops.push_back(valueOf(tempV, node));
	binOp->ops.push_back(right);

	Operation * assignOp = newStoreOp(binOp, refValueOf(tempR, node), node);
	if (spec == SPEC_POST) {
		Operation * resultOp = newVarOp(tempV, node);
		resultOp->ops.push_back(initTempOp);
		resultOp->ops.push_back(saveOp);
		resultOp->ops.push_back(assignOp);
		return valueOf(resultOp, node);
	}
	Operation * resultOp = newVarOp(tempR, node);
	resultOp->ops.push_back(initTempOp);
	resultOp->ops.push_back(saveOp);
	resultOp->ops.push_back(assignOp);
	return refValueOf(resultOp, node);
}

/*
YoProgCompiler::Operation * YoProgCompiler::newSpecAssignOp(Scope * scope, ESpecAssignRet spec, Operation * left, Operation * right, EOperation bin, YoParserNode * node)
{
	if (!left || !right) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (left->type->etype != TYPE_REF) {
		setError(ERROR_OP, left->parserNode, "Lvalue required");
		return NULL;
	}
	// TypeAttrs typeAttrs;
	// Type * valueType;
	// Variable * tempR, * tempV = NULL;
	// Operation *binOp, *assignOp, *initTempOp, *resultOp, *saveOp;
	switch (left->eop) {
	case OP_VAR:
		if (!left->var->isInitialized) {
			setError(ERROR_VAR_NOT_INITIALIZED, left->var->parserNode, "Read not initialized variable %s", left->var->name.c_str());
			return NULL;
		}
		if (!isMutable(left->var->type)) {
			setError(ERROR_MUTABLE_REQUIRED, node, "Variable %s is not mutable", left->var->name.c_str());
			return NULL;
		}
		if (left->type->isUnknownYet) {
			setError(ERROR_TYPE, left->var->parserNode, "Variable %s has unknown type", left->var->name.c_str());
			return NULL;
		}
		left->var->isChanged = true;
		break;

	// case OP_STRUCT_ELEMENT:
	// case OP_ELEMENT:
	// case OP_STORE:
	}
	bool init = false;
	if (!init) {
		left = refValueOf(left, node);
		right = valueOf(right, node);
	}
	TypeAttrs leftTypeAttrs;
	Type * leftValueType = baseType(left->type, leftTypeAttrs);
	if (!leftValueType) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (!init && (!leftTypeAttrs.isRef || !leftTypeAttrs.isMutable)) {
		setError(ERROR_MUTABLE_REQUIRED, left->parserNode, "Mutable value required, found %s", subType(left->type, NULL)->name.c_str());
		return NULL;
	}
	TypeAttrs rightTypeAttrs;
	Type * rightValueType = baseType(right->type, rightTypeAttrs);
	if (leftTypeAttrs.refCount != rightTypeAttrs.refCount + 1) {
		setError(ERROR_TYPE, node, "Error to assign %s to %s", right->type->name.c_str(), left->type->name.c_str());
		return NULL;
	}
	if (init && leftTypeAttrs.refCount > 1 && leftTypeAttrs.isMutable && !rightTypeAttrs.isMutable) {
		setError(ERROR_MUTABLE_REQUIRED, right->parserNode, "Mutable value required, found %s", right->type->name.c_str());
		return NULL;
	}
	right = convertToType(scope, right, leftValueType, CONVERT_AUTO, node);
	if (!right) {
		YO_ASSERT(isError());
		return NULL;
	}
	Variable * tempR = allocTempValue(scope, left->type, node);
	Operation * initTempOp = newStoreOp(left, tempR, node);

	Variable * tempV = allocTempValue(scope, leftValueType, node);
	Operation * saveOp = newStoreOp(valueOf(tempR, node), tempV, node);

	Operation * binOp = newOperation(bin, leftValueType, node);
	binOp->ops.push_back(valueOf(tempV, node));
	binOp->ops.push_back(right);

	// refOp = indirectOf(addrOf(loadValueOf(tempPP, node), node), node);
	Operation * assignOp = newStoreOp(binOp, refValueOf(tempR, node), node);

	if (spec == SPEC_POST) {
		Operation * resultOp = newVarOp(tempV, node);
		resultOp->ops.push_back(initTempOp);
		resultOp->ops.push_back(saveOp);
		resultOp->ops.push_back(assignOp);
		return valueOf(resultOp, node);
	}
	Operation * resultOp = newVarOp(tempR, node);
	resultOp->ops.push_back(initTempOp);
	resultOp->ops.push_back(saveOp);
	resultOp->ops.push_back(assignOp);
	// return loadValue(scope, loadValue(scope, resultOp, node), node);
	// return indirectOf(addrOf(resultOp, node), node);
	return refValueOf(resultOp, node);
}
*/

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
	switch (node->data.assign.op) {
	case T_PLUS_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_ADD, node);
	case T_MINUS_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_SUB, node);
	case T_MUL_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_MUL, node);
	case T_DIV_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_DIV, node);
	case T_MOD_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_MOD, node);
	case T_OR_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIT_OR, node);
	case T_AND_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIT_AND, node);
	case T_XOR_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIT_XOR, node);
	case T_RSH_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIT_RSH, node);
	case T_LSH_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIT_LSH, node);
	case T_POW_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_POW, node);
	// case T_CONCAT_ASSIGN: return newAssignOp(scope, SPEC_POST, left, right, OP_BIN_CONCAT, node);

	case T_INIT_ASSIGN: return newAssignOp(scope, SPEC_INIT, left, right, OP_NOP, node);
	case T_ASSIGN: return newAssignOp(scope, SPEC_ASSIGN, left, right, OP_NOP, node);
	}
#if 1
	setError(ERROR_UNREACHABLE, node, "Error assign op: %d", (int)node->data.assign.op);
	return NULL;
#else
	if (left->type->etype != TYPE_REF) {
		setError(ERROR_TYPE, left->parserNode, "Lvalue required");
		return NULL;
	}
	bool init = false;
	switch (left->eop) {
	case OP_VAR:
		if (node->data.assign.op == T_INIT_ASSIGN) {
			left->var->isInitialized = init = true;
			left->var->isUsed = false;
		}
		// else if (!left->var->isMutable) {
		else if (!isMutable(left->var->type)) {
			setError(ERROR_MUTABLE_REQUIRED, node, "Variable %s is not mutable", left->var->name.c_str());
			return NULL;
		}
		else{
			left->var->isChanged = true;
		}
		YO_ASSERT(left->type && left->var && left->var->type && right->type);
		if (right->eop == OP_FUNC && left->var->type->etype == TYPE_UNKNOWN_YET) {
			FuncDataType * funcDataType = getFuncDataType(right->func->funcNativeType);
			right = convertToType(scope, right, funcDataType, CONVERT_AUTO, node);
		}
		if (left->type->isUnknownYet) {
			TypeAttrs rightTypeAttrs;
			Type * rightType = right->type; // baseType(right->type, rightTypeAttrs, 1);
			// if (!isInitialized && !rightTypeAttrs.isMutable)
			if (matchTypeTemplate(scope, left->var->type, rightType, node->data.assign.op == T_INIT_ASSIGN)) {
				if (left->var->type->etype == TYPE_VOID) {
					setError(ERROR_TYPE, left->var->parserNode, "Variable %s should not be void", left->var->name.c_str());
					return NULL;
				}
				left->type = refType(left->var->type, node);
			}
			else{
				setError(ERROR_TYPE, node, "Error to match type %s to %s", rightType->name.c_str(), left->var->type->name.c_str());
				return NULL;
			}
			YO_ASSERT(!left->type->isUnknownYet);
		}
		if (!left->var->isInitialized && left->var->type->etype == TYPE_REF) {
			setError(ERROR_VAR_NOT_INITIALIZED, node, "Ref variable %s is not initialized", left->var->name.c_str());
			return NULL;
		}
		break;

	// case OP_STRUCT_ELEMENT:
	// case OP_ELEMENT:
	// case OP_STORE:
	}
	YO_ASSERT(node->data.assign.op == T_ASSIGN || node->data.assign.op == T_INIT_ASSIGN && left->eop == OP_VAR);
	if (!init) {
		left = refValueOf(left, node);
		right = valueOf(right, node);
	}
	TypeAttrs leftTypeAttrs;
	Type * leftValueType = baseType(left->type, leftTypeAttrs);
	if (!leftValueType) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (!init && (!leftTypeAttrs.isRef || !leftTypeAttrs.isMutable)) {
		setError(ERROR_MUTABLE_REQUIRED, left->parserNode, "Mutable value required, found %s", subType(left->type, NULL)->name.c_str());
		return NULL;
	}
	TypeAttrs rightTypeAttrs;
	Type * rightValueType = baseType(right->type, rightTypeAttrs);
	if (leftTypeAttrs.refCount != rightTypeAttrs.refCount + 1) {
		setError(ERROR_TYPE, node, "Error to assign %s to %s", right->type->name.c_str(), left->type->name.c_str());
		return NULL;
	}
	if (init && leftTypeAttrs.refCount > 1 && leftTypeAttrs.isMutable && !rightTypeAttrs.isMutable) {
		setError(ERROR_MUTABLE_REQUIRED, right->parserNode, "Mutable value required, found %s", right->type->name.c_str());
		return NULL;
	}
	if (rightValueType != leftValueType){
		right = convertToType(scope, right, leftValueType, CONVERT_AUTO, node);
		if (!right) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
#if 0
	if (node->data.assign.op == T_INIT_ASSIGN && left->eop == OP_VAR && right->eop == OP_VAR && right->var->isTemp) {
		// YO_ASSERT(right->var->type == left->var->type || (allowRightAutoMutable && !isMutable(right->var->type)
		//	&& getMutType(right->var->type, node) == left->var->type));
		YO_ASSERT(left->ops.size() == 0);
		YO_ASSERT(!right->var->initVar);
		right->var->initVar = left->var;
	}
#endif
	return newStoreOp(right, left, node);
#endif
}

YoProgCompiler::Operation * YoProgCompiler::compileIndexOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP && node->data.binOp.op == T_INDEX);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);

	Operation * left = compileOp(scope, node->data.binOp.left);
	Operation * right = compileValueOf(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	/* if (!left->type) {
		setError(ERROR_TYPE_UNKNOWN, left->parserNode, "Type unknown");
		return NULL;
	}
	if (!right->type) {
		setError(ERROR_TYPE_UNKNOWN, right->parserNode, "Type unknown");
		return NULL;
	} */
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
			return newOperation(OP_TYPE, subType, node);
		}
		setError(ERROR_TYPE, right->parserNode, "Integer type required");
		return NULL;
	}
	TypeAttrs leftTypeAttrs;
	Type * leftValueType = baseType(left->type, leftTypeAttrs);
	/* if (!leftValueType) {
		return NULL;
	} */
	switch (leftValueType->etype) {
	case TYPE_ARRAY:
		YO_ASSERT(dynamic_cast<ArrayType*>(leftValueType));
		if (getIntBits(right->type, bits, isSigned)) {
			Operation * op = newOperation(OP_ELEMENT, refType(((ArrayType*)leftValueType)->subType, node), node);
			/* if (left->eop == OP_VAR && left->var->isArg && !left->var->isChanged) {
				left->var->isChanged = true;
			} */
			op->ops.push_back(refValueOf(left, node));
			op->ops.push_back(right);
			return op;
		}
		setError(ERROR_TYPE, right->parserNode, "Integer type required");
		return NULL;
	}
	setError(ERROR_UNREACHABLE, left->parserNode, "Not supported type %s for index", leftValueType->name.c_str());
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
		setError(ERROR_UNREACHABLE, node, "Error logical op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileOp(scope, node->data.binOp.left);
	Operation * right = compileOp(scope, node->data.binOp.right);
	
	left = convertToType(scope, left, getType(TYPE_BOOL), CONVERT_AUTO, node);
	right = convertToType(scope, right, getType(TYPE_BOOL), CONVERT_AUTO, node);
	
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	Operation * op = newOperation(eop, getType(TYPE_BOOL), node);
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
		setError(ERROR_UNREACHABLE, node, "Error compare op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileValueOf(scope, node->data.binOp.left);
	Operation * right = compileValueOf(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	// TypeAttrs leftTypeAttrs, rightTypeAttrs;
	Type * leftType = left->type; //  baseType(left->type, leftTypeAttrs);
	Type * rightType = right->type; //  baseType(right->type, rightTypeAttrs);
	if (leftType != rightType) {
		Type * resType = getBestNumType(leftType, rightType);
		if (resType) {
			Operation * newLeft = convertToType(scope, left, resType, CONVERT_BY_HAND, node);
			Operation * newRight = convertToType(scope, right, resType, CONVERT_BY_HAND, node);
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
	Operation * op = newOperation(eop, getType(TYPE_BOOL), node);
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::compilePowOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_BIN_OP && node->data.binOp.op == T_POW);
	YO_ASSERT(node->data.binOp.left && node->data.binOp.right);

	Operation * left = compileValueOf(scope, node->data.binOp.left);
	Operation * right = compileValueOf(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	int bits;
	bool isSigned;
	if (getIntBits(left->type, bits, isSigned)) {
		left = convertToType(scope, left, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
		if (!left) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	else if (!left->type->isFloat()) {
		setError(ERROR_TYPE, left->parserNode, "Number required");
		return NULL;
	}
	// EOperation eop = OP_BIN_POWF;
	if (getIntBits(right->type, bits, isSigned)) {
#if 1
		right = convertToType(scope, right, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
#else
		eop = OP_BIN_POWI;
		right = convertToType(scope, right, getType(TYPE_INT32), CONVERT_AUTO, node);
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
		left = convertToType(scope, left, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
		right = convertToType(scope, right, getType(TYPE_FLOAT64), CONVERT_AUTO, node);
		if (!left || !right) {
			YO_ASSERT(isError());
			return NULL;
		}
	}
	EOperation eop = OP_BIN_POW;
	Operation * op = newOperation(eop, left->type, node);
	op->ops.push_back(left);
	op->ops.push_back(right);
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::addrOf(Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (op->eop == OP_LOAD) {
		YO_ASSERT(op->ops.size() == 1);
		op = op->ops[0];
	}
	if (op->type->etype == TYPE_REF) {
		if (unrefType(op->type, node)->etype == TYPE_REF) {
			return addrOf(valueOf(op, node), node);
		}
		op->type = refToPtrType(op->type, node);
		YO_ASSERT(op->type);
		return op;
	}
	setError(ERROR_TYPE, node, "Reference required");
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::indirectOf(Operation * op, YoParserNode * node)
{
	op = valueOf(op, node);
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	Type * type = op->type;
	if (type->etype == TYPE_MUT) {
		type = unmutType(type, node);
		YO_ASSERT(type);
	}
	if (type->etype == TYPE_PTR) {
		op->type = ptrToRefType(type, node);
		YO_ASSERT(op->type);
		return op;
	}
	setError(ERROR_TYPE, node, "Pointer required");
	return NULL;
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
		return newAssignOp(scope, SPEC_POST, op, valueOp, node->data.postUnaryOp.op == T_INC ? OP_BIN_ADD : OP_BIN_SUB, node);
	}
	setError(ERROR_UNREACHABLE, node, "Error post unary op: %d", (int)node->data.postUnaryOp.op);
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::compileUnaryOp(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_UNARY_OP);
	YO_ASSERT(node->data.unaryOp.node);
	Type * valueType;
	TypeAttrs typeAttrs;
	Operation * op, * valueOp, * binOp;
	int bits; bool isSigned;
	switch (node->data.unaryOp.op) {
	case T_INC:
	case T_DEC:
		op = compileOp(scope, node->data.unaryOp.node);
		valueOp = newConstIntOp(scope, 1, node);
		return newAssignOp(scope, SPEC_PRE, op, valueOp, node->data.unaryOp.op == T_INC ? OP_BIN_ADD : OP_BIN_SUB, node);

	case T_NOT:
		op = compileOp(scope, node->data.unaryOp.node);
		op = convertToType(scope, op, getType(TYPE_BOOL), CONVERT_AUTO, node);
		if (!op) {
			YO_ASSERT(isError());
			return NULL;
		}
		binOp = newOperation(OP_BIT_XOR, op->type, node);
		valueOp = convertToType(scope, newConstIntOp(scope, 1, node), op->type, CONVERT_BY_HAND, node);
		YO_ASSERT(valueOp);
		binOp->ops.push_back(valueOp);
		binOp->ops.push_back(op);
		return binOp;

	case T_PLUS:
	case T_MINUS:
	case T_TILDE:
		op = compileOp(scope, node->data.unaryOp.node);
		valueType = baseType(op->type, typeAttrs);
		if (valueType->isNumber()) {
			switch (node->data.unaryOp.op) {
			case T_PLUS:
				// nothing to do with number
				return valueOf(op, node);

			case T_MINUS:
				binOp = newOperation(OP_BIN_SUB, valueType, node);
				valueOp = convertToType(scope, newConstFloatOp(scope, 0, node), valueType, CONVERT_BY_HAND, node);
				YO_ASSERT(valueOp);
				binOp->ops.push_back(valueOp);
				binOp->ops.push_back(valueOf(op, node));
				return binOp;

			case T_TILDE:
				if (getIntBits(valueType, bits, isSigned)) {
					binOp = newOperation(OP_BIT_XOR, valueType, node);
					valueOp = convertToType(scope, newConstIntOp(scope, ~0, node), valueType, CONVERT_BY_HAND, node);
					YO_ASSERT(valueOp);
					binOp->ops.push_back(valueOp);
					binOp->ops.push_back(valueOf(op, node));
					return binOp;
				}
				setError(ERROR_TYPE, node, "Integer required");
				return NULL;
			}
		}
		setError(ERROR_TYPE, node, "Number required");
		return NULL;

	case T_ADDR:
		return addrOf(compileOp(scope, node->data.unaryOp.node), node);

	case T_INDIRECT:
		return indirectOf(compileOp(scope, node->data.unaryOp.node), node);
	}
	setError(ERROR_UNREACHABLE, node, "Error unary op: %d", (int)node->data.unaryOp.op);
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
	case T_RSH:
	case T_LSH:
		return compileBitOp(scope, node);

	default:
		setError(ERROR_UNREACHABLE, node, "Error bin op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileValueOf(scope, node->data.binOp.left);
	Operation * right = compileValueOf(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	// bool isLeftMutable = false, isRightMutable = false;
	Type * leftType = left->type; // removeMut(left->type, isLeftMutable);
	Type * rightType = right->type; // removeMut(right->type, isRightMutable);
	if (leftType != rightType) {
		if (leftType->isPtr() && rightType->isInt()) {
			if (eop == OP_BIN_ADD || eop == OP_BIN_SUB) {
				Operation * newLeft = convertToType(scope, left, getIntType(sizeof(void*)*8, false), CONVERT_BY_HAND, node);
				Operation * newRight = convertToType(scope, right, newLeft->type, CONVERT_BY_HAND, node);
				if (!newLeft || !newRight) {
					YO_ASSERT(isError());
					return NULL;
				}
				Type * elemType = subType(leftType, node);
				if (leftType->etype == TYPE_MUT || leftType->etype == TYPE_CONST) {
					YO_ASSERT(elemType->etype == TYPE_PTR);
					elemType = subType(elemType, node);
				}
				Operation * mulOp = newOperation(OP_BIN_MUL, newLeft->type, node);
				mulOp->ops.push_back(newRight);
				mulOp->ops.push_back(newOperation(OP_SIZEOF, newLeft->type, newOperation(OP_TYPE, elemType, node), node));

				Operation * offsOp = newOperation(eop, newLeft->type, node);
				offsOp->ops.push_back(newLeft);
				offsOp->ops.push_back(mulOp);

				return convertToType(scope, offsOp, leftType, CONVERT_BY_HAND, node);
			}
		}
		Type * resType = getBestNumType(leftType, rightType);
		if (resType) {
			Operation * newLeft = convertToType(scope, left, resType, CONVERT_BY_HAND, node);
			Operation * newRight = convertToType(scope, right, resType, CONVERT_BY_HAND, node);
			if (!newLeft || !newRight) {
				YO_ASSERT(isError());
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
	Operation * op = newOperation(eop, leftType, node);
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
	case T_RSH: eop = OP_BIT_RSH; break;
	case T_LSH: eop = OP_BIT_LSH; break;

	default:
		setError(ERROR_UNREACHABLE, node, "Error bit op: %d", (int)node->data.binOp.op);
		return NULL;
	}
	Operation * left = compileValueOf(scope, node->data.binOp.left);
	Operation * right = compileValueOf(scope, node->data.binOp.right);
	if (!left || !right) {
		return NULL;
	}
	YO_ASSERT(left->type && right->type);
	// bool isLeftMutable = false, isRightMutable = false;
	Type * leftType = left->type; // removeMut(left->type, isLeftMutable);
	Type * rightType = right->type; // removeMut(right->type, isRightMutable);
	int bits;
	bool isSigned;
	Type * resType = getBestNumType(leftType, rightType);
	if (resType && getIntBits(resType, bits, isSigned)) {
		Operation * newLeft = convertToType(scope, left, resType, CONVERT_BY_HAND, node);
		Operation * newRight = convertToType(scope, right, resType, CONVERT_BY_HAND, node);
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
	Operation * op = newOperation(eop, leftType, node);
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
	if (lt->etype == TYPE_CONST) {
		lt = subType(lt, lt->parserNode);
	}
	if (rt->etype == TYPE_CONST) {
		rt = subType(rt, rt->parserNode);
	}
	if (rt->etype == TYPE_UNKNOWN_YET) {
		YO_ASSERT(false);
		return false;
	}
	if (lt->etype == TYPE_UNKNOWN_YET) {
		a = b;
		return true;
	}
	if (lt->etype == TYPE_MUT) { // && init) {
		lt = subType(lt, lt->parserNode);
		if (matchTypeTemplate(scope, lt, rt, false)) {
			a = mutType(lt, a->parserNode);
			return true;
		}
		return false;
	}
	if (rt->etype == TYPE_MUT) {
		rt = subType(rt, rt->parserNode);
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
		if (matchTypeTemplate(scope, lt, rt, false)) {
			a = arrayType(la->size, lt, a->parserNode);
			return true;
		}
		return false;
	}
	if (lt->etype == TYPE_REF) {
		lt = unrefType(lt, lt->parserNode), rt = unrefType(rt, rt->parserNode);
		if (matchTypeTemplate(scope, lt, rt, false)) {
			a = refType(lt, a->parserNode);
			return true;
		}
		return false;
	}
	if (lt->etype == TYPE_PTR) {
		lt = unptrType(lt, lt->parserNode), rt = unptrType(rt, rt->parserNode);
		if (matchTypeTemplate(scope, lt, rt, false)) {
			a = ptrType(lt, a->parserNode);
			return true;
		}
		return false;
	}
	return false;
}

bool YoProgCompiler::compileStmtFor(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_FOR);

	// for stmt could have local vars so create scope for
	Scope * varScope = new Scope(scope, SCOPE_BLOCK, "varScope", node);
	YO_ASSERT(varScope);
	varScope->allowBreak = true;
	varScope->allowContinue = true;

	if (!compileScopeBody(varScope, node->data.stmtFor.init)) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * conditionOp = NULL;
	if (node->data.stmtFor.condition) {
		conditionOp = compileOp(varScope, node->data.stmtFor.condition);
		conditionOp = convertToType(varScope, conditionOp, getType(TYPE_BOOL), CONVERT_AUTO, node->data.stmtFor.condition);
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

	Operation * forOp = newOperation(OP_FOR, NULL, node);
	forOp->stmtFor.conditionOp = conditionOp;
	forOp->stmtFor.bodyScope = bodyScope;
	forOp->stmtFor.stepScope = stepScope;
	varScope->ops.push_back(forOp);

	Operation * varScopeOp = newOperation(OP_SCOPE, NULL, node);
	varScopeOp->scope = varScope;
	return addStmt(scope, varScopeOp);
}

bool YoProgCompiler::compileStmtBreak(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_BREAK);
	Operation * op = newOperation(node->data.stmtBreak.op == T_BREAK ? OP_BREAK : OP_CONTINUE, NULL, node);
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
	conditionOp = convertToType(varScope, conditionOp, getType(TYPE_BOOL), CONVERT_AUTO, node->data.stmtIf.ifExpr);
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

	Operation * ifOp = newOperation(OP_IF, NULL, node);
	ifOp->stmtIf.conditionOp = conditionOp;
	ifOp->stmtIf.thenScope = thenScope;
	ifOp->stmtIf.elseScope = elseScope;
	varScope->ops.push_back(ifOp);

	Operation * varScopeOp = newOperation(OP_SCOPE, NULL, node);
	varScopeOp->scope = varScope;
	return addStmt(scope, varScopeOp);
}

bool YoProgCompiler::compileStmtSwitch(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_SWITCH);

	// if stmt could have local vars so create scope for
	Scope * varScope = new Scope(scope, SCOPE_BLOCK, "varScope", node);
	YO_ASSERT(varScope);
	varScope->allowBreak = true;
	varScope->allowCase = true;

	Operation * conditionOp = NULL;
	if (node->data.stmtSwitch.condition) {
		conditionOp = compileOp(varScope, node->data.stmtSwitch.condition);
		if (!conditionOp) {
			YO_ASSERT(isError());
			return false;
		}
	}
	if (!node->data.stmtSwitch.body) {
		setError(ERROR_SYNTAX, node, "Switch body required");
		return false;
	}
	Scope * bodyScope = new Scope(varScope, SCOPE_BLOCK, "body", node->data.stmtSwitch.body);
	YO_ASSERT(bodyScope);
	if (!compileScopeBody(bodyScope, node->data.stmtSwitch.body)) {
		YO_ASSERT(isError());
		return false;
	}
	if (bodyScope->ops.size() == 0) {
		setError(ERROR_SYNTAX, node, "Switch body required");
		return false;
	}
	Operation * op = bodyScope->ops[0];
	if (op->eop != OP_CASE && op->eop != OP_DEFAULT) {
		setError(ERROR_SYNTAX, op->parserNode, "Switch body requires the first 'case' or 'default' statement");
		return false;
	}
	
	Operation * switchOp = newOperation(conditionOp ? OP_SWITCH_EXPR : OP_SWITCH_LOGICAL, NULL, node);
	switchOp->stmtSwitch.conditionOp = conditionOp;
	switchOp->stmtSwitch.bodyScope = bodyScope;
	varScope->ops.push_back(switchOp);

	Type * resNumType = NULL;
	for (int i = 0; i < (int)bodyScope->ops.size(); i++) {
		op = bodyScope->ops[i];
		if (op->eop == OP_FALLTHROUGH) {
			if (i + 1 < (int)bodyScope->ops.size()) {
				op = bodyScope->ops[i + 1];
				if (op->eop != OP_CASE && op->eop != OP_DEFAULT) {
					setError(ERROR_SYNTAX, op->parserNode, "Fallthrough requires 'case' or 'default' statement after");
					return false;
				}
			}
		}
		else if (op->eop == OP_DEFAULT) {
			if (i > 0) {
				Operation * prevOp = bodyScope->ops[i - 1];
				if (prevOp->eop != OP_FALLTHROUGH) {
					Operation * breakOp = newOperation(OP_BREAK, NULL, op->parserNode);
					bodyScope->ops.insert(bodyScope->ops.begin() + i, breakOp);
					i++;
				}
			}
		}
		else if (op->eop == OP_CASE) { // || op->eop == OP_DEFAULT) {
			if (i > 0) {
				Operation * prevOp = bodyScope->ops[i - 1];
				if (prevOp->eop != OP_FALLTHROUGH) {
					Operation * breakOp = newOperation(OP_BREAK, NULL, op->parserNode);
					bodyScope->ops.insert(bodyScope->ops.begin() + i, breakOp);
					i++;
				}
			}
			if (!conditionOp) {
				Operation * summary = NULL;
				YO_ASSERT(op->ops.size());
				for (int j = 0; j < (int)op->ops.size(); j++) {
					Operation * right = convertToType(varScope, op->ops[j], getType(TYPE_BOOL), CONVERT_AUTO, op->ops[j]->parserNode);
					if (!right) {
						YO_ASSERT(isError());
						return false;
					}
					if (!summary) {
						summary = right;
					}
					else{
						summary = newOperation(OP_LOGICAL_OR, getType(TYPE_BOOL), summary, op->ops[j]->parserNode);
						summary->ops.push_back(right);
					}
				}
				YO_ASSERT(summary);
				op->ops.clear();
				op->ops.push_back(summary);
				op->eop = OP_CASE_LOGICAL;
				switchOp->ops.push_back(op);
			}
			else{
				YO_ASSERT(op->ops.size());
				for (int j = 0; j < (int)op->ops.size(); j++) {
					Operation * cur = op->ops[j];
					Type * leftType = resNumType ? resNumType : conditionOp->type;
					resNumType = getBestNumType(leftType, cur->type);
					if (!resNumType) {
						setError(ERROR_TYPE, cur->parserNode, "Error types for compare, left: %s, right: %s", leftType->name.c_str(), cur->type->name.c_str());
						return NULL;
					}
				}
				op->eop = OP_CASE_EXPR;
				switchOp->ops.push_back(op);
			}
		}
	}
	if (conditionOp) {
		YO_ASSERT(resNumType);
		conditionOp = convertToType(varScope, conditionOp, resNumType, CONVERT_AUTO, conditionOp->parserNode);
		if (!conditionOp) {
			YO_ASSERT(isError());
			return false;
		}
		Variable * tempVar = allocTempValue(varScope, resNumType, conditionOp->parserNode);
		Operation * storeOp = newStoreOp(conditionOp, tempVar, conditionOp->parserNode);
		conditionOp = newVarOp(tempVar, tempVar->parserNode);
		conditionOp->ops.push_back(storeOp);
		switchOp->stmtSwitch.conditionOp = conditionOp;

		for (int j, i = 0; i < (int)switchOp->ops.size(); i++) {
			Operation * caseOp = switchOp->ops[i];
			YO_ASSERT(caseOp->eop == OP_CASE_EXPR);
			int count = (int)caseOp->ops.size();
			for (j = 0; j < count; j++) {
				Operation * cur = convertToType(varScope, caseOp->ops[j], resNumType, CONVERT_AUTO, conditionOp->parserNode);
				if (!cur) {
					YO_ASSERT(isError());
					return false;
				}
				caseOp->ops[j] = cur;
			}
			for (j = 0; j < count; j++) {
				Operation * cmpOp = newOperation(OP_CMP_EQ, getType(TYPE_BOOL), caseOp->ops[j]->parserNode);
				cmpOp->ops.push_back(valueOf(tempVar, tempVar->parserNode));
				cmpOp->ops.push_back(caseOp->ops[j]);
				caseOp->ops.push_back(cmpOp);
			}
		}
	}

	Operation * varScopeOp = newOperation(OP_SCOPE, NULL, node);
	varScopeOp->scope = varScope;
	return addStmt(scope, varScopeOp);
}

bool YoProgCompiler::compileStmtCase(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_CASE);
	Operation * op = newOperation(OP_CASE, NULL, node);

	std::vector<YoParserNode*> nodes;
	collectNodesInReversList(nodes, node->data.stmtCase.expr);

	std::vector<YoParserNode*>::reverse_iterator it = nodes.rbegin();
	for (; it != nodes.rend(); ++it) {
		YoParserNode * exprNode = *it;
		Operation * exprOp = compileOp(scope, exprNode);
		if (!exprOp) {
			YO_ASSERT(isError());
			return false;
		}
		op->ops.push_back(exprOp);
	}

	return addStmt(scope, op);
}

bool YoProgCompiler::compileStmtDefault(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_DEFAULT);
	Operation * op = newOperation(OP_DEFAULT, NULL, node);
	return addStmt(scope, op);
}

bool YoProgCompiler::compileStmtFallThrough(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_FALLTHROUGH);
	Operation * op = newOperation(OP_FALLTHROUGH, NULL, node);
	return addStmt(scope, op);
}

bool YoProgCompiler::compileStmtReturn(Scope * scope, YoParserNode * node)
{
	YO_ASSERT(node && node->type == YO_NODE_STMT_RETURN);
	Operation * op = newOperation(OP_RETURN, NULL, node);
	if (node->data.stmtReturn.node) {
		Operation * value = compileOp(scope, node->data.stmtReturn.node);
		if (!value) {
			YO_ASSERT(isError());
			return false;
		}
		Function * func = getFunction(scope);
		if (matchTypeTemplate(scope, func->funcNativeType->resType, value->type, false)) {
			updateFuncNativeType(func->funcNativeType);
		}
		else {
			if (value->eop == OP_VAR && func->funcNativeType->resType->etype == TYPE_REF) {
				if (!value->var->isArg || value->var->type->etype != TYPE_REF) {
					setError(ERROR_CONVERT_TO_TYPE, value->parserNode, "Error return local as ref: %s to %s", 
						value->type->name.c_str(), func->funcNativeType->resType->name.c_str());
					return NULL;
				}
			}
			value = convertToType(scope, value, func->funcNativeType->resType, CONVERT_AUTO, node);
			if (!value) {
				return false;
			}
		}
		op->ops.push_back(value);
		op->type = value->type;
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

int YoProgCompiler::getCastKey(EType from, EType to)
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
		// YO_ASSERT(false);
		return getIntBits(subType(type, NULL), bits, isSigned);
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
		// YO_ASSERT(false);
		return getFloatBits(subType(type, NULL), bits);
	}
	return false;
}

YoProgCompiler::Type * YoProgCompiler::getBestNumType(Type * a, Type * b)
{
	a = baseType(a);
	b = baseType(b);
	if (a == b) {
		return a;
	}
	int key = getCastKey(a->etype, b->etype);
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
	YO_ASSERT(baseType(from) == from && baseType(to) == to);
	int key = getCastKey(from->etype, to->etype);
	std::map<int, CastOp>::iterator it = castOps.find(key);
	if (it != castOps.end()) {
		return it->second;
	}
	if (from->isPtr() && to->isInt()) {
		return castOps[key] = CastOp(to->etype, OP_CAST_PTR_TO_INT, CAST_BY_HAND);
	}
	if (from->isInt() && to->isPtr()) {
		return castOps[key] = CastOp(to->etype, OP_CAST_INT_TO_PTR, CAST_BY_HAND);
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
bool YoProgCompiler::isLvalueOp(Operation * op)
{
	YO_ASSERT(op && op->type);
	if (!op) {
		return false;
	}
	if (op->type->etype == TYPE_REF) {
#ifdef YO_DEBUG
		switch (op->eop) {
		case OP_VAR:
		case OP_STRUCT_ELEMENT:
		case OP_ELEMENT:
		case OP_STORE:
			break;

		default:
			YO_ASSERT(false);
		}
#endif
		return true;
	}
	return false;
}
*/

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

YoProgCompiler::Type * YoProgCompiler::baseType(Type * type)
{
	TypeAttrs attrs;
	return baseType(type, attrs);
}

YoProgCompiler::Type * YoProgCompiler::baseType(Type * type, TypeAttrs& attrs, int maxRefCount)
{
	YO_ASSERT(type);
	/*
	switch (op->eop) {
	case OP_STACK_VALUE_PTR:
	case OP_STRUCT_ELEMENT_PTR:
	case OP_ELEMENT_PTR:
	case OP_STORE_VALUE:
	case OP_STORE_PTR:
		return getPtrOrRefSubType(op->type);
	}
	return op->type;
	*/
	attrs.isRef = false;
	attrs.refCount = 0;
	for (int i = 0; i < maxRefCount && type->etype == TYPE_REF; i++) {
		attrs.isRef = true;
		attrs.refCount++;
		type = unrefType(type, type->parserNode);
	}
	attrs.isMutable = false;
	if (type->etype == TYPE_MUT) {
		attrs.isMutable = true;
		type = unmutType(type, type->parserNode);
	}
	else if (type->etype == TYPE_CONST) {
		type = unconstType(type, type->parserNode);
	}
	return type;
}

YoProgCompiler::Type * YoProgCompiler::unbaseType(Type * type, TypeAttrs& attrs)
{
	YO_ASSERT(type);
	if (attrs.isMutable) {
		type = mutType(type, type->parserNode);
	}
	for (int i = 0; i < attrs.refCount; i++) {
		type = refType(type, type->parserNode);
	}
	return type;
}

/*
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
*/

YoProgCompiler::Operation * YoProgCompiler::valueOf(Variable * var, YoParserNode * node)
{
	return valueOf(newVarOp(var, node), node);
}

/* YoProgCompiler::Operation * YoProgCompiler::loadValueOf(Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (op->type->etype != TYPE_REF) {
		setError(ERROR_TYPE, node, "Reference type required");
		return NULL;
	}
	return valueOf(op, node);
} */

YoProgCompiler::Operation * YoProgCompiler::valueOf(Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	Type * valueType = op->type;
	while (valueType->etype == TYPE_REF) {
		valueType = unrefType(op->type, node);
		if (!valueType) {
			YO_ASSERT(isError());
			return NULL;
		}
		op = newOperation(OP_LOAD, valueType, op, node);
	}
	return op;
}

YoProgCompiler::Operation * YoProgCompiler::refValueOf(Variable * var, YoParserNode * node)
{
	return refValueOf(newVarOp(var, node), node);
}

YoProgCompiler::Operation * YoProgCompiler::refValueOf(Operation * op, YoParserNode * node)
{
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	if (op->type->etype != TYPE_REF) {
		setError(ERROR_TYPE, node, "Reference type required");
		return NULL;
	}
	YO_ASSERT(dynamic_cast<SubType*>(op->type));
	SubType * valueType = (SubType*)op->type;
	while (valueType->subType->etype == TYPE_REF) {
		YO_ASSERT(dynamic_cast<SubType*>(valueType->subType));
		valueType = (SubType*)valueType->subType;
		op = newOperation(OP_LOAD, valueType, op, node);
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
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Pointers required to convert: %s to %s", op->type->name.c_str(), type->name.c_str());
		return NULL;
	}
	/*
	Operation * convertOp = newOperation(OP_CAST_PTR, node);
	convertOp->type = type;
	convertOp->ops.push_back(op);
	return convertOp;
	*/
	return convertToType(scope, op, type, CONVERT_BY_HAND, node);
}

YoProgCompiler::Operation * YoProgCompiler::convertArgToType(Scope * scope, Operation * op, Type * type, bool isExtern, YoParserNode * node)
{
	if (type) {
		op = convertToType(scope, op, type, CONVERT_AUTO, node);
	}
	else{
		op = valueOf(op, node);
	}
	if (!op) {
		YO_ASSERT(isError());
		return NULL;
	}
	bool isVarArg = type == NULL;
	TypeAttrs typeAttrs;
	type = baseType(op->type, typeAttrs);
	switch (type->etype) {
	case TYPE_INT8:
	case TYPE_INT16:
	case TYPE_INT32:
		if (isVarArg || isExtern) {
			return convertToType(scope, op, getIntType(true), CONVERT_BY_HAND, node);
		}
		// no break
	case TYPE_INT64:
		return op;

	case TYPE_BOOL:
	case TYPE_UINT8:
	case TYPE_UINT16:
	case TYPE_UINT32:
		if (isVarArg || isExtern) {
			return convertToType(scope, op, getIntType(false), CONVERT_BY_HAND, node);
		}
		// no break
	case TYPE_UINT64:
		return op;

	case TYPE_FLOAT64:
	case TYPE_PTR:
		return op;

	case TYPE_REF:
		YO_ASSERT(false);
		return op;

	case TYPE_ARRAY:
		if (isVarArg || isExtern) {
			return convertToType(scope, op, ptrType(unarrayType(type, node), node), CONVERT_BY_HAND, node);
		}
		return op;

	case TYPE_FLOAT32:
		if (isExtern) {
			return convertToType(scope, op, getType(TYPE_FLOAT64), CONVERT_BY_HAND, node);
		}
		return op;

	case TYPE_STRUCT:
	case TYPE_CLASS:
		return op;
	}
	setError(ERROR_TYPE, op->parserNode, "Error %stype %s", isExtern ? "extern " : "", type->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::convertToType(Scope * scope, Operation * op, Type * dstType, EConvertType convertType, YoParserNode * node)
{
	if (!op || !dstType) {
		YO_ASSERT(isError());
		return NULL;
	}
	YO_ASSERT(op->type && dstType);
	if (op->type == dstType) {
		return op;
	}
	TypeAttrs srcTypeAttrs, dstTypeAttrs;
	if (dstType->etype == TYPE_REF) {
		if (op->type->etype == TYPE_REF) {
			op = refValueOf(op, node);
			Type * dstBaseType = baseType(dstType, dstTypeAttrs);
			Type * srcBaseType = baseType(op->type, srcTypeAttrs, dstTypeAttrs.refCount);
			if (convertType == CONVERT_BY_HAND && srcTypeAttrs.refCount == dstTypeAttrs.refCount) {
				return newOperation(OP_CAST_PTR, dstType, op, node);
			}
			if (srcBaseType == dstBaseType && srcTypeAttrs.refCount == dstTypeAttrs.refCount) {
				// if (!dstTypeAttrs.isMutable || (op->eop == OP_VAR && op->var->isTemp)) {
				if (!dstTypeAttrs.isMutable || dstTypeAttrs.isMutable == srcTypeAttrs.isMutable || (op->eop == OP_VAR && op->var->isTemp)) {
					/* if (op->eop == OP_VAR && op->var->isArg) {
						op->var->isChanged = true;
						// int i = 0;
					} */
					return newOperation(OP_CAST_PTR, dstType, op, node);
				}
			}
			// dstBaseType = baseType(dstType, dstTypeAttrs, 0);
			srcBaseType = baseType(op->type, srcTypeAttrs, 1);
			int i = dstTypeAttrs.refCount - 1;
			for (; i >= 0; i--) {
				if (srcBaseType->etype == TYPE_MUT) {
					srcBaseType = unmutType(srcBaseType, node);
					YO_ASSERT(srcBaseType);
				}
				if (srcBaseType->etype == TYPE_PTR) {
					srcBaseType = unptrType(srcBaseType, node);
					YO_ASSERT(srcBaseType);
				}
				else{
					break;
				}
			}
			if (i < 0) {
				srcBaseType = baseType(srcBaseType, srcTypeAttrs, 0);
				if (convertType == CONVERT_BY_HAND && srcBaseType == dstBaseType) {
					if (!dstTypeAttrs.isMutable || dstTypeAttrs.isMutable == srcTypeAttrs.isMutable || (op->eop == OP_VAR && op->var->isTemp)) {
						return newOperation(OP_CAST_PTR, dstType, valueOf(op, node), node);
					}
				}
			}
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), dstType->name.c_str());
		return NULL;
	}
	if (dstType->etype == TYPE_PTR) {
		Type * srcBaseType = baseType(op->type, srcTypeAttrs);
		if (srcBaseType->etype == TYPE_PTR) {
			if (convertType == CONVERT_BY_HAND) {
				return newOperation(OP_CAST_PTR, dstType, valueOf(op, node), node);
			}
			Type * dstBaseType = baseType(dstType, dstTypeAttrs);
			if (srcBaseType == dstBaseType || unptrType(dstBaseType, node)->etype == TYPE_VOID) {
				if (!dstTypeAttrs.isMutable || dstTypeAttrs.isMutable == srcTypeAttrs.isMutable) {
					return newOperation(OP_CAST_PTR, dstType, valueOf(op, node), node);
				}
			}
		}
		else if (srcBaseType->etype == TYPE_ARRAY) {
			if (convertType == CONVERT_BY_HAND) {
				if (op->type->etype == TYPE_REF) {
					op = addrOf(op, node);
					return newOperation(OP_CAST_PTR, dstType, op, node);
				}
				setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), dstType->name.c_str());
				return NULL;
			}
			srcBaseType = baseType(unarrayType(srcBaseType, node), srcTypeAttrs);
			Type * dstBaseType = baseType(unptrType(dstType, node), dstTypeAttrs);
			if (srcBaseType == dstBaseType) {
				if (!dstTypeAttrs.isMutable || dstTypeAttrs.isMutable == srcTypeAttrs.isMutable) {
					op = addrOf(op, node);
					return newOperation(OP_CAST_PTR, dstType, op, node);
				}
			}
		}
		else if (srcBaseType->isInt() && convertType == CONVERT_BY_HAND) {
			return newOperation(OP_CAST_INT_TO_PTR, dstType, op, node);
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), dstType->name.c_str());
		return NULL;
	}
	if (dstType->etype == TYPE_FUNC_DATA) {
		if (op->type->etype == TYPE_PTR && op->eop == OP_FUNC) {
			Type * funcNativeType = unptrType(op->type, node);
			if (funcNativeType->etype == TYPE_FUNC_NATIVE) {
				YO_ASSERT(dynamic_cast<FuncDataType*>(dstType));
				FuncDataType * funcDataType = (FuncDataType*)dstType;
				if (funcDataType->funcNativeType == funcNativeType) {
					Operation * resultOp = newFuncDataOp(scope, op->func, node);
					// resultOp->ops.insert(resultOp->ops.begin(), op);
					return valueOf(resultOp, node);
				}
			}
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), dstType->name.c_str());
		return NULL;
	}
	Type * srcBaseType = baseType(op->type, srcTypeAttrs);
	Type * dstBaseType = baseType(dstType, dstTypeAttrs);
	if (srcBaseType == dstBaseType) {
		if (convertType == CONVERT_BY_HAND) {
			op = valueOf(op, node);
			op->type = dstType;
			return op;
		}
		if (!dstTypeAttrs.isMutable || !dstTypeAttrs.isRef) {
			op = valueOf(op, node);
			op->type = dstType;
			return op;
		}
		setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), dstType->name.c_str());
		return NULL;
	}
	CastOp castOp = getCastOp(srcBaseType, dstBaseType);
	if (castOp.eop != OP_NOP) {
		int bits;
		bool isSigned, doConvert = false;
		if (castOp.castType == CAST_AUTO || convertType == CONVERT_BY_HAND) {
			doConvert = true;
		}
		else{
			switch (op->eop) {
			case OP_CONST_INT:
				if (getIntBits(dstBaseType, bits, isSigned)) {
					YO_U64 mask = ((YO_U64)1 << bits) - 1;
					if ((op->constInt.val & mask) == op->constInt.val) {
						doConvert = true;
					}
				}
				else{
					switch (dstBaseType->etype) {
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
			return newOperation(castOp.eop, dstType, valueOf(op, node), op->parserNode);
		}
	}
	setError(ERROR_CONVERT_TO_TYPE, op->parserNode, "Error convert: %s to %s", op->type->name.c_str(), dstType->name.c_str());
	return NULL;
}

YoProgCompiler::Operation * YoProgCompiler::newFuncDataOp(Scope * scope, Function * func, YoParserNode * node)
{
	FuncDataType * funcDataType = getFuncDataType(func->funcNativeType);
	Variable * temp = allocTempValue(scope, funcDataType, node);

	Operation * tempOp = newVarOp(temp, node);

	// func data element 0
	Operation * funcElemPtrRef = newStructElementOp(tempOp, 0, node);
	if (!funcElemPtrRef) {
		YO_ASSERT(isError());
		return NULL;
	}

	// Function * func = op->func;
	Operation * funcOp = newOperation(OP_FUNC, ptrType(func->funcNativeType, node), node);
	funcOp->func = func;

	Operation * storeOp = newStoreOp(funcOp, funcElemPtrRef, node);

	Operation * resultOp = newVarOp(temp, node);
	resultOp->ops.push_back(storeOp);

	// func data element 1
	Operation * closureElemPtrRef = newStructElementOp(tempOp, 1, node);
	if (!closureElemPtrRef) {
		YO_ASSERT(isError());
		return NULL;
	}
	Operation * nullOp = newConstNullOp(scope, node);
	nullOp = convertToType(scope, nullOp, unrefType(closureElemPtrRef->type, node), CONVERT_BY_HAND, node);
	storeOp = newStoreOp(nullOp, closureElemPtrRef, node);

	resultOp->ops.push_back(storeOp);
	return resultOp;
}