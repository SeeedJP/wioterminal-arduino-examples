// BOARD Seeed Wio Terminal
// GROVE(Right) <-> Grove - Button (SKU#101020003)

#include <GroveDriverPack.h>  // https://github.com/SeeedJP/GroveDriverPack

#define INTERVAL    (100)

GroveBoard Board;
GroveButton Button(&Board.GroveD0);

void setup() {
  Serial.begin(115200);
  while(!Serial);
  delay(200);

  Board.GroveD0.Enable();
  Button.Init();
}

void loop() {
  bool buttonState = Button.IsOn();
  Serial.print(buttonState ? '*' : '.');
  
  delay(INTERVAL);
}
