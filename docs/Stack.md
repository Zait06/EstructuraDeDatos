# Stack

- [Definición](#definición)
- [Static](#static)
- [Dynamic](#dynamic)
  - [Acción Push](#push-action)
  - [Acción Pop](#pop-action)
- [Diarama a clases](#diagrama-de-clases)

## Definición

Una pila (stack) es una estructura de datos de tipo FILO (first-in, last-out) o LIFO (last-in, first-out) dónde sus operaciones se asemejan a los de una pila de papeles; Podemos agregar nuevos elementos al inicio de la pila y remover los elementos desde el inicio de la misma. La pila tiene dos operaciones que lo caracterizan:

- `push`: Agrega un nuevo elemento en el tope o inicio de la pila.
- `pop`: Elimina el elemento del tope de la pila y lo retorna.

Otro de los metodos que se pueden encontrar dentro de una pila son:

- `is_empty`: Pregunta si la pila está vacía.
- `is_full`: Pregunta si la pila está llena.
- `top` o `peek`: Muestra el elemento en el tope de la pila.

## Static

## Dynamic

```mermaid
flowchart TB;
  subgraph "Init state"
  direction LR
    Head-->NULL
  end

  subgraph "Element"
  direction LR
    Data-->A[NULL]
  end
```

### Push Action

```mermaid
flowchart LR;
  subgraph "Push Action"
  direction LR

    subgraph "State 1.1"
      direction LR
      Head-.->NULL
      Data01-->NULL
      Head-->Data01
    end

    subgraph "State 1.2"
    direction LR
      A[Head]-->B[Data01]
      B[Data01]-->C[NULL]
    end

    subgraph "State 2.1"
    direction LR
      D[Data01]-->F[NULL]
      E[Head]-.->D[Data01]
      E[Head]-->Data02
      Data02-->D[Data01]
    end

    subgraph "State 2.2"
    direction LR
      G[Data01]-->H[NULL]
      I[Head]-->J[Data02]
      J[Data02]-->G[Data01]
    end

  end
```

### Pop Action

```mermaid
flowchart LR;
    subgraph "Pop Action"
    direction LR
      subgraph "State 1"
      direction LR
        Data01-->NULL
        Head-.->Data03
        Head-->Data02
        Data02-->Data01
        Data03-->Data02
      end

      subgraph "State 2"
      direction LR
        A[Data01]-->D[NULL]
        C[Head]-->B[Data02]
        B[Data02]-->A[Data01]
      end
    end
```

## Diagrama de clases

```mermaid
---
title: Diagrama de pila
---
classDiagram

class Node {
  +int data
  +Node next
}

class Stack {
  -Node head
  +is_empty() bool
  +push(Node node)
  +pop() Node
  +peek() Node
  +toString() String
}

Stack ..> Node: use
```
