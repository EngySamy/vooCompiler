
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 43 "voo.y"

	int ival;
	float fval;
	char * sval;
	char * idval;



/* Line 1676 of yacc.c  */
#line 112 "voo.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


