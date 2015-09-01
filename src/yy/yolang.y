%{
#include <stdio.h>
#include <stdlib.h>
#include "yoparser.h"

# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1

#define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
		  (Current).token  		 = YYRHSLOC (Rhs, 1).token;       		\
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
		  (Current).token  		 = YYRHSLOC (Rhs, 0).token;       		\
        }                                                               \
    while (YYID (0))
	
// void yoParserLocation(YYSTYPE * elem, YYLTYPE * loc, void * parm);
void yoParserModule(YYSTYPE * r, YYSTYPE * name, YYSTYPE * body, void * parm, YYLTYPE * loc);
void yoParserImport(YYSTYPE * r, YYSTYPE * name, YYSTYPE * path, void * parm, YYLTYPE * loc);
// void yoParserEnd(YYSTYPE*, void*);
void yoParserAssign(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void*, YYLTYPE * loc);
void yoParserBinOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void*, YYLTYPE * loc);
void yoParserUnaryOp(YYSTYPE * r, YYSTYPE * a, int op, void*, YYLTYPE * loc);
void yoParserConst(YYSTYPE * r, int op, void*, YYLTYPE * loc);
void yoParserTypeStdName(YYSTYPE * r, int op, void*, YYLTYPE * loc);
void yoParserTypeName(YYSTYPE * r, YYSTYPE * name, YYSTYPE * gen, void * parm, YYLTYPE * loc);
void yoParserTypeNameDef(YYSTYPE * r, YYSTYPE * name, YYSTYPE * def, void * parm, YYLTYPE * loc);
void yoParserTypeConst(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypeMutable(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypePtr(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypeRef(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypeChan(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypeSlice(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypeArr(YYSTYPE * r, YYSTYPE * size, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserTypeFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * args, YYSTYPE * type, void * parm, YYLTYPE * loc);
void yoParserDeclType(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
void yoParserDeclVar(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
void yoParserDeclArg(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
void yoParserList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
void yoParserDotName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
void yoParserNewArr(YYSTYPE * r, void * parm, YYLTYPE * loc);
void yoParserNewArrExps(YYSTYPE * r, YYSTYPE * expr_list, void * parm, YYLTYPE * loc);
void yoParserNewObj(YYSTYPE * r, YYSTYPE * name, void * parm, YYLTYPE * loc);
void yoParserNewObjExps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * expr_list, void * parm, YYLTYPE * loc);
void yoParserNewObjProps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * prop_list, void * parm, YYLTYPE * loc);
void yoParserNewLine(void*, YYLTYPE * loc);
void yoParserDeclFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, void*, YYLTYPE * loc);
void yoParserContractFunc(YYSTYPE * r, int op, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void*, YYLTYPE * loc);
void yoParserContract(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * e, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserClass(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * e, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserDebug(YYSTYPE*, void*, YYLTYPE * loc);
void yoParserError(YYSTYPE*, const char*, void*, YYLTYPE * loc);
void yoParseEmpty(YYSTYPE*, void*, YYLTYPE * loc);
void yoParserCall(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, void * parm, YYLTYPE * loc);
void yoParserStmtReturn(YYSTYPE * r, YYSTYPE * expr, void * parm, YYLTYPE * loc);
void yoParserEnableBrace(void * parm, YYLTYPE * loc);
void yoParserStmtIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseIfList, YYSTYPE * elseStmt, void * parm, YYLTYPE * loc);
void yoParserElseIfList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm, YYLTYPE * loc);
void yoParserElseIf(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * stmt, void * parm, YYLTYPE * loc);
void yoParserElse(YYSTYPE * r, YYSTYPE * stmt, void * parm, YYLTYPE * loc);
void yoParserCatchElem(YYSTYPE * r, YYSTYPE * name, YYSTYPE * stmt, void * parm, YYLTYPE * loc);
void yoParserStmtCatch(YYSTYPE * r, YYSTYPE * stmt, YYSTYPE * catchElem, void * parm, YYLTYPE * loc);
void yoParserCast(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * type, void * parm, YYLTYPE * loc);

int yolex(YYSTYPE*, YYLTYPE*, void * parser);
void yyerror(const char* s);

%}

%verbose
%pure_parser
%locations
%error-verbose
%expect 7

%token T_MODULE T_IMPORT
%token T_DOTDOTDOT
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
%token T_UNKNOWN_YET
%token T_RETURN
%token T_LET
%token T_TYPE
%token T_CHAN
%token T_FUNC T_SUB_FUNC T_LAMBDA
%token T_GET
%token T_SET
%token T_CONST T_MUTABLE
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

%right T_ASSIGN T_DECL_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_CONCAT_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN T_LSH_ASSIGN T_RSH_ASSIGN T_POW_ASSIGN
%token T_ASSIGN  		"= (T_ASSIGN)"
%token T_INIT_ASSIGN  	"= (T_INIT_ASSIGN)"
%token T_PROP_ASSIGN  	"= (T_PROP_ASSIGN)"
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

%nonassoc T_CHAN_ACCESS
%token	T_CHAN_ACCESS	"<- (T_CHAN_ACCESS)"

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
		T_MODULE T_NAME end_newline module_stmt_list	{ yoParserModule(&$$, &$2, &$4, parm, &yyloc); }

empty:
	/* empty */		{ yoParseEmpty(&$$, parm, &yyloc); }		
		
/* 
newline_list:
		newline
	|	newline_list newline	{ yoParseEmpty(&$$, parm, &yyloc); }
*/
	
end_newline:
		newline
	|	';' newline { yoParseEmpty(&$$, parm, &yyloc); }
	
module_stmt_list:
		top_stmt_list
	|	empty

newline:
	T_NEWLINE	{ yoParserNewLine(parm, &yyloc); yoParseEmpty(&$$, parm, &yyloc); }

end_stmt:
		newline
	|	';'		{ yoParseEmpty(&$$, parm, &yyloc); }

top_stmt_list: 
		top_stmt
	|	top_stmt_list top_stmt { yoParserList(&$$, &$1, &$2, parm, &yyloc); }

name_list:
		T_NAME
	|	name_list ',' T_NAME	{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }

type_or_empty:
		type
	|	empty
	
decl_var:
		T_LET T_NAME type_or_empty	{ yoParserDeclVar(&$$, &$2, &$3, parm, &yyloc); }
	|	T_LET T_NAME type_or_empty T_ASSIGN expr {
				yoParserDeclVar(&$1, &$2, &$3, parm, &yyloc); 
				yoParserAssign(&$2, &$2, &$5, T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&$$, &$1, &$2, parm, &yyloc);
			}

decl_type:
		T_TYPE T_NAME type_ext	{ yoParserDeclType(&$$, &$2, &$3, parm, &yyloc); }
		
const_str:
		T_QSTRING
	|	T_SSTRING
	
import:
		T_IMPORT const_str			{ yoParserImport(&$$, NULL, &$2, parm, &yyloc); }
	|	T_IMPORT T_NAME const_str	{ yoParserImport(&$$, &$2, &$3, parm, &yyloc); }
	|	T_IMPORT '{' newline import_body '}'	{ $$ = $4; }
				
import_body_elem:
		const_str newline			{ yoParserImport(&$$, NULL, &$1, parm, &yyloc); }
	|	T_NAME const_str newline	{ yoParserImport(&$$, &$1, &$2, parm, &yyloc); }
	
import_body:
		import_body_elem
	|	import_body import_body_elem { yoParserList(&$$, &$1, &$2, parm, &yyloc); }
				
top_stmt_no_emptyline:
		import end_stmt
	|	decl_type end_stmt
	|	top_decl_func end_stmt
	|	error { yoParserError(&$$, yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }

top_stmt:
		top_stmt_no_emptyline
	|	newline

stmt_error_end:
		empty
/*
		newline
	|	';'
	|	'}'
*/

stmt_no_emptyline:
		decl_var catch end_stmt		{ yoParserStmtCatch(&$$, &$1, &$2, parm, &yyloc); }
	|	decl_func catch end_stmt	{ yoParserStmtCatch(&$$, &$1, &$2, parm, &yyloc); }
	|	decl_type end_stmt
	|	T_RETURN expr catch end_stmt	{ yoParserStmtReturn(&$$, &$2, parm, &yyloc); yoParserStmtCatch(&$$, &$$, &$3, parm, &yyloc); }
	|	T_RETURN end_stmt				{ yoParserStmtReturn(&$$, NULL, parm, &yyloc); }
	|	if_stmt
	|	assign catch end_stmt	{ yoParserStmtCatch(&$$, &$1, &$2, parm, &yyloc); }
	|	call catch end_stmt		{ yoParserStmtCatch(&$$, &$1, &$2, parm, &yyloc); }
	|	error stmt_error_end	{ yoParserError(&$$, yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }

stmt:
		stmt_no_emptyline
	|	newline

stmt_list:
		stmt
	|	stmt_list stmt { yoParserList(&$$, &$1, &$2, parm, &yyloc); }

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
		T_IF { yoParserEnableBrace(parm, &yyloc); } if_header brace_stmt elseif_list else { 
			yoParserStmtIf(&$$, &$3, &$4, &$5, &$6, parm, &yyloc);
		}

elseif:
		T_ELSEIF { yoParserEnableBrace(parm, &yyloc); } if_header brace_stmt	{ yoParserElseIf(&$$, &$3, &$4, parm, &yyloc); }
	|	T_ELSE T_IF { yoParserEnableBrace(parm, &yyloc); } if_header brace_stmt	{ yoParserElseIf(&$$, &$4, &$5, parm, &yyloc); }
		
elseif_list:
		elseif
	|	elseif_list elseif	{ yoParserList(&$$, &$1, &$2, parm, &yyloc); }
	|	empty
		
else:
		T_ELSE '{' stmt_list '}'	{ yoParserElse(&$$, &$3, parm, &yyloc); }
	|	empty
		
catch:
		T_CATCH T_NAME '{' stmt_list '}' { yoParserCatchElem(&$$, &$2, &$4, parm, &yyloc); }
	|	empty
		
dotname:
		T_NAME
	|	dotname T_DOT T_NAME	{ yoParserDotName(&$$, &$1, &$3, parm, &yyloc); }
	
type_contract_empty:
		T_CONTRACT '{' '}'	{ yoParseEmpty(&$1, parm, &yyloc); yoParserContract(&$$, &$1, &$1, &$1, parm, &yyloc); }
		
type_contract:
		T_CONTRACT template extends '{' contract_body '}'	{ yoParserContract(&$$, &$2, &$3, &$5, parm, &yyloc); }

contract_body:
		contract_decl_func
	|	contract_body contract_decl_func	{ yoParserList(&$$, &$1, &$2, parm, &yyloc); }

contract_decl_func:
		T_FUNC T_NAME '(' decl_arg_list_or_empty ')' end_stmt	{ yoParserContractFunc(&$$, T_FUNC, &$2, &$4, NULL, parm, &yyloc); }
	|	T_FUNC T_NAME '(' decl_arg_list_or_empty ')' type end_stmt	{ yoParserContractFunc(&$$, T_FUNC, &$2, &$4, &$6, parm, &yyloc); }
	|	T_GET T_NAME '(' decl_arg_list_or_empty ')' type end_stmt	{ yoParserContractFunc(&$$, T_GET, &$2, &$4, &$6, parm, &yyloc); }
	|	T_SET T_NAME '(' decl_arg_list ')' end_stmt	{ yoParserContractFunc(&$$, T_SET, &$2, &$4, NULL, parm, &yyloc); }
	|	newline

template:
		T_LT template_arg_list T_GT { $$ = $2; }
	|	empty

template_arg:
		type_name
	|	type_name T_ASSIGN template_arg	{ yoParserTypeNameDef(&$$, &$1, &$3, parm, &yyloc); }

template_arg_list:
		template_arg
	|	template_arg_list ',' template_arg	{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }
	
extends:
		':' extends_list	{ $$ = $2; }
	|	empty
	
extends_elem:
		template_arg
	
extends_list:
		extends_elem
	|	extends_list ',' extends_elem	{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }
	
type_class:
		T_CLASS template extends '{' class_body '}'	{ yoParserClass(&$$, &$2, &$3, &$5, parm, &yyloc); }

class_body_stmt:
		decl_arg_list end_stmt
	|	newline
	
class_body_stmt_list:
		class_body_stmt
	|	class_body_stmt_list class_body_stmt	{ yoParserList(&$$, &$1, &$2, parm, &yyloc); }
	
class_body:
		class_body_stmt_list
	|	empty
	
type_base:	
		type_name
	|	type_const
	|	type_mutable
	|	type_chan
	|	type_ptr
	|	type_ref
	|	type_slice
	|	type_arr
	|	type_func
	
type_ext:
		type_base
	|	type_contract
	|	type_class
			
top_decl_func:
	|	T_FUNC decl_self dotname '(' decl_arg_list_or_empty ')' type_or_empty '{' func_body '}'	
			{ yoParserDeclFunc(&$$, T_FUNC, &$2, &$3, &$5, &$7, &$9, parm, &yyloc); }
	|	T_GET decl_self dotname '(' decl_arg_list_or_empty ')' type '{' func_body '}'	
			{ yoParserDeclFunc(&$$, T_GET, &$2, &$3, &$5, &$7, &$9, parm, &yyloc); }
	|	T_SET decl_self dotname '(' decl_arg_list ')' '{' func_body '}'	
			{ yoParserDeclFunc(&$$, T_SET, &$2, &$3, &$5, NULL, &$8, parm, &yyloc); }

decl_func:
		T_FUNC T_NAME '(' decl_arg_list_or_empty ')' type_or_empty '{' func_body '}' { 
			yoParserDeclVar(&$3, &$2, NULL, parm, &yyloc); 
			yoParserDeclFunc(&$1, T_SUB_FUNC, NULL, &$2, &$4, &$6, &$8, parm, &yyloc);
			yoParserAssign(&$2, &$2, &$1, T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&$$, &$3, &$2, parm, &yyloc);			
		}
			
expr_decl_func:
		T_FUNC empty '(' decl_arg_list_or_empty ')' type_or_empty '{' func_body '}'	
			{ yoParserDeclFunc(&$$, T_SUB_FUNC, NULL, NULL, &$4, &$6, &$8, parm, &yyloc); }
	|	'{' T_OR name_list T_OR lambda_body '}'
			{ yoParserDeclFunc(&$$, T_LAMBDA, NULL, NULL, &$3, NULL, &$5, parm, &yyloc); }
	|	'{' T_OROR lambda_body '}'
			{ yoParserDeclFunc(&$$, T_LAMBDA, NULL, NULL, NULL, NULL, &$3, parm, &yyloc); }

lambda_body:
		expr		{ yoParserStmtReturn(&$$, &$1, parm, &yyloc); }
	|	func_body
		
type_self:
		type_name
	|	T_MUL type_name					{ yoParserTypePtr(&$$, &$2, parm, &yyloc); }
	|	T_MUL T_MUTABLE type_name		{ yoParserTypeMutable(&$$, &$3, parm, &yyloc); yoParserTypePtr(&$$, &$$, parm, &yyloc); }
	|	T_AND type_name					{ yoParserTypeRef(&$$, &$2, parm, &yyloc); }
	|	T_AND T_MUTABLE type_name		{ yoParserTypeMutable(&$$, &$3, parm, &yyloc); yoParserTypeRef(&$$, &$$, parm, &yyloc); }
			
decl_self:
		'(' T_NAME type_self ')'		{ yoParserDeclArg(&$$, &$2, &$3, parm, &yyloc); }
	|	empty
			
decl_arg_list_or_empty:
		decl_arg_list
	|	empty

decl_arg_list:
		decl_arg
	|	decl_arg_list ',' decl_arg	{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }

decl_arg:
		name_list type	{ yoParserDeclArg(&$$, &$1, &$2, parm, &yyloc); }

func_body:
		stmt_list
	|	empty

/*
type_list:
		type
	|	type_list ',' type	{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }
*/

decl_self_nop:	
		empty
	
type_func:
		T_FUNC decl_self_nop '(' decl_arg_list_or_empty ')'			{ yoParserTypeFunc(&$$, T_FUNC, &$2, &$4, NULL, parm, &yyloc); }
	|	T_FUNC decl_self_nop '(' decl_arg_list_or_empty ')' type	{ yoParserTypeFunc(&$$, T_FUNC, &$2, &$4, &$6, parm, &yyloc); }
	|	T_GET decl_self_nop '(' decl_arg_list_or_empty ')' type		{ yoParserTypeFunc(&$$, T_GET, &$2, &$4, &$6, parm, &yyloc); }
	|	T_SET decl_self_nop '(' decl_arg_list ')'					{ yoParserTypeFunc(&$$, T_SET, &$2, &$4, NULL, parm, &yyloc); }

type:
		type_base
	|	type_contract_empty

type_const:
		T_CONST type	{ yoParserTypeConst(&$$, &$2, parm, &yyloc); }

type_mutable:
		T_MUTABLE type	{ yoParserTypeMutable(&$$, &$2, parm, &yyloc); }

type_chan:
		T_CHAN type	{ yoParserTypeChan(&$$, &$2, parm, &yyloc); }

type_ref:
		T_AND type	{ yoParserTypeRef(&$$, &$2, parm, &yyloc); }
		
type_ptr:
		T_MUL type	{ yoParserTypePtr(&$$, &$2, parm, &yyloc); }
	|	T_POW type	{ yoParserTypePtr(&$$, &$2, parm, &yyloc); yoParserTypePtr(&$$, &$$, parm, &yyloc); }
/*
		type T_MUL %prec T_PTR	{ yoParserTypePtr(&$$, &$1, parm, &yyloc); }
	|	type T_POW %prec T_PTR	{ yoParserTypePtr(&$$, &$1, parm, &yyloc); yoParserTypePtr(&$$, &$$, parm, &yyloc); }
*/

type_slice:
		'[' ']' type	{ yoParserTypeSlice(&$$, &$3, parm, &yyloc); }
/*		'[' ']' type %prec T_ARR	{ yoParserTypeSlice(&$$, &$3, parm, &yyloc); } */

type_arr_size:
		T_LNUMBER
	|	dotname

type_arr:
		'[' type_arr_size ']' type	{ yoParserTypeArr(&$$, &$2, &$4, parm, &yyloc); }
/*		'[' type_arr_size ']' type %prec T_ARR	{ yoParserTypeArr(&$$, &$2, &$4, parm, &yyloc); } */

type_name:
		type_std_name
	/* |	dotname			{ yoParserTypeName(&$$, &$1, NULL, parm, &yyloc); } */
	|	dotname template	{ yoParserTypeName(&$$, &$1, &$2, parm, &yyloc); }

type_std_name:
		T_INT8		{ yoParserTypeStdName(&$$, T_INT8, parm, &yyloc); }
	|	T_INT16		{ yoParserTypeStdName(&$$, T_INT16, parm, &yyloc); }
	|	T_INT32		{ yoParserTypeStdName(&$$, T_INT32, parm, &yyloc); }
	|	T_INT64		{ yoParserTypeStdName(&$$, T_INT64, parm, &yyloc); }
	|	T_UINT8		{ yoParserTypeStdName(&$$, T_UINT8, parm, &yyloc); }
	|	T_UINT16	{ yoParserTypeStdName(&$$, T_UINT16, parm, &yyloc); }
	|	T_UINT32	{ yoParserTypeStdName(&$$, T_UINT32, parm, &yyloc); }
	|	T_UINT64	{ yoParserTypeStdName(&$$, T_UINT64, parm, &yyloc); }
	|	T_UINTPTR	{ yoParserTypeStdName(&$$, T_UINTPTR, parm, &yyloc); }
	|	T_STRING	{ yoParserTypeStdName(&$$, T_STRING, parm, &yyloc); }
	|	T_FLOAT32	{ yoParserTypeStdName(&$$, T_FLOAT32, parm, &yyloc); }
	|	T_FLOAT64	{ yoParserTypeStdName(&$$, T_FLOAT64, parm, &yyloc); }
	|	T_BOOL		{ yoParserTypeStdName(&$$, T_BOOL, parm, &yyloc); }
	|	T_VOID		{ yoParserTypeStdName(&$$, T_VOID, parm, &yyloc); }
	|	'?'			{ yoParserTypeStdName(&$$, T_UNKNOWN_YET, parm, &yyloc); }

expr_const_scalar:
		T_TRUE		{ yoParserConst(&$$, T_TRUE, parm, &yyloc); }
	|	T_FALSE		{ yoParserConst(&$$, T_FALSE, parm, &yyloc); }
	|	T_NULL		{ yoParserConst(&$$, T_NULL, parm, &yyloc); }
	|	T_LNUMBER
	| 	T_DNUMBER
	|	T_SSTRING
	|	T_QSTRING

expr_list:
		expr
	|	expr_list ',' expr		{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }

expr_arr:
		'{' '}'				{ yoParserNewArr(&$$, parm, &yyloc); }
	|	'{' expr_list '}'	{ yoParserNewArrExps(&$$, &$2, parm, &yyloc); }

expr_obj:
		dotname '{' '}'			{ yoParserNewObj(&$$, &$1, parm, &yyloc); }
	|	dotname '{' expr_list '}'	{ yoParserNewObjExps(&$$, &$1, &$3, parm, &yyloc); }
	|	dotname '{' prop_assing_list '}'	{ yoParserNewObjProps(&$$, &$1, &$3, parm, &yyloc); }

prop_assing_list:
		prop_assing
	|	prop_assing_list ',' prop_assing	{ yoParserList(&$$, &$1, &$3, parm, &yyloc); }

prop_assing:
		dotname T_ASSIGN expr			{ yoParserAssign(&$$, &$1, &$3, T_PROP_ASSIGN, parm, &yyloc); }

qstr_with_inject_begin_elem:
		T_QSTRING_INJECT_EXRP expr_base { yoParserBinOp(&$$, &$1, &$2, T_CONCAT, parm, &yyloc); }

qstr_with_inject_begin_list:
		qstr_with_inject_begin_elem
	|	qstr_with_inject_begin_list qstr_with_inject_begin_elem { yoParserBinOp(&$$, &$1, &$2, T_CONCAT, parm, &yyloc); }

qstr_with_inject:
		qstr_with_inject_begin_list T_QSTRING { yoParserBinOp(&$$, &$1, &$2, T_CONCAT, parm, &yyloc); }
	
expr:
		expr_base
	|	qstr_with_inject
	
expr_base:
		expr_const_scalar
	|	expr_for_assign
	|	expr_arr
	|	expr_obj
	|	expr T_PLUS expr	{ yoParserBinOp(&$$, &$1, &$3, T_PLUS, parm, &yyloc); }
	|	expr T_MINUS expr	{ yoParserBinOp(&$$, &$1, &$3, T_MINUS, parm, &yyloc); }
	|	expr T_MUL expr		{ yoParserBinOp(&$$, &$1, &$3, T_MUL, parm, &yyloc); }
	|	expr T_DIV expr		{ yoParserBinOp(&$$, &$1, &$3, T_DIV, parm, &yyloc); }
	|	expr T_MOD expr		{ yoParserBinOp(&$$, &$1, &$3, T_MOD, parm, &yyloc); }
	|	expr T_CONCAT expr	{ yoParserBinOp(&$$, &$1, &$3, T_CONCAT, parm, &yyloc); }
	|	expr T_OR expr  	{ yoParserBinOp(&$$, &$1, &$3, T_OR, parm, &yyloc); }
	|	expr T_OROR expr  	{ yoParserBinOp(&$$, &$1, &$3, T_OROR, parm, &yyloc); }
	|	expr T_AND expr  	{ yoParserBinOp(&$$, &$1, &$3, T_AND, parm, &yyloc); }
	|	expr T_ANDAND expr  { yoParserBinOp(&$$, &$1, &$3, T_ANDAND, parm, &yyloc); }
	|	expr T_XOR expr  	{ yoParserBinOp(&$$, &$1, &$3, T_XOR, parm, &yyloc); }
	|	expr T_XORXOR expr  { yoParserBinOp(&$$, &$1, &$3, T_XORXOR, parm, &yyloc); }
	|	expr T_CHAN_ACCESS expr  { yoParserBinOp(&$$, &$1, &$3, T_CHAN_ACCESS, parm, &yyloc); }
	|	'(' expr ')'		{ $$ = $2; }
	|	call
	|	expr_decl_func
	|	expr T_AS type		{ yoParserCast(&$$, &$1, &$3, parm, &yyloc); }
	|	expr T_DOT '(' type ')'	{ yoParserCast(&$$, &$1, &$4, parm, &yyloc); }
	|	T_PLUS	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_PLUS, parm, &yyloc); }
	|	T_MINUS expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_MINUS, parm, &yyloc); }
	|	T_NOT 	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_NOT, parm, &yyloc); }
	|	T_TILDE expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_TILDE, parm, &yyloc); }
	|	T_CHAN_ACCESS expr %prec T_UNARY { yoParserUnaryOp(&$$, &$2, T_CHAN_ACCESS, parm, &yyloc); }
/*	|	'(' type ')' expr %prec T_UNARY */
/*	|	T_AT  T_NAME %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_AT, parm, &yyloc); } */

expr_for_assign:
		dotname
	|	expr T_DOT dotname  { yoParserBinOp(&$$, &$1, &$3, T_DOT, parm, &yyloc); }
	|	expr '[' expr ']'	{ yoParserBinOp(&$$, &$1, &$3, T_INDEX, parm, &yyloc); }
	|	T_MUL 	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_INDIRECT, parm, &yyloc); }
	|	T_AND	expr %prec T_UNARY	{ yoParserUnaryOp(&$$, &$2, T_ADDR, parm, &yyloc); }
		
assign:
		expr_for_assign T_ASSIGN expr	{ yoParserAssign(&$$, &$1, &$3, T_ASSIGN, parm, &yyloc); }
		
call_args:
		expr_list
	|	empty
	
call:
		dotname '(' call_args ')'	{ yoParserCall(&$$, &$1, &$3, parm, &yyloc); }
	|	expr T_DOT dotname '(' call_args ')' { 
			yoParserBinOp(&$$, &$1, &$3, T_DOT, parm, &yyloc);
			yoParserCall(&$$, &$$, &$5, parm, &yyloc);
		}

%%
