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
