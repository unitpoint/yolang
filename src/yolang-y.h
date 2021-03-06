/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
     T_WHILE = 305,
     T_LOOP = 306,
     T_BREAK = 307,
     T_CONTINUE = 308,
     T_SWITCH = 309,
     T_CASE = 310,
     T_DEFAULT = 311,
     T_FALLTHROUGH = 312,
     T_IN = 313,
     T_IF = 314,
     T_ELSE = 315,
     T_ELSEIF = 316,
     T_CATCH = 317,
     T_SIZEOF = 318,
     T_LNUMBER = 319,
     T_DNUMBER = 320,
     T_NAME = 321,
     T_NEWLINE = 322,
     T_FIX = 323,
     T_POW_ASSIGN = 324,
     T_RSH_ASSIGN = 325,
     T_LSH_ASSIGN = 326,
     T_XOR_ASSIGN = 327,
     T_OR_ASSIGN = 328,
     T_AND_ASSIGN = 329,
     T_MOD_ASSIGN = 330,
     T_CONCAT_ASSIGN = 331,
     T_DIV_ASSIGN = 332,
     T_MUL_ASSIGN = 333,
     T_MINUS_ASSIGN = 334,
     T_PLUS_ASSIGN = 335,
     T_DECL_ASSIGN = 336,
     T_ASSIGN = 337,
     T_INIT_ASSIGN = 338,
     T_PROP_ASSIGN = 339,
     T_XORXOR = 340,
     T_OROR = 341,
     T_ANDAND = 342,
     T_CHAN_ACCESS = 343,
     T_GT = 344,
     T_LT = 345,
     T_GE = 346,
     T_LE = 347,
     T_NE = 348,
     T_EQ = 349,
     T_CONCAT = 350,
     T_XOR = 351,
     T_OR = 352,
     T_MINUS = 353,
     T_PLUS = 354,
     T_RSH = 355,
     T_LSH = 356,
     T_AND = 357,
     T_MOD = 358,
     T_DIV = 359,
     T_MUL = 360,
     T_POW = 361,
     T_AS = 362,
     T_ADDR = 363,
     T_INDIRECT = 364,
     T_AT = 365,
     T_POST_UNARY = 366,
     T_UNARY = 367,
     T_DEC = 368,
     T_INC = 369,
     T_TILDE = 370,
     T_NOT = 371,
     T_DOT = 372,
     T_INDEX = 373,
     T_REF = 374,
     T_PTR = 375,
     T_ARR = 376,
     T_DOTNAME = 377,
     NotParen = 378
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
