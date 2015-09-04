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
		ERROR_VAR_DUPLICATED,
		ERROR_VAR_NOT_USED,
		ERROR_VAR_NOT_INITIALIZED,
		ERROR_NAME_NOT_FOUND,
		ERROR_FIELD_NOT_FOUND,
		ERROR_TYPE,
		ERROR_OP,
		ERROR_CONVERT_TO_TYPE,
		ERROR_TYPE_UNKNOWN,
		ERROR_TYPE_DUPLICATED,
		ERROR_FIELD_DUPLICATED,
		ERROR_MUTABLE_REQUIRED,
		ERROR_CALL_ARGS_NUMBER,
	};

	enum EType
	{
		TYPE_UNKNOWN_YET,
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
		TYPE_CLASS,
		TYPE_FUNC_NATIVE,
		TYPE_FUNC_DATA,
		TYPE_PTR,
		TYPE_ARRAY,
		TYPE_MUT,
		TYPE_CONST,
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
		bool isUnknownYet;
		// bool isGeneric;

		std::map<std::string, Type*> subTypes;

		struct {
			int index;
		} ext;

		Type(const std::string& name, EType, YoParserNode*);
		virtual ~Type();

		bool isFloat() const;
		bool isNumber() const;
	};

	class SubType : public Type
	{
	public:

		Type * subType;
		
		SubType(const std::string& name, EType, Type*, YoParserNode*);
		~SubType();
	};

	class ArrayType : public SubType
	{
	public:

		unsigned size;

		ArrayType(const std::string& name, unsigned size, Type*, YoParserNode*);
		~ArrayType();
	};

	class StructType : public Type
	{
	public:

		bool isPacked;
		std::vector<Type*> types;
		std::vector<std::string> names;
		std::map<std::string, int> nameIndices;

		StructType(const std::string& name, EType, YoParserNode*);
		~StructType();

		void updateNameIndices();
	};

	class FuncNativeType : public Type
	{
	public:

		struct Arg
		{
			Type * type;
			std::string name;
			bool isMutable;

			Arg(){ type = NULL; isMutable = false; }
			Arg(Type * t, const std::string& n, bool m): name(n){ type = t; isMutable = m; }
		};

		std::vector<Arg> args;
		Type * resType;

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
		// VALUE_SCOPE,
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
		bool isMutable;
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
		std::map<std::string, Type*> types;

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
		NAME_TYPE,
		NAME_MODULE_FUNCTION,
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
			Type * type;
			Function * func;
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
		
		OP_SIZEOF,
		OP_TYPE,
		OP_TYPE_STRUCT_ELEMENT,

		OP_STACK_VALUE_PTR,
		OP_STRUCT_ELEMENT_PTR,
		OP_ELEMENT_PTR,
		OP_FUNC,

		OP_LOAD,
		// OP_LOAD_BY_FUNC,
		OP_STORE_VALUE,
		OP_STORE_PTR,

		// OP_READ_LOCAL,
		// OP_WRITE_LOCAL,

		// OP_READ_UPVAR,
		// OP_WRITE_UPVAR,

		// OP_READ_GLOBAL,
		// OP_WRITE_GLOBAL,

		OP_RETURN,
		OP_CALL_CLOSURE,
		OP_CALL_FUNC,
		OP_BIN_ADD,
		// OP_SUB_FUNC,

		// OP_LIST,
		OP_STACK_VALUE_MEMZERO,
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

			Function * func;

			struct {
				StructType * parent;
				int index;
			} typeStructElement;

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
			} callClosure;

			struct {
				Function * func;
				int args;
			} callFunc;
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
	void dump();
	void dumpError();

	bool findName(NameInfo& out, Scope*, const std::string&);
	bool isValueOp(Operation * op);
	bool isTypeOp(Operation * op);
	bool getIntBits(Type * type, int& bits, bool& isSigned);
	
	Type * getSubType(Type * ptrType, YoParserNode* = NULL);

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
		EOperation eop;
		ECastType castType;

		CastOp() : eop(OP_NOP), castType(CAST_BY_HAND) {}
		CastOp(EType _extType, EOperation _eop, ECastType _castType = CAST_BY_HAND) : extType(_extType), eop(_eop), castType(_castType) {}
	};

	std::map<int, Type*> binOpNumCastTypes;
	std::map<int, CastOp> castOps;

	std::vector<Operation*> ops;

	std::map<std::string, Type*> globalTypes;

	Operation * newOperation(EOperation, YoParserNode*);
	Operation * newStackValuePtrOp(StackValue * value, YoParserNode*);
	Operation * newStructElementPtrOp(Operation * ptrOp, int index, YoParserNode*);

	int getConvertKey(EType from, EType to);
	Type * getBinOpNumCast(Type * a, Type * b);
	CastOp getCastOp(Type * from, Type * to);
	
	void collectNodesInReversList(std::vector<YoParserNode*>& out, YoParserNode*);
	void collectDotNameNodesInReversList(std::vector<YoParserNode*>& out, YoParserNode*);

	// Type * newType(const std::string& name, EType, YoParserNode*);
	// SubType * newSubType(const std::string& name, EType, Type*, YoParserNode*);
	// ArrayType * newArrayType(const std::string& name, unsigned size, Type*, YoParserNode*);
	// StructType * newStructType(const std::string& name, EType, YoParserNode*);
	// FuncDataType * newFuncDataType(const std::string& name, YoParserNode*);
	// FuncNativeType * newFuncNativeType(const std::string& name, YoParserNode*);

	Type * getType(EType);
	Type * getVoidPtrType();
	Type * getIntType(int bits, bool isSigned);
	Type * getFloatType(int bits);

	Type * getMutType(Type*, YoParserNode*);
	Type * getConstType(Type*, YoParserNode*);
	Type * getPtrType(Type*, YoParserNode* = NULL);
	Type * getArrayType(unsigned size, Type*, YoParserNode* = NULL);
	Type * getParserStdType(int stdType);
	Type * getParserType(Scope*, YoParserNode*);
	Type * getScopeType(Scope*, YoParserNode*);
	FuncNativeType * getFuncNativeType(Scope*, YoParserNode*);
	FuncDataType * getFuncDataType(FuncNativeType*);
	StructType * getStructType(const std::vector<Type*>& elements, YoParserNode*);

	Type * declStructType(Scope*, EType, const std::string& name, YoParserNode*);

	Type * getPtrSubType(Type * ptrType, YoParserNode* = NULL);
	Type * getValueType(Operation * op);
	Type * skipMutType(Type * type);

	bool matchTypeTemplate(Scope*, Type *& src, Type * dst);
	void updateFuncNativeType(FuncNativeType*);

	StackValue * allocTempValue(Scope*, Type * type, const std::string& name, YoParserNode*);

	bool addStmt(Scope*, Operation*);
	Function * getFunction(Scope*);
	Module * getModule(Scope*);

	bool compileModule(YoParserNode*);
	Function * compileFunc(Scope*, YoParserNode*);
	bool compileFuncBody(Function*, YoParserNode*);
	StackValue * compileDeclVar(Scope*, YoParserNode*);
	Type * compileDeclType(Scope*, YoParserNode*);
	// bool exprToStmt(Scope*, Expression*);
	bool compileStmtBinOp(Scope*, YoParserNode*);
	bool compileStmtAssign(Scope*, YoParserNode*);
	bool compileStmtReturn(Scope*, YoParserNode*);
	Operation * compileSubFunc(Scope*, YoParserNode*);
	Operation * compileDotName(Scope*, YoParserNode*);
	Operation * compileSizeOf(Scope*, YoParserNode*);
	Operation * compileCall(Scope*, YoParserNode*);
	Operation * compileAssign(Scope*, YoParserNode*);
	Operation * compileNewObjExprs(Scope*, YoParserNode*);
	Operation * compileNewObjProps(Scope*, YoParserNode*);
	Operation * compileBinOp(Scope*, YoParserNode*);
	Operation * compileIndexOp(Scope*, YoParserNode*);
	Operation * compileDotOp(Scope*, Operation * left, YoParserNode * right, YoParserNode*);
	Operation * compileOp(Scope*, YoParserNode*);
	Operation * compileValue(Scope*, YoParserNode*);

	enum EConvertType
	{
		CONVERT_AUTO,
		CONVERT_BY_HAND
	};

	Operation * convertPtrToType(Scope*, Operation*, Type*);
	Operation * convertValueToType(Scope*, Operation*, Type*, EConvertType = CONVERT_AUTO);
	Operation * getValue(Scope*, Operation*);
};

#endif // __YOPROGCOMPILER_H__
