#include "stack.h"
#include <malloc.h>

Stack* stackCreate(){
    Stack* newStack = malloc(sizeof (Stack));
    newStack->LastElement = NULL;
    return newStack;
}

void stackPush(Stack* obj, int val, int prior){
    StackElem *newElem = malloc(sizeof(StackElem));
    newElem->value = val;
    newElem->prior = prior;
    if(obj->LastElement != NULL){
        newElem->previousElement = obj->LastElement;
    } else{
        newElem->previousElement = NULL;
    }
    obj->LastElement = newElem;
}

void stackPop(Stack* obj){
    if (obj->LastElement != NULL){
        StackElem *lastElem = obj->LastElement;
        obj->LastElement = obj->LastElement->previousElement;
        free(lastElem);
    }
}

int stackTop(Stack* obj) {
    int answer = obj->LastElement->value;
    return answer;
}

void stackFree(Stack* obj) {
    while (obj->LastElement != NULL){
        stackPop(obj);
    }
    free(obj);
}