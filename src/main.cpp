#include <main.h>


float temperature = 0.0;
uint16_t voltage = 0;
int16_t current = 0;

uint16_t storage_voltage = 0;
uint16_t low_curr_voltage = 0;
uint16_t high_curr_voltage = 0;

uint16_t last_sent_current_500 = 619;
uint16_t last_sent_current_1000 = 1550;

void setup(void)
{ 
  RTC_MNG::initClockLSE();
  gpio = new GpioManager();
  pwmMng = new PwmManager();
  display = new OledDisplay();
  holder = new Holder(pwmMng, gpio, display);
  thermistor = new TempSensor();
  

  display->drawStaticDisplayElements();

  for (int i=0; i<1; i++)
  {
    if (holder->closeWithCellSensing() == true) display->updateDisplayState(0);
    else display->updateDisplayState(255);
  }
}

void loop(void)
{ 
/*
  // CODE BELOW IS OUTDATED AND USED TO TEST ONLY/

  //holder->close();
  //holder->open();
  if (digitalRead(buttonPin) == true) 
  {
    // Slowly close holder
    bool batt_detected = false;
    display->updateDisplayState(7);
    //closeHolderRouglhy();
    //connectionSenseDischarge();
    for (int i=0; i<20; i++) {
      current = INA226::getCurrent();
      display->updateDisplayCurrent(current);
      if (-current > 3) {
        batt_detected = true;
        break;
      }
      //closeHolderTighter();
    }
    if (batt_detected) 
    {
      //closeHolderTighter();
      //closeHolderTighter();
      //holdDischarge();
      delay(100);

      // Get initial current
      voltage = 0;
      for (int i=0; i<10; i++) {
        voltage+=INA226::getVoltage();
      }
      storage_voltage = voltage / 10;

      // 500mA Discharge for 3s.
      display->updateDisplayState(2);
      last_sent_current_500 = 619;
      //setDischargeCurrent(last_sent_current_500);
      uint32_t start_time = HAL_GetTick();
      while ((start_time + 1000) > HAL_GetTick())
      {
        voltage = INA226::getVoltage();
        current = INA226::getCurrent();
        display->updateDisplayVoltage(voltage);
        display->updateDisplayCurrent(current);
        if (-current < 490) {
          last_sent_current_500 += 10;
          //adjustDischargeCurrent(last_sent_current_500);
        }
        if (-current < 500) {
          last_sent_current_500++;
          //adjustDischargeCurrent(last_sent_current_500);
        }
        if (-current > 510) {
          last_sent_current_500 -= 10;
          //adjustDischargeCurrent(last_sent_current_500);
        }
        if (-current > 500) {
          last_sent_current_500--;
          //adjustDischargeCurrent(last_sent_current_500);
        }
      }

      // Get voltage after discharge
      voltage = 0;
      for (int i=0; i<10; i++) {
        voltage+=INA226::getVoltage();
      }
      //holdDischarge();
      low_curr_voltage = voltage / 10;

      delay(10);
      temperature = thermistor->getTemperature(100);
      voltage = INA226::getVoltage();
      current = INA226::getCurrent();
      display->updateDisplayVoltage(voltage);
      display->updateDisplayCurrent(current);
      display->updateDisplayTemperature(temperature);
      delay(80);
      //disableDischarge();
      //setChargeCurrent(last_sent_current_1000);
      current = INA226::getCurrent();
      start_time = HAL_GetTick();
      while (current > 50)
      {
        voltage = INA226::getVoltage();
        current = INA226::getCurrent();
        display->updateDisplayVoltage(voltage);
        display->updateDisplayCurrent(current);
        if (current > 1000) {
          last_sent_current_1000--;
          //setChargeCurrent(last_sent_current_1000);
        }
        if (current < 1000) {
          last_sent_current_1000++;
          //setChargeCurrent(last_sent_current_1000);
        }
      }
      voltage = 0;
      for (int i=0; i<10; i++) {
        voltage+=INA226::getVoltage();
      }
      //disableCharge();
      high_curr_voltage = voltage / 10;
      display->updateDisplayState(6);
      }
    //openHolder();
    
  }
  */
  temperature = thermistor->getTemperature(100);
  voltage = INA226::getVoltage();
  current = INA226::getCurrent();
  display->updateDisplayVoltage(voltage);
  display->updateDisplayCurrent(current);
  display->updateDisplayTemperature(temperature);
}
