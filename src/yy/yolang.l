#include "yoparser.h"

// #define YYPARSE_PARAM parm
// #define YYLEX_PARAM parm

// #define YY_DECL int yolex(YYSTYPE *lvalp)

#ifdef YYDEBUG
#undef YYDEBUG
#endif

#if 1
# define YYDEBUG(s, c) printf("state: %d char: %c\n", s, c)
#else
# define YYDEBUG(s, c)
#endif

// #include "yolang-y.h"

#define YYCTYPE   unsigned char
#define YYFILL(n) { if ((YYCURSOR + n) >= (YYLIMIT + YO_LEX_LEN_AHEAD)) { return 0; } }
#define YYCURSOR  parser->cursor
#define YYLIMIT   parser->limit
#define YYMARKER  parser->marker

#if 0
#define YYGETSTATE()  parser->state
#define YYSETSTATE(s) parser->state = s
#define yych		 parser->ch
#define yyaccept	 parser->accept
#endif

#define YYGETCONDITION()  parser->condition
#define YYSETCONDITION(c) parser->condition = c

#define STATE(name)  YO_##name

/* emulate flex constructs */
#define BEGIN(state) YYSETSTATE(STATE(state))
#define YYSTATE      YYGETSTATE()
#define yytext       parser->text
#define yyleng       parser->textLen
#define yyless(x)    do { YYCURSOR = (YYCTYPE*)yytext + x; yyleng = (int)x; } while(0)
#define yymore()     goto yymore_restart

/* perform sanity check. If this message is triggered you should
   increase the YO_LEX_LEN_AHEAD value in the zend_streams.h file */
/*!max:re2c */
#if YO_LEX_LEN_AHEAD < YYMAXFILL
# error YO_LEX_LEN_AHEAD should be greater than or equal to YYMAXFILL
#endif 

int yoLexDec(void*, YYSTYPE*);
int yoLexBin(void*, YYSTYPE*);
int yoLexHex(void*, YYSTYPE*);
int yoLexFloat(void*, YYSTYPE*);
int yoLexName(void*, YYSTYPE*);
int yoLexChar(void*, YYSTYPE*);
void yoLexNewLine(void*);

int yolex(YYSTYPE * parserNode, void * parm)
{
	YoParserParams * parser = (YoParserParams*)parm;
	// YYMARKER = YYCURSOR;
	
restart:
	yytext = YYCURSOR;

// yymore_restart:

	// -f option
	// YYCTYPE yych;
	// unsigned int yyaccept = 0;
	
/*!re2c
re2c:yyfill:check = 0;
LNUM		= [0-9]+;
DNUM		= ([0-9]*"."[0-9]+)|([0-9]+"."[0-9]*);
EXPONENT_DNUM = (({LNUM}|{DNUM})[eE][+-]?{LNUM});
HNUM		= "0x"[0-9a-fA-F]+;
BNUM		= "0b"[01]+;
NAME		= [a-zA-Z_\x7f-\xff][a-zA-Z0-9_\@\x7f-\xff]*;
WHITESPACES = [ \n\r\t]+;
TABS_AND_SPACES = [ \t]+;
TOKENS		= [;:,.\[\]()|^&+-/*=%!~$<>?@];
ANY_CHAR	= [^];
NEWLINE		= ("\r"|"\n"|"\r\n");

/* compute yyleng before each rule */
<!*> := yyleng = YYCURSOR - yytext;

<ST_IN_YOLANG>"@" { return T_AT; }
<ST_IN_YOLANG>"." { return T_DOT; }
<ST_IN_YOLANG>"+" { return T_PLUS; }
<ST_IN_YOLANG>"-" { return T_MINUS; }
<ST_IN_YOLANG>"*" { return T_MUL; }
<ST_IN_YOLANG>"/" { return T_DIV; }
<ST_IN_YOLANG>"%" { return T_MOD; }
<ST_IN_YOLANG>"**" { return T_POW; }
<ST_IN_YOLANG>".." { return T_CONCAT; }

<ST_IN_YOLANG>"=" { return T_ASSIGN; }
<ST_IN_YOLANG>":=" { return T_DECL_ASSIGN; }
<ST_IN_YOLANG>"+=" { return T_PLUS_ASSIGN; }
<ST_IN_YOLANG>"-=" { return T_MINUS_ASSIGN; }
<ST_IN_YOLANG>"*=" { return T_MUL_ASSIGN; }
<ST_IN_YOLANG>"/=" { return T_DIV_ASSIGN; }
<ST_IN_YOLANG>"%=" { return T_MOD_ASSIGN; }
<ST_IN_YOLANG>"**=" { return T_POW_ASSIGN; }
<ST_IN_YOLANG>"..=" { return T_CONCAT_ASSIGN; }

<ST_IN_YOLANG>"|" { return T_OR; }
<ST_IN_YOLANG>"&" { return T_AND; }
<ST_IN_YOLANG>"^" { return T_XOR; }

<ST_IN_YOLANG>"||" { return T_OROR; }
<ST_IN_YOLANG>"&&" { return T_ANDAND; }
<ST_IN_YOLANG>"^^" { return T_XORXOR; }

<ST_IN_YOLANG>"==" { return T_EQ; }
<ST_IN_YOLANG>"!=" { return T_NE; }
<ST_IN_YOLANG>"<=" { return T_LE; }
<ST_IN_YOLANG>">=" { return T_GE; }
<ST_IN_YOLANG>"<" { return T_LT; }
<ST_IN_YOLANG>">" { return T_GT; }

<ST_IN_YOLANG>{TABS_AND_SPACES} { goto restart; }
<ST_IN_YOLANG>{NEWLINE} { return T_NEWLINE; }
<ST_IN_YOLANG>"..." { return T_ELLIPSIS; }
/* <ST_IN_YOLANG>"[]" { return T_SLICE; } */

<ST_IN_YOLANG>"char" { return T_INT8; }
<ST_IN_YOLANG>"byte" { return T_INT8; }

<ST_IN_YOLANG>"int8"  { return T_INT8; }
<ST_IN_YOLANG>"int16" { return T_INT16; }
<ST_IN_YOLANG>"int32" { return T_INT32; }
<ST_IN_YOLANG>"int64" { return T_INT64; }
<ST_IN_YOLANG>"int"	  { return sizeof(int) == 8 ? T_INT64 : T_INT32; }

<ST_IN_YOLANG>"uint8"	{ return T_UINT8; }
<ST_IN_YOLANG>"uint16"	{ return T_UINT16; }
<ST_IN_YOLANG>"uint32"	{ return T_UINT32; }
<ST_IN_YOLANG>"uint64"	{ return T_UINT64; }
<ST_IN_YOLANG>"uint"	{ return sizeof(int) == 8 ? T_UINT64 : T_UINT32; }

<ST_IN_YOLANG>"uintptr" { return T_UINTPTR; }

<ST_IN_YOLANG>"float32" { return T_FLOAT32; }
<ST_IN_YOLANG>"float64" { return T_FLOAT64; }

<ST_IN_YOLANG>"float" 	{ return T_FLOAT32; }
<ST_IN_YOLANG>"double" 	{ return T_FLOAT64; }

<ST_IN_YOLANG>"string" { return T_STRING; }
<ST_IN_YOLANG>"bool" { return T_BOOL; }
<ST_IN_YOLANG>"true" { return T_TRUE; }
<ST_IN_YOLANG>"false" { return T_FALSE; }
<ST_IN_YOLANG>"null" { return T_NULL; }

<ST_IN_YOLANG>"void" { return T_VOID; }
<ST_IN_YOLANG>"var" { return T_VAR; }
<ST_IN_YOLANG>"type" { return T_TYPE; }
<ST_IN_YOLANG>"func" { return T_FUNC; }
<ST_IN_YOLANG>"const" { return T_CONST; }
<ST_IN_YOLANG>"struct" { return T_STRUCT; }
<ST_IN_YOLANG>"class" { return T_CLASS; }
<ST_IN_YOLANG>"interface" { return T_INTERFACE; }

<ST_IN_YOLANG>{NAME} { return yoLexName(parser, parserNode); }
<ST_IN_YOLANG>{LNUM} { return yoLexDec(parser, parserNode); }
<ST_IN_YOLANG>{BNUM} { return yoLexBin(parser, parserNode); }
<ST_IN_YOLANG>{HNUM} { return yoLexHex(parser, parserNode); }
<ST_IN_YOLANG>{DNUM}|{EXPONENT_DNUM} { return yoLexFloat(parser, parserNode); }

<ST_IN_YOLANG>{ANY_CHAR} { return yoLexChar(parser, parserNode); }

*/

/*
comment:
re2c:yyfill:check = 0;
<ST_IN_YOLANG>"*?	{ goto restart; } 
<ST_IN_YOLANG>{NEWLINE} { yoLexNewLine(parser); goto comment; }
<ST_IN_YOLANG>{ANY_CHAR} { goto comment; }
*/
}
