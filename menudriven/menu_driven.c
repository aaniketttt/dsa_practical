#include <stdio.h>
#include "stack.h"
#include "infixtopostfix.h"
#include "postfix_evaluation.h"
#include "bracket_matching.h"
#include "binary_tree.h"
#include "shortest_path_algorithm.h"
#include "merge.h"

void performMergeSort() {
    FILE *inputFile = fopen("inputQS.csv", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    struct Data input_data[1000];
    int count = 0;
    char line[100];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        sscanf(line, "%d,%s", &input_data[count].count, input_data[count].word);
        count++;
    }
    fclose(inputFile);

    merge_sort(input_data, 0, count - 1);

    FILE *outputFile = fopen("output.csv", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(outputFile, "%d,%s\n", input_data[i].count, input_data[i].word);
    }
    fclose(outputFile);

    printf("Data has been sorted and written to 'output.csv'.\n");
}

int main() {
    int choice;
    Stack* stack = NULL;
    BinaryTree tree;

    do {
        printf("\nMenu:\n");
        printf("1. Stack Operations\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Postfix Expression Evaluation\n");
        printf("4. Bracket Matching\n");
        printf("5. Binary Tree Operations\n");
        printf("6. Shortest Path Algorithm\n");
        printf("7. Merge Sort\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                stack = createStack();

                push(stack, 1);
                push(stack, 2);
                push(stack, 3);

                printf("Popped: %d\n", pop(stack));
                printf("Popped: %d\n", pop(stack));

                push(stack, 4);

                while (!isEmpty(stack)) {
                    printf("Popped: %d\n", pop(stack));
                }

                destroyStack(stack);
                break;

            case 2: {
                char infix[100], postfix[100];
                printf("Enter an infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n");
            }
            break;

            case 3: {
                char postfix[100];

                printf("Enter a postfix expression: ");
                scanf("%s", postfix);

                int result = evaluatePostfix(postfix);

                printf("Result: %d\n", result);
            }
            break;

            case 4: {
                char expression[100];
                int result;

                printf("Enter an expression to check if brackets are matched: ");
                fgets(expression, sizeof(expression), stdin);

                // Remove the newline character from the input
                expression[strcspn(expression, "\n")] = '\0';

                result = areBracketsMatched(expression);

                if (result) {
                    printf("Brackets are matched in the given expression.\n");
                } else {
                    printf("Brackets are not matched in the given expression.\n");
                }
            }
            break;

            case 5: {
                initBinaryTree(&tree);

                int choice;
                int value;

                do {
                    printf("\nBinary Tree Menu:\n");
                    printf("1. Insert Node\n");
                    printf("2. Delete Node\n");
                    printf("3. Preorder Traversal\n");
                    printf("4. Inorder Traversal\n");
                    printf("5. Postorder Traversal\n");
                    printf("6. Exit Binary Tree Operations\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("Enter the value to insert: ");
                            scanf("%d", &value);
                            insertNode(&tree, value);
                            break;
                        case 2:
                            printf("Enter the value to delete: ");
                            scanf("%d", &value);
                            deleteNode(&tree, value);
                            break;
                        case 3:
                            printf("Preorder Traversal: ");
                            preorderTraversal(tree.root);
                            printf("\n");
                            break;
                        case 4:
                            printf("Inorder Traversal: ");
                            inorderTraversal(tree.root);
                            printf("\n");
                            break;
                        case 5:
                            printf("Postorder Traversal: ");
                            postorderTraversal(tree.root);
                            printf("\n");
                            break;
                        case 6:
                            printf("Exiting binary tree operations.\n");
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }
                } while (choice != 6);
            }
            break;

            case 6: {
                printf("Shortest Path Algorithm Example\n");
                shortestPathAlgorithm();
            }
            break;

            case 7:
                performMergeSort();
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
