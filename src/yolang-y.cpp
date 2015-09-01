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
     T_LNUMBER = 303,
     T_DNUMBER = 304,
     T_NAME = 305,
     T_NEWLINE = 306,
     T_FIX = 307,
     T_POW_ASSIGN = 308,
     T_RSH_ASSIGN = 309,
     T_LSH_ASSIGN = 310,
     T_XOR_ASSIGN = 311,
     T_OR_ASSIGN = 312,
     T_AND_ASSIGN = 313,
     T_MOD_ASSIGN = 314,
     T_CONCAT_ASSIGN = 315,
     T_DIV_ASSIGN = 316,
     T_MUL_ASSIGN = 317,
     T_MINUS_ASSIGN = 318,
     T_PLUS_ASSIGN = 319,
     T_DECL_ASSIGN = 320,
     T_ASSIGN = 321,
     T_INIT_ASSIGN = 322,
     T_PROP_ASSIGN = 323,
     T_XORXOR = 324,
     T_OROR = 325,
     T_ANDAND = 326,
     T_CHAN_ACCESS = 327,
     T_GT = 328,
     T_LT = 329,
     T_GE = 330,
     T_LE = 331,
     T_NE = 332,
     T_EQ = 333,
     T_CONCAT = 334,
     T_XOR = 335,
     T_OR = 336,
     T_MINUS = 337,
     T_PLUS = 338,
     T_RSH = 339,
     T_LSH = 340,
     T_AND = 341,
     T_MOD = 342,
     T_DIV = 343,
     T_MUL = 344,
     T_POW = 345,
     T_AT = 346,
     T_UNARY = 347,
     T_DEC = 348,
     T_INC = 349,
     T_TILDE = 350,
     T_NOT = 351,
     T_DOT = 352,
     T_AS = 353,
     T_INDIRECT = 354,
     T_ADDR = 355,
     T_INDEX = 356,
     T_PTR = 357,
     T_ARR = 358,
     T_DOTNAME = 359,
     NotParen = 360
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
#define YYNTOKENS  116
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNRULES -- Number of states.  */
#define YYNSTATES  439

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   360

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     110,   111,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    71,   112,
       2,     2,     2,    70,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   100,     2,   115,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   113,     2,   114,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   101,   102,   103,   104,   105,   106,   107,   108,
     109
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,     9,    11,    14,    16,    18,    20,
      22,    24,    26,    29,    31,    35,    37,    39,    43,    49,
      53,    55,    57,    60,    64,    70,    73,    77,    79,    82,
      85,    88,    91,    93,    95,    97,    99,   103,   107,   110,
     115,   118,   120,   124,   128,   131,   133,   135,   137,   140,
     142,   146,   147,   154,   155,   160,   161,   167,   169,   172,
     174,   179,   181,   187,   189,   191,   195,   199,   206,   208,
     211,   218,   226,   234,   241,   243,   247,   249,   251,   255,
     257,   261,   264,   266,   268,   270,   274,   281,   284,   286,
     288,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     309,   311,   313,   315,   317,   319,   320,   331,   342,   352,
     362,   372,   379,   384,   386,   388,   390,   393,   397,   400,
     404,   409,   411,   413,   415,   417,   421,   424,   426,   428,
     430,   436,   443,   450,   456,   458,   460,   463,   466,   469,
     472,   475,   478,   482,   484,   486,   491,   493,   496,   498,
     500,   502,   504,   506,   508,   510,   512,   514,   516,   518,
     520,   522,   524,   526,   528,   530,   532,   534,   536,   538,
     540,   542,   546,   549,   553,   557,   562,   567,   569,   573,
     577,   580,   582,   585,   588,   590,   592,   594,   596,   598,
     600,   604,   608,   612,   616,   620,   624,   628,   632,   636,
     640,   644,   648,   652,   656,   658,   660,   664,   670,   673,
     676,   679,   682,   685,   687,   691,   696,   699,   702,   706,
     708,   710,   715
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     117,     0,    -1,     3,    50,   119,   120,    -1,    -1,   121,
      -1,   112,   121,    -1,   123,    -1,   118,    -1,    51,    -1,
     121,    -1,   112,    -1,   133,    -1,   123,   133,    -1,    50,
      -1,   124,    53,    50,    -1,   177,    -1,   118,    -1,    30,
      50,   125,    -1,    30,    50,   125,    67,   197,    -1,    31,
      50,   164,    -1,    23,    -1,    21,    -1,     4,   128,    -1,
       4,    50,   128,    -1,     4,   113,   121,   131,   114,    -1,
     128,   121,    -1,    50,   128,   121,    -1,   130,    -1,   131,
     130,    -1,   129,   122,    -1,   127,   122,    -1,   165,   122,
      -1,     1,    -1,   132,    -1,   121,    -1,   118,    -1,   126,
     147,   122,    -1,   166,   147,   122,    -1,   127,   122,    -1,
      29,   197,   147,   122,    -1,    29,   122,    -1,   140,    -1,
     200,   147,   122,    -1,   202,   147,   122,    -1,     1,   134,
      -1,   135,    -1,   121,    -1,   136,    -1,   137,   136,    -1,
     197,    -1,    43,   137,   114,    -1,    -1,    44,   141,   138,
     139,   145,   146,    -1,    -1,    46,   143,   138,   139,    -1,
      -1,    45,    44,   144,   138,   139,    -1,   142,    -1,   145,
     142,    -1,   118,    -1,    45,   113,   137,   114,    -1,   118,
      -1,    47,    50,   113,   137,   114,    -1,   118,    -1,    50,
      -1,   148,   101,    50,    -1,    42,   113,   114,    -1,    42,
     153,   156,   113,   151,   114,    -1,   152,    -1,   151,   152,
      -1,    33,    50,   110,   171,   111,   122,    -1,    33,    50,
     110,   171,   111,   177,   122,    -1,    36,    50,   110,   171,
     111,   177,   122,    -1,    37,    50,   110,   172,   111,   122,
      -1,   121,    -1,    77,   155,    76,    -1,   118,    -1,   186,
      -1,   186,    67,   154,    -1,   154,    -1,   155,    53,   154,
      -1,    71,   158,    -1,   118,    -1,   154,    -1,   157,    -1,
     158,    53,   157,    -1,    41,   153,   156,   113,   162,   114,
      -1,   172,   122,    -1,   121,    -1,   160,    -1,   161,   160,
      -1,   161,    -1,   118,    -1,   186,    -1,   178,    -1,   179,
      -1,   180,    -1,   182,    -1,   181,    -1,   183,    -1,   185,
      -1,   176,    -1,   163,    -1,   150,    -1,   159,    -1,    -1,
      33,   170,   148,   110,   171,   111,   125,   113,   174,   114,
      -1,    36,   170,   148,   110,   171,   111,   177,   113,   174,
     114,    -1,    37,   170,   148,   110,   172,   111,   113,   174,
     114,    -1,    33,    50,   110,   171,   111,   125,   113,   174,
     114,    -1,    33,   118,   110,   171,   111,   125,   113,   174,
     114,    -1,   113,    84,   124,    84,   168,   114,    -1,   113,
      73,   168,   114,    -1,   197,    -1,   174,    -1,   186,    -1,
      92,   186,    -1,    92,    39,   186,    -1,    89,   186,    -1,
      89,    39,   186,    -1,   110,    50,   169,   111,    -1,   118,
      -1,   172,    -1,   118,    -1,   173,    -1,   172,    53,   173,
      -1,   124,   177,    -1,   137,    -1,   118,    -1,   118,    -1,
      33,   175,   110,   171,   111,    -1,    33,   175,   110,   171,
     111,   177,    -1,    36,   175,   110,   171,   111,   177,    -1,
      37,   175,   110,   172,   111,    -1,   163,    -1,   149,    -1,
      38,   177,    -1,    39,   177,    -1,    32,   177,    -1,    89,
     177,    -1,    92,   177,    -1,    93,   177,    -1,   100,   115,
     177,    -1,    48,    -1,   148,    -1,   100,   184,   115,   177,
      -1,   187,    -1,   148,   153,    -1,     6,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    17,    -1,    15,    -1,    16,    -1,
      18,    -1,    27,    -1,    70,    -1,    19,    -1,    20,    -1,
      26,    -1,    48,    -1,    49,    -1,    21,    -1,    23,    -1,
     197,    -1,   189,    53,   197,    -1,   113,   114,    -1,   113,
     189,   114,    -1,   148,   113,   114,    -1,   148,   113,   189,
     114,    -1,   148,   113,   192,   114,    -1,   193,    -1,   192,
      53,   193,    -1,   148,    67,   197,    -1,    25,   198,    -1,
     194,    -1,   195,   194,    -1,   195,    23,    -1,   198,    -1,
     196,    -1,   188,    -1,   199,    -1,   190,    -1,   191,    -1,
     197,    86,   197,    -1,   197,    85,   197,    -1,   197,    92,
     197,    -1,   197,    91,   197,    -1,   197,    90,   197,    -1,
     197,    82,   197,    -1,   197,    84,   197,    -1,   197,    73,
     197,    -1,   197,    89,   197,    -1,   197,    74,   197,    -1,
     197,    83,   197,    -1,   197,    72,   197,    -1,   197,    75,
     197,    -1,   110,   197,   111,    -1,   202,    -1,   167,    -1,
     197,   102,   177,    -1,   197,   101,   110,   177,   111,    -1,
      86,   197,    -1,    85,   197,    -1,    99,   197,    -1,    98,
     197,    -1,    75,   197,    -1,   148,    -1,   197,   101,   148,
      -1,   197,   100,   197,   115,    -1,    92,   197,    -1,    89,
     197,    -1,   199,    67,   197,    -1,   189,    -1,   118,    -1,
     148,   110,   201,   111,    -1,   197,   101,   148,   110,   201,
     111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   226,   226,   229,   238,   239,   242,   243,   246,   249,
     250,   253,   254,   257,   258,   261,   262,   265,   266,   273,
     276,   277,   280,   281,   282,   285,   286,   289,   290,   293,
     294,   295,   296,   299,   300,   303,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   322,   323,   326,   327,   338,
     341,   344,   344,   349,   349,   350,   350,   353,   354,   355,
     358,   359,   362,   363,   366,   367,   370,   373,   376,   377,
     380,   381,   382,   383,   384,   387,   388,   391,   392,   395,
     396,   399,   400,   403,   406,   407,   410,   413,   414,   417,
     418,   421,   422,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   436,   437,   438,   440,   441,   443,   445,   449,
     457,   459,   461,   465,   466,   469,   470,   471,   472,   473,
     476,   477,   480,   481,   484,   485,   488,   491,   492,   501,
     504,   505,   506,   507,   510,   511,   514,   517,   520,   523,
     526,   527,   534,   538,   539,   542,   546,   548,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   568,   569,   570,   571,   572,   573,   574,
     577,   578,   581,   582,   585,   586,   587,   590,   591,   594,
     597,   600,   601,   604,   607,   608,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   642,   643,   644,   645,   646,   649,   652,
     653,   656,   657
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
  "T_BRACE", "T_IF", "T_ELSE", "T_ELSEIF", "T_CATCH", "T_LNUMBER",
  "T_DNUMBER", "T_NAME", "T_NEWLINE", "T_FIX", "','",
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
     305,   306,   307,    44,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
      63,    58,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
      91,   352,   353,   354,   355,   356,   357,   358,   359,   360,
      40,    41,    59,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   116,   117,   118,   119,   119,   120,   120,   121,   122,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     128,   128,   129,   129,   129,   130,   130,   131,   131,   132,
     132,   132,   132,   133,   133,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   136,   136,   137,   137,   138,
     139,   141,   140,   143,   142,   144,   142,   145,   145,   145,
     146,   146,   147,   147,   148,   148,   149,   150,   151,   151,
     152,   152,   152,   152,   152,   153,   153,   154,   154,   155,
     155,   156,   156,   157,   158,   158,   159,   160,   160,   161,
     161,   162,   162,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   164,   164,   164,   165,   165,   165,   165,   166,
     167,   167,   167,   168,   168,   169,   169,   169,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   174,   174,   175,
     176,   176,   176,   176,   177,   177,   178,   179,   180,   181,
     182,   182,   183,   184,   184,   185,   186,   186,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   187,   188,   188,   188,   188,   188,   188,   188,
     189,   189,   190,   190,   191,   191,   191,   192,   192,   193,
     194,   195,   195,   196,   197,   197,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   199,   199,   199,   200,   201,
     201,   202,   202
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     0,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     3,     5,     3,
       1,     1,     2,     3,     5,     2,     3,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     3,     3,     2,     4,
       2,     1,     3,     3,     2,     1,     1,     1,     2,     1,
       3,     0,     6,     0,     4,     0,     5,     1,     2,     1,
       4,     1,     5,     1,     1,     3,     3,     6,     1,     2,
       6,     7,     7,     6,     1,     3,     1,     1,     3,     1,
       3,     2,     1,     1,     1,     3,     6,     2,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,    10,    10,     9,     9,
       9,     6,     4,     1,     1,     1,     2,     3,     2,     3,
       4,     1,     1,     1,     1,     3,     2,     1,     1,     1,
       5,     6,     6,     5,     1,     1,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     4,     4,     1,     3,     3,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     5,     2,     2,
       2,     2,     2,     1,     3,     4,     2,     2,     3,     1,
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
       0,     0,   121,     0,     0,     0,    12,    10,     9,    30,
      29,    31,    23,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   158,   159,   157,   160,   161,     0,     3,
       3,     3,     0,     0,     3,     3,    64,   162,     0,     0,
       0,     0,     3,   103,   104,   102,    19,   101,    94,    95,
      96,    98,    97,    99,   100,    93,   146,     0,     0,     0,
       0,     0,     0,    27,     0,     0,   135,   134,   138,   129,
       0,     0,     0,   136,   137,     0,    76,     3,     3,   139,
     140,   141,   143,     0,   144,     0,     0,   147,     0,     0,
       0,   115,     3,     3,     0,     0,    25,    24,    28,     0,
       3,     3,     0,    79,     0,    77,     0,    82,     0,     0,
     142,     0,    65,     0,   118,     0,   116,   120,    13,   123,
       0,     0,   122,   124,     0,     0,    26,    66,     0,     0,
       0,     0,    75,     0,    83,    84,    81,     3,     0,   145,
     119,   117,     0,   126,     3,     0,     0,     0,   130,     0,
     133,    80,    78,     0,    92,    88,    89,    91,     0,     0,
       0,     0,     0,    74,     0,    68,    14,    16,     0,    15,
     125,     0,     0,   131,   132,    85,    90,    86,    87,     0,
       0,     0,    67,    69,     0,     0,     3,   163,   164,   168,
     169,     0,   165,     0,     0,     3,    51,   166,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,    46,
       3,     0,    45,    47,     0,    41,   213,     3,   205,     0,
     186,   188,   189,   181,     0,   185,     0,   184,   187,     3,
     204,     3,     3,     0,     0,     0,    35,    44,     3,   184,
     187,   204,    40,     3,     3,     0,     0,     0,   212,   209,
     208,   217,   216,   211,   210,     0,     0,     0,   172,     0,
     170,     0,    63,     0,    38,    48,     3,     0,     0,   108,
     183,   182,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,   107,     0,    17,     3,     3,
       0,    49,   203,     0,   114,   113,     0,     0,   173,     0,
      36,   220,   219,     0,   174,   213,     0,     0,   177,    37,
     201,   197,   199,   202,   195,   200,   196,   191,   190,   198,
     194,   193,   192,     0,     0,   214,   206,   218,    42,    43,
       0,     0,     0,    39,     0,     0,     0,     0,     3,   112,
       0,   171,     0,   221,     0,   175,     0,   176,   215,     0,
       3,    70,     0,     0,    73,    18,     3,     3,     0,     0,
      53,    59,    57,     3,     0,     0,   179,     0,   178,   207,
       0,    71,    72,     0,     0,    50,    55,     0,     0,    61,
      58,    52,   111,    62,   222,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,   109,   110,    56,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   149,     7,    17,    38,    39,    19,   150,   198,
     240,   241,    92,    21,    93,    94,    22,    23,   267,   242,
     243,   244,   330,   378,   245,   277,   402,   417,   427,   403,
     421,   293,   246,    96,    73,   194,   195,   107,   164,   134,
     138,   165,   166,    74,   186,   187,   188,    97,    76,    24,
     247,   248,   333,   120,    33,   151,   152,   153,   334,   100,
      77,   199,    78,    79,    80,    81,    82,    83,   115,    84,
      85,    86,   250,   342,   251,   252,   347,   348,   253,   254,
     255,   256,   257,   270,   259,   343,   271
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -312
static const yytype_int16 yypact[] =
{
      28,   -17,    74,   -50,  -312,  -312,    66,    47,  -312,  -312,
    -312,     7,    84,    46,    46,    46,  -312,  -312,  -312,    55,
     -27,   -27,  -312,  -312,   -27,  -312,  -312,    87,    66,  -312,
    1141,   112,  -312,   120,   120,   120,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,   108,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  1255,  -312,
    -312,  -312,  1255,  1255,   115,   115,  -312,  -312,  1255,  1255,
    1255,    10,    20,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
    -312,  -312,  -312,  -312,  -312,  -312,  -312,   601,   -29,    41,
      75,    87,    66,  -312,   -15,    62,  -312,  -312,  -312,  -312,
      90,   107,   117,  -312,  -312,  1536,  -312,   168,   168,  -312,
    -312,  -312,  -312,  1255,   158,   145,   211,  -312,   459,  1491,
     151,  -312,   215,   215,   215,    66,  -312,  -312,  -312,   155,
     215,   215,   215,  -312,    63,   200,  1536,  -312,   157,   160,
    -312,  1255,  -312,  1536,  -312,  1536,  -312,  -312,  -312,  -312,
    1186,   169,   218,  -312,   173,    -8,  -312,  -312,   174,   175,
       8,  1536,  -312,  1536,  -312,  -312,   221,    98,   153,  -312,
    -312,  -312,   225,  -312,  1255,   215,  1255,   166,  1446,  1255,
    -312,  -312,  -312,  1536,  -312,  -312,  -312,    98,   179,   -12,
     237,   239,   244,  -312,    16,  -312,  -312,  -312,   182,  -312,
    -312,   183,   547,  -312,  -312,  -312,  -312,  -312,  -312,   178,
     188,   191,  -312,  -312,   547,   547,  -312,  -312,  -312,  -312,
    -312,  1338,  -312,  1281,   252,   253,  -312,  -312,  -312,  1338,
    1338,  1338,  1338,  1338,  1338,  1338,  1338,  1012,  -312,  -312,
     258,   -27,  -312,  -312,   633,  -312,    67,   258,  -312,   195,
    -312,  -312,  -312,  -312,   180,  -312,  1548,  -312,   247,   258,
      26,   215,   215,   215,   201,   202,  -312,  -312,  -312,   205,
    -312,  -312,  -312,  1493,  1255,   207,   212,  1338,   113,   113,
     113,   113,   113,   113,   113,  1525,   547,   215,  -312,   -19,
    1548,   261,  -312,   -27,  -312,  -312,  1338,  1032,   -27,  -312,
    -312,  -312,  1338,  1338,  1338,  1338,  1338,  1338,  1338,  1338,
    1338,  1338,  1338,  1338,  1338,  1338,   -28,  1255,  1338,   -27,
     -27,   209,   216,    22,  -312,  -312,   -27,   254,   215,   215,
     280,  1548,  -312,   217,  -312,  1548,    51,  1338,  -312,   219,
    -312,  -312,   276,   222,  -312,    59,   -13,    -7,  -312,  -312,
    1315,  1315,  1251,  1569,   156,   156,   156,   156,   156,   113,
     113,   113,   113,   851,  1255,   220,  -312,  1548,  -312,  -312,
     979,  1255,   -27,  -312,  1338,   223,   229,   871,   164,  -312,
     547,  1548,   871,  -312,  1338,  -312,   120,  -312,  -312,   232,
    1338,  -312,   -27,   -27,  -312,  1548,  1255,  1255,   666,   292,
    -312,  -312,  -312,   197,   233,   752,  1548,    12,  -312,  -312,
     240,  -312,  -312,   235,   236,  -312,  -312,  1338,   -23,  -312,
    -312,  -312,  -312,  -312,  -312,   547,   547,  1338,   280,   871,
     249,   251,   280,  -312,   785,  -312,  -312,  -312,  -312
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -312,  -312,     4,  -312,  -312,    -3,    -1,  -312,    65,  -269,
    -312,   136,     2,  -312,   256,  -312,  -312,   334,  -312,  -312,
    -232,  -311,  -270,  -245,  -312,  -312,   -49,  -312,  -312,  -312,
    -312,   -24,   163,  -312,  -312,  -312,   167,    37,   -67,  -312,
     250,   184,  -312,  -312,   181,  -312,  -312,   336,  -312,  -312,
    -312,  -312,   -10,  -312,   238,  -121,  -117,   198,  -188,   194,
    -312,   -26,  -312,  -312,  -312,  -312,  -312,  -312,  -312,  -312,
      18,  -312,  -312,  -183,  -312,  -312,  -312,   -14,   121,  -312,
    -312,   210,   159,   -70,  -312,    -9,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -181
static const yytype_int16 yytable[] =
{
       8,     5,   154,     9,    18,   327,    25,   155,    26,   158,
     159,    16,   295,    29,   249,   160,    18,    32,    32,    32,
      40,   416,    66,    41,     5,    43,   264,   265,    25,    42,
      26,     1,    98,     3,   337,    91,   103,   104,   133,     5,
     337,   175,   109,   110,   111,   175,   386,    -3,    10,   190,
     189,    11,   191,   192,   289,    -6,    10,    27,   112,    11,
      66,   175,     6,    99,    99,    99,   398,     5,   106,   106,
     189,   405,   116,   291,     4,   175,   106,    -3,    12,   384,
      13,   122,   364,    14,    15,    37,    12,   140,    13,   126,
     429,    14,    15,   125,   181,   338,   182,   105,     5,   127,
      37,   385,   108,   177,   172,   121,     5,   387,    25,   117,
      26,   137,   137,   116,   346,   169,   161,     5,   434,   180,
      28,   116,   156,   135,   173,   113,   384,   413,   414,    25,
     212,    26,   258,   372,    30,   380,   144,   146,    -3,   162,
     321,   322,   116,    20,   258,   258,   323,   428,   148,     5,
     201,   123,   203,   204,   135,    20,    31,   432,    91,  -105,
     116,   170,    87,   171,   185,   193,   295,  -105,   116,   296,
      66,   184,   297,   295,   258,   129,   116,   296,   197,   135,
     297,   135,   260,   433,   185,   124,   190,   437,   208,   191,
     192,   193,   105,    72,   260,   260,    88,    89,    90,   239,
     130,   135,   295,   300,     5,   221,   238,   375,   376,   399,
     400,   239,   239,   315,   316,   317,   258,   131,   238,   238,
     266,    72,   272,   298,   260,    72,    72,   132,  -180,   276,
    -180,    72,    72,    72,   114,   319,   320,   430,   431,   136,
     294,   239,   418,   400,   292,   311,   312,   313,   314,   326,
      72,   292,    34,    35,   101,   102,   315,   316,   317,   116,
     141,   142,   147,   292,   292,   148,   260,   163,    72,   157,
     167,   175,   276,   168,   183,   196,    72,   292,   197,   202,
     174,    72,    72,   239,   176,   178,   179,   209,   261,   210,
     238,   366,   340,   207,   211,   214,   215,   349,   262,    72,
     341,   263,   274,   275,    72,   291,    72,   258,    72,   299,
     258,   339,   258,    72,   318,   324,   325,   328,   368,   369,
     370,   374,   329,   377,    72,   373,    72,   371,   258,   337,
     390,   379,   382,   383,   396,   258,   416,    72,   389,    72,
     397,    72,    72,   409,   392,   393,    72,   422,   425,   426,
     128,   424,   336,    36,   420,   258,   258,   260,   139,   258,
     260,   213,   260,   435,   258,   436,    75,   205,   206,   391,
     404,   394,   408,   200,   239,   301,     0,   239,   260,   239,
     269,   410,   401,     0,   238,   260,     0,     0,     0,     0,
       0,   411,   412,     0,   341,   239,     0,     0,     0,     0,
     197,   197,   239,     0,     0,   260,   260,   419,     0,   260,
       0,     0,     0,     0,   260,     0,     0,     0,     0,     0,
       0,     0,   239,   239,     0,     0,   239,     0,     0,   238,
     238,   239,     0,   273,     0,     0,     0,    72,     0,   278,
     279,   280,   281,   282,   283,   284,   285,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     345,     0,     0,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,   365,
      72,     0,     0,     0,     0,     0,    57,   331,     0,     0,
       0,     0,     0,     0,     0,     0,   335,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   290,   290,     0,    66,
       0,     0,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,     0,    72,   367,    67,
       0,     0,     0,    72,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   381,   216,   407,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      72,     0,     0,     0,     0,     0,   217,   218,   219,     0,
     220,     0,   221,   222,     0,     0,   223,   224,    12,     0,
     225,     0,     0,     0,   395,     0,     0,     0,     0,     0,
     335,   226,     0,     0,   406,   227,   228,    66,     5,     0,
     290,     0,     0,     0,     0,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,   229,     0,     0,     0,     0,   331,    57,     0,
       0,     0,   230,   231,   216,     0,   232,   331,     0,   233,
       0,     0,     0,     0,     0,   234,   235,     0,     0,     0,
       0,    66,   217,   218,   219,     0,   220,   236,   221,   222,
     237,    -3,   223,   224,    12,     0,   225,   216,     0,     0,
       0,    67,     0,     0,     0,     0,     0,   226,     0,     0,
       0,   227,   228,    66,     5,   217,   218,   219,     0,   220,
     118,   221,   222,   119,     0,   223,   224,    12,     0,   225,
       0,     0,     0,     0,     0,     0,     0,     0,   229,     0,
     226,     0,     0,     0,   227,   228,    66,     5,   230,   231,
       0,     0,   232,     0,     0,   233,     0,     0,     0,     0,
       0,   234,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,   236,     0,     0,   237,  -127,     0,     0,
       0,   230,   231,   216,     0,   232,     0,     0,   233,     0,
       0,     0,     0,     0,   234,   235,     0,     0,     0,     0,
       0,   217,   218,   219,     0,   220,   236,   221,   222,   237,
     415,   223,   224,    12,     0,   225,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,     0,     0,     0,
     227,   228,    66,     5,   217,   218,   219,     0,   220,     0,
     221,   222,     0,     0,   223,   224,    12,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   229,     0,   226,
       0,     0,     0,   227,   228,    66,     5,   230,   231,     0,
       0,   232,     0,     0,   233,     0,     0,     0,     0,     0,
     234,   235,     0,     0,     0,     0,     0,     0,     0,     0,
     229,     0,   236,     0,     0,   237,   423,     0,     0,     0,
     230,   231,   216,     0,   232,     0,     0,   233,     0,     0,
       0,     0,     0,   234,   235,     0,     0,     0,     0,     0,
     217,   218,   219,     0,   220,   236,   221,   222,   237,   438,
     223,   224,    12,     0,   225,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   226,     0,     0,     0,   227,
     228,    66,     5,   302,   303,   304,   305,     0,     0,     0,
       0,     0,     0,   306,   307,   308,   309,   310,     0,     0,
     311,   312,   313,   314,     0,     0,   229,     0,     0,     0,
       0,   315,   316,   317,     0,     0,   230,   231,     0,     0,
     232,     0,     0,   233,     0,     0,   388,     0,     0,   234,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,     0,   237,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,    57,     0,     0,     0,
       0,    58,    59,     0,     0,    60,    61,    62,    63,     0,
       0,    95,     0,     0,     0,     0,     0,     0,     0,    66,
       5,   217,   218,   219,     0,   220,     0,   221,   222,     0,
       0,     0,     0,     0,     0,   268,     0,     0,     0,    67,
       0,   217,   218,   219,     0,   220,     0,   221,   222,     0,
     227,   228,    66,     0,     0,   268,     0,     0,    68,     0,
       0,    69,    70,     0,     0,     0,     0,     0,     0,    71,
     227,   228,    66,     0,     0,   286,     0,   229,     0,     0,
       0,    37,     0,     0,     0,     0,   287,   230,   231,     0,
       0,   232,     0,     0,   233,     0,     0,   229,     0,     0,
     234,   235,     0,     0,     0,     0,     0,   230,   231,     0,
       0,   232,   236,     0,   233,   237,   288,     0,     0,     0,
     234,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,   237,   344,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,    58,    59,     0,     0,    60,    61,    62,
      63,     0,    64,    65,     0,     0,     0,     0,     0,     0,
       0,    66,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,    67,     0,    57,     0,     0,     0,     0,    58,    59,
       0,     0,    60,    61,    62,    63,     0,     0,    95,     0,
      68,     0,     0,    69,    70,     0,    66,     0,     0,   172,
       0,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     0,    68,     0,     0,    69,    70,
       0,     0,    57,     0,     0,     0,    71,    58,    59,     0,
       0,    60,    61,    62,    63,     0,     0,    95,     0,     0,
     217,   218,   219,     0,   220,    66,   221,   222,     0,     0,
       0,     0,     0,     0,   268,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,   305,     0,     0,   227,
     228,    66,     5,   306,   307,   308,   309,   310,     0,     0,
     311,   312,   313,   314,    68,     0,     0,    69,    70,     0,
       0,   315,   316,   317,     0,    71,   229,   217,   218,   219,
       0,   220,     0,   221,   222,     0,   230,   231,     0,     0,
     232,   268,     0,   233,     0,     0,     0,     0,     0,   234,
     235,     0,     0,     0,     0,     0,   227,   228,    66,   304,
     305,   236,     0,    37,   237,     0,     0,   306,   307,   308,
     309,   310,     0,     0,   311,   312,   313,   314,     0,     0,
       0,     0,     0,   229,     0,   315,   316,   317,     0,     0,
       0,     0,     0,   230,   231,     0,     0,   232,     0,     0,
     233,     0,     0,     0,     0,     0,   234,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,   237,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,    58,    59,
       0,     0,    60,    61,    62,    63,     0,     0,    95,     0,
       0,     0,     0,     0,     0,     0,    66,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,    67,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     291,    66,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     0,     0,     0,     0,     0,
       0,    67,     0,    57,     0,   302,   303,   304,   305,     0,
       0,     0,     0,     0,     0,   306,   307,   308,   309,   310,
       0,     0,   311,   312,   313,   314,    66,     0,     0,     0,
       0,     0,     0,   315,   316,   317,     0,   302,   303,   304,
     305,     0,     0,     0,     0,     0,    67,   306,   307,   308,
     309,   310,     0,     0,   311,   312,   313,   314,     0,     0,
     302,   303,   304,   305,     0,   315,   316,   317,     0,     0,
     306,   307,   308,   309,   310,     0,   332,   311,   312,   313,
     314,     0,     0,     0,  -181,     0,     0,     0,   315,   316,
     317,   306,   307,   308,   309,   310,     0,     0,   311,   312,
     313,   314,     0,     0,     0,     0,     0,     0,     0,   315,
     316,   317
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-312)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-181)))

static const yytype_int16 yycheck[] =
{
       3,    51,   123,     6,     7,   274,    21,   124,    23,   130,
     131,     7,   244,    11,   202,   132,    19,    13,    14,    15,
      21,    44,    50,    24,    51,    28,   214,   215,    21,    27,
      23,     3,    58,    50,    53,    50,    62,    63,   105,    51,
      53,    53,    68,    69,    70,    53,    53,     0,     1,    33,
     167,     4,    36,    37,   237,     0,     1,    50,    48,     4,
      50,    53,   112,    59,    60,    61,   377,    51,    64,    65,
     187,   382,   101,    47,     0,    53,    72,    51,    31,    67,
      33,   110,   110,    36,    37,   112,    31,   113,    33,    92,
     113,    36,    37,    91,   161,   114,   163,    77,    51,   114,
     112,   114,    65,   111,    53,    87,    51,   114,    21,    72,
      23,   107,   108,   101,   297,   141,    53,    51,   429,   111,
     113,   101,   125,   105,   150,   115,    67,   396,   397,    21,
     114,    23,   202,   111,    50,    84,   118,   119,   112,    76,
     261,   262,   101,     7,   214,   215,   263,   417,    50,    51,
     176,   110,   178,   179,   136,    19,   110,   427,    50,   112,
     101,   143,    50,   145,   167,   168,   398,   112,   101,   110,
      50,   167,   113,   405,   244,   113,   101,   110,   174,   161,
     113,   163,   202,   428,   187,   110,    33,   432,   189,    36,
      37,   194,    77,    30,   214,   215,    33,    34,    35,   202,
     110,   183,   434,    23,    51,    25,   202,   328,   329,    45,
      46,   214,   215,   100,   101,   102,   286,   110,   214,   215,
     216,    58,   223,   247,   244,    62,    63,   110,    23,   225,
      25,    68,    69,    70,    71,   259,   260,   425,   426,    71,
     241,   244,    45,    46,   240,    89,    90,    91,    92,   273,
      87,   247,    14,    15,    60,    61,   100,   101,   102,   101,
     115,    50,   111,   259,   260,    50,   286,    67,   105,   114,
     113,    53,   268,   113,    53,    50,   113,   273,   274,   113,
     111,   118,   119,   286,   111,   111,   111,    50,   110,    50,
     286,   317,   293,   114,    50,   113,   113,   298,   110,   136,
     296,   110,    50,    50,   141,    47,   143,   377,   145,   114,
     380,    50,   382,   150,    67,   114,   114,   110,   319,   320,
     111,    67,   110,    43,   161,   326,   163,   111,   398,    53,
     110,   114,   113,   111,   111,   405,    44,   174,   364,   176,
     111,   178,   179,   111,   370,   371,   183,   114,   113,   113,
      94,   111,   287,    19,   403,   425,   426,   377,   108,   429,
     380,   194,   382,   114,   434,   114,    30,   183,   187,   370,
     380,   372,   386,   175,   377,   254,    -1,   380,   398,   382,
     221,   390,   378,    -1,   380,   405,    -1,    -1,    -1,    -1,
      -1,   392,   393,    -1,   390,   398,    -1,    -1,    -1,    -1,
     396,   397,   405,    -1,    -1,   425,   426,   403,    -1,   429,
      -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   425,   426,    -1,    -1,   429,    -1,    -1,   425,
     426,   434,    -1,   223,    -1,    -1,    -1,   274,    -1,   229,
     230,   231,   232,   233,   234,   235,   236,   237,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     297,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,   316,
     317,    -1,    -1,    -1,    -1,    -1,    27,   277,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   286,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   296,   297,    -1,    50,
      -1,    -1,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   364,   318,    70,
      -1,    -1,    -1,   370,   371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,     1,   386,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   396,
     397,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    29,    30,    31,    -1,
      33,    -1,    -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,
     380,    44,    -1,    -1,   384,    48,    49,    50,    51,    -1,
     390,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    75,    -1,    -1,    -1,    -1,   417,    27,    -1,
      -1,    -1,    85,    86,     1,    -1,    89,   427,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,
      -1,    50,    19,    20,    21,    -1,    23,   110,    25,    26,
     113,   114,    29,    30,    31,    -1,    33,     1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    49,    50,    51,    19,    20,    21,    -1,    23,
      89,    25,    26,    92,    -1,    29,    30,    31,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      44,    -1,    -1,    -1,    48,    49,    50,    51,    85,    86,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,   110,    -1,    -1,   113,   114,    -1,    -1,
      -1,    85,    86,     1,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    -1,    23,   110,    25,    26,   113,
     114,    29,    30,    31,    -1,    33,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,    49,    50,    51,    19,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    -1,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    44,
      -1,    -1,    -1,    48,    49,    50,    51,    85,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,   110,    -1,    -1,   113,   114,    -1,    -1,    -1,
      85,    86,     1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    98,    99,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    -1,    23,   110,    25,    26,   113,   114,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      49,    50,    51,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    91,    92,    -1,    -1,    75,    -1,    -1,    -1,
      -1,   100,   101,   102,    -1,    -1,    85,    86,    -1,    -1,
      89,    -1,    -1,    92,    -1,    -1,   115,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,    -1,    -1,   113,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    32,    33,    -1,    -1,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    70,
      -1,    19,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      48,    49,    50,    -1,    -1,    33,    -1,    -1,    89,    -1,
      -1,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      48,    49,    50,    -1,    -1,    73,    -1,    75,    -1,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    84,    85,    86,    -1,
      -1,    89,    -1,    -1,    92,    -1,    -1,    75,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      -1,    89,   110,    -1,    92,   113,   114,    -1,    -1,    -1,
      98,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   110,    -1,    -1,   113,   114,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    36,    37,    38,
      39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      89,    -1,    -1,    92,    93,    -1,    50,    -1,    -1,    53,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    89,    -1,    -1,    92,    93,
      -1,    -1,    27,    -1,    -1,    -1,   100,    32,    33,    -1,
      -1,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      19,    20,    21,    -1,    23,    50,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    75,    -1,    -1,    48,
      49,    50,    51,    82,    83,    84,    85,    86,    -1,    -1,
      89,    90,    91,    92,    89,    -1,    -1,    92,    93,    -1,
      -1,   100,   101,   102,    -1,   100,    75,    19,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    85,    86,    -1,    -1,
      89,    33,    -1,    92,    -1,    -1,    -1,    -1,    -1,    98,
      99,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    74,
      75,   110,    -1,   112,   113,    -1,    -1,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    -1,    -1,
      -1,    -1,    -1,    75,    -1,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    85,    86,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    98,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,
      -1,   113,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      47,    50,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    27,    -1,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,    86,
      -1,    -1,    89,    90,    91,    92,    50,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,   102,    -1,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,    70,    82,    83,    84,
      85,    86,    -1,    -1,    89,    90,    91,    92,    -1,    -1,
      72,    73,    74,    75,    -1,   100,   101,   102,    -1,    -1,
      82,    83,    84,    85,    86,    -1,   111,    89,    90,    91,
      92,    -1,    -1,    -1,    75,    -1,    -1,    -1,   100,   101,
     102,    82,    83,    84,    85,    86,    -1,    -1,    89,    90,
      91,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
     101,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,   117,    50,     0,    51,   112,   119,   121,   121,
       1,     4,    31,    33,    36,    37,   118,   120,   121,   123,
     127,   129,   132,   133,   165,    21,    23,    50,   113,   128,
      50,   110,   118,   170,   170,   170,   133,   112,   121,   122,
     122,   122,   128,   121,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    27,    32,    33,
      36,    37,    38,    39,    41,    42,    50,    70,    89,    92,
      93,   100,   148,   150,   159,   163,   164,   176,   178,   179,
     180,   181,   182,   183,   185,   186,   187,    50,   148,   148,
     148,    50,   128,   130,   131,    42,   149,   163,   177,   118,
     175,   175,   175,   177,   177,    77,   118,   153,   153,   177,
     177,   177,    48,   115,   148,   184,   101,   153,    89,    92,
     169,   186,   110,   110,   110,   128,   121,   114,   130,   113,
     110,   110,   110,   154,   155,   186,    71,   118,   156,   156,
     177,   115,    50,    39,   186,    39,   186,   111,    50,   118,
     124,   171,   172,   173,   171,   172,   121,   114,   171,   171,
     172,    53,    76,    67,   154,   157,   158,   113,   113,   177,
     186,   186,    53,   177,   111,    53,   111,   111,   111,   111,
     111,   154,   154,    53,   118,   121,   160,   161,   162,   172,
      33,    36,    37,   121,   151,   152,    50,   118,   125,   177,
     173,   177,   113,   177,   177,   157,   160,   114,   122,    50,
      50,    50,   114,   152,   113,   113,     1,    19,    20,    21,
      23,    25,    26,    29,    30,    33,    44,    48,    49,    75,
      85,    86,    89,    92,    98,    99,   110,   113,   118,   121,
     126,   127,   135,   136,   137,   140,   148,   166,   167,   174,
     188,   190,   191,   194,   195,   196,   197,   198,   199,   200,
     202,   110,   110,   110,   174,   174,   118,   134,    33,   198,
     199,   202,   122,   197,    50,    50,   118,   141,   197,   197,
     197,   197,   197,   197,   197,   197,    73,    84,   114,   189,
     197,    47,   118,   147,   122,   136,   110,   113,   147,   114,
      23,   194,    72,    73,    74,    75,    82,    83,    84,    85,
      86,    89,    90,    91,    92,   100,   101,   102,    67,   147,
     147,   171,   171,   172,   114,   114,   147,   125,   110,   110,
     138,   197,   111,   168,   174,   197,   124,    53,   114,    50,
     122,   118,   189,   201,   114,   148,   189,   192,   193,   122,
     197,   197,   197,   197,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   110,   148,   177,   197,   122,   122,
     111,   111,   111,   122,    67,   171,   171,    43,   139,   114,
      84,   197,   113,   111,    67,   114,    53,   114,   115,   177,
     110,   122,   177,   177,   122,   197,   111,   111,   137,    45,
      46,   118,   142,   145,   168,   137,   197,   148,   193,   111,
     201,   122,   122,   125,   125,   114,    44,   143,    45,   118,
     142,   146,   114,   114,   111,   113,   113,   144,   138,   113,
     174,   174,   138,   139,   137,   114,   114,   139,   114
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

    { yoParserDeclVar(&(yyval), &(yyvsp[(2) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
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

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 36:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 37:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 39:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(2) - (4)]), parm, &yyloc); yoParserStmtCatch(&(yyval), &(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 40:

    { yoParserStmtReturn(&(yyval), NULL, parm, &yyloc); }
    break;

  case 42:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 43:

    { yoParserStmtCatch(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(2) - (3)]), parm, &yyloc); }
    break;

  case 44:

    { yoParserError(&(yyval), yymsgbuf, parm, &yyloc); yyclearin; YYABORT; }
    break;

  case 48:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 50:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 51:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 52:

    { 
			yoParserStmtIf(&(yyval), &(yyvsp[(3) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(5) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc);
		}
    break;

  case 53:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 54:

    { yoParserElseIf(&(yyval), &(yyvsp[(3) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 55:

    { yoParserEnableBrace(parm, &yyloc); }
    break;

  case 56:

    { yoParserElseIf(&(yyval), &(yyvsp[(4) - (5)]), &(yyvsp[(5) - (5)]), parm, &yyloc); }
    break;

  case 58:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 60:

    { yoParserElse(&(yyval), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 62:

    { yoParserCatchElem(&(yyval), &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 65:

    { yoParserDotName(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 66:

    { yoParseEmpty(&(yyvsp[(1) - (3)]), parm, &yyloc); yoParserContract(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), &(yyvsp[(1) - (3)]), parm, &yyloc); }
    break;

  case 67:

    { yoParserContract(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 69:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 70:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 71:

    { yoParserContractFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 72:

    { yoParserContractFunc(&(yyval), T_GET, &(yyvsp[(2) - (7)]), &(yyvsp[(4) - (7)]), &(yyvsp[(6) - (7)]), parm, &yyloc); }
    break;

  case 73:

    { yoParserContractFunc(&(yyval), T_SET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), NULL, parm, &yyloc); }
    break;

  case 75:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 78:

    { yoParserTypeNameDef(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 80:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 81:

    { (yyval) = (yyvsp[(2) - (2)]); }
    break;

  case 85:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 86:

    { yoParserClass(&(yyval), &(yyvsp[(2) - (6)]), &(yyvsp[(3) - (6)]), &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 90:

    { yoParserList(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 106:

    { yoParserDeclFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 107:

    { yoParserDeclFunc(&(yyval), T_GET, &(yyvsp[(2) - (10)]), &(yyvsp[(3) - (10)]), &(yyvsp[(5) - (10)]), &(yyvsp[(7) - (10)]), &(yyvsp[(9) - (10)]), parm, &yyloc); }
    break;

  case 108:

    { yoParserDeclFunc(&(yyval), T_SET, &(yyvsp[(2) - (9)]), &(yyvsp[(3) - (9)]), &(yyvsp[(5) - (9)]), NULL, &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 109:

    { 
			yoParserDeclVar(&(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), NULL, parm, &yyloc); 
			yoParserDeclFunc(&(yyvsp[(1) - (9)]), T_SUB_FUNC, NULL, &(yyvsp[(2) - (9)]), &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc);
			yoParserAssign(&(yyvsp[(2) - (9)]), &(yyvsp[(2) - (9)]), &(yyvsp[(1) - (9)]), T_INIT_ASSIGN, parm, &yyloc); 
			yoParserList(&(yyval), &(yyvsp[(3) - (9)]), &(yyvsp[(2) - (9)]), parm, &yyloc);			
		}
    break;

  case 110:

    { yoParserDeclFunc(&(yyval), T_SUB_FUNC, NULL, NULL, &(yyvsp[(4) - (9)]), &(yyvsp[(6) - (9)]), &(yyvsp[(8) - (9)]), parm, &yyloc); }
    break;

  case 111:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, &(yyvsp[(3) - (6)]), NULL, &(yyvsp[(5) - (6)]), parm, &yyloc); }
    break;

  case 112:

    { yoParserDeclFunc(&(yyval), T_LAMBDA, NULL, NULL, NULL, NULL, &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 113:

    { yoParserStmtReturn(&(yyval), &(yyvsp[(1) - (1)]), parm, &yyloc); }
    break;

  case 116:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 117:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 118:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 119:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); yoParserTypeRef(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 120:

    { yoParserDeclArg(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(3) - (4)]), parm, &yyloc); }
    break;

  case 125:

    { yoParserList(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 126:

    { yoParserDeclArg(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 130:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 131:

    { yoParserTypeFunc(&(yyval), T_FUNC, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 132:

    { yoParserTypeFunc(&(yyval), T_GET, &(yyvsp[(2) - (6)]), &(yyvsp[(4) - (6)]), &(yyvsp[(6) - (6)]), parm, &yyloc); }
    break;

  case 133:

    { yoParserTypeFunc(&(yyval), T_SET, &(yyvsp[(2) - (5)]), &(yyvsp[(4) - (5)]), NULL, parm, &yyloc); }
    break;

  case 136:

    { yoParserTypeConst(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 137:

    { yoParserTypeMutable(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 138:

    { yoParserTypeChan(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 139:

    { yoParserTypeRef(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 140:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 141:

    { yoParserTypePtr(&(yyval), &(yyvsp[(2) - (2)]), parm, &yyloc); yoParserTypePtr(&(yyval), &(yyval), parm, &yyloc); }
    break;

  case 142:

    { yoParserTypeSlice(&(yyval), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 145:

    { yoParserTypeArr(&(yyval), &(yyvsp[(2) - (4)]), &(yyvsp[(4) - (4)]), parm, &yyloc); }
    break;

  case 147:

    { yoParserTypeName(&(yyval), &(yyvsp[(1) - (2)]), &(yyvsp[(2) - (2)]), parm, &yyloc); }
    break;

  case 148:

    { yoParserTypeStdName(&(yyval), T_INT8, parm, &yyloc); }
    break;

  case 149:

    { yoParserTypeStdName(&(yyval), T_INT16, parm, &yyloc); }
    break;

  case 150:

    { yoParserTypeStdName(&(yyval), T_INT32, parm, &yyloc); }
    break;

  case 151:

    { yoParserTypeStdName(&(yyval), T_INT64, parm, &yyloc); }
    break;

  case 152:

    { yoParserTypeStdName(&(yyval), T_UINT8, parm, &yyloc); }
    break;

  case 153:

    { yoParserTypeStdName(&(yyval), T_UINT16, parm, &yyloc); }
    break;

  case 154:

    { yoParserTypeStdName(&(yyval), T_UINT32, parm, &yyloc); }
    break;

  case 155:

    { yoParserTypeStdName(&(yyval), T_UINT64, parm, &yyloc); }
    break;

  case 156:

    { yoParserTypeStdName(&(yyval), T_UINTPTR, parm, &yyloc); }
    break;

  case 157:

    { yoParserTypeStdName(&(yyval), T_STRING, parm, &yyloc); }
    break;

  case 158:

    { yoParserTypeStdName(&(yyval), T_FLOAT32, parm, &yyloc); }
    break;

  case 159:

    { yoParserTypeStdName(&(yyval), T_FLOAT64, parm, &yyloc); }
    break;

  case 160:

    { yoParserTypeStdName(&(yyval), T_BOOL, parm, &yyloc); }
    break;

  case 161:

    { yoParserTypeStdName(&(yyval), T_VOID, parm, &yyloc); }
    break;

  case 162:

    { yoParserTypeStdName(&(yyval), T_UNKNOWN_YET, parm, &yyloc); }
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

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PROP_ASSIGN, parm, &yyloc); }
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

  case 190:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_PLUS, parm, &yyloc); }
    break;

  case 191:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MINUS, parm, &yyloc); }
    break;

  case 192:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MUL, parm, &yyloc); }
    break;

  case 193:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DIV, parm, &yyloc); }
    break;

  case 194:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_MOD, parm, &yyloc); }
    break;

  case 195:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CONCAT, parm, &yyloc); }
    break;

  case 196:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OR, parm, &yyloc); }
    break;

  case 197:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_OROR, parm, &yyloc); }
    break;

  case 198:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_AND, parm, &yyloc); }
    break;

  case 199:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ANDAND, parm, &yyloc); }
    break;

  case 200:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XOR, parm, &yyloc); }
    break;

  case 201:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_XORXOR, parm, &yyloc); }
    break;

  case 202:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 203:

    { (yyval) = (yyvsp[(2) - (3)]); }
    break;

  case 206:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), parm, &yyloc); }
    break;

  case 207:

    { yoParserCast(&(yyval), &(yyvsp[(1) - (5)]), &(yyvsp[(4) - (5)]), parm, &yyloc); }
    break;

  case 208:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_PLUS, parm, &yyloc); }
    break;

  case 209:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_MINUS, parm, &yyloc); }
    break;

  case 210:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_NOT, parm, &yyloc); }
    break;

  case 211:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_TILDE, parm, &yyloc); }
    break;

  case 212:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_CHAN_ACCESS, parm, &yyloc); }
    break;

  case 214:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_DOT, parm, &yyloc); }
    break;

  case 215:

    { yoParserBinOp(&(yyval), &(yyvsp[(1) - (4)]), &(yyvsp[(3) - (4)]), T_INDEX, parm, &yyloc); }
    break;

  case 216:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_INDIRECT, parm, &yyloc); }
    break;

  case 217:

    { yoParserUnaryOp(&(yyval), &(yyvsp[(2) - (2)]), T_ADDR, parm, &yyloc); }
    break;

  case 218:

    { yoParserAssign(&(yyval), &(yyvsp[(1) - (3)]), &(yyvsp[(3) - (3)]), T_ASSIGN, parm, &yyloc); }
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




