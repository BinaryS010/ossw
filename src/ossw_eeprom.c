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
#include <string.h>
#include <ossw_delay.h>
#include <ossw_i2c.h>

/* implements */
#include <ossw_eeprom.h>

/*
 * defines
 *
 */

#define EEPROM_PAGE_SIZE            32
#define EEPROM_ADDR_SIZE            2

#define EEPROM_I2C_BUFFER_LEN       (size_t) (EEPROM_PAGE_SIZE + EEPROM_ADDR_SIZE)

#define EEPROM_WRITE_TIME           5

/*
 * globals
 *
 */

static const uint8_t EEPROM_I2C_ADDR = 0x50;

static uint8_t g_buf[EEPROM_I2C_BUFFER_LEN] = { 0 };

/*
 * exported functions
 *
 */

int
ossw_eeprom_read(uint16_t addr, uint8_t* data, size_t data_len)
{
    /* input checking */
    if((NULL == data) || (data_len == 0)){
        return -1;
    }

    /* clear buffer */
    (void) memset(g_buf, 0, EEPROM_I2C_BUFFER_LEN);

    /* 
     * set 24LC64 address
     * pointer by first 
     * issuing a write request
     * to the desired address
     */
    g_buf[0] = (uint8_t) (addr >> 8);
    g_buf[1] = (uint8_t) (addr & 0xFF);

    ossw_i2c_write(EEPROM_I2C_ADDR, g_buf, EEPROM_ADDR_SIZE);

    /* 
     * now address pointer is set,
     * perform a SEQUENTIAL read
     * of the data required into
     * the caller supplied buffer
     */
    ossw_i2c_read(EEPROM_I2C_ADDR, data, data_len);

    return 0;
}

int
ossw_eeprom_write(uint16_t addr, uint8_t* data, size_t data_len)
{
    int pages = 0;

    /* input checking */
    if((NULL == data) || (data_len == 0)){
        return -1;
    }

    /* clear buffer */
    (void) memset(g_buf, 0, EEPROM_I2C_BUFFER_LEN);

    /*
     * because the 24LC64 EEPROM
     * has a write cycle time of 
     * ~5ms in both byte AND page
     * write modes, writing a byte 
     * at a time will be very slow. 
     *
     * Instead, use the page write 
     * function to write up to 32 
     * bytes of data at a time.
     */

    /* calculate number of pages */
    pages = data_len / EEPROM_PAGE_SIZE;
    if (data_len % EEPROM_PAGE_SIZE) {
        pages++;
    }

    /* write data in pages */
    for(int i = 1; i <= pages; i++) {

        g_buf[0] = (uint8_t) (addr >> 8);
        g_buf[1] = (uint8_t) (addr & 0xFF);

        /* full page or fractional page at the end of the buffer */
        if(i == pages) {
            (void) memcpy(
                    &g_buf[2], data, data_len % EEPROM_PAGE_SIZE);

            ossw_i2c_write(
                    EEPROM_I2C_ADDR, 
                    g_buf, 
                    EEPROM_ADDR_SIZE + (data_len % EEPROM_PAGE_SIZE));
        } else {
            (void) memcpy(&g_buf[2], data, EEPROM_PAGE_SIZE);

            ossw_i2c_write(
                    EEPROM_I2C_ADDR, 
                    g_buf, 
                    EEPROM_I2C_BUFFER_LEN);
        }

        /* 
         * advance address and 
         * data pointers by one
         * whole page
         */
        addr += EEPROM_PAGE_SIZE;
        data += EEPROM_PAGE_SIZE;

        /* clear buffer for next page */
        (void) memset(g_buf, 0, EEPROM_I2C_BUFFER_LEN);

        /* wait for eeprom write cycle */
        delay_ms(EEPROM_WRITE_TIME);
    }

    return 0;
}
