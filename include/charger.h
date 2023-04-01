#ifndef CHARGER_H
#define CHARGER_H

//#include <pwms.h>

/*
STM32 PWM OUTPUT: 0.0V - 3.3V

XL4015E current limit ratio is 27.0718 mA/mV

Therefore, for 0 - 1A regulated charging current it is necessary to
regulate reference voltage in range: 0 - 37mV, however to take into account
all the tolerances and non linearities, target range is about 0 - 50mV.
1:66 divider could be used, but since 1:69 is easier to get (22+47), PWM voltage
is in range: 0 - 47.826mV.

Wiring diagram:

17.5kHz 12bit
      PWM      Low pass stage I
PB01----------[470R]---|--------|
                       |       [R1]
                       |        |     
                     [47nF]     |-[R3]-|------O To ref
                       |        |      |
                       |       [R2]   [C2]
                       |        |      |
                      GND      GND    GND
R1 - 69k
R2 - 1k
R3 - 4.7k
C2 - 15nF
*/

#endif /*CHARGER_H*/