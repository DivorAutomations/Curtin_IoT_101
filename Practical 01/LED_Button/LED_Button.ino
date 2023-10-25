void setup() {
  pinMode(12,OUTPUT);
  pinMode(16,INPUT);
}

void loop() {
  bool buttonState = digitalRead(16);
  
  digitalWrite(12,!buttonState);

  //Or use a IF statement
  
//  if(buttonState == LOW){
//    digitalWrite(12,HIGH);
//  }else{
//    digitalWrite(12,LOW);
//  }
}
