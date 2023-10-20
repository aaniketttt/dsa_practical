#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}