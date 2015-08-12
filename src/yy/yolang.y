%{
#include <stdio.h>
#include <stdlib.h>
#include "yoparser.h"

void yoParserEnd(YYSTYPE*, void*);
void yoParserBinOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void*);
void yoParserUnaryOp(YYSTYPE * r, YYSTYPE * a, int op, void*);
void yoParserConst(YYSTYPE * r, int op, void*);
void yoParserTypeStdName(YYSTYPE * r, int op, void*);
void yoParserTypeName(YYSTYPE * r, YYSTYPE * a, void*);
void yoParserTypeConst(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypePtr(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypeChan(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypeSlice(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypeArr(YYSTYPE * r, YYSTYPE * size, YYSTYPE * a, void * parm);
void yoParserTypeFunc(YYSTYPE * r, YYSTYPE * self, YYSTYPE * args, YYSTYPE * type, void * parm);
void yoParserDeclType(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserDeclVar(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserDeclArg(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserDotName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserNewArr(YYSTYPE * r, void * parm);
void yoParserNewArrExps(YYSTYPE * r, YYSTYPE * expr_list, void * parm);
void yoParserNewObj(YYSTYPE * r, YYSTYPE * name, void * parm);
void yoParserNewObjExps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * expr_list, void * parm);
void yoParserNewObjProps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * prop_list, void * parm);
void yoParserNewLine(void*);
void yoParserDeclFunc(YYSTYPE * r, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, void*);
void yoParserContractFunc(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void*);
void yoParserContract(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserClass(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserDebug(YYSTYPE*, void*);
void yoParserError(YYSTYPE*, const char*, void*);
void yoParseEmpty(YYSTYPE*, void*);
void yoParserCall(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, void * parm);
void yoParserStmtReturn(YYSTYPE * r, YYSTYPE * expr, void * parm);
void yoParserEnableBrace(void * parm);
void yoParserStmtIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseIfList, YYSTYPE * elseStmt, void * parm);
void yoParserElseIfList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm);
void yoParserElseIf(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * stmt, void * parm);
void yoParserElse(YYSTYPE * r, YYSTYPE * stmt, void * parm);
void yoParserCatchElem(YYSTYPE * r, YYSTYPE * name, YYSTYPE * stmt, void * parm);
void yoParserStmtCatch(YYSTYPE * r, YYSTYPE * stmt, YYSTYPE * catchElem, void * parm);
void yoParserCast(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * type, void * parm);

int yolex(YYSTYPE*, void * parser);
void yyerror(const char* s);

%}

%verbose
%pure_parser
%error-verbose
%expect 5

%token T_ELLIPSIS
%token T_INT8 T_INT16 T_INT32 T_INT64
%token T_UINT8 T_UINT16 T_UINT32 T_UINT64 T_UINTPTR
%token T_FLOAT32 T_FLOAT64
%token T_STRING
%token T_BOOL T_TRUE T_FALSE
%token T_SSTRING T_SSTRING_NOT_FINISHED
%token T_QSTRING T_QSTRING_NOT_FINISHED
%token T_QSTRING_INJECT_EXRP
%token T_NULL
%token T_VOID
%token T_RETURN
%token T_VAR
%token T_TYPE
%token T_CHAN
%token T_FUNC
%token T_CONST
%token T_STRUCT
%token T_CLASS
%token T_CONTRACT
%token T_BRACE
%token T_IF
%token T_ELSE
%token T_ELSEIF
%token T_CATCH

%token T_LNUMBER
%token T_DNUMBER
%token T_NAME
%token T_NEWLINE
%token T_FIX
/* %token T_SLICE */

%left ','

%left T_ASSIGN T_DECL_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_CONCAT_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN T_LSH_ASSIGN T_RSH_ASSIGN T_POW_ASSIGN
%token T_ASSIGN  		"= (T_ASSIGN)"
%token T_DECL_ASSIGN  	":= (T_DECL_ASSIGN)"
%token T_PLUS_ASSIGN	"+= (T_PLUS_ASSIGN)"
%token T_MINUS_ASSIGN	"-= (T_MINUS_ASSIGN)"
%token T_MUL_ASSIGN		"*= (T_MUL_ASSIGN)"
%token T_DIV_ASSIGN		"/= (T_DIV_ASSIGN)"
%token T_CONCAT_ASSIGN	"..= (T_CONCAT_ASSIGN)"
%token T_MOD_ASSIGN		"%= (T_MOD_ASSIGN)"
%token T_AND_ASSIGN		"&= (T_AND_ASSIGN)"
%token T_OR_ASSIGN		"|= (T_OR_ASSIGN)"
%token T_XOR_ASSIGN		"^= (T_XOR_ASSIGN)"
%token T_LSH_ASSIGN		"<<= (T_LSH_ASSIGN)"
%token T_RSH_ASSIGN		">>= (T_RSH_ASSIGN)"
%token T_POW_ASSIGN		"**= (T_POW_ASSIGN)"

%left	'?' ':'

%left	T_OROR T_XORXOR
%token	T_OROR   "|| (T_OROR)"
%token	T_XORXOR  "^^ (T_XORXOR)"

%left	T_ANDAND
%token	T_ANDAND  "&& (T_ANDAND)"

%nonassoc	T_EQ T_NE T_LE T_GE T_LT T_GT
%token	T_EQ	"== (T_EQ)"
%token	T_NE	"!= (T_NE)"
%token	T_LE	"<= (T_LE)"
%token	T_GE	">= (T_GE)"
%token	T_LT	"< (T_LT)"
%token	T_GT	"> (T_GT)"

%left	T_PLUS T_MINUS T_OR T_XOR T_CONCAT
%token	T_PLUS		"+ (T_PLUS)"
%token	T_MINUS		"- (T_MINUS)"
%token	T_OR		"| (T_OR)"
%token	T_XOR		"^ (T_XOR)"
%token	T_CONCAT	".. (T_CONCAT)"

%left	T_MUL T_DIV T_MOD T_AND T_LSH T_RSH
%token	T_MUL	"* (T_MUL)"
%token	T_DIV	"/ (T_DIV)"
%token	T_MOD	"% (T_MOD)"
%token	T_AND	"& (T_AND)"
%token	T_LSH	"<< (T_LSH)"
%token	T_RSH	">> (T_RSH)"

%left	T_POW
%token	T_POW	"** (T_POW)"

/*
%nonassoc T_IS
%token	T_IS  "is (T_IS)"
*/

%right T_NOT T_TILDE T_INC T_DEC T_UNARY T_AT 
%token T_NOT	"! (T_NOT)"
%token T_TILDE	"~ (T_TILDE)"
%token T_INC	"++ (T_INC)"
%token T_DEC	"-- (T_DEC)"
%token T_AT		"@ (T_AT)"
%token T_UNARY

%right '['

%left	T_DOT
%token	T_DOT	". (T_DOT)"

%left	T_AS
%token	T_AS  "as (T_AS)"

%token	T_INDIRECT	"* (T_INDIRECT)"
%token	T_ADDR		"& (T_ADDR)"
%token	T_INDEX		"[] (T_INDEX)"

/* manual override of shift/reduce conflicts */
%left 	T_PTR
%left 	T_ARR
%left	T_DOTNAME
%left		NotParen
%left		'('
%left		')'

/*
%destructor { delete $$; } <data>
*/

%start file

%%

file:
		top_stmt_list	{ yoParserEnd(&$$, parm); }
	|	/* empty */	{ yoParseEmpty(&$$, parm); yoParserEnd(&$$, parm); }
	|	error		{ yoParserError(&$$, yymsgbuf, parm); yyclearin; yyerrok; }

newline:
	T_NEWLINE	{ yoParserNewLine(parm); yoParseEmpty(&$$, parm); }

end_stmt:
		newline
	|	';'			{ yoParseEmpty(&$$, parm); }

top_stmt_list: 
		top_stmt
	|	top_stmt_list top_stmt { yoParserList(&$$, &$1, &$2, parm); }

name_list:
		T_NAME
	|	name_list ',' T_NAME	{ yoParserList(&$$, &$1, &$3, parm); }

top_decl_var:
		T_VAR name_list type	{ yoParserDeclVar(&$$, &$2, &$3, parm); }
	|	T_VAR name_list type T_ASSIGN expr_list {
				yoParserDeclVar(&$1, &$2, &$3, parm); 
				yoParserBinOp(&$2, &$2, &$5, T_ASSIGN, parm); 
				yoParserList(&$$, &$1, &$2, parm);
			}

decl_type:
		T_TYPE T_NAME type_ext	{ yoParserDeclType(&$$, &$2, &$3, parm); }
			
top_stmt_no_emptyline:
		top_decl_var end_stmt
	|	decl_type end_stmt
	|	top_decl_func end_stmt

top_stmt:
		top_stmt_no_emptyline
	|	newline

/*	
block_stmt:
		'{' stmt_list '}'	{ $$ = $2; }

loop_block:
		T_OPEN_BRACE stmt_list '}'	{ $$ = $2; }
*/

if_header:
		expr
	
brace_stmt:
		T_BRACE stmt_list '}'	{ $$ = $2; }
	
if_stmt:
		T_IF { yoParserEnableBrace(parm); } if_header brace_stmt elseif_list else { 
			yoParserStmtIf(&$$, &$3, &$4, &$5, &$6, parm);
		}

elseif:
		T_ELSEIF { yoParserEnableBrace(parm); } if_header brace_stmt	{ yoParserElseIf(&$$, &$3, &$4, parm); }
	|	T_ELSE T_IF { yoParserEnableBrace(parm); } if_header brace_stmt	{ yoParserElseIf(&$$, &$4, &$5, parm); }
		
elseif_list:
		elseif
	|	elseif_list elseif	{ yoParserList(&$$, &$1, &$2, parm); }
	|	/* empty */			{ yoParseEmpty(&$$, parm); }
		
else:
		T_ELSE '{' stmt_list '}'	{ yoParserElse(&$$, &$3, parm); }
	|	/* empty */					{ yoParseEmpty(&$$, parm); }
		
catch:
		T_CATCH T_NAME '{' stmt_list '}' { yoParserCatchElem(&$$, &$2, &$4, parm); }
	|	/* empty */	{ yoParseEmpty(&$$, parm); }
		
assign:		
		name_list T_ASSIGN expr_list		{ yoParserBinOp(&$$, &$1, &$3, T_ASSIGN, parm); }
	|	name_list T_DECL_ASSIGN expr_list	{ yoParserBinOp(&$$, &$1, &$3, T_DECL_ASSIGN, parm); }
		
stmt_no_emptyline:
		top_stmt_no_emptyline
	|	T_RETURN expr_list catch end_stmt	{ yoParserStmtReturn(&$$, &$2, parm); yoParserStmtCatch(&$$, &$$, &$3, parm); }
	|	T_RETURN end_stmt	{ yoParserStmtReturn(&$$, NULL, parm); }
	|	if_stmt
	|	assign catch end_stmt	{ yoParserStmtCatch(&$$, &$1, &$2, parm); }
	|	call catch end_stmt { yoParserStmtCatch(&$$, &$1, &$2, parm); }

stmt:
		stmt_no_emptyline
	|	newline

stmt_list:
		stmt
	|	stmt_list stmt { yoParserList(&$$, &$1, &$2, parm); }

dotname:
		T_NAME
	|	dotname T_DOT T_NAME	{ yoParserDotName(&$$, &$1, &$3, parm); }
	
type_contract_empty:
		T_CONTRACT '{' '}'	{ yoParseEmpty(&$1, parm); yoParserContract(&$$, &$1, parm); }
		
type_contract:
		type_contract_empty
	|	T_CONTRACT '{' contract_body '}'	{ yoParserContract(&$$, &$3, parm); }

contract_body:
		contract_decl_func
	|	contract_body contract_decl_func	{ yoParserList(&$$, &$1, &$2, parm); }

contract_decl_func:
		T_NAME '(' decl_arg_list_or_empty ')' end_stmt	{ yoParserContractFunc(&$$, &$1, &$3, NULL, parm); }
	|	T_NAME '(' decl_arg_list_or_empty ')' type end_stmt	{ yoParserContractFunc(&$$, &$1, &$3, &$5, parm); }
	|	T_NAME '(' decl_arg_list_or_empty ')' '(' type_list ')' end_stmt	{ yoParserContractFunc(&$$, &$1, &$3, &$6, parm); }
	|	newline

type_class:
		T_CLASS '{' class_body '}'	{ yoParserClass(&$$, &$3, parm); }
/*	|	T_CLASS '{' '}'	{ yoParseEmpty(&$1, parm); yoParserClass(&$$, &$1, parm); } */

class_body_stmt:
		decl_arg_list end_stmt
	|	newline
	
class_body_stmt_list:
		class_body_stmt
	|	class_body_stmt_list class_body_stmt	{ yoParserList(&$$, &$1, &$2, parm); }
	
class_body:
		class_body_stmt_list
	|	/* empty */		{ yoParseEmpty(&$$, parm); }
	
type_base:	
		type_name
	|	type_const
	|	type_chan
	|	type_ptr
	|	type_slice
	|	type_arr
	|	type_func
	
type_ext:
		type_base
	|	type_contract
	|	type_class
			
top_decl_func:
		T_FUNC decl_self dotname '(' decl_arg_list_or_empty ')' '{' func_body '}'		
			{ yoParserDeclFunc(&$$, &$2, &$3, &$5, NULL, &$8, parm); }
	|	T_FUNC decl_self dotname '(' decl_arg_list_or_empty ')' type '{' func_body '}'	
			{ yoParserDeclFunc(&$$, &$2, &$3, &$5, &$7, &$9, parm); }
	|	T_FUNC decl_self dotname '(' decl_arg_list_or_empty ')' '(' type_list ')' '{' func_body '}'	
			{ yoParserDeclFunc(&$$, &$2, &$3, &$5, &$8, &$11, parm); }

decl_self:
		'(' T_NAME type_name ')'		{ yoParserDeclArg(&$$, &$2, &$3, parm); }
	|	'(' T_NAME T_MUL type_name ')'	{ yoParserTypePtr(&$3, &$4, parm); yoParserDeclArg(&$$, &$2, &$3, parm); }
	|	/* empty */		{ yoParseEmpty(&$$, parm); }
			
decl_arg_list_or_empty:
		decl_arg_list
	|	/* empty */		{ yoParseEmpty(&$$, parm); }

decl_arg_list:
		decl_arg
	|	decl_arg_list ',' decl_arg	{ yoParserList(&$$, &$1, &$3, parm); }

decl_arg:
		name_list type	{ yoParserDeclArg(&$$, &$1, &$2, parm); }

func_body:
		stmt_list
	|	/* empty */		{ yoParseEmpty(&$$, parm); }

type_list:
		type
	|	type_list ',' type	{ yoParserList(&$$, &$1, &$3, parm); }

decl_self_nop:	
		/* empty */		{ yoParseEmpty(&$$, parm); }
	
type_func:
		T_FUNC decl_self_nop '(' decl_arg_list_or_empty ')'			{ yoParserTypeFunc(&$$, &$2, &$4, NULL, parm); }
	|	T_FUNC decl_self_nop '(' decl_arg_list_or_empty ')' type	{ yoParserTypeFunc(&$$, &$2, &$4, &$6, parm); }
	|	T_FUNC decl_self_nop '(' decl_arg_list_or_empty ')' '(' type_list ')'	{ yoParserTypeFunc(&$$, &$2, &$4, &$7, parm); }

type:
		type_base
	|	type_contract_empty

type_const:
		T_CONST type	{ yoParserTypeConst(&$$, &$2, parm); }

type_chan:
		T_CHAN type	{ yoParserTypeChan(&$$, &$2, parm); }

type_ptr:
		T_MUL type	{ yoParserTypePtr(&$$, &$2, parm); }
	|	T_POW type	{ yoParserTypePtr(&$$, &$2, parm); yoParserTypePtr(&$$, &$$, parm); }
/*
		type T_MUL %prec T_PTR	{ yoParserTypePtr(&$$, &$1, parm); }
	|	type T_POW %prec T_PTR	{ yoParserTypePtr(&$$, &$1, parm); yoParserTypePtr(&$$, &$$, parm); }
*/

type_slice:
		'[' ']' type	{ yoParserTypeSlice(&$$, &$3, parm); }
/*		'[' ']' type %prec T_ARR	{ yoParserTypeSlice(&$$, &$3, parm); } */

type_arr_size:
		T_LNUMBER
	|	dotname

type_arr:
		'[' type_arr_size ']' type	{ yoParserTypeArr(&$$, &$2, &$4, parm); }
/*		'[' type_arr_size ']' type %prec T_ARR	{ yoParserTypeArr(&$$, &$2, &$4, parm); } */

type_name:
		type_std_name
	|	dotname	{ yoParserTypeName(&$$, &$1, parm); }

type_std_name:
		T_INT8		{ yoParserTypeStdName(&$$, T_INT8, parm); }
	|	T_INT16		{ yoParserTypeStdName(&$$, T_INT16, parm); }
	|	T_INT32		{ yoParserTypeStdName(&$$, T_INT32, parm); }
	|	T_INT64		{ yoParserTypeStdName(&$$, T_INT64, parm); }
	|	T_UINT8		{ yoParserTypeStdName(&$$, T_UINT8, parm); }
	|	T_UINT16	{ yoParserTypeStdName(&$$, T_UINT16, parm); }
	|	T_UINT32	{ yoParserTypeStdName(&$$, T_UINT32, parm); }
	|	T_UINT64	{ yoParserTypeStdName(&$$, T_UINT64, parm); }
	|	T_UINTPTR	{ yoParserTypeStdName(&$$, T_UINTPTR, parm); }
	|	T_STRING	{ yoParserTypeStdName(&$$, T_STRING, parm); }
	|	T_FLOAT32	{ yoParserTypeStdName(&$$, T_FLOAT32, parm); }
	|	T_FLOAT64	{ yoParserTypeStdName(&$$, T_FLOAT64, parm); }
	|	T_BOOL		{ yoParserTypeStdName(&$$, T_BOOL, parm); }
	|	T_VOID		{ yoParserTypeStdName(&$$, T_VOID, parm); }

expr_const_scalar:
		T_TRUE		{ yoParserConst(&$$, T_TRUE, parm); }
	|	T_FALSE		{ yoParserConst(&$$, T_FALSE, parm); }
	|	T_NULL		{ yoParserConst(&$$, T_NULL, parm); }
	|	T_LNUMBER
	| 	T_DNUMBER
	|	T_SSTRING
	|	T_QSTRING

expr_list:
		expr
	|	expr_list ',' expr		{ yoParserList(&$$, &$1, &$3, parm); }

expr_arr:
		'{' '}'				{ yoParserNewArr(&$$, parm); }
	|	'{' expr_list '}'	{ yoParserNewArrExps(&$$, &$2, parm); }

expr_obj:
		dotname '{' '}'			{ yoParserNewObj(&$$, &$1, parm); }
	|	dotname '{' expr_list '}'	{ yoParserNewObjExps(&$$, &$1, &$3, parm); }
	|	dotname '{' prop_assing_list '}'	{ yoParserNewObjProps(&$$, &$1, &$3, parm); }

prop_assing_list:
		prop_assing
	|	prop_assing_list ',' prop_assing	{ yoParserList(&$$, &$1, &$3, parm); }

prop_assing:
		dotname T_ASSIGN expr			{ yoParserBinOp(&$$, &$1, &$3, T_ASSIGN, parm); }

qstr_with_inject_begin_elem:
		T_QSTRING_INJECT_EXRP expr_base { yoParserBinOp(&$$, &$1, &$2, T_CONCAT, parm); }

qstr_with_inject_begin_list:
		qstr_with_inject_begin_elem
	|	qstr_with_inject_begin_list qstr_with_inject_begin_elem { yoParserBinOp(&$$, &$1, &$2, T_CONCAT, parm); }

qstr_with_inject:
		qstr_with_inject_begin_list T_QSTRING { yoParserBinOp(&$$, &$1, &$2, T_CONCAT, parm); }
		
expr:
		expr_base
	|	qstr_with_inject
		
expr_base:
		expr_const_scalar
	|	expr_arr
	|	expr_obj
	| 	dotname
	| 	uexpr
	|	expr T_PLUS expr	{ yoParserBinOp(&$$, &$1, &$3, T_PLUS, parm); }
	|	expr T_MINUS expr	{ yoParserBinOp(&$$, &$1, &$3, T_MINUS, parm); }
	|	expr T_MUL expr		{ yoParserBinOp(&$$, &$1, &$3, T_MUL, parm); }
	|	expr T_DIV expr		{ yoParserBinOp(&$$, &$1, &$3, T_DIV, parm); }
	|	expr T_MOD expr		{ yoParserBinOp(&$$, &$1, &$3, T_MOD, parm); }
	|	expr T_CONCAT expr	{ yoParserBinOp(&$$, &$1, &$3, T_CONCAT, parm); }
	|	expr T_DOT dotname  { yoParserBinOp(&$$, &$1, &$3, T_DOT, parm); }
	|	expr T_OR expr  	{ yoParserBinOp(&$$, &$1, &$3, T_OR, parm); }
	|	expr T_OROR expr  	{ yoParserBinOp(&$$, &$1, &$3, T_OROR, parm); }
	|	expr T_AND expr  	{ yoParserBinOp(&$$, &$1, &$3, T_AND, parm); }
	|	expr T_ANDAND expr  { yoParserBinOp(&$$, &$1, &$3, T_ANDAND, parm); }
	|	expr T_XOR expr  	{ yoParserBinOp(&$$, &$1, &$3, T_XOR, parm); }
	|	expr T_XORXOR expr  { yoParserBinOp(&$$, &$1, &$3, T_XORXOR, parm); }
	|	expr '[' expr ']'	{ yoParserBinOp(&$$, &$1, &$3, T_INDEX, parm); }
	|	'(' expr ')'		{ $$ = $2; }
	|	call
	|	expr T_AS type		{ yoParserCast(&$$, &$1, &$3, parm); }
	|	expr T_DOT '(' type ')'	{ yoParserCast(&$$, &$1, &$4, parm); }

uexpr:
		T_PLUS	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_PLUS, parm); }
	|	T_MINUS expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_MINUS, parm); }
	|	T_NOT 	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_NOT, parm); }
	|	T_TILDE expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_TILDE, parm); }
	|	T_MUL 	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_INDIRECT, parm); }
	|	T_AND	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_ADDR, parm); }
/*	|	'(' type ')' expr %prec T_UNARY */
/*	|	T_AT  T_NAME %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_AT, parm); } */

call:
		dotname '(' expr_list ')'	{ yoParserCall(&$$, &$1, &$3, parm); }
	|	expr T_DOT dotname '(' expr_list ')' { 
			yoParserBinOp(&$$, &$1, &$3, T_DOT, parm);
			yoParserCall(&$$, &$$, &$5, parm);
		}

%%
