#include "menu.h"

int menu(bool full) {
    int option = 0;
    char* options[] = {
        "1.- Push",
        "2.- Pop",
        "3.- Show top",
        "4.- Print stack",
        "5.- Exit"
    };
    printf("Select an option:\n");
    for (int i = 0; i < 5; i++) {
        if (i == 0 && full) continue;
        printf("%s\n", options[i]);
    }
    printf("Type your option: ");
    scanf("%d", &option);
    return option;
}

bool action(Stack* stack, int option) {
    int value;
    printf("\e[1;1H\e[2J");
    printf("\n");
    switch (option) {
        case 1:
            if (is_full(stack)) return true;
            printf("Value: ");
            scanf("%d", &value);
            push(stack, value);
            printf("\n");
            return true;
        case 2:
            printf("Pop: %d", pop(stack));
            printf("\n");
            return true;
        case 3:
            printf("Top: %d", peek(stack));
            printf("\n");
            return true;
        case 4:
            print_stack(stack);
            printf("\n");
            return true;
        case 5:
            return false;
        default:
            printf("Option doesn't exists. Please, try again.\n");
            return true;
    }
}