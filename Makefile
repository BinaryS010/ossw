# **************************************************************************** #
#                                                                              #
# Copyright (c) 2019-2021 Binary Solo                                          #
#                                                                              #
# This file is part of the Open SCART Switch project (OSSW).                   #
#                                                                              #
# This program is free software: you can redistribute it and/or modify         #
# it under the terms of the GNU General Public License as published by         #
# the Free Software Foundation, either version 3 of the License, or            #
# (at your option) any later version.                                          #
#                                                                              #
# This program is distributed in the hope that it will be useful,              #
# but WITHOUT ANY WARRANTY; without even the implied warranty of               #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                #
# GNU General Public License for more details.                                 #
#                                                                              #
# You should have received a copy of the GNU General Public License            #
# along with this program.  If not, see <https://www.gnu.org/licenses/>        #
#                                                                              #
# **************************************************************************** #
 
# **************************************************************************** #
#                      -= Board/MCU Configuration =-                           #
# **************************************************************************** #

MCUTYPE=__SAMD21J18A__
MCUFREQ=48000000UL

# **************************************************************************** #
#                       -= Project Configuration =-                            #
# **************************************************************************** #

# **************************************************************************** #
# SRC:                                                                         #
#       Source directory.                                                      #
# CFG:                                                                         #
#       Config directory.                                                      #
# PROGRAM_SRCS:                                                                #
#       List of all .c file that need to be compiled.                          #
# **************************************************************************** #
SRC = ./src
CFG = ./cfg

PROGRAM_SRCS += $(SRC)/ossw_main.c \
				$(SRC)/ossw_bus.c \
				$(SRC)/ossw_button.c \
				$(SRC)/ossw_clock.c \
				$(SRC)/ossw_delay.c \
				$(SRC)/ossw_eeprom.c \
				$(SRC)/ossw_i2c.c \
				$(SRC)/ossw_ir.c \
				$(SRC)/ossw_ir_nec.c \
				$(SRC)/ossw_lcd.c \
				$(SRC)/ossw_rgb.c \
				$(SRC)/ossw_sync.c \
				$(SRC)/ossw_systick.c \
				$(SRC)/ossw_settings.c \
				$(SRC)/ossw_timer.c \
				$(SRC)/ossw_ui.c \
				$(SRC)/ossw_version.c

TARGET = ossw

# **************************************************************************** #
#                          -= Tool Configuration =-                            #
# **************************************************************************** #

CROSS_COMPILE = arm-none-eabi-

CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
AR = $(CROSS_COMPILE)ar
AS = $(CROSS_COMPILE)as
OD = $(CROSS_COMPILE)objdump
OC = $(CROSS_COMPILE)objcopy
SZ = $(CROSS_COMPILE)size
ST = $(CROSS_COMPILE)strip

GDB = $(CROSS_COMPILE)gdb
GDB_PORT = 3333
GDB_PARAM = -quiet --eval-command="target extended-remote localhost:$(GDB_PORT)"

OPENOCD = $(shell echo `which openocd`)
OPENOCD_CFG = $(CFG)/openocd.cfg
OPENOCD_PARAM = -f $(OPENOCD_CFG)

ECHO = echo
RM = rm

# **************************************************************************** #
#                       -= Advanced Configuration =-                           #
# **************************************************************************** #

REMOVE_OBJS = Y
VERBOSE = Y
 
# **************************************************************************** #
# OPTFLAGS: Select GCC optimization level.                                     #
# **************************************************************************** #
OPTFLAGS = -O1
DBG_OPTFLAGS = -O0

# **************************************************************************** #
#                          -= Makefile Targets =-                              #
# **************************************************************************** #
#           DON'T CHANGE ANYTHING UNLESS YOU KNOW WHAT YOU'RE DOING            #
# **************************************************************************** #

LDSCRIPT = ext/samd21j18a_flash.ld
STARTUP = ext/startup_samd21.c ext/system_samd21.c

SRCS += $(STARTUP) $(PROGRAM_SRCS)

OBJS = $(addsuffix .o,  $(basename $(SRCS)))
SUS  = $(addsuffix .su, $(basename $(OBJS)))

# common flags
MCU_FLAGS = -mcpu=cortex-m0 -mthumb

AS_DEFS =
C_DEFS += -D$(MCUTYPE) -DF_CPU=$(MCUFREQ) -DFIRMWARE_VERSION=\""$(shell git describe | cut -d- -f1,2,3)"\"
C_DEFS += -DBUILD_YEAR=\""$(shell date +%Y)"\" -DBUILD_DATE=\""$(shell date)"\" 
C_DEFS += -DBUILD_HOST=\""$(shell echo `hostname`)"\"

# tool flags
ASFLAGS += $(MCU_FLAGS) $(AS_DEFS)

CFLAGS += $(MCU_FLAGS)
CFLAGS += -std=c99 -Wall -Wextra -Werror
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -Iext/ -Iext/include -Iext/cmsis -Isrc/ -I.

CPPFLAGS += $(C_DEFS)

LDFLAGS += $(MCU_FLAGS) -T$(LDSCRIPT)
LDFLAGS += -Wl,--gc-sections -Wl,--defsym=end=_end --specs=rdimon.specs

# **************************************************************************** #

ifeq ($(VERBOSE),Y)
SILENCE =
else
SILENCE = @
endif

# **************************************************************************** #

.PHONY: all debug build debug_build strip output info size probe gdb clean_objs clean

all: clean $(SRCS) build strip clean_objs output size

debug: clean $(SRCS) debug_build clean_objs info output size

build: COMFLAGS = $(OPTFLAGS) -g0
build: $(TARGET).elf

debug_build: COMFLAGS = $(DBG_OPTFLAGS) -g -ggdb3
debug_build: CFLAGS += -fstack-usage -D_DEBUG
debug_build: LDFLAGS += -Xlinker -Map=$(TARGET).map
debug_build: $(TARGET).elf

$(TARGET).elf: $(OBJS)
	$(SILENCE)$(CC) $(LDFLAGS) $(COMFLAGS) $(OBJS) -o "$@"

.SECONDARY: $(OBJS)

%.o: %.c
	$(SILENCE)$(CC) $(CPPFLAGS) $(CFLAGS) $(COMFLAGS) -c "$<" -o "$@"

%.o: %.s
	$(SILENCE)$(AS) $(CPPFLAGS) $(ASFLAGS) -o "$@" $<

output: $(TARGET).hex $(TARGET).bin

$(TARGET).hex: $(TARGET).elf
	$(SILENCE)$(OC) -O ihex $< $@

$(TARGET).bin: $(TARGET).elf
	$(SILENCE)$(OC) -O binary $< $@

strip: $(TARGET).elf
	$(ST) -s $(TARGET).elf

info: $(TARGET).elf
	$(SILENCE)$(OD) -x -S $(TARGET).elf > $(TARGET).lst
	$(SILENCE)$(OD) -D $(TARGET).elf > $(TARGET).dis
	$(SILENCE)$(SZ) $(TARGET).elf > $(TARGET).size

size: $(TARGET).elf
	$(SILENCE)$(SZ) $(TARGET).elf

probe:
	$(SILENCE)$(GDB) $(GDB_PARAM) \
		--eval-command "set confirm off" \
		--eval-command "monitor flash list" \
		--eval-command "monitor flash probe 0" \
		--eval-command "monitor flash info 0" \
		--eval-command "quit"

gdb: $(TARGET).elf
	$(SILENCE)$(ECHO) "Run \"load\" to start debugging."
	$(SILENCE)$(GDB) $(GDB_PARAM) $(TARGET).elf

openocd:
	$(SILENCE)$(ECHO) "Running OpenOCD."
	$(SILENCE)$(OPENOCD) $(OPENOCD_PARAM)

clean_objs:
ifeq ($(REMOVE_OBJS),Y)
	$(SILENCE)$(RM) -f $(OBJS)
endif

clean:
	$(SILENCE)$(RM) -f $(TARGET).elf
	$(SILENCE)$(RM) -f $(TARGET).bin
	$(SILENCE)$(RM) -f $(TARGET).hex
	$(SILENCE)$(RM) -f $(TARGET).size
	$(SILENCE)$(RM) -f $(TARGET).lst
	$(SILENCE)$(RM) -f $(TARGET).dis
	$(SILENCE)$(RM) -f $(TARGET).map
	$(SILENCE)$(RM) -f $(OBJS)
	$(SILENCE)$(RM) -f $(SUS)
