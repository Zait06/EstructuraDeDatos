import os

from Queue import Node, Queue

options = [
    "1. Enqueue",
    "2. Dequeue",
    "3. Show head",
    "4. Show tail",
    "5. Print queue",
    "6. Exit",
]


def clear():
    # for windows
    if os.name == "nt":
        _ = os.system("cls")
    else:
        _ = os.system("clear")


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


if __name__ == "__main__":
    queue = Queue()
    print("\n\tDynamic Queue\n")

    run = True
    while run:
        print("\nChoose an option\n")
        print("\n".join(options) + "\n")
        option = int(input("Type an option: "))
        run = action(queue, option)

    del queue
