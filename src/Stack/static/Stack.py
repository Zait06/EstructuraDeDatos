# import os, sys

# sys.path.append(os.path.join(os.getcwd(), "src"))

from StructBase import StructBase


class Stack(StructBase):
    def __init__(self, size: int) -> None:
        super()
        self.__items = []
        self.size = size

    def __del__(self) -> None:
        self.__items.clear()

    def __str__(self) -> str:
        str_stack = "\tHEAD -> "
        str_stack += " -> ".join(str(e) for e in self.__items[::-1])
        str_stack += " -> NULL\n"
        return str_stack

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
