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

#include <ossw_interrupt.h>

/* implements */
#include <ossw_timer.h>

/*
 * defines
 *
 */

#if !defined F_CPU
#error "Please specify the CPU frequency."
#endif

#define MILLIS_PER_SECOND   1000ul

/*
 * globals
 *
 */

static volatile unsigned long g_millis = 0;

void
TC3_Handler(void)
{
    if (TC3->COUNT16.INTFLAG.reg & TC_INTFLAG_MC(1)) {
        g_millis++;
        TC3->COUNT16.INTFLAG.reg = TC_INTFLAG_MC(1);
    }
}

/*
 * exported functions
 *
 */

void
ossw_timer_init(void)
{
    PM->APBCMASK.reg |= PM_APBCMASK_TC3;

    GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(TC3_GCLK_ID) |
        GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN(0);

    TC3->COUNT16.CTRLA.reg = TC_CTRLA_MODE_COUNT16 | TC_CTRLA_WAVEGEN_MFRQ |
        TC_CTRLA_PRESCSYNC_GCLK;

    TC3->COUNT16.CC[0].reg = (F_CPU / MILLIS_PER_SECOND) - 1; 
    TC3->COUNT16.COUNT.reg = 0;

    TC3->COUNT16.CTRLA.reg |= TC_CTRLA_ENABLE;
    while (TC3->COUNT16.STATUS.bit.SYNCBUSY);

    TC3->COUNT16.INTENSET.reg = TC_INTENSET_MC(1);
    NVIC_EnableIRQ(TC3_IRQn);
}

unsigned long
ossw_timer_millis(void)
{
    unsigned long m = 0;

    ATOMIC_SECTION_ENTER;
    m = g_millis;
    ATOMIC_SECTION_LEAVE;

    return m;
}
