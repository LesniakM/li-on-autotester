#include <holder.h>


Holder::Holder(PwmManager* pwmManager)
{
  position = 0;
  pwmMng = pwmManager;
}

void Holder::open()
{
  _setServoPos(open_pos);
}


void Holder::close()
{
  _setServoPos(close_pos);
}

void Holder::prepareToClose()
{
  _setServoPos(prepare_pos);
}

void Holder::closeABitMore()
{
  if (position < 100) {
    position++;
    _setServoPos(position);
  }
}

void Holder::turnOffServo() {
  pwmMng->changePWMdc(2, 2, 0);
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
