//Prajwal pp b21cs1242
//Lex program - word line character count
% {
    #include<stdio.h>
    int lcase = 0,
    ucase = 0,
    words = 0,
    digits = 0,
    lines = 0,
    schar = 0; %
} %
% [\n] lines++, words++;
[\t] words++;
[0 - 9] digits++;
[a - z] lcase++;
[A - Z] ucase++;
.schar++; %
%
int main() {
    yyin = fopen("input1.txt", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    fprintf(yyout, "The FILE contains...\n");
    fprintf(yyout, " -->%d digits\n", digits);
    fprintf(yyout, " -->%d lowercase letters\n", lcase);
    fprintf(yyout, " -->%d uppercase letters\n", ucase);
    fprintf(yyout, " -->%d words\n", words);
    fprintf(yyout, " -->%d lines\n", lines);
    fprintf(yyout, " -->%d special characters\n", schar);
    fclose(yyin);
    fclose(yyout);
}
int yywrap() {
    return 1;
}
/*OUPUT:
INPUT.TXT
Hi welcome to Lex Programming!!!{
This is 1985.
OUTPUT.TXT
The FILE contains...
-->4 digits
-->28 lowercase letters
-->4 uppercase letters
-->8 words
-->2 lines
-->4 special characters
*/
