/* (C) Copyright 2010 cozybit, Inc.
 * Brian Cavagnolo <brian@cozybit.com>
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

#ifndef __CLKPWR_H__
#define __CLKPWR_H__

/* Clock and Power Control Registers */
#define CLKPWR_BASE		0xC000F000
#define CLKMODEREG		(CLKPWR_BASE + 0x000)
#define PLLSETREG0		(CLKPWR_BASE + 0x004)
#define PLLSETREG1		(CLKPWR_BASE + 0x008)
#define GPIOWAKEUPENB		(CLKPWR_BASE + 0x040)
#define RTCWAKEUPENB		(CLKPWR_BASE + 0x044)
#define GPIOWAKEUPRISEENB	(CLKPWR_BASE + 0x048)
#define GPIOWAKEUPFALLENB	(CLKPWR_BASE + 0x04C)
#define GPIOPEND		(CLKPWR_BASE + 0x050)
#define INTPENDSPAD		(CLKPWR_BASE + 0x058)
#define PWRRSTSTATUS		(CLKPWR_BASE + 0x05C)
#define INTENB			(CLKPWR_BASE + 0x060)
#define PWRMODE			(CLKPWR_BASE + 0x07C)
#define PADSTRENGTHGPIOAL	(CLKPWR_BASE + 0x100)
#define PADSTRENGTHGPIOAH	(CLKPWR_BASE + 0x104)
#define PADSTRENGTHGPIOBL	(CLKPWR_BASE + 0x108)
#define PADSTRENGTHGPIOBH	(CLKPWR_BASE + 0x10C)
#define PADSTRENGTHGPIOCL	(CLKPWR_BASE + 0x110)
#define PADSTRENGTHGPIOCH	(CLKPWR_BASE + 0x114)
#define PADSTRENGTHBUS		(CLKPWR_BASE + 0x118)

/* Clock Mode Register (CLKMODEREG) */
#define PLLPWDN1	30
#define CLKSELBCLK	24
#define CLKDIV1BCLK	20
#define CLKDIV2CPU0	6
#define CLKSELCPU0	4
#define CLKDIVCPU0	0

/* PLL0/PLL1 Setting Register (PLLSETREG0/PLLSETREG1) */
#define PDIV		18
#define MDIV		8
#define SDIV		0

/* convenience macro for setting PLL */
#define PLL_REG(m, p, s) \
	(((unsigned int)(m) << MDIV) | \
	 ((unsigned int)(p) << PDIV) | \
	 ((unsigned int)(s) << SDIV))

/* Power Mode Control Register (PWRMODE) */
#define CHGPLL		15
#define GPIOSWRSTENB	13
#define SWRST		12
#define LASTPWRMODE	4
#define CURPWRMODE	0

/* Interrupt Pending & Scratch Pad Register (INTPENDSPAD) */
#define BATFW		14
#define GPIORESETW	13
#define WATCHDOGRSTW	12
#define POWERONRSTW	11

#endif /* __CLKPWR_H__ */
