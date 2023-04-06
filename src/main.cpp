#include <main.h>

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
  
  holder->open();
}

void loop(void)
{ 
  bool success;
  display->updateDisplayVoltage(INA226::getVoltage());
  display->updateDisplayCurrent(INA226::getCurrent());
  display->updateDisplayTemperature(thermistor->getTemperature(100));

  if (gpio->getButtonState() == false) return;

  if (holder->closeWithCellSensing() == false) 
  {
    display->updateDisplayState(255);
    return;}

  success = charge(4200, 1000, 50);    // CHG 4.2V, 1A, 50mA
  if (!success) return;

  wait(15*60);               // Wait 15 min

  discharge(1000, 2500);     // DSC 1A, 2.5V MEASURE

  wait(5*60);                // Wait 5 min

  charge(3550, 1000, 200);    // CHG 3.55V, 1A, 200mA

  wait(15*60);               // Wait 15 min

  // DCIR   0.5A  2A    

  wait(20);

  charge(3.55, 1000, 50);    // CHG 3.55V, 1A, 50mA
}

/**
 * Waits and updates time left on display.
 *
 *
 * @param seconds Amount of seconds to wait for. Integers only.
 */
void wait(uint16_t seconds) 
{
  uint32_t start_time = RTC_MNG::getMilis();
  display->updateDisplayState(3);
  while ((RTC_MNG::getMilis()-start_time) < seconds*1000)
  {
    uint32_t time_left = seconds - (RTC_MNG::getMilis()-start_time)/1000;
    uint16_t minutes = time_left / 60;
    uint16_t seconds = time_left - minutes*60;
    display->updateClock(minutes, seconds);
  }
  display->clearClock();
}

/**
 * Charges with selected voltage, current and cutoff.
 *
 *
 * @param target_voltage Target charging voltage in CV mode.
 * @param target_current Target charging current in CC mode.
 * @param cutoff Target CV current. Charging stops when current is lower than this value.
 */
bool charge(uint16_t target_voltage, uint16_t target_current, uint16_t cutoff) 
{ 
  bool test_success = false;
  uint8_t state = 1;
  uint16_t voltage_reading = INA226::getVoltage();
  uint16_t current_reading = INA226::getCurrent();

  uint16_t last_sent_curr_value = target_current*2;
  pwmMng->changePWMdc(3, 2, last_sent_curr_value);
  gpio->enableCharge();
  
  display->updateDisplayTemperature(thermistor->getTemperature(100));
  for(uint32_t iteration=0; ; iteration++)
  { 
    voltage_reading = INA226::getVoltage();
    current_reading = INA226::getCurrent();
    if (1000 < voltage_reading && voltage_reading < target_voltage)   // CC mode
      { 
      if (current_reading < target_current)
      {
        last_sent_curr_value++;
        pwmMng->changePWMdc(3, 2, last_sent_curr_value);
      }
      else if (target_current > current_reading)
      {
        last_sent_curr_value--;
        pwmMng->changePWMdc(3, 2, last_sent_curr_value);
      }
      state = 1;
    }
    else if (target_voltage == voltage_reading)
    { 
      // Perfect condition, do nothing
      state = 2;
    }
    else if (voltage_reading > target_voltage && voltage_reading < 4350)
    { 
      if (voltage_reading > target_voltage + 5) last_sent_curr_value -= 10;
      else last_sent_curr_value--;
      pwmMng->changePWMdc(3, 2, last_sent_curr_value);
      state = 2;
    }
    else                  // Error, voltage is smaller than 1000 or larger than 4350
    { 
      gpio->disableCharge();
      holder->open();
      test_success = false;
      display->updateDisplayVoltage(voltage_reading);
      display->updateDisplayState(202);
      break;
    }

    if ((voltage_reading > target_voltage - 3) && (current_reading < cutoff - 1))
    {
      gpio->disableCharge();
      test_success = true;
      display->updateDisplayState(0);
      break;
    }

    if (current_reading < 10) {
      gpio->disableCharge();
      holder->open();
      test_success = false;
      display->updateDisplayState(201);
      break;
    }

    switch (iteration % 50) 
    {
    case 0:
      // Nothing for now
      break;
    case 10:
      display->updateDisplayVoltage(voltage_reading);
      break;
    case 20:
      display->updateDisplayCurrent(current_reading);
      break;
    case 30:
      display->updateDisplayTemperature(thermistor->getTemperature(25));
      break;
    case 40:
      display->updateDisplayState(state);
      break;
    default:
      break;
    }
  }
  return test_success;
}

/**
 * Discharges in CC mode with selected current and end voltage.
 *
 * @param cc_current Current value in mA.
 * @param end_voltage End voltage in mV.
 */
void discharge(uint16_t cc_current, uint16_t end_voltage) 
{ 
  bool test_success = false;
  double capacity_f = 0.0;

  display->updateDisplayState(4);

  uint32_t last_time = RTC_MNG::getMilis();
  uint32_t time_now = last_time;

  uint16_t last_sent_curr_value = cc_current*1.1;
  pwmMng->changePWMdc(3, 1, last_sent_curr_value);
  gpio->enableDischarge();

  delay(50);

  uint16_t voltage_reading = INA226::getVoltage();
  int16_t current_reading = INA226::getCurrent();

  display->updateDisplayTemperature(thermistor->getTemperature(100));
  for(uint32_t iteration=0; ; iteration++)
  { 
    voltage_reading = INA226::getVoltage();
    current_reading = INA226::getCurrent();

    if (voltage_reading < end_voltage && voltage_reading != 0)
    {
      gpio->disableDischarge();
      test_success = true;
      display->updateDisplayState(0);
      break;
    }

    if (-current_reading < cc_current) last_sent_curr_value++;
    else if (-current_reading > cc_current) last_sent_curr_value--;

    pwmMng->changePWMdc(3, 1, last_sent_curr_value);

    switch (iteration % 40) 
    {
    case 0:
      display->updateDisplayVoltage(voltage_reading);
      break;
    case 10:
      display->updateDisplayCurrent(current_reading);
      break;
    case 20:
      display->updateDisplayTemperature(thermistor->getTemperature(25));
      break;
    case 30:
      time_now = RTC_MNG::getMilis();
      capacity_f += ((time_now - last_time)/3600000.0 * (-current_reading));
      last_time = time_now;
      display->updateDisplayCapacity(int(capacity_f));
      break;
    default:
      break;
    }
  }
}