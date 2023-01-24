#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main() {
    Stack* stack;
    init_stack(stack);
    print_stack(stack);

    return 0;
}