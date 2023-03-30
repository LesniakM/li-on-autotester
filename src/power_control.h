#ifndef POWER_CONTROL_H /* include guards */
#define POWER_CONTROL_H

#include <Arduino.h>
#include <pwms.h>


constexpr uint8_t enableDischargePin {13};   // PB15
constexpr uint8_t enableChargePin {14};      // PB14

constexpr uint16_t current_5 {8};


void setupChargeDischargePins();

void connectionSenseDischarge();

void setDischargeCurrent(uint16_t current);

void setChargeCurrent(uint16_t current);

void adjustDischargeCurrent(uint16_t current);

void holdDischarge();

void disableDischarge();

void disableCharge();

#endif /* OWER_CONTROL_H */