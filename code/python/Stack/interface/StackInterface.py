from Node import Node
from typing import Union
from abc import ABCMeta, abstractmethod


class StackInterface(metaclass=ABCMeta):
    @abstractmethod
    def push(self, value: Union[int, Node]) -> None:
        pass

    @abstractmethod
    def pop(self) -> Union[int, Node]:
        pass

    @abstractmethod
    def peek(self) -> Union[int, Node]:
        pass
