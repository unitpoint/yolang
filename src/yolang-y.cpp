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
void yoParserDeclVar(YYSTYPE * r, bool isMutable, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
void yoParserDeclArg(YYSTYPE * r, bool isMutable, YYSTYPE * a, YYSTYPE * b, void*, YYLTYPE * loc);
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
void yoParserClass(YYSTYPE * r, YYSTYPE * gen, YYSTYPE * e, YYSTYPE * a, void * parm, YYLTYPE * loc);
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
     T_PTR = 370,
     T_ARR = 371,
     T_DOTNAME = 372,
     NotParen = 373
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
#define YYLAST   1861

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  103
/* YYNRULES -- Number of rules.  */
#define YYNRULES  268
/* YYNRULES -- Number of states.  */
#define YYNSTATES  522

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   373

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     123,   124,     2,     2,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,   125,
       2,     2,     2,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   116,     2,   128,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   126,     2,   127,     2,     2,     2,     2,
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
     119,   120,   121,   122
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    10,    11,    13,    16,    18,    20,
      22,    24,    26,    28,    31,    33,    37,    39,    41,    43,
      45,    47,    51,    55,    61,    64,    68,    70,    72,    75,
      79,    85,    88,    92,    94,    97,   100,   103,   106,   108,
     110,   112,   114,   116,   118,   120,   122,   125,   128,   131,
     133,   135,   140,   144,   147,   150,   152,   154,   158,   161,
     163,   165,   167,   170,   171,   180,   181,   187,   188,   193,
     195,   197,   199,   203,   205,   207,   209,   211,   213,   215,
     219,   225,   227,   231,   232,   239,   240,   245,   247,   250,
     252,   254,   259,   261,   267,   269,   271,   275,   279,   286,
     288,   291,   298,   306,   314,   321,   323,   327,   329,   331,
     335,   337,   341,   344,   346,   348,   350,   354,   361,   364,
     366,   368,   371,   373,   375,   377,   379,   381,   383,   385,
     387,   389,   391,   393,   395,   397,   399,   409,   417,   428,
     439,   449,   459,   469,   476,   481,   483,   485,   488,   492,
     495,   499,   504,   506,   508,   510,   512,   516,   520,   524,
     526,   528,   530,   536,   543,   550,   556,   558,   560,   563,
     566,   569,   572,   575,   578,   582,   584,   586,   591,   593,
     596,   598,   600,   602,   604,   606,   608,   610,   612,   614,
     616,   618,   620,   622,   624,   626,   628,   630,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   652,   655,   659,
     663,   668,   673,   675,   679,   683,   686,   688,   691,   694,
     696,   698,   700,   702,   704,   706,   710,   714,   718,   722,
     726,   730,   734,   738,   742,   746,   750,   754,   758,   762,
     766,   770,   774,   778,   782,   786,   791,   793,   797,   799,
     801,   805,   811,   814,   817,   820,   823,   826,   829,   832,
     835,   838,   841,   844,   847,   851,   853,   855,   860
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     130,     0,    -1,     3,    62,   132,   133,    -1,     1,    -1,
      -1,   134,    -1,   125,   134,    -1,   136,    -1,   131,    -1,
      63,    -1,   134,    -1,   125,    -1,   149,    -1,   136,   149,
      -1,    62,    -1,   137,    65,    62,    -1,   207,    -1,   131,
      -1,    44,    -1,   131,    -1,   141,    -1,   140,    65,   141,
      -1,   139,    62,   138,    -1,   139,    62,   138,    79,   227,
      -1,    33,   140,    -1,    34,    62,   194,    -1,    26,    -1,
      24,    -1,     4,   144,    -1,     4,    62,   144,    -1,     4,
     126,   134,   147,   127,    -1,   144,   134,    -1,    62,   144,
     134,    -1,   146,    -1,   147,   146,    -1,   145,   135,    -1,
     143,   135,    -1,   195,   135,    -1,     1,    -1,   148,    -1,
     134,    -1,   131,    -1,    62,    -1,   131,    -1,   227,    -1,
     131,    -1,    32,   152,    -1,    52,   151,    -1,    53,   151,
      -1,   227,    -1,   153,    -1,   153,    55,   227,   131,    -1,
     142,   177,   135,    -1,   196,   135,    -1,   143,   135,    -1,
     170,    -1,   158,    -1,   154,   177,   135,    -1,     1,   150,
      -1,   155,    -1,   134,    -1,   156,    -1,   157,   156,    -1,
      -1,    49,   159,   164,   125,   165,   125,   162,   169,    -1,
      -1,    50,   160,   131,   227,   169,    -1,    -1,    51,   161,
     131,   169,    -1,   163,    -1,   131,    -1,   227,    -1,   163,
      65,   227,    -1,   142,    -1,   166,    -1,   131,    -1,   227,
      -1,   131,    -1,   167,    -1,   166,    65,   167,    -1,   131,
      62,   138,    79,   227,    -1,   227,    -1,    48,   157,   127,
      -1,    -1,    55,   171,   168,   169,   175,   176,    -1,    -1,
      57,   173,   168,   169,    -1,   172,    -1,   174,   172,    -1,
     174,    -1,   131,    -1,    56,   126,   157,   127,    -1,   131,
      -1,    58,    62,   126,   157,   127,    -1,   131,    -1,    62,
      -1,   178,   117,    62,    -1,    47,   126,   127,    -1,    47,
     183,   186,   126,   181,   127,    -1,   182,    -1,   181,   182,
      -1,    37,    62,   123,   201,   124,   135,    -1,    37,    62,
     123,   201,   124,   207,   135,    -1,    41,    62,   123,   201,
     124,   207,   135,    -1,    42,    62,   123,   202,   124,   135,
      -1,   134,    -1,    89,   185,    88,    -1,   131,    -1,   216,
      -1,   216,    79,   184,    -1,   184,    -1,   185,    65,   184,
      -1,    83,   188,    -1,   131,    -1,   184,    -1,   187,    -1,
     188,    65,   187,    -1,    46,   183,   186,   126,   192,   127,
      -1,   203,   135,    -1,   134,    -1,   190,    -1,   191,   190,
      -1,   191,    -1,   131,    -1,   216,    -1,   208,    -1,   209,
      -1,   210,    -1,   212,    -1,   211,    -1,   213,    -1,   215,
      -1,   206,    -1,   193,    -1,   180,    -1,   189,    -1,    36,
      37,   178,   123,   202,    65,     5,   124,   138,    -1,    36,
      37,   178,   123,   201,   124,   138,    -1,    37,   200,   178,
     123,   201,   124,   138,   126,   204,   127,    -1,    41,   200,
     178,   123,   201,   124,   207,   126,   204,   127,    -1,    42,
     200,   178,   123,   202,   124,   126,   204,   127,    -1,    37,
      62,   123,   201,   124,   138,   126,   204,   127,    -1,    37,
     131,   123,   201,   124,   138,   126,   204,   127,    -1,   126,
      96,   201,    96,   198,   127,    -1,   126,    85,   198,   127,
      -1,   227,    -1,   216,    -1,   104,   216,    -1,   104,    44,
     216,    -1,   101,   216,    -1,   101,    44,   216,    -1,   123,
      62,   199,   124,    -1,   131,    -1,   202,    -1,   131,    -1,
     203,    -1,   202,    65,   203,    -1,   131,   137,   207,    -1,
      44,   137,   207,    -1,   157,    -1,   131,    -1,   131,    -1,
      37,   205,   123,   201,   124,    -1,    37,   205,   123,   201,
     124,   207,    -1,    41,   205,   123,   201,   124,   207,    -1,
      42,   205,   123,   202,   124,    -1,   193,    -1,   179,    -1,
      43,   207,    -1,    44,   207,    -1,    35,   207,    -1,   101,
     207,    -1,   104,   207,    -1,   105,   207,    -1,   116,   128,
     207,    -1,    60,    -1,   178,    -1,   116,   214,   128,   207,
      -1,   217,    -1,   178,   183,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      20,    -1,    18,    -1,    19,    -1,    21,    -1,    30,    -1,
      82,    -1,    22,    -1,    23,    -1,    29,    -1,    60,    -1,
      61,    -1,    24,    -1,    26,    -1,   227,    -1,   219,    65,
     227,    -1,   126,   127,    -1,   126,   219,   127,    -1,   178,
     126,   127,    -1,   178,   126,   219,   127,    -1,   178,   126,
     222,   127,    -1,   223,    -1,   222,    65,   223,    -1,    62,
      83,   227,    -1,    28,   228,    -1,   224,    -1,   225,   224,
      -1,   225,    26,    -1,   228,    -1,   226,    -1,   218,    -1,
     178,    -1,   220,    -1,   221,    -1,   227,    93,   227,    -1,
     227,    92,   227,    -1,   227,    91,   227,    -1,   227,    90,
     227,    -1,   227,    89,   227,    -1,   227,    88,   227,    -1,
     227,    98,   227,    -1,   227,    97,   227,    -1,   227,   104,
     227,    -1,   227,   103,   227,    -1,   227,   102,   227,    -1,
     227,   105,   227,    -1,   227,    94,   227,    -1,   227,    96,
     227,    -1,   227,    85,   227,    -1,   227,   101,   227,    -1,
     227,    86,   227,    -1,   227,    95,   227,    -1,   227,    87,
     227,    -1,   227,   117,   178,    -1,   227,   116,   227,   128,
      -1,   229,    -1,   123,   227,   124,    -1,   231,    -1,   197,
      -1,   227,   106,   207,    -1,   227,   117,   123,   207,   124,
      -1,   227,   113,    -1,   227,   112,    -1,   113,   227,    -1,
     112,   227,    -1,    98,   227,    -1,    97,   227,    -1,   115,
     227,    -1,   114,   227,    -1,    87,   227,    -1,    59,   227,
      -1,   104,   227,    -1,   101,   227,    -1,   227,    79,   227,
      -1,   219,    -1,   131,    -1,   178,   123,   230,   124,    -1,
     227,   117,   178,   123,   230,   124,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   237,   237,   238,   241,   250,   251,   254,   255,   258,
     261,   262,   265,   266,   269,   270,   273,   274,   277,   278,
     281,   282,   285,   286,   293,   296,   299,   300,   303,   304,
     305,   308,   309,   312,   313,   316,   317,   318,   319,   322,
     323,   326,   334,   335,   338,   339,   342,   343,   344,   345,
     348,   349,   352,   353,   354,   355,   356,   357,   358,   361,
     362,   365,   366,   382,   382,   385,   385,   388,   388,   393,
     394,   397,   398,   401,   402,   403,   406,   407,   410,   411,
     414,   421,   424,   427,   427,   432,   432,   436,   437,   440,
     441,   444,   445,   448,   449,   452,   453,   456,   459,   462,
     463,   466,   467,   468,   469,   470,   473,   474,   477,   478,
     481,   482,   485,   486,   489,   492,   493,   496,   499,   500,
     517,   518,   521,   522,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   536,   537,   538,   541,   543,   545,   547,
     549,   553,   561,   563,   565,   569,   573,   574,   575,   576,
     577,   580,   581,   584,   585,   588,   589,   592,   593,   596,
     597,   606,   609,   610,   611,   612,   615,   616,   619,   622,
     625,   628,   631,   632,   639,   643,   644,   647,   651,   653,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   676,   677,
     678,   679,   680,   681,   682,   685,   686,   689,   690,   693,
     694,   695,   698,   699,   702,   705,   708,   709,   712,   715,
     716,   729,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   752,   753,   754,   755,   756,   757,   758,
     759,   760,   761,   762,   763,   764,   765,   766,   767,   768,
     769,   770,   771,   772,   788,   791,   792,   795,   796
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
  "'['", "\". (T_DOT)\"", "\"[] (T_INDEX)\"", "T_PTR", "T_ARR",
  "T_DOTNAME", "NotParen", "'('", "')'", "';'", "'{'", "'}'", "']'",
  "$accept", "file", "empty", "end_newline", "module_stmt_list", "newline",
  "end_stmt", "top_stmt_list", "name_list", "type_or_empty",
  "mut_or_empty", "decl_var_list", "decl_var_elem", "decl_var",
  "decl_type", "const_str", "import", "import_body_elem", "import_body",
  "top_stmt_no_emptyline", "top_stmt", "stmt_error_end", "name_or_empty",
  "expr_or_empty", "stmt_post_if_elem", "stmt_post_if",
  "stmt_no_emptyline", "stmt", "stmt_list", "for_stmt", "$@1", "$@2",
  "$@3", "for_next", "for_next_list", "for_init", "for_condition",
  "var_assign_list", "var_assign_elem", "if_header", "brace_stmt",
  "if_stmt", "$@4", "elseif", "$@5", "elseif_list", "elseif_list_or_empty",
  "else", "catch", "dotname", "type_contract_empty", "type_contract",
  "contract_body", "contract_decl_func", "template", "template_arg",
  "template_arg_list", "extends", "extends_elem", "extends_list",
  "type_class", "class_body_stmt", "class_body_stmt_list", "class_body",
  "type_base", "type_ext", "top_decl_func", "decl_func", "expr_decl_func",
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
     315,   316,   317,   318,   319,    44,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,    63,    58,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,    91,   368,   369,   370,
     371,   372,   373,    40,    41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   129,   130,   130,   131,   132,   132,   133,   133,   134,
     135,   135,   136,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   143,   144,   144,   145,   145,
     145,   146,   146,   147,   147,   148,   148,   148,   148,   149,
     149,   150,   151,   151,   152,   152,   153,   153,   153,   153,
     154,   154,   155,   155,   155,   155,   155,   155,   155,   156,
     156,   157,   157,   159,   158,   160,   158,   161,   158,   162,
     162,   163,   163,   164,   164,   164,   165,   165,   166,   166,
     167,   168,   169,   171,   170,   173,   172,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   180,   181,
     181,   182,   182,   182,   182,   182,   183,   183,   184,   184,
     185,   185,   186,   186,   187,   188,   188,   189,   190,   190,
     191,   191,   192,   192,   193,   193,   193,   193,   193,   193,
     193,   193,   193,   194,   194,   194,   195,   195,   195,   195,
     195,   196,   197,   197,   197,   198,   199,   199,   199,   199,
     199,   200,   200,   201,   201,   202,   202,   203,   203,   204,
     204,   205,   206,   206,   206,   206,   207,   207,   208,   209,
     210,   211,   212,   212,   213,   214,   214,   215,   216,   216,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   218,   218,
     218,   218,   218,   218,   218,   219,   219,   220,   220,   221,
     221,   221,   222,   222,   223,   224,   225,   225,   226,   227,
     227,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   229,   230,   230,   231,   231
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     5,     2,     3,     1,     1,     2,     3,
       5,     2,     3,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     4,     3,     2,     2,     1,     1,     3,     2,     1,
       1,     1,     2,     0,     8,     0,     5,     0,     4,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       5,     1,     3,     0,     6,     0,     4,     1,     2,     1,
       1,     4,     1,     5,     1,     1,     3,     3,     6,     1,
       2,     6,     7,     7,     6,     1,     3,     1,     1,     3,
       1,     3,     2,     1,     1,     1,     3,     6,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     9,     7,    10,    10,
       9,     9,     9,     6,     4,     1,     1,     2,     3,     2,
       3,     4,     1,     1,     1,     1,     3,     3,     3,     1,
       1,     1,     5,     6,     6,     5,     1,     1,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       4,     4,     1,     3,     3,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     1,     3,     1,     1,
       3,     5,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     9,     0,     0,     5,
       6,    38,     0,     0,     0,     4,     4,     4,     8,     2,
      40,     0,     0,     0,    39,    12,     0,    27,    26,     0,
       0,    28,     0,     0,     0,   152,     0,     0,     0,    13,
      11,    10,    36,    35,    37,    29,     0,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   193,
     194,   192,   195,   196,     0,     4,     4,     4,     0,     0,
       4,     4,    95,   197,     0,     0,     0,     0,     4,   134,
     135,   133,    25,   132,   125,   126,   127,   129,   128,   130,
     131,   124,   178,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,   167,   166,   170,   161,     0,     0,     0,
     168,   169,     0,   107,     4,     4,   171,   172,   173,   175,
       0,   176,     0,     0,   179,     4,     0,     0,     0,   146,
       4,     4,     4,     0,    31,    30,    34,     0,     4,     4,
       4,   110,     0,   108,     0,   113,     0,     0,   174,     0,
      96,     0,   154,     0,   153,   155,     0,   149,     0,   147,
     151,     0,   153,     0,     0,     0,    32,    97,     0,     0,
       0,     0,   106,     0,   114,   115,   112,     4,     0,   177,
      14,     0,     0,     4,     4,   150,   148,     4,     4,     0,
       0,   162,     0,   165,   111,   109,     0,   123,   119,   120,
       4,     0,     0,     0,     0,     0,   105,     0,    99,     0,
     158,   157,    17,   137,    16,     0,   156,     0,     0,     0,
     163,   164,   116,   121,   117,   118,     0,     0,     0,    98,
     100,    15,     4,     0,     0,     4,   198,   199,   203,   204,
       0,   200,     4,     4,     4,    63,    65,    67,     4,     4,
      83,     0,   201,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   160,    60,     4,     0,    50,
       4,    59,    61,     0,    56,    55,   222,     0,   249,     0,
     221,   223,   224,   216,     0,   220,    49,   219,   246,   248,
       4,     4,     4,   136,     0,     0,    41,    58,     4,     0,
     219,    45,    46,    44,    18,    19,     0,    24,    20,     0,
       0,     4,     4,     4,    42,    43,    47,    48,     0,   261,
     260,   257,   256,   263,   262,   255,   254,   259,   258,     0,
       0,     4,   207,     0,   205,     0,    94,     0,    54,     0,
       0,    62,     4,     0,    53,   140,   218,   217,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
     252,     0,     0,     0,     0,     0,   138,   139,     4,     4,
       4,     4,    75,    73,     0,    74,    78,     0,     0,     0,
      81,   247,     0,   145,     0,     0,   208,     0,    52,     4,
      57,   266,   265,     0,    95,   209,     0,     0,   212,   264,
     239,   241,   243,   230,   229,   228,   227,   226,   225,   237,
     242,   238,   232,   231,   240,   235,   234,   233,   236,   250,
       0,     0,   244,     0,     0,     0,    22,    21,     0,     0,
       4,     4,     4,     0,     0,    68,     4,   144,     0,   206,
       0,    51,   267,     0,   210,     0,   211,   245,     0,     4,
     101,     0,     0,   104,     0,     4,     4,     0,    77,     0,
      76,     0,    79,    66,     0,    85,    90,    87,    89,     4,
       0,     0,   214,     0,   213,   251,     0,   102,   103,    23,
       0,     0,     0,     4,    82,     0,    88,     0,    92,    84,
     143,    93,   268,     0,     0,    80,    70,     0,    69,    71,
       0,     0,     0,     0,    64,     0,    86,     0,   141,   142,
      72,    91
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   152,     8,    19,    41,    42,    21,   182,   213,
     306,   307,   308,   267,   268,    99,    23,   100,   101,    24,
      25,   297,   316,   302,   269,   270,   271,   272,   273,   274,
     311,   312,   313,   507,   508,   384,   469,   385,   386,   389,
     445,   275,   318,   477,   495,   478,   479,   499,   337,   276,
     103,    79,   207,   208,   114,   174,   142,   146,   175,   176,
      80,   199,   200,   201,   104,    82,    26,   277,   278,   392,
     128,    36,   153,   162,   155,   279,   107,    83,   214,    84,
      85,    86,    87,    88,    89,   122,    90,    91,    92,   280,
     402,   281,   282,   407,   408,   283,   284,   285,   286,   287,
     288,   403,   289
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -388
static const yytype_int16 yypact[] =
{
     163,  -388,    -1,    77,   -47,  -388,  -388,    19,   266,  -388,
    -388,  -388,    18,    55,    90,    11,    11,    11,  -388,  -388,
    -388,   317,   -42,   -42,  -388,  -388,   -42,  -388,  -388,   141,
      19,  -388,  1304,   109,   116,  -388,   109,   109,   109,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,    42,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,  -388,  1458,  -388,  -388,  -388,  1458,  1458,
      79,    79,  -388,  -388,  1458,  1458,  1458,   -13,   -36,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,
    -388,  -388,  -388,   -21,   142,     5,    52,    83,   141,    19,
    -388,    10,    56,  -388,  -388,  -388,  -388,    66,    74,    86,
    -388,  -388,  1058,  -388,   130,   130,  -388,  -388,  -388,  -388,
    1458,    99,    89,   158,  -388,   187,   846,   952,   110,  -388,
     187,   187,   187,    19,  -388,  -388,  -388,   112,   187,   187,
     187,  -388,    59,   154,  1058,  -388,   114,   121,  -388,  1458,
    -388,   188,   188,   127,   189,  -388,  1058,  -388,  1058,  -388,
    -388,   128,   190,   129,   188,   -32,  -388,  -388,   134,   137,
     -15,  1058,  -388,  1058,  -388,  -388,   194,    13,    48,  -388,
    -388,  1381,  1381,  1458,    47,  -388,  -388,  1458,   187,  1458,
     136,  1635,  1458,  -388,  -388,  -388,  1058,   188,  -388,  -388,
      -9,   144,   -42,   202,   206,   210,  -388,     4,  -388,   212,
    -388,  -388,  -388,  -388,  -388,   153,  -388,   152,   157,   650,
    -388,  -388,  -388,  -388,  -388,  -388,   156,   161,   164,  -388,
    -388,  -388,  1458,   650,   650,  -388,  -388,  -388,  -388,  -388,
    1601,  -388,  1601,   236,   224,  -388,  -388,  -388,   226,   226,
    -388,  1601,  -388,  -388,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1484,  -388,  -388,   231,   -42,   235,
     231,  -388,  -388,   787,  -388,  -388,    15,   -42,  -388,   165,
    -388,  -388,  -388,  -388,   179,  -388,  1683,  -388,  -388,  -388,
     187,   187,   187,  -388,   166,   167,  -388,  -388,  -388,  1683,
     182,  -388,  -388,  1683,  -388,  -388,   233,   232,  -388,   173,
     178,   276,  -388,  -388,  -388,  -388,  -388,  -388,  1601,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,  1643,
    1601,   187,  -388,   -27,  1683,   248,  -388,   -42,  -388,  1601,
     -42,  -388,  1601,  1505,  -388,  -388,  -388,  -388,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,
    1601,  1601,  1601,  1601,  1601,  1601,  1601,  1601,  1458,  -388,
    -388,  1601,   -11,   191,   203,    -3,  -388,  -388,  1458,   236,
     187,   187,   249,  -388,   201,   265,  -388,  1601,   283,   283,
    1683,  -388,   205,  1683,   218,  1601,  -388,   208,  -388,  1683,
    -388,  -388,   268,   216,   253,  -388,   -22,   -17,  -388,  1683,
    1190,  1266,  1714,  1744,  1744,  1744,  1744,  1744,  1744,    82,
      82,    82,    82,    82,   207,   207,   207,   207,   132,  -388,
     482,  1458,   219,  1227,  1458,   -42,   267,  -388,   221,   237,
    1458,  1601,  -388,  1084,   315,  -388,   293,  -388,  1601,  1683,
     315,  -388,  -388,  1601,  -388,   294,  -388,  -388,   238,  1601,
    -388,   -42,   -42,  -388,  1601,  1458,  1458,   278,  -388,   230,
    1683,   249,  -388,  -388,   893,  -388,  -388,  -388,   293,   304,
     242,   999,  1683,   253,  -388,  -388,   239,  -388,  -388,  1683,
     247,   255,  1601,  1601,  -388,  1601,  -388,   256,  -388,  -388,
    -388,  -388,  -388,   650,   650,  1683,  -388,   283,   314,  1683,
     283,   315,   257,   259,  -388,  1601,  -388,  1105,  -388,  -388,
    1683,  -388
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -388,  -388,    -7,  -388,  -388,    -4,   -12,  -388,   240,  -167,
    -388,  -388,    14,    72,    67,    -5,  -388,   288,  -388,  -388,
     369,  -388,   145,  -388,  -388,  -388,  -388,  -260,  -371,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,  -388,   -45,  -100,
    -387,  -388,  -388,   -82,  -388,  -388,  -388,  -388,   133,   368,
    -388,  -388,  -388,   192,    35,   -87,  -388,   292,   213,  -388,
    -388,   198,  -388,  -388,   376,  -388,  -388,  -388,  -388,   -38,
    -388,    81,   -99,  -113,   -58,  -228,   135,  -388,   -46,  -388,
    -388,  -388,  -388,  -388,  -388,  -388,  -388,   -57,  -388,  -388,
    -249,  -388,  -388,  -388,   -44,   131,  -388,  -388,   274,   174,
    -388,   -41,  -388
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -216
static const yytype_int16 yytable[] =
{
       9,    18,   446,    10,    20,   294,   295,    31,    35,    35,
      35,    43,   154,   341,    44,   333,     6,    20,   105,   165,
     217,     6,   110,   111,    45,   141,    46,   170,   116,   117,
     118,   161,   163,   188,    27,   151,    28,   129,   395,   168,
     169,   203,    27,   395,    28,   204,   205,   119,   455,    72,
     188,    72,   215,   112,     6,   143,   473,   151,   106,   106,
     106,     4,   188,   113,   113,   293,    27,     6,    28,   157,
     159,   113,    98,   474,   148,    22,     6,     5,     7,   481,
      29,   123,     6,    40,   194,   203,   195,   143,    22,   204,
     205,   151,   190,   133,   406,   134,   123,    37,    38,   185,
     396,   186,   125,   179,    98,   454,   115,   145,   145,   193,
     456,     6,   431,   124,   143,   120,   143,    32,  -122,   202,
     514,   435,   123,   516,   171,   164,   216,    33,   130,   166,
     216,   229,   123,   164,    34,   210,   211,   135,   342,   143,
     517,   343,   202,   218,    30,   220,   221,   172,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     1,    27,     2,    28,   112,   123,
     197,    72,    63,   198,   206,   131,   212,   164,    94,   375,
     212,   164,   137,   363,   364,   365,   366,   367,   368,   138,
     225,   373,   374,   164,   369,   370,   198,   139,   371,   372,
     123,   108,   109,   206,    72,   346,   132,   240,  -215,   140,
    -215,   436,   265,   144,   341,   266,   123,   149,   369,   370,
     150,   341,   371,   372,    73,   212,   265,   265,   296,   266,
     266,   151,   394,   173,   160,   301,   305,   310,   368,   167,
     177,   315,   315,   126,   369,   370,   127,   178,   371,   372,
     180,   183,   187,   189,   184,   188,   338,   341,   191,   196,
     336,   192,   219,   336,   226,   344,    -4,    11,   227,   266,
      12,   224,   228,   467,   231,   512,   513,   232,   233,   290,
     304,   438,   439,   234,   291,   164,   309,   292,   314,   335,
     339,   310,   345,   376,   377,   378,   380,   379,   490,   491,
      13,   381,    14,    15,   382,   387,   388,    16,    17,   243,
     397,   440,   367,   368,   448,   433,   235,    -7,    11,   369,
     370,    12,   429,   371,   372,   398,   441,   434,   400,     6,
     442,   444,   447,   395,   450,   401,   453,   236,   237,   238,
     452,   239,   459,   240,   241,   465,   464,   242,   243,    13,
     475,    13,   244,    14,    15,   493,   483,   492,    16,    17,
     497,   466,   485,   502,   245,   246,   247,   248,   249,   500,
     250,   212,   305,   503,   251,   252,   253,    72,     6,   515,
       6,   504,   511,   383,   518,   458,   519,   461,   462,   136,
      39,   181,   451,   437,   317,   510,   496,   472,   223,   230,
      78,    93,   254,   340,    95,    96,    97,   147,    81,   222,
     480,   484,   255,   256,   300,   347,   257,     0,   486,   258,
       0,   460,     0,   463,     0,     0,     0,   259,   260,   261,
     262,     0,    78,   212,   468,   471,    78,    78,   263,   476,
     266,   264,    78,    78,    78,   121,   266,     0,     0,   487,
     488,     0,   401,     0,     0,     0,     0,     0,   212,   212,
       0,     0,    78,     0,     0,     0,     0,     0,     0,     0,
     266,     0,   498,     0,     0,     0,     0,   266,     0,     0,
      78,     0,     0,     0,     0,     0,   506,     0,    78,     0,
       0,     0,     0,     0,    78,    78,   265,   265,     0,   266,
     266,     0,     0,     0,     0,     0,     0,   266,     0,     0,
       0,     0,    78,   266,   299,     0,   303,    78,     0,     0,
       0,     0,     0,     0,    78,   319,    78,     0,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   334,    78,
       0,    78,     0,     0,     0,     0,     0,     0,     0,    78,
      78,    78,     0,     0,     0,    78,     0,    78,     0,    78,
      78,   348,     0,     0,    78,     0,     0,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,     0,     0,   363,   364,   365,   366,   367,   368,     0,
       0,     0,   390,     0,   369,   370,     0,     0,   371,   372,
      78,     0,     0,     0,   393,     0,     0,     0,     0,     0,
     457,     0,     0,   399,     0,     0,   334,   334,     0,     0,
       0,     0,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,     0,     0,     0,   430,     0,     0,     0,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   443,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,   236,   237,   238,     0,   239,     0,   240,   241,
       0,     0,   242,   243,    13,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
     246,   247,   248,   249,     0,   250,     0,     0,     0,   251,
     252,   253,    72,     6,     0,   470,     0,     0,     0,     0,
       0,     0,   393,     0,     0,     0,     0,   482,     0,     0,
       0,     0,     0,   334,     0,     0,    78,   254,   489,     0,
     432,     0,     0,     0,     0,     0,    78,   255,   256,     0,
       0,   257,     0,     0,   258,     0,     0,     0,     0,     0,
       0,     0,   259,   260,   261,   262,   505,   509,     0,   390,
       0,     0,     0,   263,     0,     0,   264,    -4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   520,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,    78,    78,     0,     0,     0,     0,     0,    78,   236,
     237,   238,     0,   239,     0,   240,   241,     0,     0,   242,
     243,    13,     0,     0,   244,     0,     0,     0,     0,     0,
       0,     0,     0,    78,    78,     0,   245,   246,   247,   248,
     249,     0,   250,     0,     0,     0,   251,   252,   253,    72,
       6,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,   254,     0,    63,     0,     0,     0,
       0,     0,     0,     0,   255,   256,     0,     0,   257,     0,
     156,   258,     0,     0,   235,     0,     0,     0,     0,   259,
     260,   261,   262,     0,     0,     0,     0,     0,    72,     0,
     263,     0,     0,   264,  -159,   236,   237,   238,     0,   239,
       0,   240,   241,     0,     0,   242,   243,    13,    73,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,   246,   247,   248,   249,     0,   250,     0,
       0,     0,   251,   252,   253,    72,     6,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
     254,     0,    63,     0,     0,     0,     0,     0,     0,     0,
     255,   256,     0,     0,   257,     0,   158,   258,     0,     0,
     235,     0,     0,     0,     0,   259,   260,   261,   262,     0,
       0,     0,     0,     0,    72,     0,   263,     0,     0,   264,
     494,   236,   237,   238,     0,   239,     0,   240,   241,     0,
       0,   242,   243,    13,    73,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   245,   246,
     247,   248,   249,     0,   250,     0,     0,     0,   251,   252,
     253,    72,     6,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,   254,     0,    63,     0,
       0,     0,     0,     0,     0,     0,   255,   256,     0,     0,
     257,     0,     0,   258,     0,     0,   235,     0,     0,     0,
       0,   259,   260,   261,   262,     0,     0,     0,     0,     0,
      72,     0,   263,     0,     0,   264,   501,   236,   237,   238,
       0,   239,   444,   240,   241,     0,     0,   242,   243,    13,
      73,     0,   244,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   245,   246,   247,   248,   249,     0,
     250,     0,     0,   348,   251,   252,   253,    72,     6,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,     0,   254,     0,     0,     0,   369,   370,     0,     0,
     371,   372,   255,   256,     0,     0,   257,     0,     0,   258,
       0,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,   264,   521,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,    66,    67,
      68,    69,     0,     0,   102,     0,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,    72,
       6,   363,   364,   365,   366,   367,   368,     0,     0,     0,
       0,     0,   369,   370,     0,     0,   371,   372,     0,    73,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    74,     0,
       0,    75,    76,     0,    63,     0,     0,     0,     0,    64,
       0,    65,     0,    77,     0,    66,    67,    68,    69,     0,
      70,    71,    40,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,     0,    72,   363,   364,   365,
     366,   367,   368,     0,     0,     0,     0,     0,   369,   370,
       0,     0,   371,   372,     0,     0,    73,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,     0,    74,     0,     0,    75,    76,
       0,    63,     0,     0,     0,     0,    64,     0,    65,     0,
      77,     0,    66,    67,    68,    69,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,   209,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,    74,     0,     0,    75,    76,     0,    63,     0,
       0,     0,     0,    64,     0,    65,     0,    77,     0,    66,
      67,    68,    69,     0,     0,   102,   236,   237,   238,     0,
     239,     0,   240,   241,     0,     0,     0,     0,     0,     0,
      72,   298,     0,     0,     0,     0,     0,   236,   237,   238,
       0,   239,     0,   240,   241,     0,     0,     0,     0,     0,
      73,     0,   298,   251,   252,   253,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
       0,     0,    75,    76,   251,   252,   253,   404,     0,   330,
       0,   254,     0,     0,    77,     0,     0,     0,     0,     0,
     331,   255,   256,     0,     0,   257,     0,     0,   258,     0,
       0,     0,   254,     0,     0,     0,   259,   260,   261,   262,
       0,     0,   255,   256,     0,     0,   257,   263,     0,   258,
     264,   332,     0,     0,     0,     0,     0,   259,   260,   261,
     262,     0,     0,   236,   237,   238,     0,   239,   263,   240,
     241,   264,   405,     0,     0,     0,     0,     0,   298,     0,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,     0,     0,
     251,   252,   253,    72,     0,    63,     0,     0,     0,     0,
      64,     0,    65,     0,     0,     0,    66,    67,    68,    69,
       0,     0,   102,     0,     0,     0,     0,     0,   254,     0,
       0,     0,     0,     0,     0,     0,     0,    72,   255,   256,
       0,     0,   257,     0,     0,   258,     0,     0,     0,     0,
       0,     0,     0,   259,   260,   261,   262,    73,     0,     0,
       0,     0,   348,     0,   263,     0,     0,   264,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,   363,   364,   365,   366,   367,   368,
       0,     0,     0,     0,     0,   369,   370,     0,     0,   371,
     372,     0,   348,     0,     0,     0,     0,   391,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,     0,     0,   363,   364,   365,   366,   367,   368,
       0,     0,     0,     0,     0,   369,   370,     0,     0,   371,
     372,  -216,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,     0,     0,     0,     0,     0,   369,   370,     0,     0,
     371,   372,  -216,  -216,  -216,  -216,  -216,  -216,   358,   359,
     360,   361,   362,     0,     0,   363,   364,   365,   366,   367,
     368,     0,     0,     0,     0,     0,   369,   370,     0,     0,
     371,   372
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-388)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-216)))

static const yytype_int16 yycheck[] =
{
       4,     8,   389,     7,     8,   233,   234,    12,    15,    16,
      17,    23,   125,   273,    26,   264,    63,    21,    64,   132,
     187,    63,    68,    69,    29,   112,    30,   140,    74,    75,
      76,   130,   131,    65,    24,    44,    26,    94,    65,   138,
     139,    37,    24,    65,    26,    41,    42,    60,    65,    62,
      65,    62,     5,    89,    63,   112,   443,    44,    65,    66,
      67,    62,    65,    70,    71,   232,    24,    63,    26,   126,
     127,    78,    62,   444,   120,     8,    63,     0,   125,   450,
      62,   117,    63,   125,   171,    37,   173,   144,    21,    41,
      42,    44,   124,    98,   343,    99,   117,    16,    17,   156,
     127,   158,   123,   149,    62,   127,    71,   114,   115,   124,
     127,    63,   123,    78,   171,   128,   173,    62,   127,   177,
     507,   124,   117,   510,    65,   132,   184,    37,   123,   133,
     188,   127,   117,   140,   123,   181,   182,   127,   123,   196,
     511,   126,   200,   189,   126,   191,   192,    88,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     1,    24,     3,    26,    89,   117,
     177,    62,    30,   177,   178,   123,   183,   184,    62,   292,
     187,   188,   126,   101,   102,   103,   104,   105,   106,   123,
     202,   290,   291,   200,   112,   113,   200,   123,   116,   117,
     117,    66,    67,   207,    62,    26,   123,    28,    26,   123,
      28,   378,   219,    83,   474,   219,   117,   128,   112,   113,
      62,   481,   116,   117,    82,   232,   233,   234,   235,   233,
     234,    44,   331,    79,   124,   242,   243,   244,   106,   127,
     126,   248,   249,   101,   112,   113,   104,   126,   116,   117,
      62,   124,   124,   124,    65,    65,   268,   517,   124,    65,
     267,   124,   126,   270,    62,   277,     0,     1,    62,   273,
       4,   127,    62,   440,    62,   503,   504,   124,   126,   123,
      44,   380,   381,   126,   123,   292,    62,   123,    62,    58,
      55,   298,   127,   127,   127,    62,   123,    65,   465,   466,
      34,   123,    36,    37,   311,   312,   313,    41,    42,    33,
      62,    62,   105,   106,    96,   124,     1,     0,     1,   112,
     113,     4,   368,   116,   117,   337,   125,   124,   340,    63,
      65,    48,   127,    65,   126,   342,    83,    22,    23,    24,
     124,    26,   123,    28,    29,   124,    79,    32,    33,    34,
      57,    34,    37,    36,    37,   125,    62,    79,    41,    42,
      56,   124,   124,   124,    49,    50,    51,    52,    53,   127,
      55,   378,   379,   126,    59,    60,    61,    62,    63,    65,
      63,   126,   126,   311,   127,   431,   127,   433,   434,   101,
      21,   151,   399,   379,   249,   495,   478,   442,   200,   207,
      32,    33,    87,   270,    36,    37,    38,   115,    32,   196,
     448,   455,    97,    98,   240,   284,   101,    -1,   459,   104,
      -1,   433,    -1,   435,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    64,   440,   441,   442,    68,    69,   123,   446,
     444,   126,    74,    75,    76,    77,   450,    -1,    -1,   461,
     462,    -1,   459,    -1,    -1,    -1,    -1,    -1,   465,   466,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,   479,    -1,    -1,    -1,    -1,   481,    -1,    -1,
     112,    -1,    -1,    -1,    -1,    -1,   493,    -1,   120,    -1,
      -1,    -1,    -1,    -1,   126,   127,   503,   504,    -1,   503,
     504,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,
      -1,    -1,   144,   517,   240,    -1,   242,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   251,   158,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   171,
      -1,   173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
     182,   183,    -1,    -1,    -1,   187,    -1,   189,    -1,   191,
     192,    79,    -1,    -1,   196,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,   101,   102,   103,   104,   105,   106,    -1,
      -1,    -1,   318,    -1,   112,   113,    -1,    -1,   116,   117,
     232,    -1,    -1,    -1,   330,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,   339,    -1,    -1,   342,   343,    -1,    -1,
      -1,    -1,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     366,   367,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   387,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   395,
      -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,    29,
      -1,    -1,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    55,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    -1,   441,    -1,    -1,    -1,    -1,
      -1,    -1,   448,    -1,    -1,    -1,    -1,   453,    -1,    -1,
      -1,    -1,    -1,   459,    -1,    -1,   368,    87,   464,    -1,
     372,    -1,    -1,    -1,    -1,    -1,   378,    97,    98,    -1,
      -1,   101,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   114,   115,   492,   493,    -1,   495,
      -1,    -1,    -1,   123,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,   515,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   431,
      -1,   433,   434,    -1,    -1,    -1,    -1,    -1,   440,    22,
      23,    24,    -1,    26,    -1,    28,    29,    -1,    -1,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   465,   466,    -1,    49,    50,    51,    52,
      53,    -1,    55,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,   101,    -1,
      44,   104,    -1,    -1,     1,    -1,    -1,    -1,    -1,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    62,    -1,
     123,    -1,    -1,   126,   127,    22,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    82,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    -1,    -1,   101,    -1,    44,   104,    -1,    -1,
       1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    62,    -1,   123,    -1,    -1,   126,
     127,    22,    23,    24,    -1,    26,    -1,    28,    29,    -1,
      -1,    32,    33,    34,    82,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    55,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,
     101,    -1,    -1,   104,    -1,    -1,     1,    -1,    -1,    -1,
      -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      62,    -1,   123,    -1,    -1,   126,   127,    22,    23,    24,
      -1,    26,    48,    28,    29,    -1,    -1,    32,    33,    34,
      82,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      55,    -1,    -1,    79,    59,    60,    61,    62,    63,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,   104,   105,
     106,    -1,    87,    -1,    -1,    -1,   112,   113,    -1,    -1,
     116,   117,    97,    98,    -1,    -1,   101,    -1,    -1,   104,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,   126,   127,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    62,
      63,   101,   102,   103,   104,   105,   106,    -1,    -1,    -1,
      -1,    -1,   112,   113,    -1,    -1,   116,   117,    -1,    82,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,   101,    -1,
      -1,   104,   105,    -1,    30,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,   116,    -1,    41,    42,    43,    44,    -1,
      46,    47,   125,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,    62,   101,   102,   103,
     104,   105,   106,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,   116,   117,    -1,    -1,    82,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,   101,    -1,    -1,   104,   105,
      -1,    30,    -1,    -1,    -1,    -1,    35,    -1,    37,    -1,
     116,    -1,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,   101,    -1,    -1,   104,   105,    -1,    30,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,   116,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    22,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    37,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      -1,    26,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    37,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,   104,   105,    59,    60,    61,    62,    -1,    85,
      -1,    87,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      96,    97,    98,    -1,    -1,   101,    -1,    -1,   104,    -1,
      -1,    -1,    87,    -1,    -1,    -1,   112,   113,   114,   115,
      -1,    -1,    97,    98,    -1,    -1,   101,   123,    -1,   104,
     126,   127,    -1,    -1,    -1,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,    22,    23,    24,    -1,    26,   123,    28,
      29,   126,   127,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      59,    60,    61,    62,    -1,    30,    -1,    -1,    -1,    -1,
      35,    -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    97,    98,
      -1,    -1,   101,    -1,    -1,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,   114,   115,    82,    -1,    -1,
      -1,    -1,    79,    -1,   123,    -1,    -1,   126,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,   116,
     117,    -1,    79,    -1,    -1,    -1,    -1,   124,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,   101,   102,   103,   104,   105,   106,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,   116,
     117,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
     116,   117,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    -1,    -1,   101,   102,   103,   104,   105,
     106,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,
     116,   117
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,   130,    62,     0,    63,   125,   132,   134,
     134,     1,     4,    34,    36,    37,    41,    42,   131,   133,
     134,   136,   143,   145,   148,   149,   195,    24,    26,    62,
     126,   144,    62,    37,   123,   131,   200,   200,   200,   149,
     125,   134,   135,   135,   135,   144,   134,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    30,    35,    37,    41,    42,    43,    44,
      46,    47,    62,    82,   101,   104,   105,   116,   178,   180,
     189,   193,   194,   206,   208,   209,   210,   211,   212,   213,
     215,   216,   217,   178,    62,   178,   178,   178,    62,   144,
     146,   147,    47,   179,   193,   207,   131,   205,   205,   205,
     207,   207,    89,   131,   183,   183,   207,   207,   207,    60,
     128,   178,   214,   117,   183,   123,   101,   104,   199,   216,
     123,   123,   123,   144,   134,   127,   146,   126,   123,   123,
     123,   184,   185,   216,    83,   131,   186,   186,   207,   128,
      62,    44,   131,   201,   202,   203,    44,   216,    44,   216,
     124,   201,   202,   201,   131,   202,   134,   127,   201,   201,
     202,    65,    88,    79,   184,   187,   188,   126,   126,   207,
      62,   137,   137,   124,    65,   216,   216,   124,    65,   124,
     124,   124,   124,   124,   184,   184,    65,   131,   134,   190,
     191,   192,   203,    37,    41,    42,   134,   181,   182,    65,
     207,   207,   131,   138,   207,     5,   203,   138,   207,   126,
     207,   207,   187,   190,   127,   135,    62,    62,    62,   127,
     182,    62,   124,   126,   126,     1,    22,    23,    24,    26,
      28,    29,    32,    33,    37,    49,    50,    51,    52,    53,
      55,    59,    60,    61,    87,    97,    98,   101,   104,   112,
     113,   114,   115,   123,   126,   131,   134,   142,   143,   153,
     154,   155,   156,   157,   158,   170,   178,   196,   197,   204,
     218,   220,   221,   224,   225,   226,   227,   228,   229,   231,
     123,   123,   123,   138,   204,   204,   131,   150,    37,   227,
     228,   131,   152,   227,    44,   131,   139,   140,   141,    62,
     131,   159,   160,   161,    62,   131,   151,   151,   171,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
      85,    96,   127,   219,   227,    58,   131,   177,   135,    55,
     177,   156,   123,   126,   135,   127,    26,   224,    79,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   101,   102,   103,   104,   105,   106,   112,
     113,   116,   117,   201,   201,   202,   127,   127,    62,    65,
     123,   123,   131,   142,   164,   166,   167,   131,   131,   168,
     227,   124,   198,   227,   201,    65,   127,    62,   135,   227,
     135,   131,   219,   230,    62,   127,   219,   222,   223,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   207,
     227,   123,   178,   124,   124,   124,   138,   141,   201,   201,
      62,   125,    65,   227,    48,   169,   169,   127,    96,   227,
     126,   131,   124,    83,   127,    65,   127,   128,   207,   123,
     135,   207,   207,   135,    79,   124,   124,   138,   131,   165,
     227,   131,   167,   169,   157,    57,   131,   172,   174,   175,
     198,   157,   227,    62,   223,   124,   230,   135,   135,   227,
     138,   138,    79,   125,   127,   173,   172,    56,   131,   176,
     127,   127,   124,   126,   126,   227,   131,   162,   163,   227,
     168,   126,   204,   204,   169,    65,   169,   157,   127,   127,
     227,   127
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

  case 18:

    { (yyval).op = T_MUTABLE; }
    break;

  case 21:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 22:

    { yoParserDeclVar(&(yyval), (yyvsp[(1) - (3)]).op == T_MUTABLE, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 23:

    {
				yoParserDeclVar(&(yyvsp[(1) - (5)]), (yyvsp[(1) - (5)]).op == T_MUTABLE, &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(5) - (5)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), parm, &yyloc);
			}
    break;

  case 24:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 25:

    { yoParserDeclType(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 28:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 29:

    { yoParserImport(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 30:

    { (yyval) = (yyvsp[(4) - (5)]); }
    break;

  case 31:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(1) - (2)]), parm, &yyloc); }
    break;

  case 32:

    { yoParserImport(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 34:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 38:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 46:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 47:

    { yoParserStmtBreak(&(yyval), &(yyvsp[(2) - (2)]), T_BREAK, parm, &yyloc); }
    break;

  case 48:

    { yoParserStmtBreak(&(yyval), &(yyvsp[(2) - (2)]), T_CONTINUE, parm, &yyloc); }
    break;

  case 51:

    { yoParserStmtIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(1) - (4)]), &(yyvsp[(4) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 52:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 57:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 58:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 62:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 63:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 64:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (8)]), &(yyvsp[(5) - (8)]), &(yyvsp[(7) - (8)]), &(yyvsp[(8) - (8)]), parm, &yyloc); 
			}
    break;

  case 65:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 66:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (5)]), &(yyvsp[(4) - (5)]), &(yyvsp[(3) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); 
			}
    break;

  case 67:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 68:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(3) - (4)]), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); 
			}
    break;

  case 72:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 79:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 80:

    {
				yoParserDeclVar(&(yyvsp[(1) - (5)]), (yyvsp[(1) - (5)]).op == T_MUTABLE, &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(5) - (5)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), parm, &yyloc);
			}
    break;

  case 82:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 83:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 84:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 85:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 86:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 88:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 91:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 93:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 96:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 97:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 98:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 100:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 101:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 102:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 103:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 104:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 106:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 109:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 111:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 112:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 116:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 117:

    { yoParserClass(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 121:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 136:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), &(yyvsp[(9) - (9)]), NULL, true, YO_CALLING_C, parm, &yyloc); }
    break;

  case 137:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (7)]), &(yyvsp[(5) - (7)]), &(yyvsp[(7) - (7)]), NULL, false, YO_CALLING_C, parm, &yyloc); }
    break;

  case 138:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 139:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 141:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), false, &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 142:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 143:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 144:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 145:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 147:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 151:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 156:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 157:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 158:

    { yoParserDeclArg(&(yyval), true, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
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

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 199:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 200:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 206:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 207:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 208:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 209:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 210:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 211:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 213:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 214:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 215:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 217:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 218:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 225:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_EQ, parm, &yyloc); }
    break;

  case 226:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_NE, parm, &yyloc); }
    break;

  case 227:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LE, parm, &yyloc); }
    break;

  case 228:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GE, parm, &yyloc); }
    break;

  case 229:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LT, parm, &yyloc); }
    break;

  case 230:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GT, parm, &yyloc); }
    break;

  case 231:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 232:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 233:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 234:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 235:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 236:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW, parm, &yyloc); }
    break;

  case 237:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 238:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 239:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 240:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 241:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 242:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 243:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 244:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 245:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 247:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 250:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 251:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 252:

    { yoParserPostUnaryOp(&(yyval), &(yyvsp[(1) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 253:

    { yoParserPostUnaryOp(&(yyval), &(yyvsp[(1) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 254:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 255:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 256:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 257:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 258:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 259:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 260:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 261:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 262:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 263:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 264:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 267:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 268:

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




