#define PIR 14

void setup() {
  pinMode(PIR,INPUT);  
  Serial.begin(115200);
}

void loop() {
  bool PIR_status = digitalRead(PIR);
  Serial.println(PIR_status);
  delay(200);
}
