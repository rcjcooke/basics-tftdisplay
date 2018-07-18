#ifndef _XC4629_TFT_H
#define _XC4629_TFT_H

#include <Arduino.h>
#include <utility/Adafruit_ST7735.h>

class XC4629_TFT : public Adafruit_ST7735 {
public:
  XC4629_TFT(uint8_t CS, uint8_t RS, uint8_t RST, uint8_t rotation);

  // Have to override setRotation since WIDTH and HEIGHT can't be changed on the underlying class
  void setRotation(uint8_t x);

  void begin();

  static const uint8_t XC4629_TFTWIDTH = 128;
  static const uint8_t XC4629_TFTHEIGHT = 128;

};

#endif // _XC4629_TFT_H