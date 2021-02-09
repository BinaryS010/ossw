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

#include <samd21.h>

#include <stdlib.h>

#include <ossw_timer.h>

/* implements */
#include <ossw_button.h>

/*
 * defines
 *
 */


#define BUTTON_PORT             0x00        /* Port Group A */

#define PORT_BUTTON_ACTION      PORT_PA20
#define PIN_BUTTON_ACTION       PIN_PA20

#define PORT_BUTTON_UP          PORT_PA19
#define PIN_BUTTON_UP           PIN_PA19

#define PORT_BUTTON_DOWN        PORT_PA18
#define PIN_BUTTON_DOWN         PIN_PA18

#define PORT_BUTTON_LEFT        PORT_PA21
#define PIN_BUTTON_LEFT         PIN_PA21

#define PORT_BUTTON_RIGHT       PORT_PA22
#define PIN_BUTTON_RIGHT        PIN_PA22

#define BUTTON_GROUP_MASK       0x1F
#define BUTTON_GROUP_SHIFT      18

#define BUTTON_IGNORE           300

void 
ossw_button_init(void)
{
    PORT->Group[BUTTON_PORT].DIRCLR.reg = 
        PORT_BUTTON_ACTION | PORT_BUTTON_UP | PORT_BUTTON_DOWN |
        PORT_BUTTON_LEFT | PORT_BUTTON_RIGHT; 

    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_ACTION].reg |= PORT_PINCFG_INEN;
    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_ACTION].reg &= ~PORT_PINCFG_PULLEN;

    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_UP].reg |= PORT_PINCFG_INEN;
    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_UP].reg &= ~PORT_PINCFG_PULLEN;

    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_DOWN].reg |= PORT_PINCFG_INEN;
    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_DOWN].reg &= ~PORT_PINCFG_PULLEN;

    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_LEFT].reg |= PORT_PINCFG_INEN;
    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_LEFT].reg &= ~PORT_PINCFG_PULLEN;

    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_RIGHT].reg |= PORT_PINCFG_INEN;
    PORT->Group[BUTTON_PORT].PINCFG[PIN_BUTTON_RIGHT].reg &= ~PORT_PINCFG_PULLEN;
}

int
ossw_button_read(uint8_t *button)
{
    int ret = -1;
    uint32_t reg = 0;

    static unsigned long button_last_press = 0;

    /* input check */
    if(NULL == button) {
        goto out;
    }

    ret = 0;

    if((millis() - button_last_press) >= BUTTON_IGNORE) {
        reg = PORT->Group[BUTTON_PORT].IN.reg & (BUTTON_GROUP_MASK << BUTTON_GROUP_SHIFT);
        *button = (uint8_t) (reg >> BUTTON_GROUP_SHIFT);

        if(*button) {
            button_last_press = millis();
            ret = 1;
        }
    }

out:
    return ret;
}
