from utils import clear, list_to_string_menu
from Queue.static import Queue


def action(queue: Queue, option: int) -> None:
    clear()
    if option == 1:
        value = int(input("Write a value: "))
        queue.enqueue(value)
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
    size = int(input("Input the queue size: "))
    queue = Queue(size)
    print("\n\tStatic Queue\n")

    run = True
    while run:
        print("\nChoose an option\n")
        offset = 1 if queue.is_full() else 0
        if queue.is_full():
            print("Queue is full")
        print(list_to_string_menu(Queue.options()[offset:]))
        option = int(input("Type an option: "))
        run = action(queue, option + offset)

    del queue


if __name__ == "__main__":
    main()
