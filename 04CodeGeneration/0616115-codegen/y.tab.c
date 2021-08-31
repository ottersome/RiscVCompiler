/* A Bison parser, made by GNU Bison 3.5.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "miniPascal.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debugheader.h"
#include "symboltable.h"
#include "semantics.h"

Node* ASTROOT;//Just declaring it atm.

extern const char * yytext;
extern const int line_no;
void yyerror(const char * charo){
    //fprintf(stderr,"There was an error on line : %d\n",line_no);
    fprintf(stderr,"line %d error token: %s\n",line_no,yytext);
    exit(-1);
}
bool isInt(char* s){
    for(int i = 0; i < strlen(s);i++) {
        if(!(s[i] >= '0' && s[i]<='9')) return false;
    }
    return true;
}

#line 96 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 250 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

#define YYUNDEFTOK  2
#define YYMAXUTOK   301


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    88,    97,   107,   118,   128,   133,   160,
     165,   169,   176,   182,   190,   206,   216,   226,   232,   236,
     250,   266,   267,   271,   280,   287,   292,   300,   308,   313,
     315,   322,   329,   335,   344,   352,   359,   365,   374,   379,
     387,   393,   401,   411,   413,   422,   425,   433,   446,   450,
     458,   468,   476,   480,   487,   489,   497,   503,   510,   516,
     522,   528,   534,   540,   547,   555,   567,   576
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "PROGRAM", "ID", "PARLEFT",
  "PARRIGHT", "SEMICOLON", "PERIOD", "COMMA", "VAR", "COLON", "ARRAY",
  "LSBRACKET", "RSBRACKET", "OF", "INTEGER", "REAL", "FUNCTION_TOK",
  "PROCEDURE", "BEGIN_TOK", "END", "ASSIGNOP", "IF", "THEN", "ELSE",
  "WHILE", "DO", "NOT", "LDOTS", "STRING", "NUM", "STRINGCONST",
  "IDENTIFIER", "OR", "AND", "EQUALS", "LESSTHAN", "LESSTHANEQ",
  "GREATERTHANEQ", "GREATERTHAN", "NEQUALS", "PLUS", "MINUS", "MULT",
  "DIV", "$accept", "prog", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "arguments", "parameter_list", "optional_var",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "variable", "tail", "procedure_statement",
  "expression_list", "expression", "boolexpression", "simple_expression",
  "term", "factor", "mulop", "relop", "id", "num", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      29,    53,    55,   -87,    57,   -87,    53,    24,   -87,    84,
      53,   -87,   -87,    83,    53,    54,     2,    53,    53,    18,
      90,   -87,    91,    12,    93,    93,    15,    15,   -87,    79,
      94,   -87,    80,   -87,     9,   -87,    83,   -87,    92,   -87,
     -87,   -87,    96,   -87,    97,    95,   101,    15,    15,   -87,
     -87,    21,    21,    85,    34,    42,    31,   -87,    13,   -87,
      77,   -87,    18,    15,    15,    15,   -87,    54,    21,   -87,
     -87,   104,    53,    19,   -87,   105,   -87,   -87,   -87,    18,
      15,    15,   -87,   -87,   -87,   -87,   -87,   -87,    15,    15,
      15,   -87,   -87,    15,    15,   -87,    18,   -87,   -87,    44,
     -87,    98,   -87,    86,   -87,    16,   106,   -87,    89,   -87,
     -87,    31,    31,    45,   -87,    50,   -87,   -87,    15,   103,
      21,    12,   -87,    18,   -87,   -87,   -87,   108,   110,   -87,
     109,    97,    12,   -87,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    64,     0,     1,     0,     0,     3,     0,
       0,     6,     4,    13,     0,     0,     0,     0,     0,    32,
       0,     6,     0,     0,    18,    18,     0,     0,    29,     0,
      24,    25,     0,    28,    36,    12,    13,     2,     0,     9,
      10,    11,     0,     7,    22,     0,     0,     0,     0,    65,
      53,     0,     0,     0,    40,    43,    45,    48,    35,    52,
       0,    23,    32,     0,     0,     0,    33,     0,     0,     5,
      21,     0,     0,     0,    16,     0,    55,    66,    67,    32,
       0,     0,    60,    58,    61,    62,    59,    63,     0,     0,
       0,    56,    57,     0,     0,    50,    32,    26,    27,     0,
      38,     0,    14,     0,    17,     0,     0,    54,     0,    42,
      41,    46,    47,    44,    49,     0,    31,    37,     0,    35,
       0,     0,    15,    32,    51,    39,    34,     0,    19,    30,
       0,    22,     0,    20,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,    -6,    99,   -86,    46,    88,   -87,   -87,   102,
     -10,   -87,    -5,   -87,   -87,   -55,   -87,   -52,   -87,    32,
     -25,    10,    38,     8,   -37,   -87,   -87,    -1,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    42,    43,    15,    20,    21,    45,
      71,    72,    28,    29,    30,    31,    32,    66,    33,    99,
     100,    54,    55,    56,    57,    93,    90,    58,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    53,    60,    77,    78,     8,    95,    97,    16,    12,
      22,    76,    10,     8,    23,    64,    24,    25,    34,    94,
     103,    47,    75,    65,   108,    38,    10,    65,   121,    39,
      40,     9,   -35,     1,    10,   128,    39,    40,    98,    19,
     101,   116,    26,    41,    48,    27,   134,    49,    50,     3,
      41,   117,     3,    49,   118,     5,   114,   124,    51,    52,
     118,    34,   102,     6,    51,    52,   105,   126,   129,    80,
      81,     8,   127,    17,    18,    19,    91,    92,    34,    82,
      83,    84,    85,    86,    87,    88,    89,     3,    88,    89,
     109,   110,    11,   125,    14,    34,   111,   112,    35,    44,
      37,    61,    62,    63,    69,    96,    68,    73,    70,    74,
      79,   104,   107,   119,   122,   123,   120,    65,   131,   106,
      36,   133,    34,   130,    67,   132,   115,    46,   113
};

static const yytype_uint8 yycheck[] =
{
       1,    26,    27,    51,    52,     6,    58,    62,    14,    10,
      15,    48,    10,    14,    12,     6,    17,    18,    19,     6,
      68,     6,    47,    14,    79,    13,    10,    14,    12,    17,
      18,     7,    23,     4,    10,   121,    17,    18,    63,    21,
      65,    96,    24,    31,    29,    27,   132,    32,    33,    34,
      31,     7,    34,    32,    10,     0,    93,     7,    43,    44,
      10,    62,    67,     6,    43,    44,    72,   119,   123,    35,
      36,    72,   120,    19,    20,    21,    45,    46,    79,    37,
      38,    39,    40,    41,    42,    43,    44,    34,    43,    44,
      80,    81,     8,   118,    11,    96,    88,    89,     8,     6,
       9,    22,     8,    23,     8,    28,    14,    12,    11,     8,
      25,     7,     7,    15,     8,    26,    30,    14,     8,    73,
      21,   131,   123,    15,    36,    16,    94,    25,    90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,    48,    34,    74,     0,     6,    49,    74,     7,
      10,     8,    74,    50,    11,    53,    49,    19,    20,    21,
      54,    55,    59,    12,    74,    74,    24,    27,    59,    60,
      61,    62,    63,    65,    74,     8,    50,     9,    13,    17,
      18,    31,    51,    52,     6,    56,    56,     6,    29,    32,
      33,    43,    44,    67,    68,    69,    70,    71,    74,    75,
      67,    22,     8,    23,     6,    14,    64,    53,    14,     8,
      11,    57,    58,    12,     8,    67,    71,    75,    75,    25,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      73,    45,    46,    72,     6,    64,    28,    62,    67,    66,
      67,    67,    59,    75,     7,    49,    52,     7,    62,    68,
      68,    70,    70,    69,    71,    66,    62,     7,    10,    15,
      30,    12,     8,    26,     7,    67,    64,    75,    51,    62,
      15,     8,    16,    57,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    68,    68,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     3,     0,     4,     6,     4,     3,     0,     4,
       6,     1,     0,     3,     1,     1,     3,     3,     1,     1,
       6,     4,     0,     2,     4,     0,     1,     4,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     3,     1,     3,
       2,     4,     1,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 70 "miniPascal.y"
        {
        ASTROOT = makeNode(NODE_ROOT);
        (yyval.node) = ASTROOT;
        Node* declNode = makeNode(NODE_DECLARATIONS);
        Node* declList = (yyvsp[-6].node);
        Node* typeNode =  makeNode(NODE_TYPE_PROG_ARG);
        adoptChild(declNode, declList);
        adoptChild(declNode, typeNode);
            adoptChild((yyval.node),(yyvsp[-8].node));
            adoptChild((yyval.node),declNode);
            adoptChild((yyval.node),(yyvsp[-3].node));
            adoptChild((yyval.node),(yyvsp[-2].node));
            adoptChild((yyval.node),(yyvsp[-1].node));
        /* Logg("Parse Succesful\n"); */
        }
#line 1532 "y.tab.c"
    break;

  case 3:
#line 89 "miniPascal.y"
    {//Create first instance of identifier list
        /* Logg("Initializing Id\n"); */
        (yyval.node) = makeNode(NODE_ID_LIST);
        (yyval.node)->lineInCode = (yyvsp[0].node)->lineInCode;
        /* Logg("Done  Id\n"); */
        adoptChild((yyval.node),(yyvsp[0].node));
        /* Logg("Adopted  Id\n"); */
    }
#line 1545 "y.tab.c"
    break;

  case 4:
#line 98 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        (yyval.node)->lineInCode = (yyvsp[0].node)->lineInCode;
        //Logg("Adding To IdentifierList %s\n");
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1556 "y.tab.c"
    break;

  case 5:
#line 108 "miniPascal.y"
    {//DIVE
        //Copy from the previous node
        (yyval.node) = (yyvsp[-5].node);
        Node* thisDecl = makeNode(NODE_DECLARATIONS);
        thisDecl->lineInCode = (yyvsp[-3].node)->lineInCode;
        adoptChild((yyval.node),thisDecl);
        adoptChild(thisDecl, (yyvsp[-3].node));
        adoptChild(thisDecl, (yyvsp[-1].node));
    }
#line 1570 "y.tab.c"
    break;

  case 6:
#line 118 "miniPascal.y"
    {//On empty rule create new NODE_ADD
    //IF we do not have this rulle then we are 
    //forcing every  program and eveyr subprogram to have declared at least one variable.
    //THis(having atleast one) of course is not necessary
    //DIVE
        (yyval.node) = makeNode(NODE_DECLARATIONS_ROOT);
        //No Children
    }
#line 1583 "y.tab.c"
    break;

  case 7:
#line 129 "miniPascal.y"
     {
     (yyval.node) = (yyvsp[0].node);
     (yyval.node)->lineInCode = line_no;
     }
#line 1592 "y.tab.c"
    break;

  case 8:
#line 134 "miniPascal.y"
    {//DEVI
       (yyval.node) = (yyvsp[0].node);
       (yyval.node)->lineInCode = line_no;
       Node* arrNode = makeNode(NODE_TYPE_ARR);         
       adoptChild(arrNode,(yyvsp[-5].node));
       adoptChild(arrNode,(yyvsp[-3].node));
       /* arrNode->lowerBound = $3->doubleVal; */
       /* arrNode->upperBound = $5->doubleVal; */
       /* deleteNodeTree($3); */
       /* deleteNodeTree($5); */
       adoptChild((yyval.node),arrNode);

       /* adoptChild(arrNode,$3); */
       /* adoptChild(arrNode,$5); */
       /* adoptChild($$,arrNode); */
       /* $$->lowerBound = $3->intVal; */
       /* deleteNodeTree($3); */
       /* $$->upperBound = $5->intVal; */
       /* deleteNodeTree($5); */
       //
       //TODO remove this as a child. We are only doing it here because our 
       //free algorithm causes memory leak otherwise. Make sure if you remove the
       //following line you have handled that.
    }
#line 1621 "y.tab.c"
    break;

  case 9:
#line 161 "miniPascal.y"
        {
        (yyval.node) = makeNode(NODE_TYPE_INT);
        (yyval.node)->typeRef = (yyval.node);//Reference  to itself so we know its a primitive type.
        }
#line 1630 "y.tab.c"
    break;

  case 10:
#line 165 "miniPascal.y"
                   {
        (yyval.node) = makeNode(NODE_TYPE_REAL);
        (yyval.node)->typeRef = (yyval.node);
        }
#line 1639 "y.tab.c"
    break;

  case 11:
#line 169 "miniPascal.y"
                {
        (yyval.node) = makeNode(NODE_TYPE_STRINGCONST);
        (yyval.node)->typeRef = (yyval.node);
        }
#line 1648 "y.tab.c"
    break;

  case 12:
#line 177 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-2].node);//Keep Sending the root to the next subpdeclaration
        adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 1657 "y.tab.c"
    break;

  case 13:
#line 182 "miniPascal.y"
    {
    //DIVE
        (yyval.node) = makeNode(NODE_SUBPDECLARATIONS);
    }
#line 1666 "y.tab.c"
    break;

  case 14:
#line 194 "miniPascal.y"
    {
       //$$ = makeNode(subprogram_declaration);  NVM we only need can create the node from suprogram
       //even better since they have the information there
       /* $$ = makeNode(NODE_SUBPDECLARATION); */
       /* adoptChild($$,$1); */
       (yyval.node) = (yyvsp[-3].node);//Changed so we can treat all SUBP (proc and func) as one later on
       adoptChild((yyval.node),(yyvsp[-2].node));
       adoptChild((yyval.node),(yyvsp[-1].node));
       adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1681 "y.tab.c"
    break;

  case 15:
#line 207 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_FUNCTION); 
        //We could actually copy the id to the node str 
        //value itself but for sake of just makign it work ill leave it like that for now
        (yyval.node)->lineInCode = (yyvsp[-4].node)->lineInCode;
        adoptChild((yyval.node),(yyvsp[-4].node));//1
        adoptChild((yyval.node),(yyvsp[-3].node));//2
        adoptChild((yyval.node),(yyvsp[-1].node));//3
    }
#line 1695 "y.tab.c"
    break;

  case 16:
#line 217 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_PROCEDURE);
        (yyval.node)->lineInCode = (yyvsp[-2].node)->lineInCode;
        adoptChild((yyval.node),(yyvsp[-2].node));//1
        adoptChild((yyval.node),(yyvsp[-1].node));//2
    }
#line 1706 "y.tab.c"
    break;

  case 17:
#line 227 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);//Just pass it along
        (yyval.node)->lineInCode = (yyvsp[-1].node)->lineInCode;
    }
#line 1715 "y.tab.c"
    break;

  case 18:
#line 232 "miniPascal.y"
        {(yyval.node) = makeNode(NODE_ARGUMENTS);}
#line 1721 "y.tab.c"
    break;

  case 19:
#line 237 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_ARGUMENTS);
        Node* argument = makeNode(NODE_ARGUMENT);
        argument->lineInCode = (yyvsp[-2].node)->lineInCode;
        (yyval.node)->lineInCode = (yyvsp[-2].node)->lineInCode;

        adoptChild(argument,(yyvsp[-2].node));
        adoptChild(argument,(yyvsp[0].node));//Remove only when your freeing algorithm can handle it
        argument->typeRef = (yyvsp[0].node);
    

        adoptChild((yyval.node),argument);
    }
#line 1739 "y.tab.c"
    break;

  case 20:
#line 251 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[0].node);
        Node* argument = makeNode(NODE_ARGUMENT);
        argument->lineInCode = (yyvsp[-4].node)->lineInCode;
        (yyval.node)->lineInCode = (yyvsp[-4].node)->lineInCode;

        adoptChild(argument,(yyvsp[-4].node));
        adoptChild(argument,(yyvsp[-2].node));//Remove only when your freeing algorithm can handle it
        argument->typeRef = (yyvsp[-2].node);

        adoptChild((yyval.node),argument);
    }
#line 1756 "y.tab.c"
    break;

  case 23:
#line 274 "miniPascal.y"
               {
               (yyval.node) = (yyvsp[-1].node);//TODO how should we use this for opening scopes
               }
#line 1764 "y.tab.c"
    break;

  case 24:
#line 281 "miniPascal.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 1772 "y.tab.c"
    break;

  case 25:
#line 288 "miniPascal.y"
    {//THere should be at least one statement
        (yyval.node) = makeNode(NODE_STATEMENT_LIST);
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1781 "y.tab.c"
    break;

  case 26:
#line 293 "miniPascal.y"
        {
            (yyval.node) = (yyvsp[-2].node);
            adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1790 "y.tab.c"
    break;

  case 27:
#line 301 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_ASSIGN_OP); 
        (yyvsp[-2].node)->assignPos = POS_LHS;
        (yyval.node)->lineInCode = line_no;
        adoptChild((yyval.node),(yyvsp[-2].node));
        adoptChild((yyval.node),(yyvsp[0].node));//TODO DEVI Might want to denote that this expression belongs to the variable somehow
    }
#line 1802 "y.tab.c"
    break;

  case 28:
#line 309 "miniPascal.y"
        {
        (yyval.node) = (yyvsp[0].node);
        (yyval.node)->lineInCode=line_no;
        }
#line 1811 "y.tab.c"
    break;

  case 29:
#line 314 "miniPascal.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1817 "y.tab.c"
    break;

  case 30:
#line 316 "miniPascal.y"
        {
        (yyval.node) = makeNode(NODE_IF_ELSE);
        adoptChild((yyval.node),(yyvsp[-4].node));
        adoptChild((yyval.node),(yyvsp[-2].node));
        adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1828 "y.tab.c"
    break;

  case 31:
#line 323 "miniPascal.y"
    {
       (yyval.node) = makeNode(NODE_WHILE); 
       adoptChild((yyval.node),(yyvsp[-2].node));
       adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1838 "y.tab.c"
    break;

  case 32:
#line 329 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_STMNT);
    }
#line 1846 "y.tab.c"
    break;

  case 33:
#line 336 "miniPascal.y"
         {
            (yyval.node) = makeNode(NODE_VARREF);
            (yyval.node)->lineInCode = (yyvsp[-1].node)->lineInCode;
            adoptChild((yyval.node),(yyvsp[-1].node));
            adoptChild((yyval.node),(yyvsp[0].node));//This could be INVALID_VALUE which means it doesnt specify a subscript(because it doesnt have to).
         }
#line 1857 "y.tab.c"
    break;

  case 34:
#line 345 "miniPascal.y"
    {//Making sure recursivity is taken care of
        //Just do it always
        (yyvsp[0].node)->valValidity = VALID_VALUE;//Means we have found atleast a single expression thus we can have a vlid array
        (yyval.node) = (yyvsp[0].node);
        adoptChild((yyval.node),(yyvsp[-2].node));
    }
#line 1868 "y.tab.c"
    break;

  case 35:
#line 352 "miniPascal.y"
       {
        (yyval.node) = makeNode(NODE_ARR_SUFFIXES);
        (yyval.node)->valValidity=INVALID_VALUE;
       }
#line 1877 "y.tab.c"
    break;

  case 36:
#line 360 "miniPascal.y"
    {//TODO DEVI
        (yyval.node) = makeNode(NODE_IN_STATEMENT_CALL);
        (yyval.node)->lineInCode = (yyvsp[0].node)->lineInCode;
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1887 "y.tab.c"
    break;

  case 37:
#line 366 "miniPascal.y"
    {
       (yyval.node) = makeNode(NODE_IN_STATEMENT_CALL);
       adoptChild((yyval.node),(yyvsp[-3].node));
       adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 1897 "y.tab.c"
    break;

  case 38:
#line 375 "miniPascal.y"
    {
        (yyval.node)  = makeNode(NODE_EXPR_LIST);
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1906 "y.tab.c"
    break;

  case 39:
#line 380 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        adoptChild((yyval.node),(yyvsp[0].node)); 
    }
#line 1915 "y.tab.c"
    break;

  case 40:
#line 388 "miniPascal.y"
        {
         /* $$ = makeNode(NODE_EXPR);  */
        (yyval.node) =(yyvsp[0].node);
            /* adoptChild($$,$1); */
        }
#line 1925 "y.tab.c"
    break;

  case 41:
#line 394 "miniPascal.y"
        {
        (yyval.node) =  makeNode(NODE_BINARY_EXPR);
        (yyval.node)->operation=NODE_OP_AND;
        (yyval.node)->lineInCode=line_no;
            adoptChild((yyval.node),(yyvsp[-2].node));
            adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1937 "y.tab.c"
    break;

  case 42:
#line 402 "miniPascal.y"
        {
        (yyval.node) = makeNode(NODE_BINARY_EXPR);
        (yyval.node)->lineInCode=line_no;
        (yyval.node)->operation = NODE_OP_OR;
            adoptChild((yyval.node),(yyvsp[-2].node));
            adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1949 "y.tab.c"
    break;

  case 43:
#line 412 "miniPascal.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1955 "y.tab.c"
    break;

  case 44:
#line 414 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        adoptChild((yyval.node),(yyvsp[-2].node));
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1965 "y.tab.c"
    break;

  case 45:
#line 423 "miniPascal.y"
        {(yyval.node) = (yyvsp[0].node);}
#line 1971 "y.tab.c"
    break;

  case 46:
#line 426 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_ADD;
      adoptChild((yyval.node),(yyvsp[-2].node));
      adoptChild((yyval.node),(yyvsp[0].node));
      }
#line 1983 "y.tab.c"
    break;

  case 47:
#line 434 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_SUBTRACT;
      adoptChild((yyval.node),(yyvsp[-2].node));
      adoptChild((yyval.node),(yyvsp[0].node));
       /*$$ = $2; */
       /*adoptChild($$,$1);*/
       /*adoptChild($$,$3);*/
    }
#line 1998 "y.tab.c"
    break;

  case 48:
#line 447 "miniPascal.y"
     {
     (yyval.node) = (yyvsp[0].node);
     }
#line 2006 "y.tab.c"
    break;

  case 49:
#line 451 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        adoptChild((yyval.node), (yyvsp[-2].node));
        adoptChild((yyval.node), (yyvsp[0].node));
    }
#line 2016 "y.tab.c"
    break;

  case 50:
#line 459 "miniPascal.y"
    {
       //Same as the one we did vefore 
        (yyval.node) = makeNode(NODE_VARREF);
        (yyval.node)->lineInCode = (yyvsp[-1].node)->lineInCode;
        //Since factor is part of an expression this means that this var ref is RHS
        (yyval.node)->assignPos = POS_RHS;
        adoptChild((yyval.node),(yyvsp[-1].node));
        adoptChild((yyval.node),(yyvsp[0].node));//This could be INVALID_VALUE which means it doesnt specify a subscript(because it doesnt have to).
    }
#line 2030 "y.tab.c"
    break;

  case 51:
#line 469 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_FUNC_CALL);
        (yyval.node)->assignPos = POS_RHS;
        (yyval.node)->lineInCode = line_no;
        adoptChild((yyval.node),(yyvsp[-3].node));
        adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 2042 "y.tab.c"
    break;

  case 52:
#line 477 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[0].node);//Just pass it along
    }
#line 2050 "y.tab.c"
    break;

  case 53:
#line 481 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_TYPE_STRINGCONST); 
        (yyval.node)->nodeStdType = TYPE_CONST_STRING;
        //TODO maybe set its hasConcreteValue flat to true
        copyStr((yyval.node),(yyvsp[0].string));
    }
#line 2061 "y.tab.c"
    break;

  case 54:
#line 488 "miniPascal.y"
        {(yyval.node) = (yyvsp[-1].node);}
#line 2067 "y.tab.c"
    break;

  case 55:
#line 490 "miniPascal.y"
        {
        (yyval.node) = makeNode(NODE_UNARY_EXPR);
        (yyval.node)->lineInCode = line_no;
        (yyval.node)->uoperation = NODE_OP_NOT;
        adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 2078 "y.tab.c"
    break;

  case 56:
#line 498 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_MULT;
      }
#line 2088 "y.tab.c"
    break;

  case 57:
#line 504 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_DIV;
      }
#line 2098 "y.tab.c"
    break;

  case 58:
#line 511 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_LESSTHAN;
      }
#line 2108 "y.tab.c"
    break;

  case 59:
#line 517 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_GREATERTHAN;
      }
#line 2118 "y.tab.c"
    break;

  case 60:
#line 523 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_EQUALS;
      }
#line 2128 "y.tab.c"
    break;

  case 61:
#line 529 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_LESSTHANEQ;
      }
#line 2138 "y.tab.c"
    break;

  case 62:
#line 535 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_GREATERTHANEQ;
      }
#line 2148 "y.tab.c"
    break;

  case 63:
#line 541 "miniPascal.y"
      {
      (yyval.node) = makeNode(NODE_BINARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->operation = NODE_OP_NEQUALS;
      }
#line 2158 "y.tab.c"
    break;

  case 64:
#line 548 "miniPascal.y"
    {
    (yyval.node) = makeNode(NODE_ID);
    (yyval.node)->lineInCode = line_no;
    copyStr((yyval.node),(yyvsp[0].string));
}
#line 2168 "y.tab.c"
    break;

  case 65:
#line 556 "miniPascal.y"
    {
        //We have received a string. Nowe we have to convert this 
        //string into a double while detecting if its an int or oreal
        (yyval.node) = makeNode(NODE_NUM);
        (yyval.node)->doubleVal = atof((yyvsp[0].string));
        (yyval.node)->nodeStdType = (isInt((yyvsp[0].string)))?TYPE_INT:TYPE_REAL;
        (yyval.node)->hasConcreteValue = true;
        //Nah nah we are sending num as adouble and we are gonig to sort it out here
        /* copyStr($$,$1); */
        /* $$->intVal =  $1;//SUPER TODO deal with this */
    }
#line 2184 "y.tab.c"
    break;

  case 66:
#line 568 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_UNARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->uoperation = NODE_OP_POSSIGN;
     /* $$->hasConcreteValue= true; */
      /* $$->doubleVal = $2->doubleVal; */
      adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 2197 "y.tab.c"
    break;

  case 67:
#line 577 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_UNARY_EXPR);
      (yyval.node)->lineInCode=line_no;
      (yyval.node)->uoperation = NODE_OP_NEGSIGN;
      /* $$->doubleVal = -1*$2->doubleVal; */
      /* $$->hasConcreteValue= true; */
      adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 2210 "y.tab.c"
    break;


#line 2214 "y.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 586 "miniPascal.y"

//d
//int yywrap(){return 1;}
int main (int argc, char **argv){
    if(argc!= 2){
        fprintf(stderr,"Please Use File dir as argument\n");
        return -1;
    }
    FILE *fp = freopen(argv[1],"r",stdin);

    int parseResult = yyparse();
    if(parseResult==0)
        printf("********************************\n"
         "*       No syntax error!       *\n"
         "********************************\n");

    traverseTree(ASTROOT,false,true,0);

    SymbolTable symTables[100];//Create a buffer for those table that open and close
    size_t tableIndex;

    initializeSymbolTable(&symTables[0]);
    bool thereWasSemanticError = buildTable(&symTables[0],ASTROOT,&tableIndex);

        printf(
        "********************************\n"
        "*    Startng Code Generation   *\n"
        "********************************\n");

    if(!thereWasSemanticError)
        generateCode(ASTROOT,symTables);
    else 
        printf("Please fix your semantic errors before code generation proceeds\n");

    printf("\n\n\n");
        printf("********************************\n"
               "*    Semantic Check Done!      *\n"
               "********************************\n");

    //Do cleanup
    terminateSymbolTable(&symTables[0]);
    traverseTree(ASTROOT,true,false,0);
    //We should have our tree by this point
    return parseResult;
}
