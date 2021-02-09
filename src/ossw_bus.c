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

/* implements */
#include <ossw_bus.h>

/*
 * defines
 *
 */

#define BUS_PORT_A  0x00        /* Port Group A */
#define BUS_PORT_B  0x01        /* Port Group B */

#define PORT_BUS1   PORT_PB06
#define PORT_BUS2   PORT_PB07
#define PORT_BUS3   PORT_PB08
#define PORT_BUS4   PORT_PB09
#define PORT_BUS5   PORT_PA04
#define PORT_BUS6   PORT_PA05
#define PORT_BUS7   PORT_PA06
#define PORT_BUS8   PORT_PA07

/*
 * globals
 *
 */

static uint8_t g_current_bus = OSSW_BUS_ID1;

/*
 * exported functions
 *
 */

void 
ossw_bus_init(void)
{
    /* set BUS0..7 as outputs */
    PORT->Group[BUS_PORT_B].DIRSET.reg = PORT_BUS1 | PORT_BUS2 | PORT_BUS3 | PORT_BUS4;
    PORT->Group[BUS_PORT_A].DIRSET.reg = PORT_BUS5 | PORT_BUS6 | PORT_BUS7 | PORT_BUS8;

    /* clear BUS0..7 to be safe */
    ossw_bus_disable_all();
}

void
ossw_bus_disable_all(void)
{
    /* set BUS0..7 high */
    PORT->Group[BUS_PORT_B].OUTSET.reg = PORT_BUS1 | PORT_BUS2 | PORT_BUS3 | PORT_BUS4;
    PORT->Group[BUS_PORT_A].OUTSET.reg = PORT_BUS5 | PORT_BUS6 | PORT_BUS7 | PORT_BUS8;
}

void
ossw_bus_cycle(int8_t increment)
{
    uint8_t bus =
        ((g_current_bus + increment + OSSW_BUS_NUM) % OSSW_BUS_NUM);
    ossw_bus_enable(bus);
}

void
ossw_bus_enable(uint8_t bus)
{
    /* disable all buses */
    ossw_bus_disable_all();

    /* enable selected bus */
    switch(bus){
        case OSSW_BUS_ID1:
            PORT->Group[BUS_PORT_B].OUTCLR.reg = PORT_BUS1;
            break;;
        case OSSW_BUS_ID2:
            PORT->Group[BUS_PORT_B].OUTCLR.reg = PORT_BUS2;
            break;;
        case OSSW_BUS_ID3:
            PORT->Group[BUS_PORT_B].OUTCLR.reg = PORT_BUS3;
            break;;
        case OSSW_BUS_ID4:
            PORT->Group[BUS_PORT_B].OUTCLR.reg = PORT_BUS4;
            break;;
        case OSSW_BUS_ID5:
            PORT->Group[BUS_PORT_A].OUTCLR.reg = PORT_BUS5;
            break;;
        case OSSW_BUS_ID6:
            PORT->Group[BUS_PORT_A].OUTCLR.reg = PORT_BUS6;
            break;;
        case OSSW_BUS_ID7:
            PORT->Group[BUS_PORT_A].OUTCLR.reg = PORT_BUS7;
            break;;
        case OSSW_BUS_ID8:
            PORT->Group[BUS_PORT_A].OUTCLR.reg = PORT_BUS8;
            break;;
        case OSSW_BUS_NUM:
            ossw_bus_disable_all();     /* error */
            break;;
    }

    /* update current bus */
    g_current_bus = bus;
}

void
ossw_bus_enable_next(void)
{
    ossw_bus_cycle(1);
}

void
ossw_bus_enable_prev(void)
{
    ossw_bus_cycle(-1);
}

uint8_t
ossw_bus_get_current_bus(void)
{
    return g_current_bus;
}
