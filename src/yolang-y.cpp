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

/* Copy the first part of user declarations.  */


#include <stdio.h>
#include <stdlib.h>
#include "yoparser.h"

void yoParserEnd(YYSTYPE*, void*);
void yoParserBinOp(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, int op, void*);
void yoParserUnaryOp(YYSTYPE * r, YYSTYPE * a, int op, void*);
void yoParserConst(YYSTYPE * r, int op, void*);
void yoParserTypeStdName(YYSTYPE * r, int op, void*);
void yoParserTypeName(YYSTYPE * r, YYSTYPE * a, void*);
void yoParserTypeConst(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypePtr(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypeChan(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypeSlice(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserTypeArr(YYSTYPE * r, YYSTYPE * size, YYSTYPE * a, void * parm);
void yoParserTypeFunc(YYSTYPE * r, YYSTYPE * self, YYSTYPE * args, YYSTYPE * type, void * parm);
void yoParserDeclType(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserDeclVar(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserDeclArg(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserDotName(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void*);
void yoParserNewArr(YYSTYPE * r, void * parm);
void yoParserNewArrExps(YYSTYPE * r, YYSTYPE * expr_list, void * parm);
void yoParserNewObj(YYSTYPE * r, YYSTYPE * name, void * parm);
void yoParserNewObjExps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * expr_list, void * parm);
void yoParserNewObjProps(YYSTYPE * r, YYSTYPE * name, YYSTYPE * prop_list, void * parm);
void yoParserNewLine(void*);
void yoParserDeclFunc(YYSTYPE * r, YYSTYPE * self, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, YYSTYPE * body, void*);
void yoParserContractFunc(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void*);
void yoParserContract(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserClass(YYSTYPE * r, YYSTYPE * a, void * parm);
void yoParserDebug(YYSTYPE*, void*);
void yoParserError(YYSTYPE*, const char*, void*);
void yoParseEmpty(YYSTYPE*, void*);
void yoParserCall(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, void * parm);
void yoParserStmtReturn(YYSTYPE * r, YYSTYPE * expr, void * parm);
void yoParserEnableBrace(void * parm);
void yoParserStmtIf(YYSTYPE * r, YYSTYPE * ifExpr, YYSTYPE * thenStmt, YYSTYPE * elseIfList, YYSTYPE * elseStmt, void * parm);
void yoParserElseIfList(YYSTYPE * r, YYSTYPE * a, YYSTYPE * b, void * parm);
void yoParserElseIf(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * stmt, void * parm);
void yoParserElse(YYSTYPE * r, YYSTYPE * stmt, void * parm);
void yoParserCatchElem(YYSTYPE * r, YYSTYPE * name, YYSTYPE * stmt, void * parm);
void yoParserStmtCatch(YYSTYPE * r, YYSTYPE * stmt, YYSTYPE * catchElem, void * parm);
void yoParserCast(YYSTYPE * r, YYSTYPE * expr, YYSTYPE * type, void * parm);

int yolex(YYSTYPE*, void * parser);
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
     T_ELLIPSIS = 258,
     T_INT8 = 259,
     T_INT16 = 260,
     T_INT32 = 261,
     T_INT64 = 262,
     T_UINT8 = 263,
     T_UINT16 = 264,
     T_UINT32 = 265,
     T_UINT64 = 266,
     T_UINTPTR = 267,
     T_FLOAT32 = 268,
     T_FLOAT64 = 269,
     T_STRING = 270,
     T_BOOL = 271,
     T_TRUE = 272,
     T_FALSE = 273,
     T_SSTRING = 274,
     T_SSTRING_NOT_FINISHED = 275,
     T_QSTRING = 276,
     T_QSTRING_NOT_FINISHED = 277,
     T_QSTRING_INJECT_EXRP = 278,
     T_NULL = 279,
     T_VOID = 280,
     T_RETURN = 281,
     T_VAR = 282,
     T_TYPE = 283,
     T_CHAN = 284,
     T_FUNC = 285,
     T_CONST = 286,
     T_STRUCT = 287,
     T_CLASS = 288,
     T_CONTRACT = 289,
     T_BRACE = 290,
     T_IF = 291,
     T_ELSE = 292,
     T_ELSEIF = 293,
     T_CATCH = 294,
     T_LNUMBER = 295,
     T_DNUMBER = 296,
     T_NAME = 297,
     T_NEWLINE = 298,
     T_FIX = 299,
     T_POW_ASSIGN = 300,
     T_RSH_ASSIGN = 301,
     T_LSH_ASSIGN = 302,
     T_XOR_ASSIGN = 303,
     T_OR_ASSIGN = 304,
     T_AND_ASSIGN = 305,
     T_MOD_ASSIGN = 306,
     T_CONCAT_ASSIGN = 307,
     T_DIV_ASSIGN = 308,
     T_MUL_ASSIGN = 309,
     T_MINUS_ASSIGN = 310,
     T_PLUS_ASSIGN = 311,
     T_DECL_ASSIGN = 312,
     T_ASSIGN = 313,
     T_XORXOR = 314,
     T_OROR = 315,
     T_ANDAND = 316,
     T_GT = 317,
     T_LT = 318,
     T_GE = 319,
     T_LE = 320,
     T_NE = 321,
     T_EQ = 322,
     T_CONCAT = 323,
     T_XOR = 324,
     T_OR = 325,
     T_MINUS = 326,
     T_PLUS = 327,
     T_RSH = 328,
     T_LSH = 329,
     T_AND = 330,
     T_MOD = 331,
     T_DIV = 332,
     T_MUL = 333,
     T_POW = 334,
     T_AT = 335,
     T_UNARY = 336,
     T_DEC = 337,
     T_INC = 338,
     T_TILDE = 339,
     T_NOT = 340,
     T_DOT = 341,
     T_AS = 342,
     T_INDIRECT = 343,
     T_ADDR = 344,
     T_INDEX = 345,
     T_PTR = 346,
     T_ARR = 347,
     T_DOTNAME = 348,
     NotParen = 349
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNRULES -- Number of states.  */
#define YYNSTATES  303

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   349

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      99,   100,     2,     2,    45,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,   101,
       2,     2,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    89,     2,   104,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   103,     2,   102,     2,     2,     2,     2,
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
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    91,    92,    93,    94,    95,    96,    97,    98
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    16,
      19,    21,    25,    29,    35,    39,    42,    45,    48,    50,
      52,    54,    58,    59,    66,    67,    72,    73,    79,    81,
      84,    85,    90,    91,    97,    98,   102,   106,   108,   113,
     116,   118,   122,   126,   128,   130,   132,   135,   137,   141,
     145,   147,   152,   154,   157,   163,   170,   179,   181,   186,
     189,   191,   193,   196,   198,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   229,   240,   253,   258,
     264,   265,   267,   268,   270,   274,   277,   279,   280,   282,
     286,   287,   293,   300,   309,   311,   313,   316,   319,   322,
     325,   329,   331,   333,   338,   340,   342,   344,   346,   348,
     350,   352,   354,   356,   358,   360,   362,   364,   366,   368,
     370,   372,   374,   376,   378,   380,   382,   384,   386,   390,
     393,   397,   401,   406,   411,   413,   417,   421,   424,   426,
     429,   432,   434,   436,   438,   440,   442,   444,   446,   450,
     454,   458,   462,   466,   470,   474,   478,   482,   486,   490,
     494,   498,   503,   507,   509,   513,   519,   522,   525,   528,
     531,   534,   537,   542
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     106,     0,    -1,   109,    -1,    -1,     1,    -1,    43,    -1,
     107,    -1,   101,    -1,   114,    -1,   109,   114,    -1,    42,
      -1,   110,    45,    42,    -1,    27,   110,   149,    -1,    27,
     110,   149,    59,   159,    -1,    28,    42,   139,    -1,   111,
     108,    -1,   112,   108,    -1,   140,   108,    -1,   113,    -1,
     107,    -1,   167,    -1,    35,   128,   102,    -1,    -1,    36,
     118,   115,   116,   122,   123,    -1,    -1,    38,   120,   115,
     116,    -1,    -1,    37,    36,   121,   115,   116,    -1,   119,
      -1,   122,   119,    -1,    -1,    37,   103,   128,   102,    -1,
      -1,    39,    42,   103,   128,   102,    -1,    -1,   110,    59,
     159,    -1,   110,    58,   159,    -1,   113,    -1,    26,   159,
     124,   108,    -1,    26,   108,    -1,   117,    -1,   125,   124,
     108,    -1,   170,   124,   108,    -1,   126,    -1,   107,    -1,
     127,    -1,   128,   127,    -1,    42,    -1,   129,    90,    42,
      -1,    34,   103,   102,    -1,   130,    -1,    34,   103,   132,
     102,    -1,   133,    -1,   132,   133,    -1,    42,    99,   142,
     100,   108,    -1,    42,    99,   142,   100,   149,   108,    -1,
      42,    99,   142,   100,    99,   146,   100,   108,    -1,   107,
      -1,    33,   103,   137,   102,    -1,   143,   108,    -1,   107,
      -1,   135,    -1,   136,   135,    -1,   136,    -1,    -1,   156,
      -1,   150,    -1,   151,    -1,   152,    -1,   153,    -1,   155,
      -1,   148,    -1,   138,    -1,   131,    -1,   134,    -1,    30,
     141,   129,    99,   142,   100,   103,   145,   102,    -1,    30,
     141,   129,    99,   142,   100,   149,   103,   145,   102,    -1,
      30,   141,   129,    99,   142,   100,    99,   146,   100,   103,
     145,   102,    -1,    99,    42,   156,   100,    -1,    99,    42,
      81,   156,   100,    -1,    -1,   143,    -1,    -1,   144,    -1,
     143,    45,   144,    -1,   110,   149,    -1,   128,    -1,    -1,
     149,    -1,   146,    45,   149,    -1,    -1,    30,   147,    99,
     142,   100,    -1,    30,   147,    99,   142,   100,   149,    -1,
      30,   147,    99,   142,   100,    99,   146,   100,    -1,   138,
      -1,   130,    -1,    31,   149,    -1,    29,   149,    -1,    81,
     149,    -1,    82,   149,    -1,    89,   104,   149,    -1,    40,
      -1,   129,    -1,    89,   154,   104,   149,    -1,   157,    -1,
     129,    -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      15,    -1,    13,    -1,    14,    -1,    16,    -1,    25,    -1,
      17,    -1,    18,    -1,    24,    -1,    40,    -1,    41,    -1,
      19,    -1,    21,    -1,   167,    -1,   159,    45,   167,    -1,
     103,   102,    -1,   103,   159,   102,    -1,   129,   103,   102,
      -1,   129,   103,   159,   102,    -1,   129,   103,   162,   102,
      -1,   163,    -1,   162,    45,   163,    -1,   129,    59,   167,
      -1,    23,   168,    -1,   164,    -1,   165,   164,    -1,   165,
      21,    -1,   168,    -1,   166,    -1,   158,    -1,   160,    -1,
     161,    -1,   129,    -1,   169,    -1,   167,    75,   167,    -1,
     167,    74,   167,    -1,   167,    81,   167,    -1,   167,    80,
     167,    -1,   167,    79,   167,    -1,   167,    71,   167,    -1,
     167,    90,   129,    -1,   167,    73,   167,    -1,   167,    63,
     167,    -1,   167,    78,   167,    -1,   167,    64,   167,    -1,
     167,    72,   167,    -1,   167,    62,   167,    -1,   167,    89,
     167,   104,    -1,    99,   167,   100,    -1,   170,    -1,   167,
      91,   149,    -1,   167,    90,    99,   149,   100,    -1,    75,
     167,    -1,    74,   167,    -1,    88,   167,    -1,    87,   167,
      -1,    81,   167,    -1,    78,   167,    -1,   129,    99,   159,
     100,    -1,   167,    90,   129,    99,   159,   100,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   187,   190,   193,   194,   197,   198,
     201,   202,   205,   206,   213,   216,   217,   218,   221,   222,
     233,   236,   239,   239,   244,   244,   245,   245,   248,   249,
     250,   253,   254,   257,   258,   261,   262,   265,   266,   267,
     268,   269,   270,   273,   274,   277,   278,   281,   282,   285,
     288,   289,   292,   293,   296,   297,   298,   299,   302,   306,
     307,   310,   311,   314,   315,   318,   319,   320,   321,   322,
     323,   324,   327,   328,   329,   332,   334,   336,   340,   341,
     342,   345,   346,   349,   350,   353,   356,   357,   360,   361,
     364,   367,   368,   369,   372,   373,   376,   379,   382,   383,
     390,   394,   395,   398,   402,   403,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     422,   423,   424,   425,   426,   427,   428,   431,   432,   435,
     436,   439,   440,   441,   444,   445,   448,   451,   454,   455,
     458,   461,   462,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   490,   491,   492,   493,
     494,   495,   500,   501
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ELLIPSIS", "T_INT8", "T_INT16",
  "T_INT32", "T_INT64", "T_UINT8", "T_UINT16", "T_UINT32", "T_UINT64",
  "T_UINTPTR", "T_FLOAT32", "T_FLOAT64", "T_STRING", "T_BOOL", "T_TRUE",
  "T_FALSE", "T_SSTRING", "T_SSTRING_NOT_FINISHED", "T_QSTRING",
  "T_QSTRING_NOT_FINISHED", "T_QSTRING_INJECT_EXRP", "T_NULL", "T_VOID",
  "T_RETURN", "T_VAR", "T_TYPE", "T_CHAN", "T_FUNC", "T_CONST", "T_STRUCT",
  "T_CLASS", "T_CONTRACT", "T_BRACE", "T_IF", "T_ELSE", "T_ELSEIF",
  "T_CATCH", "T_LNUMBER", "T_DNUMBER", "T_NAME", "T_NEWLINE", "T_FIX",
  "','", "\"**= (T_POW_ASSIGN)\"", "\">>= (T_RSH_ASSIGN)\"",
  "\"<<= (T_LSH_ASSIGN)\"", "\"^= (T_XOR_ASSIGN)\"",
  "\"|= (T_OR_ASSIGN)\"", "\"&= (T_AND_ASSIGN)\"", "\"%= (T_MOD_ASSIGN)\"",
  "\"..= (T_CONCAT_ASSIGN)\"", "\"/= (T_DIV_ASSIGN)\"",
  "\"*= (T_MUL_ASSIGN)\"", "\"-= (T_MINUS_ASSIGN)\"",
  "\"+= (T_PLUS_ASSIGN)\"", "\":= (T_DECL_ASSIGN)\"", "\"= (T_ASSIGN)\"",
  "'?'", "':'", "\"^^ (T_XORXOR)\"", "\"|| (T_OROR)\"",
  "\"&& (T_ANDAND)\"", "\"> (T_GT)\"", "\"< (T_LT)\"", "\">= (T_GE)\"",
  "\"<= (T_LE)\"", "\"!= (T_NE)\"", "\"== (T_EQ)\"", "\".. (T_CONCAT)\"",
  "\"^ (T_XOR)\"", "\"| (T_OR)\"", "\"- (T_MINUS)\"", "\"+ (T_PLUS)\"",
  "\">> (T_RSH)\"", "\"<< (T_LSH)\"", "\"& (T_AND)\"", "\"% (T_MOD)\"",
  "\"/ (T_DIV)\"", "\"* (T_MUL)\"", "\"** (T_POW)\"", "\"@ (T_AT)\"",
  "T_UNARY", "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "\"~ (T_TILDE)\"",
  "\"! (T_NOT)\"", "'['", "\". (T_DOT)\"", "\"as (T_AS)\"",
  "\"* (T_INDIRECT)\"", "\"& (T_ADDR)\"", "\"[] (T_INDEX)\"", "T_PTR",
  "T_ARR", "T_DOTNAME", "NotParen", "'('", "')'", "';'", "'}'", "'{'",
  "']'", "$accept", "file", "newline", "end_stmt", "top_stmt_list",
  "name_list", "top_decl_var", "decl_type", "top_stmt_no_emptyline",
  "top_stmt", "if_header", "brace_stmt", "if_stmt", "$@1", "elseif", "$@2",
  "$@3", "elseif_list", "else", "catch", "assign", "stmt_no_emptyline",
  "stmt", "stmt_list", "dotname", "type_contract_empty", "type_contract",
  "contract_body", "contract_decl_func", "type_class", "class_body_stmt",
  "class_body_stmt_list", "class_body", "type_base", "type_ext",
  "top_decl_func", "decl_self", "decl_arg_list_or_empty", "decl_arg_list",
  "decl_arg", "func_body", "type_list", "decl_self_nop", "type_func",
  "type", "type_const", "type_chan", "type_ptr", "type_slice",
  "type_arr_size", "type_arr", "type_name", "type_std_name",
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
     295,   296,   297,   298,   299,    44,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
      63,    58,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,    91,
     341,   342,   343,   344,   345,   346,   347,   348,   349,    40,
      41,    59,   125,   123,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   113,   113,   113,   114,   114,
     115,   116,   118,   117,   120,   119,   121,   119,   122,   122,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     131,   131,   132,   132,   133,   133,   133,   133,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   139,   139,   139,   140,   140,   140,   141,   141,
     141,   142,   142,   143,   143,   144,   145,   145,   146,   146,
     147,   148,   148,   148,   149,   149,   150,   151,   152,   152,
     153,   154,   154,   155,   156,   156,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   158,   158,   158,   158,   158,   159,   159,   160,
     160,   161,   161,   161,   162,   162,   163,   164,   165,   165,
     166,   167,   167,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   169,   169,   169,   169,
     169,   169,   170,   170
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     5,     3,     2,     2,     2,     1,     1,
       1,     3,     0,     6,     0,     4,     0,     5,     1,     2,
       0,     4,     0,     5,     0,     3,     3,     1,     4,     2,
       1,     3,     3,     1,     1,     1,     2,     1,     3,     3,
       1,     4,     1,     2,     5,     6,     8,     1,     4,     2,
       1,     1,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     9,    10,    12,     4,     5,
       0,     1,     0,     1,     3,     2,     1,     0,     1,     3,
       0,     5,     6,     8,     1,     1,     2,     2,     2,     2,
       3,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       3,     3,     4,     4,     1,     3,     3,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     1,     3,     5,     2,     2,     2,     2,
       2,     2,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,    80,     5,     0,    19,     2,     0,
       0,    18,     8,     0,    10,     0,     0,     0,     0,     1,
       9,     7,     6,    15,    16,    17,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   117,   115,   118,   119,
       0,    90,     0,     0,    47,     0,     0,     0,     0,   105,
      95,    94,    71,    12,    66,    67,    68,    69,    70,    65,
     104,     0,     0,    50,    73,    74,    72,    14,     0,     0,
      97,     0,    96,     0,    11,    98,    99,   101,     0,   102,
       0,     0,     0,    64,     0,     0,     0,    82,    82,    49,
     100,     0,    48,   120,   121,   125,   126,     0,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     143,    13,   144,   145,   138,     0,   142,   127,   141,   147,
     163,    60,     0,    61,    63,     0,     0,    83,     0,    57,
       0,    52,     0,    78,     0,    81,     0,   103,     0,   141,
     167,   166,   171,   170,   169,   168,     0,   129,     0,     0,
       0,     0,   140,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      62,    58,     0,    59,    82,    51,    53,    79,     0,    91,
     162,   130,     0,   131,   146,     0,     0,   134,   128,   160,
     156,   158,   153,   159,   155,   149,   148,   157,   152,   151,
     150,     0,     0,   154,   164,    84,     0,     0,    87,     0,
       0,    92,   172,     0,   132,     0,   133,   161,     0,     0,
       0,     0,    88,     0,    22,    47,    44,     0,    37,    40,
      34,    43,    45,    86,     0,   163,    87,     0,   136,     0,
     135,   165,     0,     0,    54,     0,     0,     0,    39,    34,
       0,     0,     0,     0,     0,    46,    75,     0,     0,    93,
     173,     0,    55,    89,    87,     0,     0,    20,    36,    35,
       0,    41,    42,    76,     0,     0,    38,     0,    30,     0,
      56,    77,     0,     0,    24,    28,    32,     0,    21,    26,
       0,     0,    29,    23,    33,     0,     0,     0,     0,    25,
       0,    27,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    22,    23,     8,   227,     9,    10,   228,    12,
     266,   278,   229,   250,   285,   290,   295,   286,   293,   254,
     230,   231,   232,   233,   109,    50,    64,   130,   131,    65,
     123,   124,   125,    51,    67,    13,    18,   134,   135,   127,
     234,   221,    71,    52,   222,    54,    55,    56,    57,    80,
      58,    59,    60,   110,   111,   112,   113,   186,   187,   114,
     115,   116,   138,   118,   119,   120
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -224
static const yytype_int16 yypact[] =
{
     105,  -224,    -5,    -1,   -65,  -224,    56,  -224,   109,   -25,
     -25,  -224,  -224,   -25,  -224,   881,   926,    24,    36,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     967,  -224,   967,     9,  -224,    49,   967,   967,   -31,    25,
    -224,  -224,  -224,    99,  -224,  -224,  -224,  -224,  -224,  -224,
    -224,    58,    78,  -224,  -224,  -224,  -224,  -224,   677,   -50,
    -224,    88,  -224,    90,  -224,  -224,  -224,  -224,   967,    25,
     103,   168,   826,   108,   -28,   479,   113,    -5,    -5,  -224,
    -224,   967,  -224,  -224,  -224,  -224,  -224,   826,  -224,  -224,
    -224,   826,   826,   826,   826,   826,   826,   826,   728,    17,
    -224,   176,  -224,  -224,  -224,   143,  -224,  1014,  -224,  -224,
    -224,  -224,   881,  -224,   108,   121,   -22,  -224,   128,  -224,
     -17,  -224,   129,  -224,   130,   183,   131,  -224,  1014,   157,
     127,   127,   127,   127,   127,   127,   991,  -224,   -39,   826,
     754,   826,  -224,  -224,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   -18,   967,  -224,
    -224,  -224,    -5,  -224,    -5,  -224,  -224,  -224,   297,   399,
    -224,  -224,   -29,  -224,    35,   -12,    -6,  -224,  1014,   710,
     710,  1035,    95,    95,    95,    95,    95,   127,   127,   127,
     127,   948,   967,   133,  -224,  -224,   134,   967,   629,   135,
     967,  -224,  -224,   826,  -224,    36,  -224,  -224,   139,   826,
     338,    -3,  -224,   656,  -224,    55,  -224,   104,  -224,  -224,
     201,  -224,  -224,   629,   140,   -26,   629,    -2,  1014,   -21,
    -224,  -224,     2,   967,  -224,   -25,   967,   138,  -224,   114,
     826,   826,   826,   202,   -25,  -224,  -224,   -25,   141,  -224,
    -224,     3,  -224,  -224,   629,   -25,   210,  1014,   176,   176,
     145,  -224,  -224,  -224,   -25,   149,  -224,   629,   132,   629,
    -224,  -224,   425,   217,  -224,  -224,   188,   512,  -224,  -224,
     826,   -33,  -224,  -224,  -224,   826,   210,   629,   210,  -224,
     542,  -224,  -224
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -224,  -224,     0,    -8,  -224,     5,  -224,  -224,    57,   246,
    -130,   -76,  -224,  -224,   -30,  -224,  -224,  -224,  -224,  -118,
    -224,  -224,  -223,  -169,     4,   239,  -224,  -224,   137,  -224,
     136,  -224,  -224,   243,  -224,  -224,  -224,   -87,   -56,    89,
    -204,  -182,  -224,  -224,   -11,  -224,  -224,  -224,  -224,  -224,
    -224,   -23,  -224,  -224,   -96,  -224,  -224,  -224,    48,   150,
    -224,  -224,    39,   171,  -224,  -178
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -138
static const yytype_int16 yytable[] =
{
       7,   136,    24,   289,    53,    25,   151,    15,     7,    77,
     255,    44,   148,   253,   128,     5,   151,   -34,     5,    49,
      49,     5,    69,   172,    44,   128,     5,   126,   237,    70,
     235,    72,   258,   151,    17,    75,    76,    14,   213,   215,
      81,    16,   246,   246,    49,    86,    49,   151,   246,    87,
      49,    49,    79,   182,   185,   235,    19,    11,   235,   255,
     275,   261,   132,   181,   255,    11,    68,    90,   126,    81,
     297,   212,    49,    78,    89,   -34,    21,   255,    44,    21,
     137,   202,    49,   121,   129,   175,   235,   206,   122,    49,
     214,    74,   122,   122,   213,    49,   216,   247,   259,   235,
     -10,   235,   260,   274,   235,    -3,     1,    81,   282,   235,
     287,   169,    73,   -10,   -10,    81,   149,   257,   173,   235,
     150,   117,   235,   242,   121,    81,    49,   249,   300,   122,
     129,   265,     2,     3,   149,     4,     2,     3,   150,     4,
     140,   141,   142,   143,   144,   145,   146,   117,     5,    45,
      14,     5,     5,   253,   184,   268,   269,   204,    82,   151,
     296,    83,   251,   252,   152,   298,    97,   209,   211,   283,
     284,   203,    49,   162,   163,   164,   165,   122,  -137,   122,
    -137,    84,    49,    49,   166,   167,   168,    88,   117,   117,
     188,   218,    89,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,    49,    91,   226,   245,
      92,    49,   244,   133,    49,   248,   166,   167,   168,   239,
     299,   151,   301,   171,    49,   291,   284,   174,   172,   177,
     178,   179,   219,   226,   220,   263,   226,   262,   236,   241,
     253,   264,   256,   273,   270,   277,   271,    49,   279,   272,
      49,   281,   238,   289,    20,    63,   292,   276,   117,    66,
     170,   205,   117,   240,   226,   153,   280,   176,   139,     0,
       0,     0,     0,     0,     0,     0,     0,   226,     0,   226,
       0,     0,   226,     0,     0,     0,     0,   226,     0,   267,
     117,   117,     0,     0,     0,     0,     0,   226,     0,     0,
     226,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    40,    41,    42,   267,
       0,    43,     0,     0,   267,     0,     0,     0,     0,    44,
       0,     0,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     0,     0,     0,     0,     0,
       0,     0,     0,    39,     0,     0,     0,    40,    41,    42,
       0,     0,    43,     0,     0,     0,     0,     0,    46,    47,
      44,     5,     0,     0,     0,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   207,     0,     0,     0,
     208,     0,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,     0,    46,
      47,     0,     0,     0,    39,     0,     0,    48,    40,    41,
      42,     0,     0,    43,     0,     0,     0,   243,     0,    21,
       0,    44,    93,    94,    95,     0,    96,     0,    97,    98,
       0,   223,     2,     3,     0,     4,     0,     0,     0,     0,
       0,   224,     0,     0,     0,    99,   100,   225,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,   210,   101,
     102,     0,     0,   103,    39,     0,   104,     0,     0,     0,
       0,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,    44,     0,     0,   107,     0,     0,   288,   108,    93,
      94,    95,     0,    96,     0,    97,    98,     0,   223,     2,
       3,     0,     4,     0,     0,     0,     0,     0,   224,     0,
       0,     0,    99,   100,   225,     5,     0,     0,     0,    93,
      94,    95,     0,    96,     0,    97,    98,     0,   223,     2,
       3,     0,     4,     0,     0,     0,     0,     0,   224,     0,
       0,     0,    99,   100,   225,     5,   101,   102,     0,     0,
     103,     0,     0,   104,     0,     0,     0,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,   294,   108,   101,   102,     0,     0,
     103,     0,     0,   104,     0,     0,     0,     0,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,   302,   108,    93,    94,    95,     0,
      96,     0,    97,    98,     0,   223,     2,     3,     0,     4,
       0,     0,     0,     0,     0,   224,     0,     0,     0,    99,
     100,   225,     5,    93,    94,    95,     0,    96,     0,    97,
      98,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,    99,   100,    44,     5,
       0,     0,    39,   101,   102,     0,     0,   103,     0,     0,
     104,     0,     0,     0,     0,     0,   105,   106,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
     101,   102,   108,     0,   103,     0,     0,   104,     0,     0,
       0,     0,     0,   105,   106,    93,    94,    95,     0,    96,
       0,    97,    98,     0,     0,   107,     0,    21,    85,   108,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
      44,    93,    94,    95,   156,    96,     0,    97,    98,     0,
       0,   157,   158,   159,   160,   161,     0,     0,   162,   163,
     164,   165,     0,     0,    99,   100,    44,     0,     0,   166,
     167,   168,   101,   102,     0,     0,   103,     0,     0,   104,
       0,     0,     0,     0,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,   101,   102,
     147,   108,   103,     0,     0,   104,     0,     0,     0,     0,
       0,   105,   106,    93,    94,    95,     0,    96,     0,    97,
      98,     0,     0,   107,     0,     0,   183,   108,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     0,     0,
     101,   102,     0,     0,   103,     0,    39,   104,     0,     0,
      40,    41,    42,   105,   106,    43,     0,     0,     0,     0,
       0,     0,     0,    44,     0,   107,    45,     0,     0,   108,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,     0,    40,    41,    42,     0,    61,
      62,     0,    46,    47,     0,     0,     0,     0,    44,     0,
      48,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,    39,     0,     0,     0,    40,    41,    42,     0,
       0,    43,     0,     0,     0,     0,     0,    46,    47,    44,
     154,   155,   156,     0,     0,    48,     0,     0,     0,   157,
     158,   159,   160,   161,     0,     0,   162,   163,   164,   165,
       0,     0,     0,     0,     0,     0,     0,   166,   167,   168,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
       0,     0,   217,   154,   155,   156,    48,     0,     0,     0,
       0,     0,   157,   158,   159,   160,   161,     0,     0,   162,
     163,   164,   165,     0,     0,     0,   154,   155,   156,     0,
     166,   167,   168,     0,     0,   157,   158,   159,   160,   161,
       0,   180,   162,   163,   164,   165,     0,     0,     0,     0,
       0,     0,     0,   166,   167,   168,   157,   158,   159,   160,
     161,     0,     0,   162,   163,   164,   165,     0,     0,     0,
       0,     0,     0,     0,   166,   167,   168
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-224)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    88,    10,    36,    15,    13,    45,     2,     8,    40,
     233,    42,   108,    39,    42,    43,    45,    43,    43,    15,
      16,    43,    18,    45,    42,    42,    43,    83,   210,    40,
     208,    42,   236,    45,    99,    46,    47,    42,    59,    45,
      90,    42,    45,    45,    40,    68,    42,    45,    45,    99,
      46,    47,    48,   149,   150,   233,     0,     0,   236,   282,
     264,   243,    85,   102,   287,     8,    42,    78,   124,    90,
     103,   100,    68,   104,   102,   101,   101,   300,    42,   101,
      91,    99,    78,    83,    84,   102,   264,   174,    83,    85,
     102,    42,    87,    88,    59,    91,   102,   100,   100,   277,
      45,   279,   100,   100,   282,     0,     1,    90,   277,   287,
     279,   122,   103,    58,    59,    90,    99,   235,   126,   297,
     103,    82,   300,   219,   124,    90,   122,   223,   297,   124,
     130,   249,    27,    28,    99,    30,    27,    28,   103,    30,
     101,   102,   103,   104,   105,   106,   107,   108,    43,    45,
      42,    43,    43,    39,   150,   251,   252,   168,    59,    45,
     290,   103,    58,    59,    21,   295,    23,   178,   179,    37,
      38,   167,   168,    78,    79,    80,    81,   172,    21,   174,
      23,   103,   178,   179,    89,    90,    91,    99,   149,   150,
     151,   202,   102,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   202,   104,   208,   220,
      42,   207,   220,   100,   210,   223,    89,    90,    91,   215,
     296,    45,   298,   102,   220,    37,    38,    99,    45,   100,
     100,   100,    99,   233,   100,   246,   236,   245,   103,   100,
      39,   103,   102,   102,    42,    35,   254,   243,   103,   257,
     246,   102,   213,    36,     8,    16,   286,   265,   219,    16,
     124,   172,   223,   215,   264,   115,   274,   130,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,   279,
      -1,    -1,   282,    -1,    -1,    -1,    -1,   287,    -1,   250,
     251,   252,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,
     300,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,   290,
      -1,    34,    -1,    -1,   295,    -1,    -1,    -1,    -1,    42,
      -1,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    81,    82,
      42,    43,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
     103,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    25,    -1,    -1,    89,    29,    30,
      31,    -1,    -1,    34,    -1,    -1,    -1,    99,    -1,   101,
      -1,    42,    17,    18,    19,    -1,    21,    -1,    23,    24,
      -1,    26,    27,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    99,    74,
      75,    -1,    -1,    78,    25,    -1,    81,    -1,    -1,    -1,
      -1,    -1,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    99,    -1,    -1,   102,   103,    17,
      18,    19,    -1,    21,    -1,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    -1,    23,    24,    -1,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    74,    75,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,   102,   103,    74,    75,    -1,    -1,
      78,    -1,    -1,    81,    -1,    -1,    -1,    -1,    -1,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,   102,   103,    17,    18,    19,    -1,
      21,    -1,    23,    24,    -1,    26,    27,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    17,    18,    19,    -1,    21,    -1,    23,
      24,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    40,    41,    42,    43,
      -1,    -1,    25,    74,    75,    -1,    -1,    78,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      74,    75,   103,    -1,    78,    -1,    -1,    81,    -1,    -1,
      -1,    -1,    -1,    87,    88,    17,    18,    19,    -1,    21,
      -1,    23,    24,    -1,    -1,    99,    -1,   101,    81,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    17,    18,    19,    64,    21,    -1,    23,    24,    -1,
      -1,    71,    72,    73,    74,    75,    -1,    -1,    78,    79,
      80,    81,    -1,    -1,    40,    41,    42,    -1,    -1,    89,
      90,    91,    74,    75,    -1,    -1,    78,    -1,    -1,    81,
      -1,    -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    74,    75,
     102,   103,    78,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      -1,    87,    88,    17,    18,    19,    -1,    21,    -1,    23,
      24,    -1,    -1,    99,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      74,    75,    -1,    -1,    78,    -1,    25,    81,    -1,    -1,
      29,    30,    31,    87,    88,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    99,    45,    -1,    -1,   103,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    81,    82,    -1,    -1,    -1,    -1,    42,    -1,
      89,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    81,    82,    42,
      62,    63,    64,    -1,    -1,    89,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    -1,    -1,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,   104,    62,    63,    64,    89,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,    78,
      79,    80,    81,    -1,    -1,    -1,    62,    63,    64,    -1,
      89,    90,    91,    -1,    -1,    71,    72,    73,    74,    75,
      -1,   100,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    71,    72,    73,    74,
      75,    -1,    -1,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    28,    30,    43,   106,   107,   109,   111,
     112,   113,   114,   140,    42,   110,    42,    99,   141,     0,
     114,   101,   107,   108,   108,   108,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    25,
      29,    30,    31,    34,    42,    45,    81,    82,    89,   129,
     130,   138,   148,   149,   150,   151,   152,   153,   155,   156,
     157,    33,    34,   130,   131,   134,   138,   139,    42,   129,
     149,   147,   149,   103,    42,   149,   149,    40,   104,   129,
     154,    90,    59,   103,   103,    81,   156,    99,    99,   102,
     149,   104,    42,    17,    18,    19,    21,    23,    24,    40,
      41,    74,    75,    78,    81,    87,    88,    99,   103,   129,
     158,   159,   160,   161,   164,   165,   166,   167,   168,   169,
     170,   107,   110,   135,   136,   137,   143,   144,    42,   107,
     132,   133,   156,   100,   142,   143,   142,   149,   167,   168,
     167,   167,   167,   167,   167,   167,   167,   102,   159,    99,
     103,    45,    21,   164,    62,    63,    64,    71,    72,    73,
      74,    75,    78,    79,    80,    81,    89,    90,    91,   149,
     135,   102,    45,   108,    99,   102,   133,   100,   100,   100,
     100,   102,   159,   102,   129,   159,   162,   163,   167,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     167,   167,    99,   129,   149,   144,   142,    99,   103,   149,
      99,   149,   100,    59,   102,    45,   102,   104,   149,    99,
     100,   146,   149,    26,    36,    42,   107,   110,   113,   117,
     125,   126,   127,   128,   145,   170,   103,   146,   167,   129,
     163,   100,   159,    99,   108,   149,    45,   100,   108,   159,
     118,    58,    59,    39,   124,   127,   102,   124,   145,   100,
     100,   146,   108,   149,   103,   124,   115,   167,   159,   159,
      42,   108,   108,   102,   100,   145,   108,    35,   116,   103,
     108,   102,   128,    37,    38,   119,   122,   128,   102,    36,
     120,    37,   119,   123,   102,   121,   115,   103,   115,   116,
     128,   116,   102
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


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    { yoParserEnd(&(yyval), parm); }
    break;

  case 3:

    { yoParseEmpty(&(yyval), parm); yoParserEnd(&(yyval), parm); }
    break;

  case 4:

    { yoParserError(&(yyval), yymsgbuf, parm); yyclearin; yyerrok; }
    break;

  case 5:

    { yoParserNewLine(parm); yoParseEmpty(&(yyval), parm); }
    break;

  case 7:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 9:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 11:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 12:

    { yoParserDeclVar(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 13:

    {
				yoParserDeclVar(&(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm); 
				yoParserBinOp(&(yyvsp[(2) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(5) - (5)]), T_ASSIGN, parm); 
				yoParserList(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), parm);
			}
    break;

  case 14:

    { yoParserDeclType(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 21:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 22:

    { yoParserEnableBrace(parm); }
    break;

  case 23:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm);
		}
    break;

  case 24:

    { yoParserEnableBrace(parm); }
    break;

  case 25:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm); }
    break;

  case 26:

    { yoParserEnableBrace(parm); }
    break;

  case 27:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm); }
    break;

  case 29:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 30:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 31:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 32:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 33:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm); }
    break;

  case 34:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 35:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm); }
    break;

  case 36:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DECL_ASSIGN, parm); }
    break;

  case 38:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (4)]), parm); yoParserStmtCatch(&(yyval), &(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 39:

    { yoParserStmtReturn(&(yyval), NULL, parm); }
    break;

  case 41:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 42:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 46:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 48:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 49:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), parm); }
    break;

  case 51:

    { yoParserContract(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 53:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 54:

    { yoParserContractFunc(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), NULL, parm); }
    break;

  case 55:

    { yoParserContractFunc(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm); }
    break;

  case 56:

    { yoParserContractFunc(&(yyval), &(yyvsp[(1) - (8)]), &(yyvsp[(3) - (8)]), &(yyvsp[(6) - (8)]), parm); }
    break;

  case 58:

    { yoParserClass(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 62:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 64:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 75:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm); }
    break;

  case 76:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm); }
    break;

  case 77:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (12)]), &(yyvsp[(3) - (12)]), &(yyvsp[(5) - (12)]), &(yyvsp[(8) - (12)]), &(yyvsp[(11) - (12)]), parm); }
    break;

  case 78:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 79:

    { yoParserTypePtr(&(yyvsp[(3) - (5)]), &(yyvsp[(4) - (5)]), parm); yoParserDeclArg(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm); }
    break;

  case 80:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 82:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 84:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 85:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 87:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 89:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 90:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 91:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm); }
    break;

  case 92:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm); }
    break;

  case 93:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (8)]), &(yyvsp[(4) - (8)]), &(yyvsp[(7) - (8)]), parm); }
    break;

  case 96:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 97:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 98:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 99:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm); yoParserTypePtr(&(yyval), &(yyval), parm); }
    break;

  case 100:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 103:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm); }
    break;

  case 105:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (1)]), parm); }
    break;

  case 106:

    { yoParserTypeStdName(&(yyval), T_INT8, parm); }
    break;

  case 107:

    { yoParserTypeStdName(&(yyval), T_INT16, parm); }
    break;

  case 108:

    { yoParserTypeStdName(&(yyval), T_INT32, parm); }
    break;

  case 109:

    { yoParserTypeStdName(&(yyval), T_INT64, parm); }
    break;

  case 110:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm); }
    break;

  case 111:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm); }
    break;

  case 112:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm); }
    break;

  case 113:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm); }
    break;

  case 114:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm); }
    break;

  case 115:

    { yoParserTypeStdName(&(yyval), T_STRING, parm); }
    break;

  case 116:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm); }
    break;

  case 117:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm); }
    break;

  case 118:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm); }
    break;

  case 119:

    { yoParserTypeStdName(&(yyval), T_VOID, parm); }
    break;

  case 120:

    { yoParserConst(&(yyval), T_TRUE, parm); }
    break;

  case 121:

    { yoParserConst(&(yyval), T_FALSE, parm); }
    break;

  case 122:

    { yoParserConst(&(yyval), T_NULL, parm); }
    break;

  case 128:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 129:

    { yoParserNewArr(&(yyval), parm); }
    break;

  case 130:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 131:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm); }
    break;

  case 132:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 133:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 135:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 136:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm); }
    break;

  case 137:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 139:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 140:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 148:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm); }
    break;

  case 149:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm); }
    break;

  case 150:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm); }
    break;

  case 151:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm); }
    break;

  case 152:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm); }
    break;

  case 153:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm); }
    break;

  case 154:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm); }
    break;

  case 155:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm); }
    break;

  case 156:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm); }
    break;

  case 157:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm); }
    break;

  case 158:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm); }
    break;

  case 159:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm); }
    break;

  case 160:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XORXOR, parm); }
    break;

  case 161:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm); }
    break;

  case 162:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 164:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 165:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm); }
    break;

  case 166:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm); }
    break;

  case 167:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm); }
    break;

  case 168:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm); }
    break;

  case 169:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm); }
    break;

  case 170:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm); }
    break;

  case 171:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm); }
    break;

  case 172:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 173:

    { 
			yoParserBinOp(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(3) - (6)]), T_DOT, parm);
			yoParserCall(&(yyval), &(yyval), &(yyvsp[(5) - (6)]), parm);
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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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




