#include <stdio.h>
#include "stack.h"

int main() {
    MinStack* st =  minStackCreate();
    minStackPush(st, 3);
    minStackPush(st, 4);
    minStackPop(st);
    minStackPush(st, 5);
    minStackPush(st, 6);
}
