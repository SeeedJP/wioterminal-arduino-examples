static int Count = 0;
  
void setup() {
  DisplayBegin();
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(WIO_KEY_A) == LOW) {
    Count += 1;
  }
  else if (digitalRead(WIO_KEY_B) == LOW) {
    Count += 10;
  }
  else if (digitalRead(WIO_KEY_C) == LOW) {
    Count += 100;
  }

  DisplayNumber(Count);
  
  delay(100);
}

////////////////////////////////////////////////////////////////////////////////
// Display

#include <TFT_eSPI.h>

static TFT_eSPI tft;

static void DisplayBegin()
{
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
}

static void DisplayClear()
{
  tft.fillScreen(TFT_BLACK);
}

static void DisplayNumber(int value)
{
  tft.setTextFont(4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawNumber(value, tft.width() / 2, tft.height() / 2);
}

////////////////////////////////////////////////////////////////////////////////
