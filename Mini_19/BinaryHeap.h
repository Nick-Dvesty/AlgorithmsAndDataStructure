#pragma once

typedef struct{
    int value;
    int prior;
}IntPrior;

typedef struct{
    IntPrior* array;
    int index;
    int size;
}BinaryHeap;

BinaryHeap* heapCreate();
BinaryHeap* heapDelete();

void heapInsert(BinaryHeap* heap, int prior, int value);
int heapPeek_max(BinaryHeap* heap);
int heapExtractMax(BinaryHeap* heap);

void swap(BinaryHeap* heap, int index1, int index2);
void shiftDown(BinaryHeap* heap, int index);
void shiftUp(BinaryHeap* heap, int index);

void increaseArray(BinaryHeap* heap);
void reduceArray(BinaryHeap* heap);


