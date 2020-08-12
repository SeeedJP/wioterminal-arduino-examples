#include <WiFiClientSecure.h>
#include <HttpClient.h> // https://github.com/amcewen/HttpClient

const char* WIFI_SSID     = "";
const char* WIFI_PASSWORD = "";

const char* SERVER_HOST = "www.example.com";
const int   SERVER_PORT = 443;
const char* SERVER_PATH = "/";

const int REPEAT_INTERVAL = 10000; // [msec.]

const char* ROOT_CA = \
  "-----BEGIN CERTIFICATE-----\n"
  "MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh\n"
  "MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3\n"
  "d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD\n"
  "QTAeFw0wNjExMTAwMDAwMDBaFw0zMTExMTAwMDAwMDBaMGExCzAJBgNVBAYTAlVT\n"
  "MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j\n"
  "b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IENBMIIBIjANBgkqhkiG\n"
  "9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4jvhEXLeqKTTo1eqUKKPC3eQyaKl7hLOllsB\n"
  "CSDMAZOnTjC3U/dDxGkAV53ijSLdhwZAAIEJzs4bg7/fzTtxRuLWZscFs3YnFo97\n"
  "nh6Vfe63SKMI2tavegw5BmV/Sl0fvBf4q77uKNd0f3p4mVmFaG5cIzJLv07A6Fpt\n"
  "43C/dxC//AH2hdmoRBBYMql1GNXRor5H4idq9Joz+EkIYIvUX7Q6hL+hqkpMfT7P\n"
  "T19sdl6gSzeRntwi5m3OFBqOasv+zbMUZBfHWymeMr/y7vrTC0LUq7dBMtoM1O/4\n"
  "gdW7jVg/tRvoSSiicNoxBN33shbyTApOB6jtSj1etX+jkMOvJwIDAQABo2MwYTAO\n"
  "BgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUA95QNVbR\n"
  "TLtm8KPiGxvDl7I90VUwHwYDVR0jBBgwFoAUA95QNVbRTLtm8KPiGxvDl7I90VUw\n"
  "DQYJKoZIhvcNAQEFBQADggEBAMucN6pIExIK+t1EnE9SsPTfrgT1eXkIoyQY/Esr\n"
  "hMAtudXH/vTBH1jLuG2cenTnmCmrEbXjcKChzUyImZOMkXDiqw8cvpOp/2PV5Adg\n"
  "06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF\n"
  "PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls\n"
  "YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk\n"
  "CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=\n"
  "-----END CERTIFICATE-----\n";

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
  Serial.println(WiFi.localIP());
  Serial.println();
}
 
void loop() {
  unsigned long startTime = millis();

  Serial.print("Connecting to ");
  Serial.println(SERVER_HOST);
  
  WiFiClientSecure client;
  HttpClient http(client);
  int ret;
  int contentLength;

  client.setCACert(ROOT_CA);
  
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
