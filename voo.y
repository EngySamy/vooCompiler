%{
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

void newSymbolRecord( char *, IdType , bool , NodeWithType * ); 
Node * NewNodeFloat(float );
Node * NewNodeInt(int);
NodeWithType * createNewValueNode(Node *);
NodeWithType * createNewIdNode(char *);
NodeWithType * createNewExprNode(oprt, int , NodeWithType *, NodeWithType *);

int cntNodes=0;

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
	struct NodeWithType * nodeval;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT //
%token <fval> FLOAT
%token <sval> STRING
%token <idval> BOOL_ID FLOAT_ID STR_ID INT_ID 
%token CONST VAR EQUAL TRUE FALSE  //TYPE_FLOAT TYPE_INT TYPE_STRING TYPE_BOOL

%left LOGIC_OR
%left LOGIC_AND
%left '|'
%left '^'
%left '&'

%left EQ NOT_EQ
%left GR GR_EQ SM SM_EQ 

%left BITWISE_SHIFT_RIGHT BITWISE_SHIFT_LEFT
%left '+' '-'
%left '*' '/' '%'
 
%right POW
%right LOGIC_NOT '~'

%token IF ELSE FOR WHILE SWITCH CASE REPEAT UNTIL DEFAULT

%type <nodeval> int_expr float_expr float_int_expr
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
	VAR id ';' ;

	
constant_stmt:
	CONST constant;
	
constant:
	INT_ID EQUAL INT ';' { cout << "const int id " << endl;
								newSymbolRecord($1,integer,false, createNewValueNode(NewNodeInt($3)) );
								mainScope.printAll();
								cout<< "ass for int id (const) -> INT_ID: " <<$1<<" with value "<<$3<<endl;}  |
	FLOAT_ID EQUAL FLOAT ';' { cout << "const float id " << endl;
								newSymbolRecord($1,floatt,false, createNewValueNode(NewNodeFloat($3)) );
								mainScope.printAll();
								cout<< "ass for int id (const) -> INT_ID: " <<$1<<" with value "<<$3<<endl;}|
	STR_ID EQUAL STRING ';' { cout << "const str id " << endl; } |
	BOOL_ID EQUAL boolean ';' { cout << "const bool id " << endl; }
	;
	
assignment:
	INT_ID EQUAL int_expr ';' { 
				newSymbolRecord($1,integer,true,$3);
				//generateQuad("Sto",$3,NULL,$1);
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<$1<<" with value "<<$3<<endl;} |
	FLOAT_ID EQUAL float_int_expr ';' { 
				newSymbolRecord($1,floatt,true,$3);
				//generateQuad("Sto",$3,NULL,$1);
				mainScope.printAll();
				cout<< "ass for float id (var) -> INT_ID: " <<$1<<" with value "<<$3<<endl;}|
	STR_ID EQUAL str_expr ';' |
	BOOL_ID EQUAL bool_expr ';' 
	;



int_expr:
	int_expr '+' int_expr { $$=createNewExprNode(pls,2,$1,$3); generateQuad("ADD",$1,$3,$$); cout << "PLUS: " << $$ <<endl; } | 
	int_expr '-' int_expr { $$=createNewExprNode(mins,2,$1,$3); generateQuad("SUB",$1,$3,$$); cout << "MINUS: " << $$ <<endl; }| 
	int_expr '*' int_expr { $$=createNewExprNode(mul,2,$1,$3); generateQuad("MUL",$1,$3,$$); cout << "MUL: " << $$ << endl;  }| 
	int_expr '/' int_expr { $$=createNewExprNode(dv,2,$1,$3); generateQuad("DIV",$1,$3,$$); cout << "DIV: " << $$ <<endl; }|  
	int_expr '%' int_expr { $$=createNewExprNode(md,2,$1,$3);  generateQuad("MOD",$1,$3,$$);cout << "MOD: " << $$ << endl; }|  
	
	int_expr '&' int_expr { $$=createNewExprNode(b_and,2,$1,$3); generateQuad("AND",$1,$3,$$); cout << "BITWISE_AND: " <<endl; } | //<< $$=$1&$3 
	int_expr '|' int_expr { $$=createNewExprNode(b_or,2,$1,$3); generateQuad("OR",$1,$3,$$); cout << "BITWISE_OR: " <<endl; } | // << $$=$1|$3 
	int_expr '^' int_expr { $$=createNewExprNode(b_xor,2,$1,$3); generateQuad("XOR",$1,$3,$$); cout << "BITWISE_XOR: " <<endl; } | // << $$=$1^$3 
	'~' int_expr { $$=createNewExprNode(b_not,1,$2,NULL); generateQuad("NOT",$2,NULL,$$); cout << "BITWISE_NOT: " <<endl; } | // << $$=~$2 
	int_expr BITWISE_SHIFT_LEFT int_expr { $$=createNewExprNode(b_shft_r,2,$1,$3); generateQuad("SHFTL",$1,$3,$$); cout << "BITWISE_SHIFT_LEFT: " <<endl; } | //<< $$=$1<<$3 
	int_expr BITWISE_SHIFT_RIGHT int_expr { $$=createNewExprNode(b_shft_l,2,$1,$3); generateQuad("SHFTR",$1,$3,$$); cout << "BITWISE_SHIFT_RIGHT: " <<endl; } |  //<< $$=$1>>$3 
	
	//'(' int_expr ')' { cout << "Brackets  " <<endl; } | //<< $$=$2
	INT { $$=createNewValueNode(NewNodeInt($1)); cout<<"int value"<<endl; } |
	INT_ID { $$=createNewIdNode($1); cout<<"int id "<<endl;}
	;

float_expr:
	float_expr '+' float_expr { $$=createNewExprNode(pls,2,$1,$3); generateQuad("ADD",$1,$3,$$); cout << "PLUS: " << $$ <<endl; } |
	float_expr '-' float_expr { $$=createNewExprNode(mins,2,$1,$3); generateQuad("SUB",$1,$3,$$); cout << "MINUS: " << $$ <<endl; }| 
	float_expr '*' float_expr { $$=createNewExprNode(mul,2,$1,$3); generateQuad("MUL",$1,$3,$$); cout << "MUL: " << $$ << endl;  }| 
	float_expr '/' float_expr { $$=createNewExprNode(dv,2,$1,$3); generateQuad("DIV",$1,$3,$$); cout << "DIV: " << $$ <<endl; }| 
	float_expr '%' float_expr { $$=createNewExprNode(md,2,$1,$3);  generateQuad("MOD",$1,$3,$$);cout << "MOD: " << $$ << endl; }| 
	float_expr POW float_expr { $$=createNewExprNode(pw,2,$1,$3);  generateQuad("POW",$1,$3,$$);cout << "POW: " << $$ << endl; }| 
	
	float_expr '+' int_expr { $$=createNewExprNode(pls,2,$1,$3); generateQuad("ADD",$1,$3,$$); cout << "PLUS: " << $$ <<endl; } |
	float_expr '-' int_expr { $$=createNewExprNode(mins,2,$1,$3); generateQuad("SUB",$1,$3,$$); cout << "MINUS: " << $$ <<endl; }| 
	float_expr '*' int_expr { $$=createNewExprNode(mul,2,$1,$3); generateQuad("MUL",$1,$3,$$); cout << "MUL: " << $$ << endl;  }| 
	float_expr '/' int_expr { $$=createNewExprNode(dv,2,$1,$3); generateQuad("DIV",$1,$3,$$); cout << "DIV: " << $$ <<endl; }| 
	float_expr '%' int_expr { $$=createNewExprNode(md,2,$1,$3);  generateQuad("MOD",$1,$3,$$);cout << "MOD: " << $$ << endl; }| 
	float_expr POW int_expr { $$=createNewExprNode(pw,2,$1,$3);  generateQuad("POW",$1,$3,$$);cout << "POW: " << $$ << endl; }| 
	
	int_expr '+' float_expr { $$=createNewExprNode(pls,2,$1,$3); generateQuad("ADD",$1,$3,$$); cout << "PLUS: " << $$ <<endl; } |
	int_expr '-' float_expr { $$=createNewExprNode(mins,2,$1,$3); generateQuad("SUB",$1,$3,$$); cout << "MINUS: " << $$ <<endl; }| 
	int_expr '*' float_expr { $$=createNewExprNode(mul,2,$1,$3); generateQuad("MUL",$1,$3,$$); cout << "MUL: " << $$ << endl;  }| 
	int_expr '/' float_expr { $$=createNewExprNode(dv,2,$1,$3); generateQuad("DIV",$1,$3,$$); cout << "DIV: " << $$ <<endl; }| 
	int_expr '%' float_expr { $$=createNewExprNode(md,2,$1,$3);  generateQuad("MOD",$1,$3,$$);cout << "MOD: " << $$ << endl; }| 
	int_expr POW float_expr { $$=createNewExprNode(pw,2,$1,$3);  generateQuad("POW",$1,$3,$$);cout << "POW: " << $$ << endl; }| 
	
	'(' float_expr ')' { cout << "Brackets  " <<endl; } | //<< $$=$2 
	FLOAT { $$=createNewValueNode(NewNodeFloat($1)); cout<<"float value"<<endl; }  | 
	FLOAT_ID  { $$=createNewIdNode($1); cout<<"float id "<<endl;}
	;
	
float_int_expr:
	float_expr | int_expr ;
	
str_expr:
	str_expr '+' str_expr |
	STRING //| STR_ID
	;

if_else_if_else_stmt:
	if_stmt else_if_stmt ;

if_stmt:
	IF '(' bool_expr ')' '{' stmt '}' { cout << "if " <<endl; }
	;
else_if_stmt:
	ELSE if_stmt else_if_stmt { cout << "else if  " <<endl; } | //sequence of else if 
	ELSE '{' stmt '}' { cout << "else " <<endl; } | //else 
	{ cout << "epsilon " <<endl; }	//epsilon 
	;
	
while_loop:
	WHILE '(' bool_expr ')' '{' stmt '}' ;
	
for_loop:
	FOR '(' for_assignment ',' bool_expr ',' for_assignment ')' '{' stmt '}'
	
for_assignment:
	id EQUAL int_expr ;		//To Check here .. int_expr?
	
repeat_until_loop:
	REPEAT '{' stmt '}' UNTIL '(' bool_expr ')' ';' ;
	
switch_case:	
	SWITCH '(' id ')' '{' case_stmt '}' ;
	
case_stmt:
	CASE value ':' stmt case_stmt |
	DEFAULT ':' stmt |
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
	'(' bool_expr ')' { cout << "Brackets " <<endl; }
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

ofstream quad;
int lineNo=0;

void generateQuad(string op , NodeWithType * arg1 , NodeWithType * arg2 , NodeWithType * res){
	quad << lineNo << " " << op <<" ";
	if(arg1->tp==val) quad << arg1->node->val->iVal << " " ;
	else if(arg1->tp==identifier) quad << arg1-> node->id << " " ;
	else quad << "t" << nodes[arg1] <<" ";
	
	if(arg2==NULL) quad << " " ;
	else if(arg2->tp==val) quad << arg2->node->val->iVal << " " ;
	else if(arg2->tp==identifier) quad << arg2-> node->id << " " ;
	else quad << "t" << nodes[arg2] <<" ";
	
	if(res->tp==val) quad << res->node->val->iVal << " " ;
	else if(res->tp==identifier) quad << res-> node->id << " " ;
	else quad << "t" << nodes[res] <<" ";
	
	quad << endl;	
	lineNo++;
}

void newSymbolRecord( char * name, IdType ty, bool v_c , NodeWithType* vlu ){
	SymRec rec ;
	rec.typ=ty;
	rec.VarConst=v_c;
	rec.value=vlu;
	mainScope.insert(name,&rec); 
}

Node * NewNodeInt(int i){
	Node * nd=new Node();
	Value * v=new Value();
	v->iVal=i;
	nd->val=v;
	cout<<"new value node created"<<endl;
	return nd;
}

Node * NewNodeFloat(float i){
	Node * nd=new Node();
	Value * v=new Value();
	v->fVal=i;
	nd->val=v;
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