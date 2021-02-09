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

/* implements */
#include <ossw_version.h>

/*
 * defines
 *
 */

#if !defined FIRMWARE_VERSION
#error "Please specify firmware version."
#endif

#if !defined BUILD_YEAR
#error "Please specify build year."
#endif

#if !defined BUILD_DATE
#error "Please specify build date."
#endif

#if !defined BUILD_HOST
#error "Please specify build host."
#endif

/*
 * types
 *
 */

struct ossw_version {

    char* product_name;
    char* company_name;
    char* website;
    char* firmware;
    char* build_year;
    char* build_date;
    char* build_host;

};

/*
 * globals
 *
 */

static struct ossw_version g_product = {

    /* product details */
    .product_name   = "OSSW",
    .company_name   = "binarysolo",
    .website        = "www.binarysolo.co.uk",

    /* version information */
    .firmware   = FIRMWARE_VERSION,

    /* build information */
    .build_year = BUILD_YEAR,
    .build_date = BUILD_DATE,
    .build_host = BUILD_HOST
};

/*
 * exported functions
 *
 */

char* 
ossw_version_get_product_name(void)
{
    return g_product.product_name;
}

char* 
ossw_version_get_company_name(void)
{
    return g_product.company_name;
}

char* 
ossw_version_get_website(void)
{
    return g_product.website;
}

char* 
ossw_version_get_firmware(void)
{
    return g_product.firmware;
}

char* 
ossw_version_get_build_year(void)
{
    return g_product.build_year;
}

char* 
ossw_version_get_build_date(void)
{
    return g_product.build_date;
}

char* 
ossw_version_get_build_host(void)
{
    return g_product.build_host;
}
