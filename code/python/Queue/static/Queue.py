from StructBase import StructBase


class Queue(StructBase):
    __items = []

    def __init__(self, size: int) -> None:
        super()
        self.size = size

    def __del__(self) -> None:
        self.__items.clear()

    def __str__(self) -> str:
        str_ = "\n\tHEAD -> "
        str_ += " -> ".join([str(e) for e in self.__iter__()])
        str_ += " <- TAIL\n"
        return str_

    def __iter__(self) -> "Queue":
        self._index = 0
        return self

    def __next__(self) -> int:
        if self._index < self.__len__():
            index = self.__len__() - self._index - 1
            self._index += 1
            return self.__items[index]
        raise StopIteration

    def is_empty(self) -> bool:
        return len(self.__items) == 0

    def is_full(self) -> bool:
        return len(self.__items) == self.size

    def enqueue(self, value: int):
        try:
            if self.is_full():
                raise Exception("Queue is full. Can't push more data")
            self.__items.append(value)
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def dequeue(self) -> int:
        try:
            if self.is_empty():
                raise Exception("Queue is empty.")
            return self.__items.pop(0)
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def head(self) -> int:
        if self.is_empty():
            return -1
        return self.__items[0]

    def tail(self) -> int:
        if self.is_empty():
            return -1
        return self.__items[-1]

    @staticmethod
    def options():
        return [
            "Enqueue",
            "Dequeue",
            "Show head",
            "Show tail",
            "Print queue",
            "Exit",
        ]
