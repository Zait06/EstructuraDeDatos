#include <stdbool.h>
#include "../../Node/node.h"
#include "../../utils/utils.h"

typedef struct Stack {
  Node* head;
} Stack;

void init_stack(Stack* stack);
bool is_empty(Stack* stack);
void push(Stack* stack, Node* node);
Node* pop(Stack* stack);
Node* peek(Stack* stack);
void print_stack(Stack* stack);
bool action(Stack* stack, int option);