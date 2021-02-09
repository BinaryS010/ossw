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

#ifndef _OSSW_EEPROM_H_
#define _OSSW_EEPROM_H_

/*
 * includes
 *
 */

#include <stdlib.h>

/*
 * exported functions
 *
 */

int ossw_eeprom_read(uint16_t addr, uint8_t* data, size_t data_len);

int ossw_eeprom_write(uint16_t addr, uint8_t* data, size_t data_len);

#endif /* ! _OSSW_EEPROM_H_ */
