#include <temp_sensor.h>
#include <math.h>

TempSensor::TempSensor(float divider_r, float a, float b, float c)
{
  analogReadResolution(READ_RESOLUTION);
  r1 = divider_r;
  a_she = a;
  b_she = b;
  c_she = c;
}

float TempSensor::getTemperature(uint8_t samples) {
  double T_sum = 0.0;
  float logRT, RT, T;
  for (int i=0; i<samples; i++){
    int inputVoltage = analogRead(THERMISTOR_PIN);
    float Vin = inputVoltage * VIN_MULTILPIER;                    // same as: (V_REF*inputVoltage*ADC_GAIN_ERROR) / 4095.0;
    RT = (r1*Vin)/(V_REF-Vin);
    logRT = log(RT);
    T = (1.0 / (a_she + b_she*logRT + c_she*logRT*logRT*logRT));  // Steinhart and Hart Equation. T  = 1 / {A + B[ln(R)] + C[ln(R)]^3}
    T =  T - 273.15;
    T_sum += T;
  }
  return (T_sum / samples)*TEMP_LINEAR_ERROR+TEMP_OFFSET;
}