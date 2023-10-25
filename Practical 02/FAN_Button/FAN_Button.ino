#include <analogWrite.h>
#define fanPin1 19
#define fanPin2 18
#define button1 16
#define button2 27

void setup() {
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  bool buttonState1 = digitalRead(button1);
  bool buttonState2 = digitalRead(button2);

  if (buttonState1 == LOW){
    clockwise();
  }
  if(buttonState2 == LOW){
    counter_clockwise();
  }
  if(buttonState1 == HIGH && buttonState2 == HIGH){
    fan_off();
  }
}
