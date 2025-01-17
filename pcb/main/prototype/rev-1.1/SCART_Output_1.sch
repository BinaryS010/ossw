EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 17
Title "OSSW - Open Scart SWitch - Main PCB"
Date "2021-02-05"
Rev "1.1 [ALPHA]"
Comp "Binary Solo"
Comment1 "www.binarysolo.co.uk"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x21 J5
U 1 1 5E1CC2D1
P 7625 3250
F 0 "J5" H 7575 4375 50  0000 L CNN
F 1 "OUT 1" H 7525 2125 50  0000 L CNN
F 2 "ossw:SCART_Female" H 7625 3250 50  0001 C CNN
F 3 "~" H 7625 3250 50  0001 C CNN
	1    7625 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7425 4250 7125 4250
Wire Wire Line
	7425 2550 7125 2550
Wire Wire Line
	7125 2550 7125 2650
Connection ~ 7125 4250
Wire Wire Line
	7425 2650 7125 2650
Connection ~ 7125 2650
Wire Wire Line
	7125 2650 7125 3050
Wire Wire Line
	7425 3050 7125 3050
Connection ~ 7125 3050
Wire Wire Line
	7125 3050 7125 3450
Wire Wire Line
	7425 3450 7125 3450
Connection ~ 7125 3450
Wire Wire Line
	7125 3450 7125 3850
Wire Wire Line
	7425 3850 7125 3850
Connection ~ 7125 3850
Wire Wire Line
	7125 3850 7125 3950
Wire Wire Line
	7425 3950 7125 3950
Connection ~ 7125 3950
Wire Wire Line
	7125 3950 7125 4250
NoConn ~ 7425 2350
NoConn ~ 7425 2750
NoConn ~ 7425 3150
NoConn ~ 7425 3350
NoConn ~ 7425 3550
NoConn ~ 7425 4150
Text HLabel 3625 2100 0    50   Input ~ 0
SCART1_OUT[1..21]
Wire Bus Line
	3750 2100 3625 2100
Text Label 3900 2250 0    50   ~ 0
SCART1_OUT1
Text Label 3900 2850 0    50   ~ 0
SCART1_OUT7
Text Label 3900 2950 0    50   ~ 0
SCART1_OUT8
Text Label 3900 3250 0    50   ~ 0
SCART1_OUT11
Text Label 3900 3650 0    50   ~ 0
SCART1_OUT15
Text Label 3900 3750 0    50   ~ 0
SCART1_OUT16
Text Label 3900 4050 0    50   ~ 0
SCART1_OUT19
Text Notes 7750 2475 0    50   ~ 0
AUDIO LEFT
Text Notes 7750 2275 0    50   ~ 0
AUDIO RIGHT
Text Notes 7750 2875 0    50   ~ 0
VIDEO BLUE
Text Notes 7750 2975 0    50   ~ 0
FUNCTION SWITCHING
Text Notes 7750 3275 0    50   ~ 0
VIDEO GREEN
Text Notes 7750 3675 0    50   ~ 0
VIDEO RED
Text Notes 7750 3775 0    50   ~ 0
BLANKING
Text Notes 7750 4075 0    50   ~ 0
VIDEO CSYNC
Text Label 3900 2450 0    50   ~ 0
SCART1_OUT3
Entry Wire Line
	3750 2150 3850 2250
Entry Wire Line
	3750 2350 3850 2450
Entry Wire Line
	3750 2750 3850 2850
Entry Wire Line
	3750 2850 3850 2950
Entry Wire Line
	3750 3150 3850 3250
Entry Wire Line
	3750 3550 3850 3650
Entry Wire Line
	3750 3650 3850 3750
Entry Wire Line
	3750 3950 3850 4050
$Comp
L power:GND #PWR?
U 1 1 5F464AE5
P 5700 5175
AR Path="/5E143861/5F464AE5" Ref="#PWR?"  Part="1" 
AR Path="/5E1438D9/5F464AE5" Ref="#PWR?"  Part="1" 
AR Path="/5E183EA3/5F464AE5" Ref="#PWR09"  Part="1" 
F 0 "#PWR09" H 5700 4925 50  0001 C CNN
F 1 "GND" H 5705 5002 50  0000 C CNN
F 2 "" H 5700 5175 50  0001 C CNN
F 3 "" H 5700 5175 50  0001 C CNN
	1    5700 5175
	1    0    0    -1  
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464AEC
P 5850 4550
AR Path="/5E143861/5F464AEC" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464AEC" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464AEC" Ref="D30"  Part="1" 
F 0 "D30" V 5700 4400 50  0000 L CNN
F 1 "D_TVS" V 5895 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 5850 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 5850 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 5850 4550 50  0001 C CNN "P/N"
	1    5850 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464AF3
P 6150 4550
AR Path="/5E143861/5F464AF3" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464AF3" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464AF3" Ref="D31"  Part="1" 
F 0 "D31" V 6000 4400 50  0000 L CNN
F 1 "D_TVS" V 6195 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 6150 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 6150 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 6150 4550 50  0001 C CNN "P/N"
	1    6150 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464AFA
P 6450 4550
AR Path="/5E143861/5F464AFA" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464AFA" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464AFA" Ref="D32"  Part="1" 
F 0 "D32" V 6300 4400 50  0000 L CNN
F 1 "D_TVS" V 6495 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 6450 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 6450 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 6450 4550 50  0001 C CNN "P/N"
	1    6450 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464B01
P 6750 4550
AR Path="/5E143861/5F464B01" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464B01" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464B01" Ref="D33"  Part="1" 
F 0 "D33" V 6600 4400 50  0000 L CNN
F 1 "D_TVS" V 6795 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 6750 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 6750 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 6750 4550 50  0001 C CNN "P/N"
	1    6750 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464B08
P 4650 4550
AR Path="/5E143861/5F464B08" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464B08" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464B08" Ref="D26"  Part="1" 
F 0 "D26" V 4500 4400 50  0000 L CNN
F 1 "D_TVS" V 4695 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 4650 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 4650 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 4650 4550 50  0001 C CNN "P/N"
	1    4650 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464B0F
P 4950 4550
AR Path="/5E143861/5F464B0F" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464B0F" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464B0F" Ref="D27"  Part="1" 
F 0 "D27" V 4800 4400 50  0000 L CNN
F 1 "D_TVS" V 4995 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 4950 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 4950 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 4950 4550 50  0001 C CNN "P/N"
	1    4950 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464B16
P 5250 4550
AR Path="/5E143861/5F464B16" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464B16" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464B16" Ref="D28"  Part="1" 
F 0 "D28" V 5100 4400 50  0000 L CNN
F 1 "D_TVS" V 5295 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 5250 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 5250 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 5250 4550 50  0001 C CNN "P/N"
	1    5250 4550
	0    1    1    0   
$EndComp
$Comp
L Device:D_TVS D?
U 1 1 5F464B1D
P 5550 4550
AR Path="/5E143861/5F464B1D" Ref="D?"  Part="1" 
AR Path="/5E1438D9/5F464B1D" Ref="D?"  Part="1" 
AR Path="/5E183EA3/5F464B1D" Ref="D29"  Part="1" 
F 0 "D29" V 5400 4400 50  0000 L CNN
F 1 "D_TVS" V 5595 4629 50  0001 L CNN
F 2 "Diode_SMD:D_0402_1005Metric" H 5550 4550 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/40/AVX-GiGuard-1101674.pdf" H 5550 4550 50  0001 C CNN
F 4 "GG040205170N2P" V 5550 4550 50  0001 C CNN "P/N"
	1    5550 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	4650 4700 4650 4900
Wire Wire Line
	4650 4900 4950 4900
Wire Wire Line
	6750 4900 6750 4700
Wire Wire Line
	4950 4700 4950 4900
Connection ~ 4950 4900
Wire Wire Line
	4950 4900 5250 4900
Wire Wire Line
	5250 4700 5250 4900
Connection ~ 5250 4900
Wire Wire Line
	5250 4900 5550 4900
Wire Wire Line
	5550 4700 5550 4900
Connection ~ 5550 4900
Wire Wire Line
	5550 4900 5700 4900
Wire Wire Line
	5850 4700 5850 4900
Connection ~ 5850 4900
Wire Wire Line
	5850 4900 6150 4900
Wire Wire Line
	6150 4700 6150 4900
Connection ~ 6150 4900
Wire Wire Line
	6150 4900 6450 4900
Wire Wire Line
	6450 4700 6450 4900
Connection ~ 6450 4900
Wire Wire Line
	6450 4900 6750 4900
Connection ~ 5700 4900
Wire Wire Line
	5700 4900 5850 4900
Wire Wire Line
	5700 4900 5700 5175
Wire Wire Line
	6750 4900 7125 4900
Wire Wire Line
	7125 4250 7125 4900
Connection ~ 6750 4900
Wire Wire Line
	3850 3650 5250 3650
Wire Wire Line
	3850 3250 5550 3250
Wire Wire Line
	3850 2850 6150 2850
Wire Wire Line
	3850 4050 4650 4050
Wire Wire Line
	4650 4400 4650 4050
Connection ~ 4650 4050
Wire Wire Line
	4650 4050 7425 4050
Wire Wire Line
	4950 4400 4950 3750
Wire Wire Line
	4950 3750 7425 3750
Wire Wire Line
	5250 4400 5250 3650
Connection ~ 5250 3650
Wire Wire Line
	5250 3650 7425 3650
Wire Wire Line
	5550 4400 5550 3250
Connection ~ 5550 3250
Wire Wire Line
	5550 3250 7425 3250
Wire Wire Line
	5850 4400 5850 2950
Wire Wire Line
	5850 2950 7425 2950
Wire Wire Line
	6150 4400 6150 2850
Connection ~ 6150 2850
Wire Wire Line
	6150 2850 7425 2850
Wire Wire Line
	6450 4400 6450 2450
Wire Wire Line
	6450 2450 7425 2450
Wire Wire Line
	6750 4400 6750 2250
Wire Wire Line
	6750 2250 7425 2250
Connection ~ 6750 2250
Connection ~ 6450 2450
Connection ~ 5850 2950
Connection ~ 4950 3750
Wire Wire Line
	3850 2250 6750 2250
Wire Wire Line
	3850 2450 6450 2450
Wire Wire Line
	3850 2950 5850 2950
Wire Wire Line
	3850 3750 4950 3750
Wire Bus Line
	3750 2100 3750 3950
$EndSCHEMATC
