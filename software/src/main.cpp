#include <Arduino.h>
#include <SPI.h>
#include <TFT.h>

static const uint8_t TFT_CS_PIN = 10;
static const uint8_t TFT_DC_PIN = 9;
static const uint8_t TFT_RST_PIN = 8;

TFT mTFTscreen = TFT(TFT_CS_PIN, TFT_DC_PIN, TFT_RST_PIN);

int xPos = 0;
char displayBuf[4];
  
void setup() {
  mTFTscreen.begin();
  // Set the display to be portrait
  mTFTscreen.setRotation(0);
  mTFTscreen.background(250, 16, 200);
  mTFTscreen.textSize(2);
}

void loop() {
  // Work out the numbers
  int sensor = analogRead(A0);
  int graphHeight = map(sensor, 0, 1023, 0, mTFTscreen.height());
  // Clear off existing text first
  mTFTscreen.stroke(250, 16, 200);
  mTFTscreen.text(displayBuf, 5, 5);
  
  // mTFTscreen.line(xPos, mTFTscreen.height() - graphHeight, xPos,
  //                 mTFTscreen.height());
  // Update text
  itoa(sensor, displayBuf, 10);  
  mTFTscreen.stroke(250, 250, 250);
  mTFTscreen.text(displayBuf, 5, 5);
  // Draw point
  mTFTscreen.stroke(250, 180, 10);
  mTFTscreen.point(xPos, mTFTscreen.height() - graphHeight);

  if (xPos >= 160) {
    xPos = 0;
    mTFTscreen.background(250, 16, 200);
  } else {
    xPos++;
  }
  delay(16);
}