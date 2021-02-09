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
/* Partially derived from Arduino-IRremote library                        */
/*   https://github.com/Arduino-IRremote/Arduino-IRremote                 */
/* Original copyright notice and license:                                 */
/* ********************************************************************** */
/* MIT License
 *
 * Copyright (c) 2015-2021 Ken Shirriff http://www.righto.com, Rafi Khan, Armin Joachimsmeyer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ************************************************************************************
 */

/*
 * includes
 *
 */

#include <samd21.h>

#include <stdlib.h>

#include <ossw_interrupt.h>
#include <ossw_timer.h>

/* implements */
#include <ossw_ir.h>

/* protocol decoders */
#include <ossw_ir_nec.h>

/*
 * defines
 *
 */

#define IR_RECV_PORT            0x00        /* Port Group A */

#define PORT_IR_RECV            PORT_PA27
#define PIN_IR_RECV             PIN_PA27

#if !defined F_CPU
#error "Please specify the CPU frequency."
#endif

#define MICROS_PER_SECOND       1000000ul

#define IR_IGNORE               300

/*
 * macros
 *
 */

#define NUM_DECODERS            ((int) (sizeof(g_decoders) / sizeof(struct decoder)))

/*
 * globals
 *
 */

static const struct decoder {

    int proto;
    int (*decode)(struct ossw_ir_result *results);
    int (*match) (unsigned int code, struct ossw_ir_result *results);

} g_decoders[] = {

    { OSSW_IR_PROTOCOL_NEC, ossw_ir_nec_decode, ossw_ir_nec_match },
};

volatile struct ossw_ir_data g_ir_data = { 0 };

/*
 * static functions
 *
 */

static inline uint8_t
ir_read(void)
{
    uint32_t reg = 0;

    reg = PORT->Group[IR_RECV_PORT].IN.reg & PORT_IR_RECV;
    return (uint8_t) (reg >> PIN_IR_RECV);
}

static inline void
ir_reset(void)
{
    ATOMIC_SECTION_ENTER;
    g_ir_data.len = 0;
    g_ir_data.state = OSSW_IR_STATE_LISTEN;
    ATOMIC_SECTION_LEAVE;
}

/*
 * interrupt handlers
 *
 */

void
TC4_Handler(void)
{
    uint8_t recv = 0;

    if (TC4->COUNT16.INTFLAG.reg & TC_INTFLAG_MC(1)) {

        g_ir_data.ticks++;

        if(g_ir_data.len >= OSSW_IR_BUFLEN){
            g_ir_data.state = OSSW_IR_STATE_ERROR;
        }

        /* read IR receiver input */
        recv = ir_read();

        switch(g_ir_data.state){

            case OSSW_IR_STATE_LISTEN:
                if(recv == OSSW_IR_MARK){
                    if(g_ir_data.ticks < OSSW_IR_MIN_GAP_TICKS) {
                        g_ir_data.ticks = 0;
                    } else {
                        g_ir_data.len = 0;
                        g_ir_data.buf[g_ir_data.len++] = g_ir_data.ticks;
                        g_ir_data.ticks = 0;
                        g_ir_data.err = OSSW_IR_ERROR_FALSE;
                        g_ir_data.state = OSSW_IR_STATE_MARK;
                    }
                }
                break;

            case OSSW_IR_STATE_MARK:
                if(recv == OSSW_IR_SPACE){
                    g_ir_data.buf[g_ir_data.len++] = g_ir_data.ticks;
                    g_ir_data.ticks = 0;
                    g_ir_data.state = OSSW_IR_STATE_SPACE;
                }
                break;

            case OSSW_IR_STATE_SPACE:
                if(recv == OSSW_IR_MARK){
                    g_ir_data.buf[g_ir_data.len++] = g_ir_data.ticks;
                    g_ir_data.ticks = 0;
                    g_ir_data.state = OSSW_IR_STATE_MARK;

                } else if(g_ir_data.ticks > OSSW_IR_MIN_GAP_TICKS) {
                    g_ir_data.state = OSSW_IR_STATE_DONE;
                }
                break;

            case OSSW_IR_STATE_DONE:
                if(recv == OSSW_IR_MARK){
                    g_ir_data.ticks = 0;
                }
                break;

            default:
            case OSSW_IR_STATE_ERROR:
                g_ir_data.err = OSSW_IR_ERROR_TRUE;
                g_ir_data.state = OSSW_IR_STATE_DONE;
                break;
        }

        /* clear interrupt flag */
        TC4->COUNT16.INTFLAG.reg = TC_INTFLAG_MC(1);
    }
}


/*
 * exported functions
 *
 */

void
ossw_ir_init(void)
{
    /*
     * configure TC4 to generate 50uS interrupt
     *
     */

    PM->APBCMASK.reg |= PM_APBCMASK_TC4;

    GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(TC4_GCLK_ID) |
        GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN(0);

    TC4->COUNT16.CTRLA.reg = TC_CTRLA_MODE_COUNT16 | TC_CTRLA_WAVEGEN_MFRQ |
        TC_CTRLA_PRESCSYNC_GCLK;

    TC4->COUNT16.CC[0].reg = ((F_CPU / MICROS_PER_SECOND) * OSSW_IR_TICK_USECS); 
    TC4->COUNT16.COUNT.reg = 0;

    TC4->COUNT16.CTRLA.reg |= TC_CTRLA_ENABLE;
    while (TC4->COUNT16.STATUS.bit.SYNCBUSY);

    TC4->COUNT16.INTENSET.reg = TC_INTENSET_MC(1);
    NVIC_EnableIRQ(TC4_IRQn);

    /* 
     * configure input pin
     *
     */

    PORT->Group[IR_RECV_PORT].DIRCLR.reg = PORT_IR_RECV;

    PORT->Group[IR_RECV_PORT].PINCFG[PIN_IR_RECV].reg |= PORT_PINCFG_INEN;
    PORT->Group[IR_RECV_PORT].PINCFG[PIN_IR_RECV].reg &= ~PORT_PINCFG_PULLEN;

    /* initialise state */
    ir_reset();
}

int
ossw_ir_recv(struct ossw_ir_result *results)
{
    int ret = -1;
    uint8_t state = 0;

    static unsigned long ir_last_recv = 0;

    /* parameter check */
    if(NULL == results) {
        goto out;
    }

    ATOMIC_SECTION_ENTER;
    state = g_ir_data.state;
    ATOMIC_SECTION_LEAVE;

    ret = 0;

    switch(state) {
        case OSSW_IR_STATE_DONE:
            if((millis() - ir_last_recv) >= IR_IGNORE) {

                /* decode data */
                ATOMIC_SECTION_ENTER;
                for(int i = 0; i < NUM_DECODERS; i++) {
                    if(g_decoders[i].decode(results) == 0) {
                        break;
                    }
                }
                ATOMIC_SECTION_LEAVE;

                if (results->proto) {
                    ir_last_recv = millis();
                    ret = 1;
                }
            }
            ir_reset();
            break;

        case OSSW_IR_STATE_ERROR:
            ir_reset();
            break;

        default:                    /* ignore other states */
            break;
    }

out:
    return ret;
}

int
ossw_ir_check(uint32_t usecs, uint32_t ticks)
{
    return ((OSSW_CHECK_MIN_USECS(ticks) <= usecs) && 
            (OSSW_CHECK_MAX_USECS(ticks) >= usecs)) ? 1 : 0;
}

int
ossw_ir_match(unsigned int action, struct ossw_ir_result *results)
{

    /* input check */
    if((NULL == results) || (!results->proto) || (results->proto > NUM_DECODERS)) {
        return 0;
    }

    /* match code */
    return g_decoders[results->proto].match(action, results);
}
