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
void yoParserStmtSwitch(YYSTYPE * r, YYSTYPE * condition, YYSTYPE * body, void * parm, YYLTYPE * loc);
void yoParserStmtCase(YYSTYPE * r, YYSTYPE * expr, void * parm, YYLTYPE * loc);
void yoParserStmtDefault(YYSTYPE * r, void * parm, YYLTYPE * loc);
void yoParserStmtFallThrough(YYSTYPE * r, void * parm, YYLTYPE * loc);
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
     T_SWITCH = 309,
     T_CASE = 310,
     T_DEFAULT = 311,
     T_FALLTHROUGH = 312,
     T_IN = 313,
     T_IF = 314,
     T_ELSE = 315,
     T_ELSEIF = 316,
     T_CATCH = 317,
     T_SIZEOF = 318,
     T_LNUMBER = 319,
     T_DNUMBER = 320,
     T_NAME = 321,
     T_NEWLINE = 322,
     T_FIX = 323,
     T_POW_ASSIGN = 324,
     T_RSH_ASSIGN = 325,
     T_LSH_ASSIGN = 326,
     T_XOR_ASSIGN = 327,
     T_OR_ASSIGN = 328,
     T_AND_ASSIGN = 329,
     T_MOD_ASSIGN = 330,
     T_CONCAT_ASSIGN = 331,
     T_DIV_ASSIGN = 332,
     T_MUL_ASSIGN = 333,
     T_MINUS_ASSIGN = 334,
     T_PLUS_ASSIGN = 335,
     T_DECL_ASSIGN = 336,
     T_ASSIGN = 337,
     T_INIT_ASSIGN = 338,
     T_PROP_ASSIGN = 339,
     T_XORXOR = 340,
     T_OROR = 341,
     T_ANDAND = 342,
     T_CHAN_ACCESS = 343,
     T_GT = 344,
     T_LT = 345,
     T_GE = 346,
     T_LE = 347,
     T_NE = 348,
     T_EQ = 349,
     T_CONCAT = 350,
     T_XOR = 351,
     T_OR = 352,
     T_MINUS = 353,
     T_PLUS = 354,
     T_RSH = 355,
     T_LSH = 356,
     T_AND = 357,
     T_MOD = 358,
     T_DIV = 359,
     T_MUL = 360,
     T_POW = 361,
     T_AS = 362,
     T_ADDR = 363,
     T_INDIRECT = 364,
     T_AT = 365,
     T_POST_UNARY = 366,
     T_UNARY = 367,
     T_DEC = 368,
     T_INC = 369,
     T_TILDE = 370,
     T_NOT = 371,
     T_DOT = 372,
     T_INDEX = 373,
     T_REF = 374,
     T_PTR = 375,
     T_ARR = 376,
     T_DOTNAME = 377,
     NotParen = 378
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
#define YYLAST   2146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  134
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  110
/* YYNRULES -- Number of rules.  */
#define YYNRULES  297
/* YYNRULES -- Number of states.  */
#define YYNSTATES  566

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   378

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     128,   129,     2,     2,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,   130,
       2,     2,     2,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   120,     2,   133,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   131,     2,   132,     2,     2,     2,     2,
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
      65,    66,    67,    68,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   121,   122,   123,   124,   125,   126,   127
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
     132,   134,   136,   141,   145,   148,   151,   153,   155,   157,
     159,   161,   163,   167,   170,   172,   174,   176,   179,   180,
     189,   190,   196,   197,   202,   204,   206,   208,   212,   214,
     216,   218,   220,   222,   224,   228,   230,   232,   234,   235,
     240,   244,   247,   249,   251,   255,   256,   263,   264,   269,
     271,   274,   276,   278,   283,   285,   291,   293,   295,   299,
     303,   310,   312,   315,   322,   330,   338,   345,   347,   351,
     353,   355,   359,   361,   365,   368,   370,   372,   374,   378,
     385,   388,   390,   392,   395,   397,   399,   401,   403,   405,
     407,   409,   411,   413,   415,   417,   419,   421,   423,   433,
     441,   452,   463,   473,   483,   493,   500,   505,   507,   509,
     512,   516,   519,   523,   528,   530,   532,   534,   536,   540,
     543,   545,   547,   549,   555,   562,   569,   575,   577,   579,
     582,   585,   588,   591,   594,   597,   600,   604,   606,   608,
     613,   615,   618,   620,   622,   624,   626,   628,   630,   632,
     634,   636,   638,   640,   642,   644,   646,   648,   650,   652,
     654,   656,   658,   660,   662,   664,   666,   668,   670,   672,
     676,   679,   683,   687,   692,   697,   699,   703,   707,   710,
     712,   715,   718,   720,   722,   724,   726,   728,   730,   734,
     738,   742,   746,   750,   754,   758,   762,   766,   770,   774,
     778,   782,   786,   790,   794,   798,   802,   806,   810,   814,
     818,   823,   825,   829,   831,   833,   837,   843,   846,   849,
     852,   855,   858,   861,   864,   867,   870,   873,   876,   879,
     882,   885,   889,   893,   897,   901,   905,   909,   913,   917,
     921,   925,   929,   933,   937,   939,   941,   946
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     135,     0,    -1,     3,    66,   137,   138,    -1,     1,    -1,
      -1,   139,    -1,   130,   139,    -1,   141,    -1,   136,    -1,
      67,    -1,   139,    -1,   130,    -1,   155,    -1,   141,   155,
      -1,    66,    -1,   142,    69,    66,    -1,   219,    -1,   136,
      -1,   145,    -1,   144,    69,   145,    -1,    66,   143,    -1,
      66,   143,    83,   239,    -1,    33,   144,    -1,    34,    66,
     206,    -1,    26,    -1,    24,    -1,     4,   148,    -1,     4,
      66,   148,    -1,     4,   131,   139,   151,   132,    -1,   148,
     139,    -1,    66,   148,   139,    -1,   150,    -1,   151,   150,
      -1,   146,    -1,   147,    -1,   149,   140,    -1,   153,   140,
      -1,   152,   140,    -1,   207,   140,    -1,     1,    -1,   154,
      -1,   139,    -1,   136,    -1,    66,    -1,   136,    -1,   239,
      -1,   136,    -1,    32,   158,    -1,    52,   157,    -1,    53,
     157,    -1,   239,    -1,   159,    -1,   159,    59,   239,   136,
      -1,   146,   189,   140,    -1,   208,   140,    -1,   147,   140,
      -1,   182,    -1,   164,    -1,   175,    -1,   177,    -1,   178,
      -1,   179,    -1,   160,   189,   140,    -1,     1,   156,    -1,
     161,    -1,   139,    -1,   162,    -1,   163,   162,    -1,    -1,
      49,   165,   170,   130,   171,   130,   168,   181,    -1,    -1,
      50,   166,   136,   239,   181,    -1,    -1,    51,   167,   136,
     181,    -1,   169,    -1,   136,    -1,   239,    -1,   169,    69,
     239,    -1,   146,    -1,   172,    -1,   136,    -1,   239,    -1,
     136,    -1,   173,    -1,   172,    69,   173,    -1,   145,    -1,
     180,    -1,   136,    -1,    -1,    54,   176,   174,   181,    -1,
      55,   231,    87,    -1,    56,    87,    -1,    57,    -1,   239,
      -1,    48,   163,   132,    -1,    -1,    59,   183,   180,   181,
     187,   188,    -1,    -1,    61,   185,   180,   181,    -1,   184,
      -1,   186,   184,    -1,   186,    -1,   136,    -1,    60,   131,
     163,   132,    -1,   136,    -1,    62,    66,   131,   163,   132,
      -1,   136,    -1,    66,    -1,   190,   121,    66,    -1,    47,
     131,   132,    -1,    47,   195,   198,   131,   193,   132,    -1,
     194,    -1,   193,   194,    -1,    37,    66,   128,   213,   129,
     140,    -1,    37,    66,   128,   213,   129,   219,   140,    -1,
      41,    66,   128,   213,   129,   219,   140,    -1,    42,    66,
     128,   214,   129,   140,    -1,   139,    -1,    93,   197,    92,
      -1,   136,    -1,   228,    -1,   228,    83,   196,    -1,   196,
      -1,   197,    69,   196,    -1,    87,   200,    -1,   136,    -1,
     196,    -1,   199,    -1,   200,    69,   199,    -1,    45,   195,
     198,   131,   204,   132,    -1,   215,   140,    -1,   139,    -1,
     202,    -1,   203,   202,    -1,   203,    -1,   136,    -1,   228,
      -1,   220,    -1,   221,    -1,   222,    -1,   224,    -1,   223,
      -1,   225,    -1,   227,    -1,   218,    -1,   205,    -1,   192,
      -1,   201,    -1,    36,    37,   190,   128,   214,    69,     5,
     129,   143,    -1,    36,    37,   190,   128,   213,   129,   143,
      -1,    37,   212,   190,   128,   213,   129,   143,   131,   216,
     132,    -1,    41,   212,   190,   128,   213,   129,   219,   131,
     216,   132,    -1,    42,   212,   190,   128,   214,   129,   131,
     216,   132,    -1,    37,    66,   128,   213,   129,   143,   131,
     216,   132,    -1,    37,   136,   128,   213,   129,   143,   131,
     216,   132,    -1,   131,   100,   213,   100,   210,   132,    -1,
     131,    89,   210,   132,    -1,   239,    -1,   228,    -1,   108,
     228,    -1,   108,    44,   228,    -1,   105,   228,    -1,   105,
      44,   228,    -1,   128,    66,   211,   129,    -1,   136,    -1,
     214,    -1,   136,    -1,   215,    -1,   214,    69,   215,    -1,
     142,   219,    -1,   163,    -1,   136,    -1,   136,    -1,    37,
     217,   128,   213,   129,    -1,    37,   217,   128,   213,   129,
     219,    -1,    41,   217,   128,   213,   129,   219,    -1,    42,
     217,   128,   214,   129,    -1,   205,    -1,   191,    -1,    43,
     219,    -1,    44,   219,    -1,    35,   219,    -1,   105,   219,
      -1,    90,   219,    -1,   108,   219,    -1,   109,   219,    -1,
     120,   133,   219,    -1,    64,    -1,   190,    -1,   120,   226,
     133,   219,    -1,   229,    -1,   190,   195,    -1,     6,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,
      12,    -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,
      17,    -1,    20,    -1,    18,    -1,    19,    -1,    21,    -1,
      30,    -1,    86,    -1,    44,    -1,    22,    -1,    23,    -1,
      29,    -1,    64,    -1,    65,    -1,    24,    -1,    26,    -1,
     239,    -1,   231,    69,   239,    -1,   131,   132,    -1,   131,
     231,   132,    -1,   190,   131,   132,    -1,   190,   131,   231,
     132,    -1,   190,   131,   234,   132,    -1,   235,    -1,   234,
      69,   235,    -1,    66,    87,   239,    -1,    28,   240,    -1,
     236,    -1,   237,   236,    -1,   237,    26,    -1,   240,    -1,
     238,    -1,   230,    -1,   190,    -1,   232,    -1,   233,    -1,
     239,    97,   239,    -1,   239,    96,   239,    -1,   239,    95,
     239,    -1,   239,    94,   239,    -1,   239,    93,   239,    -1,
     239,    92,   239,    -1,   239,   102,   239,    -1,   239,   101,
     239,    -1,   239,   108,   239,    -1,   239,   107,   239,    -1,
     239,   106,   239,    -1,   239,   109,   239,    -1,   239,    98,
     239,    -1,   239,   104,   239,    -1,   239,   103,   239,    -1,
     239,   100,   239,    -1,   239,    89,   239,    -1,   239,   105,
     239,    -1,   239,    90,   239,    -1,   239,    99,   239,    -1,
     239,    91,   239,    -1,   239,   121,   190,    -1,   239,   120,
     239,   133,    -1,   241,    -1,   128,   239,   129,    -1,   243,
      -1,   209,    -1,   239,   110,   219,    -1,   239,   121,   128,
     219,   129,    -1,   239,   117,    -1,   239,   116,    -1,   117,
     239,    -1,   116,   239,    -1,   102,   239,    -1,   101,   239,
      -1,   119,   239,    -1,   118,   239,    -1,    91,   239,    -1,
      63,   239,    -1,   108,   239,    -1,   109,   239,    -1,   105,
     239,    -1,    90,   239,    -1,   239,    83,   239,    -1,   239,
      81,   239,    -1,   239,    80,   239,    -1,   239,    79,   239,
      -1,   239,    78,   239,    -1,   239,    76,   239,    -1,   239,
      74,   239,    -1,   239,    75,   239,    -1,   239,    73,   239,
      -1,   239,    71,   239,    -1,   239,    72,   239,    -1,   239,
      70,   239,    -1,   239,    77,   239,    -1,   231,    -1,   136,
      -1,   190,   128,   242,   129,    -1,   239,   121,   190,   128,
     242,   129,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   242,   242,   243,   246,   255,   256,   259,   260,   263,
     266,   267,   270,   271,   274,   275,   278,   279,   282,   283,
     286,   287,   294,   297,   300,   301,   304,   305,   306,   309,
     310,   313,   314,   317,   320,   323,   324,   325,   326,   327,
     330,   331,   334,   342,   343,   346,   347,   350,   351,   352,
     353,   356,   357,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   373,   374,   377,   378,   394,   394,
     397,   397,   400,   400,   405,   406,   409,   410,   413,   414,
     415,   418,   419,   422,   423,   426,   429,   430,   433,   433,
     438,   441,   444,   447,   450,   453,   453,   458,   458,   462,
     463,   466,   467,   470,   471,   474,   475,   478,   479,   482,
     485,   488,   489,   492,   493,   494,   495,   496,   499,   500,
     503,   504,   507,   508,   511,   512,   515,   518,   519,   522,
     525,   526,   543,   544,   547,   548,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   562,   563,   564,   567,   569,
     571,   573,   575,   579,   587,   589,   591,   595,   599,   600,
     601,   602,   603,   606,   607,   610,   611,   614,   615,   618,
     621,   622,   631,   634,   635,   636,   637,   640,   641,   644,
     647,   650,   653,   654,   657,   658,   665,   669,   670,   673,
     677,   679,   682,   683,   684,   685,   686,   687,   688,   689,
     690,   691,   692,   693,   694,   695,   696,   697,   698,   699,
     700,   703,   704,   705,   706,   707,   708,   709,   712,   713,
     716,   717,   720,   721,   723,   726,   727,   730,   733,   736,
     737,   740,   743,   744,   757,   758,   759,   760,   761,   762,
     763,   764,   765,   766,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   780,   782,   783,
     784,   785,   786,   787,   788,   789,   790,   791,   792,   793,
     794,   795,   796,   797,   798,   799,   800,   801,   802,   803,
     804,   820,   821,   822,   823,   824,   825,   826,   827,   828,
     829,   830,   831,   832,   835,   836,   839,   840
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
  "T_FOR", "T_WHILE", "T_LOOP", "T_BREAK", "T_CONTINUE", "T_SWITCH",
  "T_CASE", "T_DEFAULT", "T_FALLTHROUGH", "T_IN", "T_IF", "T_ELSE",
  "T_ELSEIF", "T_CATCH", "T_SIZEOF", "T_LNUMBER", "T_DNUMBER", "T_NAME",
  "T_NEWLINE", "T_FIX", "','", "\"**= (T_POW_ASSIGN)\"",
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
  "var_assign_list", "var_assign_elem", "switch_header", "switch_stmt",
  "$@4", "case_stmt", "default_stmt", "fallthrough_stmt", "if_header",
  "brace_stmt", "if_stmt", "$@5", "elseif", "$@6", "elseif_list",
  "elseif_list_or_empty", "else", "catch", "dotname",
  "type_contract_empty", "type_contract", "contract_body",
  "contract_decl_func", "template", "template_arg", "template_arg_list",
  "extends", "extends_elem", "extends_list", "type_struct",
  "struct_body_stmt", "struct_body_stmt_list", "struct_body", "type_base",
  "type_ext", "top_decl_func", "decl_func", "expr_decl_func",
  "lambda_body", "type_self", "decl_self", "decl_arg_list_or_empty",
  "decl_arg_list", "decl_arg", "func_body", "decl_self_nop", "type_func",
  "type", "type_const", "type_mutable", "type_chan", "type_ref",
  "type_ptr", "type_slice", "type_arr_size", "type_arr", "type_name",
  "type_std_name", "expr_const_scalar", "expr_list", "expr_arr",
  "expr_obj", "prop_assing_list", "prop_assing",
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,    44,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,    63,    58,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
      91,   372,   373,   374,   375,   376,   377,   378,    40,    41,
      59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   134,   135,   135,   136,   137,   137,   138,   138,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   147,   148,   148,   149,   149,   149,   150,
     150,   151,   151,   152,   153,   154,   154,   154,   154,   154,
     155,   155,   156,   157,   157,   158,   158,   159,   159,   159,
     159,   160,   160,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   162,   162,   163,   163,   165,   164,
     166,   164,   167,   164,   168,   168,   169,   169,   170,   170,
     170,   171,   171,   172,   172,   173,   174,   174,   176,   175,
     177,   178,   179,   180,   181,   183,   182,   185,   184,   186,
     186,   187,   187,   188,   188,   189,   189,   190,   190,   191,
     192,   193,   193,   194,   194,   194,   194,   194,   195,   195,
     196,   196,   197,   197,   198,   198,   199,   200,   200,   201,
     202,   202,   203,   203,   204,   204,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   206,   206,   206,   207,   207,
     207,   207,   207,   208,   209,   209,   209,   210,   211,   211,
     211,   211,   211,   212,   212,   213,   213,   214,   214,   215,
     216,   216,   217,   218,   218,   218,   218,   219,   219,   220,
     221,   222,   223,   223,   224,   224,   225,   226,   226,   227,
     228,   228,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   230,   230,   230,   230,   230,   230,   230,   231,   231,
     232,   232,   233,   233,   233,   234,   234,   235,   236,   237,
     237,   238,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   242,   242,   243,   243
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     3,
       2,     4,     2,     3,     1,     1,     2,     3,     5,     2,
       3,     1,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     1,     4,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     1,     1,     2,     0,     8,
       0,     5,     0,     4,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     0,     4,
       3,     2,     1,     1,     3,     0,     6,     0,     4,     1,
       2,     1,     1,     4,     1,     5,     1,     1,     3,     3,
       6,     1,     2,     6,     7,     7,     6,     1,     3,     1,
       1,     3,     1,     3,     2,     1,     1,     1,     3,     6,
       2,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     9,     7,
      10,    10,     9,     9,     9,     6,     4,     1,     1,     2,
       3,     2,     3,     4,     1,     1,     1,     1,     3,     2,
       1,     1,     1,     5,     6,     6,     5,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     3,     1,     1,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     4,     4,     1,     3,     3,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     1,     3,     1,     1,     3,     5,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     4,     6
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
       0,     0,   164,     0,     0,     0,    13,    11,    10,    35,
      37,    36,    38,    27,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   205,   206,   204,
     207,   208,     0,     4,     4,     4,     0,   210,     0,   107,
     209,     0,     0,     0,     0,     0,    17,    20,     4,   178,
     177,   144,    16,   137,   138,   139,   141,   140,   142,   143,
     136,   190,     0,     4,     4,   146,   147,   145,    23,     0,
       0,     0,     0,     0,     0,     0,    31,     0,   181,   172,
       0,     0,     0,   179,   180,     0,   183,   182,   184,   185,
     187,     0,   188,     0,     0,     0,     0,   119,   191,    19,
       4,     4,     4,   210,     0,     0,     0,   158,     4,     4,
       0,     0,    29,    28,    32,     4,     4,     0,   109,   186,
       0,   211,   212,   216,   217,     0,   213,     4,     0,   214,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   264,   234,   236,   237,   229,
       0,   233,    21,   232,   261,   263,   122,     0,   120,   108,
       0,   125,     0,     0,    14,   166,     0,     0,   165,   167,
     210,   161,   210,   159,   163,     0,   165,     0,     0,    30,
       0,     0,     0,   189,     0,   232,     0,   276,   280,   275,
     272,   271,   279,   277,   278,   270,   269,   274,   273,     0,
       0,     4,   220,     0,   218,     4,     0,   231,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   267,     0,     0,     0,   118,
       0,   126,   127,   124,     4,     0,     0,   169,     4,     0,
     162,   160,     4,     0,     0,     0,   173,     0,   176,     4,
     262,     0,   157,     0,     0,   221,   295,   294,     0,   107,
     222,     0,     0,   225,   292,   290,   291,   289,   287,   288,
     286,   293,   285,   284,   283,   282,   281,   254,   256,   258,
     243,   242,   241,   240,   239,   238,   250,   257,   253,   245,
     244,   252,   251,   255,   248,   247,   246,   249,   265,     0,
       0,   259,   123,   121,     0,   135,   131,   132,   134,     0,
       0,     0,     0,     0,   117,     0,   111,    15,   149,     0,
     168,     0,     0,     0,   174,   175,     0,   156,     0,   219,
     296,     0,   223,     0,   224,   260,     0,     4,   128,   133,
     129,   130,     0,     0,     0,   110,   112,     4,     0,     0,
       4,     4,     4,    68,    70,    72,     4,     4,    88,     0,
       0,    92,    95,   171,    65,     4,     0,    51,     4,    64,
      66,     0,    57,    58,    59,    60,    61,    56,     0,     0,
      50,     4,     0,   227,     0,   226,   266,     0,     4,     4,
       0,   148,     0,     0,    42,    63,    46,    47,    45,     0,
       4,     4,     4,    43,    44,    48,    49,     4,     0,    91,
       0,     0,   106,     0,    55,     0,     0,    67,    54,   152,
       0,   155,   297,     0,     0,     0,   150,   151,     4,    80,
      85,    78,     0,    79,    83,     0,     0,    87,     0,    86,
      93,    90,     0,     0,    53,     4,    62,     0,     0,     0,
       0,     0,     4,     0,     0,     0,    73,    89,     4,     0,
      52,     0,   113,     0,     0,   116,     4,    82,     0,    81,
      84,    71,     0,    97,   102,    99,   101,     4,     0,   154,
     114,   115,     0,     4,    94,     0,   100,     0,   104,    96,
     105,     0,    75,     0,    74,    76,     0,     0,     0,    69,
       0,    98,     0,   153,    77,   103
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   205,     8,    20,    48,    49,    22,   206,    87,
      37,   490,   425,   426,   115,    25,   116,   117,    26,    27,
      28,    29,   455,   465,   457,   427,   428,   429,   430,   431,
     432,   460,   461,   462,   553,   554,   492,   528,   493,   494,
     498,   433,   467,   434,   435,   436,   499,   516,   437,   470,
     535,   545,   536,   537,   549,   473,   184,    89,   105,   375,
     376,   138,   291,   197,   202,   292,   293,   106,   367,   368,
     369,    90,   108,    30,   438,   185,   311,   146,    43,   207,
     216,   209,   439,   120,    91,    92,    93,    94,    95,    96,
      97,    98,   133,    99,   100,   101,   186,   317,   187,   188,
     322,   323,   189,   190,   191,   440,   193,   194,   318,   195
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -462
static const yytype_int16 yypact[] =
{
      73,  -462,    11,    87,   -20,  -462,  -462,    38,   140,  -462,
    -462,  -462,    26,    85,    88,    94,    14,    14,    14,  -462,
    -462,  -462,   179,  -462,  -462,    -8,    -8,    -8,  -462,  -462,
      -8,  -462,  -462,    72,    38,  -462,  1727,   100,  -462,  1497,
      90,   119,  -462,    90,    90,    90,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,    41,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,  1727,  -462,  -462,  -462,  1727,  1727,    86,  -462,
    -462,  1727,  1727,  1727,  1727,     0,  -462,   108,   -24,  -462,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,
    -462,  -462,    85,   116,   116,  -462,  -462,  -462,  -462,    65,
     267,    74,    78,    82,    72,    38,  -462,    16,  -462,  -462,
      83,    91,    97,  -462,  -462,    95,  -462,  -462,  -462,  -462,
    -462,  1727,   126,   118,  1687,   746,   186,  -462,  -462,  -462,
     166,   166,   188,  -462,   976,  1087,   131,  -462,   188,   188,
     188,    38,  -462,  -462,  -462,   188,   188,   188,  -462,  -462,
    1727,  -462,  -462,  -462,  -462,  1687,  -462,  -462,  1687,  -462,
    -462,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,
    1687,  1687,  1687,  1460,    39,  -462,  -462,  -462,  -462,  -462,
     111,  -462,  1964,  -462,  -462,  -462,  -462,    60,   172,  -462,
     746,  -462,   130,   132,  -462,  -462,  1612,   133,   195,  -462,
     746,  -462,   746,  -462,  -462,   136,   197,   141,   -38,  -462,
     142,   143,   -23,  -462,  1964,   138,   129,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,  1904,
    1687,   188,  -462,     3,  1964,  1687,  1575,  -462,  -462,  1687,
    1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,
    1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,
    1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,  1687,
    1687,  1687,  1687,  1727,  -462,  -462,  1687,   -39,   746,  -462,
     746,  -462,  -462,   198,   156,   147,   203,  -462,  1727,    15,
    -462,  -462,  1727,   188,  1727,   158,  1842,  1727,  -462,   188,
    -462,   160,  1964,   193,  1687,  -462,  -462,   225,   167,   208,
    -462,     4,     6,  -462,  1964,  1964,  1964,  1964,  1964,  1964,
    1964,  1964,  1964,  1964,  1964,  1964,  1964,  1113,  1223,  1995,
    2025,  2025,  2025,  2025,  2025,  2025,   238,   238,   238,   238,
     238,   122,   122,   122,   122,   122,   122,    80,  -462,  1840,
    1727,   170,  -462,  -462,   746,  -462,  -462,  -462,   156,   168,
      -8,   236,   243,   247,  -462,    76,  -462,  -462,  -462,   175,
    -462,   183,   184,   679,  -462,  -462,   189,  -462,  1687,  1964,
    -462,  1687,  -462,   251,  -462,  -462,   190,  1687,  -462,  -462,
    -462,  -462,   199,   200,   201,  -462,  -462,  1727,   679,   679,
    -462,  1687,   255,  -462,  -462,  -462,   257,   257,  -462,  1687,
     239,  -462,  -462,  -462,  -462,   268,    -8,   272,   268,  -462,
    -462,   793,  -462,  -462,  -462,  -462,  -462,  -462,    -8,   202,
    1964,  1727,   204,  1964,   208,  -462,  -462,   206,   188,   188,
     188,  -462,   207,   217,  -462,  -462,  -462,  -462,  1964,   212,
      53,  -462,  -462,  -462,  -462,  -462,  -462,  1687,     1,  -462,
    1687,   266,  -462,    -8,  -462,  1687,    -8,  -462,  -462,  -462,
     219,  -462,  -462,   223,   227,   -14,  -462,  -462,   188,  -462,
    -462,  -462,   230,   288,  -462,  1687,   313,  -462,   313,  -462,
    1964,  -462,   313,   231,  -462,  1964,  -462,   679,  1372,  1727,
      -8,   234,  1687,    85,   509,  1246,  -462,  -462,   304,  1246,
    -462,   235,  -462,    -8,    -8,  -462,  1727,  -462,   240,  1964,
    -462,  -462,   913,  -462,  -462,  -462,   304,   306,  1024,  -462,
    -462,  -462,   237,  1687,  -462,  1687,  -462,   242,  -462,  -462,
    -462,   679,  -462,   313,   300,  1964,   313,  1246,   244,  -462,
    1687,  -462,  1135,  -462,  1964,  -462
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -462,  -462,     5,  -462,  -462,    -4,   -19,  -462,  -462,  -286,
    -462,    30,    -7,    63,    20,  -462,   263,  -462,  -462,  -462,
    -462,   352,  -462,   -36,  -462,  -462,  -462,  -462,  -412,  -392,
    -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -462,  -130,
    -462,  -462,  -462,  -462,  -462,  -462,  -461,  -327,  -462,  -462,
    -152,  -462,  -462,  -462,  -462,   -43,    18,  -462,  -462,  -462,
      12,   101,  -129,  -462,   245,    25,  -462,  -462,    22,  -462,
    -462,   353,  -462,  -462,  -462,  -462,     7,  -462,   216,  -111,
    -140,  -243,  -383,   162,  -462,   -48,  -462,  -462,  -462,  -462,
    -462,  -462,  -462,  -462,   -96,  -462,  -462,  -178,  -462,  -462,
    -462,    -2,   209,  -462,  -462,   395,   228,  -462,    -3,  -462
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -229
static const yytype_int16 yytable[] =
{
       9,    23,   208,    10,    21,   243,   196,    50,    51,   502,
     218,    52,   378,    19,   147,    23,   381,   222,    21,   477,
     379,    42,    42,    42,   118,   452,   453,    79,   123,   124,
      54,   303,    35,   126,   127,   128,   129,   215,   217,   198,
      31,    86,    32,    38,   220,   221,   303,     6,   211,   213,
      31,   370,    32,    53,    88,   303,   380,    88,   109,     6,
     380,   111,   112,   113,   130,    31,    79,    32,   321,   135,
     314,    24,   314,   314,     1,   393,     2,     4,   119,   119,
     119,   204,   114,   159,   556,    24,    13,     5,   501,   360,
      88,   305,    33,   137,    88,    88,    31,   136,    32,    88,
      88,    88,    88,   132,   198,     6,   308,   114,   137,   137,
       7,   152,   223,   371,   300,   510,   301,   372,   373,    36,
     477,   451,    47,   532,   521,   370,   477,   538,    88,   288,
     313,    40,   139,   131,   151,   315,   392,   247,   394,   165,
      -4,    11,    41,     6,    12,   201,   201,   219,   153,    88,
     477,    36,   289,    88,    39,   480,    79,    34,   297,   362,
     136,   363,    88,    88,  -228,   562,  -228,   245,   558,   102,
     246,   517,   226,    13,    14,   518,    15,    16,    88,    -7,
      11,    17,    18,    12,   371,   110,   136,   531,   372,   373,
     283,   134,   198,   142,   198,   136,   284,   285,   386,   136,
     286,   287,   148,   136,   140,   141,   149,     6,   405,   135,
     150,   155,    13,    14,     6,    15,    16,   125,    88,   156,
      17,    18,   204,     6,    88,   157,   559,   158,    88,   561,
      88,   282,   283,    44,    45,   358,   121,   122,   284,   285,
     542,   468,   286,   287,   284,   285,     6,   136,   286,   287,
     316,   160,   199,   200,   204,   290,   382,   309,   384,   385,
     214,   294,   298,   295,   299,   302,   303,   364,   198,   377,
     304,   306,   307,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   383,
     366,   374,   387,   388,   314,   391,   390,    71,   397,   365,
     400,    88,   402,    86,   407,   361,    88,    86,    88,   403,
     485,   143,   396,   404,   408,   409,    88,   444,   441,   446,
      88,   459,    88,   463,    88,    88,   469,   448,   449,   450,
     471,   475,   503,    79,   479,   482,   481,   483,   484,   486,
     488,   276,   277,   278,   279,   280,   281,   282,   283,   487,
     507,   401,   508,    80,   284,   285,   509,   513,   286,   287,
     512,   515,   519,   526,   366,   533,   547,   539,   551,   560,
     543,   374,   144,   557,    46,   145,   563,   511,    88,   424,
     154,   466,    88,   530,   546,   476,   203,   406,   423,   398,
     399,   445,   107,   225,   447,   442,     0,     0,     0,   248,
       0,     0,   316,     0,   424,   424,     0,   474,     0,     0,
       0,     0,    86,   423,   423,   454,   456,   226,     0,   478,
       0,   464,   464,     0,     0,    88,     0,   424,     0,     0,
     472,     0,     0,   472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
       0,     0,     0,   491,   504,     0,     0,   506,     0,    88,
     523,   524,     0,     0,     0,   489,   495,   496,     0,     0,
       0,     0,   497,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,   525,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   424,   540,   541,     0,     0,     0,     0,
     520,   424,   423,     0,     0,   424,     0,   527,     0,     0,
       0,     0,     0,   534,     0,     0,    88,    88,   424,   192,
       0,    86,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,   548,     0,    88,     0,     0,   424,   552,     0,
       0,     0,     0,   424,     0,     0,   423,   515,   424,     0,
     224,     0,     0,   227,     0,     0,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   244,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,     0,   261,     0,     0,     0,     0,     0,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
       0,     0,     0,     0,     0,   284,   285,     0,     0,   286,
     287,     0,     0,     0,     0,   312,     0,     0,     0,     0,
     244,   244,     0,     0,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,     0,     0,
     410,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   161,   162,   163,     0,   164,     0,   165,   166,   389,
       0,   411,    13,    14,     0,     0,   412,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   413,   414,
     415,   416,   417,   418,   419,   420,   421,     0,   422,     0,
       0,     0,   168,   169,   170,    79,     6,     0,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,   171,
     172,     0,     0,     0,     0,     0,    71,     0,     0,     0,
     173,   174,     0,   312,   175,     0,   443,   176,   177,     0,
     143,     0,   244,     0,   410,   178,   179,   180,   181,     0,
       0,     0,     0,     0,     0,     0,   458,   182,     0,     0,
     183,    -4,    79,     0,   244,   161,   162,   163,     0,   164,
       0,   165,   166,     0,     0,   411,    13,    14,     0,     0,
     412,     0,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   413,   414,   415,   416,   417,   418,   419,   420,
     421,     0,   422,     0,     0,     0,   168,   169,   170,    79,
       6,     0,   500,     0,     0,   500,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,     0,     0,     0,     0,     0,
     514,     0,     0,     0,   173,   174,     0,     0,   175,     0,
       0,   176,   177,     0,     0,     0,     0,   529,     0,   178,
     179,   180,   181,     0,   410,     0,     0,     0,     0,     0,
       0,   182,     0,     0,   183,  -170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   162,   163,   555,   164,
     500,   165,   166,     0,     0,   411,    13,    14,     0,     0,
     412,     0,     0,     0,     0,   564,     0,     0,     0,     0,
       0,     0,   413,   414,   415,   416,   417,   418,   419,   420,
     421,     0,   422,     0,     0,     0,   168,   169,   170,    79,
       6,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,   171,   172,     0,    71,     0,     0,     0,
       0,     0,     0,     0,   173,   174,     0,     0,   175,     0,
     210,   176,   177,     0,     0,   410,     0,     0,     0,   178,
     179,   180,   181,     0,     0,     0,     0,     0,     0,     0,
       0,   182,    79,     0,   183,   544,   161,   162,   163,     0,
     164,     0,   165,   166,     0,     0,   411,    13,    14,     0,
       0,   412,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   413,   414,   415,   416,   417,   418,   419,
     420,   421,     0,   422,     0,     0,     0,   168,   169,   170,
      79,     6,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,     0,     0,     0,   171,   172,     0,    71,     0,     0,
       0,     0,     0,     0,     0,   173,   174,     0,     0,   175,
       0,   212,   176,   177,     0,     0,   410,     0,     0,     0,
     178,   179,   180,   181,     0,     0,     0,     0,     0,     0,
       0,     0,   182,    79,     0,   183,   550,   161,   162,   163,
       0,   164,     0,   165,   166,     0,     0,   411,    13,    14,
       0,     0,   412,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   413,   414,   415,   416,   417,   418,
     419,   420,   421,     0,   422,     0,     0,     0,   168,   169,
     170,    79,     6,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,   171,   172,     0,     0,   284,
     285,     0,     0,   286,   287,     0,   173,   174,     0,     0,
     175,     0,     0,   176,   177,     0,     0,   410,     0,     0,
       0,   178,   179,   180,   181,     0,     0,     0,     0,     0,
       0,     0,     0,   182,     0,     0,   183,   565,   161,   162,
     163,     0,   164,     0,   165,   166,     0,     0,   411,    13,
      14,     0,     0,   412,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   413,   414,   415,   416,   417,
     418,   419,   420,   421,     0,   422,     0,     0,     0,   168,
     169,   170,    79,     6,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,     0,     0,   171,   172,     0,   284,
     285,     0,     0,   286,   287,     0,     0,   173,   174,     0,
       0,   175,     0,     0,   176,   177,     0,     0,     0,     0,
       0,     0,   178,   179,   180,   181,     0,     0,     0,     0,
       0,     0,     0,     0,   182,     0,     0,   183,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,    72,     0,    73,
       0,     0,     0,    74,    75,    76,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,     0,     0,
      83,    84,   161,   162,   163,     0,   164,     0,   165,   166,
       0,     0,    85,     0,     0,     0,     0,   167,     0,     0,
       0,     0,    47,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,     0,     0,   168,   169,   170,    79,    71,     0,     0,
       0,     0,    72,     0,    73,     0,     0,     0,    74,    75,
      76,    77,   103,     0,   104,     0,     0,     0,     0,   240,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   173,   174,    79,     0,   175,     0,     0,   176,   177,
       0,     0,     0,     0,     0,     0,   178,   179,   180,   181,
       0,     0,     0,    80,     0,     0,     0,    81,   182,     0,
       0,   183,   242,     0,     0,     0,     0,   161,   162,   163,
       0,   164,    82,   165,   166,    83,    84,     0,     0,     0,
       0,     0,   167,     0,     0,     0,     0,    85,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,   168,   169,
     170,   319,    71,     0,     0,     0,     0,    72,     0,    73,
       0,     0,     0,    74,    75,    76,    77,     0,     0,    78,
       0,     0,     0,     0,     0,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,    79,     0,
     175,   296,     0,   176,   177,     0,     0,     0,     0,     0,
       0,   178,   179,   180,   181,     0,     0,     0,    80,     0,
       0,     0,    81,   182,     0,     0,   183,   320,     0,   161,
     162,   163,     0,   164,     0,   165,   166,    82,     0,     0,
      83,    84,     0,     0,   167,     0,     0,     0,     0,     0,
       0,     0,    85,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
     168,   169,   170,    79,     0,     0,     0,    71,     0,     0,
       0,     0,    72,     0,    73,     0,     0,     0,    74,    75,
      76,    77,     0,     0,    78,     0,     0,   171,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
       0,     0,   175,    79,     0,   176,   177,     0,     0,     0,
       0,     0,     0,   178,   179,   180,   181,     0,     0,     0,
       0,     0,     0,    80,     0,   182,     0,    81,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,     0,     0,     0,    72,     0,    73,
       0,     0,     0,    74,    75,    76,    77,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,     0,   261,     0,     0,     0,     0,    80,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,     0,     0,     0,     0,     0,   284,   285,     0,     0,
     286,   287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   395,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     0,   261,     0,     0,
       0,     0,     0,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,     0,     0,     0,     0,     0,
     284,   285,     0,     0,   286,   287,     0,     0,     0,     0,
       0,     0,     0,   310,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,     0,   261,     0,     0,
       0,     0,     0,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,     0,     0,     0,     0,     0,
     284,   285,     0,     0,   286,   287,  -229,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,     0,     0,     0,     0,
       0,   284,   285,     0,     0,   286,   287,  -229,  -229,  -229,
    -229,  -229,  -229,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,     0,     0,     0,     0,
       0,   284,   285,     0,     0,   286,   287
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-462)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-229)))

static const yytype_int16 yycheck[] =
{
       4,     8,   142,     7,     8,   183,   135,    26,    27,   470,
     150,    30,   298,     8,   110,    22,   302,   157,    22,   431,
       5,    16,    17,    18,    72,   408,   409,    66,    76,    77,
      34,    69,    12,    81,    82,    83,    84,   148,   149,   135,
      24,    36,    26,    13,   155,   156,    69,    67,   144,   145,
      24,   294,    26,    33,    36,    69,   299,    39,    40,    67,
     303,    43,    44,    45,    64,    24,    66,    26,   246,    93,
      69,     8,    69,    69,     1,    69,     3,    66,    73,    74,
      75,    66,    66,   131,   545,    22,    33,     0,    87,   128,
      72,   129,    66,    88,    76,    77,    24,   121,    26,    81,
      82,    83,    84,    85,   200,    67,   129,    66,   103,   104,
     130,   115,   160,    37,   210,   129,   212,    41,    42,    66,
     532,   407,   130,   515,   507,   368,   538,   519,   110,    69,
     241,    37,   102,   133,   114,   132,   132,    26,   132,    28,
       0,     1,   128,    67,     4,   140,   141,   151,   132,   131,
     562,    66,    92,   135,    66,   441,    66,   131,   206,   288,
     121,   290,   144,   145,    26,   557,    28,   128,   551,    69,
     131,   498,   167,    33,    34,   502,    36,    37,   160,     0,
       1,    41,    42,     4,    37,    66,   121,   514,    41,    42,
     110,    83,   288,   128,   290,   121,   116,   117,   309,   121,
     120,   121,   128,   121,   103,   104,   128,    67,   132,    93,
     128,   128,    33,    34,    67,    36,    37,   131,   200,   128,
      41,    42,    66,    67,   206,   128,   553,   132,   210,   556,
     212,   109,   110,    17,    18,   283,    74,    75,   116,   117,
     526,   419,   120,   121,   116,   117,    67,   121,   120,   121,
     245,   133,    66,    87,    66,    83,   304,   128,   306,   307,
     129,   131,   129,   131,    69,   129,    69,    69,   364,    66,
     129,   129,   129,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   131,
     294,   295,   132,   100,    69,    87,   129,    30,   128,   294,
     132,   283,    66,   298,   129,   287,   288,   302,   290,    66,
     450,    44,   360,    66,   131,   131,   298,    66,   129,   129,
     302,    66,   304,    66,   306,   307,    87,   128,   128,   128,
      62,    59,    66,    66,   132,   129,   132,   448,   449,   132,
     128,   103,   104,   105,   106,   107,   108,   109,   110,   132,
     131,   370,   129,    86,   116,   117,   129,    69,   120,   121,
     130,    48,   131,   129,   368,    61,    60,   132,   131,    69,
     130,   375,   105,   131,    22,   108,   132,   488,   360,   383,
     117,   417,   364,   513,   536,   428,   141,   375,   383,   364,
     368,   393,    39,   165,   397,   388,    -1,    -1,    -1,   190,
      -1,    -1,   397,    -1,   408,   409,    -1,   426,    -1,    -1,
      -1,    -1,   407,   408,   409,   410,   411,   412,    -1,   438,
      -1,   416,   417,    -1,    -1,   407,    -1,   431,    -1,    -1,
     425,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
      -1,    -1,    -1,   460,   473,    -1,    -1,   476,    -1,   441,
     508,   509,    -1,    -1,    -1,   460,   461,   462,    -1,    -1,
      -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   508,
      -1,   510,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   507,   523,   524,    -1,    -1,    -1,    -1,
     505,   515,   507,    -1,    -1,   519,    -1,   512,    -1,    -1,
      -1,    -1,    -1,   518,    -1,    -1,   508,   509,   532,   134,
      -1,   526,    -1,    -1,   538,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,   526,    -1,    -1,   551,   543,    -1,
      -1,    -1,    -1,   557,    -1,    -1,   551,    48,   562,    -1,
     165,    -1,    -1,   168,    -1,    -1,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    83,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,   120,
     121,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
     245,   246,    -1,    -1,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    -1,    -1,
       1,   286,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    -1,    26,    -1,    28,    29,   314,
      -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    90,
      91,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
     101,   102,    -1,   388,   105,    -1,   391,   108,   109,    -1,
      44,    -1,   397,    -1,     1,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   411,   128,    -1,    -1,
     131,   132,    66,    -1,   419,    22,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    -1,   467,    -1,    -1,   470,    -1,    -1,    -1,    -1,
     475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,   512,    -1,   116,
     117,   118,   119,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,   131,   132,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,   543,    26,
     545,    28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,   560,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    90,    91,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
      44,   108,   109,    -1,    -1,     1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    66,    -1,   131,   132,    22,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    37,    86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    90,    91,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,    44,   108,   109,    -1,    -1,     1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    66,    -1,   131,   132,    22,    23,    24,
      -1,    26,    -1,    28,    29,    -1,    -1,    32,    33,    34,
      -1,    -1,    37,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    90,    91,    -1,    -1,   116,
     117,    -1,    -1,   120,   121,    -1,   101,   102,    -1,    -1,
     105,    -1,    -1,   108,   109,    -1,    -1,     1,    -1,    -1,
      -1,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,   131,   132,    22,    23,
      24,    -1,    26,    -1,    28,    29,    -1,    -1,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,    90,    91,    -1,   116,
     117,    -1,    -1,   120,   121,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,   131,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,
     108,   109,    22,    23,    24,    -1,    26,    -1,    28,    29,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,   130,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    -1,    47,    -1,    -1,    -1,    -1,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,    66,    -1,   105,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    90,   128,    -1,
      -1,   131,   132,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    26,   105,    28,    29,   108,   109,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    -1,    -1,    -1,   120,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    66,    -1,
     105,    69,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    90,   128,    -1,    -1,   131,   132,    -1,    22,
      23,    24,    -1,    26,    -1,    28,    29,   105,    -1,    -1,
     108,   109,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      63,    64,    65,    66,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    90,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    66,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,   128,    -1,    90,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    83,    -1,    -1,    -1,    -1,    86,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,    -1,   120,   121,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,   120,   121,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,   120,   121
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,   135,    66,     0,    67,   130,   137,   139,
     139,     1,     4,    33,    34,    36,    37,    41,    42,   136,
     138,   139,   141,   146,   147,   149,   152,   153,   154,   155,
     207,    24,    26,    66,   131,   148,    66,   144,   145,    66,
      37,   128,   136,   212,   212,   212,   155,   130,   139,   140,
     140,   140,   140,   148,   139,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    30,    35,    37,    41,    42,    43,    44,    47,    66,
      86,    90,   105,   108,   109,   120,   136,   143,   190,   191,
     205,   218,   219,   220,   221,   222,   223,   224,   225,   227,
     228,   229,    69,    45,    47,   192,   201,   205,   206,   190,
      66,   190,   190,   190,    66,   148,   150,   151,   219,   136,
     217,   217,   217,   219,   219,   131,   219,   219,   219,   219,
      64,   133,   190,   226,    83,    93,   121,   136,   195,   145,
     195,   195,   128,    44,   105,   108,   211,   228,   128,   128,
     128,   148,   139,   132,   150,   128,   128,   128,   132,   219,
     133,    22,    23,    24,    26,    28,    29,    37,    63,    64,
      65,    90,    91,   101,   102,   105,   108,   109,   116,   117,
     118,   119,   128,   131,   190,   209,   230,   232,   233,   236,
     237,   238,   239,   240,   241,   243,   196,   197,   228,    66,
      87,   136,   198,   198,    66,   136,   142,   213,   214,   215,
      44,   228,    44,   228,   129,   213,   214,   213,   214,   139,
     213,   213,   214,   219,   239,   240,   136,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
      89,   100,   132,   231,   239,   128,   131,    26,   236,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    83,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   116,   117,   120,   121,    69,    92,
      83,   196,   199,   200,   131,   131,    69,   219,   129,    69,
     228,   228,   129,    69,   129,   129,   129,   129,   129,   128,
     129,   210,   239,   213,    69,   132,   136,   231,   242,    66,
     132,   231,   234,   235,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   219,   239,
     128,   190,   196,   196,    69,   136,   139,   202,   203,   204,
     215,    37,    41,    42,   139,   193,   194,    66,   143,     5,
     215,   143,   219,   131,   219,   219,   213,   132,   100,   239,
     129,    87,   132,    69,   132,   133,   219,   128,   199,   202,
     132,   140,    66,    66,    66,   132,   194,   129,   131,   131,
       1,    32,    37,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    59,   136,   139,   146,   147,   159,   160,   161,
     162,   163,   164,   175,   177,   178,   179,   182,   208,   216,
     239,   129,   210,   239,    66,   235,   129,   242,   128,   128,
     128,   143,   216,   216,   136,   156,   136,   158,   239,    66,
     165,   166,   167,    66,   136,   157,   157,   176,   231,    87,
     183,    62,   136,   189,   140,    59,   189,   162,   140,   132,
     143,   132,   129,   213,   213,   214,   132,   132,   128,   136,
     145,   146,   170,   172,   173,   136,   136,   136,   174,   180,
     239,    87,   180,    66,   140,   239,   140,   131,   129,   129,
     129,   213,   130,    69,   239,    48,   181,   181,   181,   131,
     136,   216,   140,   219,   219,   140,   129,   136,   171,   239,
     173,   181,   163,    61,   136,   184,   186,   187,   163,   132,
     140,   140,   143,   130,   132,   185,   184,    60,   136,   188,
     132,   131,   136,   168,   169,   239,   180,   131,   216,   181,
      69,   181,   163,   132,   239,   132
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

  case 62:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 63:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 67:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 68:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 69:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (8)]), &(yyvsp[(5) - (8)]), &(yyvsp[(7) - (8)]), &(yyvsp[(8) - (8)]), parm, &yyloc); 
			}
    break;

  case 70:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 71:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (5)]), &(yyvsp[(4) - (5)]), &(yyvsp[(3) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); 
			}
    break;

  case 72:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 73:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(3) - (4)]), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); 
			}
    break;

  case 77:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 84:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 88:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 89:

    { 
			yoParserStmtSwitch(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc);
		}
    break;

  case 90:

    { yoParserStmtCase(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 91:

    { yoParserStmtDefault(&(yyval), parm, &yyloc); }
    break;

  case 92:

    { yoParserStmtFallThrough(&(yyval), parm, &yyloc); }
    break;

  case 94:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 95:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 96:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 97:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 98:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 100:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 103:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 105:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 108:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 109:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 110:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 112:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 113:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 114:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 115:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 116:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 118:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 121:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 123:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 124:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 128:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 129:

    { yoParserStruct(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 133:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), &(yyvsp[(9) - (9)]), NULL, true, YO_CALLING_C, parm, &yyloc); }
    break;

  case 149:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (7)]), &(yyvsp[(5) - (7)]), &(yyvsp[(7) - (7)]), NULL, false, YO_CALLING_C, parm, &yyloc); }
    break;

  case 150:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 151:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 152:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 153:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 154:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 155:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 156:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 157:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 159:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 160:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 163:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 168:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 169:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 173:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 174:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 175:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 176:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 179:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 180:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 181:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 182:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 183:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 184:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 185:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 186:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 189:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 191:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 192:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 193:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 194:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 195:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 196:

    { yoParserTypeStdName(&(yyval), T_INT, parm, &yyloc); }
    break;

  case 197:

    { yoParserTypeStdName(&(yyval), T_INTPTR, parm, &yyloc); }
    break;

  case 198:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 199:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 200:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 201:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 202:

    { yoParserTypeStdName(&(yyval), T_UINT, parm, &yyloc); }
    break;

  case 203:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 204:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 205:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 206:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 207:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 208:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 209:

    { yoParserTypeStdName(&(yyval), T_UNKNOWN_YET, parm, &yyloc); }
    break;

  case 210:

    { yoParserTypeStdName(&(yyval), T_MUTABLE, parm, &yyloc); }
    break;

  case 211:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 212:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 213:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 219:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 220:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 221:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 222:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 223:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 224:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 226:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 227:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 228:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 230:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 231:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 238:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_EQ, parm, &yyloc); }
    break;

  case 239:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_NE, parm, &yyloc); }
    break;

  case 240:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LE, parm, &yyloc); }
    break;

  case 241:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GE, parm, &yyloc); }
    break;

  case 242:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LT, parm, &yyloc); }
    break;

  case 243:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GT, parm, &yyloc); }
    break;

  case 244:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 245:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 246:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 247:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 248:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 249:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW, parm, &yyloc); }
    break;

  case 250:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 251:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LSH, parm, &yyloc); }
    break;

  case 252:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_RSH, parm, &yyloc); }
    break;

  case 253:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 254:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 255:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 256:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 257:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 258:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 259:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 260:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 262:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 265:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 266:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 267:

    { yoParserPostUnaryOp(&(yyval), &(yyvsp[(1) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 268:

    { yoParserPostUnaryOp(&(yyval), &(yyvsp[(1) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 269:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 270:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 271:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 272:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 273:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 274:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 275:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 276:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 277:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 278:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); yoParserUnaryOp(&(yyval), &(yyval), T_INDIRECT, parm, &yyloc); }
    break;

  case 279:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 280:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); yoParserUnaryOp(&(yyval), &(yyval), T_ADDR, parm, &yyloc); }
    break;

  case 281:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 282:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS_ASSIGN, parm, &yyloc); }
    break;

  case 283:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS_ASSIGN, parm, &yyloc); }
    break;

  case 284:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL_ASSIGN, parm, &yyloc); }
    break;

  case 285:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV_ASSIGN, parm, &yyloc); }
    break;

  case 286:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD_ASSIGN, parm, &yyloc); }
    break;

  case 287:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR_ASSIGN, parm, &yyloc); }
    break;

  case 288:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND_ASSIGN, parm, &yyloc); }
    break;

  case 289:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR_ASSIGN, parm, &yyloc); }
    break;

  case 290:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_RSH_ASSIGN, parm, &yyloc); }
    break;

  case 291:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LSH_ASSIGN, parm, &yyloc); }
    break;

  case 292:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW_ASSIGN, parm, &yyloc); }
    break;

  case 293:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT_ASSIGN, parm, &yyloc); }
    break;

  case 296:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 297:

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




