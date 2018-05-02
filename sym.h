#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>
#include <utility>

using namespace std;

enum IdType { integer , floatt , str , boolean };
enum oprt {pls , mins , mul , dv , md , pw , b_and , b_or , b_xor , b_not , b_shft_r , b_shft_l , neg ,
			//logical operators:
			gt , gte , sm , sme , ne , eq ,
			//logic comparisons
			l_and , l_or , l_not };
enum NodeType {expression, identifier, val};
struct expr;

union Value{
	int iVal;
	float fVal;
	bool bVal;
	char * sVal;
};

struct ValueWithType {
	Value * v;
	IdType tp;
};

union Node {  //the node can have expression or actual value or identifier
	expr * exp;
	char * id;
	ValueWithType * val;
};

struct NodeWithType{
	Node * node;
	NodeType tp;
};

struct expr{
	oprt opt;
	int nOps;
	NodeWithType * opds[2]; //operands are nodes 
};



struct SymRec {
	IdType typ;
	bool VarConst; // var or constant
	bool init;		//initialized or not 
	bool used; 		//used or unused yet
	//NodeWithType * value;
};

class Scope {
private:
	string name;
	map<char *, SymRec > symbols;  //  id name , value , type 

public:
	Scope(string newname);
	~Scope();
	//void print(void (*printData)(pair <void * , IdType > *));
	bool insert(char * sym, SymRec *ptr);
	map<char*,SymRec>::iterator lookup(char * sym);
	bool checkIteratorAtEnd(map<char*,SymRec>::iterator it);
	bool checkIteratorInit(map<char*,SymRec>::iterator it);
	bool checkVarConst(map<char*,SymRec>::iterator it);
	map<char*,SymRec>::iterator firstSymRec();
	void printAll();

	string scopeName() { return name; };
};