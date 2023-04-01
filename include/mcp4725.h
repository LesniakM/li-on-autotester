#ifndef MCP4725_H /* include guards */
#define MCP4725_H

#include <Arduino.h>
#include <Wire.h>

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

constexpr uint8_t DIVIDER_MULTIPLIER {2};    // Voltage is divided by two, so output is multiplied by 2.
constexpr uint8_t MCP4725_ADDRESS {0x60};

class MCP4725 
{	
	MCP4725(uint8_t MCP4725_ADDRESS);

public:
	void setVoltage(uint16_t value);

	void increaseVoltage();

	void decreaseVoltage();

private:
	uint8_t i2c_address;
	uint16_t last_value {0};
};


#endif /* MCP4725_H */