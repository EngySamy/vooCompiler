
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
#define YYLAST   763

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNRULES -- Number of states.  */
#define YYNSTATES  424

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
     323,   325,   327,   330,   338,   346,   350,   355,   356,   366,
     367,   373,   374,   382,   383,   392,   393,   404,   406,   408,
     426,   427,   434,   435,   443,   444,   457,   458,   472,   473,
     489,   490,   507,   508,   526,   527,   546,   547,   548,   552,
     564,   565,   572,   573,   582,   583,   594,   595,   607,   608,
     621,   623,   626,   630,   634,   636,   638,   640,   644,   648,
     652,   656,   660,   664,   668,   670,   672,   674,   676,   678,
     680,   681,   693,   694,   700,   701,   708,   709,   717,   718,
     727,   728,   739,   741,   743,   745,   747,   749,   752,   754,
     755,   763,   767,   772,   774,   776,   778,   780,   782,   784,
     787
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    48,   128,    60,    49,   128,    59,    -1,
      59,    68,    -1,    59,    79,    -1,    59,    90,    -1,    59,
      83,    -1,    59,   102,    -1,    59,   112,    -1,    68,    -1,
      79,    -1,    90,    -1,    83,    -1,   102,    -1,   112,    -1,
      61,    -1,    65,    -1,    60,    61,    -1,    60,    65,    -1,
      11,    63,    50,   128,    -1,    11,    64,   128,    -1,    -1,
      11,     1,    50,    62,   128,    -1,     9,    -1,     7,    -1,
       8,    -1,     6,    -1,     9,    12,    75,    50,    -1,     7,
      12,    77,    50,    -1,     8,    12,    78,    50,    -1,     6,
      12,   109,    50,    -1,    10,    67,   128,    -1,    -1,    10,
       1,    50,    66,   128,    -1,     9,    12,     3,    50,    -1,
       7,    12,     4,    50,    -1,     8,    12,     5,    50,    -1,
       6,    12,   127,    50,    -1,    -1,     9,    12,    75,    50,
      69,   128,    -1,    -1,     7,    12,    77,    50,    70,   128,
      -1,     8,    12,    78,    50,   128,    -1,     6,    12,   109,
      50,   128,    -1,    -1,     9,    12,     1,    50,    71,   128,
      -1,    -1,     7,    12,     1,    50,    72,   128,    -1,    -1,
       8,    12,     1,    50,    73,   128,    -1,    -1,     6,    12,
       1,    50,    74,   128,    -1,    29,    75,    -1,    75,    28,
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
      -1,    75,    -1,     5,    -1,     8,    -1,    80,    82,    -1,
      37,    88,   109,    89,    53,    59,    54,    -1,    37,    88,
     109,    89,    53,    59,    54,    -1,    38,    81,    82,    -1,
      38,    53,    59,    54,    -1,    -1,    40,    88,   109,    89,
      53,   128,    59,    54,   128,    -1,    -1,    40,     1,    54,
      84,   128,    -1,    -1,    40,    88,   109,     1,    54,    85,
     128,    -1,    -1,    40,    88,   109,    89,     1,    54,    86,
     128,    -1,    -1,    40,    88,   109,    89,    53,   128,     1,
      54,    87,   128,    -1,    51,    -1,    52,    -1,    39,    51,
     101,    55,    99,   109,   100,    52,    53,   128,    59,    54,
      51,   101,    52,    50,   128,    -1,    -1,    39,     1,    52,
      50,    91,   128,    -1,    -1,    39,    51,     1,    52,    50,
      92,   128,    -1,    -1,    39,    51,   101,    55,    99,   109,
     100,     1,    52,    50,    93,   128,    -1,    -1,    39,    51,
     101,    55,    99,   109,   100,    52,     1,    52,    50,    94,
     128,    -1,    -1,    39,    51,   101,    55,    99,   109,   100,
      52,    53,   128,     1,    52,    50,    95,   128,    -1,    -1,
      39,    51,   101,    55,    99,   109,   100,    52,    53,   128,
      59,     1,    52,    50,    96,   128,    -1,    -1,    39,    51,
     101,    55,    99,   109,   100,    52,    53,   128,    59,    54,
       1,    52,    50,    97,   128,    -1,    -1,    39,    51,   101,
      55,    99,   109,   100,    52,    53,   128,    59,    54,    51,
       1,    52,    50,    98,   128,    -1,    -1,    -1,     9,    12,
      75,    -1,   108,    53,   128,    59,    54,    44,    51,   109,
      52,    50,   128,    -1,    -1,   108,     1,    52,    50,   103,
     128,    -1,    -1,   108,    53,   128,     1,    52,    50,   104,
     128,    -1,    -1,   108,    53,   128,    59,    54,     1,    52,
      50,   105,   128,    -1,    -1,   108,    53,   128,    59,    54,
      44,     1,    52,    50,   106,   128,    -1,    -1,   108,    53,
     128,    59,    54,    44,    51,     1,    52,    50,   107,   128,
      -1,    43,    -1,    35,   109,    -1,   109,    16,   109,    -1,
     109,    15,   109,    -1,   127,    -1,     6,    -1,   110,    -1,
      51,   109,    52,    -1,   111,    21,   111,    -1,   111,    20,
     111,    -1,   111,    25,   111,    -1,   111,    24,   111,    -1,
     111,    23,   111,    -1,   111,    22,   111,    -1,     3,    -1,
       9,    -1,     4,    -1,     7,    -1,     5,    -1,     8,    -1,
      -1,   119,    51,   120,    52,    53,   128,   121,   125,    54,
     113,   128,    -1,    -1,   119,     1,    54,   114,   128,    -1,
      -1,   119,    51,     1,    54,   115,   128,    -1,    -1,   119,
      51,   120,     1,    54,   116,   128,    -1,    -1,   119,    51,
     120,    52,     1,    54,   117,   128,    -1,    -1,   119,    51,
     120,    52,    53,   128,     1,    54,   118,   128,    -1,    41,
      -1,     9,    -1,     7,    -1,     8,    -1,     6,    -1,   122,
     121,    -1,   122,    -1,    -1,    42,   126,    56,   123,   128,
      59,   124,    -1,    46,    50,   128,    -1,    45,    56,   128,
      59,    -1,     3,    -1,     4,    -1,     5,    -1,   127,    -1,
      13,    -1,    14,    -1,   128,    47,    -1,    47,    -1
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
     257,   258,   262,   268,   281,   292,   293,   294,   298,   308,
     308,   310,   310,   311,   311,   312,   312,   316,   319,   322,
     332,   332,   333,   333,   334,   334,   335,   335,   336,   336,
     337,   337,   338,   338,   339,   339,   344,   348,   351,   354,
     362,   362,   363,   363,   364,   364,   365,   365,   366,   366,
     372,   375,   376,   377,   378,   379,   380,   381,   385,   386,
     387,   388,   389,   390,   394,   395,   396,   397,   398,   399,
     403,   403,   409,   409,   410,   410,   411,   411,   412,   412,
     413,   413,   418,   424,   425,   426,   427,   431,   432,   436,
     436,   455,   462,   465,   466,   467,   468,   472,   473,   477,
     478
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
  "if_else_if_else_stmt", "if_stmt1", "if_stmt", "else_if_stmt",
  "while_loop", "$@9", "$@10", "$@11", "$@12", "start_while_if",
  "end_while_if", "for_loop", "$@13", "$@14", "$@15", "$@16", "$@17",
  "$@18", "$@19", "$@20", "start_bool_expr", "end_bool_expr",
  "for_assignment", "repeat_until_loop", "$@21", "$@22", "$@23", "$@24",
  "$@25", "start_repeat", "bool_expr", "bool_term", "compare_opd",
  "switch_case", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31",
  "start_switch", "id", "case_stmts", "case_stmt", "$@32", "done",
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
      78,    78,    79,    80,    81,    82,    82,    82,    83,    84,
      83,    85,    83,    86,    83,    87,    83,    88,    89,    90,
      91,    90,    92,    90,    93,    90,    94,    90,    95,    90,
      96,    90,    97,    90,    98,    90,    99,   100,   101,   102,
     103,   102,   104,   102,   105,   102,   106,   102,   107,   102,
     108,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   111,   111,
     113,   112,   114,   112,   115,   112,   116,   112,   117,   112,
     118,   112,   119,   120,   120,   120,   120,   121,   121,   123,
     122,   124,   125,   126,   126,   126,   126,   127,   127,   128,
     128
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
       1,     1,     2,     7,     7,     3,     4,     0,     9,     0,
       5,     0,     7,     0,     8,     0,    10,     1,     1,    17,
       0,     6,     0,     7,     0,    12,     0,    13,     0,    15,
       0,    16,     0,    17,     0,    18,     0,     0,     3,    11,
       0,     6,     0,     8,     0,    10,     0,    11,     0,    12,
       1,     2,     3,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       0,    11,     0,     5,     0,     6,     0,     7,     0,     8,
       0,    10,     1,     1,     1,     1,     1,     2,     1,     0,
       7,     3,     4,     1,     1,     1,     1,     1,     1,     2,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,   190,     0,     1,     0,     0,   189,     0,
      15,    16,     0,     0,     0,     0,     0,     0,     0,    26,
      24,    25,    23,     0,     0,     0,    17,    18,    32,     0,
       0,     0,     0,    31,    21,     0,     0,     0,     0,     0,
      20,     0,     0,   187,   188,     0,     0,     0,     0,     0,
     154,   156,   158,   145,   157,   159,   155,     0,     0,     0,
     146,     0,   144,    65,    86,    87,    66,     0,     0,     0,
      89,    88,     0,    90,    91,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,   172,   140,     2,     9,
      10,    97,    12,    11,    13,     0,    14,     0,    33,    37,
      35,    36,    34,    22,   141,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    52,    61,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,    29,     0,     0,
       0,     0,     0,     0,    27,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     3,     4,     6,     5,     7,
       8,     0,    92,     0,     0,     0,     0,   147,   143,   142,
     149,   148,   153,   152,   151,   150,    64,    85,    59,    60,
      58,    62,    63,    53,    79,    54,    80,    55,    81,    56,
      82,    57,    83,     0,    84,    73,    67,    74,    68,    75,
      69,    76,    70,    77,    71,    78,    72,    53,    54,    55,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,    97,
       0,     0,   162,     0,   176,   174,   175,   173,     0,    50,
       0,    46,    40,    48,     0,    44,    38,   108,     0,   110,
       0,     0,   126,     0,     0,     0,     0,     0,    95,   130,
       0,     0,     0,   164,     0,     0,     0,    43,     0,     0,
       0,    42,     0,     0,     0,     0,   112,   128,     0,   100,
     101,     0,     0,     0,    96,     0,     0,     0,   163,     0,
     166,     0,     0,    51,    47,    41,    49,    45,    39,     0,
     111,     0,   127,     0,   103,     0,     0,   131,   132,     0,
       0,   165,     0,   168,     0,    93,   113,     0,   102,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,   178,     0,     0,   104,   105,     0,     0,   133,
     134,     0,     0,     0,   169,   170,   183,   184,   185,     0,
     186,     0,     0,   177,     0,     0,     0,     0,    98,    94,
       0,   136,     0,     0,     0,   179,     0,   160,   114,     0,
       0,   106,   135,     0,   138,     0,   171,     0,     0,     0,
       0,   116,     0,     0,   137,     0,   129,     0,   182,   161,
     115,     0,     0,     0,     0,   139,     0,   117,   118,     0,
       0,     0,     0,   180,     0,   120,     0,     0,     0,     0,
     119,     0,   122,     0,     0,   181,   121,     0,   124,     0,
     123,     0,   109,   125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    88,     9,    10,    49,    23,    24,    11,    42,
      17,    89,   273,   269,   272,   268,   270,   266,    70,    71,
      72,    75,    90,    91,   229,   162,    92,   253,   303,   319,
     357,   150,   248,    93,   275,   301,   380,   391,   404,   411,
     417,   421,   278,   317,   224,    94,   285,   323,   360,   373,
     385,    95,    59,    60,    61,    96,   379,   262,   289,   312,
     328,   364,    97,   238,   331,   332,   377,   403,   352,   349,
      62,     4
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -226
static const yytype_int16 yypact[] =
{
     -34,   -31,    34,  -226,    28,  -226,   270,   328,  -226,    94,
    -226,  -226,   -10,    50,    58,    98,   102,   -31,    83,   129,
     130,   134,   142,   105,   -31,   -31,  -226,  -226,  -226,    30,
     162,   104,   172,   133,  -226,   422,   386,   176,   169,   -31,
     133,   567,   -31,  -226,  -226,   137,   139,   145,   149,   -31,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,   422,   422,   119,
    -226,   657,  -226,  -226,  -226,  -226,  -226,   169,   169,   386,
     668,   599,   150,  -226,  -226,   154,   169,   566,   133,   201,
     202,   204,   207,   171,    20,    29,  -226,  -226,   580,  -226,
    -226,   187,  -226,  -226,  -226,     2,  -226,    45,   133,  -226,
    -226,  -226,  -226,   133,  -226,    26,   422,   422,  -226,   552,
     552,   552,   552,   552,   552,  -226,  -226,   607,   179,   169,
     169,   169,   169,   169,   386,   386,   386,   386,   386,   386,
     386,   386,   386,   386,   386,   386,  -226,  -226,   624,   169,
     169,   169,   169,   169,  -226,   372,    47,   166,   167,  -226,
     422,   174,    36,   175,   422,  -226,  -226,  -226,  -226,  -226,
    -226,   -22,  -226,   178,   -31,   180,   344,  -226,   217,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,   717,   731,
     432,   571,   571,   131,   339,   131,   339,   205,   214,   205,
     214,   205,   214,   668,   214,   685,   339,   685,   339,   263,
     214,   263,   214,   263,   214,   263,   214,   210,   210,  -226,
    -226,  -226,   200,   135,   209,   211,   212,   219,   223,   643,
      92,   235,   215,   252,   233,  -226,    11,   171,   580,   187,
     241,   502,  -226,   239,  -226,  -226,  -226,  -226,    22,  -226,
     -31,  -226,  -226,  -226,   -31,  -226,  -226,  -226,   244,  -226,
     248,   169,  -226,   -31,   240,     4,   422,   435,  -226,  -226,
     249,   440,   -31,  -226,   246,    16,   -31,   133,   -31,   -31,
     -31,   133,   -31,   -31,   580,   -31,  -226,   702,   422,   133,
    -226,   253,   -31,    92,  -226,   -31,   264,    59,   133,   -31,
    -226,   268,   -31,   133,   133,   133,   133,   133,   133,   445,
     133,   -31,    86,   -31,  -226,   511,   274,   133,  -226,   271,
      46,   133,   -31,  -226,    35,  -226,   133,    27,   133,   -31,
     276,   461,   580,   -31,   281,   286,   405,   133,   -31,   288,
     312,   299,   304,   296,    19,   133,  -226,   -31,   484,   133,
    -226,   305,   309,    97,   133,  -226,  -226,  -226,  -226,   301,
    -226,   308,   311,  -226,   316,   330,   -31,   -31,   133,  -226,
     -31,  -226,   333,   334,   -31,  -226,   -31,  -226,  -226,   338,
     525,   133,   133,   -31,  -226,   -31,   133,   -31,   567,   -31,
     -31,  -226,   345,   151,   133,   -31,   133,   567,   580,   133,
     133,   -31,   341,   346,    48,   133,   572,   133,  -226,   349,
     351,    52,   355,  -226,   -31,  -226,   366,   365,   369,   -31,
     133,   -31,  -226,   374,   382,   133,   133,   -31,  -226,   -31,
     133,   -31,   133,   133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,  -222,  -226,   387,  -226,  -226,  -226,   392,  -226,
    -226,   -84,  -226,  -226,  -226,  -226,  -226,  -226,    -3,   -40,
     287,   275,   -78,  -226,  -226,   216,   -75,  -226,  -226,  -226,
    -226,   -74,  -225,   -64,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,    33,   -55,  -226,  -226,  -226,  -226,
    -226,  -226,   -39,  -226,   535,   -29,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,   106,  -226,  -226,  -226,  -226,  -226,
     -27,   -17
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      33,   255,    45,   163,   155,   281,   257,    40,    41,   261,
     156,   154,   254,   157,     1,   227,     3,   291,   104,   105,
     355,   151,    78,   264,   158,    98,   106,   107,   333,   118,
     153,   228,   103,   159,     5,    77,   329,   222,     6,     7,
      28,   106,   107,    43,    44,   223,   165,   325,   214,   400,
      63,    64,   299,   407,    65,   164,    66,   282,   306,   160,
     309,   223,    29,   247,   115,   116,   117,   168,   169,   292,
      30,   152,   356,   138,   265,     8,    67,   330,   167,   334,
     149,    68,     8,   321,   184,   186,   188,   190,   192,   194,
     196,   198,   200,   202,   204,   206,   166,   326,    69,   401,
     338,   106,   107,   310,     6,     7,   213,   106,   107,    47,
      31,   220,   106,   107,    32,   226,   178,   179,   180,   181,
     182,   183,   185,   187,   189,   191,   193,   195,   197,   199,
     201,   203,   205,    34,   106,   107,   207,   208,   209,   210,
     211,    35,    36,    25,   247,   219,    37,   231,   383,   363,
     106,   107,   393,   256,    38,    39,   388,    79,    80,    81,
      82,   126,   127,   128,   129,   396,    46,   216,   218,   108,
      63,    73,    63,   155,    74,    48,    66,   155,    66,   156,
       8,    73,   157,   156,    74,   240,   157,    99,    83,   100,
      84,    85,    86,   158,    87,   101,    67,   158,    67,   102,
     136,    68,   159,    68,   137,   394,   159,   130,   131,   132,
     133,   134,   135,   145,   146,   155,   147,   283,    76,   148,
      76,   156,   149,   267,   157,   161,   221,   271,   160,   225,
     230,   177,   160,   107,   232,   158,   279,   155,   129,   302,
     141,   142,   143,   156,   159,   288,   157,   135,   277,   293,
     239,   294,   295,   296,   155,   297,   298,   158,   300,   241,
     156,   242,   243,   157,   251,   305,   159,   250,   307,   244,
     160,    12,   311,   245,   158,   314,    13,    14,    15,    16,
     119,   120,   121,   159,   316,   249,   318,   343,   252,   122,
     123,   259,   160,   263,   280,   327,   129,   274,   276,   155,
     290,   286,   335,   350,   155,   156,   339,   304,   157,   160,
     156,   344,   155,   157,   308,   346,   347,   348,   156,   158,
     358,   157,   313,   324,   158,    43,    44,   322,   159,    18,
     336,   340,   158,   159,    19,    20,    21,    22,   341,   370,
     371,   159,   345,   372,   351,   233,   330,   376,   354,   378,
     234,   235,   236,   237,   160,   361,   384,   365,   386,   160,
     387,   362,   389,   390,   366,   367,   368,   160,   395,   132,
     133,   134,   135,   212,   397,    50,    51,    52,    53,    54,
      55,    56,   369,   374,   375,    43,    44,   410,   381,    63,
      64,   398,   415,    65,   416,    66,    26,   392,   399,   405,
     420,    27,   422,   406,   423,   409,   342,    57,    50,    51,
      52,    53,    54,    55,    56,    67,   412,   413,    43,    44,
      68,   414,   217,    58,   418,    50,    51,    52,    53,    54,
      55,    56,   419,   215,   408,    43,    44,    69,   353,     0,
      57,    79,    80,    81,    82,   258,    79,    80,    81,    82,
       0,    79,    80,    81,    82,     0,    58,    57,   122,   123,
     139,   140,   141,   142,   143,     0,     0,    79,    80,    81,
      82,     0,    83,    58,    84,    85,    86,    83,    87,    84,
      85,    86,    83,    87,    84,    85,    86,     0,    87,   284,
      79,    80,    81,    82,   287,     0,     0,     0,    83,   315,
      84,    85,    86,   260,    87,     0,     0,     0,    79,    80,
      81,    82,   320,     0,     0,   337,     0,    79,    80,    81,
      82,    83,     0,    84,    85,    86,   382,    87,     0,     0,
       0,    79,    80,    81,    82,     0,     0,     0,   359,    83,
       0,    84,    85,    86,     0,    87,     0,     0,    83,     8,
      84,    85,    86,     0,    87,    50,    51,    52,     8,    54,
      55,    56,    83,     0,    84,    85,    86,     0,    87,     0,
       0,     0,     8,    79,    80,    81,    82,     0,    79,    80,
      81,    82,     0,   119,   120,   121,    79,    80,    81,    82,
       0,     0,   122,   123,   139,   140,   141,   142,   143,   139,
     140,   141,   142,   143,    83,     0,    84,    85,    86,    83,
      87,    84,    85,    86,     8,    87,   144,    83,   402,    84,
      85,    86,     0,    87,   119,   120,   121,   130,   131,   132,
     133,   134,   135,   122,   123,   124,   125,   126,   127,   128,
     129,   119,   120,   121,   170,   171,   172,   173,   174,   175,
     122,   123,   139,   140,   141,   142,   143,     0,     0,   176,
     119,   120,   121,     0,     0,     0,     0,     0,     0,   122,
     123,   139,   140,   141,   142,   143,   176,   109,   110,   111,
     112,   113,   114,     0,     0,   119,   120,   121,     0,     0,
       0,     0,     0,   246,   122,   123,   124,   125,   126,   127,
     128,   129,   119,   120,   121,     0,     0,     0,     0,     0,
       0,   122,   123,     0,     0,   126,   127,   128,   129,   119,
     120,   121,     0,     0,     0,     0,     0,     0,   122,   123,
     139,   140,   141,   142,   143,   120,   121,     0,     0,     0,
       0,     0,     0,   122,   123,   139,   140,   141,   142,   143,
     121,     0,     0,     0,     0,     0,     0,   122,   123,   139,
     140,   141,   142,   143
};

static const yytype_int16 yycheck[] =
{
      17,   226,    29,     1,    88,     1,   228,    24,    25,   231,
      88,    85,     1,    88,    48,    37,    47,     1,    57,    58,
       1,     1,    39,     1,    88,    42,    15,    16,     1,    69,
       1,    53,    49,    88,     0,    38,     1,     1,    10,    11,
      50,    15,    16,    13,    14,     9,     1,     1,     1,     1,
       3,     4,   274,     1,     7,    53,     9,    53,   283,    88,
       1,     9,    12,    52,    67,    68,    69,   106,   107,    53,
      12,    51,    53,    76,    52,    47,    29,    42,    52,    52,
      51,    34,    47,   305,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    51,    51,    51,    51,
     322,    15,    16,    44,    10,    11,   145,    15,    16,     5,
      12,   150,    15,    16,    12,   154,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,    50,    15,    16,   139,   140,   141,   142,
     143,    12,    12,    49,    52,   148,    12,   164,   370,    52,
      15,    16,     1,   227,    12,    50,   378,     6,     7,     8,
       9,    30,    31,    32,    33,   387,     4,     1,     1,    50,
       3,     5,     3,   257,     8,     3,     9,   261,     9,   257,
      47,     5,   257,   261,     8,    50,   261,    50,    37,    50,
      39,    40,    41,   257,    43,    50,    29,   261,    29,    50,
      50,    34,   257,    34,    50,    54,   261,    28,    29,    30,
      31,    32,    33,    12,    12,   299,    12,   256,    51,    12,
      51,   299,    51,   240,   299,    38,    52,   244,   257,    54,
      52,    52,   261,    16,    54,   299,   253,   321,    33,   278,
      30,    31,    32,   321,   299,   262,   321,    33,   251,   266,
      50,   268,   269,   270,   338,   272,   273,   321,   275,    50,
     338,    50,    50,   338,    12,   282,   321,    52,   285,    50,
     299,     1,   289,    50,   338,   292,     6,     7,     8,     9,
      17,    18,    19,   338,   301,    50,   303,   326,    55,    26,
      27,    50,   321,    54,    54,   312,    33,    53,    50,   383,
      54,    52,   319,   330,   388,   383,   323,    54,   383,   338,
     388,   328,   396,   388,    50,     3,     4,     5,   396,   383,
     337,   396,    54,    52,   388,    13,    14,    53,   383,     1,
      54,    50,   396,   388,     6,     7,     8,     9,    52,   356,
     357,   396,    54,   360,    45,     1,    42,   364,    52,   366,
       6,     7,     8,     9,   383,    50,   373,    56,   375,   388,
     377,    52,   379,   380,    56,    54,    50,   396,   385,    30,
      31,    32,    33,     1,   391,     3,     4,     5,     6,     7,
       8,     9,    52,    50,    50,    13,    14,   404,    50,     3,
       4,    50,   409,     7,   411,     9,     9,    52,    52,    50,
     417,     9,   419,    52,   421,    50,     1,    35,     3,     4,
       5,     6,     7,     8,     9,    29,    50,    52,    13,    14,
      34,    52,   147,    51,    50,     3,     4,     5,     6,     7,
       8,     9,    50,   146,   401,    13,    14,    51,   332,    -1,
      35,     6,     7,     8,     9,   229,     6,     7,     8,     9,
      -1,     6,     7,     8,     9,    -1,    51,    35,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,     6,     7,     8,
       9,    -1,    37,    51,    39,    40,    41,    37,    43,    39,
      40,    41,    37,    43,    39,    40,    41,    -1,    43,    54,
       6,     7,     8,     9,    54,    -1,    -1,    -1,    37,    54,
      39,    40,    41,     1,    43,    -1,    -1,    -1,     6,     7,
       8,     9,     1,    -1,    -1,    54,    -1,     6,     7,     8,
       9,    37,    -1,    39,    40,    41,     1,    43,    -1,    -1,
      -1,     6,     7,     8,     9,    -1,    -1,    -1,    54,    37,
      -1,    39,    40,    41,    -1,    43,    -1,    -1,    37,    47,
      39,    40,    41,    -1,    43,     3,     4,     5,    47,     7,
       8,     9,    37,    -1,    39,    40,    41,    -1,    43,    -1,
      -1,    -1,    47,     6,     7,     8,     9,    -1,     6,     7,
       8,     9,    -1,    17,    18,    19,     6,     7,     8,     9,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    28,
      29,    30,    31,    32,    37,    -1,    39,    40,    41,    37,
      43,    39,    40,    41,    47,    43,    50,    37,    46,    39,
      40,    41,    -1,    43,    17,    18,    19,    28,    29,    30,
      31,    32,    33,    26,    27,    28,    29,    30,    31,    32,
      33,    17,    18,    19,   109,   110,   111,   112,   113,   114,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    52,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    52,    20,    21,    22,
      23,    24,    25,    -1,    -1,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    50,    26,    27,    28,    29,    30,    31,
      32,    33,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    30,    31,    32,    33,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    58,    47,   128,     0,    10,    11,    47,    60,
      61,    65,     1,     6,     7,     8,     9,    67,     1,     6,
       7,     8,     9,    63,    64,    49,    61,    65,    50,    12,
      12,    12,    12,   128,    50,    12,    12,    12,    12,    50,
     128,   128,    66,    13,    14,   127,     4,     5,     3,    62,
       3,     4,     5,     6,     7,     8,     9,    35,    51,   109,
     110,   111,   127,     3,     4,     7,     9,    29,    34,    51,
      75,    76,    77,     5,     8,    78,    51,    75,   128,     6,
       7,     8,     9,    37,    39,    40,    41,    43,    59,    68,
      79,    80,    83,    90,   102,   108,   112,   119,   128,    50,
      50,    50,    50,   128,   109,   109,    15,    16,    50,    20,
      21,    22,    23,    24,    25,    75,    75,    75,    76,    17,
      18,    19,    26,    27,    28,    29,    30,    31,    32,    33,
      28,    29,    30,    31,    32,    33,    50,    50,    75,    28,
      29,    30,    31,    32,    50,    12,    12,    12,    12,    51,
      88,     1,    51,     1,    88,    68,    79,    83,    90,   102,
     112,    38,    82,     1,    53,     1,    51,    52,   109,   109,
     111,   111,   111,   111,   111,   111,    52,    52,    75,    75,
      75,    75,    75,    75,    76,    75,    76,    75,    76,    75,
      76,    75,    76,    75,    76,    75,    76,    75,    76,    75,
      76,    75,    76,    75,    76,    75,    76,    75,    75,    75,
      75,    75,     1,   109,     1,    77,     1,    78,     1,    75,
     109,    52,     1,     9,   101,    54,   109,    37,    53,    81,
      52,   128,    54,     1,     6,     7,     8,     9,   120,    50,
      50,    50,    50,    50,    50,    50,    50,    52,    89,    50,
      52,    12,    55,    84,     1,    89,    88,    59,    82,    50,
       1,    59,   114,    54,     1,    52,    74,   128,    72,    70,
      73,   128,    71,    69,    53,    91,    50,    75,    99,   128,
      54,     1,    53,   109,    54,   103,    52,    54,   128,   115,
      54,     1,    53,   128,   128,   128,   128,   128,   128,    59,
     128,    92,   109,    85,    54,   128,    89,   128,    50,     1,
      44,   128,   116,    54,   128,    54,   128,   100,   128,    86,
       1,    59,    53,   104,    52,     1,    51,   128,   117,     1,
      42,   121,   122,     1,    52,   128,    54,    54,    59,   128,
      50,    52,     1,   109,   128,    54,     3,     4,     5,   126,
     127,    45,   125,   121,    52,     1,    53,    87,   128,    54,
     105,    50,    52,    52,   118,    56,    56,    54,    50,    52,
     128,   128,   128,   106,    50,    50,   128,   123,   128,   113,
      93,    50,     1,    59,   128,   107,   128,   128,    59,   128,
     128,    94,    52,     1,    54,   128,    59,   128,    50,    52,
       1,    51,    46,   124,    95,    50,    52,     1,   101,    50,
     128,    96,    50,    52,    52,   128,   128,    97,    50,    50,
     128,    98,   128,   128
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
#line 281 "voo.y"
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

  case 95:

/* Line 1455 of yacc.c  */
#line 292 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 293 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 294 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 298 "voo.y"
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

  case 99:

/* Line 1455 of yacc.c  */
#line 308 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' after 'while' !"<<endl;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 310 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected ')' after boolean expression of while statement !"<<endl;if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 311 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after (boolean expression) of while statement !"<<endl;if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 312 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in statements of while statement !"<<endl;if(!boolRes.empty()) boolRes.pop();;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 316 "voo.y"
    {generateLabelPair();;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 319 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 322 "voo.y"
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

  case 110:

/* Line 1455 of yacc.c  */
#line 332 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '(' after 'for' !"<<endl;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 333 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: error in the for iteration assignment statement or boolean expression !"<<endl;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 334 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected ')' after the boolean expression !"<<endl;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 335 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '{' after boolean expression !"<<endl;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 336 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: error in the statements of the for loop !"<<endl;;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 337 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '}' after the last statement in the for loop !"<<endl;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 338 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: expected '(' after '}' !"<<endl;;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 339 "voo.y"
    { cout<<"At Line: "<<line_num<<" for loop: error in for iteration assignment statement !"<<endl;;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 344 "voo.y"
    {generateLabelPair();;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 348 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 351 "voo.y"
    {assignmentActions((yyvsp[(1) - (3)].idval),(yyvsp[(3) - (3)].nodeval),integer);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 354 "voo.y"
    {
		if(!boolRes.empty()){
			generateBranchQuad("JTRUE",brLabels.top(),boolRes.top()); 
			boolRes.pop();
		}
		brLabels.pop();
	;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 362 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after repeat !"<<endl;brLabels.pop();;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 363 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in statements of repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 364 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected 'UNTIL' after '}' repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 365 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' after 'UNTIL' repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 366 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in boolean expression of repeat-until statement !"<<endl;brLabels.pop();;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 372 "voo.y"
    {int label=generateOneLabel(); outLabel(label); brLabels.push(label);;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 375 "voo.y"
    {(yyval.nodeval)=createNewExprNode(l_not,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("LOG_NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); boolRes.push((yyval.nodeval)); } ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 376 "voo.y"
    { (yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("LOG_AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); boolRes.push((yyval.nodeval)); } ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 377 "voo.y"
    { (yyval.nodeval)=createNewExprNode(l_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));if((yyval.nodeval)!=NULL){generateQuad("LOG_OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); boolRes.push((yyval.nodeval));} ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 378 "voo.y"
    { (yyval.nodeval)=(yyvsp[(1) - (1)].nodeval); boolRes.push((yyval.nodeval)); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 379 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); boolRes.push((yyval.nodeval)); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 380 "voo.y"
    { (yyval.nodeval)=(yyvsp[(1) - (1)].nodeval);   if((yyval.nodeval)!=NULL) boolRes.push((yyval.nodeval)); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 381 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);  cout << "Brackets " <<endl; ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 385 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "EQ " <<endl; };}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 386 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(ne,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("NOT_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "NOT_EQ " <<endl; };}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 387 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(gt,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR " <<endl; };}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 388 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(gte,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR_EQ " <<endl; };}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 389 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(sm,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM " <<endl; };}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 390 "voo.y"
    { if(!compareTwoOperandsTypes((yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)))errorOperandsTypeMismatch(); (yyval.nodeval)=createNewExprNode(sme,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM_EQ " <<endl; };}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 394 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival)));;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 395 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 396 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 397 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 398 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 399 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 403 "voo.y"
    {
		outLabel(switchLabels.top());
		switchLabels.pop();
		if(!switchIds.empty()) switchIds.pop();
	;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 409 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' in SWITCH statement !"<<endl; switchLabels.pop();;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 410 "voo.y"
    { cout<<"At Line: "<<line_num<<" not a valid identifier in SWITCH statement !"<<endl; switchLabels.pop();;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 411 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '(' after identifier in SWITCH statement !"<<endl; switchLabels.pop();;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 412 "voo.y"
    { cout<<"At Line: "<<line_num<<" expected '{' after (identifier)  in SWITCH statement !"<<endl;switchLabels.pop();;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 413 "voo.y"
    { cout<<"At Line: "<<line_num<<" error in cases of in SWITCH statement !"<<endl;switchLabels.pop();;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 418 "voo.y"
    {
		int label = generateOneLabel();
		switchLabels.push(label);
	;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 424 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval));;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 425 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval));;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 426 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval)); switchIds.push((yyval.nodeval));;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 427 "voo.y"
    { (yyval.nodeval)=newIdActions((yyvsp[(1) - (1)].idval));switchIds.push((yyval.nodeval)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 436 "voo.y"
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

  case 181:

/* Line 1455 of yacc.c  */
#line 455 "voo.y"
    {
		generateBranchQuad("JMP",switchLabels.top(),NULL);
		outLabel(brLabels.top());
		brLabels.pop();
	;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 465 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 466 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 467 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 472 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool(true)); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 473 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool(false)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2895 "voo.tab.c"
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
#line 480 "voo.y"


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
