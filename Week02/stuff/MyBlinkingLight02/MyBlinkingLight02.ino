void setup() {
  // put your setup code here, to run once:

pinMode(13, OUTPUT); //blue LED
pinMode(12, OUTPUT); //green LED
pinMode(10, OUTPUT); // red led
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(13, 1);
delay(1000/3);
digitalWrite(12, 1);
delay(1000);
digitalWrite(13, 0);
delay(1000/2);
digitalWrite(12, 0);
delay(1000);
digitalWrite(10, 1);


}
