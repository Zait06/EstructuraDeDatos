export default abstract class StructBase {
  protected size: number = 0;

  constructor() {}

  abstract isEmpty(): boolean;
  abstract isFull(): boolean;
  abstract toString(): string;
}
