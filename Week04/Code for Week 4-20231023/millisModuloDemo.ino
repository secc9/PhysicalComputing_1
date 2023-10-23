// FadeWithMillis
// This sketch uses millis(), modulo (%) and map()
// to dim an LED without using delay();

void setup() {
  Serial.begin(9600);
}

void loop() {
  int counter = millis()%4000; // 0-4000
  int negativeCounter = counter-2000; // -2000-2000
  int loopingCounter = abs(negativeCounter); // 2000-0-2000
  
  Serial.print(counter);
  Serial.print(" : ");
  Serial.print(negativeCounter);
  Serial.print(" : ");
  Serial.println(loopingCounter);
  
  analogWrite(2,map(loopingCounter,0,2000,0,255));
}
