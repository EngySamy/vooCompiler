
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
stack<NodeWithType*> switchIds;
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

void assignmentActions(char * , NodeWithType* ,IdType ); 
void declAssignmentActions(char * id, NodeWithType* expr,IdType);
void declIdActions(char *,IdType);
NodeWithType* newIdActions(char *);

Node * NewNodeFloat(float );
Node * NewNodeInt(int);
Node * NewNodeString(char *);
Node * NewNodeBool(bool);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0,cntLabels=0;



/* Line 189 of yacc.c  */
#line 142 "voo.tab.c"

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
     DONE = 291,
     ENDL = 292,
     START_DECL = 293,
     END_DECL = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 74 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;
	bool bval;
	struct NodeWithType * nodeval;



/* Line 214 of yacc.c  */
#line 228 "voo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 240 "voo.tab.c"

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
#define YYLAST   757

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  345

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,    19,     2,
      50,    51,    30,    28,    54,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,    17,    53,    34,     2,     2,     2,
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
      44,    45,    46,    47,    48
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
     177,   178,   185,   186,   193,   195,   197,   199,   201,   205,
     209,   213,   217,   221,   225,   229,   233,   236,   240,   244,
     248,   250,   252,   256,   260,   264,   268,   272,   276,   280,
     284,   288,   292,   296,   300,   304,   308,   312,   316,   320,
     324,   328,   330,   332,   334,   336,   338,   340,   343,   351,
     359,   363,   368,   369,   380,   381,   387,   389,   391,   409,
     410,   416,   417,   418,   422,   434,   435,   441,   443,   446,
     450,   454,   456,   458,   460,   464,   468,   472,   476,   480,
     484,   488,   490,   492,   494,   496,   498,   500,   509,   511,
     513,   515,   517,   519,   522,   524,   525,   532,   535,   539,
     541,   543,   545,   547,   549,   551,   554
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    47,   109,    59,    48,   109,    58,    -1,
      58,    67,    -1,    58,    80,    -1,    58,    88,    -1,    58,
      84,    -1,    58,    93,    -1,    58,    99,    -1,    67,    -1,
      80,    -1,    88,    -1,    84,    -1,    93,    -1,    99,    -1,
      60,    -1,    64,    -1,    59,    60,    -1,    59,    64,    -1,
      11,    62,    49,   109,    -1,    11,    63,   109,    -1,    -1,
      11,     1,    49,    61,   109,    -1,     9,    -1,     7,    -1,
       8,    -1,     6,    -1,     9,    12,    76,    49,    -1,     7,
      12,    78,    49,    -1,     8,    12,    79,    49,    -1,     6,
      12,    96,    49,    -1,    10,    66,   109,    -1,    -1,    10,
       1,    49,    65,   109,    -1,     9,    12,     3,    49,    -1,
       7,    12,     4,    49,    -1,     8,    12,     5,    49,    -1,
       6,    12,   108,    49,    -1,    -1,     9,    12,    76,    49,
      68,   109,    -1,    -1,     7,    12,    78,    49,    69,   109,
      -1,     8,    12,    79,    49,   109,    -1,     6,    12,    96,
      49,   109,    -1,    -1,     9,    12,     1,    49,    70,   109,
      -1,    -1,     7,    12,     1,    49,    71,   109,    -1,    -1,
       8,    12,     1,    49,    72,   109,    -1,    -1,     6,    12,
       1,    49,    73,   109,    -1,    -1,     1,    12,    75,    49,
      74,   109,    -1,    79,    -1,    96,    -1,    76,    -1,    77,
      -1,    76,    28,    76,    -1,    76,    29,    76,    -1,    76,
      30,    76,    -1,    76,    31,    76,    -1,    76,    32,    76,
      -1,    76,    19,    76,    -1,    76,    17,    76,    -1,    76,
      18,    76,    -1,    34,    76,    -1,    76,    26,    76,    -1,
      76,    27,    76,    -1,    50,    76,    51,    -1,     3,    -1,
       9,    -1,    77,    28,    77,    -1,    77,    29,    77,    -1,
      77,    30,    77,    -1,    77,    31,    77,    -1,    77,    32,
      77,    -1,    77,    33,    77,    -1,    77,    28,    76,    -1,
      77,    29,    76,    -1,    77,    30,    76,    -1,    77,    31,
      76,    -1,    77,    32,    76,    -1,    77,    33,    76,    -1,
      76,    28,    77,    -1,    76,    29,    77,    -1,    76,    30,
      77,    -1,    76,    31,    77,    -1,    76,    32,    77,    -1,
      76,    33,    77,    -1,    50,    77,    51,    -1,     4,    -1,
       7,    -1,    77,    -1,    76,    -1,     5,    -1,     8,    -1,
      81,    83,    -1,    36,    86,    96,    87,    52,    58,    53,
      -1,    36,    86,    96,    87,    52,    58,    53,    -1,    37,
      82,    83,    -1,    37,    52,    58,    53,    -1,    -1,    39,
      86,    96,    87,    52,   109,    58,    53,    49,   109,    -1,
      -1,    39,     1,    49,    85,   109,    -1,    50,    -1,    51,
      -1,    38,    50,    92,    54,    90,    96,    91,    51,    52,
     109,    58,    53,    50,    92,    51,    49,   109,    -1,    -1,
      38,     1,    89,    49,   109,    -1,    -1,    -1,     9,    12,
      76,    -1,    95,    52,   109,    58,    53,    43,    50,    96,
      51,    49,   109,    -1,    -1,    42,     1,    49,    94,   109,
      -1,    42,    -1,    35,    96,    -1,    96,    16,    96,    -1,
      96,    15,    96,    -1,   108,    -1,     6,    -1,    97,    -1,
      50,    96,    51,    -1,    98,    21,    98,    -1,    98,    20,
      98,    -1,    98,    25,    98,    -1,    98,    24,    98,    -1,
      98,    23,    98,    -1,    98,    22,    98,    -1,     3,    -1,
       9,    -1,     4,    -1,     7,    -1,     5,    -1,     8,    -1,
     100,    50,   101,    51,    52,   102,   106,    53,    -1,    40,
      -1,     9,    -1,     7,    -1,     8,    -1,     6,    -1,   103,
     102,    -1,   103,    -1,    -1,    41,   107,    55,   104,    58,
     105,    -1,    45,    49,    -1,    44,    55,    58,    -1,     3,
      -1,     4,    -1,     5,    -1,   108,    -1,    13,    -1,    14,
      -1,   109,    46,    -1,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   116,   116,   119,   119,   119,   119,   119,   119,   120,
     120,   120,   120,   120,   120,   123,   123,   123,   123,   126,
     127,   128,   128,   131,   132,   133,   134,   138,   139,   140,
     141,   145,   146,   146,   149,   157,   165,   173,   184,   184,
     185,   185,   186,   187,   189,   189,   190,   190,   191,   191,
     192,   192,   193,   193,   197,   197,   197,   197,   200,   201,
     202,   203,   204,   206,   207,   208,   209,   210,   211,   213,
     214,   215,   219,   220,   221,   222,   223,   224,   226,   227,
     228,   229,   230,   231,   233,   234,   235,   236,   237,   238,
     240,   241,   242,   246,   246,   249,   250,   254,   260,   273,
     284,   285,   286,   290,   301,   301,   305,   308,   311,   320,
     320,   325,   329,   332,   346,   354,   354,   359,   362,   363,
     371,   379,   380,   389,   390,   396,   397,   398,   399,   400,
     401,   405,   406,   414,   415,   423,   424,   436,   443,   450,
     458,   466,   475,   486,   487,   491,   491,   506,   513,   516,
     517,   518,   519,   524,   525,   528,   529
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
  "ENDL", "START_DECL", "END_DECL", "';'", "'('", "')'", "'{'", "'}'",
  "','", "':'", "$accept", "program", "stmt", "declarations", "variable",
  "$@1", "id1", "decl_assign", "constant_stmt", "$@2", "constant",
  "assignment", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "exprr",
  "int_expr", "float_expr", "float_int_expr", "str_expr",
  "if_else_if_else_stmt", "if_stmt1", "if_stmt", "else_if_stmt",
  "while_loop", "$@10", "start_while_if", "end_while_if", "for_loop",
  "$@11", "start_bool_expr", "end_bool_expr", "for_assignment",
  "repeat_until_loop", "$@12", "start_repeat", "bool_expr", "bool_term",
  "compare_opd", "switch_case", "start_switch", "id", "case_stmts",
  "case_stmt", "$@13", "done", "defaultt", "value", "boolean", "endls", 0
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
     286,   287,   288,   289,   290,   291,   292,   293,   294,    59,
      40,    41,   123,   125,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    60,    62,    62,    62,    62,    63,    63,    63,
      63,    64,    65,    64,    66,    66,    66,    66,    68,    67,
      69,    67,    67,    67,    70,    67,    71,    67,    72,    67,
      73,    67,    74,    67,    75,    75,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    81,    82,
      83,    83,    83,    84,    85,    84,    86,    87,    88,    89,
      88,    90,    91,    92,    93,    94,    93,    95,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    98,    98,    98,    99,   100,   101,
     101,   101,   101,   102,   102,   104,   103,   105,   106,   107,
     107,   107,   107,   108,   108,   109,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     0,     5,     1,     1,     1,     1,     4,     4,     4,
       4,     3,     0,     5,     4,     4,     4,     4,     0,     6,
       0,     6,     5,     5,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     7,     7,
       3,     4,     0,    10,     0,     5,     1,     1,    17,     0,
       5,     0,     0,     3,    11,     0,     5,     1,     2,     3,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     8,     1,     1,
       1,     1,     1,     2,     1,     0,     6,     2,     3,     1,
       1,     1,     1,     1,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   156,     0,     1,     0,     0,   155,     0,
      15,    16,     0,     0,     0,     0,     0,     0,     0,    26,
      24,    25,    23,     0,     0,     0,    17,    18,    32,     0,
       0,     0,     0,    31,    21,     0,     0,     0,     0,     0,
      20,     0,     0,   153,   154,     0,     0,     0,     0,     0,
     131,   133,   135,   122,   134,   136,   132,     0,     0,     0,
     123,     0,   121,    70,    91,    92,    71,     0,     0,    94,
      93,     0,    95,    96,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,   138,     0,     0,     9,
      10,   102,    12,    11,    13,     0,    14,     0,    33,    37,
      35,    36,    34,    22,   118,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,   106,
       0,   109,     0,     0,     0,     0,     3,     4,     6,     5,
       7,     8,     0,    97,     0,     0,   124,   120,   119,   126,
     125,   130,   129,   128,   127,    69,    90,    64,    65,    63,
      67,    68,    58,    84,    59,    85,    60,    86,    61,    87,
      62,    88,     0,    89,    78,    72,    79,    73,    80,    74,
      81,    75,    82,    76,    83,    77,    58,    59,    60,    61,
      62,    70,    91,   135,    92,   136,    71,     0,     0,    56,
      57,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,     0,   115,     0,     0,
     102,     0,   142,   140,   141,   139,     0,    52,    50,     0,
      46,    40,    48,     0,    44,    38,   107,     0,     0,     0,
     111,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,    43,     0,     0,     0,    42,     0,     0,     0,   110,
     113,     0,   105,     0,   116,     0,   101,     0,     0,    53,
      51,    47,    41,    49,    45,    39,     0,   112,     0,     0,
       0,     0,     0,   144,    98,     0,     0,     0,     0,   149,
     150,   151,     0,   152,     0,     0,   143,     0,     0,     0,
       0,   145,     0,   137,     0,     0,    99,     0,     0,     0,
       0,   103,     0,     0,     0,   114,     0,   146,     0,   147,
       0,     0,     0,     0,   108
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    88,     9,    10,    49,    23,    24,    11,    42,
      17,    89,   277,   273,   276,   272,   274,   270,   269,   218,
      69,    70,    71,    74,    90,    91,   240,   163,    92,   261,
     150,   257,    93,   232,   281,   305,   234,    94,   263,    95,
     105,    60,    61,    96,    97,   246,   302,   303,   328,   337,
     315,   312,    62,     4
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
     -18,   -22,    39,  -231,    73,  -231,   100,   178,  -231,     6,
    -231,  -231,    -8,    41,    50,    69,    77,   -22,    46,    85,
     110,   113,   114,    96,   -22,   -22,  -231,  -231,  -231,    62,
      56,   141,   154,   119,  -231,   480,    40,    91,    48,   -22,
     119,   495,   -22,  -231,  -231,   111,   117,   131,   133,   -22,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   480,   480,    15,
    -231,   708,  -231,  -231,  -231,  -231,  -231,    48,    40,   625,
     267,   140,  -231,  -231,   143,    48,   585,   119,   147,   184,
     195,   197,   198,   166,     8,     9,  -231,     4,   516,  -231,
    -231,   153,  -231,  -231,  -231,   172,  -231,   176,   119,  -231,
    -231,  -231,  -231,   119,  -231,    72,   480,   480,  -231,   718,
     718,   718,   718,   718,   718,  -231,   542,   170,    48,    48,
      48,    48,    48,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,  -231,  -231,   559,    48,    48,
      48,    48,    48,  -231,   447,   414,    11,   210,    18,  -231,
     480,  -231,   219,   180,   480,   182,  -231,  -231,  -231,  -231,
    -231,  -231,   -10,  -231,   -22,   231,  -231,   217,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   674,   688,   609,
     290,   290,   327,   335,   327,   335,   201,   209,   201,   209,
     201,   209,   625,   209,   642,   335,   642,   335,   187,   209,
     187,   209,   187,   209,   187,   209,    83,    83,  -231,  -231,
    -231,   714,   720,   194,   726,   202,   732,   464,   213,   625,
     267,  -231,    88,   218,    22,   224,   227,   234,   241,   244,
     601,    76,   253,   256,   249,  -231,    76,  -231,   166,   556,
     153,   495,  -231,  -231,  -231,  -231,   254,  -231,  -231,   -22,
    -231,  -231,  -231,   -22,  -231,  -231,  -231,   257,   -22,    48,
    -231,   -22,   258,   -22,   480,    27,  -231,   155,   260,   -22,
     -22,   119,   -22,   -22,   -22,   119,   -22,   -22,   556,   119,
     659,   480,   119,   -22,   119,    76,  -231,   263,   273,   119,
     119,   119,   119,   119,   119,   119,   334,    88,   495,   264,
     278,   275,   281,   273,  -231,   279,   346,   556,   480,  -231,
    -231,  -231,   274,  -231,   282,   280,  -231,   292,   296,   355,
     102,  -231,   556,  -231,   -22,   -22,  -231,   299,   556,   395,
     495,   119,   -22,   504,   404,   119,   300,  -231,   319,  -231,
     219,   320,   326,   -22,   119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -228,  -231,   368,  -231,  -231,  -231,   369,  -231,
    -231,   -84,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
      10,    44,   233,   -23,   -48,  -231,  -231,   149,   -42,  -231,
     -83,  -230,    -2,  -231,  -231,  -231,    43,     5,  -231,  -231,
     -34,  -231,   470,    17,  -231,  -231,    78,  -231,  -231,  -231,
    -231,  -231,   -26,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -149
static const yytype_int16 yytable[] =
{
      33,    59,   154,    45,   156,   155,   262,    40,    41,   151,
     153,   265,   225,   267,    63,    64,     6,     7,    65,   229,
      66,    63,    77,   104,     3,    98,   238,    66,    78,     1,
     106,   107,   103,    79,    80,    81,    82,   106,   107,     5,
     157,    28,   239,    63,    64,    67,   158,    65,    76,    66,
     296,    63,    67,    29,    25,   299,  -117,    66,   152,   149,
      46,    68,    30,    83,   108,    84,    85,    86,    75,    87,
     306,   249,   167,   168,    67,    43,    44,   115,   116,   319,
     286,    31,    67,     6,     7,   137,   159,   106,   107,    32,
      68,   106,   107,   160,   329,    34,    72,    35,    75,    73,
     333,    12,   334,   106,   107,   161,    13,    14,    15,    16,
     222,   224,   117,   140,   141,   142,   231,   106,   107,     8,
     236,   221,    36,   166,   228,    37,    38,   256,   177,   178,
     179,   180,   181,   182,   184,   186,   188,   190,   192,   194,
     196,   198,   200,   202,   204,    39,    47,   241,   206,   207,
     208,   209,   210,   327,   219,   264,    78,    48,   230,   144,
      99,    79,    80,    81,    82,     8,   100,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   201,   203,   205,    18,
     101,   156,   102,   156,    19,    20,    21,    22,   220,   135,
     162,    83,   136,    84,    85,    86,   145,    87,   129,   130,
     131,   132,   133,   134,   118,   119,   120,   146,   287,   147,
     148,   227,   156,   121,   122,    72,   149,   157,    73,   157,
     128,   176,   156,   158,   164,   158,   165,   116,   233,   235,
     285,   237,   271,   107,   128,   156,   275,   242,   243,   244,
     245,   279,   134,   -95,   282,   156,   284,   297,   157,   156,
     156,   -96,   289,   290,   158,   291,   292,   293,   157,   294,
     295,   117,   247,   159,   158,   159,   298,   248,   259,   280,
     160,   157,   160,   250,   320,   313,   251,   158,   309,   310,
     311,   157,   161,   252,   161,   157,   157,   158,    43,    44,
     253,   158,   158,   254,   159,   129,   130,   131,   132,   133,
     134,   160,   258,   260,   159,   268,   300,   330,   331,   278,
     283,   160,   288,   161,   301,   335,   307,   159,   138,   139,
     140,   141,   142,   161,   160,   314,   344,   159,   308,   321,
     317,   159,   159,   323,   160,    78,   161,   322,   160,   160,
      79,    80,    81,    82,   324,   325,   161,    78,   332,   339,
     161,   161,    79,    80,    81,    82,    78,   125,   126,   127,
     128,    79,    80,    81,    82,   131,   132,   133,   134,   340,
      83,   342,    84,    85,    86,   343,    87,    26,    27,   226,
       0,   316,    83,   341,    84,    85,    86,   304,    87,   266,
       0,    83,     0,    84,    85,    86,    78,    87,     0,   318,
       0,    79,    80,    81,    82,    78,     0,     0,   326,     0,
      79,    80,    81,    82,     0,   223,     0,    50,    51,    52,
      53,    54,    55,    56,     0,     0,     0,    43,    44,     0,
       0,    83,     0,    84,    85,    86,     0,    87,     0,     0,
      83,     0,    84,    85,    86,     0,    87,     0,  -148,    57,
     211,   212,   213,    53,   214,   215,   216,   338,     0,     0,
      43,    44,     0,     0,    58,     0,     0,   211,   212,    52,
      53,   214,    55,   216,     0,     0,     0,    43,    44,     0,
       0,    67,    57,    50,    51,    52,    53,    54,    55,    56,
       0,     0,     0,    43,    44,     0,    78,   217,    67,    57,
       0,    79,    80,    81,    82,    78,     0,     0,     0,     0,
      79,    80,    81,    82,   217,    57,    -2,    78,     0,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      58,    83,     0,    84,    85,    86,     0,    87,     0,     0,
      83,     8,    84,    85,    86,     0,    87,     0,     0,   336,
       0,     0,    83,     0,    84,    85,    86,    78,    87,   118,
     119,   120,    79,    80,    81,    82,     0,     0,   121,   122,
     123,   124,   125,   126,   127,   128,   118,   119,   120,   169,
     170,   171,   172,   173,   174,   121,   122,   138,   139,   140,
     141,   142,    83,   175,    84,    85,    86,     0,    87,     0,
       0,     0,   118,   119,   120,     0,     0,     0,     0,     0,
     175,   121,   122,   138,   139,   140,   141,   142,   118,   119,
     120,     0,     0,     0,     0,     0,     0,   121,   122,   138,
     139,   140,   141,   142,   143,   121,   122,   138,   139,   140,
     141,   142,   118,   119,   120,     0,     0,     0,     0,     0,
     255,   121,   122,   123,   124,   125,   126,   127,   128,   118,
     119,   120,     0,     0,     0,     0,     0,     0,   121,   122,
       0,     0,   125,   126,   127,   128,   118,   119,   120,     0,
       0,     0,     0,     0,     0,   121,   122,   138,   139,   140,
     141,   142,   119,   120,     0,     0,     0,     0,     0,     0,
     121,   122,   138,   139,   140,   141,   142,   120,     0,     0,
       0,     0,     0,     0,   121,   122,   138,   139,   140,   141,
     142,    50,    51,    52,     0,    54,    55,    56,   109,   110,
     111,   112,   113,   114,  -131,  -131,  -131,  -131,  -131,  -131,
    -133,  -133,  -133,  -133,  -133,  -133,  -134,  -134,  -134,  -134,
    -134,  -134,  -132,  -132,  -132,  -132,  -132,  -132
};

static const yytype_int16 yycheck[] =
{
      17,    35,    85,    29,    88,     1,   236,    24,    25,     1,
       1,   239,     1,   241,     3,     4,    10,    11,     7,     1,
       9,     3,    39,    57,    46,    42,    36,     9,     1,    47,
      15,    16,    49,     6,     7,     8,     9,    15,    16,     0,
      88,    49,    52,     3,     4,    34,    88,     7,    38,     9,
     278,     3,    34,    12,    48,   285,    52,     9,    50,    50,
       4,    50,    12,    36,    49,    38,    39,    40,    50,    42,
     298,    49,   106,   107,    34,    13,    14,    67,    68,   307,
      53,    12,    34,    10,    11,    75,    88,    15,    16,    12,
      50,    15,    16,    88,   322,    49,     5,    12,    50,     8,
     328,     1,   330,    15,    16,    88,     6,     7,     8,     9,
     144,   145,    68,    30,    31,    32,   150,    15,    16,    46,
     154,   144,    12,    51,   147,    12,    12,    51,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    49,     5,   164,   138,   139,
     140,   141,   142,    51,   144,   238,     1,     3,   148,    12,
      49,     6,     7,     8,     9,    46,    49,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,     1,
      49,   265,    49,   267,     6,     7,     8,     9,   144,    49,
      37,    36,    49,    38,    39,    40,    12,    42,    28,    29,
      30,    31,    32,    33,    17,    18,    19,    12,    53,    12,
      12,     1,   296,    26,    27,     5,    50,   265,     8,   267,
      33,    51,   306,   265,    52,   267,    50,   217,     9,    49,
     264,    49,   249,    16,    33,   319,   253,     6,     7,     8,
       9,   258,    33,    49,   261,   329,   263,   281,   296,   333,
     334,    49,   269,   270,   296,   272,   273,   274,   306,   276,
     277,   217,    49,   265,   306,   267,   283,    49,    12,   259,
     265,   319,   267,    49,   308,   301,    49,   319,     3,     4,
       5,   329,   265,    49,   267,   333,   334,   329,    13,    14,
      49,   333,   334,    49,   296,    28,    29,    30,    31,    32,
      33,   296,    49,    54,   306,    51,    43,   324,   325,    52,
      52,   306,    52,   296,    41,   332,    52,   319,    28,    29,
      30,    31,    32,   306,   319,    44,   343,   329,    50,    55,
      51,   333,   334,    53,   329,     1,   319,    55,   333,   334,
       6,     7,     8,     9,    52,    49,   329,     1,    49,    49,
     333,   334,     6,     7,     8,     9,     1,    30,    31,    32,
      33,     6,     7,     8,     9,    30,    31,    32,    33,    50,
      36,    51,    38,    39,    40,    49,    42,     9,     9,   146,
      -1,   303,    36,   340,    38,    39,    40,    53,    42,   240,
      -1,    36,    -1,    38,    39,    40,     1,    42,    -1,    53,
      -1,     6,     7,     8,     9,     1,    -1,    -1,    53,    -1,
       6,     7,     8,     9,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    36,    -1,    38,    39,    40,    -1,    42,    -1,    -1,
      36,    -1,    38,    39,    40,    -1,    42,    -1,    53,    35,
       3,     4,     5,     6,     7,     8,     9,    53,    -1,    -1,
      13,    14,    -1,    -1,    50,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    34,    35,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    13,    14,    -1,     1,    50,    34,    35,
      -1,     6,     7,     8,     9,     1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    50,    35,     0,     1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      50,    36,    -1,    38,    39,    40,    -1,    42,    -1,    -1,
      36,    46,    38,    39,    40,    -1,    42,    -1,    -1,    45,
      -1,    -1,    36,    -1,    38,    39,    40,     1,    42,    17,
      18,    19,     6,     7,     8,     9,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    17,    18,    19,   109,
     110,   111,   112,   113,   114,    26,    27,    28,    29,    30,
      31,    32,    36,    51,    38,    39,    40,    -1,    42,    -1,
      -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      51,    26,    27,    28,    29,    30,    31,    32,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    49,    26,    27,    28,    29,    30,
      31,    32,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      49,    26,    27,    28,    29,    30,    31,    32,    33,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      -1,    -1,    30,    31,    32,    33,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,     3,     4,     5,    -1,     7,     8,     9,    20,    21,
      22,    23,    24,    25,    20,    21,    22,    23,    24,    25,
      20,    21,    22,    23,    24,    25,    20,    21,    22,    23,
      24,    25,    20,    21,    22,    23,    24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    57,    46,   109,     0,    10,    11,    46,    59,
      60,    64,     1,     6,     7,     8,     9,    66,     1,     6,
       7,     8,     9,    62,    63,    48,    60,    64,    49,    12,
      12,    12,    12,   109,    49,    12,    12,    12,    12,    49,
     109,   109,    65,    13,    14,   108,     4,     5,     3,    61,
       3,     4,     5,     6,     7,     8,     9,    35,    50,    96,
      97,    98,   108,     3,     4,     7,     9,    34,    50,    76,
      77,    78,     5,     8,    79,    50,    76,   109,     1,     6,
       7,     8,     9,    36,    38,    39,    40,    42,    58,    67,
      80,    81,    84,    88,    93,    95,    99,   100,   109,    49,
      49,    49,    49,   109,    96,    96,    15,    16,    49,    20,
      21,    22,    23,    24,    25,    76,    76,    77,    17,    18,
      19,    26,    27,    28,    29,    30,    31,    32,    33,    28,
      29,    30,    31,    32,    33,    49,    49,    76,    28,    29,
      30,    31,    32,    49,    12,    12,    12,    12,    12,    50,
      86,     1,    50,     1,    86,     1,    67,    80,    84,    88,
      93,    99,    37,    83,    52,    50,    51,    96,    96,    98,
      98,    98,    98,    98,    98,    51,    51,    76,    76,    76,
      76,    76,    76,    77,    76,    77,    76,    77,    76,    77,
      76,    77,    76,    77,    76,    77,    76,    77,    76,    77,
      76,    77,    76,    77,    76,    77,    76,    76,    76,    76,
      76,     3,     4,     5,     7,     8,     9,    50,    75,    76,
      77,    79,    96,     1,    96,     1,    78,     1,    79,     1,
      76,    96,    89,     9,    92,    49,    96,    49,    36,    52,
      82,   109,     6,     7,     8,     9,   101,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    51,    87,    49,    12,
      54,    85,    87,    94,    86,    58,    83,    58,    51,    74,
      73,   109,    71,    69,    72,   109,    70,    68,    52,   109,
      76,    90,   109,    52,   109,    96,    53,    53,    52,   109,
     109,   109,   109,   109,   109,   109,    58,    96,   109,    87,
      43,    41,   102,   103,    53,    91,    58,    52,    50,     3,
       4,     5,   107,   108,    44,   106,   102,    51,    53,    58,
      96,    55,    55,    53,    52,    49,    53,    51,   104,    58,
     109,   109,    49,    58,    58,   109,    45,   105,    53,    49,
      50,    92,    51,    49,   109
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
#line 128 "voo.y"
    { errorVarStmt();;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 131 "voo.y"
    { declIdActions((yyvsp[(1) - (1)].idval),integer);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 132 "voo.y"
    {declIdActions((yyvsp[(1) - (1)].idval),floatt);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 133 "voo.y"
    { declIdActions((yyvsp[(1) - (1)].idval),str);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 134 "voo.y"
    { declIdActions((yyvsp[(1) - (1)].idval),boolean);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 138 "voo.y"
    { declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),integer); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 139 "voo.y"
    {declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),floatt);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 140 "voo.y"
    { declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),str);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 141 "voo.y"
    { declAssignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),boolean);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 146 "voo.y"
    {errorConstStmt();;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 149 "voo.y"
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
#line 157 "voo.y"
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
#line 165 "voo.y"
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
#line 173 "voo.y"
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
#line 184 "voo.y"
    { assignmentActions((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),integer);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 185 "voo.y"
    { assignmentActions ((yyvsp[(1) - (4)].idval),(yyvsp[(3) - (4)].nodeval),floatt);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 186 "voo.y"
    { assignmentActions((yyvsp[(1) - (5)].idval),(yyvsp[(3) - (5)].nodeval),str);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 187 "voo.y"
    { assignmentActions((yyvsp[(1) - (5)].idval),(yyvsp[(3) - (5)].nodeval),boolean);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 189 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid int expression to use !" <<endl;;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 190 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid float expression to use !" <<endl;;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 191 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid string expression to use !" <<endl;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 192 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid bool expression to use !"<<endl;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 193 "voo.y"
    {cout<<"At Line: "<<line_num<<" Not a valid identifier to use !" <<endl;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 200 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS "  <<endl;} ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 201 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS" <<endl; };}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 202 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL" <<endl; } ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 203 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " <<endl; };}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 204 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " <<endl; };}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 206 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_AND " <<endl;} ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 207 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_OR " <<endl; };}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 208 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_xor,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("XOR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_XOR " <<endl; };}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 209 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_not,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "BITWISE_NOT: " <<endl; };}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 210 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_r,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_LEFT: " <<endl; };}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 211 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_l,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_RIGHT: " <<endl; };}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 213 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);	cout << "Brackets  " <<endl; ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 214 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 215 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 219 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS " <<endl; };}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 220 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS " << endl; };}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 221 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL " << endl; } ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 222 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " << endl; };}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 223 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " << endl; };}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 224 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW " << endl; };}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 226 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS " << endl; };}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 227 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS " <<endl; };}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 228 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL " << endl; } ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 229 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " <<endl; };}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 230 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " << endl; };}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 231 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW " << endl; };}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 233 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS" << endl; };}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 234 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS " << endl; };}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 235 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL " << endl;  };}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 236 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " << endl; };}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 237 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " << endl; };}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 238 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW " << endl; };}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 240 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval); cout << "Brackets  " <<endl; ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 241 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval)));  ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 242 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 249 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));  ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 250 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 254 "voo.y"
    {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
	;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 260 "voo.y"
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

  case 99:

/* Line 1455 of yacc.c  */
#line 273 "voo.y"
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
#line 284 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 285 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 286 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 290 "voo.y"
    {
		int temp =brLabels.top();
		brLabels.pop();
		if((yyvsp[(3) - (10)].nodeval)!=NULL){
			generateBranchQuad("JMP",brLabels.top(),NULL);
			outLabel(temp);
		}
		brLabels.pop();	
	;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 301 "voo.y"
    { cout<<"At Line: "<<line_num<<" Not a valid while statement !"<<endl;;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 305 "voo.y"
    {generateLabelPair();;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 308 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 311 "voo.y"
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

  case 109:

/* Line 1455 of yacc.c  */
#line 320 "voo.y"
    { cout<<"At Line: "<<line_num<<" Not a valid for statement !"<<endl;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 325 "voo.y"
    {generateLabelPair();;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 329 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 332 "voo.y"
    {
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (3)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (3)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (3)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (3)].idval));
			} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (3)].idval));}
			 
	;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 346 "voo.y"
    {
		if(!boolRes.empty()){
			generateBranchQuad("JTRUE",brLabels.top(),boolRes.top()); 
			boolRes.pop();
		}
		brLabels.pop();
	;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 354 "voo.y"
    { cout<<"At Line: "<<line_num<<" Not a valid repeat until statement !"<<endl;;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 359 "voo.y"
    {int label=generateOneLabel(); outLabel(label); brLabels.push(label);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 362 "voo.y"
    { cout << "LOGIC_NOT " <<endl; ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 363 "voo.y"
    { 
						(yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));
						if((yyval.nodeval)!=NULL){
							generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
							boolRes.push((yyval.nodeval)); 						
							cout << "LOGIC_AND " <<endl;
						}
					;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 371 "voo.y"
    { 
					(yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));
						if((yyval.nodeval)!=NULL){
							generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
							boolRes.push((yyval.nodeval)); 						
							cout << "LOGIC_OR " <<endl;
						}
					;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 379 "voo.y"
    { cout << "boolean " <<endl; ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 380 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 389 "voo.y"
    { (yyval.nodeval)=(yyvsp[(1) - (1)].nodeval);   if((yyval.nodeval)!=NULL) boolRes.push((yyval.nodeval)); 	;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 390 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);  cout << "Brackets " <<endl; ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 396 "voo.y"
    { (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "EQ " <<endl; };}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 397 "voo.y"
    { (yyval.nodeval)=createNewExprNode(ne,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("NOT_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "NOT_EQ " <<endl; };}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 398 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gt,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR " <<endl; };}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 399 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gte,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR_EQ " <<endl; };}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 400 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sm,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM " <<endl; };}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 401 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sme,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM_EQ " <<endl; };}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 405 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival)));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 406 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 414 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 415 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 423 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 424 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 436 "voo.y"
    {
		outLabel(switchLabels.top());
		switchLabels.pop();
		if(!switchIds.empty()) switchIds.pop();
	;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 443 "voo.y"
    {
		int label = generateOneLabel();
		switchLabels.push(label);
		cout<<"ok start switch";
	;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 450 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 458 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 466 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 475 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 491 "voo.y"
    {
			int l=generateOneLabel();
			brLabels.push(l);
			if(!switchIds.empty()){
				NodeWithType* vv=createNewExprNode(eq,2,switchIds.top(),(yyvsp[(2) - (3)].nodeval)); 
				if(vv!=NULL){
					generateQuad("EQ",switchIds.top(),(yyvsp[(2) - (3)].nodeval),vv);
					generateBranchQuad("JFALSE",brLabels.top(),vv);
				}
			}
		;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 506 "voo.y"
    {
		generateBranchQuad("JMP",switchLabels.top(),NULL);
		outLabel(brLabels.top());
		brLabels.pop();
	;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 513 "voo.y"
    {cout<<"ok def switch";;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 516 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 517 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 518 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 524 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); /*cout<<"bool value"<<endl;*/ ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 525 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); /*cout<<"bool value"<<endl;*/ ;}
    break;



/* Line 1455 of yacc.c  */
#line 2766 "voo.tab.c"
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
#line 531 "voo.y"


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
	FILE *myfile = fopen("sample1.voo", "r");
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
