// BOARD Seeed Wio Terminal
// GROVE(Right) <-> Grove - Rotary Angle Sensor (SKU#101020017)

#include <GroveDriverPack.h>  // https://github.com/SeeedJP/GroveDriverPack

#define INTERVAL    (100)

GroveBoard Board;
GroveRotaryAngle RotaryAngle(&Board.GroveA0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(200);

  Board.GroveA0.Enable();
  RotaryAngle.Init();
}

void loop() {
  RotaryAngle.Read();

  Serial.println(RotaryAngle.Volume);

  delay(INTERVAL);
}
