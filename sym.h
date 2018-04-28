#include<map>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>
#include <utility>

using namespace std;

enum IdType { integer , floatt , str , boolean };
enum oprt {pls , mins , mul , dv , md , pw , b_and , b_or , b_xor , b_not , b_shft_r , b_shft_l ,
			//logical operators:
			gt , gte , sm , sme , ne , eq };
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
	SymRec *lookup(char * sym);
	void printAll();

	string scopeName() { return name; };
};