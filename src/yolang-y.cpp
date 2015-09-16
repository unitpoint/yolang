/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         yoparse
#define yylex           yolex
#define yyerror         yoerror
#define yylval          yolval
#define yychar          yochar
#define yydebug         yodebug
#define yynerrs         yonerrs
#define yylloc          yolloc

/* Copy the first part of user declarations.  */


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
void yoParserPostUnaryOp(YYSTYPE * r, YYSTYPE * a, int op, void*, YYLTYPE * loc);
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
void yoParserDeclFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, bool isVarArgs, EYoCallingConv conv, void*, YYLTYPE * loc);
void yoParserDeclFunc(YYSTYPE * r, int op, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, void*, YYLTYPE * loc);
void yoParserContractFunc(YYSTYPE * r, int op, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void*, YYLTYPE * loc);
void yoParserContract(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * e, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserStruct(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * e, YYSTYPE * a, void * parm, YYLTYPE * loc);
void yoParserDebug(YYSTYPE*, void*, YYLTYPE * loc);
void yoParserError(YYSTYPE*, const char*, void*, YYLTYPE * loc);
void yoParseEmpty(YYSTYPE*, void*, YYLTYPE * loc);
void yoParserCall(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, void * parm, YYLTYPE * loc);
void yoParserStmtReturn(YYSTYPE * r, YYSTYPE * expr, void * parm, YYLTYPE * loc);
void yoParserEnableBrace(void * parm, YYLTYPE * loc);
void yoParserStmtFor(YYSTYPE * r, YYSTYPE * init, YYSTYPE * condition, YYSTYPE * step, YYSTYPE * body, void * parm, YYLTYPE * loc);
void yoParserStmtBreak(YYSTYPE * r, YYSTYPE * label, int op, void * parm, YYLTYPE * loc);
void yoParserStmtIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseIfList, YYSTYPE * elseStmt, void * parm, YYLTYPE * loc);
void yoParserElseIfList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm, YYLTYPE * loc);
void yoParserElseIf(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * stmt, void * parm, YYLTYPE * loc);
void yoParserElse(YYSTYPE * r, YYSTYPE * stmt, void * parm, YYLTYPE * loc);
void yoParserCatchElem(YYSTYPE * r, YYSTYPE * name, YYSTYPE * stmt, void * parm, YYLTYPE * loc);
void yoParserStmtCatch(YYSTYPE * r, YYSTYPE * stmt, YYSTYPE * catchElem, void * parm, YYLTYPE * loc);
void yoParserCast(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * type, void * parm, YYLTYPE * loc);
void yoParserSizeOf(YYSTYPE * r, YYSTYPE * a, void * parm, YYLTYPE * loc);

int yolex(YYSTYPE*, YYLTYPE*, void * parser);
void yyerror(const char* s);




# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yolang.tab.h".  */
#ifndef YY_YO_YOLANG_TAB_H_INCLUDED
# define YY_YO_YOLANG_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yodebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_MODULE = 258,
     T_IMPORT = 259,
     T_DOTDOTDOT = 260,
     T_INT8 = 261,
     T_INT16 = 262,
     T_INT32 = 263,
     T_INT64 = 264,
     T_INT = 265,
     T_INTPTR = 266,
     T_UINT8 = 267,
     T_UINT16 = 268,
     T_UINT32 = 269,
     T_UINT64 = 270,
     T_UINT = 271,
     T_UINTPTR = 272,
     T_FLOAT32 = 273,
     T_FLOAT64 = 274,
     T_STRING = 275,
     T_BOOL = 276,
     T_TRUE = 277,
     T_FALSE = 278,
     T_SSTRING = 279,
     T_SSTRING_NOT_FINISHED = 280,
     T_QSTRING = 281,
     T_QSTRING_NOT_FINISHED = 282,
     T_QSTRING_INJECT_EXRP = 283,
     T_NULL = 284,
     T_VOID = 285,
     T_UNKNOWN_YET = 286,
     T_RETURN = 287,
     T_LET = 288,
     T_TYPE = 289,
     T_CHAN = 290,
     T_EXTERN = 291,
     T_FUNC = 292,
     T_SUB_FUNC = 293,
     T_LAMBDA = 294,
     T_EXTERN_FUNC = 295,
     T_GET = 296,
     T_SET = 297,
     T_CONST = 298,
     T_MUTABLE = 299,
     T_STRUCT = 300,
     T_CLASS = 301,
     T_CONTRACT = 302,
     T_BRACE = 303,
     T_FOR = 304,
     T_WHILE = 305,
     T_LOOP = 306,
     T_BREAK = 307,
     T_CONTINUE = 308,
     T_IN = 309,
     T_IF = 310,
     T_ELSE = 311,
     T_ELSEIF = 312,
     T_CATCH = 313,
     T_SIZEOF = 314,
     T_LNUMBER = 315,
     T_DNUMBER = 316,
     T_NAME = 317,
     T_NEWLINE = 318,
     T_FIX = 319,
     T_POW_ASSIGN = 320,
     T_RSH_ASSIGN = 321,
     T_LSH_ASSIGN = 322,
     T_XOR_ASSIGN = 323,
     T_OR_ASSIGN = 324,
     T_AND_ASSIGN = 325,
     T_MOD_ASSIGN = 326,
     T_CONCAT_ASSIGN = 327,
     T_DIV_ASSIGN = 328,
     T_MUL_ASSIGN = 329,
     T_MINUS_ASSIGN = 330,
     T_PLUS_ASSIGN = 331,
     T_DECL_ASSIGN = 332,
     T_ASSIGN = 333,
     T_INIT_ASSIGN = 334,
     T_PROP_ASSIGN = 335,
     T_XORXOR = 336,
     T_OROR = 337,
     T_ANDAND = 338,
     T_CHAN_ACCESS = 339,
     T_GT = 340,
     T_LT = 341,
     T_GE = 342,
     T_LE = 343,
     T_NE = 344,
     T_EQ = 345,
     T_CONCAT = 346,
     T_XOR = 347,
     T_OR = 348,
     T_MINUS = 349,
     T_PLUS = 350,
     T_RSH = 351,
     T_LSH = 352,
     T_AND = 353,
     T_MOD = 354,
     T_DIV = 355,
     T_MUL = 356,
     T_POW = 357,
     T_AS = 358,
     T_ADDR = 359,
     T_INDIRECT = 360,
     T_AT = 361,
     T_POST_UNARY = 362,
     T_UNARY = 363,
     T_DEC = 364,
     T_INC = 365,
     T_TILDE = 366,
     T_NOT = 367,
     T_DOT = 368,
     T_INDEX = 369,
     T_REF = 370,
     T_PTR = 371,
     T_ARR = 372,
     T_DOTNAME = 373,
     NotParen = 374
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yoparse (void *YYPARSE_PARAM);
#else
int yoparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yoparse (void);
#else
int yoparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YO_YOLANG_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2064

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  130
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  104
/* YYNRULES -- Number of rules.  */
#define YYNRULES  283
/* YYNRULES -- Number of states.  */
#define YYNSTATES  544

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   374

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     124,   125,     2,     2,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,   126,
       2,     2,     2,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   116,     2,   129,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   127,     2,   128,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   117,   118,
     119,   120,   121,   122,   123
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    10,    11,    13,    16,    18,    20,
      22,    24,    26,    28,    31,    33,    37,    39,    41,    43,
      47,    50,    55,    58,    62,    64,    66,    69,    73,    79,
      82,    86,    88,    91,    93,    95,    98,   101,   104,   107,
     109,   111,   113,   115,   117,   119,   121,   123,   126,   129,
     132,   134,   136,   141,   145,   148,   151,   153,   155,   159,
     162,   164,   166,   168,   171,   172,   181,   182,   188,   189,
     194,   196,   198,   200,   204,   206,   208,   210,   212,   214,
     216,   220,   222,   224,   228,   229,   236,   237,   242,   244,
     247,   249,   251,   256,   258,   264,   266,   268,   272,   276,
     283,   285,   288,   295,   303,   311,   318,   320,   324,   326,
     328,   332,   334,   338,   341,   343,   345,   347,   351,   358,
     361,   363,   365,   368,   370,   372,   374,   376,   378,   380,
     382,   384,   386,   388,   390,   392,   394,   396,   406,   414,
     425,   436,   446,   456,   466,   473,   478,   480,   482,   485,
     489,   492,   496,   501,   503,   505,   507,   509,   513,   516,
     518,   520,   522,   528,   535,   542,   548,   550,   552,   555,
     558,   561,   564,   567,   570,   574,   576,   578,   583,   585,
     588,   590,   592,   594,   596,   598,   600,   602,   604,   606,
     608,   610,   612,   614,   616,   618,   620,   622,   624,   626,
     628,   630,   632,   634,   636,   638,   640,   642,   646,   649,
     653,   657,   662,   667,   669,   673,   677,   680,   682,   685,
     688,   690,   692,   694,   696,   698,   700,   704,   708,   712,
     716,   720,   724,   728,   732,   736,   740,   744,   748,   752,
     756,   760,   764,   768,   772,   776,   780,   784,   788,   793,
     795,   799,   801,   803,   807,   813,   816,   819,   822,   825,
     828,   831,   834,   837,   840,   843,   846,   849,   853,   857,
     861,   865,   869,   873,   877,   881,   885,   889,   893,   897,
     901,   903,   905,   910
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     131,     0,    -1,     3,    62,   133,   134,    -1,     1,    -1,
      -1,   135,    -1,   126,   135,    -1,   137,    -1,   132,    -1,
      63,    -1,   135,    -1,   126,    -1,   151,    -1,   137,   151,
      -1,    62,    -1,   138,    65,    62,    -1,   209,    -1,   132,
      -1,   141,    -1,   140,    65,   141,    -1,    62,   139,    -1,
      62,   139,    79,   229,    -1,    33,   140,    -1,    34,    62,
     196,    -1,    26,    -1,    24,    -1,     4,   144,    -1,     4,
      62,   144,    -1,     4,   127,   135,   147,   128,    -1,   144,
     135,    -1,    62,   144,   135,    -1,   146,    -1,   147,   146,
      -1,   142,    -1,   143,    -1,   145,   136,    -1,   149,   136,
      -1,   148,   136,    -1,   197,   136,    -1,     1,    -1,   150,
      -1,   135,    -1,   132,    -1,    62,    -1,   132,    -1,   229,
      -1,   132,    -1,    32,   154,    -1,    52,   153,    -1,    53,
     153,    -1,   229,    -1,   155,    -1,   155,    55,   229,   132,
      -1,   142,   179,   136,    -1,   198,   136,    -1,   143,   136,
      -1,   172,    -1,   160,    -1,   156,   179,   136,    -1,     1,
     152,    -1,   157,    -1,   135,    -1,   158,    -1,   159,   158,
      -1,    -1,    49,   161,   166,   126,   167,   126,   164,   171,
      -1,    -1,    50,   162,   132,   229,   171,    -1,    -1,    51,
     163,   132,   171,    -1,   165,    -1,   132,    -1,   229,    -1,
     165,    65,   229,    -1,   142,    -1,   168,    -1,   132,    -1,
     229,    -1,   132,    -1,   169,    -1,   168,    65,   169,    -1,
     141,    -1,   229,    -1,    48,   159,   128,    -1,    -1,    55,
     173,   170,   171,   177,   178,    -1,    -1,    57,   175,   170,
     171,    -1,   174,    -1,   176,   174,    -1,   176,    -1,   132,
      -1,    56,   127,   159,   128,    -1,   132,    -1,    58,    62,
     127,   159,   128,    -1,   132,    -1,    62,    -1,   180,   117,
      62,    -1,    47,   127,   128,    -1,    47,   185,   188,   127,
     183,   128,    -1,   184,    -1,   183,   184,    -1,    37,    62,
     124,   203,   125,   136,    -1,    37,    62,   124,   203,   125,
     209,   136,    -1,    41,    62,   124,   203,   125,   209,   136,
      -1,    42,    62,   124,   204,   125,   136,    -1,   135,    -1,
      89,   187,    88,    -1,   132,    -1,   218,    -1,   218,    79,
     186,    -1,   186,    -1,   187,    65,   186,    -1,    83,   190,
      -1,   132,    -1,   186,    -1,   189,    -1,   190,    65,   189,
      -1,    45,   185,   188,   127,   194,   128,    -1,   205,   136,
      -1,   135,    -1,   192,    -1,   193,   192,    -1,   193,    -1,
     132,    -1,   218,    -1,   210,    -1,   211,    -1,   212,    -1,
     214,    -1,   213,    -1,   215,    -1,   217,    -1,   208,    -1,
     195,    -1,   182,    -1,   191,    -1,    36,    37,   180,   124,
     204,    65,     5,   125,   139,    -1,    36,    37,   180,   124,
     203,   125,   139,    -1,    37,   202,   180,   124,   203,   125,
     139,   127,   206,   128,    -1,    41,   202,   180,   124,   203,
     125,   209,   127,   206,   128,    -1,    42,   202,   180,   124,
     204,   125,   127,   206,   128,    -1,    37,    62,   124,   203,
     125,   139,   127,   206,   128,    -1,    37,   132,   124,   203,
     125,   139,   127,   206,   128,    -1,   127,    96,   203,    96,
     200,   128,    -1,   127,    85,   200,   128,    -1,   229,    -1,
     218,    -1,   104,   218,    -1,   104,    44,   218,    -1,   101,
     218,    -1,   101,    44,   218,    -1,   124,    62,   201,   125,
      -1,   132,    -1,   204,    -1,   132,    -1,   205,    -1,   204,
      65,   205,    -1,   138,   209,    -1,   159,    -1,   132,    -1,
     132,    -1,    37,   207,   124,   203,   125,    -1,    37,   207,
     124,   203,   125,   209,    -1,    41,   207,   124,   203,   125,
     209,    -1,    42,   207,   124,   204,   125,    -1,   195,    -1,
     181,    -1,    43,   209,    -1,    44,   209,    -1,    35,   209,
      -1,   101,   209,    -1,   104,   209,    -1,   105,   209,    -1,
     116,   129,   209,    -1,    60,    -1,   180,    -1,   116,   216,
     129,   209,    -1,   219,    -1,   180,   185,    -1,     6,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      17,    -1,    20,    -1,    18,    -1,    19,    -1,    21,    -1,
      30,    -1,    82,    -1,    44,    -1,    22,    -1,    23,    -1,
      29,    -1,    60,    -1,    61,    -1,    24,    -1,    26,    -1,
     229,    -1,   221,    65,   229,    -1,   127,   128,    -1,   127,
     221,   128,    -1,   180,   127,   128,    -1,   180,   127,   221,
     128,    -1,   180,   127,   224,   128,    -1,   225,    -1,   224,
      65,   225,    -1,    62,    83,   229,    -1,    28,   230,    -1,
     226,    -1,   227,   226,    -1,   227,    26,    -1,   230,    -1,
     228,    -1,   220,    -1,   180,    -1,   222,    -1,   223,    -1,
     229,    93,   229,    -1,   229,    92,   229,    -1,   229,    91,
     229,    -1,   229,    90,   229,    -1,   229,    89,   229,    -1,
     229,    88,   229,    -1,   229,    98,   229,    -1,   229,    97,
     229,    -1,   229,   104,   229,    -1,   229,   103,   229,    -1,
     229,   102,   229,    -1,   229,   105,   229,    -1,   229,    94,
     229,    -1,   229,   100,   229,    -1,   229,    99,   229,    -1,
     229,    96,   229,    -1,   229,    85,   229,    -1,   229,   101,
     229,    -1,   229,    86,   229,    -1,   229,    95,   229,    -1,
     229,    87,   229,    -1,   229,   117,   180,    -1,   229,   116,
     229,   129,    -1,   231,    -1,   124,   229,   125,    -1,   233,
      -1,   199,    -1,   229,   106,   209,    -1,   229,   117,   124,
     209,   125,    -1,   229,   113,    -1,   229,   112,    -1,   113,
     229,    -1,   112,   229,    -1,    98,   229,    -1,    97,   229,
      -1,   115,   229,    -1,   114,   229,    -1,    87,   229,    -1,
      59,   229,    -1,   104,   229,    -1,   101,   229,    -1,   229,
      79,   229,    -1,   229,    77,   229,    -1,   229,    76,   229,
      -1,   229,    75,   229,    -1,   229,    74,   229,    -1,   229,
      72,   229,    -1,   229,    70,   229,    -1,   229,    71,   229,
      -1,   229,    69,   229,    -1,   229,    67,   229,    -1,   229,
      68,   229,    -1,   229,    66,   229,    -1,   229,    73,   229,
      -1,   221,    -1,   132,    -1,   180,   124,   232,   125,    -1,
     229,   117,   180,   124,   232,   125,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   237,   237,   238,   241,   250,   251,   254,   255,   258,
     261,   262,   265,   266,   269,   270,   273,   274,   277,   278,
     281,   282,   289,   292,   295,   296,   299,   300,   301,   304,
     305,   308,   309,   312,   315,   318,   319,   320,   321,   322,
     325,   326,   329,   337,   338,   341,   342,   345,   346,   347,
     348,   351,   352,   355,   356,   357,   358,   359,   360,   361,
     364,   365,   368,   369,   385,   385,   388,   388,   391,   391,
     396,   397,   400,   401,   404,   405,   406,   409,   410,   413,
     414,   417,   420,   423,   426,   426,   431,   431,   435,   436,
     439,   440,   443,   444,   447,   448,   451,   452,   455,   458,
     461,   462,   465,   466,   467,   468,   469,   472,   473,   476,
     477,   480,   481,   484,   485,   488,   491,   492,   495,   498,
     499,   516,   517,   520,   521,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   535,   536,   537,   540,   542,   544,
     546,   548,   552,   560,   562,   564,   568,   572,   573,   574,
     575,   576,   579,   580,   583,   584,   587,   588,   591,   594,
     595,   604,   607,   608,   609,   610,   613,   614,   617,   620,
     623,   626,   629,   630,   637,   641,   642,   645,   649,   651,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   675,
     676,   677,   678,   679,   680,   681,   684,   685,   688,   689,
     692,   693,   695,   698,   699,   702,   705,   708,   709,   712,
     715,   716,   729,   730,   731,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   767,
     768,   769,   770,   771,   772,   773,   774,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     805,   806,   809,   810
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_MODULE", "T_IMPORT", "T_DOTDOTDOT",
  "T_INT8", "T_INT16", "T_INT32", "T_INT64", "T_INT", "T_INTPTR",
  "T_UINT8", "T_UINT16", "T_UINT32", "T_UINT64", "T_UINT", "T_UINTPTR",
  "T_FLOAT32", "T_FLOAT64", "T_STRING", "T_BOOL", "T_TRUE", "T_FALSE",
  "T_SSTRING", "T_SSTRING_NOT_FINISHED", "T_QSTRING",
  "T_QSTRING_NOT_FINISHED", "T_QSTRING_INJECT_EXRP", "T_NULL", "T_VOID",
  "T_UNKNOWN_YET", "T_RETURN", "T_LET", "T_TYPE", "T_CHAN", "T_EXTERN",
  "T_FUNC", "T_SUB_FUNC", "T_LAMBDA", "T_EXTERN_FUNC", "T_GET", "T_SET",
  "T_CONST", "T_MUTABLE", "T_STRUCT", "T_CLASS", "T_CONTRACT", "T_BRACE",
  "T_FOR", "T_WHILE", "T_LOOP", "T_BREAK", "T_CONTINUE", "T_IN", "T_IF",
  "T_ELSE", "T_ELSEIF", "T_CATCH", "T_SIZEOF", "T_LNUMBER", "T_DNUMBER",
  "T_NAME", "T_NEWLINE", "T_FIX", "','", "\"**= (T_POW_ASSIGN)\"",
  "\">>= (T_RSH_ASSIGN)\"", "\"<<= (T_LSH_ASSIGN)\"",
  "\"^= (T_XOR_ASSIGN)\"", "\"|= (T_OR_ASSIGN)\"", "\"&= (T_AND_ASSIGN)\"",
  "\"%= (T_MOD_ASSIGN)\"", "\"..= (T_CONCAT_ASSIGN)\"",
  "\"/= (T_DIV_ASSIGN)\"", "\"*= (T_MUL_ASSIGN)\"",
  "\"-= (T_MINUS_ASSIGN)\"", "\"+= (T_PLUS_ASSIGN)\"",
  "\":= (T_DECL_ASSIGN)\"", "\"= (T_ASSIGN)\"", "\"= (T_INIT_ASSIGN)\"",
  "\"= (T_PROP_ASSIGN)\"", "'?'", "':'", "\"^^ (T_XORXOR)\"",
  "\"|| (T_OROR)\"", "\"&& (T_ANDAND)\"", "\"<- (T_CHAN_ACCESS)\"",
  "\"> (T_GT)\"", "\"< (T_LT)\"", "\">= (T_GE)\"", "\"<= (T_LE)\"",
  "\"!= (T_NE)\"", "\"== (T_EQ)\"", "\".. (T_CONCAT)\"", "\"^ (T_XOR)\"",
  "\"| (T_OR)\"", "\"- (T_MINUS)\"", "\"+ (T_PLUS)\"", "\">> (T_RSH)\"",
  "\"<< (T_LSH)\"", "\"& (T_AND)\"", "\"% (T_MOD)\"", "\"/ (T_DIV)\"",
  "\"* (T_MUL)\"", "\"** (T_POW)\"", "\"as (T_AS)\"", "\"& (T_ADDR)\"",
  "\"* (T_INDIRECT)\"", "\"@ (T_AT)\"", "T_POST_UNARY", "T_UNARY",
  "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "\"~ (T_TILDE)\"", "\"! (T_NOT)\"",
  "'['", "\". (T_DOT)\"", "\"[] (T_INDEX)\"", "T_REF", "T_PTR", "T_ARR",
  "T_DOTNAME", "NotParen", "'('", "')'", "';'", "'{'", "'}'", "']'",
  "$accept", "file", "empty", "end_newline", "module_stmt_list", "newline",
  "end_stmt", "top_stmt_list", "name_list", "type_or_empty",
  "decl_var_list", "decl_var_elem", "decl_var", "decl_type", "const_str",
  "import", "import_body_elem", "import_body", "top_decl_var",
  "top_decl_type", "top_stmt_no_emptyline", "top_stmt", "stmt_error_end",
  "name_or_empty", "expr_or_empty", "stmt_post_if_elem", "stmt_post_if",
  "stmt_no_emptyline", "stmt", "stmt_list", "for_stmt", "$@1", "$@2",
  "$@3", "for_next", "for_next_list", "for_init", "for_condition",
  "var_assign_list", "var_assign_elem", "if_header", "brace_stmt",
  "if_stmt", "$@4", "elseif", "$@5", "elseif_list", "elseif_list_or_empty",
  "else", "catch", "dotname", "type_contract_empty", "type_contract",
  "contract_body", "contract_decl_func", "template", "template_arg",
  "template_arg_list", "extends", "extends_elem", "extends_list",
  "type_struct", "struct_body_stmt", "struct_body_stmt_list",
  "struct_body", "type_base", "type_ext", "top_decl_func", "decl_func",
  "expr_decl_func", "lambda_body", "type_self", "decl_self",
  "decl_arg_list_or_empty", "decl_arg_list", "decl_arg", "func_body",
  "decl_self_nop", "type_func", "type", "type_const", "type_mutable",
  "type_chan", "type_ref", "type_ptr", "type_slice", "type_arr_size",
  "type_arr", "type_name", "type_std_name", "expr_const_scalar",
  "expr_list", "expr_arr", "expr_obj", "prop_assing_list", "prop_assing",
  "qstr_with_inject_begin_elem", "qstr_with_inject_begin_list",
  "qstr_with_inject", "expr", "expr_base", "assign", "call_args", "call", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    44,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,    63,    58,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,    91,   368,   369,   370,
     371,   372,   373,   374,    40,    41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   130,   131,   131,   132,   133,   133,   134,   134,   135,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   143,   144,   144,   145,   145,   145,   146,
     146,   147,   147,   148,   149,   150,   150,   150,   150,   150,
     151,   151,   152,   153,   153,   154,   154,   155,   155,   155,
     155,   156,   156,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   159,   159,   161,   160,   162,   160,   163,   160,
     164,   164,   165,   165,   166,   166,   166,   167,   167,   168,
     168,   169,   170,   171,   173,   172,   175,   174,   176,   176,
     177,   177,   178,   178,   179,   179,   180,   180,   181,   182,
     183,   183,   184,   184,   184,   184,   184,   185,   185,   186,
     186,   187,   187,   188,   188,   189,   190,   190,   191,   192,
     192,   193,   193,   194,   194,   195,   195,   195,   195,   195,
     195,   195,   195,   195,   196,   196,   196,   197,   197,   197,
     197,   197,   198,   199,   199,   199,   200,   201,   201,   201,
     201,   201,   202,   202,   203,   203,   204,   204,   205,   206,
     206,   207,   208,   208,   208,   208,   209,   209,   210,   211,
     212,   213,   214,   214,   215,   216,   216,   217,   218,   218,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   220,
     220,   220,   220,   220,   220,   220,   221,   221,   222,   222,
     223,   223,   223,   224,   224,   225,   226,   227,   227,   228,
     229,   229,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     232,   232,   233,   233
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     3,
       2,     4,     2,     3,     1,     1,     2,     3,     5,     2,
       3,     1,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     1,     4,     3,     2,     2,     1,     1,     3,     2,
       1,     1,     1,     2,     0,     8,     0,     5,     0,     4,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     0,     6,     0,     4,     1,     2,
       1,     1,     4,     1,     5,     1,     1,     3,     3,     6,
       1,     2,     6,     7,     7,     6,     1,     3,     1,     1,
       3,     1,     3,     2,     1,     1,     1,     3,     6,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     9,     7,    10,
      10,     9,     9,     9,     6,     4,     1,     1,     2,     3,
       2,     3,     4,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     5,     6,     6,     5,     1,     1,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     3,
       3,     4,     4,     1,     3,     3,     2,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     4,     1,
       3,     1,     1,     3,     5,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     9,     0,     0,     5,
       6,    39,     0,     0,     0,     0,     4,     4,     4,     8,
       2,    41,     0,    33,    34,     0,     0,     0,    40,    12,
       0,    25,    24,     0,     0,    26,     4,    22,    18,     0,
       0,     0,   153,     0,     0,     0,    13,    11,    10,    35,
      37,    36,    38,    27,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   193,   194,   192,
     195,   196,     0,     4,     4,     4,     0,   198,     0,    96,
     197,     0,     0,     0,     0,    17,    20,     4,   167,   166,
     133,    16,   126,   127,   128,   130,   129,   131,   132,   125,
     178,     0,     4,     4,   135,   136,   134,    23,     0,     0,
       0,     0,     0,     0,     0,    31,     0,   170,   161,     0,
       0,     0,   168,   169,     0,   171,   172,   173,   175,     0,
     176,     0,     0,     0,     0,   108,   179,    19,     4,     4,
       4,   198,     0,     0,     0,   147,     4,     4,     0,     0,
      29,    28,    32,     4,     4,     0,    98,   174,     0,   199,
     200,   204,   205,     0,   201,     4,     0,   202,   203,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223,   252,   222,   224,   225,   217,     0,   221,    21,   220,
     249,   251,   111,     0,   109,    97,     0,   114,     0,     0,
      14,   155,     0,     0,   154,   156,   198,   150,   198,   148,
     152,     0,   154,     0,     0,    30,     0,     0,     0,   177,
       0,   220,     0,   264,   263,   260,   259,   266,   265,   258,
     257,   262,   261,     0,     0,     4,   208,     0,   206,     4,
       0,   219,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   255,
       0,     0,     0,   107,     0,   115,   116,   113,     4,     0,
       0,   158,     4,     0,   151,   149,     4,     0,     0,     0,
     162,     0,   165,     4,   250,     0,   146,     0,     0,   209,
     281,   280,     0,    96,   210,     0,     0,   213,   278,   276,
     277,   275,   273,   274,   272,   279,   271,   270,   269,   268,
     267,   242,   244,   246,   231,   230,   229,   228,   227,   226,
     238,   245,   241,   233,   232,   240,   239,   243,   236,   235,
     234,   237,   253,     0,     0,   247,   112,   110,     0,   124,
     120,   121,   123,     0,     0,     0,     0,     0,   106,     0,
     100,    15,   138,     0,   157,     0,     0,     0,   163,   164,
       0,   145,     0,   207,   282,     0,   211,     0,   212,   248,
       0,     4,   117,   122,   118,   119,     0,     0,     0,    99,
     101,     4,     0,     0,     4,     4,     4,    64,    66,    68,
       4,     4,    84,   160,    61,     4,     0,    51,     4,    60,
      62,     0,    57,    56,     0,     0,    50,     4,     0,   215,
       0,   214,   254,     0,     4,     4,     0,   137,     0,     0,
      42,    59,    46,    47,    45,     0,     4,     4,     4,    43,
      44,    48,    49,     0,     0,    95,     0,    55,     0,     0,
      63,    54,   141,     0,   144,   283,     0,     0,     0,   139,
     140,     4,    76,    81,    74,     0,    75,    79,     0,     0,
       0,    82,     0,    53,     4,    58,     0,     0,     0,     0,
       0,     4,     0,     0,     0,    69,     4,     0,    52,     0,
     102,     0,     0,   105,     4,    78,     0,    77,    80,    67,
       0,    86,    91,    88,    90,     4,     0,   143,   103,   104,
       0,     4,    83,     0,    89,     0,    93,    85,    94,     0,
      71,     0,    70,    72,     0,     0,     0,    65,     0,    87,
       0,   142,    73,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   201,     8,    20,    48,    49,    22,   202,    86,
      37,   473,   415,   416,   114,    25,   115,   116,    26,    27,
      28,    29,   441,   451,   443,   417,   418,   419,   420,   421,
     422,   446,   447,   448,   531,   532,   475,   506,   476,   477,
     480,   495,   423,   453,   513,   523,   514,   515,   527,   456,
     180,    88,   104,   369,   370,   136,   285,   193,   198,   286,
     287,   105,   361,   362,   363,    89,   107,    30,   424,   181,
     305,   144,    43,   203,   212,   205,   425,   119,    90,    91,
      92,    93,    94,    95,    96,    97,   131,    98,    99,   100,
     182,   311,   183,   184,   316,   317,   185,   186,   187,   426,
     189,   190,   312,   191
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -436
static const yytype_int16 yypact[] =
{
      84,  -436,    -5,    67,     2,  -436,  -436,    11,   123,  -436,
    -436,  -436,    -2,    34,    40,    71,    -3,    -3,    -3,  -436,
    -436,  -436,   175,  -436,  -436,     5,     5,     5,  -436,  -436,
       5,  -436,  -436,   154,    11,  -436,  1564,    89,  -436,  1410,
      96,   107,  -436,    96,    96,    96,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,    37,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,  -436,  1564,  -436,  -436,  -436,  1564,  1564,    50,  -436,
    -436,  1564,  1564,  1564,   -50,  -436,   103,   -35,  -436,  -436,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,
    -436,    34,   113,   113,  -436,  -436,  -436,  -436,   -33,   258,
      46,    64,    86,   154,    11,  -436,    19,  -436,  -436,   100,
     104,   105,  -436,  -436,   106,  -436,  -436,  -436,  -436,  1564,
      97,   108,  1590,   951,   173,  -436,  -436,  -436,   156,   156,
     178,  -436,  1058,  1165,   116,  -436,   178,   178,   178,    11,
    -436,  -436,  -436,   178,   178,   178,  -436,  -436,  1564,  -436,
    -436,  -436,  -436,  1590,  -436,  -436,  1590,  -436,  -436,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,   221,
     -20,  -436,  -436,  -436,  -436,  -436,   187,  -436,  1886,  -436,
    -436,  -436,  -436,    10,   167,  -436,   951,  -436,   124,   125,
    -436,  -436,  1487,   128,   190,  -436,   951,  -436,   951,  -436,
    -436,   129,   191,   136,    15,  -436,   137,   162,    18,  -436,
    1886,   192,   165,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,  1826,  1590,   178,  -436,    -9,  1886,  1590,
     673,  -436,  -436,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,  1590,
    1590,  1590,  1590,  1590,  1590,  1590,  1590,  1564,  -436,  -436,
    1590,   -30,   951,  -436,   951,  -436,  -436,   225,    87,    29,
     231,  -436,  1564,    47,  -436,  -436,  1564,   178,  1564,   170,
    1712,  1564,  -436,   178,  -436,   166,  1886,   204,  1590,  -436,
    -436,   236,   180,   220,  -436,     4,     8,  -436,  1886,  1886,
    1886,  1886,  1886,  1886,  1886,  1886,  1886,  1886,  1886,  1886,
    1886,   467,  1188,  1917,  1947,  1947,  1947,  1947,  1947,  1947,
     357,   357,   357,   357,   357,    79,    79,    79,    79,    79,
      79,    88,  -436,  1762,  1564,   183,  -436,  -436,   951,  -436,
    -436,  -436,    87,   181,     5,   248,   249,   250,  -436,     9,
    -436,  -436,  -436,   196,  -436,   197,   199,   654,  -436,  -436,
     198,  -436,  1590,  1886,  -436,  1590,  -436,   254,  -436,  -436,
     202,  1590,  -436,  -436,  -436,  -436,   205,   206,   207,  -436,
    -436,  1564,   654,   654,  -436,  1590,   266,  -436,  -436,  -436,
     270,   270,  -436,  -436,  -436,   279,     5,   283,   279,  -436,
    -436,   783,  -436,  -436,     5,   211,  1886,  1564,   213,  1886,
     220,  -436,  -436,   217,   178,   178,   178,  -436,   216,   218,
    -436,  -436,  -436,  -436,  1886,   223,    31,  -436,  -436,  -436,
    -436,  -436,  -436,  1590,   288,  -436,     5,  -436,  1590,     5,
    -436,  -436,  -436,   226,  -436,  -436,   227,   229,    21,  -436,
    -436,   178,  -436,  -436,  -436,   230,   290,  -436,  1590,   309,
     309,  1886,   233,  -436,  1886,  -436,   654,  1333,  1564,     5,
     238,  1590,    34,  1710,  1211,  -436,   304,  1211,  -436,   240,
    -436,     5,     5,  -436,  1564,  -436,   243,  1886,  -436,  -436,
     890,  -436,  -436,  -436,   304,   308,   997,  -436,  -436,  -436,
     239,  1590,  -436,  1590,  -436,   251,  -436,  -436,  -436,   654,
    -436,   309,   305,  1886,   309,  1211,   247,  -436,  1590,  -436,
    1104,  -436,  1886,  -436
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -436,  -436,     3,  -436,  -436,    -4,   -21,  -436,  -436,  -279,
    -436,    -6,    -7,    81,    25,  -436,   260,  -436,  -436,  -436,
    -436,   355,  -436,   -32,  -436,  -436,  -436,  -436,  -396,  -435,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,  -111,
    -140,  -341,  -436,  -436,  -130,  -436,  -436,  -436,  -436,   -31,
      90,  -436,  -436,  -436,    16,    95,  -131,  -436,   253,    35,
    -436,  -436,    27,  -436,  -436,   358,  -436,  -436,  -436,  -436,
      14,  -436,   189,  -120,  -132,  -244,  -374,   147,  -436,   -41,
    -436,  -436,  -436,  -436,  -436,  -436,  -436,  -436,   -95,  -436,
    -436,  -124,  -436,  -436,  -436,    13,   215,  -436,  -436,   371,
     252,  -436,    20,  -436
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -217
static const yytype_int16 yytable[] =
{
       9,    23,   192,    10,    21,    50,    51,    38,   204,    52,
     128,    19,    79,   372,   145,    23,   214,   375,    21,    42,
      42,    42,    31,   218,    32,   460,   211,   213,   438,   439,
      54,   117,    79,   216,   217,   122,   123,    35,   194,    85,
     125,   126,   127,    31,   364,    32,   365,   207,   209,   374,
     366,   367,   373,   374,   133,   237,   308,     4,    53,   510,
      33,    31,   516,    32,    13,     6,   365,     5,     6,   308,
     366,   367,     6,   387,     6,   282,   118,   118,   118,   129,
     297,   113,   134,   297,   134,     1,   297,     2,   157,    24,
     135,   140,     6,    36,   354,   137,    36,   134,   283,   113,
     540,   194,    39,    24,   239,   135,   135,   240,    40,   200,
     150,   294,   499,   295,   460,   307,   315,   219,   364,   309,
     460,    41,   437,    -4,    11,    34,    87,    12,     7,    87,
     108,    47,   386,   110,   111,   112,   388,   399,   149,   496,
     299,   197,   197,   302,   460,   215,   489,   151,   463,   200,
       6,   356,   509,   357,   101,   536,    13,    14,    79,    15,
      16,   291,    87,   134,    17,    18,    87,    87,   222,   109,
     146,    87,    87,    87,   130,    -7,    11,   124,    31,    12,
      32,   134,   132,   380,   276,   277,     6,   194,   147,   194,
     537,   278,   279,   539,   277,   280,   281,   138,   139,    87,
     278,   279,   133,   134,   280,   281,    44,    45,    13,    14,
     148,    15,    16,   241,   134,   163,    17,    18,  -216,    87,
    -216,   120,   121,    87,   153,   520,   278,   279,   154,   155,
     280,   281,    87,    87,   156,   195,   352,   158,     6,   196,
     200,   210,   310,   159,   160,   161,   284,   162,    87,   163,
     164,   288,   289,   292,   296,   293,   297,   376,   165,   378,
     379,   298,   300,   194,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     166,   167,   168,    79,   360,   368,    87,   301,    71,   303,
     358,   359,    87,   371,   381,    85,    87,   377,    87,    85,
     382,   308,   141,   385,   468,   384,   234,   391,   169,   394,
     396,   397,   398,   390,   466,   467,   430,   235,   170,   171,
      79,   401,   172,   427,   402,   173,   403,   432,   445,   434,
     435,   436,   449,   174,   175,   176,   177,   454,   458,   462,
      80,   464,   465,   395,   469,   178,   470,   471,   179,   236,
     482,   490,   487,   486,   488,   492,   491,   494,   360,   142,
     497,   511,   143,   504,   525,   368,   529,    87,   517,   521,
     538,   355,    87,   414,    87,   541,   152,    46,   535,   452,
     413,   508,    87,   534,   524,   400,    87,   459,    87,   393,
      87,    87,   199,   392,   310,   457,   428,   106,   414,   414,
     431,   242,     0,   461,    85,   413,   413,   440,   442,   222,
       0,   433,     0,   450,   450,   221,     0,   414,   455,     0,
       0,   455,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,   483,     0,     0,   485,   474,
       0,     0,     0,     0,    87,     0,   501,   502,    87,   472,
     478,   479,     0,     0,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,   500,     0,   503,   278,
     279,     0,     0,   280,   281,     0,     0,     0,     0,     0,
     518,   519,   414,     0,     0,     0,     0,   498,     0,   413,
     414,    87,     0,   414,   505,     0,     0,     0,     0,   512,
       0,     0,     0,   188,     0,     0,   414,    85,     0,     0,
       0,     0,   414,     0,     0,     0,     0,    87,   526,     0,
       0,     0,     0,     0,   530,   414,     0,     0,     0,     0,
       0,   414,   413,     0,   220,     0,   414,   223,     0,     0,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     238,     0,     0,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,    87,    87,   278,
     279,     0,     0,   280,   281,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   306,     0,     0,     0,     0,
     238,   238,     0,     0,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,     0,     0,
       0,   353,     0,     0,     0,   404,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   159,   160,   161,   383,
     162,     0,   163,   164,     0,     0,   405,    13,    14,     0,
       0,   406,     0,     0,     0,   159,   160,   161,     0,   162,
       0,   163,   164,   407,   408,   409,   410,   411,     0,   412,
     165,     0,     0,   166,   167,   168,    79,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   167,   168,   313,     0,     0,     0,     0,
       0,   169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,   171,   306,     0,   172,   429,     0,   173,     0,
     169,     0,   238,     0,     0,     0,   174,   175,   176,   177,
     170,   171,     0,     0,   172,     0,   444,   173,   178,     0,
       0,   179,    -4,     0,   404,   174,   175,   176,   177,     0,
       0,     0,     0,     0,     0,     0,     0,   178,     0,     0,
     179,   314,     0,     0,     0,   159,   160,   161,     0,   162,
       0,   163,   164,     0,     0,   405,    13,    14,     0,     0,
     406,     0,     0,     0,   481,     0,     0,     0,     0,   484,
       0,     0,   407,   408,   409,   410,   411,     0,   412,     0,
       0,     0,   166,   167,   168,    79,     6,     0,     0,   493,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,     0,     0,     0,     0,     0,     0,     0,
     169,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,   171,     0,     0,   172,     0,     0,   173,     0,     0,
       0,   404,   533,     0,   481,   174,   175,   176,   177,     0,
       0,     0,     0,     0,     0,     0,     0,   178,     0,   542,
     179,  -159,   159,   160,   161,     0,   162,     0,   163,   164,
       0,     0,   405,    13,    14,     0,     0,   406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   407,
     408,   409,   410,   411,     0,   412,     0,     0,     0,   166,
     167,   168,    79,     6,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,     0,     0,   169,     0,     0,
       0,    71,     0,     0,     0,     0,     0,   170,   171,     0,
       0,   172,     0,     0,   173,   141,     0,     0,   404,     0,
       0,     0,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,    79,   178,     0,     0,   179,   522,   159,
     160,   161,     0,   162,     0,   163,   164,     0,     0,   405,
      13,    14,     0,    80,   406,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   407,   408,   409,   410,
     411,     0,   412,     0,     0,     0,   166,   167,   168,    79,
       6,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,     0,     0,   169,     0,     0,     0,    71,     0,
       0,     0,     0,     0,   170,   171,     0,     0,   172,     0,
       0,   173,   206,     0,     0,   404,     0,     0,     0,   174,
     175,   176,   177,     0,     0,     0,     0,     0,     0,     0,
      79,   178,     0,     0,   179,   528,   159,   160,   161,     0,
     162,     0,   163,   164,     0,     0,   405,    13,    14,     0,
      80,   406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   407,   408,   409,   410,   411,     0,   412,
       0,     0,     0,   166,   167,   168,    79,     6,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,     0,
       0,   169,     0,     0,     0,    71,     0,     0,     0,     0,
       0,   170,   171,     0,     0,   172,     0,     0,   173,   208,
       0,     0,   404,     0,     0,     0,   174,   175,   176,   177,
       0,     0,     0,     0,     0,     0,     0,    79,   178,     0,
       0,   179,   543,   159,   160,   161,     0,   162,     0,   163,
     164,     0,     0,   405,    13,    14,     0,    80,   406,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     407,   408,   409,   410,   411,     0,   412,     0,     0,     0,
     166,   167,   168,    79,     6,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,     0,     0,     0,   169,     0,
     278,   279,     0,     0,   280,   281,     0,     0,   170,   171,
       0,     0,   172,     0,     0,   173,     0,     0,     0,     0,
       0,     0,     0,   174,   175,   176,   177,     0,     0,     0,
       0,     0,     0,     0,     0,   178,     0,     0,   179,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,     0,     0,     0,
       0,     0,     0,    71,     0,     0,     0,     0,    72,     0,
      73,     0,     0,     0,    74,    75,    76,    77,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,    81,     0,     0,    82,    83,     0,
      71,     0,     0,     0,     0,    72,     0,    73,     0,    84,
       0,    74,    75,    76,    77,   102,     0,   103,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    80,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,    81,     0,     0,    82,    83,     0,    71,     0,     0,
       0,     0,    72,     0,    73,     0,    84,     0,    74,    75,
      76,    77,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    79,
       0,     0,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,    81,     0,
       0,    82,    83,     0,    71,     0,     0,     0,     0,    72,
       0,    73,     0,    84,     0,    74,    75,    76,    77,     0,
       0,    78,   159,   160,   161,     0,   162,     0,   163,   164,
       0,     0,     0,     0,     0,     0,    79,   165,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,   166,
     167,   168,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    82,    83,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
      84,     0,     0,     0,     0,     0,     0,   170,   171,     0,
       0,   172,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,   174,   175,   176,   177,     0,     0,     0,     0,
       0,     0,     0,     0,   178,     0,     0,   179,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,    72,     0,    73,
       0,     0,     0,    74,    75,    76,    77,     0,   494,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    79,     0,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,     0,   255,
       0,     0,     0,     0,    80,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,     0,     0,     0,
       0,     0,   278,   279,     0,     0,   280,   281,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
       0,   255,     0,     0,     0,     0,     0,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,     0,
       0,     0,     0,     0,   278,   279,     0,     0,   280,   281,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   389,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,   255,     0,     0,     0,     0,
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   279,
       0,     0,   280,   281,     0,     0,     0,     0,     0,     0,
       0,   304,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,     0,   255,     0,     0,     0,     0,
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,     0,     0,     0,     0,     0,   278,   279,
       0,     0,   280,   281,  -217,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     279,     0,     0,   280,   281,  -217,  -217,  -217,  -217,  -217,
    -217,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,     0,     0,     0,     0,     0,   278,
     279,     0,     0,   280,   281
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-436)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-217)))

static const yytype_int16 yycheck[] =
{
       4,     8,   133,     7,     8,    26,    27,    13,   140,    30,
      60,     8,    62,   292,   109,    22,   148,   296,    22,    16,
      17,    18,    24,   155,    26,   421,   146,   147,   402,   403,
      34,    72,    62,   153,   154,    76,    77,    12,   133,    36,
      81,    82,    83,    24,   288,    26,    37,   142,   143,   293,
      41,    42,     5,   297,    89,   179,    65,    62,    33,   494,
      62,    24,   497,    26,    33,    63,    37,     0,    63,    65,
      41,    42,    63,    65,    63,    65,    73,    74,    75,   129,
      65,    62,   117,    65,   117,     1,    65,     3,   129,     8,
      87,   124,    63,    62,   124,   101,    62,   117,    88,    62,
     535,   196,    62,    22,   124,   102,   103,   127,    37,    62,
     114,   206,   486,   208,   510,   235,   240,   158,   362,   128,
     516,   124,   401,     0,     1,   127,    36,     4,   126,    39,
      40,   126,   128,    43,    44,    45,   128,   128,   113,   480,
     125,   138,   139,   125,   540,   149,   125,   128,   427,    62,
      63,   282,   493,   284,    65,   529,    33,    34,    62,    36,
      37,   202,    72,   117,    41,    42,    76,    77,   165,    62,
     124,    81,    82,    83,    84,     0,     1,   127,    24,     4,
      26,   117,    79,   303,   105,   106,    63,   282,   124,   284,
     531,   112,   113,   534,   106,   116,   117,   102,   103,   109,
     112,   113,    89,   117,   116,   117,    17,    18,    33,    34,
     124,    36,    37,    26,   117,    28,    41,    42,    26,   129,
      28,    74,    75,   133,   124,   504,   112,   113,   124,   124,
     116,   117,   142,   143,   128,    62,   277,   129,    63,    83,
      62,   125,   239,    22,    23,    24,    79,    26,   158,    28,
      29,   127,   127,   125,   125,    65,    65,   298,    37,   300,
     301,   125,   125,   358,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      59,    60,    61,    62,   288,   289,   196,   125,    30,   124,
      65,   288,   202,    62,   128,   292,   206,   127,   208,   296,
      96,    65,    44,    83,   436,   125,    85,   124,    87,   128,
      62,    62,    62,   354,   434,   435,    62,    96,    97,    98,
      62,   125,   101,   125,   127,   104,   127,   125,    62,   124,
     124,   124,    62,   112,   113,   114,   115,    58,    55,   128,
      82,   128,   125,   364,   128,   124,   128,   124,   127,   128,
      62,   471,   125,   127,   125,    65,   126,    48,   362,   101,
     127,    57,   104,   125,    56,   369,   127,   277,   128,   126,
      65,   281,   282,   377,   284,   128,   116,    22,   127,   411,
     377,   492,   292,   523,   514,   369,   296,   418,   298,   362,
     300,   301,   139,   358,   391,   416,   382,    39,   402,   403,
     387,   186,    -1,   424,   401,   402,   403,   404,   405,   406,
      -1,   391,    -1,   410,   411,   163,    -1,   421,   415,    -1,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,    -1,    -1,    -1,    -1,   456,    -1,    -1,   459,   446,
      -1,    -1,    -1,    -1,   354,    -1,   487,   488,   358,   446,
     447,   448,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,   487,    -1,   489,   112,
     113,    -1,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
     501,   502,   486,    -1,    -1,    -1,    -1,   484,    -1,   486,
     494,   401,    -1,   497,   491,    -1,    -1,    -1,    -1,   496,
      -1,    -1,    -1,   132,    -1,    -1,   510,   504,    -1,    -1,
      -1,    -1,   516,    -1,    -1,    -1,    -1,   427,   515,    -1,
      -1,    -1,    -1,    -1,   521,   529,    -1,    -1,    -1,    -1,
      -1,   535,   529,    -1,   163,    -1,   540,   166,    -1,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,    -1,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,   487,   488,   112,
     113,    -1,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   504,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,    -1,
     239,   240,    -1,    -1,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,    -1,    -1,
      -1,   280,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,   308,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    49,    50,    51,    52,    53,    -1,    55,
      37,    -1,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,   382,    -1,   101,   385,    -1,   104,    -1,
      87,    -1,   391,    -1,    -1,    -1,   112,   113,   114,   115,
      97,    98,    -1,    -1,   101,    -1,   405,   104,   124,    -1,
      -1,   127,   128,    -1,     1,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,
     127,   128,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,   458,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    -1,    -1,   478,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   491,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,    -1,
      -1,     1,   521,    -1,   523,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,   538,
     127,   128,    22,    23,    24,    -1,    26,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,   101,    -1,    -1,   104,    44,    -1,    -1,     1,    -1,
      -1,    -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,   124,    -1,    -1,   127,   128,    22,
      23,    24,    -1,    26,    -1,    28,    29,    -1,    -1,    32,
      33,    34,    -1,    82,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,   101,    -1,
      -1,   104,    44,    -1,    -1,     1,    -1,    -1,    -1,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,   124,    -1,    -1,   127,   128,    22,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      82,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,    55,
      -1,    -1,    -1,    59,    60,    61,    62,    63,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    97,    98,    -1,    -1,   101,    -1,    -1,   104,    44,
      -1,    -1,     1,    -1,    -1,    -1,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,   124,    -1,
      -1,   127,   128,    22,    23,    24,    -1,    26,    -1,    28,
      29,    -1,    -1,    32,    33,    34,    -1,    82,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,    -1,    87,    -1,
     112,   113,    -1,    -1,   116,   117,    -1,    -1,    97,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,   127,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,   101,    -1,    -1,   104,   105,    -1,
      30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,   116,
      -1,    41,    42,    43,    44,    45,    -1,    47,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,   101,    -1,    -1,   104,   105,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,   116,    -1,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,   101,    -1,
      -1,   104,   105,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,   116,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    22,    23,    24,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,   104,   105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,   127,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    48,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    79,
      -1,    -1,    -1,    -1,    82,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,    -1,   116,   117,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,   112,   113,    -1,    -1,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,   116,   117,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,   116,   117,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,   116,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,   131,    62,     0,    63,   126,   133,   135,
     135,     1,     4,    33,    34,    36,    37,    41,    42,   132,
     134,   135,   137,   142,   143,   145,   148,   149,   150,   151,
     197,    24,    26,    62,   127,   144,    62,   140,   141,    62,
      37,   124,   132,   202,   202,   202,   151,   126,   135,   136,
     136,   136,   136,   144,   135,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    30,    35,    37,    41,    42,    43,    44,    47,    62,
      82,   101,   104,   105,   116,   132,   139,   180,   181,   195,
     208,   209,   210,   211,   212,   213,   214,   215,   217,   218,
     219,    65,    45,    47,   182,   191,   195,   196,   180,    62,
     180,   180,   180,    62,   144,   146,   147,   209,   132,   207,
     207,   207,   209,   209,   127,   209,   209,   209,    60,   129,
     180,   216,    79,    89,   117,   132,   185,   141,   185,   185,
     124,    44,   101,   104,   201,   218,   124,   124,   124,   144,
     135,   128,   146,   124,   124,   124,   128,   209,   129,    22,
      23,    24,    26,    28,    29,    37,    59,    60,    61,    87,
      97,    98,   101,   104,   112,   113,   114,   115,   124,   127,
     180,   199,   220,   222,   223,   226,   227,   228,   229,   230,
     231,   233,   186,   187,   218,    62,    83,   132,   188,   188,
      62,   132,   138,   203,   204,   205,    44,   218,    44,   218,
     125,   203,   204,   203,   204,   135,   203,   203,   204,   209,
     229,   230,   132,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,    85,    96,   128,   221,   229,   124,
     127,    26,   226,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    79,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   112,   113,
     116,   117,    65,    88,    79,   186,   189,   190,   127,   127,
      65,   209,   125,    65,   218,   218,   125,    65,   125,   125,
     125,   125,   125,   124,   125,   200,   229,   203,    65,   128,
     132,   221,   232,    62,   128,   221,   224,   225,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   209,   229,   124,   180,   186,   186,    65,   132,
     135,   192,   193,   194,   205,    37,    41,    42,   135,   183,
     184,    62,   139,     5,   205,   139,   209,   127,   209,   209,
     203,   128,    96,   229,   125,    83,   128,    65,   128,   129,
     209,   124,   189,   192,   128,   136,    62,    62,    62,   128,
     184,   125,   127,   127,     1,    32,    37,    49,    50,    51,
      52,    53,    55,   132,   135,   142,   143,   155,   156,   157,
     158,   159,   160,   172,   198,   206,   229,   125,   200,   229,
      62,   225,   125,   232,   124,   124,   124,   139,   206,   206,
     132,   152,   132,   154,   229,    62,   161,   162,   163,    62,
     132,   153,   153,   173,    58,   132,   179,   136,    55,   179,
     158,   136,   128,   139,   128,   125,   203,   203,   204,   128,
     128,   124,   132,   141,   142,   166,   168,   169,   132,   132,
     170,   229,    62,   136,   229,   136,   127,   125,   125,   125,
     203,   126,    65,   229,    48,   171,   171,   127,   132,   206,
     136,   209,   209,   136,   125,   132,   167,   229,   169,   171,
     159,    57,   132,   174,   176,   177,   159,   128,   136,   136,
     139,   126,   128,   175,   174,    56,   132,   178,   128,   127,
     132,   164,   165,   229,   170,   127,   206,   171,    65,   171,
     159,   128,   229,   128
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc = yyloc_default;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { yoParserModule(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 3:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 4:

    { yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 6:

    { yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 9:

    { yoParserNewLine(parm, &yyloc); yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 11:

    { yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 13:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 15:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 19:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 20:

    { yoParserDeclVar(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 21:

    {
				yoParserDeclVar(&(yyvsp[(3) - (4)]), &(yyvsp[(1) - (4)]), &(yyvsp[(2) - (4)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(1) - (4)]), &(yyvsp[(1) - (4)]), &(yyvsp[(4) - (4)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(1) - (4)]), parm, &yyloc);
			}
    break;

  case 22:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 23:

    { yoParserDeclType(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 26:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 27:

    { yoParserImport(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 28:

    { (yyval) = (yyvsp[(4) - (5)]); }
    break;

  case 29:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(1) - (2)]), parm, &yyloc); }
    break;

  case 30:

    { yoParserImport(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 32:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 39:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 47:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 48:

    { yoParserStmtBreak(&(yyval), &(yyvsp[(2) - (2)]), T_BREAK, parm, &yyloc); }
    break;

  case 49:

    { yoParserStmtBreak(&(yyval), &(yyvsp[(2) - (2)]), T_CONTINUE, parm, &yyloc); }
    break;

  case 52:

    { yoParserStmtIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(1) - (4)]), &(yyvsp[(4) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 53:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 58:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 59:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 63:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 64:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 65:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (8)]), &(yyvsp[(5) - (8)]), &(yyvsp[(7) - (8)]), &(yyvsp[(8) - (8)]), parm, &yyloc); 
			}
    break;

  case 66:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 67:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (5)]), &(yyvsp[(4) - (5)]), &(yyvsp[(3) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); 
			}
    break;

  case 68:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 69:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(3) - (4)]), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); 
			}
    break;

  case 73:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 80:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 83:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 84:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 85:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 86:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 87:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 89:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 92:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 94:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 97:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 98:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 99:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 101:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 102:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 103:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 104:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 105:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 107:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 110:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 112:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 113:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 117:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 118:

    { yoParserStruct(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 122:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 137:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), &(yyvsp[(9) - (9)]), NULL, true, YO_CALLING_C, parm, &yyloc); }
    break;

  case 138:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (7)]), &(yyvsp[(5) - (7)]), &(yyvsp[(7) - (7)]), NULL, false, YO_CALLING_C, parm, &yyloc); }
    break;

  case 139:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 141:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 142:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 143:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 144:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 145:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 146:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 151:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 152:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 157:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 158:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 163:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 164:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 165:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 168:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 169:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 170:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 171:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 172:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 173:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 174:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 177:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 179:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 180:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 181:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 182:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 183:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 184:

    { yoParserTypeStdName(&(yyval), T_INT, parm, &yyloc); }
    break;

  case 185:

    { yoParserTypeStdName(&(yyval), T_INTPTR, parm, &yyloc); }
    break;

  case 186:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 187:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 188:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 189:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 190:

    { yoParserTypeStdName(&(yyval), T_UINT, parm, &yyloc); }
    break;

  case 191:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 192:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 193:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 194:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 195:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 196:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 197:

    { yoParserTypeStdName(&(yyval), T_UNKNOWN_YET, parm, &yyloc); }
    break;

  case 198:

    { yoParserTypeStdName(&(yyval), T_MUTABLE, parm, &yyloc); }
    break;

  case 199:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 200:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 201:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 207:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 208:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 209:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 210:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 211:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 212:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 214:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 215:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 216:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 218:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 219:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 226:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_EQ, parm, &yyloc); }
    break;

  case 227:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_NE, parm, &yyloc); }
    break;

  case 228:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LE, parm, &yyloc); }
    break;

  case 229:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GE, parm, &yyloc); }
    break;

  case 230:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LT, parm, &yyloc); }
    break;

  case 231:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GT, parm, &yyloc); }
    break;

  case 232:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 233:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 234:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 235:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 236:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 237:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW, parm, &yyloc); }
    break;

  case 238:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 239:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LSH, parm, &yyloc); }
    break;

  case 240:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_RSH, parm, &yyloc); }
    break;

  case 241:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 242:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 243:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 244:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 245:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 246:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 247:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 248:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 250:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 253:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 254:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 255:

    { yoParserPostUnaryOp(&(yyval), &(yyvsp[(1) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 256:

    { yoParserPostUnaryOp(&(yyval), &(yyvsp[(1) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 257:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 258:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 259:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 260:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 261:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 262:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 263:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 264:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 265:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 266:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 267:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 268:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS_ASSIGN, parm, &yyloc); }
    break;

  case 269:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS_ASSIGN, parm, &yyloc); }
    break;

  case 270:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL_ASSIGN, parm, &yyloc); }
    break;

  case 271:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV_ASSIGN, parm, &yyloc); }
    break;

  case 272:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD_ASSIGN, parm, &yyloc); }
    break;

  case 273:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR_ASSIGN, parm, &yyloc); }
    break;

  case 274:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND_ASSIGN, parm, &yyloc); }
    break;

  case 275:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR_ASSIGN, parm, &yyloc); }
    break;

  case 276:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_RSH_ASSIGN, parm, &yyloc); }
    break;

  case 277:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LSH_ASSIGN, parm, &yyloc); }
    break;

  case 278:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW_ASSIGN, parm, &yyloc); }
    break;

  case 279:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT_ASSIGN, parm, &yyloc); }
    break;

  case 282:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 283:

    { 
			yoParserBinOp(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(3) - (6)]), T_DOT, parm, &yyloc);
			yoParserCall(&(yyval), &(yyval), &(yyvsp[(5) - (6)]), parm, &yyloc);
		}
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}




