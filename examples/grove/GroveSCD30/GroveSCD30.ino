// BOARD Seeed Wio Terminal
// GROVE(Left) <-> Grove - CO2 & Temperature & Humidity Sensor for Arduino (SCD30) - 3-in-1 (SKU#101020634)

#include <GroveDriverPack.h>  // https://github.com/SeeedJP/GroveDriverPack

#define INTERVAL    (100)

GroveBoard Board;
GroveSCD30 Sensor(&Board.GroveI2C1);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(200);

  Board.GroveI2C1.Enable();
  if (!Sensor.Init())
  {
    Serial.println("Sensor not found.");
  }
}

void loop() {
  if (Sensor.ReadyToRead())
  {
    Sensor.Read();
  
    Serial.print("Current humidity = ");
    Serial.print(Sensor.Humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(Sensor.Temperature);
    Serial.print("C  ");
    Serial.print("CO2 concentration = ");
    Serial.print(Sensor.Co2Concentration);
    Serial.println("ppm");
  }

  delay(INTERVAL);
}
