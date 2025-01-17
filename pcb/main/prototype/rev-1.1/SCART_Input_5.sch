EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 14 17
Title "OSSW - Open Scart SWitch - Main PCB"
Date "2021-02-05"
Rev "1.1 [ALPHA]"
Comp "Binary Solo"
Comment1 "www.binarysolo.co.uk"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Entry Wire Line
	5125 4475 5225 4575
Entry Wire Line
	5125 4075 5225 4175
Entry Wire Line
	5125 2675 5225 2775
Entry Wire Line
	5125 3175 5225 3275
Entry Wire Line
	5125 3575 5225 3675
Entry Wire Line
	5125 3975 5225 4075
$Comp
L Connector_Generic:Conn_01x21 J3
U 1 1 5F5479A6
P 1400 3575
AR Path="/5E1438D9/5F5479A6" Ref="J3"  Part="1" 
AR Path="/5F516C61/5F5479A6" Ref="J?"  Part="1" 
AR Path="/5F522975/5F5479A6" Ref="J?"  Part="1" 
AR Path="/5F5379DE/5F5479A6" Ref="J7"  Part="1" 
AR Path="/5F543256/5F5479A6" Ref="J?"  Part="1" 
F 0 "J7" H 1400 2350 50  0000 C CNN
F 1 "IN 5" H 1400 2450 50  0000 C CNN
F 2 "ossw:SCART_Female" H 1400 3575 50  0001 C CNN
F 3 "~" H 1400 3575 50  0001 C CNN
	1    1400 3575
	-1   0    0    1   
$EndComp
Entry Wire Line
	5225 3175 5325 3275
Entry Wire Line
	5225 3675 5325 3775
Entry Wire Line
	5225 3275 5325 3375
Entry Wire Line
	5225 3375 5325 3475
Entry Wire Line
	5225 3575 5325 3675
Entry Wire Line
	5225 3875 5325 3975
Wire Wire Line
	1600 2575 1750 2575
Wire Wire Line
	1600 4175 1750 4175
Wire Wire Line
	1750 4175 1750 3775
Wire Wire Line
	1750 3375 1600 3375
Wire Wire Line
	1600 3775 1750 3775
Connection ~ 1750 3775
Wire Wire Line
	1750 3775 1750 3375
Wire Wire Line
	1750 3375 1750 2975
Connection ~ 1750 3375
Wire Wire Line
	1600 4275 1750 4275
Text Label 1800 2675 0    50   ~ 0
CSYNC5
Text Label 1800 3175 0    50   ~ 0
RED5
Text Label 1800 3575 0    50   ~ 0
GREEN5
Text Label 1800 3975 0    50   ~ 0
BLUE5
Text Label 1800 4075 0    50   ~ 0
AL5
Text Label 1800 4475 0    50   ~ 0
AR5
Wire Wire Line
	1750 4275 1750 4175
Connection ~ 1750 4175
Wire Wire Line
	1600 2975 1750 2975
Connection ~ 1750 2975
Wire Wire Line
	1750 2975 1750 2875
Wire Wire Line
	1600 2875 1750 2875
Connection ~ 1750 2875
Wire Wire Line
	1750 2875 1750 2575
Connection ~ 1750 4275
Entry Wire Line
	5125 3075 5225 3175
Text Label 1800 3075 0    50   ~ 0
BLANK5
Entry Wire Line
	5125 3875 5225 3975
Text Label 1800 3875 0    50   ~ 0
FUNC5
$Comp
L power:GND #PWR?
U 1 1 5F5451F4
P 6950 4550
AR Path="/5E143861/5F5451F4" Ref="#PWR?"  Part="1" 
AR Path="/5E1438D9/5F5451F4" Ref="#PWR06"  Part="1" 
AR Path="/5F516C61/5F5451F4" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F5451F4" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F5451F4" Ref="#PWR079"  Part="1" 
AR Path="/5F543256/5F5451F4" Ref="#PWR?"  Part="1" 
F 0 "#PWR079" H 6950 4300 50  0001 C CNN
F 1 "GND" H 6955 4377 50  0000 C CNN
F 2 "" H 6950 4550 50  0001 C CNN
F 3 "" H 6950 4550 50  0001 C CNN
	1    6950 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2925 6800 2875
$Comp
L Device:C_Small C?
U 1 1 5F5451F5
P 7125 2875
AR Path="/5E18BCBF/5F5451F5" Ref="C?"  Part="1" 
AR Path="/5E18AC8A/5F5451F5" Ref="C?"  Part="1" 
AR Path="/5E143861/5F5451F5" Ref="C?"  Part="1" 
AR Path="/5E1438D9/5F5451F5" Ref="C2"  Part="1" 
AR Path="/5F516C61/5F5451F5" Ref="C?"  Part="1" 
AR Path="/5F522975/5F5451F5" Ref="C?"  Part="1" 
AR Path="/5F5379DE/5F5451F5" Ref="C50"  Part="1" 
AR Path="/5F543256/5F5451F5" Ref="C?"  Part="1" 
F 0 "C50" V 7050 2775 50  0000 C CNN
F 1 "0.1uF" V 7225 3050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7125 2875 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/447/UPY-GPHC_X7R_6.3V-to-50V_18-1154002.pdf" H 7125 2875 50  0001 C CNN
F 4 "CC0603KRX7R7BB104" V 7125 2875 50  0001 C CNN "P/N"
	1    7125 2875
	0    1    1    0   
$EndComp
Wire Wire Line
	7025 2875 6800 2875
Connection ~ 6800 2875
Wire Wire Line
	6800 2875 6800 2775
Wire Wire Line
	6750 4325 6750 4475
Wire Wire Line
	6750 4475 6650 4475
Wire Wire Line
	6650 4325 6650 4475
Connection ~ 6650 4475
Wire Wire Line
	6950 4325 6950 4550
$Comp
L power:GND #PWR?
U 1 1 5F54A912
P 7600 2975
AR Path="/5E143861/5F54A912" Ref="#PWR?"  Part="1" 
AR Path="/5E1438D9/5F54A912" Ref="#PWR07"  Part="1" 
AR Path="/5F516C61/5F54A912" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F54A912" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F54A912" Ref="#PWR080"  Part="1" 
AR Path="/5F543256/5F54A912" Ref="#PWR?"  Part="1" 
F 0 "#PWR080" H 7600 2725 50  0001 C CNN
F 1 "GND" H 7605 2802 50  0000 C CNN
F 2 "" H 7600 2975 50  0001 C CNN
F 3 "" H 7600 2975 50  0001 C CNN
	1    7600 2975
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2875 7600 2975
Wire Wire Line
	7225 2875 7600 2875
NoConn ~ 1600 2775
NoConn ~ 1600 3275
NoConn ~ 1600 3475
NoConn ~ 1600 3675
NoConn ~ 1600 4375
NoConn ~ 1600 4575
$Comp
L Device:R_Small R?
U 1 1 5F54520A
P 7700 4825
AR Path="/5E18BCBF/5F54520A" Ref="R?"  Part="1" 
AR Path="/5E143861/5F54520A" Ref="R?"  Part="1" 
AR Path="/5E1438D9/5F54520A" Ref="R3"  Part="1" 
AR Path="/5F516C61/5F54520A" Ref="R?"  Part="1" 
AR Path="/5F522975/5F54520A" Ref="R?"  Part="1" 
AR Path="/5F5379DE/5F54520A" Ref="R64"  Part="1" 
AR Path="/5F543256/5F54520A" Ref="R?"  Part="1" 
F 0 "R64" H 7575 4950 50  0000 L CNN
F 1 "220R" H 7750 4725 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7700 4825 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/315/AOA0000C331-1141874.pdf" H 7700 4825 50  0001 C CNN
F 4 "ERJ-PA3J221V" H 7700 4825 50  0001 C CNN "P/N"
	1    7700 4825
	1    0    0    -1  
$EndComp
$Comp
L Device:LED_Small D?
U 1 1 5F54520B
P 7700 5100
AR Path="/5E143861/5F54520B" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F54520B" Ref="D3"  Part="1" 
AR Path="/5F516C61/5F54520B" Ref="D?"  Part="1" 
AR Path="/5F522975/5F54520B" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F54520B" Ref="D72"  Part="1" 
AR Path="/5F543256/5F54520B" Ref="D?"  Part="1" 
F 0 "D72" V 7775 5175 50  0000 C CNN
F 1 "LED_Small" H 7675 5250 50  0001 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 7700 5100 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/216/APT1608SGC-32861.pdf" V 7700 5100 50  0001 C CNN
F 4 "APT1608SGC" V 7700 5100 50  0001 C CNN "P/N"
	1    7700 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 5275 7700 5200
Wire Wire Line
	7700 5000 7700 4925
Wire Wire Line
	7700 4725 7700 4650
Wire Wire Line
	6650 5275 7700 5275
$Comp
L Device:R_Small R?
U 1 1 5F5451F7
P 8025 4825
AR Path="/5E18BCBF/5F5451F7" Ref="R?"  Part="1" 
AR Path="/5E143861/5F5451F7" Ref="R?"  Part="1" 
AR Path="/5E1438D9/5F5451F7" Ref="R4"  Part="1" 
AR Path="/5F516C61/5F5451F7" Ref="R?"  Part="1" 
AR Path="/5F522975/5F5451F7" Ref="R?"  Part="1" 
AR Path="/5F5379DE/5F5451F7" Ref="R65"  Part="1" 
AR Path="/5F543256/5F5451F7" Ref="R?"  Part="1" 
F 0 "R65" H 7900 4950 50  0000 L CNN
F 1 "220R" H 8075 4725 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8025 4825 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/315/AOA0000C331-1141874.pdf" H 8025 4825 50  0001 C CNN
F 4 "ERJ-PA3J221V" H 8025 4825 50  0001 C CNN "P/N"
	1    8025 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	8025 5275 8025 5200
Wire Wire Line
	8025 5000 8025 4925
Wire Wire Line
	8025 4725 8025 4650
Connection ~ 7700 5275
Wire Wire Line
	7700 5275 8025 5275
$Comp
L Device:LED_Small D?
U 1 1 5F5451F8
P 8025 5100
AR Path="/5E143861/5F5451F8" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F5451F8" Ref="D4"  Part="1" 
AR Path="/5F516C61/5F5451F8" Ref="D?"  Part="1" 
AR Path="/5F522975/5F5451F8" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F5451F8" Ref="D73"  Part="1" 
AR Path="/5F543256/5F5451F8" Ref="D?"  Part="1" 
F 0 "D73" V 8100 5175 50  0000 C CNN
F 1 "LED_Small" H 8000 5250 50  0001 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 8025 5100 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/216/APT1608SGC-32861.pdf" V 8025 5100 50  0001 C CNN
F 4 "APT1608SGC" V 8025 5100 50  0001 C CNN "P/N"
	1    8025 5100
	0    -1   -1   0   
$EndComp
Entry Wire Line
	5225 4175 5325 4275
Entry Wire Line
	5225 4975 5325 5075
Text Label 5350 5075 0    50   ~ 0
BLANK5_SW
Text Label 5350 4275 0    50   ~ 0
FUNC5_SW
$Comp
L Jumper:SolderJumper_3_Bridged12 JP?
U 1 1 5F54A915
P 5925 4475
AR Path="/5E143861/5F54A915" Ref="JP?"  Part="1" 
AR Path="/5E1438D9/5F54A915" Ref="JP3"  Part="1" 
AR Path="/5F516C61/5F54A915" Ref="JP?"  Part="1" 
AR Path="/5F522975/5F54A915" Ref="JP?"  Part="1" 
AR Path="/5F5379DE/5F54A915" Ref="JP9"  Part="1" 
AR Path="/5F543256/5F54A915" Ref="JP?"  Part="1" 
F 0 "JP9" V 5971 4542 50  0000 L CNN
F 1 "FUNC5" V 5880 4542 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 5925 4475 50  0001 C CNN
F 3 "~" H 5925 4475 50  0001 C CNN
	1    5925 4475
	0    -1   1    0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP?
U 1 1 5F5451FA
P 5925 5275
AR Path="/5E143861/5F5451FA" Ref="JP?"  Part="1" 
AR Path="/5E1438D9/5F5451FA" Ref="JP4"  Part="1" 
AR Path="/5F516C61/5F5451FA" Ref="JP?"  Part="1" 
AR Path="/5F522975/5F5451FA" Ref="JP?"  Part="1" 
AR Path="/5F5379DE/5F5451FA" Ref="JP10"  Part="1" 
AR Path="/5F543256/5F5451FA" Ref="JP?"  Part="1" 
F 0 "JP10" V 5971 5342 50  0000 L CNN
F 1 "BLANK5" V 5880 5342 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 5925 5275 50  0001 C CNN
F 3 "~" H 5925 5275 50  0001 C CNN
	1    5925 5275
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F5451FB
P 5925 4750
AR Path="/5E143861/5F5451FB" Ref="#PWR?"  Part="1" 
AR Path="/5E1438D9/5F5451FB" Ref="#PWR045"  Part="1" 
AR Path="/5F516C61/5F5451FB" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F5451FB" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F5451FB" Ref="#PWR076"  Part="1" 
AR Path="/5F543256/5F5451FB" Ref="#PWR?"  Part="1" 
F 0 "#PWR076" H 5925 4500 50  0001 C CNN
F 1 "GND" H 5930 4577 50  0000 C CNN
F 2 "" H 5925 4750 50  0001 C CNN
F 3 "" H 5925 4750 50  0001 C CNN
	1    5925 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 4750 5925 4675
$Comp
L power:GND #PWR?
U 1 1 5F5451FC
P 5925 5550
AR Path="/5E143861/5F5451FC" Ref="#PWR?"  Part="1" 
AR Path="/5E1438D9/5F5451FC" Ref="#PWR046"  Part="1" 
AR Path="/5F516C61/5F5451FC" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F5451FC" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F5451FC" Ref="#PWR077"  Part="1" 
AR Path="/5F543256/5F5451FC" Ref="#PWR?"  Part="1" 
F 0 "#PWR077" H 5925 5300 50  0001 C CNN
F 1 "GND" H 5930 5377 50  0000 C CNN
F 2 "" H 5925 5550 50  0001 C CNN
F 3 "" H 5925 5550 50  0001 C CNN
	1    5925 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5925 5550 5925 5475
Wire Wire Line
	5325 4275 5925 4275
Wire Wire Line
	5325 5075 5925 5075
$Comp
L power:+5V #PWR0107
U 1 1 5F545206
P 6800 2775
AR Path="/5E1438D9/5F545206" Ref="#PWR0107"  Part="1" 
AR Path="/5F516C61/5F545206" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F545206" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F545206" Ref="#PWR078"  Part="1" 
AR Path="/5F543256/5F545206" Ref="#PWR?"  Part="1" 
F 0 "#PWR078" H 6800 2625 50  0001 C CNN
F 1 "+5V" H 6815 2948 50  0000 C CNN
F 2 "" H 6800 2775 50  0001 C CNN
F 3 "" H 6800 2775 50  0001 C CNN
	1    6800 2775
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0108
U 1 1 5F545207
P 7700 4650
AR Path="/5E1438D9/5F545207" Ref="#PWR0108"  Part="1" 
AR Path="/5F516C61/5F545207" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F545207" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F545207" Ref="#PWR081"  Part="1" 
AR Path="/5F543256/5F545207" Ref="#PWR?"  Part="1" 
F 0 "#PWR081" H 7700 4500 50  0001 C CNN
F 1 "+5V" H 7715 4823 50  0000 C CNN
F 2 "" H 7700 4650 50  0001 C CNN
F 3 "" H 7700 4650 50  0001 C CNN
	1    7700 4650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5F545208
P 8025 4650
AR Path="/5E1438D9/5F545208" Ref="#PWR0109"  Part="1" 
AR Path="/5F516C61/5F545208" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F545208" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F545208" Ref="#PWR082"  Part="1" 
AR Path="/5F543256/5F545208" Ref="#PWR?"  Part="1" 
F 0 "#PWR082" H 8025 4500 50  0001 C CNN
F 1 "+5V" H 8040 4823 50  0000 C CNN
F 2 "" H 8025 4650 50  0001 C CNN
F 3 "" H 8025 4650 50  0001 C CNN
	1    8025 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F5451FD
P 3100 5550
AR Path="/5E143861/5F5451FD" Ref="#PWR?"  Part="1" 
AR Path="/5E1438D9/5F5451FD" Ref="#PWR05"  Part="1" 
AR Path="/5F516C61/5F5451FD" Ref="#PWR?"  Part="1" 
AR Path="/5F522975/5F5451FD" Ref="#PWR?"  Part="1" 
AR Path="/5F5379DE/5F5451FD" Ref="#PWR075"  Part="1" 
AR Path="/5F543256/5F5451FD" Ref="#PWR?"  Part="1" 
F 0 "#PWR075" H 3100 5300 50  0001 C CNN
F 1 "GND" H 3105 5377 50  0000 C CNN
F 2 "" H 3100 5550 50  0001 C CNN
F 3 "" H 3100 5550 50  0001 C CNN
	1    3100 5550
	1    0    0    -1  
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F5451FE
P 3250 4925
AR Path="/5E143861/5F5451FE" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F5451FE" Ref="D22"  Part="1" 
AR Path="/5F516C61/5F5451FE" Ref="D?"  Part="1" 
AR Path="/5F522975/5F5451FE" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F5451FE" Ref="D68"  Part="1" 
AR Path="/5F543256/5F5451FE" Ref="D?"  Part="1" 
F 0 "D68" V 3100 4775 50  0000 L CNN
F 1 "D_TVS" V 3295 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3250 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3250 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 3250 4925 50  0001 C CNN "P/N"
	1    3250 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F5479B2
P 3550 4925
AR Path="/5E143861/5F5479B2" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F5479B2" Ref="D23"  Part="1" 
AR Path="/5F516C61/5F5479B2" Ref="D?"  Part="1" 
AR Path="/5F522975/5F5479B2" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F5479B2" Ref="D69"  Part="1" 
AR Path="/5F543256/5F5479B2" Ref="D?"  Part="1" 
F 0 "D69" V 3400 4775 50  0000 L CNN
F 1 "D_TVS" V 3595 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3550 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3550 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 3550 4925 50  0001 C CNN "P/N"
	1    3550 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F545200
P 3850 4925
AR Path="/5E143861/5F545200" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F545200" Ref="D24"  Part="1" 
AR Path="/5F516C61/5F545200" Ref="D?"  Part="1" 
AR Path="/5F522975/5F545200" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F545200" Ref="D70"  Part="1" 
AR Path="/5F543256/5F545200" Ref="D?"  Part="1" 
F 0 "D70" V 3700 4775 50  0000 L CNN
F 1 "D_TVS" V 3895 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3850 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3850 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 3850 4925 50  0001 C CNN "P/N"
	1    3850 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F545201
P 4150 4925
AR Path="/5E143861/5F545201" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F545201" Ref="D25"  Part="1" 
AR Path="/5F516C61/5F545201" Ref="D?"  Part="1" 
AR Path="/5F522975/5F545201" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F545201" Ref="D71"  Part="1" 
AR Path="/5F543256/5F545201" Ref="D?"  Part="1" 
F 0 "D71" V 4000 4775 50  0000 L CNN
F 1 "D_TVS" V 4195 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 4150 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 4150 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 4150 4925 50  0001 C CNN "P/N"
	1    4150 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F545202
P 2050 4925
AR Path="/5E143861/5F545202" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F545202" Ref="D18"  Part="1" 
AR Path="/5F516C61/5F545202" Ref="D?"  Part="1" 
AR Path="/5F522975/5F545202" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F545202" Ref="D64"  Part="1" 
AR Path="/5F543256/5F545202" Ref="D?"  Part="1" 
F 0 "D64" V 1900 4775 50  0000 L CNN
F 1 "D_TVS" V 2095 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 2050 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 2050 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 2050 4925 50  0001 C CNN "P/N"
	1    2050 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F5479B6
P 2350 4925
AR Path="/5E143861/5F5479B6" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F5479B6" Ref="D19"  Part="1" 
AR Path="/5F516C61/5F5479B6" Ref="D?"  Part="1" 
AR Path="/5F522975/5F5479B6" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F5479B6" Ref="D65"  Part="1" 
AR Path="/5F543256/5F5479B6" Ref="D?"  Part="1" 
F 0 "D65" V 2200 4775 50  0000 L CNN
F 1 "D_TVS" V 2395 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 2350 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 2350 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 2350 4925 50  0001 C CNN "P/N"
	1    2350 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F545204
P 2650 4925
AR Path="/5E143861/5F545204" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F545204" Ref="D20"  Part="1" 
AR Path="/5F516C61/5F545204" Ref="D?"  Part="1" 
AR Path="/5F522975/5F545204" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F545204" Ref="D66"  Part="1" 
AR Path="/5F543256/5F545204" Ref="D?"  Part="1" 
F 0 "D66" V 2500 4775 50  0000 L CNN
F 1 "D_TVS" V 2695 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 2650 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 2650 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 2650 4925 50  0001 C CNN "P/N"
	1    2650 4925
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F545205
P 2950 4925
AR Path="/5E143861/5F545205" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F545205" Ref="D21"  Part="1" 
AR Path="/5F516C61/5F545205" Ref="D?"  Part="1" 
AR Path="/5F522975/5F545205" Ref="D?"  Part="1" 
AR Path="/5F5379DE/5F545205" Ref="D67"  Part="1" 
AR Path="/5F543256/5F545205" Ref="D?"  Part="1" 
F 0 "D67" V 2800 4775 50  0000 L CNN
F 1 "D_TVS" V 2995 5004 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 2950 4925 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 2950 4925 50  0001 C CNN
F 4 "GG040205170N2P" V 2950 4925 50  0001 C CNN "P/N"
	1    2950 4925
	0    1    1    0   
$EndComp
Wire Wire Line
	2050 5075 2050 5275
Wire Wire Line
	2050 5275 2350 5275
Wire Wire Line
	4150 5275 4150 5075
Wire Wire Line
	2350 5075 2350 5275
Connection ~ 2350 5275
Wire Wire Line
	2350 5275 2650 5275
Wire Wire Line
	2650 5075 2650 5275
Connection ~ 2650 5275
Wire Wire Line
	2650 5275 2950 5275
Wire Wire Line
	2950 5075 2950 5275
Connection ~ 2950 5275
Wire Wire Line
	2950 5275 3100 5275
Wire Wire Line
	3250 5075 3250 5275
Connection ~ 3250 5275
Wire Wire Line
	3250 5275 3550 5275
Wire Wire Line
	3550 5075 3550 5275
Connection ~ 3550 5275
Wire Wire Line
	3550 5275 3850 5275
Wire Wire Line
	3850 5075 3850 5275
Connection ~ 3850 5275
Wire Wire Line
	3850 5275 4150 5275
Connection ~ 3100 5275
Wire Wire Line
	3100 5275 3250 5275
Wire Wire Line
	2050 5275 1750 5275
Connection ~ 2050 5275
Wire Wire Line
	2050 4775 2050 4475
Wire Wire Line
	2350 4775 2350 4075
Wire Wire Line
	2650 4775 2650 3975
Wire Wire Line
	2950 4775 2950 3875
Wire Wire Line
	3250 4775 3250 3575
Wire Wire Line
	3550 4775 3550 3175
Wire Wire Line
	3850 4775 3850 3075
Wire Wire Line
	4150 4775 4150 2675
Wire Wire Line
	3100 5275 3100 5550
Wire Wire Line
	1750 4275 1750 5275
Wire Wire Line
	1600 4475 2050 4475
Connection ~ 2050 4475
Wire Wire Line
	1600 4075 2350 4075
Connection ~ 2350 4075
Wire Wire Line
	1600 3975 2650 3975
Connection ~ 2650 3975
Wire Wire Line
	1600 3875 2950 3875
Connection ~ 2950 3875
Wire Wire Line
	1600 3575 3250 3575
Connection ~ 3250 3575
Wire Wire Line
	1600 3175 3550 3175
Connection ~ 3550 3175
Wire Wire Line
	1600 3075 3850 3075
Connection ~ 3850 3075
Wire Wire Line
	1600 2675 4150 2675
Connection ~ 4150 2675
Text Label 9325 4075 2    50   ~ 0
SCART1_OUT8
Text Label 9325 4175 2    50   ~ 0
SCART1_OUT16
Entry Wire Line
	9375 4075 9475 4175
Entry Wire Line
	9375 4175 9475 4275
Wire Bus Line
	9475 4075 9575 4075
Text HLabel 9575 4075 2    50   Output ~ 0
SCART1_OUT[1..21]
Entry Wire Line
	9375 4375 9475 4475
Entry Wire Line
	9375 4475 9475 4575
Wire Bus Line
	9475 4375 9575 4375
Text HLabel 9575 4375 2    50   Output ~ 0
SCART2_OUT[1..21]
Wire Wire Line
	8600 4175 8600 4475
Wire Wire Line
	8700 4075 8700 4375
Text Label 9325 4375 2    50   ~ 0
SCART2_OUT8
Text Label 9325 4475 2    50   ~ 0
SCART2_OUT16
Text Label 8575 3475 2    50   ~ 0
VIDEO_AMP1
Text Label 8575 3575 2    50   ~ 0
VIDEO_AMP2
Text Label 8575 3675 2    50   ~ 0
VIDEO_AMP3
Text Label 8575 3775 2    50   ~ 0
VIDEO_AMP4
Entry Wire Line
	9375 3475 9475 3575
Entry Wire Line
	9375 3575 9475 3675
Entry Wire Line
	9375 3675 9475 3775
Entry Wire Line
	9375 3775 9475 3875
Wire Bus Line
	9475 3475 9575 3475
Text HLabel 9575 3475 2    50   Output ~ 0
VIDEO_AMP[1..4]
Entry Wire Line
	9375 3025 9475 3125
Entry Wire Line
	9375 3125 9475 3225
Wire Bus Line
	9475 3025 9575 3025
Text HLabel 9575 3025 2    50   Output ~ 0
AUDIO_AMP[1..2]
Text Label 8600 3025 2    50   ~ 0
AUDIO_AMP1
Text Label 8600 3125 2    50   ~ 0
AUDIO_AMP2
Text HLabel 9575 5275 2    50   Input ~ 0
~BUS_ENABLE[1..8]
Entry Wire Line
	9375 5275 9475 5375
Wire Bus Line
	9475 5375 9475 5275
Wire Bus Line
	9475 5275 9575 5275
Text Label 9300 5275 2    50   ~ 0
~BUS_ENABLE5
Wire Wire Line
	8600 4175 9375 4175
Wire Wire Line
	8600 4475 9375 4475
Wire Wire Line
	8700 4075 9375 4075
Wire Wire Line
	8700 4375 9375 4375
Wire Wire Line
	7200 3275 7925 3275
Entry Wire Line
	7925 3275 8025 3375
Entry Wire Line
	7925 3375 8025 3475
Entry Wire Line
	7925 3475 8025 3575
Entry Wire Line
	7925 3575 8025 3675
Entry Wire Line
	7925 3675 8025 3775
Entry Wire Line
	7925 3775 8025 3875
Entry Wire Line
	7925 3875 8025 3975
Entry Wire Line
	7925 3975 8025 4075
Wire Wire Line
	7925 3375 7200 3375
Wire Wire Line
	7925 3475 7200 3475
Wire Wire Line
	7925 3575 7200 3575
Wire Wire Line
	7925 3675 7200 3675
Wire Wire Line
	7925 3775 7200 3775
Wire Wire Line
	7925 3875 7200 3875
Wire Wire Line
	7925 3975 7200 3975
Wire Wire Line
	9375 3025 8125 3025
Entry Wire Line
	8025 2925 8125 3025
Entry Wire Line
	8025 3025 8125 3125
Wire Wire Line
	9375 3125 8125 3125
Wire Wire Line
	8700 4075 8125 4075
Connection ~ 8700 4075
Entry Wire Line
	8025 3975 8125 4075
Entry Wire Line
	8025 4075 8125 4175
Wire Wire Line
	8600 4175 8125 4175
Connection ~ 8600 4175
Wire Wire Line
	9375 3475 8125 3475
Wire Wire Line
	9375 3575 8125 3575
Wire Wire Line
	9375 3675 8125 3675
Wire Wire Line
	9375 3775 8125 3775
Entry Wire Line
	8025 3375 8125 3475
Entry Wire Line
	8025 3475 8125 3575
Entry Wire Line
	8025 3575 8125 3675
Entry Wire Line
	8025 3675 8125 3775
Text Label 7675 3375 2    50   ~ 0
AUDIO_AMP1
Text Label 7675 3275 2    50   ~ 0
AUDIO_AMP2
Text Label 8400 4075 2    50   ~ 0
SCART8
Text Label 8450 4175 2    50   ~ 0
SCART16
Text Label 7500 3575 2    50   ~ 0
SCART8
Text Label 7550 3875 2    50   ~ 0
SCART16
Text Label 7675 3475 2    50   ~ 0
VIDEO_AMP1
Text Label 7675 3675 2    50   ~ 0
VIDEO_AMP2
Text Label 7675 3775 2    50   ~ 0
VIDEO_AMP3
Text Label 7675 3975 2    50   ~ 0
VIDEO_AMP4
Text Label 5350 3275 0    50   ~ 0
AR5_SW
Text Label 5350 3375 0    50   ~ 0
AL5_SW
Text Label 5350 3475 0    50   ~ 0
BLUE5_SW
Text Label 5350 3675 0    50   ~ 0
GREEN5_SW
Text Label 5350 3775 0    50   ~ 0
RED5_SW
Wire Wire Line
	5325 3375 6400 3375
Wire Wire Line
	5325 3475 6400 3475
Wire Wire Line
	5325 3675 6400 3675
Wire Wire Line
	5325 3775 6400 3775
Wire Wire Line
	6225 3575 6400 3575
Wire Wire Line
	6225 3575 6225 4475
Wire Wire Line
	6325 5275 6325 3875
Wire Wire Line
	6325 3875 6400 3875
Text Label 5350 3975 0    50   ~ 0
CSYNC5_SW
Wire Wire Line
	5325 3275 6400 3275
Wire Wire Line
	6650 4475 6650 5275
Wire Wire Line
	9375 5275 8025 5275
Connection ~ 8025 5275
$Comp
L ossw:SN74CBT3244 U2
U 1 1 5F54A925
P 6800 3625
AR Path="/5E1438D9/5F54A925" Ref="U2"  Part="1" 
AR Path="/5F516C61/5F54A925" Ref="U?"  Part="1" 
AR Path="/5F522975/5F54A925" Ref="U?"  Part="1" 
AR Path="/5F5379DE/5F54A925" Ref="U12"  Part="1" 
AR Path="/5F543256/5F54A925" Ref="U?"  Part="1" 
F 0 "U12" H 6800 4506 50  0000 C CNN
F 1 "SN74CBT3244" H 6800 4415 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 6900 2575 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74cbt3244c.pdf?HQS=TI-null-null-mousermode-df-pf-null-wwe&ts=1602451228311&ref_url=https%253A%252F%252Fwww.mouser.co.uk%252F" H 6800 3525 50  0001 C CNN
F 4 "SN74CBT3244CDWR" H 6800 3625 50  0001 C CNN "P/N"
	1    6800 3625
	1    0    0    -1  
$EndComp
Text Label 4650 3075 0    50   ~ 0
BLANK5_SW
Text Label 4650 2675 0    50   ~ 0
CSYNC5_SW
Text Label 4750 3175 0    50   ~ 0
RED5_SW
Text Label 4650 3575 0    50   ~ 0
GREEN5_SW
Text Label 4700 3875 0    50   ~ 0
FUNC5_SW
Text Label 4725 3975 0    50   ~ 0
BLUE5_SW
Text Label 4825 4075 0    50   ~ 0
AL5_SW
Text Label 4800 4475 0    50   ~ 0
AR5_SW
Wire Wire Line
	6075 4475 6225 4475
Wire Wire Line
	6075 5275 6325 5275
Wire Wire Line
	5325 3975 6400 3975
Wire Wire Line
	2050 4475 5125 4475
Wire Wire Line
	2350 4075 5125 4075
Wire Wire Line
	2650 3975 5125 3975
Wire Wire Line
	2950 3875 5125 3875
Wire Wire Line
	3250 3575 5125 3575
Wire Wire Line
	3550 3175 5125 3175
Wire Wire Line
	3850 3075 5125 3075
Wire Wire Line
	4150 2675 5125 2675
Wire Bus Line
	9475 3025 9475 3225
Wire Bus Line
	9475 4375 9475 4575
Wire Bus Line
	9475 4075 9475 4275
Wire Bus Line
	9475 3475 9475 3875
Wire Bus Line
	8025 2925 8025 4075
Wire Bus Line
	5225 2775 5225 4975
$EndSCHEMATC
