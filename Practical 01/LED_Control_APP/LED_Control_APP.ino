#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>
#include <analogWrite.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define led_y 12
String item = "0";
WiFiServer server(80);

LiquidCrystal_I2C mylcd(0x27,16,2);

void setup() {
  Serial.begin(115200);
  mylcd.init();
  mylcd.backlight();
  pinMode(led_y, OUTPUT);
  connect_to_WiFi("Divor Automations","automations2021");
}

void loop() {
  led_req();
}
