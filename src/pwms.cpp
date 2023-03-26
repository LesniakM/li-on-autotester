#include <pwms.h>

// Timer 2 channels used to controll servo:
constexpr uint8_t SLOW_PWM_CH_2 = PA1;
constexpr uint8_t SLOW_PWM_CH_3 = PA2;
constexpr uint8_t SLOW_PWM_CH_4 = PA3;

constexpr uint16_t TIM2_PRESCALER = 32;                       // For max resolution and speed
constexpr uint16_t TIM2_FREQ = 50;                       // For max resolution and speed
constexpr uint16_t TIM2_OVERFLOW = 72000000/TIM2_FREQ/TIM2_PRESCALER;   // 72MHZ / 2048 = 35156.25Hz


// Timer 3 channels with low pass filters:
constexpr uint16_t FAST_PWM_CH_1 = PA6;
constexpr uint16_t FAST_PWM_CH_2 = PA7_ALT1;
constexpr uint16_t FAST_PWM_CH_3 = PB0_ALT1;
constexpr uint16_t FAST_PWM_CH_4 = PB1_ALT1;

constexpr uint16_t TIM3_PRESCALER = 1;          // For max resolution and speed
constexpr uint16_t TIM3_OVERFLOW = 2047;        // 72MHZ / 2048 = 35156.25Hz
//constexpr uint16_t TIM3_OVERFLOW = 4095;      // 72MHZ / 4096 = 17578.125Hz

constexpr uint16_t COMPARE_VAL_START = 0;


TIM_TypeDef *InstanceFast = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAST_PWM_CH_1), PinMap_TIM);
TIM_TypeDef *InstanceSlow = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(SLOW_PWM_CH_2), PinMap_TIM);
HardwareTimer fast_timer(InstanceFast);
HardwareTimer slow_timer(InstanceSlow);

void setupTimer(HardwareTimer &timer, uint8_t prescaler, uint16_t overflow)
{
  timer.setPrescaleFactor(prescaler);
  timer.setOverflow(overflow);    
  timer.refresh();
  timer.resume();
}

void setupChannel(HardwareTimer &timer, uint8_t ch, uint16_t output_pin)
{
  timer.setMode(ch, TIMER_OUTPUT_COMPARE_PWM1, output_pin);
  timer.setCaptureCompare(ch, COMPARE_VAL_START);
  timer.refresh();
  timer.resume();
}

void setupPWMs() {
  setupTimer(fast_timer, TIM3_PRESCALER, TIM3_OVERFLOW);
  setupTimer(slow_timer, TIM2_PRESCALER, TIM2_OVERFLOW);

  setupChannel(fast_timer, 1, FAST_PWM_CH_1);
  setupChannel(fast_timer, 2, FAST_PWM_CH_2);
  setupChannel(fast_timer, 3, FAST_PWM_CH_3);
  setupChannel(fast_timer, 4, FAST_PWM_CH_4);

  setupChannel(slow_timer, 2, SLOW_PWM_CH_2);
  setupChannel(slow_timer, 3, SLOW_PWM_CH_3);
  setupChannel(slow_timer, 4, SLOW_PWM_CH_4);
}

void changePWMdc(uint8_t timer, uint8_t channel, uint16_t compareVal) {
  if (timer == 2) 
  {
    slow_timer.setCaptureCompare(channel, compareVal);
    slow_timer.refresh();
    slow_timer.resume();
  }
  if (timer == 3) 
  {
    fast_timer.setCaptureCompare(channel, compareVal);
    fast_timer.refresh();
    fast_timer.resume();
  }
}
