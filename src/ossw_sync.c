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
#include <ossw_sync.h>

/*
 * globals
 *
 */

#define SYNC_PORT           0x00        /* Port Group A */

#define PORT_SYNC_STRIP     PORT_PA15
#define PIN_SYNC_STRIP      PIN_PA15

/*
 * Sync strip enabled setting
 */
static uint8_t g_sync_strip_enabled = 0;

/*
 * static functions
 *
 */

static void 
sync_strip_enable(void)
{
    if(g_sync_strip_enabled)
        return;

    /* enable sync stripping */
    PORT->Group[SYNC_PORT].OUTSET.reg = PORT_SYNC_STRIP;

    /* update enabled flag */
    g_sync_strip_enabled = 1;
}

static void 
sync_strip_disable(void)
{
    if(!g_sync_strip_enabled)
        return;

    /* disable sync stripping */
    PORT->Group[SYNC_PORT].OUTCLR.reg = PORT_SYNC_STRIP;

    /* update enabled flag */
    g_sync_strip_enabled = 0;
}

/*
 * exported functions
 *
 */

void 
ossw_sync_init(void)
{
    /* set PORT_SYNC_STRIP as output */
    PORT->Group[SYNC_PORT].DIRSET.reg = PORT_SYNC_STRIP;

    /* disable sync stripping by default */
    sync_strip_disable();
}

void 
ossw_sync_strip_toggle(void)
{
    if(g_sync_strip_enabled) {
        sync_strip_disable();
    } else {
        sync_strip_enable();
    }
}

void
ossw_sync_strip_set_enable(uint8_t enable)
{
    if(enable){
        sync_strip_enable();
    } else {
        sync_strip_disable();
    }
}

uint8_t 
ossw_sync_strip_get_enable(void)
{
    return g_sync_strip_enabled;
}

