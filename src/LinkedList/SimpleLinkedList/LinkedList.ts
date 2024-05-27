import StructBase from "../../StructBase/StructBase";
import { Node } from "../../Node/Node";

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
    while (tmpNode?.link) {
      str += `${tmpNode.data} -> `;
      tmpNode = tmpNode.link;
    }
    str += `${tmpNode?.data}`;
    return str;
  }

  push(value: Node) {
    if (!this.isEmpty()) value.link = this._top;
    this._top = value;
    this.size++;
  }

  append(value: Node) {
    if (this.isEmpty()) return this.push(value);

    let tmpNode = this._top;
    while (tmpNode?.link) tmpNode = tmpNode.link;
    if (!tmpNode) return;
    tmpNode.link = value;
    this.size++;
  }

  insert(value: Node, index: number = 0) {
    if (this.isEmpty() || index === 0) return this.push(value);
    if (index > this.size || index === -1) return this.append(value);
    index = 0 > index ? this.size + index : index;

    let tmpNode = this._top;
    for (let idx = 0; idx < index - 1; idx++) {
      if (!tmpNode?.link) break;
      tmpNode = tmpNode.link;
    }

    if (!tmpNode) return;
    value.link = tmpNode.link;
    tmpNode.link = value;
    this.size++;
  }

  at(index: number): Node {
    if (this.isEmpty()) return { data: -1, link: undefined };
    if (0 > index) index = this.size + index;
    else if (this.size < index) index = this.size - 1;

    let tmpNode = this._top;
    for (let idx = 0; idx < index; idx++) {
      if (!tmpNode?.link) break;
      tmpNode = tmpNode.link;
    }
    return tmpNode ? tmpNode : { data: -1, link: undefined };
  }

  pop(): Node {
    if (this.isEmpty() || !this._top) return { data: -1, link: undefined };
    let tmpNode = this._top;
    this._top = tmpNode.link;
    this.size--;
    return tmpNode;
  }

  remove(): Node {
    if (this.isEmpty() || !this._top) return { data: -1, link: undefined };
    let tmpNode = this._top;
    while (tmpNode.link?.link) tmpNode = tmpNode.link;

    let rmNode = tmpNode.link?.link;
    tmpNode.link = undefined;
    this.size--;
    return rmNode ? rmNode : { data: -1, link: undefined };
  }

  removeAt(index: number): Node {
    if (this.isEmpty() || !this._top) return { data: -1, link: undefined };
    if (0 > index) index = this.size + index;
    else if (this.size < index) index = this.size - 1;

    let tmpNode = this._top;
    for (let idx = 0; idx < index - 1; idx++) {
      if (!tmpNode.link) break;
      tmpNode = tmpNode.link;
    }

    let rmNode = tmpNode.link?.link;
    tmpNode.link = undefined;
    this.size--;
    return rmNode ? rmNode : { data: -1, link: undefined };
  }
}
