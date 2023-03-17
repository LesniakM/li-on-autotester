#ifndef TEMP_SENSOR_H /* include guards */
#define TEMP_SENSOR_H
#include <Arduino.h>

/* Wiring diagram:

           3.3V
            |
           [Rt] (100k) - Thermistor
            |
PA0 --------|
            |
           [R1] (100k) - Put exact value as R1 below.
            |
           GND
*/

#define R1 97700.0
#define A_SHE 5.024804487e-03       // Steinhart and Hart Equation coefficient A
#define B_SHE -4.386597963e-04      // Steinhart and Hart Equation coefficient B
#define C_SHE 22.09685670e-07       // Steinhart and Hart Equation coefficient C

#ifdef BOARD_STM32F103C8
  #define V_ref 3.25
  #define ADC_gain_error 0.995
  #define temp_offset -2.2
  #define temp_linear_error 1.02
  #define THERMISTOR_PIN PA0
#endif 
#ifdef BOARD_ESP32C3
  #define V_ref 3.33
  #define ADC_gain_error 0.98
  #define temp_offset -2.2
  #define temp_linear_error 1.02
  #define THERMISTOR_PIN 1
#endif 

void setupTempSensor();

/* blinks the LED once for an length of <ms> milliseconds. */
float getTemperature(int samples);

#endif /* TEMP_SENSOR */