#ifndef GPIO_MANAGER_H /* include guards */
#define GPIO_MANAGER_H

#include <Arduino.h>

constexpr uint8_t enableDischargePin {13};   // PB15
constexpr uint8_t enableChargePin {14};      // PB14
constexpr uint8_t buttonPin {31};            // PB11

class GpioManager
{ 
public:
  GpioManager();
  void enableDischarge();
  void disableDischarge();
  void enableCharge();
  void disableCharge();
  bool getButtonState();
  bool getChargeState();
  bool getDischargeState();

private:
  bool _chargeState;
  bool _dischargeState;
};

#endif  /* GPIO_MANAGER_H */