//Prajwal pp b21cs1242
//Shift Reduce Parser
#include<stdio.h>
#include<string.h>
#include <stdlib.h>

struct Production {
    char left[10];
    char right[10];
}
rules[10];
int rule_count, stack_length, substring_length, stack_top;
char
temp[10], temp2[10], ch[2], input[20], stack[20], * substring, * substring2, * token
1, * token3, * token2;
char operators[] = {
    '+',
    '-',
    '/',
    '%',
    '*',
    '<',
    '>',
    '^',
    '='
};
int isOperator(char c) {
    for (int k = 0; k < 10; k++) {
        if (c == operators[k]) {
            return k;
        }
    }
    return -1;
}
char getOperatorfromStack() {
    stack_length = strlen(stack);
    for (int m = stack_length; m >= 0; m--) {
        //printf(" %c\t",stack[m]);
        if (isOperator(stack[m - 1]) > -1) {
            //printf("Operator in stack is %c\n",stack[m-1]);
            return stack[m - 1];
            break;
        } else if (stack[m - 1] == 'd' && stack[m - 2] == 'i') {
            return 'z';
            break;
        }
    }
    printf("\n");
}
int checkPrecedence(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
        break;
    case '/':
    case '*':
        return 2;
        break;
    case '^':
        return 3;
        break;
    case 'z':
        return 4;
        break;
    default:
        return 0;
    }
}
void printStack() {
    printf("Stack Elements are :\t");
    stack_length = strlen(stack);
    for (int m = stack_length; m >= 0; m--) {
        printf(" %c ", stack[m]);
    }
    printf("\n");
}
void main() {
        printf("Enter the number of production rules :\t");
        scanf("%d", & rule_count);
        printf("Enter each production rule in the format (left->right) :\
            n ");
            for (int c = 0; c < rule_count; c++) {
                scanf("%s", & temp);
                token1 = strtok(temp, "->");
                token2 = strtok(NULL, "->");
                strcpy(rules[c].left, token1);
                if (token3 = strtok(NULL, "-")) {
                    strcpy(temp2, token3);
                    strcat(token2, "-");
                    strcat(token2, temp2);
                    strcpy(rules[c].right, token2);
                } else {
                    strcpy(rules[c].right, token2);
                }
            }
            for (int f = 0; f < rule_count; f++) {
                printf("\t%s->%s\n", rules[f].left, rules[f].right);
            }
            printf("Enter the input string : \n"); scanf("%s", input); printf("\n"); stack[0] = '\0'; printf("Stack\tInput\tAction\n"); int flag = 0; int i = 0; int j = 0;
            while (1) {
                if (i < strlen(input)) {
                    //ch[0] = input[i];
                    option
                    ch[0] = '\0';
                    j = 0;
                    if (input[i] >= 'a' && input[i] <= 'z') {
                        while (i < strlen(input) && input[i] >= 'a' &&
                            input[i] <= 'z') {
                            ch[j++] = input[i++];
                        }
                    } else {
                        ch[j++] = input[i++];
                    }
                    substring = strstr(stack, rules[j].right);
                    if (substring != NULL) {
                        if (checkPrecedence(getOperatorfromStack()) < checkPrecedence(input[i])) {
                            printf("\nShift Reduce Conflict\n");
                            //exit(1);
                        }
                    }
                    ch[j] = '\0';
                    strcat(stack, ch);
                    printf("$%s\t", stack);
                    for (int k = i; k < strlen(input); k++) {
                        printf("%c", input[k]);
                    }
                    printf("$");
                    printf("\tShift\n");
                    if (strcmp(stack, rules[0].left) == 0 && i == strlen(input)) {
                        printf("Input Accepted\n");
                        flag = 1;
                        break;
                    }
                }
                for (j = 0; j < rule_count; j++) {
                    substring = strstr(stack, rules[j].right);
                    if (substring != NULL) {
                        if (checkPrecedence(getOperatorfromStack()) < checkPrecedence(input[i])) {
                            printf("\nShift Reduce Conflict\n\n");
                            goto shift;
                            //exit(1);
                        }
                        /*for(int g = j+1;g<rule_count;g++){
                        substring2 = strstr(stack,rules[j].right);
                        if(substring2!=NULL){
                        printf("Reduce Reduce Conflict\n");
                        exit(1);
                        }
                        }*/
                        //printf("Substring is %s\n",substring);
                        //printStack();
                        //printf("Operator in Stack is
                        %
                        c\ n ",getOperatorfromStack());
                        stack_length = strlen(stack);
                        substring_length = strlen(substring);
                        stack_top = stack_length - substring_length;
                        stack[stack_top] = '\0';
                        strcat(stack, rules[j].left);
                        printf("$%s\t", stack);
                        for (int k = i; k < strlen(input); k++) {
                            printf("%c", input[k]);
                        }
                        printf("$");
                        printf("\tReduce %s->%s\n", rules[j].left, rules[j].right);
                        j = -1;
                        if (strcmp(stack, rules[0].left) == 0 && i == strlen(input)) {
                            printf("Input Accepted\n");
                            break;
                        }
                    }
                }
                if (flag != 1) {
                    if (strcmp(stack, rules[0].left) == 0 && i == strlen(input)) {
                        printf("Input Accepted\n");
                        break;
                    }
                }
                if (i == strlen(input)) {
                    printf("Input Rejected\n");
                    break;
                }
            }
        }
        /* OUTPUT
        Enter the number of production rules : 3
        Enter each production rule in the format (left->right) :
        E->3E3
        E->2E2
        E->4
        Enter the input string :
        32423
        Stack Input Action
        $3 2423$ Shift
        $32 423$ Shift
        $324 23$ Shift
        $32E 23$ Reduce E->4
        $32E2 3$ Shift
        $3E 3$ Reduce E->2E2
        $3E3 $ Shift
        $E $ Reduce E->3E3
        Input Accepted
        Enter the number of production rules : 3
        Enter each production rule in the format (left->right) :
        E->3E3
        E->2E2
        E->4
        Enter the input string :
        322323
        Stack Input Action
        $3 22323$ Shift
        $32 2323$ Shift
        $322 323$ Shift
        $3223 23$ Shift
        $32232 3$ Shift
        $322323 $ Shift
        Input Rejected
        Enter the number of production rules : 4
        Enter each production rule in the format (left->right) :
        S->(L)
        S->a
        L->L,S
        L->S
        S->(L)
        S->a
        L->L,S
        L->S
        Enter the input string :
        ((a,a),a)
        Stack Input Action
        $( (a,a),a)$ Shift
        $(( a,a),a)$ Shift
        $((a ,a),a)$ Shift
        $((S ,a),a)$ Reduce S->a
        $((L ,a),a)$ Reduce L->S
        $((L, a),a)$ Shift
        $((L,a ),a)$ Shift
        $((L,S ),a)$ Reduce S->a
        $((L ),a)$ Reduce L->L,S
        $((L) ,a)$ Shift
        $(S ,a)$ Reduce S->(L)
        $(L ,a)$ Reduce L->S
        $(L, a)$ Shift
        $(L,a )$ Shift
        $(L,S )$ Reduce S->a
        $(L )$ Reduce L->L,S
        $(L) $ Shift
        $S $ Reduce S->(L)
        Input Accepted
        */