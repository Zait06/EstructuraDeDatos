#include <stdbool.h>
#include "../../Node/node.h"
#include "../../utils/utils.h"

typedef struct Stack {
  int size;
  Node* head;
} Stack;

void stack_init(Stack* stack);
bool stack_is_empty(Stack* stack);
void stack_push(Stack* stack, Node node);
Node stack_pop(Stack* stack);
Node stack_peek(Stack* stack);
void stack_print(Stack* stack);
bool stack_action(Stack* stack, int option);
void stack_destroy(Stack* stack);
