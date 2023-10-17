
/*
 * 
 ******************************************************
                     Ashley Sagar
                 Physical Computing 1
                  Week 02 homework

                    Make a button

*****************************************************
                  Instructions from VLE
                  

********************************************************
Inspiration taken from the 1971 book, The Dice Man, by Luke Rhinehart.


https://en.wikipedia.org/wiki/The_Dice_Man



Instead of rolling a dice to make a decision we instead have a more 
computational method of green and red. Go and stop.

To make a decision simply press the button and wait for the response
of the lights.


***********************************************
Help with the code taken from 

https://www.learnrobotics.org/blog/random-leds-arduino/

accesed 23_10_17





********************************************************
*
*
* Steps I need to do in this code?
* My Logic????????
* 1. push a button
* 2. a delay happens to create the illusion of suspense with the machine making its choice
* 3. an LED is randomly selected 
* 4. the chosen LED continues blinking until the button is pressed again
* 
* 
*********************************************************************
**********************************************************************
*
*
*                 BUGS SO FAR
*
*       Light randomly flashes so it doesnt really work
*       
*       I need to work out how to store the random choice somewhere
*       and then load that and that stored data then gets recalled.
*       
*       I am a bad programmer and my logic is bad
*       

*/




//these are the constants for the pin numbers
const int buttonPin = 2;
const int ledPinGreen = 11;
const int ledPinRed = 12;

int buttonState = 0;
void setup() {
  // put your setup code here, to run once:


  pinMode(buttonPin, INPUT); //init pushbutton pin as input on pin 2
  
  pinMode(ledPinGreen, OUTPUT); // init ledPin as output
  pinMode(ledPinRed, OUTPUT); 





}

void loop() {
  // put your main code here, to run repeatedly:






random_led();



}



//this function randomly chooses a blinking light

void random_led(){

  
  int random_led = random(11, 13); // randomly choose either pin 12 or 13


  //read state of pushbutton value
  buttonState = digitalRead(buttonPin);

delay(2000); // add a delay untill the led blinks



for(int i = 0; i < 1; i ++){
digitalWrite(random_led+i, HIGH);
delay(500);
digitalWrite(random_led+i, LOW);
delay(500);
}

}
