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

#include <ossw_systick.h>

/* implements */
#include <ossw_delay.h>

/*
 * defines
 *
 */

#if !defined F_CPU
#error "Please specify the CPU frequency."
#endif

#define delay_cycles(val) ossw_systick_delay_cycles(val)

/*
 * globals
 *
 */

static uint32_t cycles_per_ms = ((F_CPU / 1000) - 1);
static uint32_t cycles_per_us = ((F_CPU / 1000000) - 1);

/*
 * exported functions
 *
 */

void 
ossw_delay_cycles_us(uint32_t n)
{
	while (n--) {
		delay_cycles(cycles_per_us);
	}
}

void 
ossw_delay_cycles_ms(uint32_t n)
{
	while (n--) {
		delay_cycles(cycles_per_ms);
	}
}

