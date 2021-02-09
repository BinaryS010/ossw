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

/* device */
#include <ossw_clock.h>
#include <ossw_systick.h>
#include <ossw_timer.h>
#include <ossw_i2c.h>

/* system */
#include <ossw_bus.h>
#include <ossw_rgb.h>
#include <ossw_lcd.h>
#include <ossw_button.h>
#include <ossw_ir.h>
#include <ossw_delay.h>
#include <ossw_settings.h>
#include <ossw_sync.h>
#include <ossw_ui.h>
#include <ossw_version.h>

static inline void
device_init(void)
{
    /* init peripherals */
    ossw_clock_init();
    ossw_systick_init();
    ossw_timer_init();
    ossw_i2c_init();

    /* init system functions */
    ossw_settings_init();
    ossw_bus_init();
    ossw_rgb_init();
    ossw_sync_init();
    ossw_lcd_init();
    ossw_button_init();
    ossw_ir_init();
}

/*
 * exported functions
 *
 */
int
main(void)
{
    device_init();

    ossw_settings_load();
    ossw_bus_enable(ossw_settings_get_default_bus());

    ossw_ui_init();

    /*
     * main loop
     */
    while(1) {

        /*
         * update settings
         *
         */

        /* set RGB LPF */
        ossw_rgb_lpf_set_enable(ossw_settings_get_lpf_enable());

        /* set sync strip */
        ossw_sync_strip_set_enable(ossw_settings_get_sync_strip_enable());

        /* set LCD contrast */
        ossw_lcd_set_contrast(ossw_settings_get_lcd_contrast());

        /*
         * update UI
         *
         */

        ossw_ui_update();
        delay_ms(10);
    }
}
