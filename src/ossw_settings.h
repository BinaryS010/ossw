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

#ifndef _OSSW_SETTINGS_H_
#define _OSSW_SETTINGS_H_

/*
 * includes
 *
 */

#include <stdint.h>

/*
 * defines
 *
 */

#define BUS_NUM             8 
#define BUS_NAME_MAX_LEN    40

/*
 * types
 *
 */

struct ossw_settings {

    uint8_t default_bus;
    uint8_t lpf_enabled;
    uint8_t sync_strip_enabled;
    uint8_t lcd_contrast;
    uint8_t lcd_backlight;
    uint8_t menu_timeout;
    char    bus_names[BUS_NUM][BUS_NAME_MAX_LEN + 1];

} __attribute__ ((__packed__));

/*
 * exported functions
 *
 */

void ossw_settings_init(void);

int ossw_settings_load(void);

int ossw_settings_save(void);

int ossw_settings_default(void);

void ossw_settings_set_default_bus(uint8_t bus);

uint8_t ossw_settings_get_default_bus(void);

void ossw_settings_set_lpf_enable(uint8_t enable);

uint8_t ossw_settings_get_lpf_enable(void);

void ossw_settings_set_sync_strip_enable(uint8_t enable);

uint8_t ossw_settings_get_sync_strip_enable(void);

void ossw_settings_set_lcd_contrast(uint8_t contrast);

uint8_t ossw_settings_get_lcd_contrast(void);

void ossw_settings_set_lcd_backlight(uint8_t backlight);

uint8_t ossw_settings_get_lcd_backlight(void);

void ossw_settings_set_menu_timeout(uint8_t timeout);

uint8_t ossw_settings_get_menu_timeout(void);

void ossw_settings_set_bus_name(unsigned int bus, const char* name);

char* ossw_settings_get_bus_name(unsigned int bus);

#endif /* ! _OSSW_SETTINGS_H_ */
