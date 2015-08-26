#ifndef __YOPROGCOMPILER_H__
#define __YOPROGCOMPILER_H__

#include "yodef.h"
#include <string>
#include <vector>
#include <map>

struct YoParserNode;
class YoParser;
class YoProgCompiler
{
public:

	enum EType
	{
		TYPE_VOID,
		TYPE_BOOL,
		TYPE_INT8,
		TYPE_INT16,
		TYPE_INT32,
		TYPE_INT64,
		TYPE_UINT8,
		TYPE_UINT16,
		TYPE_UINT32,
		TYPE_UINT64,
		TYPE_FLOAT32,
		TYPE_FLOAT64,
		TYPE_STRING,
		TYPE_STRUCT,
		TYPE_PTR,
		TYPE_MUT,
		// ===========
		// TYPE_BEGIN_STD = TYPE_VOID,
		// TYPE_END_STD = TYPE_FLOAT64
	};

	struct Type
	{
		YoParserNode * parserNode;
		std::string name;
		int size;
		EType etype;
		// bool isGeneric;

		Type(const std::string& name, EType, int size, YoParserNode*);
		virtual ~Type();
	};

	struct SubType : public Type
	{
		Type * subType;
		SubType(const std::string& name, EType, int size, Type*, YoParserNode*);
	};

	enum EScope
	{
		SCOPE_BLOCK,
		SCOPE_FUNCTION,
		SCOPE_MODULE,
	};

	struct Variable
	{
		YoParserNode * parserNode;
		std::string name;
		Type * type;
		int index;
		// bool isClosure;

		Variable(const std::string& name, YoParserNode*);
	};

	struct Scope
	{
		YoParserNode * parserNode;
		Scope * parent;
		EScope escope;

		std::vector<Variable*> vars;

		Scope(Scope * parent, EScope, YoParserNode*);
		virtual ~Scope();
	};

	struct Expression;
	struct Function: public Scope
	{
		std::string name;
		Type * resType;
		int argsNumber;
		// bool isGeneric;

		std::vector<Expression*> ops;

		Function(Scope * parent, const std::string& name, YoParserNode*);
		~Function();
	};

	struct Module: public Scope
	{
		std::string name;

		// std::map<std::string, Module*> imports;
		// std::map<std::string, Type*> types;
		// std::map<std::string, Function*> funcs;
		std::vector<Function*> funcs;

		Module(const std::string& name, YoParserNode*);
		~Module();
	};

	enum EName
	{
		NAME_UNKNOWN,
		NAME_FUNC_VAR,
		NAME_FUNC_TYPE,
		NAME_PARENT_FUNC_VAR,
		NAME_PARENT_FUNC_TYPE,
		NAME_MODULE_VAR,
		NAME_MODULE_TYPE,
		NAME_MODULE_FUNC,
		NAME_MODULE_IMPORT,
	};

	struct NameAccess
	{
		Scope * scope;
		int upCount;
		Variable * var;
		EName ename;

		NameAccess();
	};

	enum EOperation
	{
		OP_NOP,

		OP_CAST_TRUNC,
		OP_CAST_ZERO_EXT,
		OP_CAST_SIGN_EXT,
		OP_CAST_SI_TO_FP,
		OP_CAST_UI_TO_FP,
		OP_CAST_FP_TO_SI,
		OP_CAST_FP_TO_UI,
		OP_CAST_FP_TRUNC,
		OP_CAST_FP_EXT,

		OP_CONST_INT,

		OP_READ_LOCAL,
		OP_WRITE_LOCAL,

		OP_READ_UPVAR,
		OP_WRITE_UPVAR,

		OP_READ_GLOBAL,
		OP_WRITE_GLOBAL,

		OP_RETURN,
		OP_BIN_ADD,
	};

	struct Expression
	{
		YoParserNode * parserNode;
		Type * type;

		EOperation op;
		NameAccess nameAccess;

		union {
			struct {
				YO_U64 ival64;
				YO_BYTE bits;
				bool isSigned;
			} constInt;

			struct {
				float fval32;
			} constFloat;

			struct {
				double fval64;
			} constDouble;
		};

		std::vector<Expression*> list;

		Expression(EOperation, YoParserNode*);
		virtual ~Expression();
	};

	struct Statement
	{
		YoParserNode * parserNode;

	};

	YoParser * parser;

	std::vector<Module*> modules;
	std::map<std::string, Type*> progTypes;

	YoProgCompiler(YoParser*);
	~YoProgCompiler();

	bool run();

	bool findName(NameAccess& out, Scope*, const std::string&);

	static std::string getTokenStr(YoParserNode*);

protected:

	enum ECastType
	{
		CAST_AUTO,
		CAST_BY_HAND,
	};

	struct CastOp
	{
		EOperation op;
		ECastType castType;

		CastOp() : op(OP_NOP), castType(CAST_BY_HAND) {}
		CastOp(EOperation _op, ECastType _castType = CAST_BY_HAND) : op(_op), castType(_castType) {}
	};

	std::map<int, CastOp> convertOps;

	int getConvertKey(EType from, EType to);
	void initConvertOps();

	void collectNodesInReversList(std::vector<YoParserNode*>& out, YoParserNode*);

	Type * getPrimitiveType(int stdType);
	Type * getIntType(int bits, bool isSigned);
	Type * getType(Scope*, YoParserNode*);

	bool addStmt(Scope*, Expression*);
	Function * getFunction(Scope*);

	bool compileModule(YoParserNode*);
	bool compileModuleFunc(Module*, YoParserNode*);
	bool compileFuncBody(Function*, YoParserNode*);
	bool compileDeclVar(Scope*, YoParserNode*);
	bool exprToStmt(Scope*, Expression*);
	bool compileStmtBinOp(Scope*, YoParserNode*);
	bool compileStmtReturn(Scope*, YoParserNode*);
	Expression * compileAssignOp(Scope*, YoParserNode*);
	Expression * compileBinOp(Scope*, YoParserNode*);
	Expression * compileExpr(Scope*, YoParserNode*);
	Expression * convertExprToType(Scope*, Expression*, Type*, bool freeOnError);
};

#endif // __YOPROGCOMPILER_H__
