
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
//queue<NodeWithType *> boolQuads;
//queue<string> boolQuadsOp;
stack<NodeWithType*> boolRes;

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 ,NodeWithType * res );
void generateBranchQuad(string , int , NodeWithType * );
void generateLabelPair();
int generateOneLabel();
void outLabel(int);

void newSymbolRecord( char *, IdType , bool); 
bool updateSymbolRecord(char *, bool , NodeWithType* ) ;
Node * NewNodeFloat(float );
Node * NewNodeInt(int);
Node * NewNodeString(char *);
Node * NewNodeBool(bool);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0,cntLabels=0;



/* Line 189 of yacc.c  */
#line 125 "voo.tab.c"

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
#line 57 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;
	bool bval;
	struct NodeWithType * nodeval;



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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNRULES -- Number of states.  */
#define YYNSTATES  252

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
     244,   246,   248,   250,   252,   255,   265,   273,   277,   282,
     283,   291,   293,   295,   311,   312,   313,   317,   327,   335,
     341,   345,   346,   349,   353,   357,   359,   361,   363,   367,
     371,   375,   379,   383,   387,   389,   391,   393,   395,   397,
     399,   401,   403,   405,   407,   409,   411,   413,   415,   417
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    54,    53,    -1,    57,    53,    -1,    59,
      53,    -1,    64,    53,    -1,    71,    53,    -1,    68,    53,
      -1,    75,    53,    -1,    76,    53,    -1,    54,    -1,    57,
      -1,    59,    -1,    64,    -1,    71,    -1,    68,    -1,    75,
      -1,    76,    -1,    11,    55,    45,    -1,    11,    56,    -1,
       9,    -1,     7,    -1,     8,    -1,     6,    -1,     9,    12,
      60,    45,    -1,     7,    12,    62,    45,    -1,     8,    12,
      63,    45,    -1,     6,    12,    78,    45,    -1,    10,    58,
      -1,     9,    12,     3,    45,    -1,     7,    12,     4,    45,
      -1,     8,    12,     5,    45,    -1,     6,    12,    82,    45,
      -1,     9,    12,    60,    45,    -1,     7,    12,    62,    45,
      -1,     8,    12,    63,    45,    -1,     6,    12,    78,    45,
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
       8,    -1,    65,    67,    -1,    36,    46,    72,    78,    73,
      47,    48,    53,    49,    -1,    36,    69,    78,    70,    48,
      53,    49,    -1,    37,    66,    67,    -1,    37,    48,    53,
      49,    -1,    -1,    39,    69,    78,    70,    48,    53,    49,
      -1,    46,    -1,    47,    -1,    38,    46,    74,    50,    72,
      78,    73,    47,    48,    53,    49,    46,    74,    47,    45,
      -1,    -1,    -1,     9,    12,    60,    -1,    42,    48,    53,
      49,    43,    46,    78,    47,    45,    -1,    40,    46,    83,
      47,    48,    77,    49,    -1,    41,    81,    51,    53,    77,
      -1,    44,    51,    53,    -1,    -1,    35,    78,    -1,    78,
      16,    78,    -1,    78,    15,    78,    -1,    82,    -1,     6,
      -1,    79,    -1,    80,    21,    80,    -1,    80,    20,    80,
      -1,    80,    25,    80,    -1,    80,    24,    80,    -1,    80,
      23,    80,    -1,    80,    22,    80,    -1,     3,    -1,     9,
      -1,     4,    -1,     7,    -1,     5,    -1,     8,    -1,     3,
      -1,     4,    -1,     5,    -1,    82,    -1,    13,    -1,    14,
      -1,     9,    -1,     7,    -1,     8,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   106,   107,
     110,   114,   118,   122,   126,   131,   136,   140,   144,   147,
     153,   159,   165,   169,   173,   177,   180,   189,   190,   191,
     192,   193,   195,   196,   197,   198,   199,   200,   203,   204,
     208,   209,   210,   211,   212,   213,   215,   216,   217,   218,
     219,   220,   222,   223,   224,   225,   226,   227,   230,   231,
     235,   235,   239,   240,   244,   250,   263,   274,   275,   276,
     280,   290,   293,   296,   306,   310,   313,   316,   319,   322,
     323,   323,   328,   329,   334,   335,   336,   337,   344,   347,
     350,   351,   352,   353,   357,   358,   359,   360,   361,   362,
     365,   365,   365,   365,   369,   370,   373,   374,   375,   376
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
  "if_else_if_else_stmt", "if_stmt1", "if_stmt", "else_if_stmt",
  "while_loop", "start_while_if", "end_while_if", "for_loop",
  "start_bool_expr", "end_bool_expr", "for_assignment",
  "repeat_until_loop", "switch_case", "case_stmt", "bool_expr",
  "bool_term", "compare_opd", "value", "boolean", "id", 0
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
      62,    62,    63,    63,    64,    65,    66,    67,    67,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      77,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      81,    81,    81,    81,    82,    82,    83,    83,    83,    83
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
       1,     1,     1,     1,     2,     9,     7,     3,     4,     0,
       7,     1,     1,    15,     0,     0,     3,     9,     7,     5,
       3,     0,     2,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    79,    15,    14,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    23,    21,    22,    20,     0,    19,    84,     0,    81,
       0,     0,     0,     1,     2,     3,     4,     5,     0,    74,
       7,     6,     8,     9,   104,   106,   108,    96,   107,   109,
     105,   114,   115,     0,     0,    97,     0,    95,    48,    68,
      69,    49,     0,    71,    70,     0,    72,    73,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,   119,   117,   118,   116,     0,     0,     0,
       0,    79,    92,     0,     0,    36,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,    84,    82,
       0,     0,     0,     0,     0,    77,    94,    93,    99,    98,
     103,   102,   101,   100,    43,    44,    42,    46,    47,    37,
      62,    38,    63,    39,    64,    40,    65,    41,    66,     0,
      67,    56,    50,    57,    51,    58,    52,    59,    53,    60,
      54,    61,    55,    37,    38,    39,    40,    41,    32,    30,
      31,    29,    27,    25,    26,    24,     0,    86,     0,     0,
      91,     0,     0,    78,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,    80,   110,   111,   112,     0,   113,
       0,    88,     0,     0,     0,     0,     0,    90,     0,     0,
      75,     0,    91,    87,    76,     0,    89,     0,     0,     0,
       0,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,    35,    36,    14,    30,    15,    73,    74,
      75,    78,    16,    17,   101,    49,    18,    40,   150,    19,
      89,   206,    91,    20,    21,   219,    64,    65,    66,   228,
      67,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
       7,    -2,     0,    20,    30,   161,   185,   -27,     5,    15,
      24,    40,    80,     7,     7,     7,     7,    61,     7,     7,
       7,     7,    17,    32,    69,    41,   104,   111,   112,   133,
     -72,   142,   143,   151,   159,    99,   -72,   -72,   141,   -72,
      17,   198,     7,   -72,   -72,   -72,   -72,   -72,    -8,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,    17,    39,   -72,   242,   -72,   -72,   -72,
     -72,   -72,    41,    64,   209,   131,   -72,   -72,   150,   108,
      43,   204,   213,   216,    17,    32,    69,    41,   -72,    17,
     269,   232,    18,   -72,   -72,   -72,   -72,   236,   235,    15,
       7,    61,   -72,    17,    17,   -72,   178,   178,   178,   178,
     178,   178,   -72,    41,    41,    41,    41,    41,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
     -72,   -72,    41,    41,    41,    41,    41,   -72,   240,   241,
     243,   245,    44,   246,   247,   130,    70,    41,   -72,   -72,
     239,   249,   250,    17,   251,   -72,   273,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   203,   217,   184,   100,   100,   194,
     244,   194,   244,   261,   262,   261,   262,   261,   262,    64,
     262,   147,   244,   147,   244,    45,   262,    45,   262,    45,
     262,    45,   262,   248,   248,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   252,   171,    17,     7,
      35,   255,    18,   -72,   254,    70,   256,   138,   253,   257,
      17,   259,     7,   263,   -72,   -72,   -72,   -72,   258,   -72,
       7,   -72,    22,     7,   264,   260,     7,   -72,   266,   265,
     -72,     7,    35,   -72,   -72,   267,   -72,   271,   141,   268,
     274,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -13,   -72,   -72,   -72,   -72,   -72,   -72,   -14,   132,
     211,   212,   -72,   -72,   -72,   202,   -72,   219,   109,   -72,
     164,   105,    74,   -72,   -72,    81,   -36,   -72,   162,   -72,
     -71,   -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    45,    46,    47,    92,    50,    51,    52,    53,   138,
      22,    79,    23,     1,     2,     3,     4,     5,     6,    37,
      54,    55,    56,    57,    58,    59,    60,   102,    99,    98,
      61,    62,    24,   103,   104,    68,    69,   103,   104,    70,
     100,    71,    25,     7,    68,     8,     9,    10,   142,    11,
      71,    38,    63,   146,   103,   104,    61,    62,   112,   103,
     104,    39,   113,   114,   115,   149,    72,   156,   157,   238,
      41,   116,   117,   145,    76,    72,   217,    77,   123,   218,
      43,   113,   114,   115,   105,   103,   104,   154,    42,   202,
     116,   117,   118,   119,   120,   121,   122,   123,    48,   164,
     165,   166,   167,   168,   169,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   189,   191,    80,   212,   193,   194,
     195,   196,   197,    81,    82,   113,   114,   115,   132,   133,
     134,   135,   136,   207,   116,   117,   132,   133,   134,   135,
     136,   225,   226,   227,    88,    83,   229,   113,   114,   115,
      90,    61,    62,   137,    84,    85,   116,   117,   132,   133,
     134,   135,   136,    86,   113,   114,   115,    26,    27,    28,
      29,    87,   215,   116,   117,   205,   130,   120,   121,   122,
     123,    54,    55,    56,   232,    58,    59,    60,   113,   114,
     115,    31,    32,    33,    34,   131,   216,   116,   117,   132,
     133,   134,   135,   136,    93,    94,    95,    96,   139,   234,
     116,   117,   132,   133,   134,   135,   136,   237,   140,   141,
     239,   114,   115,   242,   120,   121,   122,   123,   245,   116,
     117,   132,   133,   134,   135,   136,   115,   124,   125,   126,
     127,   128,   129,   116,   117,   132,   133,   134,   135,   136,
     170,   172,   174,   176,   178,   180,   182,   184,   186,   188,
     190,   192,   106,   107,   108,   109,   110,   111,   158,   159,
     160,   161,   162,   163,   126,   127,   128,   129,   134,   135,
     136,   147,   148,   151,   152,   198,   199,   209,   200,   104,
     201,   203,   204,   211,   123,   129,   143,   210,   144,   214,
     213,   220,   222,   155,   230,   224,   231,   233,   241,   236,
     235,   243,   208,   240,   244,   250,   247,   248,   153,   251,
     223,   221,   249,   246
};

static const yytype_uint8 yycheck[] =
{
      13,    14,    15,    16,    40,    18,    19,    20,    21,    80,
      12,    25,    12,     6,     7,     8,     9,    10,    11,    46,
       3,     4,     5,     6,     7,     8,     9,    63,    36,    42,
      13,    14,    12,    15,    16,     3,     4,    15,    16,     7,
      48,     9,    12,    36,     3,    38,    39,    40,    84,    42,
       9,    46,    35,    89,    15,    16,    13,    14,    72,    15,
      16,    46,    17,    18,    19,    47,    34,   103,   104,    47,
      46,    26,    27,    87,     5,    34,    41,     8,    33,    44,
       0,    17,    18,    19,    45,    15,    16,   100,    48,    45,
      26,    27,    28,    29,    30,    31,    32,    33,    37,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,    12,   153,   132,   133,
     134,   135,   136,    12,    12,    17,    18,    19,    28,    29,
      30,    31,    32,   147,    26,    27,    28,    29,    30,    31,
      32,     3,     4,     5,    45,    12,   217,    17,    18,    19,
       9,    13,    14,    45,    12,    12,    26,    27,    28,    29,
      30,    31,    32,    12,    17,    18,    19,     6,     7,     8,
       9,    12,   208,    26,    27,    45,    45,    30,    31,    32,
      33,     3,     4,     5,   220,     7,     8,     9,    17,    18,
      19,     6,     7,     8,     9,    45,   209,    26,    27,    28,
      29,    30,    31,    32,     6,     7,     8,     9,     4,   222,
      26,    27,    28,    29,    30,    31,    32,   230,     5,     3,
     233,    18,    19,   236,    30,    31,    32,    33,   241,    26,
      27,    28,    29,    30,    31,    32,    19,    28,    29,    30,
      31,    32,    33,    26,    27,    28,    29,    30,    31,    32,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,    20,    21,    22,    23,    24,    25,   106,   107,
     108,   109,   110,   111,    30,    31,    32,    33,    30,    31,
      32,    12,    50,    47,    49,    45,    45,    48,    45,    16,
      45,    45,    45,    43,    33,    33,    85,    48,    86,    47,
      49,    46,    48,   101,    51,    49,    49,    48,    48,    51,
      47,    45,   148,    49,    49,    47,    49,    46,    99,    45,
     215,   212,   248,   242
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,     8,     9,    10,    11,    36,    38,    39,
      40,    42,    53,    54,    57,    59,    64,    65,    68,    71,
      75,    76,    12,    12,    12,    12,     6,     7,     8,     9,
      58,     6,     7,     8,     9,    55,    56,    46,    46,    46,
      69,    46,    48,     0,    53,    53,    53,    53,    37,    67,
      53,    53,    53,    53,     3,     4,     5,     6,     7,     8,
       9,    13,    14,    35,    78,    79,    80,    82,     3,     4,
       7,     9,    34,    60,    61,    62,     5,     8,    63,    60,
      12,    12,    12,    12,    12,    12,    12,    12,    45,    72,
       9,    74,    78,     6,     7,     8,     9,    83,    53,    36,
      48,    66,    78,    15,    16,    45,    20,    21,    22,    23,
      24,    25,    60,    17,    18,    19,    26,    27,    28,    29,
      30,    31,    32,    33,    28,    29,    30,    31,    32,    33,
      45,    45,    28,    29,    30,    31,    32,    45,    82,     4,
       5,     3,    78,    62,    63,    60,    78,    12,    50,    47,
      70,    47,    49,    69,    53,    67,    78,    78,    80,    80,
      80,    80,    80,    80,    60,    60,    60,    60,    60,    60,
      61,    60,    61,    60,    61,    60,    61,    60,    61,    60,
      61,    60,    61,    60,    61,    60,    61,    60,    61,    60,
      61,    60,    61,    60,    60,    60,    60,    60,    45,    45,
      45,    45,    45,    45,    45,    45,    73,    60,    72,    48,
      48,    43,    78,    49,    47,    78,    53,    41,    44,    77,
      46,    70,    48,    73,    49,     3,     4,     5,    81,    82,
      51,    49,    78,    48,    53,    47,    51,    53,    47,    53,
      49,    48,    53,    45,    49,    53,    77,    49,    46,    74,
      47,    45
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
#line 110 "voo.y"
    { 
			newSymbolRecord((yyvsp[(1) - (1)].idval),integer,true);
			mainScope.printAll();
			cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 114 "voo.y"
    { 
			newSymbolRecord((yyvsp[(1) - (1)].idval),floatt,true);
			mainScope.printAll();
			cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 118 "voo.y"
    { 
			newSymbolRecord((yyvsp[(1) - (1)].idval),str,true);
			mainScope.printAll();
			cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 122 "voo.y"
    { cout << " bool id " << endl; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 126 "voo.y"
    { 
				newSymbolRecord((yyvsp[(1) - (4)].idval),integer,true);
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 131 "voo.y"
    { 
				newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,true);
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 136 "voo.y"
    { 
				newSymbolRecord((yyvsp[(1) - (4)].idval),str,true);
				mainScope.printAll();
				cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 147 "voo.y"
    { cout << "const int id " << endl;
								NodeWithType* nt=createNewValueNode(NewNodeInt((yyvsp[(3) - (4)].ival)));
								newSymbolRecord((yyvsp[(1) - (4)].idval),integer,false);
								generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
								mainScope.printAll();
								cout<< "ass for int id (const) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].ival)<<endl;;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 153 "voo.y"
    { cout << "const float id " << endl;
								NodeWithType* nt=createNewValueNode(NewNodeFloat((yyvsp[(3) - (4)].fval)));
								newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,false);
								generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
								mainScope.printAll();
								cout<< "ass for float id (const) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].fval)<<endl;;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 159 "voo.y"
    { cout << "const str id " << endl; 
								NodeWithType* nt=createNewValueNode(NewNodeString((yyvsp[(3) - (4)].sval)));
								newSymbolRecord((yyvsp[(1) - (4)].idval),str,false);
								generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
								mainScope.printAll();
								cout<< "ass for str id (const) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].sval)<<endl;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 165 "voo.y"
    { cout << "const bool id " << endl; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 169 "voo.y"
    { 
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 173 "voo.y"
    { 
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 177 "voo.y"
    { 
				mainScope.printAll();
				cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 180 "voo.y"
    { 
				generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
				mainScope.printAll();
				cout<< "ass for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 189 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 190 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 191 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 192 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 193 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 195 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_AND: " <<endl; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 196 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_OR: " <<endl; ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 197 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_xor,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("XOR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_XOR: " <<endl; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 198 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_not,1,(yyvsp[(2) - (2)].nodeval),NULL); generateQuad("NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "BITWISE_NOT: " <<endl; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 199 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_r,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SHFTL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_LEFT: " <<endl; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 200 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_l,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SHFTR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_RIGHT: " <<endl; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 203 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); cout<<"int value"<<endl; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 204 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"int id "<<endl;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 208 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 209 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 210 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 211 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 212 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 213 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 215 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 216 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 217 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 218 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 219 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 220 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 222 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 223 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 224 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 225 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 226 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 227 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 230 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); cout<<"float value"<<endl; ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 231 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"float id "<<endl;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 239 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); cout<<"string value"<<endl; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 240 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"string id"<<endl; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 244 "voo.y"
    {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
		;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 250 "voo.y"
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

  case 76:

/* Line 1455 of yacc.c  */
#line 263 "voo.y"
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

  case 77:

/* Line 1455 of yacc.c  */
#line 274 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 275 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 276 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 280 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		generateBranchQuad("JMP",brLabels.top(),NULL);
		outLabel(temp);
		brLabels.pop();	
		;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 290 "voo.y"
    {generateLabelPair();;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 293 "voo.y"
    {generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 296 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		generateBranchQuad("JMP",brLabels.top(),NULL);
		outLabel(temp);
		brLabels.pop();;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 306 "voo.y"
    {generateLabelPair();;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 310 "voo.y"
    {generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 313 "voo.y"
    {generateQuad("STO",(yyvsp[(3) - (3)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (3)].idval)));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 328 "voo.y"
    { cout << "LOGIC_NOT " <<endl; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 329 "voo.y"
    { 
						(yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));
						generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
						boolRes.push((yyval.nodeval)); 						
						cout << "LOGIC_AND " <<endl; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 334 "voo.y"
    { cout << "LOGIC_OR " <<endl; ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 335 "voo.y"
    { cout << "boolean " <<endl; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 336 "voo.y"
    { (yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"bool id"<<endl; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 344 "voo.y"
    { (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); 								 
								generateQuad("EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
								cout << "EQ " <<endl; ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 347 "voo.y"
    { (yyval.nodeval)=createNewExprNode(ne,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); 
									generateQuad("NOT_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); 
									cout << "NOT_EQ " <<endl; ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 350 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gt,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("GR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR " <<endl; ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 351 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gte,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("GR_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR_EQ " <<endl; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 352 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sm,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SM",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM " <<endl; ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 353 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sme,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); generateQuad("SM_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM_EQ " <<endl; ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 357 "voo.y"
    {;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 358 "voo.y"
    {(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"compare id in bool expr"<<endl;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 359 "voo.y"
    {;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 360 "voo.y"
    {(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"compare id in bool expr"<<endl;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 361 "voo.y"
    {;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 362 "voo.y"
    {(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); cout<<"compare id in bool expr"<<endl;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 369 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); cout<<"bool value"<<endl; ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 370 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); cout<<"bool value"<<endl; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 373 "voo.y"
    { cout << " int id " << endl; ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 374 "voo.y"
    { cout << " float id " << endl; ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 375 "voo.y"
    { cout << " str id " << endl; ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 376 "voo.y"
    { cout << " bool id " << endl; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2334 "voo.tab.c"
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
#line 380 "voo.y"


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
	//nodes.insert(pair<NodeWithType*,int>(ndt,cntNodes++));
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
