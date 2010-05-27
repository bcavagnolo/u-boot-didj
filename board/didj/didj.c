/*
 * (C) Copyright 2010 cozybit, Inc.
 * Brian Cavagnolo, <brian@cozybit.com>
 *
 * (C) Copyright 2007 Leapfrog, Inc.
 * Andrey Yurovsky" <yurovsky@gmail.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/clkpwr.h>
#include <asm/arch/reg.h>
#include <asm/arch/gpio.h>
#include <asm/arch/timer.h>
#include <asm/arch/uart.h>

#if defined(CONFIG_SHOW_BOOT_PROGRESS)
void show_boot_progress(int progress)
{
    printf("Boot reached stage %d\n", progress);
}
#endif

/* Desired PLL1 frequency for SDRAM and UART */
#define PLL1_FREQ	147000000

/* UART clock divider calculated such that the default BRD of 1 corresponds to
 * a baud rate of 115200bps.  This is required by the serial driver.  Note that
 * we calculate the divider below with an extra bit of precision to ensure that
 * we round to the most suitable divider value.
 */
#define DEFAULT_BRD	1
#define UARTDIV		((((PLL1_FREQ<<1)/(115200*(DEFAULT_BRD + 1)*16)) + 1)>>1)

int board_init (void)
{

	unsigned long tmp;

	icache_enable();

	/* Didj uses PLL0 for the CPU clock at 393216000 Hz */
	REG32(PLLSETREG0) = PLL_REG(801, 55, 0);
	/* PLL1 (bus clock) 147000000 Hz */
	REG32(PLLSETREG1) = PLL_REG(196, 9, 2);

	/* set bus and cpu clock source and dividers */
	tmp = REG32(CLKMODEREG);
	tmp &= ~((0x3<<CLKSELCPU0)|
		 (0xF<<CLKDIVCPU0)|
		 (0xF<<CLKDIV2CPU0)|
		 (0x3<<CLKSELBCLK)|
		 (0xF<<CLKDIV1BCLK));
	tmp |= ((0<<CLKSELCPU0)|
		(0<<CLKDIVCPU0)|
		(2<<CLKDIV2CPU0)|
		(0<<CLKSELBCLK)|
		(2<<CLKDIV1BCLK));
	REG32(CLKMODEREG) = tmp;

	/* apply settings */
	BIT_SET(REG32(PWRMODE), CHGPLL);

	/* wait for PLLs to stabalize */
	while(IS_SET(REG32(PWRMODE), CHGPLL));

	/* timer runs on PLL0 divided down by 256 */
	REG32(CONFIG_SYS_TIMERBASE + TMRCLKGEN) |=
		((256-1)<<TCLKDIV)|(0<<TCLKSRCSEL);

	/* UART0 pins can either be a UART or GPIO.  We want UART.  For this we
	 * must configure GPIOA, pin 8 to be the UART TX, which is it's
	 * alternative function.
	 */
	tmp = REG32(GPIOAALTFN0);
	tmp &= ~(ALTFN0_PIN_MASK(8));
	tmp |= ALTFN0_PIN_CFG(8, GPIO_ALT1);
	REG32(GPIOAALTFN0) = tmp;

	/* UART0 runs on PLL1. */
	REG32(UART0_BASE + UARTCLKGEN) =
		((1<<UARTCLKSRCSEL)|((UARTDIV - 1)<<UARTCLKDIV));

	return 0;
}

int dram_init (void)
{
	return 0;
}
