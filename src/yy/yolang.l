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
   increase the YO_LEX_MAXFILL value in the yoparser.h file */
/*!max:re2c */
#if YO_LEX_MAXFILL < YYMAXFILL
# error YO_LEX_MAXFILL should be greater than or equal to YYMAXFILL
#endif 

int yoLexIntRadix(YYSTYPE*, int radix, int skipEnd, void * parm, YYLTYPE*);
int yoLexFloat(YYSTYPE*, int skipEnd, void * parm, YYLTYPE*);
int yoLexName(YYSTYPE*, void * parm, YYLTYPE*);
int yoLexChar(YYSTYPE*, void * parm, YYLTYPE*);
void yoLexLineComment(void * parm, YYLTYPE*);
void yoLexMultiLineComment(void * parm, YYLTYPE*);
void yoLexNewLine(void * parm, YYLTYPE*);
int yoLexSingleQuotedString(YYSTYPE * elem, void * parm, YYLTYPE*);
int yoLexQuotedString(YYSTYPE * elem, void * parm, YYLTYPE*);
int yoLexInjectOpenBrace(YYSTYPE*, void * parm, YYLTYPE*);
int yoLexInjectCloseBrace(YYSTYPE*, void * parm, YYLTYPE*);
int yoLexOpenBrace(void * parm, YYLTYPE*);
int yoLexOpenBracket(void * parm, YYLTYPE*);
int yoLexCloseBracket(void * parm, YYLTYPE*);
void yoLexTrackRule(YYSTYPE*, void * parm, YYLTYPE*);

int yolex(YYSTYPE * parserElem, YYLTYPE * parserLoc, void * parm)
{
	YoParser * parser = (YoParser*)parm;
	// YYMARKER = YYCURSOR;
	
restart:
	yytext = YYCURSOR;

// yymore_restart:

	// -f option
	// YYCTYPE yych;
	// unsigned int yyaccept = 0;
	
/*!re2c
re2c:yyfill:check = 0;
LNUM		= [0-9][0-9_]*;
DNUM		= {LNUM}"."{LNUM};
EXPONENT_DNUM = (({LNUM}|{DNUM})[eE][+-]?{LNUM});
HNUM		= "0x"[0-9a-fA-F][0-9a-fA-F_]*;
BNUM		= "0b"[01][01_]*;
/* ONUM		= "0"[0-7][0-7_]*; */
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
<!*> := yoLexTrackRule(parserElem, parm, parserLoc); // yyleng = YYCURSOR - yytext;

<ST_YOLANG,ST_INJECT>"!" { return T_NOT; }
<ST_YOLANG,ST_INJECT>"~" { return T_TILDE; }
<ST_YOLANG,ST_INJECT>"@" { return T_AT; }
<ST_YOLANG,ST_INJECT>"." { return T_DOT; }
<ST_YOLANG,ST_INJECT>"+" { return T_PLUS; }
<ST_YOLANG,ST_INJECT>"-" { return T_MINUS; }
<ST_YOLANG,ST_INJECT>"*" { return T_MUL; }
<ST_YOLANG,ST_INJECT>"/" { return T_DIV; }
<ST_YOLANG,ST_INJECT>"%" { return T_MOD; }
<ST_YOLANG,ST_INJECT>"|" { return T_OR; }
<ST_YOLANG,ST_INJECT>"&" { return T_AND; }
<ST_YOLANG,ST_INJECT>"^" { return T_XOR; }
<ST_YOLANG,ST_INJECT>">>" { return T_RSH; }
<ST_YOLANG,ST_INJECT>"<<" { return T_LSH; }
<ST_YOLANG,ST_INJECT>"**" { return T_POW; }
<ST_YOLANG,ST_INJECT>".." { return T_CONCAT; }
<ST_YOLANG,ST_INJECT>"<-" { return T_CHAN_ACCESS; }

<ST_YOLANG,ST_INJECT>"++" { return T_INC; }
<ST_YOLANG,ST_INJECT>"--" { return T_DEC; }

<ST_YOLANG,ST_INJECT>"=" { return T_ASSIGN; }
<ST_YOLANG,ST_INJECT>":=" { return T_DECL_ASSIGN; }
<ST_YOLANG,ST_INJECT>"+=" { return T_PLUS_ASSIGN; }
<ST_YOLANG,ST_INJECT>"-=" { return T_MINUS_ASSIGN; }
<ST_YOLANG,ST_INJECT>"*=" { return T_MUL_ASSIGN; }
<ST_YOLANG,ST_INJECT>"/=" { return T_DIV_ASSIGN; }
<ST_YOLANG,ST_INJECT>"%=" { return T_MOD_ASSIGN; }
<ST_YOLANG,ST_INJECT>"|=" { return T_OR_ASSIGN; }
<ST_YOLANG,ST_INJECT>"&=" { return T_AND_ASSIGN; }
<ST_YOLANG,ST_INJECT>"^=" { return T_XOR_ASSIGN; }
<ST_YOLANG,ST_INJECT>">>=" { return T_RSH_ASSIGN; }
<ST_YOLANG,ST_INJECT>"<<=" { return T_LSH_ASSIGN; }
<ST_YOLANG,ST_INJECT>"**=" { return T_POW_ASSIGN; }
<ST_YOLANG,ST_INJECT>"..=" { return T_CONCAT_ASSIGN; }

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
<ST_YOLANG,ST_INJECT>"..." { return T_DOTDOTDOT; }
/* <ST_YOLANG,ST_INJECT>"[]" { return T_SLICE; } */

<ST_YOLANG,ST_INJECT>"char" { return T_UINT8; }
<ST_YOLANG,ST_INJECT>"byte" { return T_UINT8; }

<ST_YOLANG,ST_INJECT>"int8"  { return T_INT8; }
<ST_YOLANG,ST_INJECT>"int16" { return T_INT16; }
<ST_YOLANG,ST_INJECT>"int32" { return T_INT32; }
<ST_YOLANG,ST_INJECT>"int64" { return T_INT64; }
<ST_YOLANG,ST_INJECT>"int"	  { return T_INT; }

<ST_YOLANG,ST_INJECT>"uint8"	{ return T_UINT8; }
<ST_YOLANG,ST_INJECT>"uint16"	{ return T_UINT16; }
<ST_YOLANG,ST_INJECT>"uint32"	{ return T_UINT32; }
<ST_YOLANG,ST_INJECT>"uint64"	{ return T_UINT64; }
<ST_YOLANG,ST_INJECT>"uint"	{ return T_UINT; }

<ST_YOLANG,ST_INJECT>"intptr" { return T_INTPTR; }
<ST_YOLANG,ST_INJECT>"uintptr" { return T_UINTPTR; }

<ST_YOLANG,ST_INJECT>"float32"|"float" { return T_FLOAT32; }
<ST_YOLANG,ST_INJECT>"float64"|"double" { return T_FLOAT64; }

<ST_YOLANG,ST_INJECT>"string" { return T_STRING; }
<ST_YOLANG,ST_INJECT>"bool" { return T_BOOL; }
<ST_YOLANG,ST_INJECT>"true" { return T_TRUE; }
<ST_YOLANG,ST_INJECT>"false" { return T_FALSE; }
<ST_YOLANG,ST_INJECT>"null" { return T_NULL; }

<ST_YOLANG,ST_INJECT>"mod" { return T_MODULE; }
<ST_YOLANG,ST_INJECT>"import" { return T_IMPORT; }
<ST_YOLANG,ST_INJECT>"extern" { return T_EXTERN; }
<ST_YOLANG,ST_INJECT>"void" { return T_VOID; }
<ST_YOLANG,ST_INJECT>"return" { return T_RETURN; }
<ST_YOLANG,ST_INJECT>"let" { return T_LET; }
<ST_YOLANG,ST_INJECT>"type" { return T_TYPE; }
<ST_YOLANG,ST_INJECT>"chan" { return T_CHAN; }
<ST_YOLANG,ST_INJECT>"func" { return T_FUNC; }
<ST_YOLANG,ST_INJECT>"get" { return T_GET; }
<ST_YOLANG,ST_INJECT>"set" { return T_SET; }
<ST_YOLANG,ST_INJECT>"const" { return T_CONST; }
<ST_YOLANG,ST_INJECT>"mut" { return T_MUTABLE; }
<ST_YOLANG,ST_INJECT>"struct" { return T_STRUCT; }
<ST_YOLANG,ST_INJECT>"class" { return T_CLASS; }
<ST_YOLANG,ST_INJECT>"contract" { return T_CONTRACT; }
<ST_YOLANG,ST_INJECT>"for" { return T_FOR; }
<ST_YOLANG,ST_INJECT>"while" { return T_WHILE; }
<ST_YOLANG,ST_INJECT>"loop" { return T_LOOP; }
<ST_YOLANG,ST_INJECT>"break" { return T_BREAK; }
<ST_YOLANG,ST_INJECT>"continue" { return T_CONTINUE; }
<ST_YOLANG,ST_INJECT>"switch" { return T_SWITCH; }
<ST_YOLANG,ST_INJECT>"case" { return T_CASE; }
<ST_YOLANG,ST_INJECT>"default" { return T_DEFAULT; }
<ST_YOLANG,ST_INJECT>"fallthrough" { return T_FALLTHROUGH; }
<ST_YOLANG,ST_INJECT>"in" { return T_IN; }
<ST_YOLANG,ST_INJECT>"if" { return T_IF; }
<ST_YOLANG,ST_INJECT>"else" { return T_ELSE; }
<ST_YOLANG,ST_INJECT>"elseif" { return T_ELSEIF; }
<ST_YOLANG,ST_INJECT>"catch" { return T_CATCH; }
<ST_YOLANG,ST_INJECT>"as" { return T_AS; }
<ST_YOLANG,ST_INJECT>"sizeof" { return T_SIZEOF; }

<ST_YOLANG>"{"	{ return yoLexOpenBrace(parm, parserLoc); }
<ST_INJECT>"{"	{ return yoLexInjectOpenBrace(parserElem, parm, parserLoc); }
<ST_INJECT>"}"	{ return yoLexInjectCloseBrace(parserElem, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{OPEN_BRACKET}	{ return yoLexOpenBracket(parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{CLOSE_BRACKET} { return yoLexCloseBracket(parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{NAME} { return yoLexName(parserElem, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{HNUM} { return yoLexIntRadix(parserElem, 16, 0, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{LNUM} { return yoLexIntRadix(parserElem, 10, 0, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{BNUM} { return yoLexIntRadix(parserElem, 2, 0, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{HNUM}("i8"|"u8") { return yoLexIntRadix(parserElem, 16, 2, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{LNUM}("i8"|"u8") { return yoLexIntRadix(parserElem, 10, 2, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{BNUM}("i8"|"u8") { return yoLexIntRadix(parserElem, 2, 2, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{HNUM}("i16"|"i32"|"i64"|"u16"|"u32"|"u64") { return yoLexIntRadix(parserElem, 16, 3, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{LNUM}("i16"|"i32"|"i64"|"u16"|"u32"|"u64") { return yoLexIntRadix(parserElem, 10, 3, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{BNUM}("i16"|"i32"|"i64"|"u16"|"u32"|"u64") { return yoLexIntRadix(parserElem, 2, 3, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{DNUM}|{EXPONENT_DNUM} { return yoLexFloat(parserElem, 0, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>({DNUM}|{EXPONENT_DNUM})"f32" { return yoLexFloat(parserElem, 3, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>({DNUM}|{EXPONENT_DNUM})"f64" { return yoLexFloat(parserElem, 3, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>"//" { yoLexLineComment(parm, parserLoc); goto restart; }
<ST_YOLANG,ST_INJECT>"/*" { yoLexMultiLineComment(parm, parserLoc); goto restart; }

<ST_YOLANG,ST_INJECT>{SINGLE_QUOTE} { return yoLexSingleQuotedString(parserElem, parm, parserLoc); }
<ST_YOLANG,ST_INJECT>{QUOTE}	{ return yoLexQuotedString(parserElem, parm, parserLoc); }

<ST_YOLANG,ST_INJECT>{ANY_CHAR} { return yoLexChar(parserElem, parm, parserLoc); }

*/
}
