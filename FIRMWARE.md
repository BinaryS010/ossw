# Firmware

This document is the main reference for the firmware components of the OSSW project intended to enable development, debugging and programming of the Atmel ATSAMD microcontroller.

The software is currently considered to be in an **ALPHA** release state. Generally, all of the existing features have been tested and appear stable under a reasonable amount of usage to date.

## Development environment

The OSSW firmware has been developed using almost exclusively open source environments and toolchains. The primary development environment is **Ubuntu 18.04.4 LTS x86_64.** 

It should be relatively easy to use other Linux based development environments.

### Prequisite packages

In order to build the firmware and program the OSSW, the development environment must first be configured.

### Build tools

Firstly, install the required build packages using the package manager of your preferred distribution.

```
sudo apt-get install build-essential openocd telnet
```

### ARM GNU toolchain

Developing for the ATSAMD microcontroller requires a cross toolchain for the ARM Cortex M0+ architecture. 

Whilst you are free to build or use one you may already have, I chose to use the **official** GNU ARM Embedded toolchain which can be downloaded from this [link](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

The version used during development of the OSSW was: [Version 7-2017-Q4-major](https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2017q4/gcc-arm-none-eabi-7-2017-q4-major-linux.tar.bz2?revision=375265d4-e9b5-41c8-bf23-56cbe927e156?product=GNU%20Arm%20Embedded%20Toolchain,64-bit,,Linux,7-2017-q4-major).

Later versions have **NOT** been tested, but I expect they'll work just fine.

#### Download and extract toolchain

Download the toolchain and extract it to a location of your choosing. In my case I use `~/toolchains` as follows:

```
mkdir ~/toolchains
cd ~/toolchains

wget "https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2017q4/gcc-arm-none-eabi-7-2017-q4-major-linux.tar.bz2?revision=375265d4-e9b5-41c8-bf23-56cbe927e156?product=GNU%20Arm%20Embedded%20Toolchain,64-bit,,Linux,7-2017-q4-major" -O gcc-arm-none-eabi-7-2017-q4-major.tar.bz2

tar xjvf gcc-arm-none-eabi-7-2017-q4-major.tar.bz2
ln -s gcc-arm-none-eabi-7-2017-q4-major/install-native arm-none-eabi
```

#### Configure PATH environment variable

Once extracted, you now need to add the toolchain to your `PATH` environment variable for the makefile to pick it up and cross compile the firmware. In order to do this, you could add the following lines to your `~/.profile` as follows:

```
PATH="$PATH:$HOME/toolchain/arm-none-eabi/bin/"
export PATH
```

Once this is complete, `source` your profile to pick up the changes and add the toolchain to your path.

```
. ~/.profile
```

Toolchain configuration is now complete.


### Atmel/Microchip ASF

In order to aid development, and possibly portability to alternative ATSAMD devices, the OSSW firmware was developed against the Atmel/Mircochip ASF development kit. 

**Note:** The only portions of the ASF that are really used are the ATSAMD starup code and memory mapped register definitions and helper macros. The OSSW firmware does **NOT** use the full Hardware Abstraction Layer (HAL) library features provided by the ASF so the included code is only very minimal, probably around 1KB.

Follow the steps below to download and configure the ASF:

#### Download ASF

Download the standalone ASF archive from [here](https://www.microchip.com/en-us/development-tools-tools-and-software/libraries-code-examples-and-more/advanced-software-framework-for-sam-devices#Downloads). 

The version used to develop the OSSW firmware was **3.47.0.96** although the current version available for download is **3.49.1.105** at the time of writing. It is a **~0.5Gb** download.

#### Extract ASF

Firstly, extract the ASF to a location **outside** of the OSSW source repository. In this example *~/share* is used.

```
cd ~
mkdir share
cd share
unzip ~/Downloads/asf-standalone-archive-<version>.zip
ln -s xdk-ask-<version> xdk-asf
```

#### Link to ASF

Now that the ASF is installed to a known location, the *Makefile* needs to be able to locate the relevant files needed to build the firmware.

The creation of an additional directory is required in the root of the OSSW source respository to point to the external files. In this example, an *ext/* directory is created.

```
cd <ossw_repository_directory>
mkdir ext
cd ext
```

Now create the following symlinks to the various ASF components required, replacing `username` with your own:

```
ln -s /home/<username>/share/xdk-asf/thirdparty/CMSIS/Include/ cmsis
ln -s /home/<username>/share/xdk-asf/thirdparty/CMSIS/Include/ include
ln -s /home/<username>/share/xdk-asf/sam0/utils/linker_scripts/samd21/gcc/samd21j18a_flash.ld samd21j18a_flash.ld
ln -s /home/<username>/share/xdk-asf/sam0/utils/cmsis/samd21/source/gcc/startup_samd21.c startup_samd21.c
ln -s /home/<username>/share/xdk-asf/sam0/utils/cmsis/samd21/source/system_samd21.c system_samd21.c
ln -s /home/<username>/share/xdk-asf/sam0/utils/cmsis/samd21/source/system_samd21.h system_samd21.h
```

Setup of the development environment is now complete.

#### Additional reference

A good reference for bare-metal ARM programming can be found on the MickMake YouTube channel [here](https://youtu.be/xy62eC6bd44). The instructions in this guide are based on this video.

### Additional tools

#### Programmer (required)

This document assumes you have an Atmel ICE or other suitable programmer available and  connected to the onboard *Serial Wire Debug* port located on the main OSSW board. For now, this is the **ONLY** method available for programming and/or debugging the Atmel ATSAMD microcontroller on the OSSW.

If using an Atmel ICE, the **SAM** debug port should be used as opposed to the **AVR** port on the programmer.

#### Logic Analyser (optional)

A logic analyser is often useful for both debugging and verifying commnication signals during development, particularly the protocols involved in I2C, SPI and Infrared communicatons. 

It is however optional, and not required to build and program an OSSW device.

## Configure programmer

The OSSW repository contains an **openocd** configuration file in the *cfg/* directory in the root of the source repository.

In order to configure your programmer correctly you need update the configuration file with the appropriate USB VID, PID and serial number of your particular programmer.

These values can be obtained by the following commands with the programmer connected and powered on:

```
lsusb -v | less 
```

Search the output for the following lines:

```
idVendor           0x03eb Atmel Corp.
idProduct          0x2141 ICE debugger
bcdDevice            1.01
iManufacturer           1 Atmel Corp.
iProduct                2 Atmel-ICE CMSIS-DAP
iSerial                 3 J47201015054
```

The relevant values from *your* output fields **idVendor** (in this case 0x03eb), **idProduct** (0x2141) and **idSerial** (J47201015054) should be entered into the *cfg/openocd.cfg* file before attempting to program or debug the firmware.


## Debugging the firmware

Being able to debug the Atmel ATSAMD21J18A microcontroller is essential during development and testing. The included *Makefile* has a few targets to enable this. 

Firstly, to ensure relevant debugging information is present within the firmware binary, a **debug** target is also provided within the *Makefile*.

Secondly, the **openocd**  target connects to the ATSAMD and places it under the control of the openocd debugger. An openocd config file suitable for the ATSAMD21J18A target is present within the *cfg/* directory in the root of the source repository.

Finally, the **gdb** target initiates a debug session using GDB to enable the developer to test and debug the firmware.

To initiate a debug session running, follow the steps outlined below. All shell commands should be executed from the *root* of the source repository,  where the *Makefile* resides. 

The following instructions assume you have our Atmel ICE programmer connected to the OSSW using the **SAM** port (not the **AVR** port) on the programmer.

### Build a debug firmware

In one shell:

```
make debug
```

### Connect to the ATSAMD target

In a second shell:

```
make openocd
```

### Initiate a GDB session

In a third shell:

```
make gdb
```

Once the GDB session is established, run the following commands to load the debug firmware:

```
load
break main
monitor reset init
```

The session is now configured for debugging, for example:

`break <breakpoint>` or `c` to resume execution.


## Flashing the firmware

Currently the only method of permanently flashing the firmware of the OSSW is via **openocd** using an Atmel ICE or other suitable programmer capable of interfacing with the **Serial Wire Debug** port present on the main OSSW board. 

As with the debugging steps above, the following instructions assume you have our Atmel ICE programmer connected using the **SAM** port (not the **AVR** port).

The included *Makefile* includes a few targets to make permanently flashing the firmware a little easier.

Firstly, release mode firmware should not include debugging information or symbols to ensure appropriate operation and smaller firmware binaries. The default **make** target will build a release mode firmware image.

Secondly, the **openocd**  target connects to the ATSAMD and places it under the control of the openocd debugger.

To flash the firmware, follow the steps outlined below. All shell commands should be executed from the *root* of the source repository, where the *Makefile* resides. 

### Build release firmware

In one shell:

```
make
```

### Connect to the ATSAMD target

In a second shell:

```
make openocd
```

### Initiate an OpenOCD session

In a third shell:

```
telnet localhost 4444
```

### Flash the firmware

In the OpenOCD session, enter the following commands:

```
reset halt
flash list
flash banks
flash probe 0
flash write_image erase ossw.bin 0x00000000
exit
```

### Enable flash read protection (optional)

This step is not required, as the firmware is open source anyway, but probably a good habit to get into.

TODO

Once this step has been performed, the flash will be protected and cannot be read via an external programmer.

## Remove firmware build artefacts

Artefacts generated by the build process can be removed by running `make clean` in the *root* of the source repository, where the *Makefile* resides.

**Note:** Running the above command will remove all artefacts, including built firmware binaries.

## Infrared remote control support

Currently, the IR support within the firmware is limited to a simple 5 button remote I had lying around from an old LED strip light. The IR codes specific to that remote control are currently hardcoded into the firmware.

In order to use the IR functions of the OSSW, you will need to perform the following steps:

 * Obtain a remote control known to use the NEC Infrared remote control protocol.
 * Obtain a method for recording and displaying the remote control codes emitted by your particular device. An Arduino for instance and the IR protocol library could be used.
 * Modify the global structure `g_nec_keymap` in the source file *src/ossw_ir_nec.c*, changing the values to the ones you have captured.
 * Save the changes, rebuild the firmware, flash the device and test the new codes.

Another option would be to train a universal remote control or mobile phone to send the codes already in the firmware.

Additional protocol support and remote training functionality are on the roadmap for integration into the OSSW firmware at some point in the future.

## Version history

#### Version 1.1 [ALPHA]
Initial prototype. First release.

#### Version 1.0
Internal prototype. Not released.

## License

This firmware is licensed under the GNU General Public License, version 3 (GPLv3).

## Credits

The OSSW project has used concepts and/or code from the projects outlined below. Every attempt has been made to respect the copyright of the originators and preserve the original licensing conditions:

 * **Open Source Scan Converter (OSSC)**: LCD menu code, concepts and supporting macros adapted for use within this project. ([Github](https://github.com/marqs85/ossc))
 * **Arduino-IRremote**: Portions of the IR receive and NEC protocol decoding logic plus supporting macros adapted for use within this project. ([Github](https://github.com/Arduino-IRremote/Arduino-IRremote))

## Copyright

The **Open Scart Switch (OSSW)** project is Copyright(c) 2019-2021 Binary Solo.

The **Advanced Software Framework (ASF)** is Copyright(c) Microchip Corporation.


