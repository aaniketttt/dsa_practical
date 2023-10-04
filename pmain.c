// main.c
#include "stack.h"
#include <stdio.h>

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack));
    printf("Pop: %d\n", pop(&stack)); // This will trigger an underflow error

    return 0;
}
