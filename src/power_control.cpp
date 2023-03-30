#include <power_control.h>

void setupChargeDischargePins() 
{
  pinMode(enableChargePin, OUTPUT);
  pinMode(enableDischargePin, OUTPUT);
  digitalWrite(enableChargePin, LOW);
  digitalWrite(enableDischargePin, LOW);
}

void connectionSenseDischarge() 
{
  changePWMdc(3, 1, current_5);
  digitalWrite(enableChargePin, LOW);
  digitalWrite(enableDischargePin, HIGH);
}

void setDischargeCurrent(uint16_t current) 
{
  digitalWrite(enableChargePin, LOW);
  delay(25);
  changePWMdc(3, 1, current);
  digitalWrite(enableDischargePin, HIGH);
}

void setChargeCurrent(uint16_t current) 
{
  changePWMdc(3, 2, current);
  digitalWrite(enableDischargePin, LOW);
  delay(25);
  digitalWrite(enableChargePin, HIGH);
}

void adjustDischargeCurrent(uint16_t current) 
{
  changePWMdc(3, 1, current);
}

void holdDischarge() 
{
  changePWMdc(3, 1, 0);
}

void disableDischarge() {
  digitalWrite(enableDischargePin, LOW);
  changePWMdc(3, 1, 0);
}

void disableCharge() {
  digitalWrite(enableChargePin, LOW);
}