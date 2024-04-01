#pragma once

typedef struct binomialHeapInt binomialHeap;
typedef struct binomialHeapList binomialHeapList;

struct binomialHeapInt{
    int degree;
    int value;
    int prior;

    binomialHeap *next;
    binomialHeap *previous;
    binomialHeap *right;

};
struct binomialHeapList{
    int size;
    binomialHeap *firstHeap;
    binomialHeap *lastHeap;
};

binomialHeapList *createBinHeapList();
binomialHeap *returnBinHeap(binomialHeapList *heapList, int degree);
void *addBinHeap(binomialHeapList *heapList, binomialHeap *binHeap);

//Нужно реализовать по заданию

binomialHeap *createBinHeap(int value, int prior);
void deleteBinHeap(binomialHeap *binHeap);

void insertBinHeap(binomialHeapList *binHeapIn, int value, int prior);
void extractMinBinHeap(binomialHeap *binHeap);
void deleteElemBinHeap(binomialHeap *binHeap, int index);
void decreaseKeyBinHeap(binomialHeapList *binHeapList, int index, int prior);
binomialHeapList *mergeBinHeap(binomialHeapList *binHeapA, binomialHeapList *binHeapB);

int peekMinBinHeap(binomialHeapList *binHeapList);

// доп методы
binomialHeap* connect(binomialHeap *binHeap1, binomialHeap *binHeap2);

void siftingUp(binomialHeap *binHeap, int elem);

void swap(binomialHeap *binHeap, int elem);

