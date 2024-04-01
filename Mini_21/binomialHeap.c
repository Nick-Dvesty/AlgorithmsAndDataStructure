#include <stdlib.h>
#include "binomialHeap.h"

int powInt(int a, int  b){
    int ans = 1;
    for (int i = 0; i < b; ++i) {
        ans *=a;
    }
    return ans;
}


binomialHeapList *createBinHeapList(){
    binomialHeapList *binHeapList = malloc(sizeof(binomialHeapList));
    if(binHeapList != NULL){
        binHeapList->firstHeap =NULL;
        binHeapList->lastHeap = NULL;
        binHeapList->size = 0;
        return  binHeapList;
    }
    return NULL;
}
binomialHeap *returnBinHeap(binomialHeapList *heapList, int degree){
    binomialHeap *pVoid = heapList->firstHeap;
    for (int i = 0; i < heapList->size; ++i) {
        if(pVoid->degree == degree) return pVoid;
        pVoid = pVoid->right;
    }
    return NULL;
}
void *addBinHeap(binomialHeapList *heapList, binomialHeap *binHeap){
    if(heapList->size > 0) heapList->lastHeap->right = binHeap;
    else  heapList->firstHeap = binHeap;
    heapList->lastHeap = binHeap;
    heapList->size++;
}
void *removeBinHeap(binomialHeapList *heapList){
    if(heapList->firstHeap != NULL){
        if(heapList->firstHeap == heapList->lastHeap)  heapList->lastHeap = NULL;
        heapList->firstHeap = heapList->firstHeap->right;
        heapList->size--;
    }
}




binomialHeap *createBinHeap(int value, int prior) {
    binomialHeap *binHeap = malloc(sizeof(binomialHeap));
    if (binHeap != NULL) {
        binHeap->prior = prior;
        binHeap->value = value;
        binHeap->degree = 0;
        binHeap->next = NULL;
        binHeap->previous = NULL;
        binHeap->right = NULL;
        return binHeap;
    }
    return NULL;
}

binomialHeapList *mergeBinHeap(binomialHeapList *binHeapIn, binomialHeapList *binHeapAdd) {
    binomialHeapList* answer = createBinHeapList();
    binomialHeap *pVoid = NULL;
    int maxSize;
    if(binHeapIn->lastHeap != NULL) maxSize = binHeapIn->lastHeap->degree > binHeapAdd->lastHeap->degree ? binHeapIn->lastHeap->degree + 1 : binHeapAdd->lastHeap->degree + 1;
    else maxSize = binHeapAdd->lastHeap->degree + 1;
    for (int i = 0; i <= maxSize; ++i) {
        binomialHeap* nowBHIn = returnBinHeap(binHeapIn, i);
        binomialHeap* nowBHAdd = returnBinHeap(binHeapAdd, i);
        if(nowBHIn != NULL && nowBHAdd != NULL){
            removeBinHeap(binHeapIn);
            removeBinHeap(binHeapAdd);
            if(pVoid != NULL) addBinHeap(answer, pVoid);
            pVoid = connect(nowBHIn, nowBHAdd);
            continue;
        }
        if(nowBHIn != NULL){
            removeBinHeap(binHeapIn);
            if(pVoid != NULL){
                pVoid = connect(nowBHIn, pVoid);
            } else {
                nowBHIn->right = NULL;
                addBinHeap(answer, nowBHIn);
            }
            continue;

        }
        if(nowBHAdd != NULL){
            removeBinHeap(binHeapAdd);
            if(pVoid != NULL){
                pVoid = connect(nowBHAdd, pVoid);
            } else {
                nowBHAdd->right = NULL;
                addBinHeap(answer, nowBHAdd);
            }
            continue;
        }
        if(pVoid != NULL){
            addBinHeap(answer, pVoid);
            pVoid = NULL;
        }
    }
    return answer;
}

void insertBinHeap(binomialHeapList *binHeapIn, int value, int prior){
    binomialHeapList* binHLAdd = createBinHeapList();
    binomialHeap *binHeap = createBinHeap(value, prior);
    addBinHeap(binHLAdd, binHeap);
    binomialHeapList* binHLAns = mergeBinHeap(binHeapIn, binHLAdd);
    *binHeapIn = *binHLAns;
    free(binHLAdd);
    free(binHLAns);
}

int peekMinBinHeap(binomialHeapList *binHeapList){
    binomialHeap* min = binHeapList->firstHeap;
    binomialHeap* nowElem = binHeapList->firstHeap;
    while (nowElem!=NULL){
        if(nowElem->prior < min->prior) min = nowElem;
        nowElem = nowElem->right;
    }
    return min->value;
}
void decreaseKeyBinHeap(binomialHeapList *binHeapList, int index, int prior){
    binomialHeap* noeHeap = binHeapList->firstHeap;
    while (noeHeap != NULL){
        if(index < powInt(2, noeHeap->degree)) break;
        index -= powInt(2, noeHeap->degree);
        noeHeap = noeHeap->right;
    }decreaseKeyBinHeap
}




binomialHeap* connect(binomialHeap *binHeap1, binomialHeap *binHeap2){
    if(binHeap1->prior <= binHeap2->prior ){
        binomialHeap *pVoid = binHeap1->next;
        binHeap1->next = binHeap2;
        binHeap2->previous = binHeap1;
        binHeap2->right = pVoid;
        binHeap1->right = NULL;
        binHeap1->degree++;
        return binHeap1;
    } else return connect(binHeap2, binHeap1);
}
