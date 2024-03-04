#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *detectCycle(struct ListNode *head);

int main() {
    struct ListNode El1;
    struct ListNode El2;
    struct ListNode El3;
    struct ListNode El4;

    El1.next = &El2;
    El2.next = &El3;
    El3.next = &El4;
    El4.next = &El2;

    El1.val = 3;
    El2.val = 2;
    El3.val = 0;
    El4.val = -4;

    detectCycle(&El1);
}



struct ListNode *detectCycle(struct ListNode *head) {
    if(head != NULL){
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        struct ListNode *bra = head;
        do{
            if(fast->next == NULL || fast->next->next == NULL) return  NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while (slow != fast);
        while (1){
            slow = head;//начальная позиция
            bra = fast;//фиксируем ту величину, что точно была в цикле
            while (slow->next != fast){
                slow = slow->next;
            }
            if(fast == head) return fast;
            fast = slow;// записываем в fast предыдущий элемент
            slow = bra->next; // записываем элемент из цикла
            while (slow != fast){
                if(slow == bra) return fast->next;
                slow = slow->next;
            }
        }
    }
        return NULL;
}
/*
 *     if(head != NULL){
        struct ListNode *test = head;
        struct ListNode *test2 = head;
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        while (test2->next != NULL){
            slow = head;
            fast = head;
            do{
                if(test2->next == NULL || slow->next == NULL || fast->next == NULL || fast->next->next == NULL) return NULL;
                slow = slow->next;
                fast = fast->next->next;

                if(test2->next == test){
                    return test;
                } else{
                    test2 = test2->next;
                }
            }while (slow != fast);
            if(test->next == NULL) return  NULL;
                test = test->next;
        }
    }
        return NULL;

 * if(head != NULL){
        struct ListNode *test = head;
        struct ListNode *test2 = head;
        struct ListNode *slow = head;
        struct ListNode *fast = head;
        while (test2->next != NULL){
            for (int i = 0; i < 10000; ++i) {
                if(test2->next == NULL) return NULL;
                if(test2->next == test){
                    return test;
                } else{
                    test2 = test2->next;
                }
            }
            test = test->next;
        }
    }
        return NULL;
 * */