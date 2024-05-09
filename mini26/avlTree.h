#pragma once
#include <stddef.h>

typedef struct TreeNode TreeNode;
typedef struct TreeNode LinkNode;
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

TreeNode* balanceBST(struct TreeNode* root);

void convertToArr(TreeNode* root);
void collapse(TreeNode** start, size_t size);