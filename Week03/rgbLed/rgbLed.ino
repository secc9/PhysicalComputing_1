void setup() {
  // put your setup code here, to run once:

analogWrite(9, 0); //red
analogWrite(10, 0); //green
analogWrite(11, 255); //blue
delay(200);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//
//for(int i = 0; i < 255; i ++){
//  analogWrite(9, i); //red
//  analogWrite(10, i); //green
//  analogWrite(11, (255-i)/2); //blue
//  delay(15);
//  }
//
//
//
//for(int i = 255; i > 0; i --){
//  analogWrite(9, 255-i); //red
//  analogWrite(10, i); //green
//  analogWrite(11, i); //blue
//  delay(15);
//  }

//red up
for(int i = 0; i <255; i ++){
  analogWrite(9, i);
  analogWrite(10, 0);
  analogWrite(11, 0);
  delay(15);
  };


//green up

for(int i = 255; i > 0; i --){
  analogWrite(9, 0);
  analogWrite(10, i);
  analogWrite(11, 0);
  delay(15);
  };


  //blue up
for(int i = 0; i < 255; i ++){
  analogWrite(9, 0);
  analogWrite(10, 0);
  analogWrite(11, i);
  delay(15);
  };



//Serial.print()
}
