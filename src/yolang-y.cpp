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
     T_LNUMBER = 289,
     T_DNUMBER = 290,
     T_NAME = 291,
     T_NEWLINE = 292,
     T_FIX = 293,
     T_POW_ASSIGN = 294,
     T_RSH_ASSIGN = 295,
     T_LSH_ASSIGN = 296,
     T_XOR_ASSIGN = 297,
     T_OR_ASSIGN = 298,
     T_AND_ASSIGN = 299,
     T_MOD_ASSIGN = 300,
     T_CONCAT_ASSIGN = 301,
     T_DIV_ASSIGN = 302,
     T_MUL_ASSIGN = 303,
     T_MINUS_ASSIGN = 304,
     T_PLUS_ASSIGN = 305,
     T_DECL_ASSIGN = 306,
     T_ASSIGN = 307,
     T_XORXOR = 308,
     T_OROR = 309,
     T_ANDAND = 310,
     T_GT = 311,
     T_LT = 312,
     T_GE = 313,
     T_LE = 314,
     T_NE = 315,
     T_EQ = 316,
     T_CONCAT = 317,
     T_XOR = 318,
     T_OR = 319,
     T_MINUS = 320,
     T_PLUS = 321,
     T_RSH = 322,
     T_LSH = 323,
     T_AND = 324,
     T_MOD = 325,
     T_DIV = 326,
     T_MUL = 327,
     T_POW = 328,
     T_IS = 329,
     T_UNARY = 330,
     T_DEC = 331,
     T_INC = 332,
     T_TILDE = 333,
     T_NOT = 334,
     T_DOT = 335,
     T_AT = 336,
     T_INDIRECT = 337,
     T_ADDR = 338,
     T_INDEX = 339,
     T_PTR = 340,
     T_ARR = 341,
     T_DOTNAME = 342,
     NotParen = 343
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
#define YYLAST   768

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNRULES -- Number of states.  */
#define YYNSTATES  237

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      93,    94,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    95,
       2,     2,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    83,     2,    98,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    96,     2,    97,     2,     2,     2,     2,
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
      35,    36,    37,    38,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    84,    85,    86,    87,    88,
      89,    90,    91,    92
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    10,    12,    14,    16,
      19,    21,    25,    29,    35,    39,    42,    45,    50,    53,
      55,    57,    60,    62,    66,    69,    71,    75,    79,    81,
      86,    88,    91,    97,   104,   113,   115,   120,   123,   125,
     127,   130,   132,   133,   135,   137,   139,   141,   143,   145,
     147,   149,   159,   170,   183,   188,   194,   195,   197,   198,
     200,   204,   207,   209,   210,   212,   216,   217,   223,   230,
     239,   241,   243,   246,   249,   253,   255,   257,   262,   264,
     266,   268,   270,   272,   274,   276,   278,   280,   282,   284,
     286,   288,   290,   292,   294,   296,   298,   300,   302,   304,
     306,   308,   310,   314,   317,   321,   325,   330,   335,   337,
     341,   345,   348,   350,   353,   356,   358,   360,   362,   364,
     366,   368,   370,   374,   378,   382,   386,   390,   394,   398,
     403,   407,   409,   412,   415,   418,   421,   424,   427,   432
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     100,     0,    -1,   103,    -1,    -1,     1,    -1,    37,    -1,
     101,    -1,    95,    -1,   107,    -1,   103,   107,    -1,    36,
      -1,   104,    39,    36,    -1,    27,   104,   130,    -1,    27,
     104,   130,    53,   138,    -1,    28,    36,   120,    -1,   105,
     102,    -1,   106,   102,    -1,   104,    53,   138,   102,    -1,
     121,   102,    -1,   101,    -1,   109,    -1,   108,   109,    -1,
     107,    -1,    26,   138,   102,    -1,    26,   102,    -1,    36,
      -1,   110,    84,    36,    -1,    33,    96,    97,    -1,   111,
      -1,    33,    96,   113,    97,    -1,   114,    -1,   113,   114,
      -1,    36,    93,   123,    94,   102,    -1,    36,    93,   123,
      94,   130,   102,    -1,    36,    93,   123,    94,    93,   127,
      94,   102,    -1,   101,    -1,    32,    96,   118,    97,    -1,
     124,   102,    -1,   101,    -1,   116,    -1,   117,   116,    -1,
     117,    -1,    -1,   135,    -1,   131,    -1,   132,    -1,   134,
      -1,   129,    -1,   119,    -1,   112,    -1,   115,    -1,    29,
     122,   110,    93,   123,    94,    96,   126,    97,    -1,    29,
     122,   110,    93,   123,    94,   130,    96,   126,    97,    -1,
      29,   122,   110,    93,   123,    94,    93,   127,    94,    96,
     126,    97,    -1,    93,    36,   135,    94,    -1,    93,    36,
      75,   135,    94,    -1,    -1,   124,    -1,    -1,   125,    -1,
     124,    39,   125,    -1,   104,   130,    -1,   108,    -1,    -1,
     130,    -1,   127,    39,   130,    -1,    -1,    29,   128,    93,
     123,    94,    -1,    29,   128,    93,   123,    94,   130,    -1,
      29,   128,    93,   123,    94,    93,   127,    94,    -1,   119,
      -1,   111,    -1,    75,   130,    -1,    76,   130,    -1,    83,
      98,   130,    -1,    34,    -1,   110,    -1,    83,   133,    98,
     130,    -1,   136,    -1,   110,    -1,     4,    -1,     5,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    15,    -1,    13,    -1,    14,    -1,
      16,    -1,    25,    -1,    17,    -1,    18,    -1,    24,    -1,
      34,    -1,    35,    -1,    19,    -1,    21,    -1,   146,    -1,
     138,    39,   146,    -1,    96,    97,    -1,    96,   138,    97,
      -1,   110,    96,    97,    -1,   110,    96,   138,    97,    -1,
     110,    96,   141,    97,    -1,   142,    -1,   141,    39,   142,
      -1,   110,    53,   146,    -1,    23,   147,    -1,   143,    -1,
     144,   143,    -1,   144,    21,    -1,   147,    -1,   145,    -1,
     137,    -1,   139,    -1,   140,    -1,   110,    -1,   148,    -1,
     146,    69,   146,    -1,   146,    68,   146,    -1,   146,    75,
     146,    -1,   146,    74,   146,    -1,   146,    73,   146,    -1,
     146,    65,   146,    -1,   146,    84,   110,    -1,   146,    83,
     146,    98,    -1,    93,   146,    94,    -1,   149,    -1,    69,
     146,    -1,    68,   146,    -1,    82,   146,    -1,    81,   146,
      -1,    75,   146,    -1,    72,   146,    -1,   110,    93,   138,
      94,    -1,   146,    84,   110,    93,   138,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   166,   166,   167,   168,   171,   174,   175,   178,   179,
     182,   183,   186,   187,   194,   197,   198,   199,   200,   201,
     204,   205,   208,   209,   210,   224,   225,   228,   231,   232,
     235,   236,   239,   240,   241,   242,   245,   249,   250,   253,
     254,   257,   258,   261,   262,   263,   264,   265,   268,   269,
     270,   273,   275,   277,   281,   282,   283,   286,   287,   290,
     291,   294,   297,   298,   301,   302,   305,   308,   309,   310,
     313,   314,   317,   318,   325,   328,   329,   332,   335,   336,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   355,   356,   357,   358,   359,   360,
     361,   364,   365,   368,   369,   372,   373,   374,   377,   378,
     381,   384,   387,   388,   391,   394,   395,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   415,   416,   417,   418,   419,   420,   424,   425
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
  "T_CLASS", "T_INTERFACE", "T_LNUMBER", "T_DNUMBER", "T_NAME",
  "T_NEWLINE", "T_FIX", "','", "\"**= (T_POW_ASSIGN)\"",
  "\">>= (T_RSH_ASSIGN)\"", "\"<<= (T_LSH_ASSIGN)\"",
  "\"^= (T_XOR_ASSIGN)\"", "\"|= (T_OR_ASSIGN)\"", "\"&= (T_AND_ASSIGN)\"",
  "\"%= (T_MOD_ASSIGN)\"", "\"..= (T_CONCAT_ASSIGN)\"",
  "\"/= (T_DIV_ASSIGN)\"", "\"*= (T_MUL_ASSIGN)\"",
  "\"-= (T_MINUS_ASSIGN)\"", "\"+= (T_PLUS_ASSIGN)\"",
  "\":= (T_DECL_ASSIGN)\"", "\"= (T_ASSIGN)\"", "'?'", "':'",
  "\"^^ (T_XORXOR)\"", "\"|| (T_OROR)\"", "\"&& (T_ANDAND)\"",
  "\"> (T_GT)\"", "\"< (T_LT)\"", "\">= (T_GE)\"", "\"<= (T_LE)\"",
  "\"!= (T_NE)\"", "\"== (T_EQ)\"", "\".. (T_CONCAT)\"", "\"^ (T_XOR)\"",
  "\"| (T_OR)\"", "\"- (T_MINUS)\"", "\"+ (T_PLUS)\"", "\">> (T_RSH)\"",
  "\"<< (T_LSH)\"", "\"& (T_AND)\"", "\"% (T_MOD)\"", "\"/ (T_DIV)\"",
  "\"* (T_MUL)\"", "\"** (T_POW)\"", "\"is (T_IS)\"", "T_UNARY",
  "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "\"~ (T_TILDE)\"", "\"! (T_NOT)\"",
  "'['", "\". (T_DOT)\"", "\"@ (T_AT)\"", "\"* (T_INDIRECT)\"",
  "\"& (T_ADDR)\"", "\"[] (T_INDEX)\"", "T_PTR", "T_ARR", "T_DOTNAME",
  "NotParen", "'('", "')'", "';'", "'{'", "'}'", "']'", "$accept", "file",
  "newline", "end_statement", "top_statement_list", "name_list",
  "top_decl_var", "decl_type", "top_statement", "statement_list",
  "statement", "dotname", "type_interface_empty", "type_interface",
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    44,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,    63,    58,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    91,   335,   336,   337,   338,   339,   340,
     341,   342,   343,    40,    41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   100,   100,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   111,   112,   112,
     113,   113,   114,   114,   114,   114,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   119,   120,   120,
     120,   121,   121,   121,   122,   122,   122,   123,   123,   124,
     124,   125,   126,   126,   127,   127,   128,   129,   129,   129,
     130,   130,   131,   131,   132,   133,   133,   134,   135,   135,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   140,   141,   141,
     142,   143,   144,   144,   145,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   147,   147,   147,   147,
     147,   147,   148,   148,   148,   148,   148,   148,   149,   149
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     5,     3,     2,     2,     4,     2,     1,
       1,     2,     1,     3,     2,     1,     3,     3,     1,     4,
       1,     2,     5,     6,     8,     1,     4,     2,     1,     1,
       2,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     9,    10,    12,     4,     5,     0,     1,     0,     1,
       3,     2,     1,     0,     1,     3,     0,     5,     6,     8,
       1,     1,     2,     2,     3,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     4,     4,     1,     3,
       3,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     1,     2,     2,     2,     2,     2,     2,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,    56,    10,     5,     0,    19,     2,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     1,
       9,     0,     0,     7,     6,    15,    16,    18,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    90,    91,    89,
      92,    93,    66,     0,    25,     0,     0,     0,    79,    71,
      70,    47,    12,    44,    45,    46,    43,    78,     0,     0,
      28,    49,    50,    48,    14,     0,     0,    11,    94,    95,
      99,   100,     0,    96,    97,    98,     0,     0,     0,     0,
       0,     0,     0,     0,   120,   117,     0,   118,   119,   112,
       0,   116,   101,   115,   121,   131,     0,     0,    72,    73,
      75,     0,    76,     0,     0,     0,    42,     0,     0,     0,
      58,     0,   115,   133,   132,   137,   136,   135,   134,     0,
     103,     0,     0,     0,     0,    17,   114,   113,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    27,    74,     0,
      26,    13,    38,     0,    39,    41,     0,     0,    59,     0,
      35,     0,    30,     0,    54,     0,    57,   130,   104,     0,
     105,   120,     0,     0,   108,   102,   127,   123,   122,   126,
     125,   124,     0,   128,     0,    77,    61,    40,    36,     0,
      37,    58,    29,    31,    55,     0,   138,     0,   106,     0,
     107,   129,     0,    67,    60,     0,     0,    63,     0,   110,
       0,   109,     0,     0,    68,     0,     0,    64,     0,    22,
      62,    20,     0,    63,   139,     0,     0,    32,     0,     0,
       0,    24,     0,    21,    51,     0,    69,     0,    33,    65,
      63,    23,    52,     0,     0,    34,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,    24,    25,     9,    10,    11,    12,   209,   210,
     211,    84,    49,    61,   151,   152,    62,   144,   145,   146,
      50,    64,    14,    18,   155,   156,   148,   212,   206,    96,
      51,   207,    53,    54,   103,    55,    56,    57,    85,    86,
      87,    88,   163,   164,    89,    90,    91,    92,    93,    94,
      95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -181
static const yytype_int16 yypact[] =
{
     189,  -181,    12,    19,   -35,  -181,  -181,    62,  -181,   165,
      -2,   -34,   -34,  -181,   -34,   489,   525,    39,    42,  -181,
    -181,    53,   600,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,  -181,
    -181,  -181,  -181,     5,  -181,   569,   569,   -16,    20,  -181,
    -181,  -181,    57,  -181,  -181,  -181,  -181,  -181,    16,    24,
    -181,  -181,  -181,  -181,  -181,   693,    10,  -181,  -181,  -181,
    -181,  -181,   600,  -181,  -181,  -181,   600,   600,   600,   600,
     600,   600,   600,   387,    15,  -181,   -18,  -181,  -181,  -181,
      33,  -181,   271,  -181,  -181,  -181,    23,    27,  -181,  -181,
    -181,   569,    20,    25,    85,   600,    82,   -13,   726,    32,
      12,   271,    60,    13,    13,    13,    13,    13,    13,   258,
    -181,   -17,   600,   395,   600,  -181,  -181,  -181,   600,   600,
     600,   600,   600,   600,   600,    42,    12,  -181,  -181,   569,
    -181,    91,  -181,   489,  -181,    82,    31,    -3,  -181,    40,
    -181,   -11,  -181,    38,  -181,    41,    97,  -181,  -181,    -4,
    -181,    21,   -12,    -9,  -181,   271,    69,    69,    69,    13,
      13,    13,    89,    45,    46,  -181,  -181,  -181,  -181,    12,
    -181,    12,  -181,  -181,  -181,   242,  -181,   600,  -181,    42,
    -181,  -181,   600,   367,  -181,    47,   569,   149,    50,   271,
     -24,  -181,    -1,   569,  -181,   275,     1,  -181,   592,  -181,
     149,  -181,    58,   149,  -181,     4,   569,  -181,   -34,   569,
      51,  -181,   -18,  -181,  -181,    59,  -181,     8,  -181,  -181,
     149,  -181,  -181,   -34,    63,  -181,  -181
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -181,  -181,     0,   -10,  -181,     3,  -181,  -181,    70,  -181,
     -60,    26,   143,  -181,  -181,    17,  -181,    22,  -181,  -181,
     150,  -181,  -181,  -181,  -128,   -96,    -5,  -180,  -164,  -181,
    -181,   -14,  -181,  -181,  -181,  -181,    -8,  -181,  -181,   -77,
    -181,  -181,  -181,   -19,    90,  -181,  -181,   -65,   109,  -181,
    -181
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -112
static const yytype_int16 yytable[] =
{
       8,    52,    26,     6,    27,    15,   121,   111,   174,     8,
     147,   113,   114,   115,   116,   117,   118,   119,   100,     6,
      44,   124,   124,   149,     6,   149,     6,   124,   141,   187,
     189,    98,    99,   225,     6,   124,   179,    21,   124,   215,
     219,    48,    48,   219,    66,   159,   162,   219,     5,   147,
     234,    22,   227,   195,   126,    16,    72,   109,    17,   165,
     104,    23,    19,   166,   167,   168,   169,   170,   171,   172,
      13,    48,    48,   102,   187,    65,   125,    23,    44,    20,
     158,  -111,   101,  -111,   137,   188,   182,   138,   190,    67,
     186,    48,    23,   214,   104,   220,   134,   135,   226,   104,
     153,    97,   233,   110,   104,   104,   142,   150,   122,   143,
     105,   123,   106,   143,   122,   202,   136,   123,     5,     6,
     107,   140,   199,   139,   137,   175,   154,    48,   178,   176,
     124,   222,   184,   181,    48,   185,   179,   180,   192,   143,
     193,   205,   131,   132,   133,   142,   213,   230,   143,   161,
     223,   150,   134,   135,   128,   224,   232,   129,   130,    60,
     236,   173,   131,   132,   133,    48,    63,   177,   183,    48,
     201,   198,   134,   135,   194,   208,     2,     3,     4,   204,
     127,   112,   143,     0,   143,     5,     6,   191,     0,    -3,
       1,   218,     2,     3,     4,   217,     0,     8,   221,     0,
       0,     5,     6,     0,     0,   229,     0,     0,   228,     0,
       8,    48,   231,     8,     0,   200,     2,     3,     4,    48,
       0,     0,    48,   235,     0,     5,     6,     0,     0,    48,
       8,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    48,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,    42,     0,     0,     0,    43,     0,     0,    44,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    42,     0,     0,     0,    43,     0,
       0,    44,     6,     0,     0,     0,     0,    45,    46,     0,
       0,     0,     0,   128,     0,    47,   129,   130,     0,     0,
       0,   131,   132,   133,     0,   196,   128,     0,   197,   129,
     130,   134,   135,     0,   131,   132,   133,     0,     0,     0,
      45,    46,   157,     0,   134,   135,     0,     0,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,     0,
      23,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    42,     0,     0,     0,
      43,     0,     0,    44,    68,    69,    70,     0,    71,     0,
      72,    73,    68,    69,    70,     0,    71,     0,    72,    73,
       0,    74,    75,    44,     0,     0,     0,     0,     0,    74,
      75,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,    46,     0,     0,     0,     0,     0,     0,
      47,     0,     0,     0,     0,    76,    77,     0,     0,    78,
     203,     0,    79,    76,    77,     0,     0,    78,    80,    81,
      79,     0,     0,     0,     0,     0,    80,    81,     0,     0,
      82,     0,     0,    83,   120,     0,     0,     0,    82,     0,
       0,    83,   160,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    42,     0,
       0,     0,    43,     0,     0,    44,     0,     0,    21,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,     0,     0,
      41,     0,     0,     0,    42,     0,     0,    58,    59,     0,
       0,    44,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    47,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,    42,     0,
      45,    46,    43,     0,     0,    44,     0,     0,    47,    68,
      69,    70,     0,    71,     0,    72,    73,    68,    69,    70,
       0,    71,     0,    72,    73,     0,    74,    75,    44,     6,
       0,     0,     0,     0,    74,    75,    44,     0,     0,     0,
       0,     0,     0,     0,    45,    46,     0,     0,     0,     0,
       0,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      76,    77,     0,     0,    78,     0,     0,    79,    76,    77,
       0,     0,    78,    80,    81,    79,     0,     0,     0,     0,
       0,    80,    81,     0,     0,    82,     0,    23,    83,     0,
       0,     0,     0,    82,     0,     0,    83,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,   108
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-181)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    15,    12,    37,    14,     2,    83,    72,   136,     9,
     106,    76,    77,    78,    79,    80,    81,    82,    34,    37,
      36,    39,    39,    36,    37,    36,    37,    39,   105,    53,
      39,    45,    46,   213,    37,    39,    39,    39,    39,   203,
      39,    15,    16,    39,    18,   122,   123,    39,    36,   145,
     230,    53,   216,   181,    21,    36,    23,    65,    93,   124,
      84,    95,     0,   128,   129,   130,   131,   132,   133,   134,
       0,    45,    46,    47,    53,    36,    86,    95,    36,     9,
      97,    21,    98,    23,    97,    97,    97,   101,    97,    36,
      94,    65,    95,    94,    84,    94,    83,    84,    94,    84,
     108,    96,    94,    93,    84,    84,   106,   107,    93,   106,
      53,    96,    96,   110,    93,   192,    93,    96,    36,    37,
      96,    36,   187,    98,    97,   139,    94,   101,    97,   143,
      39,   208,    94,    93,   108,    94,    39,   147,    93,   136,
      94,    94,    73,    74,    75,   145,    96,    96,   145,   123,
     210,   151,    83,    84,    65,    97,    97,    68,    69,    16,
      97,   135,    73,    74,    75,   139,    16,   145,   151,   143,
     189,   185,    83,    84,   179,    26,    27,    28,    29,   193,
      90,    72,   179,    -1,   181,    36,    37,    98,    -1,     0,
       1,   205,    27,    28,    29,   205,    -1,   197,   208,    -1,
      -1,    36,    37,    -1,    -1,   219,    -1,    -1,   218,    -1,
     210,   185,   222,   213,    -1,   189,    27,    28,    29,   193,
      -1,    -1,   196,   233,    -1,    36,    37,    -1,    -1,   203,
     230,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   216,    -1,    -1,   219,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    -1,    -1,    36,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,
      -1,    36,    37,    -1,    -1,    -1,    -1,    75,    76,    -1,
      -1,    -1,    -1,    65,    -1,    83,    68,    69,    -1,    -1,
      -1,    73,    74,    75,    -1,    93,    65,    -1,    96,    68,
      69,    83,    84,    -1,    73,    74,    75,    -1,    -1,    -1,
      75,    76,    94,    -1,    83,    84,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      95,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    -1,    -1,    36,    17,    18,    19,    -1,    21,    -1,
      23,    24,    17,    18,    19,    -1,    21,    -1,    23,    24,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    68,    69,    -1,    -1,    72,
      93,    -1,    75,    68,    69,    -1,    -1,    72,    81,    82,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    -1,    -1,    36,    -1,    -1,    39,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    -1,    32,    33,    -1,
      -1,    36,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,
      75,    76,    33,    -1,    -1,    36,    -1,    -1,    83,    17,
      18,    19,    -1,    21,    -1,    23,    24,    17,    18,    19,
      -1,    21,    -1,    23,    24,    -1,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    -1,    72,    -1,    -1,    75,    68,    69,
      -1,    -1,    72,    81,    82,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    93,    -1,    95,    96,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    96,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    28,    29,    36,    37,   100,   101,   103,
     104,   105,   106,   107,   121,   104,    36,    93,   122,     0,
     107,    39,    53,    95,   101,   102,   102,   102,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    25,    29,    33,    36,    75,    76,    83,   110,   111,
     119,   129,   130,   131,   132,   134,   135,   136,    32,    33,
     111,   112,   115,   119,   120,    36,   110,    36,    17,    18,
      19,    21,    23,    24,    34,    35,    68,    69,    72,    75,
      81,    82,    93,    96,   110,   137,   138,   139,   140,   143,
     144,   145,   146,   147,   148,   149,   128,    96,   130,   130,
      34,    98,   110,   133,    84,    53,    96,    96,    75,   135,
      93,   146,   147,   146,   146,   146,   146,   146,   146,   146,
      97,   138,    93,    96,    39,   102,    21,   143,    65,    68,
      69,    73,    74,    75,    83,    84,    93,    97,   130,    98,
      36,   138,   101,   104,   116,   117,   118,   124,   125,    36,
     101,   113,   114,   135,    94,   123,   124,    94,    97,   138,
      97,   110,   138,   141,   142,   146,   146,   146,   146,   146,
     146,   146,   146,   110,   123,   130,   130,   116,    97,    39,
     102,    93,    97,   114,    94,    94,    94,    53,    97,    39,
      97,    98,    93,    94,   125,   123,    93,    96,   130,   146,
     110,   142,   138,    93,   130,    94,   127,   130,    26,   107,
     108,   109,   126,    96,    94,   127,    93,   102,   130,    39,
      94,   102,   138,   109,    97,   126,    94,   127,   102,   130,
      96,   102,    97,    94,   126,   102,    97
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

  case 17:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_ASSIGN, parm); }
    break;

  case 21:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 23:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 24:

    { yoParserStmtReturn(&(yyval), NULL, parm); }
    break;

  case 26:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 27:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm); yoParserInterface(&(yyval), &(yyvsp[(1) - (3)]), parm); }
    break;

  case 29:

    { yoParserInterface(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 31:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 32:

    { yoParserInterfaceFunc(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(3) - (5)]), NULL, parm); }
    break;

  case 33:

    { yoParserInterfaceFunc(&(yyval), &(yyvsp[(1) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm); }
    break;

  case 34:

    { yoParserInterfaceFunc(&(yyval), &(yyvsp[(1) - (8)]), &(yyvsp[(3) - (8)]), &(yyvsp[(6) - (8)]), parm); }
    break;

  case 36:

    { yoParserClass(&(yyval), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 40:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 42:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 51:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm); }
    break;

  case 52:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm); }
    break;

  case 53:

    { yoParserDeclFunc(&(yyval), &(yyvsp[(2) - (12)]), &(yyvsp[(3) - (12)]), &(yyvsp[(5) - (12)]), &(yyvsp[(8) - (12)]), &(yyvsp[(11) - (12)]), parm); }
    break;

  case 54:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 55:

    { yoParserTypePtr(&(yyvsp[(3) - (5)]), &(yyvsp[(4) - (5)]), parm); yoParserDeclArg(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm); }
    break;

  case 56:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 58:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 60:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 61:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 63:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 65:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 66:

    { yoParseEmpty(&(yyval), parm); }
    break;

  case 67:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm); }
    break;

  case 68:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm); }
    break;

  case 69:

    { yoParserTypeFunc(&(yyval), &(yyvsp[(2) - (8)]), &(yyvsp[(4) - (8)]), &(yyvsp[(7) - (8)]), parm); }
    break;

  case 72:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm); }
    break;

  case 73:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm); yoParserTypePtr(&(yyval), &(yyval), parm); }
    break;

  case 74:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 77:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm); }
    break;

  case 79:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (1)]), parm); }
    break;

  case 80:

    { yoParserTypeStdName(&(yyval), T_INT8, parm); }
    break;

  case 81:

    { yoParserTypeStdName(&(yyval), T_INT16, parm); }
    break;

  case 82:

    { yoParserTypeStdName(&(yyval), T_INT32, parm); }
    break;

  case 83:

    { yoParserTypeStdName(&(yyval), T_INT64, parm); }
    break;

  case 84:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm); }
    break;

  case 85:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm); }
    break;

  case 86:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm); }
    break;

  case 87:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm); }
    break;

  case 88:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm); }
    break;

  case 89:

    { yoParserTypeStdName(&(yyval), T_STRING, parm); }
    break;

  case 90:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm); }
    break;

  case 91:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm); }
    break;

  case 92:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm); }
    break;

  case 93:

    { yoParserTypeStdName(&(yyval), T_VOID, parm); }
    break;

  case 94:

    { yoParserConst(&(yyval), T_TRUE, parm); }
    break;

  case 95:

    { yoParserConst(&(yyval), T_FALSE, parm); }
    break;

  case 96:

    { yoParserConst(&(yyval), T_NULL, parm); }
    break;

  case 102:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 103:

    { yoParserNewArr(&(yyval), parm); }
    break;

  case 104:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm); }
    break;

  case 105:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm); }
    break;

  case 106:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 107:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 109:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm); }
    break;

  case 110:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm); }
    break;

  case 111:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 113:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 114:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm); }
    break;

  case 122:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm); }
    break;

  case 123:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm); }
    break;

  case 124:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm); }
    break;

  case 125:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm); }
    break;

  case 126:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm); }
    break;

  case 127:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm); }
    break;

  case 128:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm); }
    break;

  case 129:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm); }
    break;

  case 130:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 132:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm); }
    break;

  case 133:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm); }
    break;

  case 134:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm); }
    break;

  case 135:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm); }
    break;

  case 136:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm); }
    break;

  case 137:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm); }
    break;

  case 138:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm); }
    break;

  case 139:

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




