from utils import clear, list_to_string_menu
from Stack.dynamic import Stack
from Node import Node


def action(stack: Stack, option: int) -> bool:
    clear()
    if option == 1:
        value = int(input("Write a value: "))
        stack.push(Node(value))
        return True
    elif option == 2:
        print(f"Pop: {stack.pop()}")
        return True
    elif option == 3:
        print(f"Top: {stack.peek()}")
        return True
    elif option == 4:
        print(stack)
        return True
    elif option == 5:
        return False
    else:
        print("Option doesn't exists. Please, try again.\n")
        return True


def main():
    clear()
    stack = Stack()
    print("\n\tDynamic Stack")

    run = True
    while run:
        print("\nChoose an option\n")
        print(list_to_string_menu(Stack.options()))
        option = int(input("Type an option: "))
        run = action(stack, option)

    del stack


if __name__ == "__main__":
    main()
