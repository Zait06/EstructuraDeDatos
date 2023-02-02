import { Node } from "./Node";

export class Stack {
    head: Node | null;

    constructor() {
        this.head = null;
    }

    is_empty() {
        return this.head === null;
    }

    push(node: Node) {
        if (this.is_empty()) return;
        node.next = this.head;
        this.head = node;
    }

    pop(): Node | null {
        const node = this.head;
        if(!node) return null;
        this.head = node.next;
        return node;
    }

    peek(): Node | null {
        return this.head;
    }
}