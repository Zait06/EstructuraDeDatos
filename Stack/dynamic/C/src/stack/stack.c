#include "stack.h"

void init_stack(Stack* stack) {
    stack->head = NULL;
}

bool is_empty(Stack* stack) {
    return stack->head == NULL;
}

void push(Stack* stack, Node* node) {
    node->next = stack->head;
    stack->head = node;
}

Node* pop(Stack* stack) {
    if (is_empty(stack)) return NULL;
    Node* node = stack->head;
    stack->head = stack->head->next;
    return node;
}

Node* peek(Stack* stack) {
    if (is_empty(stack)) return NULL;
    return stack->head;
}

void print_stack(Stack* stack) {
    Node* aux_node = stack->head;
    printf("\tHEAD -> ");
    while(aux_node != NULL) {
        printf("%d -> ", aux_node->data);
        aux_node = aux_node->next;
    }
    printf("NULL\n");
}