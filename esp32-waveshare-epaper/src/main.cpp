#include <Arduino.h>
#include <Wire.h>
// graphic
#include <GxEPD2_GFX.h>
#include <Fonts/FreeMonoBold9pt7b.h>
// display
#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include "GxEPD2_display_selection_new_style.h"

void displayInit (CURRENT_DISPLAY_CLASS display){
  SPI.end();
  SPI.begin(13, 12, 14, 15);
  display.init(115200);
}

void drawCenteredText(CURRENT_DISPLAY_CLASS display, const char *text, uint8_t rotation = 1){
  display.setRotation(rotation);
  display.setFont(&FreeMonoBold9pt7b);
  int16_t tbx, tby; uint16_t tbw, tbh;
  display.getTextBounds(text, 0, 0, &tbx, &tby, &tbw, &tbh);
  // center bounding box by transposition of origin:
  uint16_t center_x = ((display.width() - tbw) / 2) - tbx; 
  uint16_t center_y = ((display.height() - tbh) / 2) - tby;
  display.setFullWindow();
  display.firstPage();
  Serial.print("Pointer text : ");
  Serial.println(text);
  do
  {
    display.fillScreen(GxEPD_WHITE);
    display.setCursor(center_x, center_y);
    display.setTextColor(GxEPD_BLACK);
    display.print(text);
  }
  while (display.nextPage());
}

void setup()
{
  //
  Serial.begin(115200);

  // release standard SPI pins
  displayInit(display);
  drawCenteredText(display, "Hello world!");
  display.hibernate();
}

void loop(){};