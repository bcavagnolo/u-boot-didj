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

#include <common.h>
#include <asm/arch/reg.h>
#include <asm/arch/uart.h>

#ifndef CONFIG_CONSOLE_UART_BASE
#error "Please define CONFIG_CONSOLE_UART_BASE to a suitable UARTx_BASE"
#endif
#define UART_BASE CONFIG_CONSOLE_UART_BASE

DECLARE_GLOBAL_DATA_PTR;

#define DEFAULT_BRD	1
void serial_setbrg (void)
{
	int baudrate, brd;

	if ((baudrate = gd->baudrate) <= 0)
		baudrate = CONFIG_BAUDRATE;

	/* we expect that the board-specific code set up the clock source such
	 * that a BRD of 1 corresponds to a baudrate of 115200 bps.  We use
	 * this fact to calculate the BRD for any baudrate.  We add one bit of
	 * precision to the division so we can round to the best BRD.
	 */
	brd = ((((115200 << 1)*(DEFAULT_BRD + 1)/baudrate) + 1) >> 1) - 1;
	REG16(UART_BASE + BRD) = brd;
}

int serial_init (void)
{
	/* expect that board-specific init has setup clock source */

	/* disable UART clock */
	REG32(UART_BASE + UARTCLKENB) &= ~(1<<UARTCLKGENENB);

	/* clear IRQ pending, set 8 bit word length */
	REG16(UART_BASE + LCON) = (1<<SYNC_PENDCLR)|(3<<WORD_LEN);

	/* enable polling/IRQ transmit and receive */
	REG16(UART_BASE + UCON) = (1<<TRANS_MODE)|(1<<RECEIVE_MODE);

	/* reset the FIFOs */
	REG16(UART_BASE + FCON) =
		(1<<TX_FIFO_RESET)|(1<<RX_FIFO_RESET);

	/* enable TX */
	REG16(UART_BASE + MCON) = (1<<SCRXENB);

	/* set the baud rate */
	serial_setbrg();

	/* enable UART clock */
	REG32(UART_BASE + UARTCLKENB) |= (1<<UARTCLKGENENB);

	return 0;
}

void serial_putc (const char c)
{
	u16 status, ready_mask;

	ready_mask = (1<<TRANSMITTER_EMPTY)|(1<<TRANSMIT_BUFFER_EMPTY);
	if(c == '\n')
		serial_putc('\r');

	while(1) { /* wait for transmitter to be ready */
		status = REG16(UART_BASE + TRSTATUS);
		if(status & ready_mask)
			break;
	}
	/* transmit */
	REG8(UART_BASE + THB) = c;
}

void serial_puts (const char *s)
{
	while (*s) {
		serial_putc (*s++);
	}
}

int serial_tstc (void)
{
	return (REG16(UART_BASE + FSTATUS) & 0xF);
}

int serial_getc (void)
{
	while(!serial_tstc());
	return REG16(UART_BASE + RHB);
}
