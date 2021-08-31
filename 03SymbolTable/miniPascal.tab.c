/* A Bison parser, made by GNU Bison 3.4.2.  */

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
#define YYBISON_VERSION "3.4.2"

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

#include "ast.h"
#include "symboltable.h"
#include "semantics.h"

#ifdef DEBUG
#define Logg(s) printf("%s", s)
#else
#define Logg(s)
#endif

Node* ASTROOT;//Just declaring it atm.

extern const char * yytext;
extern const int line_no;
void yyerror(const char * charo){
    //fprintf(stderr,"There was an error on line : %d\n",line_no);
    fprintf(stderr,"line %d error token: %s\n",line_no,yytext);
    exit(-1);
}

#line 96 "miniPascal.tab.c"

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
#ifndef YY_YY_MINIPASCAL_TAB_H_INCLUDED
# define YY_YY_MINIPASCAL_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 27 "miniPascal.y"

    struct Node* node;
    //int num;//Pendejo estoy puede ser both real o stirng
    char * num;
    double real;
    char character;
    char * string;

#line 195 "miniPascal.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINIPASCAL_TAB_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   129

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

#define YYUNDEFTOK  2
#define YYMAXUTOK   301

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    79,    87,    96,   106,   116,   120,   136,
     141,   145,   152,   158,   166,   182,   191,   200,   205,   209,
     221,   235,   236,   240,   249,   256,   261,   269,   275,   277,
     279,   286,   293,   299,   307,   315,   322,   327,   336,   341,
     349,   353,   357,   360,   362,   371,   373,   381,   385,   393,
     400,   408,   413,   418,   420,   427,   429,   433,   435,   439,
     444,   449,   454,   459,   464,   470,   478,   486
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
  "IDENTIFIER", "PLUS", "MINUS", "OR", "AND", "LESSTHAN", "LESSTHANEQ",
  "EQUALS", "GREATERTHANEQ", "GREATERTHAN", "NEQUALS", "MULT", "DIV",
  "$accept", "prog", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "arguments", "parameter_list", "optional_var",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "variable", "tail", "procedure_statement",
  "expression_list", "expression", "boolexpression", "simple_expression",
  "term", "factor", "addop", "mulop", "relop", "id", "num", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -88

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define YYTABLE_NINF -36

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,    -3,    34,   -88,    30,   -88,    -3,    37,   -88,    32,
      -3,   -88,   -88,    35,    -3,    76,    18,    -3,    -3,    24,
      68,   -88,    89,     2,    93,    93,    20,    20,   -88,    78,
      94,   -88,    80,   -88,    15,   -88,    35,   -88,    87,   -88,
     -88,   -88,    96,   -88,    95,    97,    99,    20,    20,   -88,
     -88,   -88,   -88,    83,    22,    39,    40,   -88,    52,    21,
     -88,    77,   -88,    24,    20,    20,    20,   -88,    76,    52,
     -88,   -88,   103,    -3,     6,   -88,   104,   -88,    24,    20,
      20,   -88,   -88,   -88,   -88,   -88,   -88,    20,    20,   -88,
     -88,    20,   -88,    20,   -88,    24,   -88,   -88,    54,   -88,
      98,   -88,    82,   -88,    59,   106,   -88,    90,   -88,   -88,
      40,    57,   -88,    63,   -88,   -88,    20,   101,    52,     2,
     -88,    24,   -88,   -88,   -88,   102,   110,   -88,   105,    95,
       2,   -88,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    65,     0,     1,     0,     0,     3,     0,
       0,     6,     4,    13,     0,     0,     0,     0,     0,    32,
       0,     6,     0,     0,    18,    18,     0,     0,    29,     0,
      24,    25,     0,    28,    36,    12,    13,     2,     0,     9,
      10,    11,     0,     7,    22,     0,     0,     0,     0,    66,
      52,    55,    56,     0,    40,    43,    45,    47,     0,    35,
      51,     0,    23,    32,     0,     0,     0,    33,     0,     0,
       5,    21,     0,     0,     0,    16,     0,    54,    32,     0,
       0,    59,    62,    61,    63,    60,    64,     0,     0,    57,
      58,     0,    67,     0,    49,    32,    26,    27,     0,    38,
       0,    14,     0,    17,     0,     0,    53,     0,    42,    41,
      46,    44,    48,     0,    31,    37,     0,    35,     0,     0,
      15,    32,    50,    39,    34,     0,    19,    30,     0,    22,
       0,    20,     8
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    -8,   107,   -87,    45,    86,   -88,   -88,   100,
      -6,   -88,   -11,   -88,   -88,   -53,   -88,   -51,   -88,    31,
     -25,    10,    38,    42,   -41,   -44,   -88,   -88,    -1,   -55
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    13,    42,    43,    15,    20,    21,    45,
      72,    73,    28,    29,    30,    31,    32,    67,    33,    98,
      99,    54,    55,    56,    57,    58,    91,    88,    59,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    53,    61,    92,    22,     8,    16,    77,    94,    12,
      96,    87,     1,     8,   102,    38,    24,    25,    34,    39,
      40,    65,    76,    39,    40,   107,    47,    93,    10,    66,
      23,     3,   126,    41,     5,    66,     6,    41,   -35,    97,
      11,   100,   114,   132,     9,    19,    14,    10,    26,    48,
     112,    27,    49,    50,     3,    51,    52,   101,     3,    79,
      80,   115,    34,   125,   116,   104,   124,    87,   127,    10,
     122,   119,     8,   116,    51,    52,    35,    34,    81,    82,
      83,    84,    85,    86,    49,    89,    90,    51,    52,   108,
     109,   123,    51,    52,    34,    17,    18,    19,    37,    44,
      62,    69,    63,    64,    70,    95,    71,    75,    78,    74,
     103,   106,   118,   117,   120,    66,   121,   128,   129,   105,
      34,   130,    68,   131,   113,    46,   111,     0,    36,   110
};

static const yytype_int16 yycheck[] =
{
       1,    26,    27,    58,    15,     6,    14,    48,    59,    10,
      63,    55,     4,    14,    69,    13,    17,    18,    19,    17,
      18,     6,    47,    17,    18,    78,     6,     6,    10,    14,
      12,    34,   119,    31,     0,    14,     6,    31,    23,    64,
       8,    66,    95,   130,     7,    21,    11,    10,    24,    29,
      91,    27,    32,    33,    34,    35,    36,    68,    34,    37,
      38,     7,    63,   118,    10,    73,   117,   111,   121,    10,
       7,    12,    73,    10,    35,    36,     8,    78,    39,    40,
      41,    42,    43,    44,    32,    45,    46,    35,    36,    79,
      80,   116,    35,    36,    95,    19,    20,    21,     9,     6,
      22,    14,     8,    23,     8,    28,    11,     8,    25,    12,
       7,     7,    30,    15,     8,    14,    26,    15,     8,    74,
     121,    16,    36,   129,    93,    25,    88,    -1,    21,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    48,    34,    75,     0,     6,    49,    75,     7,
      10,     8,    75,    50,    11,    53,    49,    19,    20,    21,
      54,    55,    59,    12,    75,    75,    24,    27,    59,    60,
      61,    62,    63,    65,    75,     8,    50,     9,    13,    17,
      18,    31,    51,    52,     6,    56,    56,     6,    29,    32,
      33,    35,    36,    67,    68,    69,    70,    71,    72,    75,
      76,    67,    22,     8,    23,     6,    14,    64,    53,    14,
       8,    11,    57,    58,    12,     8,    67,    71,    25,    37,
      38,    39,    40,    41,    42,    43,    44,    72,    74,    45,
      46,    73,    76,     6,    64,    28,    62,    67,    66,    67,
      67,    59,    76,     7,    49,    52,     7,    62,    68,    68,
      70,    69,    71,    66,    62,     7,    10,    15,    30,    12,
       8,    26,     7,    67,    64,    76,    51,    62,    15,     8,
      16,    57,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    52,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    74,    74,    74,    74,    75,    76,    76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     1,     3,     6,     0,     1,     8,     1,
       1,     1,     3,     0,     4,     6,     4,     3,     0,     4,
       6,     1,     0,     3,     1,     1,     3,     3,     1,     1,
       6,     4,     0,     2,     4,     0,     1,     4,     1,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     2,
       4,     1,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
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
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
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

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
#line 66 "miniPascal.y"
    {
        ASTROOT = makeNode(NODE_ROOT);
        (yyval.node) = ASTROOT;
            adoptChild((yyval.node),(yyvsp[-8].node));
            adoptChild((yyval.node),(yyvsp[-6].node));
            adoptChild((yyval.node),(yyvsp[-3].node));
            adoptChild((yyval.node),(yyvsp[-2].node));
            adoptChild((yyval.node),(yyvsp[-1].node));
        Logg("Parse Succesful\n");
        }
#line 1393 "miniPascal.tab.c"
    break;

  case 3:
#line 80 "miniPascal.y"
    {//Create first instance of identifier list
        Logg("Initializing Id\n");
        (yyval.node) = makeNode(NODE_ID_LIST);
        Logg("Done  Id\n");
        adoptChild((yyval.node),(yyvsp[0].node));
        Logg("Adopted  Id\n");
    }
#line 1405 "miniPascal.tab.c"
    break;

  case 4:
#line 88 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        //Logg("Adding To IdentifierList %s\n");
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1415 "miniPascal.tab.c"
    break;

  case 5:
#line 97 "miniPascal.y"
    {//DIVE
        //Copy from the previous node
        (yyval.node) = (yyvsp[-5].node);
        Node* thisDecl = makeNode(NODE_DECLARATIONS);
        adoptChild((yyval.node),thisDecl);
        adoptChild(thisDecl, (yyvsp[-3].node));
        adoptChild(thisDecl, (yyvsp[-1].node));
    }
#line 1428 "miniPascal.tab.c"
    break;

  case 6:
#line 106 "miniPascal.y"
    {//On empty rule create new NODE_ADD
    //IF we do not have this rulle then we are 
    //forcing every  program and eveyr subprogram to have declared at least one variable.
    //THis(having atleast one) of course is not necessary
    //DIVE
        (yyval.node) = makeNode(NODE_DECLARATIONS_ROOT);
        //No Children
    }
#line 1441 "miniPascal.tab.c"
    break;

  case 7:
#line 117 "miniPascal.y"
    {
     (yyval.node) = (yyvsp[0].node);
     }
#line 1449 "miniPascal.tab.c"
    break;

  case 8:
#line 121 "miniPascal.y"
    {//DEVI
       (yyval.node) = makeNode(NODE_TYPE_ARR);         
       (yyval.node)->lowerBound = (yyvsp[-5].node)->intVal;
       deleteNodeTree((yyvsp[-5].node));
       (yyval.node)->upperBound = (yyvsp[-3].node)->intVal;
       deleteNodeTree((yyvsp[-3].node));
       //
       (yyval.node)->typeRef = (yyvsp[0].node);//Leak Comes from here because we are not setting a ndoe as a child
       //TODO remove this as a child. We are only doing it here because our 
       //free algorithm causes memory leak otherwise. Make sure if you remove the
       //following line you have handled that.
       adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1467 "miniPascal.tab.c"
    break;

  case 9:
#line 137 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_TYPE_INT);
        (yyval.node)->typeRef = (yyval.node);//Reference  to itself so we know its a primitive type.
        }
#line 1476 "miniPascal.tab.c"
    break;

  case 10:
#line 141 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_TYPE_REAL);
        (yyval.node)->typeRef = (yyval.node);
        }
#line 1485 "miniPascal.tab.c"
    break;

  case 11:
#line 145 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_TYPE_STRINGCONST);
        (yyval.node)->typeRef = (yyval.node);
        }
#line 1494 "miniPascal.tab.c"
    break;

  case 12:
#line 153 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-2].node);//Keep Sending the root to the next subpdeclaration
        adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 1503 "miniPascal.tab.c"
    break;

  case 13:
#line 158 "miniPascal.y"
    {
    //DIVE
        (yyval.node) = makeNode(NODE_SUBPDECLARATIONS);
    }
#line 1512 "miniPascal.tab.c"
    break;

  case 14:
#line 170 "miniPascal.y"
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
#line 1527 "miniPascal.tab.c"
    break;

  case 15:
#line 183 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_FUNCTION); 
        //We could actually copy the id to the node str 
        //value itself but for sake of just makign it work ill leave it like that for now
        adoptChild((yyval.node),(yyvsp[-4].node));
        adoptChild((yyval.node),(yyvsp[-3].node));
        adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 1540 "miniPascal.tab.c"
    break;

  case 16:
#line 192 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_PROCEDURE);
        adoptChild((yyval.node),(yyvsp[-2].node));//Same here
        adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 1550 "miniPascal.tab.c"
    break;

  case 17:
#line 201 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);//Just pass it along
    }
#line 1558 "miniPascal.tab.c"
    break;

  case 18:
#line 205 "miniPascal.y"
    {(yyval.node) = makeNode(NODE_ARGUMENTS);}
#line 1564 "miniPascal.tab.c"
    break;

  case 19:
#line 210 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_ARGUMENTS);
        Node* argument = makeNode(NODE_ARGUMENT);

        adoptChild(argument,(yyvsp[-2].node));
        adoptChild(argument,(yyvsp[0].node));//Remove only when your freeing algorithm can handle it
        argument->typeRef = (yyvsp[0].node);
    

        adoptChild((yyval.node),argument);
    }
#line 1580 "miniPascal.tab.c"
    break;

  case 20:
#line 222 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        Node* argument = makeNode(NODE_ARGUMENT);

        adoptChild(argument,(yyvsp[-4].node));
        adoptChild(argument,(yyvsp[-2].node));//Remove only when your freeing algorithm can handle it
        argument->typeRef = (yyvsp[-2].node);

        adoptChild((yyval.node),argument);
    }
#line 1595 "miniPascal.tab.c"
    break;

  case 23:
#line 243 "miniPascal.y"
    {
               (yyval.node) = (yyvsp[-1].node);//TODO how should we use this for opening scopes
               }
#line 1603 "miniPascal.tab.c"
    break;

  case 24:
#line 250 "miniPascal.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 1611 "miniPascal.tab.c"
    break;

  case 25:
#line 257 "miniPascal.y"
    {//THere should be at least one statement
        (yyval.node) = makeNode(NODE_STATEMENT_LIST);
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1620 "miniPascal.tab.c"
    break;

  case 26:
#line 262 "miniPascal.y"
    {
            (yyval.node) = (yyvsp[-2].node);
            adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1629 "miniPascal.tab.c"
    break;

  case 27:
#line 270 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_ASSIGN_OP); 
        adoptChild((yyval.node),(yyvsp[-2].node));
        adoptChild((yyval.node),(yyvsp[0].node));//TODO DEVI Might want to denote that this expression belongs to the variable somehow
    }
#line 1639 "miniPascal.tab.c"
    break;

  case 28:
#line 276 "miniPascal.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1645 "miniPascal.tab.c"
    break;

  case 29:
#line 278 "miniPascal.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1651 "miniPascal.tab.c"
    break;

  case 30:
#line 280 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_IF_ELSE);
        adoptChild((yyval.node),(yyvsp[-4].node));
        adoptChild((yyval.node),(yyvsp[-2].node));
        adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1662 "miniPascal.tab.c"
    break;

  case 31:
#line 287 "miniPascal.y"
    {
       (yyval.node) = makeNode(NODE_WHILE); 
       adoptChild((yyval.node),(yyvsp[-2].node));
       adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1672 "miniPascal.tab.c"
    break;

  case 32:
#line 293 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_STMNT);
    }
#line 1680 "miniPascal.tab.c"
    break;

  case 33:
#line 300 "miniPascal.y"
    {
            (yyval.node) = makeNode(NODE_VARREF);
            adoptChild((yyval.node),(yyvsp[-1].node));
            adoptChild((yyval.node),(yyvsp[0].node));//This could be INVALID_VALUE which means it doesnt specify a subscript(because it doesnt have to).
         }
#line 1690 "miniPascal.tab.c"
    break;

  case 34:
#line 308 "miniPascal.y"
    {//Making sure recursivity is taken care of
        //Just do it always
        (yyvsp[0].node)->valValidity = VALID_VALUE;//Means we have found atleast a single expression thus we can have a vlid array
        (yyval.node) = (yyvsp[0].node);
        adoptChild((yyval.node),(yyvsp[-2].node));
    }
#line 1701 "miniPascal.tab.c"
    break;

  case 35:
#line 315 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_ARR_SUFFIXES);
        (yyval.node)->valValidity=INVALID_VALUE;
       }
#line 1710 "miniPascal.tab.c"
    break;

  case 36:
#line 323 "miniPascal.y"
    {//TODO DEVI
        (yyval.node) = makeNode(NODE_PROCEDURE_CALL);
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1719 "miniPascal.tab.c"
    break;

  case 37:
#line 328 "miniPascal.y"
    {
       (yyval.node) = makeNode(NODE_PROCEDURE_CALL);
       adoptChild((yyval.node),(yyvsp[-3].node));
       adoptChild((yyval.node),(yyvsp[-1].node));
    }
#line 1729 "miniPascal.tab.c"
    break;

  case 38:
#line 337 "miniPascal.y"
    {
        (yyval.node)  = makeNode(NODE_EXPR_LIST);
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1738 "miniPascal.tab.c"
    break;

  case 39:
#line 342 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        adoptChild((yyval.node),(yyvsp[0].node)); 
    }
#line 1747 "miniPascal.tab.c"
    break;

  case 40:
#line 350 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_EXPR);
        }
#line 1755 "miniPascal.tab.c"
    break;

  case 41:
#line 354 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_EXPR);
        }
#line 1763 "miniPascal.tab.c"
    break;

  case 43:
#line 361 "miniPascal.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1769 "miniPascal.tab.c"
    break;

  case 44:
#line 363 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        adoptChild((yyval.node),(yyvsp[-2].node));
        adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1779 "miniPascal.tab.c"
    break;

  case 45:
#line 372 "miniPascal.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1785 "miniPascal.tab.c"
    break;

  case 46:
#line 374 "miniPascal.y"
    {
       (yyval.node) = (yyvsp[-1].node); 
       adoptChild((yyval.node),(yyvsp[-2].node));
       adoptChild((yyval.node),(yyvsp[0].node));
    }
#line 1795 "miniPascal.tab.c"
    break;

  case 47:
#line 382 "miniPascal.y"
    {
     (yyval.node) = (yyvsp[0].node);
     }
#line 1803 "miniPascal.tab.c"
    break;

  case 48:
#line 386 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        adoptChild((yyval.node), (yyvsp[-2].node));
        adoptChild((yyval.node), (yyvsp[0].node));
    }
#line 1813 "miniPascal.tab.c"
    break;

  case 49:
#line 394 "miniPascal.y"
    {
       //Same as the one we did vefore 
        (yyval.node) = makeNode(NODE_VARREF);
        adoptChild((yyval.node),(yyvsp[-1].node));
        adoptChild((yyval.node),(yyvsp[0].node));//This could be INVALID_VALUE which means it doesnt specify a subscript(because it doesnt have to).
    }
#line 1824 "miniPascal.tab.c"
    break;

  case 50:
#line 401 "miniPascal.y"
    {
        {
            (yyval.node) =makeNode(NODE_FUNC_CALL);
            adoptChild((yyval.node),(yyvsp[-3].node));
            adoptChild((yyval.node),(yyvsp[-2].node));
        };
    }
#line 1836 "miniPascal.tab.c"
    break;

  case 51:
#line 409 "miniPascal.y"
    {
            (yyval.node) = (yyvsp[0].node);//Just pass it along
        }
#line 1844 "miniPascal.tab.c"
    break;

  case 52:
#line 414 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_TYPE_STRINGCONST); 
        copyStr((yyval.node),(yyvsp[0].string));
    }
#line 1853 "miniPascal.tab.c"
    break;

  case 53:
#line 419 "miniPascal.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 1859 "miniPascal.tab.c"
    break;

  case 54:
#line 421 "miniPascal.y"
    {
        (yyval.node) = makeNode(NODE_UNARY_NOT_OP);
        adoptChild((yyval.node),(yyvsp[0].node));
        }
#line 1868 "miniPascal.tab.c"
    break;

  case 55:
#line 428 "miniPascal.y"
    {(yyval.node) = makeNode(NODE_ADD);}
#line 1874 "miniPascal.tab.c"
    break;

  case 56:
#line 430 "miniPascal.y"
    {(yyval.node) = makeNode(NODE_SUB);}
#line 1880 "miniPascal.tab.c"
    break;

  case 57:
#line 434 "miniPascal.y"
    {(yyval.node) = makeNode(NODE_MUL);}
#line 1886 "miniPascal.tab.c"
    break;

  case 58:
#line 436 "miniPascal.y"
    {(yyval.node) = makeNode(NODE_DIV);}
#line 1892 "miniPascal.tab.c"
    break;

  case 59:
#line 440 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_RELOP);
      (yyval.node)->relop = NODE_OP_LESSTHAN;
      }
#line 1901 "miniPascal.tab.c"
    break;

  case 60:
#line 445 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_RELOP);
      (yyval.node)->relop = NODE_OP_GREATERTHAN;
      }
#line 1910 "miniPascal.tab.c"
    break;

  case 61:
#line 450 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_RELOP);
      (yyval.node)->relop = NODE_OP_EQUALS;
      }
#line 1919 "miniPascal.tab.c"
    break;

  case 62:
#line 455 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_RELOP);
      (yyval.node)->relop = NODE_OP_LESSTHANEQ;
      }
#line 1928 "miniPascal.tab.c"
    break;

  case 63:
#line 460 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_RELOP);
      (yyval.node)->relop = NODE_OP_GREATERTHANEQ;
      }
#line 1937 "miniPascal.tab.c"
    break;

  case 64:
#line 465 "miniPascal.y"
    {
      (yyval.node) = makeNode(NODE_RELOP);
      (yyval.node)->relop = NODE_OP_NEQUALS;
      }
#line 1946 "miniPascal.tab.c"
    break;

  case 65:
#line 471 "miniPascal.y"
    {
    (yyval.node) = makeNode(NODE_ID);
    copyStr((yyval.node),(yyvsp[0].string));
    printf("Confirming copied identifier : %s\n",(yyval.node)->stringVal);
}
#line 1956 "miniPascal.tab.c"
    break;

  case 66:
#line 479 "miniPascal.y"
    {
        printf("Incoming num token with value %d\n",(yyvsp[0].num));
        (yyval.node) = makeNode(NODE_NUM);
        (yyval.node)->intVal =  (yyvsp[0].num);//SUPER TODO deal with this
        printf("\tWe got a num node of : %d\n",(yyval.node)->intVal);
    }
#line 1967 "miniPascal.tab.c"
    break;

  case 67:
#line 487 "miniPascal.y"
    {
        (yyval.node) = (yyvsp[0].node);
        //$$->intVal = $2->intVal;
    /* TODO: We have to do a Unary Operation here */
    }
#line 1977 "miniPascal.tab.c"
    break;


#line 1981 "miniPascal.tab.c"

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
#line 493 "miniPascal.y"

//d
//int yywrap(){return 1;}
int main (int argc, char **argv){
    if(argc!= 2){
        fprintf(stderr,"Please Use File dir as argument\n");
        return -1;
    }
    FILE *fp = freopen(argv[1],"r",stdin);

    int parseResult = yyparse();

    traverseTree(ASTROOT,false,true,0);

    SymbolTable symTable;
    initializeSymbolTable(&symTable);
    buildTable(&symTable,ASTROOT);

    traverseTree(ASTROOT,true,false,0);
    //We should have our tree by this point
    if(parseResult==0)
        fprintf(stdout,"OK");
    return parseResult;
}
