
const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0; 


void setup() {
  // put your setup code here, to run once:

pinMode(ledPin, OUTPUT); // led pin as an output
pinMode(buttonPin, INPUT); //pushbutton as an input



}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  //check if the pushbutton is pressed, if yes the state is high
  if(buttonState == HIGH){
    //turn led on
    digitalWrite(ledPin, HIGH);
    delay(2000);
    }else{
      //turn led off
      digitalWrite(ledPin, LOW);
      }

}
