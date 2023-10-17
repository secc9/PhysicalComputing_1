
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int ledPin = 13;

int buttonState1 = 0;
int buttonState2 = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT);
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

buttonState1 = digitalRead(buttonPin1);
buttonState2 = digitalRead(buttonPin2);

if(buttonState1 == HIGH && buttonState2 == HIGH){
  //turn led on
  digitalWrite(ledPin, 1);
  }else{
    digitalWrite(ledPin, 0);
    }
 
}
