#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiClient.h>
#include <ESP32Tone.h>
#include <LiquidCrystal_I2C.h>
#define PIR 14
#define buzzer 25

String item = "0";
bool system_status;
WiFiServer server(80);

LiquidCrystal_I2C mylcd(0x27, 16, 2);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(PIR, INPUT);
  Serial.begin(115200);
  mylcd.init();
  mylcd.backlight();
  connect_to_WiFi("Divor Automations", "automations2021");
}

void loop() {
  secure_system();
  //  Serial.println(system_status);
  if (system_status == 1) {
    bool PIR_status = digitalRead(PIR);
    //    Serial.println(PIR_status);
    delay(200);
    if (PIR_status == 1) {
      tone(buzzer, 900, 250, 0);
      tone(buzzer, 0, 250, 0);
    }
  }
}
