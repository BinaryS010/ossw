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

#ifndef _OSSW_BUS_H_
#define _OSSW_BUS_H_

/*
 * includes
 *
 */
#include <stdint.h>

/*
 * enums
 *
 */

enum ossw_bus_id {

    OSSW_BUS_ID1 = 0,
    OSSW_BUS_ID2 = 1,
    OSSW_BUS_ID3 = 2,
    OSSW_BUS_ID4 = 3,
    OSSW_BUS_ID5 = 4,
    OSSW_BUS_ID6 = 5,
    OSSW_BUS_ID7 = 6,
    OSSW_BUS_ID8 = 7,
    OSSW_BUS_NUM = 8

};

/*
 * exported functions
 *
 */

void ossw_bus_init(void);

void ossw_bus_disable_all(void);

void ossw_bus_cycle(int8_t increment);

void ossw_bus_enable(uint8_t bus);

void ossw_bus_enable_next(void);

void ossw_bus_enable_prev(void);

uint8_t ossw_bus_get_current_bus(void);

#endif /* ! _OSSW_BUS_H_ */
