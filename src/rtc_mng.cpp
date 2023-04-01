#include <rtc_mng.h>

void RTC_MNG::initClockLSE() {
  enableClock(LSE_CLOCK);
}

uint32_t RTC_MNG::getMilis(){
  return HAL_GetTick();
}