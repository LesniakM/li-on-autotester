/*
  Display uses:

  Universal 8bit Graphics Library (https://github.com/olikraus/u8g2/)

  Copyright (c) 2016, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

*/

#include <U8x8lib.h>
#include <display.h>
#include <Wire.h>

constexpr uint8_t INFO_ROW = 0;
constexpr uint8_t INFO_COL = 0;
constexpr uint8_t CAPACITY_ROW = 0;
constexpr uint8_t VOLTAGE_ROW = 1;
constexpr uint8_t CURRENT_ROW = 2;
constexpr uint8_t TEMP_ROW = 3;

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

void setupDisplay() {
  u8x8.begin();
  u8x8.clear();
  u8x8.setFont(u8x8_font_artossans8_r);
}

void drawStaticDisplayElements() {
  u8x8.drawString(0, CAPACITY_ROW,"     IR:    mOhm");
  u8x8.drawString(0, VOLTAGE_ROW, "Voltage:      mV");
  u8x8.drawString(0, CURRENT_ROW, "Current:      mA");
  u8x8.drawString(0, TEMP_ROW,    "   Temp:");
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.drawString(0, TEMP_ROW,    "   ");
}

void updateDisplayCapacity(uint16_t capacity) {
  char scap[5];
  itoa(capacity, scap, 10);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(9, CAPACITY_ROW, "   ");
  u8x8.drawString(8, CAPACITY_ROW, scap);
}

void updateDisplayVoltage(uint16_t voltage) {
  char svolt[5];
  itoa(voltage, svolt, 10);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(9, VOLTAGE_ROW, "    ");
  u8x8.drawString(8, VOLTAGE_ROW, svolt);
}

void updateDisplayCurrent(int16_t current) {
  char scurr[5];
  itoa(current, scurr, 10);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(9, CURRENT_ROW, "    ");
  u8x8.drawString(8, CURRENT_ROW, scurr);
}

void updateDisplayTemperature(float temperature) {
  char stemp[6];
  dtostrf(temperature, 3, 1, stemp);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(8, TEMP_ROW, stemp);
  u8x8.drawString(15, TEMP_ROW, "C");
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.drawGlyph(14, TEMP_ROW, 176);
}


/**
 * Prints state code on display.
 *
 * 0 - OK
 * 1 - CHG
 * 2 - DCH
 * 3 - IDL
 * 4 - IR
 * 5 - II
 * 6 - HOP
 * 7 - HCL
 * 99 - 
 * default - ERR
 */
void updateDisplayState(uint8_t state) {
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  switch (state)
  {
  case 0:
    u8x8.drawString(INFO_COL, INFO_ROW, "OK ");
    break;
  case 1:
    u8x8.drawString(INFO_COL, INFO_ROW, "CHG");
    break;
  case 2:
    u8x8.drawString(INFO_COL, INFO_ROW, "DCH");
    break;
  case 3:
    u8x8.drawString(INFO_COL, INFO_ROW, "IDL");
    break;
  case 4:
    u8x8.drawString(INFO_COL, INFO_ROW, "IR ");
    break;
  case 5:
    u8x8.drawString(INFO_COL, INFO_ROW, "II ");
    break;
  case 6:
    u8x8.drawString(INFO_COL, INFO_ROW, "HOP");
    break;
  case 7:
    u8x8.drawString(INFO_COL, INFO_ROW, "HCL");
    break;
  case 99:
    u8x8.drawString(INFO_COL, INFO_ROW, "   ");
    break;
  case 101:
    u8x8.drawString(INFO_COL, INFO_ROW, " I ");
    break;
  case 102:
    u8x8.drawString(INFO_COL, INFO_ROW, "II ");
    break;
  case 103:
    u8x8.drawString(INFO_COL, INFO_ROW, "III");
    break;
  case 104:
    u8x8.drawString(INFO_COL, INFO_ROW, "IV ");
    break;
  case 105:
    u8x8.drawString(INFO_COL, INFO_ROW, " V ");
    break;
  case 106:
    u8x8.drawString(INFO_COL, INFO_ROW, " VI");
    break;
  case 107:
    u8x8.drawString(INFO_COL, INFO_ROW, " ^ ");
    break;
  case 100:
    u8x8.drawString(INFO_COL, INFO_ROW, " X ");
    break;
  default:
    u8x8.drawString(INFO_COL, INFO_ROW, "ERR");
    break;
  }
}