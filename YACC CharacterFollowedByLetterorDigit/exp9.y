//Prajwal PP B21CS1242
//YACC Program to recognize any character followed by letters and digits

%{
#include<stdio.h>
#include<stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token ALNUM
%token SYMBOL

%%
S: SYMBOL A | ALNUM A;
A: ALNUM A | ALNUM;
%%
void yyerror(const char *s) {}

int main(void){
	printf("Enter Input: ");
	if (yyparse() == 0)printf("It is valid\n");
	else printf("It is not valid\n");
	return 0;
}

/*OUTPUT
Enter Input: _178a
It is valid
Enter Input: _@543
It is not valid*/
