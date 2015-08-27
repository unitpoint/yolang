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
     T_SUB_FUNC = 288,
     T_LAMBDA = 289,
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
     T_INIT_ASSIGN = 321,
     T_PROP_ASSIGN = 322,
     T_XORXOR = 323,
     T_OROR = 324,
     T_ANDAND = 325,
     T_CHAN_ACCESS = 326,
     T_GT = 327,
     T_LT = 328,
     T_GE = 329,
     T_LE = 330,
     T_NE = 331,
     T_EQ = 332,
     T_CONCAT = 333,
     T_XOR = 334,
     T_OR = 335,
     T_MINUS = 336,
     T_PLUS = 337,
     T_RSH = 338,
     T_LSH = 339,
     T_AND = 340,
     T_MOD = 341,
     T_DIV = 342,
     T_MUL = 343,
     T_POW = 344,
     T_AT = 345,
     T_UNARY = 346,
     T_DEC = 347,
     T_INC = 348,
     T_TILDE = 349,
     T_NOT = 350,
     T_DOT = 351,
     T_AS = 352,
     T_INDIRECT = 353,
     T_ADDR = 354,
     T_INDEX = 355,
     T_PTR = 356,
     T_ARR = 357,
     T_DOTNAME = 358,
     NotParen = 359
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
#define YYLAST   1784

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  115
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNRULES -- Number of states.  */
#define YYNSTATES  435

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   359

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     109,   110,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    70,   111,
       2,     2,     2,    69,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    99,     2,   114,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   112,     2,   113,     2,     2,     2,     2,
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
      66,    67,    68,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   100,   101,   102,   103,   104,   105,   106,   107,   108
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    11,    14,    16,    18,    20,
      22,    24,    26,    29,    31,    35,    38,    42,    47,    53,
      57,    59,    61,    64,    68,    74,    77,    81,    83,    86,
      89,    92,    95,    97,    99,   101,   103,   105,   107,   111,
     114,   119,   122,   124,   128,   132,   135,   137,   139,   141,
     144,   146,   150,   151,   158,   159,   164,   165,   171,   173,
     176,   178,   183,   185,   191,   193,   197,   199,   203,   207,
     214,   216,   219,   226,   234,   242,   249,   251,   255,   257,
     259,   263,   265,   269,   272,   274,   276,   278,   282,   289,
     292,   294,   296,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   317,   319,   321,   323,   325,   327,   337,   348,
     359,   369,   378,   388,   395,   400,   402,   404,   406,   409,
     413,   416,   420,   425,   427,   429,   431,   433,   437,   440,
     442,   444,   446,   452,   459,   466,   472,   474,   476,   479,
     482,   485,   488,   491,   494,   498,   500,   502,   507,   509,
     512,   514,   516,   518,   520,   522,   524,   526,   528,   530,
     532,   534,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   554,   556,   560,   563,   567,   571,   576,   581,   583,
     587,   591,   594,   596,   599,   602,   604,   606,   608,   610,
     612,   614,   616,   620,   624,   628,   632,   636,   640,   644,
     648,   652,   656,   660,   664,   668,   672,   677,   681,   683,
     685,   689,   695,   698,   701,   704,   707,   710,   713,   716,
     718,   720,   725
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     116,     0,    -1,     3,    49,   118,   119,    -1,    -1,   120,
      -1,   111,   120,    -1,   122,    -1,   117,    -1,    50,    -1,
     120,    -1,   111,    -1,   131,    -1,   122,   131,    -1,    49,
      -1,   123,    52,    49,    -1,    29,    49,    -1,    29,    49,
     175,    -1,    29,    49,    66,   195,    -1,    29,    49,   175,
      66,   195,    -1,    30,    49,   163,    -1,    23,    -1,    21,
      -1,     4,   126,    -1,     4,    49,   126,    -1,     4,   112,
     120,   129,   113,    -1,   126,   120,    -1,    49,   126,   120,
      -1,   128,    -1,   129,   128,    -1,   127,   121,    -1,   125,
     121,    -1,   164,   121,    -1,     1,    -1,   130,    -1,   120,
      -1,   120,    -1,   111,    -1,   113,    -1,   124,   145,   121,
      -1,   125,   121,    -1,    28,   195,   145,   121,    -1,    28,
     121,    -1,   138,    -1,   146,   145,   121,    -1,   199,   145,
     121,    -1,     1,   132,    -1,   133,    -1,   120,    -1,   134,
      -1,   135,   134,    -1,   195,    -1,    42,   135,   113,    -1,
      -1,    43,   139,   136,   137,   143,   144,    -1,    -1,    45,
     141,   136,   137,    -1,    -1,    44,    43,   142,   136,   137,
      -1,   140,    -1,   143,   140,    -1,   117,    -1,    44,   112,
     135,   113,    -1,   117,    -1,    46,    49,   112,   135,   113,
      -1,   117,    -1,   123,    66,   187,    -1,    49,    -1,   147,
     100,    49,    -1,    41,   112,   113,    -1,    41,   152,   155,
     112,   150,   113,    -1,   151,    -1,   150,   151,    -1,    32,
      49,   109,   169,   110,   121,    -1,    32,    49,   109,   169,
     110,   175,   121,    -1,    35,    49,   109,   169,   110,   175,
     121,    -1,    36,    49,   109,   170,   110,   121,    -1,   120,
      -1,    76,   154,    75,    -1,   117,    -1,   184,    -1,   184,
      66,   153,    -1,   153,    -1,   154,    52,   153,    -1,    70,
     157,    -1,   117,    -1,   153,    -1,   156,    -1,   157,    52,
     156,    -1,    40,   152,   155,   112,   161,   113,    -1,   170,
     121,    -1,   120,    -1,   159,    -1,   160,   159,    -1,   160,
      -1,   117,    -1,   184,    -1,   176,    -1,   177,    -1,   178,
      -1,   180,    -1,   179,    -1,   181,    -1,   183,    -1,   174,
      -1,   162,    -1,   149,    -1,   158,    -1,    32,   168,   147,
     109,   169,   110,   112,   172,   113,    -1,    32,   168,   147,
     109,   169,   110,   175,   112,   172,   113,    -1,    35,   168,
     147,   109,   169,   110,   175,   112,   172,   113,    -1,    36,
     168,   147,   109,   170,   110,   112,   172,   113,    -1,    32,
     117,   109,   169,   110,   112,   172,   113,    -1,    32,   117,
     109,   169,   110,   175,   112,   172,   113,    -1,   112,    83,
     123,    83,   166,   113,    -1,   112,    72,   166,   113,    -1,
     195,    -1,   172,    -1,   184,    -1,    91,   184,    -1,    91,
      38,   184,    -1,    88,   184,    -1,    88,    38,   184,    -1,
     109,    49,   167,   110,    -1,   117,    -1,   170,    -1,   117,
      -1,   171,    -1,   170,    52,   171,    -1,   123,   175,    -1,
     135,    -1,   117,    -1,   117,    -1,    32,   173,   109,   169,
     110,    -1,    32,   173,   109,   169,   110,   175,    -1,    35,
     173,   109,   169,   110,   175,    -1,    36,   173,   109,   170,
     110,    -1,   162,    -1,   148,    -1,    37,   175,    -1,    38,
     175,    -1,    31,   175,    -1,    88,   175,    -1,    91,   175,
      -1,    92,   175,    -1,    99,   114,   175,    -1,    47,    -1,
     147,    -1,    99,   182,   114,   175,    -1,   185,    -1,   147,
     152,    -1,     6,    -1,     7,    -1,     8,    -1,     9,    -1,
      10,    -1,    11,    -1,    12,    -1,    13,    -1,    14,    -1,
      17,    -1,    15,    -1,    16,    -1,    18,    -1,    27,    -1,
      19,    -1,    20,    -1,    26,    -1,    47,    -1,    48,    -1,
      21,    -1,    23,    -1,   195,    -1,   187,    52,   195,    -1,
     112,   113,    -1,   112,   187,   113,    -1,   147,   112,   113,
      -1,   147,   112,   187,   113,    -1,   147,   112,   190,   113,
      -1,   191,    -1,   190,    52,   191,    -1,   147,    66,   195,
      -1,    25,   196,    -1,   192,    -1,   193,   192,    -1,   193,
      23,    -1,   196,    -1,   194,    -1,   186,    -1,   188,    -1,
     189,    -1,   147,    -1,   197,    -1,   195,    85,   195,    -1,
     195,    84,   195,    -1,   195,    91,   195,    -1,   195,    90,
     195,    -1,   195,    89,   195,    -1,   195,    81,   195,    -1,
     195,   100,   147,    -1,   195,    83,   195,    -1,   195,    72,
     195,    -1,   195,    88,   195,    -1,   195,    73,   195,    -1,
     195,    82,   195,    -1,   195,    71,   195,    -1,   195,    74,
     195,    -1,   195,    99,   195,   114,    -1,   109,   195,   110,
      -1,   199,    -1,   165,    -1,   195,   101,   175,    -1,   195,
     100,   109,   175,   110,    -1,    85,   195,    -1,    84,   195,
      -1,    98,   195,    -1,    97,   195,    -1,    91,   195,    -1,
      88,   195,    -1,    74,   195,    -1,   187,    -1,   117,    -1,
     147,   109,   198,   110,    -1,   195,   100,   147,   109,   198,
     110,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   225,   225,   228,   237,   238,   241,   242,   245,   248,
     249,   252,   253,   256,   257,   260,   261,   262,   267,   274,
     277,   278,   281,   282,   283,   286,   287,   290,   291,   294,
     295,   296,   297,   300,   301,   304,   305,   306,   309,   310,
     311,   312,   313,   314,   315,   316,   319,   320,   323,   324,
     335,   338,   341,   341,   346,   346,   347,   347,   350,   351,
     352,   355,   356,   359,   360,   363,   367,   368,   371,   374,
     377,   378,   381,   382,   383,   384,   385,   388,   389,   392,
     393,   396,   397,   400,   401,   404,   407,   408,   411,   414,
     415,   418,   419,   422,   423,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   437,   438,   439,   442,   444,   446,
     448,   452,   454,   456,   458,   462,   463,   466,   467,   468,
     469,   470,   473,   474,   477,   478,   481,   482,   485,   488,
     489,   498,   501,   502,   503,   504,   507,   508,   511,   514,
     517,   520,   523,   524,   531,   535,   536,   539,   543,   545,
     548,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   564,   565,   566,   567,   568,   569,
     570,   573,   574,   577,   578,   581,   582,   583,   586,   587,
     590,   593,   596,   597,   600,   603,   604,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   634,   635,   636,   637,   638,   639,   640,   645,
     646,   649,   650
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
  "T_TYPE", "T_CHAN", "T_FUNC", "T_SUB_FUNC", "T_LAMBDA", "T_GET", "T_SET",
  "T_CONST", "T_MUTABLE", "T_STRUCT", "T_CLASS", "T_CONTRACT", "T_BRACE",
  "T_IF", "T_ELSE", "T_ELSEIF", "T_CATCH", "T_LNUMBER", "T_DNUMBER",
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
  "\"* (T_MUL)\"", "\"** (T_POW)\"", "\"@ (T_AT)\"", "T_UNARY",
  "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "\"~ (T_TILDE)\"", "\"! (T_NOT)\"",
  "'['", "\". (T_DOT)\"", "\"as (T_AS)\"", "\"* (T_INDIRECT)\"",
  "\"& (T_ADDR)\"", "\"[] (T_INDEX)\"", "T_PTR", "T_ARR", "T_DOTNAME",
  "NotParen", "'('", "')'", "';'", "'{'", "'}'", "']'", "$accept", "file",
  "empty", "end_newline", "module_stmt_list", "newline", "end_stmt",
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
  "uexpr", "call_args", "call", YY_NULL
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
     314,   315,   316,   317,   318,   319,   320,   321,   322,    63,
      58,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,    91,
     351,   352,   353,   354,   355,   356,   357,   358,   359,    40,
      41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   115,   116,   117,   118,   118,   119,   119,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   124,   124,   125,
     126,   126,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   130,   130,   131,   131,   132,   132,   132,   133,   133,
     133,   133,   133,   133,   133,   133,   134,   134,   135,   135,
     136,   137,   139,   138,   141,   140,   142,   140,   143,   143,
     143,   144,   144,   145,   145,   146,   147,   147,   148,   149,
     150,   150,   151,   151,   151,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   157,   157,   158,   159,
     159,   160,   160,   161,   161,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   163,   163,   163,   164,   164,   164,
     164,   165,   165,   165,   165,   166,   166,   167,   167,   167,
     167,   167,   168,   168,   169,   169,   170,   170,   171,   172,
     172,   173,   174,   174,   174,   174,   175,   175,   176,   177,
     178,   179,   180,   180,   181,   182,   182,   183,   184,   184,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   186,   186,   186,   186,   186,   186,
     186,   187,   187,   188,   188,   189,   189,   189,   190,   190,
     191,   192,   193,   193,   194,   195,   195,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   197,   197,   197,   197,   197,   197,   197,   198,
     198,   199,   199
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     3,     4,     5,     3,
       1,     1,     2,     3,     5,     2,     3,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     2,
       4,     2,     1,     3,     3,     2,     1,     1,     1,     2,
       1,     3,     0,     6,     0,     4,     0,     5,     1,     2,
       1,     4,     1,     5,     1,     3,     1,     3,     3,     6,
       1,     2,     6,     7,     7,     6,     1,     3,     1,     1,
       3,     1,     3,     2,     1,     1,     1,     3,     6,     2,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     9,    10,    10,
       9,     8,     9,     6,     4,     1,     1,     1,     2,     3,
       2,     3,     4,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     5,     6,     6,     5,     1,     1,     2,     2,
       2,     2,     2,     2,     3,     1,     1,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     4,     4,     1,     3,
       3,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     1,     1,
       3,     5,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     8,     0,     0,     4,     5,
      32,     0,     0,     3,     3,     3,     7,     2,    34,     0,
       0,     0,    33,    11,     0,    21,    20,     0,     0,    22,
       0,     0,   123,     0,     0,     0,    12,    10,     9,    30,
      29,    31,    23,     0,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   160,   161,   159,   162,   163,     0,     3,
       3,     3,     0,     0,     3,     3,    66,     0,     0,     0,
       0,     3,   105,   106,   104,    19,   103,    96,    97,    98,
     100,    99,   101,   102,    95,   148,     0,     0,     0,     0,
       0,     0,    27,     0,     0,   137,   136,   140,   131,     0,
       0,     0,   138,   139,     0,    78,     3,     3,   141,   142,
     143,   145,     0,   146,     0,     0,   149,     0,     0,     0,
     117,     3,     3,     0,     0,    25,    24,    28,     0,     3,
       3,     0,    81,     0,    79,     0,    84,     0,     0,   144,
       0,    67,     0,   120,     0,   118,   122,    13,   125,     0,
       0,   124,   126,     0,     0,    26,    68,     0,     0,     0,
       0,    77,     0,    85,    86,    83,     3,     0,   147,   121,
     119,     0,   128,     0,     0,     0,     0,   132,     0,   135,
      82,    80,     0,    94,    90,    91,    93,     0,     0,     0,
       0,     0,    76,     0,    70,    14,     0,     0,   127,     0,
       0,   133,   134,    87,    92,    88,    89,     0,     0,     0,
      69,    71,     0,   164,   165,   169,   170,     0,   166,     0,
       0,     3,    52,   167,   168,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,    47,     0,     3,     0,
      46,    48,     0,    42,     3,   190,   209,     0,   187,   188,
     189,   182,     0,   186,     0,   185,   191,   208,     0,     0,
       0,     3,     3,     0,    36,    37,    35,    45,   185,   208,
      41,     3,    15,     0,     0,   218,   213,   212,   217,   216,
     215,   214,     0,     0,     0,   173,     0,   171,     0,     0,
      64,     0,    39,    49,     0,     3,     0,   107,   184,   183,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,    16,     3,     0,    50,   207,
       0,   116,   115,     0,     0,   174,    65,     0,    38,    43,
     220,   219,     0,   175,   190,     0,     0,   178,   204,   200,
     202,   205,   197,   203,   199,   193,   192,   201,   196,   195,
     194,     0,     0,   198,   210,    44,   108,   109,     0,     0,
       0,    40,    17,     0,     0,     0,     3,   114,     0,   172,
       0,   221,     0,   176,     0,   177,   206,     0,     3,    72,
       0,     0,    75,    18,     0,     0,     0,    54,    60,    58,
       3,     0,     0,   180,     0,   179,   211,     0,    73,    74,
       0,     0,    51,    56,     0,     0,    62,    59,    53,   113,
      63,   222,     0,     0,     0,     0,     0,   111,     0,     0,
      55,     0,   112,    57,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   235,     7,    17,   236,    39,    19,   237,   238,
     239,    91,    21,    92,    93,    22,    23,   267,   240,   241,
     242,   327,   376,   243,   274,   399,   414,   424,   400,   418,
     291,   244,   245,    95,    72,   193,   194,   106,   163,   133,
     137,   164,   165,    73,   185,   186,   187,    96,    75,    24,
     246,   330,   119,    33,   150,   151,   152,   331,    99,    76,
      97,    77,    78,    79,    80,    81,    82,   114,    83,    84,
      85,   248,   341,   249,   250,   346,   347,   251,   252,   253,
     254,   255,   256,   342,   269
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -287
static const yytype_int16 yypact[] =
{
      95,   -20,    47,   -45,  -287,  -287,    70,   133,  -287,  -287,
    -287,    44,    36,    18,    18,    18,  -287,  -287,  -287,   278,
     -15,   -15,  -287,  -287,   -15,  -287,  -287,   205,    70,  -287,
    1130,    96,  -287,    99,    99,    99,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,   155,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  1284,  -287,
    -287,  -287,  1284,  1284,    91,    91,  -287,  1284,  1284,  1284,
     -32,    81,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,
    -287,  -287,  -287,  -287,  -287,  -287,  1343,    82,    84,   111,
     205,    70,  -287,    23,    86,  -287,  -287,  -287,  -287,   113,
     123,   134,  -287,  -287,  1646,  -287,   135,   135,  -287,  -287,
    -287,  -287,  1284,   149,   138,   211,  -287,  1558,  1602,   151,
    -287,   222,   222,   222,    70,  -287,  -287,  -287,   160,   222,
     222,   222,  -287,    89,   208,  1646,  -287,   169,   173,  -287,
    1284,  -287,  1646,  -287,  1646,  -287,  -287,  -287,  -287,  1174,
     177,   231,  -287,   179,   -30,  -287,  -287,   180,   182,     7,
    1646,  -287,  1646,  -287,  -287,   241,   -46,   171,  -287,  -287,
    -287,   246,  -287,   859,   222,  1284,   184,  1455,  1284,  -287,
    -287,  -287,  1646,  -287,  -287,  -287,   -46,   185,    38,   250,
     252,   253,  -287,    42,  -287,  -287,   445,   191,  -287,   193,
     445,  -287,  -287,  -287,  -287,  -287,  -287,   197,   202,   206,
    -287,  -287,   -27,  -287,  -287,  -287,  -287,  1348,  -287,  1315,
     258,  -287,  -287,  -287,  -287,   -11,  1348,  1348,  1348,  1348,
    1348,  1348,  1348,  1348,  1002,  -287,  -287,   114,   263,   -15,
    -287,  -287,   560,  -287,   263,    26,  -287,   207,  -287,  -287,
    -287,  -287,   213,  -287,  1620,  -287,  -287,   -36,   445,   445,
     214,   222,   222,   222,  -287,  -287,  -287,  -287,   217,  -287,
    -287,  1428,  1240,   215,  1348,   147,   147,   147,   147,   147,
     147,   147,  1597,   445,   222,  -287,   -10,  1620,  1348,   272,
    -287,   -15,  -287,  -287,   -15,  1348,  1022,  -287,  -287,  -287,
    1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,  1348,
    1348,  1348,  1348,  1348,   -33,  1284,   -15,   219,   220,  -287,
     224,   226,    21,   -15,  1348,   259,   222,   284,  1620,  -287,
     228,  -287,  1620,    27,  1348,  -287,   287,   218,  -287,  -287,
    -287,   287,   235,  -287,    62,    -2,    -1,  -287,  1641,  1641,
    1662,  1683,   314,   314,   314,   314,   314,   147,   147,   147,
     147,  1449,  1284,   237,  -287,  -287,  -287,  -287,   969,  1284,
     -15,  -287,  1620,  1348,   238,   814,   164,  -287,   445,  1620,
     814,  -287,  1348,  -287,    99,  -287,  -287,   249,  1348,  -287,
     -15,   -15,  -287,  1620,   925,   592,   304,  -287,  -287,  -287,
     212,   248,   687,  1620,    58,  -287,  -287,   254,  -287,  -287,
     445,   255,  -287,  -287,  1348,   -41,  -287,  -287,  -287,  -287,
    -287,  -287,   266,   445,  1348,   284,   814,  -287,   267,   284,
    -287,   719,  -287,  -287,  -287
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -287,  -287,    -7,  -287,  -287,     6,     0,  -287,   -61,  -287,
     168,    29,  -287,   273,  -287,  -287,   346,  -287,  -287,  -241,
    -286,  -228,  -240,  -287,  -287,   -29,  -287,  -287,  -287,  -287,
    -128,  -287,   200,  -287,  -287,  -287,   190,   145,   -56,  -287,
     265,   203,  -287,  -287,   201,  -287,  -287,   354,  -287,  -287,
    -287,     8,  -287,   198,  -111,  -103,   221,  -157,   216,  -287,
     -31,  -287,  -287,  -287,  -287,  -287,  -287,  -287,  -287,    35,
    -287,  -287,  -201,  -287,  -287,  -287,     4,   137,  -287,  -287,
     124,   175,  -287,    11,  -151
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -182
static const yytype_int16 yytable[] =
{
      16,   293,   413,   147,     5,     5,    32,    32,    32,     8,
     289,   153,     9,    18,    -3,   111,    66,    66,   157,   158,
     154,    40,   174,     5,    41,    18,    38,    38,   159,     3,
      38,   102,   103,   286,    43,     5,   108,   109,   110,   247,
      29,   -13,   334,   260,    25,   257,    26,     4,   132,   257,
     334,   384,    98,    98,    98,   -13,    42,   105,   105,   174,
     149,   149,   149,   188,   105,    25,     6,    26,   149,   149,
     149,   426,    90,   174,   189,    -3,   362,   190,   191,   171,
     176,   139,   112,   188,   264,    30,   265,   336,     5,   395,
     174,   257,     5,    27,   402,   345,    37,   125,     1,   136,
     136,   317,   318,   335,   180,   149,   181,   257,   257,   168,
     378,   383,   385,   149,   148,   148,   294,   179,   172,   124,
       5,   120,   148,   148,   382,   149,   115,    31,   382,   316,
     155,   370,   257,    -3,    10,   295,   126,    11,   296,   134,
     431,   160,   197,   323,   199,    86,   201,   202,    66,    37,
     320,   321,   143,   145,   293,   210,    28,   104,   115,   183,
     322,   293,   115,    12,   161,    13,   171,   104,    14,    15,
     134,   295,   184,   192,   296,    20,    25,   169,    26,   170,
     288,   115,   115,     5,   115,   430,   425,    20,   206,   433,
     293,   121,   184,   122,    38,   134,   429,   134,   128,   192,
     149,   149,   149,   189,    90,   135,   190,   191,   396,   397,
     107,   115,    34,    35,   273,   374,   116,   134,   266,   270,
     123,     5,   129,   333,   257,    38,    25,   257,    26,   257,
      71,   290,   130,    87,    88,    89,   298,   290,   217,   292,
    -181,   325,  -181,   131,   257,    38,   313,   314,   315,   115,
     290,   257,   140,   422,   148,   148,   415,   397,    71,   257,
     141,   146,    71,    71,   290,   149,   428,    71,    71,    71,
     113,   147,   257,   156,   162,   257,   100,   101,    -6,    10,
     257,   166,    11,   174,   364,   167,    71,   173,   340,   175,
     177,   338,   178,   182,   339,   195,   200,    38,   205,   207,
      38,   208,   209,   258,    71,   259,   261,   272,    12,   289,
      13,   262,    71,    14,    15,   263,   365,    71,    71,   148,
     297,   337,    38,   371,   326,   373,   375,   319,     5,    38,
     380,   387,   366,   367,   368,    71,   369,   390,   391,   334,
      71,   377,    71,   271,    71,   381,   388,   413,   394,    71,
     275,   276,   277,   278,   279,   280,   281,   282,   287,   406,
      71,   419,    71,   411,   421,    36,   127,   423,   389,   398,
     392,   417,   138,    71,    38,    71,    38,    71,    71,   427,
     432,   340,    71,   211,    74,   203,   401,   204,   405,   299,
     408,   409,   268,   416,     0,   198,    38,    38,   328,   407,
       0,     0,   309,   310,   311,   312,     0,   332,     0,     0,
       0,     0,   287,   313,   314,   315,     0,     0,     0,   287,
     287,     0,     0,     0,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,     0,     0,
       0,     0,     0,     0,     0,     0,   212,     0,   372,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   379,     0,
       0,     0,     0,     0,   213,   214,   215,     0,   216,     0,
     217,   218,    71,   219,   220,    12,     0,   221,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,     0,
       0,     0,   223,   224,   225,     5,   344,   393,     0,     0,
       0,     0,   332,     0,     0,     0,   403,     0,     0,     0,
       0,     0,   287,     0,   363,    71,     0,     0,     0,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
     228,     0,     0,   229,     0,     0,   230,     0,   328,     0,
       0,     0,   231,   232,     0,     0,     0,     0,   328,     0,
       0,     0,     0,     0,   233,     0,     0,   234,    -3,     0,
       0,   212,    71,     0,     0,     0,     0,     0,    71,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
     214,   215,     0,   216,   404,   217,   218,     0,   219,   220,
      12,     0,   221,   212,    71,     0,     0,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,   223,   224,   225,
       5,   213,   214,   215,     0,   216,     0,   217,   218,     0,
     219,   220,    12,     0,   221,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   222,     0,     0,     0,   223,
     224,   225,     5,     0,   227,   228,     0,     0,   229,     0,
       0,   230,     0,     0,     0,     0,     0,   231,   232,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,   233,
       0,     0,   234,  -129,     0,     0,   227,   228,     0,     0,
     229,     0,     0,   230,     0,     0,     0,     0,   212,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,     0,   234,   412,   213,   214,   215,     0,
     216,     0,   217,   218,     0,   219,   220,    12,     0,   221,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,     0,     0,     0,   223,   224,   225,     5,   213,   214,
     215,     0,   216,     0,   217,   218,     0,   219,   220,    12,
       0,   221,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,   222,     0,     0,     0,   223,   224,   225,     5,
       0,   227,   228,     0,     0,   229,     0,     0,   230,     0,
       0,     0,     0,     0,   231,   232,     0,     0,     0,     0,
       0,     0,     0,   226,     0,     0,   233,     0,     0,   234,
     420,     0,     0,   227,   228,     0,     0,   229,     0,     0,
     230,     0,     0,     0,     0,   212,   231,   232,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,     0,
       0,   234,   434,   213,   214,   215,     0,   216,     0,   217,
     218,     0,   219,   220,    12,     0,   221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   222,     0,     0,
       0,   223,   224,   225,     5,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,   226,     0,
      58,    59,     0,     0,    60,    61,    62,    63,   227,   228,
      94,     0,   229,     0,     0,   230,     0,     0,    66,     0,
       0,   231,   232,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,     0,     0,   234,     0,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,     0,     0,    67,     0,     0,
      68,    69,    57,     0,     0,     0,    58,    59,    70,     0,
      60,    61,    62,    63,     0,     0,    94,     0,     0,     0,
       0,   196,     0,     0,    66,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
      58,    59,     0,     0,    60,    61,    62,    63,     0,     0,
      94,     0,     0,    67,     0,     0,    68,    69,    66,     5,
       0,   213,   214,   215,    70,   216,     0,   217,   218,     0,
       0,     0,     0,     0,   221,     0,     0,   410,     0,     0,
       0,   213,   214,   215,     0,   216,     0,   217,   218,   223,
     224,    66,     0,     0,   221,     0,     0,    67,     0,     0,
      68,    69,     0,     0,     0,     0,     0,     0,    70,   223,
     224,    66,     0,     0,   283,     0,   226,     0,     0,     0,
      37,     0,     0,     0,     0,   284,   227,   228,     0,     0,
     229,     0,     0,   230,     0,     0,   226,     0,     0,   231,
     232,     0,     0,     0,     0,     0,   227,   228,     0,     0,
     229,   233,     0,   230,   234,   285,     0,     0,     0,   231,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,     0,     0,   234,   343,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,    58,    59,     0,     0,    60,    61,    62,    63,     0,
      64,    65,     0,     0,     0,     0,     0,     0,     0,    66,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,     0,    58,    59,     0,     0,    60,
      61,    62,    63,     0,     0,    94,     0,     0,    67,     0,
       0,    68,    69,    66,     0,     0,   171,     0,     0,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,    67,     0,     0,    68,    69,    57,     0,     0,
       0,    58,    59,    70,     0,    60,    61,    62,    63,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,    66,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,     0,     0,     0,   324,     0,     0,     0,
       0,    57,     0,     0,     0,    58,    59,     0,     0,    60,
      61,    62,    63,     0,     0,    94,     0,     0,    67,     0,
       0,    68,    69,    66,   213,   214,   215,     0,   216,    70,
     217,   218,     0,     0,     0,     0,     0,   221,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,   223,   224,    66,     5,     0,   213,   214,   215,
      57,   216,    67,   217,   218,    68,    69,     0,     0,     0,
     221,     0,     0,    70,     0,     0,     0,     0,     0,   226,
       0,     0,    66,     0,     0,   223,   224,    66,     0,   227,
     228,     0,     0,   229,     0,     0,   230,     0,     0,     0,
       0,     0,   231,   232,     0,     0,     0,     0,     0,     0,
       0,     0,   226,     0,   233,     0,    37,   234,     0,     0,
       0,   117,   227,   228,   118,     0,   229,     0,     0,   230,
       0,     0,     0,     0,     0,   231,   232,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,     0,     0,
     234,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   289,     0,     0,     0,     0,     0,
       0,     0,    57,     0,     0,     0,    58,    59,     0,     0,
      60,    61,    62,    63,     0,     0,    94,     0,     0,   300,
     301,   302,   303,     0,    66,     0,     0,     0,     0,   304,
     305,   306,   307,   308,     0,     0,   309,   310,   311,   312,
     300,   301,   302,   303,     0,     0,     0,   313,   314,   315,
     304,   305,   306,   307,   308,     0,     0,   309,   310,   311,
     312,     0,     0,     0,     0,     0,     0,    69,   313,   314,
     315,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   386,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    66,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,   300,   301,
     302,   303,     0,    57,     0,     0,     0,     0,   304,   305,
     306,   307,   308,     0,     0,   309,   310,   311,   312,     0,
       0,   300,   301,   302,   303,    66,   313,   314,   315,     0,
       0,   304,   305,   306,   307,   308,     0,   329,   309,   310,
     311,   312,     0,     0,   302,   303,     0,     0,     0,   313,
     314,   315,   304,   305,   306,   307,   308,     0,     0,   309,
     310,   311,   312,     0,     0,     0,   303,     0,     0,     0,
     313,   314,   315,   304,   305,   306,   307,   308,     0,     0,
     309,   310,   311,   312,     0,     0,     0,  -182,     0,     0,
       0,   313,   314,   315,   304,   305,   306,   307,   308,     0,
       0,   309,   310,   311,   312,     0,     0,     0,     0,     0,
       0,     0,   313,   314,   315
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-287)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-182)))

static const yytype_int16 yycheck[] =
{
       7,   242,    43,    49,    50,    50,    13,    14,    15,     3,
      46,   122,     6,     7,    50,    47,    49,    49,   129,   130,
     123,    21,    52,    50,    24,    19,    20,    21,   131,    49,
      24,    62,    63,   234,    28,    50,    67,    68,    69,   196,
      11,    52,    52,   200,    21,   196,    23,     0,   104,   200,
      52,    52,    59,    60,    61,    66,    27,    64,    65,    52,
     121,   122,   123,   166,    71,    21,   111,    23,   129,   130,
     131,   112,    49,    52,    32,   111,   109,    35,    36,    52,
     110,   112,   114,   186,   111,    49,   113,   288,    50,   375,
      52,   242,    50,    49,   380,   296,   111,    91,     3,   106,
     107,   258,   259,   113,   160,   166,   162,   258,   259,   140,
      83,   113,   113,   174,   121,   122,   244,   110,   149,    90,
      50,    86,   129,   130,    66,   186,   100,   109,    66,   257,
     124,   110,   283,     0,     1,   109,   113,     4,   112,   104,
     426,    52,   173,   271,   175,    49,   177,   178,    49,   111,
     261,   262,   117,   118,   395,   113,   112,    76,   100,   166,
     263,   402,   100,    30,    75,    32,    52,    76,    35,    36,
     135,   109,   166,   167,   112,     7,    21,   142,    23,   144,
      66,   100,   100,    50,   100,   425,   414,    19,   188,   429,
     431,   109,   186,   109,   188,   160,   424,   162,   112,   193,
     261,   262,   263,    32,    49,    70,    35,    36,    44,    45,
      65,   100,    14,    15,   221,   326,    71,   182,   212,   219,
     109,    50,   109,   284,   375,   219,    21,   378,    23,   380,
      30,   238,   109,    33,    34,    35,    23,   244,    25,   239,
      23,   272,    25,   109,   395,   239,    99,   100,   101,   100,
     257,   402,   114,   410,   261,   262,    44,    45,    58,   410,
      49,   110,    62,    63,   271,   326,   423,    67,    68,    69,
      70,    49,   423,   113,    66,   426,    60,    61,     0,     1,
     431,   112,     4,    52,   315,   112,    86,   110,   295,   110,
     110,   291,   110,    52,   294,    49,   112,   291,   113,    49,
     294,    49,    49,   112,   104,   112,   109,    49,    30,    46,
      32,   109,   112,    35,    36,   109,   316,   117,   118,   326,
     113,    49,   316,   323,   109,    66,    42,   113,    50,   323,
     112,   362,   113,   113,   110,   135,   110,   368,   369,    52,
     140,   113,   142,   219,   144,   110,   109,    43,   110,   149,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   110,
     160,   113,   162,   394,   110,    19,    93,   112,   368,   376,
     370,   400,   107,   173,   368,   175,   370,   177,   178,   113,
     113,   388,   182,   193,    30,   182,   378,   186,   384,   252,
     390,   391,   217,   400,    -1,   174,   390,   391,   274,   388,
      -1,    -1,    88,    89,    90,    91,    -1,   283,    -1,    -1,
      -1,    -1,   288,    99,   100,   101,    -1,    -1,    -1,   295,
     296,    -1,    -1,    -1,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    -1,    23,    -1,
      25,    26,   272,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    -1,    47,    48,    49,    50,   296,   373,    -1,    -1,
      -1,    -1,   378,    -1,    -1,    -1,   382,    -1,    -1,    -1,
      -1,    -1,   388,    -1,   314,   315,    -1,    -1,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,
      85,    -1,    -1,    88,    -1,    -1,    91,    -1,   414,    -1,
      -1,    -1,    97,    98,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,   112,   113,    -1,
      -1,     1,   362,    -1,    -1,    -1,    -1,    -1,   368,   369,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    -1,    23,   384,    25,    26,    -1,    28,    29,
      30,    -1,    32,     1,   394,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    48,    49,
      50,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    43,    -1,    -1,    -1,    47,
      48,    49,    50,    -1,    84,    85,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,    -1,   109,
      -1,    -1,   112,   113,    -1,    -1,    84,    85,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,     1,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,   112,   113,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    28,    29,    30,    -1,    32,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    48,    49,    50,    19,    20,
      21,    -1,    23,    -1,    25,    26,    -1,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    43,    -1,    -1,    -1,    47,    48,    49,    50,
      -1,    84,    85,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,   109,    -1,    -1,   112,
     113,    -1,    -1,    84,    85,    -1,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    -1,     1,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,   112,   113,    19,    20,    21,    -1,    23,    -1,    25,
      26,    -1,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    47,    48,    49,    50,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    74,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    38,    84,    85,
      41,    -1,    88,    -1,    -1,    91,    -1,    -1,    49,    -1,
      -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,   112,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    88,    -1,    -1,
      91,    92,    27,    -1,    -1,    -1,    31,    32,    99,    -1,
      35,    36,    37,    38,    -1,    -1,    41,    -1,    -1,    -1,
      -1,   112,    -1,    -1,    49,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    38,    -1,    -1,
      41,    -1,    -1,    88,    -1,    -1,    91,    92,    49,    50,
      -1,    19,    20,    21,    99,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,   112,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,    -1,    25,    26,    47,
      48,    49,    -1,    -1,    32,    -1,    -1,    88,    -1,    -1,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    47,
      48,    49,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    83,    84,    85,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    74,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      88,   109,    -1,    91,   112,   113,    -1,    -1,    -1,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,   112,   113,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,
      -1,    31,    32,    -1,    -1,    35,    36,    37,    38,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,    88,    -1,
      -1,    91,    92,    49,    -1,    -1,    52,    -1,    -1,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    88,    -1,    -1,    91,    92,    27,    -1,    -1,
      -1,    31,    32,    99,    -1,    35,    36,    37,    38,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    66,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    41,    -1,    -1,    88,    -1,
      -1,    91,    92,    49,    19,    20,    21,    -1,    23,    99,
      25,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    47,    48,    49,    50,    -1,    19,    20,    21,
      27,    23,    88,    25,    26,    91,    92,    -1,    -1,    -1,
      32,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    -1,    49,    -1,    -1,    47,    48,    49,    -1,    84,
      85,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,   109,    -1,   111,   112,    -1,    -1,
      -1,    88,    84,    85,    91,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
     112,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    -1,    -1,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    41,    -1,    -1,    71,
      72,    73,    74,    -1,    49,    -1,    -1,    -1,    -1,    81,
      82,    83,    84,    85,    -1,    -1,    88,    89,    90,    91,
      71,    72,    73,    74,    -1,    -1,    -1,    99,   100,   101,
      81,    82,    83,    84,    85,    -1,    -1,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    92,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    27,    -1,    -1,    -1,    -1,    81,    82,
      83,    84,    85,    -1,    -1,    88,    89,    90,    91,    -1,
      -1,    71,    72,    73,    74,    49,    99,   100,   101,    -1,
      -1,    81,    82,    83,    84,    85,    -1,   110,    88,    89,
      90,    91,    -1,    -1,    73,    74,    -1,    -1,    -1,    99,
     100,   101,    81,    82,    83,    84,    85,    -1,    -1,    88,
      89,    90,    91,    -1,    -1,    -1,    74,    -1,    -1,    -1,
      99,   100,   101,    81,    82,    83,    84,    85,    -1,    -1,
      88,    89,    90,    91,    -1,    -1,    -1,    74,    -1,    -1,
      -1,    99,   100,   101,    81,    82,    83,    84,    85,    -1,
      -1,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,   100,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   116,    49,     0,    50,   111,   118,   120,   120,
       1,     4,    30,    32,    35,    36,   117,   119,   120,   122,
     125,   127,   130,   131,   164,    21,    23,    49,   112,   126,
      49,   109,   117,   168,   168,   168,   131,   111,   120,   121,
     121,   121,   126,   120,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    27,    31,    32,
      35,    36,    37,    38,    40,    41,    49,    88,    91,    92,
      99,   147,   149,   158,   162,   163,   174,   176,   177,   178,
     179,   180,   181,   183,   184,   185,    49,   147,   147,   147,
      49,   126,   128,   129,    41,   148,   162,   175,   117,   173,
     173,   173,   175,   175,    76,   117,   152,   152,   175,   175,
     175,    47,   114,   147,   182,   100,   152,    88,    91,   167,
     184,   109,   109,   109,   126,   120,   113,   128,   112,   109,
     109,   109,   153,   154,   184,    70,   117,   155,   155,   175,
     114,    49,    38,   184,    38,   184,   110,    49,   117,   123,
     169,   170,   171,   169,   170,   120,   113,   169,   169,   170,
      52,    75,    66,   153,   156,   157,   112,   112,   175,   184,
     184,    52,   175,   110,    52,   110,   110,   110,   110,   110,
     153,   153,    52,   117,   120,   159,   160,   161,   170,    32,
      35,    36,   120,   150,   151,    49,   112,   175,   171,   175,
     112,   175,   175,   156,   159,   113,   121,    49,    49,    49,
     113,   151,     1,    19,    20,    21,    23,    25,    26,    28,
      29,    32,    43,    47,    48,    49,    74,    84,    85,    88,
      91,    97,    98,   109,   112,   117,   120,   123,   124,   125,
     133,   134,   135,   138,   146,   147,   165,   172,   186,   188,
     189,   192,   193,   194,   195,   196,   197,   199,   112,   112,
     172,   109,   109,   109,   111,   113,   120,   132,   196,   199,
     121,   195,    49,   117,   139,   195,   195,   195,   195,   195,
     195,   195,   195,    72,    83,   113,   187,   195,    66,    46,
     117,   145,   121,   134,   145,   109,   112,   113,    23,   192,
      71,    72,    73,    74,    81,    82,    83,    84,    85,    88,
      89,    90,    91,    99,   100,   101,   145,   172,   172,   113,
     169,   169,   170,   145,    66,   175,   109,   136,   195,   110,
     166,   172,   195,   123,    52,   113,   187,    49,   121,   121,
     117,   187,   198,   113,   147,   187,   190,   191,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   195,   195,
     195,   195,   109,   147,   175,   121,   113,   113,   110,   110,
     110,   121,   195,    66,   169,    42,   137,   113,    83,   195,
     112,   110,    66,   113,    52,   113,   114,   175,   109,   121,
     175,   175,   121,   195,   110,   135,    44,    45,   117,   140,
     143,   166,   135,   195,   147,   191,   110,   198,   121,   121,
     112,   175,   113,    43,   141,    44,   117,   140,   144,   113,
     113,   110,   172,   112,   142,   136,   112,   113,   172,   136,
     137,   135,   113,   137,   113
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

    { yoParserDeclVar(&(yyval), &(yyvsp[(2) - (2)]), NULL, parm, &yyloc); }
    break;

  case 16:

    { yoParserDeclVar(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 17:

    {
				yoParserDeclVar(&(yyvsp[(1) - (4)]), &(yyvsp[(2) - (4)]), NULL, parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (4)]), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(2) - (4)]), parm, &yyloc);
			}
    break;

  case 18:

    {
				yoParserDeclVar(&(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(3) - (5)]), parm, &yyloc); 
				yoParserAssign(&(yyvsp[(2) - (5)]), &(yyvsp[(2) - (5)]), &(yyvsp[(5) - (5)]), T_INIT_ASSIGN, parm, &yyloc); 
				yoParserList(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(2) - (5)]), parm, &yyloc);
			}
    break;

  case 19:

    { yoParserDeclType(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 22:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 23:

    { yoParserImport(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 24:

    { (yyval) = (yyvsp[(4) - (5)]); }
    break;

  case 25:

    { yoParserImport(&(yyval), NULL, &(yyvsp[(1) - (2)]), parm, &yyloc); }
    break;

  case 26:

    { yoParserImport(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 28:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 32:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; yyerrok; }
    break;

  case 38:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 40:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (4)]), parm, &yyloc); yoParserStmtCatch(&(yyval), &(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 41:

    { yoParserStmtReturn(&(yyval), NULL, parm, &yyloc); }
    break;

  case 43:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 44:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 45:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; yyerrok; }
    break;

  case 49:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 51:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 52:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 53:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 54:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 55:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 56:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 57:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); }
    break;

  case 59:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 61:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 63:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 65:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
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

  case 107:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
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

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (8)]), NULL, &(yyvsp[(7) - (8)]), parm, &yyloc); }
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

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 127:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 128:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 132:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 133:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 134:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 135:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 138:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 139:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 141:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 142:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 143:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 144:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 147:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 151:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 152:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 153:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 154:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 155:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 156:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 157:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 158:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 159:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 160:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 163:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 164:

    { yoParserConst(&(yyval), T_TRUE, parm, &yyloc); }
    break;

  case 165:

    { yoParserConst(&(yyval), T_FALSE, parm, &yyloc); }
    break;

  case 166:

    { yoParserConst(&(yyval), T_NULL, parm, &yyloc); }
    break;

  case 172:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 173:

    { yoParserNewArr(&(yyval), parm, &yyloc); }
    break;

  case 174:

    { yoParserNewArrExps(&(yyval), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 175:

    { yoParserNewObj(&(yyval), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 176:

    { yoParserNewObjExps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 177:

    { yoParserNewObjProps(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 179:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 180:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
    break;

  case 181:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 183:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 184:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), T_CONCAT, parm, &yyloc); }
    break;

  case 192:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 193:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 194:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 195:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 196:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 197:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 198:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
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

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 207:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 210:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 211:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 212:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 213:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 214:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 215:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 216:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 217:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 218:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 221:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 222:

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




