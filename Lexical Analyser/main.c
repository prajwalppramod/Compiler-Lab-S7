#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isTokenPresent(char token[15], char tokensArray[20][20], int count) {
    for (int k = 0; k < count; k++) {
        if (strcmp(tokensArray[k], token) == 0) {
            return -1;
        }
    }
    return 1;
}

void main() {
    char temp[15], identifiers[20][20], keywords[20][20], operators[20][20], constants[20][20];
    char currentChar;
    FILE *inputFile, *symbolFile;
    int pos = 0, identifierCount = 0, keywordCount = 0, operatorCount = 0, constantCount = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Unable to open file\n");
        return;
    }

    while ((currentChar = fgetc(inputFile)) != EOF) {
    parse:
        if (currentChar == '\n' || currentChar == '\t' || currentChar == '{' || currentChar == ' ' || currentChar == '(' || currentChar == '}' || currentChar == ')' || currentChar == ';') {
            continue;
        }
        if (currentChar >= '0' && currentChar <= '9') {
            pos = 0;
            temp[pos++] = currentChar;
            while ((currentChar = fgetc(inputFile)) >= '0' && currentChar <= '9' && currentChar != ';') {
                temp[pos++] = currentChar;
            }
            temp[pos] = '\0';
            pos = 0;
            if (isTokenPresent(temp, constants, constantCount) == 1) {
                strcpy(constants[constantCount], temp);
                constantCount++;
            }
            goto parse;

        } else if (currentChar == 'i') {
            temp[pos++] = currentChar;
            currentChar = fgetc(inputFile);
            if (currentChar == 'f') {
                temp[pos++] = currentChar;
                currentChar = fgetc(inputFile);
                if (currentChar == ' ' || currentChar == '(') {
                    temp[pos] = '\0';
                    pos = 0;
                    if (isTokenPresent(temp, keywords, keywordCount) == 1) {
                        strcpy(keywords[keywordCount], temp);
                        keywordCount++;
                    }
                } else {
                    goto iden;
                }
            } else if (currentChar == 'n') {
                temp[pos++] = currentChar;
                currentChar = fgetc(inputFile);
                if (currentChar == 't') {
                    temp[pos++] = currentChar;
                    currentChar = fgetc(inputFile);
                    if (currentChar == ' ' || currentChar == '(' || currentChar == '=') {
                        temp[pos] = '\0';
                        pos = 0;
                        if (isTokenPresent(temp, keywords, keywordCount) == 1) {
                            strcpy(keywords[keywordCount], temp);
                            keywordCount++;
                        }
                        if (currentChar == '=') {
                            goto ops;
                        }
                    } else {
                        goto iden;
                    }
                } else {
                    goto iden;
                }
            } else {
                goto iden;
            }
        } else if (currentChar == 'e') {
            temp[pos++] = currentChar;
            currentChar = fgetc(inputFile);
            if (currentChar == 'l') {
                temp[pos++] = currentChar;
                currentChar = fgetc(inputFile);
                if (currentChar == 's') {
                    temp[pos++] = currentChar;
                    currentChar = fgetc(inputFile);
                    if (currentChar == 'e') {
                        temp[pos++] = currentChar;
                        currentChar = fgetc(inputFile);
                        if (currentChar == ' ' || currentChar == '(' || currentChar == '=' || currentChar == '\n') {
                            temp[pos] = '\0';
                            pos = 0;
                            if (isTokenPresent(temp, keywords, keywordCount) == 1) {
                                strcpy(keywords[keywordCount], temp);
                                keywordCount++;
                            }
                            if (currentChar == '=') {
                                goto ops;
                            }
                        } else {
                            goto iden;
                        }
                    } else {
                        goto iden;
                    }
                } else {
                    goto iden;
                }
            } else {
                goto iden;
            }
        } else if (currentChar == 'v') {
            temp[pos++] = currentChar;
            currentChar = fgetc(inputFile);
            if (currentChar == 'o') {
                temp[pos++] = currentChar;
                currentChar = fgetc(inputFile);
                if (currentChar == 'i') {
                    temp[pos++] = currentChar;
                    currentChar = fgetc(inputFile);
                    if (currentChar == 'd') {
                        temp[pos++] = currentChar;
                        currentChar = fgetc(inputFile);
                        if (currentChar == ' ' || currentChar == '(' || currentChar == '=') {
                            temp[pos] = '\0';
                            pos = 0;
                            if (isTokenPresent(temp, keywords, keywordCount) == 1) {
                                strcpy(keywords[keywordCount], temp);
                                keywordCount++;
                            }
                            if (currentChar == '=') {
                                goto ops;
                            }
                        } else {
                            goto iden;
                        }
                    } else {
                        goto iden;
                    }
                } else {
                    goto iden;
                }
            } else {
                goto iden;
            }
        } else if (currentChar == '=') {
        ops:
            temp[pos++] = currentChar;
            currentChar = fgetc(inputFile);
            if (currentChar == '=' || currentChar == '+' || currentChar == '-') {
                temp[pos++] = currentChar;
                temp[pos] = '\0';
                pos = 0;
                if (isTokenPresent(temp, operators, operatorCount) == 1) {
                    strcpy(operators[operatorCount], temp);
                    operatorCount++;
                }

            } else {
                temp[pos] = '\0';
                pos = 0;
                if (isTokenPresent(temp, operators, operatorCount) == 1) {
                    strcpy(operators[operatorCount], temp);
                    operatorCount++;
                }
                goto parse;
            }
        } else {
        iden:
            temp[pos++] = currentChar;

            while ((currentChar = fgetc(inputFile)) != ' ' && currentChar != '\n' && currentChar != '(' && currentChar != ')' && currentChar != ';' && currentChar != ',' && currentChar != '\t' && currentChar != '{' && currentChar != '}' && currentChar != EOF && currentChar != '=') {
                temp[pos++] = currentChar;
            }
            temp[pos] = '\0';
            pos = 0;
            if (isTokenPresent(temp, identifiers, identifierCount) == 1) {
                strcpy(identifiers[identifierCount], temp);
                identifierCount++;
            }

            if (currentChar == '=') {
                goto ops;
            }
        }
    }

    fclose(inputFile);
    printf("\nKeywords\n----------------------------\n");
    for (int m = 0; m < keywordCount; m++) {
        printf("%s\n", keywords[m]);
    }

    printf("\nIdentifiers\n----------------------------\n");
    symbolFile = fopen("SymbolTable.txt", "w");
    for (int m = 0; m < identifierCount; m++) {
        printf("%s\n", identifiers[m]);
        fprintf(symbolFile, "%s\n", identifiers[m]);
    }
    fclose(symbolFile);

    printf("\nConstants\n----------------------------\n");
    for (int m = 0; m < constantCount; m++) {
        printf("%s\n", constants[m]);
    }

    printf("\nOperators\n----------------------------\n");
    for (int m = 0; m < operatorCount; m++) {
        printf("%s\n", operators[m]);
    }
}
/*OUTPUT
void main() {
    int x, a = 0;
    if (a == 0) {
        x = 0;
    } else {
        x = 1;
    }
}
*/
