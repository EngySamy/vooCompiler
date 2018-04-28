
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
#include "sym.h"
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

Scope mainScope("global");
map<NodeWithType* , int > nodes;

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 ,NodeWithType * res );

void newSymbolRecord( char *, IdType , bool); 
bool updateSymbolRecord(char *, bool , NodeWithType* ) ;
Node * NewNodeFloat(float );
Node * NewNodeInt(int);
Node * NewNodeString(char *);
Node * NewNodeBool(bool);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0;



/* Line 189 of yacc.c  */
#line 114 "voo.tab.c"

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
     CONST = 265,
     VAR = 266,
     EQUAL = 267,
     TRUE = 268,
     FALSE = 269,
     LOGIC_OR = 270,
     LOGIC_AND = 271,
     NOT_EQ = 272,
     EQ = 273,
     SM_EQ = 274,
     SM = 275,
     GR_EQ = 276,
     GR = 277,
     BITWISE_SHIFT_LEFT = 278,
     BITWISE_SHIFT_RIGHT = 279,
     POW = 280,
     LOGIC_NOT = 281,
     IF = 282,
     ELSE = 283,
     FOR = 284,
     WHILE = 285,
     SWITCH = 286,
     CASE = 287,
     REPEAT = 288,
     UNTIL = 289,
     DEFAULT = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 46 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;
	struct NodeWithType * nodeval;



/* Line 214 of yacc.c  */
#line 195 "voo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "voo.tab.c"

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   314

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,    19,     2,
      46,    47,    30,    28,    50,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,    17,    49,    34,     2,     2,     2,
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
      15,    16,    20,    21,    22,    23,    24,    25,    26,    27,
      33,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    18,    21,    24,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    47,
      50,    52,    54,    56,    58,    63,    68,    73,    78,    81,
      86,    91,    96,   101,   106,   111,   116,   121,   125,   129,
     133,   137,   141,   145,   149,   153,   156,   160,   164,   166,
     168,   172,   176,   180,   184,   188,   192,   196,   200,   204,
     208,   212,   216,   220,   224,   228,   232,   236,   240,   242,
     244,   246,   248,   250,   252,   255,   263,   267,   272,   273,
     281,   293,   297,   307,   315,   321,   325,   326,   330,   334,
     338,   342,   346,   350,   352,   355,   359,   363,   367,   369,
     371,   373,   375,   377,   379,   381,   383,   385,   387,   389,
     391
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    53,    -1,    57,    53,    -1,    59,
      53,    -1,    64,    53,    -1,    68,    53,    -1,    67,    53,
      -1,    70,    53,    -1,    71,    53,    -1,    54,    -1,    57,
      -1,    59,    -1,    64,    -1,    68,    -1,    67,    -1,    70,
      -1,    71,    -1,    11,    55,    45,    -1,    11,    56,    -1,
       9,    -1,     7,    -1,     8,    -1,     6,    -1,     9,    12,
      60,    45,    -1,     7,    12,    62,    45,    -1,     8,    12,
      63,    45,    -1,     6,    12,    73,    45,    -1,    10,    58,
      -1,     9,    12,     3,    45,    -1,     7,    12,     4,    45,
      -1,     8,    12,     5,    45,    -1,     6,    12,    76,    45,
      -1,     9,    12,    60,    45,    -1,     7,    12,    62,    45,
      -1,     8,    12,    63,    45,    -1,     6,    12,    73,    45,
      -1,    60,    28,    60,    -1,    60,    29,    60,    -1,    60,
      30,    60,    -1,    60,    31,    60,    -1,    60,    32,    60,
      -1,    60,    19,    60,    -1,    60,    17,    60,    -1,    60,
      18,    60,    -1,    34,    60,    -1,    60,    26,    60,    -1,
      60,    27,    60,    -1,     3,    -1,     9,    -1,    61,    28,
      61,    -1,    61,    29,    61,    -1,    61,    30,    61,    -1,
      61,    31,    61,    -1,    61,    32,    61,    -1,    61,    33,
      61,    -1,    61,    28,    60,    -1,    61,    29,    60,    -1,
      61,    30,    60,    -1,    61,    31,    60,    -1,    61,    32,
      60,    -1,    61,    33,    60,    -1,    60,    28,    61,    -1,
      60,    29,    61,    -1,    60,    30,    61,    -1,    60,    31,
      61,    -1,    60,    32,    61,    -1,    60,    33,    61,    -1,
       4,    -1,     7,    -1,    61,    -1,    60,    -1,     5,    -1,
       8,    -1,    65,    66,    -1,    36,    46,    73,    47,    48,
      53,    49,    -1,    37,    65,    66,    -1,    37,    48,    53,
      49,    -1,    -1,    39,    46,    73,    47,    48,    53,    49,
      -1,    38,    46,    69,    50,    73,    50,    69,    47,    48,
      53,    49,    -1,    77,    12,    60,    -1,    42,    48,    53,
      49,    43,    46,    73,    47,    45,    -1,    40,    46,    77,
      47,    48,    72,    49,    -1,    41,    75,    51,    53,    72,
      -1,    44,    51,    53,    -1,    -1,    74,    21,    74,    -1,
      74,    20,    74,    -1,    74,    25,    74,    -1,    74,    24,
      74,    -1,    74,    23,    74,    -1,    74,    22,    74,    -1,
      76,    -1,    35,    73,    -1,    73,    16,    73,    -1,    73,
      15,    73,    -1,    46,    73,    47,    -1,     3,    -1,     4,
      -1,     5,    -1,     3,    -1,     4,    -1,     5,    -1,    76,
      -1,    13,    -1,    14,    -1,     9,    -1,     7,    -1,     8,
      -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    87,    87,    93,    94,
      97,   101,   105,   109,   113,   118,   123,   127,   131,   134,
     140,   146,   152,   156,   160,   164,   167,   173,   174,   175,
     176,   177,   179,   180,   181,   182,   183,   184,   187,   188,
     192,   193,   194,   195,   196,   197,   199,   200,   201,   202,
     203,   204,   206,   207,   208,   209,   210,   211,   214,   215,
     219,   219,   223,   224,   228,   231,   234,   235,   236,   240,
     243,   246,   249,   252,   255,   256,   256,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   275,   275,
     275,   278,   278,   278,   278,   282,   282,   285,   286,   287,
     288
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "BOOL_ID",
  "FLOAT_ID", "STR_ID", "INT_ID", "CONST", "VAR", "EQUAL", "TRUE", "FALSE",
  "LOGIC_OR", "LOGIC_AND", "'|'", "'^'", "'&'", "NOT_EQ", "EQ", "SM_EQ",
  "SM", "GR_EQ", "GR", "BITWISE_SHIFT_LEFT", "BITWISE_SHIFT_RIGHT", "'+'",
  "'-'", "'*'", "'/'", "'%'", "POW", "'~'", "LOGIC_NOT", "IF", "ELSE",
  "FOR", "WHILE", "SWITCH", "CASE", "REPEAT", "UNTIL", "DEFAULT", "';'",
  "'('", "')'", "'{'", "'}'", "','", "':'", "$accept", "stmt", "variable",
  "id1", "decl_assign", "constant_stmt", "constant", "assignment",
  "int_expr", "float_expr", "float_int_expr", "str_expr",
  "if_else_if_else_stmt", "if_stmt", "else_if_stmt", "while_loop",
  "for_loop", "for_assignment", "repeat_until_loop", "switch_case",
  "case_stmt", "bool_expr", "compare_opd", "value", "boolean", "id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   124,    94,    38,
     272,   273,   274,   275,   276,   277,   278,   279,    43,    45,
      42,    47,    37,   280,   126,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    59,    40,    41,   123,   125,
      44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    56,    57,    58,
      58,    58,    58,    59,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    65,    66,    66,    66,    67,
      68,    69,    70,    71,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    76,    76,    77,    77,    77,
      77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     1,     1,     1,     4,     4,     4,     4,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     2,     7,     3,     4,     0,     7,
      11,     3,     9,     7,     5,     3,     0,     3,     3,     3,
       3,     3,     3,     1,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    78,    15,    14,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    23,    21,    22,    20,     0,    19,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     0,    74,     7,
       6,     8,     9,    98,    99,   100,   105,   106,     0,     0,
       0,     0,    93,    48,    68,    69,    49,     0,    71,    70,
       0,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,   110,   108,   109,   107,     0,
       0,     0,     0,     0,     0,    78,    94,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    97,
      96,    95,    88,    87,    92,    91,    90,    89,    43,    44,
      42,    46,    47,    37,    62,    38,    63,    39,    64,    40,
      65,    41,    66,     0,    67,    56,    50,    57,    51,    58,
      52,    59,    53,    60,    54,    61,    55,    37,    38,    39,
      40,    41,    32,    30,    31,    29,    27,    25,    26,    24,
       0,     0,    81,     0,    86,     0,    77,     0,     0,     0,
       0,     0,     0,     0,    75,     0,    79,   101,   102,   103,
       0,   104,     0,    83,     0,     0,     0,    85,     0,     0,
      86,    82,     0,    84,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    35,    36,    14,    30,    15,    68,    69,
      70,    73,    16,    17,    48,    18,    19,    89,    20,    21,
     212,    60,    61,   220,    62,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
      10,    -2,     3,    12,    13,   152,   160,   -17,    -3,    -1,
       1,    31,    58,    10,    10,    10,    10,    23,    10,    10,
      10,    10,     9,    50,    34,    53,    56,    61,    73,    74,
     -72,    76,   120,   121,   128,    96,   -72,     9,   230,     9,
     230,    10,   -72,   -72,   -72,   -72,   -72,    30,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     9,     9,
      48,   261,   -72,   -72,   -72,   -72,   -72,    53,    80,   171,
     126,   -72,   -72,   137,   125,    69,   158,   178,   181,     9,
      50,    34,    53,   -72,    18,   -72,   -72,   -72,   -72,   136,
     195,    20,   161,   165,    10,    23,   -72,    22,     9,     9,
     -72,    91,    91,    91,    91,    91,    91,   -72,    53,    53,
      53,    53,    53,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,   -72,   -72,    53,    53,    53,
      53,    53,   -72,   166,   170,   190,   208,    60,   209,   246,
     146,   192,     9,    53,   244,   245,   167,   247,   -72,   -72,
     278,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   215,   229,
     248,   117,   117,   219,   257,   219,   257,   262,   264,   262,
     264,   262,   264,    80,   264,   162,   257,   162,   257,   179,
     264,   179,   264,   179,   264,   179,   264,    72,    72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
      10,    11,   200,    10,    36,   252,   -72,   250,   230,   251,
      87,   253,   254,     9,   -72,   255,   -72,   -72,   -72,   -72,
     256,   -72,    10,   -72,    25,   258,    10,   -72,   260,    10,
      36,   -72,   259,   -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -13,   -72,   -72,   -72,   -72,   -72,   -72,     7,   149,
     221,   228,   -72,   263,   216,   -72,   -72,   104,   -72,   -72,
      83,   -28,   119,   -72,   -71,   274
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    44,    45,    46,   133,    49,    50,    51,    52,    84,
      22,    91,    53,    54,    55,    23,     1,     2,     3,     4,
       5,     6,    56,    57,    24,    25,    98,    99,    93,    37,
      96,    97,    74,    98,    99,    98,    99,    98,    99,    71,
      98,    99,    72,    38,    58,    39,     7,    40,     8,     9,
      10,   137,    11,    63,    64,    59,    63,    65,    42,    66,
      47,   208,    66,    98,    99,   141,     7,   144,    75,   149,
     150,   151,   228,    76,   107,    98,    99,   210,    94,    41,
     211,   147,    56,    57,    67,    77,    78,    67,    79,   140,
     217,   218,   219,   100,    53,    54,    55,   108,   109,   110,
      56,    57,   129,   130,   131,   196,   111,   112,   113,   114,
     115,   116,   117,   118,   201,   158,   159,   160,   161,   162,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   181,
     183,   185,    80,    81,   187,   188,   189,   190,   191,   221,
      82,    83,   108,   109,   110,   127,   128,   129,   130,   131,
     202,   111,   112,   127,   128,   129,   130,   131,    26,    27,
      28,    29,   134,   108,   109,   110,    31,    32,    33,    34,
     132,   125,   111,   112,   127,   128,   129,   130,   131,   108,
     109,   110,   126,   135,   136,   224,   142,   207,   111,   112,
     209,   199,   115,   116,   117,   118,   108,   109,   110,   119,
     120,   121,   122,   123,   124,   111,   112,   143,   145,   227,
     205,   192,   118,   230,   146,   193,   232,   108,   109,   110,
     152,   153,   154,   155,   156,   157,   111,   112,   127,   128,
     129,   130,   131,   109,   110,   194,    85,    86,    87,    88,
     200,   111,   112,   127,   128,   129,   130,   131,   110,   115,
     116,   117,   118,   195,   197,   111,   112,   127,   128,   129,
     130,   131,   164,   166,   168,   170,   172,   174,   176,   178,
     180,   182,   184,   186,   111,   112,   127,   128,   129,   130,
     131,   101,   102,   103,   104,   105,   106,   121,   122,   123,
     124,   198,   203,   204,    99,   118,   206,   124,   213,   214,
     216,   138,   225,   223,   222,   231,   229,   226,   234,   139,
      95,   148,   215,   233,    92
};

static const yytype_uint8 yycheck[] =
{
      13,    14,    15,    16,    75,    18,    19,    20,    21,    37,
      12,    39,     3,     4,     5,    12,     6,     7,     8,     9,
      10,    11,    13,    14,    12,    12,    15,    16,    41,    46,
      58,    59,    25,    15,    16,    15,    16,    15,    16,     5,
      15,    16,     8,    46,    35,    46,    36,    46,    38,    39,
      40,    79,    42,     3,     4,    46,     3,     7,     0,     9,
      37,    50,     9,    15,    16,    47,    36,    47,    12,    47,
      98,    99,    47,    12,    67,    15,    16,    41,    48,    48,
      44,    94,    13,    14,    34,    12,    12,    34,    12,    82,
       3,     4,     5,    45,     3,     4,     5,    17,    18,    19,
      13,    14,    30,    31,    32,    45,    26,    27,    28,    29,
      30,    31,    32,    33,   142,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    12,    12,   127,   128,   129,   130,   131,   210,
      12,    45,    17,    18,    19,    28,    29,    30,    31,    32,
     143,    26,    27,    28,    29,    30,    31,    32,     6,     7,
       8,     9,     4,    17,    18,    19,     6,     7,     8,     9,
      45,    45,    26,    27,    28,    29,    30,    31,    32,    17,
      18,    19,    45,     5,     3,   213,    50,   200,    26,    27,
     203,    45,    30,    31,    32,    33,    17,    18,    19,    28,
      29,    30,    31,    32,    33,    26,    27,    12,    47,   222,
      43,    45,    33,   226,    49,    45,   229,    17,    18,    19,
     101,   102,   103,   104,   105,   106,    26,    27,    28,    29,
      30,    31,    32,    18,    19,    45,     6,     7,     8,     9,
      48,    26,    27,    28,    29,    30,    31,    32,    19,    30,
      31,    32,    33,    45,    45,    26,    27,    28,    29,    30,
      31,    32,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    26,    27,    28,    29,    30,    31,
      32,    20,    21,    22,    23,    24,    25,    30,    31,    32,
      33,    45,    48,    48,    16,    33,    49,    33,    46,    49,
      49,    80,    47,    49,    51,    45,    48,    51,    49,    81,
      47,    95,   208,   230,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    36,    38,    39,
      40,    42,    53,    54,    57,    59,    64,    65,    67,    68,
      70,    71,    12,    12,    12,    12,     6,     7,     8,     9,
      58,     6,     7,     8,     9,    55,    56,    46,    46,    46,
      46,    48,     0,    53,    53,    53,    53,    37,    66,    53,
      53,    53,    53,     3,     4,     5,    13,    14,    35,    46,
      73,    74,    76,     3,     4,     7,     9,    34,    60,    61,
      62,     5,     8,    63,    60,    12,    12,    12,    12,    12,
      12,    12,    12,    45,    73,     6,     7,     8,     9,    69,
      77,    73,    77,    53,    48,    65,    73,    73,    15,    16,
      45,    20,    21,    22,    23,    24,    25,    60,    17,    18,
      19,    26,    27,    28,    29,    30,    31,    32,    33,    28,
      29,    30,    31,    32,    33,    45,    45,    28,    29,    30,
      31,    32,    45,    76,     4,     5,     3,    73,    62,    63,
      60,    47,    50,    12,    47,    47,    49,    53,    66,    47,
      73,    73,    74,    74,    74,    74,    74,    74,    60,    60,
      60,    60,    60,    60,    61,    60,    61,    60,    61,    60,
      61,    60,    61,    60,    61,    60,    61,    60,    61,    60,
      61,    60,    61,    60,    61,    60,    61,    60,    60,    60,
      60,    60,    45,    45,    45,    45,    45,    45,    45,    45,
      48,    73,    60,    48,    48,    43,    49,    53,    50,    53,
      41,    44,    72,    46,    49,    69,    49,     3,     4,     5,
      75,    76,    51,    49,    73,    47,    51,    53,    47,    48,
      53,    45,    53,    72,    49
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
    { 
			newSymbolRecord((yyvsp[(1) - (1)].idval),integer,true);
			mainScope.printAll();
			cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 101 "voo.y"
    { 
			newSymbolRecord((yyvsp[(1) - (1)].idval),floatt,true);
			mainScope.printAll();
			cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 105 "voo.y"
    { 
			newSymbolRecord((yyvsp[(1) - (1)].idval),str,true);
			mainScope.printAll();
			cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 109 "voo.y"
    { cout << " bool id " << endl; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 113 "voo.y"
    { 
				newSymbolRecord((yyvsp[(1) - (4)].idval),integer,true);
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 118 "voo.y"
    { 
				newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,true);
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 123 "voo.y"
    { 
				newSymbolRecord((yyvsp[(1) - (4)].idval),str,true);
				mainScope.printAll();
				cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 134 "voo.y"
    { cout << "const int id " << endl;
								NodeWithType* nt=createNewValueNode(NewNodeInt((yyvsp[(3) - (4)].ival)));
								newSymbolRecord((yyvsp[(1) - (4)].idval),integer,false);
								generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
								mainScope.printAll();
								cout<< "ass for int id (const) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].ival)<<endl;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 140 "voo.y"
    { cout << "const float id " << endl;
								NodeWithType* nt=createNewValueNode(NewNodeFloat((yyvsp[(3) - (4)].fval)));
								newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,false);
								generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
								mainScope.printAll();
								cout<< "ass for float id (const) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].fval)<<endl;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 146 "voo.y"
    { cout << "const str id " << endl; 
								NodeWithType* nt=createNewValueNode(NewNodeString((yyvsp[(3) - (4)].sval)));
								newSymbolRecord((yyvsp[(1) - (4)].idval),str,false);
								generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
								mainScope.printAll();
								cout<< "ass for str id (const) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].sval)<<endl;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 152 "voo.y"
    { cout << "const bool id " << endl; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 156 "voo.y"
    { 
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 160 "voo.y"
    { 
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 164 "voo.y"
    { 
				mainScope.printAll();
				cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 173 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 174 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 175 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 176 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 177 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 179 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_AND: " <<endl; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 180 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_OR: " <<endl; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 181 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_xor,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("XOR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_XOR: " <<endl; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 182 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_not,1,(yyvsp[(2) - (2)].nodeval),NULL); generateQuad("NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "BITWISE_NOT: " <<endl; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 183 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_r,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SHFTL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_LEFT: " <<endl; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 184 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_l,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SHFTR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_RIGHT: " <<endl; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 187 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); cout<<"int value"<<endl; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 188 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"int id "<<endl;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 192 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 193 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 194 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 195 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 196 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 197 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 199 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 200 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 201 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 202 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 203 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 204 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 206 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 207 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 208 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 209 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 210 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 211 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 214 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); cout<<"float value"<<endl; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 215 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"float id "<<endl;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 223 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); cout<<"string value"<<endl; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 224 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"string id"<<endl; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 231 "voo.y"
    { cout << "if " <<endl; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 234 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 235 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 236 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 261 "voo.y"
    { (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("COMP",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); generateQuad("JE",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "EQ " <<endl; ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 262 "voo.y"
    { cout << "NOT_EQ " <<endl; ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 263 "voo.y"
    { cout << "GR " <<endl; ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 264 "voo.y"
    { cout << "GR_EQ " <<endl; ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 265 "voo.y"
    { cout << "SM " <<endl; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 266 "voo.y"
    { cout << "SM_EQ " <<endl; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 267 "voo.y"
    { cout << "boolean " <<endl; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 268 "voo.y"
    { cout << "LOGIC_NOT " <<endl; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 269 "voo.y"
    { cout << "LOGIC_AND " <<endl; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 270 "voo.y"
    { cout << "LOGIC_OR " <<endl; ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 271 "voo.y"
    { cout << "Brackets " <<endl; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 275 "voo.y"
    {;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 275 "voo.y"
    {;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 275 "voo.y"
    {;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 282 "voo.y"
    {;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 282 "voo.y"
    {;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 285 "voo.y"
    { cout << " int id " << endl; ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 286 "voo.y"
    { cout << " float id " << endl; ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 287 "voo.y"
    { cout << " str id " << endl; ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 288 "voo.y"
    { cout << " bool id " << endl; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2175 "voo.tab.c"
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
#line 292 "voo.y"


ofstream quad;
int lineNo=0;

void outValue(ValueWithType * vt){
	if(vt->tp==integer) quad << vt->v->iVal << " " ;
	else if (vt->tp==floatt) quad << vt->v->fVal << " " ;
	else if (vt->tp==str) quad << vt->v->sVal << " " ;
	else quad << vt->v->bVal << " " ;
}

void outArg(NodeWithType * arg){
	if(arg->tp==val) outValue(arg->node->val); //send value with type
	else if(arg->tp==identifier) quad << arg-> node->id << " " ;
	else quad << "t" << nodes[arg] <<" ";
}

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 , NodeWithType * res){
	quad << lineNo << " " << op <<" ";
	outArg(arg1);
	
	if(arg2==NULL) quad << " " ;
	else outArg(arg2);
	
	outArg(res);
	
	quad << endl;	
	lineNo++;
	cout<<"quad generated"<<endl;
}

void newSymbolRecord( char * name, IdType ty, bool v_c ){
	SymRec rec ;
	rec.typ=ty;
	rec.VarConst=v_c;
	//rec.value=vlu;
	mainScope.insert(name,&rec); 
}

/*bool updateSymbolRecord(char * name, bool v_c , NodeWithType* vlu  ) {
	//check if it's var not const
	if(v_c){
		//check if it exists
		SymRec * oldRec=mainScope.lookup(name);
		if(oldRec!=NULL){ //update
			//oldRec->typ=ty;
			//oldRec->VarConst=v_c;
			oldRec->value=vlu;
			//mainScope.insert(name,&rec);
			return true;
		}
		else {//handle error -> this variable doesn't exist 
			cout<<"variable doesn't exist" <<endl;
			return false;
		}
	}
	else {//handle error -> this is not a variable  
		cout<<"Constant can't be modified" <<endl;
		return false;
	}
}*/

Node * NewNodeInt(int i){  //create new node and new value and assign this value to a new ValueWithType then assign this ValueWithType to the node  
	Node * nd=new Node();
	Value * v=new Value();
	v->iVal=i;
	ValueWithType * vt= new ValueWithType();
	vt->v=v;
	vt->tp=integer;
	nd->val=vt;
	cout<<"new value node created"<<endl;
	return nd;
}

Node * NewNodeFloat(float i){
	Node * nd=new Node();
	Value * v=new Value();
	v->fVal=i;
	ValueWithType * vt= new ValueWithType();
	vt->v=v;
	vt->tp=floatt;
	nd->val=vt;
	cout<<"new value node created"<<endl;
	return nd;
}

Node * NewNodeString(char * i){
	Node * nd=new Node();
	Value * v=new Value();
	v->sVal=i;
	ValueWithType * vt= new ValueWithType();
	vt->v=v;
	vt->tp=str;
	nd->val=vt;
	cout<<"new value node created"<<endl;
	return nd;
}

Node * NewNodeBool(bool i){
	Node * nd=new Node();
	Value * v=new Value();
	v->bVal=i;
	ValueWithType * vt= new ValueWithType();
	vt->v=v;
	vt->tp=boolean;
	nd->val=vt;
	cout<<"new value node created"<<endl;
	return nd;
}

NodeWithType * createNewValueNode(Node * nd){
	NodeWithType * ndt=new NodeWithType();
	ndt->node=nd;
	ndt->tp=val;
	nodes.insert(pair<NodeWithType*,int>(ndt,cntNodes++));
	return ndt;
}

NodeWithType * createNewIdNode(char* idd){
	Node * nd=new Node();
	nd->id=idd;
	cout<<"new id node created"<<endl;
	NodeWithType * ndt=new NodeWithType();
	ndt->node=nd;
	ndt->tp=identifier;
	nodes.insert(pair<NodeWithType*,int>(ndt,cntNodes++));
	return ndt;
}

NodeWithType * createNewExprNode(oprt op, int n, NodeWithType* oprd1, NodeWithType* oprd2 ){
	expr * ex=new expr();
	ex->opt=op;
	ex->nOps=n;
	ex->opds[0]=oprd1;
	ex->opds[1]=oprd2;
	Node * nd=new Node();
	nd->exp=ex;
	cout<<"new expr node created"<<endl;
	NodeWithType * ndt=new NodeWithType();
	ndt->node=nd;
	ndt->tp=expression;
	nodes.insert(pair<NodeWithType*,int>(ndt,cntNodes++));
	return ndt;
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
		//quadraple();
	} while (!feof(yyin));
	
	quad.close();
	
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}
