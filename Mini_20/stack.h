#pragma once

typedef  struct  stackElemInt stackElem;
typedef  struct  stackInt MinStack;

struct stackElemInt{
    int value;
    int min;
    struct  stackElemInt* previousElement;
};

struct stackInt{
    struct  stackElemInt* LastElement;
};

MinStack* minStackCreate();

void minStackPush(MinStack* obj, int val);

void minStackPop(MinStack* obj);

int minStackTop(MinStack* obj);

int minStackGetMin(MinStack* obj);

void minStackFree(MinStack* obj);

/*
void pushEnd(stack *_stack, int elem);

void pushBegin(stack *_stack, int elem);

void pop(stack *_stack);

int top(stack *_stack);

int getMin(stack *_stack);
 */