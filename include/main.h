#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
// #include <charger.h>
#include <display.h>
#include <gpio_manager.h>
#include <holder.h>
#include <ina226.h>
// #include <mcp4725.h>
#include <pwm_manager.h>
#include <rtc_mng.h>
#include <temp_sensor.h>


GpioManager* gpio;
PwmManager* pwmMng;
Holder* holder;
TempSensor* thermistor;
OledDisplay* display;

#endif