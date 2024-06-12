from abc import ABC, abstractmethod


class StructBase(ABC):
    size: int = 0

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

    @abstractmethod
    def __str__(self) -> str:
        return super().__str__()
