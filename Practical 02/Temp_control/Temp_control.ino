#include "DHT.h"
#include <analogWrite.h>
#define fanPin1 19
#define fanPin2 18
#define DHTPIN 17
#define DHTTYPE DHT11

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  Serial.begin(115200);
  dht.begin();
  mylcd.init();
  mylcd.backlight();
}

void loop() {
  float temp = temperature_read();

  if(temp > 29){
    fan_on();
  }else{
    fan_off();
  }
}
