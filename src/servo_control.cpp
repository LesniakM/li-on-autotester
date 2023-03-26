#include <servo_control.h>
#include <pwms.h>
#include <Arduino.h>

#define servoMinPosCompare 1125
#define servoMaxPosCompare 5625
#define close_pos 72
#define open_pos 15


void setServoPos(uint8_t servo, uint8_t pos) {
  if (0 <= pos <= 100)
  {
    uint16_t val_to_send = ((servoMaxPosCompare - servoMinPosCompare) * pos) / 100 + 1125;
    switch (servo)
    {
    case 1:
      changePWMdc(2, 2, val_to_send);
      break;
    case 2:
      changePWMdc(2, 3, val_to_send);
      break;
    case 3:
      changePWMdc(2, 4, val_to_send);
      break;
    default:
      break;
    }
  }
}

void openHolder() {
  setServoPos(1, open_pos);
  delay(500);
  changePWMdc(2, 2, 0);
}

void closeHolder() {
  setServoPos(1, close_pos);
  delay(500);
  changePWMdc(2, 2, 0);
}

/*
void openHolder() {
  if (CONTROL_TYPE == 1) {openSTM32F103();}
  else if (CONTROL_TYPE == 2) {openESP32();}
}

void closeHolder() {
  if (CONTROL_TYPE == 1) {closeSTM32F103();}
  else if (CONTROL_TYPE == 2) {closeESP32();}
}

void openSTM32F103() {
  holder_servo.attach(servoPin);
  holder_servo.write(open_pos);
  delay(250);
	holder_servo.detach();
}

void openESP32() {
  holder_servo.setPeriodHertz(50);
	holder_servo.attach(servoPin, 500, 2400);
  holder_servo.write(open_pos);
  delay(250);
	holder_servo.detach();
}

void closeSTM32F103() {
  holder_servo.attach(servoPin);
  holder_servo.write(close_pos);
  delay(250);
	holder_servo.detach();
}

void closeESP32() {
  holder_servo.setPeriodHertz(50);
	holder_servo.attach(servoPin, 500, 2400);
  holder_servo.write(close_pos);
  delay(250);
	holder_servo.detach();
}
*/