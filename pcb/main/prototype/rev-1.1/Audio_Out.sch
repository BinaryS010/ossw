EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 17
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
	5800 3450 5900 3550
Entry Wire Line
	5800 3550 5900 3650
Text Label 5925 3650 0    50   ~ 0
AUDIO_OUT2
Text Label 5925 3550 0    50   ~ 0
AUDIO_OUT1
Wire Bus Line
	5800 3350 5650 3350
Text HLabel 5650 3350 0    50   Input ~ 0
AUDIO_OUT[1..2]
Text Notes 5725 3525 2    50   ~ 0
LEFT
Text Notes 5725 3650 2    50   ~ 0
RIGHT
Wire Wire Line
	5900 3550 6800 3550
Wire Wire Line
	5900 3650 6800 3650
Wire Wire Line
	6800 3750 6625 3750
Wire Wire Line
	6625 3750 6625 3925
$Comp
L power:GND #PWR0162
U 1 1 5F87537B
P 6625 3925
F 0 "#PWR0162" H 6625 3675 50  0001 C CNN
F 1 "GND" H 6630 3752 50  0000 C CNN
F 2 "" H 6625 3925 50  0001 C CNN
F 3 "" H 6625 3925 50  0001 C CNN
	1    6625 3925
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J12
U 1 1 5F2EF5A5
P 7000 3650
F 0 "J12" H 6925 3850 50  0000 L CNN
F 1 "Audio Out" V 7125 3450 50  0000 L CNN
F 2 "ossw:PSG01550" H 7000 3650 50  0001 C CNN
F 3 "~" H 7000 3650 50  0001 C CNN
F 4 "PSG01550" H 7000 3650 50  0001 C CNN "P/N"
	1    7000 3650
	1    0    0    1   
$EndComp
Wire Bus Line
	5800 3350 5800 3550
$EndSCHEMATC
