#include <stdio.h>
#include <malloc.h>
#include "avlTree.h"
int main() {
    TreeNode *t1 = malloc(sizeof(TreeNode));
    TreeNode *t2 = malloc(sizeof(TreeNode));
    TreeNode *t3 = malloc(sizeof(TreeNode));
    TreeNode *t4 = malloc(sizeof(TreeNode));
    TreeNode *t5 = malloc(sizeof(TreeNode));
    TreeNode *t6 = malloc(sizeof(TreeNode));
    TreeNode *t7 = malloc(sizeof(TreeNode));
    TreeNode *t8 = malloc(sizeof(TreeNode));
    TreeNode *t9 = malloc(sizeof(TreeNode));


    t1->val = 9;
    t1->left = t2;
    t1->right = t3;

    t2->val = 6;
    t2->left = t4;
    t2->right = t5;

    t3->val = 10;
    t3->left = nullptr;
    t3->right = t8;

    t4->val = 4;
    t4->left = t6;
    t4->right = t7;

    t5->val = 7;
    t5->left = nullptr;
    t5->right = t9;

    t6->val = 2;
    t6->left = nullptr;
    t6->right = nullptr;

    t7->val = 5;
    t7->left = nullptr;
    t7->right = nullptr;

    t8->val = 17;
    t8->left = nullptr;
    t8->right = nullptr;

    t9->val = 8;
    t9->left = nullptr;
    t9->right = nullptr;

    TreeNode *test = malloc(sizeof(TreeNode));
    convertToArr(t1);
    size_t size = 0;
    while (t1->left != nullptr){
        t1 = t1->left;
    }
    TreeNode **start = malloc(sizeof(TreeNode**));
    *start = t1;
    while (t1 != nullptr){
        t1 = t1->right;
        size++;
    }
    collapse(start,size);
    float t = 8.9;
    int t23 = 9;
    if(t2){
        t23 = 23;
    }
    printf("%d %d", 0);
}