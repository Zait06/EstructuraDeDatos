import Queue from "./Queue";
import * as readline from "readline";
import { stdin as input, stdout as output } from "node:process";

var queue: Queue;

const menu = [
  "1. Enqueue",
  "2. Dequeue",
  "3. Show head",
  "4. Show tail",
  "5. Print queue",
  "6. Exit",
];

const rl = readline.createInterface({ input, output });

const closeAll = () => {
  rl.close();
  process.exit();
};

const action = (option: number) => {
  console.clear();
  switch (option) {
    case 1:
      break;
    case 2:
      console.log("Dequeue:", queue.dequeue());
      break;
    case 3:
      console.log("Head:", queue.head());
      break;
    case 4:
      console.log("Tail", queue.tail());
      break;
    case 5:
      console.log(queue.toString());
      break;
    case 6:
      return closeAll();
    default:
      console.log("Option doesn't exists. Please, try again.\n");
      break;
  }
  if (option !== 1) return showMenu();
  rl.question("Write a value: ", (answer) => {
    queue.enqueue(parseInt(answer));
    showMenu();
  });
};

const showMenu = () => {
  console.log("Choose an option: ");
  menu.forEach((e) => {
    console.log(`${e}`);
  });
  rl.question("Type an option: ", (answer) => {
    action(parseInt(answer));
  });
};

console.log("\tStatic Queue\n");
rl.question("Queue size: ", (answer) => {
  queue = new Queue(parseInt(answer));
  showMenu();
});
