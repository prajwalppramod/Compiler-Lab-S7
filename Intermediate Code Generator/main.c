//Prajwal pp b21cs1242
//Intermediate Code Generator
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_EXPRE_LEN 100
#define MAX_TEMP_VARS 50
char expr[MAX_EXPRE_LEN];
char temp_vars[MAX_TEMP_VARS][4];
int temp_var_count = 0;
FILE * fp;
char * new_temp_var() {
    if (temp_var_count >= MAX_TEMP_VARS) {
        printf("Error : Too many temporary variables\n");
        exit(1);
    }
    sprintf(temp_vars[temp_var_count], "T%d", temp_var_count + 1);
    return temp_vars[temp_var_count++];
}
int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}
char * generate_code(char * expr) {
    int len = strlen(expr);
    int paren_count = 0;
    int op_pos = -1;
    int min_precedence = 3;
    for (int i = len - 1; i >= 0; i--) {
        if (expr[i] == ')') paren_count++;
        else if (expr[i] == '(') paren_count--;
        else if (paren_count == 0) {
            int prec = precedence(expr[i]);
            if (prec > 0 && prec <= min_precedence) {
                min_precedence = prec;
                op_pos = i;
            }
        }
    }
    if (op_pos == -1) {
        if (expr[0] == '(' && expr[len - 1] == ')') {
            expr[len - 1] = '\0';
            return generate_code(expr + 1);
        }
        return expr;
    }
    char op = expr[op_pos];
    expr[op_pos] = '\0';
    char * left = generate_code(expr);
    char * right = generate_code(expr + op_pos + 1);
    char * temp = new_temp_var();
    printf("%s := %s %c %s\n", temp, left, op, right);
    fprintf(fp, "%s := %s %c %s\n", temp, left, op, right);
    //fclose(fp);
    return temp;
}
int main() {
    fp = fopen("output.txt", "w");
    printf("Intermediate Code Generation\n");
    printf("Enter the expression :\t");
    if (scanf("%99s", expr) != 1) {
        printf("Error Reading input");
        return 1;
    }
    printf("The intermediate code : \n");
    char * assignment = strchr(expr, '=');
    if (assignment) {
        * assignment = '\0';
        char * lhs = expr;
        char * rhs = assignment + 1;
        char * result = generate_code(rhs);
        printf("%s:=%s\n", lhs, result);
        fprintf(fp, "%s:=%s\n", lhs, result);
    } else {
        generate_code(expr);
    }
    return 0;
}
/*OUTPUT
Intermediate Code Generation
w=(a+b)/(c+d)
t1=a+b
t2=c+d
t3=t1/t2
w=t3
*/