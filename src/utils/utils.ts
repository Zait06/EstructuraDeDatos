/**
 * Fix the index with the size given
 * @param index The position of element
 * @param size The number of elements in the struct
 * @returns Index as positive value between 0 to size - 1
 */
export function fixIndex(index: number, size: number): number {
  if (index > size) index = -1;
  if (0 > index) index = size + index;
  if (index > size || 0 > index) index = 0;
  return index;
}
