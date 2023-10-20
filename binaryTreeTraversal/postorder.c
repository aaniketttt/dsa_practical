#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>

void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}