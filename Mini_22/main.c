#include <malloc.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char* serialize(struct TreeNode* root) {
    char* answer = calloc(sizeof (char), 100);
    int now = 0;
    int max = 1;
}

char* serializeRecurs(struct TreeNode* root) {
    if (root != NULL) {
        char *left = serializeRecurs(root->left);
        char *right = serializeRecurs(root->right);
        char *answer = ;
        return answer;
    } return NULL;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {

}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);