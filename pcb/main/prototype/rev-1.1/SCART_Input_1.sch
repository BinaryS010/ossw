EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 17
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
	5425 4450 5525 4550
Entry Wire Line
	5425 4050 5525 4150
Entry Wire Line
	5425 2650 5525 2750
Entry Wire Line
	5425 3150 5525 3250
Entry Wire Line
	5425 3550 5525 3650
Entry Wire Line
	5425 3950 5525 4050
$Comp
L Connector_Generic:Conn_01x21 J1
U 1 1 5E15F9FB
P 1800 3550
F 0 "J1" H 1800 2325 50  0000 C CNN
F 1 "IN 1" H 1800 2425 50  0000 C CNN
F 2 "ossw:SCART_Female" H 1800 3550 50  0001 C CNN
F 3 "~" H 1800 3550 50  0001 C CNN
	1    1800 3550
	-1   0    0    1   
$EndComp
Entry Wire Line
	5525 3150 5625 3250
Entry Wire Line
	5525 3550 5625 3650
Entry Wire Line
	5525 3250 5625 3350
Entry Wire Line
	5525 3350 5625 3450
Entry Wire Line
	5525 3650 5625 3750
Entry Wire Line
	5525 4150 5625 4250
Wire Wire Line
	2000 2550 2150 2550
Wire Wire Line
	2000 4150 2150 4150
Wire Wire Line
	2150 4150 2150 3750
Wire Wire Line
	2150 3350 2000 3350
Wire Wire Line
	2000 3750 2150 3750
Connection ~ 2150 3750
Wire Wire Line
	2150 3750 2150 3350
Wire Wire Line
	2150 3350 2150 2950
Connection ~ 2150 3350
Wire Wire Line
	2000 4250 2150 4250
Text Label 2200 2650 0    50   ~ 0
CSYNC1
Text Label 2200 3150 0    50   ~ 0
RED1
Text Label 2200 3550 0    50   ~ 0
GREEN1
Text Label 2200 3950 0    50   ~ 0
BLUE1
Text Label 2200 4050 0    50   ~ 0
AL1
Text Label 2200 4450 0    50   ~ 0
AR1
Wire Wire Line
	2150 4250 2150 4150
Connection ~ 2150 4150
Wire Wire Line
	2000 2950 2150 2950
Connection ~ 2150 2950
Wire Wire Line
	2150 2950 2150 2850
Wire Wire Line
	2000 2850 2150 2850
Connection ~ 2150 2850
Wire Wire Line
	2150 2850 2150 2550
$Comp
L power:GND #PWR02
U 1 1 5E15FA2F
P 7200 4525
F 0 "#PWR02" H 7200 4275 50  0001 C CNN
F 1 "GND" H 7205 4352 50  0000 C CNN
F 2 "" H 7200 4525 50  0001 C CNN
F 3 "" H 7200 4525 50  0001 C CNN
	1    7200 4525
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5E15FA37
P 3500 5525
F 0 "#PWR01" H 3500 5275 50  0001 C CNN
F 1 "GND" H 3505 5352 50  0000 C CNN
F 2 "" H 3500 5525 50  0001 C CNN
F 3 "" H 3500 5525 50  0001 C CNN
	1    3500 5525
	1    0    0    -1  
$EndComp
Entry Wire Line
	5425 3850 5525 3950
Text Label 2200 3850 0    50   ~ 0
FUNC1
Entry Wire Line
	5425 3050 5525 3150
Text Label 2200 3050 0    50   ~ 0
BLANK1
Entry Wire Line
	5525 4950 5625 5050
Text Label 5650 3250 0    50   ~ 0
AR1_SW
Text Label 5650 5050 0    50   ~ 0
BLANK1_SW
Text Label 5650 3350 0    50   ~ 0
AL1_SW
Text Label 5650 3450 0    50   ~ 0
BLUE1_SW
Text Label 5650 4250 0    50   ~ 0
FUNC1_SW
Text Label 5650 3650 0    50   ~ 0
GREEN1_SW
Text Label 5650 3750 0    50   ~ 0
RED1_SW
Wire Wire Line
	7050 2900 7050 2850
$Comp
L Device:C_Small C?
U 1 1 5E2A9B9E
P 7375 2850
AR Path="/5E18BCBF/5E2A9B9E" Ref="C?"  Part="1" 
AR Path="/5E18AC8A/5E2A9B9E" Ref="C?"  Part="1" 
AR Path="/5E143861/5E2A9B9E" Ref="C1"  Part="1" 
F 0 "C1" V 7300 2750 50  0000 C CNN
F 1 "0.1uF" V 7475 3025 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7375 2850 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/447/UPY-GPHC_X7R_6.3V-to-50V_18-1154002.pdf" H 7375 2850 50  0001 C CNN
F 4 "CC0603KRX7R7BB104" V 7375 2850 50  0001 C CNN "P/N"
	1    7375 2850
	0    1    1    0   
$EndComp
Wire Wire Line
	7275 2850 7050 2850
Connection ~ 7050 2850
Wire Wire Line
	7050 2850 7050 2750
Wire Wire Line
	7000 4300 7000 4450
Wire Wire Line
	7000 4450 6900 4450
$Comp
L power:GND #PWR03
U 1 1 5E2B8EDE
P 7850 2950
F 0 "#PWR03" H 7850 2700 50  0001 C CNN
F 1 "GND" H 7855 2777 50  0000 C CNN
F 2 "" H 7850 2950 50  0001 C CNN
F 3 "" H 7850 2950 50  0001 C CNN
	1    7850 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 2850 7850 2950
Wire Wire Line
	7475 2850 7850 2850
$Comp
L Device:R_Small R?
U 1 1 5E3285A3
P 7950 4775
AR Path="/5E18BCBF/5E3285A3" Ref="R?"  Part="1" 
AR Path="/5E143861/5E3285A3" Ref="R1"  Part="1" 
F 0 "R1" H 7825 4900 50  0000 L CNN
F 1 "220R" H 8000 4675 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7950 4775 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/315/AOA0000C331-1141874.pdf" H 7950 4775 50  0001 C CNN
F 4 "ERJ-PA3J221V" H 7950 4775 50  0001 C CNN "P/N"
	1    7950 4775
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 4300 7200 4525
Wire Wire Line
	6900 4450 6900 4300
Connection ~ 6900 4450
NoConn ~ 2000 2750
NoConn ~ 2000 3250
NoConn ~ 2000 3450
NoConn ~ 2000 3650
NoConn ~ 2000 4350
NoConn ~ 2000 4550
Text Label 9575 4050 2    50   ~ 0
SCART1_OUT8
Text Label 9575 4150 2    50   ~ 0
SCART1_OUT16
Entry Wire Line
	9625 4050 9725 4150
Entry Wire Line
	9625 4150 9725 4250
Wire Bus Line
	9725 4050 9825 4050
Text HLabel 9825 4050 2    50   Output ~ 0
SCART1_OUT[1..21]
Entry Wire Line
	9625 4350 9725 4450
Entry Wire Line
	9625 4450 9725 4550
Wire Bus Line
	9725 4350 9825 4350
Text HLabel 9825 4350 2    50   Output ~ 0
SCART2_OUT[1..21]
Wire Wire Line
	8850 4150 8850 4450
Wire Wire Line
	8950 4050 8950 4350
Text Label 9575 4350 2    50   ~ 0
SCART2_OUT8
Text Label 9575 4450 2    50   ~ 0
SCART2_OUT16
Text Label 8825 3450 2    50   ~ 0
VIDEO_AMP1
Text Label 8825 3550 2    50   ~ 0
VIDEO_AMP2
Text Label 8825 3650 2    50   ~ 0
VIDEO_AMP3
Text Label 8825 3750 2    50   ~ 0
VIDEO_AMP4
Entry Wire Line
	9625 3450 9725 3550
Entry Wire Line
	9625 3550 9725 3650
Entry Wire Line
	9625 3650 9725 3750
Entry Wire Line
	9625 3750 9725 3850
Wire Bus Line
	9725 3450 9825 3450
Text HLabel 9825 3450 2    50   Output ~ 0
VIDEO_AMP[1..4]
Entry Wire Line
	9625 3000 9725 3100
Entry Wire Line
	9625 3100 9725 3200
Wire Bus Line
	9725 3000 9825 3000
Text HLabel 9825 3000 2    50   Output ~ 0
AUDIO_AMP[1..2]
Text Label 8850 3000 2    50   ~ 0
AUDIO_AMP1
Text Label 8850 3100 2    50   ~ 0
AUDIO_AMP2
Text HLabel 9825 5225 2    50   Input ~ 0
~BUS_ENABLE[1..8]
Entry Wire Line
	9625 5225 9725 5325
Wire Bus Line
	9725 5325 9725 5225
Wire Bus Line
	9725 5225 9825 5225
Text Label 9550 5225 2    50   ~ 0
~BUS_ENABLE1
$Comp
L Device:LED_Small D1
U 1 1 5FB67F38
P 7950 5050
F 0 "D1" V 8025 5125 50  0000 C CNN
F 1 "LED_Small" H 7925 5200 50  0001 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 7950 5050 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/216/APT1608SGC-32861.pdf" V 7950 5050 50  0001 C CNN
F 4 "APT1608SGC" V 7950 5050 50  0001 C CNN "P/N"
	1    7950 5050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6900 5225 7950 5225
Wire Wire Line
	7950 5225 7950 5150
Wire Wire Line
	7950 4950 7950 4875
Wire Wire Line
	7950 4675 7950 4600
$Comp
L Device:R_Small R?
U 1 1 5F2D9A80
P 8250 4775
AR Path="/5E18BCBF/5F2D9A80" Ref="R?"  Part="1" 
AR Path="/5E143861/5F2D9A80" Ref="R2"  Part="1" 
AR Path="/5E1438D9/5F2D9A80" Ref="R?"  Part="1" 
F 0 "R2" H 8125 4900 50  0000 L CNN
F 1 "220R" H 8300 4675 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8250 4775 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/315/AOA0000C331-1141874.pdf" H 8250 4775 50  0001 C CNN
F 4 "ERJ-PA3J221V" H 8250 4775 50  0001 C CNN "P/N"
	1    8250 4775
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 5225 8250 5150
Wire Wire Line
	8250 4950 8250 4875
Wire Wire Line
	8250 4675 8250 4600
Connection ~ 7950 5225
Connection ~ 8250 5225
Wire Wire Line
	7950 5225 8250 5225
Wire Wire Line
	8250 5225 9625 5225
$Comp
L Device:LED_Small D2
U 1 1 5F2EE7D8
P 8250 5050
F 0 "D2" V 8325 5125 50  0000 C CNN
F 1 "LED_Small" H 8225 5200 50  0001 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" V 8250 5050 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/216/APT1608SGC-32861.pdf" V 8250 5050 50  0001 C CNN
F 4 "APT1608SGC" V 8250 5050 50  0001 C CNN "P/N"
	1    8250 5050
	0    -1   -1   0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Bridged12 JP1
U 1 1 5F300F12
P 6225 4450
F 0 "JP1" V 6271 4517 50  0000 L CNN
F 1 "FUNC1" V 6180 4517 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 6225 4450 50  0001 C CNN
F 3 "~" H 6225 4450 50  0001 C CNN
	1    6225 4450
	0    -1   1    0   
$EndComp
$Comp
L power:GND #PWR043
U 1 1 5F303D16
P 6225 4725
F 0 "#PWR043" H 6225 4475 50  0001 C CNN
F 1 "GND" H 6230 4552 50  0000 C CNN
F 2 "" H 6225 4725 50  0001 C CNN
F 3 "" H 6225 4725 50  0001 C CNN
	1    6225 4725
	1    0    0    -1  
$EndComp
Wire Wire Line
	5625 3350 6650 3350
Wire Wire Line
	5625 3450 6650 3450
Wire Wire Line
	5625 3650 6650 3650
Wire Wire Line
	5625 3750 6650 3750
Wire Wire Line
	6225 4725 6225 4650
$Comp
L power:GND #PWR044
U 1 1 5F332EB4
P 6225 5525
F 0 "#PWR044" H 6225 5275 50  0001 C CNN
F 1 "GND" H 6230 5352 50  0000 C CNN
F 2 "" H 6225 5525 50  0001 C CNN
F 3 "" H 6225 5525 50  0001 C CNN
	1    6225 5525
	1    0    0    -1  
$EndComp
Wire Wire Line
	6225 5525 6225 5450
Wire Wire Line
	5625 4250 6225 4250
Wire Wire Line
	5625 5050 6225 5050
$Comp
L power:+5V #PWR0106
U 1 1 5F48B565
P 7050 2750
F 0 "#PWR0106" H 7050 2600 50  0001 C CNN
F 1 "+5V" H 7065 2923 50  0000 C CNN
F 2 "" H 7050 2750 50  0001 C CNN
F 3 "" H 7050 2750 50  0001 C CNN
	1    7050 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F5AFD3A
P 7950 4600
AR Path="/5E18BCCA/5F5AFD3A" Ref="#PWR?"  Part="1" 
AR Path="/5E143861/5F5AFD3A" Ref="#PWR0134"  Part="1" 
F 0 "#PWR0134" H 7950 4450 50  0001 C CNN
F 1 "+5V" V 7965 4728 50  0000 L CNN
F 2 "" H 7950 4600 50  0001 C CNN
F 3 "" H 7950 4600 50  0001 C CNN
	1    7950 4600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F5B239C
P 8250 4600
AR Path="/5E18BCCA/5F5B239C" Ref="#PWR?"  Part="1" 
AR Path="/5E143861/5F5B239C" Ref="#PWR0135"  Part="1" 
F 0 "#PWR0135" H 8250 4450 50  0001 C CNN
F 1 "+5V" V 8265 4728 50  0000 L CNN
F 2 "" H 8250 4600 50  0001 C CNN
F 3 "" H 8250 4600 50  0001 C CNN
	1    8250 4600
	1    0    0    -1  
$EndComp
$Comp
L Device:D_TVS D14
U 1 1 5F14CCB7
P 3650 4900
F 0 "D14" V 3500 4750 50  0000 L CNN
F 1 "D_TVS" V 3695 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3650 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3650 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 3650 4900 50  0001 C CNN "P/N"
	1    3650 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D15
U 1 1 5F175231
P 3950 4900
F 0 "D15" V 3800 4750 50  0000 L CNN
F 1 "D_TVS" V 3995 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3950 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3950 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 3950 4900 50  0001 C CNN "P/N"
	1    3950 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D16
U 1 1 5F1779A3
P 4250 4900
F 0 "D16" V 4100 4750 50  0000 L CNN
F 1 "D_TVS" V 4295 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 4250 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 4250 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 4250 4900 50  0001 C CNN "P/N"
	1    4250 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D17
U 1 1 5F1779AA
P 4550 4900
F 0 "D17" V 4400 4750 50  0000 L CNN
F 1 "D_TVS" V 4595 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 4550 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 4550 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 4550 4900 50  0001 C CNN "P/N"
	1    4550 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D10
U 1 1 5F17C2EA
P 2450 4900
F 0 "D10" V 2300 4750 50  0000 L CNN
F 1 "D_TVS" V 2495 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 2450 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 2450 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 2450 4900 50  0001 C CNN "P/N"
	1    2450 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D11
U 1 1 5F17C2F1
P 2750 4900
F 0 "D11" V 2600 4750 50  0000 L CNN
F 1 "D_TVS" V 2795 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 2750 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 2750 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 2750 4900 50  0001 C CNN "P/N"
	1    2750 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D12
U 1 1 5F17C2F8
P 3050 4900
F 0 "D12" V 2900 4750 50  0000 L CNN
F 1 "D_TVS" V 3095 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3050 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3050 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 3050 4900 50  0001 C CNN "P/N"
	1    3050 4900
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D13
U 1 1 5F17C2FF
P 3350 4900
F 0 "D13" V 3200 4750 50  0000 L CNN
F 1 "D_TVS" V 3395 4979 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 3350 4900 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 3350 4900 50  0001 C CNN
F 4 "GG040205170N2P" V 3350 4900 50  0001 C CNN "P/N"
	1    3350 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 5050 2450 5250
Wire Wire Line
	2450 5250 2750 5250
Wire Wire Line
	4550 5250 4550 5050
Wire Wire Line
	2750 5050 2750 5250
Connection ~ 2750 5250
Wire Wire Line
	2750 5250 3050 5250
Wire Wire Line
	3050 5050 3050 5250
Connection ~ 3050 5250
Wire Wire Line
	3050 5250 3350 5250
Wire Wire Line
	3350 5050 3350 5250
Connection ~ 3350 5250
Wire Wire Line
	3350 5250 3500 5250
Wire Wire Line
	3650 5050 3650 5250
Connection ~ 3650 5250
Wire Wire Line
	3650 5250 3950 5250
Wire Wire Line
	3950 5050 3950 5250
Connection ~ 3950 5250
Wire Wire Line
	3950 5250 4250 5250
Wire Wire Line
	4250 5050 4250 5250
Connection ~ 4250 5250
Wire Wire Line
	4250 5250 4550 5250
Connection ~ 3500 5250
Wire Wire Line
	3500 5250 3650 5250
Wire Wire Line
	2000 2650 4550 2650
Wire Wire Line
	2000 3050 4250 3050
Wire Wire Line
	2000 3150 3950 3150
Wire Wire Line
	2000 3550 3650 3550
Wire Wire Line
	2000 3850 3350 3850
Wire Wire Line
	2000 3950 3050 3950
Wire Wire Line
	2000 4050 2750 4050
Wire Wire Line
	2000 4450 2450 4450
Wire Wire Line
	2450 5250 2150 5250
Wire Wire Line
	2150 5250 2150 4250
Connection ~ 2450 5250
Connection ~ 2150 4250
Wire Wire Line
	2450 4750 2450 4450
Connection ~ 2450 4450
Wire Wire Line
	2750 4750 2750 4050
Connection ~ 2750 4050
Wire Wire Line
	3050 4750 3050 3950
Connection ~ 3050 3950
Wire Wire Line
	3350 4750 3350 3850
Connection ~ 3350 3850
Wire Wire Line
	3650 4750 3650 3550
Connection ~ 3650 3550
Wire Wire Line
	3950 4750 3950 3150
Connection ~ 3950 3150
Wire Wire Line
	4250 4750 4250 3050
Connection ~ 4250 3050
Wire Wire Line
	4550 4750 4550 2650
Connection ~ 4550 2650
Wire Wire Line
	3500 5250 3500 5525
$Comp
L ossw:SN74CBT3244 U1
U 1 1 5F4F8328
P 7050 3600
F 0 "U1" H 7050 4481 50  0000 C CNN
F 1 "SN74CBT3244" H 7500 2925 50  0000 C CNN
F 2 "Package_SO:SOIC-20W_7.5x12.8mm_P1.27mm" H 7150 2550 50  0001 C CNN
F 3 "https://www.ti.com/lit/ds/symlink/sn74cbt3244c.pdf?HQS=TI-null-null-mousermode-df-pf-null-wwe&ts=1602451228311&ref_url=https%253A%252F%252Fwww.mouser.co.uk%252F" H 7050 3500 50  0001 C CNN
F 4 "SN74CBT3244CDWR" H 7050 3600 50  0001 C CNN "P/N"
	1    7050 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6475 3550 6650 3550
Wire Wire Line
	6475 3550 6475 4450
Wire Wire Line
	6575 5250 6575 3850
Wire Wire Line
	6575 3850 6650 3850
Entry Wire Line
	5525 3850 5625 3950
Text Label 5650 3950 0    50   ~ 0
CSYNC1_SW
Wire Wire Line
	5625 3250 6650 3250
Wire Wire Line
	6900 4450 6900 5225
Wire Wire Line
	8850 4150 9625 4150
Wire Wire Line
	8850 4450 9625 4450
Wire Wire Line
	8950 4050 9625 4050
Wire Wire Line
	8950 4350 9625 4350
Wire Wire Line
	7450 3250 8175 3250
Entry Wire Line
	8175 3250 8275 3350
Entry Wire Line
	8175 3350 8275 3450
Entry Wire Line
	8175 3450 8275 3550
Entry Wire Line
	8175 3550 8275 3650
Entry Wire Line
	8175 3650 8275 3750
Entry Wire Line
	8175 3750 8275 3850
Entry Wire Line
	8175 3850 8275 3950
Entry Wire Line
	8175 3950 8275 4050
Wire Wire Line
	8175 3350 7450 3350
Wire Wire Line
	8175 3450 7450 3450
Wire Wire Line
	8175 3550 7450 3550
Wire Wire Line
	8175 3650 7450 3650
Wire Wire Line
	8175 3750 7450 3750
Wire Wire Line
	8175 3850 7450 3850
Wire Wire Line
	8175 3950 7450 3950
Wire Wire Line
	9625 3000 8375 3000
Entry Wire Line
	8275 2900 8375 3000
Entry Wire Line
	8275 3000 8375 3100
Wire Wire Line
	9625 3100 8375 3100
Wire Wire Line
	8950 4050 8375 4050
Connection ~ 8950 4050
Entry Wire Line
	8275 3950 8375 4050
Entry Wire Line
	8275 4050 8375 4150
Wire Wire Line
	8850 4150 8375 4150
Connection ~ 8850 4150
Wire Wire Line
	9625 3450 8375 3450
Wire Wire Line
	9625 3550 8375 3550
Wire Wire Line
	9625 3650 8375 3650
Wire Wire Line
	9625 3750 8375 3750
Entry Wire Line
	8275 3350 8375 3450
Entry Wire Line
	8275 3450 8375 3550
Entry Wire Line
	8275 3550 8375 3650
Entry Wire Line
	8275 3650 8375 3750
Text Label 7900 3350 2    50   ~ 0
AUDIO_AMP1
Text Label 7900 3250 2    50   ~ 0
AUDIO_AMP2
Text Label 8650 4050 2    50   ~ 0
SCART8
Text Label 8700 4150 2    50   ~ 0
SCART16
Text Label 7725 3550 2    50   ~ 0
SCART8
Text Label 7775 3850 2    50   ~ 0
SCART16
Text Label 7900 3450 2    50   ~ 0
VIDEO_AMP1
Text Label 7900 3650 2    50   ~ 0
VIDEO_AMP2
Text Label 7900 3750 2    50   ~ 0
VIDEO_AMP3
Text Label 7900 3950 2    50   ~ 0
VIDEO_AMP4
Text Label 4975 2650 0    50   ~ 0
CSYNC1_SW
Text Label 4975 3050 0    50   ~ 0
BLANK1_SW
Text Label 5075 3150 0    50   ~ 0
RED1_SW
Text Label 4975 3550 0    50   ~ 0
GREEN1_SW
Text Label 5025 3850 0    50   ~ 0
FUNC1_SW
Text Label 5025 3950 0    50   ~ 0
BLUE1_SW
Text Label 5125 4050 0    50   ~ 0
AL1_SW
Text Label 5125 4450 0    50   ~ 0
AR1_SW
Wire Wire Line
	6375 5250 6575 5250
$Comp
L Jumper:SolderJumper_3_Bridged12 JP2
U 1 1 5F30197F
P 6225 5250
F 0 "JP2" V 6271 5317 50  0000 L CNN
F 1 "BLANK1" V 6180 5317 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Bridged12_RoundedPad1.0x1.5mm" H 6225 5250 50  0001 C CNN
F 3 "~" H 6225 5250 50  0001 C CNN
	1    6225 5250
	0    -1   1    0   
$EndComp
Wire Wire Line
	6375 4450 6475 4450
Wire Wire Line
	5625 3950 6650 3950
Wire Wire Line
	2450 4450 5425 4450
Wire Wire Line
	2750 4050 5425 4050
Wire Wire Line
	3050 3950 5425 3950
Wire Wire Line
	3350 3850 5425 3850
Wire Wire Line
	3650 3550 5425 3550
Wire Wire Line
	3950 3150 5425 3150
Wire Wire Line
	4250 3050 5425 3050
Wire Wire Line
	4550 2650 5425 2650
$Comp
L Connector_Generic:Conn_02x07_Odd_Even J20
U 1 1 5F852A6E
P 5000 6575
F 0 "J20" H 5050 7000 50  0000 C CNN
F 1 "EXT" H 5050 6150 50  0000 C CNN
F 2 "ossw:TE_MATE-N-LOK_4-794630-4_2x07_P3.0mm_Vertical" H 5000 6575 50  0001 C CNN
F 3 "https://www.te.com/commerce/DocumentDelivery/DDEController?Action=srchrtrv&DocNm=794630&DocType=Customer+Drawing&DocLang=English&PartCntxt=4-794630-4&DocFormat=pdf" H 5000 6575 50  0001 C CNN
F 4 "4-794630-4" H 5000 6575 50  0001 C CNN "P/N"
	1    5000 6575
	1    0    0    -1  
$EndComp
Wire Wire Line
	4675 6275 4675 6200
$Comp
L power:+5V #PWR?
U 1 1 5F860954
P 4675 6200
AR Path="/5E18BCCA/5F860954" Ref="#PWR?"  Part="1" 
AR Path="/5E143861/5F860954" Ref="#PWR0156"  Part="1" 
F 0 "#PWR0156" H 4675 6050 50  0001 C CNN
F 1 "+5V" V 4690 6328 50  0000 L CNN
F 2 "" H 4675 6200 50  0001 C CNN
F 3 "" H 4675 6200 50  0001 C CNN
	1    4675 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 6275 4675 6275
Wire Wire Line
	5300 6275 5400 6275
Wire Wire Line
	5400 6275 5400 7075
$Comp
L power:GND #PWR0157
U 1 1 5F86CECB
P 5400 7075
F 0 "#PWR0157" H 5400 6825 50  0001 C CNN
F 1 "GND" H 5405 6902 50  0000 C CNN
F 2 "" H 5400 7075 50  0001 C CNN
F 3 "" H 5400 7075 50  0001 C CNN
	1    5400 7075
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 6875 6025 6875
Text Label 6025 6875 2    50   ~ 0
SCART1_OUT8
Wire Wire Line
	5300 6775 6025 6775
Wire Wire Line
	5300 6675 6025 6675
Wire Wire Line
	5300 6575 6025 6575
Wire Wire Line
	5300 6475 6025 6475
Wire Wire Line
	5300 6375 6025 6375
Wire Wire Line
	4075 6375 4800 6375
Wire Wire Line
	4075 6475 4800 6475
Wire Wire Line
	4075 6575 4800 6575
Wire Wire Line
	4075 6675 4800 6675
Wire Wire Line
	4075 6775 4800 6775
Wire Wire Line
	4075 6875 4800 6875
Text Label 4075 6875 0    50   ~ 0
SCART1_OUT16
Text Label 6025 6775 2    50   ~ 0
VIDEO_AMP4
Text Label 4075 6775 0    50   ~ 0
VIDEO_AMP3
Text Label 6025 6675 2    50   ~ 0
VIDEO_AMP2
Text Label 4075 6675 0    50   ~ 0
VIDEO_AMP1
Text Label 6025 6575 2    50   ~ 0
AUDIO_AMP1
Text Label 4075 6575 0    50   ~ 0
AUDIO_AMP2
Text Notes 9925 6075 0    50   ~ 0
External Control
Text Label 9625 6150 2    50   ~ 0
EXT_CTRL1
Text Label 9625 6000 2    50   ~ 0
EXT_CTRL2
Text Label 9625 5850 2    50   ~ 0
EXT_CTRL3
Text Label 9625 5700 2    50   ~ 0
EXT_CTRL4
Wire Wire Line
	9225 5700 9625 5700
Wire Wire Line
	9225 5850 9625 5850
Wire Wire Line
	9225 6000 9625 6000
Wire Wire Line
	9225 6150 9625 6150
Text Label 4075 6375 0    50   ~ 0
EXT_CTRL1
Text Label 6025 6375 2    50   ~ 0
EXT_CTRL2
Text Label 4075 6475 0    50   ~ 0
EXT_CTRL3
Text Label 6025 6475 2    50   ~ 0
EXT_CTRL4
Text HLabel 9825 5800 2    50   Input ~ 0
EXT_CTRL[1..4]
Wire Bus Line
	9825 5800 9725 5800
Entry Wire Line
	9625 6150 9725 6250
Entry Wire Line
	9625 5700 9725 5800
Entry Wire Line
	9625 5850 9725 5950
Entry Wire Line
	9625 6000 9725 6100
Wire Bus Line
	9725 3000 9725 3200
Wire Bus Line
	9725 4350 9725 4550
Wire Bus Line
	9725 4050 9725 4250
Wire Bus Line
	9725 5800 9725 6250
Wire Bus Line
	9725 3450 9725 3850
Wire Bus Line
	8275 2900 8275 4050
Wire Bus Line
	5525 2750 5525 4950
$EndSCHEMATC
