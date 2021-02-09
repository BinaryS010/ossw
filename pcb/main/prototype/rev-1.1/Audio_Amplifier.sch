EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 17
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
	4400 3075 4500 3175
Entry Wire Line
	4400 3225 4500 3325
Wire Bus Line
	4400 3000 4250 3000
Text HLabel 4250 3000 0    50   Input ~ 0
AUDIO_AMP[1..2]
Text Notes 4125 3175 0    50   ~ 0
LEFT
Text Notes 4125 3325 0    50   ~ 0
RIGHT
Text Label 4525 3175 0    50   ~ 0
AUDIO_AMP1
Text Label 4525 3325 0    50   ~ 0
AUDIO_AMP2
Entry Wire Line
	6650 3425 6550 3325
Entry Wire Line
	6650 3275 6550 3175
Text Label 6525 3325 2    50   ~ 0
SCART1_OUT1
Text Label 6525 3175 2    50   ~ 0
SCART1_OUT3
Wire Bus Line
	6650 3175 6800 3175
Text HLabel 6800 3175 2    50   Output ~ 0
SCART1_OUT[1..21]
Text Notes 6675 3300 0    50   ~ 0
LEFT
Text Notes 6675 3425 0    50   ~ 0
RIGHT
Entry Wire Line
	6650 3975 6550 3875
Entry Wire Line
	6650 3825 6550 3725
Text Label 6525 3875 2    50   ~ 0
SCART2_OUT1
Text Label 6525 3725 2    50   ~ 0
SCART2_OUT3
Wire Bus Line
	6650 3725 6800 3725
Text HLabel 6800 3725 2    50   Output ~ 0
SCART2_OUT[1..21]
Text Notes 6675 3850 0    50   ~ 0
LEFT
Text Notes 6675 3975 0    50   ~ 0
RIGHT
Entry Wire Line
	6650 4525 6550 4425
Entry Wire Line
	6650 4375 6550 4275
Text Label 6550 4425 2    50   ~ 0
AUDIO_OUT2
Text Label 6525 4275 2    50   ~ 0
AUDIO_OUT1
Wire Bus Line
	6650 4275 6800 4275
Text HLabel 6800 4275 2    50   Output ~ 0
AUDIO_OUT[1..2]
Text Notes 6675 4400 0    50   ~ 0
LEFT
Text Notes 6675 4525 0    50   ~ 0
RIGHT
Wire Wire Line
	5400 3725 5400 3175
Connection ~ 5400 3175
Wire Wire Line
	5200 4275 5200 3175
Connection ~ 5200 3175
Wire Wire Line
	5200 3175 5400 3175
Wire Wire Line
	4500 3325 5100 3325
Wire Wire Line
	5300 3875 5300 3325
Connection ~ 5300 3325
Wire Wire Line
	4500 3175 5200 3175
Wire Wire Line
	5100 4425 5100 3325
Connection ~ 5100 3325
Wire Wire Line
	5100 3325 5300 3325
Wire Wire Line
	5400 3175 6550 3175
Wire Wire Line
	5300 3325 6550 3325
Wire Wire Line
	5400 3725 6550 3725
Wire Wire Line
	5300 3875 6550 3875
Wire Wire Line
	5200 4275 6550 4275
Wire Wire Line
	5100 4425 6550 4425
Wire Bus Line
	4400 3000 4400 3225
Wire Bus Line
	6650 3175 6650 3425
Wire Bus Line
	6650 3725 6650 3975
Wire Bus Line
	6650 4275 6650 4525
$EndSCHEMATC
