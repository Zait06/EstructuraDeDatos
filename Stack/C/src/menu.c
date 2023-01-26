#include "menu.h"

int menu() {
    int option = 0;
    char* options[] = {
        "1.- Push",
        "2.- Pop",
        "3.- Print",
        "4.- Exit"
    };
    printf("Select an option:\n");
    for (int i = 0; i < 4; i++) {
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
            printf("Value: ");
            scanf("%d", &value);
            push(stack, create_node(value));
            printf("\n");
            return true;
        case 2:
            print_node(pop(stack));
            printf("\n");
            return true;
        case 3:
            print_stack(stack);
            printf("\n");
            return true;
        case 4:
            return false;
        default:
            printf("Option doesn't exists. Please, try again.\n");
            return true;
    }
}