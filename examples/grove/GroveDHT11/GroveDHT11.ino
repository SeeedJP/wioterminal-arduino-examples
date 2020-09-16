// BOARD Seeed Wio Terminal
// GROVE(Right) <-> Grove - Temperature & Humidity Sensor (DHT11) (SKU#101020011)

#include <GroveDriverPack.h>  // https://github.com/SeeedJP/GroveDriverPack

#define INTERVAL    (2000)

GroveBoard Board;
GroveTempHumiDHT11 TempHumi(&Board.GroveD0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(200);

  Board.GroveD0.Enable();
  TempHumi.Init();
}

void loop() {
  TempHumi.Read();
  
  Serial.print("Current humidity = ");
  Serial.print(TempHumi.Humidity);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(TempHumi.Temperature);
  Serial.println("C");

  delay(INTERVAL);
}
