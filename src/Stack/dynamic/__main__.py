from Stack import Node, Stack
import os

options = ["1.- Push", "2.- Pop", "3.- Show top", "4.- Print stack", "5.- Exit"]


def clear():
    # for windows
    if os.name == "nt":
        os.system("cls")
    else:
        os.system("clear")


def action(stack: Stack, option: int) -> None:
    clear()
    if option == 1:
        value_int = int(input("Write a value: "))
        value = Node(value_int)
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


if __name__ == "__main__":
    stack = Stack()
    print("\n\tStatic Stack\n")

    run = True
    while run:
        print("\nChoose an option\n")
        print("\n".join(options) + "\n")
        option = int(input("Type an option: "))
        run = action(stack, option)

    del stack
