#include <Arduino.h>
#include <temp_sensor.h>
#include <display.h>
#include <servo_control.h>
#include <ina226.h>

float temperature = 0.0;
int voltage = 0;
int current = 0;


void setup(void)
{ 
  Serial.begin(9600);
  pinMode(PB13, OUTPUT);
  digitalWrite(PB13, HIGH);
  setupTempSensor();
  setupDisplay();
  drawStaticDisplayElements();
  Serial.print("Wooohoooo");
}

void loop(void)
{ 
  Serial.print("Huuuuuu");
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

  Serial.print("Weeeee");

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

  Serial.print("Heeeee");
}
