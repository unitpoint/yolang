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
     T_EXTERN = 288,
     T_FUNC = 289,
     T_SUB_FUNC = 290,
     T_LAMBDA = 291,
     T_EXTERN_FUNC = 292,
     T_GET = 293,
     T_SET = 294,
     T_CONST = 295,
     T_MUTABLE = 296,
     T_STRUCT = 297,
     T_CLASS = 298,
     T_CONTRACT = 299,
     T_BRACE = 300,
     T_IF = 301,
     T_ELSE = 302,
     T_ELSEIF = 303,
     T_CATCH = 304,
     T_SIZEOF = 305,
     T_LNUMBER = 306,
     T_DNUMBER = 307,
     T_NAME = 308,
     T_NEWLINE = 309,
     T_FIX = 310,
     T_POW_ASSIGN = 311,
     T_RSH_ASSIGN = 312,
     T_LSH_ASSIGN = 313,
     T_XOR_ASSIGN = 314,
     T_OR_ASSIGN = 315,
     T_AND_ASSIGN = 316,
     T_MOD_ASSIGN = 317,
     T_CONCAT_ASSIGN = 318,
     T_DIV_ASSIGN = 319,
     T_MUL_ASSIGN = 320,
     T_MINUS_ASSIGN = 321,
     T_PLUS_ASSIGN = 322,
     T_DECL_ASSIGN = 323,
     T_ASSIGN = 324,
     T_INIT_ASSIGN = 325,
     T_PROP_ASSIGN = 326,
     T_XORXOR = 327,
     T_OROR = 328,
     T_ANDAND = 329,
     T_CHAN_ACCESS = 330,
     T_GT = 331,
     T_LT = 332,
     T_GE = 333,
     T_LE = 334,
     T_NE = 335,
     T_EQ = 336,
     T_CONCAT = 337,
     T_XOR = 338,
     T_OR = 339,
     T_MINUS = 340,
     T_PLUS = 341,
     T_RSH = 342,
     T_LSH = 343,
     T_AND = 344,
     T_MOD = 345,
     T_DIV = 346,
     T_MUL = 347,
     T_POW = 348,
     T_AT = 349,
     T_UNARY = 350,
     T_DEC = 351,
     T_INC = 352,
     T_TILDE = 353,
     T_NOT = 354,
     T_DOT = 355,
     T_AS = 356,
     T_INDIRECT = 357,
     T_ADDR = 358,
     T_INDEX = 359,
     T_PTR = 360,
     T_ARR = 361,
     T_DOTNAME = 362,
     NotParen = 363
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
#define YYLAST   1824

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  119
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  86
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNRULES -- Number of states.  */
#define YYNSTATES  475

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     113,   114,     2,     2,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,   115,
       2,     2,     2,    73,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   103,     2,   118,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   116,     2,   117,     2,     2,     2,     2,
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
      55,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   104,   105,   106,   107,   108,
     109,   110,   111,   112
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
     319,   321,   323,   325,   327,   329,   331,   333,   343,   351,
     362,   373,   383,   393,   403,   410,   415,   417,   419,   422,
     426,   429,   433,   438,   440,   442,   444,   446,   450,   454,
     458,   460,   462,   464,   470,   477,   484,   490,   492,   494,
     497,   500,   503,   506,   509,   512,   516,   518,   520,   525,
     527,   530,   532,   534,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   554,   556,   558,   560,   562,   564,   566,
     568,   570,   572,   574,   576,   580,   583,   587,   591,   596,
     601,   603,   607,   611,   614,   616,   619,   622,   624,   626,
     628,   630,   632,   634,   638,   642,   646,   650,   654,   658,
     662,   666,   670,   674,   678,   682,   686,   690,   694,   698,
     702,   706,   710,   714,   718,   723,   725,   729,   731,   733,
     737,   743,   746,   749,   752,   755,   758,   761,   764,   767,
     771,   773,   775,   780
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     120,     0,    -1,     3,    53,   122,   123,    -1,    -1,   124,
      -1,   115,   124,    -1,   126,    -1,   121,    -1,    54,    -1,
     124,    -1,   115,    -1,   136,    -1,   126,   136,    -1,    53,
      -1,   127,    56,    53,    -1,   180,    -1,   121,    -1,    30,
     121,    53,   128,    -1,    30,    41,    53,   128,    -1,    30,
     121,    53,   128,    70,   200,    -1,    30,    41,    53,   128,
      70,   200,    -1,    31,    53,   167,    -1,    23,    -1,    21,
      -1,     4,   131,    -1,     4,    53,   131,    -1,     4,   116,
     124,   134,   117,    -1,   131,   124,    -1,    53,   131,   124,
      -1,   133,    -1,   134,   133,    -1,   132,   125,    -1,   130,
     125,    -1,   168,   125,    -1,     1,    -1,   135,    -1,   124,
      -1,   121,    -1,   129,   150,   125,    -1,   169,   150,   125,
      -1,   130,   125,    -1,    29,   200,   150,   125,    -1,    29,
     125,    -1,   143,    -1,   202,   150,   125,    -1,   204,   150,
     125,    -1,     1,   137,    -1,   138,    -1,   124,    -1,   139,
      -1,   140,   139,    -1,   200,    -1,    45,   140,   117,    -1,
      -1,    46,   144,   141,   142,   148,   149,    -1,    -1,    48,
     146,   141,   142,    -1,    -1,    47,    46,   147,   141,   142,
      -1,   145,    -1,   148,   145,    -1,   121,    -1,    47,   116,
     140,   117,    -1,   121,    -1,    49,    53,   116,   140,   117,
      -1,   121,    -1,    53,    -1,   151,   104,    53,    -1,    44,
     116,   117,    -1,    44,   156,   159,   116,   154,   117,    -1,
     155,    -1,   154,   155,    -1,    34,    53,   113,   174,   114,
     125,    -1,    34,    53,   113,   174,   114,   180,   125,    -1,
      38,    53,   113,   174,   114,   180,   125,    -1,    39,    53,
     113,   175,   114,   125,    -1,   124,    -1,    80,   158,    79,
      -1,   121,    -1,   189,    -1,   189,    70,   157,    -1,   157,
      -1,   158,    56,   157,    -1,    74,   161,    -1,   121,    -1,
     157,    -1,   160,    -1,   161,    56,   160,    -1,    43,   156,
     159,   116,   165,   117,    -1,   176,   125,    -1,   124,    -1,
     163,    -1,   164,   163,    -1,   164,    -1,   121,    -1,   189,
      -1,   181,    -1,   182,    -1,   183,    -1,   185,    -1,   184,
      -1,   186,    -1,   188,    -1,   179,    -1,   166,    -1,   153,
      -1,   162,    -1,    33,    34,   151,   113,   175,    56,     5,
     114,   128,    -1,    33,    34,   151,   113,   174,   114,   128,
      -1,    34,   173,   151,   113,   174,   114,   128,   116,   177,
     117,    -1,    38,   173,   151,   113,   174,   114,   180,   116,
     177,   117,    -1,    39,   173,   151,   113,   175,   114,   116,
     177,   117,    -1,    34,    53,   113,   174,   114,   128,   116,
     177,   117,    -1,    34,   121,   113,   174,   114,   128,   116,
     177,   117,    -1,   116,    87,   174,    87,   171,   117,    -1,
     116,    76,   171,   117,    -1,   200,    -1,   189,    -1,    95,
     189,    -1,    95,    41,   189,    -1,    92,   189,    -1,    92,
      41,   189,    -1,   113,    53,   172,   114,    -1,   121,    -1,
     175,    -1,   121,    -1,   176,    -1,   175,    56,   176,    -1,
     121,   127,   180,    -1,    41,   127,   180,    -1,   140,    -1,
     121,    -1,   121,    -1,    34,   178,   113,   174,   114,    -1,
      34,   178,   113,   174,   114,   180,    -1,    38,   178,   113,
     174,   114,   180,    -1,    39,   178,   113,   175,   114,    -1,
     166,    -1,   152,    -1,    40,   180,    -1,    41,   180,    -1,
      32,   180,    -1,    92,   180,    -1,    95,   180,    -1,    96,
     180,    -1,   103,   118,   180,    -1,    51,    -1,   151,    -1,
     103,   187,   118,   180,    -1,   190,    -1,   151,   156,    -1,
       6,    -1,     7,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    14,    -1,    17,    -1,
      15,    -1,    16,    -1,    18,    -1,    27,    -1,    73,    -1,
      19,    -1,    20,    -1,    26,    -1,    51,    -1,    52,    -1,
      21,    -1,    23,    -1,   200,    -1,   192,    56,   200,    -1,
     116,   117,    -1,   116,   192,   117,    -1,   151,   116,   117,
      -1,   151,   116,   192,   117,    -1,   151,   116,   195,   117,
      -1,   196,    -1,   195,    56,   196,    -1,    53,    74,   200,
      -1,    25,   201,    -1,   197,    -1,   198,   197,    -1,   198,
      23,    -1,   201,    -1,   199,    -1,   191,    -1,   151,    -1,
     193,    -1,   194,    -1,   200,    84,   200,    -1,   200,    83,
     200,    -1,   200,    82,   200,    -1,   200,    81,   200,    -1,
     200,    80,   200,    -1,   200,    79,   200,    -1,   200,    89,
     200,    -1,   200,    88,   200,    -1,   200,    95,   200,    -1,
     200,    94,   200,    -1,   200,    93,   200,    -1,   200,    96,
     200,    -1,   200,    85,   200,    -1,   200,    87,   200,    -1,
     200,    76,   200,    -1,   200,    92,   200,    -1,   200,    77,
     200,    -1,   200,    86,   200,    -1,   200,    75,   200,    -1,
     200,    78,   200,    -1,   200,   104,   151,    -1,   200,   103,
     200,   118,    -1,   202,    -1,   113,   200,   114,    -1,   204,
      -1,   170,    -1,   200,   105,   180,    -1,   200,   104,   113,
     180,   114,    -1,    89,   200,    -1,    88,   200,    -1,   102,
     200,    -1,   101,   200,    -1,    78,   200,    -1,    50,   200,
      -1,    95,   200,    -1,    92,   200,    -1,   200,    70,   200,
      -1,   192,    -1,   121,    -1,   151,   113,   203,   114,    -1,
     200,   104,   151,   113,   203,   114,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   230,   230,   233,   242,   243,   246,   247,   250,   253,
     254,   257,   258,   261,   262,   265,   266,   269,   270,   271,
     276,   283,   286,   287,   290,   291,   292,   295,   296,   299,
     300,   303,   304,   305,   306,   309,   310,   313,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   332,   333,   336,
     337,   348,   351,   354,   354,   359,   359,   360,   360,   363,
     364,   365,   368,   369,   372,   373,   376,   377,   380,   383,
     386,   387,   390,   391,   392,   393,   394,   397,   398,   401,
     402,   405,   406,   409,   410,   413,   416,   417,   420,   423,
     424,   441,   442,   445,   446,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   460,   461,   462,   465,   467,   469,
     471,   473,   477,   485,   487,   489,   493,   497,   498,   499,
     500,   501,   504,   505,   508,   509,   512,   513,   516,   517,
     520,   521,   530,   533,   534,   535,   536,   539,   540,   543,
     546,   549,   552,   555,   556,   563,   567,   568,   571,   575,
     577,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   597,   598,   599,   600,
     601,   602,   603,   606,   607,   610,   611,   614,   615,   616,
     619,   620,   623,   626,   629,   630,   633,   636,   637,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   695,
     698,   699,   702,   703
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
  "T_LET", "T_TYPE", "T_CHAN", "T_EXTERN", "T_FUNC", "T_SUB_FUNC",
  "T_LAMBDA", "T_EXTERN_FUNC", "T_GET", "T_SET", "T_CONST", "T_MUTABLE",
  "T_STRUCT", "T_CLASS", "T_CONTRACT", "T_BRACE", "T_IF", "T_ELSE",
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
  "\"* (T_MUL)\"", "\"** (T_POW)\"", "\"@ (T_AT)\"", "T_UNARY",
  "\"-- (T_DEC)\"", "\"++ (T_INC)\"", "\"~ (T_TILDE)\"", "\"! (T_NOT)\"",
  "'['", "\". (T_DOT)\"", "\"as (T_AS)\"", "\"* (T_INDIRECT)\"",
  "\"& (T_ADDR)\"", "\"[] (T_INDEX)\"", "T_PTR", "T_ARR", "T_DOTNAME",
  "NotParen", "'('", "')'", "';'", "'{'", "'}'", "']'", "$accept", "file",
  "empty", "end_newline", "module_stmt_list", "newline", "end_stmt",
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
     305,   306,   307,   308,   309,   310,    44,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,    63,    58,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,    91,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    40,    41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   119,   120,   121,   122,   122,   123,   123,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   129,
     129,   130,   131,   131,   132,   132,   132,   133,   133,   134,
     134,   135,   135,   135,   135,   136,   136,   137,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   142,   144,   143,   146,   145,   147,   145,   148,
     148,   148,   149,   149,   150,   150,   151,   151,   152,   153,
     154,   154,   155,   155,   155,   155,   155,   156,   156,   157,
     157,   158,   158,   159,   159,   160,   161,   161,   162,   163,
     163,   164,   164,   165,   165,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   167,   167,   167,   168,   168,   168,
     168,   168,   169,   170,   170,   170,   171,   172,   172,   172,
     172,   172,   173,   173,   174,   174,   175,   175,   176,   176,
     177,   177,   178,   179,   179,   179,   179,   180,   180,   181,
     182,   183,   184,   185,   185,   186,   187,   187,   188,   189,
     189,   190,   190,   190,   190,   190,   190,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   191,   191,   191,   191,
     191,   191,   191,   192,   192,   193,   193,   194,   194,   194,
     195,   195,   196,   197,   198,   198,   199,   200,   200,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   202,
     203,   203,   204,   204
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
       1,     1,     1,     1,     1,     1,     1,     9,     7,    10,
      10,     9,     9,     9,     6,     4,     1,     1,     2,     3,
       2,     3,     4,     1,     1,     1,     1,     3,     3,     3,
       1,     1,     1,     5,     6,     6,     5,     1,     1,     2,
       2,     2,     2,     2,     2,     3,     1,     1,     4,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     4,     4,
       1,     3,     3,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     1,     3,     1,     1,     3,
       5,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       1,     1,     4,     6
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     8,     0,     0,     4,     5,
      34,     0,     0,     0,     3,     3,     3,     7,     2,    36,
       0,     0,     0,    35,    11,     0,    23,    22,     0,     0,
      24,     0,     0,     0,   123,     0,     0,     0,    12,    10,
       9,    32,    31,    33,    25,     0,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   161,   162,   160,   163,   164,
       0,     3,     3,     3,     0,     0,     3,     3,    66,   165,
       0,     0,     0,     0,     3,   105,   106,   104,    21,   103,
      96,    97,    98,   100,    99,   101,   102,    95,   149,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,   138,
     137,   141,   132,     0,     0,     0,   139,   140,     0,    78,
       3,     3,   142,   143,   144,   146,     0,   147,     0,     0,
     150,     3,     0,     0,     0,   117,     3,     3,     3,     0,
      27,    26,    30,     0,     3,     3,     3,    81,     0,    79,
       0,    84,     0,     0,   145,     0,    67,     0,   125,     0,
     124,   126,     0,   120,     0,   118,   122,     0,   124,     0,
       0,     0,    28,    68,     0,     0,     0,     0,    77,     0,
      85,    86,    83,     3,     0,   148,    13,     0,     0,     3,
       3,   121,   119,     3,     3,     0,     0,   133,     0,   136,
      82,    80,     0,    94,    90,    91,     3,     0,     0,     0,
       0,     0,    76,     0,    70,     0,   129,   128,    16,   108,
      15,     0,   127,     0,     0,     0,   134,   135,    87,    92,
      88,    89,     0,     0,     0,    69,    71,    14,     3,     0,
       0,     3,   166,   167,   171,   172,     0,   168,     0,     3,
       3,    53,     0,   169,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,    48,     3,     0,    47,    49,
       0,    43,   190,     3,   218,     0,   189,   191,   192,   184,
       0,   188,     0,   187,   215,   217,     3,     3,     3,   107,
       0,     0,    37,    46,     3,   187,   215,   217,    42,     3,
       0,     0,     0,     0,     0,   226,   225,   222,   221,   228,
     227,   224,   223,     0,     0,     3,   175,     0,   173,     0,
      65,     0,    40,    50,     3,     0,     0,   111,   186,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     3,     3,     3,     3,     0,    51,   216,     0,
     116,     0,     0,   176,     0,    38,   231,   230,     0,    66,
     177,     0,     0,   180,    39,   229,   211,   207,   209,   212,
     198,   197,   196,   195,   194,   193,   205,   210,   206,   200,
     199,   208,   203,   202,   201,   204,     0,     0,   213,   219,
      44,    45,     0,     0,     0,    41,    18,    17,     0,     0,
       0,     3,   115,     0,   174,     0,   232,     0,   178,     0,
     179,   214,     0,     3,    72,     0,     0,    75,     0,     0,
       3,     3,     0,     0,    55,    61,    59,     3,     0,     0,
     182,     0,   181,   220,     0,    73,    74,    20,    19,     0,
       0,    52,    57,     0,     0,    63,    60,    54,   114,    64,
     233,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,   112,   113,    58,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   148,     7,    18,    40,    41,    20,   178,   209,
     256,   257,    95,    22,    96,    97,    23,    24,   283,   258,
     259,   260,   356,   411,   261,   294,   436,   453,   463,   437,
     457,   311,   262,    99,    75,   203,   204,   110,   170,   138,
     142,   171,   172,    76,   195,   196,   197,   100,    78,    25,
     263,   264,   359,   124,    35,   149,   158,   151,   265,   103,
      79,   210,    80,    81,    82,    83,    84,    85,   118,    86,
      87,    88,   266,   367,   267,   268,   372,   373,   269,   270,
     271,   272,   273,   286,   368,   287
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -397
static const yytype_int16 yypact[] =
{
      42,    25,    60,   -43,  -397,  -397,    40,   271,  -397,  -397,
    -397,    -5,    77,   102,    33,    33,    33,  -397,  -397,  -397,
     316,   -13,   -13,  -397,  -397,   -13,  -397,  -397,    91,    40,
    -397,  1337,   144,   148,  -397,   144,   144,   144,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,    86,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
    1456,  -397,  -397,  -397,  1456,  1456,   128,   128,  -397,  -397,
    1456,  1456,  1456,   -38,     6,  -397,  -397,  -397,  -397,  -397,
    -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,    -9,
     595,    37,    61,    75,    91,    40,  -397,   -14,   116,  -397,
    -397,  -397,  -397,   126,   129,   130,  -397,  -397,   145,  -397,
     170,   170,  -397,  -397,  -397,  -397,  1456,   154,   127,   209,
    -397,   223,   754,   843,   151,  -397,   223,   223,   223,    40,
    -397,  -397,  -397,   149,   223,   223,   223,  -397,    63,   197,
     145,  -397,   152,   153,  -397,  1456,  -397,   220,   220,   160,
     221,  -397,   145,  -397,   145,  -397,  -397,   162,   224,   165,
     220,   -37,  -397,  -397,   172,   173,    -1,   145,  -397,   145,
    -397,  -397,   228,    34,    95,  -397,  -397,  1386,  1386,  1456,
      48,  -397,  -397,  1456,   223,  1456,   174,  1117,  1456,  -397,
    -397,  -397,   145,   220,  -397,  -397,     5,   171,   -13,   236,
     239,   240,  -397,     4,  -397,   242,  -397,  -397,  -397,  -397,
    -397,   183,  -397,   182,   185,   613,  -397,  -397,  -397,  -397,
    -397,  -397,   193,   195,   198,  -397,  -397,  -397,  1456,   613,
     613,  -397,  -397,  -397,  -397,  -397,  1566,  -397,  1482,   272,
     259,  -397,  1566,  -397,  -397,  1566,  1566,  1566,  1566,  1566,
    1566,  1566,  1566,  1205,  -397,  -397,   265,   -13,  -397,  -397,
     702,  -397,    79,   265,  -397,   201,  -397,  -397,  -397,  -397,
     141,  -397,  1692,  -397,     0,     0,   223,   223,   223,  -397,
     202,   205,  -397,  -397,  -397,   194,  -397,  -397,  -397,  1545,
     262,   270,   211,   218,  1566,    64,    64,    64,    64,    64,
      64,    64,    64,  1652,  1566,   223,  -397,     8,  1692,   273,
    -397,   -13,  -397,  -397,  1566,  1225,   -13,  -397,  -397,  -397,
    1566,  1566,  1566,  1566,  1566,  1566,  1566,  1566,  1566,  1566,
    1566,  1566,  1566,  1566,  1566,  1566,  1566,  1566,  1566,  1566,
    1566,  1566,    31,  1456,   -13,   -13,   222,   225,     9,  -397,
    -397,   -13,  1456,  1456,   223,   223,   287,  1692,  -397,   226,
    1692,   248,  1566,  -397,   232,  -397,  -397,   281,   237,   268,
    -397,    10,    15,  -397,  -397,  1692,   435,   435,   857,   946,
    1719,  1719,  1719,  1719,  1719,  1719,   156,   156,   156,   156,
     156,   111,   111,   111,   111,    64,  1608,  1456,   243,  -397,
    -397,  -397,  1169,  1456,   -13,  -397,   282,   283,   244,   247,
    1058,   157,  -397,  1566,  1692,  1058,  -397,  1566,  -397,   311,
    -397,  -397,   251,  1566,  -397,   -13,   -13,  -397,  1566,  1566,
    1456,  1456,   791,   320,  -397,  -397,  -397,   176,   250,   880,
    1692,   268,  -397,  -397,   254,  -397,  -397,  1692,  1692,   255,
     256,  -397,  -397,  1566,   -34,  -397,  -397,  -397,  -397,  -397,
    -397,   613,   613,  1566,   287,  1058,   258,   260,   287,  -397,
     969,  -397,  -397,  -397,  -397
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -397,  -397,     7,  -397,  -397,    -3,   -17,  -397,   229,  -177,
    -397,    80,    22,  -397,   286,  -397,  -397,   358,  -397,  -397,
    -250,  -325,  -396,  -344,  -397,  -397,   -53,  -397,  -397,  -397,
    -397,   -90,   309,  -397,  -397,  -397,   186,   -11,   -68,  -397,
     275,   196,  -397,  -397,   199,  -397,  -397,   359,  -397,  -397,
    -397,  -397,   -21,  -397,   213,   -99,   -84,    29,  -228,   168,
    -397,   -40,  -397,  -397,  -397,  -397,  -397,  -397,  -397,  -397,
     -61,  -397,  -397,  -219,  -397,  -397,  -397,   -26,   124,  -397,
    -397,   257,   161,  -132,   -25,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -184
static const yytype_int16 yytable[] =
{
       8,   280,   281,     9,    19,    42,   213,    26,    43,    27,
     313,     5,   452,   115,    17,    68,    26,    19,    27,   184,
     101,    34,    34,    34,   106,   107,    45,   157,   159,   125,
     112,   113,   114,    30,   307,   164,   165,   150,   199,    94,
     137,     5,   200,   201,   161,     1,   147,   139,    28,   309,
      44,   279,   166,   211,    -3,   184,   111,   464,     5,     5,
       4,   153,   155,   120,   362,   184,   362,   468,   102,   102,
     102,   419,     6,   109,   109,   147,   144,   186,     3,   139,
     116,   109,   465,   274,    68,   432,   108,    21,     5,   147,
     439,   181,   130,   182,     5,   119,   371,   274,   274,   190,
      21,   191,    39,   131,   121,   175,   139,    26,   139,    27,
     119,    29,    26,   189,    27,    -3,   129,   141,   141,   167,
     469,   225,   -93,   404,   473,   363,   162,   418,   274,   199,
      31,   139,   420,   200,   201,   160,    32,   206,   207,    94,
     470,   119,   168,   160,   397,   214,    33,   216,   217,     5,
     126,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   318,   119,   236,   341,   342,   343,
     194,   202,    59,   316,   127,   406,   407,   346,   347,   119,
     193,   221,   313,   119,   344,   345,   208,   160,   128,   313,
     208,   160,   314,   194,   348,   315,   275,    68,    68,   351,
     202,    90,   198,   160,   433,   434,   361,   340,   108,   212,
     275,   275,   255,   212,   341,   342,   343,  -183,    69,  -183,
     313,   288,   254,   454,   434,   198,   255,   255,    36,    37,
     104,   105,   133,   466,   467,   208,   254,   254,   282,   134,
     312,   275,   135,   136,   140,   145,   291,   293,   336,   337,
     338,   339,   340,   449,   450,   408,   409,   255,   119,   341,
     342,   343,   146,   310,   147,   156,   163,   169,   173,   174,
     310,    -3,    10,   176,   179,    11,   183,   180,   274,   185,
     184,   310,   310,   274,   192,   160,   187,   188,   220,   222,
     215,   293,   223,   224,   365,   227,   310,   228,   229,   374,
     274,   230,    12,   399,    13,    14,   276,   274,   277,    15,
      16,   278,   292,   290,   309,   352,    -6,    10,   317,   349,
      11,   366,   350,   353,   354,     5,   364,   400,   401,   274,
     274,   355,   410,   274,   405,   413,   402,   362,   274,   403,
      74,    89,   417,   412,    91,    92,    93,    12,   415,    13,
      14,   416,   428,   429,    15,    16,   423,   422,   430,   208,
     208,   431,   425,   426,   441,   443,   452,   458,   460,    74,
       5,   461,   462,    74,    74,   471,   177,   472,    38,    74,
      74,    74,   117,   132,   456,   424,   143,   427,   218,   226,
      77,   275,   438,   442,   319,   219,   275,   285,   444,    74,
       0,     0,     0,     0,     0,     0,     0,   255,   445,   446,
       0,     0,   255,   275,     0,     0,     0,    74,   435,     0,
     275,     0,     0,     0,     0,    74,     0,     0,     0,   255,
     366,    74,    74,     0,     0,     0,   255,   208,   208,     0,
       0,     0,   275,   275,   455,     0,   275,     0,     0,    74,
       0,   275,     0,     0,    74,     0,     0,     0,   255,   255,
       0,    74,   255,    74,     0,     0,     0,   255,   254,   254,
       0,     0,     0,     0,     0,     0,    74,     0,    74,     0,
       0,     0,     0,     0,     0,     0,    74,    74,    74,     0,
       0,     0,    74,     0,    74,   289,    74,    74,     0,   295,
       0,    74,   296,   297,   298,   299,   300,   301,   302,   303,
     308,     0,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,     0,     0,   336,   337,   338,
     339,   340,     0,     0,     0,     0,     0,    74,   341,   342,
     343,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   308,   308,     0,     0,     0,     0,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,     0,
       0,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,   231,     0,     0,     0,     0,   414,
       0,     0,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   233,   234,     0,   235,     0,   236,   237,
       0,     0,   238,   239,    12,     0,     0,   240,    68,     0,
       0,   398,    74,     0,     0,     0,     0,     0,     0,   241,
       0,    74,    74,   242,   243,   244,    68,     5,    69,     0,
     360,     0,     0,     0,   440,     0,     0,     0,     0,     0,
     308,     0,     0,     0,     0,   447,   448,   122,     0,     0,
     123,   245,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   246,   247,   231,     0,   248,    74,     0,   249,     0,
     357,    74,    74,     0,   250,   251,     0,     0,     0,     0,
     357,   232,   233,   234,     0,   235,   252,   236,   237,   253,
      -3,   238,   239,    12,     0,     0,   240,     0,     0,    74,
      74,     0,     0,     0,     0,     0,     0,     0,   241,     0,
       0,     0,   242,   243,   244,    68,     5,     0,     0,     0,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,     0,     0,     0,     0,
     245,    59,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,   231,     0,   248,   152,     0,   249,     0,     0,
       0,     0,     0,   250,   251,     0,     0,    68,     0,     0,
     232,   233,   234,     0,   235,   252,   236,   237,   253,  -130,
     238,   239,    12,     0,     0,   240,     0,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,     0,     0,
       0,   242,   243,   244,    68,     5,     0,     0,     0,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,     0,     0,     0,   245,
      59,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     247,   231,     0,   248,   154,     0,   249,     0,     0,     0,
       0,     0,   250,   251,     0,     0,    68,     0,     0,   232,
     233,   234,     0,   235,   252,   236,   237,   253,   451,   238,
     239,    12,     0,     0,   240,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   241,     0,     0,     0,
     242,   243,   244,    68,     5,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,     0,     0,   336,
     337,   338,   339,   340,     0,     0,     0,     0,   245,     0,
     341,   342,   343,     0,     0,     0,     0,     0,   246,   247,
     231,     0,   248,     0,     0,   249,     0,     0,     0,     0,
       0,   250,   251,     0,     0,     0,     0,     0,   232,   233,
     234,     0,   235,   252,   236,   237,   253,   459,   238,   239,
      12,     0,     0,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   241,     0,     0,     0,   242,
     243,   244,    68,     5,  -184,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,     0,     0,   336,   337,
     338,   339,   340,     0,     0,     0,     0,   245,     0,   341,
     342,   343,     0,     0,     0,     0,     0,   246,   247,   231,
       0,   248,     0,     0,   249,     0,     0,     0,     0,     0,
     250,   251,     0,     0,     0,     0,     0,   232,   233,   234,
       0,   235,   252,   236,   237,   253,   474,   238,   239,    12,
       0,     0,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,     0,     0,     0,   242,   243,
     244,    68,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,   245,     0,     0,     0,
       0,     0,     0,     0,    59,     0,   246,   247,     0,    60,
     248,    61,     0,   249,     0,    62,    63,    64,    65,   250,
     251,    98,     0,     0,     0,     0,     0,     0,     0,     0,
      68,   252,     0,     0,   253,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,     0,     0,
      69,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,    60,     0,    61,     0,     0,     0,    62,    63,    64,
      65,     0,     0,    98,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     5,   232,   233,   234,     0,   235,     0,
     236,   237,     0,     0,     0,     0,     0,     0,     0,   284,
       0,     0,    69,     0,   232,   233,   234,     0,   235,     0,
     236,   237,     0,     0,     0,   242,   243,   244,    68,   284,
       0,    70,     0,     0,    71,    72,     0,     0,     0,     0,
       0,     0,    73,     0,     0,   242,   243,   244,   369,     0,
       0,   304,     0,   245,    39,     0,     0,     0,     0,     0,
       0,     0,   305,   246,   247,     0,     0,   248,     0,     0,
     249,     0,     0,   245,     0,     0,   250,   251,     0,     0,
       0,     0,     0,   246,   247,     0,     0,   248,   252,     0,
     249,   253,   306,     0,     0,     0,   250,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,   253,   370,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,     0,     0,     0,    60,
       0,    61,     0,     0,     0,    62,    63,    64,    65,     0,
      66,    67,     0,     0,     0,     0,     0,     0,     0,     0,
      68,     0,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,     0,     0,
      69,     0,     0,    59,     0,     0,     0,     0,    60,     0,
      61,     0,     0,     0,    62,    63,    64,    65,     0,    70,
      98,     0,    71,    72,     0,     0,     0,     0,     0,    68,
      73,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,     0,     0,     0,    70,     0,
       0,    71,    72,    59,     0,     0,     0,     0,    60,    73,
      61,     0,     0,     0,    62,    63,    64,    65,     0,     0,
      98,   232,   233,   234,     0,   235,     0,   236,   237,    68,
       0,     0,     0,     0,     0,     0,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,   242,   243,   244,    68,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,    71,    72,     0,     0,     0,     0,     0,     0,    73,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     246,   247,     0,     0,   248,     0,     0,   249,     0,     0,
       0,     0,     0,   250,   251,   232,   233,   234,     0,   235,
       0,   236,   237,     0,   309,   252,     0,    39,   253,     0,
     284,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   320,   242,   243,   244,    68,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,     0,     0,   336,   337,   338,
     339,   340,     0,     0,   245,     0,     0,     0,   341,   342,
     343,     0,     0,     0,   246,   247,     0,     0,   248,     0,
       0,   249,     0,     0,     0,     0,     0,   250,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   320,   252,
       0,     0,   253,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,     0,     0,
     336,   337,   338,   339,   340,     0,     0,     0,     0,     0,
       0,   341,   342,   343,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,     0,     0,   421,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,     0,     0,   336,   337,   338,   339,   340,     0,
       0,     0,     0,     0,     0,   341,   342,   343,     0,     0,
       0,     0,   320,     0,     0,     0,   358,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,     0,     0,   336,   337,   338,   339,   340,     0,
       0,     0,     0,     0,     0,   341,   342,   343,  -184,  -184,
    -184,  -184,  -184,  -184,   331,   332,   333,   334,   335,     0,
       0,   336,   337,   338,   339,   340,     0,     0,     0,     0,
       0,     0,   341,   342,   343
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-397)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-184)))

static const yytype_int16 yycheck[] =
{
       3,   229,   230,     6,     7,    22,   183,    21,    25,    23,
     260,    54,    46,    51,     7,    53,    21,    20,    23,    56,
      60,    14,    15,    16,    64,    65,    29,   126,   127,    90,
      70,    71,    72,    11,   253,   134,   135,   121,    34,    53,
     108,    54,    38,    39,   128,     3,    41,   108,    53,    49,
      28,   228,   136,     5,    54,    56,    67,   453,    54,    54,
       0,   122,   123,    74,    56,    56,    56,   463,    61,    62,
      63,    56,   115,    66,    67,    41,   116,   114,    53,   140,
     118,    74,   116,   215,    53,   410,    80,     7,    54,    41,
     415,   152,    95,   154,    54,   104,   315,   229,   230,   167,
      20,   169,   115,   117,   113,   145,   167,    21,   169,    23,
     104,   116,    21,   114,    23,   115,    94,   110,   111,    56,
     464,   117,   117,   114,   468,   117,   129,   117,   260,    34,
      53,   192,   117,    38,    39,   128,    34,   177,   178,    53,
     465,   104,    79,   136,   113,   185,   113,   187,   188,    54,
     113,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    23,   104,    25,   103,   104,   105,
     173,   174,    27,   263,   113,   352,   353,   276,   277,   104,
     173,   198,   432,   104,   274,   275,   179,   180,   113,   439,
     183,   184,   113,   196,   278,   116,   215,    53,    53,   289,
     203,    53,   173,   196,    47,    48,   305,    96,    80,   180,
     229,   230,   215,   184,   103,   104,   105,    23,    73,    25,
     470,   238,   215,    47,    48,   196,   229,   230,    15,    16,
      62,    63,   116,   461,   462,   228,   229,   230,   231,   113,
     257,   260,   113,   113,    74,   118,   239,   240,    92,    93,
      94,    95,    96,   430,   431,   354,   355,   260,   104,   103,
     104,   105,    53,   256,    41,   114,   117,    70,   116,   116,
     263,     0,     1,    53,   114,     4,   114,    56,   410,   114,
      56,   274,   275,   415,    56,   278,   114,   114,   117,    53,
     116,   284,    53,    53,   311,    53,   289,   114,   116,   316,
     432,   116,    31,   343,    33,    34,   113,   439,   113,    38,
      39,   113,    53,    41,    49,    53,     0,     1,   117,   117,
       4,   314,   117,    53,   113,    54,    53,   344,   345,   461,
     462,   113,    45,   465,   351,    87,   114,    56,   470,   114,
      31,    32,    74,   117,    35,    36,    37,    31,   116,    33,
      34,   114,    70,    70,    38,    39,   113,   397,   114,   352,
     353,   114,   402,   403,    53,   114,    46,   117,   114,    60,
      54,   116,   116,    64,    65,   117,   147,   117,    20,    70,
      71,    72,    73,    97,   437,   402,   111,   404,   192,   203,
      31,   410,   413,   419,   270,   196,   415,   236,   423,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,   425,   426,
      -1,    -1,   415,   432,    -1,    -1,    -1,   108,   411,    -1,
     439,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,   432,
     423,   122,   123,    -1,    -1,    -1,   439,   430,   431,    -1,
      -1,    -1,   461,   462,   437,    -1,   465,    -1,    -1,   140,
      -1,   470,    -1,    -1,   145,    -1,    -1,    -1,   461,   462,
      -1,   152,   465,   154,    -1,    -1,    -1,   470,   461,   462,
      -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   169,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,    -1,
      -1,    -1,   183,    -1,   185,   238,   187,   188,    -1,   242,
      -1,   192,   245,   246,   247,   248,   249,   250,   251,   252,
     253,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    -1,    -1,    -1,    -1,   228,   103,   104,
     105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   314,   315,    -1,    -1,    -1,    -1,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     1,    -1,    -1,    -1,    -1,   362,
      -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    21,    -1,    23,    -1,    25,    26,
      -1,    -1,    29,    30,    31,    -1,    -1,    34,    53,    -1,
      -1,   342,   343,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,   352,   353,    50,    51,    52,    53,    54,    73,    -1,
     413,    -1,    -1,    -1,   417,    -1,    -1,    -1,    -1,    -1,
     423,    -1,    -1,    -1,    -1,   428,   429,    92,    -1,    -1,
      95,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,     1,    -1,    92,   397,    -1,    95,    -1,
     453,   402,   403,    -1,   101,   102,    -1,    -1,    -1,    -1,
     463,    19,    20,    21,    -1,    23,   113,    25,    26,   116,
     117,    29,    30,    31,    -1,    -1,    34,    -1,    -1,   430,
     431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,     1,    -1,    92,    41,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,    53,    -1,    -1,
      19,    20,    21,    -1,    23,   113,    25,    26,   116,   117,
      29,    30,    31,    -1,    -1,    34,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,     1,    -1,    92,    41,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,    53,    -1,    -1,    19,
      20,    21,    -1,    23,   113,    25,    26,   116,   117,    29,
      30,    31,    -1,    -1,    34,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    95,    96,    -1,    -1,    -1,    -1,    78,    -1,
     103,   104,   105,    -1,    -1,    -1,    -1,    -1,    88,    89,
       1,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    -1,    23,   113,    25,    26,   116,   117,    29,    30,
      31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    95,    96,    -1,    -1,    -1,    -1,    78,    -1,   103,
     104,   105,    -1,    -1,    -1,    -1,    -1,    88,    89,     1,
      -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      -1,    23,   113,    25,    26,   116,   117,    29,    30,    31,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    88,    89,    -1,    32,
      92,    34,    -1,    95,    -1,    38,    39,    40,    41,   101,
     102,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,   113,    -1,    -1,   116,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    -1,    34,    -1,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    19,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    -1,    73,    -1,    19,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    50,    51,    52,    53,    34,
      -1,    92,    -1,    -1,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    50,    51,    52,    53,    -1,
      -1,    76,    -1,    78,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    78,    -1,    -1,   101,   102,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    -1,    92,   113,    -1,
      95,   116,   117,    -1,    -1,    -1,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,   117,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      -1,    34,    -1,    -1,    -1,    38,    39,    40,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    -1,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    92,
      44,    -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    53,
     103,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    27,    -1,    -1,    -1,    -1,    32,   103,
      34,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      44,    19,    20,    21,    -1,    23,    -1,    25,    26,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    50,    51,    52,    53,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      -1,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    -1,    92,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,   102,    19,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    49,   113,    -1,   115,   116,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    50,    51,    52,    53,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      95,    96,    -1,    -1,    78,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,    -1,    88,    89,    -1,    -1,    92,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,   113,
      -1,    -1,   116,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,   118,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,   114,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,   103,   104,   105,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,   105
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   120,    53,     0,    54,   115,   122,   124,   124,
       1,     4,    31,    33,    34,    38,    39,   121,   123,   124,
     126,   130,   132,   135,   136,   168,    21,    23,    53,   116,
     131,    53,    34,   113,   121,   173,   173,   173,   136,   115,
     124,   125,   125,   125,   131,   124,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    27,
      32,    34,    38,    39,    40,    41,    43,    44,    53,    73,
      92,    95,    96,   103,   151,   153,   162,   166,   167,   179,
     181,   182,   183,   184,   185,   186,   188,   189,   190,   151,
      53,   151,   151,   151,    53,   131,   133,   134,    44,   152,
     166,   180,   121,   178,   178,   178,   180,   180,    80,   121,
     156,   156,   180,   180,   180,    51,   118,   151,   187,   104,
     156,   113,    92,    95,   172,   189,   113,   113,   113,   131,
     124,   117,   133,   116,   113,   113,   113,   157,   158,   189,
      74,   121,   159,   159,   180,   118,    53,    41,   121,   174,
     175,   176,    41,   189,    41,   189,   114,   174,   175,   174,
     121,   175,   124,   117,   174,   174,   175,    56,    79,    70,
     157,   160,   161,   116,   116,   180,    53,   127,   127,   114,
      56,   189,   189,   114,    56,   114,   114,   114,   114,   114,
     157,   157,    56,   121,   124,   163,   164,   165,   176,    34,
      38,    39,   124,   154,   155,    56,   180,   180,   121,   128,
     180,     5,   176,   128,   180,   116,   180,   180,   160,   163,
     117,   125,    53,    53,    53,   117,   155,    53,   114,   116,
     116,     1,    19,    20,    21,    23,    25,    26,    29,    30,
      34,    46,    50,    51,    52,    78,    88,    89,    92,    95,
     101,   102,   113,   116,   121,   124,   129,   130,   138,   139,
     140,   143,   151,   169,   170,   177,   191,   193,   194,   197,
     198,   199,   200,   201,   202,   204,   113,   113,   113,   128,
     177,   177,   121,   137,    34,   201,   202,   204,   125,   200,
      41,   121,    53,   121,   144,   200,   200,   200,   200,   200,
     200,   200,   200,   200,    76,    87,   117,   192,   200,    49,
     121,   150,   125,   139,   113,   116,   150,   117,    23,   197,
      70,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    92,    93,    94,    95,
      96,   103,   104,   105,   150,   150,   174,   174,   175,   117,
     117,   150,    53,    53,   113,   113,   141,   200,   114,   171,
     200,   174,    56,   117,    53,   125,   121,   192,   203,    53,
     117,   192,   195,   196,   125,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   200,   200,   200,   200,   113,   151,   180,
     125,   125,   114,   114,   114,   125,   128,   128,   174,   174,
      45,   142,   117,    87,   200,   116,   114,    74,   117,    56,
     117,   118,   180,   113,   125,   180,   180,   125,    70,    70,
     114,   114,   140,    47,    48,   121,   145,   148,   171,   140,
     200,    53,   196,   114,   203,   125,   125,   200,   200,   128,
     128,   117,    46,   146,    47,   121,   145,   149,   117,   117,
     114,   116,   116,   147,   141,   116,   177,   177,   141,   142,
     140,   117,   117,   142,   117
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

  case 107:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), &(yyvsp[(9) - (9)]), NULL, true, YO_CALLING_C, parm, &yyloc); }
    break;

  case 108:

    { yoParserDeclFunc(&(yyval), T_EXTERN_FUNC, NULL, &(yyvsp[(3) - (7)]), &(yyvsp[(5) - (7)]), &(yyvsp[(7) - (7)]), NULL, false, YO_CALLING_C, parm, &yyloc); }
    break;

  case 109:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 110:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 111:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 112:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), false, &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 113:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 114:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 115:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 116:

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

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_EQ, parm, &yyloc); }
    break;

  case 194:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_NE, parm, &yyloc); }
    break;

  case 195:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LE, parm, &yyloc); }
    break;

  case 196:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GE, parm, &yyloc); }
    break;

  case 197:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_LT, parm, &yyloc); }
    break;

  case 198:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_GT, parm, &yyloc); }
    break;

  case 199:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 200:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 201:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 202:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 203:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 204:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_POW, parm, &yyloc); }
    break;

  case 205:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 206:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 207:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 208:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 209:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 210:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 211:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XORXOR, parm, &yyloc); }
    break;

  case 212:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 213:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 214:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 216:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 219:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 220:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 221:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 222:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 223:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 224:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 225:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 226:

    { yoParserSizeOf(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 227:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 228:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 229:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
    break;

  case 232:

    { yoParserCall(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 233:

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




