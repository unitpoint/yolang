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
