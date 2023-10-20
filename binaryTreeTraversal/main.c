#include <stdio.h>
#include "binarytree.h"

int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Display Tree (Pattern)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insertNode(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Inorder traversal of the BST: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal of the BST: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal of the BST: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Binary Search Tree (Pattern):\n");
                displayPattern(root, 0, 0);
                break;
            case 7:
                freeTree(root);
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

