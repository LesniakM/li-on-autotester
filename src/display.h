#ifndef DISPLAY_H /* include guards */
#define DISPLAY_H

#include <stdint.h>

void setupDisplay();

void drawStaticDisplayElements();

void updateDisplayTemperature(float temperature);

void updateDisplayVoltage(uint16_t voltage);

void updateDisplayCurrent(int16_t current);

#endif /* DISPLAY_H */