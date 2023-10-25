void connect_to_WiFi(const char* ssid, const char* pass) {
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Network");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
  Serial.println("TCP server started");
  MDNS.addService("http", "tcp", 80);
  mylcd.setCursor(0, 0);
  mylcd.print("ip:");
  mylcd.setCursor(0, 1);
  mylcd.print(WiFi.localIP());
  delay(5000);
  mylcd.clear();
}

void weather_station() {
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
    s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>ESP32 ip:";
    s += ipStr;
    s += "</html>\r\n\r\n";
    Serial.println("Sending 200");
    client.println(s);  //Send the string S, then you can read the information when visiting the address of E smart home using a browser.
  }
  if (req == "/temp/on") //Browser accesses address ip address/led/on
  {
    client.print(String(temp));
  }
  if (req == "/temp/off") //Browser accesses address ip address/led/off
  {

  }
  if (req == "/humidity/on") //Browser accesses address ip address/led/on
  {
    client.print(String(humi));
  }
  if (req == "/humidity/off") //Browser accesses address ip address/led/off
  {

  }
  client.stop();
}
