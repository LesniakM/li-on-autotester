#include <mcp4725.h>


MCP4725::MCP4725(uint8_t MCP4725_ADDRESS)
{
  i2c_address = MCP4725_ADDRESS;
}

void MCP4725::setVoltage(uint16_t value) {
  last_value = value*DIVIDER_MULTIPLIER;
  Wire.beginTransmission(i2c_address);
  Wire.write(64);                             // Command to update the DAC
  Wire.write(last_value >> 4);         // the 8 most significant bits.
  Wire.write((last_value & 15) << 4);  // the 4 least significant bits.
  Wire.endTransmission();
}

void MCP4725::increaseVoltage() {
  last_value++;
  setVoltage(last_value);
}

void MCP4725::decreaseVoltage() {
  last_value--;
  setVoltage(last_value-1);
}
