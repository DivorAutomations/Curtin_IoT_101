#include <analogWrite.h>
#define fanPin1 19
#define fanPin2 18

void setup() {
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
}

void loop() {
  fan_on();
  delay(5000);
  fan_off();
  delay(5000);

}
