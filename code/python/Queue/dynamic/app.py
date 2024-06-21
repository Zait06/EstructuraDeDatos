from utils import clear, list_to_string_menu
from Queue.dynamic import Queue
from Node import Node


def action(queue: Queue, option: int) -> None:
    clear()
    if option == 1:
        value = int(input("Write a value: "))
        queue.enqueue(Node(value))
        return True
    elif option == 2:
        print(f"Dequeue: {queue.dequeue()}")
        return True
    elif option == 3:
        print(f"Head: {queue.head()}")
        return True
    elif option == 4:
        print(f"Tail: {queue.tail()}")
        return True
    elif option == 5:
        print(queue)
        return True
    elif option == 6:
        return False
    else:
        print("Option doesn't exists. Please, try again.\n")
        return True


def main():
    clear()
    queue = Queue()
    print("\n\tDynamic Queue")

    run = True
    while run:
        print("\nChoose an option\n")
        print(list_to_string_menu(Queue.options()))
        option = int(input("Type an option: "))
        run = action(queue, option)

    del queue


if __name__ == "__main__":
    main()
