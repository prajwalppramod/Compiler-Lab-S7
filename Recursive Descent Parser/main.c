//Prajwal pp b21cs1242
//Recursive descent parser
#include<stdio.h>
#include<stdlib.h>

char input[20];
int i = 0, error = 0;
int S();
int L();
int Lprime();
void main() {
    printf("Recursive Descent Parser\n");
    printf("Enter an input string : \t");
    fgets(input, sizeof(input), stdin);
    printf("%s\n", input);
    S();
    if (error == 0) {
        printf("String Accepted");
    } else {
        printf("String rejected");
    }
}
int L() {
    if (S() == 1) {
        printf("The char is %c\n", input[i]);
        if (Lprime() == 1) {
            printf("The char is %c\n", input[i]);
            printf("L' true\n");
            //i++;
            return 1;
        } else {
            error = 1;
            return 0;
        }
    }
}
int Lprime() {
    if (input[i] == ',') {
        printf("The char is %c\n", input[i]);
        printf(", true\n");
        i++;
        if (S() == 1) {
            printf("The char is %c\n", input[i]);
            printf("S true\n");
            //i++;
            if (Lprime() == 1) {
                printf("The char is %c\n", input[i]);
                printf("L' true\n");
                return 1;
            }
        }
    } else {
        return 1;
    }
}
int S() {
    printf("The char is %c\n", input[i]);
    if (input[i] == '(') {
        printf("The char is %c\n", input[i]);
        printf("( true\n");
        i++;
        if (L() == 1) {
            printf("The char is %c\n", input[i]);
            printf("L true\n");
            //i++;
            printf("The char is %c\n", input[i]);
            if (input[i] == ')') {
                printf("The char is %c\n", input[i]);
                printf(") true\n");
                i++;
                error = 0;
                return 1;
            } else {
                error = 1;
                return 0;
            }
        }
    } else if (input[i] == 'a') {
        printf("The char is %c\n", input[i]);
        printf("a true\n");
        i++;
        return 1;
    } else {
        return 0;
    }
}