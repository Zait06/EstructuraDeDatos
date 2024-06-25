from Node import Node
from abc import ABCMeta, abstractmethod


class QueueInterface(metaclass=ABCMeta):
    @abstractmethod
    def enqueue(self, value: int | Node) -> None:
        pass

    @abstractmethod
    def dequeue(self) -> int | Node:
        pass

    @abstractmethod
    def head(self) -> int | Node:
        pass

    @abstractmethod
    def tail(self) -> int | Node:
        pass
