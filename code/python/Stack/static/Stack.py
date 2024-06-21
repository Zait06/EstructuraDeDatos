from StructBase import StructBase
from Stack.interface import StackInterface


class Stack(StructBase, StackInterface):
    def __init__(self, size: int) -> None:
        super()
        self.__items = []
        self.size = size

    def __del__(self) -> None:
        self.__items.clear()

    def __len__(self) -> int:
        return len(self.__items)

    def __str__(self) -> str:
        str_stack = "\tHEAD -> "
        str_stack += " -> ".join(str(e) for e in self.__iter__())
        str_stack += " -> NULL\n"
        return str_stack

    def __iter__(self) -> "Stack":
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

    def push(self, value: int) -> None:
        try:
            if self.is_full():
                raise Exception("Stack is full. Can't push more data")
            self.__items.append(value)
        except Exception as exp:
            msg = exp.args
            print(f"Error: {msg[0]}")

    def pop(self) -> int:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self.__items.pop()
        except Exception as exp:
            print(exp[0])

    def peek(self) -> int:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self.__items[-1]
        except Exception as exp:
            print(exp[0])

    @staticmethod
    def options() -> list[str]:
        return ["Push", "Pop", "Show top", "Print stack", "Exit"]
