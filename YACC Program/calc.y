//prajwal pp b21cs1242
//YACC Program to identify valid expressions


%{
#include <stdio.h>
int yylex();
void yyerror(const char *s);
%}
%token NUMBER
%token INVALID
%%
Expr : Expr '+' Term 
	| Expr '-' Term 
	| Term ;
Term : Term '*' Factor 
	| Term '/' Factor 
	| Factor ;
Factor: '(' Expr ')' 
	| NUMBER; 
%% 
void yyerror(const char *s) {}
int main(void) {
	printf("Enter Expression:");
	if (yyparse() == 0) {printf("It is valid\n");}
	else printf("It is not Valid\n");
}

/*calc.l
%{
#include "y.tab.h"
%}
%%
[0-9]+		{ yylval = atoi(yytext); return NUMBER; }
"+"		{ return '+'; }
"-"		{ return '-'; }
"*"		{ return '*'; }
"/"		{ return '/'; }
"("		{ return '('; }
")"		{ return ')'; }
\n 	        { return 0; }
." "		{ return INVALID; }

%%  */

/*OUTPUT
Enter Expression:5*6+(10-6)/2
It is valid */
