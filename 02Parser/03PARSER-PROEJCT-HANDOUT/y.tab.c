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
#line 1 "standard-pascal.y"

/*
 * grammar.y
 *
 * Pascal grammar in Yacc format, based originally on BNF given
 * in "Standard Pascal -- User Reference Manual", by Doug Cooper.
 * This in turn is the BNF given by the ANSI and ISO Pascal standards,
 * and so, is PUBLIC DOMAIN. The grammar is for ISO Level 0 Pascal.
 * The grammar has been massaged somewhat to make it LALR, and added
 * the following extensions.
 *
 * constant expressions
 * otherwise statement in a case
 * productions to correctly match else's with if's
 * beginnings of a separate compilation facility
 */


#line 89 "y.tab.c"

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
    AND = 258,
    ARRAY = 259,
    ASSIGNMENT = 260,
    CASE = 261,
    CHARACTER_STRING = 262,
    COLON = 263,
    COMMA = 264,
    CONST = 265,
    DIGSEQ = 266,
    DIV = 267,
    DO = 268,
    DOT = 269,
    DOTDOT = 270,
    DOWNTO = 271,
    ELSE = 272,
    END = 273,
    EQUAL = 274,
    EXTERNAL = 275,
    FOR = 276,
    FORWARD = 277,
    FUNCTION = 278,
    GE = 279,
    GOTO = 280,
    GT = 281,
    IDENTIFIER = 282,
    IF = 283,
    IN = 284,
    LABEL = 285,
    LBRAC = 286,
    LE = 287,
    LPAREN = 288,
    LT = 289,
    MINUS = 290,
    MOD = 291,
    NIL = 292,
    NOT = 293,
    NOTEQUAL = 294,
    OF = 295,
    OR = 296,
    OTHERWISE = 297,
    PACKED = 298,
    PBEGIN = 299,
    PFILE = 300,
    PLUS = 301,
    PROCEDURE = 302,
    PROGRAM = 303,
    RBRAC = 304,
    REALNUMBER = 305,
    RECORD = 306,
    REPEAT = 307,
    RPAREN = 308,
    SEMICOLON = 309,
    SET = 310,
    SLASH = 311,
    STAR = 312,
    STARSTAR = 313,
    THEN = 314,
    TO = 315,
    TYPE = 316,
    UNTIL = 317,
    UPARROW = 318,
    VAR = 319,
    WHILE = 320,
    WITH = 321
  };
#endif
/* Tokens.  */
#define AND 258
#define ARRAY 259
#define ASSIGNMENT 260
#define CASE 261
#define CHARACTER_STRING 262
#define COLON 263
#define COMMA 264
#define CONST 265
#define DIGSEQ 266
#define DIV 267
#define DO 268
#define DOT 269
#define DOTDOT 270
#define DOWNTO 271
#define ELSE 272
#define END 273
#define EQUAL 274
#define EXTERNAL 275
#define FOR 276
#define FORWARD 277
#define FUNCTION 278
#define GE 279
#define GOTO 280
#define GT 281
#define IDENTIFIER 282
#define IF 283
#define IN 284
#define LABEL 285
#define LBRAC 286
#define LE 287
#define LPAREN 288
#define LT 289
#define MINUS 290
#define MOD 291
#define NIL 292
#define NOT 293
#define NOTEQUAL 294
#define OF 295
#define OR 296
#define OTHERWISE 297
#define PACKED 298
#define PBEGIN 299
#define PFILE 300
#define PLUS 301
#define PROCEDURE 302
#define PROGRAM 303
#define RBRAC 304
#define REALNUMBER 305
#define RECORD 306
#define REPEAT 307
#define RPAREN 308
#define SEMICOLON 309
#define SET 310
#define SLASH 311
#define STAR 312
#define STARSTAR 313
#define THEN 314
#define TO 315
#define TYPE 316
#define UNTIL 317
#define UPARROW 318
#define VAR 319
#define WHILE 320
#define WITH 321

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   501

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  135
/* YYNRULES -- Number of rules.  */
#define YYNRULES  254
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  410

#define YYUNDEFTOK  2
#define YYMAXUTOK   321

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    29,    32,    35,    36,    39,    40,    43,
      51,    57,    58,    61,    62,    65,    68,    69,    72,    73,
      76,    81,    82,    85,    86,    89,    90,    93,    94,    97,
      98,   101,   102,   103,   104,   107,   108,   109,   112,   113,
     116,   117,   118,   121,   122,   125,   126,   129,   132,   133,
     136,   137,   138,   141,   142,   145,   148,   151,   152,   155,
     156,   157,   158,   161,   164,   165,   168,   170,   171,   174,
     176,   177,   178,   181,   182,   185,   188,   189,   190,   193,
     194,   197,   198,   201,   202,   204,   207,   208,   211,   212,
     215,   217,   219,   222,   224,   227,   230,   232,   233,   237,
     238,   241,   245,   246,   250,   251,   254,   255,   258,   259,
     262,   263,   266,   267,   270,   272,   273,   276,   277,   278,
     279,   282,   285,   288,   290,   292,   294,   296,   297,   298,
     301,   302,   305,   307,   309,   311,   313,   315,   316,   319,
     320,   323,   324,   327,   328,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   344,   345,   346,   347,
     350,   353,   356,   359,   363,   367,   370,   373,   374,   377,
     381,   384,   385,   386,   387,   390,   393,   394,   397,   399,
     402,   403,   406,   408,   409,   417,   418,   419,   422,   425,
     426,   427,   429,   433,   435,   436,   439,   442,   443,   446,
     448,   450,   451,   454,   456,   457,   460,   462,   463,   466,
     467,   470,   471,   474,   475,   478,   479,   482,   483,   484,
     485,   486,   487,   490,   491,   492,   495,   495,   497,   500,
     504,   507,   508,   511,   512,   515,   516,   519,   520,   521,
     524,   525,   526,   527,   528,   531,   532,   533,   534,   535,
     536,   537,   540,   543,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "ARRAY", "ASSIGNMENT", "CASE",
  "CHARACTER_STRING", "COLON", "COMMA", "CONST", "DIGSEQ", "DIV", "DO",
  "DOT", "DOTDOT", "DOWNTO", "ELSE", "END", "EQUAL", "EXTERNAL", "FOR",
  "FORWARD", "FUNCTION", "GE", "GOTO", "GT", "IDENTIFIER", "IF", "IN",
  "LABEL", "LBRAC", "LE", "LPAREN", "LT", "MINUS", "MOD", "NIL", "NOT",
  "NOTEQUAL", "OF", "OR", "OTHERWISE", "PACKED", "PBEGIN", "PFILE", "PLUS",
  "PROCEDURE", "PROGRAM", "RBRAC", "REALNUMBER", "RECORD", "REPEAT",
  "RPAREN", "SEMICOLON", "SET", "SLASH", "STAR", "STARSTAR", "THEN", "TO",
  "TYPE", "UNTIL", "UPARROW", "VAR", "WHILE", "WITH", "$accept", "file",
  "program", "program_heading", "identifier_list", "block", "module",
  "label_declaration_part", "label_list", "label",
  "constant_definition_part", "constant_list", "constant_definition",
  "cexpression", "csimple_expression", "cterm", "cfactor",
  "cexponentiation", "cprimary", "constant", "sign", "non_string",
  "type_definition_part", "type_definition_list", "type_definition",
  "type_denoter", "new_type", "new_ordinal_type", "enumerated_type",
  "subrange_type", "new_structured_type", "structured_type", "array_type",
  "index_list", "index_type", "ordinal_type", "component_type",
  "record_type", "record_section_list", "record_section", "variant_part",
  "variant_selector", "variant_list", "variant", "case_constant_list",
  "case_constant", "tag_field", "tag_type", "set_type", "base_type",
  "file_type", "new_pointer_type", "domain_type",
  "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "procedure_and_function_declaration_part",
  "proc_or_func_declaration_list", "proc_or_func_declaration",
  "procedure_declaration", "procedure_heading", "directive",
  "formal_parameter_list", "formal_parameter_section_list",
  "formal_parameter_section", "value_parameter_specification",
  "variable_parameter_specification", "procedural_parameter_specification",
  "functional_parameter_specification", "procedure_identification",
  "procedure_block", "function_declaration", "function_heading",
  "result_type", "function_identification", "function_block",
  "statement_part", "compound_statement", "statement_sequence",
  "statement", "open_statement", "closed_statement",
  "non_labeled_closed_statement", "non_labeled_open_statement",
  "repeat_statement", "open_while_statement", "closed_while_statement",
  "open_for_statement", "closed_for_statement", "open_with_statement",
  "closed_with_statement", "open_if_statement", "closed_if_statement",
  "assignment_statement", "variable_access", "indexed_variable",
  "index_expression_list", "index_expression", "field_designator",
  "procedure_statement", "params", "actual_parameter_list",
  "actual_parameter", "goto_statement", "case_statement", "case_index",
  "case_list_element_list", "case_list_element", "otherwisepart",
  "control_variable", "initial_value", "direction", "final_value",
  "record_variable_list", "boolean_expression", "expression",
  "simple_expression", "term", "factor", "exponentiation", "primary",
  "unsigned_constant", "unsigned_number", "unsigned_integer",
  "unsigned_real", "function_designator", "set_constructor",
  "member_designator_list", "member_designator", "addop", "mulop", "relop",
  "identifier", "semicolon", "comma", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -307

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-307)))

#define YYTABLE_NINF -182

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,     9,     9,    43,  -307,    -6,  -307,     2,  -307,     9,
    -307,    56,    22,  -307,  -307,   115,     9,    94,  -307,   237,
       9,   177,   183,   191,     9,  -307,   172,     9,    24,  -307,
    -307,   237,  -307,  -307,   437,  -307,  -307,    -6,   344,   127,
    -307,  -307,   148,   237,  -307,  -307,  -307,  -307,  -307,    25,
    -307,  -307,    20,  -307,  -307,     2,  -307,   391,   105,    -6,
    -307,     9,     9,  -307,    -6,  -307,  -307,    -6,   188,  -307,
      -6,    -6,   194,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,   237,   237,  -307,  -307,  -307,
    -307,  -307,   237,   437,  -307,  -307,  -307,     9,  -307,   177,
      94,   203,  -307,  -307,     9,   124,   196,  -307,   102,   215,
       9,   256,   193,  -307,    -6,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,   258,   391,     9,   108,
    -307,    24,   236,   162,  -307,   236,   115,  -307,   127,   170,
    -307,  -307,  -307,  -307,    24,   311,    35,  -307,   391,     9,
     112,    92,  -307,   261,   311,  -307,  -307,   230,  -307,  -307,
    -307,  -307,  -307,     9,   276,  -307,  -307,  -307,  -307,  -307,
    -307,     9,     9,   134,  -307,   114,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,   245,  -307,    37,  -307,
    -307,   258,  -307,  -307,  -307,   255,   289,  -307,   262,   391,
    -307,   102,  -307,  -307,  -307,  -307,  -307,  -307,     9,   108,
     231,     9,  -307,   162,   328,  -307,  -307,   263,   311,   230,
       9,  -307,  -307,   290,  -307,     9,  -307,  -307,   451,     9,
     177,   451,   328,   451,     9,   293,  -307,   122,  -307,  -307,
    -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,   119,  -307,  -307,  -307,  -307,  -307,   118,
     391,  -307,   298,    -6,  -307,   269,  -307,  -307,  -307,  -307,
    -307,   422,   451,   283,   451,     7,   275,  -307,   344,   127,
    -307,  -307,   265,  -307,  -307,  -307,   286,   320,  -307,  -307,
     272,  -307,    -3,   319,     7,    40,  -307,   202,  -307,   328,
     451,     9,   451,  -307,   451,  -307,  -307,   230,   230,   302,
     230,  -307,  -307,   125,   321,   284,  -307,  -307,   230,   451,
     451,   451,   283,  -307,   451,   328,   451,   328,   328,     9,
    -307,  -307,  -307,  -307,  -307,   128,  -307,  -307,    36,  -307,
     337,  -307,  -307,   102,  -307,  -307,   451,   451,  -307,   273,
     168,  -307,   127,   170,  -307,  -307,    38,  -307,  -307,   330,
    -307,  -307,  -307,  -307,  -307,     7,  -307,   451,  -307,   451,
     451,   238,   297,   321,  -307,   328,  -307,   334,   364,  -307,
    -307,   451,   328,  -307,  -307,   346,  -307,   102,  -307,  -307,
    -307,   351,  -307,   328,   352,  -307,  -307,  -307,   451,   313,
    -307,   181,   328,  -307,  -307,  -307,   349,  -307,  -307,  -307
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,     0,     0,     2,     0,     3,    44,   252,    16,
      19,     0,     5,     1,   253,    12,     0,    98,    18,     0,
       0,     0,     0,    17,    43,    46,     0,     0,   103,   224,
     228,     0,    39,   225,     0,    38,   229,     0,    21,    23,
      25,    28,    29,     0,    33,   223,   226,   227,    31,     0,
       8,    15,     0,    14,     4,    44,    45,     0,     0,     0,
     100,     0,     0,    10,     0,   105,   106,     0,   110,   107,
       0,     0,     0,    34,    20,   245,   250,   248,   251,   249,
     247,   238,   246,   239,   237,     0,     0,   244,   242,   243,
     241,   240,     0,     0,    27,   254,     6,     0,    11,     0,
      98,     0,    37,    40,     0,     0,     0,    42,    78,     0,
       0,     0,     0,    35,     0,    49,    50,    53,    54,    51,
      57,    59,    60,    61,    62,    52,    48,     0,    97,   133,
     125,   102,    12,     0,   111,    12,    12,    32,    24,    22,
      26,    30,     7,    13,   103,     0,     0,    58,     0,     0,
       0,     0,    74,     0,     0,    95,    96,     0,    36,    41,
      47,   101,    99,     0,     0,   104,   113,   112,   126,   108,
     109,     0,     0,     0,   123,     0,   116,   117,   118,   119,
     120,   124,   134,   127,   129,   128,     0,    67,     0,    65,
      66,    68,    55,    69,    94,     0,     0,    80,    90,     0,
      70,    78,    72,    93,    92,    56,   130,   132,     0,     0,
       0,     0,   114,     0,   155,     9,   135,     0,     0,     0,
       0,    75,    73,     0,   131,     0,   121,   115,     0,     0,
       0,     0,   155,     0,     0,     0,   148,     0,   138,   139,
     140,   144,   142,   150,   158,   153,   159,   154,   156,   151,
     157,   152,   145,     0,   172,   173,   146,   147,   149,   171,
       0,    64,    88,    77,    82,     0,    87,    79,    91,    71,
     122,     0,     0,     0,     0,   217,     0,   193,   207,   209,
     211,   214,   215,   218,   219,   220,   171,     0,   199,   188,
       0,   206,     0,     0,   205,     0,   171,   155,   136,   155,
       0,     0,     0,   174,     0,   180,    63,     0,    76,     0,
       0,   232,   236,     0,   234,     0,   222,   213,     0,     0,
       0,     0,     0,   230,     0,   155,     0,   155,   155,     0,
     143,   141,   137,   170,   179,     0,   177,   178,     0,   184,
     185,    89,    81,    78,    86,   231,     0,     0,   221,     0,
       0,   195,   210,   208,   212,   216,     0,   200,   167,   140,
     160,   161,   162,   165,   166,   204,   175,     0,   182,     0,
       0,     0,     0,   233,   235,   155,   189,   253,     0,   202,
     201,     0,   155,   176,   183,   186,    83,    78,    85,   196,
     190,   197,   194,   155,     0,   203,   168,   169,     0,     0,
     198,     0,   155,   187,    84,   191,     0,   163,   164,   192
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -307,  -307,  -307,  -307,   -11,    -9,  -307,  -307,  -307,   -16,
     341,  -307,   375,   356,   303,   312,   -19,   295,   362,  -153,
      33,   288,   348,  -307,   383,   -47,  -307,   -87,  -307,  -307,
    -307,   304,  -307,  -307,   190,   259,   152,  -307,    72,  -194,
    -184,  -307,  -307,   109,  -306,   106,  -307,   199,  -307,  -307,
    -307,  -307,  -307,   322,  -307,   292,   277,  -307,   299,  -307,
    -119,   296,   355,  -307,   222,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -113,   224,  -307,   307,  -307,   252,   208,  -288,
    -287,  -300,   150,   153,  -307,  -307,  -307,  -307,  -307,  -307,
    -307,  -307,  -307,  -307,  -133,  -307,  -307,    78,  -307,  -307,
     165,  -307,    83,  -307,  -307,  -307,  -307,    85,  -307,  -307,
    -307,  -307,  -307,  -307,  -220,    58,   141,   146,  -242,   144,
     200,   219,  -307,  -307,  -307,  -307,  -307,  -307,   121,  -256,
    -248,   198,    -1,    -2,   -50
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   150,   182,     6,    23,    52,   235,
       7,     9,    10,    37,    38,    39,    40,    41,    42,   111,
     274,   113,    17,    24,    25,   193,   115,   116,   117,   118,
     119,   120,   121,   188,   189,   190,   194,   122,   151,   152,
     153,   195,   263,   264,   265,   266,   196,   197,   123,   204,
     124,   125,   155,    28,    59,    60,    63,    64,    65,    66,
      67,   169,   164,   175,   176,   177,   178,   179,   180,    68,
     170,    69,    70,   206,    71,   184,   215,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   275,   254,   335,   336,   255,   256,
     305,   338,   339,   257,   258,   276,   350,   351,   393,   287,
     356,   381,   394,   295,   290,   291,   278,   279,   280,   281,
     282,   283,    45,    46,    47,   284,   285,   313,   314,    85,
      92,    86,   286,   299,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,    12,    99,    15,   205,    53,    22,   222,    11,    49,
     114,   332,   349,   293,   174,    26,    58,   223,    48,    50,
     181,   301,   319,    26,    94,   359,    50,   362,   364,    95,
      48,   321,   317,    48,    95,    74,     8,   358,   302,     1,
     361,   363,    48,    13,    95,    95,    95,    61,    14,    95,
      98,    14,    43,   328,   379,    20,   126,   128,   187,   326,
     129,   130,   131,    16,    43,   132,   262,   187,   135,   136,
     303,    62,   349,   140,    14,    19,    43,     2,    96,   354,
     161,   253,   397,   143,    48,    48,   217,   389,   192,   368,
     112,    48,    48,   146,   174,   396,   142,   319,   380,   253,
     181,   294,   408,    50,   321,   401,   360,    50,   149,   156,
     200,   159,   160,   127,    95,   407,   163,    58,    43,    43,
     199,    95,   173,   168,   300,    43,   126,    50,   101,     8,
      87,   187,    50,   301,    95,  -181,  -181,    95,   218,    88,
     298,   133,   211,    95,   191,    21,    14,   126,   198,   201,
     302,   304,   221,   191,   341,   262,   159,   262,    27,   372,
     112,   210,   207,    89,   253,   262,   253,   212,    14,   106,
     209,    50,  -181,   213,   345,   108,    14,   366,   112,   109,
    -181,   112,   303,    90,    91,   171,   376,   112,    51,     8,
     112,    57,   253,   222,   253,   253,   365,    54,   126,   405,
      50,     1,   173,   399,   103,    81,    93,   207,   228,    62,
     226,    83,    50,   259,   289,   310,    84,   191,   159,   268,
       8,   133,   377,   229,   270,   262,   172,   230,   288,     8,
     231,   259,   112,   296,   145,   406,   148,   102,    44,   225,
      95,   103,   253,   107,    29,   329,   214,   137,    30,   253,
      44,   112,   112,    44,   232,   154,   166,     8,   167,   126,
     253,   308,    44,   346,     8,    32,    21,   233,   234,   253,
      31,   157,    32,   -41,    33,    34,    35,   309,    95,   202,
     107,   375,    95,    35,   208,   367,   277,    36,   369,   214,
      29,   386,    14,   112,    30,   219,   259,   220,   259,   310,
     334,   297,   -91,   260,    44,    44,   159,   159,   269,   159,
       8,    44,    44,   307,   271,   318,   272,   159,   102,   304,
      33,   273,   103,   322,   259,   324,   259,   259,   296,   312,
     315,   325,   327,    36,   228,   343,   347,   348,     8,    51,
     112,   112,    50,   112,   104,   370,    32,   382,   378,   229,
     388,   112,   390,   230,   398,     8,   231,    35,   333,   400,
     337,   107,   340,    75,    55,   402,   404,   409,    76,   387,
      77,   102,   214,    78,   259,   103,    79,   159,    80,    81,
     232,   259,   357,    82,    18,    83,    50,    72,   141,   139,
      84,     8,   259,   233,   234,   101,    73,   138,   102,    32,
     158,   259,   103,   100,   312,   374,   391,    56,   261,   147,
      35,   112,   306,   203,   107,   371,   344,   342,     8,   267,
     162,   186,   144,   134,   104,   337,    32,   340,   385,    29,
     165,   183,   224,    30,   105,   227,   106,    35,   216,   395,
     292,   107,   108,   185,    29,   383,   109,   330,    30,     8,
     331,   323,   384,   271,   110,   272,   403,    32,    29,    33,
     273,   353,    30,   392,     8,   352,   355,   373,    35,     0,
      31,   311,    36,   316,    33,    34,   320,     0,     8,     0,
       0,     0,   271,     0,   272,     0,    32,    36,    33,   273,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,    36
};

static const yytype_int16 yycheck[] =
{
       1,     2,    52,     5,   157,    21,    15,   201,     9,    20,
      57,   299,   318,   233,   133,    16,    27,   201,    19,    20,
     133,    14,   278,    24,    43,   325,    27,   327,   328,     9,
      31,   279,   274,    34,     9,    37,    27,   325,    31,    10,
     327,   328,    43,     0,     9,     9,     9,    23,    54,     9,
      52,    54,    19,    13,    16,    33,    57,    59,   145,    62,
      61,    62,    64,    61,    31,    67,   219,   154,    70,    71,
      63,    47,   378,    92,    54,    19,    43,    48,    53,   321,
     127,   214,   382,    99,    85,    86,    49,   375,    53,    53,
      57,    92,    93,   104,   213,   382,    97,   353,    60,   232,
     213,   234,   402,   104,   352,   393,   326,   108,     6,   110,
      18,   112,   114,     8,     9,   402,     8,   128,    85,    86,
       8,     9,   133,   132,     5,    92,   127,   128,     4,    27,
       3,   218,   133,    14,     9,    17,    18,     9,   188,    12,
      18,    33,     8,     9,   145,    30,    54,   148,   149,   151,
      31,    33,   199,   154,   307,   308,   157,   310,    64,   343,
     127,   172,   163,    36,   297,   318,   299,    53,    54,    45,
     171,   172,    54,   175,    49,    51,    54,    49,   145,    55,
      62,   148,    63,    56,    57,    23,    18,   154,    11,    27,
     157,    19,   325,   387,   327,   328,   329,    14,   199,    18,
     201,    10,   213,   387,    11,    35,    58,   208,     6,    47,
     211,    41,   213,   214,   230,   265,    46,   218,   219,   220,
      27,    33,    54,    21,   225,   378,    64,    25,   229,    27,
      28,   232,   199,   234,    31,    54,    40,     7,    19,     8,
       9,    11,   375,    50,     7,   295,    44,    53,    11,   382,
      31,   218,   219,    34,    52,    40,    20,    27,    22,   260,
     393,   263,    43,   313,    27,    35,    30,    65,    66,   402,
      33,    15,    35,    15,    37,    38,    46,     8,     9,    18,
      50,     8,     9,    46,     8,   335,   228,    50,   338,    44,
       7,    53,    54,   260,    11,    40,   297,     8,   299,   349,
     301,     8,    40,    40,    85,    86,   307,   308,    18,   310,
      27,    92,    93,    15,    31,    40,    33,   318,     7,    33,
      37,    38,    11,    58,   325,     5,   327,   328,   329,   271,
     272,    59,    13,    50,     6,    33,    15,    53,    27,    11,
     307,   308,   343,   310,    33,     8,    35,    17,   350,    21,
      53,   318,    18,    25,     8,    27,    28,    46,   300,     8,
     302,    50,   304,    19,    23,    13,    53,    18,    24,   371,
      26,     7,    44,    29,   375,    11,    32,   378,    34,    35,
      52,   382,   324,    39,     9,    41,   387,    31,    93,    86,
      46,    27,   393,    65,    66,     4,    34,    85,     7,    35,
     112,   402,    11,    55,   346,   347,    42,    24,   218,   105,
      46,   378,   260,   154,    50,   343,   310,   308,    27,   220,
     128,   144,   100,    68,    33,   367,    35,   369,   370,     7,
     131,   135,   208,    11,    43,   213,    45,    46,   186,   381,
     232,    50,    51,   136,     7,   367,    55,   297,    11,    27,
     297,   286,   369,    31,    63,    33,   398,    35,     7,    37,
      38,   320,    11,   378,    27,   319,   322,   346,    46,    -1,
      33,    49,    50,   273,    37,    38,   278,    -1,    27,    -1,
      -1,    -1,    31,    -1,    33,    -1,    35,    50,    37,    38,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    48,    68,    69,    70,    73,    77,    27,    78,
      79,   199,   199,     0,    54,   200,    61,    89,    79,    19,
      33,    30,    72,    74,    90,    91,   199,    64,   120,     7,
      11,    33,    35,    37,    38,    46,    50,    80,    81,    82,
      83,    84,    85,    87,   188,   189,   190,   191,   199,    71,
     199,    11,    75,    76,    14,    77,    91,    19,    71,   121,
     122,    23,    47,   123,   124,   125,   126,   127,   136,   138,
     139,   141,    80,    85,   200,    19,    24,    26,    29,    32,
      34,    35,    39,    41,    46,   196,   198,     3,    12,    36,
      56,    57,   197,    58,    83,     9,    53,   201,   200,   201,
      89,     4,     7,    11,    33,    43,    45,    50,    51,    55,
      63,    86,    87,    88,    92,    93,    94,    95,    96,    97,
      98,    99,   104,   115,   117,   118,   199,     8,   200,   199,
     199,   200,   200,    33,   129,   200,   200,    53,    82,    81,
      83,    84,   199,    76,   120,    31,    71,    98,    40,     6,
      71,   105,   106,   107,    40,   119,   199,    15,    88,   199,
     200,    92,   122,     8,   129,   125,    20,    22,    72,   128,
     137,    23,    64,    71,   127,   130,   131,   132,   133,   134,
     135,   139,    72,   128,   142,   142,   123,    94,   100,   101,
     102,   199,    53,    92,   103,   108,   113,   114,   199,     8,
      18,   200,    18,   102,   116,    86,   140,   199,     8,   199,
      71,     8,    53,   200,    44,   143,   144,    49,   201,    40,
       8,    92,   106,   107,   140,     8,   199,   131,     6,    21,
      25,    28,    52,    65,    66,    76,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   165,   166,   170,   171,   199,
      40,   101,    86,   109,   110,   111,   112,   114,   199,    18,
     199,    31,    33,    38,    87,   161,   172,   182,   183,   184,
     185,   186,   187,   188,   192,   193,   199,   176,   199,    76,
     181,   182,   145,   181,   161,   180,   199,     8,    18,   200,
       5,    14,    31,    63,    33,   167,   103,    15,   200,     8,
     201,    49,   182,   194,   195,   182,   187,   185,    40,   196,
     198,   197,    58,   167,     5,    59,    62,    13,    13,   201,
     149,   150,   146,   182,   199,   163,   164,   182,   168,   169,
     182,    86,   110,    33,   112,    49,   201,    15,    53,   111,
     173,   174,   184,   183,   185,   186,   177,   182,   146,   148,
     181,   147,   148,   147,   148,   161,    49,   201,    53,   201,
       8,   105,   107,   195,   182,     8,    18,    54,   200,    16,
      60,   178,    17,   164,   169,   182,    53,   200,    53,   146,
      18,    42,   174,   175,   179,   182,   147,   148,     8,   107,
       8,   146,    13,   182,    53,    18,    54,   147,   148,    18
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      73,    74,    74,    75,    75,    76,    77,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    90,    91,    92,    92,
      93,    93,    93,    94,    94,    95,    96,    97,    97,    98,
      98,    98,    98,    99,   100,   100,   101,   102,   102,   103,
     104,   104,   104,   105,   105,   106,   107,   107,   107,   108,
     108,   109,   109,   110,   110,   110,   111,   111,   112,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   130,   130,   131,   131,   131,
     131,   132,   133,   134,   135,   136,   137,   138,   138,   138,
     139,   139,   140,   141,   142,   143,   144,   145,   145,   146,
     146,   147,   147,   148,   148,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   150,   150,   150,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   158,   159,
     160,   161,   161,   161,   161,   162,   163,   163,   164,   165,
     166,   166,   167,   168,   168,   169,   169,   169,   170,   171,
     171,   171,   171,   172,   173,   173,   174,   175,   175,   176,
     177,   178,   178,   179,   180,   180,   181,   182,   182,   183,
     183,   184,   184,   185,   185,   186,   186,   187,   187,   187,
     187,   187,   187,   188,   188,   188,   189,   189,   190,   191,
     192,   193,   193,   194,   194,   195,   195,   196,   196,   196,
     197,   197,   197,   197,   197,   198,   198,   198,   198,   198,
     198,   198,   199,   200,   201
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     4,     2,     5,     3,     1,     6,
       4,     3,     0,     3,     1,     1,     2,     0,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     2,     1,     1,
       3,     1,     3,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     0,     2,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     2,     1,
       1,     1,     1,     6,     3,     1,     1,     1,     1,     1,
       3,     5,     3,     3,     1,     3,     5,     4,     0,     3,
       1,     3,     1,     5,     7,     5,     3,     1,     1,     3,
       1,     1,     3,     1,     3,     2,     1,     3,     0,     3,
       1,     3,     2,     0,     3,     1,     1,     1,     3,     3,
       1,     2,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     3,     4,     1,     1,     2,     1,     3,     3,     3,
       4,     5,     1,     2,     1,     1,     3,     3,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       4,     4,     4,     8,     8,     4,     4,     4,     6,     6,
       3,     1,     1,     1,     2,     4,     3,     1,     1,     3,
       2,     1,     3,     3,     1,     1,     3,     5,     2,     5,
       6,     8,     9,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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

#line 1719 "y.tab.c"

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
