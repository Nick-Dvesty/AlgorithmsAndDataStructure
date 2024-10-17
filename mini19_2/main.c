#include <assert.h>
#include <malloc.h>

typedef struct{
    struct ListNode * value;
    int prior;
}IntPrior;

typedef struct{
    IntPrior* array;
    int index;
    int size;
}BinaryHeap;

BinaryHeap* heapCreate();
BinaryHeap* heapDelete();

void heapInsert(BinaryHeap* heap, int prior, struct ListNode* value);
int heapPeek_max(BinaryHeap* heap);
struct ListNode* heapExtractMin(BinaryHeap* heap);

void swap(BinaryHeap* heap, int index1, int index2);
void shiftDown(BinaryHeap* heap, int index);
void shiftUp(BinaryHeap* heap, int index);

void increaseArray(BinaryHeap* heap);
void reduceArray(BinaryHeap* heap);


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    BinaryHeap* heap = heapCreate();
    struct ListNode* pNode = NULL;
    struct ListNode* ret = NULL;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL){
            heapInsert(heap, (lists[i]->val), lists[i]);
            lists[i] = lists[i]->next;
        }
    }
    while (heap->index !=    0){
        struct ListNode* newNode;
        newNode = heapExtractMin(heap);
        if (newNode->next != NULL) heapInsert(heap, newNode->next->val, newNode->next);
        newNode->next = NULL;
        if (pNode != NULL) pNode->next = newNode;
        else {
            pNode = newNode;
            ret = newNode;
        }
        pNode = newNode;
    }
    return ret;
}


BinaryHeap* heapCreate(){
    BinaryHeap *heap = malloc(sizeof(BinaryHeap));
    IntPrior* array = malloc(sizeof(IntPrior));
    heap->array = array;
    heap->size = 1;
    heap->index = 0;
    return  heap;
}
void heapInsert(BinaryHeap* heap, int prior, struct ListNode * value){
    if(heap->size == heap->index) increaseArray(heap);
    IntPrior newElem;
    newElem.value = value;
    newElem.prior = prior;
    heap->array[heap->index] = newElem;
    shiftUp(heap, heap->index);
    heap->index++;
}
struct ListNode* heapExtractMin(BinaryHeap* heap){
    struct ListNode* answer = heap->array[0].value;
    heap->index--;
    if (heap->size > 1) {
        swap(heap, 0, heap->index);
        shiftDown(heap, heap->index);
        if (heap->index <= heap->size / 4) reduceArray(heap);
    }
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
        if(heap->array[index].prior <= heap->array[(index - 1)/ 2].prior){
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
            if (heap->array[i * 2 + 1].prior <= heap->array[i * 2 + 2].prior){
                if (heap->array[i].prior >= heap->array[i * 2 + 1].prior){
                    swap(heap, i, i * 2 + 1);
                    i = i * 2 + 1;
                } else if (heap->array[i].prior >= heap->array[i * 2 + 2].prior){
                    swap(heap, i, i * 2 + 2);
                    i = i * 2 + 2;
                } else break;
            } else{
                if (heap->array[i].prior >= heap->array[i * 2 + 2].prior){
                    swap(heap, i, i * 2 + 2);
                    i = i * 2 + 2;
                } else if (heap->array[i].prior >= heap->array[i * 2 + 1].prior){
                    swap(heap, i, i * 2 + 1);
                    i = i * 2 + 1;
                } else break;
            }
        } else{
            if (heap->array[i].prior >= heap->array[i * 2 + 1].prior){
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


int main(){
    struct ListNode** lists = calloc(sizeof (struct ListNode*), 1);
    struct ListNode* node1 = malloc(sizeof(struct ListNode));
    struct ListNode* node2 = malloc(sizeof(struct ListNode));
    struct ListNode* node3 = malloc(sizeof(struct ListNode));
    struct ListNode* node4 = malloc(sizeof(struct ListNode));
    struct ListNode* node5 = malloc(sizeof(struct ListNode));
    struct ListNode* node6 = malloc(sizeof(struct ListNode));
    struct ListNode* node7 = malloc(sizeof(struct ListNode));
    struct ListNode* node8 = malloc(sizeof(struct ListNode));
    lists[0] = node1;
    lists[1] = node4;
    lists[2] = node7;
    node1->val = 1;
    node2->val = 4;
    node3->val = 5;
    node4->val = 1;
    node5->val = 3;
    node6->val = 4;
    node7->val = 2;
    node8->val = 6;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;
    node7->next = node8;
    node8->next = NULL;
    //node1->val = 0;
    //node2->val = 2;
    //node3->val = 5;
    //node1->next = node2;
    //node2->next = node3;
    //node3->next = NULL;
    struct ListNode* t = mergeKLists(lists,3);
}