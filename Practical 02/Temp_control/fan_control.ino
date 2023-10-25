void fan_on(){
  analogWrite(fanPin1,150);
  digitalWrite(fanPin2,LOW);
}

void fan_off(){
  analogWrite(fanPin1,0);
  analogWrite(fanPin2,0);
}

void counter_clockwise(){
  digitalWrite(fanPin1,LOW);
  analogWrite(fanPin2,150);
}
