


//  Ashley Sagar
//  Week 03 homework
// 
// 
//  A box that subverts?

//  This box has a noise happening when it's closed but when you approach and open the
//  lid the noise ceases.
//

// Most of the code below has been adapted from the example files AnalogInOutSerial and ]
//  Servo Sweep.


#include <Servo.h>


//code taken from servo example
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;    // variable to store the servo position


// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)




void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  // declare the ledPin as an OUTPUT:

  Serial.begin(9600);
}

void loop() {



  /////LDR functionality ** taken from analogIOSerial

    // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 200, 800, 0, 255); // here I changed the sensor value to something that works better with the servo
  
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);


//  The only thing I really did with this code was to add the forloops into an
//  if and else conditional and change the rotation value.
if(sensorValue < 20){
    for (pos = 0; pos <= 10; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 40; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
  else{
       for (pos = 0; pos <= 0; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1500);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 0; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    
    }
  
}
