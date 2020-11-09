EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L 4xxx:4027 U1
U 2 1 5F9057B6
P 2400 2150
F 0 "U1" H 2450 1900 50  0000 L CNN
F 1 "HCF4027B" H 2450 1800 50  0000 L CNN
F 2 "SMD_Packages:SO-16-N" H 2400 2150 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4027bms.pdf" H 2400 2150 50  0001 C CNN
	2    2400 2150
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4027 U1
U 3 1 5F90647C
P 5500 4400
F 0 "U1" H 5550 4050 50  0000 L CNN
F 1 "HCF4027B" H 5550 3950 50  0000 L CNN
F 2 "SMD_Packages:SO-16-N" H 5500 4400 50  0001 C CNN
F 3 "http://www.intersil.com/content/dam/Intersil/documents/cd40/cd4027bms.pdf" H 5500 4400 50  0001 C CNN
	3    5500 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q3
U 1 1 5F908445
P 6700 1700
F 0 "Q3" H 6904 1746 50  0000 L CNN
F 1 "IRLML2502" H 6904 1655 50  0001 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6900 1800 50  0001 C CNN
F 3 "~" H 6700 1700 50  0001 C CNN
	1    6700 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q4
U 1 1 5F9099D8
P 6700 2300
F 0 "Q4" H 6904 2346 50  0000 L CNN
F 1 "IRLML2502" H 6904 2255 50  0001 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 6900 2400 50  0001 C CNN
F 3 "~" H 6700 2300 50  0001 C CNN
	1    6700 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q1
U 1 1 5F90A446
P 5350 1700
F 0 "Q1" H 5554 1746 50  0000 L CNN
F 1 "IRLML2502" H 5554 1655 50  0001 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5550 1800 50  0001 C CNN
F 3 "~" H 5350 1700 50  0001 C CNN
	1    5350 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_GSD Q2
U 1 1 5F90ADD7
P 5350 2300
F 0 "Q2" H 5554 2346 50  0000 L CNN
F 1 "IRLML2502" H 5554 2255 50  0001 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-23" H 5550 2400 50  0001 C CNN
F 3 "~" H 5350 2300 50  0001 C CNN
	1    5350 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 5F90C82A
P 5450 2700
F 0 "R9" H 5520 2746 50  0000 L CNN
F 1 "27 Ω" H 5520 2655 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 5380 2700 50  0001 C CNN
F 3 "~" H 5450 2700 50  0001 C CNN
	1    5450 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 5F90D266
P 6800 2700
F 0 "R12" H 6870 2746 50  0000 L CNN
F 1 "27 Ω" H 6870 2655 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 6730 2700 50  0001 C CNN
F 3 "~" H 6800 2700 50  0001 C CNN
	1    6800 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5F90D73E
P 2900 1750
F 0 "R5" H 2970 1796 50  0000 L CNN
F 1 "10 kΩ" H 2970 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 2830 1750 50  0001 C CNN
F 3 "~" H 2900 1750 50  0001 C CNN
	1    2900 1750
	-1   0    0    1   
$EndComp
$Comp
L Device:R R6
U 1 1 5F90E1F8
P 3300 1750
F 0 "R6" H 3370 1796 50  0000 L CNN
F 1 "10 kΩ" H 3370 1705 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 3230 1750 50  0001 C CNN
F 3 "~" H 3300 1750 50  0001 C CNN
	1    3300 1750
	-1   0    0    1   
$EndComp
Text Label 4400 2600 2    50   ~ 0
~Q
$Comp
L Device:R R13
U 1 1 5F916E87
P 8450 2000
F 0 "R13" V 8243 2000 50  0000 C CNN
F 1 "0 Ω" V 8334 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8380 2000 50  0001 C CNN
F 3 "~" H 8450 2000 50  0001 C CNN
	1    8450 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R R14
U 1 1 5F917A36
P 8450 2100
F 0 "R14" V 8650 2100 50  0000 C CNN
F 1 "0 Ω" V 8550 2100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805" V 8380 2100 50  0001 C CNN
F 3 "~" H 8450 2100 50  0001 C CNN
	1    8450 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	6650 1450 6800 1450
Wire Wire Line
	6800 1450 6800 1500
Wire Wire Line
	6800 2500 6800 2550
Wire Wire Line
	5300 1450 5450 1450
Wire Wire Line
	5450 1450 5450 1500
Wire Wire Line
	5450 1900 5450 2000
Wire Wire Line
	5450 2500 5450 2550
Wire Wire Line
	5150 1700 5100 1700
Wire Wire Line
	6500 1700 6450 1700
Text Label 4700 1700 0    50   ~ 0
Q
Text Label 4700 2300 0    50   ~ 0
~Q
Wire Wire Line
	4700 2300 4800 2300
Wire Wire Line
	6800 1900 6800 2000
Wire Wire Line
	6800 2000 7000 2000
Connection ~ 6800 2000
Wire Wire Line
	6800 2000 6800 2100
Wire Wire Line
	5450 2000 5650 2000
Connection ~ 5450 2000
Wire Wire Line
	5450 2000 5450 2100
Wire Wire Line
	8300 2100 8050 2100
Wire Wire Line
	8300 2000 8050 2000
Text Label 8050 2000 0    50   ~ 0
L1
Text Label 8050 2100 0    50   ~ 0
L2
Text Label 7000 2000 0    50   ~ 0
L1
Text Label 5650 2000 0    50   ~ 0
L2
Wire Wire Line
	2400 1850 2400 950 
Wire Wire Line
	2400 950  1650 950 
Wire Wire Line
	2400 2450 2400 2600
Wire Wire Line
	2400 2600 2250 2600
Wire Wire Line
	2100 2050 1850 2050
Wire Wire Line
	2100 2150 1850 2150
Text Label 1850 2150 0    50   ~ 0
CLK
Text Label 1250 1900 0    50   ~ 0
FF_K
Text Label 1850 2600 0    50   ~ 0
FF_RESET
Text Label 1400 950  0    50   ~ 0
FF_SET
Wire Wire Line
	5450 2850 5450 2900
Wire Wire Line
	3300 2050 3300 1900
Wire Wire Line
	2700 2250 2900 2250
Wire Wire Line
	2900 2250 2900 1900
Wire Wire Line
	2700 2050 3300 2050
$Comp
L power:GND #PWR09
U 1 1 5F955FCB
P 5450 2900
F 0 "#PWR09" H 5450 2650 50  0001 C CNN
F 1 "GND" H 5455 2727 50  0000 C CNN
F 2 "" H 5450 2900 50  0001 C CNN
F 3 "" H 5450 2900 50  0001 C CNN
	1    5450 2900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5F956548
P 6800 2850
F 0 "#PWR012" H 6800 2600 50  0001 C CNN
F 1 "GND" H 6805 2677 50  0000 C CNN
F 2 "" H 6800 2850 50  0001 C CNN
F 3 "" H 6800 2850 50  0001 C CNN
	1    6800 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5F956AA7
P 5500 4950
F 0 "#PWR010" H 5500 4700 50  0001 C CNN
F 1 "GND" H 5505 4777 50  0000 C CNN
F 2 "" H 5500 4950 50  0001 C CNN
F 3 "" H 5500 4950 50  0001 C CNN
	1    5500 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 4800 5500 4950
Wire Wire Line
	5500 4000 5500 3850
Wire Wire Line
	5500 3850 5050 3850
Text Label 4850 3850 0    50   ~ 0
Vbb
Text Label 5300 1450 0    50   ~ 0
Vdd
Text Label 6650 1450 0    50   ~ 0
Vdd
Wire Wire Line
	8600 2000 9100 2000
Wire Wire Line
	8600 2100 9100 2100
Wire Wire Line
	1700 5150 1700 5300
$Comp
L power:GND #PWR04
U 1 1 5F98DB74
P 1700 5300
F 0 "#PWR04" H 1700 5050 50  0001 C CNN
F 1 "GND" H 1705 5127 50  0000 C CNN
F 2 "" H 1700 5300 50  0001 C CNN
F 3 "" H 1700 5300 50  0001 C CNN
	1    1700 5300
	1    0    0    -1  
$EndComp
Text Label 1850 4650 2    50   ~ 0
CLK
Text Label 1850 4850 2    50   ~ 0
FF_K
Text Label 1850 4950 2    50   ~ 0
FF_J
Text Label 1850 4750 2    50   ~ 0
FF_RESET
Text Label 1850 5050 2    50   ~ 0
FF_SET
Text Label 3000 4450 2    50   ~ 0
Vdd
Wire Wire Line
	1450 5150 1700 5150
Wire Wire Line
	1450 5050 1850 5050
Wire Wire Line
	1450 4950 1850 4950
Wire Wire Line
	1450 4850 1850 4850
Wire Wire Line
	1450 4750 1850 4750
Wire Wire Line
	1450 4650 1850 4650
$Comp
L Device:R R7
U 1 1 5F95BC79
P 4950 1700
F 0 "R7" V 5050 1700 50  0000 L CNN
F 1 "1 kΩ" V 4850 1600 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 4880 1700 50  0001 C CNN
F 3 "~" H 4950 1700 50  0001 C CNN
	1    4950 1700
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 1700 4700 1700
$Comp
L Device:R R8
U 1 1 5F95E530
P 4950 2300
F 0 "R8" V 5050 2300 50  0000 L CNN
F 1 "1 kΩ" V 4850 2200 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 4880 2300 50  0001 C CNN
F 3 "~" H 4950 2300 50  0001 C CNN
	1    4950 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 2300 5150 2300
$Comp
L Device:R R10
U 1 1 5F9633A5
P 6300 1700
F 0 "R10" V 6400 1700 50  0000 L CNN
F 1 "1 kΩ" V 6200 1600 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 6230 1700 50  0001 C CNN
F 3 "~" H 6300 1700 50  0001 C CNN
	1    6300 1700
	0    1    1    0   
$EndComp
$Comp
L Device:R R11
U 1 1 5F963848
P 6350 2300
F 0 "R11" V 6450 2300 50  0000 L CNN
F 1 "1 kΩ" V 6250 2200 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 6280 2300 50  0001 C CNN
F 3 "~" H 6350 2300 50  0001 C CNN
	1    6350 2300
	0    1    1    0   
$EndComp
Wire Wire Line
	6200 2300 6000 2300
Wire Wire Line
	6150 1700 6000 1700
Text Label 6000 1700 0    50   ~ 0
~Q
Text Label 6000 2300 0    50   ~ 0
Q
Connection ~ 3300 2050
Wire Wire Line
	3300 2050 3500 2050
Connection ~ 2900 2250
$Comp
L Device:C C2
U 1 1 5F98A5ED
P 5050 4200
F 0 "C2" H 4900 4300 50  0000 L CNN
F 1 "100 nF" H 4750 4100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5088 4050 50  0001 C CNN
F 3 "~" H 5050 4200 50  0001 C CNN
	1    5050 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3850 5050 4050
Wire Wire Line
	5050 4350 5050 4550
Connection ~ 5050 3850
Wire Wire Line
	5050 3850 4850 3850
$Comp
L power:GND #PWR07
U 1 1 5F98C5D7
P 5050 4550
F 0 "#PWR07" H 5050 4300 50  0001 C CNN
F 1 "GND" H 5055 4377 50  0000 C CNN
F 2 "" H 5050 4550 50  0001 C CNN
F 3 "" H 5050 4550 50  0001 C CNN
	1    5050 4550
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 6 1 5FA1C3A1
P 3800 2050
F 0 "U2" H 3800 2367 50  0000 C CNN
F 1 "74LS04" H 3800 2276 50  0000 C CNN
F 2 "LED_Chain:SOIC-14" H 3800 2050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 3800 2050 50  0001 C CNN
	6    3800 2050
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 5 1 5FA1F249
P 3800 2600
F 0 "U2" H 3800 2917 50  0000 C CNN
F 1 "74LS04" H 3800 2826 50  0000 C CNN
F 2 "LED_Chain:SOIC-14" H 3800 2600 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 3800 2600 50  0001 C CNN
	5    3800 2600
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74LS04 U2
U 7 1 5FA22306
P 5500 6050
F 0 "U2" H 5730 6096 50  0000 L CNN
F 1 "74LS04" H 5730 6005 50  0000 L CNN
F 2 "LED_Chain:SOIC-14" H 5500 6050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS04" H 5500 6050 50  0001 C CNN
	7    5500 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 5550 5500 5450
Wire Wire Line
	5500 5450 5050 5450
Text Label 4850 5450 0    50   ~ 0
Vbb
$Comp
L Device:C C3
U 1 1 5FA25BC0
P 5050 5800
F 0 "C3" H 4900 5900 50  0000 L CNN
F 1 "100 nF" H 4750 5700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 5088 5650 50  0001 C CNN
F 3 "~" H 5050 5800 50  0001 C CNN
	1    5050 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 5450 5050 5650
Wire Wire Line
	5050 5950 5050 6150
$Comp
L power:GND #PWR08
U 1 1 5FA25EF8
P 5050 6150
F 0 "#PWR08" H 5050 5900 50  0001 C CNN
F 1 "GND" H 5055 5977 50  0000 C CNN
F 2 "" H 5050 6150 50  0001 C CNN
F 3 "" H 5050 6150 50  0001 C CNN
	1    5050 6150
	1    0    0    -1  
$EndComp
Connection ~ 5050 5450
Wire Wire Line
	5050 5450 4850 5450
$Comp
L power:GND #PWR011
U 1 1 5FA27AD9
P 5500 6650
F 0 "#PWR011" H 5500 6400 50  0001 C CNN
F 1 "GND" H 5505 6477 50  0000 C CNN
F 2 "" H 5500 6650 50  0001 C CNN
F 3 "" H 5500 6650 50  0001 C CNN
	1    5500 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 6650 5500 6550
Wire Wire Line
	3100 2250 3100 2600
Wire Wire Line
	3100 2600 3500 2600
Wire Wire Line
	2900 2250 3100 2250
Text Label 4400 2050 2    50   ~ 0
Q
Wire Wire Line
	4100 2050 4400 2050
Wire Wire Line
	4100 2600 4400 2600
$Comp
L Device:R R3
U 1 1 5FA3C7A8
P 1650 1200
F 0 "R3" H 1720 1246 50  0000 L CNN
F 1 "10 kΩ" H 1720 1155 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 1580 1200 50  0001 C CNN
F 3 "~" H 1650 1200 50  0001 C CNN
	1    1650 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5FA40534
P 2250 2850
F 0 "R4" H 2320 2896 50  0000 L CNN
F 1 "10 kΩ" H 2320 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 2180 2850 50  0001 C CNN
F 3 "~" H 2250 2850 50  0001 C CNN
	1    2250 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5FA40EFD
P 2250 3100
F 0 "#PWR06" H 2250 2850 50  0001 C CNN
F 1 "GND" H 2255 2927 50  0000 C CNN
F 2 "" H 2250 3100 50  0001 C CNN
F 3 "" H 2250 3100 50  0001 C CNN
	1    2250 3100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5FA412B8
P 1650 1450
F 0 "#PWR03" H 1650 1200 50  0001 C CNN
F 1 "GND" H 1655 1277 50  0000 C CNN
F 2 "" H 1650 1450 50  0001 C CNN
F 3 "" H 1650 1450 50  0001 C CNN
	1    1650 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 950  1650 1050
Wire Wire Line
	1650 1350 1650 1450
Connection ~ 1650 950 
Wire Wire Line
	1650 950  1400 950 
Wire Wire Line
	2250 2600 2250 2700
Wire Wire Line
	2250 3000 2250 3100
Connection ~ 2250 2600
Wire Wire Line
	2250 2600 1850 2600
$Comp
L Connector:Conn_01x08_Male J1
U 1 1 5FA505DA
P 1250 4750
F 0 "J1" H 1358 5231 50  0000 C CNN
F 1 "Interface" H 1358 5140 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x08_Pitch2.54mm" H 1250 4750 50  0001 C CNN
F 3 "~" H 1250 4750 50  0001 C CNN
	1    1250 4750
	1    0    0    -1  
$EndComp
Text Label 2350 4550 2    50   ~ 0
Vbb
$Comp
L Device:C C1
U 1 1 5FA5A175
P 2750 4700
F 0 "C1" H 2600 4800 50  0000 L CNN
F 1 "1 μF" H 2450 4600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805" H 2788 4550 50  0001 C CNN
F 3 "~" H 2750 4700 50  0001 C CNN
	1    2750 4700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 5FA5A79C
P 2750 4950
F 0 "#PWR05" H 2750 4700 50  0001 C CNN
F 1 "GND" H 2755 4777 50  0000 C CNN
F 2 "" H 2750 4950 50  0001 C CNN
F 3 "" H 2750 4950 50  0001 C CNN
	1    2750 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4450 2750 4550
Wire Wire Line
	2750 4850 2750 4950
Connection ~ 2750 4450
$Comp
L Device:R R1
U 1 1 5FA5E8ED
P 850 2050
F 0 "R1" H 920 2096 50  0000 L CNN
F 1 "10 kΩ" H 920 2005 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 780 2050 50  0001 C CNN
F 3 "~" H 850 2050 50  0001 C CNN
	1    850  2050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5FA5ECA7
P 850 2300
F 0 "#PWR01" H 850 2050 50  0001 C CNN
F 1 "GND" H 855 2127 50  0000 C CNN
F 2 "" H 850 2300 50  0001 C CNN
F 3 "" H 850 2300 50  0001 C CNN
	1    850  2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  1800 850  1900
Wire Wire Line
	850  2200 850  2300
$Comp
L Device:R R2
U 1 1 5FA61321
P 1450 2150
F 0 "R2" H 1520 2196 50  0000 L CNN
F 1 "10 kΩ" H 1520 2105 50  0000 L CNN
F 2 "Resistors_SMD:R_0805" V 1380 2150 50  0001 C CNN
F 3 "~" H 1450 2150 50  0001 C CNN
	1    1450 2150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5FA616F7
P 1450 2400
F 0 "#PWR02" H 1450 2150 50  0001 C CNN
F 1 "GND" H 1455 2227 50  0000 C CNN
F 2 "" H 1450 2400 50  0001 C CNN
F 3 "" H 1450 2400 50  0001 C CNN
	1    1450 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1900 1450 2000
Wire Wire Line
	1450 2300 1450 2400
Wire Wire Line
	1850 2050 1850 1800
Wire Wire Line
	1850 1800 850  1800
Connection ~ 850  1800
Wire Wire Line
	850  1800 600  1800
Text Label 600  1800 0    50   ~ 0
FF_J
Wire Wire Line
	1800 2250 1800 1900
Wire Wire Line
	1800 1900 1450 1900
Wire Wire Line
	1800 2250 2100 2250
Connection ~ 1450 1900
Wire Wire Line
	1450 1900 1250 1900
Wire Wire Line
	2900 1200 2900 1600
Wire Wire Line
	3300 1200 3300 1600
Text Label 2650 1200 0    50   ~ 0
Vbb
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 5FA85238
P 7750 5050
F 0 "J5" H 7722 5024 50  0000 R CNN
F 1 "NeoPixel R1 C" H 7722 4933 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 7750 5050 50  0001 C CNN
F 3 "~" H 7750 5050 50  0001 C CNN
	1    7750 5050
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J4
U 1 1 5FA870C1
P 7750 4650
F 0 "J4" H 7722 4624 50  0000 R CNN
F 1 "NeoPixel R1 B" H 7722 4533 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 7750 4650 50  0001 C CNN
F 3 "~" H 7750 4650 50  0001 C CNN
	1    7750 4650
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x03_Male J3
U 1 1 5FA916E0
P 7750 4350
F 0 "J3" H 7722 4374 50  0000 R CNN
F 1 "NeoPixel R1 A" H 7722 4283 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 7750 4350 50  0001 C CNN
F 3 "~" H 7750 4350 50  0001 C CNN
	1    7750 4350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7550 4550 6850 4550
Wire Wire Line
	7550 4650 6850 4650
Wire Wire Line
	7550 4750 6850 4750
Wire Wire Line
	7550 4850 6850 4850
Wire Wire Line
	7550 4950 6850 4950
Wire Wire Line
	7550 5050 6850 5050
Wire Wire Line
	7550 5250 6850 5250
Wire Wire Line
	7550 4250 6850 4250
Wire Wire Line
	7550 4350 6850 4350
Wire Wire Line
	7550 4450 6850 4450
Text Label 7350 4550 0    50   ~ 0
A4
Text Label 7350 4650 0    50   ~ 0
A5
Text Label 7350 4750 0    50   ~ 0
A6
Text Label 7350 4850 0    50   ~ 0
A7
Text Label 7350 5250 0    50   ~ 0
B3
Text Label 7350 5150 0    50   ~ 0
B2
Text Label 7350 5050 0    50   ~ 0
B1
Text Label 7350 4950 0    50   ~ 0
B0
Text Label 7350 4250 0    50   ~ 0
A3
Text Label 7350 4350 0    50   ~ 0
A2
Text Label 7350 4450 0    50   ~ 0
A1
Wire Wire Line
	3450 5550 3200 5550
Text Label 3200 5650 0    50   ~ 0
Vdd
Wire Wire Line
	3450 5650 3200 5650
Wire Wire Line
	7550 5350 6850 5350
Wire Wire Line
	7550 5450 6850 5450
Text Label 7350 5350 0    50   ~ 0
5V
Text Label 6850 5450 0    50   ~ 0
GND
$Comp
L Connector:Conn_01x02_Male J6
U 1 1 5FAE3734
P 7750 5350
F 0 "J6" H 7722 5324 50  0000 R CNN
F 1 "NeoPixel R1 D" H 7722 5233 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 7750 5350 50  0001 C CNN
F 3 "~" H 7750 5350 50  0001 C CNN
	1    7750 5350
	-1   0    0    -1  
$EndComp
Text Label 3200 5550 0    50   ~ 0
Vbb
$Comp
L Connector:Conn_01x02_Male J2
U 1 1 5FAE8623
P 3650 5550
F 0 "J2" H 3622 5524 50  0000 R CNN
F 1 "PWR" H 3622 5433 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 3650 5550 50  0001 C CNN
F 3 "~" H 3650 5550 50  0001 C CNN
	1    3650 5550
	-1   0    0    -1  
$EndComp
Text Notes 6950 4150 0    50   ~ 0
Interface to the NeoPixel R 2L_1
Text Notes 2900 5850 0    50   ~ 0
Jumper for common Vbb and Vdd
Wire Wire Line
	7550 5150 6850 5150
Text Label 6850 4950 0    50   ~ 0
CLK
Text Label 6850 4350 0    50   ~ 0
FF_J
Text Label 6850 4250 0    50   ~ 0
FF_K
Text Label 6850 4450 0    50   ~ 0
FF_SET
Text Label 6850 4550 0    50   ~ 0
FF_RESET
Text Label 6850 5350 0    50   ~ 0
Vdd
NoConn ~ 6850 4650
NoConn ~ 6850 4750
NoConn ~ 6850 4850
NoConn ~ 6850 5250
NoConn ~ 6850 5050
NoConn ~ 6850 5150
Wire Wire Line
	2750 4450 3000 4450
Wire Wire Line
	2650 1200 2900 1200
Connection ~ 2900 1200
Wire Wire Line
	2900 1200 3300 1200
Wire Wire Line
	1450 4450 2750 4450
Wire Wire Line
	1450 4550 2350 4550
$Comp
L Connector:Conn_01x02_Female J7
U 1 1 5FAA49F0
P 9300 2000
F 0 "J7" H 9328 1976 50  0000 L CNN
F 1 "LED" H 9328 1885 50  0000 L CNN
F 2 "LED_Chain:TerminalBlock_bornier-2_P5.08mm" H 9300 2000 50  0001 C CNN
F 3 "~" H 9300 2000 50  0001 C CNN
	1    9300 2000
	1    0    0    -1  
$EndComp
Text Label 8750 2000 0    50   ~ 0
LED1
Text Label 8750 2100 0    50   ~ 0
LED2
$EndSCHEMATC
