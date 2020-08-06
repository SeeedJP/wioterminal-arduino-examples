#include <WiFiClientSecure.h>
#include <PubSubClient.h> // https://github.com/SeeedJP/pubsubclient

const char* WIFI_SSID     = "";
const char* WIFI_PASSWORD = "";

const char* MQTT_SERVER_HOST = "192.168.1.106";
const int   MQTT_SERVER_PORT = 8883;

const char* MQTT_ID       = "id";
const char* MQTT_USERNAME = "name";
const char* MQTT_PASSWORD = "";

const char* OUT_TOPIC = "outTopic";
const char* IN_TOPIC  = "inTopic";

const int REPEAT_INTERVAL = 1000; // [msec.]

const char* ROOT_CA = \
  "-----BEGIN CERTIFICATE-----\n"
  "MIIDwzCCAqugAwIBAgIUAVBcWFKDzdNC3+VirLApjpYRBoswDQYJKoZIhvcNAQEL\n"
  "BQAwcTELMAkGA1UEBhMCSlAxDjAMBgNVBAgMBUFpY2hpMREwDwYDVQQKDAhDQW1h\n"
  "c3RlcjENMAsGA1UECwwEVEVTVDESMBAGA1UEAwwJbG9jYWxob3N0MRwwGgYJKoZI\n"
  "hvcNAQkBFg10ZXN0QHRlc3QuY29tMB4XDTIwMDcyMDA3MDUyMloXDTI1MDcyMDA3\n"
  "MDUyMlowcTELMAkGA1UEBhMCSlAxDjAMBgNVBAgMBUFpY2hpMREwDwYDVQQKDAhD\n"
  "QW1hc3RlcjENMAsGA1UECwwEVEVTVDESMBAGA1UEAwwJbG9jYWxob3N0MRwwGgYJ\n"
  "KoZIhvcNAQkBFg10ZXN0QHRlc3QuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8A\n"
  "MIIBCgKCAQEA5CkRYYHY6Mzy69ESnYfyOyVbCYl4QNWj8T/E1eLIWS6RZH8jmKvG\n"
  "iyPnT6DLC3I4dqxt+g8a4Ytu8I4qtvImGEtx+v2g7vbTzI87gZv+XEu0/TUP/5fH\n"
  "FdpUJKA6kaoGBGZeHP2gfY9qvBZGw5cUTH1UpCQz9OY2UIyjh/jXdmnzhPCABabp\n"
  "gTprR0hiR1FAKD9s/OwvP1HDGt1W0ZREdj/SiboY8skJUs/agN/+tQaogf9PryrE\n"
  "j2+NY4uXya6pu5B/YDR0UqY7L1mI2soj8GvCEkH2QPaVVyLWT7zaK8wk2CtPvWVj\n"
  "C1MPyXp4i30LL26tbCQYBAepwHYbhGrAUwIDAQABo1MwUTAdBgNVHQ4EFgQUU9a6\n"
  "m5dbcTtKDjX317m9bh8/WnIwHwYDVR0jBBgwFoAUU9a6m5dbcTtKDjX317m9bh8/\n"
  "WnIwDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAe7sx2Fw+Kgow\n"
  "ZSsM5Jt1ACOz048DHRDHwVsEcPsKfLPiAIxyaoCfMNrtKZ8U9sxfA5fprm8y/RjU\n"
  "TbcURvDI6AC9mFdvjNiZZrg6/BS/J8QGZtZcdIcJGe+CZy7Qc05s2dhFqXHQ5F7p\n"
  "2JbmCktZGaK3EatxgkofVCFJ/kGS6nZfphMAQGiKM6ickUslzR/8ajAKJ17zb/fT\n"
  "+rPIE3FofDFJNvJu1AydGfQJsB0fMP5WuHVK/z5bAodgGD+KqzH8XIFplaMsjSLX\n"
  "EZY6pU4q3/EG0lR7GINdQcrm7DpDfAd+IpC6XmUHk+eT4Aw/0BaTVDpwTVae7rTi\n"
  "Tg4Tvqd2ag==\n"
  "-----END CERTIFICATE-----\n";

static WiFiClientSecure Client;
static PubSubClient Mqtt;

void setup()
{
  Serial.begin(115200);
  while (!Serial);
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

  Client.setCACert(ROOT_CA);
  
  Mqtt.setServer(MQTT_SERVER_HOST, MQTT_SERVER_PORT);
  Mqtt.setCallback(callback);
  Mqtt.setClient(Client);
}

void loop()
{
  if (!Mqtt.connected())
  {
    Serial.print("Connecting to ");
    Serial.println(MQTT_SERVER_HOST);
  
    if (!Mqtt.connect(MQTT_ID, MQTT_USERNAME, MQTT_PASSWORD))
    {
      Serial.println("ERROR: Mqtt.connect()");
      goto stop;
    }
    Mqtt.subscribe(IN_TOPIC);
  }

  char data[100];
  sprintf(data, "{\"uptime\":%lu}", millis() / 1000);
  Serial.print("Publish:");
  Serial.println(data);
  Mqtt.publish(OUT_TOPIC, data);
  Serial.println("Published");

stop:
  unsigned long next = millis();
  while (millis() < next + REPEAT_INTERVAL) Mqtt.loop();
}

void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Subscribe:");
  for (int i = 0; i < length; i++) Serial.print((char)payload[i]);
  Serial.println();
}
