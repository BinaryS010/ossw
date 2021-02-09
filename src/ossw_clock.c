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
#include <ossw_clock.h>

/*
 * defines
 *
 */

/* Clock generator constants */
#define GENERIC_CLOCK_GENERATOR_MAIN      (0u)
#define GENERIC_CLOCK_GENERATOR_XOSC32K   (1u)
#define GENERIC_CLOCK_GENERATOR_OSCULP32K (2u)
#define GENERIC_CLOCK_GENERATOR_OSC8M     (3u)

/* Clock multiplexer constants */
#define GENERIC_CLOCK_MULTIPLEXER_DFLL48M (0u)

/*
 * exported functions
 *
 */

void 
ossw_clock_init(void)
{
    uint32_t dfll_48_calibration_coarse = 0;

    /* set flash wait states (48MHz, 3V3) */
    NVMCTRL->CTRLB.bit.RWS = 1;

    /*
     * configure XOSC32K
     *
     */
	
	/* configure XOSC32K as DFLL48M reference */
    SYSCTRL_XOSC32K_Type sysctrl_xosc32k = {
        .bit.WRTLOCK = 0,
        .bit.STARTUP = 0x2,
        .bit.ONDEMAND = 0,
        .bit.RUNSTDBY = 0,
        .bit.AAMPEN = 0,
        .bit.EN32K = 1,
        .bit.XTALEN = 1
    };

    /* write settings */
    SYSCTRL->XOSC32K.reg = sysctrl_xosc32k.reg;
    
    /* enable oscillator */
    SYSCTRL->XOSC32K.bit.ENABLE = 1;
	
    /* wait until XOSC32K is ready */
    while(!SYSCTRL->PCLKSR.bit.XOSC32KRDY);
	
    /*
     * set XOSC32K as source of Generic clock generator 1
     *
     */
	
    /* configure GCLK->GENDIV */
    GCLK_GENDIV_Type gclk1_gendiv = {
        .bit.DIV = 1,
        .bit.ID = GENERIC_CLOCK_GENERATOR_XOSC32K
    };

    /* write settings */
    GCLK->GENDIV.reg = gclk1_gendiv.reg;
	
    /* configure generic Clock generator 1 using XOSC32K as source */
    GCLK_GENCTRL_Type gclk1_genctrl = {
        .bit.RUNSTDBY = 0,
        .bit.DIVSEL =  0,
        .bit.OE = 0,
        .bit.OOV = 0,
        .bit.IDC = 1,
        .bit.GENEN = 1,
        .bit.SRC = 0x05,
        .bit.ID = GENERIC_CLOCK_GENERATOR_XOSC32K
    };

    /* write settings */
    GCLK->GENCTRL.reg = gclk1_genctrl.reg;

    /* wait for sync to complete */
    while(GCLK->STATUS.bit.SYNCBUSY);
	
    /* set Generic clock generator 1 as source for Generic clock multiplexer 0 */
    GCLK_CLKCTRL_Type gclk_clkctrl = {
        .bit.WRTLOCK = 0,
        .bit.CLKEN = 1,	
        .bit.GEN = GENERIC_CLOCK_GENERATOR_XOSC32K,
        .bit.ID = 0x00
    };

    /* write settings */
    GCLK->CLKCTRL.reg = gclk_clkctrl.reg;
	
    /*
     * enable DFLL48M clock
     *
     */

    /* wait for ready */
    while(!SYSCTRL->PCLKSR.bit.DFLLRDY);

    /* enable */
    SYSCTRL->DFLLCTRL.reg = (uint16_t)(SYSCTRL_DFLLCTRL_ENABLE);

    /* wait for ready */
    while(!SYSCTRL->PCLKSR.bit.DFLLRDY);
	
    /* set multiplier, coarse and fine steps */
    SYSCTRL_DFLLMUL_Type sysctrl_dfllmul = {
        .bit.CSTEP = 31,
        .bit.FSTEP = 511,
        .bit.MUL = 1465
    };

    /* write settings */
    SYSCTRL->DFLLMUL.reg = sysctrl_dfllmul.reg;

    /* wait for until DFLL is ready */
    while(!SYSCTRL->PCLKSR.bit.DFLLRDY);

    /* Retrieve "DFLL48M COARSE CAL" value from NVM factory calibration area. */
    dfll_48_calibration_coarse = *(uint32_t*)FUSES_DFLL48M_COARSE_CAL_ADDR;
    dfll_48_calibration_coarse &= FUSES_DFLL48M_COARSE_CAL_Msk;
    dfll_48_calibration_coarse = dfll_48_calibration_coarse>>FUSES_DFLL48M_COARSE_CAL_Pos;

    /* write settings */
    SYSCTRL->DFLLVAL.bit.COARSE = dfll_48_calibration_coarse;

    /* wait until DFLL is ready and enable WAITLOCK */
    while(!SYSCTRL->PCLKSR.bit.DFLLRDY);
    SYSCTRL->DFLLCTRL.reg |= (uint16_t) (SYSCTRL_DFLLCTRL_MODE | SYSCTRL_DFLLCTRL_WAITLOCK);

   /*
    * update source of Generic clock generator 0 to be DFLL48M. 
    *
    * core should then run at 48MHz.
    *
    */

    /* switch source of Clock generator 0 */
    GCLK_GENCTRL_Type gclk_genctrl0 = {
        .bit.RUNSTDBY = 0,
        .bit.DIVSEL =  0,
        .bit.OE = 1,
        .bit.OOV = 0,
        .bit.IDC = 1,
        .bit.GENEN = 1,
        .bit.SRC = 0x07,
        .bit.ID = GENERIC_CLOCK_GENERATOR_MAIN
    };

    /* write settings */
    GCLK->GENCTRL.reg = gclk_genctrl0.reg;

    /* wait for sync to complete */
    while(GCLK->STATUS.bit.SYNCBUSY);

    /* configure CPU and APBx bus clocks for 48MHz */
    PM->CPUSEL.reg  = PM_CPUSEL_CPUDIV_DIV1 ;
    PM->APBASEL.reg = PM_APBASEL_APBADIV_DIV1_Val ;
    PM->APBBSEL.reg = PM_APBBSEL_APBBDIV_DIV1_Val ;
    PM->APBCSEL.reg = PM_APBCSEL_APBCDIV_DIV1_Val ;
}
