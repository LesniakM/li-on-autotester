#include <pwms.h>

#define fast1 PA1
#define fast1_channel 2
#define slow1 PB1
#define slow1_channel 3

#define slowPwmPres 32
#define slowPwmFreq 50    // 50Hz -> T = 20ms
#define slowPwmOver 72000000/slowPwmFreq/slowPwmPres  // 45000

TIM_TypeDef *InstanceFast = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(fast1), PinMap_TIM);
TIM_TypeDef *InstanceSlow = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(slow1), PinMap_TIM);
HardwareTimer fast_timer(InstanceFast);
HardwareTimer slow_timer(InstanceSlow);

void setupPWMs() {
  fast_timer.setPrescaleFactor(1);
  fast_timer.setOverflow(20470); // 72MHZ / 2048 = 35156.25Hz
  fast_timer.setMode(fast1_channel, TIMER_OUTPUT_COMPARE_PWM1, fast1);
  fast_timer.setCaptureCompare(fast1_channel, 1000);
  fast_timer.refresh();
  fast_timer.resume();

  slow_timer.setPrescaleFactor(slowPwmPres);
  slow_timer.setOverflow(slowPwmOver);
  slow_timer.setMode(slow1_channel, TIMER_OUTPUT_COMPARE_PWM1, slow1);
  slow_timer.setCaptureCompare(slow1_channel, 3375);
  slow_timer.refresh();
  slow_timer.resume();
}

void changePWM(uint16_t compareVal) {
  slow_timer.setCaptureCompare(slow1_channel, compareVal);
  slow_timer.refresh();
  slow_timer.resume();
}
