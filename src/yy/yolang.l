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
#define YYFILL(n) { if ((YYCURSOR + n) >= (YYLIMIT + YO_LEX_MAXFILL)) { return 0; } }
#define YYCURSOR  parser->cursor
#define YYLIMIT   parser->limit
#define YYMARKER  parser->marker

#if 0
#define YYGETSTATE()  parser->state
#define YYSETSTATE(s) parser->state = s
#define yych		 parser->ch
#define yyaccept	 parser->accept
#endif

#define YYGETCONDITION()  parser->state
#define YYSETCONDITION(c) parser->state = c

#define STATE(name)  YO_##name

/* emulate flex constructs */
#define BEGIN(state) YYSETSTATE(STATE(state))
#define YYSTATE      YYGETSTATE()
#define yytext       parser->text
#define yyleng       parser->textLen
#define yyless(x)    do { YYCURSOR = (YYCTYPE*)yytext + x; yyleng = (int)x; } while(0)
#define yymore()     goto yymore_restart

/* perform sanity check. If this message is triggered you should
   increase the YO_LEX_MAXFILL value in the zend_streams.h file */
/*!max:re2c */
#if YO_LEX_MAXFILL < YYMAXFILL
# error YO_LEX_MAXFILL should be greater than or equal to YYMAXFILL
#endif 

int yoLexDec(void*, YYSTYPE*);
int yoLexBin(void*, YYSTYPE*);
int yoLexHex(void*, YYSTYPE*);
int yoLexFloat(void*, YYSTYPE*);
int yoLexName(void*, YYSTYPE*);
int yoLexChar(void*, YYSTYPE*);
void yoLexLineComment(void*);
void yoLexMultiLineComment(void*);
void yoLexNewLine(void*);
int yoLexSingleQuotedString(void * parm, YYSTYPE * elem);
int yoLexQuotedString(void * parm, YYSTYPE * elem);
int yoLexInjectOpenBrace(void * parm, YYSTYPE*);
int yoLexInjectCloseBrace(void * parm, YYSTYPE*);
int yoLexOpenBrace(void * parm);
int yoLexOpenBracket(void * parm);
int yoLexCloseBracket(void * parm);

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
SINGLE_QUOTE = ['];
QUOTE 		= ["];
OPEN_BRACKET	= ("("|"{");
CLOSE_BRACKET	= (")"|"}");

/* compute yyleng before each rule */
<!*> := yyleng = YYCURSOR - yytext;

<ST_YOLANG,ST_INJECT>"@" { return T_AT; }
<ST_YOLANG,ST_INJECT>"." { return T_DOT; }
<ST_YOLANG,ST_INJECT>"+" { return T_PLUS; }
<ST_YOLANG,ST_INJECT>"-" { return T_MINUS; }
<ST_YOLANG,ST_INJECT>"*" { return T_MUL; }
<ST_YOLANG,ST_INJECT>"/" { return T_DIV; }
<ST_YOLANG,ST_INJECT>"%" { return T_MOD; }
<ST_YOLANG,ST_INJECT>"**" { return T_POW; }
<ST_YOLANG,ST_INJECT>".." { return T_CONCAT; }

<ST_YOLANG,ST_INJECT>"=" { return T_ASSIGN; }
<ST_YOLANG,ST_INJECT>":=" { return T_DECL_ASSIGN; }
<ST_YOLANG,ST_INJECT>"+=" { return T_PLUS_ASSIGN; }
<ST_YOLANG,ST_INJECT>"-=" { return T_MINUS_ASSIGN; }
<ST_YOLANG,ST_INJECT>"*=" { return T_MUL_ASSIGN; }
<ST_YOLANG,ST_INJECT>"/=" { return T_DIV_ASSIGN; }
<ST_YOLANG,ST_INJECT>"%=" { return T_MOD_ASSIGN; }
<ST_YOLANG,ST_INJECT>"**=" { return T_POW_ASSIGN; }
<ST_YOLANG,ST_INJECT>"..=" { return T_CONCAT_ASSIGN; }

<ST_YOLANG,ST_INJECT>"|" { return T_OR; }
<ST_YOLANG,ST_INJECT>"&" { return T_AND; }
<ST_YOLANG,ST_INJECT>"^" { return T_XOR; }

<ST_YOLANG,ST_INJECT>"||" { return T_OROR; }
<ST_YOLANG,ST_INJECT>"&&" { return T_ANDAND; }
<ST_YOLANG,ST_INJECT>"^^" { return T_XORXOR; }

<ST_YOLANG,ST_INJECT>"==" { return T_EQ; }
<ST_YOLANG,ST_INJECT>"!=" { return T_NE; }
<ST_YOLANG,ST_INJECT>"<=" { return T_LE; }
<ST_YOLANG,ST_INJECT>">=" { return T_GE; }
<ST_YOLANG,ST_INJECT>"<" { return T_LT; }
<ST_YOLANG,ST_INJECT>">" { return T_GT; }

<ST_YOLANG,ST_INJECT>{TABS_AND_SPACES} { goto restart; }
<ST_YOLANG,ST_INJECT>{NEWLINE} { return T_NEWLINE; }
<ST_YOLANG,ST_INJECT>"..." { return T_ELLIPSIS; }
/* <ST_YOLANG,ST_INJECT>"[]" { return T_SLICE; } */

<ST_YOLANG,ST_INJECT>"char" { return T_INT8; }
<ST_YOLANG,ST_INJECT>"byte" { return T_INT8; }

<ST_YOLANG,ST_INJECT>"int8"  { return T_INT8; }
<ST_YOLANG,ST_INJECT>"int16" { return T_INT16; }
<ST_YOLANG,ST_INJECT>"int32" { return T_INT32; }
<ST_YOLANG,ST_INJECT>"int64" { return T_INT64; }
<ST_YOLANG,ST_INJECT>"int"	  { return sizeof(int) == 8 ? T_INT64 : T_INT32; }

<ST_YOLANG,ST_INJECT>"uint8"	{ return T_UINT8; }
<ST_YOLANG,ST_INJECT>"uint16"	{ return T_UINT16; }
<ST_YOLANG,ST_INJECT>"uint32"	{ return T_UINT32; }
<ST_YOLANG,ST_INJECT>"uint64"	{ return T_UINT64; }
<ST_YOLANG,ST_INJECT>"uint"	{ return sizeof(int) == 8 ? T_UINT64 : T_UINT32; }

<ST_YOLANG,ST_INJECT>"uintptr" { return T_UINTPTR; }

<ST_YOLANG,ST_INJECT>"float32" { return T_FLOAT32; }
<ST_YOLANG,ST_INJECT>"float64" { return T_FLOAT64; }

<ST_YOLANG,ST_INJECT>"float" 	{ return T_FLOAT32; }
<ST_YOLANG,ST_INJECT>"double" 	{ return T_FLOAT64; }

<ST_YOLANG,ST_INJECT>"string" { return T_STRING; }
<ST_YOLANG,ST_INJECT>"bool" { return T_BOOL; }
<ST_YOLANG,ST_INJECT>"true" { return T_TRUE; }
<ST_YOLANG,ST_INJECT>"false" { return T_FALSE; }
<ST_YOLANG,ST_INJECT>"null" { return T_NULL; }

<ST_YOLANG,ST_INJECT>"void" { return T_VOID; }
<ST_YOLANG,ST_INJECT>"return" { return T_RETURN; }
<ST_YOLANG,ST_INJECT>"var" { return T_VAR; }
<ST_YOLANG,ST_INJECT>"type" { return T_TYPE; }
<ST_YOLANG,ST_INJECT>"chan" { return T_CHAN; }
<ST_YOLANG,ST_INJECT>"func" { return T_FUNC; }
<ST_YOLANG,ST_INJECT>"const" { return T_CONST; }
<ST_YOLANG,ST_INJECT>"struct" { return T_STRUCT; }
<ST_YOLANG,ST_INJECT>"class" { return T_CLASS; }
<ST_YOLANG,ST_INJECT>"interface" { return T_INTERFACE; }
<ST_YOLANG,ST_INJECT>"if" { return T_IF; }
<ST_YOLANG,ST_INJECT>"else" { return T_ELSE; }
<ST_YOLANG,ST_INJECT>"elseif" { return T_ELSEIF; }
<ST_YOLANG,ST_INJECT>"catch" { return T_CATCH; }
<ST_YOLANG,ST_INJECT>"as" { return T_AS; }

<ST_YOLANG>"{"	{ return yoLexOpenBrace(parser); }
<ST_INJECT>"{"	{ return yoLexInjectOpenBrace(parser, parserNode); }
<ST_INJECT>"}"	{ return yoLexInjectCloseBrace(parser, parserNode); }

<ST_YOLANG,ST_INJECT>{OPEN_BRACKET}	{ return yoLexOpenBracket(parser); }
<ST_YOLANG,ST_INJECT>{CLOSE_BRACKET} { return yoLexCloseBracket(parser); }

<ST_YOLANG,ST_INJECT>{NAME} { return yoLexName(parser, parserNode); }
<ST_YOLANG,ST_INJECT>{LNUM} { return yoLexDec(parser, parserNode); }
<ST_YOLANG,ST_INJECT>{BNUM} { return yoLexBin(parser, parserNode); }
<ST_YOLANG,ST_INJECT>{HNUM} { return yoLexHex(parser, parserNode); }
<ST_YOLANG,ST_INJECT>{DNUM}|{EXPONENT_DNUM} { return yoLexFloat(parser, parserNode); }

<ST_YOLANG,ST_INJECT>"//" { yoLexLineComment(parser); goto restart; }
<ST_YOLANG,ST_INJECT>"/*" { yoLexMultiLineComment(parser); goto restart; }

<ST_YOLANG,ST_INJECT>{SINGLE_QUOTE} { return yoLexSingleQuotedString(parser, parserNode); }
<ST_YOLANG,ST_INJECT>{QUOTE}	{ return yoLexQuotedString(parser, parserNode); }

<ST_YOLANG,ST_INJECT>{ANY_CHAR} { return yoLexChar(parser, parserNode); }

*/

/*
comment:
re2c:yyfill:check = 0;
<ST_YOLANG,ST_INJECT>"*?	{ goto restart; } 
<ST_YOLANG,ST_INJECT>{NEWLINE} { yoLexNewLine(parser); goto comment; }
<ST_YOLANG,ST_INJECT>{ANY_CHAR} { goto comment; }
*/
}
