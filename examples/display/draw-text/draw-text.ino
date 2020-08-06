#include <TFT_eSPI.h>

TFT_eSPI tft;

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  const int charWidth = tft.textWidth(" ");
  const int charNumOfWidth = tft.width() / charWidth;
  const int charHeight = tft.fontHeight();
  const int charNumOfHeight = tft.height() / charHeight;
  
  // Cross Line

  tft.drawLine(0, tft.height() / 2, tft.width(), tft.height() / 2, TFT_DARKGREY);
  tft.drawLine(tft.width() / 2, 0, tft.width() / 2, tft.height(), TFT_DARKGREY);

  // X-Axis
  
  tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
  tft.setTextDatum(TL_DATUM);
  for (int i = 0; i < charNumOfWidth; i += 10) {
    tft.drawNumber(i / 10, charWidth * i, 0);
  }
  for (int i = 0; i < charNumOfWidth; ++i) {
    tft.drawNumber(i % 10, charWidth * i, 0);
  }

  // Y-Axis

  tft.setTextColor(TFT_DARKGREY, TFT_BLACK);
  tft.setTextDatum(TL_DATUM);
  for (int i = 2; i < charNumOfHeight; ++i) {
    tft.drawNumber(i, 0, charHeight * i);
  }

  // Center

  tft.setTextColor(TFT_DARKGREEN, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  tft.drawString("Wio Terminal", tft.width() / 2, tft.height() / 2);
}

void loop() {
  static int count = -1;
  count = (count + 1) % 10000;
  String str{ StringFormat("%8d", count) };

  tft.setTextColor(TFT_BLACK, TFT_DARKGREY);
  tft.setTextDatum(BR_DATUM);
  tft.drawString(str, tft.width() - 1, tft.height() - 1);
  
  delay(100);
}

static String StringFormat(const char* format, ...)
{
  va_list arg;
  va_start(arg, format);
  const int len = vsnprintf(nullptr, 0, format, arg);
  char str[len + 1];
  vsnprintf(str, sizeof(str), format, arg);
  va_end(arg);

  return String(str);
}
