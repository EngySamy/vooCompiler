%{
#include <cstdio>
#include <iostream>
using namespace std;

// stuff from flex that bison needs to know about:
extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
 
void yyerror(const char *s);
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":
%union {
	int ival;
	float fval;
	char *sval;
	char *idval;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <idval> ID
%token TYPE_FLOAT TYPE_INT TYPE_STRING TYPE_BOOL SEMI_COLON COLON COMMA CONST EQUAL TRUE FALSE

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
%%
// this is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:

stmt:
	variable stmt | constant stmt | assignment stmt | if_else_if_else_stmt stmt | for_loop stmt | while_loop stmt | repeat_until_loop stmt | switch_case stmt |
	variable | constant | assignment | if_else_if_else_stmt | for_loop | while_loop | repeat_until_loop | switch_case ;
variable: 
	type ID SEMI_COLON 
	;
	
constant:
	CONST type ID EQUAL value SEMI_COLON;
	
assignment:
	ID EQUAL right_hand_side SEMI_COLON; 
	
right_hand_side:
	math_expr | boolean | STRING ; //ID and INT and FLOAT are included in math_expr

//////TODO : modify this math_expr & int_expr	
math_expr:
	math_expr PLUS math_expr { cout << "PLUS: " <<endl; } | //<< $$=$1+$3 
	math_expr MINUS math_expr { cout << "MINUS: " <<endl; }| //<< $$=$1-$3
	math_expr MUL math_expr { cout << "MUL: " << endl; }| //$$=$1*$3 <<
	math_expr DIV math_expr { cout << "DIV: " <<endl; }|  //<< $$=$1/$3 
	math_expr MOD math_expr { cout << "MOD: " << endl; }|  //$$=$1%$3 <<
	math_expr POW math_expr { cout << "POW: " << endl; }|  //$$=pow($1,$3) <<
	
	OPEN_BRACKET math_expr CLOSE_BRACKET { cout << "Brackets  " <<endl; } | //<< $$=$2 
	int_expr | 
	number // << $$=$1 
	;
	
int_expr:
	
	int_expr BITWISE_AND int_expr { cout << "BITWISE_AND: " <<endl; } | //<< $$=$1&$3 
	int_expr BITWISE_OR int_expr { cout << "BITWISE_OR: " <<endl; } | // << $$=$1|$3 
	int_expr BITWISE_XOR int_expr { cout << "BITWISE_XOR: " <<endl; } | // << $$=$1^$3 
	BITWISE_NOT int_expr { cout << "BITWISE_NOT: " <<endl; } | // << $$=~$2 
	int_expr BITWISE_SHIFT_LEFT int_expr { cout << "BITWISE_SHIFT_LEFT: " <<endl; } | //<< $$=$1<<$3 
	int_expr BITWISE_SHIFT_RIGHT int_expr { cout << "BITWISE_SHIFT_RIGHT: " <<endl; } |  //<< $$=$1>>$3 
	INT 
	;
		
number:
	INT { cout << "bison found int " << $1 <<endl; }
	| FLOAT { cout << "bison found float " << $1 << endl; }
	| ID { cout << "bison found id " << $1 << endl; }
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
	ID EQUAL math_expr ;
	
repeat_until_loop:
	REPEAT OPEN_PARANTH stmt CLOSE_PARANTH UNTIL OPEN_BRACKET bool_expr CLOSE_BRACKET SEMI_COLON ;
	
switch_case:	
	SWITCH OPEN_BRACKET ID CLOSE_BRACKET OPEN_PARANTH case_stmt CLOSE_PARANTH ;
	
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
	ID | INT | FLOAT | STRING ;
	
value:
	INT | FLOAT | STRING | boolean ;
	

	
boolean:
	TRUE | FALSE;
	
type: 
	TYPE_INT { cout << "bison found a type int " << endl; }
	| TYPE_FLOAT { cout << "bison found a type float " << endl; }
	| TYPE_STRING { cout << "bison found a type str "  << endl; }
	| TYPE_BOOL { cout << "bison found a type bool "  << endl; }
	;

	
	
%%

int main(int, char**) {
	// open a file handle to a particular file:
	FILE *myfile = fopen("a.engy.file", "r");
	// make sure it is valid:
	if (!myfile) {
		cout << "I can't open a.engy.file!" << endl;
		return -1;
	}
	// set flex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// parse through the input until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	
}

void yyerror(const char *s) {
	cout << "EEK, parse error!  Message: " << s << endl;
	// might as well halt now:
	exit(-1);
}