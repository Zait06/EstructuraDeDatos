import { Node } from "./Node";

export class Stack {
    head: Node | undefined;

    constructor() {
        this.head = undefined;
    }

    is_empty() {
        return !this.head
    }

    push(node: Node) {
        if (this.is_empty() || !this.head) return;
        node.next = this.head;
        this.head = node;
    }

    pop(): Node | undefined {
        const node = this.head;
        if(!node) return undefined;
        this.head = node.next;
        return node;
    }

    peek(): Node | undefined {
        return this.head;
    }
}