#include <HCSR04.h>
#include <Servo.h>

Servo myServo;
int pos = 0;
byte triggerPin = 12;
byte echoPin = 11;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
HCSR04.begin(triggerPin, echoPin);
myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
double* distances = HCSR04.measureDistanceCm();

Serial.print("1: ");
Serial.print(distances[0]);
Serial.println(" cm");

Serial.println("---");
delay(250);

if(distances[0] >= 10){
  myServo.write(0);
  }else{
    myServo.write(180);
    }
}
