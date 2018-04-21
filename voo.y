%{
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

%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int ival;
	float fval;
	char * sval;
	char * idval;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT //
%token <fval> FLOAT
%token <sval> STRING
%token <idval> BOOL_ID FLOAT_ID STR_ID INT_ID
%token SEMI_COLON COLON COMMA CONST VAR EQUAL TRUE FALSE  //TYPE_FLOAT TYPE_INT TYPE_STRING TYPE_BOOL

%left LOGIC_OR
%left LOGIC_AND
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND

%left EQ NOT_EQ
%left GR GR_EQ SM SM_EQ 

%left BITWISE_SHIFT_RIGHT BITWISE_SHIFT_LEFT
%left PLUS MINUS
%left MUL DIV MOD 
%right POW
%right LOGIC_NOT BITWISE_NOT

%token OPEN_BRACKET CLOSE_BRACKET 
%token OPEN_PARANTH CLOSE_PARANTH
%token IF ELSE FOR WHILE SWITCH CASE REPEAT UNTIL DEFAULT

%type <idval> int_expr
//%type <fval> float_expr
//%type <sval> str_expr

%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:

stmt:
	variable stmt | constant_stmt stmt | assignment stmt | if_else_if_else_stmt stmt | for_loop stmt | while_loop stmt | repeat_until_loop stmt | switch_case stmt |
	variable | constant_stmt | assignment | if_else_if_else_stmt | for_loop | while_loop | repeat_until_loop | switch_case ;
variable: 
	VAR id SEMI_COLON ;

	
constant_stmt:
	CONST constant;
	
constant:
	INT_ID EQUAL int_value SEMI_COLON { cout << "const int id " << endl; } |
	FLOAT_ID EQUAL float_value SEMI_COLON { cout << "const float id " << endl; }|
	STR_ID EQUAL str_value SEMI_COLON { cout << "const str id " << endl; } |
	BOOL_ID EQUAL bool_value SEMI_COLON { cout << "const bool id " << endl; }
	;

	
int_value:
	INT | INT_ID  ;
float_value:
	FLOAT | FLOAT_ID ;
str_value:
	STRING | STR_ID ;
bool_value:
	boolean | BOOL_ID ;
	
assignment:
	INT_ID EQUAL int_expr SEMI_COLON {	mainScope.insert((string)$1,(void *)$3); cout<< "ass for int id -> INT_ID: " <<$1<<"with expr value "<<$3;  }  |
	FLOAT_ID EQUAL float_int_expr SEMI_COLON |
	STR_ID EQUAL str_expr SEMI_COLON |
	BOOL_ID EQUAL bool_expr SEMI_COLON 
	;



int_expr:
	int_expr PLUS int_expr { /*$$=$1+$3;*/  cout << "PLUS: " << $$ <<endl; generateQuad("Add",$1,$3);} |   //AddToTable($1,$3,"PLUS");
	int_expr MINUS int_expr { /*$$=$1-$3;*/ cout << "MINUS: " << $$ <<endl; }| 
	int_expr MUL int_expr { /*$$=$1*$3;*/ cout << "MUL: " << $$ << endl;  }| 
	int_expr DIV int_expr { /*$$=$1/$3;*/ cout << "DIV: " << $$ <<endl; }|  
	int_expr MOD int_expr { /*$$=$1%$3;*/ cout << "MOD: " << $$ << endl; }|  
	
	int_expr BITWISE_AND int_expr { cout << "BITWISE_AND: " <<endl; } | //<< $$=$1&$3 
	int_expr BITWISE_OR int_expr { cout << "BITWISE_OR: " <<endl; } | // << $$=$1|$3 
	int_expr BITWISE_XOR int_expr { cout << "BITWISE_XOR: " <<endl; } | // << $$=$1^$3 
	BITWISE_NOT int_expr { cout << "BITWISE_NOT: " <<endl; } | // << $$=~$2 
	int_expr BITWISE_SHIFT_LEFT int_expr { cout << "BITWISE_SHIFT_LEFT: " <<endl; } | //<< $$=$1<<$3 
	int_expr BITWISE_SHIFT_RIGHT int_expr { cout << "BITWISE_SHIFT_RIGHT: " <<endl; } |  //<< $$=$1>>$3 
	
	OPEN_BRACKET int_expr CLOSE_BRACKET { cout << "Brackets  " <<endl; } | //<< $$=$2
	//INT | 
	INT_ID {cout<<"int id hh"<<endl;}//{$$=(int)mainScope.lookup((string)$1);}  //$$=symbols.find($1)->second;
	;

float_expr:
	float_expr PLUS float_expr { cout << "PLUS: " <<endl; } | //<< $$=$1+$3 
	float_expr MINUS float_expr { cout << "MINUS: " <<endl; }| //<< $$=$1-$3
	float_expr MUL float_expr { cout << "MUL: " << endl; }| //$$=$1*$3 <<
	float_expr DIV float_expr { cout << "DIV: " <<endl; }|  //<< $$=$1/$3 
	float_expr MOD float_expr { cout << "MOD: " << endl; }|  //$$=$1%$3 <<
	float_expr POW float_expr { cout << "POW: " << endl; }|  //$$=pow($1,$3) <<
	
	float_expr PLUS int_expr { cout << "PLUS: " <<endl; } | //<< $$=$1+$3 
	float_expr MINUS int_expr { cout << "MINUS: " <<endl; }| //<< $$=$1-$3
	float_expr MUL int_expr { cout << "MUL: " << endl; }| //$$=$1*$3 <<
	float_expr DIV int_expr { cout << "DIV: " <<endl; }|  //<< $$=$1/$3 
	float_expr MOD int_expr { cout << "MOD: " << endl; }|  //$$=$1%$3 <<
	float_expr POW int_expr { cout << "POW: " << endl; }|  //$$=pow($1,$3) <<
	
	int_expr PLUS float_expr { cout << "PLUS: " <<endl; } | //<< $$=$1+$3 
	int_expr MINUS float_expr { cout << "MINUS: " <<endl; }| //<< $$=$1-$3
	int_expr MUL float_expr { cout << "MUL: " << endl; }| //$$=$1*$3 <<
	int_expr DIV float_expr { cout << "DIV: " <<endl; }|  //<< $$=$1/$3 
	int_expr MOD float_expr { cout << "MOD: " << endl; }|  //$$=$1%$3 <<
	int_expr POW float_expr { cout << "POW: " << endl; }|  //$$=pow($1,$3) <<
	
	OPEN_BRACKET float_expr CLOSE_BRACKET { cout << "Brackets  " <<endl; } | //<< $$=$2 
	FLOAT  //| FLOAT_ID |
	//int_expr 
	;
	
float_int_expr:
	float_expr | int_expr ;
	
str_expr:
	str_expr PLUS str_expr |
	STRING //| STR_ID
	;

if_else_if_else_stmt:
	if_stmt else_if_stmt ;

if_stmt:
	IF OPEN_BRACKET bool_expr CLOSE_BRACKET OPEN_PARANTH stmt CLOSE_PARANTH { cout << "if " <<endl; }
	;
else_if_stmt:
	ELSE if_stmt else_if_stmt { cout << "else if  " <<endl; } | //sequence of else if 
	ELSE OPEN_PARANTH stmt CLOSE_PARANTH { cout << "else " <<endl; } | //else 
	{ cout << "epsilon " <<endl; }	//epsilon 
	;
	
while_loop:
	WHILE OPEN_BRACKET bool_expr CLOSE_BRACKET OPEN_PARANTH stmt CLOSE_PARANTH ;
	
for_loop:
	FOR OPEN_BRACKET for_assignment COMMA bool_expr COMMA for_assignment CLOSE_BRACKET OPEN_PARANTH stmt CLOSE_PARANTH
	
for_assignment:
	id EQUAL int_expr ;		//To Check here .. int_expr?
	
repeat_until_loop:
	REPEAT OPEN_PARANTH stmt CLOSE_PARANTH UNTIL OPEN_BRACKET bool_expr CLOSE_BRACKET SEMI_COLON ;
	
switch_case:	
	SWITCH OPEN_BRACKET id CLOSE_BRACKET OPEN_PARANTH case_stmt CLOSE_PARANTH ;
	
case_stmt:
	CASE value COLON stmt case_stmt |
	DEFAULT COLON stmt |
	//epsilon
	;
	
bool_expr:
	compare_opd EQ compare_opd { cout << "EQ " <<endl; } | 
	compare_opd NOT_EQ compare_opd { cout << "NOT_EQ " <<endl; } | 
	compare_opd GR compare_opd { cout << "GR " <<endl; } | 
	compare_opd GR_EQ compare_opd { cout << "GR_EQ " <<endl; } | 
	compare_opd SM compare_opd { cout << "SM " <<endl; } | 
	compare_opd SM_EQ compare_opd { cout << "SM_EQ " <<endl; } |
	boolean { cout << "boolean " <<endl; } |
	LOGIC_NOT bool_expr { cout << "LOGIC_NOT " <<endl; } |
	bool_expr LOGIC_AND bool_expr { cout << "LOGIC_AND " <<endl; } | 
	bool_expr LOGIC_OR bool_expr { cout << "LOGIC_OR " <<endl; } |
	OPEN_BRACKET bool_expr CLOSE_BRACKET { cout << "Brackets " <<endl; }
	;
	
compare_opd:
	 INT | FLOAT | STRING ; //add IDs 
	
value:
	INT | FLOAT | STRING | boolean ;
	
	
boolean:
	TRUE | FALSE;
	
id:
	INT_ID { cout << " int id " << endl; }
	| FLOAT_ID  { cout << " float id " << endl; }
	| STR_ID  { cout << " str id " << endl; }
	| BOOL_ID  { cout << " bool id " << endl; }
	;
	
	
%%
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