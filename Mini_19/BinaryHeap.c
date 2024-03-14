#include "BinaryHeap.h"
#include <assert.h>
#include <malloc.h>

BinaryHeap* heapCreate(){
    BinaryHeap *heap = malloc(sizeof(BinaryHeap));
    IntPrior* array = malloc(sizeof(IntPrior));
    heap->array = array;
    heap->size = 1;
    heap->index = 0;
    return  heap;
}
void heapInsert(BinaryHeap* heap, int prior, int value){
    if(heap->size == heap->index) increaseArray(heap);
    IntPrior newElem;
    newElem.value = value;
    newElem.prior = prior;
    heap->array[heap->index] = newElem;
    shiftUp(heap, heap->index);
    heap->index++;
}
int heapPeek_max(BinaryHeap* heap){
    return heap->array[0].value;
}
int heapExtractMax(BinaryHeap* heap){
    int answer = heap->array[0].value;
    swap(heap, 0, heap->index - 1);
    heap->index--;
    shiftDown(heap, heap->index);
    if(heap->index <= heap->size / 4) reduceArray(heap);
    return  answer;
}

void swap(BinaryHeap* heap, int index1, int index2){
    assert((index1 < heap->size) && (index2 < heap->size));
    IntPrior bufer = heap->array[index1];
    heap->array[index1] = heap->array[index2];
    heap->array[index2] = bufer;
}
void shiftUp(BinaryHeap* heap, int index){
    while (index != 0){
        if(heap->array[index].prior > heap->array[(index - 1)/ 2].prior){
            swap(heap, index, (index - 1)/ 2);
            index = (index - 1)/ 2;
        } else{
            break;
        }
    }
}
void shiftDown(BinaryHeap* heap, int index){
    int i = 0;
    while ((i * 2 + 1) < index){
        if((i * 2 + 2) < index){
            if (heap->array[i * 2 + 1].prior > heap->array[i * 2 + 2].prior){
                if (heap->array[i].prior < heap->array[i * 2 + 1].prior){
                    swap(heap, i, i * 2 + 1);
                    i = i * 2 + 1;
                } else if (heap->array[i].prior < heap->array[i * 2 + 2].prior){
                    swap(heap, i, i * 2 + 2);
                    i = i * 2 + 2;
                } else break;
            } else{
                if (heap->array[i].prior < heap->array[i * 2 + 2].prior){
                    swap(heap, i, i * 2 + 2);
                    i = i * 2 + 2;
                } else if (heap->array[i].prior < heap->array[i * 2 + 1].prior){
                    swap(heap, i, i * 2 + 1);
                    i = i * 2 + 1;
                } else break;
            }
        } else{
            if (heap->array[i].prior < heap->array[i * 2 + 1].prior){
                swap(heap, i, i * 2 + 1);
                i = i * 2 + 1;
            } else break;
        }
    }
}

void increaseArray(BinaryHeap* heap){
    IntPrior* newArray = malloc(sizeof(IntPrior) * heap->size * 2);
    for (int i = 0; i < heap->size; i++) {
        newArray[i] = heap->array[i];
    }
    free(heap->array);
    heap->array = newArray;
    heap->size *= 2;
}
void reduceArray(BinaryHeap* heap){
    IntPrior* newArray = malloc(sizeof(IntPrior) * heap->size / 2);
    for (int i = 0; i < heap->index; i++) {
        newArray[i] = heap->array[i];
    }
    free(heap->array);
    heap->array = newArray;
    heap->size /= 2;
}


