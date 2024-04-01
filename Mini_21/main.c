#include <stdio.h>
#include "binomialHeap.h"

int main() {
    binomialHeapList* test = createBinHeapList();
    insertBinHeap(test, 1,1);
    insertBinHeap(test, 2,2);
    insertBinHeap(test, 3,3);
    insertBinHeap(test, 4,4);

    binomialHeapList* test2 = createBinHeapList();
    insertBinHeap(test, 5,5);
    insertBinHeap(test,6 ,6);
    insertBinHeap(test2, 7,7);
    insertBinHeap(test2, 8,8);

    binomialHeapList* test3 = createBinHeapList();
    insertBinHeap(test3, 9,9);
    insertBinHeap(test3, 10,10);
    insertBinHeap(test3, 53,-11);
    insertBinHeap(test3, 12,12);
    binomialHeapList *an = mergeBinHeap(test,test2);
    binomialHeapList *an2 = mergeBinHeap(an,test3);
    decreaseKeyBinHeap(an2, 9,2);
    return 0;
}
