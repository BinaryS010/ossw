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
#include <string.h>

/* implements */
#include <ossw_i2c.h>

/*
 * defines
 *
 */

#define PORT_WRCONFIG_PERIPHERAL_FUNCTION_C 0x02

#define I2C_CONTROL (1 << 7)
#define I2C_REGSEL  (1 << 6)

#define BUF_NUM     0x2

#define BUF_TX      0x0
#define BUF_RX      0x1

#define BUF_DONE    0x1

enum i2c_mode {
    I2C_MODE_READ,
    I2C_MODE_WRITE
};

static volatile struct i2c_data {

    uint8_t* buf;
    uint8_t  done;

    size_t   len;
    size_t   idx;

} i2c_buf[BUF_NUM];

static inline void
sercom_i2c_peripheral_init(void)
{
    /*
     * Enable SERCOM1 peripheral in
     * Power Manager
     */
    PM->APBCMASK.reg |= PM_APBCMASK_SERCOM1;
}

static inline void
sercom_i2c_clock_init(void)
{
    /* 
     * Configure SERCOM1_CORE with source of 
     * Generic Clock Generator 0 and enable 
     */
    GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(SERCOM1_GCLK_ID_CORE) |
      GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN(0);
 
    /* 
     * Configure SERCOM1_SLOW with source of 
     * Generic Clock Generator 0 and enable 
     */
    GCLK->CLKCTRL.reg = GCLK_CLKCTRL_ID(SERCOM1_GCLK_ID_SLOW) |
      GCLK_CLKCTRL_CLKEN | GCLK_CLKCTRL_GEN(0);
}

static inline void
sercom_i2c_pin_init(void)
{
    PORT->Group[0].WRCONFIG.reg = 
        PORT_WRCONFIG_HWSEL | 
        PORT_WRCONFIG_WRPINCFG | 
        PORT_WRCONFIG_WRPMUX | 
        PORT_WRCONFIG_PMUX(PORT_WRCONFIG_PERIPHERAL_FUNCTION_C) | 
        PORT_WRCONFIG_PMUXEN | 
        PORT_WRCONFIG_PINMASK((PORT_PA16C_SERCOM1_PAD0 >> 16) | (PORT_PA17C_SERCOM1_PAD1 >> 16));
}

static inline void
sercom_i2c_master_init(void)
{
    /* 
     * Configure SERCOM1 as I2C.
     *
     * NOTE: SERCOM_I2CM_CTRLA_SPEED = FAST_MODE (400KHz, default register = 0) so
     * no need to set this. SDA_HOLD 300-600ns, MODE I2C Master.
     */
    SERCOM1->I2CM.CTRLA.reg = SERCOM_I2CM_CTRLA_SDAHOLD(0x2) |
        SERCOM_I2CM_CTRLA_RUNSTDBY | SERCOM_I2CM_CTRLA_MODE_I2C_MASTER;

    /* enable smart mode */
    SERCOM1->I2CM.CTRLB.reg = SERCOM_I2CM_CTRLB_SMEN;

    /* sync busy */
    while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

    /* BAUDLOW is non-zero, and baud register is loaded */
    SERCOM1->I2CM.BAUD.reg = SERCOM_I2CM_BAUD_BAUD(220);

    /* sync busy */
    while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

    /* enable SERCOM1 peripheral by setting ENABLE to 1 */
    SERCOM1->I2CM.CTRLA.reg |= SERCOM_I2CM_CTRLA_ENABLE;

    /* SERCOM ENABLE sync busy */
    while((SERCOM1->I2CM.SYNCBUSY.reg & SERCOM_I2CM_SYNCBUSY_ENABLE));

    /* force bus into idle state */
    SERCOM1->I2CM.STATUS.bit.BUSSTATE = 0x1;

    /* sync busy */
    while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

    /* set interrupts bit, both master on bus and slave on bus enabled */
    SERCOM1->I2CM.INTENSET.reg = SERCOM_I2CM_INTENSET_MB | SERCOM_I2CM_INTENSET_SB;

    /* enable SERCOM1 interrupt handler */
	NVIC_EnableIRQ(SERCOM1_IRQn);
}

static void
sercom_i2c_transact(uint8_t addr, int mode)
{
    /* acknowledge is set as ACK signal by writing 0 in ACKACT bit */
    SERCOM1->I2CM.CTRLB.reg &= ~SERCOM_I2CM_CTRLB_ACKACT;
    while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

    if(I2C_MODE_WRITE == mode) {

        /* slave address with Write(0) */
        SERCOM1->I2CM.ADDR.reg = (addr << 1) | 0;

        while(!i2c_buf[BUF_TX].done);
    }

    if(I2C_MODE_READ == mode) {

        /* slave address with Read(1) */
        SERCOM1->I2CM.ADDR.reg = (addr << 1) | 1;

        while(!i2c_buf[BUF_RX].done);
    }
}

/*
 * I2C interrupt handler
 */
void
SERCOM1_Handler(void)
{
    /* Master on bus */
    if(SERCOM1->I2CM.INTFLAG.bit.MB){

        if(i2c_buf[BUF_TX].idx == i2c_buf[BUF_TX].len){

            /* after last byte send stop condition */
            SERCOM1->I2CM.CTRLB.bit.CMD = 0x3;
            while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

            i2c_buf[BUF_TX].done = BUF_DONE;

        } else {

            if(i2c_buf[BUF_TX].buf != NULL){

                /* send data and increment tx buffer */
                SERCOM1->I2CM.DATA.reg = i2c_buf[BUF_TX].buf[i2c_buf[BUF_TX].idx];
                i2c_buf[BUF_TX].idx++;

                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);
            }
        }
    }

    /* Slave on bus */
    if(SERCOM1->I2CM.INTFLAG.bit.SB){

        if(i2c_buf[BUF_RX].buf != NULL){

            if (i2c_buf[BUF_RX].idx == (i2c_buf[BUF_RX].len - 1)) {

                /* send NACK after reading last byte */
                SERCOM1->I2CM.CTRLB.reg |= SERCOM_I2CM_CTRLB_ACKACT;
                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

                SERCOM1->I2CM.CTRLB.bit.CMD = 0x3;
                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

                i2c_buf[BUF_RX].buf[i2c_buf[BUF_RX].idx] = SERCOM1->I2CM.DATA.reg;
                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

                i2c_buf[BUF_RX].done = BUF_DONE;

            } else {

                SERCOM1->I2CM.CTRLB.reg &= ~SERCOM_I2CM_CTRLB_ACKACT;
                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

                i2c_buf[BUF_RX].buf[i2c_buf[BUF_RX].idx] = SERCOM1->I2CM.DATA.reg;
                i2c_buf[BUF_RX].idx++;
                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);

                /* sending ACK after reading each byte */
                SERCOM1->I2CM.CTRLB.bit.CMD = 0x2;
                while(SERCOM1->I2CM.SYNCBUSY.bit.SYSOP);
            }
        }
    }
}

void 
ossw_i2c_init(void)
{
    /* initialize sercom */
    sercom_i2c_peripheral_init();
    sercom_i2c_clock_init();
    sercom_i2c_pin_init();

    /* configure sercom */
    sercom_i2c_master_init();

    /* initialize buffers */
    (void) memset((void*) i2c_buf, 0, sizeof(i2c_buf));
}

void
ossw_i2c_write(uint8_t addr, uint8_t* cmd, size_t cmd_len)
{
    if((NULL == cmd) || (cmd_len == 0)) {
        return;
    }

    i2c_buf[BUF_TX].buf = cmd;
    i2c_buf[BUF_TX].len = cmd_len;

    i2c_buf[BUF_RX].buf = NULL;
    i2c_buf[BUF_RX].len = 0;

    sercom_i2c_transact(addr, I2C_MODE_WRITE);

    /* clear buffers */
    (void) memset((void*) i2c_buf, 0, sizeof(i2c_buf));
}

void
ossw_i2c_read(uint8_t addr, uint8_t* res, size_t res_len)
{
    unsigned int i = 0;

    if((NULL == res) || (res_len == 0)) {
        return;
    }

    i2c_buf[BUF_TX].buf = NULL;
    i2c_buf[BUF_TX].len = 0;

    i2c_buf[BUF_RX].buf = res;
    i2c_buf[BUF_RX].len = res_len;

    sercom_i2c_transact(addr, I2C_MODE_READ);

    /* copy data to output buffer */
    while(i < res_len) {
        res[i] = i2c_buf[BUF_RX].buf[i];
        i++;
    }

    /* clear buffers */
    (void) memset((void*) i2c_buf, 0, sizeof(i2c_buf));
}
