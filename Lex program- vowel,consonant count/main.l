//Prajwal pp b21cs1242
//Lex program- vowel consonant count
% {
    #include<stdio.h>

    int vowel_count = 0;
    int consonant_count = 0; %
} %
% [aeiouAEIOU] {
    vowel_count++;
}
[a - zA - Z] {
    consonant_count++;
}
[\t] + {
    ;
}
. | \n {
    return 0;
} %
%
int main() {
    printf("Enter a string : ");
    yylex();
    printf("\nTotal number of vowels : %d\n", vowel_count);
    printf("Total number of consonants : %d", consonant_count);
    return 0;
}
int yywrap() {
    return 1;
}
/*OUTPUT
Hello my name is faris
Total number of vowels:7
Total number of consonants:11
*/
