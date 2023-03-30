#ifndef SERVO_CONTROL_H /* include guards */
#define SERVO_CONTROL_H

#include <stdint.h>

constexpr uint8_t close_pos {60};
constexpr uint8_t open_pos {15};

void openHolder(uint8_t pos = open_pos);

void closeHolderRouglhy(uint8_t pos = close_pos);

void closeHolderTighter();

void setServoPos(uint8_t servo, uint8_t pos);


#endif /* SERVO_CONTROL_ */