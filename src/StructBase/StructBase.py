from abc import ABC, abstractmethod


class StructBase(ABC):
    size: int = 0

    @abstractmethod
    def is_empty(self) -> bool:
        pass

    @abstractmethod
    def is_full(self) -> bool:
        pass

    @abstractmethod
    def __str__(self) -> str:
        return super().__str__()
