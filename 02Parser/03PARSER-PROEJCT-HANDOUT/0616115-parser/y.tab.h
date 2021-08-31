/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    STRINGCONST = 259,
    COMMENT = 260,
    PROGRAM = 261,
    ID = 262,
    PARLEFT = 263,
    PARRIGHT = 264,
    SEMICOLON = 265,
    PERIOD = 266,
    COMMA = 267,
    VAR = 268,
    COLON = 269,
    ARRAY = 270,
    LSBRACKET = 271,
    RSBRACKET = 272,
    OF = 273,
    INTEGER = 274,
    REAL = 275,
    FUNCTION_TOK = 276,
    PROCEDURE = 277,
    BEGIN_TOK = 278,
    END = 279,
    ASSIGNOP = 280,
    IF = 281,
    THEN = 282,
    ELSE = 283,
    WHILE = 284,
    DO = 285,
    NOT = 286,
    LDOTS = 287,
    IDENTIFIER = 288,
    STRING = 289,
    PLUS = 290,
    MINUS = 291,
    OR = 292,
    AND = 293,
    LESSTHAN = 294,
    LESSTHANEQ = 295,
    EQUALS = 296,
    GREATERTHANEQ = 297,
    GREATERTHAN = 298,
    NEQUALS = 299,
    MULT = 300,
    DIV = 301
  };
#endif
/* Tokens.  */
#define NUM 258
#define STRINGCONST 259
#define COMMENT 260
#define PROGRAM 261
#define ID 262
#define PARLEFT 263
#define PARRIGHT 264
#define SEMICOLON 265
#define PERIOD 266
#define COMMA 267
#define VAR 268
#define COLON 269
#define ARRAY 270
#define LSBRACKET 271
#define RSBRACKET 272
#define OF 273
#define INTEGER 274
#define REAL 275
#define FUNCTION_TOK 276
#define PROCEDURE 277
#define BEGIN_TOK 278
#define END 279
#define ASSIGNOP 280
#define IF 281
#define THEN 282
#define ELSE 283
#define WHILE 284
#define DO 285
#define NOT 286
#define LDOTS 287
#define IDENTIFIER 288
#define STRING 289
#define PLUS 290
#define MINUS 291
#define OR 292
#define AND 293
#define LESSTHAN 294
#define LESSTHANEQ 295
#define EQUALS 296
#define GREATERTHANEQ 297
#define GREATERTHAN 298
#define NEQUALS 299
#define MULT 300
#define DIV 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
