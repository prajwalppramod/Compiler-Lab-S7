//Prajwal pp b21cs1242
//Shift Reduce Parser
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rule {
    char left[20];
    char right[20];
} rules[10];

int main() {
    int numRules, stackPos = 0;
    char inputStr[30], parsingStack[35];
    parsingStack[stackPos++] = '$';
    parsingStack[stackPos] = '\0';

    printf("Enter the number of grammar rules: ");
    scanf("%d", &numRules);
    getchar(); 

    printf("Provide the grammar rules:\n");
    for (int i = 0; i < numRules; i++) {
        scanf("%[^-]s", rules[i].left); 
        getchar(); 
        getchar(); 
        scanf("%[^\n]s", rules[i].right);
        getchar();
    }

    printf("\nEnter the input string to parse: ");
    scanf("%[^\n]s", inputStr);
    getchar();

    printf("\n");

    char *currentInput = inputStr;

    printf("%-12s %-12s %-12s\n", "STACK", "REMAINING", "ACTION");

    while (*currentInput != '\0') {
        int ruleApplied;

        parsingStack[stackPos++] = *currentInput;
        parsingStack[stackPos] = '\0';
        currentInput++;

        printf("%-12s %-12s %-12s\n", parsingStack, currentInput, "Shift");

        do {
            ruleApplied = 0;
            for (int j = 0; j < numRules; j++) {
                int ruleLen = strlen(rules[j].right);
                if (strcmp(&parsingStack[1], rules[0].left) != 0 && stackPos >= ruleLen &&
                    strncmp(&parsingStack[stackPos - ruleLen], rules[j].right, ruleLen) == 0) {
                    
                    char replaced[20];
                    strcpy(replaced, &parsingStack[stackPos - ruleLen]);
                    stackPos -= ruleLen; 
                    strcpy(&parsingStack[stackPos], rules[j].left); 
                    stackPos += strlen(rules[j].left);
                    parsingStack[stackPos] = '\0';

                    printf("%-12s %-12s %-12s %s -> %s\n", parsingStack, currentInput, "Reduce", replaced, rules[j].left);
                    ruleApplied = 1;
                    break;
                }
            }
        } while (ruleApplied);
    }

    if (strcmp(&parsingStack[1], rules[0].left) == 0 && stackPos == 2) {
        printf("%-12s %-12s %-12s\n", parsingStack, currentInput, "ACCEPT");
    } else {
        printf("%-12s %-12s %-12s\n", parsingStack, currentInput, "REJECT");
    }

    return 0;
}
/*
Enter the number of grammar rules: 3
Provide the grammar rules:
S->S+S
S->S*S
S->i

Enter the input string to parse: i+i+i

STACK        REMAINING    ACTION      
$            i+i+i        Shift       
$i           +i+i         Shift       
$S           +i+i         Reduce      i -> S
$S+          i+i          Shift       
$S+i         +i           Shift       
$S+S         +i           Reduce      i -> S
$S           +i           Reduce      S+S -> S
$S+          i            Shift       
$S+i                      Shift       
$S+S                      Reduce      i -> S
$S                        Reduce      S+S -> S
$S                        ACCEPT   */
