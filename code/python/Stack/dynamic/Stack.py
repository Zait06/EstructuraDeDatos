from typing import Union, Any

from Node import Node
from StructBase import StructBase
from Stack.interface import StackInterface


class Stack(StructBase, StackInterface):
    def __init__(self) -> None:
        super(StructBase, self)
        self.size = 0
        self._head: Node = None

    def __del__(self) -> None:
        self._head = None

    def __len__(self) -> int:
        return self.size

    def __str__(self) -> str:
        str_stack = "\tHEAD -> "
        str_stack += " -> ".join(str(e) for e in self.__iter__())
        str_stack += " -> NULL\n"
        return str_stack

    def __iter__(self) -> Any:
        self._tmpNode = self._head
        return self

    def __next__(self) -> Any:
        if self._tmpNode is None:
            raise StopIteration
        data = self._tmpNode
        self._tmpNode = data.link
        return data

    def is_empty(self) -> bool:
        return self._head is None

    def is_full(self) -> bool:
        return False

    def push(self, value: Union[int, Node]) -> None:
        if type(value) is 'int':
            value = Node(value)
        value.link = self._head
        self._head = value
        self.size += 1

    def pop(self) -> Union[int, Node]:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            node = self._head
            self._head = node.link
            self.size -= 1
            return node
        except Exception as exc:
            print(exc)

    def peek(self) -> Union[int, Node]:
        try:
            if self.is_empty():
                raise Exception("Stack is empty.")
            return self._head
        except Exception as exc:
            print(exc)

    @staticmethod
    def options():
        return ["Push", "Pop", "Show top", "Print stack", "Exit"]
