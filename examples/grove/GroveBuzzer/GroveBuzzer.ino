// BOARD Seeed Wio Terminal
// GROVE(Right) <-> Grove - Buzzer (SKU#107020000)

#include <GroveDriverPack.h>  // https://github.com/SeeedJP/GroveDriverPack

#define BUZZER_ON_TIME  (200)
#define BUZZER_OFF_TIME (800)

GroveBoard Board;
GroveBuzzer Buzzer(&Board.GroveD0);

void setup() {
  delay(200);

  Board.GroveD0.Enable();
  Buzzer.Init();
}

void loop() {
  Buzzer.On();
  delay(BUZZER_ON_TIME);

  Buzzer.Off();
  delay(BUZZER_OFF_TIME);
}
