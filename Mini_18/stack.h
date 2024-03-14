#pragma once

typedef  struct  stackElemInt StackElem;
typedef  struct  stackInt Stack;

struct stackElemInt{
    int value;
    int prior;
    struct  stackElemInt* previousElement;
};

struct stackInt{
    struct  stackElemInt* LastElement;
};

Stack* stackCreate();

void stackPush(Stack* obj, int val, int prior);

void stackPop(Stack* obj);

int stackTop(Stack* obj);

void stackFree(Stack* obj);
