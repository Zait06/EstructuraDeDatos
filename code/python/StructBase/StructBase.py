from abc import ABC, abstractmethod

from Node import Node


class StructBase(ABC):
    size: int = 0
    _index: int = 0
    _tmpNode: Node = None

    @abstractmethod
    def __str__(self) -> str:
        return super().__str__()

    @abstractmethod
    def __next__(self) -> any:
        pass

    @abstractmethod
    def __iter__(self) -> any:
        pass

    @abstractmethod
    def __len__(self) -> int:
        pass

    @abstractmethod
    def is_empty(self) -> bool:
        """Return if the struct is empty

        Returns:
            bool: is empty the struct
        """
        pass

    @abstractmethod
    def is_full(self) -> bool:
        """Return if the struct is full

        Returns:
            bool: is full the struct
        """
        pass
