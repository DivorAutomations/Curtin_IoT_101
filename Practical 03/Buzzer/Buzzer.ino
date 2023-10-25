#include <ESP32Tone.h>
#define buzzer 25

void setup() {
  pinMode(buzzer,OUTPUT);
}

void loop() {
  //parameters: pin, freqency, delay, channel
  tone(buzzer,900,250,0);
  tone(buzzer,0,250,0);
}
