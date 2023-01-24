#include "stack.h"

void init_stack(Stack* stack) {
    stack->head = NULL;
    stack->length = 0;
}

int is_empty(Stack* stack) {
    return stack->head == NULL;
}

void push(Stack* stack, Node* node) {
    node->next = stack->head;
    stack->head = node;
    stack->length++;
}

Node* pop(Stack* stack) {
    if (is_empty(stack)) return NULL;
    Node* node = stack->head;
    stack->head = stack->head->next;
    stack->length--;
    return node;
}

void print_stack(Stack* stack) {
    if (is_empty(stack)) return printf("NULL");
    Node* node = stack->head;
    while(node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL");
}