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

/* implements */
#include <ossw_rgb.h>

/*
 * globals
 *
 */

#define RGB_PORT       0x00        /* Port Group A */

#define PORT_RGB_LPF   PORT_PA14
#define PIN_RGB_LPF    PIN_PA14

/*
 * RGB Low Pass Filter enabled setting
 */
static uint8_t g_rgb_lpf_enabled = 0;

/*
 * static functions
 *
 */

static void 
rgb_lpf_enable(void)
{
    if(g_rgb_lpf_enabled)
        return;

    /* enable RGB LPF filter */
    PORT->Group[RGB_PORT].OUTCLR.reg = PORT_RGB_LPF;

    /* update enabled flag */
    g_rgb_lpf_enabled = 1;
}

static void 
rgb_lpf_disable(void)
{
    if(!g_rgb_lpf_enabled)
        return;

    /* disable RGB LPF filter */
    PORT->Group[RGB_PORT].OUTSET.reg = PORT_RGB_LPF;

    /* update enabled flag */
    g_rgb_lpf_enabled = 0;
}

/*
 * exported functions
 *
 */

void 
ossw_rgb_init(void)
{
    /* set PORT_RGB_LPF as output */
    PORT->Group[RGB_PORT].DIRSET.reg = PORT_RGB_LPF;

    /* disable RGB LPF by default */
    rgb_lpf_disable();
}

void 
ossw_rgb_lpf_toggle(void)
{
    if(g_rgb_lpf_enabled) {
        rgb_lpf_disable();
    } else {
        rgb_lpf_enable();
    }
}

void
ossw_rgb_lpf_set_enable(uint8_t enable)
{
    if(enable){
        rgb_lpf_enable();
    } else {
        rgb_lpf_disable();
    }
}

uint8_t 
ossw_rgb_lpf_get_enable(void)
{
    return g_rgb_lpf_enabled;
}
