#ifndef SERVO_CONTROL_H /* include guards */
#define SERVO_CONTROL_H

#include <stdint.h>

void openHolder();

void closeHolder();

void setServoPos(uint8_t servo, uint8_t pos);


#endif /* SERVO_CONTROL_ */