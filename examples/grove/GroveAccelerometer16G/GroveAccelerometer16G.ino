// BOARD Seeed Wio Terminal
// GROVE(Left) <-> Grove - 3-Axis Digital Accelerometer(±16g) (SKU#101020054)

#include <GroveDriverPack.h>  // https://github.com/SeeedJP/GroveDriverPack

#define INTERVAL    (100)

GroveBoard Board;
GroveAccelerometer16G Accel(&Board.GroveI2C1);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(200);

  Board.GroveI2C1.Enable();
  if (!Accel.Init())
  {
    Serial.println("Sensor not found.");
  }
}

void loop() {
  Accel.Read();

  Serial.print(Accel.X);
  Serial.print(' ');
  Serial.print(Accel.Y);
  Serial.print(' ');
  Serial.println(Accel.Z);

  delay(INTERVAL);
}
