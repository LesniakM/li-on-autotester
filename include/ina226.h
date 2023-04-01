#ifndef INA226_H
#define INA226_H

#include <Arduino.h>
#include <Wire.h>

constexpr uint8_t INA_ADDRESS {0x40};
constexpr uint8_t INA_BUS_CURRENT_REGISTER {0x1};
constexpr uint8_t INA_BUS_VOLTAGE_REGISTER {0x2};
constexpr float BUS_VOLTAGE_MULTIPLER {1.25F};    // 0.00125 for [V], 1.25 for [mV]
constexpr float BUS_CURRENT_MULTIPLER {0.25F};    // 0.00025 for [A], 0.25 for [mA]

class INA226
{
public:
  static uint16_t getVoltage();

  static int16_t getCurrent();

private:
  static int16_t _readIna226Register(uint8_t register_address);
};

#endif