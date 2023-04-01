#include <holder.h>


Holder::Holder(PwmManager* pwmManagerPtr, GpioManager* gpioPtr, OledDisplay* displayPtr)
{
  position = 0;
  pwmMng = pwmManagerPtr;
  gpio = gpioPtr;
}

void Holder::open()
{
  _setServoPos(open_pos);
  delay(100);
  turnOffServo();
}


void Holder::close()
{
  _setServoPos(close_pos);
  delay(100);
  turnOffServo();
}

void Holder::prepareToClose()
{
  _setServoPos(prepare_pos);
  delay(100);
  turnOffServo();
}

void Holder::closeABitMore()
{
  if (position < 100) {
    position+=2;
    _setServoPos(position);
    delay(50);
    turnOffServo();
  }
}

/**
 * Slowly closes holder until cell is locked.
 *
 * @return Returns true if cell is present in holder in correct polarity or false otherwise.
 */
bool Holder::closeWithCellSensing(uint16_t senseCurrent)
{ 
  bool currentSenseStarted = false;
  uint8_t position = open_pos;
  uint16_t voltage = 0;
  _setServoPos(position);
  gpio->disableAll();
  delay(250);

  // Voltage sense loop
  for (position; position<=100; position+=4)
  { 
    _setServoPos(position);
    voltage = INA226::getVoltage();
    display->updateDisplayVoltage(voltage);
    // Stop when voltage is weird. (too small but not 0)
    if (50 < voltage & voltage < 2000)                         
    {
      open();
      return false;
    }
    // Stop when voltage is weird. (too big)
    else if (voltage > 4400)                                        
    {
      open();
      return false;
    }
    // Proceed to current sensing if voltage is OK.
    else if (2000 <= voltage & voltage <= 4400 & currentSenseStarted == 0)  
    { 
      for (int i=0; i<4; i++)
      {
        position+=6;
        _setServoPos(position);
      }
      currentSenseStarted = true;
      break;
    }
  }

  if (currentSenseStarted) {
    gpio->enableDischarge();
    pwmMng->changePWMdc(3, 1, senseCurrent);
    int16_t current = 0;
    display->updateDisplayCurrent(current);
    // Current sense loop
    for (position; position<=100; position++)
    {
      _setServoPos(position);
      current = INA226::getCurrent();

      // Return true and close even harder when current is acceptable:
      if (-current > 5 & -current < 50)
      { 
        gpio->disableAll();
        pwmMng->changePWMdc(3, 1, 0);
        closeABitMore();
        turnOffServo();
        return true;
      }
      // Return false and open when current is too big:
      else if (-current >= 50) {
        gpio->disableAll();
        pwmMng->changePWMdc(3, 1, 0);
        open();
        return false;
      }
    } 
  }

  // Open when holder is empty or cell is dead and return false:
  open();
  gpio->disableAll();
  return false;
}

void Holder::turnOffServo() {
  pwmMng->changePWMdc(2, 2, 45000);
}

void Holder::setRawPos(uint16_t raw_val) {
  pwmMng->changePWMdc(2, 2, raw_val);
}

void Holder::_setServoPos(uint8_t pos) {
  if (0 <= pos <= 100)
  { 
    uint16_t delay_time = abs(position-pos)*10+25;
    position = pos;
    uint16_t val_to_send = (((servoMaxPosCompare - servoMinPosCompare) * pos) / 100) + servoMinPosCompare;
    pwmMng->changePWMdc(2, 2, val_to_send);
    delay(delay_time);
  }
}
