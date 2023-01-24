#include "node.h"

typedef struct Stack {
    Node* head;
    int length;
} Stack;

void init_stack(Stack* stack);
int is_empty(Stack* stack);
void push(Stack* stack, Node* node);
Node* pop(Stack* stack);
void print_stack(Stack* stack);