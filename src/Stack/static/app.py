from utils import clear, list_to_string_menu
from Stack.static import Stack


def action(stack: Stack, option: int) -> None:
    clear()
    if option == 1:
        value = int(input("Write a value: "))
        stack.push(value)
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
    size = int(input("Input the stack size: "))
    stack = Stack(size)
    print("\n\tStatic Stack")

    run = True
    while run:
        print("\nChoose an option\n")
        offset = 1 if stack.is_full() else 0
        if stack.is_full():
            print("Stack is full")
        print(list_to_string_menu(Stack.options()[offset:]))
        option = int(input("Type an option: "))
        run = action(stack, option + offset)

    del stack
