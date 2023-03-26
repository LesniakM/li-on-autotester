#ifndef PWMS_H /* include guards */
#define PWMS_H

#include <Arduino.h>

void setupPWMs();

void changePWMdc(uint8_t timer, uint8_t channel, uint16_t compareVal);

#endif /* PWMS_H */