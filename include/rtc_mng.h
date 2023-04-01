#ifndef RTC_MNG_H
#define RTC_MNG_H

#include <clock.h>

class RTC_MNG{
public:
  static void initClockLSE();

  static uint32_t getMilis();
};

#endif