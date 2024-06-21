export default abstract class StructBase {
  protected size: number = 0;

  constructor() {}

  /**
   * Return if the struct is empty.
   * @returns is empty the struct
   */
  abstract isEmpty(): boolean;

  /**
   * Return if the struct is full
   * @returns is full the struct
   */
  abstract isFull(): boolean;

  abstract toString(): string;
}
