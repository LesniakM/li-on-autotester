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

#define CAPACITY_ROW 0
#define VOLTAGE_ROW 1
#define CURRENT_ROW 2
#define TEMP_ROW 3

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE, /* clock=*/ SCL, /* data=*/ SDA);

void setupDisplay() {
  u8x8.begin();
  u8x8.clear();
  u8x8.setFont(u8x8_font_artossans8_r);
}

void drawStaticDisplayElements() {
  u8x8.drawString(0, CAPACITY_ROW,"Capaci: None mAh");
  u8x8.drawString(0, VOLTAGE_ROW, "Voltage:      mV");
  u8x8.drawString(0, CURRENT_ROW, "Current:      mA");
  u8x8.drawString(0, TEMP_ROW,    "   Temp:");
}

void updateDisplayCapacity(uint16_t capacity) {
  char scap[5];
  itoa(capacity, scap, 10);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(9, CAPACITY_ROW, scap);
}

void updateDisplayVoltage(uint16_t voltage) {
  char svolt[5];
  itoa(voltage, svolt, 10);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(10, VOLTAGE_ROW, "   ");
  u8x8.drawString(9, VOLTAGE_ROW, svolt);
}

void updateDisplayCurrent(int16_t current) {
  char scurr[5];
  itoa(current, scurr, 10);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(10, CURRENT_ROW, "   ");
  u8x8.drawString(9, CURRENT_ROW, scurr);
}

void updateDisplayTemperature(float temperature) {
  char stemp[6];
  dtostrf(temperature, 3, 1, stemp);
  u8x8.setFont(u8x8_font_artossans8_r);
  u8x8.drawString(9, TEMP_ROW, stemp);
  u8x8.drawString(15, TEMP_ROW, "C");
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);
  u8x8.drawGlyph(14, TEMP_ROW, 176);
}