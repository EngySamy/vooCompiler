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
	bool bval;
	struct NodeWithType * nodeval;
}

// define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the union:
%token <ival> INT //
%token <fval> FLOAT
%token <sval> STRING
%token <idval> BOOL_ID FLOAT_ID STR_ID INT_ID 
%token CONST VAR EQUAL 
%token <bval> TRUE FALSE 

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

%type <nodeval> int_expr float_expr float_int_expr bool_expr compare_opd boolean str_expr bool_term

%%
// this is the actual grammar that bison will parse

stmt:
	variable stmt | constant_stmt stmt | assignment stmt | if_else_if_else_stmt stmt | for_loop stmt | while_loop stmt | repeat_until_loop stmt | switch_case stmt |
	variable | constant_stmt | assignment | if_else_if_else_stmt | for_loop | while_loop | repeat_until_loop | switch_case ;

/*declaration:
	variable | constant_stmt ;
	*/
variable: 
	VAR id1 ';' |
	VAR decl_assign 
	;
id1:
	INT_ID { 
			newSymbolRecord($1,integer,true);
			mainScope.printAll();
			cout<< "ass for int id (var) -> INT_ID: " <<$1<<endl;} |
	FLOAT_ID  { 
			newSymbolRecord($1,floatt,true);
			mainScope.printAll();
			cout<< "ass for float id (var) -> FLOAT_ID: " <<$1<<endl;}|
	STR_ID  { 
			newSymbolRecord($1,str,true);
			mainScope.printAll();
			cout<< "ass for string id (var) -> STR_ID: " <<$1<<endl;}|
	BOOL_ID  { cout << " bool id " << endl; }
	;

decl_assign:	
	INT_ID EQUAL int_expr ';' { 
				newSymbolRecord($1,integer,true);
				generateQuad("STO",$3,NULL,createNewIdNode($1));
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<$1<<" with value "<<$3<<endl;} |
	FLOAT_ID EQUAL float_int_expr ';' { 
				newSymbolRecord($1,floatt,true);
				generateQuad("STO",$3,NULL,createNewIdNode($1));
				mainScope.printAll();
				cout<< "ass for float id (var) -> FLOAT_ID: " <<$1<<" with value "<<$3<<endl;}|
	STR_ID EQUAL str_expr ';' { 
				newSymbolRecord($1,str,true);
				mainScope.printAll();
				cout<< "ass for string id (var) -> STR_ID: " <<$1<<" with value "<<$3<<endl;}|
	BOOL_ID EQUAL bool_expr ';' 
	;
	
constant_stmt:
	CONST constant;
	
constant:
	INT_ID EQUAL INT ';' { cout << "const int id " << endl;
								NodeWithType* nt=createNewValueNode(NewNodeInt($3));
								newSymbolRecord($1,integer,false);
								generateQuad("STO",nt,NULL,createNewIdNode($1));
								mainScope.printAll();
								cout<< "ass for int id (const) -> INT_ID: " <<$1<<" with value "<<$3<<endl;}  |
	FLOAT_ID EQUAL FLOAT ';' { cout << "const float id " << endl;
								NodeWithType* nt=createNewValueNode(NewNodeFloat($3));
								newSymbolRecord($1,floatt,false);
								generateQuad("STO",nt,NULL,createNewIdNode($1));
								mainScope.printAll();
								cout<< "ass for float id (const) -> FLOAT_ID: " <<$1<<" with value "<<$3<<endl;}|
	STR_ID EQUAL STRING ';' { cout << "const str id " << endl; 
								NodeWithType* nt=createNewValueNode(NewNodeString($3));
								newSymbolRecord($1,str,false);
								generateQuad("STO",nt,NULL,createNewIdNode($1));
								mainScope.printAll();
								cout<< "ass for str id (const) -> STR_ID: " <<$1<<" with value "<<$3<<endl;}|
	BOOL_ID EQUAL boolean ';' { cout << "const bool id " << endl; }
	;
	
assignment:
	INT_ID EQUAL int_expr ';' { 
				generateQuad("STO",$3,NULL,createNewIdNode($1));
				mainScope.printAll();
				cout<< "ass for int id (var) -> INT_ID: " <<$1<<" with value "<<$3<<endl;} |
	FLOAT_ID EQUAL float_int_expr ';' { 
				generateQuad("STO",$3,NULL,createNewIdNode($1));
				mainScope.printAll();
				cout<< "ass for float id (var) -> FLOAT_ID: " <<$1<<" with value "<<$3<<endl;}|
	STR_ID EQUAL str_expr ';' { 
				mainScope.printAll();
				cout<< "ass for string id (var) -> STR_ID: " <<$1<<" with value "<<$3<<endl;}|
	BOOL_ID EQUAL bool_expr ';' { 
				generateQuad("STO",$3,NULL,createNewIdNode($1));
				mainScope.printAll();
				cout<< "ass for bool id (var) -> BOOL_ID: " <<$1<<" with value "<<$3<<endl;}
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
	
	//'(' float_expr ')' { cout << "Brackets  " <<endl; } |
	FLOAT { $$=createNewValueNode(NewNodeFloat($1)); cout<<"float value"<<endl; }  | 
	FLOAT_ID  { $$=createNewIdNode($1); cout<<"float id "<<endl;}
	;
	
float_int_expr:
	float_expr | int_expr ;
	
str_expr:
	//str_expr '+' str_expr {$$=createNewExprNode(concat,2,$1,$3); generateQuad("ADD",$1,$3,$$); cout << "PLUS: " << $$ <<endl; }|
	STRING { $$=createNewValueNode(NewNodeString($1)); cout<<"string value"<<endl; }  |  
	STR_ID { $$=createNewIdNode($1); cout<<"string id"<<endl; }
	;

if_else_if_else_stmt:
	if_stmt1 else_if_stmt {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
		};

if_stmt1:
	IF '(' start_bool_expr bool_expr end_bool_expr ')' '{' stmt '}' { 
		cout << "if " <<endl;
		int temp =brLabels.top();
		brLabels.pop();
		int label=generateOneLabel(); //label to jump after else
		ifElseLabels.push(label);
		generateBranchQuad("JMP",label,NULL);
		outLabel(temp);
		brLabels.pop();	
		}
	;
	
if_stmt:
	IF start_while_if bool_expr end_while_if '{' stmt '}' { 
		cout << "if " <<endl;
		int temp =brLabels.top();
		brLabels.pop();
		int label=ifElseLabels.top(); //label to jump after else
		generateBranchQuad("JMP",label,NULL);
		outLabel(temp);
		brLabels.pop();	
		}
	;
else_if_stmt:
	ELSE if_stmt else_if_stmt { cout << "else if  " <<endl; } | //sequence of else if 
	ELSE '{' stmt '}' { cout << "else " <<endl; } | //else 
	{ cout << "epsilon " <<endl; }	//epsilon 
	;
	
while_loop:
	WHILE start_while_if bool_expr end_while_if '{' stmt '}' {
		int temp =brLabels.top();
		brLabels.pop();
		generateBranchQuad("JMP",brLabels.top(),NULL);
		outLabel(temp);
		brLabels.pop();	
		}
	;
	
start_while_if:
	'(' {generateLabelPair();};
	
end_while_if:
	')' {generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();}  ;
	
for_loop:
	FOR '(' for_assignment ',' start_bool_expr bool_expr end_bool_expr')' '{' stmt '}' '(' for_assignment ')' ';' {
		int temp =brLabels.top();
		brLabels.pop();
		generateBranchQuad("JMP",brLabels.top(),NULL);
		outLabel(temp);
		brLabels.pop();}
	;
	
start_bool_expr:
	//epsilon 
	{generateLabelPair();};
	
end_bool_expr:
	//epsilon
	{generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();}  ;
	
for_assignment:
	INT_ID EQUAL int_expr {generateQuad("STO",$3,NULL,createNewIdNode($1));} ;
	
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
	LOGIC_NOT bool_expr { cout << "LOGIC_NOT " <<endl; } |
	bool_expr LOGIC_AND bool_expr { 
						$$=createNewExprNode(l_and,2,$1,$3);
						generateQuad("AND",$1,$3,$$);
						boolRes.push($$); 						
						cout << "LOGIC_AND " <<endl; } | 
	bool_expr LOGIC_OR bool_expr { cout << "LOGIC_OR " <<endl; } |
	boolean { cout << "boolean " <<endl; } |
	BOOL_ID { $$=createNewIdNode($1); cout<<"bool id"<<endl; } |
	bool_term 
	//'(' bool_expr ')' { cout << "Brackets " <<endl; }
	;


	
bool_term:
	compare_opd EQ compare_opd { $$=createNewExprNode(eq,2,$1,$3); 								 
								generateQuad("EQ",$1,$3,$$);
								cout << "EQ " <<endl; } | 
	compare_opd NOT_EQ compare_opd { $$=createNewExprNode(ne,2,$1,$3); 
									generateQuad("NOT_EQ",$1,$3,$$); 
									cout << "NOT_EQ " <<endl; } | 
	compare_opd GR compare_opd { $$=createNewExprNode(gt,2,$1,$3); generateQuad("GR",$1,$3,$$); cout << "GR " <<endl; } | 
	compare_opd GR_EQ compare_opd { $$=createNewExprNode(gte,2,$1,$3); generateQuad("GR_EQ",$1,$3,$$); cout << "GR_EQ " <<endl; } | 
	compare_opd SM compare_opd { $$=createNewExprNode(sm,2,$1,$3); generateQuad("SM",$1,$3,$$); cout << "SM " <<endl; } | 
	compare_opd SM_EQ compare_opd { $$=createNewExprNode(sme,2,$1,$3); generateQuad("SM_EQ",$1,$3,$$); cout << "SM_EQ " <<endl; } 
	;
	
compare_opd:
	INT {}|
	INT_ID {$$=createNewIdNode($1); cout<<"compare id in bool expr"<<endl;}|
	FLOAT {} |
	FLOAT_ID {$$=createNewIdNode($1); cout<<"compare id in bool expr"<<endl;}|
	STRING {}|
	STR_ID {$$=createNewIdNode($1); cout<<"compare id in bool expr"<<endl;}; 
	
value:
	INT | FLOAT | STRING | boolean ;
	
	
boolean:
	TRUE { $$=createNewValueNode(NewNodeBool($1)); cout<<"bool value"<<endl; } | 
	FALSE { $$=createNewValueNode(NewNodeBool($1)); cout<<"bool value"<<endl; } ;
	
id:
	INT_ID { cout << " int id " << endl; }
	| FLOAT_ID  { cout << " float id " << endl; }
	| STR_ID  { cout << " str id " << endl; }
	| BOOL_ID  { cout << " bool id " << endl; }
	;
	
	
%%

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