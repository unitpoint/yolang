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
#define YYLAST   1925

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  125
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNRULES -- Number of states.  */
#define YYNSTATES  478

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
     110,   112,   114,   118,   122,   125,   130,   133,   135,   139,
     143,   146,   148,   150,   152,   155,   157,   161,   162,   169,
     170,   175,   176,   182,   184,   187,   189,   194,   196,   202,
     204,   206,   210,   214,   221,   223,   226,   233,   241,   249,
     256,   258,   262,   264,   266,   270,   272,   276,   279,   281,
     283,   285,   289,   296,   299,   301,   303,   306,   308,   310,
     312,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   344,   352,   363,   374,   384,   394,   404,   411,
     416,   418,   420,   423,   427,   430,   434,   439,   441,   443,
     445,   447,   451,   455,   459,   461,   463,   465,   471,   478,
     485,   491,   493,   495,   498,   501,   504,   507,   510,   513,
     517,   519,   521,   526,   528,   531,   533,   535,   537,   539,
     541,   543,   545,   547,   549,   551,   553,   555,   557,   559,
     561,   563,   565,   567,   569,   571,   573,   575,   577,   579,
     581,   583,   587,   590,   594,   598,   603,   608,   610,   614,
     618,   621,   623,   626,   629,   631,   633,   635,   637,   639,
     641,   645,   649,   653,   657,   661,   665,   669,   673,   677,
     681,   685,   689,   693,   697,   701,   705,   709,   713,   717,
     721,   726,   728,   732,   734,   736,   740,   746,   749,   752,
     755,   758,   761,   764,   767,   770,   774,   776,   778,   783
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     126,     0,    -1,     3,    59,   128,   129,    -1,     1,    -1,
      -1,   130,    -1,   121,   130,    -1,   132,    -1,   127,    -1,
      60,    -1,   130,    -1,   121,    -1,   145,    -1,   132,   145,
      -1,    59,    -1,   133,    62,    59,    -1,   189,    -1,   127,
      -1,    44,    -1,   127,    -1,   137,    -1,   136,    62,   137,
      -1,   135,    59,   134,    -1,   135,    59,   134,    76,   209,
      -1,    33,   136,    -1,    34,    59,   176,    -1,    26,    -1,
      24,    -1,     4,   140,    -1,     4,    59,   140,    -1,     4,
     122,   130,   143,   123,    -1,   140,   130,    -1,    59,   140,
     130,    -1,   142,    -1,   143,   142,    -1,   141,   131,    -1,
     139,   131,    -1,   177,   131,    -1,     1,    -1,   144,    -1,
     130,    -1,   127,    -1,   138,   159,   131,    -1,   178,   159,
     131,    -1,   139,   131,    -1,    32,   209,   159,   131,    -1,
      32,   131,    -1,   152,    -1,   211,   159,   131,    -1,   213,
     159,   131,    -1,     1,   146,    -1,   147,    -1,   130,    -1,
     148,    -1,   149,   148,    -1,   209,    -1,    48,   149,   123,
      -1,    -1,    52,   153,   150,   151,   157,   158,    -1,    -1,
      54,   155,   150,   151,    -1,    -1,    53,    52,   156,   150,
     151,    -1,   154,    -1,   157,   154,    -1,   127,    -1,    53,
     122,   149,   123,    -1,   127,    -1,    55,    59,   122,   149,
     123,    -1,   127,    -1,    59,    -1,   160,   110,    59,    -1,
      47,   122,   123,    -1,    47,   165,   168,   122,   163,   123,
      -1,   164,    -1,   163,   164,    -1,    37,    59,   119,   183,
     120,   131,    -1,    37,    59,   119,   183,   120,   189,   131,
      -1,    41,    59,   119,   183,   120,   189,   131,    -1,    42,
      59,   119,   184,   120,   131,    -1,   130,    -1,    86,   167,
      85,    -1,   127,    -1,   198,    -1,   198,    76,   166,    -1,
     166,    -1,   167,    62,   166,    -1,    80,   170,    -1,   127,
      -1,   166,    -1,   169,    -1,   170,    62,   169,    -1,    46,
     165,   168,   122,   174,   123,    -1,   185,   131,    -1,   130,
      -1,   172,    -1,   173,   172,    -1,   173,    -1,   127,    -1,
     198,    -1,   190,    -1,   191,    -1,   192,    -1,   194,    -1,
     193,    -1,   195,    -1,   197,    -1,   188,    -1,   175,    -1,
     162,    -1,   171,    -1,    36,    37,   160,   119,   184,    62,
       5,   120,   134,    -1,    36,    37,   160,   119,   183,   120,
     134,    -1,    37,   182,   160,   119,   183,   120,   134,   122,
     186,   123,    -1,    41,   182,   160,   119,   183,   120,   189,
     122,   186,   123,    -1,    42,   182,   160,   119,   184,   120,
     122,   186,   123,    -1,    37,    59,   119,   183,   120,   134,
     122,   186,   123,    -1,    37,   127,   119,   183,   120,   134,
     122,   186,   123,    -1,   122,    93,   183,    93,   180,   123,
      -1,   122,    82,   180,   123,    -1,   209,    -1,   198,    -1,
     101,   198,    -1,   101,    44,   198,    -1,    98,   198,    -1,
      98,    44,   198,    -1,   119,    59,   181,   120,    -1,   127,
      -1,   184,    -1,   127,    -1,   185,    -1,   184,    62,   185,
      -1,   127,   133,   189,    -1,    44,   133,   189,    -1,   149,
      -1,   127,    -1,   127,    -1,    37,   187,   119,   183,   120,
      -1,    37,   187,   119,   183,   120,   189,    -1,    41,   187,
     119,   183,   120,   189,    -1,    42,   187,   119,   184,   120,
      -1,   175,    -1,   161,    -1,    43,   189,    -1,    44,   189,
      -1,    35,   189,    -1,    98,   189,    -1,   101,   189,    -1,
     102,   189,    -1,   109,   124,   189,    -1,    57,    -1,   160,
      -1,   109,   196,   124,   189,    -1,   199,    -1,   160,   165,
      -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,
      -1,    11,    -1,    12,    -1,    13,    -1,    14,    -1,    15,
      -1,    16,    -1,    17,    -1,    20,    -1,    18,    -1,    19,
      -1,    21,    -1,    30,    -1,    79,    -1,    22,    -1,    23,
      -1,    29,    -1,    57,    -1,    58,    -1,    24,    -1,    26,
      -1,   209,    -1,   201,    62,   209,    -1,   122,   123,    -1,
     122,   201,   123,    -1,   160,   122,   123,    -1,   160,   122,
     201,   123,    -1,   160,   122,   204,   123,    -1,   205,    -1,
     204,    62,   205,    -1,    59,    80,   209,    -1,    28,   210,
      -1,   206,    -1,   207,   206,    -1,   207,    26,    -1,   210,
      -1,   208,    -1,   200,    -1,   160,    -1,   202,    -1,   203,
      -1,   209,    90,   209,    -1,   209,    89,   209,    -1,   209,
      88,   209,    -1,   209,    87,   209,    -1,   209,    86,   209,
      -1,   209,    85,   209,    -1,   209,    95,   209,    -1,   209,
      94,   209,    -1,   209,   101,   209,    -1,   209,   100,   209,
      -1,   209,    99,   209,    -1,   209,   102,   209,    -1,   209,
      91,   209,    -1,   209,    93,   209,    -1,   209,    82,   209,
      -1,   209,    98,   209,    -1,   209,    83,   209,    -1,   209,
      92,   209,    -1,   209,    84,   209,    -1,   209,   110,   160,
      -1,   209,   109,   209,   124,    -1,   211,    -1,   119,   209,
     120,    -1,   213,    -1,   179,    -1,   209,   111,   189,    -1,
     209,   110,   119,   189,   120,    -1,    95,   209,    -1,    94,
     209,    -1,   108,   209,    -1,   107,   209,    -1,    84,   209,
      -1,    56,   209,    -1,   101,   209,    -1,    98,   209,    -1,
     209,    76,   209,    -1,   201,    -1,   127,    -1,   160,   119,
     212,   120,    -1,   209,   110,   160,   119,   212,   120,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   233,   233,   234,   237,   246,   247,   250,   251,   254,
     257,   258,   261,   262,   265,   266,   269,   270,   273,   274,
     277,   278,   281,   282,   289,   292,   295,   296,   299,   300,
     301,   304,   305,   308,   309,   312,   313,   314,   315,   318,
     319,   322,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   341,   342,   345,   346,   362,   365,   368,   368,   373,
     373,   374,   374,   377,   378,   379,   382,   383,   386,   387,
     390,   391,   394,   397,   400,   401,   404,   405,   406,   407,
     408,   411,   412,   415,   416,   419,   420,   423,   424,   427,
     430,   431,   434,   437,   438,   455,   456,   459,   460,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   474,   475,
     476,   479,   481,   483,   485,   487,   491,   499,   501,   503,
     507,   511,   512,   513,   514,   515,   518,   519,   522,   523,
     526,   527,   530,   531,   534,   535,   544,   547,   548,   549,
     550,   553,   554,   557,   560,   563,   566,   569,   570,   577,
     581,   582,   585,   589,   591,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   614,   615,   616,   617,   618,   619,   620,
     623,   624,   627,   628,   631,   632,   633,   636,   637,   640,
     643,   646,   647,   650,   653,   654,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   690,   691,
     692,   693,   694,   695,   696,   697,   698,   699,   700,   701,
     702,   703,   704,   705,   706,   722,   725,   726,   729,   730
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
  "if_header", "brace_stmt", "if_stmt", "$@1", "elseif", "$@2", "$@3",
  "elseif_list", "else", "catch", "dotname", "type_contract_empty",
  "type_contract", "contract_body", "contract_decl_func", "template",
  "template_arg", "template_arg_list", "extends", "extends_elem",
  "extends_list", "type_class", "class_body_stmt", "class_body_stmt_list",
  "class_body", "type_base", "type_ext", "top_decl_func", "decl_func",
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
     147,   148,   148,   149,   149,   150,   151,   153,   152,   155,
     154,   156,   154,   157,   157,   157,   158,   158,   159,   159,
     160,   160,   161,   162,   163,   163,   164,   164,   164,   164,
     164,   165,   165,   166,   166,   167,   167,   168,   168,   169,
     170,   170,   171,   172,   172,   173,   173,   174,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   176,
     176,   177,   177,   177,   177,   177,   178,   179,   179,   179,
     180,   181,   181,   181,   181,   181,   182,   182,   183,   183,
     184,   184,   185,   185,   186,   186,   187,   188,   188,   188,
     188,   189,   189,   190,   191,   192,   193,   194,   194,   195,
     196,   196,   197,   198,   198,   199,   199,   199,   199,   199,
     199,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   200,   200,   200,   200,   200,
     201,   201,   202,   202,   203,   203,   203,   204,   204,   205,
     206,   207,   207,   208,   209,   209,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   211,   212,   212,   213,   213
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     5,     2,     3,     1,     1,     2,     3,
       5,     2,     3,     1,     2,     2,     2,     2,     1,     1,
       1,     1,     3,     3,     2,     4,     2,     1,     3,     3,
       2,     1,     1,     1,     2,     1,     3,     0,     6,     0,
       4,     0,     5,     1,     2,     1,     4,     1,     5,     1,
       1,     3,     3,     6,     1,     2,     6,     7,     7,     6,
       1,     3,     1,     1,     3,     1,     3,     2,     1,     1,
       1,     3,     6,     2,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     9,     7,    10,    10,     9,     9,     9,     6,     4,
       1,     1,     2,     3,     2,     3,     4,     1,     1,     1,
       1,     3,     3,     3,     1,     1,     1,     5,     6,     6,
       5,     1,     1,     2,     2,     2,     2,     2,     2,     3,
       1,     1,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     4,     4,     1,     3,     3,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     1,     3,     1,     1,     3,     5,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     0,     1,     9,     0,     0,     5,
       6,    38,     0,     0,     0,     4,     4,     4,     8,     2,
      40,     0,     0,     0,    39,    12,     0,    27,    26,     0,
       0,    28,     0,     0,     0,   127,     0,     0,     0,    13,
      11,    10,    36,    35,    37,    29,     0,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   168,
     169,   167,   170,   171,     0,     4,     4,     4,     0,     0,
       4,     4,    70,   172,     0,     0,     0,     0,     4,   109,
     110,   108,    25,   107,   100,   101,   102,   104,   103,   105,
     106,    99,   153,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,   142,   141,   145,   136,     0,     0,     0,
     143,   144,     0,    82,     4,     4,   146,   147,   148,   150,
       0,   151,     0,     0,   154,     4,     0,     0,     0,   121,
       4,     4,     4,     0,    31,    30,    34,     0,     4,     4,
       4,    85,     0,    83,     0,    88,     0,     0,   149,     0,
      71,     0,   129,     0,   128,   130,     0,   124,     0,   122,
     126,     0,   128,     0,     0,     0,    32,    72,     0,     0,
       0,     0,    81,     0,    89,    90,    87,     4,     0,   152,
      14,     0,     0,     4,     4,   125,   123,     4,     4,     0,
       0,   137,     0,   140,    86,    84,     0,    98,    94,    95,
       4,     0,     0,     0,     0,     0,    80,     0,    74,     0,
     133,   132,    17,   112,    16,     0,   131,     0,     0,     0,
     138,   139,    91,    96,    92,    93,     0,     0,     0,    73,
      75,    15,     4,     0,     0,     4,   173,   174,   178,   179,
       0,   175,     0,     4,     4,    57,     0,   176,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,    52,
       4,     0,    51,    53,     0,    47,   197,     4,   224,     0,
     196,   198,   199,   191,     0,   195,     0,   194,   221,   223,
       4,     4,     4,   111,     0,     0,    41,    50,     4,   194,
     221,   223,    46,     4,    18,    19,     0,    24,    20,     0,
       0,     0,   232,   231,   228,   227,   234,   233,   230,   229,
       0,     0,     4,   182,     0,   180,     0,    69,     0,    44,
      54,     4,     0,     0,   115,   193,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     4,     4,
       4,     4,     0,    55,   222,     0,   120,     0,     0,   183,
       0,    42,   237,   236,     0,    70,   184,     0,     0,   187,
      43,   235,   214,   216,   218,   205,   204,   203,   202,   201,
     200,   212,   217,   213,   207,   206,   215,   210,   209,   208,
     211,     0,     0,   219,   225,    48,    49,     0,     0,     0,
      45,    22,    21,     0,     0,     0,     4,   119,     0,   181,
       0,   238,     0,   185,     0,   186,   220,     0,     4,    76,
       0,     0,    79,     0,     4,     4,     0,     0,    59,    65,
      63,     4,     0,     0,   189,     0,   188,   226,     0,    77,
      78,    23,     0,     0,    56,    61,     0,     0,    67,    64,
      58,   118,    68,   239,     0,     0,     0,     0,     0,     0,
       0,     0,    60,     0,   116,   117,    62,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,   152,     8,    19,    41,    42,    21,   182,   213,
     296,   297,   298,   260,   261,    99,    23,   100,   101,    24,
      25,   287,   262,   263,   264,   362,   416,   265,   301,   440,
     456,   466,   441,   460,   318,   266,   103,    79,   207,   208,
     114,   174,   142,   146,   175,   176,    80,   199,   200,   201,
     104,    82,    26,   267,   268,   365,   128,    36,   153,   162,
     155,   269,   107,    83,   214,    84,    85,    86,    87,    88,
      89,   122,    90,    91,    92,   270,   373,   271,   272,   378,
     379,   273,   274,   275,   276,   277,   290,   374,   291
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -365
static const yytype_int16 yypact[] =
{
     161,  -365,   -34,    30,   -16,  -365,  -365,    10,   414,  -365,
    -365,  -365,    15,    44,    85,    58,    58,    58,  -365,  -365,
    -365,   442,     2,     2,  -365,  -365,     2,  -365,  -365,   210,
      10,  -365,  1114,    75,   111,  -365,    75,    75,    75,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,    76,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  1264,  -365,  -365,  -365,  1264,  1264,
      39,    39,  -365,  -365,  1264,  1264,  1264,   -12,   -31,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,    66,  1410,    82,    88,   102,   210,    10,
    -365,   -13,    73,  -365,  -365,  -365,  -365,    69,    86,    94,
    -365,  -365,  1748,  -365,   157,   157,  -365,  -365,  -365,  -365,
    1264,   135,   123,   196,  -365,   207,  1640,  1694,   141,  -365,
     207,   207,   207,    10,  -365,  -365,  -365,   139,   207,   207,
     207,  -365,    51,   189,  1748,  -365,   146,   148,  -365,  1264,
    -365,   212,   212,   154,   213,  -365,  1748,  -365,  1748,  -365,
    -365,   158,   215,   162,   212,   -56,  -365,  -365,   163,   166,
      27,  1748,  -365,  1748,  -365,  -365,   225,    96,    90,  -365,
    -365,  1189,  1189,  1264,    54,  -365,  -365,  1264,   207,  1264,
     159,  1586,  1264,  -365,  -365,  -365,  1748,   212,  -365,  -365,
     -29,   167,     2,   230,   232,   233,  -365,     1,  -365,   236,
    -365,  -365,  -365,  -365,  -365,   176,  -365,   180,   181,    59,
    -365,  -365,  -365,  -365,  -365,  -365,   185,   188,   191,  -365,
    -365,  -365,  1264,    59,    59,  -365,  -365,  -365,  -365,  -365,
    1469,  -365,  1423,   264,   253,  -365,  1469,  -365,  -365,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1290,  -365,  -365,
     258,     2,  -365,  -365,   614,  -365,    53,   258,  -365,   193,
    -365,  -365,  -365,  -365,   218,  -365,  1785,  -365,    -7,    -7,
     207,   207,   207,  -365,   200,   201,  -365,  -365,  -365,   226,
    -365,  -365,  -365,   461,  -365,  -365,   255,   260,  -365,   216,
     217,  1469,   117,   117,   117,   117,   117,   117,   117,   117,
    1746,  1469,   207,  -365,     3,  1785,   256,  -365,     2,  -365,
    -365,  1469,  1377,     2,  -365,  -365,  -365,  1469,  1469,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,     9,  1264,
       2,     2,   211,   214,    28,  -365,  -365,     2,  1264,   264,
     207,   207,   289,  1785,  -365,   221,  1785,   245,  1469,  -365,
     227,  -365,  -365,   278,   228,   270,  -365,     7,    16,  -365,
    -365,  1785,  1814,  1587,  1641,  1001,  1001,  1001,  1001,  1001,
    1001,   219,   219,   219,   219,   219,   100,   100,   100,   100,
     117,  1699,  1264,   234,  -365,  -365,  -365,  1038,  1264,     2,
    -365,   275,  -365,   238,   239,   921,   164,  -365,  1469,  1785,
     921,  -365,  1469,  -365,   293,  -365,  -365,   240,  1469,  -365,
       2,     2,  -365,  1469,  1264,  1264,   723,   302,  -365,  -365,
    -365,   169,   243,   776,  1785,   270,  -365,  -365,   241,  -365,
    -365,  1785,   247,   249,  -365,  -365,  1469,   -36,  -365,  -365,
    -365,  -365,  -365,  -365,    59,    59,  1469,   289,   921,   251,
     252,   289,  -365,   868,  -365,  -365,  -365,  -365
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -365,  -365,     6,  -365,  -365,    -4,   -18,  -365,   205,  -178,
    -365,  -365,     4,  -365,   147,     8,  -365,   279,  -365,  -365,
     355,  -365,  -365,  -257,  -364,  -295,  -280,  -365,  -365,   -62,
    -365,  -365,  -365,  -365,  -134,   309,  -365,  -365,  -365,   174,
      87,   -72,  -365,   267,   194,  -365,  -365,   187,  -365,  -365,
     356,  -365,  -365,  -365,  -365,   -26,  -365,    91,   -81,  -113,
      20,  -232,   192,  -365,   -40,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,   199,  -365,  -365,  -247,  -365,  -365,  -365,
     -30,   119,  -365,  -365,   257,   156,  -201,   -28,  -167
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -191
static const yytype_int16 yytable[] =
{
       9,   284,   285,    10,    20,    43,   188,   320,    44,   217,
     314,    27,   154,    28,    18,   151,   455,    20,   278,   165,
      31,    35,    35,    35,   105,     4,    46,   170,   110,   111,
       5,     6,   278,   278,   116,   117,   118,    45,   203,    27,
     141,    28,   204,   205,     6,   119,    98,    72,   316,   161,
     163,   436,   279,    -4,   283,   112,   443,   168,   169,   215,
     235,     6,     6,   278,   190,   368,   279,   279,    72,   368,
       6,   106,   106,   106,    29,   377,   113,   113,   424,   123,
     148,   236,   237,   238,   113,   239,   468,   240,   241,   188,
     188,   242,   243,    13,   -97,   134,   244,   279,   151,   194,
      27,   195,    28,    32,   473,     7,   133,    37,    38,   179,
     135,   245,   120,   171,    -4,   246,   247,   248,    72,     6,
     145,   145,    33,    40,   229,   112,   369,   203,   402,   166,
     423,   204,   205,   323,    72,    98,   172,    30,   164,   425,
     151,   210,   211,   249,   350,   351,   164,   193,   409,   218,
       6,   220,   221,   250,   251,    22,     6,   252,   115,   357,
     253,   467,     1,   123,     2,   124,   254,   255,    22,   354,
      94,   471,   321,   198,   206,   322,   123,    34,   256,   320,
     411,   257,    -4,   197,   225,   125,   320,   472,   138,   212,
     164,   476,   123,   212,   164,   137,   198,   202,   123,   352,
     353,   130,   346,   206,   216,   139,   164,   131,   216,   347,
     348,   349,   123,   140,   278,   259,   320,   437,   438,   278,
     202,   132,   457,   438,   292,   258,   347,   348,   349,   259,
     259,   367,   469,   470,    27,   278,    28,   144,   212,   258,
     258,   286,   278,   319,   325,   123,   240,   149,   279,   295,
     300,   151,  -190,   279,  -190,   150,   452,   453,   108,   109,
     259,   160,   167,   278,   278,   173,   317,   278,   177,   279,
     178,   180,   278,   317,   183,   184,   279,   188,   187,   413,
     414,   219,   189,   191,   317,   317,   192,   196,   164,   226,
     224,   227,   228,   129,   300,   231,   232,   279,   279,   317,
     371,   279,   233,   234,   280,   380,   279,   281,   294,   404,
     282,   143,   299,   316,   358,   370,   324,   342,   343,   344,
     345,   346,   359,   355,   356,   157,   159,   372,   347,   348,
     349,   407,   405,   406,   408,   360,   361,   415,   418,   410,
     368,    78,    93,   143,   417,    95,    96,    97,   421,   420,
     422,   433,   445,   428,   455,   185,   181,   186,   434,   435,
     447,   463,   427,   412,   212,   295,   461,   430,   431,   464,
     143,   465,   143,    78,   474,   475,    39,    78,    78,   459,
     136,   230,   147,    78,    78,    78,   121,   223,    81,   429,
     222,   432,   442,   326,   446,   143,   289,     0,     0,     0,
     448,     0,     0,    78,     0,     0,     0,     0,     0,     0,
       0,   259,   449,   450,    -4,    11,   259,     0,    12,     0,
       0,    78,   439,     0,     0,     0,     0,     0,     0,    78,
       0,     0,   259,     0,   372,    78,    78,     0,     0,   259,
     212,   212,    -7,    11,     0,     0,    12,   458,    13,     0,
      14,    15,     0,    78,     0,    16,    17,     0,    78,     0,
     259,   259,     0,     0,   259,    78,     0,    78,     0,   259,
     258,   258,     0,     0,     6,     0,    13,     0,    14,    15,
      78,     0,    78,    16,    17,     0,     0,     0,     0,     0,
      78,    78,    78,     0,     0,     0,    78,     0,    78,   293,
      78,    78,     6,   302,     0,    78,   303,   304,   305,   306,
     307,   308,   309,   310,   315,     0,   316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,     0,     0,
       0,    78,     0,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   363,   342,
     343,   344,   345,   346,     0,     0,     0,     0,   366,     0,
     347,   348,   349,     0,     0,     0,     0,     0,   315,   315,
       0,     0,     0,     0,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   419,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   237,   238,     0,
     239,     0,   240,   241,     0,     0,   242,   243,    13,     0,
       0,   244,     0,     0,     0,     0,     0,   403,    78,     0,
       0,     0,     0,     0,     0,     0,   245,    78,     0,     0,
     246,   247,   248,    72,     6,   366,     0,     0,     0,   444,
       0,     0,     0,     0,     0,   315,     0,     0,     0,     0,
     451,     0,     0,     0,     0,     0,     0,     0,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
       0,    78,   252,   363,     0,   253,    78,    78,     0,     0,
       0,   254,   255,   363,   235,     0,     0,     0,     0,     0,
       0,     0,     0,   256,     0,     0,   257,  -134,     0,     0,
       0,     0,     0,    78,    78,   236,   237,   238,     0,   239,
       0,   240,   241,     0,     0,   242,   243,    13,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   245,     0,   235,     0,   246,
     247,   248,    72,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     238,     0,   239,     0,   240,   241,     0,   249,   242,   243,
      13,     0,     0,   244,     0,     0,     0,   250,   251,     0,
       0,   252,     0,     0,   253,     0,     0,     0,   245,     0,
     254,   255,   246,   247,   248,    72,     6,     0,     0,     0,
       0,     0,   256,     0,     0,   257,   454,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,   235,
     250,   251,     0,     0,   252,     0,     0,   253,     0,     0,
       0,     0,     0,   254,   255,     0,     0,     0,     0,     0,
     236,   237,   238,     0,   239,   256,   240,   241,   257,   462,
     242,   243,    13,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     245,     0,   235,     0,   246,   247,   248,    72,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   236,   237,   238,     0,   239,     0,   240,
     241,     0,   249,   242,   243,    13,     0,     0,   244,     0,
       0,     0,   250,   251,     0,     0,   252,     0,     0,   253,
       0,     0,     0,   245,     0,   254,   255,   246,   247,   248,
      72,     6,     0,     0,     0,     0,     0,   256,     0,     0,
     257,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   250,   251,     0,     0,   252,
       0,     0,   253,     0,     0,     0,     0,     0,   254,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,   257,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,    64,     0,    65,     0,     0,     0,    66,
      67,    68,    69,     0,     0,   102,  -191,  -191,  -191,  -191,
    -191,  -191,   337,   338,   339,   340,   341,    72,     6,   342,
     343,   344,   345,   346,     0,     0,     0,     0,     0,     0,
     347,   348,   349,     0,     0,     0,     0,    73,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    74,     0,     0,    75,
      76,     0,     0,     0,    63,     0,     0,    77,     0,    64,
       0,    65,     0,     0,     0,    66,    67,    68,    69,    40,
      70,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    74,     0,     0,    75,    76,     0,     0,    63,
       0,     0,     0,    77,    64,     0,    65,     0,     0,     0,
      66,    67,    68,    69,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,     0,
       0,   209,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    74,     0,     0,
      75,    76,     0,     0,    63,     0,     0,     0,    77,    64,
       0,    65,     0,     0,     0,    66,    67,    68,    69,     0,
       0,   102,   236,   237,   238,     0,   239,     0,   240,   241,
       0,     0,     0,    72,     0,     0,     0,   288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,   246,   247,   248,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,    75,    76,     0,     0,     0,
       0,     0,   311,    77,   249,     0,     0,     0,     0,     0,
       0,     0,     0,   312,   250,   251,     0,     0,   252,     0,
       0,   253,     0,     0,     0,     0,     0,   254,   255,   236,
     237,   238,     0,   239,     0,   240,   241,     0,     0,   256,
       0,     0,   257,   313,   288,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,   246,   247,   248,   375,     0,     0,     0,
      63,     0,     0,     0,     0,   236,   237,   238,     0,   239,
       0,   240,   241,     0,     0,     0,     0,     0,     0,     0,
     288,   249,     0,     0,     0,     0,     0,     0,     0,    72,
       0,   250,   251,     0,     0,   252,     0,     0,   253,   246,
     247,   248,    72,     6,   254,   255,     0,     0,     0,    73,
       0,   236,   237,   238,     0,   239,   256,   240,   241,   257,
     376,     0,     0,     0,     0,     0,   288,   249,   126,     0,
       0,   127,     0,     0,     0,     0,     0,   250,   251,     0,
       0,   252,     0,     0,   253,   246,   247,   248,    72,     0,
     254,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,    40,   257,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   250,   251,     0,     0,   252,     0,     0,
     253,     0,     0,     0,     0,     0,   254,   255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,   257,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,    64,     0,    65,     0,     0,     0,    66,    67,    68,
      69,     0,     0,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,     0,     0,    73,     0,     0,     0,     0,
      63,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,     0,   156,   342,   343,   344,   345,   346,
       0,     0,     0,     0,     0,     0,   347,   348,   349,    72,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,     0,    73,
       0,     0,     0,     0,    63,  -191,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     0,   158,   342,
     343,   344,   345,   346,     0,     0,     0,     0,     0,     0,
     347,   348,   349,    72,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,     0,     0,    73,     0,   327,     0,     0,    63,     0,
       0,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,     0,     0,   342,   343,   344,
     345,   346,     0,     0,     0,     0,     0,    72,   347,   348,
     349,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   327,   426,     0,     0,     0,    73,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,     0,     0,   342,   343,   344,   345,   346,     0,
       0,     0,     0,     0,     0,   347,   348,   349,     0,     0,
       0,   327,     0,     0,     0,     0,   364,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,     0,     0,   342,   343,   344,   345,   346,     0,     0,
       0,     0,     0,     0,   347,   348,   349,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
       0,     0,   342,   343,   344,   345,   346,     0,     0,     0,
       0,     0,     0,   347,   348,   349
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-365)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-191)))

static const yytype_int16 yycheck[] =
{
       4,   233,   234,     7,     8,    23,    62,   264,    26,   187,
     257,    24,   125,    26,     8,    44,    52,    21,   219,   132,
      12,    15,    16,    17,    64,    59,    30,   140,    68,    69,
       0,    60,   233,   234,    74,    75,    76,    29,    37,    24,
     112,    26,    41,    42,    60,    57,    59,    59,    55,   130,
     131,   415,   219,    60,   232,    86,   420,   138,   139,     5,
       1,    60,    60,   264,   120,    62,   233,   234,    59,    62,
      60,    65,    66,    67,    59,   322,    70,    71,    62,   110,
     120,    22,    23,    24,    78,    26,   122,    28,    29,    62,
      62,    32,    33,    34,   123,    99,    37,   264,    44,   171,
      24,   173,    26,    59,   468,   121,    98,    16,    17,   149,
     123,    52,   124,    62,   121,    56,    57,    58,    59,    60,
     114,   115,    37,   121,   123,    86,   123,    37,   119,   133,
     123,    41,    42,   267,    59,    59,    85,   122,   132,   123,
      44,   181,   182,    84,   278,   279,   140,   120,   120,   189,
      60,   191,   192,    94,    95,     8,    60,    98,    71,   293,
     101,   456,     1,   110,     3,    78,   107,   108,    21,   282,
      59,   466,   119,   177,   178,   122,   110,   119,   119,   436,
     358,   122,   123,   177,   202,   119,   443,   467,   119,   183,
     184,   471,   110,   187,   188,   122,   200,   177,   110,   280,
     281,   119,   102,   207,   184,   119,   200,   119,   188,   109,
     110,   111,   110,   119,   415,   219,   473,    53,    54,   420,
     200,   119,    53,    54,   242,   219,   109,   110,   111,   233,
     234,   312,   464,   465,    24,   436,    26,    80,   232,   233,
     234,   235,   443,   261,    26,   110,    28,   124,   415,   243,
     244,    44,    26,   420,    28,    59,   434,   435,    66,    67,
     264,   120,   123,   464,   465,    76,   260,   468,   122,   436,
     122,    59,   473,   267,   120,    62,   443,    62,   120,   360,
     361,   122,   120,   120,   278,   279,   120,    62,   282,    59,
     123,    59,    59,    94,   288,    59,   120,   464,   465,   293,
     318,   468,   122,   122,   119,   323,   473,   119,    44,   349,
     119,   112,    59,    55,    59,    59,   123,    98,    99,   100,
     101,   102,    62,   123,   123,   126,   127,   321,   109,   110,
     111,   120,   350,   351,   120,   119,   119,    48,    93,   357,
      62,    32,    33,   144,   123,    36,    37,    38,   120,   122,
      80,    76,    59,   119,    52,   156,   151,   158,   120,   120,
     120,   120,   402,   359,   358,   359,   123,   407,   408,   122,
     171,   122,   173,    64,   123,   123,    21,    68,    69,   441,
     101,   207,   115,    74,    75,    76,    77,   200,    32,   407,
     196,   409,   418,   274,   424,   196,   240,    -1,    -1,    -1,
     428,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   415,   430,   431,     0,     1,   420,    -1,     4,    -1,
      -1,   112,   416,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,   436,    -1,   428,   126,   127,    -1,    -1,   443,
     434,   435,     0,     1,    -1,    -1,     4,   441,    34,    -1,
      36,    37,    -1,   144,    -1,    41,    42,    -1,   149,    -1,
     464,   465,    -1,    -1,   468,   156,    -1,   158,    -1,   473,
     464,   465,    -1,    -1,    60,    -1,    34,    -1,    36,    37,
     171,    -1,   173,    41,    42,    -1,    -1,    -1,    -1,    -1,
     181,   182,   183,    -1,    -1,    -1,   187,    -1,   189,   242,
     191,   192,    60,   246,    -1,   196,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,   232,    -1,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,   301,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,   311,    -1,
     109,   110,   111,    -1,    -1,    -1,    -1,    -1,   321,   322,
      -1,    -1,    -1,    -1,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   368,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,
      26,    -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,
      -1,    37,    -1,    -1,    -1,    -1,    -1,   348,   349,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,   358,    -1,    -1,
      56,    57,    58,    59,    60,   418,    -1,    -1,    -1,   422,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,
     433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,
      -1,   402,    98,   456,    -1,   101,   407,   408,    -1,    -1,
      -1,   107,   108,   466,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,    -1,    -1,   122,   123,    -1,    -1,
      -1,    -1,    -1,   434,   435,    22,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    -1,    32,    33,    34,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,     1,    -1,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    23,
      24,    -1,    26,    -1,    28,    29,    -1,    84,    32,    33,
      34,    -1,    -1,    37,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    -1,    -1,    -1,    52,    -1,
     107,   108,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,
      94,    95,    -1,    -1,    98,    -1,    -1,   101,    -1,    -1,
      -1,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,    -1,
      22,    23,    24,    -1,    26,   119,    28,    29,   122,   123,
      32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,     1,    -1,    56,    57,    58,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    -1,    26,    -1,    28,
      29,    -1,    84,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    -1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,
      -1,    -1,    -1,    52,    -1,   107,   108,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    95,    -1,    -1,    98,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,   122,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    35,    -1,    37,    -1,    -1,    -1,    41,
      42,    43,    44,    -1,    -1,    47,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    59,    60,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,    -1,    -1,    79,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    98,    -1,    -1,   101,
     102,    -1,    -1,    -1,    30,    -1,    -1,   109,    -1,    35,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,   121,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    98,    -1,    -1,   101,   102,    -1,    -1,    30,
      -1,    -1,    -1,   109,    35,    -1,    37,    -1,    -1,    -1,
      41,    42,    43,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    98,    -1,    -1,
     101,   102,    -1,    -1,    30,    -1,    -1,    -1,   109,    35,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    -1,
      -1,    47,    22,    23,    24,    -1,    26,    -1,    28,    29,
      -1,    -1,    -1,    59,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    56,    57,    58,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,   101,   102,    -1,    -1,    -1,
      -1,    -1,    82,   109,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    -1,    -1,    98,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,    22,
      23,    24,    -1,    26,    -1,    28,    29,    -1,    -1,   119,
      -1,    -1,   122,   123,    37,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    26,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      37,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    94,    95,    -1,    -1,    98,    -1,    -1,   101,    56,
      57,    58,    59,    60,   107,   108,    -1,    -1,    -1,    79,
      -1,    22,    23,    24,    -1,    26,   119,    28,    29,   122,
     123,    -1,    -1,    -1,    -1,    -1,    37,    84,    98,    -1,
      -1,   101,    -1,    -1,    -1,    -1,    -1,    94,    95,    -1,
      -1,    98,    -1,    -1,   101,    56,    57,    58,    59,    -1,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,   121,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    98,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,   122,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      -1,    35,    -1,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      30,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    -1,    44,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    59,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    79,
      -1,    -1,    -1,    -1,    30,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    -1,    44,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    59,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    79,    -1,    76,    -1,    -1,    30,    -1,
      -1,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    -1,    -1,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    59,   109,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,   124,    -1,    -1,    -1,    79,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,   120,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      -1,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,   126,    59,     0,    60,   121,   128,   130,
     130,     1,     4,    34,    36,    37,    41,    42,   127,   129,
     130,   132,   139,   141,   144,   145,   177,    24,    26,    59,
     122,   140,    59,    37,   119,   127,   182,   182,   182,   145,
     121,   130,   131,   131,   131,   140,   130,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    30,    35,    37,    41,    42,    43,    44,
      46,    47,    59,    79,    98,   101,   102,   109,   160,   162,
     171,   175,   176,   188,   190,   191,   192,   193,   194,   195,
     197,   198,   199,   160,    59,   160,   160,   160,    59,   140,
     142,   143,    47,   161,   175,   189,   127,   187,   187,   187,
     189,   189,    86,   127,   165,   165,   189,   189,   189,    57,
     124,   160,   196,   110,   165,   119,    98,   101,   181,   198,
     119,   119,   119,   140,   130,   123,   142,   122,   119,   119,
     119,   166,   167,   198,    80,   127,   168,   168,   189,   124,
      59,    44,   127,   183,   184,   185,    44,   198,    44,   198,
     120,   183,   184,   183,   127,   184,   130,   123,   183,   183,
     184,    62,    85,    76,   166,   169,   170,   122,   122,   189,
      59,   133,   133,   120,    62,   198,   198,   120,    62,   120,
     120,   120,   120,   120,   166,   166,    62,   127,   130,   172,
     173,   174,   185,    37,    41,    42,   130,   163,   164,    62,
     189,   189,   127,   134,   189,     5,   185,   134,   189,   122,
     189,   189,   169,   172,   123,   131,    59,    59,    59,   123,
     164,    59,   120,   122,   122,     1,    22,    23,    24,    26,
      28,    29,    32,    33,    37,    52,    56,    57,    58,    84,
      94,    95,    98,   101,   107,   108,   119,   122,   127,   130,
     138,   139,   147,   148,   149,   152,   160,   178,   179,   186,
     200,   202,   203,   206,   207,   208,   209,   210,   211,   213,
     119,   119,   119,   134,   186,   186,   127,   146,    37,   210,
     211,   213,   131,   209,    44,   127,   135,   136,   137,    59,
     127,   153,   209,   209,   209,   209,   209,   209,   209,   209,
     209,    82,    93,   123,   201,   209,    55,   127,   159,   131,
     148,   119,   122,   159,   123,    26,   206,    76,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    98,    99,   100,   101,   102,   109,   110,   111,
     159,   159,   183,   183,   184,   123,   123,   159,    59,    62,
     119,   119,   150,   209,   120,   180,   209,   183,    62,   123,
      59,   131,   127,   201,   212,    59,   123,   201,   204,   205,
     131,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   119,   160,   189,   131,   131,   120,   120,   120,
     131,   134,   137,   183,   183,    48,   151,   123,    93,   209,
     122,   120,    80,   123,    62,   123,   124,   189,   119,   131,
     189,   189,   131,    76,   120,   120,   149,    53,    54,   127,
     154,   157,   180,   149,   209,    59,   205,   120,   212,   131,
     131,   209,   134,   134,   123,    52,   155,    53,   127,   154,
     158,   123,   123,   120,   122,   122,   156,   150,   122,   186,
     186,   150,   151,   149,   123,   123,   151,   123
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

  case 48:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
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

  case 56:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 57:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 58:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 59:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 60:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 61:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 62:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); }
    break;

  case 64:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 66:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 68:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 71:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 72:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 73:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 75:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 76:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 77:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 78:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 79:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 81:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 84:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 86:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 87:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 91:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 92:

    { yoParserClass(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 96:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 111:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), &(yyvsp[(9) - (9)]), NULL, true, YO_CALLING_C, parm, &yyloc); }
    break;

  case 112:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (7)]), &(yyvsp[(5) - (7)]), &(yyvsp[(7) - (7)]), NULL, false, YO_CALLING_C, parm, &yyloc); }
    break;

  case 113:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 114:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 115:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 116:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), false, &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 117:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 118:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 119:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 120:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 122:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 123:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 124:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 125:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 126:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 131:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 132:

    { yoParserDeclArg(&(yyval), false, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 133:

    { yoParserDeclArg(&(yyval), true, &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 137:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 138:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 139:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 143:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 144:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 145:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 146:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 147:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 152:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 154:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 155:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 156:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 157:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 158:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 159:

    { yoParserTypeStdName(&(yyval), T_INT, parm, &yyloc); }
    break;

  case 160:

    { yoParserTypeStdName(&(yyval), T_INTPTR, parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 163:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 164:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 165:

    { yoParserTypeStdName(&(yyval), T_UINT, parm, &yyloc); }
    break;

  case 166:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 167:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 168:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 169:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 170:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 171:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 172:

    { yoParserTypeStdName(&(yyval), T_UNKNOWN_YET, parm, &yyloc); }
    break;

  case 173:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 174:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 175:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 181:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 182:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 183:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 184:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 185:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 186:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 188:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 189:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 190:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 192:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 193:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 200:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_EQ, parm, &yyloc); }
    break;

  case 201:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_NE, parm, &yyloc); }
    break;

  case 202:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LE, parm, &yyloc); }
    break;

  case 203:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GE, parm, &yyloc); }
    break;

  case 204:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LT, parm, &yyloc); }
    break;

  case 205:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GT, parm, &yyloc); }
    break;

  case 206:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 207:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 208:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 209:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 210:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 211:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW, parm, &yyloc); }
    break;

  case 212:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 213:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 214:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 215:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 216:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 217:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 218:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 219:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 220:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 222:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 225:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 226:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 227:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 228:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 229:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 230:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 231:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 232:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 233:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 234:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 235:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 238:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 239:

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




