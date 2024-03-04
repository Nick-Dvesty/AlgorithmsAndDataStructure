#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseBetween(struct ListNode* head, int left, int right);

int main() {

}


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(left != right) {
        struct ListNode null;
        null.next = head;
        struct ListNode *leftElement = &null;
        struct ListNode *rightElement = &null;
        for (int i = 0; i < right; i++) {
            if (i < left - 1) leftElement = leftElement->next;
            if (i < right)rightElement = rightElement->next;
        }
        struct ListNode *left1 = leftElement->next;
        struct ListNode *left2 = left1->next;
        struct ListNode *left3 = left2->next;
        leftElement->next->next = rightElement->next;
        for (int i = left; i < right; i++) {
            left2->next = left1;

            left1 = left2;
            left2 = left3;
            if (left3 != NULL)left3 = left3->next;
        }
        leftElement->next = rightElement;
        if(left != 1) return head;
        else return  rightElement;
    }
    return head;

}