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
     T_UNKNOWN_YET = 283,
     T_RETURN = 284,
     T_LET = 285,
     T_TYPE = 286,
     T_CHAN = 287,
     T_FUNC = 288,
     T_SUB_FUNC = 289,
     T_LAMBDA = 290,
     T_GET = 291,
     T_SET = 292,
     T_CONST = 293,
     T_MUTABLE = 294,
     T_STRUCT = 295,
     T_CLASS = 296,
     T_CONTRACT = 297,
     T_BRACE = 298,
     T_IF = 299,
     T_ELSE = 300,
     T_ELSEIF = 301,
     T_CATCH = 302,
     T_SIZEOF = 303,
     T_LNUMBER = 304,
     T_DNUMBER = 305,
     T_NAME = 306,
     T_NEWLINE = 307,
     T_FIX = 308,
     T_POW_ASSIGN = 309,
     T_RSH_ASSIGN = 310,
     T_LSH_ASSIGN = 311,
     T_XOR_ASSIGN = 312,
     T_OR_ASSIGN = 313,
     T_AND_ASSIGN = 314,
     T_MOD_ASSIGN = 315,
     T_CONCAT_ASSIGN = 316,
     T_DIV_ASSIGN = 317,
     T_MUL_ASSIGN = 318,
     T_MINUS_ASSIGN = 319,
     T_PLUS_ASSIGN = 320,
     T_DECL_ASSIGN = 321,
     T_ASSIGN = 322,
     T_INIT_ASSIGN = 323,
     T_PROP_ASSIGN = 324,
     T_XORXOR = 325,
     T_OROR = 326,
     T_ANDAND = 327,
     T_CHAN_ACCESS = 328,
     T_GT = 329,
     T_LT = 330,
     T_GE = 331,
     T_LE = 332,
     T_NE = 333,
     T_EQ = 334,
     T_CONCAT = 335,
     T_XOR = 336,
     T_OR = 337,
     T_MINUS = 338,
     T_PLUS = 339,
     T_RSH = 340,
     T_LSH = 341,
     T_AND = 342,
     T_MOD = 343,
     T_DIV = 344,
     T_MUL = 345,
     T_POW = 346,
     T_AT = 347,
     T_UNARY = 348,
     T_DEC = 349,
     T_INC = 350,
     T_TILDE = 351,
     T_NOT = 352,
     T_DOT = 353,
     T_AS = 354,
     T_INDIRECT = 355,
     T_ADDR = 356,
     T_INDEX = 357,
     T_PTR = 358,
     T_ARR = 359,
     T_DOTNAME = 360,
     NotParen = 361
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
#define YYLAST   1671

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  117
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNRULES -- Number of states.  */
#define YYNSTATES  451

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   361

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     111,   112,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,   113,
       2,     2,     2,    71,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   101,     2,   116,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   114,     2,   115,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   102,   103,   104,   105,   106,   107,   108,
     109,   110
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    11,    14,    16,    18,    20,
      22,    24,    26,    29,    31,    35,    37,    39,    44,    49,
      56,    63,    67,    69,    71,    74,    78,    84,    87,    91,
      93,    96,    99,   102,   105,   107,   109,   111,   113,   117,
     121,   124,   129,   132,   134,   138,   142,   145,   147,   149,
     151,   154,   156,   160,   161,   168,   169,   174,   175,   181,
     183,   186,   188,   193,   195,   201,   203,   205,   209,   213,
     220,   222,   225,   232,   240,   248,   255,   257,   261,   263,
     265,   269,   271,   275,   278,   280,   282,   284,   288,   295,
     298,   300,   302,   305,   307,   309,   311,   313,   315,   317,
     319,   321,   323,   325,   327,   329,   331,   333,   334,   345,
     356,   366,   376,   386,   393,   398,   400,   402,   404,   407,
     411,   414,   418,   423,   425,   427,   429,   431,   435,   439,
     443,   445,   447,   449,   455,   462,   469,   475,   477,   479,
     482,   485,   488,   491,   494,   497,   501,   503,   505,   510,
     512,   515,   517,   519,   521,   523,   525,   527,   529,   531,
     533,   535,   537,   539,   541,   543,   545,   547,   549,   551,
     553,   555,   557,   559,   561,   565,   568,   572,   576,   581,
     586,   588,   592,   596,   599,   601,   604,   607,   609,   611,
     613,   615,   617,   619,   623,   627,   631,   635,   639,   643,
     647,   651,   655,   659,   663,   667,   671,   675,   677,   679,
     683,   689,   692,   695,   698,   701,   704,   707,   709,   713,
     718,   721,   724,   728,   730,   732,   737
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     118,     0,    -1,     3,    51,   120,   121,    -1,    -1,   122,
      -1,   113,   122,    -1,   124,    -1,   119,    -1,    52,    -1,
     122,    -1,   113,    -1,   134,    -1,   124,   134,    -1,    51,
      -1,   125,    54,    51,    -1,   178,    -1,   119,    -1,    30,
     119,    51,   126,    -1,    30,    39,    51,   126,    -1,    30,
     119,    51,   126,    68,   198,    -1,    30,    39,    51,   126,
      68,   198,    -1,    31,    51,   165,    -1,    23,    -1,    21,
      -1,     4,   129,    -1,     4,    51,   129,    -1,     4,   114,
     122,   132,   115,    -1,   129,   122,    -1,    51,   129,   122,
      -1,   131,    -1,   132,   131,    -1,   130,   123,    -1,   128,
     123,    -1,   166,   123,    -1,     1,    -1,   133,    -1,   122,
      -1,   119,    -1,   127,   148,   123,    -1,   167,   148,   123,
      -1,   128,   123,    -1,    29,   198,   148,   123,    -1,    29,
     123,    -1,   141,    -1,   201,   148,   123,    -1,   203,   148,
     123,    -1,     1,   135,    -1,   136,    -1,   122,    -1,   137,
      -1,   138,   137,    -1,   198,    -1,    43,   138,   115,    -1,
      -1,    44,   142,   139,   140,   146,   147,    -1,    -1,    46,
     144,   139,   140,    -1,    -1,    45,    44,   145,   139,   140,
      -1,   143,    -1,   146,   143,    -1,   119,    -1,    45,   114,
     138,   115,    -1,   119,    -1,    47,    51,   114,   138,   115,
      -1,   119,    -1,    51,    -1,   149,   102,    51,    -1,    42,
     114,   115,    -1,    42,   154,   157,   114,   152,   115,    -1,
     153,    -1,   152,   153,    -1,    33,    51,   111,   172,   112,
     123,    -1,    33,    51,   111,   172,   112,   178,   123,    -1,
      36,    51,   111,   172,   112,   178,   123,    -1,    37,    51,
     111,   173,   112,   123,    -1,   122,    -1,    78,   156,    77,
      -1,   119,    -1,   187,    -1,   187,    68,   155,    -1,   155,
      -1,   156,    54,   155,    -1,    72,   159,    -1,   119,    -1,
     155,    -1,   158,    -1,   159,    54,   158,    -1,    41,   154,
     157,   114,   163,   115,    -1,   174,   123,    -1,   122,    -1,
     161,    -1,   162,   161,    -1,   162,    -1,   119,    -1,   187,
      -1,   179,    -1,   180,    -1,   181,    -1,   183,    -1,   182,
      -1,   184,    -1,   186,    -1,   177,    -1,   164,    -1,   151,
      -1,   160,    -1,    -1,    33,   171,   149,   111,   172,   112,
     126,   114,   175,   115,    -1,    36,   171,   149,   111,   172,
     112,   178,   114,   175,   115,    -1,    37,   171,   149,   111,
     173,   112,   114,   175,   115,    -1,    33,    51,   111,   172,
     112,   126,   114,   175,   115,    -1,    33,   119,   111,   172,
     112,   126,   114,   175,   115,    -1,   114,    85,   125,    85,
     169,   115,    -1,   114,    74,   169,   115,    -1,   198,    -1,
     175,    -1,   187,    -1,    93,   187,    -1,    93,    39,   187,
      -1,    90,   187,    -1,    90,    39,   187,    -1,   111,    51,
     170,   112,    -1,   119,    -1,   173,    -1,   119,    -1,   174,
      -1,   173,    54,   174,    -1,   119,   125,   178,    -1,    39,
     125,   178,    -1,   138,    -1,   119,    -1,   119,    -1,    33,
     176,   111,   172,   112,    -1,    33,   176,   111,   172,   112,
     178,    -1,    36,   176,   111,   172,   112,   178,    -1,    37,
     176,   111,   173,   112,    -1,   164,    -1,   150,    -1,    38,
     178,    -1,    39,   178,    -1,    32,   178,    -1,    90,   178,
      -1,    93,   178,    -1,    94,   178,    -1,   101,   116,   178,
      -1,    49,    -1,   149,    -1,   101,   185,   116,   178,    -1,
     188,    -1,   149,   154,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    14,    -1,    17,    -1,    15,    -1,    16,    -1,    18,
      -1,    27,    -1,    71,    -1,    19,    -1,    20,    -1,    26,
      -1,    49,    -1,    50,    -1,    21,    -1,    23,    -1,   198,
      -1,   190,    54,   198,    -1,   114,   115,    -1,   114,   190,
     115,    -1,   149,   114,   115,    -1,   149,   114,   190,   115,
      -1,   149,   114,   193,   115,    -1,   194,    -1,   193,    54,
     194,    -1,   149,    68,   198,    -1,    25,   199,    -1,   195,
      -1,   196,   195,    -1,   196,    23,    -1,   199,    -1,   197,
      -1,   189,    -1,   200,    -1,   191,    -1,   192,    -1,   198,
      87,   198,    -1,   198,    86,   198,    -1,   198,    93,   198,
      -1,   198,    92,   198,    -1,   198,    91,   198,    -1,   198,
      83,   198,    -1,   198,    85,   198,    -1,   198,    74,   198,
      -1,   198,    90,   198,    -1,   198,    75,   198,    -1,   198,
      84,   198,    -1,   198,    73,   198,    -1,   198,    76,   198,
      -1,   111,   198,   112,    -1,   203,    -1,   168,    -1,   198,
     103,   178,    -1,   198,   102,   111,   178,   112,    -1,    87,
     198,    -1,    86,   198,    -1,   100,   198,    -1,    99,   198,
      -1,    76,   198,    -1,    48,   198,    -1,   149,    -1,   198,
     102,   149,    -1,   198,   101,   198,   116,    -1,    93,   198,
      -1,    90,   198,    -1,   200,    68,   198,    -1,   190,    -1,
     119,    -1,   149,   111,   202,   112,    -1,   198,   102,   149,
     111,   202,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   228,   228,   231,   240,   241,   244,   245,   248,   251,
     252,   255,   256,   259,   260,   263,   264,   267,   268,   269,
     274,   281,   284,   285,   288,   289,   290,   293,   294,   297,
     298,   301,   302,   303,   304,   307,   308,   311,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   330,   331,   334,
     335,   346,   349,   352,   352,   357,   357,   358,   358,   361,
     362,   363,   366,   367,   370,   371,   374,   375,   378,   381,
     384,   385,   388,   389,   390,   391,   392,   395,   396,   399,
     400,   403,   404,   407,   408,   411,   414,   415,   418,   421,
     422,   439,   440,   443,   444,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   458,   459,   460,   462,   463,   465,
     467,   471,   479,   481,   483,   487,   488,   491,   492,   493,
     494,   495,   498,   499,   502,   503,   506,   507,   510,   511,
     514,   515,   524,   527,   528,   529,   530,   533,   534,   537,
     540,   543,   546,   549,   550,   557,   561,   562,   565,   569,
     571,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   591,   592,   593,   594,
     595,   596,   597,   600,   601,   604,   605,   608,   609,   610,
     613,   614,   617,   620,   623,   624,   627,   630,   631,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   666,   667,   668,
     669,   670,   673,   676,   677,   680,   681
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
  "T_QSTRING_INJECT_EXRP", "T_NULL", "T_VOID", "T_UNKNOWN_YET", "T_RETURN",
  "T_LET", "T_TYPE", "T_CHAN", "T_FUNC", "T_SUB_FUNC", "T_LAMBDA", "T_GET",
  "T_SET", "T_CONST", "T_MUTABLE", "T_STRUCT", "T_CLASS", "T_CONTRACT",
  "T_BRACE", "T_IF", "T_ELSE", "T_ELSEIF", "T_CATCH", "T_SIZEOF",
  "T_LNUMBER", "T_DNUMBER", "T_NAME", "T_NEWLINE", "T_FIX", "','",
  "\"**= (T_POW_ASSIGN)\"", "\">>= (T_RSH_ASSIGN)\"",
  "\"<<= (T_LSH_ASSIGN)\"", "\"^= (T_XOR_ASSIGN)\"",
  "\"|= (T_OR_ASSIGN)\"", "\"&= (T_AND_ASSIGN)\"", "\"%= (T_MOD_ASSIGN)\"",
  "\"..= (T_CONCAT_ASSIGN)\"", "\"/= (T_DIV_ASSIGN)\"",
  "\"*= (T_MUL_ASSIGN)\"", "\"-= (T_MINUS_ASSIGN)\"",
  "\"+= (T_PLUS_ASSIGN)\"", "\":= (T_DECL_ASSIGN)\"", "\"= (T_ASSIGN)\"",
  "\"= (T_INIT_ASSIGN)\"", "\"= (T_PROP_ASSIGN)\"", "'?'", "':'",
  "\"^^ (T_XORXOR)\"", "\"|| (T_OROR)\"", "\"&& (T_ANDAND)\"",
  "\"<- (T_CHAN_ACCESS)\"", "\"> (T_GT)\"", "\"< (T_LT)\"",
  "\">= (T_GE)\"", "\"<= (T_LE)\"", "\"!= (T_NE)\"", "\"== (T_EQ)\"",
  "\".. (T_CONCAT)\"", "\"^ (T_XOR)\"", "\"| (T_OR)\"", "\"- (T_MINUS)\"",
  "\"+ (T_PLUS)\"", "\">> (T_RSH)\"", "\"<< (T_LSH)\"", "\"& (T_AND)\"",
  "\"% (T_MOD)\"", "\"/ (T_DIV)\"", "\"* (T_MUL)\"", "\"** (T_POW)\"",
  "\"@ (T_AT)\"", "T_UNARY", "\"-- (T_DEC)\"", "\"++ (T_INC)\"",
  "\"~ (T_TILDE)\"", "\"! (T_NOT)\"", "'['", "\". (T_DOT)\"",
  "\"as (T_AS)\"", "\"* (T_INDIRECT)\"", "\"& (T_ADDR)\"",
  "\"[] (T_INDEX)\"", "T_PTR", "T_ARR", "T_DOTNAME", "NotParen", "'('",
  "')'", "';'", "'{'", "'}'", "']'", "$accept", "file", "empty",
  "end_newline", "module_stmt_list", "newline", "end_stmt",
  "top_stmt_list", "name_list", "type_or_empty", "decl_var", "decl_type",
  "const_str", "import", "import_body_elem", "import_body",
  "top_stmt_no_emptyline", "top_stmt", "stmt_error_end",
  "stmt_no_emptyline", "stmt", "stmt_list", "if_header", "brace_stmt",
  "if_stmt", "$@1", "elseif", "$@2", "$@3", "elseif_list", "else", "catch",
  "dotname", "type_contract_empty", "type_contract", "contract_body",
  "contract_decl_func", "template", "template_arg", "template_arg_list",
  "extends", "extends_elem", "extends_list", "type_class",
  "class_body_stmt", "class_body_stmt_list", "class_body", "type_base",
  "type_ext", "top_decl_func", "decl_func", "expr_decl_func",
  "lambda_body", "type_self", "decl_self", "decl_arg_list_or_empty",
  "decl_arg_list", "decl_arg", "func_body", "decl_self_nop", "type_func",
  "type", "type_const", "type_mutable", "type_chan", "type_ref",
  "type_ptr", "type_slice", "type_arr_size", "type_arr", "type_name",
  "type_std_name", "expr_const_scalar", "expr_list", "expr_arr",
  "expr_obj", "prop_assing_list", "prop_assing",
  "qstr_with_inject_begin_elem", "qstr_with_inject_begin_list",
  "qstr_with_inject", "expr", "expr_base", "expr_for_assign", "assign",
  "call_args", "call", YY_NULL
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
     305,   306,   307,   308,    44,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,    63,    58,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,    91,   353,   354,   355,   356,   357,   358,   359,   360,
     361,    40,    41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   117,   118,   119,   120,   120,   121,   121,   122,   123,
     123,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     127,   128,   129,   129,   130,   130,   130,   131,   131,   132,
     132,   133,   133,   133,   133,   134,   134,   135,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   137,   137,   138,
     138,   139,   140,   142,   141,   144,   143,   145,   143,   146,
     146,   146,   147,   147,   148,   148,   149,   149,   150,   151,
     152,   152,   153,   153,   153,   153,   153,   154,   154,   155,
     155,   156,   156,   157,   157,   158,   159,   159,   160,   161,
     161,   162,   162,   163,   163,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   165,   165,   165,   166,   166,   166,
     166,   167,   168,   168,   168,   169,   169,   170,   170,   170,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   177,   177,   177,   177,   178,   178,   179,
     180,   181,   182,   183,   183,   184,   185,   185,   186,   187,
     187,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   189,   189,   189,   189,
     189,   189,   189,   190,   190,   191,   191,   192,   192,   192,
     193,   193,   194,   195,   196,   196,   197,   198,   198,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   200,   200,   200,
     200,   200,   201,   202,   202,   203,   203
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     4,     4,     6,
       6,     3,     1,     1,     2,     3,     5,     2,     3,     1,
       2,     2,     2,     2,     1,     1,     1,     1,     3,     3,
       2,     4,     2,     1,     3,     3,     2,     1,     1,     1,
       2,     1,     3,     0,     6,     0,     4,     0,     5,     1,
       2,     1,     4,     1,     5,     1,     1,     3,     3,     6,
       1,     2,     6,     7,     7,     6,     1,     3,     1,     1,
       3,     1,     3,     2,     1,     1,     1,     3,     6,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,    10,    10,
       9,     9,     9,     6,     4,     1,     1,     1,     2,     3,
       2,     3,     4,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     5,     6,     6,     5,     1,     1,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     4,     4,
       1,     3,     3,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       5,     2,     2,     2,     2,     2,     2,     1,     3,     4,
       2,     2,     3,     1,     1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     8,     0,     0,     4,     5,
      34,     0,     0,     3,     3,     3,     7,     2,    36,     0,
       0,     0,    35,    11,     0,    23,    22,     0,     0,    24,
       0,     0,   123,     0,     0,     0,    12,    10,     9,    32,
      31,    33,    25,     0,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   161,   162,   160,   163,   164,     0,     3,
       3,     3,     0,     0,     3,     3,    66,   165,     0,     0,
       0,     0,     3,   105,   106,   104,    21,   103,    96,    97,
      98,   100,    99,   101,   102,    95,   149,     0,     0,     0,
       0,     0,     0,    29,     0,     0,   138,   137,   141,   132,
       0,     0,     0,   139,   140,     0,    78,     3,     3,   142,
     143,   144,   146,     0,   147,     0,     0,   150,     0,     0,
       0,   117,     3,     3,     3,     0,    27,    26,    30,     0,
       3,     3,     3,    81,     0,    79,     0,    84,     0,     0,
     145,     0,    67,     0,   120,     0,   118,   122,     0,   125,
       0,   124,   126,     0,     0,     0,    28,    68,     0,     0,
       0,     0,    77,     0,    85,    86,    83,     3,     0,   148,
     121,   119,    13,     0,     0,     3,     3,     0,     0,   133,
       0,   136,    82,    80,     0,    94,    90,    91,     3,     0,
       0,     0,     0,     0,    76,     0,    70,     0,   129,   128,
      16,     0,    15,   127,     0,     0,   134,   135,    87,    92,
      88,    89,     0,     0,     0,    69,    71,    14,     0,     0,
       3,   166,   167,   171,   172,     0,   168,     0,     3,     3,
      53,     0,   169,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,    48,     3,     0,    47,    49,     0,
      43,   217,     3,   208,     0,   189,   191,   192,   184,     0,
     188,     0,   187,   190,     3,   207,     3,     3,     3,     0,
       0,    37,    46,     3,   187,   190,   207,    42,     3,     0,
       0,     0,     0,     0,   216,   215,   212,   211,   221,   220,
     214,   213,     0,     0,     0,   175,     0,   173,     0,    65,
       0,    40,    50,     3,     0,     0,   110,   186,   185,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,   109,     0,     3,     3,     3,     3,     0,    51,
     206,     0,   116,   115,     0,     0,   176,     0,    38,   224,
     223,     0,   177,   217,     0,     0,   180,    39,   204,   200,
     202,   205,   198,   203,   199,   194,   193,   201,   197,   196,
     195,     0,     0,   218,   209,   222,    44,    45,     0,     0,
       0,    41,    18,    17,     0,     0,     0,     3,   114,     0,
     174,     0,   225,     0,   178,     0,   179,   219,     0,     3,
      72,     0,     0,    75,     0,     0,     3,     3,     0,     0,
      55,    61,    59,     3,     0,     0,   182,     0,   181,   210,
       0,    73,    74,    20,    19,     0,     0,    52,    57,     0,
       0,    63,    60,    54,   113,    64,   226,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,   111,   112,    58,
      62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   149,     7,    17,    38,    39,    19,   174,   201,
     245,   246,    92,    21,    93,    94,    22,    23,   272,   247,
     248,   249,   338,   387,   250,   283,   412,   429,   439,   413,
     433,   300,   251,    96,    73,   195,   196,   107,   164,   134,
     138,   165,   166,    74,   187,   188,   189,    97,    76,    24,
     252,   253,   341,   120,    33,   150,   151,   152,   342,   100,
      77,   202,    78,    79,    80,    81,    82,    83,   115,    84,
      85,    86,   255,   350,   256,   257,   355,   356,   258,   259,
     260,   261,   262,   275,   264,   351,   276
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -349
static const yytype_int16 yypact[] =
{
      39,    10,    58,   -19,  -349,  -349,    54,    76,  -349,  -349,
    -349,    27,    70,    26,    26,    26,  -349,  -349,  -349,   186,
     -18,   -18,  -349,  -349,   -18,  -349,  -349,   156,    54,  -349,
    1228,    91,  -349,   102,   102,   102,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,   149,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  1344,  -349,
    -349,  -349,  1344,  1344,    80,    80,  -349,  -349,  1344,  1344,
    1344,   -13,   -49,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
    -349,  -349,  -349,  -349,  -349,  -349,  -349,   691,    34,    36,
      67,   156,    54,  -349,   -10,    47,  -349,  -349,  -349,  -349,
      65,    77,    95,  -349,  -349,   959,  -349,   175,   175,  -349,
    -349,  -349,  -349,  1344,   119,   112,   183,  -349,   780,   865,
     141,  -349,   219,   219,   219,    54,  -349,  -349,  -349,   148,
     219,   219,   219,  -349,    19,   210,   959,  -349,   160,   163,
    -349,  1344,  -349,   959,  -349,   959,  -349,  -349,   238,   238,
     182,   239,  -349,   190,   238,    21,  -349,  -349,   191,   193,
      28,   959,  -349,   959,  -349,  -349,   244,    18,   208,  -349,
    -349,  -349,  -349,  1274,  1274,  1344,   219,  1344,   195,  1511,
    1344,  -349,  -349,  -349,   959,   238,  -349,  -349,     4,   192,
     -18,   257,   260,   261,  -349,   -28,  -349,   262,  -349,  -349,
    -349,   201,  -349,  -349,   202,   467,  -349,  -349,  -349,  -349,
    -349,  -349,   211,   212,   214,  -349,  -349,  -349,   467,   467,
    -349,  -349,  -349,  -349,  -349,  1402,  -349,  1368,   280,   269,
    -349,  1402,  -349,  -349,  1402,  1402,  1402,  1402,  1402,  1402,
    1402,  1402,  1035,  -349,  -349,   279,   -18,  -349,  -349,   554,
    -349,   162,   279,  -349,   213,  -349,  -349,  -349,  -349,   188,
    -349,  1505,  -349,   264,   279,   -29,   219,   219,   219,   215,
     218,  -349,  -349,  -349,   206,  -349,  -349,  -349,  1005,   278,
     284,   225,   226,  1402,   181,   181,   181,   181,   181,   181,
     181,   181,  1482,   467,   238,  -349,    -5,  1505,   287,  -349,
     -18,  -349,  -349,  1402,  1118,   -18,  -349,  -349,  -349,  1402,
    1402,  1402,  1402,  1402,  1402,  1402,  1402,  1402,  1402,  1402,
    1402,  1402,  1402,   -14,  1344,  1402,   -18,   -18,   227,   228,
      32,  -349,  -349,   -18,  1344,  1344,   219,   219,   302,  1505,
    -349,   231,  -349,  1505,    -2,  1402,  -349,   234,  -349,  -349,
     296,   245,  -349,   140,     5,     8,  -349,  -349,  1526,  1526,
    1547,  1568,   288,   288,   288,   288,   288,   181,   181,   181,
     181,  1087,  1344,   240,  -349,  1505,  -349,  -349,  1011,  1344,
     -18,  -349,   290,   291,   248,   249,   902,   151,  -349,   467,
    1505,   902,  -349,  1402,  -349,   102,  -349,  -349,   250,  1402,
    -349,   -18,   -18,  -349,  1402,  1402,  1344,  1344,   641,   319,
    -349,  -349,  -349,   194,   252,   728,  1505,   -17,  -349,  -349,
     254,  -349,  -349,  1505,  1505,   256,   258,  -349,  -349,  1402,
     -12,  -349,  -349,  -349,  -349,  -349,  -349,   467,   467,  1402,
     302,   902,   253,   259,   302,  -349,   815,  -349,  -349,  -349,
    -349
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -349,  -349,     7,  -349,  -349,    -3,    -9,  -349,  -142,  -280,
    -349,    97,    17,  -349,   281,  -349,  -349,   354,  -349,  -349,
    -248,  -257,  -348,  -220,  -349,  -349,   -37,  -349,  -349,  -349,
    -349,     3,    30,  -349,  -349,  -349,   187,   129,   -31,  -349,
     276,   203,  -349,  -349,   189,  -349,  -349,   355,  -349,  -349,
    -349,  -349,     6,  -349,   251,  -104,  -122,    -8,  -188,   209,
    -349,   -23,  -349,  -349,  -349,  -349,  -349,  -349,  -349,  -349,
     143,  -349,  -349,  -235,  -349,  -349,  -349,     2,   139,  -349,
    -349,   220,   174,   -94,  -349,     1,    38
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -184
static const yytype_int16 yytable[] =
{
       8,   302,   155,     9,    18,   191,   173,   296,   192,   193,
     160,    25,    40,    26,    16,    41,    18,   254,   298,   153,
      32,    32,    32,    -3,     5,    43,   158,   159,    29,   105,
     269,   270,   428,     5,     5,    98,   112,    66,    66,   103,
     104,    91,     1,   148,    42,   109,   110,   111,    25,   345,
      26,   393,   197,   116,   382,   383,     5,   148,     4,   345,
      72,     3,   395,    88,    89,    90,    99,    99,    99,   354,
       5,   106,   106,   161,   133,   176,    -3,    10,    27,   106,
      11,   440,   176,   389,    -3,   116,   176,   215,    72,   126,
     140,   444,    72,    72,     6,    37,   162,   372,    72,    72,
      72,   114,   441,   113,    20,   127,     5,    12,   125,    13,
     346,   263,    14,    15,   137,   137,    20,    72,   169,   -93,
     394,    30,   156,   396,   263,   263,   425,   426,     5,   408,
     182,   154,   183,   178,   415,    72,   116,    31,   116,   154,
     181,    28,    87,    72,   380,   122,   330,   123,    72,    72,
     198,   199,   344,    66,   204,   263,   206,   207,   105,   190,
     302,   129,   328,   329,   186,   194,    72,   302,   203,   116,
      25,    72,    26,    72,   185,    72,   130,    25,   124,    26,
     190,   211,   200,   154,   446,   186,    -6,    10,   131,  -107,
      11,    72,   194,    72,   108,   154,   409,   410,   302,   263,
      91,   117,   244,    72,    72,    72,   132,    72,   393,    72,
      72,   307,   243,   225,    72,   244,   244,    12,   277,    13,
     445,   116,    14,    15,   449,   243,   243,   271,   141,  -183,
     121,  -183,   384,   385,   142,   280,   282,   301,     5,   430,
     410,   191,   116,   265,   192,   193,   244,   136,   135,   442,
     443,   303,   299,   147,   304,   305,   265,   265,   148,   299,
       5,   144,   146,   157,   116,    34,    35,   326,   327,   101,
     102,   299,   299,   303,   167,   154,   304,   168,   163,   135,
     282,   333,   322,   323,   324,   299,   170,   265,   171,   172,
     244,   348,   263,   176,   175,   263,   357,   263,   184,  -107,
     243,   374,   177,   179,   135,   180,   135,   210,   212,   205,
     349,   213,   214,   217,   263,   218,   219,   376,   377,   279,
     281,   263,   266,   267,   381,   268,   298,   135,   306,   334,
     331,   265,   325,   332,   353,   335,   336,   337,   347,   378,
     379,   200,   200,   263,   263,   386,   388,   263,   391,   398,
     345,   399,   263,   373,    72,   401,   402,   392,   404,   405,
     406,   407,   419,   428,    72,    72,   436,   434,   447,   400,
     437,   403,   438,    36,   448,   128,   432,   209,   318,   319,
     320,   321,   216,   244,   139,    75,   244,   208,   244,   322,
     323,   324,   421,   422,   411,   414,   243,   418,   308,   274,
     420,     0,    72,     0,     0,   244,   349,     0,    72,    72,
       0,     0,   244,   200,   200,     0,     0,     0,     0,     0,
     431,     0,     0,     0,   265,   417,     0,   265,     0,   265,
       0,     0,     0,     0,   244,   244,    72,    72,   244,     0,
       0,     0,     0,   244,   243,   243,   265,   278,     0,     0,
       0,   284,     0,   265,   285,   286,   287,   288,   289,   290,
     291,   292,   297,     0,     0,     0,     0,     0,   220,     0,
       0,     0,     0,     0,     0,   265,   265,     0,     0,   265,
       0,     0,     0,     0,   265,     0,   221,   222,   223,     0,
     224,     0,   225,   226,     0,     0,   227,   228,    12,     0,
     229,     0,     0,   339,     0,     0,     0,     0,     0,     0,
       0,   230,     0,   343,     0,   231,   232,   233,    66,     5,
       0,     0,     0,   297,   297,     0,     0,     0,     0,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   234,     0,   375,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   220,     0,   237,     0,     0,
     238,     0,     0,     0,     0,   390,   239,   240,     0,     0,
       0,     0,     0,   221,   222,   223,     0,   224,   241,   225,
     226,   242,    -3,   227,   228,    12,     0,   229,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   230,     0,
       0,     0,   231,   232,   233,    66,     5,     0,     0,   343,
       0,     0,     0,   416,     0,     0,     0,     0,     0,   297,
       0,     0,     0,     0,   423,   424,     0,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     235,   236,   220,     0,   237,     0,     0,   238,     0,   339,
       0,     0,     0,   239,   240,     0,     0,     0,     0,   339,
     221,   222,   223,     0,   224,   241,   225,   226,   242,  -130,
     227,   228,    12,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,     0,     0,     0,   231,
     232,   233,    66,     5,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,   234,    57,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   220,
       0,   237,     0,     0,   238,     0,     0,     0,     0,     0,
     239,   240,    66,     0,     0,     0,     0,   221,   222,   223,
       0,   224,   241,   225,   226,   242,   427,   227,   228,    12,
       0,   229,    67,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,     0,     0,     0,   231,   232,   233,    66,
       5,   118,     0,     0,   119,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,   234,     0,     0,    57,     0,     0,
       0,     0,     0,     0,   235,   236,   220,     0,   237,   143,
       0,   238,     0,     0,     0,     0,     0,   239,   240,     0,
       0,    66,     0,     0,   221,   222,   223,     0,   224,   241,
     225,   226,   242,   435,   227,   228,    12,     0,   229,     0,
       0,    67,     0,     0,     0,     0,     0,     0,     0,   230,
       0,     0,     0,   231,   232,   233,    66,     5,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,     0,     0,     0,     0,
       0,   234,    57,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   236,   220,   145,   237,     0,     0,   238,     0,
       0,     0,     0,     0,   239,   240,    66,     0,     0,     0,
       0,   221,   222,   223,     0,   224,   241,   225,   226,   242,
     450,   227,   228,    12,     0,   229,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,     0,     0,     0,
     231,   232,   233,    66,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,   234,     0,
       0,     0,     0,     0,     0,     0,    57,     0,   235,   236,
       0,     0,   237,     0,     0,   238,     0,     0,     0,     0,
       0,   239,   240,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,   241,     0,     0,   242,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      67,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,    58,    59,     0,     0,    60,    61,    62,
      63,     0,   298,    95,   221,   222,   223,     0,   224,     0,
     225,   226,    66,     5,     0,     0,     0,     0,   273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   309,   310,
     311,   312,    67,   231,   232,   233,    66,     0,   313,   314,
     315,   316,   317,     0,     0,   318,   319,   320,   321,     0,
       0,    68,     0,     0,    69,    70,   322,   323,   324,   293,
       0,   234,    71,     0,     0,     0,     0,     0,     0,     0,
     294,   235,   236,     0,    37,   237,     0,     0,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   221,   222,   223,
       0,   224,     0,   225,   226,     0,   241,     0,     0,   242,
     295,   273,     0,     0,     0,     0,     0,     0,     0,     0,
     309,   310,   311,   312,     0,     0,   231,   232,   233,    66,
     313,   314,   315,   316,   317,     0,     0,   318,   319,   320,
     321,     0,     0,     0,     0,     0,     0,     0,   322,   323,
     324,     0,     0,     0,   234,     0,     0,     0,     0,     0,
       0,     0,     0,   397,   235,   236,     0,     0,   237,     0,
       0,   238,     0,     0,     0,     0,     0,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
       0,     0,   242,   352,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    62,    63,     0,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,    66,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,    67,
       0,    57,     0,     0,     0,     0,    58,    59,     0,     0,
      60,    61,    62,    63,     0,     0,    95,     0,    68,     0,
       0,    69,    70,     0,     0,    66,     0,     0,   197,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,     0,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,    68,     0,     0,    69,    70,     0,
       0,    57,     0,     0,     0,    71,    58,    59,     0,     0,
      60,    61,    62,    63,     0,     0,    95,   221,   222,   223,
       0,   224,     0,   225,   226,    66,     0,     0,     0,     0,
       0,   273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,   231,   232,   233,    66,
       5,   221,   222,   223,     0,   224,     0,   225,   226,     0,
       0,     0,     0,     0,    68,   273,     0,    69,    70,     0,
       0,     0,     0,     0,   234,    71,     0,     0,     0,     0,
     231,   232,   233,    66,   235,   236,     0,     0,   237,     0,
       0,   238,     0,     0,     0,     0,     0,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   241,
       0,    37,   242,     0,     0,     0,     0,     0,   235,   236,
       0,     0,   237,     0,     0,   238,     0,     0,     0,     0,
       0,   239,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   241,     0,     0,   242,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,    58,    59,     0,     0,    60,    61,    62,
      63,     0,     0,    95,     0,   309,   310,   311,   312,     0,
       0,     0,    66,     0,     0,   313,   314,   315,   316,   317,
       0,     0,   318,   319,   320,   321,     0,     0,   309,   310,
     311,   312,    67,   322,   323,   324,     0,     0,   313,   314,
     315,   316,   317,     0,   340,   318,   319,   320,   321,     0,
       0,   311,   312,     0,     0,    70,   322,   323,   324,   313,
     314,   315,   316,   317,     0,     0,   318,   319,   320,   321,
       0,     0,     0,   312,     0,     0,     0,   322,   323,   324,
     313,   314,   315,   316,   317,     0,     0,   318,   319,   320,
     321,     0,     0,     0,  -184,     0,     0,     0,   322,   323,
     324,   313,   314,   315,   316,   317,     0,     0,   318,   319,
     320,   321,     0,     0,     0,     0,     0,     0,     0,   322,
     323,   324
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-349)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-184)))

static const yytype_int16 yycheck[] =
{
       3,   249,   124,     6,     7,    33,   148,   242,    36,    37,
     132,    21,    21,    23,     7,    24,    19,   205,    47,   123,
      13,    14,    15,    52,    52,    28,   130,   131,    11,    78,
     218,   219,    44,    52,    52,    58,    49,    51,    51,    62,
      63,    51,     3,    39,    27,    68,    69,    70,    21,    54,
      23,    68,    54,   102,   334,   335,    52,    39,     0,    54,
      30,    51,    54,    33,    34,    35,    59,    60,    61,   304,
      52,    64,    65,    54,   105,    54,     0,     1,    51,    72,
       4,   429,    54,    85,   113,   102,    54,   115,    58,    92,
     113,   439,    62,    63,   113,   113,    77,   111,    68,    69,
      70,    71,   114,   116,     7,   115,    52,    31,    91,    33,
     115,   205,    36,    37,   107,   108,    19,    87,   141,   115,
     115,    51,   125,   115,   218,   219,   406,   407,    52,   386,
     161,   124,   163,   112,   391,   105,   102,   111,   102,   132,
     112,   114,    51,   113,   112,   111,   268,   111,   118,   119,
     173,   174,   294,    51,   177,   249,   179,   180,    78,   167,
     408,   114,   266,   267,   167,   168,   136,   415,   176,   102,
      21,   141,    23,   143,   167,   145,   111,    21,   111,    23,
     188,   190,   175,   176,   441,   188,     0,     1,   111,   113,
       4,   161,   195,   163,    65,   188,    45,    46,   446,   293,
      51,    72,   205,   173,   174,   175,   111,   177,    68,   179,
     180,    23,   205,    25,   184,   218,   219,    31,   227,    33,
     440,   102,    36,    37,   444,   218,   219,   220,   116,    23,
      87,    25,   336,   337,    51,   228,   229,   246,    52,    45,
      46,    33,   102,   205,    36,    37,   249,    72,   105,   437,
     438,   111,   245,   112,   114,   252,   218,   219,    39,   252,
      52,   118,   119,   115,   102,    14,    15,   264,   265,    60,
      61,   264,   265,   111,   114,   268,   114,   114,    68,   136,
     273,   278,   101,   102,   103,   278,   143,   249,   145,    51,
     293,   300,   386,    54,   112,   389,   305,   391,    54,   113,
     293,   324,   112,   112,   161,   112,   163,   115,    51,   114,
     303,    51,    51,    51,   408,   114,   114,   326,   327,    39,
      51,   415,   111,   111,   333,   111,    47,   184,   115,    51,
     115,   293,    68,   115,   304,    51,   111,   111,    51,   112,
     112,   334,   335,   437,   438,    43,   115,   441,   114,   372,
      54,   111,   446,   323,   324,   378,   379,   112,    68,    68,
     112,   112,   112,    44,   334,   335,   112,   115,   115,   378,
     114,   380,   114,    19,   115,    94,   413,   188,    90,    91,
      92,    93,   195,   386,   108,    30,   389,   184,   391,   101,
     102,   103,   401,   402,   387,   389,   389,   395,   259,   225,
     399,    -1,   372,    -1,    -1,   408,   399,    -1,   378,   379,
      -1,    -1,   415,   406,   407,    -1,    -1,    -1,    -1,    -1,
     413,    -1,    -1,    -1,   386,   395,    -1,   389,    -1,   391,
      -1,    -1,    -1,    -1,   437,   438,   406,   407,   441,    -1,
      -1,    -1,    -1,   446,   437,   438,   408,   227,    -1,    -1,
      -1,   231,    -1,   415,   234,   235,   236,   237,   238,   239,
     240,   241,   242,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,   437,   438,    -1,    -1,   441,
      -1,    -1,    -1,    -1,   446,    -1,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,   283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,   293,    -1,    48,    49,    50,    51,    52,
      -1,    -1,    -1,   303,   304,    -1,    -1,    -1,    -1,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,    76,    -1,   325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    87,     1,    -1,    90,    -1,    -1,
      93,    -1,    -1,    -1,    -1,   345,    99,   100,    -1,    -1,
      -1,    -1,    -1,    19,    20,    21,    -1,    23,   111,    25,
      26,   114,   115,    29,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,   389,
      -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,   399,
      -1,    -1,    -1,    -1,   404,   405,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,     1,    -1,    90,    -1,    -1,    93,    -1,   429,
      -1,    -1,    -1,    99,   100,    -1,    -1,    -1,    -1,   439,
      19,    20,    21,    -1,    23,   111,    25,    26,   114,   115,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    87,     1,
      -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,
      99,   100,    51,    -1,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,   111,    25,    26,   114,   115,    29,    30,    31,
      -1,    33,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    90,    -1,    -1,    93,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    87,     1,    -1,    90,    39,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    51,    -1,    -1,    19,    20,    21,    -1,    23,   111,
      25,    26,   114,   115,    29,    30,    31,    -1,    33,    -1,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    87,     1,    39,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    99,   100,    51,    -1,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,   111,    25,    26,   114,
     115,    29,    30,    31,    -1,    33,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    86,    87,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    -1,   111,    -1,    -1,   114,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,
      39,    -1,    47,    42,    19,    20,    21,    -1,    23,    -1,
      25,    26,    51,    52,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    76,    71,    48,    49,    50,    51,    -1,    83,    84,
      85,    86,    87,    -1,    -1,    90,    91,    92,    93,    -1,
      -1,    90,    -1,    -1,    93,    94,   101,   102,   103,    74,
      -1,    76,   101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,   113,    90,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    99,   100,    -1,    19,    20,    21,
      -1,    23,    -1,    25,    26,    -1,   111,    -1,    -1,   114,
     115,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    48,    49,    50,    51,
      83,    84,    85,    86,    87,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    86,    87,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,   115,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      32,    33,    -1,    -1,    36,    37,    38,    39,    -1,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      -1,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    90,    -1,
      -1,    93,    94,    -1,    -1,    51,    -1,    -1,    54,   101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    90,    -1,    -1,    93,    94,    -1,
      -1,    27,    -1,    -1,    -1,   101,    32,    33,    -1,    -1,
      36,    37,    38,    39,    -1,    -1,    42,    19,    20,    21,
      -1,    23,    -1,    25,    26,    51,    -1,    -1,    -1,    -1,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    48,    49,    50,    51,
      52,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    90,    33,    -1,    93,    94,    -1,
      -1,    -1,    -1,    -1,    76,   101,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    86,    87,    -1,    -1,    90,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    99,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,   111,
      -1,   113,   114,    -1,    -1,    -1,    -1,    -1,    86,    87,
      -1,    -1,    90,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    73,    74,    75,    76,    -1,
      -1,    -1,    51,    -1,    -1,    83,    84,    85,    86,    87,
      -1,    -1,    90,    91,    92,    93,    -1,    -1,    73,    74,
      75,    76,    71,   101,   102,   103,    -1,    -1,    83,    84,
      85,    86,    87,    -1,   112,    90,    91,    92,    93,    -1,
      -1,    75,    76,    -1,    -1,    94,   101,   102,   103,    83,
      84,    85,    86,    87,    -1,    -1,    90,    91,    92,    93,
      -1,    -1,    -1,    76,    -1,    -1,    -1,   101,   102,   103,
      83,    84,    85,    86,    87,    -1,    -1,    90,    91,    92,
      93,    -1,    -1,    -1,    76,    -1,    -1,    -1,   101,   102,
     103,    83,    84,    85,    86,    87,    -1,    -1,    90,    91,
      92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   118,    51,     0,    52,   113,   120,   122,   122,
       1,     4,    31,    33,    36,    37,   119,   121,   122,   124,
     128,   130,   133,   134,   166,    21,    23,    51,   114,   129,
      51,   111,   119,   171,   171,   171,   134,   113,   122,   123,
     123,   123,   129,   122,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    27,    32,    33,
      36,    37,    38,    39,    41,    42,    51,    71,    90,    93,
      94,   101,   149,   151,   160,   164,   165,   177,   179,   180,
     181,   182,   183,   184,   186,   187,   188,    51,   149,   149,
     149,    51,   129,   131,   132,    42,   150,   164,   178,   119,
     176,   176,   176,   178,   178,    78,   119,   154,   154,   178,
     178,   178,    49,   116,   149,   185,   102,   154,    90,    93,
     170,   187,   111,   111,   111,   129,   122,   115,   131,   114,
     111,   111,   111,   155,   156,   187,    72,   119,   157,   157,
     178,   116,    51,    39,   187,    39,   187,   112,    39,   119,
     172,   173,   174,   172,   119,   173,   122,   115,   172,   172,
     173,    54,    77,    68,   155,   158,   159,   114,   114,   178,
     187,   187,    51,   125,   125,   112,    54,   112,   112,   112,
     112,   112,   155,   155,    54,   119,   122,   161,   162,   163,
     174,    33,    36,    37,   122,   152,   153,    54,   178,   178,
     119,   126,   178,   174,   178,   114,   178,   178,   158,   161,
     115,   123,    51,    51,    51,   115,   153,    51,   114,   114,
       1,    19,    20,    21,    23,    25,    26,    29,    30,    33,
      44,    48,    49,    50,    76,    86,    87,    90,    93,    99,
     100,   111,   114,   119,   122,   127,   128,   136,   137,   138,
     141,   149,   167,   168,   175,   189,   191,   192,   195,   196,
     197,   198,   199,   200,   201,   203,   111,   111,   111,   175,
     175,   119,   135,    33,   199,   200,   203,   123,   198,    39,
     119,    51,   119,   142,   198,   198,   198,   198,   198,   198,
     198,   198,   198,    74,    85,   115,   190,   198,    47,   119,
     148,   123,   137,   111,   114,   148,   115,    23,   195,    73,
      74,    75,    76,    83,    84,    85,    86,    87,    90,    91,
      92,    93,   101,   102,   103,    68,   148,   148,   172,   172,
     173,   115,   115,   148,    51,    51,   111,   111,   139,   198,
     112,   169,   175,   198,   125,    54,   115,    51,   123,   119,
     190,   202,   115,   149,   190,   193,   194,   123,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   111,   149,   178,   198,   123,   123,   112,   112,
     112,   123,   126,   126,   172,   172,    43,   140,   115,    85,
     198,   114,   112,    68,   115,    54,   115,   116,   178,   111,
     123,   178,   178,   123,    68,    68,   112,   112,   138,    45,
      46,   119,   143,   146,   169,   138,   198,   149,   194,   112,
     202,   123,   123,   198,   198,   126,   126,   115,    44,   144,
      45,   119,   143,   147,   115,   115,   112,   114,   114,   145,
     139,   114,   175,   175,   139,   140,   138,   115,   115,   140,
     115
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

  case 17:

    { yoParserDeclVar(&(yyval), false, &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 18:

    { yoParserDeclVar(&(yyval), true, &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 19:

    {
				yoParserDeclVar(&(yyvsp[(1) - (6)]), true, &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(2) - (6)]), parm, &yyloc);
			}
    break;

  case 20:

    {
				yoParserDeclVar(&(yyvsp[(1) - (6)]), true, &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(6) - (6)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(2) - (6)]), parm, &yyloc);
			}
    break;

  case 21:

    { yoParserDeclType(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 24:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 25:

    { yoParserImport(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 26:

    { (yyval) = (yyvsp[(4) - (5)]); }
    break;

  case 27:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(1) - (2)]), parm, &yyloc); }
    break;

  case 28:

    { yoParserImport(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 30:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 34:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 38:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 39:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 41:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (4)]), parm, &yyloc); yoParserStmtCatch(&(yyval), &(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 42:

    { yoParserStmtReturn(&(yyval), NULL, parm, &yyloc); }
    break;

  case 44:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 45:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 46:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 50:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 52:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 53:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 54:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 55:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 56:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 57:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 58:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); }
    break;

  case 60:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 62:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 64:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 67:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 68:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 69:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 71:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 72:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 73:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 74:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 75:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 77:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 80:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 82:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 83:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 87:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 88:

    { yoParserClass(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 92:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 108:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 109:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 110:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 111:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), false, &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 112:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 113:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 114:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 115:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 118:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 119:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 120:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 121:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 122:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 127:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 128:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 129:

    { yoParserDeclArg(&(yyval), true, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 133:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 134:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 135:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 136:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 139:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 141:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 142:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 143:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 144:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 145:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 151:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 152:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 153:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 154:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 155:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 156:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 157:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 158:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 159:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 160:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 163:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 164:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 165:

    { yoParserTypeStdName(&(yyval), T_UNKNOWN_YET, parm, &yyloc); }
    break;

  case 166:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 167:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 168:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 174:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 175:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 176:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 177:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 178:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 179:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 181:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 182:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 183:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 185:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 186:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 193:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 194:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 195:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 196:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 197:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 198:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 199:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 200:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 201:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 202:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 203:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 204:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XORXOR, parm, &yyloc); }
    break;

  case 205:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
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

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 216:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 218:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 219:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 220:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 221:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 222:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 225:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 226:

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




