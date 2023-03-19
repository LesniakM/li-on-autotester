#include <servo_control.h>
#include <pwms.h>
#include <Arduino.h>

#define servoMinPosCompare 1125
#define servoMaxPosCompare 5625
#define close_pos 0
#define open_pos 100

void setServoPos(uint8_t pos) {
  if (0 <= pos <= 100){
    uint16_t val_to_send = ((servoMaxPosCompare - servoMinPosCompare) * pos) / 100 + 1125;
    changePWM(val_to_send);
  }
}

void openHolder() {
  setServoPos(open_pos);
  delay(250);
  changePWM(0);
}

void closeHolder() {
  setServoPos(close_pos);
  delay(250);
  changePWM(0);
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