
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "voo.y"

#include <cstdio>
#include <iostream>
#include <math.h>
#include <stdarg.h>
#include "symTab.h"
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

Scope mainScope("global");

void generateQuad(char * op , char * arg1 , char * arg2 );
void qudraple();
void AddToTable(int ,int, string);

int ind=0;
char temp='A';
struct code
{
	string opd1;
	string opd2;
	string opr;
};



/* Line 189 of yacc.c  */
#line 111 "voo.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     STRING = 260,
     BOOL_ID = 261,
     FLOAT_ID = 262,
     STR_ID = 263,
     INT_ID = 264,
     SEMI_COLON = 265,
     COLON = 266,
     COMMA = 267,
     CONST = 268,
     VAR = 269,
     EQUAL = 270,
     TRUE = 271,
     FALSE = 272,
     LOGIC_OR = 273,
     LOGIC_AND = 274,
     BITWISE_OR = 275,
     BITWISE_XOR = 276,
     BITWISE_AND = 277,
     NOT_EQ = 278,
     EQ = 279,
     SM_EQ = 280,
     SM = 281,
     GR_EQ = 282,
     GR = 283,
     BITWISE_SHIFT_LEFT = 284,
     BITWISE_SHIFT_RIGHT = 285,
     MINUS = 286,
     PLUS = 287,
     MOD = 288,
     DIV = 289,
     MUL = 290,
     POW = 291,
     BITWISE_NOT = 292,
     LOGIC_NOT = 293,
     OPEN_BRACKET = 294,
     CLOSE_BRACKET = 295,
     OPEN_PARANTH = 296,
     CLOSE_PARANTH = 297,
     IF = 298,
     ELSE = 299,
     FOR = 300,
     WHILE = 301,
     SWITCH = 302,
     CASE = 303,
     REPEAT = 304,
     UNTIL = 305,
     DEFAULT = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 43 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;



/* Line 214 of yacc.c  */
#line 207 "voo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 219 "voo.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNRULES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    18,    21,    24,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    47,
      50,    55,    60,    65,    70,    72,    74,    76,    78,    80,
      82,    84,    86,    91,    96,   101,   106,   110,   114,   118,
     122,   126,   130,   134,   138,   141,   145,   149,   153,   155,
     159,   163,   167,   171,   175,   179,   183,   187,   191,   195,
     199,   203,   207,   211,   215,   219,   223,   227,   231,   233,
     235,   237,   241,   243,   246,   254,   258,   263,   264,   272,
     284,   288,   298,   306,   312,   316,   317,   321,   325,   329,
     333,   337,   341,   343,   346,   350,   354,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   376,   378,   380,   382
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    53,    -1,    55,    53,    -1,    61,
      53,    -1,    66,    53,    -1,    70,    53,    -1,    69,    53,
      -1,    72,    53,    -1,    73,    53,    -1,    54,    -1,    55,
      -1,    61,    -1,    66,    -1,    70,    -1,    69,    -1,    72,
      -1,    73,    -1,    14,    79,    10,    -1,    13,    56,    -1,
       9,    15,    57,    10,    -1,     7,    15,    58,    10,    -1,
       8,    15,    59,    10,    -1,     6,    15,    60,    10,    -1,
       3,    -1,     9,    -1,     4,    -1,     7,    -1,     5,    -1,
       8,    -1,    78,    -1,     6,    -1,     9,    15,    62,    10,
      -1,     7,    15,    64,    10,    -1,     8,    15,    65,    10,
      -1,     6,    15,    75,    10,    -1,    62,    32,    62,    -1,
      62,    31,    62,    -1,    62,    35,    62,    -1,    62,    34,
      62,    -1,    62,    33,    62,    -1,    62,    22,    62,    -1,
      62,    20,    62,    -1,    62,    21,    62,    -1,    37,    62,
      -1,    62,    29,    62,    -1,    62,    30,    62,    -1,    39,
      62,    40,    -1,     9,    -1,    63,    32,    63,    -1,    63,
      31,    63,    -1,    63,    35,    63,    -1,    63,    34,    63,
      -1,    63,    33,    63,    -1,    63,    36,    63,    -1,    63,
      32,    62,    -1,    63,    31,    62,    -1,    63,    35,    62,
      -1,    63,    34,    62,    -1,    63,    33,    62,    -1,    63,
      36,    62,    -1,    62,    32,    63,    -1,    62,    31,    63,
      -1,    62,    35,    63,    -1,    62,    34,    63,    -1,    62,
      33,    63,    -1,    62,    36,    63,    -1,    39,    63,    40,
      -1,     4,    -1,    63,    -1,    62,    -1,    65,    32,    65,
      -1,     5,    -1,    67,    68,    -1,    43,    39,    75,    40,
      41,    53,    42,    -1,    44,    67,    68,    -1,    44,    41,
      53,    42,    -1,    -1,    46,    39,    75,    40,    41,    53,
      42,    -1,    45,    39,    71,    12,    75,    12,    71,    40,
      41,    53,    42,    -1,    79,    15,    62,    -1,    49,    41,
      53,    42,    50,    39,    75,    40,    10,    -1,    47,    39,
      79,    40,    41,    74,    42,    -1,    48,    77,    11,    53,
      74,    -1,    51,    11,    53,    -1,    -1,    76,    24,    76,
      -1,    76,    23,    76,    -1,    76,    28,    76,    -1,    76,
      27,    76,    -1,    76,    26,    76,    -1,    76,    25,    76,
      -1,    78,    -1,    38,    75,    -1,    75,    19,    75,    -1,
      75,    18,    75,    -1,    39,    75,    40,    -1,     3,    -1,
       4,    -1,     5,    -1,     3,    -1,     4,    -1,     5,    -1,
      78,    -1,    16,    -1,    17,    -1,     9,    -1,     7,    -1,
       8,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    90,    94,
      97,    98,    99,   100,   105,   105,   107,   107,   109,   109,
     111,   111,   114,   115,   116,   117,   123,   124,   125,   126,
     127,   129,   130,   131,   132,   133,   134,   136,   138,   142,
     143,   144,   145,   146,   147,   149,   150,   151,   152,   153,
     154,   156,   157,   158,   159,   160,   161,   163,   164,   169,
     169,   172,   173,   177,   180,   183,   184,   185,   189,   192,
     195,   198,   201,   204,   205,   205,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   224,   224,   224,
     227,   227,   227,   227,   231,   231,   234,   235,   236,   237
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "BOOL_ID",
  "FLOAT_ID", "STR_ID", "INT_ID", "SEMI_COLON", "COLON", "COMMA", "CONST",
  "VAR", "EQUAL", "TRUE", "FALSE", "LOGIC_OR", "LOGIC_AND", "BITWISE_OR",
  "BITWISE_XOR", "BITWISE_AND", "NOT_EQ", "EQ", "SM_EQ", "SM", "GR_EQ",
  "GR", "BITWISE_SHIFT_LEFT", "BITWISE_SHIFT_RIGHT", "MINUS", "PLUS",
  "MOD", "DIV", "MUL", "POW", "BITWISE_NOT", "LOGIC_NOT", "OPEN_BRACKET",
  "CLOSE_BRACKET", "OPEN_PARANTH", "CLOSE_PARANTH", "IF", "ELSE", "FOR",
  "WHILE", "SWITCH", "CASE", "REPEAT", "UNTIL", "DEFAULT", "$accept",
  "stmt", "variable", "constant_stmt", "constant", "int_value",
  "float_value", "str_value", "bool_value", "assignment", "int_expr",
  "float_expr", "float_int_expr", "str_expr", "if_else_if_else_stmt",
  "if_stmt", "else_if_stmt", "while_loop", "for_loop", "for_assignment",
  "repeat_until_loop", "switch_case", "case_stmt", "bool_expr",
  "compare_opd", "value", "boolean", "id", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    55,
      56,    56,    56,    56,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    68,    68,    68,    69,    70,
      71,    72,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       4,     4,     4,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     3,     1,     2,     7,     3,     4,     0,     7,    11,
       3,     9,     7,     5,     3,     0,     3,     3,     3,     3,
       3,     3,     1,     2,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    77,    15,    14,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
      19,   109,   107,   108,   106,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     0,    73,     7,     6,
       8,     9,    97,    98,    99,   104,   105,     0,     0,     0,
       0,    92,    68,    48,     0,     0,    70,    69,     0,    72,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,     0,     0,    77,    93,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    34,     0,
       0,    32,     0,     0,     0,     0,     0,    31,     0,    30,
      26,    27,     0,    28,    29,     0,    24,    25,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    96,    95,    94,
      87,    86,    91,    90,    89,    88,    47,    67,    42,    43,
      41,    45,    46,    37,    62,    36,    61,    40,    65,    39,
      64,    38,    63,     0,    66,    56,    50,    55,    49,    59,
      53,    58,    52,    57,    51,    60,    54,    71,    37,    36,
      40,    39,    38,    23,    21,    22,    20,     0,     0,    80,
       0,    85,     0,    76,     0,     0,     0,     0,     0,     0,
       0,    74,     0,    78,   100,   101,   102,     0,   103,     0,
      82,     0,     0,     0,    84,     0,     0,    85,    81,     0,
      83,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    14,    30,   138,   132,   135,   128,    15,
      66,    67,    68,    70,    16,    17,    47,    18,    19,    79,
      20,    21,   209,    59,    60,   217,    61,    80
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
       8,    13,    14,    18,    45,   231,   245,     5,    26,    67,
      79,    11,    84,     8,     8,     8,     8,    77,     8,     8,
       8,     8,    20,     9,   172,    29,   167,   171,   181,   186,
     -70,   -70,   -70,   -70,   -70,   175,    20,   245,    20,   245,
       8,   -70,   -70,   -70,   -70,   -70,   264,   -70,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,    20,    20,    16,
     262,   -70,   -70,   -70,    29,     9,   159,   191,   187,   -70,
      37,    29,   102,   113,    63,    97,   169,   -70,     1,   193,
     194,    21,   201,   200,     8,    77,   -70,    24,   -70,    20,
      20,   170,   170,   170,   170,   170,   170,   -70,   119,   233,
      29,    29,    29,    29,    29,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,   -70,   -70,   172,
     136,   -70,    29,    29,    29,    29,    29,   -70,   246,   -70,
     -70,   -70,   261,   -70,   -70,   265,   -70,   -70,   281,   268,
      20,    29,   269,   270,   205,   230,   -70,   -70,   255,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   214,   228,
     249,   129,   129,   259,   263,   259,   263,   272,   276,   272,
     276,   272,   276,   159,   276,   182,   263,   182,   263,   178,
     276,   178,   276,   178,   276,   178,   276,   -70,   267,   267,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,     8,   258,   199,
       8,    69,   274,   -70,   273,   245,   275,   111,   292,   277,
      20,   -70,   266,   -70,   -70,   -70,   -70,   293,   -70,     8,
     -70,    85,   279,     8,   -70,   304,     8,    69,   -70,   280,
     -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -13,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
     -15,   -33,   -70,   197,   -70,   278,   236,   -70,   -70,   118,
     -70,   -70,    91,   -27,    51,   -70,   -69,     6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    43,    44,    45,   129,    48,    49,    50,    51,    78,
      72,    81,    35,    62,     1,     2,     3,     4,    63,    89,
      90,     5,     6,    52,    53,    54,    88,    83,    22,    23,
      86,    87,    99,    24,    89,    90,    55,    56,    63,    89,
      90,   139,    89,    90,    36,    82,    64,   118,    65,    97,
      98,     7,    40,     8,     9,    10,   120,    11,    57,    58,
      25,   142,   148,   149,   147,    37,    64,   130,    71,   119,
     131,   145,   164,   166,   168,   170,   172,   174,   176,   178,
     180,   182,   184,   186,    41,   158,   159,   160,   161,   162,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   181,
     183,   185,   133,    89,    90,   134,    38,   188,   189,   190,
     191,   192,   121,   198,   214,   215,   216,   207,    39,   127,
     208,    46,   100,   101,   102,   225,   199,    55,    56,    55,
      56,   103,   104,   122,   123,   124,   125,   126,   218,   100,
     101,   102,   150,   151,   152,   153,   154,   155,   103,   104,
     105,   106,   107,   108,   109,   110,   100,   101,   102,   156,
     122,   123,   124,   125,   126,   103,   104,   122,   123,   124,
     125,   126,   136,    52,    53,    54,   156,    69,   137,   100,
     101,   102,    73,   221,   204,    77,    74,   206,   103,   104,
     105,   106,   107,   108,   109,   110,    75,   117,   100,   101,
     102,    76,   100,   101,   102,   140,   224,   103,   104,   141,
     227,   103,   104,   229,   110,   107,   108,   109,   110,   100,
     101,   102,   111,   112,   113,   114,   115,   116,   103,   104,
     122,   123,   124,   125,   126,   101,   102,    26,    27,    28,
      29,   143,   144,   103,   104,   122,   123,   124,   125,   126,
     102,    31,    32,    33,    34,   202,   193,   103,   104,   122,
     123,   124,   125,   126,   111,   112,   113,   114,   115,   116,
     205,   194,   203,   157,    90,   195,    89,    90,   103,   104,
     122,   123,   124,   125,   126,    91,    92,    93,    94,    95,
      96,   196,   107,   108,   109,   110,   113,   114,   115,   116,
     124,   125,   126,   219,   223,    84,   222,     7,   110,   197,
     200,   201,   116,   210,   228,   211,   187,   213,   230,   220,
     226,   146,   231,   212,    85
};

static const yytype_uint8 yycheck[] =
{
      13,    14,    15,    16,    73,    18,    19,    20,    21,    36,
      25,    38,     6,     4,     6,     7,     8,     9,     9,    18,
      19,    13,    14,     3,     4,     5,    10,    40,    15,    15,
      57,    58,    65,    15,    18,    19,    16,    17,     9,    18,
      19,    40,    18,    19,    39,    39,    37,    10,    39,    64,
      65,    43,    41,    45,    46,    47,    71,    49,    38,    39,
      15,    40,    89,    90,    40,    39,    37,     4,    39,    32,
       7,    84,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     5,    18,    19,     8,    39,   122,   123,   124,
     125,   126,    10,   140,     3,     4,     5,    48,    39,     6,
      51,    44,    20,    21,    22,    40,   141,    16,    17,    16,
      17,    29,    30,    31,    32,    33,    34,    35,   207,    20,
      21,    22,    91,    92,    93,    94,    95,    96,    29,    30,
      31,    32,    33,    34,    35,    36,    20,    21,    22,    40,
      31,    32,    33,    34,    35,    29,    30,    31,    32,    33,
      34,    35,     3,     3,     4,     5,    40,     5,     9,    20,
      21,    22,    15,   210,   197,    10,    15,   200,    29,    30,
      31,    32,    33,    34,    35,    36,    15,    10,    20,    21,
      22,    15,    20,    21,    22,    12,   219,    29,    30,    15,
     223,    29,    30,   226,    36,    33,    34,    35,    36,    20,
      21,    22,    31,    32,    33,    34,    35,    36,    29,    30,
      31,    32,    33,    34,    35,    21,    22,     6,     7,     8,
       9,    40,    42,    29,    30,    31,    32,    33,    34,    35,
      22,     6,     7,     8,     9,    50,    10,    29,    30,    31,
      32,    33,    34,    35,    31,    32,    33,    34,    35,    36,
      12,    10,    42,    40,    19,    10,    18,    19,    29,    30,
      31,    32,    33,    34,    35,    23,    24,    25,    26,    27,
      28,    10,    33,    34,    35,    36,    33,    34,    35,    36,
      33,    34,    35,    11,    11,    41,    40,    43,    36,    41,
      41,    41,    36,    39,    10,    42,   119,    42,   227,    42,
      41,    85,    42,   205,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    13,    14,    43,    45,    46,
      47,    49,    53,    54,    55,    61,    66,    67,    69,    70,
      72,    73,    15,    15,    15,    15,     6,     7,     8,     9,
      56,     6,     7,     8,     9,    79,    39,    39,    39,    39,
      41,     0,    53,    53,    53,    53,    44,    68,    53,    53,
      53,    53,     3,     4,     5,    16,    17,    38,    39,    75,
      76,    78,     4,     9,    37,    39,    62,    63,    64,     5,
      65,    39,    62,    15,    15,    15,    15,    10,    75,    71,
      79,    75,    79,    53,    41,    67,    75,    75,    10,    18,
      19,    23,    24,    25,    26,    27,    28,    62,    62,    63,
      20,    21,    22,    29,    30,    31,    32,    33,    34,    35,
      36,    31,    32,    33,    34,    35,    36,    10,    10,    32,
      62,    10,    31,    32,    33,    34,    35,     6,    60,    78,
       4,     7,    58,     5,     8,    59,     3,     9,    57,    40,
      12,    15,    40,    40,    42,    53,    68,    40,    75,    75,
      76,    76,    76,    76,    76,    76,    40,    40,    62,    62,
      62,    62,    62,    62,    63,    62,    63,    62,    63,    62,
      63,    62,    63,    62,    63,    62,    63,    62,    63,    62,
      63,    62,    63,    62,    63,    62,    63,    65,    62,    62,
      62,    62,    62,    10,    10,    10,    10,    41,    75,    62,
      41,    41,    50,    42,    53,    12,    53,    48,    51,    74,
      39,    42,    71,    42,     3,     4,     5,    77,    78,    11,
      42,    75,    40,    11,    53,    40,    41,    53,    10,    53,
      74,    42
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 20:

/* Line 1455 of yacc.c  */
#line 97 "voo.y"
    { cout << "const int id " << endl; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 98 "voo.y"
    { cout << "const float id " << endl; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 99 "voo.y"
    { cout << "const str id " << endl; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 100 "voo.y"
    { cout << "const bool id " << endl; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 114 "voo.y"
    {	mainScope.insert((string)(yyvsp[(1) - (4)].idval),(void *)(yyvsp[(3) - (4)].idval)); cout<< "ass for int id -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<"with expr value "<<(yyvsp[(3) - (4)].idval);  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 123 "voo.y"
    { /*$$=$1+$3;*/  cout << "PLUS: " << (yyval.idval) <<endl; generateQuad("Add",(yyvsp[(1) - (3)].idval),(yyvsp[(3) - (3)].idval));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 124 "voo.y"
    { /*$$=$1-$3;*/ cout << "MINUS: " << (yyval.idval) <<endl; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 125 "voo.y"
    { /*$$=$1*$3;*/ cout << "MUL: " << (yyval.idval) << endl;  ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 126 "voo.y"
    { /*$$=$1/$3;*/ cout << "DIV: " << (yyval.idval) <<endl; ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 127 "voo.y"
    { /*$$=$1%$3;*/ cout << "MOD: " << (yyval.idval) << endl; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 129 "voo.y"
    { cout << "BITWISE_AND: " <<endl; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 130 "voo.y"
    { cout << "BITWISE_OR: " <<endl; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 131 "voo.y"
    { cout << "BITWISE_XOR: " <<endl; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 132 "voo.y"
    { cout << "BITWISE_NOT: " <<endl; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 133 "voo.y"
    { cout << "BITWISE_SHIFT_LEFT: " <<endl; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 134 "voo.y"
    { cout << "BITWISE_SHIFT_RIGHT: " <<endl; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 136 "voo.y"
    { cout << "Brackets  " <<endl; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 138 "voo.y"
    {cout<<"int id hh"<<endl;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 142 "voo.y"
    { cout << "PLUS: " <<endl; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 143 "voo.y"
    { cout << "MINUS: " <<endl; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 144 "voo.y"
    { cout << "MUL: " << endl; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 145 "voo.y"
    { cout << "DIV: " <<endl; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 146 "voo.y"
    { cout << "MOD: " << endl; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 147 "voo.y"
    { cout << "POW: " << endl; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 149 "voo.y"
    { cout << "PLUS: " <<endl; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 150 "voo.y"
    { cout << "MINUS: " <<endl; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 151 "voo.y"
    { cout << "MUL: " << endl; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 152 "voo.y"
    { cout << "DIV: " <<endl; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 153 "voo.y"
    { cout << "MOD: " << endl; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 154 "voo.y"
    { cout << "POW: " << endl; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 156 "voo.y"
    { cout << "PLUS: " <<endl; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 157 "voo.y"
    { cout << "MINUS: " <<endl; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 158 "voo.y"
    { cout << "MUL: " << endl; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 159 "voo.y"
    { cout << "DIV: " <<endl; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 160 "voo.y"
    { cout << "MOD: " << endl; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 161 "voo.y"
    { cout << "POW: " << endl; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 163 "voo.y"
    { cout << "Brackets  " <<endl; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 180 "voo.y"
    { cout << "if " <<endl; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 183 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 184 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 185 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 210 "voo.y"
    { cout << "EQ " <<endl; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 211 "voo.y"
    { cout << "NOT_EQ " <<endl; ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 212 "voo.y"
    { cout << "GR " <<endl; ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 213 "voo.y"
    { cout << "GR_EQ " <<endl; ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 214 "voo.y"
    { cout << "SM " <<endl; ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 215 "voo.y"
    { cout << "SM_EQ " <<endl; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 216 "voo.y"
    { cout << "boolean " <<endl; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 217 "voo.y"
    { cout << "LOGIC_NOT " <<endl; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 218 "voo.y"
    { cout << "LOGIC_AND " <<endl; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 219 "voo.y"
    { cout << "LOGIC_OR " <<endl; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 220 "voo.y"
    { cout << "Brackets " <<endl; ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 234 "voo.y"
    { cout << " int id " << endl; ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 235 "voo.y"
    { cout << " float id " << endl; ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 236 "voo.y"
    { cout << " str id " << endl; ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 237 "voo.y"
    { cout << " bool id " << endl; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2025 "voo.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 241 "voo.y"

struct code codeInstr[20];
int id=0;
ofstream quad;
int lineNo=0;

void AddToTable(string opd1,string opd2,string opr)
{
	codeInstr[ind].opd1=opd1;
	codeInstr[ind].opd2=opd2;
	codeInstr[ind].opr=opr;
	ind++;
	temp++;
	//return temp;
}

void quadraple()
{
	int cnt=0;
	temp++;
	//printf(“\n\n\t QUADRAPLE CODE\n\n”);
	while(cnt<ind)
	{
		/*//printf(“%c : = \t”,temp);
		printf(“%d”,id);
		printf(“\t”);
		printf(“%c”,codeInstr[cnt].opr);
		printf(“\t”);
		if(isalpha(codeInstr[cnt].opd1))
		printf(“%c\t”,codeInstr[cnt].opd1);
		else
		{printf(“%c\t”,temp);}

		//printf(“%c\t”,codeInstr[cnt].opr);

		if(isalpha(codeInstr[cnt].opd2))
		printf(“%c\t”,codeInstr[cnt].opd2);
		else
		{printf(“%c\t”,temp);}

		printf(“%c”,temp);

		printf(“\n”);
		cnt++;
		temp++;
		id++;*/
		cout<< cnt <<" " << codeInstr[cnt].opr <<" " << codeInstr[cnt].opd1 << " " << codeInstr[cnt].opd2 <<endl;

	}
}

void generateQuad(char * op , char * arg1 , char * arg2 ){
	quad << lineNo << " " << op <<" " << arg1 << " " << arg2 << endl;
	
}

int main(int, char**) {
	// open a file handle to a particular file:
	FILE *myfile = fopen("sample.voo", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open sample.voo!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	//create a file to write the quadruples in 
	
	quad.open ("quad.txt");
	
	
	// parse through the input until there is no more:
	do {
		yyparse();
		quadraple();
	} while (!feof(yyin));
	
	quad.close();
	
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}