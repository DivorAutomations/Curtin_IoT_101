void temperature_read(){
  float t = dht.readTemperature();
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  mylcd.setCursor(0, 0);
  mylcd.print("T = "+String(t));

}

void humidity_read(){
  float h = dht.readHumidity();
  Serial.print(F("Humidity: "));
  Serial.print(h);
  mylcd.setCursor(0, 1);
  mylcd.print("H = "+String(h));
}
