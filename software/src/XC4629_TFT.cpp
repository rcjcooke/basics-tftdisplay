#include "XC4629_TFT.hpp"

XC4629_TFT::XC4629_TFT(uint8_t CS, uint8_t RS, uint8_t RST, uint8_t rotation) 
  : Adafruit_ST7735(CS, RS, RST) {
  setRotation(rotation);
}

void XC4629_TFT::begin() {
  initG();
}

void XC4629_TFT::setRotation(uint8_t x) {
  rotation = (x & 3);
  switch(rotation) {
   case 0:
   case 2:
    _width  = XC4629_TFTWIDTH;
    _height = XC4629_TFTHEIGHT;
    break;
   case 1:
   case 3:
    _width  = XC4629_TFTHEIGHT;
    _height = XC4629_TFTWIDTH;
    break;
  }
}