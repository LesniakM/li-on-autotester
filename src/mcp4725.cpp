#include <mcp4725.h>
#include <Wire.h>

uint16_t last_voltage_sent = 0;

void setVoltage(uint16_t value) {
  last_voltage_sent = value*DIVIDER_MULTIPLIER;
  Wire.beginTransmission(MCP4725_ADDRESS);
  Wire.write(64);                             // Command to update the DAC
  Wire.write(last_voltage_sent >> 4);         // the 8 most significant bits.
  Wire.write((last_voltage_sent & 15) << 4);  // the 4 least significant bits.
  Wire.endTransmission();
}

void increaseVoltage() {
  setVoltage(last_voltage_sent+1);
  last_voltage_sent++;
}

void decreaseVoltage() {
  setVoltage(last_voltage_sent-1);
  last_voltage_sent--;
}
