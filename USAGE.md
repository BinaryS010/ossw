# USAGE

This document provides operating instructions for the **OSSW** device.

## RGB SCART Cables

The OSSW can only tolerate a maximum of **5V** on any of it's SCART input and output ports. As such it is **highly** recommended to use only good quality, dedicated RGB SCART cables, made specifically for retro gaming consoles.

The OSSW is known to work well with cables wired for **Composite Sync (CSYNC), Sync-over-composite** and **Sync-on-Luma** on **SCART Pin 20.** 

Care should be taken to ensure that voltage on **ANY** SCART pin, particularly the **AV switching pin 8,** does not exceed **5V.**

The following cables have been tested for use with the OSSW connected onwards to an **Open Source Scan Converter** and appear to work well:

 * **Sega Master System 1:** 
    * Sega Master System 1 / Mega Drive 1 RGB SCART PACKAPUNCH PRO CABLE - CSYNC - [UK seller](https://www.retrogamingcables.co.uk/sega/master-system-model-1/SEGA-MASTER-SYSTEM-1-RGB-SCART-CABLE-PACKAPUNCH-PRO)
 * **Sega Megadrive 2:** 
    * Sega Mega Drive 2 / Genesis 2 RGB SCART PACKAPUNCH PRO CABLE - CSYNC - [UK seller](https://www.retrogamingcables.co.uk/sega/mega-drive-2/sega-mega-drive-2-sega-genesis-2-rgb-av-scart-cable-tv-lead)
 * **Sega Saturn:** 
    * Sega Saturn RGB SCART PACKAPUNCH PRO CABLE - SYNC ON LUMA - [UK seller](https://www.retrogamingcables.co.uk/sega/saturn/SEGA-SATURN-RGB-SCART-PACKAPUNCH-PRO-CABLE)
 * **Nintendo SNES:** 
    * Super Nintendo PAL SNES RGB SCART PACKAPUNCH PRO CABLE - CSYNC w/STRIPPER - [UK seller](https://www.retrogamingcables.co.uk/SUPER-NINTENDO-SUPER-FAMICOM-GAMECUBE-WII-N64-SNES-NES-RGB-SCART-CSYNC-COMPONENT-YPBPR-HDTV-HDMI-VIDEO-CABLES-CORDS-RAD2X/SUPER-NINTENDO-SUPER-FAMICOM-SNES-NES-RGB-SCART-CSYNC-COMPONENT-YPBPR-HDTV-HDMI-VIDEO-CABLES-CORDS-RAD2X/packapunch-pro-super-nintendo-entertainment-system-snes-rgb-av-scart-cable-pal)
 * **Nintendo Gamecube:**
    * Nintendo GameCube GC RGB SCART cable (PAL) PACKAPUNCH PRO - CSYNC w/STRIPPER - [UK seller](https://www.retrogamingcables.co.uk/SUPER-NINTENDO-SUPER-FAMICOM-GAMECUBE-WII-N64-SNES-NES-RGB-SCART-CSYNC-COMPONENT-YPBPR-HDTV-HDMI-VIDEO-CABLES-CORDS-RAD2X/PAL-GAMECUBE-RGB-SCART-CSYNC-COMPONENT-YPBPR-HDTV-HDMI-VIDEO-CABLES-CORDS-RAD2X/PAL-GAMECUBE-PACKAPUNCH-PRO-RGB-SCART-CABLE)

## Powering the OSSW

Please follow the instructions laid out here in order to correctly power up the OSSW SCART switch.

### Power supply

 * The OSSW is powered by a **7.5V DC, 1 Amp, centre-positive** supply. A good quality variable voltage AC to DC power supply is ideal for powering the device.
 * The power supply tip should be compatible with the **2.5mm** DC barrel jack present at the rear of the main board. It should not be loose in the power receptacle.
 * Although there is **polarity protection** built into the OSSW, care should still be taken to correctly connect the power supply.

### Connecting the device

 * Ensure the AC outlet is switched **OFF** at the wall.
 * Ensure the power switch on the OSSW is in the **OFF** position (angled towards the **FRONT** of the board).
 * Connect the adapter to the AC outlet and the tip of the DC supply to the barrel jack on the rear of the OSSW.
 * Connect SCART cables to consoles and upstream devices (TVs, scalers etc). **It is important to do this with the power OFF!**
 * Switch the AC outlet **ON** at the wall.
 * Turn on any other AV equipment in your setup.
 * Finally, turn **ON** the OSSW by pushing the toggle switch towards the **REAR** of the device.

The OSSW should now power up, briefly displaying a splash screen. After approximately 5 seconds the main interface will be displayed and the OSSW is ready for use.

## Operating the OSSW

The following section outlines the options for controlling the OSSW, using either the button interface present on the device or infrared remote control. 

It also provides details on the information presented on the LCD display and how to navigate the menu system.

### Controls

#### Button controls

The following tactile button control interfaces can be used with the OSSW:

##### Navigation buttons

The OSSW main board contains 5 tactile push buttons arranged in a directional pad style, '+' configuration. The buttons function as follows:

|Button position|Label|Usage - **Information view** | Usage - **Menu view**|
|:---:|:---:|:---:|:---:|
|Top|UP|-|Move cursor up|
|Centre|ACTION|Enter menu|Select current menu item|
|Bottom|DOWN|-|Move cursor down|
|Left|LEFT|Select **previous** SCART input|Decrease value OR Toggle item On/Off|
|Right|RIGHT|Select **next** SCART input|Increase value OR Toggle item On/Off|

##### Reset button

The **RESET** button, located to the left of the LCD display panel at the front of the unit, resets the device.

#### Infrared remote control

The OSSW also includes limited support for an Infrared remote control interface. 

As with the tactile button interface, 5 buttons on the remote control are used, and when used in a similar directional layout to the tactile buttons their functions are **identical.**

### Display

The LCD display on the OSSW provides information output to the user and facilitates navigation of the menu system in order to configure the device according to the user's requirements.

The LCD display has three main modes as follows:

#### Startup

The startup screen is shown briefly after the device is powered up. It simply displays the **device name** and current **firmware version.** 

After **5 seconds** the OSSW switches to display the main information screen (see below).

No user control is possible whilst the OSSW is displaying the startup screen.

#### Information screen

The information screen is the primary display mode for the OSSW. It conveys several pieces of information to the user:

 * **First line:** The **label** assigned to the currently selected input.
    * By default these are set to be **Input 1, Input 2** etc.
    * Each input label can be changed within the menu system to one of a predefined set of system names contained within the firmware, i.e. **Sega Megadrive, Sega Saturn** etc.
    * Assigned input labels can be saved to the internal EEPROM of the OSSW and are restored when the system is next powered on.

 * **Second line:** The currently selected **SCART** input number plus sync stripper and low pass filter enabled/disabled indicators.
    * A left arrow icon (**<**) points towards the currently selected SCART input. 
    * To the right of the second line on the display are two indicators. A small '**S**' indicates the enabled/disabled state of the **sync-stripper.** A small '**L**' indicates the enabled/disabled state of the video amplifier's **low pass filter.**
    * Those functions are **enabled** when the indicators have a **dark background.**

In order to select the desired SCART input, simply use the **LEFT** and **RIGHT** buttons. The menu can be acesssed using the **ACTION** button (see menu section below). 

#### Menu

The OSSW includes a menu system for configuring the device settings according to the needs of the user. The menu is organised in a tree structure to group related configuration items together and provide a consistent navigation experience.

This structure is as follows:

||||
|---|---|---|
|General options:      |||
|   |Save settings ||
|   |Load settings ||
|   |Default settings ||
|Input options:    |||
|   |Default input ||
|   |Input labels:||
|   |   |Input 1|
|   |   |  ...  |
|   |   |Input 8|  
|   |Sync strip ||
|Output options:    |||
|   |Low pass filter| |
|Display options:
|   |Menu timeout ||
|   |LCD constrast ||
|   |LCD backlight
|About      |||
|   |   |   |

The menu is controlled as follows:

 * Menu levels and items are selected using the **ACTION** button. 
 * Options that present a value that can be changed are selected using the **LEFT** or **RIGHT** buttons. 
 * Menu screens are scrolled using the **UP** and **DOWN** buttons.

Each menu level includes either a **previous menu** or an **exit menu** option to aid navigation.

The menu includes a timeout, meaning the display will automatically revert to the main information screen if no button is pressed for the configured length of time. By default the menu timeout is **5 seconds** although this can be changed and saved according to the user's preference.

Settings can be saved and loaded by using the **Save settings** and **Load settings** respectively in the *General options* menu. **Settings are NOT automatically saved by the system.**

#### LCD backlight

The OSSW LCD display includes a user configurable LED backlight. 

By default, the backlight is configured to be always **ON.** However, by using the menu system as described above, the backlight can be configured to turn **OFF** after a pre-determined delay between **1** and **60** seconds.

Setting the backlight timeout to **0** in the menu will cause the backlight to remain **ON** whilst the device is powered.

### SD card interface

The OSSW device has a micro SD-card slot at the front of the unit. This is **unused** with the current firmware, but is included to support future features.

### Expansion connector

The OSSW device has a 14-pin expansion connector, labelled **EXT,** on the left side of the unit. This is **unused** with the current firmware, but is included to support future expansion functionality.

## Warnings

 * Using power supplies outside the specifications outlined above may **damage or destroy** the OSSW.
 * Ensure power is **OFF** to all equipment in your setup **BEFORE** connecting or disconnecting SCART/audio or power cables. **Failure to adhere to this rule could damage parts of your setup, including the OSSW.**