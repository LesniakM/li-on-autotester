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

#include <display.h>
#include <string>

constexpr uint8_t INFO_ROW = 3;
constexpr uint8_t INFO_COL = 0;
constexpr uint8_t CAPACITY_ROW = 0;
constexpr uint8_t VOLTAGE_ROW = 1;
constexpr uint8_t CURRENT_ROW = 2;
constexpr uint8_t TEMP_ROW = 3;

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

OledDisplay::OledDisplay() {
  u8x8.begin();
  u8x8.clear();
  drawSplashScreen();
  drawStaticDisplayElements();
}

void OledDisplay::drawSplashScreen(){
  u8x8.setFont(u8x8_font_8x13B_1x2_r);
  u8x8.drawString(0, 0, "     Dotigo     ");
  delay(750);
  u8x8.drawString(0, 2, "P r e s e n t s ");
  delay(750);
  u8x8.drawString(0, 0, "     LI-ION     ");
  u8x8.drawString(0, 2, "   AUTOTESTER   ");
  delay(750);
  clear();
}

void OledDisplay::clear(){
  u8x8.clear();
}

void OledDisplay::drawStaticDisplayElements() {
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.drawString(0, CAPACITY_ROW,"Capacit:     mAh");
  u8x8.drawString(0, VOLTAGE_ROW, "Voltage:      mV");
  u8x8.drawString(0, CURRENT_ROW, "Current:      mA");
  u8x8.drawString(0, TEMP_ROW,    "            T:  ");
}

void OledDisplay::updateDisplayCapacity(uint16_t capacity) {
  char scap[5];
  u8x8.setFont(u8x8_font_artossans8_r);
  itoa(capacity, scap, 10);
  u8x8.drawString(9, CAPACITY_ROW, "   ");
  u8x8.drawString(8, CAPACITY_ROW, scap);
}

void OledDisplay::updateDisplayVoltage(uint16_t voltage) {
  char svolt[5];
  u8x8.setFont(u8x8_font_artossans8_r);
  itoa(voltage, svolt, 10);
  u8x8.drawString(9, VOLTAGE_ROW, "    ");
  u8x8.drawString(8, VOLTAGE_ROW, svolt);
}

void OledDisplay::updateDisplayCurrent(int16_t current) {
  char scurr[5];
  u8x8.setFont(u8x8_font_artossans8_r);
  itoa(current, scurr, 10);
  u8x8.drawString(9, CURRENT_ROW, "    ");
  u8x8.drawString(8, CURRENT_ROW, scurr);
}

void OledDisplay::updateDisplayTemperature(float temperature) {
  char stemp[3]; // 6 for decimal point
  u8x8.setFont(u8x8_font_artossans8_r);
  itoa(int(temperature), stemp, 10);
  //dtostrf(temperature, 3, 1, stemp);
  u8x8.drawString(14, TEMP_ROW, stemp);
  // u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  // u8x8.drawGlyph(14, TEMP_ROW, 176);
  // u8x8.drawString(15, TEMP_ROW, "C");
}


/**
 * Prints state code on display.
 *
 * 0 - OK
 * 1 - CHG CC
 * 2 - CHG CV
 * 3 - Wait
 * 4 - DSC CC
 * 5 - IR TST
 * 6 - HOP
 * 7 - HCL
 * 99 - 
 * default - ERR
 */
void OledDisplay::updateDisplayState(uint8_t state) {
  u8x8.setFont(u8x8_font_artossans8_r);
  switch (state)
  {
  case 0:
    u8x8.drawString(INFO_COL, INFO_ROW, "  OK  ");
    break;
  case 1:
    u8x8.drawString(INFO_COL, INFO_ROW, "CHG CC");
    break;
  case 2:
    u8x8.drawString(INFO_COL, INFO_ROW, "CHG CV");
    break;
  case 3:
    u8x8.drawString(INFO_COL, INFO_ROW, "Wait: ");
    break;
  case 4:
    u8x8.drawString(INFO_COL, INFO_ROW, "DSC CC");
    break;
  case 5:
    u8x8.drawString(INFO_COL, INFO_ROW, "IR TST");
    break;
  case 6:
    u8x8.drawString(INFO_COL, INFO_ROW, " HOP  ");
    break;
  case 7:
    u8x8.drawString(INFO_COL, INFO_ROW, " HCL  ");
    break;
  case 99:
    u8x8.drawString(INFO_COL, INFO_ROW, "      ");
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
  case 201:
    u8x8.drawString(INFO_COL, INFO_ROW, "Cr low");
    break;
  case 202:
    u8x8.drawString(INFO_COL, INFO_ROW, "V err ");
    break;
  default:
    u8x8.drawString(INFO_COL, INFO_ROW, " ERR  ");
    break;
  }
}

/**
 * Prints time in info_row.
 *
 * @param minutes
 * @param seconds
 */
void OledDisplay::updateClock(uint8_t minutes, uint8_t seconds) {
  u8x8.setFont(u8x8_font_artossans8_r);
  std::string text = "";
  text += std::to_string(minutes);
  if (text.length() < 2) text.insert(0, "0");
  text += ":";
  text += std::to_string(seconds);
  if (text.length() < 5) text.insert(text.size()-1, "0");
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(5, INFO_ROW, text.c_str());
}

/**
 * Clears area where time is normally diplayed.
 *
 */
void OledDisplay::clearClock() {
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(5, INFO_ROW, "     ");
}