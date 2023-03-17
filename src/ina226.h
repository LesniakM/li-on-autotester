#ifndef INA226_H /* include guards */
#define INA226_H

#include <stdint.h>
#define INA_ADDRESS 0x40
#define INA_BUS_CURRENT_REG 0x1
#define INA_BUS_VOLTAGE_REG 0x2
#define BUS_VOLTAGE_MULTIPLER 1.25   // 0.00125 for [V], 1.25 for [mV]
#define BUS_CURRENT_MULTIPLER 0.25   // 0.00025 for [A], 0.25 for [mA]

int16_t _readIna226Register(uint8_t register_address);

uint16_t getVoltage();

int16_t getCurrent();

#endif /* INA226_H */