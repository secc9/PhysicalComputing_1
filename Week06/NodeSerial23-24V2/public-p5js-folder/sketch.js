// Create connection to Node.JS Server
const socket = io();

// Create variables from sensors we expect
let sensor1, sensor2;

// Connect to Node.JS Server
socket.on("connect", () => {
  console.log(socket.id);
});

// Callback function on the event we disconnect
socket.on("disconnect", () => {
  console.log(socket.id);
});

// Callback function to recieve message from Node.JS
socket.on("message", (_message) => {
  console.log(_message);
  sensor1 = _message.sensor3;
  sensor2 = _message.sensor4;
});

function setup() {
  createCanvas(1280, 720);
}

function draw() {
  // Draw basic sketch to show the data we're recieving
  background(map(sensor1, 0, 1000, 0, 255));
  fill(255);
  ellipse(50, 50, 80, 80);
  fill(map(sensor2, 0, 1000, 0, 255), 0, 255);
  ellipse(200, 50, 80, 80);
}

function mouseDragged() {
  // Send message back to Arduino
  socket.emit("message", {
    xpos: (mouseX / width) * 180,
    ypos: (mouseY / height) * 180,
  });
}
