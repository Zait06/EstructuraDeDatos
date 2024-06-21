from Node import Node
from abc import ABCMeta, abstractmethod


class StackInterface(metaclass=ABCMeta):
    @abstractmethod
    def push(self, value: int | Node) -> None:
        pass

    @abstractmethod
    def pop(self) -> int | Node:
        pass

    @abstractmethod
    def peek(self) -> int | Node:
        pass
