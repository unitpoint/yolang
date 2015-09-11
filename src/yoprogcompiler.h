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
		ERROR_ESCAPE_CHAR,
		ERROR_LINK_EXTERN_FUNC,
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
			// bool isMutable;

			Arg(){ type = NULL; } // isMutable = false;
			// Arg(Type * t, const std::string& n, bool m): name(n){ type = t; isMutable = m; }
			// Arg(Type * t, bool m){ type = t; isMutable = m; }
			Arg(Type * t){ type = t; }
		};

		std::vector<Arg> args;
		EYoCallingConv conv;
		bool isVarArg;
		bool isExtern;
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

	class StackValue
	{
	public:

		std::string name;
		YoParserNode * parserNode;

		Type * type;
		bool isArg;
		// bool isMutable;
		bool isInitialized;
		bool isChanged;
		bool isUsed;
		bool isTemp;
		// bool isClosure;

		StackValue * initStackValue;
		int initStructElementIndex;

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
		void * externFunc;

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
		OP_SCOPE,
		OP_FOR,
		OP_IF,
		OP_BREAK,
		OP_CONTINUE,

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
		OP_CONST_STRING,
		
		OP_SIZEOF,
		OP_TYPE,
		OP_TYPE_STRUCT_ELEMENT,

		// OP_PTR,
		// OP_INDIRECT,
		
		OP_STACK_VALUE,
		OP_STRUCT_ELEMENT,
		OP_ELEMENT,

		OP_LOAD,
		OP_STORE,
		OP_STORE_VALUE,
		OP_STORE_REF,

		OP_FUNC,
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

		OP_BIT_OR,
		OP_BIT_AND,
		OP_BIT_XOR,

		OP_CMP_EQ,
		OP_CMP_NE,
		OP_CMP_LE,
		OP_CMP_GE,
		OP_CMP_LT,
		OP_CMP_GT,

		OP_LOGICAL_OR,
		OP_LOGICAL_AND,

		OP_STACK_VALUE_MEMZERO,
		OP_ZERO_VALUE,
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
				int extraArgs;
				int args;
			} callFunc;

			struct {
				Operation * conditionOp;
				Scope * thenScope;
				Scope * elseScope;
			} stmtIf;

			struct {
				Operation * conditionOp;
				Scope * bodyScope;
				Scope * stepScope;
			} stmtFor;

			int strIndex;
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

	void addSymbol(const std::string& name, void*);

	void dump();
	void dumpError();

	bool findName(NameInfo& out, Scope*, const std::string&);
	// bool isLvalueOp(Operation * op);
	bool isTypeOp(Operation * op);
	bool getIntBits(Type * type, int& bits, bool& isSigned);
	bool getFloatBits(Type * type, int& bits);

	bool isMutable(Type*);
	// Type * addMut(Type * type, bool isMutable);
	// Type * removeMut(Type * type, bool& isMutable);
	Type * subType(Type * ptrType, YoParserNode*);

	struct TypeAttrs
	{
		int refCount;
		bool isRef;
		bool isMutable;
		
		TypeAttrs(){ refCount = 0; isRef = isMutable = false; }
	};

	Type * baseType(Type * type);
	Type * baseType(Type * type, TypeAttrs&, int maxRefCount = INT_MAX);
	Type * unbaseType(Type * type, TypeAttrs&);

	static std::string getTokenStr(YoParserNode*);
	std::string getConstStr(int i);
	int addConstStr(const std::string&);

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

	std::vector<Operation*> allOps;

	std::map<std::string, int> constStringsMap;
	std::vector<std::string> constStrings;

	std::map<std::string, Type*> globalTypes;
	std::map<std::string, void*> symbols;

	Operation * newOperation(EOperation, Type * type, YoParserNode*);
	Operation * newOperation(EOperation, Type * type, Operation * sub, YoParserNode*);
	Operation * newStackValueOp(StackValue * value, YoParserNode*);
	Operation * newStructElementOp(Operation * refOp, int index, YoParserNode*);
	Operation * newFuncDataOp(Scope*, Function * func, YoParserNode*);

	Operation * newConstNullOp(Scope*, YoParserNode*);
	Operation * newConstBoolOp(Scope*, bool val, YoParserNode*);
	Operation * newConstStringOp(Scope*, const std::string& val, YoParserNode*);

	Operation * newConstIntOp(Scope*, YO_U64 val, int bits, bool isSigned, YoParserNode*);
	Operation * newConstIntOp(Scope*, YO_U64 val, Type * type, YoParserNode*);
	Operation * newConstIntOp(Scope*, YO_U64 val, YoParserNode*);
	
	Operation * newConstFloatOp(Scope*, double val, int bits, YoParserNode*);
	Operation * newConstFloatOp(Scope*, double val, Type * type, YoParserNode*);
	Operation * newConstFloatOp(Scope*, double val, YoParserNode*);

	enum ESpecAssignRet
	{
		SPEC_PRE,
		SPEC_POST,
	};
	Operation * newSpecAssignOp(Scope*, ESpecAssignRet, Operation * dstPtr, Operation * value, EOperation bin, YoParserNode*);

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
	Type * getIntType(bool isSigned);
	Type * getIntPtrType(bool isSigned);
	Type * getFloatType(int bits);

	Type * getParserStdType(int stdType);
	Type * getParserType(Scope*, YoParserNode*);
	Type * getScopeType(Scope*, YoParserNode*);
	FuncNativeType * getFuncNativeType(std::vector<std::string>& argNames, Scope*, YoParserNode*);
	FuncDataType * getFuncDataType(FuncNativeType*);
	StructType * getStructType(const std::vector<Type*>& elements, YoParserNode*);

	Type * declStructType(Scope*, EType, const std::string& name, YoParserNode*);

	Type * mutType(Type*, YoParserNode*);
	Type * unmutType(Type*, YoParserNode*);
	
	Type * constType(Type*, YoParserNode*);
	Type * unconstType(Type*, YoParserNode*);

	Type * ptrType(Type*, YoParserNode*);
	Type * unptrType(Type*, YoParserNode*);

	Type * refType(Type*, YoParserNode*);
	Type * unrefType(Type*, YoParserNode*);

	Type * arrayType(unsigned size, Type*, YoParserNode*);
	Type * unarrayType(Type*, YoParserNode*);

	// Type * getPtrSubType(Type * ptrType, YoParserNode* = NULL);
	// Type * getRefSubType(Type * refType, YoParserNode* = NULL);
	// Type * getPtrOrRefSubType(Type * ptrType, YoParserNode* = NULL);
	// Type * getValueType(Operation * op);

	Type * ptrToRefType(Type * type, YoParserNode*);
	Type * refToPtrType(Type * type, YoParserNode*);

	bool matchTypeTemplate(Scope*, Type *& src, Type * dst, bool init);

	std::string getFuncNativeTypeName(FuncNativeType*);
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
	bool compileStmtUnaryOp(Scope*, YoParserNode*);
	bool compileStmtPostUnaryOp(Scope*, YoParserNode*);
	bool compileStmtAssign(Scope*, YoParserNode*);
	bool compileStmtIf(Scope*, YoParserNode*);
	bool compileStmtFor(Scope*, YoParserNode*);
	bool compileStmtBreak(Scope*, YoParserNode*);
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
	Operation * compilePostUnaryOp(Scope*, YoParserNode*);
	Operation * compileIndexOp(Scope*, YoParserNode*);
	Operation * compilePowOp(Scope*, YoParserNode*);
	Operation * compileCompareOp(Scope*, YoParserNode*);
	Operation * compileLogicalOp(Scope*, YoParserNode*);
	Operation * compileBitOp(Scope*, YoParserNode*);
	Operation * compileDotOp(Scope*, Operation * left, YoParserNode * right, YoParserNode*);
	Operation * compileOp(Scope*, YoParserNode*);
	Operation * compileQuotedString(Scope*, YoParserNode*);
	Operation * compileSingleQuotedString(Scope*, YoParserNode*);
	Operation * compileValueOf(Scope*, YoParserNode*);

	enum EConvertType
	{
		CONVERT_AUTO,
		CONVERT_BY_HAND
	};

	Operation * convertPtrToType(Scope*, Operation*, Type*, YoParserNode*);
	Operation * convertToType(Scope*, Operation*, Type*, EConvertType, YoParserNode*);
	Operation * convertArgToType(Scope*, Operation*, Type*, bool isExtern, YoParserNode*);
	
	Operation * loadValueOf(Operation*, YoParserNode*);
	Operation * loadStackValueOf(StackValue*, YoParserNode*);
	Operation * valueOf(Operation*, YoParserNode*);
	Operation * addrOf(Operation*, YoParserNode*);
	Operation * indirectOf(Operation*, YoParserNode*);

	Operation * optimizeOpPass1(Scope*, Operation*);
	bool optimizeScopePass1(Scope*);
};

#endif // __YOPROGCOMPILER_H__
