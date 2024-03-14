#include <stdio.h>
#include "stack.h"
#define SIZE_STRING 100
int main(){
    char expression[SIZE_STRING];
    char answer[SIZE_STRING * 2];
    Stack* stack = stackCreate();
    int prior;
    int dopPrior = 0;
    int j = 0;
    printf("Enter the expression in infix notation(without spaces): ");
    scanf("%s", expression);
    for (int i = 0; i < SIZE_STRING; i++) {
        if (expression[i] == '|' && expression[i + 1] == '|') {
            expression[i] = 'o';
            expression[i + 1] = ' ';
        } else if (expression[i] == '&' && expression[i + 1] == '&') {
            expression[i] = 'a';
            expression[i + 1] = ' ';
        } else if (expression[i] == '!' && expression[i + 1] == '=') {
            expression[i] = 'n';
            expression[i + 1] = ' ';
        } else if (expression[i] == '=' && expression[i + 1] == '=') {
            expression[i] = 'e';
            expression[i + 1] = ' ';
        } else if (expression[i] == '<' && expression[i + 1] == '<') {
            expression[i] = 'l';
            expression[i + 1] = ' ';
        } else if (expression[i] == '>' && expression[i + 1] == '>') {
            expression[i] = 'r';
            expression[i + 1] = ' ';
        }
    }
    for (int i = 0; (i < SIZE_STRING) && (expression[i] != '\000'); i++) {
        if(expression[i] != ' '){
            prior = 0;
            if (expression[i] >= 0x30 && expression[i] <= 0x39){
                answer[j] = expression[i];
                j++;
            } else{
                if(expression[i] == '(') dopPrior += 15;
                else if(expression[i] == ')') dopPrior -= 15;
                else {
                    if (expression[i] == 'o') prior = 3;
                    else if (expression[i] == 'a') prior = 4;
                    else if (expression[i] == '|') prior = 5;
                    else if (expression[i] == '^') prior = 6;
                    else if (expression[i] == '&') prior = 7;
                    else if (expression[i] == 'n' || expression[i] == 'e') prior = 8;
                    else if (expression[i] == 'l' || expression[i] == 'r') prior = 10;
                    else if (expression[i] == '+' || expression[i] == '-') prior = 11;
                    else if (expression[i] == '*' || expression[i] == '/' || expression[i] == '%') prior = 12;
                    else if (expression[i] == '~' || expression[i] == '!') prior = 14;
                    while ((stack->LastElement != NULL) && (stack->LastElement->prior > prior + dopPrior)) {
                        answer[j++] = ' ';
                        answer[j++] = (char) stackTop(stack);
                        stackPop(stack);
                    }
                    answer[j++] = ' ';
                    stackPush(stack, expression[i], prior+ dopPrior);
                }
            }
        }
    }
    while (stack->LastElement != NULL){
        answer[j++] = ' ';
        answer[j++] = (char)stackTop(stack);
        stackPop(stack);
    }
    for (int i = 0; (i < SIZE_STRING * 2) && (answer[i] != '\000'); i++){
        switch (answer[i]) {
            case 'o':
                printf("||");
                break;
            case 'a':
                printf("&&");
                break;
            case 'n':
                printf("!=");
                break;
            case 'e':
                printf("==");
                break;
            case 'l':
                printf("<<");
                break;
            case 'r':
                printf(">>");
                break;
            default:
                printf("%c", answer[i]);
        }
    }

}


