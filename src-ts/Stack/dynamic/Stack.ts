import { Node } from "../../utils/Node";

export default class Stack {
    head: Node | undefined;

    constructor() {
        this.head = undefined;
    }

    is_empty() {
        return !this.head;
    }

    push(node: Node) {
        node.next = this.head;
        this.head = node;
    }

    pop(): Node | undefined {
        if (this.is_empty()) return undefined;
        const node = this.head;
        if (!node) return undefined;
        this.head = node.next;
        return node;
    }

    peek(): Node | undefined {
        return this.head;
    }

    toString(): string {
        let str = "\tHEAD -> ";
        let aux_node = this.head;
        while (aux_node !== undefined) {
            str += `${aux_node.data} -> `
            aux_node = aux_node.next;
        }
        str += "NULL\n";
        return str;
    }
}