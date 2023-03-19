#ifndef PWMS_H /* include guards */
#define PWMS_H

#include <Arduino.h>

void setupPWMs();

void changePWM(uint16_t dc);

#endif /* PWMS_H */