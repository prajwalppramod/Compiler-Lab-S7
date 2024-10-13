//Prajwal PP B21CS1242
//Lexical Analyzer Using Lex Tool


%{
%}
PUNCTUATION ")"|"("|"{"|"}"|;
%%
int {
	printf("\nKeyword->int\n");
}
if {
	printf("\nKeyword->if\n");	
}
else {
	printf("\nKeyword->else\n");	
}
printf {
	printf("\nKeyword->printf\n");	
}
void {
	printf("\nKeyword->void\n");
}
main {
	printf("\nKeyword->main\n");
}
[_a-zA-Z][a-zA-Z0-9]* {
	printf("\nIdentifier->%s\n",yytext);
}
[0-9] {
	printf("\nDigit->%c\n",yytext[0]);
}	
[+*/<>=] {
	printf("\nOperator->%c\n",yytext[0]);
}
["][a-zA-Z0-9]*["] {		
	printf("\nString Literal->%s\n",yytext);
}
{PUNCTUATION} {
	printf("\nPunctuator->%c\n",yytext[0]);
}	
. {
	printf(" ");
}								
%%
int main(){
	yyin=fopen("input.txt","r");
	yylex();
	return 0;
}
int yywrap(){
	return -1;
}

/*lex exp10.l
gcc lex.yy.c
./a.out*/

/*OUTPUT
input.txt
int a=6;
int as=4;
if(a>4){
	printf("Hello");
	printf("Hi");
}
b=a+6;
print(b)


Keyword->int
 
Identifier->a

Operator->=

Digit->6

Punctuator->;


Keyword->int
 
Identifier->as

Operator->=

Digit->4

Punctuator->;


Keyword->if

Punctuator->(

Identifier->a

Operator->>

Digit->4

Punctuator->)

Punctuator->{

 
Keyword->printf

Punctuator->(

String Literal->"Hello"

Punctuator->)

Punctuator->;

 
Keyword->printf

Punctuator->(

String Literal->"Hi"

Punctuator->)

Punctuator->;


Punctuator->}


Identifier->b

Operator->=

Identifier->a

Operator->+

Digit->6

Punctuator->;


Identifier->print

Punctuator->(

Identifier->b

Punctuator->)*/

