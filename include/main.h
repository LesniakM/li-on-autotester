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

void wait(uint16_t seconds);

bool charge(uint16_t target_voltage=4200, uint16_t target_current=1000, uint16_t cutoff=50);

void discharge(uint16_t cc_current=1000, uint16_t end_voltage=2500);

#endif