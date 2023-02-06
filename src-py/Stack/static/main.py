from Stack import Stack
from os import system, name

options = [
    "1.- Push",
    "2.- Pop",
    "3.- Show top",
    "4.- Print stack",
    "5.- Exit"
]

def clear():
    # for windows
    if name == 'nt':
        _ = system('cls')
    else:
        _ = system('clear')

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
        

if __name__ == "__main__":
    size = int(input("Input the stack size: "))
    stack = Stack(size)
    print("\n\tStatic Stack\n")
    
    run = True
    while (run):
        print("\nChoose an option\n")
        print("\n".join(options) + "\n")
        option = int(input("Type an option: "))
        run = action(stack, option)
        
    del stack