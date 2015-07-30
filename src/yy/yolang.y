%{
#include <stdio.h>
#include <stdlib.h>
#include "yoparser.h"

extern void yoParserEnd(YYSTYPE*, void*);
extern void yoParserBinOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void*);
extern void yoParserBeginUnaryOp(YYSTYPE * r, int op, void*);
extern void yoParserEndUnaryOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * op, void*);
extern void yoParserConst(YYSTYPE * r, int op, void*);
extern void yoParserStdTypeName(YYSTYPE * r, int op, void*);
extern void yoParserTypeName(YYSTYPE * r, YYSTYPE * a, void*);
extern void yoParserPkgTypeName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
extern void yoParserTypeSpec(YYSTYPE * r, YYSTYPE * a, EYoParserTypeSpec spec, void * parm);
extern void yoParserTypeArray(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm);
extern void yoParserDeclVar(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
extern void yoParserStatementList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
// extern void yoParserMakeStatement(YYSTYPE * r, void*);
extern void yoParserNewLine(void*);

extern int yolex(YYSTYPE*, void * parser);
extern void yyerror(const char* s);

%}

%verbose
%pure_parser
%error-verbose

%token T_ELLIPSIS
%token T_INT8 T_INT16 T_INT32 T_INT64
%token T_UINT8 T_UINT16 T_UINT32 T_UINT64 T_UINTPTR
%token T_FLOAT32 T_FLOAT64
%token T_STRING
%token T_BOOL T_TRUE T_FALSE
%token T_NULL
%token T_VOID
%token T_VAR
%token T_CONST
%token T_STRUCT
%token T_CLASS

%token T_LNUMBER
%token T_DNUMBER
%token T_NAME
%token T_NEWLINE
%token T_SLICE

%left ','

%left T_ASSIGN T_PLUS_ASSIGN T_MINUS_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_CONCAT_ASSIGN T_MOD_ASSIGN T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN T_LSH_ASSIGN T_RSH_ASSIGN T_POW_ASSIGN
%token T_ASSIGN  		"= (T_ASSIGN)"
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

%left	T_EQ T_NE T_LE T_GE T_LT T_GT
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

%nonassoc T_IS
%token T_IS  "is (T_IS)"

%right T_NOT T_TILDE T_AT T_INC T_DEC T_UNARY
%token T_NOT	"! (T_NOT)"
%token T_TILDE	"~ (T_TILDE)"
%token T_AT		"@ (T_AT)"
%token T_INC	"++ (T_INC)"
%token T_DEC	"-- (T_DEC)"
%token T_UNARY

%right '[' 

%left	T_DOT
%token	T_DOT	". (T_DOT)"

%token	T_INDIRECT	"* (T_INDIRECT)"
%token	T_ADDR		"& (T_ADDR)"

/*
%destructor { delete $$; } <data>
*/

%start file

%%

file:
	statement_list	{ yoParserEnd(&$$, parm); }
;

statement_list: 
		statement_list statement	{ yoParserStatementList(&$$, &$1, &$2, parm); }
	|	/* empty */
;

statement: 
		T_NAME T_ASSIGN expr end_statement	{ yoParserBinOp(&$$, &$1, &$3, T_ASSIGN, parm); }
	|	type T_NAME end_statement { yoParserDeclVar(&$$, &$1, &$2, parm); }
	|	type T_NAME T_ASSIGN expr end_statement { 
				yoParserDeclVar(&$1, &$1, &$2, parm); 
				yoParserBinOp(&$3, &$2, &$4, T_ASSIGN, parm); 
				yoParserStatementList(&$$, &$1, &$3, parm);
			}
;

type:
		type_name			{ yoParserTypeSpec(&$$, &$1, YO_TYPE_SPEC_VALUE, parm); }
	|	type_name T_MUL		{ yoParserTypeSpec(&$$, &$1, YO_TYPE_SPEC_PTR, parm); }
	|	type_name T_SLICE	{ yoParserTypeSpec(&$$, &$1, YO_TYPE_SPEC_SLICE, parm); }
	|	type_name '[' T_LNUMBER ']'	{ yoParserTypeArray(&$$, &$1, &$3, parm); }
;

type_name:
		std_type_name	{ $$ = $1; }
	|	T_NAME			{ yoParserTypeName(&$$, &$1, parm); }
	|	T_NAME T_DOT T_NAME	{ yoParserPkgTypeName(&$$, &$1, &$3, parm); }
;

std_type_name:
		T_INT8		{ yoParserStdTypeName(&$$, T_INT8, parm); }
	|	T_INT16		{ yoParserStdTypeName(&$$, T_INT16, parm); }
	|	T_INT32		{ yoParserStdTypeName(&$$, T_INT32, parm); }
	|	T_INT64		{ yoParserStdTypeName(&$$, T_INT64, parm); }
	|	T_UINT8		{ yoParserStdTypeName(&$$, T_UINT8, parm); }
	|	T_UINT16	{ yoParserStdTypeName(&$$, T_UINT16, parm); }
	|	T_UINT32	{ yoParserStdTypeName(&$$, T_UINT32, parm); }
	|	T_UINT64	{ yoParserStdTypeName(&$$, T_UINT64, parm); }
	|	T_UINTPTR	{ yoParserStdTypeName(&$$, T_UINTPTR, parm); }
	|	T_STRING	{ yoParserStdTypeName(&$$, T_STRING, parm); }
	|	T_FLOAT32	{ yoParserStdTypeName(&$$, T_FLOAT32, parm); }
	|	T_FLOAT64	{ yoParserStdTypeName(&$$, T_FLOAT64, parm); }
	|	T_BOOL		{ yoParserStdTypeName(&$$, T_BOOL, parm); }
	|	T_VOID		{ yoParserStdTypeName(&$$, T_VOID, parm); }
;

end_statement:
		T_NEWLINE	{ yoParserNewLine(parm); }
	|	';'
	|	/* empty */
;

expr: 
		T_TRUE		{ yoParserConst(&$$, T_TRUE, parm); }
	|	T_FALSE		{ yoParserConst(&$$, T_FALSE, parm); }
	|	T_NULL		{ yoParserConst(&$$, T_NULL, parm); }
	|	T_LNUMBER	{ $$ = $1; }
	| 	T_DNUMBER	{ $$ = $1; }
	| 	T_NAME		{ $$ = $1; }
	| 	uexpr		{ $$ = $1; }
	|	expr T_PLUS expr	{ yoParserBinOp(&$$, &$1, &$3, T_PLUS, parm); }
	|	expr T_MINUS expr	{ yoParserBinOp(&$$, &$1, &$3, T_MINUS, parm); }
	|	expr T_MUL expr		{ yoParserBinOp(&$$, &$1, &$3, T_MUL, parm); }
	|	expr T_DIV expr		{ yoParserBinOp(&$$, &$1, &$3, T_DIV, parm); }
	|	expr T_MOD expr		{ yoParserBinOp(&$$, &$1, &$3, T_MOD, parm); }
	|	'(' expr ')'	{ $$ = $2; }
;

uexpr:
		T_PLUS	{ yoParserBeginUnaryOp(&$1, T_PLUS, parm); } 		expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
	|	T_MINUS { yoParserBeginUnaryOp(&$1, T_MINUS, parm); } 		expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
	|	T_NOT 	{ yoParserBeginUnaryOp(&$1, T_NOT, parm); } 		expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
	|	T_TILDE { yoParserBeginUnaryOp(&$1, T_TILDE, parm); } 		expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
	|	T_AT 	{ yoParserBeginUnaryOp(&$1, T_AT, parm); } 			expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
	|	T_INDIRECT { yoParserBeginUnaryOp(&$1, T_INDIRECT, parm); } expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
	|	T_ADDR	{ yoParserBeginUnaryOp(&$1, T_ADDR, parm); } 		expr %prec T_UNARY { yoParserEndUnaryOp(&$$, &$3, &$1, parm); }
;


%%
