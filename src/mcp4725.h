#ifndef MCP4725_H /* include guards */
#define MCP4725_H

#include <stdint.h>

/* Voltage divider is used to improve voltage step size:

    MCP4725  OUT
              |
              R1
              |
              ------ IN - adjustable load input
              |
              R2
              |
             GND
*/

#define DIVIDER_MULTIPLIER 2    // Voltage is divided by two, so output is multiplied by 2.

#define MCP4725_ADDRESS 0x60

void setVoltage(uint16_t value);

void increaseVoltage();

void decreaseVoltage();

#endif /* MCP4725_H */