import StructBase from "../../StructBase/StructBase";
import { Node } from "../../Node/Node";
import { fixIndex } from "../../utils/utils";

export default class LinkedList extends StructBase {
  private _top: Node | undefined;

  constructor() {
    super();
  }

  isEmpty(): boolean {
    return !this._top;
  }

  isFull(): boolean {
    return false;
  }

  toString(): string {
    let str = "Top -> ";
    if (this.isEmpty()) return str;
    let tmpNode = this._top;
    while (tmpNode) {
      str += `${tmpNode.data} -> `;
      tmpNode = tmpNode.link;
    }
    str += `NULL`;
    return str;
  }

  at(index: number): Node | undefined {
    if (this.isEmpty()) return undefined;

    index = fixIndex(index, this.size);

    let tmpNode = this._top;
    for (let idx = 0; idx < index; idx++) tmpNode = tmpNode?.link;
    return tmpNode;
  }

  insert(value: Node, index: number = 0) {
    if (0 === index || this.isEmpty()) {
      if (!this.isEmpty()) value.link = this._top;
      this._top = value;
      this.size++;
      return;
    }

    index = fixIndex(index, this.size);
    if (index !== this.size - 1) index -= 1;

    let prevNode = this.at(index);
    if (!prevNode) return;
    value.link = prevNode.link;
    prevNode.link = value;
    this.size++;
  }

  push(value: Node) {
    this.insert(value, 0);
  }

  append(value: Node) {
    this.insert(value, -1);
  }

  removeAt(index: number): Node | undefined {
    if (this.isEmpty() || !this._top) return undefined;

    let tmpNode: Node | undefined = this._top;

    if (!tmpNode) return tmpNode;
    if (index === 0) {
      this._top = tmpNode.link;
      tmpNode.link = undefined;
      this.size--;
      return tmpNode;
    }

    tmpNode = this.at(index - 1);
    if (!tmpNode) return tmpNode;

    let rmNode = tmpNode.link;
    if (!rmNode) return rmNode;

    if (!rmNode.link) tmpNode.link = undefined;
    else tmpNode.link = rmNode.link;
    rmNode.link = undefined;
    this.size--;
    return rmNode;
  }

  removeFirst(): Node | undefined {
    return this.removeAt(0);
  }

  removeLast(): Node | undefined {
    return this.removeAt(-1);
  }
}
