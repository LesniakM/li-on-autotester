#include <gpio_manager.h>

GpioManager::GpioManager()
{
  pinMode(enableChargePin, OUTPUT);
  pinMode(enableDischargePin, OUTPUT);
  pinMode(buttonPin, INPUT);
  _chargeState = false;
  digitalWrite(enableChargePin, _chargeState);
  _dischargeState = false;
  digitalWrite(enableDischargePin, _dischargeState);
}

void GpioManager::enableCharge()
{
  if (_dischargeState == true) 
  {
    disableDischarge();
    delay(25);
  };
  _chargeState = true;
  digitalWrite(enableChargePin, _chargeState);
}

void GpioManager::disableCharge() 
{
  _chargeState = false;
  digitalWrite(enableChargePin, _chargeState);
}

void GpioManager::enableDischarge()
{
  if (_chargeState == true) 
  {
    disableCharge();
    delay(25);
  };
  _dischargeState = true;
  digitalWrite(enableDischargePin, _dischargeState);
}

void GpioManager::disableDischarge() 
{
  _dischargeState = false;
  digitalWrite(enableDischargePin, _dischargeState);
}

bool GpioManager::getButtonState()
{
  return digitalRead(buttonPin);
}

bool GpioManager::getChargeState()
{
  return _chargeState;
}

bool GpioManager::getDischargeState()
{
  return _dischargeState;
}
