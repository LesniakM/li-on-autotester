/*
Servo pwm freq = 50Hz
Servo pwm overflow = 45000

1 / 50Hz = 0.02s = 20ms - full cycle

1ms  ---> 1/20 * 45000 = 2250   - min servo pos dc
2ms  ---> 2/20 * 45000 = 4500   - max servo pos dc
*/

#ifndef HOLDER_H
#define HOLDER_H

#include <Arduino.h>
#include <display.h>
#include <gpio_manager.h>
#include <ina226.h>
#include <pwm_manager.h>

constexpr uint8_t close_pos {100};
constexpr uint8_t prepare_pos {60};
constexpr uint8_t open_pos {0};

constexpr uint16_t servoMinPosCompare {2250};
constexpr uint16_t servoMaxPosCompare {4500};

class Holder
{
public:
  Holder(PwmManager* pwmManagerPtr, GpioManager* gpioPtr, OledDisplay* displayPtr);
  void open();
  void close();

  bool closeWithCellSensing(uint16_t senseCurrent = 10);

  void prepareToClose();
  void closeABitMore();

  void turnOffServo();

  void setRawPos(uint16_t raw_val);
private:
  void _setServoPos(uint8_t pos);
  uint8_t position;
  PwmManager* pwmMng;
  GpioManager* gpio;
  OledDisplay* display;
};

#endif