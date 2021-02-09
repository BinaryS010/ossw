/* ********************************************************************** */
/*                                                                        */
/* Copyright (c) 2019-2021 Binary Solo                                    */
/*                                                                        */
/* This file is part of the Open SCART Switch project (OSSW).             */
/*                                                                        */
/* This program is free software: you can redistribute it and/or modify   */
/* it under the terms of the GNU General Public License as published by   */
/* the Free Software Foundation, either version 3 of the License, or      */
/* (at your option) any later version.                                    */
/*                                                                        */
/* This program is distributed in the hope that it will be useful,        */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          */
/* GNU General Public License for more details.                           */
/*                                                                        */
/* You should have received a copy of the GNU General Public License      */
/* along with this program.  If not, see <https://www.gnu.org/licenses/>  */
/*                                                                        */
/* ********************************************************************** */

/*
 * includes
 *
 */

#include <stdio.h>
#include <string.h>

#include <ossw_eeprom.h>

/* implements */
#include <ossw_settings.h>

/*
 * defines
 *
 */

static const uint16_t SETTINGS_EEPROM_ADDR = 0x0; 

/*
 * globals
 *
 */

struct ossw_settings g_ossw_default_settings = {

    .default_bus        = 0,
    .lpf_enabled        = 0,
    .sync_strip_enabled = 0,
    .lcd_contrast       = 8,
    .lcd_backlight      = 0,
    .menu_timeout       = 5,
    .bus_names          = {
        "Input 1",
        "Input 2",
        "Input 3",
        "Input 4",
        "Input 5",
        "Input 6",
        "Input 7",
        "Input 8"
    }
};

struct ossw_settings g_ossw_settings = { 0 };

/* 
 * exported functions
 *
 */

void
ossw_settings_init(void)
{
    (void)memcpy(
            &g_ossw_settings, 
            &g_ossw_default_settings, 
            sizeof(g_ossw_default_settings));
}

int 
ossw_settings_load(void)
{
    int res = -1;

    struct ossw_settings set = { 0 };
    
    if((res = ossw_eeprom_read(
                    (uint16_t) SETTINGS_EEPROM_ADDR, 
                    (uint8_t*) &set, 
                    sizeof(set))) == 0) {

        (void) memcpy(&g_ossw_settings, &set, sizeof(set));
    }

    return res;
}

int
ossw_settings_save(void)
{
    return ossw_eeprom_write(
            (uint16_t) SETTINGS_EEPROM_ADDR, 
            (uint8_t*) &g_ossw_settings, 
            sizeof(g_ossw_settings));
}

int
ossw_settings_default(void)
{
    ossw_settings_init();
    return ossw_settings_save();
}

void
ossw_settings_set_default_bus(uint8_t bus)
{
    g_ossw_settings.default_bus = bus;
}

uint8_t
ossw_settings_get_default_bus(void)
{
    return g_ossw_settings.default_bus;
}

void
ossw_settings_set_lpf_enable(uint8_t enable)
{
    g_ossw_settings.lpf_enabled = enable;
}

uint8_t
ossw_settings_get_lpf_enable(void)
{
    return g_ossw_settings.lpf_enabled;
}

void
ossw_settings_set_sync_strip_enable(uint8_t enable)
{
    g_ossw_settings.sync_strip_enabled = enable;
}

uint8_t
ossw_settings_get_sync_strip_enable(void)
{
    return g_ossw_settings.sync_strip_enabled;
}

void
ossw_settings_set_lcd_contrast(uint8_t contrast)
{
    g_ossw_settings.lcd_contrast = contrast;
}

uint8_t
ossw_settings_get_lcd_contrast(void)
{
    return g_ossw_settings.lcd_contrast;
}

void
ossw_settings_set_lcd_backlight(uint8_t backlight)
{
    g_ossw_settings.lcd_backlight = backlight;
}

uint8_t
ossw_settings_get_lcd_backlight(void)
{
    return g_ossw_settings.lcd_backlight;
}

void
ossw_settings_set_menu_timeout(uint8_t timeout)
{
    g_ossw_settings.menu_timeout = timeout;
}

uint8_t
ossw_settings_get_menu_timeout(void)
{
    return g_ossw_settings.menu_timeout;
}

void
ossw_settings_set_bus_name(unsigned int bus, const char* name)
{
    char def_name[BUS_NAME_MAX_LEN + 1] = { 0 };

    memset(g_ossw_settings.bus_names[bus], 0, BUS_NAME_MAX_LEN + 1);

    if(NULL != name) {
        strncpy(g_ossw_settings.bus_names[bus], name, BUS_NAME_MAX_LEN);
    } else {
        snprintf(def_name, BUS_NAME_MAX_LEN, "Input %u", (bus + 1));
        strncpy(g_ossw_settings.bus_names[bus], def_name, BUS_NAME_MAX_LEN);
    }
}

char*
ossw_settings_get_bus_name(unsigned int bus) 
{
    return g_ossw_settings.bus_names[bus];
}
