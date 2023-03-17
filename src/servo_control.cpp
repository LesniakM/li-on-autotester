#include <servo_control.h>
#include <Arduino.h>


#ifdef BOARD_STM32F103C8
  #include <Servo.h>
  #define servoPin PA5
  #define CONTROL_TYPE 1  // 1 for STM32F103, 2 for ESP32.
#endif 
#ifdef BOARD_ESP32C3
  #include <ESP32Servo.h>
  #include "esp32-hal-ledc.h"
  #define servoPin 2
  #define CONTROL_TYPE 2  // 1 for STM32F103, 2 for ESP32.
#endif 

#define close_pos 26
#define open_pos 180
Servo holder_servo;

void openHolder() {
  holder_servo.attach(servoPin);
  holder_servo.write(open_pos);
  delay(250);
	holder_servo.detach();
}

void closeHolder() {
  holder_servo.attach(servoPin);
  holder_servo.write(close_pos);
  delay(250);
	holder_servo.detach();
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