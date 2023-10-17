
int pushButton = 2;
int ledPin = 13;
int buttonState = 0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pushButton, INPUT);
pinMode(ledPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

int buttonState = digitalRead(pushButton);
if(buttonState == HIGH){
Serial.println(buttonState);
digitalWrite(ledPin, HIGH);
delay(1);

}

}
