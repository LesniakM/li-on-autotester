#include <temp_sensor.h>
#include <math.h>

void setupTempSensor() {
    analogReadResolution(12);
}

float getTemperature(int samples) {
  double T_sum = 0.0;
  float logRT, RT, T;
  for (int i=0; i<samples; i++){
    int Vo = analogRead(THERMISTOR_PIN);
    float Vin = (V_ref*Vo*ADC_gain_error) / 4095.0;
    RT = (R1*Vin)/(V_ref-Vin);
    logRT = log(RT);
    T = (1.0 / (A_SHE + B_SHE*logRT + C_SHE*logRT*logRT*logRT));  // Steinhart and Hart Equation. T  = 1 / {A + B[ln(R)] + C[ln(R)]^3}
    T =  T - 273.15;
    T_sum += T;
  }
  return (T_sum / samples)*temp_linear_error+temp_offset;
}