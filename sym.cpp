#include<string>
#include"sym.h"
#include"tree.h"

using namespace std;

// Class Scope
Scope::Scope(string newname) {
	name = newname;
}

Scope::~Scope() {
}

/*void Scope::print(void (*printData)(pair <void * , IdType > *) ) {
	printf("Scope: %-15s -----------------\n", name.c_str());
	for(map<string, pair <void * , IdType > * >::iterator it = symbols.begin(); it != symbols.end(); it++) {
		printf("%20s: ", (it->first).c_str());
		printData((it->second)->first);
		printf("\n");
		
		printData((it->second)->second);
		printf("\n");		
	}
}

*/
bool Scope::insert(char * sym, SymRec *ptr) {
	if(symbols.find(sym) == symbols.end()) {
		symbols[sym] = * ptr;
		//cout<<"added symbol[  " << sym << " ] = "<< symbols[sym].typ <<endl;
		return true;
	} else 
		return false;
}

SymRec *Scope::lookup(char * sym) {
	if(symbols.find(sym) != symbols.end()) {
		return &symbols[sym];
	} else
		return NULL;
}

void Scope::printAll(){
	cout<<"start printing symbol table"<<endl;
	for (map<char*,SymRec>::iterator it=symbols.begin(); it!=symbols.end(); ++it)
		cout << it->first << " => type: " << it->second.typ << " , var? : " << it->second.VarConst << endl;//" , value : " << (((it->second.value)->node)->val)->v->iVal <<'\n';
}
