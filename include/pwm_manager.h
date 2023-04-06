#ifndef PWM_MANAGER_H /* include guards */
#define PWM_MANAGER_H

#include <Arduino.h>


// Timer 2 channels used to controll servo:
constexpr uint8_t SLOW_PWM_CH_2 = PA1;
constexpr uint8_t SLOW_PWM_CH_3 = PA2;
constexpr uint8_t SLOW_PWM_CH_4 = PA3;

constexpr uint16_t TIM2_PRESCALER = 32;                       // For max resolution and speed
constexpr uint16_t TIM2_FREQ = 50;                       // For max resolution and speed
constexpr uint16_t TIM2_OVERFLOW = (72000000/TIM2_FREQ/TIM2_PRESCALER)-1;   // 72MHZ / 2048 = 35156.25Hz


// Timer 3 channels with low pass filters:
constexpr uint16_t FAST_PWM_CH_1 = PA6;
constexpr uint16_t FAST_PWM_CH_2 = PA7_ALT1;
constexpr uint16_t FAST_PWM_CH_3 = PB0_ALT1;
constexpr uint16_t FAST_PWM_CH_4 = PB1_ALT1;

constexpr uint16_t TIM3_PRESCALER = 1;            // For max resolution and speed
//constexpr uint16_t TIM3_OVERFLOW = 2047;        // 72MHZ / 2048 = 35156.25Hz
constexpr uint16_t TIM3_OVERFLOW = 4095;          // 72MHZ / 4096 = 17578.125Hz

constexpr uint16_t COMPARE_VAL_START = 0;

class PwmManager
{ 
public:
  PwmManager();
  void changePWMdc(uint8_t timer, uint8_t channel, uint16_t compareVal);
private:
  void setupTimer(HardwareTimer &timer, uint8_t prescaler, uint16_t overflow);
  void setupChannel(HardwareTimer &timer, uint8_t ch, uint16_t output_pin);
};


#endif /* PWM_MNG_H */