
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


Node * NewNodeFloat(float );
Node * NewNodeInt(int);
Node * NewNodeString(char *);
Node * NewNodeBool(bool);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0,cntLabels=0;



/* Line 189 of yacc.c  */
#line 135 "voo.tab.c"

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
     ENDL = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 67 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;
	bool bval;
	struct NodeWithType * nodeval;



/* Line 214 of yacc.c  */
#line 219 "voo.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 231 "voo.tab.c"

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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   801

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  153
/* YYNRULES -- Number of states.  */
#define YYNSTATES  337

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    32,    19,     2,
      48,    49,    30,    28,    52,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    17,    51,    34,     2,     2,     2,
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
      44,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    15,    18,    21,    24,
      27,    29,    31,    33,    35,    37,    39,    41,    43,    48,
      52,    53,    59,    61,    63,    65,    67,    72,    77,    82,
      87,    91,    92,    98,   103,   108,   113,   118,   124,   130,
     136,   142,   143,   150,   151,   158,   159,   166,   167,   174,
     175,   182,   184,   186,   188,   190,   194,   198,   202,   206,
     210,   214,   218,   222,   225,   229,   233,   237,   239,   241,
     245,   249,   253,   257,   261,   265,   269,   273,   277,   281,
     285,   289,   293,   297,   301,   305,   309,   313,   317,   319,
     321,   323,   325,   327,   329,   332,   340,   348,   352,   357,
     358,   369,   370,   376,   378,   380,   398,   399,   405,   406,
     407,   411,   423,   424,   430,   432,   435,   439,   443,   445,
     447,   449,   453,   457,   461,   465,   469,   473,   477,   479,
     481,   483,   485,   487,   489,   498,   500,   502,   504,   506,
     508,   511,   513,   514,   521,   524,   528,   530,   532,   534,
     536,   538,   540,   543
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    55,    56,    -1,    55,    60,    -1,    55,
      63,    -1,    55,    74,    -1,    55,    82,    -1,    55,    78,
      -1,    55,    87,    -1,    55,    93,    -1,    56,    -1,    60,
      -1,    63,    -1,    74,    -1,    82,    -1,    78,    -1,    87,
      -1,    93,    -1,    11,    58,    47,   103,    -1,    11,    59,
     103,    -1,    -1,    11,     1,    47,    57,   103,    -1,     9,
      -1,     7,    -1,     8,    -1,     6,    -1,     9,    12,    70,
      47,    -1,     7,    12,    72,    47,    -1,     8,    12,    73,
      47,    -1,     6,    12,    90,    47,    -1,    10,    62,   103,
      -1,    -1,    10,     1,    47,    61,   103,    -1,     9,    12,
       3,    47,    -1,     7,    12,     4,    47,    -1,     8,    12,
       5,    47,    -1,     6,    12,   102,    47,    -1,     9,    12,
      70,    47,   103,    -1,     7,    12,    72,    47,   103,    -1,
       8,    12,    73,    47,   103,    -1,     6,    12,    90,    47,
     103,    -1,    -1,     9,    12,     1,    47,    64,   103,    -1,
      -1,     7,    12,     1,    47,    65,   103,    -1,    -1,     8,
      12,     1,    47,    66,   103,    -1,    -1,     6,    12,     1,
      47,    67,   103,    -1,    -1,     1,    12,    69,    47,    68,
     103,    -1,    73,    -1,    90,    -1,    70,    -1,    71,    -1,
      70,    28,    70,    -1,    70,    29,    70,    -1,    70,    30,
      70,    -1,    70,    31,    70,    -1,    70,    32,    70,    -1,
      70,    19,    70,    -1,    70,    17,    70,    -1,    70,    18,
      70,    -1,    34,    70,    -1,    70,    26,    70,    -1,    70,
      27,    70,    -1,    48,    70,    49,    -1,     3,    -1,     9,
      -1,    71,    28,    71,    -1,    71,    29,    71,    -1,    71,
      30,    71,    -1,    71,    31,    71,    -1,    71,    32,    71,
      -1,    71,    33,    71,    -1,    71,    28,    70,    -1,    71,
      29,    70,    -1,    71,    30,    70,    -1,    71,    31,    70,
      -1,    71,    32,    70,    -1,    71,    33,    70,    -1,    70,
      28,    71,    -1,    70,    29,    71,    -1,    70,    30,    71,
      -1,    70,    31,    71,    -1,    70,    32,    71,    -1,    70,
      33,    71,    -1,    48,    71,    49,    -1,     4,    -1,     7,
      -1,    71,    -1,    70,    -1,     5,    -1,     8,    -1,    75,
      77,    -1,    36,    80,    90,    81,    50,    55,    51,    -1,
      36,    80,    90,    81,    50,    55,    51,    -1,    37,    76,
      77,    -1,    37,    50,    55,    51,    -1,    -1,    39,    80,
      90,    81,    50,   103,    55,    51,    47,   103,    -1,    -1,
      39,     1,    47,    79,   103,    -1,    48,    -1,    49,    -1,
      38,    48,    86,    52,    84,    90,    85,    49,    50,   103,
      55,    51,    48,    86,    49,    47,   103,    -1,    -1,    38,
       1,    83,    47,   103,    -1,    -1,    -1,     9,    12,    70,
      -1,    89,    50,   103,    55,    51,    43,    48,    90,    49,
      47,   103,    -1,    -1,    42,     1,    47,    88,   103,    -1,
      42,    -1,    35,    90,    -1,    90,    16,    90,    -1,    90,
      15,    90,    -1,   102,    -1,     6,    -1,    91,    -1,    48,
      90,    49,    -1,    92,    21,    92,    -1,    92,    20,    92,
      -1,    92,    25,    92,    -1,    92,    24,    92,    -1,    92,
      23,    92,    -1,    92,    22,    92,    -1,     3,    -1,     9,
      -1,     4,    -1,     7,    -1,     5,    -1,     8,    -1,    94,
      48,    95,    49,    50,    96,   100,    51,    -1,    40,    -1,
       9,    -1,     7,    -1,     8,    -1,     6,    -1,    97,    96,
      -1,    97,    -1,    -1,    41,   101,    53,    98,    55,    99,
      -1,    45,    47,    -1,    44,    53,    55,    -1,     3,    -1,
       4,    -1,     5,    -1,   102,    -1,    13,    -1,    14,    -1,
     103,    46,    -1,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   113,   114,
     115,   115,   119,   127,   135,   143,   155,   169,   180,   190,
     208,   209,   209,   212,   222,   232,   242,   255,   268,   281,
     293,   308,   308,   309,   309,   310,   310,   311,   311,   312,
     312,   316,   316,   316,   316,   319,   320,   321,   322,   323,
     325,   326,   327,   328,   329,   330,   332,   333,   334,   345,
     346,   347,   348,   349,   350,   352,   353,   354,   355,   356,
     357,   359,   360,   361,   362,   363,   364,   366,   367,   368,
     379,   379,   382,   383,   394,   400,   413,   424,   425,   426,
     430,   441,   441,   445,   448,   451,   460,   460,   465,   469,
     472,   486,   494,   494,   499,   502,   503,   511,   519,   520,
     529,   530,   536,   537,   538,   539,   540,   541,   545,   546,
     554,   555,   563,   564,   576,   583,   590,   598,   606,   615,
     626,   627,   631,   631,   646,   653,   656,   657,   658,   659,
     664,   665,   668,   669
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
  "ENDL", "';'", "'('", "')'", "'{'", "'}'", "','", "':'", "$accept",
  "stmt", "variable", "$@1", "id1", "decl_assign", "constant_stmt", "$@2",
  "constant", "assignment", "$@3", "$@4", "$@5", "$@6", "$@7", "exprr",
  "int_expr", "float_expr", "float_int_expr", "str_expr",
  "if_else_if_else_stmt", "if_stmt1", "if_stmt", "else_if_stmt",
  "while_loop", "$@8", "start_while_if", "end_while_if", "for_loop", "$@9",
  "start_bool_expr", "end_bool_expr", "for_assignment",
  "repeat_until_loop", "$@10", "start_repeat", "bool_expr", "bool_term",
  "compare_opd", "switch_case", "start_switch", "id", "case_stmts",
  "case_stmt", "$@11", "done", "defaultt", "value", "boolean", "endls", 0
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
     286,   287,   288,   289,   290,   291,   292,    59,    40,    41,
     123,   125,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    56,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    61,    60,    62,    62,    62,    62,    63,    63,    63,
      63,    64,    63,    65,    63,    66,    63,    67,    63,    68,
      63,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    75,    76,    77,    77,    77,
      78,    79,    78,    80,    81,    82,    83,    82,    84,    85,
      86,    87,    88,    87,    89,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    94,    95,    95,    95,    95,
      96,    96,    98,    97,    99,   100,   101,   101,   101,   101,
     102,   102,   103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       0,     5,     1,     1,     1,     1,     4,     4,     4,     4,
       3,     0,     5,     4,     4,     4,     4,     5,     5,     5,
       5,     0,     6,     0,     6,     0,     6,     0,     6,     0,
       6,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     2,     7,     7,     3,     4,     0,
      10,     0,     5,     1,     1,    17,     0,     5,     0,     0,
       3,    11,     0,     5,     1,     2,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     8,     1,     1,     1,     1,     1,
       2,     1,     0,     6,     2,     3,     1,     1,     1,     1,
       1,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,     0,    10,    11,    12,    13,    99,    15,
      14,    16,     0,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    23,    24,
      22,     0,     0,   103,     0,   106,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     7,     6,     8,     9,     0,
      94,     0,     0,    67,    88,   132,   119,    89,   133,    68,
     150,   151,     0,     0,     0,     0,    53,    54,    51,    52,
     120,     0,   118,     0,   128,   130,   132,   131,   133,   129,
       0,     0,     0,    67,    88,    89,    68,     0,    91,    90,
       0,     0,    92,    93,     0,     0,     0,     0,    31,     0,
       0,     0,     0,   153,    30,    20,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,   101,     0,   112,     0,
       0,    99,     0,   139,   137,   138,   136,     0,    63,   115,
       0,     0,     0,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,    43,     0,    45,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,     0,     0,     0,    18,   104,     0,     0,     0,   108,
       0,     0,     0,     0,     0,    97,     0,     0,    66,    87,
     121,     0,    61,    62,    60,    64,    65,    55,    81,    56,
      82,    57,    83,    58,    84,    59,    85,     0,    86,    75,
      69,    76,    70,    77,    71,    78,    72,    79,    73,    80,
      74,   117,   116,   123,   122,   127,   126,   125,   124,     0,
      40,     0,    38,     0,    39,     0,    55,    56,    57,    58,
      59,    37,    32,    36,    34,    35,    33,    21,    29,    27,
      28,    26,     0,   107,   110,     0,   102,     0,   113,     0,
      98,     0,     0,    50,    48,    44,    46,    42,     0,   109,
       0,     0,     0,     0,     0,   141,    95,     0,     0,     0,
       0,   146,   147,   148,     0,   149,     0,     0,   140,     0,
       0,     0,     0,   142,     0,   134,     0,     0,    96,     0,
       0,     0,     0,   100,     0,     0,     0,   111,     0,   143,
       0,   144,     0,     0,     0,     0,   105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,   189,    41,    42,    15,   183,    35,    16,
     255,   251,   253,   249,   211,    75,    98,    99,   100,    78,
      17,    18,   131,    60,    19,   200,    44,   196,    20,   123,
     275,   297,   125,    21,   202,    22,   142,    80,    81,    23,
      24,   137,   294,   295,   320,   329,   307,   304,    82,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -123
static const yytype_int16 yypact[] =
{
     584,    26,    27,    43,    45,    55,   208,   404,   -31,    17,
      18,  -123,    14,   572,  -123,  -123,  -123,  -123,    13,  -123,
    -123,  -123,    28,  -123,    29,   469,   257,   431,    74,    60,
      46,    83,    90,    91,    95,    69,    70,   109,   132,   135,
     139,    85,    69,  -123,   541,  -123,   140,   105,   541,   106,
    -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,  -123,   -25,
    -123,    69,   486,   423,   536,   108,  -123,   685,   123,   770,
    -123,  -123,   137,   541,   505,   125,   694,   602,  -123,     7,
    -123,   776,  -123,   128,  -123,  -123,  -123,  -123,  -123,  -123,
     541,    21,   133,  -123,  -123,  -123,  -123,   204,   694,   602,
     134,   142,  -123,  -123,   143,   145,   137,   650,  -123,    19,
     180,   196,   209,  -123,   164,  -123,   541,   204,     5,   137,
      69,   164,    31,   171,   225,   167,  -123,    31,  -123,   -31,
     584,    13,   460,  -123,  -123,  -123,  -123,   191,  -123,  -123,
     610,   458,    81,  -123,   137,   137,   137,   137,   137,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   541,   541,   120,   120,   120,   120,   120,   120,  -123,
      69,  -123,    69,  -123,    69,  -123,   634,   137,   137,   137,
     137,   137,    69,    69,   199,   201,   203,   212,  -123,    69,
      37,   220,   222,   672,   164,  -123,   193,    69,   137,  -123,
      69,   223,    69,   541,    20,  -123,    34,   227,  -123,  -123,
    -123,    69,   743,   757,   618,   587,   587,   624,   640,   624,
     640,   239,   246,   239,   246,   239,   246,   694,   246,   711,
     640,   711,   640,   580,   246,   580,   246,   580,   246,   580,
     246,   264,  -123,  -123,  -123,  -123,  -123,  -123,  -123,    69,
     164,    69,   164,    69,   164,    69,   104,   104,  -123,  -123,
    -123,   164,   164,  -123,  -123,  -123,  -123,   164,  -123,  -123,
    -123,  -123,   584,   164,   728,   541,   164,    69,   164,    31,
    -123,   240,   241,   164,   164,   164,   164,   164,    80,     7,
     460,   236,   242,   173,   245,   241,  -123,   244,   103,   584,
     541,  -123,  -123,  -123,   243,  -123,   247,   248,  -123,   252,
     256,   334,    84,  -123,   584,  -123,    69,    69,  -123,   259,
     584,   391,   460,   164,    69,   526,   413,   164,   262,  -123,
     280,  -123,   140,   281,   284,    69,   164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -116,   -13,  -123,  -123,  -123,   -10,  -123,  -123,    -7,
    -123,  -123,  -123,  -123,  -123,  -123,    76,     9,   178,   -20,
      -4,  -123,  -123,   206,    -1,  -123,    -3,  -122,    35,  -123,
    -123,  -123,     0,    38,  -123,  -123,   -24,  -123,   437,    41,
    -123,  -123,    39,  -123,  -123,  -123,  -123,  -123,  -105,   207
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -146
static const yytype_int16 yytable[] =
{
      51,    79,    91,    52,   184,   201,    53,    48,   104,    54,
     102,   129,    55,   103,   204,    49,   206,    43,    45,    47,
     122,     1,   161,   162,   127,   130,     2,     3,     4,     5,
       6,     7,    70,    71,    77,     1,   161,   162,    25,    26,
       2,     3,     4,     5,     6,     7,   161,   162,    56,   139,
      59,    57,   161,   162,    58,    27,     8,    28,     9,    10,
      11,   105,    12,    93,  -114,    46,    43,    29,   170,    96,
       8,   280,     9,    10,    11,   101,    12,    62,    61,   102,
     195,     1,   103,   141,   268,   281,     2,     3,     4,     5,
       6,     7,   190,   108,    72,   109,   161,   162,   192,   161,
     162,    76,   110,   111,     1,   107,   141,   112,   106,     2,
       3,     4,     5,     6,     7,   113,     8,   115,     9,    10,
      11,   116,    12,    84,    85,    86,   203,    87,    88,    89,
     210,   296,   120,   319,   179,   180,   181,   241,   242,     8,
      93,     9,    10,    11,   117,    12,    96,   118,   138,   124,
     140,   119,   126,   128,   310,   -92,   288,   291,   218,   220,
     222,   224,   226,   228,   230,   232,   234,   236,   238,   240,
     -93,    72,   143,   140,   298,   169,   301,   302,   303,   279,
     171,   172,   176,   311,   185,   106,    70,    71,   305,   173,
     174,    51,   175,    51,    52,   193,    52,    53,   321,    53,
      54,   186,    54,    55,   325,    55,   326,    93,    94,    30,
     188,    95,   187,    96,    31,    32,    33,    34,   197,   199,
     212,   213,   214,   215,   216,   217,   219,   221,   223,   225,
     227,   229,   231,   233,   235,   237,   239,   198,    72,    56,
     207,    56,    57,   272,    57,    58,   263,    58,   264,   121,
     265,   289,    97,   256,   257,   258,   259,   260,    83,   266,
      84,    85,    86,    66,    87,    88,    89,   269,   132,   270,
      70,    71,   154,   277,   274,    51,   312,   282,    52,   160,
     162,    53,   293,   292,    54,    51,   299,    55,    52,   306,
     300,    53,    73,   309,    54,   191,   313,    55,    51,   315,
     314,    52,   316,   317,    53,    90,   324,    54,    51,   331,
      55,    52,    51,    51,    53,    52,    52,    54,    53,    53,
      55,    54,    54,    56,    55,    55,    57,   194,   332,    58,
     334,   335,   333,    56,   308,     1,    57,   205,     0,    58,
       2,     3,     4,     5,     6,     7,    56,     0,     0,    57,
       0,     0,    58,     0,     0,     0,    56,     0,     0,    57,
      56,    56,    58,    57,    57,     0,    58,    58,     0,     0,
       8,     0,     9,    10,    11,     0,    12,   250,     0,   252,
       0,   254,     0,     0,     0,   318,     0,     0,     0,   261,
     262,     0,     1,     0,     0,     0,   267,     2,     3,     4,
       5,     6,     7,     0,   273,    36,     0,   276,     0,   278,
      37,    38,    39,    40,     1,     0,     0,     0,   283,     2,
       3,     4,     5,     6,     7,     0,     0,     8,     0,     9,
      10,    11,    92,    12,    93,    94,     0,     0,    95,     0,
      96,     0,  -145,  -128,  -128,  -128,  -128,  -128,  -128,     8,
       0,     9,    10,    11,     0,    12,   284,     0,   285,     0,
     286,     1,   287,     0,   330,    72,     2,     3,     4,     5,
       6,     7,    63,    64,    65,    66,    67,    68,    69,    97,
       0,     0,    70,    71,   290,     0,   155,   156,   157,   158,
     159,   160,   133,   134,   135,   136,     8,     0,     9,    10,
      11,     0,    12,    72,    73,     0,   188,   209,    63,    64,
      86,    66,    67,    88,    69,     0,     0,    74,    70,    71,
       0,     0,     0,   322,   323,     0,     0,     1,     0,     0,
       0,   327,     2,     3,     4,     5,     6,     7,     0,    72,
      73,     0,   336,     0,    84,    85,    86,    66,    87,    88,
      89,     0,     0,    74,    70,    71,  -130,  -130,  -130,  -130,
    -130,  -130,     8,     0,     9,    10,    11,     0,    12,     0,
       0,   328,    50,     1,     0,     0,    73,     0,     2,     3,
       4,     5,     6,     7,     0,     1,     0,     0,     0,    90,
       2,     3,     4,     5,     6,     7,     0,   144,   145,   146,
     243,   244,   245,   246,   247,   248,   147,   148,     8,     0,
       9,    10,    11,   154,    12,   177,   178,   179,   180,   181,
       8,     0,     9,    10,    11,     0,    12,   144,   145,   146,
     155,   156,   157,   158,   159,   160,   147,   148,   149,   150,
     151,   152,   153,   154,   147,   148,   177,   178,   179,   180,
     181,   144,   145,   146,   151,   152,   153,   154,     0,   208,
     147,   148,   177,   178,   179,   180,   181,   144,   145,   146,
     157,   158,   159,   160,     0,     0,   147,   148,   177,   178,
     179,   180,   181,   208,     0,     0,     0,     0,     0,   144,
     145,   146,     0,     0,     0,     0,     0,   182,   147,   148,
     177,   178,   179,   180,   181,  -131,  -131,  -131,  -131,  -131,
    -131,   144,   145,   146,     0,     0,     0,     0,     0,   271,
     147,   148,   149,   150,   151,   152,   153,   154,   144,   145,
     146,     0,     0,     0,     0,     0,     0,   147,   148,     0,
       0,   151,   152,   153,   154,   144,   145,   146,     0,     0,
       0,     0,     0,     0,   147,   148,   177,   178,   179,   180,
     181,   145,   146,     0,     0,     0,     0,     0,     0,   147,
     148,   177,   178,   179,   180,   181,   146,     0,     0,     0,
       0,     0,     0,   147,   148,   177,   178,   179,   180,   181,
    -129,  -129,  -129,  -129,  -129,  -129,   163,   164,   165,   166,
     167,   168
};

static const yytype_int16 yycheck[] =
{
      13,    25,    26,    13,   109,   127,    13,    10,    28,    13,
       5,    36,    13,     8,   130,     1,   132,    48,     1,     1,
      44,     1,    15,    16,    48,    50,     6,     7,     8,     9,
      10,    11,    13,    14,    25,     1,    15,    16,    12,    12,
       6,     7,     8,     9,    10,    11,    15,    16,    13,    73,
      37,    13,    15,    16,    13,    12,    36,    12,    38,    39,
      40,     1,    42,     3,    50,    48,    48,    12,    47,     9,
      36,    51,    38,    39,    40,     1,    42,    48,    50,     5,
      49,     1,     8,    74,    47,    51,     6,     7,     8,     9,
      10,    11,   116,    47,    34,    12,    15,    16,   118,    15,
      16,    25,    12,    12,     1,    29,    97,    12,    48,     6,
       7,     8,     9,    10,    11,    46,    36,    47,    38,    39,
      40,    12,    42,     3,     4,     5,   129,     7,     8,     9,
      49,    51,    47,    49,    30,    31,    32,   161,   162,    36,
       3,    38,    39,    40,    12,    42,     9,    12,    72,     9,
      74,    12,    47,    47,    51,    47,   272,   279,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
      47,    34,    47,    97,   290,    47,     3,     4,     5,   203,
      47,    47,   106,   299,     4,    48,    13,    14,   293,    47,
      47,   204,    47,   206,   204,   119,   206,   204,   314,   206,
     204,     5,   206,   204,   320,   206,   322,     3,     4,     1,
      46,     7,     3,     9,     6,     7,     8,     9,    47,    52,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,    12,    34,   204,
      49,   206,   204,    50,   206,   204,    47,   206,    47,    42,
      47,   275,    48,   177,   178,   179,   180,   181,     1,    47,
       3,     4,     5,     6,     7,     8,     9,    47,    61,    47,
      13,    14,    33,    50,   198,   288,   300,    50,   288,    33,
      16,   288,    41,    43,   288,   298,    50,   288,   298,    44,
      48,   298,    35,    49,   298,   117,    53,   298,   311,    51,
      53,   311,    50,    47,   311,    48,    47,   311,   321,    47,
     311,   321,   325,   326,   321,   325,   326,   321,   325,   326,
     321,   325,   326,   288,   325,   326,   288,   120,    48,   288,
      49,    47,   332,   298,   295,     1,   298,   131,    -1,   298,
       6,     7,     8,     9,    10,    11,   311,    -1,    -1,   311,
      -1,    -1,   311,    -1,    -1,    -1,   321,    -1,    -1,   321,
     325,   326,   321,   325,   326,    -1,   325,   326,    -1,    -1,
      36,    -1,    38,    39,    40,    -1,    42,   170,    -1,   172,
      -1,   174,    -1,    -1,    -1,    51,    -1,    -1,    -1,   182,
     183,    -1,     1,    -1,    -1,    -1,   189,     6,     7,     8,
       9,    10,    11,    -1,   197,     1,    -1,   200,    -1,   202,
       6,     7,     8,     9,     1,    -1,    -1,    -1,   211,     6,
       7,     8,     9,    10,    11,    -1,    -1,    36,    -1,    38,
      39,    40,     1,    42,     3,     4,    -1,    -1,     7,    -1,
       9,    -1,    51,    20,    21,    22,    23,    24,    25,    36,
      -1,    38,    39,    40,    -1,    42,   249,    -1,   251,    -1,
     253,     1,   255,    -1,    51,    34,     6,     7,     8,     9,
      10,    11,     3,     4,     5,     6,     7,     8,     9,    48,
      -1,    -1,    13,    14,   277,    -1,    28,    29,    30,    31,
      32,    33,     6,     7,     8,     9,    36,    -1,    38,    39,
      40,    -1,    42,    34,    35,    -1,    46,    49,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    48,    13,    14,
      -1,    -1,    -1,   316,   317,    -1,    -1,     1,    -1,    -1,
      -1,   324,     6,     7,     8,     9,    10,    11,    -1,    34,
      35,    -1,   335,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    48,    13,    14,    20,    21,    22,    23,
      24,    25,    36,    -1,    38,    39,    40,    -1,    42,    -1,
      -1,    45,     0,     1,    -1,    -1,    35,    -1,     6,     7,
       8,     9,    10,    11,    -1,     1,    -1,    -1,    -1,    48,
       6,     7,     8,     9,    10,    11,    -1,    17,    18,    19,
     163,   164,   165,   166,   167,   168,    26,    27,    36,    -1,
      38,    39,    40,    33,    42,    28,    29,    30,    31,    32,
      36,    -1,    38,    39,    40,    -1,    42,    17,    18,    19,
      28,    29,    30,    31,    32,    33,    26,    27,    28,    29,
      30,    31,    32,    33,    26,    27,    28,    29,    30,    31,
      32,    17,    18,    19,    30,    31,    32,    33,    -1,    49,
      26,    27,    28,    29,    30,    31,    32,    17,    18,    19,
      30,    31,    32,    33,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    49,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    -1,    -1,    -1,    -1,    47,    26,    27,
      28,    29,    30,    31,    32,    20,    21,    22,    23,    24,
      25,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    47,
      26,    27,    28,    29,    30,    31,    32,    33,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,    30,    31,    32,    33,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      20,    21,    22,    23,    24,    25,    20,    21,    22,    23,
      24,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,     7,     8,     9,    10,    11,    36,    38,
      39,    40,    42,    55,    56,    60,    63,    74,    75,    78,
      82,    87,    89,    93,    94,    12,    12,    12,    12,    12,
       1,     6,     7,     8,     9,    62,     1,     6,     7,     8,
       9,    58,    59,    48,    80,     1,    48,     1,    80,     1,
       0,    56,    60,    63,    74,    78,    82,    87,    93,    37,
      77,    50,    48,     3,     4,     5,     6,     7,     8,     9,
      13,    14,    34,    35,    48,    69,    70,    71,    73,    90,
      91,    92,   102,     1,     3,     4,     5,     7,     8,     9,
      48,    90,     1,     3,     4,     7,     9,    48,    70,    71,
      72,     1,     5,     8,    73,     1,    48,    70,    47,    12,
      12,    12,    12,    46,   103,    47,    12,    12,    12,    12,
      47,   103,    90,    83,     9,    86,    47,    90,    47,    36,
      50,    76,   103,     6,     7,     8,     9,    95,    70,    90,
      70,    71,    90,    47,    17,    18,    19,    26,    27,    28,
      29,    30,    31,    32,    33,    28,    29,    30,    31,    32,
      33,    15,    16,    20,    21,    22,    23,    24,    25,    47,
      47,    47,    47,    47,    47,    47,    70,    28,    29,    30,
      31,    32,    47,    61,   102,     4,     5,     3,    46,    57,
      90,    72,    73,    70,   103,    49,    81,    47,    12,    52,
      79,    81,    88,    80,    55,    77,    55,    49,    49,    49,
      49,    68,    70,    70,    70,    70,    70,    70,    71,    70,
      71,    70,    71,    70,    71,    70,    71,    70,    71,    70,
      71,    70,    71,    70,    71,    70,    71,    70,    71,    70,
      71,    90,    90,    92,    92,    92,    92,    92,    92,    67,
     103,    65,   103,    66,   103,    64,    70,    70,    70,    70,
      70,   103,   103,    47,    47,    47,    47,   103,    47,    47,
      47,    47,    50,   103,    70,    84,   103,    50,   103,    90,
      51,    51,    50,   103,   103,   103,   103,   103,    55,    90,
     103,    81,    43,    41,    96,    97,    51,    85,    55,    50,
      48,     3,     4,     5,   101,   102,    44,   100,    96,    49,
      51,    55,    90,    53,    53,    51,    50,    47,    51,    49,
      98,    55,   103,   103,    47,    55,    55,   103,    45,    99,
      51,    47,    48,    86,    49,    47,   103
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
    {cout<<"At Line: "<<line_num<<" Not a valid var statement to declare !"<<endl;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 119 "voo.y"
    { 
				if( mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (1)].idval)))){  //check if this var hasn't been declared before , not to declare 2 var with the same name 
					newSymbolRecord((yyvsp[(1) - (1)].idval),integer,true,false);
					//mainScope.printAll();
					cout<< "decl for int id (var) -> INT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 127 "voo.y"
    {
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (1)].idval)))){
					newSymbolRecord((yyvsp[(1) - (1)].idval),floatt,true,false);
					//mainScope.printAll();
					cout<< "decl for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 135 "voo.y"
    { 
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (1)].idval)))){
					newSymbolRecord((yyvsp[(1) - (1)].idval),str,true,false);
					//mainScope.printAll();
					cout<< "decl for string id (var) -> STR_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 143 "voo.y"
    { 
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (1)].idval)))){
					newSymbolRecord((yyvsp[(1) - (1)].idval),boolean,true,false);
					//mainScope.printAll();
					cout<< "decl for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (1)].idval)<<endl;
				}
				else errorExistsBefore((yyvsp[(1) - (1)].idval));
			;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 155 "voo.y"
    { 
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){ //check if this var hasn't been declared before , not to declare 2 var with the same name 
					if((yyvsp[(3) - (4)].nodeval)!=NULL){ //check if the variables used in the expression are valid and exist  
						if(unInit.empty()){
							newSymbolRecord((yyvsp[(1) - (4)].idval),integer,true,true);
							generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							//mainScope.printAll();
							cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
						}
						else errorUnInitVar();
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));	
			;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 169 "voo.y"
    {
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,true,true);
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						//mainScope.printAll();
						cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 180 "voo.y"
    { 
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),str,true,true);
						//mainScope.printAll();
						cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 190 "voo.y"
    { 
				if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){
					if((yyvsp[(3) - (4)].nodeval)!=NULL){
						newSymbolRecord((yyvsp[(1) - (4)].idval),boolean,true,true);
						generateQuad("STO",(yyvsp[(3) - (4)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
						//mainScope.printAll();
						cout<< "ass for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (4)].idval)<<endl;
					}
				}
				else errorExistsBefore((yyvsp[(1) - (4)].idval));
			;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 209 "voo.y"
    {cout<<"At Line: "<<line_num<<"Not a valid const statement to declare !"<<endl;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 212 "voo.y"
    { 
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){  //check if this var hasn't been declared before , not to declare 2 var with the same name 
							NodeWithType* nt=createNewValueNode(NewNodeInt((yyvsp[(3) - (4)].ival)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),integer,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							//mainScope.printAll();
							cout<< "ass for int id (const) -> INT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].ival)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));	
					;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 222 "voo.y"
    { 
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){	
							NodeWithType* nt=createNewValueNode(NewNodeFloat((yyvsp[(3) - (4)].fval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),floatt,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							//mainScope.printAll();
							cout<< "ass for float id (const) -> FLOAT_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].fval)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));	
					;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 232 "voo.y"
    {
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){	
							NodeWithType* nt=createNewValueNode(NewNodeString((yyvsp[(3) - (4)].sval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),str,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							//mainScope.printAll();
							cout<< "ass for str id (const) -> STR_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].sval)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));
					;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 242 "voo.y"
    {
						if(mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (4)].idval)))){	
							NodeWithType* nt=createNewValueNode(NewNodeBool((yyvsp[(3) - (4)].nodeval)));
							newSymbolRecord((yyvsp[(1) - (4)].idval),boolean,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode((yyvsp[(1) - (4)].idval)));
							//mainScope.printAll();
							cout<< "ass for bool id (const) -> BOOL_ID: " <<(yyvsp[(1) - (4)].idval)<<" with value "<<(yyvsp[(3) - (4)].nodeval)<<endl;
						}
						else errorExistsBefore((yyvsp[(1) - (4)].idval));
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 255 "voo.y"
    { 
				if(!mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (5)].idval)))){  //check if the var has been declared before, to use it 
					if((yyvsp[(3) - (5)].nodeval)!=NULL){ 				//check if the variables used in the expression are valid and exist
						if(unInit.empty()){
							updateSymbolRecordInit((yyvsp[(1) - (5)].idval));
							generateQuad("STO",(yyvsp[(3) - (5)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (5)].idval)));
							cout<< "ass for int id (var) -> INT_ID: " <<(yyvsp[(1) - (5)].idval)<<" with value "<<(yyvsp[(3) - (5)].nodeval)<<endl;
						}
						else errorUnInitVar();
					}
				}
				else errorDoesntExist((yyvsp[(1) - (5)].idval));
			;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 268 "voo.y"
    { 
				if(!mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (5)].idval)))){
					if((yyvsp[(3) - (5)].nodeval)!=NULL){
						if(unInit.empty()){
							updateSymbolRecordInit((yyvsp[(1) - (5)].idval));
							generateQuad("STO",(yyvsp[(3) - (5)].nodeval),NULL,createNewIdNode((yyvsp[(1) - (5)].idval)));
							cout<< "ass for float id (var) -> FLOAT_ID: " <<(yyvsp[(1) - (5)].idval)<<" with value "<<(yyvsp[(3) - (5)].nodeval)<<endl;
						}
						else errorUnInitVar();
					}
				}
				else errorDoesntExist((yyvsp[(1) - (5)].idval));		
			;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 281 "voo.y"
    { 
				if(!mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (5)].idval)))){
					if((yyvsp[(3) - (5)].nodeval)!=NULL){
						if(unInit.empty()){
							updateSymbolRecordInit((yyvsp[(1) - (5)].idval));
							cout<< "ass for string id (var) -> STR_ID: " <<(yyvsp[(1) - (5)].idval)<<" with value "<<(yyvsp[(3) - (5)].nodeval)<<endl;
						}
						else errorUnInitVar();
					}
				}
				else errorDoesntExist((yyvsp[(1) - (5)].idval));		
			;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 293 "voo.y"
    { 
				if(!mainScope.checkIteratorAtEnd(mainScope.lookup((yyvsp[(1) - (5)].idval)))){
					if((yyvsp[(3) - (5)].nodeval)!=NULL){
						if(unInit.empty()){
							updateSymbolRecordInit((yyvsp[(1) - (5)].idval));
							generateQuad("STO",boolRes.top(),NULL,createNewIdNode((yyvsp[(1) - (5)].idval)));
							boolRes.pop();
							cout<< "ass for bool id (var) -> BOOL_ID: " <<(yyvsp[(1) - (5)].idval)<<" with value "<<(yyvsp[(3) - (5)].nodeval)<<endl;
						}
						else errorUnInitVar();
					}
				}
				else errorDoesntExist((yyvsp[(1) - (5)].idval));		
			;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 308 "voo.y"
    {cout<<"At Line: "<<line_num<<"Not a valid int expression to use !" <<endl;;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 309 "voo.y"
    {cout<<"At Line: "<<line_num<<"Not a valid float expression to use !" <<endl;;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 310 "voo.y"
    {cout<<"At Line: "<<line_num<<"Not a valid string expression to use !" <<endl;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 311 "voo.y"
    {cout<<"At Line: "<<line_num<<"Not a valid bool expression to use !"<<endl;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 312 "voo.y"
    {cout<<"At Line: "<<line_num<<"Not a valid identifier to use !" <<endl;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 319 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS "  <<endl;} ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 320 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS" <<endl; };}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 321 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL" <<endl; } ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 322 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV " <<endl; };}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 323 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD " <<endl; };}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 325 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_AND " <<endl;} ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 326 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_or,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_OR " <<endl; };}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 327 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_xor,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("XOR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_XOR " <<endl; };}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 328 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_not,1,(yyvsp[(2) - (2)].nodeval),NULL); if((yyval.nodeval)!=NULL){generateQuad("NOT",(yyvsp[(2) - (2)].nodeval),NULL,(yyval.nodeval)); cout << "BITWISE_NOT: " <<endl; };}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 329 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_r,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_LEFT: " <<endl; };}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 330 "voo.y"
    { (yyval.nodeval)=createNewExprNode(b_shft_l,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SHFTR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "BITWISE_SHIFT_RIGHT: " <<endl; };}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 332 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);	cout << "Brackets  " <<endl; ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 333 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 334 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
			} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 345 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 346 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 347 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl; } ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 348 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; };}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 349 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; };}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 350 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; };}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 352 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 353 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 354 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl; } ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 355 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; };}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 356 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; };}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 357 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; };}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 359 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pls,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("ADD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "PLUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 360 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mins,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SUB",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MINUS: " << (yyval.nodeval) <<endl; };}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 361 "voo.y"
    { (yyval.nodeval)=createNewExprNode(mul,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("MUL",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "MUL: " << (yyval.nodeval) << endl;  };}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 362 "voo.y"
    { (yyval.nodeval)=createNewExprNode(dv,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("DIV",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "DIV: " << (yyval.nodeval) <<endl; };}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 363 "voo.y"
    { (yyval.nodeval)=createNewExprNode(md,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("MOD",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "MOD: " << (yyval.nodeval) << endl; };}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 364 "voo.y"
    { (yyval.nodeval)=createNewExprNode(pw,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));  if((yyval.nodeval)!=NULL){generateQuad("POW",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));cout << "POW: " << (yyval.nodeval) << endl; };}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 366 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval); cout << "Brackets  " <<endl; ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 367 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval)));  ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 368 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval));
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
			} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 382 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));  ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 383 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval));
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
			} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 394 "voo.y"
    {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
	;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 400 "voo.y"
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

  case 96:

/* Line 1455 of yacc.c  */
#line 413 "voo.y"
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

  case 97:

/* Line 1455 of yacc.c  */
#line 424 "voo.y"
    { cout << "else if  " <<endl; ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 425 "voo.y"
    { cout << "else " <<endl; ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 426 "voo.y"
    { cout << "epsilon " <<endl; ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 430 "voo.y"
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

  case 101:

/* Line 1455 of yacc.c  */
#line 441 "voo.y"
    { cout<<"At Line: "<<line_num<<" Not a valid while statement !"<<endl;;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 445 "voo.y"
    {generateLabelPair();;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 448 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 451 "voo.y"
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

  case 106:

/* Line 1455 of yacc.c  */
#line 460 "voo.y"
    { cout<<"At Line: "<<line_num<<" Not a valid for statement !"<<endl;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 465 "voo.y"
    {generateLabelPair();;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 469 "voo.y"
    { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 472 "voo.y"
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

  case 111:

/* Line 1455 of yacc.c  */
#line 486 "voo.y"
    {
		if(!boolRes.empty()){
			generateBranchQuad("JTRUE",brLabels.top(),boolRes.top()); 
			boolRes.pop();
		}
		brLabels.pop();
	;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 494 "voo.y"
    { cout<<"At Line: "<<line_num<<" Not a valid repeat until statement !"<<endl;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 499 "voo.y"
    {int label=generateOneLabel(); outLabel(label); brLabels.push(label);;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 502 "voo.y"
    { cout << "LOGIC_NOT " <<endl; ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 503 "voo.y"
    { 
						(yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));
						if((yyval.nodeval)!=NULL){
							generateQuad("AND",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
							boolRes.push((yyval.nodeval)); 						
							cout << "LOGIC_AND " <<endl;
						}
					;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 511 "voo.y"
    { 
					(yyval.nodeval)=createNewExprNode(l_and,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval));
						if((yyval.nodeval)!=NULL){
							generateQuad("OR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval));
							boolRes.push((yyval.nodeval)); 						
							cout << "LOGIC_OR " <<endl;
						}
					;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 519 "voo.y"
    { cout << "boolean " <<endl; ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 520 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 529 "voo.y"
    { (yyval.nodeval)=(yyvsp[(1) - (1)].nodeval);   if((yyval.nodeval)!=NULL) boolRes.push((yyval.nodeval)); 	;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 530 "voo.y"
    { (yyval.nodeval)=(yyvsp[(2) - (3)].nodeval);  cout << "Brackets " <<endl; ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 536 "voo.y"
    { (yyval.nodeval)=createNewExprNode(eq,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "EQ " <<endl; };}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 537 "voo.y"
    { (yyval.nodeval)=createNewExprNode(ne,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("NOT_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "NOT_EQ " <<endl; };}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 538 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gt,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR " <<endl; };}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 539 "voo.y"
    { (yyval.nodeval)=createNewExprNode(gte,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("GR_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "GR_EQ " <<endl; };}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 540 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sm,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM " <<endl; };}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 541 "voo.y"
    { (yyval.nodeval)=createNewExprNode(sme,2,(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval)); if((yyval.nodeval)!=NULL){generateQuad("SM_EQ",(yyvsp[(1) - (3)].nodeval),(yyvsp[(3) - (3)].nodeval),(yyval.nodeval)); cout << "SM_EQ " <<endl; };}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 545 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival)));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 546 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 554 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 555 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 563 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval)));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 564 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));}  ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 576 "voo.y"
    {
		outLabel(switchLabels.top());
		switchLabels.pop();
		if(!switchIds.empty()) switchIds.pop();
	;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 583 "voo.y"
    {
		int label = generateOneLabel();
		switchLabels.push(label);
		cout<<"ok start switch";
	;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 590 "voo.y"
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
#line 598 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 606 "voo.y"
    { 
		map<char*,SymRec>::iterator it=mainScope.lookup((yyvsp[(1) - (1)].idval));
		if(!mainScope.checkIteratorAtEnd(it)){
			(yyval.nodeval)=createNewIdNode((yyvsp[(1) - (1)].idval)); 
			if(!mainScope.checkIteratorInit(it)) unInit.push((yyvsp[(1) - (1)].idval));
			updateSymbolRecordUsed((yyvsp[(1) - (1)].idval));
		} 
		else {(yyval.nodeval)=NULL; errorDoesntExist((yyvsp[(1) - (1)].idval));} ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 615 "voo.y"
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
#line 631 "voo.y"
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

  case 144:

/* Line 1455 of yacc.c  */
#line 646 "voo.y"
    {
		generateBranchQuad("JMP",switchLabels.top(),NULL);
		outLabel(brLabels.top());
		brLabels.pop();
	;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 653 "voo.y"
    {cout<<"ok def switch";;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 656 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeInt((yyvsp[(1) - (1)].ival))); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 657 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeFloat((yyvsp[(1) - (1)].fval))); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 658 "voo.y"
    {(yyval.nodeval)=createNewValueNode(NewNodeString((yyvsp[(1) - (1)].sval))); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 664 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); /*cout<<"bool value"<<endl;*/ ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 665 "voo.y"
    { (yyval.nodeval)=createNewValueNode(NewNodeBool((yyvsp[(1) - (1)].bval))); /*cout<<"bool value"<<endl;*/ ;}
    break;



/* Line 1455 of yacc.c  */
#line 2907 "voo.tab.c"
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
#line 671 "voo.y"


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
	cout<<"There exists a variable with the same name! '"<< name <<"'"<<endl;
}

void errorDoesntExist(char * name){
	cout<<"This variable has not been declared ! '"<< name <<"'"<<endl;
}

void errorUnInitVar(){
	while(!unInit.empty()){
		cout<<"This variable is used before it's initialized '"<< unInit.front() <<"'"<<endl;
		unInit.pop();
	}
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
