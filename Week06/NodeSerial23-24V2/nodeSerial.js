// Import Libraries and Setup

const arduinoPort = "/dev/tty.usbmodem2101";

const os = require("node:os");
const { SerialPort } = require("serialport");
const { DelimiterParser } = require("@serialport/parser-delimiter");
const open = require("open");

const express = require("express");
const app = express();
const http = require("http");
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);

let openedPage = false;
let waitForData = 5;

console.log("Welcome to Phys Comp 1");
console.log("\x1b[1;32mThis code connects your Arduino to P5.js.\x1b[0m");
console.log(
  `❗\x1b[1;31mPlease don't edit this code other than to change the address of your Arduino.\x1b[0m❗`
);

// Tell our Node.js Server to host our P5.JS sketch from the public folder.
app.use(express.static("public-p5js-folder"));

switch (os.platform()) {
  case "darwin":
    console.log("Running on macOS");
    console.log(
      "The address of your Arduino will look like \x1b[1;32m/dev/cu.usbmodem11301\x1b[0m"
    );
    break;
  case "linux":
    console.log("Running on Linux");
    console.log(
      "The address of your Arduino will look like \x1b[1;32m/dev/cu.usbmodem11301\x1b[0m"
    );
    break;
  case "win32":
    console.log("Running on Windows");
    console.log(
      "The address of your Arduino will look like \x1b[1;32mCOM1\x1b[0m"
    );
    break;
  default:
    console.log("Unknown OS");
}

// Setup Our Node.js server to listen to connections from chrome, and open chrome when it is ready
server.listen(3000, () => {
  console.log("listening on *:3000");

  // Move this to only happen once arduino connection is fine.
  //open("http://localhost:3000", { app: "chrome" });
});

// Setup directional messages
let webToArd = {};
let ardToWeb;

let msgPerSecUp = 0;
let msgPerSecDown = 0;

let printEveryMessage = 0; // 0 - Report Message Every Second, 1 - Every message conveyed

// Create a port that connects to our Arduino

const port = new SerialPort({
  path: arduinoPort, // Set this to the name of the port your Arduino is connected to
  baudRate: 57600, // Leave this at this level
});

port.on("error", (err) => {
  console.error(
    `There was an error with the Serial Port: \x1b[31m${err.message}\x1b[0m`
  );
  if (
    err.message.includes("No such file or directory") ||
    err.message.includes("Unknown error code 3") ||
    err.message.includes("File not found")
  ) {
    console.log(
      "........................................................................"
    );
    console.error(
      `\x1b[1;31mEither your arduino is disconnected, or the port ${arduinoPort} is incorrect.\x1b[0m`
    );
    console.log("Try one of these...");
    SerialPort.list()
      .then((ports) => {
        ports.forEach((port) => {
          console.log(port.path);
        });
        process.exit();
      })
      .catch((err) => {
        console.error("Error listing serial ports:", err);
        process.exit();
      });
  }
  if (
    err.message.includes("Access denied") ||
    err.message.includes("Resource busy")
  ) {
    console.log(
      "........................................................................"
    );
    console.error(
      `\x1b[1;31mIt looks like there is a Serial Monitor open, please close it and try again.\x1b[0m`
    );
    process.exit();
  }
});

// Callback function for what to do when our P5.JS sketch connects and sends us messages
io.on("connection", (socket) => {
  console.log("a user connected");
  // Code to run every time we get a message from P5.JS
  socket.on("message", (_msg) => {
    // Save it to our Function
    webToArd = _msg;
    // Print it to the Console
    if (printEveryMessage == 1) {
      console.log(_msg);
    }
  });
  socket.on("disconnect", (reason) => {
    if (io.engine.clientsCount == 0) {
      console.error(
        `\x1b[1;31mAll P5.js Sketches Closed ... Closing Node.js\x1b[0m`
      );
      process.exit();
    }
  });
});
// Setup the function that listens for Data from the Arduino
const parser = port.pipe(new DelimiterParser({ delimiter: "\n" }));

// Callback function that runs when we get data from Arduino
parser.on("data", (_data) => {
  // Unpack the Data from the Arduino
  try {
    ardToWeb = JSON.parse(_data);
  } catch (error) {
    //console.log(error.message);
    if (error.message.includes("Unexpected token")) {
      console.log(
        "........................................................................"
      );
      console.error(
        `\x1b[1;31mThe Arduino is successfully connected but it is sending messages that aren't JSON encoded.\x1b[0m`
      );
      console.error(
        `\x1b[1;31mThis is probably because you have an extra Serial.println() somewhere in your code.\x1b[0m`
      );
    }
    process.exit();
  }

  // Send it to P5.js
  io.emit("message", ardToWeb);

  // Print it to COnsole
  if (printEveryMessage == 1) {
    console.log(ardToWeb);
  }
  msgPerSecUp++;
});

// Runs Once Per second and reports on message frequency
setInterval(() => {
  console.log("Report Up: " + msgPerSecUp + " Down: " + msgPerSecDown);

  if (msgPerSecDown > 40 && msgPerSecUp > 40 && !openedPage) {
    console.log("Opening Page");
    openedPage = true;
    open("http://localhost:3000", { app: "chrome" });
  }
  if (msgPerSecUp == 0 && waitForData != 0) {
    waitForData--;
  }

  if (waitForData == 0) {
    console.log(
      "........................................................................"
    );
    console.error(
      `\x1b[1;31mThe Arduino is successfully connected but it isn't sending any messages.\x1b[0m`
    );
    console.error(
      `\x1b[1;31mThis might be because you are using too many delay() functions or have deleted the Serial.println() command.\x1b[0m`
    );
    process.exit();
  }

  msgPerSecUp = 0;
  msgPerSecDown = 0;
}, 1000);

// Runs 50 times per second, Sends message to Arduino
// Set Timeout because Arduino Mega won't respond to serial messages if we send messages too soon after opening the port.
setTimeout(() => {
  setInterval(() => {
    // Convert message from web to String and send it
    port.write(JSON.stringify(webToArd));

    // Write a new line to finish message
    port.write("\n");

    msgPerSecDown++;
  }, 20);
}, 1000);
