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

#ifndef __UART_H__
#define __UART_H__

/* UART base addresses */
#define UART0_BASE		0xC0016000
#define UART1_BASE		0xC0016080
#define UART2_BASE		0xC0016800
#define UART3_BASE		0xC0016880

/* UART register offsets */
#define LCON			0x00
#define UCON			0x02
#define FCON			0x04
#define MCON			0x06
#define TRSTATUS		0x08
#define ESTATUS			0x0A
#define FSTATUS			0x0C
#define MSTATUS			0x0E
#define THB			0x10
#define RHB			0x12
#define BRD			0x14
#define TIMEOUTREG		0x16
#define INTSTATUSREG		0x18
#define UARTCLKENB		0x40
#define UARTCLKGEN		0x44

/* UART register bit definitions */

/* LCON Register */
#define SYNC_PENDCLR		7
#define SIR_MODE		6
#define PARITY_MODE		3
#define STOPBIT			2
#define WORD_LEN		0

/* UCON Register */
#define TX_INT			9
#define RX_INT			8
#define RX_TIMEOUT		7
#define RX_ERRSTATUS		6
#define LOOPBACK_MODE		5
#define SEND_BREAK		4
#define TRANS_MODE		2
#define RECEIVE_MODE		0

/* FCON Register */
#define TX_FIFO_TRIGGER		6
#define RX_FIFO_TRIGGER		4
#define TX_FIFO_RESET		2
#define RX_FIFO_RESET		1
#define FIFO_EN			0

/* MCON Register */
#define HALF_CH_ENB		7
#define SCRXENB			6
#define SCTXENB			5
#define AFC			4
#define DTR_ACTIVE		1
#define RTS_ACTIVE		0

/* FSTATUS Register */
#define RX_FIFO_ERROR		10
#define TX_FIFO_FULL		9
#define RX_FIFO_FULL		8
#define TX_FIFO_COUNT		4
#define RX_FIFO_COUNT		0

/* TRSTATUS */
#define TRANSMITTER_EMPTY	2
#define	TRANSMIT_BUFFER_EMPTY	1
#define RECEIVE_BUFFER_DATA_READY	0

/* UARTCLKENB */
#define UARTCLKGENENB		2

/* UARTCLKGEN */
#define UARTCLKDIV		4
#define UARTCLKSRCSEL		1

#endif /* __UART_H__ */
