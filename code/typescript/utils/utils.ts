import * as readline from "readline";
import { stdin as input, stdout as output } from "node:process";

export const readlineInterface = readline.createInterface({ input, output });

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

export function showMenu(options: Array<String>, worker: CallableFunction) {
  console.log("Choose an option: ");
  options.forEach((elem, idx) => {
    console.log(`${idx + 1}.- ${elem}`);
  });
  readlineInterface.question("Type an option: ", (answer) => {
    worker(parseInt(answer));
  });
}

export function closeAll() {
  readlineInterface.close();
  process.exit();
}
