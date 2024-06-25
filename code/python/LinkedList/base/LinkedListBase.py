from Node import Node
from abc import ABC, abstractmethod


class LinkedListBase(ABC):
    @abstractmethod
    def __getitem__(self, index: int) -> None:
        pass

    @abstractmethod
    def insert(self, value: Node, index: int = 0) -> None:
        pass

    @abstractmethod
    def removeAt(self, index: int = 0) -> None:
        pass

    def push(self, value: Node) -> None:
        self.insert(value)

    def append(self, value: Node):
        self.insert(value, -1)

    def removeFist(self) -> Node:
        return self.removeAt(0)

    def removeLast(self) -> Node:
        return self.removeAt(-1)

    @staticmethod
    def options():
        return [
            "Push",
            "Append",
            "Insert",
            "Get at",
            "Remove first",
            "Remove last",
            "Remove at",
            "Print list",
            "Exit",
        ]
