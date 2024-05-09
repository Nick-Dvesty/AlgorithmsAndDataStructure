#include "avlTree.h"
#include <malloc.h>

void convertToArr(TreeNode* root);
void collapse(TreeNode** start, size_t size);

TreeNode* balanceBST(struct TreeNode* root){
    convertToArr(root);
    size_t size = 0;
    while (root->left != nullptr){
        root = root->left;

    }
    TreeNode **start = malloc(sizeof(TreeNode**));
    *start = root;
    while (root != nullptr){
        root = root->right;
        size++;
    }
    collapse(start,size);
    return *start;
}

void convertToArr(TreeNode* root){
    LinkNode *rightNode;
    TreeNode *leftNode;

    if (root->val == 6)
        root->val= 6;

    if(root->left != NULL){
        leftNode = root->left;
        convertToArr(leftNode);
        while (leftNode->right != NULL){
            leftNode = leftNode->right;
        }
        if(root->left != NULL){
            root->left = leftNode;
            root->left->right = root;
        }
    }
    if(root->right != NULL){
        rightNode = root->right;
        convertToArr(rightNode);
        while (rightNode->left != NULL){
            rightNode = rightNode->left;
        }
        if(root->right != NULL){
            root->right = rightNode;
            root->right->left = root;
        }
    }


}

void collapse(TreeNode** start, size_t size){
    if (size >1){
        TreeNode **startRecLeft = malloc(sizeof(TreeNode**)), **startRecRight = malloc(sizeof(TreeNode**));
        *startRecLeft = *start;
        for (int i = 0; i < size/2; ++i) {
            *start = (*start)->right;
        }
        if ((*start)->left != nullptr) {
            (*start)->left->right = nullptr;
            collapse(startRecLeft, size/2);
            (*start)->left = *startRecLeft;
        }
        if ((*start)->right != nullptr) {
            *startRecRight = (*start)->right;
            (*start)->right->left = nullptr;
            collapse(startRecRight, size - (size/2 + 1));
            (*start)->right = *startRecRight;
        }

    }
}
