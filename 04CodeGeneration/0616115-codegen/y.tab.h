/* A Bison parser, made by GNU Bison 3.5.  */

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
    COMMENT = 258,
    PROGRAM = 259,
    ID = 260,
    PARLEFT = 261,
    PARRIGHT = 262,
    SEMICOLON = 263,
    PERIOD = 264,
    COMMA = 265,
    VAR = 266,
    COLON = 267,
    ARRAY = 268,
    LSBRACKET = 269,
    RSBRACKET = 270,
    OF = 271,
    INTEGER = 272,
    REAL = 273,
    FUNCTION_TOK = 274,
    PROCEDURE = 275,
    BEGIN_TOK = 276,
    END = 277,
    ASSIGNOP = 278,
    IF = 279,
    THEN = 280,
    ELSE = 281,
    WHILE = 282,
    DO = 283,
    NOT = 284,
    LDOTS = 285,
    STRING = 286,
    NUM = 287,
    STRINGCONST = 288,
    IDENTIFIER = 289,
    OR = 290,
    AND = 291,
    EQUALS = 292,
    LESSTHAN = 293,
    LESSTHANEQ = 294,
    GREATERTHANEQ = 295,
    GREATERTHAN = 296,
    NEQUALS = 297,
    PLUS = 298,
    MINUS = 299,
    MULT = 300,
    DIV = 301
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define PROGRAM 259
#define ID 260
#define PARLEFT 261
#define PARRIGHT 262
#define SEMICOLON 263
#define PERIOD 264
#define COMMA 265
#define VAR 266
#define COLON 267
#define ARRAY 268
#define LSBRACKET 269
#define RSBRACKET 270
#define OF 271
#define INTEGER 272
#define REAL 273
#define FUNCTION_TOK 274
#define PROCEDURE 275
#define BEGIN_TOK 276
#define END 277
#define ASSIGNOP 278
#define IF 279
#define THEN 280
#define ELSE 281
#define WHILE 282
#define DO 283
#define NOT 284
#define LDOTS 285
#define STRING 286
#define NUM 287
#define STRINGCONST 288
#define IDENTIFIER 289
#define OR 290
#define AND 291
#define EQUALS 292
#define LESSTHAN 293
#define LESSTHANEQ 294
#define GREATERTHANEQ 295
#define GREATERTHAN 296
#define NEQUALS 297
#define PLUS 298
#define MINUS 299
#define MULT 300
#define DIV 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "miniPascal.y"

    struct Node* node;
    //int num;//esto puede ser both real o stirng
    /* char * num; */
    char* num;
    /* double real; */
    char character;
    char * string;

#line 159 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
