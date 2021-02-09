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

#include <stdlib.h>

/* implements */
#include <ossw_ir_nec.h>

/*
 * defines
 *
 */

/* Source: https://www.sbprojects.net/knowledge/ir/nec.php */

#define NEC_AGC_PULSE_USECS         9000u   /* start of message */
#define NEC_LONG_PAUSE_USECS        4500u   /* follows AGC pulse for complete code */
#define NEC_SHORT_PAUSE_USECS       2250u   /* follows AGC pulse for repeat code */
#define NEC_STOP_PULSE_USECS        560u    /* end of message */

#define NEC_DATA_BITS               32
#define NEC_DATA_REPEAT_LEN         4
#define NEC_DATA_CODE_LEN           (4 + (2 * NEC_DATA_BITS))

/*
 * NEC protocol transmits data as:
 *  - logical 1: 560us MARK + 1690us SPACE
 *  - logical 0: 560us MARK + 560us SPACE
 */
#define NEC_DATA_MARK_USECS         560u
#define NEC_DATA_ONE_SPACE_USECS    1690u
#define NEC_DATA_ZERO_SPACE_USECS   560u

#define NEC_NUM_KEYCODES            6

/* 
 * globals
 *
 */

static const uint16_t g_nec_keymap[NEC_NUM_KEYCODES] = {
    0x0000, /* unused */
    0x05FA, /* EXEC */ 
    0x1BE4, /* PREV */
    0x1AE5, /* NEXT */
    0x04FB, /* JUMPL */
    0x06F9  /* JUMPR */
};

/*
 * exported functions
 *
 */

int
ossw_ir_nec_decode(struct ossw_ir_result *results)
{
    int ret = -1;
    int index = 1;

    uint32_t data = 0;

    if(NULL == results){
        goto out;
    }

    /* check for initial AGC pulse */
    if(!CHECK(NEC_AGC_PULSE_USECS, g_ir_data.buf[index++])){
        goto out;
    }

    if((g_ir_data.len == NEC_DATA_REPEAT_LEN) && 
            (CHECK(NEC_SHORT_PAUSE_USECS, g_ir_data.buf[index]))) {     /* repeat code */

        results->data = OSSW_IR_REPEAT;
        results->len  = 0;

    } else if((g_ir_data.len == NEC_DATA_CODE_LEN) && 
            (CHECK(NEC_LONG_PAUSE_USECS, g_ir_data.buf[index]))) {      /* complete code */

        index++;
        for(int i = 0; i < NEC_DATA_BITS; i++) {
            if(!CHECK(MARK(NEC_DATA_MARK_USECS), g_ir_data.buf[index++])){
                goto out;
            }

            if(CHECK(SPACE(NEC_DATA_ONE_SPACE_USECS), g_ir_data.buf[index])) {
                data |= (1 << i);
            } else if (CHECK(SPACE(NEC_DATA_ZERO_SPACE_USECS), g_ir_data.buf[index])) {
                data &= ~(1 << i);
            } else {
                goto out;
            }
            index++;
        }

        /* reverse bytes */
        results->data = (((data & 0xFF000000) >> 24) | ((data & 0x00FF0000) >> 8)  | 
                ((data & 0x0000FF00) << 8) | ((data & 0x000000FF) << 24));
        results->len = NEC_DATA_BITS;

    } else {
        goto out;
    }

    /* indicate successful decode */
    results->proto = OSSW_IR_PROTOCOL_NEC;
    ret = 0;

out:
    return ret;
}

int
ossw_ir_nec_match(unsigned int action, struct ossw_ir_result *results)
{
    /* input check */
    if((NULL == results) || (action >= NEC_NUM_KEYCODES) ||
            (results->proto != OSSW_IR_PROTOCOL_NEC)) {
        return 0;
    }

    return ((results->data & 0x0000FFFF) == g_nec_keymap[action]) ? 1 : 0;
}
