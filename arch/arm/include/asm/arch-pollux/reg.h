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

#ifndef __REG_H__
#define __REG_H__

/* register access and manipulation helper macros */
#define REG8(addr)  (*((volatile unsigned char *)(addr)))
#define REG16(addr) (*((volatile unsigned short *)(addr)))
#define REG32(addr) (*((volatile unsigned long *)(addr)))

#define BIT_SET(v,b)    ((v) |= (1<<(b)))
#define BIT_CLR(v,b)    ((v) &= ~(1<<(b)))
#define IS_SET(v,b)     ((v) & (1<<(b)))
#define IS_CLR(v,b)     !((v) & (1<<(b)))

#endif /* __REG_H__ */
