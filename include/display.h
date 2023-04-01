#ifndef DISPLAY_H /* include guards */
#define DISPLAY_H

#include <stdint.h>
#include <U8x8lib.h>

class OledDisplay
{
public:
  OledDisplay();
  void drawStaticDisplayElements();
  void updateDisplayCapacity(uint16_t capacity);
  void updateDisplayTemperature(float temperature);
  void updateDisplayVoltage(uint16_t voltage);
  void updateDisplayCurrent(int16_t current);
  void updateDisplayState(uint8_t state);
};

#endif /* DISPLAY_H */