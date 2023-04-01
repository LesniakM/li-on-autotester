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

#ifdef BOARD_STM32F103C8
  constexpr float V_REF {3.25};
  constexpr float ADC_GAIN_ERROR {0.995};
  constexpr float TEMP_OFFSET {-2.2};
  constexpr float TEMP_LINEAR_ERROR {1.02};
  constexpr uint8_t THERMISTOR_PIN {PA0};
  constexpr uint8_t READ_RESOLUTION {12};
  constexpr float VIN_MULTILPIER {V_REF * ADC_GAIN_ERROR / 4095.0};    // (V_REF*ADC_GAIN_ERROR) / 4095.0;
#endif 
#ifdef BOARD_ESP32C3
  #define V_ref 3.33
  #define ADC_gain_error 0.98
  #define temp_offset -2.2
  #define temp_linear_error 1.02
  #define THERMISTOR_PIN 1
#endif 

constexpr float R1 {97700.0};
constexpr float A_SHE {5.024804487e-03};      // Steinhart and Hart Equation coefficient A
constexpr float B_SHE {-4.386597963e-04};     // Steinhart and Hart Equation coefficient B
constexpr float C_SHE {22.09685670e-07};      // Steinhart and Hart Equation coefficient C
constexpr uint8_t T_SAMPLES {64};             // 

class TempSensor 
{
public:
  TempSensor(float divider_r = R1, float a = A_SHE, float b = B_SHE, float c = C_SHE);
  float getTemperature(uint8_t samples = T_SAMPLES);
private:
  float r1;
  float a_she;
  float b_she;
  float c_she;
};

/* blinks the LED once for an length of <ms> milliseconds. */


#endif /* TEMP_SENSOR */