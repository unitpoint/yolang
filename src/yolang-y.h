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
     T_VAR = 281,
     T_TYPE = 282,
     T_FUNC = 283,
     T_CONST = 284,
     T_STRUCT = 285,
     T_CLASS = 286,
     T_INTERFACE = 287,
     T_LNUMBER = 288,
     T_DNUMBER = 289,
     T_NAME = 290,
     T_NEWLINE = 291,
     T_FIX = 292,
     T_POW_ASSIGN = 293,
     T_RSH_ASSIGN = 294,
     T_LSH_ASSIGN = 295,
     T_XOR_ASSIGN = 296,
     T_OR_ASSIGN = 297,
     T_AND_ASSIGN = 298,
     T_MOD_ASSIGN = 299,
     T_CONCAT_ASSIGN = 300,
     T_DIV_ASSIGN = 301,
     T_MUL_ASSIGN = 302,
     T_MINUS_ASSIGN = 303,
     T_PLUS_ASSIGN = 304,
     T_DECL_ASSIGN = 305,
     T_ASSIGN = 306,
     T_XORXOR = 307,
     T_OROR = 308,
     T_ANDAND = 309,
     T_GT = 310,
     T_LT = 311,
     T_GE = 312,
     T_LE = 313,
     T_NE = 314,
     T_EQ = 315,
     T_CONCAT = 316,
     T_XOR = 317,
     T_OR = 318,
     T_MINUS = 319,
     T_PLUS = 320,
     T_RSH = 321,
     T_LSH = 322,
     T_AND = 323,
     T_MOD = 324,
     T_DIV = 325,
     T_MUL = 326,
     T_POW = 327,
     T_IS = 328,
     T_UNARY = 329,
     T_DEC = 330,
     T_INC = 331,
     T_TILDE = 332,
     T_NOT = 333,
     T_DOT = 334,
     T_AT = 335,
     T_INDIRECT = 336,
     T_ADDR = 337,
     T_INDEX = 338,
     T_PTR = 339,
     T_ARR = 340,
     T_DOTNAME = 341,
     NotParen = 342
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
