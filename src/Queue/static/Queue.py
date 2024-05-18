class Queue:
    __queue = []

    def __init__(self, size: int) -> None:
        self.__size = size

    def __del__(self) -> None:
        self.__queue.clear()

    def __str__(self) -> str:
        str_ = "\n\tHEAD -> "
        str_ += " -> ".join([str(e) for e in self.__queue])
        str_ += " <- TAIL\n"
        return str_

    def is_empty(self) -> bool:
        return len(self.__queue) == 0

    def is_full(self) -> bool:
        return len(self.__queue) == self.__size

    def enqueue(self, value: int):
        try:
            if self.is_full():
                raise Exception("Queue is full. Can't push more data")
            self.__queue.append(value)
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def dequeue(self) -> int:
        try:
            if self.is_empty():
                raise Exception("Queue is empty.")
            return self.__queue.pop(0)
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def head(self) -> int:
        if self.is_empty():
            return -1
        return self.__queue[0]

    def tail(self) -> int:
        if self.is_empty():
            return -1
        return self.__queue[-1]
