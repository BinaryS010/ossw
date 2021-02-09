# Open SCART SWitch (OSSW)

## Overview

The **Open SCART Switch** (OSSW) is an RGB video and audio SCART switch designed to connect up to **8** RGB capable video game consoles with compatible display devices or scalers such as the **Open Source Scan Converter (OSSC).**

It was designed for use with properly constructed **RGB SCART** cables which correctly attenuate video and sync signals to levels safe for use with consumer grade televisions and the OSSC.

## Motivation

I designed this device to scratch a few itches, but mostly because there are currently no open source SCART switch designs within the retro gaming community.

It would have been cheaper to buy an existing solution, of which there are several very good ones, but I've learnt a lot throughout this project.

## Features

Currently the OSSW has the following features:

 * **8** SCART **inputs**, with **2** SCART **outputs**. Supports simultaneous output (**untested**).
 * Integrated **video amplifier** and switchable **sync stripper.**
 * Support for **Composite sync (CSYNC)**, **Sync-over-composite** or **Sync-on-Luma** on **SCART pin 20.**
 * Backlit LCD character **display** with menu driven interface.
 * Infrared **remote** and **5 button** control interface support.
 * Line-level **stereo audio** output via RCA jacks.
 * Built in 64Kb **EEPROM** to save and load configuration data.
 * Externally powered by **7.5V DC** supply. **2.5mm** barrel jack, centre positive.
 * Power **input polarity** and **over-voltage protection**, with onboard 1A fuse.
 * **SD Card** interface. (**unused/untested**, see future features).
 * Simple **expansion** interface for future feature support (**untested**).
 * Transient voltage **protection** for SCART Input and Outputs (**untested**).

### Limitations

The following are known limitations with the OSSW:

 * **Euro SCART** only. Currently NO support for **JP-21 SCART** standard.
 * Currently, **manual** switching only (see future features below).
 * No **audio amplification** is performed by the OSSW. Audio is currently split between the two SCART outputs and the RCA stereo jacks. A decrease in audio volume may be noticeable when using multiple outputs simultaneously (see future features below).
 * Input and output SCART ports can tolerate a maximum of **5V.** Use properly constructed RGB SCART cables to ensure no signal line (particularly, **SCART pin 8**) carries no more than **5V**.
 * Fimware only upgradeable using compatible programmer, such as an Atmel ICE (see future features).
 * Infrared remote control decoding is currently limited to **NEC protocol** only. Remote specific codes are hard-coded in the firmware.

### Future Features

The following features are planned for the OSSW:

 * Audio amplification.
 * Sync detection and automatic switching funtionality.
 * SD card based firmware upgrades and custom profile loading and saving.
 * Infrared remote control training and additional protocol decoding support.

### Warnings

Currently the device should only be used with **75 ohm** attenuated sync signals. Using the OSSW with **TTL** level sync signals will likely damage upstream devices such as the OSSC.

## Hardware

OSSW hardware overview and build instructions are located in the [HARDWARE](./HARDWARE.md) readme.

## Firmware

OSSW firmware build, programming and debugging instructions are located in the [FIRMWARE](./FIRMWARE.md) readme.

## Usage

OSSW usage instructions are located in the [USAGE](./USAGE.md) readme.

## Revision history

Please see the [CHANGELOG](./CHANGELOG)

## Disclaimer

This is a **DIY hobby** project currently in an early prototype stage. 

I am **not** a trained electrical engineer and although this device seems to work well with my equipment it may not work so well with other setups.

I **do not** intend to sell kits or completed devices. Design files are released to the community in the hope that the design may be improved upon should people wish to contribute. 

I **may** sell surplus PCBs at around cost price (+shipping) but **ONLY** if I have them available.

I offer **NO WARRANTY** of any kind and assume **NO RESPONSIBILITY** for potential damage or loss caused by this device. **Use the information in the repository at your own risk.**

I also offer **NO GUARANTEE** of support if you attempt to build and operate one of these devices. This is a hobby project and not a business. I'm open to contributions and suggestions on current or future features but it's unlikely I'll have time to answer direct queries.

## Donations

Donations are certainly not expected or required. However, if you would like to contribute a small donation towards future revisions of this project then please use one of the methods below:

 * Paypal: **ossw AT binarysolo.co.uk** (replace AT with @).
 * Bitcoin: **36CN15aT6YL5B6MN5kqg4JD5AhEYchCwxG**

Any and all donations are greatly appreciated.

## License

This project is licensed under the GNU General Public License, version 3 (GPLv3).

## Copyright

The **Open Scart Switch (OSSW)** project is Copyright(c) 2019-2021 Binary Solo.

Elements of the OSSW project that are derived from other works are credited within the relevant source files. Those works are copyright of their respective owners as indicated in the original copyright notice.

## Contact

The OSSW developer can be contacted via email as **ossw AT binarysolo.co.uk** (replace the AT with @).
