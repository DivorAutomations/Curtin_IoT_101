#include "DHT.h"
#define DHTPIN 17
#define DHTTYPE DHT11

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C mylcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  mylcd.init();
  mylcd.backlight();
}

void loop() {
  delay(2000);
  humidity_read();
  temperature_read();

}
