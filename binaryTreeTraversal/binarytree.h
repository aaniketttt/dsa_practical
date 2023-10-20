#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(int key);
Node* insertNode(Node* root, int key);
Node* deleteNode(Node* root, int key);
Node* findMin(Node* node);
void inorderTraversal(Node* root);
void postorderTraversal(Node* root);
void preorderTraversal(Node* root);
void displayPattern(Node* root, int level, int space);
void freeTree(Node* root);

#endif

