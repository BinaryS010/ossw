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

#include <samd21.h>
#include <stdint.h>

#include <ossw_i2c.h>
#include <ossw_delay.h>

/* implements */
#include <ossw_lcd.h>

/*
 * defines
 *
 */

static const uint8_t LCD_I2C_ADDR = 0x3c;

#define LCD_CMD_FUNCTION_SET1   (uint8_t) 0x38
#define LCD_CMD_FUNCTION_SET2   (uint8_t) 0x39
#define LCD_CMD_SET_BIAS        (uint8_t) 0x14
#define LCD_CMD_SET_CONTRAST    (uint8_t) 0x78
#define LCD_CMD_POWER_CTRL      (uint8_t) 0x5E
#define LCD_CMD_FOLLOW_CTRL     (uint8_t) 0x6C
#define LCD_CMD_DISPLAY_ON      (uint8_t) 0x0C
#define LCD_CMD_DISPLAY_OFF     (uint8_t) 0x08
#define LCD_CMD_CLEAR_DISPLAY   (uint8_t) 0x01
#define LCD_CMD_RETURN_HOME     (uint8_t) 0x02
#define LCD_CMD_SET_ENTRY_MODE  (uint8_t) 0x06
#define LCD_CMD_SET_DDRAM_ADDR  (uint8_t) 0x80
#define LCD_CMD_SET_CGRAM_ADDR  (uint8_t) 0x40

#define LCD_CTRL_BYTE           (uint8_t) 0x0

#define LCD_CTRL_BYTE_REPEAT    (1 << 7)
#define LCD_CTRL_BYTE_REGSEL    (1 << 6)
#define LCD_CTRL_BYTE_FOLLOW    (1 << 7)

#define LCD_WRITE_FUNCTION_SET1 lcd_write_instruction(LCD_CMD_FUNCTION_SET1)
#define LCD_WRITE_FUNCTION_SET2 lcd_write_instruction(LCD_CMD_FUNCTION_SET2)
#define LCD_WRITE_SET_BIAS      lcd_write_instruction(LCD_CMD_SET_BIAS)
#define LCD_WRITE_SET_CONTRAST  lcd_write_instruction(LCD_CMD_SET_CONTRAST)
#define LCD_WRITE_POWER_CTRL    lcd_write_instruction(LCD_CMD_POWER_CTRL)
#define LCD_WRITE_FOLLOW_CTRL   lcd_write_instruction(LCD_CMD_FOLLOW_CTRL)
#define LCD_WRITE_DISPLAY_ON    lcd_write_instruction(LCD_CMD_DISPLAY_ON)
#define LCD_WRITE_DISPLAY_OFF   lcd_write_instruction(LCD_CMD_DISPLAY_OFF)
#define LCD_WRITE_CLEAR_DISPLAY lcd_write_instruction(LCD_CMD_CLEAR_DISPLAY)
#define LCD_WRITE_ENTRY_MODE    lcd_write_instruction(LCD_CMD_SET_ENTRY_MODE)
#define LCD_WRITE_RETURN_HOME   lcd_write_instruction(LCD_CMD_RETURN_HOME)

#define LCD_CGRAM_ADDR_SHIFT    3

#define LCD_SET_DDRAM_ADDR(a) \
    lcd_write_instruction(LCD_CMD_SET_DDRAM_ADDR | a)

#define LCD_SET_CGRAM_ADDR(num) \
    lcd_write_instruction(LCD_CMD_SET_CGRAM_ADDR | (num << LCD_CGRAM_ADDR_SHIFT))

#define LCD_WRITE_DATA(c)       lcd_write_data(c)

#define LCD_MEM_ROW1_MIN        0x00
#define LCD_MEM_ROW1_MAX        0x27
#define LCD_MEM_ROW2_MIN        0x40
#define LCD_MEM_ROW2_MAX        0x67

#define LCD_SET_CONTRAST(c) \
    lcd_write_instruction(((LCD_CMD_SET_CONTRAST & 0xF0) | (c & 0x0F)))

#define LCD_DELAY               30

#define LCD_I2C_BUFFER_LEN      (size_t) 2

/* LCD backlight */

#define LCD_BL_PORT             0x01        /* Port Group B */

#define PORT_LCD_BL             PORT_PB23
#define PIN_LCD_BL              PIN_PB23

/*
 * globals
 *
 */

/**
 * LCD contrast
 */
static uint8_t g_lcd_contrast = 0;

/*
 * static functions
 *
 */

static void 
lcd_write_instruction(uint8_t cmd)
{
    uint8_t buf[LCD_I2C_BUFFER_LEN] = { 0 };

    buf[0] = LCD_CTRL_BYTE;
    buf[1] = cmd;

    ossw_i2c_write(LCD_I2C_ADDR, buf, LCD_I2C_BUFFER_LEN);
    delay_us(LCD_DELAY);
}

static void
lcd_write_data(uint8_t data)
{
    uint8_t buf[LCD_I2C_BUFFER_LEN] = { 0 };

    buf[0] = LCD_CTRL_BYTE | LCD_CTRL_BYTE_REGSEL;
    buf[1] = data;

    ossw_i2c_write(LCD_I2C_ADDR, buf, LCD_I2C_BUFFER_LEN);
    delay_us(LCD_DELAY);
}

void 
ossw_lcd_init(void)
{
    /* init backlight */
    PORT->Group[LCD_BL_PORT].DIRSET.reg = PORT_LCD_BL;
    ossw_lcd_backlight_enable();

    /* init display */
    delay_ms(500);

    LCD_WRITE_FUNCTION_SET1;

    LCD_WRITE_FUNCTION_SET2;

    LCD_WRITE_SET_BIAS;

    LCD_WRITE_SET_CONTRAST;
    g_lcd_contrast = LCD_CMD_SET_CONTRAST & 0x0F;

    LCD_WRITE_POWER_CTRL;

    LCD_WRITE_FOLLOW_CTRL;

    LCD_WRITE_DISPLAY_ON;

    LCD_WRITE_CLEAR_DISPLAY;
    delay_ms(2);

    LCD_WRITE_ENTRY_MODE;
}

void
ossw_lcd_clear_display(void)
{
    LCD_WRITE_CLEAR_DISPLAY;
    delay_ms(2);
}

void
ossw_lcd_return_home(void)
{
    LCD_WRITE_RETURN_HOME;
    delay_ms(2);
}

void
ossw_lcd_set_contrast(uint8_t val)
{
    if(val > OSSW_LCD_CONTRAST_MAX) {
        return;
    }

    /* 
     * contrast allowable range is 4-bit 
     * value so discard upper 4 bits of val 
     */
    if((val & 0x0F) != g_lcd_contrast) {
        LCD_SET_CONTRAST(val);
        g_lcd_contrast = val & 0x0F;
    }
}

void
ossw_lcd_set_cursor(uint8_t row, uint8_t col)
{
    uint8_t addr = 0;

    if((row < 1) || (row > OSSW_LCD_ROW_NUM) || \
            (col < 1) || (col > OSSW_LCD_COL_NUM)) {
        return;
    }

    addr = (((row == OSSW_LCD_ROW_NUM) ? LCD_MEM_ROW2_MIN : LCD_MEM_ROW1_MIN) | (col - 1)); 

    LCD_SET_DDRAM_ADDR(addr);
}

void
ossw_lcd_print_char(char c)
{
    LCD_WRITE_DATA(c);
}

void
ossw_lcd_print_string(char* s)
{
    char* p = NULL;

    if(NULL == s) {
        return;
    }
    p = s;

    while(*p) ossw_lcd_print_char(*(p++));
}

void
ossw_lcd_display(char* s1, char* s2, uint8_t j1, uint8_t j2)
{
    if((NULL == s1) || (NULL == s2) || (j1 > 2) || (j2 > 2)) {
        return;
    }

    ossw_lcd_clear_display();
    ossw_lcd_return_home();

    ossw_lcd_set_cursor(1,1);
    ossw_lcd_print_string(s1);

    ossw_lcd_set_cursor(2,1);
    ossw_lcd_print_string(s2);
}

void 
ossw_lcd_create_custom_char(uint8_t num, uint8_t* data)
{
    uint8_t *p = NULL;

    if((NULL == data) || (num >= OSSW_LCD_MAX_CUSTOM_CHARS)) {
        return;
    }

    p = data;

    LCD_WRITE_FUNCTION_SET1;

    LCD_SET_CGRAM_ADDR(num);

    for(int i = 0; i < OSSW_LCD_CHAR_HEIGHT; i++) {
        LCD_WRITE_DATA(*(p++));
    }

    LCD_WRITE_FUNCTION_SET2;

    ossw_lcd_set_cursor(1,1);
}

void 
ossw_lcd_print_custom_char(uint8_t num)
{
    if(num >= OSSW_LCD_MAX_CUSTOM_CHARS) {
        return;
    }

    LCD_WRITE_DATA(num);
}

void
ossw_lcd_backlight_enable(void)
{
	PORT->Group[LCD_BL_PORT].OUTSET.reg = PORT_LCD_BL;
}

void ossw_lcd_backlight_disable(void)
{
	PORT->Group[LCD_BL_PORT].OUTCLR.reg = PORT_LCD_BL;
}
