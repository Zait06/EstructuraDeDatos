import { Node } from "../../Node/Node";

export default interface LinkedListInterface {
  insert(value: Node, index: number): void;
  push(value: Node): void;
  append(value: Node): void;
  at(index: number): Node | undefined;
  removeAt(index: number): Node | undefined;
  removeFirst(): Node | undefined;
  removeLast(): Node | undefined;
}
