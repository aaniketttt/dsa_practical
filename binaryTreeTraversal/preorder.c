#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>

void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}