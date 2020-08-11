#include <AceButton.h>    // https://github.com/bxparks/AceButton
using namespace ace_button;

#define NUM_BUTTON  (3)
static AceButton Buttons[NUM_BUTTON];

#define ID_A        (0)
#define ID_B        (1)
#define ID_C        (2)

static int Count = 0;

void setup() {
  DisplayBegin();
  DisplayNumber(Count);

  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);

  Buttons[0].init(WIO_KEY_A, HIGH, ID_A);
  Buttons[1].init(WIO_KEY_B, HIGH, ID_B);
  Buttons[2].init(WIO_KEY_C, HIGH, ID_C);
  
  ButtonConfig* buttonConfig = ButtonConfig::getSystemButtonConfig();
  buttonConfig->setEventHandler(ButtonEventHandler);
  buttonConfig->setFeature(ButtonConfig::kFeatureClick);
  buttonConfig->setFeature(ButtonConfig::kFeatureRepeatPress);
  buttonConfig->setFeature(ButtonConfig::kFeatureLongPress);
}

void loop() {
  for (int i = 0; i < NUM_BUTTON; ++i) {
    Buttons[i].check();
  }
}

static void ButtonEventHandler(AceButton* button, uint8_t eventType, uint8_t buttonState) {
  const uint8_t id = button->getId();

  switch (eventType) {
  case AceButton::kEventClicked:
    Count += (int)pow(10, id);
    DisplayNumber(Count);
    break;
  case AceButton::kEventRepeatPressed:
    if (id == ID_A || id == ID_B) {
      Count += (int)pow(10, id);
      DisplayNumber(Count);
    }
    break;
  case AceButton::kEventLongPressed:
    if (id == ID_C) {
      Count = 0;
      DisplayClear();
      DisplayNumber(Count);
    }
    break;
  }
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
