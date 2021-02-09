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

#ifndef _OSSW_BUTTON_H_
#define _OSSW_BUTTON_H_

/*
 * enums
 *
 */

enum ossw_buttons {

    OSSW_BUTTON_DOWN    = (1 << 0),
    OSSW_BUTTON_UP      = (1 << 1),
    OSSW_BUTTON_ACTION  = (1 << 2),
    OSSW_BUTTON_LEFT    = (1 << 3),
    OSSW_BUTTON_RIGHT   = (1 << 4)
};

/*
 * exported functions
 *
 */

void ossw_button_init(void);

int ossw_button_read(uint8_t *button);

#endif /* ! _OSSW_BUTTON_H_ */
