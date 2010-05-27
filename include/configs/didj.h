/*
 * (C) Copyright 2010 cozybit, Inc.
 * Brian Cavagnolo <brian@cozybit.com>
 *
 * (C) Copyright 2007 Leapfrog, Inc.
 * Kosta Demirev, kdemirev@yahoo.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <asm/arch/uart.h>
#include <asm/arch/timer.h>

#define CONFIG_ARM926EJS

/* didj has minimal support for now, so turn lots of stuff off */
#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_SKIP_RELOCATE_UBOOT
#define CONFIG_SKIP_LOWLEVEL_INIT

/* memory layout */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM_1			0x00000000
#define PHYS_SDRAM_1_SIZE		0x02000000
#define CONFIG_SYS_GBL_DATA_SIZE	128
#define CONFIG_ENV_SIZE			8192
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 128 * 1024)
#define CONFIG_STACKSIZE		(128 * 1024)
#define CONFIG_TEXT_BASE		0x00100000
#define CONFIG_SYS_LOAD_ADDR		0x00200000

/* timer and clock set up */
#define CONFIG_SYS_HZ			(384000000/256)
#define CONFIG_SYS_TIMERBASE		TIMER0_BASE

/* serial port configuration */
#define CONFIG_POLLUX_SERIAL
#define CONFIG_CONSOLE_UART_BASE	UART0_BASE
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/* console/printing setup */
#define CONFIG_SYS_PROMPT "=> "
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_PBSIZE \
	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16

/* SUBJECT TO AUDIT */

#define CONFIG_PL011_CLOCK	24000000

#endif	/* __CONFIG_H */
