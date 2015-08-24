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
     T_UINT8 = 265,
     T_UINT16 = 266,
     T_UINT32 = 267,
     T_UINT64 = 268,
     T_UINTPTR = 269,
     T_FLOAT32 = 270,
     T_FLOAT64 = 271,
     T_STRING = 272,
     T_BOOL = 273,
     T_TRUE = 274,
     T_FALSE = 275,
     T_SSTRING = 276,
     T_SSTRING_NOT_FINISHED = 277,
     T_QSTRING = 278,
     T_QSTRING_NOT_FINISHED = 279,
     T_QSTRING_INJECT_EXRP = 280,
     T_NULL = 281,
     T_VOID = 282,
     T_RETURN = 283,
     T_LET = 284,
     T_TYPE = 285,
     T_CHAN = 286,
     T_FUNC = 287,
     T_EXPR_FUNC = 288,
     T_EXPR_LAMBDA = 289,
     T_GET = 290,
     T_SET = 291,
     T_CONST = 292,
     T_MUTABLE = 293,
     T_STRUCT = 294,
     T_CLASS = 295,
     T_CONTRACT = 296,
     T_BRACE = 297,
     T_IF = 298,
     T_ELSE = 299,
     T_ELSEIF = 300,
     T_CATCH = 301,
     T_LNUMBER = 302,
     T_DNUMBER = 303,
     T_NAME = 304,
     T_NEWLINE = 305,
     T_FIX = 306,
     T_POW_ASSIGN = 307,
     T_RSH_ASSIGN = 308,
     T_LSH_ASSIGN = 309,
     T_XOR_ASSIGN = 310,
     T_OR_ASSIGN = 311,
     T_AND_ASSIGN = 312,
     T_MOD_ASSIGN = 313,
     T_CONCAT_ASSIGN = 314,
     T_DIV_ASSIGN = 315,
     T_MUL_ASSIGN = 316,
     T_MINUS_ASSIGN = 317,
     T_PLUS_ASSIGN = 318,
     T_DECL_ASSIGN = 319,
     T_ASSIGN = 320,
     T_XORXOR = 321,
     T_OROR = 322,
     T_ANDAND = 323,
     T_CHAN_ACCESS = 324,
     T_GT = 325,
     T_LT = 326,
     T_GE = 327,
     T_LE = 328,
     T_NE = 329,
     T_EQ = 330,
     T_CONCAT = 331,
     T_XOR = 332,
     T_OR = 333,
     T_MINUS = 334,
     T_PLUS = 335,
     T_RSH = 336,
     T_LSH = 337,
     T_AND = 338,
     T_MOD = 339,
     T_DIV = 340,
     T_MUL = 341,
     T_POW = 342,
     T_AT = 343,
     T_UNARY = 344,
     T_DEC = 345,
     T_INC = 346,
     T_TILDE = 347,
     T_NOT = 348,
     T_DOT = 349,
     T_AS = 350,
     T_INDIRECT = 351,
     T_ADDR = 352,
     T_INDEX = 353,
     T_PTR = 354,
     T_ARR = 355,
     T_DOTNAME = 356,
     NotParen = 357
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1638

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  113
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  219
/* YYNRULES -- Number of states.  */
#define YYNSTATES  432

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     107,   108,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,   109,
       2,     2,     2,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    97,     2,   112,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   110,     2,   111,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    98,
      99,   100,   101,   102,   103,   104,   105,   106
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    11,    14,    16,    18,    20,
      22,    24,    26,    29,    31,    35,    39,    45,    49,    51,
      53,    56,    60,    66,    69,    73,    75,    78,    81,    84,
      87,    89,    91,    93,    95,    97,    99,   102,   105,   110,
     113,   115,   119,   123,   126,   128,   130,   132,   135,   137,
     141,   142,   149,   150,   155,   156,   162,   164,   167,   169,
     174,   176,   182,   184,   188,   192,   194,   198,   202,   209,
     211,   214,   221,   229,   237,   244,   246,   250,   252,   254,
     258,   260,   264,   267,   269,   271,   273,   277,   284,   287,
     289,   291,   294,   296,   298,   300,   302,   304,   306,   308,
     310,   312,   314,   316,   318,   320,   322,   332,   343,   354,
     364,   373,   383,   390,   395,   397,   399,   401,   404,   408,
     411,   415,   420,   422,   424,   426,   428,   432,   435,   437,
     439,   441,   447,   454,   461,   467,   469,   471,   474,   477,
     480,   483,   486,   489,   493,   495,   497,   502,   504,   507,
     509,   511,   513,   515,   517,   519,   521,   523,   525,   527,
     529,   531,   533,   535,   537,   539,   541,   543,   545,   547,
     549,   551,   555,   558,   562,   566,   571,   576,   578,   582,
     586,   589,   591,   594,   597,   599,   601,   603,   605,   607,
     609,   611,   615,   619,   623,   627,   631,   635,   639,   643,
     647,   651,   655,   659,   663,   667,   672,   676,   678,   680,
     684,   690,   693,   696,   699,   702,   705,   708,   711,   716
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     114,     0,    -1,     3,    49,   116,   117,    -1,    -1,   118,
      -1,   109,   118,    -1,   120,    -1,   115,    -1,    50,    -1,
     118,    -1,   109,    -1,   129,    -1,   120,   129,    -1,    49,
      -1,   121,    52,    49,    -1,    29,    49,   173,    -1,    29,
      49,   173,    66,   193,    -1,    30,    49,   161,    -1,    23,
      -1,    21,    -1,     4,   124,    -1,     4,    49,   124,    -1,
       4,   110,   118,   127,   111,    -1,   124,   118,    -1,    49,
     124,   118,    -1,   126,    -1,   127,   126,    -1,   125,   119,
      -1,   123,   119,    -1,   162,   119,    -1,     1,    -1,   128,
      -1,   118,    -1,   118,    -1,   109,    -1,   111,    -1,   122,
     119,    -1,   123,   119,    -1,    28,   193,   143,   119,    -1,
      28,   119,    -1,   136,    -1,   144,   143,   119,    -1,   196,
     143,   119,    -1,     1,   130,    -1,   131,    -1,   118,    -1,
     132,    -1,   133,   132,    -1,   193,    -1,    42,   133,   111,
      -1,    -1,    43,   137,   134,   135,   141,   142,    -1,    -1,
      45,   139,   134,   135,    -1,    -1,    44,    43,   140,   134,
     135,    -1,   138,    -1,   141,   138,    -1,   115,    -1,    44,
     110,   133,   111,    -1,   115,    -1,    46,    49,   110,   133,
     111,    -1,   115,    -1,   121,    66,   185,    -1,   121,    65,
     185,    -1,    49,    -1,   145,    98,    49,    -1,    41,   110,
     111,    -1,    41,   150,   153,   110,   148,   111,    -1,   149,
      -1,   148,   149,    -1,    32,    49,   107,   167,   108,   119,
      -1,    32,    49,   107,   167,   108,   173,   119,    -1,    35,
      49,   107,   167,   108,   173,   119,    -1,    36,    49,   107,
     168,   108,   119,    -1,   118,    -1,    74,   152,    73,    -1,
     115,    -1,   182,    -1,   182,    66,   151,    -1,   151,    -1,
     152,    52,   151,    -1,    68,   155,    -1,   115,    -1,   151,
      -1,   154,    -1,   155,    52,   154,    -1,    40,   150,   153,
     110,   159,   111,    -1,   168,   119,    -1,   118,    -1,   157,
      -1,   158,   157,    -1,   158,    -1,   115,    -1,   182,    -1,
     174,    -1,   175,    -1,   176,    -1,   178,    -1,   177,    -1,
     179,    -1,   181,    -1,   172,    -1,   160,    -1,   147,    -1,
     156,    -1,    32,   166,   145,   107,   167,   108,   110,   170,
     111,    -1,    32,   166,   145,   107,   167,   108,   173,   110,
     170,   111,    -1,    35,   166,   145,   107,   167,   108,   173,
     110,   170,   111,    -1,    36,   166,   145,   107,   168,   108,
     110,   170,   111,    -1,    32,   115,   107,   167,   108,   110,
     170,   111,    -1,    32,   115,   107,   167,   108,   173,   110,
     170,   111,    -1,   110,    81,   121,    81,   164,   111,    -1,
     110,    70,   164,   111,    -1,   193,    -1,   170,    -1,   182,
      -1,    89,   182,    -1,    89,    38,   182,    -1,    86,   182,
      -1,    86,    38,   182,    -1,   107,    49,   165,   108,    -1,
     115,    -1,   168,    -1,   115,    -1,   169,    -1,   168,    52,
     169,    -1,   121,   173,    -1,   133,    -1,   115,    -1,   115,
      -1,    32,   171,   107,   167,   108,    -1,    32,   171,   107,
     167,   108,   173,    -1,    35,   171,   107,   167,   108,   173,
      -1,    36,   171,   107,   168,   108,    -1,   160,    -1,   146,
      -1,    37,   173,    -1,    38,   173,    -1,    31,   173,    -1,
      86,   173,    -1,    89,   173,    -1,    90,   173,    -1,    97,
     112,   173,    -1,    47,    -1,   145,    -1,    97,   180,   112,
     173,    -1,   183,    -1,   145,   150,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    17,    -1,    15,    -1,    16,
      -1,    18,    -1,    27,    -1,    19,    -1,    20,    -1,    26,
      -1,    47,    -1,    48,    -1,    21,    -1,    23,    -1,   193,
      -1,   185,    52,   193,    -1,   110,   111,    -1,   110,   185,
     111,    -1,   145,   110,   111,    -1,   145,   110,   185,   111,
      -1,   145,   110,   188,   111,    -1,   189,    -1,   188,    52,
     189,    -1,   145,    66,   193,    -1,    25,   194,    -1,   190,
      -1,   191,   190,    -1,   191,    23,    -1,   194,    -1,   192,
      -1,   184,    -1,   186,    -1,   187,    -1,   145,    -1,   195,
      -1,   193,    83,   193,    -1,   193,    82,   193,    -1,   193,
      89,   193,    -1,   193,    88,   193,    -1,   193,    87,   193,
      -1,   193,    79,   193,    -1,   193,    98,   145,    -1,   193,
      81,   193,    -1,   193,    70,   193,    -1,   193,    86,   193,
      -1,   193,    71,   193,    -1,   193,    80,   193,    -1,   193,
      69,   193,    -1,   193,    72,   193,    -1,   193,    97,   193,
     112,    -1,   107,   193,   108,    -1,   196,    -1,   163,    -1,
     193,    99,   173,    -1,   193,    98,   107,   173,   108,    -1,
      83,   193,    -1,    82,   193,    -1,    96,   193,    -1,    95,
     193,    -1,    89,   193,    -1,    86,   193,    -1,    72,   193,
      -1,   145,   107,   185,   108,    -1,   193,    98,   145,   107,
     185,   108,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   222,   222,   225,   234,   235,   238,   239,   242,   245,
     246,   249,   250,   253,   254,   257,   258,   265,   268,   269,
     272,   273,   274,   277,   278,   281,   282,   285,   286,   287,
     288,   291,   292,   295,   296,   297,   300,   301,   302,   303,
     304,   305,   306,   307,   310,   311,   314,   315,   326,   329,
     332,   332,   337,   337,   338,   338,   341,   342,   343,   346,
     347,   350,   351,   354,   355,   358,   359,   362,   365,   368,
     369,   372,   373,   374,   375,   376,   379,   380,   383,   384,
     387,   388,   391,   392,   395,   398,   399,   402,   405,   406,
     409,   410,   413,   414,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   428,   429,   430,   433,   435,   437,   439,
     443,   445,   447,   449,   453,   454,   457,   458,   459,   460,
     461,   464,   465,   468,   469,   472,   473,   476,   479,   480,
     489,   492,   493,   494,   495,   498,   499,   502,   505,   508,
     511,   514,   515,   522,   526,   527,   530,   534,   536,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   555,   556,   557,   558,   559,   560,   561,
     564,   565,   568,   569,   572,   573,   574,   577,   578,   581,
     584,   587,   588,   591,   594,   595,   598,   599,   600,   601,
     602,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,   620,   621,
     622,   625,   626,   627,   628,   629,   630,   631,   636,   637
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_MODULE", "T_IMPORT", "T_DOTDOTDOT",
  "T_INT8", "T_INT16", "T_INT32", "T_INT64", "T_UINT8", "T_UINT16",
  "T_UINT32", "T_UINT64", "T_UINTPTR", "T_FLOAT32", "T_FLOAT64",
  "T_STRING", "T_BOOL", "T_TRUE", "T_FALSE", "T_SSTRING",
  "T_SSTRING_NOT_FINISHED", "T_QSTRING", "T_QSTRING_NOT_FINISHED",
  "T_QSTRING_INJECT_EXRP", "T_NULL", "T_VOID", "T_RETURN", "T_LET",
  "T_TYPE", "T_CHAN", "T_FUNC", "T_EXPR_FUNC", "T_EXPR_LAMBDA", "T_GET",
  "T_SET", "T_CONST", "T_MUTABLE", "T_STRUCT", "T_CLASS", "T_CONTRACT",
  "T_BRACE", "T_IF", "T_ELSE", "T_ELSEIF", "T_CATCH", "T_LNUMBER",
  "T_DNUMBER", "T_NAME", "T_NEWLINE", "T_FIX", "','",
  "\"**= (T_POW_ASSIGN)\"", "\">>= (T_RSH_ASSIGN)\"",
  "\"<<= (T_LSH_ASSIGN)\"", "\"^= (T_XOR_ASSIGN)\"",
  "\"|= (T_OR_ASSIGN)\"", "\"&= (T_AND_ASSIGN)\"", "\"%= (T_MOD_ASSIGN)\"",
  "\"..= (T_CONCAT_ASSIGN)\"", "\"/= (T_DIV_ASSIGN)\"",
  "\"*= (T_MUL_ASSIGN)\"", "\"-= (T_MINUS_ASSIGN)\"",
  "\"+= (T_PLUS_ASSIGN)\"", "\":= (T_DECL_ASSIGN)\"", "\"= (T_ASSIGN)\"",
  "'?'", "':'", "\"^^ (T_XORXOR)\"", "\"|| (T_OROR)\"",
  "\"&& (T_ANDAND)\"", "\"<- (T_CHAN_ACCESS)\"", "\"> (T_GT)\"",
  "\"< (T_LT)\"", "\">= (T_GE)\"", "\"<= (T_LE)\"", "\"!= (T_NE)\"",
  "\"== (T_EQ)\"", "\".. (T_CONCAT)\"", "\"^ (T_XOR)\"", "\"| (T_OR)\"",
  "\"- (T_MINUS)\"", "\"+ (T_PLUS)\"", "\">> (T_RSH)\"", "\"<< (T_LSH)\"",
  "\"& (T_AND)\"", "\"% (T_MOD)\"", "\"/ (T_DIV)\"", "\"* (T_MUL)\"",
  "\"** (T_POW)\"", "\"@ (T_AT)\"", "T_UNARY", "\"-- (T_DEC)\"",
  "\"++ (T_INC)\"", "\"~ (T_TILDE)\"", "\"! (T_NOT)\"", "'['",
  "\". (T_DOT)\"", "\"as (T_AS)\"", "\"* (T_INDIRECT)\"", "\"& (T_ADDR)\"",
  "\"[] (T_INDEX)\"", "T_PTR", "T_ARR", "T_DOTNAME", "NotParen", "'('",
  "')'", "';'", "'{'", "'}'", "']'", "$accept", "file", "empty",
  "end_newline", "module_stmt_list", "newline", "end_stmt",
  "top_stmt_list", "name_list", "decl_var", "decl_type", "const_str",
  "import", "import_body_elem", "import_body", "top_stmt_no_emptyline",
  "top_stmt", "stmt_error_end", "stmt_no_emptyline", "stmt", "stmt_list",
  "if_header", "brace_stmt", "if_stmt", "$@1", "elseif", "$@2", "$@3",
  "elseif_list", "else", "catch", "assign", "dotname",
  "type_contract_empty", "type_contract", "contract_body",
  "contract_decl_func", "template", "template_arg", "template_arg_list",
  "extends", "extends_elem", "extends_list", "type_class",
  "class_body_stmt", "class_body_stmt_list", "class_body", "type_base",
  "type_ext", "top_decl_func", "expr_decl_func", "lambda_body",
  "type_self", "decl_self", "decl_arg_list_or_empty", "decl_arg_list",
  "decl_arg", "func_body", "decl_self_nop", "type_func", "type",
  "type_const", "type_mutable", "type_chan", "type_ref", "type_ptr",
  "type_slice", "type_arr_size", "type_arr", "type_name", "type_std_name",
  "expr_const_scalar", "expr_list", "expr_arr", "expr_obj",
  "prop_assing_list", "prop_assing", "qstr_with_inject_begin_elem",
  "qstr_with_inject_begin_list", "qstr_with_inject", "expr", "expr_base",
  "uexpr", "call", YY_NULL
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
     305,   306,    44,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,    63,    58,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,    91,   349,   350,
     351,   352,   353,   354,   355,   356,   357,    40,    41,    59,
     123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   113,   114,   115,   116,   116,   117,   117,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   124,   124,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     131,   131,   131,   131,   132,   132,   133,   133,   134,   135,
     137,   136,   139,   138,   140,   138,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   147,   148,
     148,   149,   149,   149,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   155,   155,   156,   157,   157,
     158,   158,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   161,   161,   161,   162,   162,   162,   162,
     163,   163,   163,   163,   164,   164,   165,   165,   165,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   170,   170,
     171,   172,   172,   172,   172,   173,   173,   174,   175,   176,
     177,   178,   178,   179,   180,   180,   181,   182,   182,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   184,   184,   184,   184,   184,   184,   184,
     185,   185,   186,   186,   187,   187,   187,   188,   188,   189,
     190,   191,   191,   192,   193,   193,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   195,   195,   195,   195,   195,   195,   195,   196,   196
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     3,     5,     3,     1,     1,
       2,     3,     5,     2,     3,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     2,
       1,     3,     3,     2,     1,     1,     1,     2,     1,     3,
       0,     6,     0,     4,     0,     5,     1,     2,     1,     4,
       1,     5,     1,     3,     3,     1,     3,     3,     6,     1,
       2,     6,     7,     7,     6,     1,     3,     1,     1,     3,
       1,     3,     2,     1,     1,     1,     3,     6,     2,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     9,    10,    10,     9,
       8,     9,     6,     4,     1,     1,     1,     2,     3,     2,
       3,     4,     1,     1,     1,     1,     3,     2,     1,     1,
       1,     5,     6,     6,     5,     1,     1,     2,     2,     2,
       2,     2,     2,     3,     1,     1,     4,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     4,     4,     1,     3,     3,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     1,     1,     3,
       5,     2,     2,     2,     2,     2,     2,     2,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     8,     0,     0,     4,     5,
      30,     0,     0,     3,     3,     3,     7,     2,    32,     0,
       0,     0,    31,    11,     0,    19,    18,     0,     0,    20,
       0,     0,   122,     0,     0,     0,    12,    10,     9,    28,
      27,    29,    21,     0,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   159,   160,   158,   161,   162,     0,     3,
       3,     3,     0,     0,     3,     3,    65,     0,     0,     0,
       0,     3,   104,   105,   103,    17,   102,    95,    96,    97,
      99,    98,   100,   101,    94,   147,     0,     0,     0,     0,
       0,     0,    25,     0,     0,   136,   135,   139,   130,     0,
       0,     0,   137,   138,     0,    77,     3,     3,   140,   141,
     142,   144,     0,   145,     0,     0,   148,     0,     0,     0,
     116,     3,     3,     0,     0,    23,    22,    26,     0,     3,
       3,     0,    80,     0,    78,     0,    83,     0,     0,   143,
       0,    66,     0,   119,     0,   117,   121,    13,   124,     0,
       0,   123,   125,     0,     0,    24,    67,     0,     0,     0,
       0,    76,     0,    84,    85,    82,     3,     0,   146,   120,
     118,     0,   127,     0,     0,     0,     0,   131,     0,   134,
      81,    79,     0,    93,    89,    90,    92,     0,     0,     0,
       0,     0,    75,     0,    69,    14,     0,     0,   126,     0,
       0,   132,   133,    86,    91,    87,    88,     0,     0,     0,
      68,    70,     0,   163,   164,   168,   169,     0,   165,     0,
       0,     3,    50,   166,   167,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   129,    45,     0,     0,     0,
      44,    46,     0,    40,     3,   189,   208,     0,   186,   187,
     188,   181,     0,   185,     0,   184,   190,   207,     0,     0,
       0,     3,     3,     0,    34,    35,    33,    43,   184,   207,
      39,     3,     0,     0,     0,   217,   212,   211,   216,   215,
     214,   213,     0,     0,     0,   172,     0,   170,     0,     0,
      36,    37,    47,     0,    62,     0,     0,     0,   106,   183,
     182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,     0,    15,     3,     0,    48,   206,
       0,   115,   114,     0,     0,   173,    64,    63,     0,    41,
       0,   174,   189,     0,     0,   177,   203,   199,   201,   204,
     196,   202,   198,   192,   191,   200,   195,   194,   193,     0,
       0,   197,   209,    42,   107,   108,     0,     0,     0,    38,
       0,     0,     0,     3,   113,     0,   171,     0,   218,     0,
     175,     0,   176,   205,     0,     0,    71,     0,     0,    74,
      16,     0,     0,     0,    52,    58,    56,     3,     0,     0,
     179,     0,   178,   210,     0,    72,    73,     0,     0,    49,
      54,     0,     0,    60,    57,    51,   112,    61,   219,     0,
       0,     0,     0,     0,   110,     0,     0,    53,     0,   111,
      55,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   235,     7,    17,   236,    39,    19,   237,   238,
     239,    91,    21,    92,    93,    22,    23,   267,   240,   241,
     242,   327,   373,   243,   274,   396,   411,   421,   397,   415,
     295,   244,   245,    95,    72,   193,   194,   106,   163,   133,
     137,   164,   165,    73,   185,   186,   187,    96,    75,    24,
     246,   330,   119,    33,   150,   151,   152,   331,    99,    76,
      97,    77,    78,    79,    80,    81,    82,   114,    83,    84,
      85,   248,   286,   249,   250,   344,   345,   251,   252,   253,
     254,   255,   256,   269
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -280
static const yytype_int16 yypact[] =
{
      32,    75,    90,   -34,  -280,  -280,   140,   239,  -280,  -280,
    -280,    38,   136,   123,   123,   123,  -280,  -280,  -280,   307,
     -17,   -17,  -280,  -280,   -17,  -280,  -280,   117,   140,  -280,
    1229,   184,  -280,   187,   187,   187,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,   116,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  1337,  -280,
    -280,  -280,  1337,  1337,   174,   174,  -280,  1337,  1337,  1337,
     -27,    22,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,   681,    98,    99,   131,
     117,   140,  -280,    -2,   141,  -280,  -280,  -280,  -280,   150,
     158,   171,  -280,  -280,  1536,  -280,   202,   202,  -280,  -280,
    -280,  -280,  1337,   183,   173,   234,  -280,   775,   868,   179,
    -280,   241,   241,   241,   140,  -280,  -280,  -280,   185,   241,
     241,   241,  -280,    58,   229,  1536,  -280,   189,   190,  -280,
    1337,  -280,  1536,  -280,  1536,  -280,  -280,  -280,  -280,  1273,
     194,   251,  -280,   201,    -4,  -280,  -280,   205,   206,    26,
    1536,  -280,  1536,  -280,  -280,   258,   152,   217,  -280,  -280,
    -280,   266,  -280,  1017,   241,  1337,   207,  1469,  1337,  -280,
    -280,  -280,  1536,  -280,  -280,  -280,   152,   209,   -35,   267,
     269,   273,  -280,    45,  -280,  -280,   435,   214,  -280,   216,
     435,  -280,  -280,  -280,  -280,  -280,  -280,   220,   222,   224,
    -280,  -280,   -46,  -280,  -280,  -280,  -280,  1309,  -280,  1364,
     283,  -280,  -280,  -280,  -280,   110,  1309,  1309,  1309,  1309,
    1309,  1309,  1309,  1309,  1097,  -280,  -280,   151,   -17,   -17,
    -280,  -280,   540,  -280,   288,    70,  -280,   225,  -280,  -280,
    -280,  -280,   132,  -280,  1518,  -280,  -280,   -18,   435,   435,
     227,   241,   241,   241,  -280,  -280,  -280,  -280,   135,  -280,
    -280,  1442,  1337,   228,  1309,   195,   195,   195,   195,   195,
     195,   195,  1495,   435,   241,  -280,    10,  1518,  1309,  1309,
    -280,  -280,  -280,   291,  -280,   -17,  1309,   532,  -280,  -280,
    -280,  1309,  1309,  1309,  1309,  1309,  1309,  1309,  1309,  1309,
    1309,  1309,  1309,  1309,  1309,   -31,  1337,   -17,   230,   233,
    -280,   237,   240,    36,   -17,   290,   241,   312,  1518,  -280,
     247,  -280,  1518,     8,  1309,  -280,   308,   308,   249,  -280,
      41,  -280,   181,    15,    17,  -280,   299,   299,   512,  1539,
     264,   264,   264,   264,   264,   195,   195,   195,   195,   894,
    1337,   260,  -280,  -280,  -280,  -280,  1125,  1337,   -17,  -280,
    1309,   265,   912,   163,  -280,   435,  1518,   912,  -280,  1309,
    -280,   187,  -280,  -280,   268,  1309,  -280,   -17,   -17,  -280,
    1518,  1061,   633,   332,  -280,  -280,  -280,   168,   272,   726,
    1518,   -43,  -280,  -280,    46,  -280,  -280,   435,   274,  -280,
    -280,  1309,   -42,  -280,  -280,  -280,  -280,  -280,  -280,   278,
     435,  1309,   312,   912,  -280,   280,   312,  -280,   819,  -280,
    -280,  -280
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,    -7,  -280,  -280,     6,   -19,  -280,   -80,  -280,
     106,    13,  -280,   284,  -280,  -280,   373,  -280,  -280,  -213,
    -236,  -279,  -248,  -280,  -280,     3,  -280,  -280,  -280,  -280,
    -201,  -280,    49,  -280,  -280,  -280,   208,    37,   -33,  -280,
     295,   213,  -280,  -280,   218,  -280,  -280,   375,  -280,  -280,
    -280,    28,  -280,   248,   -91,  -120,   232,  -186,   212,  -280,
      83,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,   124,
    -280,  -280,  -252,  -280,  -280,  -280,    27,   155,  -280,  -280,
     192,   193,  -280,   -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -181
static const yytype_int16 yytable[] =
{
      16,   410,    40,   154,     5,    41,    32,    32,    32,     8,
     247,   159,     9,    18,   260,     5,     5,   174,    66,    25,
     111,    26,    66,   379,    29,    18,    38,    38,   293,   292,
      38,   153,    -3,     5,    43,     1,   336,   337,   157,   158,
      42,   149,   149,   149,   340,   343,   188,    90,   174,   149,
     149,   149,    98,    98,    98,   115,   317,   105,   105,    25,
     171,    26,   334,   264,   105,   265,   188,   334,   423,   381,
     324,   132,   318,   319,    37,     6,   360,   189,   174,    71,
     190,   191,    87,    88,    89,   112,   149,    27,   174,   375,
       4,    -3,    37,   334,   149,     5,   104,   125,   334,   136,
     136,   257,   107,   124,   176,   257,   149,    71,   116,   126,
     160,    71,    71,    20,   148,   148,    71,    71,    71,   113,
     115,   335,   148,   148,     3,    20,   380,   180,   382,   181,
     155,   161,   422,   404,   179,    71,   392,    25,    25,    26,
      26,   399,   426,   323,   368,   102,   103,   257,    28,   378,
     108,   109,   110,    71,   418,   299,   210,   217,  -180,   183,
    -180,    71,   -13,   257,   257,    90,    71,    71,   115,   206,
     321,   322,   184,   192,   427,   -13,   -13,   296,   430,   292,
     297,   149,   149,   149,    71,    30,   292,   428,   257,    71,
       5,    71,   184,    71,    38,   139,   115,   115,    71,   192,
     270,   147,     5,   171,   333,   121,   122,   393,   394,    71,
     120,    71,   412,   394,   273,   292,   288,   289,   266,   290,
     291,   419,    71,   168,    71,    38,    71,    71,   134,   115,
      31,    71,   172,    86,   425,   371,    66,   294,   123,    -3,
      10,   143,   145,    11,    38,    38,   149,   379,   104,   189,
     294,   128,   190,   191,   148,   148,   197,   129,   199,   134,
     201,   202,    34,    35,   294,   130,   169,     5,   170,    12,
     135,    13,   100,   101,    14,    15,   339,   257,   131,   115,
     257,   115,   257,   141,   134,   140,   134,   146,   296,     5,
     147,   297,   314,   315,   316,   162,   156,   257,   363,   166,
     167,    38,   173,   174,   257,   369,   134,    -6,    10,   175,
     182,    11,   257,   177,   178,   195,   207,   200,   208,   148,
     205,    71,   209,    38,   258,   257,   259,   261,   257,   262,
      38,   263,   272,   257,   293,   326,   298,    12,   320,    13,
     338,   364,    14,    15,   365,   366,   342,   386,   367,   389,
     310,   311,   312,   313,   372,   325,   370,     5,   374,   377,
     334,   314,   315,   316,   361,    71,   395,   385,   405,   406,
     303,   304,    38,   391,    38,   410,   403,   127,   305,   306,
     307,   308,   309,   416,   420,   310,   311,   312,   313,   424,
     413,   429,    36,    38,    38,   203,   314,   315,   316,   362,
     414,   211,   138,   398,   204,    74,   198,   300,   402,    71,
     268,   271,     0,     0,     0,    71,    71,     0,   275,   276,
     277,   278,   279,   280,   281,   282,   287,     0,     0,     0,
     401,     0,     0,     0,     0,     0,   212,     0,     0,     0,
      71,     0,     0,   384,     0,     0,     0,     0,     0,   387,
     388,     0,     0,     0,   213,   214,   215,     0,   216,     0,
     217,   218,     0,   219,   220,    12,   328,   221,     0,     0,
       0,     0,     0,     0,   408,   332,     0,     0,   222,     0,
     287,   287,   223,   224,   225,     5,     0,     0,   287,   287,
       0,     0,     0,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   226,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,     0,
       0,   229,     0,     0,   230,     0,   376,     0,     0,     0,
     231,   232,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,   233,     0,     0,   234,    -3,     0,     0,     0,
       0,   213,   214,   215,     0,   216,     0,   217,   218,   213,
     214,   215,   390,   216,   221,   217,   218,   332,   219,   220,
      12,   400,   221,     0,     0,     0,     0,   287,     0,   223,
     224,    66,     0,   222,   304,     0,     0,   223,   224,   225,
       5,   305,   306,   307,   308,   309,     0,     0,   310,   311,
     312,   313,     0,   328,   226,     0,     0,     0,     0,   314,
     315,   316,   226,   328,   227,   228,     0,     0,   229,     0,
       0,   230,   227,   228,     0,     0,   229,   231,   232,   230,
       0,     0,     0,     0,   212,   231,   232,     0,     0,   233,
       0,     0,   234,   341,     0,     0,     0,   233,     0,     0,
     234,  -128,   213,   214,   215,     0,   216,     0,   217,   218,
       0,   219,   220,    12,     0,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   222,     0,     0,     0,
     223,   224,   225,     5,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,   226,     0,     0,    57,     0,
       0,     0,     0,     0,     0,   227,   228,     0,     0,   229,
       0,     0,   230,     0,     0,     0,     0,   212,   231,   232,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,     0,     0,   234,   409,   213,   214,   215,     0,   216,
       0,   217,   218,     0,   219,   220,    12,     0,   221,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,   222,
     118,     0,     0,   223,   224,   225,     5,     0,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,     0,     0,   226,     0,
       0,     0,    57,     0,     0,     0,     0,     0,   227,   228,
       0,     0,   229,   142,     0,   230,     0,     0,     0,     0,
     212,   231,   232,     0,    66,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,   234,   417,   213,   214,
     215,     0,   216,     0,   217,   218,     0,   219,   220,    12,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   222,     0,     0,     0,   223,   224,   225,     5,
       0,     0,     0,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,   226,     0,     0,     0,    57,     0,     0,     0,     0,
       0,   227,   228,     0,     0,   229,   144,     0,   230,     0,
       0,     0,     0,   212,   231,   232,     0,    66,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,   234,
     431,   213,   214,   215,     0,   216,     0,   217,   218,     0,
     219,   220,    12,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   222,     0,     0,     0,   223,
     224,   225,     5,   301,   302,   303,   304,     0,     0,     0,
       0,     0,     0,   305,   306,   307,   308,   309,     0,     0,
     310,   311,   312,   313,   226,     0,     0,     0,     0,     0,
       0,   314,   315,   316,   227,   228,     0,     0,   229,     0,
       0,   230,     0,     0,     0,     0,   383,   231,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
       0,     0,   234,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,    58,    59,
       0,     0,    60,    61,    62,    63,     0,     0,    94,     0,
       0,     0,     0,     0,     0,     0,    66,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,    58,    59,     0,     0,    60,    61,    62,    63,
       0,     0,    94,    67,     0,     0,    68,    69,     0,     0,
      66,     0,     0,     0,    70,     0,   213,   214,   215,     0,
     216,     0,   217,   218,     0,     0,     0,   196,     0,   221,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   223,   224,    66,    67,     0,     0,
      68,    69,    57,     0,     0,     0,    58,    59,    70,     0,
      60,    61,    62,    63,     0,     0,    94,   283,     0,   226,
       0,   407,     0,     0,    66,     5,     0,     0,   284,   227,
     228,     0,     0,   229,     0,     0,   230,     0,     0,     0,
       0,     0,   231,   232,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,     0,   234,   285,     0,
       0,    67,     0,     0,    68,    69,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    62,    63,     0,    64,
      65,     0,     0,     0,     0,     0,     0,     0,    66,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,     0,     0,    58,    59,     0,     0,    60,    61,
      62,    63,     0,     0,    94,    67,     0,     0,    68,    69,
       0,     0,    66,     0,     0,   171,    70,     0,   213,   214,
     215,     0,   216,     0,   217,   218,     0,     0,     0,     0,
       0,   221,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,   223,   224,    66,    67,
       0,     0,    68,    69,    57,     0,     0,     0,    58,    59,
      70,     0,    60,    61,    62,    63,     0,     0,    94,     0,
       0,   226,     0,   213,   214,   215,    66,   216,     0,   217,
     218,   227,   228,     0,     0,   229,   221,     0,   230,     0,
       0,     0,     0,     0,   231,   232,     0,     0,     0,     0,
       0,   223,   224,    66,     5,     0,   233,     0,     0,   234,
       0,     0,     0,    67,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,    70,     0,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   227,   228,     0,     0,
     229,     0,     0,   230,     0,     0,     0,     0,     0,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,    37,   234,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,   293,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    62,    63,     0,     0,
      94,   301,   302,   303,   304,     0,     0,     0,    66,     0,
       0,   305,   306,   307,   308,   309,     0,     0,   310,   311,
     312,   313,     0,     0,     0,     0,     0,     0,     0,   314,
     315,   316,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,    69,
       0,     0,     0,    57,   301,   302,   303,   304,     0,     0,
       0,     0,     0,     0,   305,   306,   307,   308,   309,     0,
       0,   310,   311,   312,   313,    66,     0,   301,   302,   303,
     304,     0,   314,   315,   316,     0,     0,   305,   306,   307,
     308,   309,     0,   329,   310,   311,   312,   313,     0,     0,
       0,  -181,     0,     0,     0,   314,   315,   316,   305,   306,
     307,   308,   309,     0,     0,   310,   311,   312,   313,     0,
       0,     0,     0,     0,     0,     0,   314,   315,   316
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-280)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-181)))

static const yytype_int16 yycheck[] =
{
       7,    43,    21,   123,    50,    24,    13,    14,    15,     3,
     196,   131,     6,     7,   200,    50,    50,    52,    49,    21,
      47,    23,    49,    66,    11,    19,    20,    21,    46,   242,
      24,   122,    50,    50,    28,     3,   288,   289,   129,   130,
      27,   121,   122,   123,   296,   297,   166,    49,    52,   129,
     130,   131,    59,    60,    61,    98,   257,    64,    65,    21,
      52,    23,    52,   109,    71,   111,   186,    52,   110,    52,
     271,   104,   258,   259,   109,   109,   107,    32,    52,    30,
      35,    36,    33,    34,    35,   112,   166,    49,    52,    81,
       0,   109,   109,    52,   174,    50,    74,    91,    52,   106,
     107,   196,    65,    90,   108,   200,   186,    58,    71,   111,
      52,    62,    63,     7,   121,   122,    67,    68,    69,    70,
      98,   111,   129,   130,    49,    19,   111,   160,   111,   162,
     124,    73,   411,   385,   108,    86,   372,    21,    21,    23,
      23,   377,   421,   263,   108,    62,    63,   242,   110,   108,
      67,    68,    69,   104,   108,    23,   111,    25,    23,   166,
      25,   112,    52,   258,   259,    49,   117,   118,    98,   188,
     261,   262,   166,   167,   422,    65,    66,   107,   426,   392,
     110,   261,   262,   263,   135,    49,   399,   423,   283,   140,
      50,   142,   186,   144,   188,   112,    98,    98,   149,   193,
     219,    49,    50,    52,   284,   107,   107,    44,    45,   160,
      86,   162,    44,    45,   221,   428,    65,    66,   212,   238,
     239,   407,   173,   140,   175,   219,   177,   178,   104,    98,
     107,   182,   149,    49,   420,   326,    49,   244,   107,     0,
       1,   117,   118,     4,   238,   239,   326,    66,    74,    32,
     257,   110,    35,    36,   261,   262,   173,   107,   175,   135,
     177,   178,    14,    15,   271,   107,   142,    50,   144,    30,
      68,    32,    60,    61,    35,    36,   295,   372,   107,    98,
     375,    98,   377,    49,   160,   112,   162,   108,   107,    50,
      49,   110,    97,    98,    99,    66,   111,   392,   317,   110,
     110,   295,   108,    52,   399,   324,   182,     0,     1,   108,
      52,     4,   407,   108,   108,    49,    49,   110,    49,   326,
     111,   272,    49,   317,   110,   420,   110,   107,   423,   107,
     324,   107,    49,   428,    46,   107,   111,    30,   111,    32,
      49,   111,    35,    36,   111,   108,   297,   366,   108,   368,
      86,    87,    88,    89,    42,   272,    66,    50,   111,   110,
      52,    97,    98,    99,   315,   316,   373,   107,   387,   388,
      71,    72,   366,   108,   368,    43,   108,    93,    79,    80,
      81,    82,    83,   111,   110,    86,    87,    88,    89,   111,
     397,   111,    19,   387,   388,   182,    97,    98,    99,   316,
     397,   193,   107,   375,   186,    30,   174,   252,   381,   360,
     217,   219,    -1,    -1,    -1,   366,   367,    -1,   226,   227,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
     381,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
     391,    -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,   366,
     367,    -1,    -1,    -1,    19,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    28,    29,    30,   274,    32,    -1,    -1,
      -1,    -1,    -1,    -1,   391,   283,    -1,    -1,    43,    -1,
     288,   289,    47,    48,    49,    50,    -1,    -1,   296,   297,
      -1,    -1,    -1,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      -1,    86,    -1,    -1,    89,    -1,   334,    -1,    -1,    -1,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,   107,    -1,    -1,   110,   111,    -1,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,    -1,    25,    26,    19,
      20,    21,   370,    23,    32,    25,    26,   375,    28,    29,
      30,   379,    32,    -1,    -1,    -1,    -1,   385,    -1,    47,
      48,    49,    -1,    43,    72,    -1,    -1,    47,    48,    49,
      50,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      88,    89,    -1,   411,    72,    -1,    -1,    -1,    -1,    97,
      98,    99,    72,   421,    82,    83,    -1,    -1,    86,    -1,
      -1,    89,    82,    83,    -1,    -1,    86,    95,    96,    89,
      -1,    -1,    -1,    -1,     1,    95,    96,    -1,    -1,   107,
      -1,    -1,   110,   111,    -1,    -1,    -1,   107,    -1,    -1,
     110,   111,    19,    20,    21,    -1,    23,    -1,    25,    26,
      -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    48,    49,    50,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,     1,    95,    96,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     107,    -1,    -1,   110,   111,    19,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    43,
      89,    -1,    -1,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    86,    38,    -1,    89,    -1,    -1,    -1,    -1,
       1,    95,    96,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,    -1,   110,   111,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    86,    38,    -1,    89,    -1,
      -1,    -1,    -1,     1,    95,    96,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,   110,
     111,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,    -1,
      86,    87,    88,    89,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,    82,    83,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    -1,    -1,   112,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,
      -1,    -1,   110,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,    41,    86,    -1,    -1,    89,    90,    -1,    -1,
      49,    -1,    -1,    -1,    97,    -1,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,   110,    -1,    32,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    47,    48,    49,    86,    -1,    -1,
      89,    90,    27,    -1,    -1,    -1,    31,    32,    97,    -1,
      35,    36,    37,    38,    -1,    -1,    41,    70,    -1,    72,
      -1,   110,    -1,    -1,    49,    50,    -1,    -1,    81,    82,
      83,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    -1,    -1,   110,   111,    -1,
      -1,    86,    -1,    -1,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    38,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    41,    86,    -1,    -1,    89,    90,
      -1,    -1,    49,    -1,    -1,    52,    97,    -1,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      -1,    32,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    47,    48,    49,    86,
      -1,    -1,    89,    90,    27,    -1,    -1,    -1,    31,    32,
      97,    -1,    35,    36,    37,    38,    -1,    -1,    41,    -1,
      -1,    72,    -1,    19,    20,    21,    49,    23,    -1,    25,
      26,    82,    83,    -1,    -1,    86,    32,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    -1,   107,    -1,    -1,   110,
      -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,   109,   110,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      41,    69,    70,    71,    72,    -1,    -1,    -1,    49,    -1,
      -1,    79,    80,    81,    82,    83,    -1,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    27,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    89,    49,    -1,    69,    70,    71,
      72,    -1,    97,    98,    99,    -1,    -1,    79,    80,    81,
      82,    83,    -1,   108,    86,    87,    88,    89,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    97,    98,    99,    79,    80,
      81,    82,    83,    -1,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   114,    49,     0,    50,   109,   116,   118,   118,
       1,     4,    30,    32,    35,    36,   115,   117,   118,   120,
     123,   125,   128,   129,   162,    21,    23,    49,   110,   124,
      49,   107,   115,   166,   166,   166,   129,   109,   118,   119,
     119,   119,   124,   118,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    27,    31,    32,
      35,    36,    37,    38,    40,    41,    49,    86,    89,    90,
      97,   145,   147,   156,   160,   161,   172,   174,   175,   176,
     177,   178,   179,   181,   182,   183,    49,   145,   145,   145,
      49,   124,   126,   127,    41,   146,   160,   173,   115,   171,
     171,   171,   173,   173,    74,   115,   150,   150,   173,   173,
     173,    47,   112,   145,   180,    98,   150,    86,    89,   165,
     182,   107,   107,   107,   124,   118,   111,   126,   110,   107,
     107,   107,   151,   152,   182,    68,   115,   153,   153,   173,
     112,    49,    38,   182,    38,   182,   108,    49,   115,   121,
     167,   168,   169,   167,   168,   118,   111,   167,   167,   168,
      52,    73,    66,   151,   154,   155,   110,   110,   173,   182,
     182,    52,   173,   108,    52,   108,   108,   108,   108,   108,
     151,   151,    52,   115,   118,   157,   158,   159,   168,    32,
      35,    36,   118,   148,   149,    49,   110,   173,   169,   173,
     110,   173,   173,   154,   157,   111,   119,    49,    49,    49,
     111,   149,     1,    19,    20,    21,    23,    25,    26,    28,
      29,    32,    43,    47,    48,    49,    72,    82,    83,    86,
      89,    95,    96,   107,   110,   115,   118,   121,   122,   123,
     131,   132,   133,   136,   144,   145,   163,   170,   184,   186,
     187,   190,   191,   192,   193,   194,   195,   196,   110,   110,
     170,   107,   107,   107,   109,   111,   118,   130,   194,   196,
     119,   193,    49,   115,   137,   193,   193,   193,   193,   193,
     193,   193,   193,    70,    81,   111,   185,   193,    65,    66,
     119,   119,   132,    46,   115,   143,   107,   110,   111,    23,
     190,    69,    70,    71,    72,    79,    80,    81,    82,    83,
      86,    87,    88,    89,    97,    98,    99,   143,   170,   170,
     111,   167,   167,   168,   143,   173,   107,   134,   193,   108,
     164,   170,   193,   121,    52,   111,   185,   185,    49,   119,
     185,   111,   145,   185,   188,   189,   193,   193,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     107,   145,   173,   119,   111,   111,   108,   108,   108,   119,
      66,   167,    42,   135,   111,    81,   193,   110,   108,    66,
     111,    52,   111,   112,   173,   107,   119,   173,   173,   119,
     193,   108,   133,    44,    45,   115,   138,   141,   164,   133,
     193,   145,   189,   108,   185,   119,   119,   110,   173,   111,
      43,   139,    44,   115,   138,   142,   111,   111,   108,   170,
     110,   140,   134,   110,   111,   170,   134,   135,   133,   111,
     135,   111
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

    { yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 5:

    { yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 8:

    { yoParserNewLine(parm, &yyloc); yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 10:

    { yoParseEmpty(&(yyval), parm, &yyloc); }
    break;

  case 12:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 14:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 15:

    { yoParserDeclVar(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 16:

    {
				yoParserDeclVar(&(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm, &yyloc); 
				yoParserBinOp(&(yyvsp[(2) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(5) - (5)]), T_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), parm, &yyloc);
			}
    break;

  case 17:

    { yoParserDeclType(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 20:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 21:

    { yoParserImport(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 22:

    { (yyval) = (yyvsp[(4) - (5)]); }
    break;

  case 23:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(1) - (2)]), parm, &yyloc); }
    break;

  case 24:

    { yoParserImport(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 26:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 30:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; yyerrok; }
    break;

  case 38:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (4)]), parm, &yyloc); yoParserStmtCatch(&(yyval), &(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 39:

    { yoParserStmtReturn(&(yyval), NULL, parm, &yyloc); }
    break;

  case 41:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 42:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 43:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; yyerrok; }
    break;

  case 47:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 49:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 50:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 51:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 52:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 53:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 54:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 55:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); }
    break;

  case 57:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 59:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 61:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 63:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 64:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DECL_ASSIGN, parm, &yyloc); }
    break;

  case 66:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 67:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 68:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 70:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 71:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 72:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 73:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 74:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 76:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 79:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 81:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 82:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 86:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 87:

    { yoParserClass(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 91:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 106:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 107:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 108:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 109:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 110:

    { yoParserDeclFunc(&(yyval), T_EXPR_FUNC, NULL, NULL, &(yyvsp[(4) - (8)]), NULL, &(yyvsp[(7) - (8)]), parm, &yyloc); }
    break;

  case 111:

    { yoParserDeclFunc(&(yyval), T_EXPR_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 112:

    { yoParserDeclFunc(&(yyval), T_EXPR_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 113:

    { yoParserDeclFunc(&(yyval), T_EXPR_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 114:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 117:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 118:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 119:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 120:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 121:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 126:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 127:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 131:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 132:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 133:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 134:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 137:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 138:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 139:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 141:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 142:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 143:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 146:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 151:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 152:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 153:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 154:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 155:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 156:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 157:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 158:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 159:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 160:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 163:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 164:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 165:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 171:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 172:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 173:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 174:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 175:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 176:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 178:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 179:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 180:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 182:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 183:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 191:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 192:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 193:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 194:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 195:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 196:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 197:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 198:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 199:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 200:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 201:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 202:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 203:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XORXOR, parm, &yyloc); }
    break;

  case 204:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 205:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 206:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 209:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 210:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 211:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 212:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 213:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 214:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 215:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 216:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 217:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 218:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 219:

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




