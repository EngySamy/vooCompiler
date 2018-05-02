
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
extern int line_num;
 
void yyerror(const char *s);

Scope mainScope("global");
map<NodeWithType* , int > nodes;  //after creating id node or expr node we insert it here , to be able to generate quadruples
stack<int> brLabels;
stack<int> ifElseLabels;
stack<int> switchLabels;
stack<NodeWithType*> switchIds;  //id of switch case 
stack<NodeWithType*> boolRes;
queue<char *> unInit;

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 ,NodeWithType * res );
void generateBranchQuad(string , int , NodeWithType * );
void generateLabelPair();
int generateOneLabel();
void outLabel(int);

void newSymbolRecord( char *, IdType , bool , bool);
void updateSymbolRecordInit(char *); 
void updateSymbolRecordUsed(char *);
bool updateSymbolRecord(char *, bool , NodeWithType* ) ;

void errorExistsBefore(char *);
void errorDoesntExist(char *);
void errorUnInitVar();
void errorConstNotVar(char *);
void errorVarStmt();
void errorConstStmt();
void errorTypeMismatch();
void errorOperandsTypeMismatch();

void assignmentActions(char * , NodeWithType* ,IdType ); 
void declAssignmentActions(char * id, NodeWithType* expr,IdType);
void declIdActions(char *,IdType);
NodeWithType* newIdActions(char *);

IdType getIdTypeForId(NodeWithType* );
IdType getIdTypeForUnknownNode(NodeWithType* );
bool compareTwoOperandsTypes(NodeWithType* , NodeWithType* );

Node * NewNodeFloat(float );
Node * NewNodeInt(int);
Node * NewNodeString(char *);
Node * NewNodeBool(bool);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0,cntLabels=0;



/* Line 189 of yacc.c  */
#line 148 "voo.tab.c"

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
     UMINUS = 282,
     IF = 283,
     ELSE = 284,
     FOR = 285,
     WHILE = 286,
     SWITCH = 287,
     CASE = 288,
     REPEAT = 289,
     UNTIL = 290,
     DEFAULT = 291,
     DONE = 292,
     ENDL = 293,
     START_DECL = 294,
     END_DECL = 295
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 80 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;
	bool bval;
	struct NodeWithType * nodeval;



/* Line 214 of yacc.c  */
#line 235 "voo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 247 "voo.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   801

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNRULES -- Number of states.  */
#define YYNSTATES  455

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,    19,     2,
      51,    52,    30,    28,    55,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    17,    54,    34,     2,     2,     2,
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
      44,    45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    13,    16,    19,    22,    25,    28,
      30,    32,    34,    36,    38,    40,    42,    44,    47,    50,
      55,    59,    60,    66,    68,    70,    72,    74,    79,    84,
      89,    94,    98,    99,   105,   110,   115,   120,   125,   126,
     133,   134,   141,   147,   153,   154,   161,   162,   169,   170,
     177,   178,   185,   188,   192,   196,   200,   204,   208,   212,
     216,   220,   223,   227,   231,   235,   237,   239,   243,   247,
     251,   255,   259,   263,   267,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   307,   311,   315,   317,   319,   321,
     323,   325,   327,   331,   340,   344,   349,   355,   362,   371,
     380,   384,   385,   391,   392,   399,   400,   408,   409,   419,
     423,   429,   430,   435,   445,   446,   452,   453,   461,   462,
     471,   472,   483,   485,   487,   505,   506,   513,   514,   522,
     523,   536,   537,   551,   552,   568,   569,   586,   587,   605,
     606,   625,   626,   627,   631,   643,   644,   651,   652,   661,
     662,   673,   674,   686,   687,   700,   702,   705,   709,   713,
     715,   717,   719,   723,   727,   731,   735,   739,   743,   747,
     749,   751,   753,   755,   757,   759,   760,   772,   773,   779,
     780,   787,   788,   796,   797,   806,   807,   818,   820,   822,
     824,   826,   828,   831,   833,   834,   842,   846,   851,   853,
     855,   857,   859,   861,   863,   866
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    48,   133,    60,    49,   133,    59,    -1,
      59,    68,    -1,    59,    79,    -1,    59,    95,    -1,    59,
      88,    -1,    59,   107,    -1,    59,   117,    -1,    68,    -1,
      79,    -1,    95,    -1,    88,    -1,   107,    -1,   117,    -1,
      61,    -1,    65,    -1,    60,    61,    -1,    60,    65,    -1,
      11,    63,    50,   133,    -1,    11,    64,   133,    -1,    -1,
      11,     1,    50,    62,   133,    -1,     9,    -1,     7,    -1,
       8,    -1,     6,    -1,     9,    12,    75,    50,    -1,     7,
      12,    77,    50,    -1,     8,    12,    78,    50,    -1,     6,
      12,   114,    50,    -1,    10,    67,   133,    -1,    -1,    10,
       1,    50,    66,   133,    -1,     9,    12,     3,    50,    -1,
       7,    12,     4,    50,    -1,     8,    12,     5,    50,    -1,
       6,    12,   132,    50,    -1,    -1,     9,    12,    75,    50,
      69,   133,    -1,    -1,     7,    12,    77,    50,    70,   133,
      -1,     8,    12,    78,    50,   133,    -1,     6,    12,   114,
      50,   133,    -1,    -1,     9,    12,     1,    50,    71,   133,
      -1,    -1,     7,    12,     1,    50,    72,   133,    -1,    -1,
       8,    12,     1,    50,    73,   133,    -1,    -1,     6,    12,
       1,    50,    74,   133,    -1,    29,    75,    -1,    75,    28,
      75,    -1,    75,    29,    75,    -1,    75,    30,    75,    -1,
      75,    31,    75,    -1,    75,    32,    75,    -1,    75,    19,
      75,    -1,    75,    17,    75,    -1,    75,    18,    75,    -1,
      34,    75,    -1,    75,    26,    75,    -1,    75,    27,    75,
      -1,    51,    75,    52,    -1,     3,    -1,     9,    -1,    76,
      28,    76,    -1,    76,    29,    76,    -1,    76,    30,    76,
      -1,    76,    31,    76,    -1,    76,    32,    76,    -1,    76,
      33,    76,    -1,    76,    28,    75,    -1,    76,    29,    75,
      -1,    76,    30,    75,    -1,    76,    31,    75,    -1,    76,
      32,    75,    -1,    76,    33,    75,    -1,    75,    28,    76,
      -1,    75,    29,    76,    -1,    75,    30,    76,    -1,    75,
      31,    76,    -1,    75,    32,    76,    -1,    75,    33,    76,
      -1,    51,    76,    52,    -1,     4,    -1,     7,    -1,    76,
      -1,    75,    -1,     5,    -1,     8,    -1,    80,    86,   133,
      -1,    37,    93,   114,    94,    53,   133,    59,    54,    -1,
      37,     1,    54,    -1,    37,    93,     1,    54,    -1,    37,
      93,   114,     1,    54,    -1,    37,    93,   114,    94,     1,
      54,    -1,    37,    93,   114,    94,    53,   133,     1,    54,
      -1,    37,    93,   114,    94,    53,   133,    59,    54,    -1,
      37,     1,    54,    -1,    -1,    37,    93,    82,     1,    54,
      -1,    -1,    37,    93,   114,    83,     1,    54,    -1,    -1,
      37,    93,   114,    94,    84,     1,    54,    -1,    -1,    37,
      93,   114,    94,    53,   133,    85,     1,    54,    -1,    38,
      81,    86,    -1,    38,    53,   133,    59,    54,    -1,    -1,
      38,    87,     1,    54,    -1,    40,    93,   114,    94,    53,
     133,    59,    54,   133,    -1,    -1,    40,     1,    54,    89,
     133,    -1,    -1,    40,    93,   114,     1,    54,    90,   133,
      -1,    -1,    40,    93,   114,    94,     1,    54,    91,   133,
      -1,    -1,    40,    93,   114,    94,    53,   133,     1,    54,
      92,   133,    -1,    51,    -1,    52,    -1,    39,    51,   106,
      55,   104,   114,   105,    52,    53,   133,    59,    54,    51,
     106,    52,    50,   133,    -1,    -1,    39,     1,    52,    50,
      96,   133,    -1,    -1,    39,    51,     1,    52,    50,    97,
     133,    -1,    -1,    39,    51,   106,    55,   104,   114,   105,
       1,    52,    50,    98,   133,    -1,    -1,    39,    51,   106,
      55,   104,   114,   105,    52,     1,    52,    50,    99,   133,
      -1,    -1,    39,    51,   106,    55,   104,   114,   105,    52,
      53,   133,     1,    52,    50,   100,   133,    -1,    -1,    39,
      51,   106,    55,   104,   114,   105,    52,    53,   133,    59,
       1,    52,    50,   101,   133,    -1,    -1,    39,    51,   106,
      55,   104,   114,   105,    52,    53,   133,    59,    54,     1,
      52,    50,   102,   133,    -1,    -1,    39,    51,   106,    55,
     104,   114,   105,    52,    53,   133,    59,    54,    51,     1,
      52,    50,   103,   133,    -1,    -1,    -1,     9,    12,    75,
      -1,   113,    53,   133,    59,    54,    44,    51,   114,    52,
      50,   133,    -1,    -1,   113,     1,    52,    50,   108,   133,
      -1,    -1,   113,    53,   133,     1,    52,    50,   109,   133,
      -1,    -1,   113,    53,   133,    59,    54,     1,    52,    50,
     110,   133,    -1,    -1,   113,    53,   133,    59,    54,    44,
       1,    52,    50,   111,   133,    -1,    -1,   113,    53,   133,
      59,    54,    44,    51,     1,    52,    50,   112,   133,    -1,
      43,    -1,    35,   114,    -1,   114,    16,   114,    -1,   114,
      15,   114,    -1,   132,    -1,     6,    -1,   115,    -1,    51,
     114,    52,    -1,   116,    21,   116,    -1,   116,    20,   116,
      -1,   116,    25,   116,    -1,   116,    24,   116,    -1,   116,
      23,   116,    -1,   116,    22,   116,    -1,     3,    -1,     9,
      -1,     4,    -1,     7,    -1,     5,    -1,     8,    -1,    -1,
     124,    51,   125,    52,    53,   133,   126,   130,    54,   118,
     133,    -1,    -1,   124,     1,    54,   119,   133,    -1,    -1,
     124,    51,     1,    54,   120,   133,    -1,    -1,   124,    51,
     125,     1,    54,   121,   133,    -1,    -1,   124,    51,   125,
      52,     1,    54,   122,   133,    -1,    -1,   124,    51,   125,
      52,    53,   133,     1,    54,   123,   133,    -1,    41,    -1,
       9,    -1,     7,    -1,     8,    -1,     6,    -1,   127,   126,
      -1,   127,    -1,    -1,    42,   131,    56,   128,   133,    59,
     129,    -1,    46,    50,   133,    -1,    45,    56,   133,    59,
      -1,     3,    -1,     4,    -1,     5,    -1,   132,    -1,    13,
      -1,    14,    -1,   133,    47,    -1,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   126,   126,   126,   126,   126,   126,   127,
     127,   127,   127,   127,   127,   130,   130,   130,   130,   133,
     134,   135,   135,   138,   139,   140,   141,   145,   146,   147,
     148,   152,   153,   153,   156,   164,   172,   180,   191,   191,
     192,   192,   193,   194,   196,   196,   197,   197,   198,   198,
     199,   199,   207,   208,   209,   210,   211,   212,   214,   215,
     216,   217,   218,   219,   221,   222,   223,   227,   228,   229,
     230,   231,   232,   234,   235,   236,   237,   238,   239,   241,
     242,   243,   244,   245,   246,   248,   249,   250,   254,   254,
     257,   258,   262,   268,   279,   280,   281,   282,   283,   288,
     298,   299,   299,   300,   300,   301,   301,   302,   302,   305,
     306,   308,   308,   313,   323,   323,   325,   325,   326,   326,
     327,   327,   331,   334,   337,   347,   347,   348,   348,   349,
     349,   350,   350,   351,   351,   352,   352,   353,   353,   354,
     354,   359,   363,   366,   369,   377,   377,   378,   378,   379,
     379,   380,   380,   381,   381,   387,   390,   391,   392,   393,
     394,   395,   396,   400,   401,   402,   403,   404,   405,   409,
     410,   411,   412,   413,   414,   418,   418,   424,   424,   425,
     425,   426,   426,   427,   427,   428,   428,   433,   439,   440,
     441,   442,   446,   447,   451,   451,   470,   477,   480,   481,
     482,   483,   487,   488,   492,   493
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
  "'-'", "'*'", "'/'", "'%'", "POW", "'~'", "LOGIC_NOT", "UMINUS", "IF",
  "ELSE", "FOR", "WHILE", "SWITCH", "CASE", "REPEAT", "UNTIL", "DEFAULT",
  "DONE", "ENDL", "START_DECL", "END_DECL", "';'", "'('", "')'", "'{'",
  "'}'", "','", "':'", "$accept", "program", "stmt", "declarations",
  "variable", "$@1", "id1", "decl_assign", "constant_stmt", "$@2",
  "constant", "assignment", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "int_expr", "float_expr", "float_int_expr", "str_expr",
  "if_else_if_else_stmt", "if_stmt1", "if_stmt", "$@9", "$@10", "$@11",
  "$@12", "else_if_stmt", "$@13", "while_loop", "$@14", "$@15", "$@16",
  "$@17", "start_while_if", "end_while_if", "for_loop", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "$@24", "$@25", "start_bool_expr",
  "end_bool_expr", "for_assignment", "repeat_until_loop", "$@26", "$@27",
  "$@28", "$@29", "$@30", "start_repeat", "bool_expr", "bool_term",
  "compare_opd", "switch_case", "$@31", "$@32", "$@33", "$@34", "$@35",
  "$@36", "start_switch", "id", "case_stmts", "case_stmt", "$@37", "done",
  "defaultt", "value", "boolean", "endls", 0
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
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
      59,    40,    41,   123,   125,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    61,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    66,    65,    67,    67,    67,    67,    69,    68,
      70,    68,    68,    68,    71,    68,    72,    68,    73,    68,
      74,    68,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    77,
      78,    78,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    81,    83,    81,    84,    81,    85,    81,    86,
      86,    87,    86,    88,    89,    88,    90,    88,    91,    88,
      92,    88,    93,    94,    95,    96,    95,    97,    95,    98,
      95,    99,    95,   100,    95,   101,    95,   102,    95,   103,
      95,   104,   105,   106,   107,   108,   107,   109,   107,   110,
     107,   111,   107,   112,   107,   113,   114,   114,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   116,
     116,   116,   116,   116,   116,   118,   117,   119,   117,   120,
     117,   121,   117,   122,   117,   123,   117,   124,   125,   125,
     125,   125,   126,   126,   128,   127,   129,   130,   131,   131,
     131,   131,   132,   132,   133,   133
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     0,     5,     1,     1,     1,     1,     4,     4,     4,
       4,     3,     0,     5,     4,     4,     4,     4,     0,     6,
       0,     6,     5,     5,     0,     6,     0,     6,     0,     6,
       0,     6,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     8,     3,     4,     5,     6,     8,     8,
       3,     0,     5,     0,     6,     0,     7,     0,     9,     3,
       5,     0,     4,     9,     0,     5,     0,     7,     0,     8,
       0,    10,     1,     1,    17,     0,     6,     0,     7,     0,
      12,     0,    13,     0,    15,     0,    16,     0,    17,     0,
      18,     0,     0,     3,    11,     0,     6,     0,     8,     0,
      10,     0,    11,     0,    12,     1,     2,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     0,    11,     0,     5,     0,
       6,     0,     7,     0,     8,     0,    10,     1,     1,     1,
       1,     1,     2,     1,     0,     7,     3,     4,     1,     1,
       1,     1,     1,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   205,     0,     1,     0,     0,   204,     0,
      15,    16,     0,     0,     0,     0,     0,     0,     0,    26,
      24,    25,    23,     0,     0,     0,    17,    18,    32,     0,
       0,     0,     0,    31,    21,     0,     0,     0,     0,     0,
      20,     0,     0,   202,   203,     0,     0,     0,     0,     0,
     169,   171,   173,   160,   172,   174,   170,     0,     0,     0,
     161,     0,   159,    65,    86,    87,    66,     0,     0,     0,
      89,    88,     0,    90,    91,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,   187,   155,     2,     9,
      10,     0,    12,    11,    13,     0,    14,     0,    33,    37,
      35,    36,    34,    22,   156,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    52,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     3,     4,     6,     5,
       7,     8,   111,     0,     0,     0,     0,     0,   162,   158,
     157,   164,   163,   168,   167,   166,   165,    64,    85,    59,
      60,    58,    62,    63,    53,    79,    54,    80,    55,    81,
      56,    82,    57,    83,     0,    84,    73,    67,    74,    68,
      75,    69,    76,    70,    77,    71,    78,    72,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,   114,     0,
       0,     0,     0,     0,    92,     0,     0,   177,     0,   191,
     189,   190,   188,     0,    50,     0,    46,    40,    48,     0,
      44,    38,    95,     0,   123,     0,   125,     0,     0,   141,
       0,     0,     0,     0,   101,     0,   109,     0,   145,     0,
       0,     0,   179,     0,     0,     0,    43,     0,     0,     0,
      42,     0,     0,    96,     0,     0,     0,   127,   143,     0,
     115,   116,     0,     0,   100,     0,   103,     0,   112,     0,
       0,     0,   178,     0,   181,     0,     0,    51,    47,    41,
      49,    45,    39,    97,     0,   126,     0,   142,     0,   118,
       0,     0,     0,   105,   110,   146,   147,     0,     0,   180,
       0,   183,     0,     0,     0,   128,     0,   117,     0,     0,
       0,   102,     0,     0,     0,     0,     0,     0,     0,   182,
       0,     0,     0,     0,   193,    98,    93,     0,     0,   119,
     120,     0,   104,   107,     0,   148,   149,     0,     0,     0,
     184,   185,   198,   199,   200,     0,   201,     0,     0,   192,
       0,     0,     0,     0,   113,     0,     0,   106,     0,   151,
       0,     0,     0,   194,     0,   175,   129,     0,     0,   121,
      99,     0,   150,     0,   153,     0,   186,     0,     0,     0,
       0,   131,     0,     0,   108,   152,     0,   144,     0,   197,
     176,   130,     0,     0,     0,     0,   154,     0,   132,   133,
       0,     0,     0,     0,   195,     0,   135,     0,     0,     0,
       0,   134,     0,   137,     0,     0,   196,   136,     0,   139,
       0,   138,     0,   124,   140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    88,     9,    10,    49,    23,    24,    11,    42,
      17,    89,   282,   278,   281,   277,   279,   275,    70,    71,
      72,    75,    90,    91,   232,   295,   322,   344,   386,   163,
     233,    92,   260,   318,   338,   383,   151,   255,    93,   286,
     316,   410,   422,   435,   442,   448,   452,   289,   336,   227,
      94,   299,   345,   388,   403,   416,    95,    59,    60,    61,
      96,   409,   271,   303,   330,   350,   392,    97,   243,   353,
     354,   407,   434,   378,   375,    62,     4
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     -20,     5,    60,  -231,    90,  -231,   297,   485,  -231,    19,
    -231,  -231,    21,    74,    93,   112,   120,     5,    85,   126,
     138,   152,   155,    95,     5,     5,  -231,  -231,  -231,    24,
     171,   179,   186,   151,  -231,   453,   197,    98,   183,     5,
     151,   389,     5,  -231,  -231,   169,   173,   175,   185,     5,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   453,   453,   110,
    -231,   776,  -231,  -231,  -231,  -231,  -231,   183,   183,   197,
     700,   709,   194,  -231,  -231,   195,   183,   598,   151,   204,
     221,   235,   240,    38,    40,    42,  -231,  -231,   612,  -231,
    -231,   215,  -231,  -231,  -231,     8,  -231,    43,   151,  -231,
    -231,  -231,  -231,   151,  -231,   128,   453,   453,  -231,   307,
     307,   307,   307,   307,   307,  -231,  -231,   639,   648,   183,
     183,   183,   183,   183,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   197,   197,   197,  -231,  -231,   656,   183,
     183,   183,   183,   183,  -231,   148,   162,   189,   176,   201,
    -231,   403,   207,    18,   217,   453,  -231,  -231,  -231,  -231,
    -231,  -231,   -13,     5,   223,     5,   220,   653,  -231,   261,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   749,
     763,   683,   603,   603,   260,   370,   260,   370,   245,   247,
     245,   247,   245,   247,   700,   247,   717,   370,   717,   370,
     330,   247,   330,   247,   330,   247,   330,   247,   177,   177,
    -231,  -231,  -231,   231,   206,   233,   234,   237,   246,   250,
     675,  -231,   248,    33,   257,   267,   308,   254,  -231,    35,
      44,     5,   215,   321,   151,   273,   533,  -231,   271,  -231,
    -231,  -231,  -231,    11,  -231,     5,  -231,  -231,  -231,     5,
    -231,  -231,  -231,   275,  -231,     9,  -231,   277,   183,  -231,
       5,   278,    12,   281,   453,   389,  -231,   283,  -231,   279,
     466,     5,  -231,   284,    13,     5,   151,     5,     5,     5,
     151,     5,     5,  -231,   287,     5,     5,  -231,   734,   453,
     151,  -231,   289,     5,  -231,   352,   143,   471,  -231,     5,
     304,    15,   151,     5,  -231,   301,     5,   151,   151,   151,
     151,   151,   151,  -231,   542,   151,     5,   222,     5,  -231,
     556,   314,   360,   309,  -231,   151,  -231,   317,    45,   151,
       5,  -231,    57,   316,   476,   151,    17,   151,     5,   320,
     492,  -231,   322,     5,   377,     5,   329,   328,   436,   151,
       5,   333,   236,   337,   341,  -231,  -231,   332,    14,   151,
    -231,     5,  -231,   389,   335,   151,  -231,   344,   339,   166,
     151,  -231,  -231,  -231,  -231,   358,  -231,   359,   366,  -231,
     371,   372,     5,     5,   151,   515,   421,  -231,     5,  -231,
     384,   396,     5,  -231,     5,  -231,  -231,   397,   599,   151,
    -231,   394,   151,     5,  -231,     5,   151,     5,   389,     5,
       5,  -231,   399,   133,  -231,   151,     5,   151,   389,   612,
     151,   151,     5,   402,   401,    46,   151,   604,   151,  -231,
     405,   411,    22,   414,  -231,     5,  -231,   415,   416,   417,
       5,   151,     5,  -231,   420,   426,   151,   151,     5,  -231,
       5,   151,     5,   151,   151
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -230,  -231,   472,  -231,  -231,  -231,   480,  -231,
    -231,   -77,  -231,  -231,  -231,  -231,  -231,  -231,   -12,   -52,
     349,   343,   -68,  -231,  -231,  -231,  -231,  -231,  -231,   264,
    -231,   -67,  -231,  -231,  -231,  -231,   -83,  -226,   -55,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,    65,
     -46,  -231,  -231,  -231,  -231,  -231,  -231,   -53,  -231,   645,
       0,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   164,
    -231,  -231,  -231,  -231,  -231,   -28,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      33,    45,   155,   262,   104,   105,   270,    40,    41,   164,
     284,   156,   273,   292,   305,   381,   327,   118,   357,   225,
     157,   158,    78,   438,   230,    98,    77,   226,     1,     6,
       7,   226,   103,   159,   253,   297,   261,    43,    44,   149,
     231,   152,   160,   154,   166,   263,   347,   431,   106,   107,
     106,   107,     3,   169,   170,   115,   116,   117,   351,   328,
       5,   165,   285,   274,   138,   293,   306,   382,    25,   358,
     323,    28,   185,   187,   189,   191,   193,   195,   197,   199,
     201,   203,   205,   207,   334,   254,    29,   254,   161,   150,
     340,   153,   214,   150,   167,   150,   348,   432,   223,   352,
       6,     7,   229,    73,     8,    30,    74,   179,   180,   181,
     182,   183,   184,   186,   188,   190,   192,   194,   196,   198,
     200,   202,   204,   206,    31,   106,   107,   208,   209,   210,
     211,   212,    32,   385,   424,    34,   220,     8,    35,    79,
      80,    81,    82,   106,   107,    39,   234,   264,   236,   213,
      36,    50,    51,    52,    53,    54,    55,    56,   106,   107,
     108,    43,    44,   215,    37,    63,    64,    38,   413,    65,
      83,    66,    84,    85,    86,    46,    87,   219,   419,    63,
     168,   106,   107,    57,    47,    66,    63,   425,   427,    48,
     217,    67,    66,   156,    73,   254,    68,    74,     8,    58,
      63,    64,   157,   158,    65,    67,    66,   141,   142,   143,
      68,   296,    67,    69,   265,   159,   145,    68,   391,    99,
     156,   106,   107,   100,   160,   101,    67,    76,   276,   157,
     158,    68,   280,   146,    76,   102,   317,   106,   107,   372,
     373,   374,   159,   290,   136,   137,   288,   147,    69,    43,
      44,   160,   148,   162,   302,   221,   245,   156,   307,   224,
     308,   309,   310,   156,   311,   312,   157,   158,   314,   315,
     161,   228,   157,   158,   237,   235,   320,   107,   129,   159,
     135,   244,   325,   246,   247,   159,   329,   248,   160,   332,
     126,   127,   128,   129,   160,   369,   249,   161,    12,   335,
     250,   337,   252,    13,    14,    15,    16,   256,   156,   259,
      50,    51,    52,   349,    54,    55,    56,   157,   158,   257,
     258,   359,   267,   268,   376,   272,   363,   287,   365,   283,
     159,   300,   291,   370,   161,   294,   156,   298,   304,   160,
     161,   313,   156,   319,   384,   157,   158,   119,   120,   121,
     156,   157,   158,   321,   326,   331,   122,   123,   159,   157,
     158,   342,   343,   129,   159,   398,   399,   160,   341,   346,
     355,   402,   159,   160,   360,   406,   362,   408,   364,   366,
     367,   160,   377,   352,   380,   161,   415,   371,   417,   387,
     418,   390,   420,   421,   389,    79,    80,    81,    82,   426,
     132,   133,   134,   135,   222,   428,    50,    51,    52,    53,
      54,    55,    56,   161,   393,   394,    43,    44,   441,   161,
     395,   396,   401,   446,   397,   447,    83,   161,    84,    85,
      86,   451,    87,   453,   404,   454,     8,   368,    57,    50,
      51,    52,    53,    54,    55,    56,   405,   411,   414,    43,
      44,   423,   429,   430,    58,   436,    50,    51,    52,    53,
      54,    55,    56,   437,   440,   443,    43,    44,   444,   445,
     449,    57,    79,    80,    81,    82,   450,    79,    80,    81,
      82,    26,    79,    80,    81,    82,    18,    58,    57,    27,
     218,    19,    20,    21,    22,   216,   266,   439,    79,    80,
      81,    82,     0,    83,    58,    84,    85,    86,    83,    87,
      84,    85,    86,    83,    87,    84,    85,    86,   379,    87,
     301,    79,    80,    81,    82,   324,     0,     0,     0,    83,
     356,    84,    85,    86,   269,    87,     0,     0,     0,    79,
      80,    81,    82,   333,     0,     0,   361,     0,    79,    80,
      81,    82,    83,     0,    84,    85,    86,   339,    87,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,   400,
      83,     0,    84,    85,    86,     0,    87,     0,     0,    83,
       8,    84,    85,    86,     0,    87,     0,     0,     0,     8,
       0,     0,     0,    83,     0,    84,    85,    86,     0,    87,
     412,     0,     0,     8,     0,    79,    80,    81,    82,     0,
      79,    80,    81,    82,     0,   119,   120,   121,    79,    80,
      81,    82,     0,     0,   122,   123,   139,   140,   141,   142,
     143,   139,   140,   141,   142,   143,    83,     0,    84,    85,
      86,    83,    87,    84,    85,    86,     8,    87,   144,    83,
     433,    84,    85,    86,   238,    87,   119,   120,   121,   239,
     240,   241,   242,     0,     0,   122,   123,   124,   125,   126,
     127,   128,   129,   119,   120,   121,   130,   131,   132,   133,
     134,   135,   122,   123,   139,   140,   141,   142,   143,     0,
       0,   177,   119,   120,   121,     0,     0,     0,     0,     0,
     178,   122,   123,   139,   140,   141,   142,   143,   177,   122,
     123,   139,   140,   141,   142,   143,     0,   119,   120,   121,
       0,     0,     0,     0,     0,   251,   122,   123,   124,   125,
     126,   127,   128,   129,   119,   120,   121,   130,   131,   132,
     133,   134,   135,   122,   123,     0,     0,   126,   127,   128,
     129,   119,   120,   121,   171,   172,   173,   174,   175,   176,
     122,   123,   139,   140,   141,   142,   143,   120,   121,     0,
       0,     0,     0,     0,     0,   122,   123,   139,   140,   141,
     142,   143,   121,     0,     0,     0,     0,     0,     0,   122,
     123,   139,   140,   141,   142,   143,   109,   110,   111,   112,
     113,   114
};

static const yytype_int16 yycheck[] =
{
      17,    29,    85,   229,    57,    58,   236,    24,    25,     1,
       1,    88,     1,     1,     1,     1,     1,    69,     1,     1,
      88,    88,    39,     1,    37,    42,    38,     9,    48,    10,
      11,     9,    49,    88,     1,   265,     1,    13,    14,     1,
      53,     1,    88,     1,     1,     1,     1,     1,    15,    16,
      15,    16,    47,   106,   107,    67,    68,    69,     1,    44,
       0,    53,    53,    52,    76,    53,    53,    53,    49,    52,
     296,    50,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   314,    52,    12,    52,    88,    51,
     320,    51,   145,    51,    51,    51,    51,    51,   151,    42,
      10,    11,   155,     5,    47,    12,     8,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,    12,    15,    16,   139,   140,   141,
     142,   143,    12,   363,     1,    50,   148,    47,    12,     6,
       7,     8,     9,    15,    16,    50,   163,   230,   165,     1,
      12,     3,     4,     5,     6,     7,     8,     9,    15,    16,
      50,    13,    14,     1,    12,     3,     4,    12,   398,     7,
      37,     9,    39,    40,    41,     4,    43,     1,   408,     3,
      52,    15,    16,    35,     5,     9,     3,    54,   418,     3,
       1,    29,     9,   270,     5,    52,    34,     8,    47,    51,
       3,     4,   270,   270,     7,    29,     9,    30,    31,    32,
      34,   264,    29,    51,   231,   270,    12,    34,    52,    50,
     297,    15,    16,    50,   270,    50,    29,    51,   245,   297,
     297,    34,   249,    12,    51,    50,   289,    15,    16,     3,
       4,     5,   297,   260,    50,    50,   258,    12,    51,    13,
      14,   297,    12,    38,   271,    54,    50,   334,   275,    52,
     277,   278,   279,   340,   281,   282,   334,   334,   285,   286,
     270,    54,   340,   340,    54,    52,   293,    16,    33,   334,
      33,    50,   299,    50,    50,   340,   303,    50,   334,   306,
      30,    31,    32,    33,   340,   348,    50,   297,     1,   316,
      50,   318,    54,     6,     7,     8,     9,    50,   385,    55,
       3,     4,     5,   330,     7,     8,     9,   385,   385,    52,
      12,   338,     1,    50,   352,    54,   343,    50,   345,    54,
     385,    52,    54,   350,   334,    54,   413,    54,    54,   385,
     340,    54,   419,    54,   361,   413,   413,    17,    18,    19,
     427,   419,   419,     1,    50,    54,    26,    27,   413,   427,
     427,     1,    53,    33,   419,   382,   383,   413,    54,    52,
      54,   388,   427,   419,    54,   392,    54,   394,     1,    50,
      52,   427,    45,    42,    52,   385,   403,    54,   405,    54,
     407,    52,   409,   410,    50,     6,     7,     8,     9,   416,
      30,    31,    32,    33,     1,   422,     3,     4,     5,     6,
       7,     8,     9,   413,    56,    56,    13,    14,   435,   419,
      54,    50,     1,   440,    52,   442,    37,   427,    39,    40,
      41,   448,    43,   450,    50,   452,    47,     1,    35,     3,
       4,     5,     6,     7,     8,     9,    50,    50,    54,    13,
      14,    52,    50,    52,    51,    50,     3,     4,     5,     6,
       7,     8,     9,    52,    50,    50,    13,    14,    52,    52,
      50,    35,     6,     7,     8,     9,    50,     6,     7,     8,
       9,     9,     6,     7,     8,     9,     1,    51,    35,     9,
     147,     6,     7,     8,     9,   146,   232,   432,     6,     7,
       8,     9,    -1,    37,    51,    39,    40,    41,    37,    43,
      39,    40,    41,    37,    43,    39,    40,    41,   354,    43,
      54,     6,     7,     8,     9,    54,    -1,    -1,    -1,    37,
      54,    39,    40,    41,     1,    43,    -1,    -1,    -1,     6,
       7,     8,     9,     1,    -1,    -1,    54,    -1,     6,     7,
       8,     9,    37,    -1,    39,    40,    41,     1,    43,    -1,
      -1,    -1,     6,     7,     8,     9,    -1,    -1,    -1,    54,
      37,    -1,    39,    40,    41,    -1,    43,    -1,    -1,    37,
      47,    39,    40,    41,    -1,    43,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    37,    -1,    39,    40,    41,    -1,    43,
       1,    -1,    -1,    47,    -1,     6,     7,     8,     9,    -1,
       6,     7,     8,     9,    -1,    17,    18,    19,     6,     7,
       8,     9,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    28,    29,    30,    31,    32,    37,    -1,    39,    40,
      41,    37,    43,    39,    40,    41,    47,    43,    50,    37,
      46,    39,    40,    41,     1,    43,    17,    18,    19,     6,
       7,     8,     9,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    17,    18,    19,    28,    29,    30,    31,
      32,    33,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    52,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      52,    26,    27,    28,    29,    30,    31,    32,    52,    26,
      27,    28,    29,    30,    31,    32,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    50,    26,    27,    28,    29,
      30,    31,    32,    33,    17,    18,    19,    28,    29,    30,
      31,    32,    33,    26,    27,    -1,    -1,    30,    31,    32,
      33,    17,    18,    19,   109,   110,   111,   112,   113,   114,
      26,    27,    28,    29,    30,    31,    32,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    20,    21,    22,    23,
      24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    58,    47,   133,     0,    10,    11,    47,    60,
      61,    65,     1,     6,     7,     8,     9,    67,     1,     6,
       7,     8,     9,    63,    64,    49,    61,    65,    50,    12,
      12,    12,    12,   133,    50,    12,    12,    12,    12,    50,
     133,   133,    66,    13,    14,   132,     4,     5,     3,    62,
       3,     4,     5,     6,     7,     8,     9,    35,    51,   114,
     115,   116,   132,     3,     4,     7,     9,    29,    34,    51,
      75,    76,    77,     5,     8,    78,    51,    75,   133,     6,
       7,     8,     9,    37,    39,    40,    41,    43,    59,    68,
      79,    80,    88,    95,   107,   113,   117,   124,   133,    50,
      50,    50,    50,   133,   114,   114,    15,    16,    50,    20,
      21,    22,    23,    24,    25,    75,    75,    75,    76,    17,
      18,    19,    26,    27,    28,    29,    30,    31,    32,    33,
      28,    29,    30,    31,    32,    33,    50,    50,    75,    28,
      29,    30,    31,    32,    50,    12,    12,    12,    12,     1,
      51,    93,     1,    51,     1,    93,    68,    79,    88,    95,
     107,   117,    38,    86,     1,    53,     1,    51,    52,   114,
     114,   116,   116,   116,   116,   116,   116,    52,    52,    75,
      75,    75,    75,    75,    75,    76,    75,    76,    75,    76,
      75,    76,    75,    76,    75,    76,    75,    76,    75,    76,
      75,    76,    75,    76,    75,    76,    75,    76,    75,    75,
      75,    75,    75,     1,   114,     1,    77,     1,    78,     1,
      75,    54,     1,   114,    52,     1,     9,   106,    54,   114,
      37,    53,    81,    87,   133,    52,   133,    54,     1,     6,
       7,     8,     9,   125,    50,    50,    50,    50,    50,    50,
      50,    50,    54,     1,    52,    94,    50,    52,    12,    55,
      89,     1,    94,     1,    93,   133,    86,     1,    50,     1,
      59,   119,    54,     1,    52,    74,   133,    72,    70,    73,
     133,    71,    69,    54,     1,    53,    96,    50,    75,   104,
     133,    54,     1,    53,    54,    82,   114,    59,    54,   108,
      52,    54,   133,   120,    54,     1,    53,   133,   133,   133,
     133,   133,   133,    54,   133,   133,    97,   114,    90,    54,
     133,     1,    83,    94,    54,   133,    50,     1,    44,   133,
     121,    54,   133,     1,    59,   133,   105,   133,    91,     1,
      59,    54,     1,    53,    84,   109,    52,     1,    51,   133,
     122,     1,    42,   126,   127,    54,    54,     1,    52,   133,
      54,    54,    54,   133,     1,   133,    50,    52,     1,   114,
     133,    54,     3,     4,     5,   131,   132,    45,   130,   126,
      52,     1,    53,    92,   133,    59,    85,    54,   110,    50,
      52,    52,   123,    56,    56,    54,    50,    52,   133,   133,
      54,     1,   133,   111,    50,    50,   133,   128,   133,   118,
      98,    50,     1,    59,    54,   133,   112,   133,   133,    59,
     133,   133,    99,    52,     1,    54,   133,    59,   133,    50,
      52,     1,    51,    46,   129,   100,    50,    52,     1,   106,
      50,   133,   101,    50,    52,    52,   133,   133,   102,    50,
      50,   133,   103,   133,   133
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
        case 21:

/* Line 1455 of yacc.c  */
#line 135 "voo.y"
    { errorVarStmt();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 138 "voo.y"
    { declIdActions((yyvsp[(1) - (1)].idval),integer);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 139 "voo.y"
    {declIdActions((yyvsp[(1) - (1)].idval),floatt);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 140 "voo.y"
    { declIdActions((yyvsp[(1) - (1)].idval),str);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 141 "voo.y"
    { declIdActions((yyvsp[(1) - (1)].idval),boolean);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 145 "voo.y"
    { declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),integer); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 146 "voo.y"
    {declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),floatt);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 147 "voo.y"
    { declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),str);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 148 "voo.y"
    { declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),boolean);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 153 "voo.y"
    {errorConstStmt();;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 156 "voo.y"
    { 
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){  //check if this var hasn't been declared before , not to declare 2 var with the same name 
							NodeWithType* nt=createNewValueNode(NewNodeInt((yyvsp[(3) - (4)].ival)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),integer,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));	
					;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 164 "voo.y"
    { 
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){	
							NodeWithType* nt=createNewValueNode(NewNodeFloat((yyvsp[(3) - (4)].fval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));	
					;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 172 "voo.y"
    {
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){	
							NodeWithType* nt=createNewValueNode(NewNodeString((yyvsp[(3) - (4)].sval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),str,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 180 "voo.y"
    {
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){	
							NodeWithType* nt=createNewValueNode(NewNodeBool((yyvsp[(3) - (4)].nodeval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),boolean,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));
					;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 191 "voo.y"
    { assignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),integer);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 192 "voo.y"
    { assignmentActions ((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),floatt);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 193 "voo.y"
    { assignmentActions((yyvsp[(1) - (5)].idval),(yyvsp[(3) - (5)].nodeval),str);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 194 "voo.y"
    { assignmentActions((yyvsp[(1) - (5)].idval),(yyvsp[(3) - (5)].nodeval),boolean);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 196 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid int expression to use !" <<endl;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 197 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid float expression to use !" <<endl;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 198 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid string expression to use !" <<endl;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 199 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid bool expression to use !"<<endl;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 207 "voo.y"
    { (yyval.nodeval)=createNewExprNode(neg,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("NEG",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "NEG " <<endl; };}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 208 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS "  <<endl;} ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 209 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS" <<endl; };}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 210 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL" <<endl; } ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 211 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " <<endl; };}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 212 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " <<endl; };}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 214 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_AND " <<endl;} ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 215 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_OR " <<endl; };}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 216 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_xor,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("XOR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_XOR " <<endl; };}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 217 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_not,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "BITWISE_NOT: " <<endl; };}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 218 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_r,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_LEFT: " <<endl; };}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 219 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_l,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_RIGHT: " <<endl; };}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 221 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);	cout << "Brackets  " <<endl; ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 222 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 223 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 227 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS " <<endl; };}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 228 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS " << endl; };}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 229 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL " << endl; } ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 230 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " << endl; };}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 231 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " << endl; };}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 232 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW " << endl; };}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 234 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS " << endl; };}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 235 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS " <<endl; };}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 236 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL " << endl; } ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 237 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " <<endl; };}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 238 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " << endl; };}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 239 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW " << endl; };}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 241 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS" << endl; };}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 242 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS " << endl; };}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 243 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL " << endl;  };}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 244 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " << endl; };}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 245 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " << endl; };}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 246 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW " << endl; };}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 248 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval); cout << "Brackets  " <<endl; ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 249 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval)));  ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 250 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 257 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));  ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 258 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 262 "voo.y"
    {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
	;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 268 "voo.y"
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

  case 94:

/* Line 1455 of yacc.c  */
#line 279 "voo.y"
    {cout<<"At Line: "<<line_num<<" expected '(' after 'if' !"<<endl; YYABORT ;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 280 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in boolean expression of if statement !"<<endl; YYABORT; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 281 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected ')' after boolean expression of if statement !"<<endl; YYABORT ; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 282 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after (boolean expression) of if statement !"<<endl; YYABORT ; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 283 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in statements of if statement !"<<endl; YYABORT ; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 288 "voo.y"
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

  case 100:

/* Line 1455 of yacc.c  */
#line 298 "voo.y"
    {cout<<"At Line: "<<line_num<<" expected '(' after 'if' !"<<endl; YYABORT ;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 299 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in boolean expression of if statement !"<<endl; YYABORT; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 300 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected ')' after boolean expression of if statement !"<<endl; YYABORT ; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 301 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after (boolean expression) of if statement !"<<endl; YYABORT ; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 302 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in statements of if statement !"<<endl; YYABORT ; if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 305 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 306 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 308 "voo.y"
    {cout<<"At Line: "<<line_num<<" expected '{' after 'else' !"<<endl;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 309 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 313 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		if((yyvsp[(3) - (9)].nodeval)!=NULL){
			generateBranchQuad("JMP",brLabels.top(),NULL);
			outLabel(temp);
		}
		brLabels.pop();	
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 323 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' after 'while' !"<<endl;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 325 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected ')' after boolean expression of while statement !"<<endl;if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 326 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after (boolean expression) of while statement !"<<endl;if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 327 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in statements of while statement !"<<endl;if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 331 "voo.y"
    {generateLabelPair();;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 334 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 337 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		if((yyvsp[(6) - (17)].nodeval)!=NULL){
			generateBranchQuad("JMP",brLabels.top(),NULL);
			outLabel(temp);
		}
		brLabels.pop();
	;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 347 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '(' after 'for' !"<<endl;;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 348 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: error in the for iteration assignment statement or boolean expression !"<<endl;;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 349 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected ')' after the boolean expression !"<<endl;;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 350 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '{' after boolean expression !"<<endl;;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 351 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: error in the statements of the for loop !"<<endl;;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 352 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '}' after the last statement in the for loop !"<<endl;;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 353 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '(' after '}' !"<<endl;;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 354 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: error in for iteration assignment statement !"<<endl;;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 359 "voo.y"
    {generateLabelPair();;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 363 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 366 "voo.y"
    {assignmentActions((yyvsp[(1) - (3)].idval),(yyvsp[(3) - (3)].nodeval),integer);;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 369 "voo.y"
    {
		if(!boolRes.empty()){
			generateBranchQuad("JTRUE",brLabels.top(),boolRes.top()); 
			boolRes.pop();
		}
		brLabels.pop();
	;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 377 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after repeat !"<<endl;brLabels.pop();;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 378 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in statements of repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 379 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected 'UNTIL' after '}' repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 380 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' after 'UNTIL' repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 381 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in boolean expression of repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 387 "voo.y"
    {int label=generateOneLabel(); outLabel(label); brLabels.push(label);;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 390 "voo.y"
    {(yyval.nodeval)=createNewExprNode(l_not,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("LOG_NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); boolRes.push((yyval.nodeval)); } ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 391 "voo.y"
    { (yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("LOG_AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); boolRes.push((yyval.nodeval)); } ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 392 "voo.y"
    { (yyval.nodeval)=createNewExprNode(l_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));if((yyval.nodeval)!=NULL){generateQuad("LOG_OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); boolRes.push((yyval.nodeval));} ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 393 "voo.y"
    { (yyval.nodeval)=(yyvsp[(1) - (1)].nodeval); boolRes.push((yyval.nodeval)); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 394 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); boolRes.push((yyval.nodeval)); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 395 "voo.y"
    { (yyval.nodeval)=(yyvsp[(1) - (1)].nodeval);   if((yyval.nodeval)!=NULL) boolRes.push((yyval.nodeval)); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 396 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);  cout << "Brackets " <<endl; ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 400 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "EQ " <<endl; };}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 401 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(ne,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("NOT_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "NOT_EQ " <<endl; };}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 402 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(gt,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR " <<endl; };}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 403 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(gte,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR_EQ " <<endl; };}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 404 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(sm,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM " <<endl; };}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 405 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(sme,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM_EQ " <<endl; };}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 409 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival)));;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 410 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 411 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 412 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 413 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 414 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 418 "voo.y"
    {
		outLabel(switchLabels.top());
		switchLabels.pop();
		if(!switchIds.empty()) switchIds.pop();
	;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 424 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' in SWITCH statement !"<<endl; switchLabels.pop();;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 425 "voo.y"
    { cout<<"At Line: "<<line_num<<" not a valid identifier in SWITCH statement !"<<endl; switchLabels.pop();;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 426 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' after identifier in SWITCH statement !"<<endl; switchLabels.pop();;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 427 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after (identifier)  in SWITCH statement !"<<endl;switchLabels.pop();;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 428 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in cases of in SWITCH statement !"<<endl;switchLabels.pop();;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 433 "voo.y"
    {
		int label = generateOneLabel();
		switchLabels.push(label);
	;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 439 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval));;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 440 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval));;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 441 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 442 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));switchIds.push((yyval.nodeval)); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 451 "voo.y"
    {
			int l=generateOneLabel();
			brLabels.push(l);
			//check if value type is the same with id
			if(getIdTypeForId(switchIds.top()) == (yyvsp[(2) - (3)].nodeval)->node->val->tp ) {
				if(!switchIds.empty()){
					NodeWithType* vv=createNewExprNode(eq,2,switchIds.top(),(yyvsp[(2) - (3)].nodeval)); 
					if(vv!=NULL){
						generateQuad("EQ",switchIds.top(),(yyvsp[(2) - (3)].nodeval),vv);
						generateBranchQuad("JFALSE",brLabels.top(),vv);
					}
				}
			}
			else errorTypeMismatch();
		;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 470 "voo.y"
    {
		generateBranchQuad("JMP",switchLabels.top(),NULL);
		outLabel(brLabels.top());
		brLabels.pop();
	;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 480 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 481 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 482 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 487 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool(true)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 488 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool(false)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3001 "voo.tab.c"
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
#line 495 "voo.y"


ofstream quad;
int lineNo=0;

NodeWithType* newIdActions(char * id){
	NodeWithType* newNode;
	
	map<char*,SymRec>::iterator it=mainScope.lookup(id);
	if(!mainScope.checkIteratorAtEnd(it)){
		newNode=createNewIdNode(id); 
		if(!mainScope.checkIteratorInit(it)) unInit.push(id);
		updateSymbolRecordUsed(id);
	} 
	else {newNode=NULL; errorDoesntExist(id);}
	return newNode;
}

void declIdActions(char * id,IdType typ){
	if( mainScope.checkIteratorAtEnd(mainScope.lookup(id))){  //check if this var hasn't been declared before , not to declare 2 var with the same name 
		newSymbolRecord(id,typ,true,false);
	}
	else errorExistsBefore(id);
}

void declAssignmentActions(char * id, NodeWithType* expr,IdType typ){
	if(mainScope.checkIteratorAtEnd(mainScope.lookup(id)) ){ //check if this var hasn't been declared before , not to declare 2 var with the same name 
		if(expr!=NULL){ //check if the variables used in the expression are valid and exist  
			if(unInit.empty()){  //check if there is uninitialized variables used
				newSymbolRecord(id,typ,true,true);
				if(typ!=str)generateQuad("STO",expr,NULL,createNewIdNode(id));	
			}
			else errorUnInitVar();
		}
	}
	else errorExistsBefore(id);	
}

void assignmentActions(char * id, NodeWithType* expr, IdType typ ){
	map<char*,SymRec>::iterator it=mainScope.lookup(id);
	if(!mainScope.checkIteratorAtEnd(it) ){  //check if the var has been declared before, to use it 
		if(mainScope.checkVarConst(it)){   //check if it is var or const
			if(expr!=NULL){ 				//check if the variables used in the expression are valid and exist
				if(unInit.empty()){
					updateSymbolRecordInit(id);
					if(typ!=str) generateQuad("STO",expr,NULL,createNewIdNode(id));
					if(typ==boolean) boolRes.pop();
				}
				else errorUnInitVar();
			}
		}
		else errorConstNotVar(id);
	}
	else errorDoesntExist(id);
}

IdType getIdTypeForId(NodeWithType* n){
	char* name= n->node->id;
	if(name[0]=='i') return integer;
	else if(name[0]=='f') return floatt;
	else if(name[0]=='b') return boolean;
	else if(name[0]=='s') return str;
}
IdType getIdTypeForUnknownNode(NodeWithType* n){
	if(n->tp==identifier) return getIdTypeForId(n);
	else return n->node->val->tp;
}
bool compareTwoOperandsTypes(NodeWithType* op1, NodeWithType* op2){
	return getIdTypeForUnknownNode(op1)==getIdTypeForUnknownNode(op2);
}

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
	//cout<<"quad generated"<<endl;
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

void newSymbolRecord( char * name, IdType ty, bool v_c, bool init ){
	SymRec rec ;
	rec.typ=ty;
	rec.VarConst=v_c;
	rec.init=init;
	rec.used=false;
	//rec.value=vlu;
	mainScope.insert(name,&rec); 
}

void updateSymbolRecordInit(char * name){
	map<char*,SymRec>::iterator it =mainScope.lookup(name);
	it->second.init=true;
}

void updateSymbolRecordUsed(char * name){
	map<char*,SymRec>::iterator it =mainScope.lookup(name);
	it->second.used=true;
}

void errorExistsBefore(char * name){
	cout<<"At line: "<<line_num<<" There exists a variable with the same name! '"<< name <<"'"<<endl;
}

void errorDoesntExist(char * name){
	cout<<"At line: "<<line_num<<" This variable has not been declared ! '"<< name <<"'"<<endl;
}

void errorConstNotVar(char * name){
	cout<<"At line: "<<line_num<<" Constant can not be assigned a new value ! '"<< name <<"'"<<endl;
}

void errorUnInitVar(){
	while(!unInit.empty()){
		cout<<"At line: "<<line_num<<" This variable is used before it's initialized '"<< unInit.front() <<"'"<<endl;
		unInit.pop();
	}
}

void errorVarStmt(){
	cout<<"At Line: "<<line_num<<" Not a valid var statement to declare !"<<endl;
}

void errorConstStmt(){
	cout<<"At Line: "<<line_num<<" Not a valid const statement to declare !"<<endl;	
}

void errorTypeMismatch(){
	cout<<"At Line: "<<line_num<<" mismatch type between value and identifier  !"<<endl;	
}

void errorOperandsTypeMismatch(){
	cout<<"At Line: "<<line_num<<" mismatch type between comparison operands  !"<<endl;	
}

void printUnUsedVar(){
	cout<<"These variables are declared but not used:"<<endl;
	map<char*,SymRec>::iterator it=mainScope.firstSymRec();
	while(!mainScope.checkIteratorAtEnd(it)){
		if(it->second.used==false)
			cout<<it->first<<endl;
		++it;
	}
}


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
	if(n==2 &&( oprd1==NULL || oprd2 ==NULL))
		return NULL;
	else if(n==1 &&oprd1==NULL)
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
	FILE *myfile = fopen("sample3.voo", "r");
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
	mainScope.printAll();
	printUnUsedVar();
	quad.close();
	
}

void yyerror(const char *s) {
	//cout << "EEK, parse error!  on line: " << line_num << " Message: " << s << endl;
	//cout << "EEK, parse error!  " << " Message: " << s << endl;
	cout<<"Syntax Error "<< endl;
	// might as well halt now:
	//exit(-1);
}
