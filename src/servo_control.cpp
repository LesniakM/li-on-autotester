#include <servo_control.h>
#include <pwms.h>
#include <Arduino.h>

#define servoMinPosCompare 1125
#define servoMaxPosCompare 5625
uint8_t current_pos {50};


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

void turnOffServoMotor() {
  changePWMdc(2, 2, 0);
}

void openHolder(uint8_t pos) {
  setServoPos(1, pos);
  delay(abs(current_pos-pos)*10+10);
  current_pos = pos;
  turnOffServoMotor();
}

void closeHolderRouglhy(uint8_t pos) {
  setServoPos(1, pos);
  delay(abs(current_pos-pos)*10+10);
  current_pos = pos;
  turnOffServoMotor();
}

void closeHolderTighter() {
  current_pos++;
  setServoPos(1, current_pos);
  delay(30);
  turnOffServoMotor();
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