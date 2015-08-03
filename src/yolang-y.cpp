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
void yoParserTypePtr(YYSTYPE * r, YYSTYPE * a, void * parm);
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
void yoParserInterfaceFunc(YYSTYPE * r, YYSTYPE * name, YYSTYPE * args, YYSTYPE * type, void*);
void yoParserInterface(YYSTYPE * r, YYSTYPE * a, void * parm);
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
     T_FUNC = 284,
     T_CONST = 285,
     T_STRUCT = 286,
     T_CLASS = 287,
     T_INTERFACE = 288,
     T_BRACE = 289,
     T_IF = 290,
     T_ELSE = 291,
     T_ELSEIF = 292,
     T_LNUMBER = 293,
     T_DNUMBER = 294,
     T_NAME = 295,
     T_NEWLINE = 296,
     T_FIX = 297,
     T_POW_ASSIGN = 298,
     T_RSH_ASSIGN = 299,
     T_LSH_ASSIGN = 300,
     T_XOR_ASSIGN = 301,
     T_OR_ASSIGN = 302,
     T_AND_ASSIGN = 303,
     T_MOD_ASSIGN = 304,
     T_CONCAT_ASSIGN = 305,
     T_DIV_ASSIGN = 306,
     T_MUL_ASSIGN = 307,
     T_MINUS_ASSIGN = 308,
     T_PLUS_ASSIGN = 309,
     T_DECL_ASSIGN = 310,
     T_ASSIGN = 311,
     T_XORXOR = 312,
     T_OROR = 313,
     T_ANDAND = 314,
     T_GT = 315,
     T_LT = 316,
     T_GE = 317,
     T_LE = 318,
     T_NE = 319,
     T_EQ = 320,
     T_CONCAT = 321,
     T_XOR = 322,
     T_OR = 323,
     T_MINUS = 324,
     T_PLUS = 325,
     T_RSH = 326,
     T_LSH = 327,
     T_AND = 328,
     T_MOD = 329,
     T_DIV = 330,
     T_MUL = 331,
     T_POW = 332,
     T_IS = 333,
     T_UNARY = 334,
     T_DEC = 335,
     T_INC = 336,
     T_TILDE = 337,
     T_NOT = 338,
     T_DOT = 339,
     T_AT = 340,
     T_INDIRECT = 341,
     T_ADDR = 342,
     T_INDEX = 343,
     T_PTR = 344,
     T_ARR = 345,
     T_DOTNAME = 346,
     NotParen = 347
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
#define YYLAST   709

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNRULES -- Number of states.  */
#define YYNSTATES  267

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   347

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      97,    98,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    99,
       2,     2,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    87,     2,   102,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   101,     2,   100,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    88,
      89,    90,    91,    92,    93,    94,    95,    96
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    16,
      19,    21,    25,    29,    35,    39,    42,    45,    48,    50,
      52,    56,    59,    61,    65,    66,    73,    74,    79,    80,
      86,    88,    91,    92,    97,    98,   100,   102,   104,   109,
     111,   113,   115,   118,   120,   124,   128,   130,   135,   137,
     140,   146,   153,   162,   164,   169,   172,   174,   176,   179,
     181,   182,   184,   186,   188,   190,   192,   194,   196,   198,
     208,   219,   232,   237,   243,   244,   246,   247,   249,   253,
     256,   258,   259,   261,   265,   266,   272,   279,   288,   290,
     292,   295,   298,   302,   304,   306,   311,   313,   315,   317,
     319,   321,   323,   325,   327,   329,   331,   333,   335,   337,
     339,   341,   343,   345,   347,   349,   351,   353,   355,   357,
     359,   363,   366,   370,   374,   379,   384,   386,   390,   394,
     397,   399,   402,   405,   407,   409,   411,   413,   415,   417,
     419,   423,   427,   431,   435,   439,   443,   447,   452,   456,
     458,   461,   464,   467,   470,   473,   476,   481
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     104,     0,    -1,   107,    -1,    -1,     1,    -1,    41,    -1,
     105,    -1,    99,    -1,   112,    -1,   107,   112,    -1,    40,
      -1,   108,    43,    40,    -1,    27,   108,   146,    -1,    27,
     108,   146,    57,   154,    -1,    28,    40,   136,    -1,   109,
     106,    -1,   110,   106,    -1,   137,   106,    -1,   111,    -1,
     105,    -1,    26,   154,   106,    -1,    26,   106,    -1,   162,
      -1,    34,   125,   100,    -1,    -1,    35,   117,   114,   115,
     121,   122,    -1,    -1,    37,   119,   114,   115,    -1,    -1,
      36,    35,   120,   114,   115,    -1,   118,    -1,   121,   118,
      -1,    -1,    36,   101,   125,   100,    -1,    -1,   111,    -1,
     113,    -1,   116,    -1,   108,    57,   154,   106,    -1,   123,
      -1,   105,    -1,   124,    -1,   125,   124,    -1,    40,    -1,
     126,    88,    40,    -1,    33,   101,   100,    -1,   127,    -1,
      33,   101,   129,   100,    -1,   130,    -1,   129,   130,    -1,
      40,    97,   139,    98,   106,    -1,    40,    97,   139,    98,
     146,   106,    -1,    40,    97,   139,    98,    97,   143,    98,
     106,    -1,   105,    -1,    32,   101,   134,   100,    -1,   140,
     106,    -1,   105,    -1,   132,    -1,   133,   132,    -1,   133,
      -1,    -1,   151,    -1,   147,    -1,   148,    -1,   150,    -1,
     145,    -1,   135,    -1,   128,    -1,   131,    -1,    29,   138,
     126,    97,   139,    98,   101,   142,   100,    -1,    29,   138,
     126,    97,   139,    98,   146,   101,   142,   100,    -1,    29,
     138,   126,    97,   139,    98,    97,   143,    98,   101,   142,
     100,    -1,    97,    40,   151,    98,    -1,    97,    40,    79,
     151,    98,    -1,    -1,   140,    -1,    -1,   141,    -1,   140,
      43,   141,    -1,   108,   146,    -1,   125,    -1,    -1,   146,
      -1,   143,    43,   146,    -1,    -1,    29,   144,    97,   139,
      98,    -1,    29,   144,    97,   139,    98,   146,    -1,    29,
     144,    97,   139,    98,    97,   143,    98,    -1,   135,    -1,
     127,    -1,    79,   146,    -1,    80,   146,    -1,    87,   102,
     146,    -1,    38,    -1,   126,    -1,    87,   149,   102,   146,
      -1,   152,    -1,   126,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,
      -1,    12,    -1,    15,    -1,    13,    -1,    14,    -1,    16,
      -1,    25,    -1,    17,    -1,    18,    -1,    24,    -1,    38,
      -1,    39,    -1,    19,    -1,    21,    -1,   162,    -1,   154,
      43,   162,    -1,   101,   100,    -1,   101,   154,   100,    -1,
     126,   101,   100,    -1,   126,   101,   154,   100,    -1,   126,
     101,   157,   100,    -1,   158,    -1,   157,    43,   158,    -1,
     126,    57,   162,    -1,    23,   163,    -1,   159,    -1,   160,
     159,    -1,   160,    21,    -1,   163,    -1,   161,    -1,   153,
      -1,   155,    -1,   156,    -1,   126,    -1,   164,    -1,   162,
      73,   162,    -1,   162,    72,   162,    -1,   162,    79,   162,
      -1,   162,    78,   162,    -1,   162,    77,   162,    -1,   162,
      69,   162,    -1,   162,    88,   126,    -1,   162,    87,   162,
     102,    -1,    97,   162,    98,    -1,   165,    -1,    73,   162,
      -1,    72,   162,    -1,    86,   162,    -1,    85,   162,    -1,
      79,   162,    -1,    76,   162,    -1,   126,    97,   154,    98,
      -1,   162,    88,   126,    97,   154,    98,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   176,   177,   180,   183,   184,   187,   188,
     191,   192,   195,   196,   203,   206,   207,   208,   211,   212,
     215,   216,   227,   230,   233,   233,   238,   238,   239,   239,
     242,   243,   244,   247,   248,   251,   252,   253,   254,   257,
     258,   261,   262,   265,   266,   269,   272,   273,   276,   277,
     280,   281,   282,   283,   286,   290,   291,   294,   295,   298,
     299,   302,   303,   304,   305,   306,   309,   310,   311,   314,
     316,   318,   322,   323,   324,   327,   328,   331,   332,   335,
     338,   339,   342,   343,   346,   349,   350,   351,   354,   355,
     358,   359,   366,   369,   370,   373,   376,   377,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   396,   397,   398,   399,   400,   401,   402,   405,
     406,   409,   410,   413,   414,   415,   418,   419,   422,   425,
     428,   429,   432,   435,   436,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     456,   457,   458,   459,   460,   461,   465,   466
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
  "T_RETURN", "T_VAR", "T_TYPE", "T_FUNC", "T_CONST", "T_STRUCT",
  "T_CLASS", "T_INTERFACE", "T_BRACE", "T_IF", "T_ELSE", "T_ELSEIF",
  "T_LNUMBER", "T_DNUMBER", "T_NAME", "T_NEWLINE", "T_FIX", "','",
  "\"**= (T_POW_ASSIGN)\"", "\">>= (T_RSH_ASSIGN)\"",
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
  "\"/ (T_DIV)\"", "\"* (T_MUL)\"", "\"** (T_POW)\"", "\"is (T_IS)\"",
  "T_UNARY", "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "\"~ (T_TILDE)\"",
  "\"! (T_NOT)\"", "'['", "\". (T_DOT)\"", "\"@ (T_AT)\"",
  "\"* (T_INDIRECT)\"", "\"& (T_ADDR)\"", "\"[] (T_INDEX)\"", "T_PTR",
  "T_ARR", "T_DOTNAME", "NotParen", "'('", "')'", "';'", "'}'", "'{'",
  "']'", "$accept", "file", "newline", "end_stmt", "top_stmt_list",
  "name_list", "top_decl_var", "decl_type", "top_stmt_no_newline",
  "top_stmt", "ret_stmt", "if_header", "brace_stmt", "if_stmt", "$@1",
  "elseif", "$@2", "$@3", "elseif_list", "else", "stmt_no_newline", "stmt",
  "stmt_list", "dotname", "type_interface_empty", "type_interface",
  "interface_body", "interface_decl_func", "type_class", "class_body_stmt",
  "class_body_stmt_list", "class_body", "type_base", "type_ext",
  "top_decl_func", "decl_self", "decl_arg_list_or_empty", "decl_arg_list",
  "decl_arg", "func_body", "type_list", "decl_self_nop", "type_func",
  "type", "type_ptr", "type_slice", "type_arr_size", "type_arr",
  "type_name", "type_std_name", "expr_const_scalar", "expr_list",
  "expr_arr", "expr_obj", "prop_assing_list", "prop_assing",
  "qstr_with_inject_begin_elem", "qstr_with_inject_begin_list",
  "qstr_with_inject", "expr", "expr_base", "uexpr", "call", YY_NULL
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
     295,   296,   297,    44,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,    63,    58,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,    91,   339,   340,
     341,   342,   343,   344,   345,   346,   347,    40,    41,    59,
     125,   123,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   104,   104,   105,   106,   106,   107,   107,
     108,   108,   109,   109,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   115,   117,   116,   119,   118,   120,   118,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   128,   128,   129,   129,
     130,   130,   130,   130,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   135,   136,   136,   136,   137,
     137,   137,   138,   138,   138,   139,   139,   140,   140,   141,
     142,   142,   143,   143,   144,   145,   145,   145,   146,   146,
     147,   147,   148,   149,   149,   150,   151,   151,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   153,   153,   153,   153,   153,   153,   153,   154,
     154,   155,   155,   156,   156,   156,   157,   157,   158,   159,
     160,   160,   161,   162,   162,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     164,   164,   164,   164,   164,   164,   165,   165
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     5,     3,     2,     2,     2,     1,     1,
       3,     2,     1,     3,     0,     6,     0,     4,     0,     5,
       1,     2,     0,     4,     0,     1,     1,     1,     4,     1,
       1,     1,     2,     1,     3,     3,     1,     4,     1,     2,
       5,     6,     8,     1,     4,     2,     1,     1,     2,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     9,
      10,    12,     4,     5,     0,     1,     0,     1,     3,     2,
       1,     0,     1,     3,     0,     5,     6,     8,     1,     1,
       2,     2,     3,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     4,     4,     1,     3,     3,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     1,
       2,     2,     2,     2,     2,     2,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,    74,     5,     0,    19,     2,     0,
       0,    18,     8,     0,    10,     0,     0,     0,     0,     1,
       9,     7,     6,    15,    16,    17,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   108,   109,   107,   110,   111,
      84,     0,    43,     0,     0,     0,     0,    97,    89,    88,
      65,    12,    62,    63,    64,    61,    96,     0,     0,    46,
      67,    68,    66,    14,     0,     0,     0,     0,    11,    90,
      91,    93,     0,    94,     0,     0,     0,    60,     0,     0,
       0,    76,    76,    45,    92,     0,    44,   112,   113,   117,
     118,     0,   114,   115,   116,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   135,    13,   136,   137,   130,     0,
     134,   119,   133,   139,   149,    56,     0,    57,    59,     0,
       0,    77,     0,    53,     0,    48,     0,    72,     0,    75,
       0,    95,     0,   133,   151,   150,   155,   154,   153,   152,
       0,   121,     0,     0,     0,     0,   132,   131,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    58,    54,     0,
      55,    76,    47,    49,    73,     0,    85,   148,   122,     0,
     123,   138,     0,     0,   126,   120,   145,   141,   140,   144,
     143,   142,     0,   146,    78,     0,     0,    81,     0,     0,
      86,   156,     0,   124,     0,   125,   147,     0,     0,     0,
      82,     0,    24,    40,     0,    35,    36,    37,    39,    41,
      80,     0,    81,     0,   128,     0,   127,     0,     0,    50,
       0,     0,     0,    21,     0,     0,     0,    42,    69,     0,
      87,   157,     0,    51,    83,    81,    20,     0,    22,     0,
      70,     0,     0,     0,    32,    38,    52,    71,     0,     0,
      26,    30,    34,    23,    28,     0,     0,    31,    25,     0,
       0,     0,     0,    27,     0,    29,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    22,    23,     8,   204,     9,    10,   205,    12,
     206,   237,   244,   207,   225,   251,   255,   259,   252,   258,
     208,   209,   210,   103,    48,    60,   124,   125,    61,   117,
     118,   119,    49,    63,    13,    18,   128,   129,   121,   211,
     199,    66,    50,   200,    52,    53,    74,    54,    55,    56,
     104,   105,   106,   107,   173,   174,   108,   109,   110,   111,
     112,   113,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -205
static const yytype_int16 yypact[] =
{
     195,  -205,    44,    86,   -47,  -205,   137,  -205,   172,   -29,
     -29,  -205,  -205,   -29,  -205,   527,   584,   114,   127,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,  -205,
    -205,    69,  -205,   135,   621,   621,    27,    90,  -205,  -205,
    -205,   133,  -205,  -205,  -205,  -205,  -205,   106,   108,  -205,
    -205,  -205,  -205,  -205,    12,    80,   124,   131,  -205,  -205,
    -205,  -205,   621,    90,   125,   193,   486,   142,   -11,   669,
     136,    44,    44,  -205,  -205,   621,  -205,  -205,  -205,  -205,
    -205,   486,  -205,  -205,  -205,   486,   486,   486,   486,   486,
     486,   486,   393,    83,  -205,   196,  -205,  -205,  -205,   165,
    -205,   168,  -205,  -205,  -205,  -205,   527,  -205,   142,   138,
     -28,  -205,   145,  -205,    -6,  -205,   146,  -205,   151,   207,
     153,  -205,   168,   170,   110,   110,   110,   110,   110,   110,
     247,  -205,    -7,   486,   478,   486,  -205,  -205,   486,   486,
     486,   486,   486,   486,   486,   127,  -205,  -205,  -205,    44,
    -205,    44,  -205,  -205,  -205,   261,   359,  -205,  -205,   -34,
    -205,    68,    10,    15,  -205,   168,   141,   141,   141,   110,
     110,   110,    72,   155,  -205,   156,   621,   252,   152,   621,
    -205,  -205,   486,  -205,   127,  -205,  -205,   486,   298,     6,
    -205,   385,  -205,  -205,    73,  -205,  -205,  -205,  -205,  -205,
     252,   157,   252,    30,   168,    70,  -205,    37,   621,  -205,
     -29,   621,   158,  -205,    47,   486,   486,  -205,  -205,   160,
    -205,  -205,    59,  -205,  -205,   252,  -205,   224,   168,    47,
    -205,   -29,   162,   252,   167,  -205,  -205,  -205,    34,   228,
    -205,  -205,   189,  -205,  -205,   486,   -25,  -205,  -205,   486,
     224,   252,   224,  -205,    79,  -205,  -205
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -205,  -205,     0,    -9,  -205,     5,  -205,  -205,   140,   274,
    -205,  -112,   -46,  -205,  -205,    31,  -205,  -205,  -205,  -205,
    -205,  -131,  -204,   -13,   268,  -205,  -205,   161,  -205,   171,
    -205,  -205,   272,  -205,  -205,  -205,   -76,    45,   132,   -80,
    -135,  -205,  -205,    -4,  -205,  -205,  -205,  -205,    57,  -205,
    -205,   -88,  -205,  -205,  -205,   101,   187,  -205,  -205,   -53,
     206,  -205,  -205
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -130
static const yytype_int16 yytable[] =
{
       7,    24,    47,    47,    25,    65,   130,    15,     7,   145,
     254,    51,     5,     5,   142,   159,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   122,
       5,    47,    47,    73,   122,     5,   145,    39,   132,   248,
      69,    70,   134,   135,   136,   137,   138,   139,   140,   221,
      17,    47,    42,   145,   213,   169,   172,   264,   194,    47,
     201,     2,     3,     4,   191,    71,    47,    42,    84,   202,
      21,    21,    47,   221,    14,     5,   261,   115,   123,   227,
     145,   131,   116,   232,    14,   185,   116,   116,     5,    83,
     145,    79,   175,   168,   162,   176,   177,   178,   179,   180,
     181,   182,   221,    47,   222,   201,     2,     3,     4,   217,
     193,   160,   156,   224,   202,   195,    43,   227,   115,    14,
       5,    80,   120,   116,   123,   192,    16,   192,   230,    72,
     226,   171,   229,   227,   253,   231,   126,    19,   239,   214,
      11,   148,   183,   260,   149,   150,    21,   262,    11,   151,
     152,   153,    47,    47,    64,   242,    75,   241,    75,   154,
     155,   188,   190,   120,   116,   143,   116,    42,    75,   144,
      67,    75,   238,    47,   196,    68,    47,    81,    75,   266,
     143,   215,    14,     5,   144,    47,   146,   203,    91,   219,
      76,  -129,   223,  -129,   220,    -3,     1,   154,   155,     2,
       3,     4,   238,   249,   250,    47,   238,    77,    47,    78,
     203,   233,   203,     5,   263,   236,   265,   234,   151,   152,
     153,    82,     2,     3,     4,   256,   250,    85,   154,   155,
     245,    83,   246,    86,   127,   203,     5,   148,   158,   145,
     149,   150,   161,   203,   164,   151,   152,   153,   203,   165,
     159,   166,   197,   212,   198,   154,   155,   228,   243,   235,
     240,   203,   247,   254,   203,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,   201,     2,
       3,     4,    20,   257,    59,   163,    39,   202,    62,   157,
      40,   184,    14,     5,    41,   216,   147,   133,     0,     0,
       0,    42,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,     0,   148,     0,     0,   149,
     150,     0,     0,    39,   151,   152,   153,    40,     0,     0,
       0,    41,     0,     0,   154,   155,     0,     0,    42,     5,
      44,    45,     0,     0,     0,   167,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
       0,     0,   187,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,    44,    45,     0,
       0,     0,     0,     0,    39,    46,     0,     0,    40,     0,
       0,     0,    41,     0,     0,   218,     0,    21,     0,    42,
       0,     0,    87,    88,    89,     0,    90,     0,    91,    92,
      87,    88,    89,     0,    90,     0,    91,    92,     0,     0,
       0,     0,     0,    93,    94,    42,     5,     0,     0,     0,
       0,    93,    94,    42,     0,     0,     0,     0,    44,    45,
       0,     0,     0,     0,     0,     0,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   189,    95,    96,     0,
       0,    97,     0,     0,    98,    95,    96,     0,     0,    97,
      99,   100,    98,     0,     0,     0,     0,     0,    99,   100,
       0,     0,   101,     0,    21,     0,   102,     0,     0,     0,
     101,     0,     0,   141,   102,    87,    88,    89,     0,    90,
       0,    91,    92,    87,    88,    89,     0,    90,     0,    91,
      92,     0,     0,     0,     0,     0,    93,    94,    42,     0,
       0,     0,     0,     0,    93,    94,    42,     0,     0,     0,
       0,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,     0,     0,     0,     0,     0,     0,
      95,    96,    39,     0,    97,     0,    40,    98,    95,    96,
      41,     0,    97,    99,   100,    98,     0,    42,     0,     0,
      43,    99,   100,     0,     0,   101,     0,     0,   170,   102,
       0,     0,     0,   101,     0,     0,     0,   102,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,    44,    45,     0,    39,
       0,     0,     0,    40,    46,     0,    57,    58,     0,     0,
       0,     0,     0,     0,    42,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      40,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,    42,     0,    44,    45,     0,     0,     0,     0,     0,
       0,    46,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,     0,     0,
      44,    45,     0,     0,     0,     0,     0,     0,    46,    42
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-205)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    10,    15,    16,    13,    18,    82,     2,     8,    43,
      35,    15,    41,    41,   102,    43,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    40,
      41,    44,    45,    46,    40,    41,    43,    25,    91,   243,
      44,    45,    95,    96,    97,    98,    99,   100,   101,    43,
      97,    64,    40,    43,   189,   143,   144,   261,    43,    72,
      26,    27,    28,    29,    98,    38,    79,    40,    72,    35,
      99,    99,    85,    43,    40,    41,   101,    77,    78,   210,
      43,    85,    77,   218,    40,   161,    81,    82,    41,   100,
      43,    79,   145,   100,   100,   148,   149,   150,   151,   152,
     153,   154,    43,   116,    98,    26,    27,    28,    29,   197,
     100,   120,   116,   201,    35,   100,    43,   248,   118,    40,
      41,    64,    77,   118,   124,    57,    40,    57,    98,   102,
      57,   144,   212,   264,   100,    98,    79,     0,   226,   192,
       0,    69,   155,   255,    72,    73,    99,   259,     8,    77,
      78,    79,   165,   166,    40,   235,    88,    98,    88,    87,
      88,   165,   166,   118,   159,    97,   161,    40,    88,   101,
     101,    88,   225,   186,   102,    40,   189,    97,    88,   100,
      97,   194,    40,    41,   101,   198,    21,   187,    23,   198,
      57,    21,   201,    23,   198,     0,     1,    87,    88,    27,
      28,    29,   255,    36,    37,   218,   259,   101,   221,   101,
     210,   220,   212,    41,   260,   224,   262,   221,    77,    78,
      79,    97,    27,    28,    29,    36,    37,   102,    87,    88,
     239,   100,   241,    40,    98,   235,    41,    69,   100,    43,
      72,    73,    97,   243,    98,    77,    78,    79,   248,    98,
      43,    98,    97,   101,    98,    87,    88,   100,    34,   101,
     100,   261,   100,    35,   264,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    26,    27,
      28,    29,     8,   252,    16,   124,    25,    35,    16,   118,
      29,   159,    40,    41,    33,   194,   109,    91,    -1,    -1,
      -1,    40,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    69,    -1,    -1,    72,
      73,    -1,    -1,    25,    77,    78,    79,    29,    -1,    -1,
      -1,    33,    -1,    -1,    87,    88,    -1,    -1,    40,    41,
      79,    80,    -1,    -1,    -1,    98,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    79,    80,    -1,
      -1,    -1,    -1,    -1,    25,    87,    -1,    -1,    29,    -1,
      -1,    -1,    33,    -1,    -1,    97,    -1,    99,    -1,    40,
      -1,    -1,    17,    18,    19,    -1,    21,    -1,    23,    24,
      17,    18,    19,    -1,    21,    -1,    23,    24,    -1,    -1,
      -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    72,    73,    -1,
      -1,    76,    -1,    -1,    79,    72,    73,    -1,    -1,    76,
      85,    86,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    97,    -1,    99,    -1,   101,    -1,    -1,    -1,
      97,    -1,    -1,   100,   101,    17,    18,    19,    -1,    21,
      -1,    23,    24,    17,    18,    19,    -1,    21,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    25,    -1,    76,    -1,    29,    79,    72,    73,
      33,    -1,    76,    85,    86,    79,    -1,    40,    -1,    -1,
      43,    85,    86,    -1,    -1,    97,    -1,    -1,   100,   101,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    79,    80,    -1,    25,
      -1,    -1,    -1,    29,    87,    -1,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    40,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    87,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    28,    29,    41,   104,   105,   107,   109,
     110,   111,   112,   137,    40,   108,    40,    97,   138,     0,
     112,    99,   105,   106,   106,   106,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    25,
      29,    33,    40,    43,    79,    80,    87,   126,   127,   135,
     145,   146,   147,   148,   150,   151,   152,    32,    33,   127,
     128,   131,   135,   136,    40,   126,   144,   101,    40,   146,
     146,    38,   102,   126,   149,    88,    57,   101,   101,    79,
     151,    97,    97,   100,   146,   102,    40,    17,    18,    19,
      21,    23,    24,    38,    39,    72,    73,    76,    79,    85,
      86,    97,   101,   126,   153,   154,   155,   156,   159,   160,
     161,   162,   163,   164,   165,   105,   108,   132,   133,   134,
     140,   141,    40,   105,   129,   130,   151,    98,   139,   140,
     139,   146,   162,   163,   162,   162,   162,   162,   162,   162,
     162,   100,   154,    97,   101,    43,    21,   159,    69,    72,
      73,    77,    78,    79,    87,    88,   146,   132,   100,    43,
     106,    97,   100,   130,    98,    98,    98,    98,   100,   154,
     100,   126,   154,   157,   158,   162,   162,   162,   162,   162,
     162,   162,   162,   126,   141,   139,    97,   101,   146,    97,
     146,    98,    57,   100,    43,   100,   102,    97,    98,   143,
     146,    26,    35,   105,   108,   111,   113,   116,   123,   124,
     125,   142,   101,   143,   162,   126,   158,   154,    97,   106,
     146,    43,    98,   106,   154,   117,    57,   124,   100,   142,
      98,    98,   143,   106,   146,   101,   106,   114,   162,   154,
     100,    98,   142,    34,   115,   106,   106,   100,   125,    36,
      37,   118,   121,   100,    35,   119,    36,   118,   122,   120,
     114,   101,   114,   115,   125,   115,   100
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

  case 20:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 21:

    { yoParserStmtReturn(&(yyval), NULL, parm); }
    break;

  case 23:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 24:

    { yoParserEnableBrace(parm); }
    break;

  case 25:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm);
		}
    break;

  case 26:

    { yoParserEnableBrace(parm); }
    break;

  case 27:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm); }
    break;

  case 28:

    { yoParserEnableBrace(parm); }
    break;

  case 29:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm); }
    break;

  case 31:

    { yoParserElseIfList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 32:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 33:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 34:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 38:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_ASSIGN, parm); }
    break;

  case 42:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 44:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 45:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm); yoParserInterface(&(yyval), &(yyvsp[(1) - (3)]), parm); }
    break;

  case 47:

    { yoParserInterface(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 49:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 50:

    { yoParserInterfaceFunc(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), NULL, parm); }
    break;

  case 51:

    { yoParserInterfaceFunc(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm); }
    break;

  case 52:

    { yoParserInterfaceFunc(&(yyval), &(yyvsp[(1) - (8)]), &(yyvsp[(3) - (8)]), &(yyvsp[(6) - (8)]), parm); }
    break;

  case 54:

    { yoParserClass(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 58:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 60:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 69:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm); }
    break;

  case 70:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm); }
    break;

  case 71:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (12)]), &(yyvsp[(3) - (12)]), &(yyvsp[(5) - (12)]), &(yyvsp[(8) - (12)]), &(yyvsp[(11) - (12)]), parm); }
    break;

  case 72:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 73:

    { yoParserTypePtr(&(yyvsp[(3) - (5)]), &(yyvsp[(4) - (5)]), parm); yoParserDeclArg(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm); }
    break;

  case 74:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 76:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 78:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 79:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 81:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 83:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 84:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 85:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm); }
    break;

  case 86:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm); }
    break;

  case 87:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (8)]), &(yyvsp[(4) - (8)]), &(yyvsp[(7) - (8)]), parm); }
    break;

  case 90:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 91:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm); yoParserTypePtr(&(yyval), &(yyval), parm); }
    break;

  case 92:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 95:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm); }
    break;

  case 97:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (1)]), parm); }
    break;

  case 98:

    { yoParserTypeStdName(&(yyval), T_INT8, parm); }
    break;

  case 99:

    { yoParserTypeStdName(&(yyval), T_INT16, parm); }
    break;

  case 100:

    { yoParserTypeStdName(&(yyval), T_INT32, parm); }
    break;

  case 101:

    { yoParserTypeStdName(&(yyval), T_INT64, parm); }
    break;

  case 102:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm); }
    break;

  case 103:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm); }
    break;

  case 104:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm); }
    break;

  case 105:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm); }
    break;

  case 106:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm); }
    break;

  case 107:

    { yoParserTypeStdName(&(yyval), T_STRING, parm); }
    break;

  case 108:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm); }
    break;

  case 109:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm); }
    break;

  case 110:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm); }
    break;

  case 111:

    { yoParserTypeStdName(&(yyval), T_VOID, parm); }
    break;

  case 112:

    { yoParserConst(&(yyval), T_TRUE, parm); }
    break;

  case 113:

    { yoParserConst(&(yyval), T_FALSE, parm); }
    break;

  case 114:

    { yoParserConst(&(yyval), T_NULL, parm); }
    break;

  case 120:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 121:

    { yoParserNewArr(&(yyval), parm); }
    break;

  case 122:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 123:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm); }
    break;

  case 124:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 125:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 127:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 128:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm); }
    break;

  case 129:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 131:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 132:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 140:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm); }
    break;

  case 141:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm); }
    break;

  case 142:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm); }
    break;

  case 143:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm); }
    break;

  case 144:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm); }
    break;

  case 145:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm); }
    break;

  case 146:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm); }
    break;

  case 147:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm); }
    break;

  case 148:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 150:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm); }
    break;

  case 151:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm); }
    break;

  case 152:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm); }
    break;

  case 153:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm); }
    break;

  case 154:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm); }
    break;

  case 155:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm); }
    break;

  case 156:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 157:

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




