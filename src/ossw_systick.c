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
#include <ossw_systick.h>

/*
 * exported functions
 *
 */

void
ossw_systick_init(void)
{
	SysTick->CTRL = 0;
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;
}

void 
ossw_systick_delay_cycles(uint32_t cycles)
{
	uint8_t  n   = cycles >> 24;
	uint32_t buf = cycles;

	while (n--) {
		SysTick->LOAD = 0xFFFFFF;
		SysTick->VAL  = 0xFFFFFF;
		while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
		buf -= 0xFFFFFF;
	}

	SysTick->LOAD = buf;
	SysTick->VAL  = buf;
	while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
}


