#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define fanPin1 19
#define fanPin2 18
#define led_y 12

String item = "0";

WiFiServer server(80);

LiquidCrystal_I2C mylcd(0x27, 16, 2);

void setup() {
  pinMode(led_y, OUTPUT);
  pinMode(fanPin1, OUTPUT);
  pinMode(fanPin2, OUTPUT);
  Serial.begin(115200);
  mylcd.begin();
  mylcd.backlight();
  connect_to_network("Divor Automations", "automations2021");
}

void loop() {
  listen_to_requests();
}
