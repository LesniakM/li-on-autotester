Project in this repo is no longer developed. I switch frameworks and created new repo. More info below.

This project was quite successful and the essential functions were completed:
  - Closed loop current/voltage control while cell charging in the CC/CV mode.
  - Cell discharge in closed-loop CC mode with energy measured in [mAh] and contious current adjustment.
  - Combine charging and discharging to perform complete test of the lithium-ion battery capacity. After capacity measure during discharge, cell voltage is restored to storage level.

but the following issues pushed me to switch from Arduino-Framework to stm32cube:
  - STM32duino packages footprints are quite large. They took up almost half of the Bluepill (stm32f103C8T6) flash memory.
  - The most recent STM32Cube and the Arduino-Framework have poor compatibility. CubeMx templates works flawlessly with the stm32cube framework in PlatformIo, in opposition to the "hidden" HAL functions calls in the Arduino framework, which are very confusing.
   - Setup and loop main functions in Arduino-Framework are quite annoying too. I just prefer single "int main()" function.
   - STM32duino packages caused some problems during testing.


Due to reasons mentioned above, the project is now developed using STM32Cube Framework. New repo is avaiable here (may be private in early stages):
https://github.com/LesniakM/stm32_li-ion_autotester
