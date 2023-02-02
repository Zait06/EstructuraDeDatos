#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "menu/menu.h"

int main() {
    Stack stack;

    srand(time(NULL));
    
    printf("\e[1;1H\e[2J");
    printf("\n\tSimple Stack\n");

    int size;
    printf("Input size stack: ");
    scanf("%d", &size);

    init_stack(&stack, size);
    
    bool doit = true;
    while (doit) {
        bool full = is_full(&stack);
        if (full) printf("The stack is full\n\n");
        doit = action(&stack, menu(full));
    }

    destroy_stack(&stack);

    return 0;
}