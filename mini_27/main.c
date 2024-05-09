#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}



struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    BinaryHeap* heap = heapCreate();
    for (int i = 0; i < listsSize; i++) {
        struct ListNode* bufer = lists[i];
        while (bufer != NULL){
            heapInsert(heap, (bufer->val), bufer->val);
            bufer = bufer->next;
        }
    }
    struct ListNode* answer = NULL;
    while ( heap->index != 0) {
        struct ListNode* answer2 = malloc(sizeof (struct  ListNode));
        answer2->val = heapExtractMax(heap);
        answer2->next = answer;
        answer = answer2;
    }
    return answer;
}