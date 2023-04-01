#include <pwm_manager.h>

TIM_TypeDef *InstanceFast = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAST_PWM_CH_1), PinMap_TIM);
TIM_TypeDef *InstanceSlow = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(SLOW_PWM_CH_2), PinMap_TIM);
HardwareTimer fast_timer(InstanceFast);
HardwareTimer slow_timer(InstanceSlow);

PwmManager::PwmManager(void) {
  setupTimer(fast_timer, TIM3_PRESCALER, TIM3_OVERFLOW);
  setupTimer(slow_timer, TIM2_PRESCALER, TIM2_OVERFLOW);

  setupChannel(fast_timer, 1, FAST_PWM_CH_1);
  setupChannel(fast_timer, 2, FAST_PWM_CH_2);
  //setupChannel(fast_timer, 3, FAST_PWM_CH_3);
  //setupChannel(fast_timer, 4, FAST_PWM_CH_4);

  setupChannel(slow_timer, 2, SLOW_PWM_CH_2);
  //setupChannel(slow_timer, 3, SLOW_PWM_CH_3);
  //setupChannel(slow_timer, 4, SLOW_PWM_CH_4);
}

void PwmManager::setupTimer(HardwareTimer &timer, uint8_t prescaler, uint16_t overflow)
{
  timer.setPrescaleFactor(prescaler);
  timer.setOverflow(overflow);    
  timer.refresh();
  timer.resume();
}

void PwmManager::setupChannel(HardwareTimer &timer, uint8_t ch, uint16_t output_pin)
{
  timer.setMode(ch, TIMER_OUTPUT_COMPARE_PWM1, output_pin);
  timer.setCaptureCompare(ch, COMPARE_VAL_START);
  timer.refresh();
  timer.resume();
}

void PwmManager::changePWMdc(uint8_t timer, uint8_t channel, uint16_t compareVal) {
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
