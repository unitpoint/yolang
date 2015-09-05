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
		ERROR_RETURN_IN_MIDDLE,
		ERROR_RETURN_REQUIRED,
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
		TYPE_REF,
		TYPE_ARRAY,
		TYPE_MUT,
		TYPE_CONST,
		// ===========
		// TYPE_BEGIN_STD = TYPE_VOID,
		// TYPE_END_STD = TYPE_FLOAT64
	};

	class SubType;
	class Type
	{
	public:

		enum EModifier
		{
			DEFAULT,
			CONTANT,
			MUTABLE,
		};

		YoParserNode * parserNode;
		std::string name;
		EType etype;
		// EModifier emod;
		// bool isMutable;
		bool isUnknownYet;
		// bool isGeneric;

		SubType * ptrType;
		SubType * refType;
		SubType * mutType;
		SubType * constType;

		std::map<std::string, Type*> subTypes;

		struct {
			int index;
		} ext;

		Type(const std::string& name, EType, YoParserNode*);
		virtual ~Type();

		bool isSigned() const;
		bool isFloat() const;
		bool isNumber() const;
		bool isMutable() const;
		bool isPointer() const;
		bool isRef() const;

		// Type * toPointer(YoProgCompiler*);
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

	class FuncDataType;
	class FuncNativeType : public Type
	{
	public:

		struct Arg
		{
			Type * type;
			// std::string name;
			bool isMutable;

			Arg(){ type = NULL; isMutable = false; }
			// Arg(Type * t, const std::string& n, bool m): name(n){ type = t; isMutable = m; }
			Arg(Type * t, bool m){ type = t; isMutable = m; }
		};

		std::vector<Arg> args;
		Type * resType;

		FuncDataType * funcDataType;

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
		bool isArg;
		bool isMutable;
		bool isInitialized;
		bool isChanged;
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

	class Operation;
	class Scope // : public Value
	{
	public:

		std::string name;
		YoParserNode * parserNode;

		Scope * parent;
		EScope escope;

		std::vector<Scope*> scopes;
		std::vector<StackValue*> stackValues;
		std::map<std::string, Type*> types;
		std::vector<Operation*> ops;

		Scope(Scope * parent, EScope, const std::string& name, YoParserNode*);
		virtual ~Scope();
	};

	class Function : public Scope
	{
	public:

		FuncNativeType * funcNativeType;
		std::vector<std::string> argNames;

		struct {
			int index;
		} ext;

		Function(Scope * parent, FuncNativeType * funcNativeType, const std::vector<std::string>& argNames, const std::string& name, YoParserNode*);
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
	};

	enum EOperation
	{
		OP_NOP,
		// OP_SCOPE,
		OP_IF,

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
		OP_PTR,
		// OP_INDIRECT,
		OP_FUNC,

		OP_LOAD,
		OP_STORE_VALUE,
		OP_STORE_PTR,

		OP_RETURN,
		OP_CALL_CLOSURE,
		OP_CALL_FUNC,
		
		OP_BIN_ADD,
		OP_BIN_SUB,
		OP_BIN_MUL,
		OP_BIN_DIV,
		OP_BIN_MOD,
		OP_BIN_POWF,
		OP_BIN_POWI,

		OP_CMP_EQ,
		OP_CMP_NE,
		OP_CMP_LE,
		OP_CMP_GE,
		OP_CMP_LT,
		OP_CMP_GT,

		OP_STACK_VALUE_MEMZERO,
		OP_VALUE_ZERO,
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
			Scope * scope;

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

			struct {
				Operation * conditionOp;
				Scope * thenScope;
				Scope * elseScope;
			} stmtIf;
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
	bool getFloatBits(Type * type, int& bits);

	Type * getSubType(Type * ptrType, YoParserNode* = NULL);

	static std::string getTokenStr(YoParserNode*);

	Function * getFunction(Scope*);
	Module * getModule(Scope*);

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
	Operation * newOperation(EOperation, Operation * sub, Type * type, YoParserNode*);
	Operation * newStackValuePtrOp(StackValue * value, YoParserNode*);
	Operation * newStructElementPtrOp(Operation * ptrOp, int index, YoParserNode*);
	Operation * newFuncDataPtrOp(Scope*, Function * func, YoParserNode*);

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
	Type * getRefType(Type*, YoParserNode* = NULL);
	Type * getArrayType(unsigned size, Type*, YoParserNode* = NULL);
	Type * getParserStdType(int stdType);
	Type * getParserType(Scope*, YoParserNode*);
	Type * getScopeType(Scope*, YoParserNode*);
	FuncNativeType * getFuncNativeType(std::vector<std::string>& argNames, Scope*, YoParserNode*);
	FuncDataType * getFuncDataType(FuncNativeType*);
	StructType * getStructType(const std::vector<Type*>& elements, YoParserNode*);

	Type * declStructType(Scope*, EType, const std::string& name, YoParserNode*);

	Type * getPtrSubType(Type * ptrType, YoParserNode* = NULL);
	Type * getRefSubType(Type * refType, YoParserNode* = NULL);
	Type * getPtrOrRefSubType(Type * ptrType, YoParserNode* = NULL);
	Type * getValueType(Operation * op);

	Type * skipTypeMod(Type * type);
	Type * getRefFromPtrType(Type * type, YoParserNode* = NULL);
	Type * getPtrFromRefType(Type * type, YoParserNode* = NULL);

	bool matchTypeTemplate(Scope*, Type *& src, Type * dst);
	void updateFuncNativeType(FuncNativeType*);

	StackValue * allocTempValue(Scope*, Type * type, const std::string& name, YoParserNode*);

	bool addStmt(Scope*, Operation*);

	bool compileModule(YoParserNode*);
	Function * compileFunc(Scope*, YoParserNode*);
	bool compileFuncBody(Function*, YoParserNode * funcNode);
	bool compileScopeBody(Scope*, YoParserNode*);
	StackValue * compileDeclVar(Scope*, YoParserNode*);
	Type * compileDeclType(Scope*, YoParserNode*);
	// bool exprToStmt(Scope*, Expression*);
	bool compileStmtBinOp(Scope*, YoParserNode*);
	bool compileStmtAssign(Scope*, YoParserNode*);
	bool compileStmtIf(Scope*, YoParserNode*);
	bool compileStmtReturn(Scope*, YoParserNode*);
	bool compileStmtCall(Scope*, YoParserNode*);
	Operation * compileSubFunc(Scope*, YoParserNode*);
	Operation * compileDotName(Scope*, YoParserNode*);
	Operation * compileSizeOf(Scope*, YoParserNode*);
	Operation * compileCall(Scope*, YoParserNode*);
	Operation * compileAssign(Scope*, YoParserNode*);
	Operation * compileNewObjExprs(Scope*, YoParserNode*);
	Operation * compileNewObjProps(Scope*, YoParserNode*);
	Operation * compileBinOp(Scope*, YoParserNode*);
	Operation * compileUnaryOp(Scope*, YoParserNode*);
	Operation * compileIndexOp(Scope*, YoParserNode*);
	Operation * compilePowOp(Scope*, YoParserNode*);
	Operation * compileCompareOp(Scope*, YoParserNode*);
	Operation * compileDotOp(Scope*, Operation * left, YoParserNode * right, YoParserNode*);
	Operation * compileOp(Scope*, YoParserNode*);
	Operation * compileValue(Scope*, YoParserNode*);

	enum EConvertType
	{
		CONVERT_AUTO,
		CONVERT_BY_HAND
	};

	Operation * convertPtrToType(Scope*, Operation*, Type*, YoParserNode*);
	Operation * convertOpToType(Scope*, Operation*, Type*, EConvertType, YoParserNode*);
	Operation * getValue(Scope*, Operation*);
};

#endif // __YOPROGCOMPILER_H__
