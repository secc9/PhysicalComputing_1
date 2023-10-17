


const int buttonPin = 2;
const int ledPin = 13;


int buttonState = 0;




void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    //turn led on:
    digitalWrite(ledPin, HIGH);
    delay(1000);
    }else{
      //turn led off
      digitalWrite(ledPin, LOW);
      }

}
