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

#ifndef __TIMER_H__
#define __TIMER_H__

/* Timer base addresses */
#define TIMER0_BASE	0xC0001800
#define TIMER1_BASE	0xC0001880
#define TIMER2_BASE	0xC0001900
#define TIMER3_BASE	0xC0001980
#define TIMER4_BASE	0xC0001A00

/* Timer register offsets */
#define TMRCOUNT	0x00
#define TMRMATCH	0x04
#define TMRCONTROL	0x08
#define TMRCLKENB	0x40
#define TMRCLKGEN	0x44

/* Timer Control Register n (TMRCONTROLn) */
#define LDCNT		6
#define INTPEND		5
#define TINTENB		4
#define RUN		3
#define WDENB		2
#define SETCLK		0

/* Timer Clock Generation Enable Register n (TMRCLKENBn) */
#define TCLKMODE	3
#define TCLKGENENB	2

/* Timer Clock Generation Control Register n (TMRCLKGENn) */
#define TCLKDIV		4
#define TCLKSRCSEL	1

#endif /* __TIMER_H__ */
