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
%token <idval> BOOL_ID FLOAT_ID STR_ID INT_ID error
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

%token IF ELSE FOR WHILE SWITCH CASE REPEAT UNTIL DEFAULT DONE ENDL START_DECL END_DECL

%type <nodeval> int_expr float_expr float_int_expr bool_expr compare_opd boolean str_expr bool_term id value for_assignment

%%
// this is the actual grammar that bison will parse

program:
	START_DECL endls declarations END_DECL endls stmt ;

stmt:
	stmt assignment  | stmt if_else_if_else_stmt  | stmt for_loop  | stmt while_loop  | stmt repeat_until_loop  | stmt switch_case  |
	assignment | if_else_if_else_stmt | for_loop | while_loop  | repeat_until_loop | switch_case ;

declarations:
	variable | constant_stmt | declarations variable | declarations constant_stmt ;	
	
variable: 
	VAR id1 ';' endls |
	VAR decl_assign endls |
	VAR error ';' { errorVarStmt();} endls  //handle syntax error
	;
id1:
	INT_ID { declIdActions($1,integer);} |
	FLOAT_ID  {declIdActions($1,floatt);} |
	STR_ID  { declIdActions($1,str);} |
	BOOL_ID  { declIdActions($1,boolean);}
	;

decl_assign:	
	INT_ID EQUAL int_expr ';' { declAssignmentActions($1,$3,integer); } |
	FLOAT_ID EQUAL float_int_expr ';' {declAssignmentActions($1,$3,floatt);}|
	STR_ID EQUAL str_expr ';' { declAssignmentActions($1,$3,str);}|
	BOOL_ID EQUAL bool_expr ';' { declAssignmentActions($1,$3,boolean);}
	;
	
constant_stmt:
	CONST constant endls |
	CONST error ';' {errorConstStmt();} endls //handle syntax error;
	
constant:
	INT_ID EQUAL INT ';' { 
						if(mainScope.checkIteratorAtEnd(mainScope.lookup($1))){  //check if this var hasn't been declared before , not to declare 2 var with the same name 
							NodeWithType* nt=createNewValueNode(NewNodeInt($3));
							newSymbolRecord($1,integer,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode($1));
						}
						else errorExistsBefore($1);	
					} |
	FLOAT_ID EQUAL FLOAT ';' { 
						if(mainScope.checkIteratorAtEnd(mainScope.lookup($1))){	
							NodeWithType* nt=createNewValueNode(NewNodeFloat($3));
							newSymbolRecord($1,floatt,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode($1));
						}
						else errorExistsBefore($1);	
					}|
	STR_ID EQUAL STRING ';' {
						if(mainScope.checkIteratorAtEnd(mainScope.lookup($1))){	
							NodeWithType* nt=createNewValueNode(NewNodeString($3));
							newSymbolRecord($1,str,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode($1));
						}
						else errorExistsBefore($1);
					}|
	BOOL_ID EQUAL boolean ';' {
						if(mainScope.checkIteratorAtEnd(mainScope.lookup($1))){	
							NodeWithType* nt=createNewValueNode(NewNodeBool($3));
							newSymbolRecord($1,boolean,false,true);
							generateQuad("STO",nt,NULL,createNewIdNode($1));
						}
						else errorExistsBefore($1);
					}
	;
	
assignment:
	INT_ID EQUAL int_expr ';' { assignmentActions($1,$3,integer);} endls |
	FLOAT_ID EQUAL float_int_expr ';' { assignmentActions ($1,$3,floatt);} endls |
	STR_ID EQUAL str_expr ';' endls { assignmentActions($1,$3,str);}|
	BOOL_ID EQUAL bool_expr ';' endls { assignmentActions($1,$3,boolean);} |
	//handle errors 
	INT_ID EQUAL error ';' {cout<<"At Line: "<<line_num<<" Not a valid int expression to use !" <<endl;} endls |
	FLOAT_ID EQUAL error ';' {cout<<"At Line: "<<line_num<<" Not a valid float expression to use !" <<endl;} endls |
	STR_ID EQUAL error ';' {cout<<"At Line: "<<line_num<<" Not a valid string expression to use !" <<endl;} endls |
	BOOL_ID EQUAL error ';' {cout<<"At Line: "<<line_num<<" Not a valid bool expression to use !"<<endl;} endls |
	error EQUAL exprr ';' {cout<<"At Line: "<<line_num<<" Not a valid identifier to use !" <<endl;} endls //|
	//error EQUAL error ';' {cout<<"Not a valid assignment expression to use !" <<endl;}
	;
exprr :
	str_expr | bool_expr | int_expr | float_expr ;

int_expr:
	int_expr '+' int_expr { $$=createNewExprNode(pls,2,$1,$3); if($$!=NULL){generateQuad("ADD",$1,$3,$$); cout << "PLUS "  <<endl;} } | 
	int_expr '-' int_expr { $$=createNewExprNode(mins,2,$1,$3); if($$!=NULL){generateQuad("SUB",$1,$3,$$); cout << "MINUS" <<endl; }}| 
	int_expr '*' int_expr { $$=createNewExprNode(mul,2,$1,$3); if($$!=NULL){generateQuad("MUL",$1,$3,$$); cout << "MUL" <<endl; } }| 
	int_expr '/' int_expr { $$=createNewExprNode(dv,2,$1,$3); if($$!=NULL){generateQuad("DIV",$1,$3,$$); cout << "DIV " <<endl; }}|  
	int_expr '%' int_expr { $$=createNewExprNode(md,2,$1,$3);  if($$!=NULL){generateQuad("MOD",$1,$3,$$);cout << "MOD " <<endl; }}|  
	
	int_expr '&' int_expr { $$=createNewExprNode(b_and,2,$1,$3); if($$!=NULL){generateQuad("AND",$1,$3,$$); cout << "BITWISE_AND " <<endl;} } | //<< $$=$1&$3 
	int_expr '|' int_expr { $$=createNewExprNode(b_or,2,$1,$3); if($$!=NULL){generateQuad("OR",$1,$3,$$); cout << "BITWISE_OR " <<endl; }} | // << $$=$1|$3 
	int_expr '^' int_expr { $$=createNewExprNode(b_xor,2,$1,$3); if($$!=NULL){generateQuad("XOR",$1,$3,$$); cout << "BITWISE_XOR " <<endl; }} | // << $$=$1^$3 
	'~' int_expr { $$=createNewExprNode(b_not,1,$2,NULL); if($$!=NULL){generateQuad("NOT",$2,NULL,$$); cout << "BITWISE_NOT: " <<endl; }} | // << $$=~$2 
	int_expr BITWISE_SHIFT_LEFT int_expr { $$=createNewExprNode(b_shft_r,2,$1,$3); if($$!=NULL){generateQuad("SHFTL",$1,$3,$$); cout << "BITWISE_SHIFT_LEFT: " <<endl; }} | //<< $$=$1<<$3 
	int_expr BITWISE_SHIFT_RIGHT int_expr { $$=createNewExprNode(b_shft_l,2,$1,$3); if($$!=NULL){generateQuad("SHFTR",$1,$3,$$); cout << "BITWISE_SHIFT_RIGHT: " <<endl; }} |  //<< $$=$1>>$3 
	
	'(' int_expr ')' { $$=$2;	cout << "Brackets  " <<endl; } | 
	INT { $$=createNewValueNode(NewNodeInt($1)); } |
	INT_ID { $$=newIdActions($1);}
	;

float_expr:
	float_expr '+' float_expr { $$=createNewExprNode(pls,2,$1,$3); if($$!=NULL){generateQuad("ADD",$1,$3,$$); cout << "PLUS " <<endl; }} |
	float_expr '-' float_expr { $$=createNewExprNode(mins,2,$1,$3); if($$!=NULL){generateQuad("SUB",$1,$3,$$); cout << "MINUS " << endl; }}| 
	float_expr '*' float_expr { $$=createNewExprNode(mul,2,$1,$3); if($$!=NULL){generateQuad("MUL",$1,$3,$$); cout << "MUL " << endl; } }| 
	float_expr '/' float_expr { $$=createNewExprNode(dv,2,$1,$3); if($$!=NULL){generateQuad("DIV",$1,$3,$$); cout << "DIV " << endl; }}| 
	float_expr '%' float_expr { $$=createNewExprNode(md,2,$1,$3);  if($$!=NULL){generateQuad("MOD",$1,$3,$$);cout << "MOD " << endl; }}| 
	float_expr POW float_expr { $$=createNewExprNode(pw,2,$1,$3);  if($$!=NULL){generateQuad("POW",$1,$3,$$);cout << "POW " << endl; }}| 
	
	float_expr '+' int_expr { $$=createNewExprNode(pls,2,$1,$3); if($$!=NULL){generateQuad("ADD",$1,$3,$$); cout << "PLUS " << endl; }} |
	float_expr '-' int_expr { $$=createNewExprNode(mins,2,$1,$3); if($$!=NULL){generateQuad("SUB",$1,$3,$$); cout << "MINUS " <<endl; }}| 
	float_expr '*' int_expr { $$=createNewExprNode(mul,2,$1,$3); if($$!=NULL){generateQuad("MUL",$1,$3,$$); cout << "MUL " << endl; } }| 
	float_expr '/' int_expr { $$=createNewExprNode(dv,2,$1,$3); if($$!=NULL){generateQuad("DIV",$1,$3,$$); cout << "DIV " <<endl; }}| 
	float_expr '%' int_expr { $$=createNewExprNode(md,2,$1,$3);  if($$!=NULL){generateQuad("MOD",$1,$3,$$);cout << "MOD " << endl; }}| 
	float_expr POW int_expr { $$=createNewExprNode(pw,2,$1,$3);  if($$!=NULL){generateQuad("POW",$1,$3,$$);cout << "POW " << endl; }}| 
	
	int_expr '+' float_expr { $$=createNewExprNode(pls,2,$1,$3); if($$!=NULL){generateQuad("ADD",$1,$3,$$); cout << "PLUS" << endl; }} |
	int_expr '-' float_expr { $$=createNewExprNode(mins,2,$1,$3); if($$!=NULL){generateQuad("SUB",$1,$3,$$); cout << "MINUS " << endl; }}| 
	int_expr '*' float_expr { $$=createNewExprNode(mul,2,$1,$3); if($$!=NULL){generateQuad("MUL",$1,$3,$$); cout << "MUL " << endl;  }}| 
	int_expr '/' float_expr { $$=createNewExprNode(dv,2,$1,$3); if($$!=NULL){generateQuad("DIV",$1,$3,$$); cout << "DIV " << endl; }}| 
	int_expr '%' float_expr { $$=createNewExprNode(md,2,$1,$3);  if($$!=NULL){generateQuad("MOD",$1,$3,$$);cout << "MOD " << endl; }}| 
	int_expr POW float_expr { $$=createNewExprNode(pw,2,$1,$3);  if($$!=NULL){generateQuad("POW",$1,$3,$$);cout << "POW " << endl; }}| 
	
	'(' float_expr ')' { $$=$2; cout << "Brackets  " <<endl; } |
	FLOAT { $$=createNewValueNode(NewNodeFloat($1));  }  | 
	FLOAT_ID  { $$=newIdActions($1);}
	;
	
float_int_expr:
	float_expr | int_expr ;
	
str_expr:
	STRING { $$=createNewValueNode(NewNodeString($1));  }  |  
	STR_ID { $$=newIdActions($1); }
	;

if_else_if_else_stmt:
	if_stmt1 else_if_stmt {
		outLabel(ifElseLabels.top());  //label after the else stat
		ifElseLabels.pop();	
	};

if_stmt1:
	IF start_while_if bool_expr end_while_if '{' stmt '}' { 
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
	WHILE start_while_if bool_expr end_while_if '{' endls stmt '}' ';' endls {
		int temp =brLabels.top();
		brLabels.pop();
		if($3!=NULL){
			generateBranchQuad("JMP",brLabels.top(),NULL);
			outLabel(temp);
		}
		brLabels.pop();	
	}|
	//handle error 
	//WHILE '(' error ')' '{' stmt '}' {cout<<"Not a valid boolean expression in while statement !"<<endl;}|
	WHILE error ';' { cout<<"At Line: "<<line_num<<" Not a valid while statement !"<<endl;} endls // char* cc="Not a valid while statement ! from yyerror"; yyerror(cc);
	;
	
start_while_if:
	'(' {generateLabelPair();};
	
end_while_if:
	')' { if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} }  ;
	
for_loop:
	FOR '(' for_assignment ',' start_bool_expr bool_expr end_bool_expr ')' '{' endls stmt '}' '(' for_assignment ')' ';' endls {
		int temp =brLabels.top();
		brLabels.pop();
		if($6!=NULL){
			generateBranchQuad("JMP",brLabels.top(),NULL);
			outLabel(temp);
		}
		brLabels.pop();
	} |
	FOR error { cout<<"At Line: "<<line_num<<" Not a valid for statement !"<<endl;} ';' endls
	;
	
start_bool_expr:
	//epsilon 
	{generateLabelPair();};
	
end_bool_expr:
	//epsilon
	{ if(!boolRes.empty()){generateBranchQuad("JFALSE",brLabels.top(),boolRes.top()); boolRes.pop();} }  ;
	
for_assignment:
	INT_ID EQUAL int_expr {
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
			} 
		else {$$=NULL; errorDoesntExist($1);}
			 
	} ;
	

			
repeat_until_loop:
	start_repeat '{' endls stmt '}' UNTIL '(' bool_expr ')' ';' endls {
		if(!boolRes.empty()){
			generateBranchQuad("JTRUE",brLabels.top(),boolRes.top()); 
			boolRes.pop();
		}
		brLabels.pop();
	} |
	//handle syntax error
	REPEAT error ';' { cout<<"At Line: "<<line_num<<" Not a valid repeat until statement !"<<endl;} endls
	;
	

start_repeat:
	REPEAT {int label=generateOneLabel(); outLabel(label); brLabels.push(label);} ;

bool_expr:
	LOGIC_NOT bool_expr { cout << "LOGIC_NOT " <<endl; } |
	bool_expr LOGIC_AND bool_expr { 
						$$=createNewExprNode(l_and,2,$1,$3);
						if($$!=NULL){
							generateQuad("AND",$1,$3,$$);
							boolRes.push($$); 						
							cout << "LOGIC_AND " <<endl;
						}
					} | 
	bool_expr LOGIC_OR bool_expr { 
					$$=createNewExprNode(l_and,2,$1,$3);
						if($$!=NULL){
							generateQuad("OR",$1,$3,$$);
							boolRes.push($$); 						
							cout << "LOGIC_OR " <<endl;
						}
					} |
	boolean { cout << "boolean " <<endl; } |
	BOOL_ID { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);}  } |
	
	bool_term { $$=$1;   if($$!=NULL) boolRes.push($$); 	}|
	'(' bool_expr ')' { $$=$2;  cout << "Brackets " <<endl; }
	;

	
	
bool_term:
	compare_opd EQ compare_opd { $$=createNewExprNode(eq,2,$1,$3); if($$!=NULL){generateQuad("EQ",$1,$3,$$); cout << "EQ " <<endl; }} | 
	compare_opd NOT_EQ compare_opd { $$=createNewExprNode(ne,2,$1,$3); if($$!=NULL){generateQuad("NOT_EQ",$1,$3,$$); cout << "NOT_EQ " <<endl; }} | 
	compare_opd GR compare_opd { $$=createNewExprNode(gt,2,$1,$3); if($$!=NULL){generateQuad("GR",$1,$3,$$); cout << "GR " <<endl; }} | 
	compare_opd GR_EQ compare_opd { $$=createNewExprNode(gte,2,$1,$3); if($$!=NULL){generateQuad("GR_EQ",$1,$3,$$); cout << "GR_EQ " <<endl; }} | 
	compare_opd SM compare_opd { $$=createNewExprNode(sm,2,$1,$3); if($$!=NULL){generateQuad("SM",$1,$3,$$); cout << "SM " <<endl; }} | 
	compare_opd SM_EQ compare_opd { $$=createNewExprNode(sme,2,$1,$3); if($$!=NULL){generateQuad("SM_EQ",$1,$3,$$); cout << "SM_EQ " <<endl; }} 
	;

compare_opd:
	INT {$$=createNewValueNode(NewNodeInt($1));}|
	INT_ID { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);}  }|
	FLOAT {$$=createNewValueNode(NewNodeFloat($1)); } |
	FLOAT_ID { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);}  }|
	STRING {$$=createNewValueNode(NewNodeString($1));}|
	STR_ID { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);}  }
	; 

	
switch_case:	
	start_switch '(' id ')' '{' case_stmts defaultt '}' {
		outLabel(switchLabels.top());
		switchLabels.pop();
		if(!switchIds.empty()) switchIds.pop();
	};
	
start_switch:
	SWITCH {
		int label = generateOneLabel();
		switchLabels.push(label);
		cout<<"ok start switch";
	};

id:
	INT_ID { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);}  }
	| FLOAT_ID  { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);} }
	| STR_ID  { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);} }
		
	| BOOL_ID  { 
		map<char*,SymRec>::iterator it=mainScope.lookup($1);
		if(!mainScope.checkIteratorAtEnd(it)){
			$$=createNewIdNode($1); 
			if(!mainScope.checkIteratorInit(it)) unInit.push($1);
			updateSymbolRecordUsed($1);
		} 
		else {$$=NULL; errorDoesntExist($1);} }
	;
	
case_stmts:
	case_stmt case_stmts |
	case_stmt
	;
	
case_stmt:
	CASE value ':' {
			int l=generateOneLabel();
			brLabels.push(l);
			if(!switchIds.empty()){
				NodeWithType* vv=createNewExprNode(eq,2,switchIds.top(),$2); 
				if(vv!=NULL){
					generateQuad("EQ",switchIds.top(),$2,vv);
					generateBranchQuad("JFALSE",brLabels.top(),vv);
				}
			}
		}
		stmt done 
	;
	
done:
	DONE ';' {
		generateBranchQuad("JMP",switchLabels.top(),NULL);
		outLabel(brLabels.top());
		brLabels.pop();
	};
	
defaultt:	
	DEFAULT ':' stmt {cout<<"ok def switch";};
	
value:
	INT {$$=createNewValueNode(NewNodeInt($1)); }
	| FLOAT {$$=createNewValueNode(NewNodeFloat($1)); }
	| STRING {$$=createNewValueNode(NewNodeString($1)); }
	| boolean //{$$=createNewValueNode(NewNodeBool($1)); }
	;
	
	
boolean:
	TRUE { $$=createNewValueNode(NewNodeBool($1)); /*cout<<"bool value"<<endl;*/ } | 
	FALSE { $$=createNewValueNode(NewNodeBool($1)); /*cout<<"bool value"<<endl;*/ } ;

endls:
	endls ENDL
	| ENDL 
	;	
%%

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