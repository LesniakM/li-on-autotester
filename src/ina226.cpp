#include <ina226.h>


/**
 * Reads INA226 module bus voltage / cell voltage.
 *
 * @return Voltage value in [mV]
 */
uint16_t INA226::getVoltage()
{
  int samples {20};
  float value;
  for (int i=0; i<samples; i++)
  {    
    value += _readIna226Register(INA_BUS_VOLTAGE_REGISTER)*BUS_VOLTAGE_MULTIPLER;
  }
  value = value / samples;
  return (uint16_t)value;
}

/**
 * Reads INA226 shunt voltage, that is later converted to current. Negative values are discharge, positive are charging.
 *
 * @return Current value in [mA]
 */
int16_t INA226::getCurrent()
{   
  int samples {80};
  float value;
  for (int i=0; i<samples; i++)
  {
    value += _readIna226Register(INA_BUS_CURRENT_REGISTER)*BUS_CURRENT_MULTIPLER;
  }
  value = value / samples;
  return (int16_t)value;
}

/**
 * Reads INA226 from selected address. Do not use directly.
 *
 * @return Raw integer value.
 */
int16_t INA226::_readIna226Register(uint8_t register_address)
{
  int16_t value;
  uint16_t status;
  Wire.beginTransmission(INA_ADDRESS);
  Wire.write(register_address);
  Wire.endTransmission();

  Wire.requestFrom(INA_ADDRESS, (uint8_t)2);
  uint8_t vha = Wire.read();
  uint8_t vla = Wire.read();

  value = vha << 8 | vla;

  return value;
}