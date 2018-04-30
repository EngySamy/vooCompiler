
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
#include <stack>
#include <queue>

using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);

Scope mainScope("global");
map<NodeWithType* , int > nodes;  //after creating id node or expr node we insert it here , to be able to generate quadruples
stack<int> brLabels;
stack<int> ifElseLabels;
stack<int> switchLabels;
stack<NodeWithType*> switchIds;
stack<NodeWithType*> boolRes;

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 ,NodeWithType * res );
void generateBranchQuad(string , int , NodeWithType * );
void generateLabelPair();
int generateOneLabel();
void outLabel(int);

void newSymbolRecord( char *, IdType , bool); 
bool updateSymbolRecord(char *, bool , NodeWithType* ) ;
//bool searchSymbolRecord( char * );
void errorExistsBefore(char *);
void errorDoesntExist(char *);


Node * NewNodeFloat(float );
Node * NewNodeInt(int);
Node * NewNodeString(char *);
Node * NewNodeBool(bool);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0,cntLabels=0;



/* Line 189 of yacc.c  */
#line 130 "voo.tab.c"

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
     DEFAULT = 290,
     DONE = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 62 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;
	bool bval;
	struct NodeWithType * nodeval;



/* Line 214 of yacc.c  */
#line 213 "voo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 225 "voo.tab.c"

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
#define YYLAST   374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  268

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,    19,     2,
      47,    48,    30,    28,    51,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    17,    50,    34,     2,     2,     2,
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
      44,    45
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
     133,   137,   141,   145,   149,   153,   156,   160,   164,   168,
     170,   172,   176,   180,   184,   188,   192,   196,   200,   204,
     208,   212,   216,   220,   224,   228,   232,   236,   240,   244,
     248,   250,   252,   254,   256,   258,   260,   263,   271,   279,
     283,   288,   289,   297,   299,   301,   317,   318,   319,   323,
     324,   335,   338,   342,   346,   348,   350,   352,   356,   360,
     364,   368,   372,   376,   380,   382,   384,   386,   388,   390,
     392,   401,   403,   405,   407,   409,   411,   414,   416,   417,
     424,   427,   431,   433,   435,   437,   439,   441
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    54,    -1,    58,    54,    -1,    60,
      54,    -1,    65,    54,    -1,    72,    54,    -1,    69,    54,
      -1,    76,    54,    -1,    81,    54,    -1,    55,    -1,    58,
      -1,    60,    -1,    65,    -1,    72,    -1,    69,    -1,    76,
      -1,    81,    -1,    11,    56,    46,    -1,    11,    57,    -1,
       9,    -1,     7,    -1,     8,    -1,     6,    -1,     9,    12,
      61,    46,    -1,     7,    12,    63,    46,    -1,     8,    12,
      64,    46,    -1,     6,    12,    78,    46,    -1,    10,    59,
      -1,     9,    12,     3,    46,    -1,     7,    12,     4,    46,
      -1,     8,    12,     5,    46,    -1,     6,    12,    90,    46,
      -1,     9,    12,    61,    46,    -1,     7,    12,    63,    46,
      -1,     8,    12,    64,    46,    -1,     6,    12,    78,    46,
      -1,    61,    28,    61,    -1,    61,    29,    61,    -1,    61,
      30,    61,    -1,    61,    31,    61,    -1,    61,    32,    61,
      -1,    61,    19,    61,    -1,    61,    17,    61,    -1,    61,
      18,    61,    -1,    34,    61,    -1,    61,    26,    61,    -1,
      61,    27,    61,    -1,    47,    61,    48,    -1,     3,    -1,
       9,    -1,    62,    28,    62,    -1,    62,    29,    62,    -1,
      62,    30,    62,    -1,    62,    31,    62,    -1,    62,    32,
      62,    -1,    62,    33,    62,    -1,    62,    28,    61,    -1,
      62,    29,    61,    -1,    62,    30,    61,    -1,    62,    31,
      61,    -1,    62,    32,    61,    -1,    62,    33,    61,    -1,
      61,    28,    62,    -1,    61,    29,    62,    -1,    61,    30,
      62,    -1,    61,    31,    62,    -1,    61,    32,    62,    -1,
      61,    33,    62,    -1,    47,    62,    48,    -1,     4,    -1,
       7,    -1,    62,    -1,    61,    -1,     5,    -1,     8,    -1,
      66,    68,    -1,    36,    70,    78,    71,    49,    54,    50,
      -1,    36,    70,    78,    71,    49,    54,    50,    -1,    37,
      67,    68,    -1,    37,    49,    54,    50,    -1,    -1,    39,
      70,    78,    71,    49,    54,    50,    -1,    47,    -1,    48,
      -1,    38,    47,    75,    51,    73,    78,    74,    48,    49,
      54,    50,    47,    75,    48,    46,    -1,    -1,    -1,     9,
      12,    61,    -1,    -1,    77,    42,    49,    54,    50,    43,
      47,    78,    48,    46,    -1,    35,    78,    -1,    78,    16,
      78,    -1,    78,    15,    78,    -1,    90,    -1,     6,    -1,
      79,    -1,    47,    78,    48,    -1,    80,    21,    80,    -1,
      80,    20,    80,    -1,    80,    25,    80,    -1,    80,    24,
      80,    -1,    80,    23,    80,    -1,    80,    22,    80,    -1,
       3,    -1,     9,    -1,     4,    -1,     7,    -1,     5,    -1,
       8,    -1,    82,    47,    83,    48,    49,    84,    88,    50,
      -1,    40,    -1,     9,    -1,     7,    -1,     8,    -1,     6,
      -1,    85,    84,    -1,    85,    -1,    -1,    41,    89,    52,
      86,    54,    87,    -1,    45,    46,    -1,    44,    52,    54,
      -1,     3,    -1,     4,    -1,     5,    -1,    90,    -1,    13,
      -1,    14,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   111,   112,
     115,   123,   131,   139,   150,   161,   172,   182,   196,   199,
     209,   219,   229,   242,   251,   260,   268,   282,   283,   284,
     285,   286,   288,   289,   290,   291,   292,   293,   295,   296,
     297,   302,   303,   304,   305,   306,   307,   309,   310,   311,
     312,   313,   314,   316,   317,   318,   319,   320,   321,   323,
     324,   325,   330,   330,   333,   334,   339,   345,   358,   369,
     370,   371,   375,   387,   390,   393,   403,   407,   410,   413,
     413,   423,   424,   432,   433,   434,   436,   437,   443,   444,
     445,   446,   447,   448,   452,   453,   455,   456,   458,   459,
     465,   471,   477,   479,   481,   483,   488,   489,   493,   493,
     504,   511,   514,   515,   516,   517,   522,   523
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
  "FOR", "WHILE", "SWITCH", "CASE", "REPEAT", "UNTIL", "DEFAULT", "DONE",
  "';'", "'('", "')'", "'{'", "'}'", "','", "':'", "$accept", "stmt",
  "variable", "id1", "decl_assign", "constant_stmt", "constant",
  "assignment", "int_expr", "float_expr", "float_int_expr", "str_expr",
  "if_else_if_else_stmt", "if_stmt1", "if_stmt", "else_if_stmt",
  "while_loop", "start_while_if", "end_while_if", "for_loop",
  "start_bool_expr", "end_bool_expr", "for_assignment",
  "repeat_until_loop", "$@1", "bool_expr", "bool_term", "compare_opd",
  "switch_case", "start_switch", "id", "case_stmts", "case_stmt", "$@2",
  "done", "defaultt", "value", "boolean", 0
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
     286,   287,   288,   289,   290,   291,    59,    40,    41,   123,
     125,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    57,    57,    57,    57,    58,    59,
      59,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    66,    67,    68,
      68,    68,    69,    70,    71,    72,    73,    74,    75,    77,
      76,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    82,    83,    83,    83,    83,    84,    84,    86,    85,
      87,    88,    89,    89,    89,    89,    90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     1,     1,     1,     4,     4,     4,     4,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     2,     7,     7,     3,
       4,     0,     7,     1,     1,    15,     0,     0,     3,     0,
      10,     2,     3,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       8,     1,     1,     1,     1,     1,     2,     1,     0,     6,
       2,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,    10,    11,    12,    13,    81,    15,    14,    16,
       0,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,    23,    21,    22,    20,     0,    19,    83,     0,
       0,     0,     1,     2,     3,     4,     5,     0,    76,     7,
       6,     8,     0,     9,     0,   104,   106,   108,    95,   107,
     109,   105,   126,   127,     0,     0,     0,    96,     0,    94,
      49,    70,    71,    50,     0,     0,    73,    72,     0,    74,
      75,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    89,    81,
      89,   115,   113,   114,   112,     0,    91,     0,     0,     0,
      36,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,    84,     0,     0,    86,     0,     0,
       0,    79,     0,     0,    97,    93,    92,    99,    98,   103,
     102,   101,   100,    48,    69,    43,    44,    42,    46,    47,
      37,    63,    38,    64,    39,    65,    40,    66,    41,    67,
       0,    68,    57,    51,    58,    52,    59,    53,    60,    54,
      61,    55,    62,    56,    37,    38,    39,    40,    41,    32,
      30,    31,    29,    27,    25,    26,    24,    89,    88,     0,
      89,     0,    80,     0,     0,     0,    87,     0,     0,     0,
       0,     0,   117,    77,     0,    82,    89,     0,   122,   123,
     124,     0,   125,     0,     0,   116,     0,     0,     0,   118,
      89,   110,    89,    78,     0,    89,   121,     0,    90,     0,
       0,     0,   119,     0,   120,     0,     0,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    36,    37,    13,    31,    14,    76,    77,
      78,    81,    15,    16,    99,    48,    17,    39,   155,    18,
     219,   234,    95,    19,    20,    66,    67,    68,    21,    22,
     105,   231,   232,   255,   262,   244,   241,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -86
static const yytype_int16 yypact[] =
{
     131,    25,    46,    49,    63,   140,   264,    32,    40,    32,
     -86,    47,    34,    34,    34,    34,    89,    34,    34,    34,
      -7,    34,    80,    13,    21,    51,    20,   122,   123,   132,
     154,   -86,   156,   168,   169,   173,    38,   -86,   -86,    13,
     134,    13,   -86,   -86,   -86,   -86,   -86,     0,   -86,   -86,
     -86,   -86,   137,   -86,   308,   -86,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,    13,    13,    16,   -86,   327,   -86,
     -86,   -86,   -86,   -86,    20,    21,   250,    64,   141,   -86,
     -86,   149,    20,   199,    52,   192,   202,   194,    13,    21,
      51,    20,   -86,    -2,   207,   170,    -2,    32,   131,    89,
     131,   -86,   -86,   -86,   -86,   174,   -86,    35,    13,    13,
     -86,   337,   337,   337,   337,   337,   337,   -86,   146,   204,
      20,    20,    20,    20,    20,    21,    21,    21,    21,    21,
      21,    21,    21,    21,    21,    21,    21,   -86,   -86,   172,
      20,    20,    20,    20,    20,   -86,   177,   193,   195,   196,
      23,   198,   203,   229,   -86,   201,    20,   -86,   205,    13,
     224,   -86,   248,   252,   -86,   235,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   293,   307,   183,   234,   234,
     297,   323,   297,   323,   220,   266,   220,   266,   220,   266,
     250,   266,    72,   323,    72,   323,   267,   266,   267,   266,
     267,   266,   267,   266,    76,    76,   -86,   -86,   -86,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -86,   131,   278,    13,
     131,    -2,   -86,   259,   262,   263,    66,   268,   282,   285,
     179,   299,   262,   -86,   309,   -86,   131,    13,   -86,   -86,
     -86,   306,   -86,   310,   311,   -86,   314,   315,    37,   -86,
     131,   -86,   131,   -86,   313,   131,   -86,   316,   -86,   319,
     320,   322,   -86,   134,   -86,   312,   324,   -86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -12,   -86,   -86,   -86,   -86,   -86,   -86,   -11,    26,
     280,   281,   -86,   -86,   -86,   273,   -86,     3,   -85,   -86,
     -86,   -86,   110,   -86,   -86,   -31,   -86,   176,   -86,   -86,
     -86,   142,   -86,   -86,   -86,   -86,   -86,   -80
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      43,    44,    45,    46,   146,    49,    50,    51,    93,    53,
      96,   158,    41,   108,   109,    83,    55,    56,    57,    58,
      59,    60,    61,    70,    70,    71,    62,    63,    72,    73,
      73,   108,   109,   106,   107,    52,    97,    23,   108,   109,
       1,     2,     3,     4,     5,     6,   154,    42,    64,    98,
     108,   109,   108,   109,    74,    74,    79,   150,    24,    80,
      65,    25,   110,   117,   118,    62,    63,    82,    75,   213,
       7,   139,     8,     9,    10,    26,   -89,   165,   166,    38,
     153,   108,   109,   164,    92,   254,   160,    40,   162,   120,
     121,   122,   131,   132,   133,   134,   135,   136,   123,   124,
     159,   119,   127,   128,   129,   130,   142,   143,   144,   175,
     176,   177,   178,   179,   180,   182,   184,   186,   188,   190,
     192,   194,   196,   198,   200,   202,    47,    54,   221,   204,
     205,   206,   207,   208,    84,    85,   228,     1,     2,     3,
       4,     5,     6,    94,    86,   218,    27,    28,    29,    30,
     242,   181,   183,   185,   187,   189,   191,   193,   195,   197,
     199,   201,   203,   120,   121,   122,    87,     7,    88,     8,
       9,    10,   123,   124,   125,   126,   127,   128,   129,   130,
      89,    90,   238,   239,   240,    91,   100,   137,   226,   120,
     121,   122,    62,    63,   173,   138,   147,   149,   123,   124,
     140,   141,   142,   143,   144,   225,   248,   148,   227,   123,
     124,   140,   141,   142,   143,   144,   120,   121,   122,   156,
     173,   157,   163,   209,   247,   123,   124,   140,   141,   142,
     143,   144,   131,   132,   133,   134,   135,   136,   256,   210,
     257,   211,   212,   259,   214,   145,   120,   121,   122,   215,
     217,   109,   174,   130,   220,   123,   124,   140,   141,   142,
     143,   144,   140,   141,   142,   143,   144,   120,   121,   122,
      32,    33,    34,    35,   222,   216,   123,   124,   125,   126,
     127,   128,   129,   130,   120,   121,   122,   167,   168,   169,
     170,   171,   172,   123,   124,   120,   121,   122,   223,   136,
     130,   224,   229,   230,   123,   124,   140,   141,   142,   143,
     144,   121,   122,   233,   101,   102,   103,   104,   235,   123,
     124,   140,   141,   142,   143,   144,   122,   127,   128,   129,
     130,   236,   237,   123,   124,   140,   141,   142,   143,   144,
      55,    56,    57,   243,    59,    60,    61,   111,   112,   113,
     114,   115,   116,   133,   134,   135,   136,   246,   249,   258,
     266,   251,   250,   252,   261,   253,   260,   263,   264,   151,
     267,   152,   161,   265,   245
};

static const yytype_uint16 yycheck[] =
{
      12,    13,    14,    15,    84,    17,    18,    19,    39,    21,
      41,    96,     9,    15,    16,    26,     3,     4,     5,     6,
       7,     8,     9,     3,     3,     4,    13,    14,     7,     9,
       9,    15,    16,    64,    65,    42,    36,    12,    15,    16,
       6,     7,     8,     9,    10,    11,    48,     0,    35,    49,
      15,    16,    15,    16,    34,    34,     5,    88,    12,     8,
      47,    12,    46,    74,    75,    13,    14,    47,    47,    46,
      36,    82,    38,    39,    40,    12,    42,   108,   109,    47,
      91,    15,    16,    48,    46,    48,    98,    47,   100,    17,
      18,    19,    28,    29,    30,    31,    32,    33,    26,    27,
      97,    75,    30,    31,    32,    33,    30,    31,    32,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,    37,    47,   159,   140,
     141,   142,   143,   144,    12,    12,   221,     6,     7,     8,
       9,    10,    11,     9,    12,   156,     6,     7,     8,     9,
     230,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    17,    18,    19,    12,    36,    12,    38,
      39,    40,    26,    27,    28,    29,    30,    31,    32,    33,
      12,    12,     3,     4,     5,    12,    49,    46,   219,    17,
      18,    19,    13,    14,    48,    46,     4,     3,    26,    27,
      28,    29,    30,    31,    32,   217,   237,     5,   220,    26,
      27,    28,    29,    30,    31,    32,    17,    18,    19,    12,
      48,    51,    48,    46,   236,    26,    27,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    33,   250,    46,
     252,    46,    46,   255,    46,    46,    17,    18,    19,    46,
      49,    16,    48,    33,    49,    26,    27,    28,    29,    30,
      31,    32,    28,    29,    30,    31,    32,    17,    18,    19,
       6,     7,     8,     9,    50,    46,    26,    27,    28,    29,
      30,    31,    32,    33,    17,    18,    19,   111,   112,   113,
     114,   115,   116,    26,    27,    17,    18,    19,    50,    33,
      33,    49,    43,    41,    26,    27,    28,    29,    30,    31,
      32,    18,    19,    50,     6,     7,     8,     9,    50,    26,
      27,    28,    29,    30,    31,    32,    19,    30,    31,    32,
      33,    49,    47,    26,    27,    28,    29,    30,    31,    32,
       3,     4,     5,    44,     7,     8,     9,    20,    21,    22,
      23,    24,    25,    30,    31,    32,    33,    48,    52,    46,
      48,    50,    52,    49,    45,    50,    50,    47,    46,    89,
      46,    90,    99,   263,   232
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    36,    38,    39,
      40,    54,    55,    58,    60,    65,    66,    69,    72,    76,
      77,    81,    82,    12,    12,    12,    12,     6,     7,     8,
       9,    59,     6,     7,     8,     9,    56,    57,    47,    70,
      47,    70,     0,    54,    54,    54,    54,    37,    68,    54,
      54,    54,    42,    54,    47,     3,     4,     5,     6,     7,
       8,     9,    13,    14,    35,    47,    78,    79,    80,    90,
       3,     4,     7,     9,    34,    47,    61,    62,    63,     5,
       8,    64,    47,    61,    12,    12,    12,    12,    12,    12,
      12,    12,    46,    78,     9,    75,    78,    36,    49,    67,
      49,     6,     7,     8,     9,    83,    78,    78,    15,    16,
      46,    20,    21,    22,    23,    24,    25,    61,    61,    62,
      17,    18,    19,    26,    27,    28,    29,    30,    31,    32,
      33,    28,    29,    30,    31,    32,    33,    46,    46,    61,
      28,    29,    30,    31,    32,    46,    90,     4,     5,     3,
      78,    63,    64,    61,    48,    71,    12,    51,    71,    70,
      54,    68,    54,    48,    48,    78,    78,    80,    80,    80,
      80,    80,    80,    48,    48,    61,    61,    61,    61,    61,
      61,    62,    61,    62,    61,    62,    61,    62,    61,    62,
      61,    62,    61,    62,    61,    62,    61,    62,    61,    62,
      61,    62,    61,    62,    61,    61,    61,    61,    61,    46,
      46,    46,    46,    46,    46,    46,    46,    49,    61,    73,
      49,    78,    50,    50,    49,    54,    78,    54,    71,    43,
      41,    84,    85,    50,    74,    50,    49,    47,     3,     4,
       5,    89,    90,    44,    88,    84,    48,    54,    78,    52,
      52,    50,    49,    50,    48,    86,    54,    54,    46,    54,
      50,    45,    87,    47,    46,    75,    48,    46
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
#line 115 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (1)].idval))==NULL){
					newSymbolRecord((yyvsp[(1) - (1)].idval),integer,true);
					mainScope.printAll();
					cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 123 "voo.y"
    {
				if(mainScope.lookup((yyvsp[(1) - (1)].idval))==NULL){
					newSymbolRecord((yyvsp[(1) - (1)].idval),floatt,true);
					mainScope.printAll();
					cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			  ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 131 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (1)].idval))==NULL){
					newSymbolRecord((yyvsp[(1) - (1)].idval),str,true);
					mainScope.printAll();
					cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 139 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (1)].idval))==NULL){
					newSymbolRecord((yyvsp[(1) - (1)].idval),boolean,true);
					mainScope.printAll();
					cout<< "ass for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 150 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),integer,true);
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						mainScope.printAll();
						cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));	
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 161 "voo.y"
    {
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,true);
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						mainScope.printAll();
						cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 172 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),str,true);
						mainScope.printAll();
						cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 182 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),boolean,true);
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						mainScope.printAll();
						cout<< "ass for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (4)].idval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 199 "voo.y"
    { 
						if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){
							NodeWithType* nt=createNewValueNode(NewNodeInt((yyvsp[(3) - (4)].ival)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),integer,false);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							mainScope.printAll();
							cout<< "ass for int id (const) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].ival)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));	
					;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 209 "voo.y"
    { 
						if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){	
							NodeWithType* nt=createNewValueNode(NewNodeFloat((yyvsp[(3) - (4)].fval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,false);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							mainScope.printAll();
							cout<< "ass for float id (const) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].fval)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));	
					;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 219 "voo.y"
    {
						if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){	
							NodeWithType* nt=createNewValueNode(NewNodeString((yyvsp[(3) - (4)].sval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),str,false);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							mainScope.printAll();
							cout<< "ass for str id (const) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].sval)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));
					;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 229 "voo.y"
    {
						if(mainScope.lookup((yyvsp[(1) - (4)].idval))==NULL){	
							NodeWithType* nt=createNewValueNode(NewNodeBool((yyvsp[(3) - (4)].nodeval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),boolean,false);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							mainScope.printAll();
							cout<< "ass for bool id (const) -> BOOL_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));
					;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 242 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))!=NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorDoesntExist((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 251 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))!=NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorDoesntExist((yyvsp[(1) - (4)].idval));		
			;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 260 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))!=NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
					cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorDoesntExist((yyvsp[(1) - (4)].idval));		
			;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 268 "voo.y"
    { 
				if(mainScope.lookup((yyvsp[(1) - (4)].idval))!=NULL){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						generateQuad("STO",boolRes.top(),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						boolRes.pop();
						cout<< "ass for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorDoesntExist((yyvsp[(1) - (4)].idval));		
			;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 282 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS "  <<endl;} ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 283 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS" <<endl; };}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 284 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL" <<endl; } ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 285 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " <<endl; };}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 286 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " <<endl; };}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 288 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_AND " <<endl;} ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 289 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_OR " <<endl; };}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 290 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_xor,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("XOR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_XOR " <<endl; };}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 291 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_not,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "BITWISE_NOT: " <<endl; };}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 292 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_r,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_LEFT: " <<endl; };}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 293 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_l,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_RIGHT: " <<endl; };}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 295 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);	cout << "Brackets  " <<endl; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 296 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); cout<<"int value"<<endl; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 297 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"int id "<<endl;} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 302 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 303 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 304 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl; } ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 305 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; };}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 306 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; };}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 307 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; };}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 309 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 310 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 311 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl; } ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 312 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; };}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 313 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; };}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 314 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; };}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 316 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 317 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 318 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  };}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 319 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; };}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 320 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; };}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 321 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; };}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 323 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval); cout << "Brackets  " <<endl; ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 324 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); cout<<"float value"<<endl; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 325 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"float id "<<endl;} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 333 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); cout<<"string value"<<endl; ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 334 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"string id"<<endl; }
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));};}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 339 "voo.y"
    {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
	;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 345 "voo.y"
    { 
		cout << "if " <<endl;
		int temp =brLabels.top();
		brLabels.pop();
		int label=generateOneLabel(); //label to jump after else
		ifElseLabels.push(label);
		generateBranchQuad("JMP",label,NULL);
		outLabel(temp);
		brLabels.pop();	
		;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 358 "voo.y"
    { 
		cout << "if " <<endl;
		int temp =brLabels.top();
		brLabels.pop();
		int label=ifElseLabels.top(); //label to jump after else
		generateBranchQuad("JMP",label,NULL);
		outLabel(temp);
		brLabels.pop();	
		;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 369 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 370 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 371 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 375 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		if((yyvsp[(3) - (7)].nodeval)!=NULL){
			generateBranchQuad("JMP",brLabels.top(),NULL);
			outLabel(temp);
		}
		brLabels.pop();	
	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 387 "voo.y"
    {generateLabelPair();;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 390 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 393 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		generateBranchQuad("JMP",brLabels.top(),NULL);
		outLabel(temp);
		brLabels.pop();;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 403 "voo.y"
    {generateLabelPair();;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 407 "voo.y"
    {generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 410 "voo.y"
    {generateQuad("STO",(yyvsp[(3) - (3)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (3)].idval)));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 413 "voo.y"
    {int label=generateOneLabel(); outLabel(label); brLabels.push(label);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 414 "voo.y"
    {
		generateBranchQuad("JTRUE",brLabels.top(),boolRes.top()); 
		boolRes.pop();
		brLabels.pop();
	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 423 "voo.y"
    { cout << "LOGIC_NOT " <<endl; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 424 "voo.y"
    { 
						(yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));
						if((yyval.nodeval)!=NULL){
							generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
							boolRes.push((yyval.nodeval)); 						
							cout << "LOGIC_AND " <<endl;
						}
					;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 432 "voo.y"
    { cout << "LOGIC_OR " <<endl; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 433 "voo.y"
    { cout << "boolean " <<endl; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 434 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"bool id "<<endl;} 
			  else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 436 "voo.y"
    {(yyval.nodeval)=(yyvsp[(1) - (1)].nodeval);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 437 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);  cout << "Brackets " <<endl; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 443 "voo.y"
    { (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "EQ " <<endl; };}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 444 "voo.y"
    { (yyval.nodeval)=createNewExprNode(ne,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("NOT_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "NOT_EQ " <<endl; };}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 445 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gt,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR " <<endl; };}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 446 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gte,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR_EQ " <<endl; };}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 447 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sm,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM " <<endl; };}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 448 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sme,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM_EQ " <<endl; };}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 452 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival)));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 453 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"int id "<<endl;} 
			else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 455 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 456 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"float id "<<endl;} 
				else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 458 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 459 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"str id "<<endl;} 
			else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 465 "voo.y"
    {
		outLabel(switchLabels.top());
		switchLabels.pop();
	;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 471 "voo.y"
    {
		int label = generateOneLabel();
		switchLabels.push(label);
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 477 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval)); cout<<"int id "<<endl;} 
			else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 479 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval)); cout<<"float id "<<endl;} 
				  else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 481 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval)); cout<<"str id "<<endl;} 
				else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 483 "voo.y"
    { if(mainScope.lookup((yyvsp[(1) - (1)].idval))!=NULL){(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval)); cout<<"bool id "<<endl;} 
				else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 493 "voo.y"
    {
			int l=generateOneLabel();
			brLabels.push(l);
			NodeWithType* vv=createNewExprNode(eq,2,switchIds.top(),(yyvsp[(2) - (3)].nodeval)); 
			generateQuad("EQ",switchIds.top(),(yyvsp[(2) - (3)].nodeval),vv);
			generateBranchQuad("JFALSE",brLabels.top(),vv);
		;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 504 "voo.y"
    {
		generateBranchQuad("JMP",switchLabels.top(),NULL);
		outLabel(brLabels.top());
		brLabels.pop();
	;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 514 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 515 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 516 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 522 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); /*cout<<"bool value"<<endl;*/ ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 523 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); /*cout<<"bool value"<<endl;*/ ;}
    break;



/* Line 1455 of yacc.c  */
#line 2580 "voo.tab.c"
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
#line 526 "voo.y"


ofstream quad;
int lineNo=0;

void outValue(ValueWithType * vt){
	if(vt->tp==integer) quad << vt->v->iVal << ", " ;
	else if (vt->tp==floatt) quad << vt->v->fVal << ", " ;
	else if (vt->tp==str) quad << vt->v->sVal << ", " ;
	else quad << vt->v->bVal << " " ;
}

void outArg(NodeWithType * arg){
	if(arg->tp==val) outValue(arg->node->val); //send value with type
	else if(arg->tp==identifier) quad << arg-> node->id << ", " ;
	else quad << "t" << nodes[arg] <<", ";
}

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 , NodeWithType * res){
	quad << lineNo << " " << op <<", ";
	outArg(arg1);
	
	if(arg2==NULL) quad << ", " ;
	else outArg(arg2);
	
	outArg(res);
	
	quad << endl;	
	lineNo++;
	cout<<"quad generated"<<endl;
}

void generateBranchQuad(string br , int label ,  NodeWithType * cond){
	quad << lineNo << " " << br <<", L"<<label <<", ";
	
	if(cond==NULL) quad << ", " ;
	else outArg(cond);
	
	quad<<endl;
	lineNo++;
}

void generateLabelPair(){
	quad<<"L" <<cntLabels<<": " <<endl;
	brLabels.push(cntLabels);
	cntLabels++;
	brLabels.push(cntLabels);
	cntLabels++;
}
int generateOneLabel(){
	return cntLabels++;
}

void outLabel(int label){
	quad<<"L" <<label<<": " <<endl;
}

void newSymbolRecord( char * name, IdType ty, bool v_c ){
	SymRec rec ;
	rec.typ=ty;
	rec.VarConst=v_c;
	//rec.value=vlu;
	mainScope.insert(name,&rec); 
}

/*bool searchSymbolRecord( char * name){
	SymRec* s=mainScope.lookup(name);
	if(s==NULL) return false;
	else {
		
		return true;
	}
}
*/
void errorExistsBefore(char * name){
	cout<<"There exists a variable with the same name! '"<< name <<"'"<<endl;
}

void errorDoesntExist(char * name){
	cout<<"This variable has not been declared ! '"<< name <<"'"<<endl;
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
	//cout<<"new value node created"<<endl;
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
	//cout<<"new value node created"<<endl;
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
	//cout<<"new value node created"<<endl;
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
	//cout<<"new value node created"<<endl;
	return nd;
}

NodeWithType * createNewValueNode(Node * nd){
	NodeWithType * ndt=new NodeWithType();
	ndt->node=nd;
	ndt->tp=val;
	//nodes.insert(pair<NodeWithType*,int>(ndt,cntNodes++));
	return ndt;
}

NodeWithType * createNewIdNode(char* idd){
	Node * nd=new Node();
	nd->id=idd;
	//cout<<"new id node created"<<endl;
	NodeWithType * ndt=new NodeWithType();
	ndt->node=nd;
	ndt->tp=identifier;
	nodes.insert(pair<NodeWithType*,int>(ndt,cntNodes++));
	return ndt;
}

NodeWithType * createNewExprNode(oprt op, int n, NodeWithType* oprd1, NodeWithType* oprd2 ){
	if(oprd1==NULL || oprd2 ==NULL)
		return NULL;
	expr * ex=new expr();
	ex->opt=op;
	ex->nOps=n;
	ex->opds[0]=oprd1;
	ex->opds[1]=oprd2;
	Node * nd=new Node();
	nd->exp=ex;
	//cout<<"new expr node created"<<endl;
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
