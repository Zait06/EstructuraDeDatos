import { Node } from "../../Node/Node";
import StructBase from "../../StructBase/StructBase";
import QueueInterface from "../interface/QueueInterface";

export default class Queue extends StructBase implements QueueInterface {
  private _head: Node | undefined;
  private _tail: Node | undefined;

  constructor() {
    super();
  }

  *[Symbol.iterator]() {
    let tmpNode = this._head;
    let auxNode = this._head;
    while (tmpNode !== undefined) {
      auxNode = tmpNode;
      tmpNode = tmpNode.link;
      yield auxNode;
    }
  }

  isEmpty(): boolean {
    return !this._head && !this._tail;
  }

  isFull(): boolean {
    return false;
  }

  enqueue(value: Node) {
    try {
      if (this.isEmpty()) {
        this._head = value;
        this._tail = value;
        return;
      }
      if (!this._tail) return;
      value.link = this._tail;
      this._tail.link = value;
    } catch (err) {
      console.error(err);
    }
  }

  dequeue(): Node | undefined {
    try {
      if (this.isEmpty()) throw "Queue is empty.";
      if (!this._head) return;
      const node: Node = this._head;
      this._head = node.link;
      return node;
    } catch (err: any) {
      console.error(err);
    }
  }

  head(): Node | undefined {
    if (this.isEmpty()) return undefined;
    return this._head;
  }

  tail(): Node | undefined {
    if (this.isEmpty()) return undefined;
    return this._tail;
  }

  toString(): string {
    let str: string = "\nFRONT -> ";
    let aux: Node | undefined = this._head;
    str += [...this].map((elem) => elem.data).join(" -> ");
    str += `${aux?.data} <- TAIL\n`;
    return str;
  }
}
