// Import Libraries
#include <ArduinoJson.h>
#include <Servo.h>

String inputString = "";      // A String to hold incoming data
bool stringComplete = false;  // A Boolean for whether the string is complete

// Initialise Servos
Servo servo1;  
Servo servo2;

void setup() {
  // Initialize Serial port
  Serial.begin(57600);

  // Attach Servos to Pins
  servo1.attach(9);
  servo2.attach(10);
  
}

void loop() {
  
  // If statement runs when a full message has been revcieved from p5.js
  if (stringComplete) {
    // Setup a space in memory for the message we are recieving
    DynamicJsonDocument  in(200);
    deserializeJson(in, inputString);

    // Make variables from recieved values
    int pos1 = in["xpos"];
    int pos2 = in["ypos"];

    // Set the Servos from the recieved values
    servo1.write(pos1);
    servo2.write(pos2);
    
    // Empty input string once we are done
    inputString = "";
    stringComplete = false;
  
    // Setup a space in memory for the message we want to send back to P5.js
    DynamicJsonDocument  out(200);
    
    // Add data from sensors to message
    out["sensor3"] = analogRead(A0);
    out["sensor4"] = analogRead(A1);
    
    // Generate the minified JSON and send it to the Serial port.
    String jsonOut;
    // Convert the message to a serial string
    serializeJson(out, jsonOut);
    // Send the string over serial to node.js for it to be passed to p5.js
    Serial.println(jsonOut);
  }
}

// Function like setup and loop, runs when we are getting data over serial
void serialEvent() {
  while (Serial.available()) {
    // Get the new byte
    char inChar = (char)Serial.read();
    // Add it to the inputString
    inputString += inChar;
    // If the incoming character is a newline, set a flag so the main loop can
    // Do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
