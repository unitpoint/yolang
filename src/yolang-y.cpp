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
void yoParserStmtFor(YYSTYPE * r, YYSTYPE * init, YYSTYPE * condition, YYSTYPE * next, YYSTYPE * body, void * parm, YYLTYPE * loc);
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
     T_LOOP = 305,
     T_IN = 306,
     T_IF = 307,
     T_ELSE = 308,
     T_ELSEIF = 309,
     T_CATCH = 310,
     T_SIZEOF = 311,
     T_LNUMBER = 312,
     T_DNUMBER = 313,
     T_NAME = 314,
     T_NEWLINE = 315,
     T_FIX = 316,
     T_POW_ASSIGN = 317,
     T_RSH_ASSIGN = 318,
     T_LSH_ASSIGN = 319,
     T_XOR_ASSIGN = 320,
     T_OR_ASSIGN = 321,
     T_AND_ASSIGN = 322,
     T_MOD_ASSIGN = 323,
     T_CONCAT_ASSIGN = 324,
     T_DIV_ASSIGN = 325,
     T_MUL_ASSIGN = 326,
     T_MINUS_ASSIGN = 327,
     T_PLUS_ASSIGN = 328,
     T_DECL_ASSIGN = 329,
     T_ASSIGN = 330,
     T_INIT_ASSIGN = 331,
     T_PROP_ASSIGN = 332,
     T_XORXOR = 333,
     T_OROR = 334,
     T_ANDAND = 335,
     T_CHAN_ACCESS = 336,
     T_GT = 337,
     T_LT = 338,
     T_GE = 339,
     T_LE = 340,
     T_NE = 341,
     T_EQ = 342,
     T_CONCAT = 343,
     T_XOR = 344,
     T_OR = 345,
     T_MINUS = 346,
     T_PLUS = 347,
     T_RSH = 348,
     T_LSH = 349,
     T_AND = 350,
     T_MOD = 351,
     T_DIV = 352,
     T_MUL = 353,
     T_POW = 354,
     T_AT = 355,
     T_UNARY = 356,
     T_DEC = 357,
     T_INC = 358,
     T_TILDE = 359,
     T_NOT = 360,
     T_DOT = 361,
     T_AS = 362,
     T_INDIRECT = 363,
     T_ADDR = 364,
     T_INDEX = 365,
     T_PTR = 366,
     T_ARR = 367,
     T_DOTNAME = 368,
     NotParen = 369
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
#define YYLAST   1973

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  253
/* YYNRULES -- Number of states.  */
#define YYNSTATES  504

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   369

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     119,   120,     2,     2,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,   121,
       2,     2,     2,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   109,     2,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   122,     2,   123,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   110,   111,   112,   113,   114,   115,   116,   117,   118
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
     110,   112,   114,   118,   122,   125,   130,   133,   135,   137,
     141,   144,   146,   148,   150,   153,   154,   163,   165,   167,
     169,   173,   175,   177,   179,   181,   185,   191,   193,   197,
     198,   205,   206,   211,   212,   218,   220,   223,   225,   230,
     232,   238,   240,   242,   246,   250,   257,   259,   262,   269,
     277,   285,   292,   294,   298,   300,   302,   306,   308,   312,
     315,   317,   319,   321,   325,   332,   335,   337,   339,   342,
     344,   346,   348,   350,   352,   354,   356,   358,   360,   362,
     364,   366,   368,   370,   380,   388,   399,   410,   420,   430,
     440,   447,   452,   454,   456,   459,   463,   466,   470,   475,
     477,   479,   481,   483,   487,   491,   495,   497,   499,   501,
     507,   514,   521,   527,   529,   531,   534,   537,   540,   543,
     546,   549,   553,   555,   557,   562,   564,   567,   569,   571,
     573,   575,   577,   579,   581,   583,   585,   587,   589,   591,
     593,   595,   597,   599,   601,   603,   605,   607,   609,   611,
     613,   615,   617,   619,   623,   626,   630,   634,   639,   644,
     646,   650,   654,   657,   659,   662,   665,   667,   669,   671,
     673,   675,   677,   681,   685,   689,   693,   697,   701,   705,
     709,   713,   717,   721,   725,   729,   733,   737,   741,   745,
     749,   753,   757,   762,   764,   768,   770,   772,   776,   782,
     785,   788,   791,   794,   797,   800,   803,   806,   809,   812,
     816,   818,   820,   825
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     126,     0,    -1,     3,    59,   128,   129,    -1,     1,    -1,
      -1,   130,    -1,   121,   130,    -1,   132,    -1,   127,    -1,
      60,    -1,   130,    -1,   121,    -1,   145,    -1,   132,   145,
      -1,    59,    -1,   133,    62,    59,    -1,   196,    -1,   127,
      -1,    44,    -1,   127,    -1,   137,    -1,   136,    62,   137,
      -1,   135,    59,   134,    -1,   135,    59,   134,    76,   216,
      -1,    33,   136,    -1,    34,    59,   183,    -1,    26,    -1,
      24,    -1,     4,   140,    -1,     4,    59,   140,    -1,     4,
     122,   130,   143,   123,    -1,   140,   130,    -1,    59,   140,
     130,    -1,   142,    -1,   143,   142,    -1,   141,   131,    -1,
     139,   131,    -1,   184,   131,    -1,     1,    -1,   144,    -1,
     130,    -1,   127,    -1,   138,   166,   131,    -1,   185,   166,
     131,    -1,   139,   131,    -1,    32,   216,   166,   131,    -1,
      32,   131,    -1,   159,    -1,   150,    -1,   216,   166,   131,
      -1,     1,   146,    -1,   147,    -1,   130,    -1,   148,    -1,
     149,   148,    -1,    -1,    49,   151,   154,   121,   216,   121,
     152,   158,    -1,   153,    -1,   127,    -1,   216,    -1,   153,
      62,   216,    -1,   138,    -1,   155,    -1,   127,    -1,   156,
      -1,   155,    62,   156,    -1,   127,    59,   134,    76,   216,
      -1,   216,    -1,    48,   149,   123,    -1,    -1,    52,   160,
     157,   158,   164,   165,    -1,    -1,    54,   162,   157,   158,
      -1,    -1,    53,    52,   163,   157,   158,    -1,   161,    -1,
     164,   161,    -1,   127,    -1,    53,   122,   149,   123,    -1,
     127,    -1,    55,    59,   122,   149,   123,    -1,   127,    -1,
      59,    -1,   167,   110,    59,    -1,    47,   122,   123,    -1,
      47,   172,   175,   122,   170,   123,    -1,   171,    -1,   170,
     171,    -1,    37,    59,   119,   190,   120,   131,    -1,    37,
      59,   119,   190,   120,   196,   131,    -1,    41,    59,   119,
     190,   120,   196,   131,    -1,    42,    59,   119,   191,   120,
     131,    -1,   130,    -1,    86,   174,    85,    -1,   127,    -1,
     205,    -1,   205,    76,   173,    -1,   173,    -1,   174,    62,
     173,    -1,    80,   177,    -1,   127,    -1,   173,    -1,   176,
      -1,   177,    62,   176,    -1,    46,   172,   175,   122,   181,
     123,    -1,   192,   131,    -1,   130,    -1,   179,    -1,   180,
     179,    -1,   180,    -1,   127,    -1,   205,    -1,   197,    -1,
     198,    -1,   199,    -1,   201,    -1,   200,    -1,   202,    -1,
     204,    -1,   195,    -1,   182,    -1,   169,    -1,   178,    -1,
      36,    37,   167,   119,   191,    62,     5,   120,   134,    -1,
      36,    37,   167,   119,   190,   120,   134,    -1,    37,   189,
     167,   119,   190,   120,   134,   122,   193,   123,    -1,    41,
     189,   167,   119,   190,   120,   196,   122,   193,   123,    -1,
      42,   189,   167,   119,   191,   120,   122,   193,   123,    -1,
      37,    59,   119,   190,   120,   134,   122,   193,   123,    -1,
      37,   127,   119,   190,   120,   134,   122,   193,   123,    -1,
     122,    93,   190,    93,   187,   123,    -1,   122,    82,   187,
     123,    -1,   216,    -1,   205,    -1,   101,   205,    -1,   101,
      44,   205,    -1,    98,   205,    -1,    98,    44,   205,    -1,
     119,    59,   188,   120,    -1,   127,    -1,   191,    -1,   127,
      -1,   192,    -1,   191,    62,   192,    -1,   127,   133,   196,
      -1,    44,   133,   196,    -1,   149,    -1,   127,    -1,   127,
      -1,    37,   194,   119,   190,   120,    -1,    37,   194,   119,
     190,   120,   196,    -1,    41,   194,   119,   190,   120,   196,
      -1,    42,   194,   119,   191,   120,    -1,   182,    -1,   168,
      -1,    43,   196,    -1,    44,   196,    -1,    35,   196,    -1,
      98,   196,    -1,   101,   196,    -1,   102,   196,    -1,   109,
     124,   196,    -1,    57,    -1,   167,    -1,   109,   203,   124,
     196,    -1,   206,    -1,   167,   172,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    20,    -1,    18,    -1,    19,    -1,    21,    -1,    30,
      -1,    79,    -1,    22,    -1,    23,    -1,    29,    -1,    57,
      -1,    58,    -1,    24,    -1,    26,    -1,   216,    -1,   208,
      62,   216,    -1,   122,   123,    -1,   122,   208,   123,    -1,
     167,   122,   123,    -1,   167,   122,   208,   123,    -1,   167,
     122,   211,   123,    -1,   212,    -1,   211,    62,   212,    -1,
      59,    80,   216,    -1,    28,   217,    -1,   213,    -1,   214,
     213,    -1,   214,    26,    -1,   217,    -1,   215,    -1,   207,
      -1,   167,    -1,   209,    -1,   210,    -1,   216,    90,   216,
      -1,   216,    89,   216,    -1,   216,    88,   216,    -1,   216,
      87,   216,    -1,   216,    86,   216,    -1,   216,    85,   216,
      -1,   216,    95,   216,    -1,   216,    94,   216,    -1,   216,
     101,   216,    -1,   216,   100,   216,    -1,   216,    99,   216,
      -1,   216,   102,   216,    -1,   216,    91,   216,    -1,   216,
      93,   216,    -1,   216,    82,   216,    -1,   216,    98,   216,
      -1,   216,    83,   216,    -1,   216,    92,   216,    -1,   216,
      84,   216,    -1,   216,   110,   167,    -1,   216,   109,   216,
     124,    -1,   218,    -1,   119,   216,   120,    -1,   220,    -1,
     186,    -1,   216,   111,   196,    -1,   216,   110,   119,   196,
     120,    -1,   106,   216,    -1,   105,   216,    -1,    95,   216,
      -1,    94,   216,    -1,   108,   216,    -1,   107,   216,    -1,
      84,   216,    -1,    56,   216,    -1,   101,   216,    -1,    98,
     216,    -1,   216,    76,   216,    -1,   208,    -1,   127,    -1,
     167,   119,   219,   120,    -1,   216,   110,   167,   119,   219,
     120,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   234,   234,   235,   238,   247,   248,   251,   252,   255,
     258,   259,   262,   263,   266,   267,   270,   271,   274,   275,
     278,   279,   282,   283,   290,   293,   296,   297,   300,   301,
     302,   305,   306,   309,   310,   313,   314,   315,   316,   319,
     320,   323,   331,   332,   333,   334,   335,   336,   337,   340,
     341,   344,   345,   348,   349,   365,   365,   370,   371,   374,
     375,   378,   379,   380,   383,   384,   387,   394,   397,   400,
     400,   405,   405,   406,   406,   409,   410,   411,   414,   415,
     418,   419,   422,   423,   426,   429,   432,   433,   436,   437,
     438,   439,   440,   443,   444,   447,   448,   451,   452,   455,
     456,   459,   462,   463,   466,   469,   470,   487,   488,   491,
     492,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     506,   507,   508,   511,   513,   515,   517,   519,   523,   531,
     533,   535,   539,   543,   544,   545,   546,   547,   550,   551,
     554,   555,   558,   559,   562,   563,   566,   567,   576,   579,
     580,   581,   582,   585,   586,   589,   592,   595,   598,   601,
     602,   609,   613,   614,   617,   621,   623,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   646,   647,   648,   649,   650,
     651,   652,   655,   656,   659,   660,   663,   664,   665,   668,
     669,   672,   675,   678,   679,   682,   685,   686,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     722,   723,   724,   725,   726,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   740,   756,
     759,   760,   763,   764
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
  "T_FOR", "T_LOOP", "T_IN", "T_IF", "T_ELSE", "T_ELSEIF", "T_CATCH",
  "T_SIZEOF", "T_LNUMBER", "T_DNUMBER", "T_NAME", "T_NEWLINE", "T_FIX",
  "','", "\"**= (T_POW_ASSIGN)\"", "\">>= (T_RSH_ASSIGN)\"",
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
  "top_stmt_list", "name_list", "type_or_empty", "mut_or_empty",
  "decl_var_list", "decl_var_elem", "decl_var", "decl_type", "const_str",
  "import", "import_body_elem", "import_body", "top_stmt_no_emptyline",
  "top_stmt", "stmt_error_end", "stmt_no_emptyline", "stmt", "stmt_list",
  "for_stmt", "$@1", "for_next", "for_next_list", "for_init",
  "var_assign_list", "var_assign_elem", "if_header", "brace_stmt",
  "if_stmt", "$@2", "elseif", "$@3", "$@4", "elseif_list", "else", "catch",
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
     315,   316,    44,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,    63,
      58,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,    91,
     361,   362,   363,   364,   365,   366,   367,   368,   369,    40,
      41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   125,   126,   126,   127,   128,   128,   129,   129,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   137,   137,   138,   139,   140,   140,   141,   141,
     141,   142,   142,   143,   143,   144,   144,   144,   144,   145,
     145,   146,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   148,   148,   149,   149,   151,   150,   152,   152,   153,
     153,   154,   154,   154,   155,   155,   156,   157,   158,   160,
     159,   162,   161,   163,   161,   164,   164,   164,   165,   165,
     166,   166,   167,   167,   168,   169,   170,   170,   171,   171,
     171,   171,   171,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   177,   177,   178,   179,   179,   180,   180,   181,
     181,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     183,   183,   183,   184,   184,   184,   184,   184,   185,   186,
     186,   186,   187,   188,   188,   188,   188,   188,   189,   189,
     190,   190,   191,   191,   192,   192,   193,   193,   194,   195,
     195,   195,   195,   196,   196,   197,   198,   199,   200,   201,
     201,   202,   203,   203,   204,   205,   205,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   207,   207,   207,   207,   207,
     207,   207,   208,   208,   209,   209,   210,   210,   210,   211,
     211,   212,   213,   214,   214,   215,   216,   216,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   218,
     219,   219,   220,   220
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     5,     2,     3,     1,     1,     2,     3,
       5,     2,     3,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     3,     3,     2,     4,     2,     1,     1,     3,
       2,     1,     1,     1,     2,     0,     8,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     5,     1,     3,     0,
       6,     0,     4,     0,     5,     1,     2,     1,     4,     1,
       5,     1,     1,     3,     3,     6,     1,     2,     6,     7,
       7,     6,     1,     3,     1,     1,     3,     1,     3,     2,
       1,     1,     1,     3,     6,     2,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     9,     7,    10,    10,     9,     9,     9,
       6,     4,     1,     1,     2,     3,     2,     3,     4,     1,
       1,     1,     1,     3,     3,     3,     1,     1,     1,     5,
       6,     6,     5,     1,     1,     2,     2,     2,     2,     2,
       2,     3,     1,     1,     4,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     4,     4,     1,
       3,     3,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     1,     3,     1,     1,     3,     5,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     9,     0,     0,     5,
       6,    38,     0,     0,     0,     4,     4,     4,     8,     2,
      40,     0,     0,     0,    39,    12,     0,    27,    26,     0,
       0,    28,     0,     0,     0,   139,     0,     0,     0,    13,
      11,    10,    36,    35,    37,    29,     0,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   180,
     181,   179,   182,   183,     0,     4,     4,     4,     0,     0,
       4,     4,    82,   184,     0,     0,     0,     0,     4,   121,
     122,   120,    25,   119,   112,   113,   114,   116,   115,   117,
     118,   111,   165,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,   154,   153,   157,   148,     0,     0,     0,
     155,   156,     0,    94,     4,     4,   158,   159,   160,   162,
       0,   163,     0,     0,   166,     4,     0,     0,     0,   133,
       4,     4,     4,     0,    31,    30,    34,     0,     4,     4,
       4,    97,     0,    95,     0,   100,     0,     0,   161,     0,
      83,     0,   141,     0,   140,   142,     0,   136,     0,   134,
     138,     0,   140,     0,     0,     0,    32,    84,     0,     0,
       0,     0,    93,     0,   101,   102,    99,     4,     0,   164,
      14,     0,     0,     4,     4,   137,   135,     4,     4,     0,
       0,   149,     0,   152,    98,    96,     0,   110,   106,   107,
       4,     0,     0,     0,     0,     0,    92,     0,    86,     0,
     145,   144,    17,   124,    16,     0,   143,     0,     0,     0,
     150,   151,   103,   108,   104,   105,     0,     0,     0,    85,
      87,    15,     4,     0,     0,     4,   185,   186,   190,   191,
       0,   187,     0,     4,     4,    55,    69,     0,   188,   189,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,    52,     4,     0,    51,    53,     0,    48,    47,
     209,     4,   236,     0,   208,   210,   211,   203,     0,   207,
       4,   206,   233,   235,     4,     4,     4,   123,     0,     0,
      41,    50,     4,     0,   206,    46,     4,    18,    19,     0,
      24,    20,     0,     0,     4,     0,   246,   245,   242,   241,
     248,   247,   240,   239,   244,   243,     0,     0,     4,   194,
       0,   192,     0,    81,     0,    44,    54,     4,     0,     0,
     127,   205,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,   126,     0,     4,     4,     4,     4,    63,    61,     0,
      62,    64,     0,    67,   234,     0,   132,     0,     0,   195,
       0,    42,   251,   250,     0,    82,   196,     0,     0,   199,
      43,   249,   226,   228,   230,   217,   216,   215,   214,   213,
     212,   224,   229,   225,   219,   218,   227,   222,   221,   220,
     223,     0,     0,   231,   237,    49,     0,     0,     0,    45,
      22,    21,     0,     0,     4,     0,     4,     0,     4,   131,
       0,   193,     0,   252,     0,   197,     0,   198,   232,     0,
       4,    88,     0,     0,    91,     0,     4,     4,     0,     0,
       0,    65,     0,     0,    71,    77,    75,     4,     0,     0,
     201,     0,   200,   238,     0,    89,    90,    23,     0,     0,
       0,     4,    68,    73,     0,     0,    79,    76,    70,   130,
      80,   253,     0,     0,    66,    58,     0,    57,    59,     0,
       0,     0,     0,     0,    56,     0,     0,    72,     0,   128,
     129,    60,    74,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   152,     8,    19,    41,    42,    21,   182,   213,
     299,   300,   301,   263,   264,    99,    23,   100,   101,    24,
      25,   291,   265,   266,   267,   268,   304,   486,   487,   369,
     370,   371,   372,   428,   269,   305,   456,   474,   489,   457,
     478,   324,   270,   103,    79,   207,   208,   114,   174,   142,
     146,   175,   176,    80,   199,   200,   201,   104,    82,    26,
     271,   272,   375,   128,    36,   153,   162,   155,   273,   107,
      83,   214,    84,    85,    86,    87,    88,    89,   122,    90,
      91,    92,   274,   383,   275,   276,   388,   389,   277,   278,
     279,   280,   281,   282,   384,   283
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -377
static const yytype_int16 yypact[] =
{
     219,  -377,    -6,    72,   -22,  -377,  -377,    36,   209,  -377,
    -377,  -377,     9,    42,    67,    21,    21,    21,  -377,  -377,
    -377,   290,   -19,   -19,  -377,  -377,   -19,  -377,  -377,   197,
      36,  -377,  1245,    63,    69,  -377,    63,    63,    63,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,    31,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  1395,  -377,  -377,  -377,  1395,  1395,
      61,    61,  -377,  -377,  1395,  1395,  1395,   -43,   -37,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,    32,   834,    65,    79,    92,   197,    36,
    -377,   -13,    47,  -377,  -377,  -377,  -377,    68,    76,    82,
    -377,  -377,  1113,  -377,   134,   134,  -377,  -377,  -377,  -377,
    1395,   114,   120,   188,  -377,   204,   382,  1018,   129,  -377,
     204,   204,   204,    36,  -377,  -377,  -377,   135,   204,   204,
     204,  -377,   -10,   176,  1113,  -377,   137,   143,  -377,  1395,
    -377,   198,   198,   150,   210,  -377,  1113,  -377,  1113,  -377,
    -377,   151,   214,   157,   198,    14,  -377,  -377,   158,   160,
      17,  1113,  -377,  1113,  -377,  -377,   220,    25,   111,  -377,
    -377,  1320,  1320,  1395,    43,  -377,  -377,  1395,   204,  1395,
     146,   607,  1395,  -377,  -377,  -377,  1113,   198,  -377,  -377,
     -23,   161,   -19,   222,   224,   227,  -377,   -17,  -377,   228,
    -377,  -377,  -377,  -377,  -377,   168,  -377,   171,   173,    60,
    -377,  -377,  -377,  -377,  -377,  -377,   177,   179,   186,  -377,
    -377,  -377,  1395,    60,    60,  -377,  -377,  -377,  -377,  -377,
    1614,  -377,  1561,   263,   249,  -377,  -377,  1614,  -377,  -377,
    1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,
    1421,  -377,  -377,   259,   -19,  -377,  -377,   684,  -377,  -377,
      40,   259,  -377,   192,  -377,  -377,  -377,  -377,   206,  -377,
     467,  -377,  -377,  -377,   204,   204,   204,  -377,   193,   194,
    -377,  -377,  -377,  1777,   207,  -377,   467,  -377,  -377,   264,
     260,  -377,   211,   215,   292,  1614,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,  1738,  1614,   204,  -377,
     -12,  1777,   269,  -377,   -19,  -377,  -377,  1614,  1508,   -19,
    -377,  -377,  -377,  1614,  1614,  1614,  1614,  1614,  1614,  1614,
    1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,  1614,
    1614,  1614,  1614,  1614,    11,  1395,   -19,   213,   216,    18,
    -377,  -377,   -19,  1395,   263,   204,   204,   270,  -377,   217,
     273,  -377,   289,  1777,  -377,   218,  1777,   246,  1614,  -377,
     230,  -377,  -377,   278,   229,   274,  -377,     3,     4,  -377,
    -377,  1777,  1806,  1834,  1862,  1132,  1132,  1132,  1132,  1132,
    1132,   201,   201,   201,   201,   201,    95,    95,    95,    95,
     107,  1655,  1395,   234,  -377,  -377,  1169,  1395,   -19,  -377,
     279,  -377,   238,   239,  1395,  1614,  -377,  1052,    24,  -377,
    1614,  1777,  1052,  -377,  1614,  -377,   301,  -377,  -377,   241,
    1614,  -377,   -19,   -19,  -377,  1614,  1395,  1395,   286,  1698,
     270,  -377,   776,   311,  -377,  -377,  -377,   110,   242,   868,
    1777,   274,  -377,  -377,   244,  -377,  -377,  1777,   245,   247,
    1614,  1614,  -377,  -377,  1614,    -8,  -377,  -377,  -377,  -377,
    -377,  -377,    60,    60,  1777,  -377,   289,   306,  1777,  1614,
     289,  1052,   250,   252,  -377,  1614,   289,  -377,   960,  -377,
    -377,  1777,  -377,  -377
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -377,  -377,    -7,  -377,  -377,    -4,   -11,  -377,   221,  -185,
    -377,  -377,    12,    73,    46,     7,  -377,   280,  -377,  -377,
     359,  -377,  -377,  -260,  -376,  -377,  -377,  -377,  -377,  -377,
    -377,   -44,  -350,  -296,  -377,  -377,   -74,  -377,  -377,  -377,
    -377,  -139,   310,  -377,  -377,  -377,   199,    20,   -50,  -377,
     293,   231,  -377,  -377,   225,  -377,  -377,   377,  -377,  -377,
    -377,  -377,   -20,  -377,   191,   -99,   -98,   -28,  -228,   174,
    -377,   -46,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
     148,  -377,  -377,  -215,  -377,  -377,  -377,   -25,   136,  -377,
    -377,   258,   175,  -377,   -27,  -377
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -203
static const yytype_int16 yytable[] =
{
       9,    18,   217,    10,    20,   288,   289,   326,    35,    35,
      35,    27,    43,    28,   119,    44,    72,    20,   105,    31,
     203,   151,   110,   111,   204,   205,    46,   154,   116,   117,
     118,   161,   163,    27,   165,    28,    45,     6,     6,   168,
     169,     6,   170,     6,   473,   320,    98,   287,   215,   112,
     378,   452,   171,     4,    22,    27,   459,    28,   106,   106,
     106,   235,   141,   113,   113,   378,   436,    22,    29,   151,
      72,   113,     5,   123,   148,   172,   188,   453,   454,   188,
     188,   120,   236,   237,   238,     6,   239,   151,   240,   241,
      98,   115,   242,   243,    13,   134,     6,   244,   124,     7,
    -109,    32,    40,   179,    33,   133,   229,   145,   145,   245,
     135,   379,   246,   387,   491,   498,   247,   248,   249,    72,
       6,   194,    72,   195,   490,   164,   435,   437,    94,   166,
     412,    30,   329,   164,   190,   210,   211,   193,   418,   496,
      34,   356,   123,   218,   250,   220,   221,   112,   203,   202,
     123,   125,   204,   205,   251,   252,   216,   362,   253,   327,
     216,   254,   328,   475,   454,   255,   256,   257,   258,   137,
     197,     6,   202,   198,   206,   123,   212,   164,   420,   259,
     212,   164,   260,    -4,   130,   357,   358,   138,   359,   123,
     494,   225,   326,   164,   497,   139,   198,   352,   131,   326,
     502,   140,   123,   206,   353,   354,   355,    37,    38,    -4,
      11,   132,   261,    12,   144,   262,   353,   354,   355,   377,
       1,    27,     2,    28,   123,   212,   261,   261,   290,   262,
     262,   295,   331,  -202,   240,  -202,   298,   303,   326,   448,
     108,   109,   129,    13,   149,    14,    15,   150,   151,   160,
      16,    17,   173,   325,   492,   493,   323,   180,   167,   177,
     143,   468,   469,   262,   323,   178,   422,   423,   219,     6,
     183,   187,   184,   323,   157,   159,   188,   189,   191,   164,
     192,   226,   196,   227,   224,   303,   228,   231,   232,   323,
      -7,    11,   143,   233,    12,   234,   284,   367,   285,   348,
     349,   350,   351,   352,   185,   286,   186,   297,   302,   414,
     353,   354,   355,   381,   322,   330,   360,   361,   390,   143,
     382,   143,   364,   363,    13,   243,    14,    15,   380,   424,
     365,    16,    17,   416,   366,   426,   417,   427,   425,   430,
     378,   429,    78,    93,   143,   415,    95,    96,    97,   433,
       6,   419,   432,   440,   434,   445,   212,   298,   446,   447,
     461,   463,   470,   473,   481,   479,   439,   482,   495,   483,
     442,   443,   181,   499,    78,   500,   421,   368,    78,    78,
      39,   136,   451,   477,    78,    78,    78,   121,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    78,   441,   230,   444,   147,    81,
     458,   462,    63,   464,   332,   294,     0,   212,     0,   450,
       0,   455,    78,   262,     0,   223,   156,   222,   262,     0,
      78,   465,   466,   382,     0,     0,    78,    78,     0,   212,
     212,    72,     0,     0,     0,     0,     0,     0,   262,     0,
     476,     0,     0,     0,    78,   262,     0,     0,     0,    78,
       0,    73,     0,     0,   485,     0,    78,     0,    78,     0,
       0,     0,     0,     0,     0,   261,   261,     0,   262,   262,
       0,    78,     0,    78,     0,     0,     0,   262,     0,     0,
       0,    78,    78,    78,   262,     0,     0,    78,   293,    78,
     296,    78,    78,     0,     0,   306,    78,     0,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   321,     0,
       0,     0,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,   333,     0,     0,     0,     0,     0,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   373,     0,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,   376,   353,   354,   355,     0,
       0,     0,     0,     0,     0,   321,   321,     0,     0,     0,
       0,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,   431,    63,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,    66,    67,
      68,    69,     0,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   413,    78,    72,     0,     0,     0,
       0,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   449,     0,   235,    73,     0,   376,     0,
       0,     0,   460,     0,     0,     0,     0,     0,   321,     0,
       0,     0,     0,   467,     0,     0,   236,   237,   238,     0,
     239,     0,   240,   241,     0,     0,   242,   243,    13,     0,
       0,   244,    78,     0,     0,     0,    78,    78,   484,   488,
       0,     0,   373,   245,    78,     0,   246,     0,     0,     0,
     247,   248,   249,    72,     6,     0,     0,   373,     0,     0,
       0,     0,     0,   501,     0,     0,    78,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   251,   252,
       0,     0,   253,     0,     0,   254,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,     0,   236,   237,
     238,     0,   239,   259,   240,   241,   260,  -146,   242,   243,
      13,     0,     0,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,     0,   246,     0,
       0,     0,   247,   248,   249,    72,     6,     0,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
     250,     0,     0,     0,    63,     0,     0,     0,     0,   235,
     251,   252,     0,     0,   253,     0,     0,   254,     0,     0,
       0,   255,   256,   257,   258,     0,     0,     0,     0,     0,
     236,   237,   238,    72,   239,   259,   240,   241,   260,   472,
     242,   243,    13,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,   245,     0,     0,
     246,     0,     0,     0,   247,   248,   249,    72,     6,     0,
       0,     0,   126,     0,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   250,     0,     0,     0,     0,     0,     0,     0,
       0,   235,   251,   252,     0,     0,   253,     0,     0,   254,
       0,     0,     0,   255,   256,   257,   258,     0,     0,     0,
       0,     0,   236,   237,   238,     0,   239,   259,   240,   241,
     260,   480,   242,   243,    13,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   245,
       0,     0,   246,     0,     0,     0,   247,   248,   249,    72,
       6,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,   250,     0,     0,     0,    63,     0,
       0,     0,     0,   235,   251,   252,     0,     0,   253,     0,
       0,   254,   158,     0,     0,   255,   256,   257,   258,     0,
       0,     0,     0,     0,   236,   237,   238,    72,   239,   259,
     240,   241,   260,   503,   242,   243,    13,     0,     0,   244,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,   245,     0,     0,   246,     0,     0,     0,   247,   248,
     249,    72,     6,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,   250,     0,     0,     0,
       0,     0,     0,    63,     0,     0,   251,   252,     0,     0,
     253,     0,     0,   254,     0,     0,     0,   255,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   259,    72,     0,   260,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    73,     0,     0,     0,     0,     0,     0,    63,
       0,     0,     0,     0,    64,     0,    65,     0,     0,     0,
      66,    67,    68,    69,     0,     0,   102,  -203,  -203,  -203,
    -203,  -203,  -203,   343,   344,   345,   346,   347,    72,     6,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,   353,   354,   355,     0,     0,     0,     0,    73,     0,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    74,     0,     0,
      75,    76,     0,     0,     0,    63,     0,     0,    77,     0,
      64,     0,    65,     0,     0,     0,    66,    67,    68,    69,
      40,    70,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    74,     0,     0,    75,    76,     0,     0,
      63,     0,     0,     0,    77,    64,     0,    65,     0,     0,
       0,    66,    67,    68,    69,     0,     0,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
       0,     0,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    74,     0,
       0,    75,    76,     0,     0,    63,     0,     0,     0,    77,
      64,     0,    65,     0,     0,     0,    66,    67,    68,    69,
       0,     0,   102,   236,   237,   238,     0,   239,     0,   240,
     241,     0,     0,     0,    72,     0,     0,     0,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,   247,   248,   249,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,    75,    76,     0,     0,
       0,     0,     0,   317,    77,   250,     0,     0,     0,     0,
       0,     0,     0,     0,   318,   251,   252,     0,     0,   253,
       0,     0,   254,     0,     0,     0,   255,   256,   257,   258,
     236,   237,   238,     0,   239,     0,   240,   241,     0,     0,
     259,     0,     0,   260,   319,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   248,   249,   385,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,   237,   238,     0,   239,     0,   240,
     241,     0,   250,     0,     0,     0,     0,     0,   292,     0,
       0,     0,   251,   252,     0,     0,   253,     0,     0,   254,
       0,     0,     0,   255,   256,   257,   258,   247,   248,   249,
      72,     6,     0,     0,     0,     0,     0,   259,     0,     0,
     260,   386,     0,     0,     0,     0,   236,   237,   238,     0,
     239,     0,   240,   241,     0,   250,     0,     0,     0,     0,
       0,   292,     0,     0,     0,   251,   252,     0,     0,   253,
       0,     0,   254,     0,     0,     0,   255,   256,   257,   258,
     247,   248,   249,    72,     0,     0,     0,     0,     0,     0,
     259,     0,    40,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   251,   252,
       0,     0,   253,     0,     0,   254,     0,     0,     0,   255,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
       0,   333,     0,   259,     0,     0,   260,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,     0,     0,   348,   349,   350,   351,   352,     0,     0,
       0,     0,     0,     0,   353,   354,   355,     0,     0,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,   438,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,     0,     0,   348,   349,   350,   351,
     352,     0,     0,     0,     0,     0,     0,   353,   354,   355,
       0,     0,     0,     0,   333,     0,     0,     0,     0,   471,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,     0,     0,   348,   349,   350,   351,
     352,     0,     0,     0,     0,     0,     0,   353,   354,   355,
       0,     0,     0,   333,     0,     0,     0,     0,   374,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,     0,     0,   348,   349,   350,   351,   352,
       0,     0,     0,     0,     0,     0,   353,   354,   355,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,     0,     0,   348,   349,   350,   351,   352,     0,
       0,     0,     0,     0,     0,   353,   354,   355,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
       0,     0,   348,   349,   350,   351,   352,     0,     0,     0,
       0,     0,     0,   353,   354,   355,  -203,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,     0,     0,
     348,   349,   350,   351,   352,     0,     0,     0,     0,     0,
       0,   353,   354,   355
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-377)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-203)))

static const yytype_int16 yycheck[] =
{
       4,     8,   187,     7,     8,   233,   234,   267,    15,    16,
      17,    24,    23,    26,    57,    26,    59,    21,    64,    12,
      37,    44,    68,    69,    41,    42,    30,   125,    74,    75,
      76,   130,   131,    24,   132,    26,    29,    60,    60,   138,
     139,    60,   140,    60,    52,   260,    59,   232,     5,    86,
      62,   427,    62,    59,     8,    24,   432,    26,    65,    66,
      67,     1,   112,    70,    71,    62,    62,    21,    59,    44,
      59,    78,     0,   110,   120,    85,    62,    53,    54,    62,
      62,   124,    22,    23,    24,    60,    26,    44,    28,    29,
      59,    71,    32,    33,    34,    99,    60,    37,    78,   121,
     123,    59,   121,   149,    37,    98,   123,   114,   115,    49,
     123,   123,    52,   328,   122,   491,    56,    57,    58,    59,
      60,   171,    59,   173,   474,   132,   123,   123,    59,   133,
     119,   122,   271,   140,   120,   181,   182,   120,   120,   489,
     119,   280,   110,   189,    84,   191,   192,    86,    37,   177,
     110,   119,    41,    42,    94,    95,   184,   296,    98,   119,
     188,   101,   122,    53,    54,   105,   106,   107,   108,   122,
     177,    60,   200,   177,   178,   110,   183,   184,   363,   119,
     187,   188,   122,   123,   119,   284,   285,   119,   286,   110,
     486,   202,   452,   200,   490,   119,   200,   102,   119,   459,
     496,   119,   110,   207,   109,   110,   111,    16,    17,     0,
       1,   119,   219,     4,    80,   219,   109,   110,   111,   318,
       1,    24,     3,    26,   110,   232,   233,   234,   235,   233,
     234,   242,    26,    26,    28,    28,   243,   244,   498,   424,
      66,    67,    94,    34,   124,    36,    37,    59,    44,   120,
      41,    42,    76,   264,   482,   483,   263,    59,   123,   122,
     112,   446,   447,   267,   271,   122,   365,   366,   122,    60,
     120,   120,    62,   280,   126,   127,    62,   120,   120,   286,
     120,    59,    62,    59,   123,   292,    59,    59,   120,   296,
       0,     1,   144,   122,     4,   122,   119,   304,   119,    98,
      99,   100,   101,   102,   156,   119,   158,    44,    59,   355,
     109,   110,   111,   324,    55,   123,   123,   123,   329,   171,
     327,   173,    62,    59,    34,    33,    36,    37,    59,    59,
     119,    41,    42,   120,   119,    62,   120,    48,   121,    93,
      62,   123,    32,    33,   196,   356,    36,    37,    38,   120,
      60,   362,   122,   119,    80,    76,   363,   364,   120,   120,
      59,   120,    76,    52,   120,   123,   412,   122,    62,   122,
     416,   417,   151,   123,    64,   123,   364,   304,    68,    69,
      21,   101,   426,   457,    74,    75,    76,    77,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    94,   416,   207,   418,   115,    32,
     430,   436,    30,   440,   278,   240,    -1,   424,    -1,   426,
      -1,   428,   112,   427,    -1,   200,    44,   196,   432,    -1,
     120,   442,   443,   440,    -1,    -1,   126,   127,    -1,   446,
     447,    59,    -1,    -1,    -1,    -1,    -1,    -1,   452,    -1,
     457,    -1,    -1,    -1,   144,   459,    -1,    -1,    -1,   149,
      -1,    79,    -1,    -1,   471,    -1,   156,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,   482,   483,    -1,   482,   483,
      -1,   171,    -1,   173,    -1,    -1,    -1,   491,    -1,    -1,
      -1,   181,   182,   183,   498,    -1,    -1,   187,   240,   189,
     242,   191,   192,    -1,    -1,   247,   196,    -1,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   232,    76,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   305,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,   317,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   378,    30,    -1,    -1,
      -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   354,   355,    59,    -1,    -1,    -1,
      -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   425,    -1,     1,    79,    -1,   430,    -1,
      -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,   440,    -1,
      -1,    -1,    -1,   445,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    37,   412,    -1,    -1,    -1,   416,   417,   470,   471,
      -1,    -1,   474,    49,   424,    -1,    52,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    -1,    -1,   489,    -1,    -1,
      -1,    -1,    -1,   495,    -1,    -1,   446,   447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    94,    95,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,   119,    28,    29,   122,   123,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,     1,
      94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,   105,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    59,    26,   119,    28,    29,   122,   123,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    -1,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,   105,   106,   107,   108,    -1,    -1,    -1,
      -1,    -1,    22,    23,    24,    -1,    26,   119,    28,    29,
     122,   123,    32,    33,    34,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    -1,    -1,    -1,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,     1,    94,    95,    -1,    -1,    98,    -1,
      -1,   101,    44,    -1,    -1,   105,   106,   107,   108,    -1,
      -1,    -1,    -1,    -1,    22,    23,    24,    59,    26,   119,
      28,    29,   122,   123,    32,    33,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    94,    95,    -1,    -1,
      98,    -1,    -1,   101,    -1,    -1,    -1,   105,   106,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    59,    -1,   122,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    47,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    59,    60,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,    -1,    -1,    79,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    98,    -1,    -1,
     101,   102,    -1,    -1,    -1,    30,    -1,    -1,   109,    -1,
      35,    -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,
     121,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    98,    -1,    -1,   101,   102,    -1,    -1,
      30,    -1,    -1,    -1,   109,    35,    -1,    37,    -1,    -1,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    98,    -1,
      -1,   101,   102,    -1,    -1,    30,    -1,    -1,    -1,   109,
      35,    -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,
      -1,    -1,    47,    22,    23,    24,    -1,    26,    -1,    28,
      29,    -1,    -1,    -1,    59,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    56,    57,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,   101,   102,    -1,    -1,
      -1,    -1,    -1,    82,   109,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,   106,   107,   108,
      22,    23,    24,    -1,    26,    -1,    28,    29,    -1,    -1,
     119,    -1,    -1,   122,   123,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      29,    -1,    84,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,   105,   106,   107,   108,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,   105,   106,   107,   108,
      56,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,   121,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,    -1,    98,    -1,    -1,   101,    -1,    -1,    -1,   105,
     106,   107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,   119,    -1,    -1,   122,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,   124,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,   121,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    -1,    -1,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,   120,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    -1,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,   126,    59,     0,    60,   121,   128,   130,
     130,     1,     4,    34,    36,    37,    41,    42,   127,   129,
     130,   132,   139,   141,   144,   145,   184,    24,    26,    59,
     122,   140,    59,    37,   119,   127,   189,   189,   189,   145,
     121,   130,   131,   131,   131,   140,   130,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    30,    35,    37,    41,    42,    43,    44,
      46,    47,    59,    79,    98,   101,   102,   109,   167,   169,
     178,   182,   183,   195,   197,   198,   199,   200,   201,   202,
     204,   205,   206,   167,    59,   167,   167,   167,    59,   140,
     142,   143,    47,   168,   182,   196,   127,   194,   194,   194,
     196,   196,    86,   127,   172,   172,   196,   196,   196,    57,
     124,   167,   203,   110,   172,   119,    98,   101,   188,   205,
     119,   119,   119,   140,   130,   123,   142,   122,   119,   119,
     119,   173,   174,   205,    80,   127,   175,   175,   196,   124,
      59,    44,   127,   190,   191,   192,    44,   205,    44,   205,
     120,   190,   191,   190,   127,   191,   130,   123,   190,   190,
     191,    62,    85,    76,   173,   176,   177,   122,   122,   196,
      59,   133,   133,   120,    62,   205,   205,   120,    62,   120,
     120,   120,   120,   120,   173,   173,    62,   127,   130,   179,
     180,   181,   192,    37,    41,    42,   130,   170,   171,    62,
     196,   196,   127,   134,   196,     5,   192,   134,   196,   122,
     196,   196,   176,   179,   123,   131,    59,    59,    59,   123,
     171,    59,   120,   122,   122,     1,    22,    23,    24,    26,
      28,    29,    32,    33,    37,    49,    52,    56,    57,    58,
      84,    94,    95,    98,   101,   105,   106,   107,   108,   119,
     122,   127,   130,   138,   139,   147,   148,   149,   150,   159,
     167,   185,   186,   193,   207,   209,   210,   213,   214,   215,
     216,   217,   218,   220,   119,   119,   119,   134,   193,   193,
     127,   146,    37,   216,   217,   131,   216,    44,   127,   135,
     136,   137,    59,   127,   151,   160,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,    82,    93,   123,
     208,   216,    55,   127,   166,   131,   148,   119,   122,   166,
     123,    26,   213,    76,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    98,    99,
     100,   101,   102,   109,   110,   111,   166,   190,   190,   191,
     123,   123,   166,    59,    62,   119,   119,   127,   138,   154,
     155,   156,   157,   216,   120,   187,   216,   190,    62,   123,
      59,   131,   127,   208,   219,    59,   123,   208,   211,   212,
     131,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   119,   167,   196,   131,   120,   120,   120,   131,
     134,   137,   190,   190,    59,   121,    62,    48,   158,   123,
      93,   216,   122,   120,    80,   123,    62,   123,   124,   196,
     119,   131,   196,   196,   131,    76,   120,   120,   134,   216,
     127,   156,   149,    53,    54,   127,   161,   164,   187,   149,
     216,    59,   212,   120,   219,   131,   131,   216,   134,   134,
      76,   121,   123,    52,   162,    53,   127,   161,   165,   123,
     123,   120,   122,   122,   216,   127,   152,   153,   216,   163,
     157,   122,   193,   193,   158,    62,   157,   158,   149,   123,
     123,   216,   158,   123
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

  case 42:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 43:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 45:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (4)]), parm, &yyloc); yoParserStmtCatch(&(yyval), &(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 46:

    { yoParserStmtReturn(&(yyval), NULL, parm, &yyloc); }
    break;

  case 49:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 50:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 54:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 55:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 56:

    {
				yoParserStmtFor(&(yyval), &(yyvsp[(3) - (8)]), &(yyvsp[(5) - (8)]), &(yyvsp[(7) - (8)]), &(yyvsp[(8) - (8)]), parm, &yyloc); 
			}
    break;

  case 60:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 65:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 66:

    {
				yoParserDeclVar(&(yyvsp[(1) - (5)]), (yyvsp[(1) - (5)]).op == T_MUTABLE, &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(5) - (5)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), parm, &yyloc);
			}
    break;

  case 68:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 69:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 70:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 71:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 72:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 73:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 74:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); }
    break;

  case 76:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 78:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 80:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 83:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 84:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 85:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 87:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 88:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 89:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 90:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 91:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 93:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 96:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 98:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 99:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 103:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 104:

    { yoParserClass(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 108:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 123:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), &(yyvsp[(9) - (9)]), NULL, true, YO_CALLING_C, parm, &yyloc); }
    break;

  case 124:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (7)]), &(yyvsp[(5) - (7)]), &(yyvsp[(7) - (7)]), NULL, false, YO_CALLING_C, parm, &yyloc); }
    break;

  case 125:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 126:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 127:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 128:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), false, &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 129:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 130:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 131:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 132:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 134:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 135:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 136:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 137:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 138:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 143:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 144:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 145:

    { yoParserDeclArg(&(yyval), true, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 151:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 152:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 155:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 156:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 157:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 158:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 159:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 160:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 164:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 166:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 167:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 168:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 169:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 170:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 171:

    { yoParserTypeStdName(&(yyval), T_INT, parm, &yyloc); }
    break;

  case 172:

    { yoParserTypeStdName(&(yyval), T_INTPTR, parm, &yyloc); }
    break;

  case 173:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 174:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 175:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 176:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 177:

    { yoParserTypeStdName(&(yyval), T_UINT, parm, &yyloc); }
    break;

  case 178:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 179:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 180:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 181:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 182:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 183:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 184:

    { yoParserTypeStdName(&(yyval), T_UNKNOWN_YET, parm, &yyloc); }
    break;

  case 185:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 186:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 187:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 193:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 194:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 195:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 196:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 197:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 198:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 200:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 201:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 202:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 204:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 205:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 212:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_EQ, parm, &yyloc); }
    break;

  case 213:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_NE, parm, &yyloc); }
    break;

  case 214:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LE, parm, &yyloc); }
    break;

  case 215:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GE, parm, &yyloc); }
    break;

  case 216:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LT, parm, &yyloc); }
    break;

  case 217:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GT, parm, &yyloc); }
    break;

  case 218:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 219:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 220:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 221:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 222:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 223:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW, parm, &yyloc); }
    break;

  case 224:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 225:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 226:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 227:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 228:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 229:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 230:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 231:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 232:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 234:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 237:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 238:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 239:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INC, parm, &yyloc); }
    break;

  case 240:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_DEC, parm, &yyloc); }
    break;

  case 241:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 242:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 243:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 244:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 245:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 246:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 247:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 248:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 249:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 252:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 253:

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




