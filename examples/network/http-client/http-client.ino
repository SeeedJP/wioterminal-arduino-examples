#include <AtWiFi.h>
#include <HttpClient.h> // https://github.com/amcewen/HttpClient

const char* WIFI_SSID     = "";
const char* WIFI_PASSWORD = "";

const char* SERVER_HOST = "192.168.1.106";
const int   SERVER_PORT = 80;
const char* SERVER_PATH = "/index.html";

const int REPEAT_INTERVAL = 10000; // [msec.]

void setup() {
  Serial.begin(115200);
  while(!Serial); // Wait for Serial to be ready
  delay(1000);
  
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.println("Connected.");
  
  Serial.print("IP Address: ");
  Serial.println (WiFi.localIP());
  Serial.println();
}

void loop() {
  unsigned long startTime = millis();
  
  Serial.print("Connecting to ");
  Serial.println(SERVER_HOST);
  
  WiFiClient client;
  HttpClient http(client);
  int ret;
  int contentLength;
  
  if ((ret = http.get(SERVER_HOST, SERVER_PORT, SERVER_PATH)) != HTTP_SUCCESS) {
    Serial.print("ERROR: http.get() ");
    Serial.println(ret);
    goto stop;
  }
  
  if ((ret = http.responseStatusCode()) != 200) {
    Serial.print("ERROR: http.responseStatusCode() ");
    Serial.println(ret);
    goto stop;
  }
  if ((ret = http.skipResponseHeaders()) != HTTP_SUCCESS) {
    Serial.print("ERROR: http.skipResponseHeaders() ");
    Serial.println(ret);
    goto stop;
  }
  contentLength = http.contentLength();
  
  Serial.println("---");
  while (contentLength--)
  {
    while (http.available() == 0) delay(1);
    Serial.print((char)http.read());
  }
  Serial.println();
  Serial.println("---");

stop:
  http.stop();

  Serial.print("Elapsed ");
  Serial.println(millis() - startTime);

  delay(REPEAT_INTERVAL);
  Serial.println();
}
