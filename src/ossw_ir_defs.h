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

#ifndef _OSSW_IR_DEFS_H_
#define _OSSW_IR_DEFS_H_

/*
 * includes
 *
 */

#include <stdint.h>

/*
 * defines
 *
 */

#define OSSW_IR_SPACE                   1
#define OSSW_IR_MARK                    0

#define OSSW_IR_BUFLEN                  128u

#define OSSW_IR_TICK_USECS              50u

#define OSSW_IR_MIN_GAP_USECS           10000u
#define OSSW_IR_MIN_GAP_TICKS           (OSSW_IR_MIN_GAP_USECS/OSSW_IR_TICK_USECS)

#define OSSW_CHECK_TICK_MARGIN          2
#define OSSW_CHECK_MIN_USECS(x)         ((x - OSSW_CHECK_TICK_MARGIN) * OSSW_IR_TICK_USECS)
#define OSSW_CHECK_MAX_USECS(x)         ((x + OSSW_CHECK_TICK_MARGIN) * OSSW_IR_TICK_USECS)

#define OFFSET                          50u
#define SPACE(x)                        (x - OFFSET)
#define MARK(x)                         (x + OFFSET)

#define CHECK(x,y)                      ossw_ir_check(x,y)

#define OSSW_IR_REPEAT                  0xFFFFFFFF

/*
 * enums
 *
 */

enum ossw_ir_state {

    OSSW_IR_STATE_LISTEN = 1,
    OSSW_IR_STATE_MARK,
    OSSW_IR_STATE_SPACE,
    OSSW_IR_STATE_DONE,
    OSSW_IR_STATE_ERROR,

};

enum ossw_ir_error {
    
    OSSW_IR_ERROR_FALSE = 0,
    OSSW_IR_ERROR_TRUE
};

/* supported ir protocols */
enum ossw_ir_protocol {

    OSSW_IR_PROTOCOL_UNKNOWN = 0,
    OSSW_IR_PROTOCOL_NEC
};

/*
 * types
 *
 */

struct ossw_ir_data {
    
    uint32_t ticks;
    uint32_t buf[OSSW_IR_BUFLEN];
    uint8_t  state;
    uint8_t  len;
    uint8_t  err;
};


struct ossw_ir_result {

    uint32_t data;
    uint8_t  len;
    uint8_t  proto;
};

/*
 * globals
 *
 */

extern volatile struct ossw_ir_data g_ir_data;

/*
 * exported functions
 *
 */

int ossw_ir_check(uint32_t usecs, uint32_t ticks);

#endif /* ! _OSSW_IR_DEFS_H_ */

