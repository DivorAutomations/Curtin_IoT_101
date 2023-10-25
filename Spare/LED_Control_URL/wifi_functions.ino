
void connect_to_network(char* ssid, char* pass) {
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  mylcd.setCursor(0, 0);
  mylcd.print("Connected");
  mylcd.setCursor(0, 1);
  mylcd.print("ip:");
  mylcd.print(WiFi.localIP());
  server.begin();
  MDNS.addService("http", "tcp", 80);
}

void listen_to_requests() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while (client.connected() && !client.available()) {
    delay(1);
  }
  String req = client.readStringUntil('\r');
  int addr_start = req.indexOf(' ');
  int addr_end = req.indexOf(' ', addr_start + 1);
  if (addr_start == -1 || addr_end == -1) {
    Serial.print("Invalid request: ");
    Serial.println(req);
    return;
  }
  req = req.substring(addr_start + 1, addr_end);
  item = req;
  Serial.println(item);
  String s;
  if (req == "/")  //Browser accesses address can read the information sent by the client.println(s);
  {
    IPAddress ip = WiFi.localIP();
    String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
    s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>Hello from ESP32 at ";
    s += ipStr;
    s += "</html>\r\n\r\n";
    Serial.println("Sending 200");
    client.println(s);  //Send the string S, you can read the information when visiting the address of E smart home using a browser.
    //client.print(s);
  }
  if (req == "/led/on")  //Browser accesses the ip address/led/on
  {
    client.println("turn on the LED");
    digitalWrite(led_y, HIGH);
  }
  if (req == "/led/off")  //Browser accesses the ip address/led/off
  {
    client.println("turn off the LED");
    digitalWrite(led_y, LOW);
  }
  if (req == "/fan/on")  //Browser accesses the ip address/fan/on
  {
    client.println("turn on the fan");
    digitalWrite(fanPin1, LOW);  //pwm = 0
    analogWrite(fanPin2, 180);
  }
  if (req == "/fan/off")  //Browser accesses the ip address/fan/off
  {
    client.println("turn off the fan");
    digitalWrite(fanPin1, LOW);  //pwm = 0
    analogWrite(fanPin2, 0);
  }
  //client.print(s);
  client.stop();
}