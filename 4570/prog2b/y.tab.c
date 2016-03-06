/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     VAR = 259,
     COLON = 260,
     COMMA = 261,
     SEMI = 262,
     LPAR = 263,
     RPAR = 264,
     IF = 265,
     WHILE = 266,
     PROCEDURE = 267,
     BGN = 268,
     ELSE = 269,
     END = 270,
     DO_KEYWORD = 271,
     REPEAT = 272,
     UNTIL = 273,
     THEN = 274,
     ADD_OP = 275,
     MUL_OP = 276,
     REL_OP = 277,
     STRING = 278,
     FLOAT = 279,
     UNSIGNED_INT = 280,
     ASSIGN_OP = 281,
     PROGRAM = 282,
     PROGRAM_END = 283,
     ERROR = 284,
     EXP = 285
   };
#endif
/* Tokens.  */
#define IDENT 258
#define VAR 259
#define COLON 260
#define COMMA 261
#define SEMI 262
#define LPAR 263
#define RPAR 264
#define IF 265
#define WHILE 266
#define PROCEDURE 267
#define BGN 268
#define ELSE 269
#define END 270
#define DO_KEYWORD 271
#define REPEAT 272
#define UNTIL 273
#define THEN 274
#define ADD_OP 275
#define MUL_OP 276
#define REL_OP 277
#define STRING 278
#define FLOAT 279
#define UNSIGNED_INT 280
#define ASSIGN_OP 281
#define PROGRAM 282
#define PROGRAM_END 283
#define ERROR 284
#define EXP 285




/* Copy the first part of user declarations.  */
#line 1 "upc.y"

#include "symtab.h"
//#include "value.h"
#include <list>
#define YYSTYPE val


using namespace std;

void yyerror( const char *msg );
void error( const char *msg );
int yylex( void );
extern int yylineno;
int debug = 0;
symtab symbol_table ;
procedure* last_proc;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 185 "y.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    23,    27,    30,
      33,    34,    37,    39,    42,    44,    49,    54,    59,    64,
      68,    72,    73,    81,    88,    95,   102,   106,   110,   114,
     116,   120,   124,   128,   133,   138,   143,   147,   151,   155,
     157,   161,   165,   166,   168,   173,   178,   183,   187,   192,
     197,   202,   206,   211,   216,   223,   230,   232,   234,   236,
     240,   244,   246,   250,   252,   255,   259,   261,   265,   267,
     269,   273,   277,   281,   283,   285,   287,   289,   291,   293,
     297,   301
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      32,     0,    -1,    33,    34,    28,    -1,    33,    34,     1,
      -1,    27,     3,     7,    -1,    27,     3,     1,    -1,    27,
       1,     7,    -1,     1,     3,     7,    -1,    35,    44,    -1,
      35,    36,    -1,    -1,     4,    37,    -1,    39,    -1,    37,
      38,    -1,    38,    -1,    54,     5,     3,     7,    -1,    54,
       5,     3,     1,    -1,    54,     5,     1,     7,    -1,    54,
       1,     3,     7,    -1,    40,    34,     7,    -1,    40,    34,
       1,    -1,    -1,    12,     3,    41,     8,    42,     9,     7,
      -1,    12,     3,     8,    42,     9,     1,    -1,    12,     3,
       8,    42,     1,     7,    -1,    12,     3,     1,    42,     9,
       7,    -1,    12,     3,     1,    -1,    12,     1,     7,    -1,
      12,     3,     7,    -1,    43,    -1,    42,     7,    43,    -1,
      42,     1,    43,    -1,    54,     5,     3,    -1,     4,    54,
       5,     3,    -1,     4,    54,     5,     1,    -1,     4,    54,
       1,     7,    -1,    13,    45,    15,    -1,    13,    45,     1,
      -1,     1,    45,    15,    -1,    46,    -1,    45,     7,    46,
      -1,    45,     1,    46,    -1,    -1,     3,    -1,     3,     8,
      47,     9,    -1,     3,     1,    47,     9,    -1,     3,     8,
      47,     1,    -1,     3,    26,    48,    -1,    11,    48,    16,
      46,    -1,    11,    48,     1,    46,    -1,    17,    45,    18,
      48,    -1,    17,    45,     1,    -1,    10,    48,    19,    46,
      -1,    10,    48,     1,    46,    -1,    10,    48,    19,    46,
      14,    46,    -1,    10,    48,     1,    46,    14,    46,    -1,
      44,    -1,     1,    -1,    48,    -1,    47,     6,    48,    -1,
      47,     1,    48,    -1,    49,    -1,    49,    22,    49,    -1,
      50,    -1,    20,    50,    -1,    49,    20,    50,    -1,    51,
      -1,    50,    21,    51,    -1,     3,    -1,    52,    -1,     8,
      48,     9,    -1,     8,    48,     1,    -1,     1,    48,     9,
      -1,    53,    -1,    23,    -1,     1,    -1,    25,    -1,    24,
      -1,     3,    -1,    54,     6,     3,    -1,    54,     6,     1,
      -1,    54,     1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    59,    69,    75,    83,    92,   103,   107,
     108,   113,   115,   119,   121,   125,   142,   151,   160,   171,
     176,   187,   186,   204,   213,   223,   231,   240,   249,   256,
     261,   269,   279,   304,   329,   337,   347,   349,   358,   368,
     370,   372,   379,   382,   396,   420,   428,   436,   447,   449,
     457,   459,   467,   469,   476,   478,   486,   488,   497,   503,
     509,   519,   524,   528,   534,   536,   540,   542,   546,   561,
     563,   565,   573,   583,   585,   587,   598,   600,   604,   610,
     617,   625
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "VAR", "COLON", "COMMA", "SEMI",
  "LPAR", "RPAR", "IF", "WHILE", "PROCEDURE", "BGN", "ELSE", "END",
  "DO_KEYWORD", "REPEAT", "UNTIL", "THEN", "ADD_OP", "MUL_OP", "REL_OP",
  "STRING", "FLOAT", "UNSIGNED_INT", "ASSIGN_OP", "PROGRAM", "PROGRAM_END",
  "ERROR", "EXP", "$accept", "program", "program_header", "block",
  "declarations", "declaration", "variable_decls", "variable_decl",
  "procedure_decl", "procedure_header", "@1", "parameter_list",
  "parameter_group", "compound_statement", "statement_list", "statement",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "constant", "number", "identifier_list", 0
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
     285
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    33,    34,    35,
      35,    36,    36,    37,    37,    38,    38,    38,    38,    39,
      39,    41,    40,    40,    40,    40,    40,    40,    40,    42,
      42,    42,    43,    43,    43,    43,    44,    44,    44,    45,
      45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    47,    47,
      47,    48,    48,    49,    49,    49,    50,    50,    51,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    54,    54,
      54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     2,     2,
       0,     2,     1,     2,     1,     4,     4,     4,     4,     3,
       3,     0,     7,     6,     6,     6,     3,     3,     3,     1,
       3,     3,     3,     4,     4,     4,     3,     3,     3,     1,
       3,     3,     0,     1,     4,     4,     4,     3,     4,     4,
       4,     3,     4,     4,     6,     6,     1,     1,     1,     3,
       3,     1,     3,     1,     2,     3,     1,     3,     1,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    10,     0,     0,     0,     1,     0,
       0,     7,     6,     5,     4,     3,     2,     0,     0,     0,
       0,     9,    12,    10,     8,     0,     0,     0,     0,     0,
      56,     0,    39,    78,    11,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,     0,    74,    77,
      76,     0,    61,    63,    66,    69,    73,     0,     0,     0,
       0,    38,    13,     0,     0,     0,    27,    26,    28,     0,
       0,     0,    36,    20,    19,     0,    58,     0,    47,     0,
       0,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    40,    81,     0,     0,    80,    79,     0,     0,
      29,     0,     0,     0,     0,     0,    45,     0,    44,    72,
      71,    70,    53,    52,    65,    62,    67,    49,    48,    50,
      18,    17,    16,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60,    59,     0,     0,     0,     0,    31,
      30,    25,    81,    32,    24,    23,     0,    55,    54,    35,
      34,    33,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    21,    34,    35,    22,    23,
      70,    99,   100,    30,    31,    32,    75,    76,    52,    53,
      54,    55,    56,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -65
static const yytype_int16 yypact[] =
{
       3,     9,   231,    48,   -65,    49,    65,    72,   -65,     5,
      58,   -65,   -65,   -65,   -65,   -65,   -65,   226,    73,   237,
     226,   -65,   -65,   -65,   -65,   146,    80,    41,    41,   213,
     -65,    14,   -65,   -65,    73,   -65,   167,    68,    85,    45,
     136,    41,    41,    41,    96,   -65,    41,    66,   -65,   -65,
     -65,     6,   228,    62,   -65,   -65,   -65,    10,    27,   226,
     200,   -65,   -65,    93,   250,   251,   -65,    20,   -65,    20,
      92,    40,   -65,   -65,   -65,   124,   -65,   125,   -65,    99,
      26,    62,   164,   164,    66,    41,    66,   164,   164,   182,
      41,   -65,   -65,   106,   116,   151,   -65,   -65,    73,   100,
     -65,   185,   131,    20,    41,    41,   -65,   121,   -65,   -65,
     -65,   -65,   113,   137,    62,   134,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   203,    20,    20,   148,   159,   163,
     218,   168,   141,   -65,   -65,   164,   164,     7,   254,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   169,   -65,   -65,   -65,
     -65,   -65,   -65
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -65,   147,   -65,   -65,   -65,   150,   -65,   -65,
     -65,   -64,   119,   170,    -7,   -51,   145,   -27,   103,   -44,
     108,   -65,   -65,   -16
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      51,    57,    36,    81,     1,   102,    15,    82,    91,    92,
     142,    87,     5,    39,   149,    59,    78,    79,    36,    80,
      91,    60,    58,    33,    98,    83,    88,   110,    89,    61,
       2,   112,   113,    16,    60,   111,   117,   118,    91,   132,
     114,    25,    44,    26,    45,    90,    71,   -37,     8,    46,
      27,    28,    60,    20,   -37,   -37,    11,    29,   -37,    17,
      72,    47,    18,   119,    48,    49,    50,    44,   -37,    45,
      19,    20,    12,    13,    46,    66,    33,   133,   134,    14,
     133,    41,   124,    86,   147,   148,    67,   -43,    42,    48,
      49,    50,    68,    69,   -43,   -43,    93,    44,   -43,    45,
     103,   125,   -75,   -75,    46,   -75,    43,   126,   109,   127,
     -75,   -75,   -75,   120,   -75,   -75,    47,   -75,   -75,    48,
      49,    50,    44,   121,    45,   104,   107,   135,   -46,    46,
     105,   105,   130,   106,   108,   -46,   -46,    73,   126,   -46,
     131,    47,   125,    74,    48,    49,    50,    25,   126,    26,
     146,   136,   122,   -42,    84,   141,    27,    28,   123,    20,
     -57,   -42,   142,    29,   -57,    25,   143,    26,    63,   145,
      40,   -42,    64,    65,    27,    28,   152,    20,   -42,   -42,
      24,    29,   -42,    25,    62,    26,   128,    77,   115,   -42,
     129,    65,    27,    28,   116,    20,   -51,   -51,     0,    29,
     -42,    25,     0,    26,   137,     0,     0,   -42,   138,    65,
      27,    28,     0,    20,    25,   -42,    26,    29,   -42,     0,
     -42,    33,    98,    27,    28,   144,    20,    25,     0,    26,
      29,   -42,     6,   -42,     7,     0,    27,    28,    37,    20,
      38,   -42,     0,    29,   139,   140,     0,     0,    84,   139,
      85,    94,    96,    95,    97,   150,     0,   151
};

static const yytype_int16 yycheck[] =
{
      27,    28,    18,    47,     1,    69,     1,     1,    59,    60,
       3,     1,     3,    20,     7,     1,    43,    44,    34,    46,
      71,     7,    29,     3,     4,    19,    16,     1,     1,    15,
      27,    82,    83,    28,     7,     9,    87,    88,    89,   103,
      84,     1,     1,     3,     3,    18,     1,     7,     0,     8,
      10,    11,     7,    13,    14,    15,     7,    17,    18,     1,
      15,    20,     4,    90,    23,    24,    25,     1,    28,     3,
      12,    13,     7,     1,     8,     7,     3,   104,   105,     7,
     107,     1,    98,    21,   135,   136,     1,     7,     8,    23,
      24,    25,     7,     8,    14,    15,     3,     1,    18,     3,
       8,     1,     6,     7,     8,     9,    26,     7,     9,     9,
      14,    15,    16,     7,    18,    19,    20,    21,    22,    23,
      24,    25,     1,     7,     3,     1,     1,    14,     7,     8,
       6,     6,     1,     9,     9,    14,    15,     1,     7,    18,
       9,    20,     1,     7,    23,    24,    25,     1,     7,     3,
       9,    14,     1,     7,    20,     7,    10,    11,     7,    13,
      14,    15,     3,    17,    18,     1,     3,     3,     1,     1,
      23,     7,     5,     6,    10,    11,     7,    13,    14,    15,
      10,    17,    18,     1,    34,     3,     1,    42,    85,     7,
       5,     6,    10,    11,    86,    13,    14,    15,    -1,    17,
      18,     1,    -1,     3,     1,    -1,    -1,     7,     5,     6,
      10,    11,    -1,    13,     1,    15,     3,    17,    18,    -1,
       7,     3,     4,    10,    11,     7,    13,     1,    -1,     3,
      17,    18,     1,     7,     3,    -1,    10,    11,     1,    13,
       3,    15,    -1,    17,   125,   126,    -1,    -1,    20,   130,
      22,     1,     1,     3,     3,     1,    -1,     3
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    32,    33,     3,     1,     3,     0,    34,
      35,     7,     7,     1,     7,     1,    28,     1,     4,    12,
      13,    36,    39,    40,    44,     1,     3,    10,    11,    17,
      44,    45,    46,     3,    37,    38,    54,     1,     3,    45,
      34,     1,     8,    26,     1,     3,     8,    20,    23,    24,
      25,    48,    49,    50,    51,    52,    53,    48,    45,     1,
       7,    15,    38,     1,     5,     6,     7,     1,     7,     8,
      41,     1,    15,     1,     7,    47,    48,    47,    48,    48,
      48,    50,     1,    19,    20,    22,    21,     1,    16,     1,
      18,    46,    46,     3,     1,     3,     1,     3,     4,    42,
      43,    54,    42,     8,     1,     6,     9,     1,     9,     9,
       1,     9,    46,    46,    50,    49,    51,    46,    46,    48,
       7,     7,     1,     7,    54,     1,     7,     9,     1,     5,
       1,     9,    42,    48,    48,    14,    14,     1,     5,    43,
      43,     7,     3,     3,     7,     1,     9,    46,    46,     7,
       1,     3,     7
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



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
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 60 "upc.y"
    {
				if(debug)
					printf( "#program#\n" );
				error( "'.' expected" );
				yyerrok;
			}
    break;

  case 4:
#line 70 "upc.y"
    {
				symbol_table.install( (yyvsp[(2) - (3)].val.name), new program((yyvsp[(2) - (3)].val.name)) );	
				symbol_table.open_scope();
			}
    break;

  case 5:
#line 76 "upc.y"
    {
				if(debug)
					printf( "program header\n" );
				error( "';' expected" );
				yyerrok;
			}
    break;

  case 6:
#line 84 "upc.y"
    {
				if(debug)
					printf( "program header\n" );
				error( "indentifier expected" );
				//yyclearin;	
				yyerrok;
			}
    break;

  case 7:
#line 93 "upc.y"
    {
				if(debug)
					printf( "program header\n" );
				error( "'program' expected" );
				yyerrok;
				//yyclearin;
			}
    break;

  case 15:
#line 126 "upc.y"
    {
				type* etype = symbol_table.lookupType( (yyvsp[(3) - (4)].val.name) );	
				int tp = etype->ident_type;
				list<char*>::iterator var_it;

				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					for(var_it=(yyvsp[(1) - (4)].val.list_val)->begin(); var_it!=(yyvsp[(1) - (4)].val.list_val)->end(); var_it++)
						symbol_table.install( (*var_it), new variable(tp) );	
				}
				else
				{
					error( "integer or real type exptected" ); 
				}
			}
    break;

  case 16:
#line 143 "upc.y"
    {
				if(debug)
					printf( "variable_decl\n" );
				error( "';' expected" );
				yyclearin;
				//yyerrok;
			}
    break;

  case 17:
#line 152 "upc.y"
    {
				if(debug)
					printf( "variable_decl\n" );
				error( "identifier expected" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 18:
#line 161 "upc.y"
    {
				if(debug)
					printf( "variable_decl\n" );
				error( "':' expected" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 19:
#line 172 "upc.y"
    {
				symbol_table.close_scope();
			}
    break;

  case 20:
#line 177 "upc.y"
    {
				if(debug)
					printf( "procedure_decl" );
				error( "';' expected" );
				yyerrok;
			}
    break;

  case 21:
#line 187 "upc.y"
    {
				symbol_table.install( (yyvsp[(2) - (2)].val.name), new procedure() );
				last_proc = (procedure*)symbol_table.lookup( (yyvsp[(2) - (2)].val.name) );
				symbol_table.open_scope();
			}
    break;

  case 22:
#line 193 "upc.y"
    {
				//for each param on $5
				//symbol_table.update_proc( last_proc, param);
				list<Param*>::iterator it;

				for( it=(yyvsp[(5) - (7)].val.plist)->begin(); it!=(yyvsp[(5) - (7)].val.plist)->end(); it++ )
				{
					symbol_table.update_proc( last_proc, (*it) );
				}
			}
    break;

  case 23:
#line 205 "upc.y"
    {
				if(debug)
					printf( "#procedure_header#\n" );
				error( "';' expected" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 24:
#line 214 "upc.y"
    {
				//not indicated as needed by kochut
				if(debug)
					printf( "#procedure_header#\n" );
				error( "')' expected" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 25:
#line 224 "upc.y"
    {
				if(debug)
					printf( "#procedure_header#\n" );
				error( "'(' expected" );
				yyerrok;
			}
    break;

  case 26:
#line 232 "upc.y"
    {
				if(debug)
					printf( "#procedure_header#\n" );
				error( "';' expected" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 27:
#line 241 "upc.y"
    {
				if(debug)
					printf( "#procedure_header#\n" );
				error( "identifier expected" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 28:
#line 250 "upc.y"
    {
				symbol_table.install( (yyvsp[(2) - (3)].val.name), new procedure() );
				symbol_table.open_scope();
			}
    break;

  case 29:
#line 257 "upc.y"
    {
				(yyval.val.plist) = (yyvsp[(1) - (1)].val.plist);
			}
    break;

  case 30:
#line 262 "upc.y"
    {
				list<Param*>::iterator it; 
				(yyval.val.plist) = (yyvsp[(1) - (3)].val.plist);
				for( it=(yyvsp[(3) - (3)].val.plist)->begin(); it!=(yyvsp[(3) - (3)].val.plist)->end(); it++)
					(yyval.val.plist)->push_back(*it);
			}
    break;

  case 31:
#line 270 "upc.y"
    {
				if(debug)
					printf( "parameter_list" );		
				error( "';' expected" );
				yyerrok;
			}
    break;

  case 32:
#line 280 "upc.y"
    {
				int tp;
				(yyval.val.plist) = new list< Param* >;
				list<char*>::iterator it;
				Param* p;

				tp = symbol_table.lookupIdentType( (yyvsp[(3) - (3)].val.name) );	
				//check for appropriate type??
				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					for( it=(yyvsp[(1) - (3)].val.list_val)->begin(); it!=(yyvsp[(1) - (3)].val.list_val)->end(); it++);
					{
						p->tp = tp;
						p->ppc = BY_VAL;
						(yyval.val.plist)->push_back( p );
						symbol_table.install( *it, new parameter(tp, BY_VAL) );	
					}
				}
				else
				{
					error( "incorrect variable declaration" );
				}
			}
    break;

  case 33:
#line 305 "upc.y"
    {
				int tp;
				(yyval.val.plist) = new list< Param* >;
				list<char*>::iterator it;
				Param* p;

				tp = symbol_table.lookupIdentType( (yyvsp[(4) - (4)].val.name) );	
				//check for appropriate type??
				if( tp == TYPE_INT || tp == TYPE_FLT )
				{
					for( it=(yyvsp[(2) - (4)].val.list_val)->begin(); it!=(yyvsp[(2) - (4)].val.list_val)->end(); it++);
					{
						p->tp = tp;
						p->ppc = BY_REF;
						(yyval.val.plist)->push_back( p );
						symbol_table.install( *it, new parameter(tp, BY_REF) );	
					}
				}
				else
				{
					error( "incorrect variable declaration" );
				}
			}
    break;

  case 34:
#line 330 "upc.y"
    {
				if(debug)
					printf( "parameter_group" );
				error( "';' expected" );
				yyerrok;
			}
    break;

  case 35:
#line 338 "upc.y"
    {
				if(debug)
					printf( "parameter_group" );
				error( "':' expected" );
				yyerrok;
			}
    break;

  case 37:
#line 350 "upc.y"
    {
				if(debug)
					printf( "compound_statement\n");
				error( "reached end of file while parsing" );
				//yyclearin;
				yyerrok;
			}
    break;

  case 38:
#line 359 "upc.y"
    {
				if(debug)
					printf("compound_statement\n");
				error( "'BEGIN' expected" );
				yyerrok;
			}
    break;

  case 41:
#line 373 "upc.y"
    {
					error( "';' expected");
					yyerrok;
				}
    break;

  case 43:
#line 383 "upc.y"
    {
				Entry* binding = symbol_table.lookupBinding( (yyvsp[(1) - (1)].val.name) );
				
				if( binding->getType() != Entry::procedure )
				{
					error( "procedure expected" );
				}
				else if( ((procedure*)binding)->param_no != 0) 
				{
					error( "call with no parameters supplied" );
				}
			}
    break;

  case 44:
#line 397 "upc.y"
    {
				Entry* binding = symbol_table.lookupBinding( (yyvsp[(1) - (4)].val.name) );

				if( binding->getType() != Entry::procedure )
					error( "procedure expected" );
				else if( (yyvsp[(3) - (4)].val.elist)->size() != ((procedure*)binding)->param_no )
					error( "incorrect number of parameters" );
				else
				{
					list<ExprAttr*>::iterator e_it;
					list<Param*>::iterator p_it;
					procedure* temp = (procedure*)symbol_table.lookupBinding( (yyvsp[(1) - (4)].val.name) );
					vector<Param*>* pv;

					for(e_it=(yyvsp[(3) - (4)].val.elist)->begin(); e_it!=(yyvsp[(3) - (4)].val.elist)->end(); e_it++ )
					{
						if( (*e_it)->tp == BY_REF )
							if( (*e_it)->lval == 0 )
								error( "incorrect expresion" );		
					}	
				}
			}
    break;

  case 45:
#line 421 "upc.y"
    {
				if(debug)
					printf( "#statement#\n" );
				error( "'(' expected" );
				yyerrok;
			}
    break;

  case 46:
#line 429 "upc.y"
    {
				if(debug)
					printf( "#statement#\n" );
				error( "')' expected" );
				yyerrok;
			}
    break;

  case 47:
#line 437 "upc.y"
    {
				Entry::EntryType etype = symbol_table.lookup((yyvsp[(1) - (3)].val.name));

				if( etype != Entry::variable || etype != Entry::parameter )
					error( "incorrect type" );
				if( symbol_table.lookupType((yyvsp[(1) - (3)].val.name))->ident_type == TYPE_INT )
					if( (yyvsp[(3) - (3)].val.eattr)->tp == TYPE_FLT )
						error( "incorrect assignment, integer expected" );
			}
    break;

  case 49:
#line 450 "upc.y"
    {
				if(debug)
					printf( "#statement#\n" );
				error( "'DO' expected" );
				yyerrok;
			}
    break;

  case 51:
#line 460 "upc.y"
    {
				if(debug)
					printf( "#statement#\n" );
				error( "'UNTIL' expected" );
				yyerrok;
			}
    break;

  case 53:
#line 470 "upc.y"
    {
				if(debug)
					printf( "#statement\n#" );
				error( "'THEN' expected" );
			}
    break;

  case 55:
#line 479 "upc.y"
    {
				if(debug)
					printf( "#statement#\n" );
				error( "'THEN' expected" );
				yyerrok;
			}
    break;

  case 57:
#line 489 "upc.y"
    {
				error( "not a statement" );
				yyerrok;
				//yyclearin;
			}
    break;

  case 58:
#line 498 "upc.y"
    {
				(yyval.val.elist) = new list<ExprAttr*>;
				(yyval.val.elist)->push_back( (yyvsp[(1) - (1)].val.eattr) );
			}
    break;

  case 59:
#line 504 "upc.y"
    {
				(yyvsp[(1) - (3)].val.elist)->push_back( (yyvsp[(3) - (3)].val.eattr) );
				(yyval.val.elist) = (yyvsp[(1) - (3)].val.elist);		
			}
    break;

  case 60:
#line 510 "upc.y"
    {
				if(debug)
					printf( "#expression_list#\n" );
				error( "',' expected" );
				yyerrok;
			}
    break;

  case 61:
#line 520 "upc.y"
    {
				
			}
    break;

  case 63:
#line 529 "upc.y"
    {
				(yyval.val.eattr)->lval = (yyvsp[(1) - (1)].val.eattr)->lval;
				(yyval.val.eattr)->tp = (yyvsp[(1) - (1)].val.eattr)->tp;
			}
    break;

  case 68:
#line 547 "upc.y"
    {
				Entry* binding = symbol_table.lookupBinding( (yyvsp[(1) - (1)].val.name) );
				
				if(binding->getType()!=Entry::parameter || binding->getType()!=Entry::variable)
				{
					error( "illegal factor: variable or parameter expected" );
				}
				else
				{
					(yyval.val.eattr)->tp = binding->getType();
					(yyval.val.eattr)->lval = 1;
				}
			}
    break;

  case 71:
#line 566 "upc.y"
    {
				if(debug)
					printf( "factor" );
				error( "')' expected" );
				yyerrok;
			}
    break;

  case 72:
#line 574 "upc.y"
    {
				if(debug)
					printf( "factor" );
				error( "'(' expected" );
				yyerrok;
			}
    break;

  case 75:
#line 588 "upc.y"
    {
				if(debug)
					printf( "#constant#\n" );
				error( "syntax error" );
				//yyerrok;
				yyclearin;
			}
    break;

  case 78:
#line 605 "upc.y"
    {
				(yyval.val.list_val) = new list<char*>();
				(yyval.val.list_val)->push_back( (yyvsp[(1) - (1)].val.name) );
			}
    break;

  case 79:
#line 611 "upc.y"
    {
				//$1 = new list<char*>();
				(yyvsp[(1) - (3)].val.list_val)->push_back( (yyvsp[(3) - (3)].val.name) );
				(yyval.val.list_val) = (yyvsp[(1) - (3)].val.list_val);		
			}
    break;

  case 80:
#line 618 "upc.y"
    {
				if(debug)
					printf( "#identifier_list#" );
				error( "identifier expected" );
				yyerrok;
			}
    break;

  case 81:
#line 626 "upc.y"
    {
				if(debug)
					printf( "#identifier_list#" );
				error( "',' expected" );
				yyerrok;
			}
    break;


/* Line 1267 of yacc.c.  */
#line 2123 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 634 "upc.y"

extern int yylineno;

void yyerror( const char* msg )
{
//	fprintf( stderr, "Line %d: %s\n", yylineno, msg );
//	fflush( stderr );
}
void 
error( const char *msg )
{
	fprintf( stderr, "Line %d: %s\n", yylineno, msg );
	fflush( stderr );
}

