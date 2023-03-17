EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Analog_ADC:INA226 U?
U 1 1 64159260
P 3900 3100
F 0 "U?" H 4050 3650 50  0000 C CNN
F 1 "INA226" H 4100 3550 50  0000 C CNN
F 2 "Package_SO:VSSOP-10_3x3mm_P0.5mm" H 4700 2650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ina226.pdf" H 4250 3000 50  0001 C CNN
	1    3900 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2600 3900 2050
$Comp
L Device:R R?
U 1 1 6415B78D
P 2850 3250
F 0 "R?" H 2920 3296 50  0000 L CNN
F 1 "0.1Ohm" H 2920 3205 50  0000 L CNN
F 2 "" V 2780 3250 50  0001 C CNN
F 3 "~" H 2850 3250 50  0001 C CNN
	1    2850 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 3550 2850 3400
Wire Wire Line
	3500 3200 3350 3200
Wire Wire Line
	3350 3200 3350 2950
Wire Wire Line
	3350 2950 2850 2950
Wire Wire Line
	2850 2950 2850 3100
Wire Wire Line
	3500 3300 3350 3300
Wire Wire Line
	3350 3300 3350 3550
Wire Wire Line
	3350 3550 2850 3550
$Comp
L Device:R R?
U 1 1 6415E748
P 5700 3350
F 0 "R?" H 5770 3396 50  0000 L CNN
F 1 "10k" H 5770 3305 50  0000 L CNN
F 2 "" V 5630 3350 50  0001 C CNN
F 3 "~" H 5700 3350 50  0001 C CNN
	1    5700 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 6415EA4D
P 6000 3350
F 0 "R?" H 6070 3396 50  0000 L CNN
F 1 "10k" H 6070 3305 50  0000 L CNN
F 2 "" V 5930 3350 50  0001 C CNN
F 3 "~" H 6000 3350 50  0001 C CNN
	1    6000 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3600 3900 3700
Wire Wire Line
	3900 3700 5700 3700
Wire Wire Line
	5700 3700 5700 3500
Wire Wire Line
	5700 3700 6000 3700
Wire Wire Line
	6000 3700 6000 3500
Wire Wire Line
	4300 2900 5700 2900
Wire Wire Line
	5700 2900 5700 3200
Wire Wire Line
	4300 2800 6000 2800
Wire Wire Line
	6000 2800 6000 3200
$Comp
L Device:C C?
U 1 1 64161068
P 6400 3350
F 0 "C?" H 6515 3396 50  0000 L CNN
F 1 "100nF" H 6515 3305 50  0000 L CNN
F 2 "" H 6438 3200 50  0001 C CNN
F 3 "~" H 6400 3350 50  0001 C CNN
	1    6400 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3500 6400 3700
Wire Wire Line
	6400 3700 6000 3700
Connection ~ 6000 3700
Wire Wire Line
	3900 2050 4400 2050
Wire Wire Line
	6400 2050 6400 3200
$Comp
L Device:R R?
U 1 1 641637B2
P 4400 2400
F 0 "R?" H 4470 2446 50  0000 L CNN
F 1 "10k" H 4470 2355 50  0000 L CNN
F 2 "" V 4330 2400 50  0001 C CNN
F 3 "~" H 4400 2400 50  0001 C CNN
	1    4400 2400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 641637B8
P 4750 2400
F 0 "R?" H 4820 2446 50  0000 L CNN
F 1 "10k" H 4820 2355 50  0000 L CNN
F 2 "" V 4680 2400 50  0001 C CNN
F 3 "~" H 4750 2400 50  0001 C CNN
	1    4750 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3100 4400 3100
Wire Wire Line
	4400 3100 4400 2550
Wire Wire Line
	4300 3200 4750 3200
Wire Wire Line
	4750 3200 4750 2550
Wire Wire Line
	4400 2250 4400 2050
Connection ~ 4400 2050
Wire Wire Line
	4400 2050 4750 2050
Wire Wire Line
	4750 2250 4750 2050
Text HLabel 2750 2950 0    50   Input ~ 0
IN+
Text HLabel 2750 3550 0    50   Input ~ 0
IN_
Text HLabel 2750 2800 0    50   Input ~ 0
VBUS
Text HLabel 5200 3400 2    50   Input ~ 0
ALERT
Text HLabel 4450 3100 2    50   Input ~ 0
SDA
Text HLabel 4800 3200 2    50   Input ~ 0
SCL
Text HLabel 2750 3700 0    50   Input ~ 0
GND
Text HLabel 2750 2050 0    50   Input ~ 0
VCC
Connection ~ 5700 3700
$Comp
L Device:R R?
U 1 1 64172DB0
P 5100 2400
F 0 "R?" H 5170 2446 50  0000 L CNN
F 1 "10k" H 5170 2355 50  0000 L CNN
F 2 "" V 5030 2400 50  0001 C CNN
F 3 "~" H 5100 2400 50  0001 C CNN
	1    5100 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3400 5100 3400
Wire Wire Line
	5100 3400 5100 2550
Wire Wire Line
	4750 2050 5100 2050
Wire Wire Line
	5100 2050 5100 2250
Connection ~ 4750 2050
Wire Wire Line
	5100 2050 6400 2050
Wire Wire Line
	2850 2950 2750 2950
Connection ~ 2850 2950
Wire Wire Line
	2750 3550 2850 3550
Connection ~ 2850 3550
Wire Wire Line
	3500 2800 2750 2800
Wire Wire Line
	3900 3700 2750 3700
Wire Wire Line
	2750 2050 3900 2050
Connection ~ 3900 2050
Connection ~ 3900 3700
Connection ~ 5100 2050
Wire Wire Line
	5200 3400 5100 3400
Connection ~ 5100 3400
Wire Wire Line
	4400 3100 4450 3100
Connection ~ 4400 3100
Wire Wire Line
	4750 3200 4800 3200
Connection ~ 4750 3200
$EndSCHEMATC
