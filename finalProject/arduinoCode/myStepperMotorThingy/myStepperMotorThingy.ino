//Includes the Arduino Stepper Library
#include <Stepper.h>
#include <HCSR04.h>

// Defines the number of steps per rotation
const int stepsPerRevolution = 2038;

// Creates an instance of stepper class
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);


//setup distance sensor

byte triggerPin = 12;
byte echoPin = 13;

void setup() {
    // Nothing to do (Stepper Library sets pins as outputs)

     Serial.begin(9600);
  HCSR04.begin(triggerPin, echoPin);
}

void loop() {

    double* distances = HCSR04.measureDistanceCm();
  
  Serial.print("1: ");
  Serial.print(distances[0]);
  Serial.println(" cm");
  
  Serial.println("---");
  //delay(250);



  
  // Rotate CW slowly at 5 RPM

//  if()
  myStepper.setSpeed(1);
  myStepper.step(stepsPerRevolution);
//  delay(1000);
  
//  // Rotate CCW quickly at 10 RPM
//  myStepper.setSpeed(10);
//  myStepper.step(-stepsPerRevolution);
//  delay(1000);
}
