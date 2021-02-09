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

#ifndef _OSSW_LCD_H_
#define _OSSW_LCD_H_

/*
 * includes
 *
 */

#include <stdint.h>

/*
 * defines
 *
 */

#define OSSW_LCD_ROW_NUM            2
#define OSSW_LCD_COL_NUM            20

#define OSSW_LCD_CHAR_WIDTH         5
#define OSSW_LCD_CHAR_HEIGHT        8

#define OSSW_LCD_MAX_CHARS          40
#define OSSW_LCD_MAX_CUSTOM_CHARS   8

/* allowable contrast range */
#define OSSW_LCD_CONTRAST_MIN       0x00
#define OSSW_LCD_CONTRAST_MAX       0x0F


/*
 * enums
 *
 */

enum ossw_lcd_justify {

    OSSW_LCD_JUSTIFY_LEFT   = 0,
    OSSW_LCD_JUSTIFY_CENTER = 1,
    OSSW_LCD_JUSTIFY_RIGHT  = 2

};

/*
 * exported functions
 *
 */

void ossw_lcd_init(void);

void ossw_lcd_clear_display(void);

void ossw_lcd_return_home(void);

void ossw_lcd_set_contrast(uint8_t val);

void ossw_lcd_set_cursor(uint8_t row, uint8_t col);

void ossw_lcd_print_char(char c);

void ossw_lcd_print_string(char* s);

void ossw_lcd_display(char* s1, char* s2, uint8_t j1, uint8_t j2);

void ossw_lcd_create_custom_char(uint8_t num, uint8_t* data);

void ossw_lcd_print_custom_char(uint8_t num);

void ossw_lcd_backlight_enable(void);

void ossw_lcd_backlight_disable(void);

#endif /* ! _OSSW_LCD_H_ */
