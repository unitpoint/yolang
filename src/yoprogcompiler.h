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

	enum Error
	{
		ERROR_NOTHING,
		ERROR_UNREACHABLE,
		// ERROR_PARSER_NODE,
		ERROR_VAR_NOT_USED,
		// ERROR_FUNC_STMT,
		ERROR_NAME_NOT_FOUND,
		// ERROR_NAME,
		ERROR_TYPE,
		ERROR_OP,
		ERROR_CONVERT_TO_TYPE,
	};

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
		TYPE_FUNC_NATIVE,
		TYPE_FUNC_DATA,
		TYPE_PTR,
		TYPE_MUT,
		// ===========
		// TYPE_BEGIN_STD = TYPE_VOID,
		// TYPE_END_STD = TYPE_FLOAT64
	};

	class Type
	{
	public:

		YoParserNode * parserNode;
		std::string name;
		EType etype;
		// bool isMutable;
		// bool isGeneric;

		struct {
			int index;
		} ext;

		Type(const std::string& name, EType, YoParserNode*);
		virtual ~Type();

		bool isFloat() const;
	};

	class SubType : public Type
	{
	public:

		Type * subType;
		
		SubType(const std::string& name, EType, Type*, YoParserNode*);
		~SubType();
	};

	class StructType : public Type
	{
	public:

		bool isPacked;
		std::vector<Type*> elements;

		StructType(const std::string& name, YoParserNode*);
		~StructType();
	};

	class FuncNativeType : public Type
	{
	public:

		Type * resType;
		std::vector<Type*> argTypes;
		std::vector<std::string> argNames;

		FuncNativeType(const std::string& name, YoParserNode*);
		~FuncNativeType();
	};

	class FuncDataType : public StructType
	{
	public:

		FuncNativeType * funcNativeType;

		FuncDataType(const std::string& name, YoParserNode*);
		~FuncDataType();
	};

	enum EValue
	{
		VALUE_NOTHING,
		VALUE_STACKVALUE,
		VALUE_SCOPE,
	};

	class Value
	{
	public:

		EValue evalue;

		std::string name;
		YoParserNode * parserNode;

		Value(EValue evalue, const std::string& name, YoParserNode*);
		virtual ~Value();

	private:

		Value(const Value&); // no body
	};

	class StackValue : public Value
	{
	public:

		Type * type;
		bool isInitialized;
		bool isUsed;
		bool isTemp;
		// bool isClosure;

		struct {
			int index;
		} ext;

		StackValue(Type * type, const std::string& name, YoParserNode*);
		~StackValue();
	};

	enum EScope
	{
		SCOPE_BLOCK,
		SCOPE_FUNCTION,
		SCOPE_MODULE,
	};

	class Scope // : public Value
	{
	public:

		std::string name;
		YoParserNode * parserNode;

		Scope * parent;
		EScope escope;

		std::vector<StackValue*> stackValues;

		Scope(Scope * parent, EScope, const std::string& name, YoParserNode*);
		virtual ~Scope();
	};

	class Operation;
	class Function : public Scope
	{
	public:

		FuncNativeType * funcNativeType;
		std::vector<Operation*> ops;

		struct {
			int index;
		} ext;

		Function(Scope * parent, FuncNativeType * funcNativeType, const std::string& name, YoParserNode*);
		~Function();
	};

	class Module : public Scope
	{
	public:

		std::vector<Function*> funcs;

		Module(const std::string& name, YoParserNode*);
		~Module();
	};

	enum EName
	{
		NAME_UNKNOWN,
		NAME_STACKVALUE,
		NAME_CLOSUREVALUE,
	};

	struct NameInfo
	{
		EName ename;
		Scope * scope;

		union {
			struct {
				int count;
				StackValue * value;
			} closureValue;

			StackValue * stackValue;
		};
		// NameInfo();
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
		
		OP_CAST_PTR,

		OP_CONST_NULL,
		OP_CONST_INT,
		OP_CONST_FLOAT,
		
		OP_STACKVALUE_PTR,
		OP_STRUCTELEMENT_PTR,
		OP_FUNC,

		OP_LOAD_BY_PTR,
		// OP_LOAD_BY_FUNC,
		OP_STORE,

		// OP_READ_LOCAL,
		// OP_WRITE_LOCAL,

		// OP_READ_UPVAR,
		// OP_WRITE_UPVAR,

		// OP_READ_GLOBAL,
		// OP_WRITE_GLOBAL,

		OP_RETURN,
		OP_CALL,
		OP_BIN_ADD,
		// OP_SUB_FUNC,

		// OP_LIST,
	};

	class Operation
	{
	public:

		YoParserNode * parserNode;
		Type * type;

		EOperation eop;
		std::vector<Operation*> ops;
		
		// NameInfo nameInfo;

		union {
			struct {
				YO_U64 val;
				YO_BYTE bits;
				bool isSigned;
			} constInt;

			struct {
				double fval;
				// float fval32;
			} constFloat;

			struct {
				Function * func;
			} func;

			/* struct {
				StackValue * stackValue;
				int index;
			} stackValueElement; */
			int structElementIndex;

			struct {
				int upCount;
				StackValue * value;
			} upvalue;

			StackValue * stackValue;

			struct {
				FuncDataType * funcDataType;
				int args;
			} call;
		};

		Operation(EOperation, YoParserNode*);
		// Operation(StackValue * stackValue, YoParserNode*);
		virtual ~Operation();
	};

	YoParser * parser;

	std::vector<Module*> modules;

	Error error;
	std::string errorMsg;
	YoParserNode * errorNode;

	YoProgCompiler(YoParser*);
	~YoProgCompiler();

	void reset();

	void resetError();
	void setError(Error);
	void setError(Error, YoParserNode*, const char * msg, ...);
	void setError(Error, YoParserNode*, const std::string& msg);
	bool isError() const;

	bool run();

	bool findName(NameInfo& out, Scope*, const std::string&);

	static std::string getTokenStr(YoParserNode*);

protected:

	enum ECastType
	{
		CAST_AUTO,
		CAST_BY_HAND,
	};

	struct CastOp
	{
		EType extType;
		EOperation op;
		ECastType castType;

		CastOp() : op(OP_NOP), castType(CAST_BY_HAND) {}
		CastOp(EType _extType, EOperation _op, ECastType _castType = CAST_BY_HAND) : extType(_extType), op(_op), castType(_castType) {}
	};

	std::map<int, CastOp> convertOps;

	std::vector<Operation*> ops;

	std::map<std::string, Type*> types;

	Operation * newOperation(EOperation, YoParserNode*);
	Operation * newStackValuePtrOp(StackValue * value, YoParserNode*);
	Operation * newStructElementPtrOp(Operation * ptrOp, int index, YoParserNode*);

	int getConvertKey(EType from, EType to);
	void initConvertOps();

	void collectNodesInReversList(std::vector<YoParserNode*>& out, YoParserNode*);

	Type * newType(const std::string& name, EType, YoParserNode*);
	SubType * newSubType(const std::string& name, EType, Type*, YoParserNode*);
	StructType * newStructType(const std::string& name, YoParserNode*);
	FuncDataType * newFuncDataType(const std::string& name, YoParserNode*);
	FuncNativeType * newFuncNativeType(const std::string& name, YoParserNode*);

	Type * getType(EType);
	Type * getVoidPtrType();
	Type * getIntType(int bits, bool isSigned);
	Type * getFloatType(int bits);
	Type * getMutType(Type*, YoParserNode* = NULL);
	Type * getPtrType(Type*, YoParserNode* = NULL);
	Type * getIndirectType(Type * ptrType, YoParserNode* = NULL);
	Type * getParserStdType(int stdType);
	Type * getParserType(YoParserNode*);
	FuncNativeType * getFuncNativeType(YoParserNode*);
	FuncDataType * getFuncDataType(FuncNativeType*);
	StructType * getStructType(const std::vector<Type*>& elements, YoParserNode*);

	StackValue * allocTempValue(Scope*, Type * type, const std::string& name, YoParserNode*);

	bool addStmt(Scope*, Operation*);
	Function * getFunction(Scope*);
	Module * getModule(Scope*);

	bool compileModule(YoParserNode*);
	Function * compileFunc(Scope*, YoParserNode*);
	bool compileFuncBody(Function*, YoParserNode*);
	StackValue * compileDeclVar(Scope*, YoParserNode*);
	// bool exprToStmt(Scope*, Expression*);
	bool compileStmtBinOp(Scope*, YoParserNode*);
	bool compileStmtAssign(Scope*, YoParserNode*);
	bool compileStmtReturn(Scope*, YoParserNode*);
	Operation * compileSubFunc(Scope*, YoParserNode*);
	Operation * compileCall(Scope*, YoParserNode*);
	Operation * compileAssign(Scope*, YoParserNode*);
	Operation * compileBinOp(Scope*, YoParserNode*);
	Operation * compileOp(Scope*, YoParserNode*);
	Operation * compileValueOp(Scope*, YoParserNode*);
	Operation * convertOpToType(Scope*, Operation*, Type*);
	Operation * convertOpToValue(Scope*, Operation*);
};

#endif // __YOPROGCOMPILER_H__
