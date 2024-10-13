//Prajwal pp b21cs1242
//Lex program- vowel consonant count
%{
    #include <stdio.h>

    int vowel_count = 0;
    int consonant_count = 0;
%}

%%

[aeiouAEIOU] {
    vowel_count++;
}

[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {
    consonant_count++;
}

[ \t\n] {
    /* Ignore whitespace and newline */
}

. {
    /* Ignore other characters */
}

%%

int main() {
    printf("Enter a string: ");
    yylex();
    printf("\nTotal number of vowels: %d\n", vowel_count);
    printf("Total number of consonants: %d\n", consonant_count);
    return 0;
}

int yywrap() {
    return 1;
}

/*OUTPUT
Hello my name is prajwal
Total number of vowels:7
Total number of consonants:13
*/
