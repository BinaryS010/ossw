# Hardware

This document is the main reference for the hardware components of the **OSSW** project intended to enable DIY build and assembly of the device.

The hardware is currently considered to be in an **ALPHA** release state. It may not be entirely safe for use across all setups and is subject to change. 

Certain elements of the hardware are sub-optimal, so please respect the fact that this is still considered a prototype design.

## Overview

The OSSW hardware forms the basis of an **8 input** and **2 output** RGB SCART switch with the following main components:

 * Dual PCB design consisting of:
    * Main board, 4 layers (~400mm x 130mm).
    * LCD display carrier board, 2 layers (~75mm x 28mm).
 * Laser cut acrylic case (3mm thickness). 

## Main components

The following components implement the major functionality of the OSSW:

 * Atmel/Microchip **ATSAMD21J18A** TQFP-64, microcontroller providing input/output and user interface control.
 * Information output via Midas **MCCOG22005A6W** 20x2 I2C LCD character display.
 * Bus switching via **SN74CBT3244** Octal FET bus switch ICs.
 * Video amplification via **THS7374** 4-channel SD video amplifier IC, including user selectable LPF filter.
 * Selectable video sync-stripping via **LM1881** sync separator IC.
 * Storage facilitated by **24LC64** 64Kb I2C EEPROM IC.
 * Infrared remote control via **TSOP 38238** 38kHz IR receiver/decoder module.
 * Manual control using 5 tactile buttons with hardware debouncing via **SN74HC14** Hex schmitt-trigger IC.
 * Serial wire debug support via 10 pin (2x5), 1.27mm pitch header.
 * SD-Card connector for future feature support and end-user firmware upgrade.
 * Bus status LED indicators (Green).

### Power supply

 * Power is delivered using a **7.5V DC (centre positive)** supply, with a current rating of **1A**.
 * The main power connector is a **FC681465P** 2.5mm barrel jack.
 * Power is regulated as follows:
    * 5V: **NCP1117ST503G**, 5V/1A LDO, powering bus switches and video amplifier.
    * 3V: **NCP1117ST333G**, 5V/1A LDO, powering ATSAMD MCU and additional low-voltage components.
 * Power status LED indicators (Red). 

## ATSAMD pinout

The following table describe the assigned pin functions of the OSSW's ATSAMD21J18A microcontroller.

|Port|Pin|Usage|Description|
|:---|---|:---|:---|
|PA00|1|XIN32|32.768kHz crystal|
|PA01|2|XOUT32|32.768kHz crystal|
|PA02|3|EXT_CTRL1|EXT control interface 1|
|PA03|4|EXT_CTRL2|EXT control interface 2|
|PA04|13|BUS_EN5|Bus Switch 5 enable|
|PA05|14|BUS_EN6|Bus Switch 6 enable|
|PA06|15|BUS_EN7|Bus Switch 7 enable|
|PA07|16|BUS_EN8|Bus Switch 8 enable|
|PA08|17|-|-|
|PA09|18|-|-|
|PA10|19|-|-|
|PA11|20|-|-|
|PA12|29|-|-|
|PA13|30|-|-|
|PA14|31|BYPASS|THS7374 LPF bypass enable/disable|
|PA15|32|SYNC_SPLIT|LM1881 Sync-stripper enable/disable|
|PA16|35|SERCOM1 PAD0|I2C SDA|
|PA17|36|SERCOM1 PAD1|I2C SCL|
|PA18|37|BTN_DOWN|Button Down|
|PA19|38|BTN_UP|Button Up|
|PA20|41|BTN_ACTION|Button Action|
|PA21|42|BTN_LEFT|Button Left|
|PA22|43|BTN_RIGHT|Button Right|
|PA23|44|-|-|
|PA24|45|-|-|
|PA25|46|-|-|
|PA27|51|IR_RECV|IR Receiver|
|PA28|53|-|-|
|PA30|57|SWCLK|-|
|PA31|58|SWDIO|-|
|PB00|61|SD_CS|SPI/SD-Card Chip Select|
|PB01|62|SD_MISO|SPI/SD-Card Master-In, Slave-Out|
|PB02|63|-|-|
|PB03|64|-|-|
|PB04|5|EXT_CTRL3|EXT control interface 3|
|PB05|6|EXT_CTRL4|EXT control interface 4|
|PB06|9|BUS_EN1|Bus Switch 1 enable|
|PB07|10|BUS_EN2|Bus Switch 2 enable|
|PB08|11|BUS_EN3|Bus Switch 3 enable|
|PB09|12|BUS_EN4|Bus Switch 4 enable|
|PB10|23|-|-|
|PB11|24|-|-|
|PB12|25|-|-|
|PB13|26|-|-|
|PB14|27|-|-|
|PB15|28|-|-|
|PB16|39|-|-|
|PB17|40|-|-|
|PB22|49|-|-|
|PB23|50|LCD_BL|LCD LED Backlight enable/disable|
|PB30|59|SD_MOSI|SPI/SD-Card Master-Out, Slave-In|
|PB31|60|SD_SCK|SPI/SD-Card Clock|
|RESET|52|RESET|Button Reset|

## Manufacture

Building the OSSW device from scratch is a relatively difficult task due to the high part count and the size of some of the components used. 

However, it should be achievable by most experienced electronics hobbyists comfortable with soldering at least **0402/0603 SMD** components and **0.5mm pin pitch** surface mount IC packages. 

Hot air rework stations and/or reflow ovens will certainly help although are not strictly required. The prototype unit was built using a **temperature controlled** KSGER T12 soldering iron and a variety of tips suitable for general purpose and SMD work.

### PCBs

The PCBs for DIY OSSW builds can be ordered from any low cost PCB house and have few special requirements. Prototype units were manufactured by JLCPCB and are of acceptable quality.

Due to the size of the main board and the 4 layer design, manufacture and shipping costs are slightly higher. For reference, 5 copies of both boards for the prototype cost around **£80** total (including import taxes and shipping).

GERBER files for the two PCBs can be found in the *GERBER/* folder for the relevant board and version under the *pcb/* folder in the root of the repository.


#### Design files

The OSSW PCB hardware was designed using the **KiCAD** EDA Suite, version **5.1.6-c6e7f7d~87~ubuntu18.04.1, release build** at the time of writing. Full design files are available in the *pcb/* folder within the source repository.

There is currently no intention to port the design to other EDA suites.

#### Ordering

 * Main OSSW board:
    * Thickness: **2.0mm** (1.6mm is really too thin for a board of this size).
    * Surface finish: No special requirement, HASL is fine.
    * Solder mask: Your choice, **Black** looks good but is **HARDER** to work and clean after soldering.

 * LCD carrier board:
    * Thickness: **1.6mm.**
    * Surface finish and solder mask: No special requirements.

#### Bill of Materials

The BOMs for each OSSW PCB can be found in the *BOM/* folder under the relevant board revision within the *pcb/* folder in the root of the source repository. 

As the BOM will likely change across board revisions it is best to place it alongside the relevant design files.

Generally, all schematic elements within the design contain the manufacturer part number and relevant datasheet links. 

Large online electronics distributors (Mouser/Digikey/Farnell etc) carry most of the BOM items. The exception here is the SCART connectors which are either salvaged or available from online auction sites such as Ebay.

The BOM for the two PCBs is generated by the **InteractiveHtmlBom** plugin for KiCAD.

### Assembly

Component placement should be self-explanatory from the included design files for each board and revision. Use of the **InteractiveHtmlBOM** plugin for KiCAD can be useful during soldering.

Based on hand assembly of the prototype unit, the following tips and warnings may prove useful.

#### LCD carrier board

When assembling the LCD daughter board for use with the OSSW, please ensure you **omit** the parts labelled **R1** and **R2.** These footprints are used as pull-up resistors for the **I2C** bus. Since the main OSSW PCB contains these parts they are **not** required on the LCD display carrier board.

**Note:** Failure to adhere to this warning will cause communication errors on the I2C bus and the OSSW is unlikely to boot correctly.

#### Tips

 * Flux, preferably the liquid no-clean variety, is required to ensure surface mount components are soldered easily and correctly.
 * Residual flux from soldering should be cleaned using >90% Isopropyl Alcohol (IPA) and a soft anti-static brush.
 * It is advised to start by soldering the ATSAMD microcontroller and verifying there are no shorted pins before soldering the rest of the components.
 * For the remainder of the components, start with the lowest profile components and continue in that fashion for the rest of the build.
 * Solder all connectors and buttons last. It is advisable to test the unit before soldering ALL the SCART connectors onto the board.
 * Once the unit is verified to be working, the LCD daughter board can be permanently fixed in place using the solder pads on both sides of the main board.
 * Use a **multimeter** to verify connectivty, particularly with the power circuitry, **BEFORE** powering on a newly assembled unit.

#### Warnings

 * **DO NOT** use hot air to solder, or nearby to, **ANY** plastic containing components on the board. Doing so will likely melt the plastic and damage/destroy the component. Kapton tape can be used to carefully isolate already soldered plastic components if rework is required. 
 * Ensure **all** safety precautions are taken when soldering components. Solder fumes and flux are generally considered to be **toxic** substances. 
 * If using leaded solder, this device will not be RoHS compliant. Prototype units were assembled using leaded solder.

### Case

A **preliminary** design for a two part case, consisting of a top and bottom plate, is included within this repository. **As I have not made one yet, I cannot guarantee it is correct.**

It is expected that the case can be laser cut or machined from 3mm acrylic using a variety of online merchants, or at home if you have the equipment.

It may be possible to 3D print the case design, subject to access to a printer with a build volume of ~400mm x 150mm. This is likely to be of a lower quality than the acrylic option.

### Design files

The OSSW case was designed using **Inkscape**, version **0.92.3 (2405546, 2018-03-11)** at the time of writing. Files are available in the *case/* folder within the source repository for the relevant main board revision.

### Additional components

As well as the electronic components, you will also need the following components to completely assemble the OSSW:

 * Brass/Steel PCB standoffs, 12mm (**6** x Male/Female, **26** x Female/Female).
 * M3 x 6mm screws (**26**).

### Future Work

There are plenty of features that *could* be implemented into the hardware, subject to demand. These features are already outlined in the main [README](./README.md) file for this project.

I am aware that the current BOM is rather costly and could do with some consolidation.