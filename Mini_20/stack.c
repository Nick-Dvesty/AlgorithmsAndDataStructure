#include "stack.h"
#include <malloc.h>

MinStack* minStackCreate(){
    MinStack* newStack = malloc(sizeof (MinStack));
    newStack->LastElement = NULL;
    return newStack;
}

void minStackPush(MinStack* obj, int val){
    stackElem *newElem = malloc(sizeof(stackElem));
    newElem->value = val;
    if(obj->LastElement != NULL){
        newElem->previousElement = obj->LastElement;
        if(val < obj->LastElement->min){
            newElem->min = val;
        }
        else {
            newElem->min = obj->LastElement->min;
        }
    } else{
        newElem->min = val;
        newElem->previousElement = NULL;
    }
    obj->LastElement = newElem;
}

void minStackPop(MinStack* obj){
    if (obj->LastElement != NULL){
        stackElem *lastElem = obj->LastElement;
        obj->LastElement = obj->LastElement->previousElement;
        free(lastElem);
    }
}

int minStackTop(MinStack* obj) {
    int answer = obj->LastElement->value;
    return answer;
}

int minStackGetMin(MinStack* obj) {
    int answer = obj->LastElement->min;
    return answer;
}

void minStackFree(MinStack* obj) {
    while (obj->LastElement != NULL){
        minStackPop(obj);
    }
    free(obj);
}