#include <Arduino.h>
#include <temp_sensor.h>
#include <display.h>
#include <servo_control.h>
#include <ina226.h>
#include <pwms.h>

float temperature = 0.0;
int voltage = 0;
int current = 0;
int pwm_dutycycle = 0;


void setup(void)
{ 
  pinMode(PB13, OUTPUT);
  digitalWrite(PB13, HIGH);
  setupTempSensor();
  setupDisplay();
  drawStaticDisplayElements();
  setupPWMs();
}

void loop(void)
{ 
  openHolder();
  for (int i=0; i<10; i++) {
    temperature = getTemperature(100);
    voltage = getVoltage();
    current = getCurrent();
    updateDisplayVoltage(voltage);
    updateDisplayCurrent(current);
    updateDisplayTemperature(temperature);
    delay(100);
  }
  //closeHolder();
  for (int i=0; i<100; i++) {
    temperature = getTemperature(100);
    voltage = getVoltage();
    current = getCurrent();
    updateDisplayVoltage(voltage);
    updateDisplayCurrent(current);
    updateDisplayTemperature(temperature);
    delay(100);
  }
}
