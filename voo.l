%{
#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
#define YY_DECL extern "C" int yylex()

#include "voo.tab.h"  // to get the token types that we return
#include "symTab.h"

%}
%%

"const"		{return CONST;}
"var"		{return VAR;}
"true" 		{return TRUE;}
"false"		{return FALSE;}
"="			{return EQUAL;}
";" 		{return SEMI_COLON;}
":"			{return COLON;}
","			{return COMMA;}

"+"			{return PLUS;}
"-"			{return MINUS;}
"**"		{return POW;}
"*"			{return MUL;}
"/"			{return DIV;}
"%"			{return MOD;}

"||"		{return LOGIC_OR;}
"&&"		{return LOGIC_AND;}
"!"			{return LOGIC_NOT;}

"|"			{return BITWISE_OR;}
"^"			{return BITWISE_XOR;}
"&"			{return BITWISE_AND;}
"~"			{return BITWISE_NOT;}
"<<"		{return BITWISE_SHIFT_LEFT;}
">>"		{return BITWISE_SHIFT_RIGHT;}

">="		{return GR_EQ;}
">"			{return GR;}
"<="		{return SM_EQ;}
"<"			{return SM;}
"!="		{return NOT_EQ;}
"=="		{return EQ;}

"("			{return OPEN_BRACKET;}
")"			{return CLOSE_BRACKET;}

"{"			{return OPEN_PARANTH;}
"}"			{return CLOSE_PARANTH;}

"if"		{return IF;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"for"		{return FOR;}
"switch"	{return SWITCH;}
"case"		{return CASE;}
"default"	{return DEFAULT;}
"repeat"	{return REPEAT;}
"until"		{return UNTIL;}



[ \t\n]           ;
[0-9]+\.[0-9]+ { 
	yylval.fval = atof(yytext);
	//cout<< "float from lex is " << yylval.fval <<endl;	
	return FLOAT; 
}

[0-9]+      {
	yylval.ival = atoi(yytext); 
	//cout<< "int from lex is " << yylval.ival <<endl;
	return INT; 
}

i\_[a-zA-Z\_][a-zA-Z0-9\_]*	{
	yylval.idval = strdup(yytext);
	//cout<< "Id from lex is " << yylval.idval <<endl;
	return INT_ID;
}

f\_[a-zA-Z\_][a-zA-Z0-9\_]*	{
	yylval.idval = strdup(yytext);
	//cout<< "Id from lex is " << yylval.idval <<endl;
	return FLOAT_ID;
}

s\_[a-zA-Z\_][a-zA-Z0-9\_]*	{
	yylval.idval = strdup(yytext);
	//cout<< "Id from lex is " << yylval.idval <<endl;
	return STR_ID;
}

b\_[a-zA-Z\_][a-zA-Z0-9\_]*	{
	yylval.idval = strdup(yytext);
	//cout<< "Id from lex is " << yylval.idval <<endl;
	return BOOL_ID;
}

[a-zA-Z0-9]+      {
	// we have to copy because we can't rely on yytext not changing underneath us:
	yylval.sval = strdup(yytext);
	return STRING;
}


.                ;
%%