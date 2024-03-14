#include <stdio.h>
#include <malloc.h>
#include "BinaryHeap.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);

int main() {
    struct ListNode a1;
    struct ListNode a2;
    struct ListNode a3;
    a1.val = 1;
    a2.val = 4;
    a3.val = 5;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = NULL;

    struct ListNode b1;
    struct ListNode b2;
    struct ListNode b3;
    b1.val = 1;
    b2.val = 3;
    b3.val = 4;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = NULL;

    struct ListNode c1;
    struct ListNode c2;
    c1.val = 2;
    c2.val = 6;
    c1.next = &c2;
    c2.next = NULL;

    struct ListNode* list[3] = {&a1, &b1, &c1};
    struct ListNode* answer = mergeKLists(list,3);
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