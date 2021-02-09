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

#ifndef _OSSW_VERSION_H_
#define _OSSW_VERSION_H_

/*
 * exported functions
 *
 */

char* ossw_version_get_product_name(void);
char* ossw_version_get_company_name(void);
char* ossw_version_get_website(void);
char* ossw_version_get_firmware(void);
char* ossw_version_get_build_year(void);
char* ossw_version_get_build_date(void);
char* ossw_version_get_build_host(void);

#endif /* _OSSW_VERSION_H_ */




