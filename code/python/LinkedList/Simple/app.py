from Node import Node
from LinkedList.Simple import LinkedList

from utils import clear, list_to_string_menu


def action(linked_list: LinkedList, option: int) -> None:
    idx = 0
    value = 0

    clear()

    if option in [1, 2, 3]:
        value = int(input("Write a value: "))

    if option in [3, 4, 7]:
        idx = int(input("Give an index: "))

    if option == 1:
        linked_list.push(Node(value))
        return True
    elif option == 2:
        linked_list.append(Node(value))
        return True
    elif option == 3:
        linked_list.insert(Node(value), idx)
        return True
    elif option == 4:
        print(f"Value at {idx} is {linked_list[idx]}")
        return True
    elif option == 5:
        print(f"Remove {linked_list.removeFist()}")
        return True
    elif option == 6:
        print(f"Remove {linked_list.removeLast()}")
        return True
    elif option == 7:
        print(f"Remove {linked_list.removeAt(idx)}")
        return True
    elif option == 8:
        print(linked_list)
        return True
    elif option == 9:
        return False
    else:
        print("Option doesn't exists. Please, try again.\n")
        return True


def main():
    clear()

    linked_list = LinkedList()
    print("\n\tLinkedList Simple")

    run = True
    while run:
        print("\nChoose an option\n")
        print(list_to_string_menu(LinkedList.options()))
        option = int(input("Type an option: "))
        run = action(linked_list, option)

    del linked_list


if __name__ == "__main__":
    main()
