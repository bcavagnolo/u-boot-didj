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

#ifndef __GPIO_H__
#define __GPIO_H__

/* GPIO registers */
#define GPIO_BASE		0xC000A000

#define GPIOAOUT		(GPIO_BASE + 0x00)
#define GPIOAOUTENB		(GPIO_BASE + 0x04)
#define GPIOADETMODE0		(GPIO_BASE + 0x08)
#define GPIOADETMODE1		(GPIO_BASE + 0x0C)
#define GPIOAINTENB		(GPIO_BASE + 0x10)
#define GPIOADET		(GPIO_BASE + 0x14)
#define GPIOAPAD		(GPIO_BASE + 0x18)
#define GPIOAPUENB		(GPIO_BASE + 0x1C)
#define GPIOAALTFN0		(GPIO_BASE + 0x20)
#define GPIOAALTFN1		(GPIO_BASE + 0x24)

#define GPIOBOUT		(GPIO_BASE + 0x40)
#define GPIOBOUTENB		(GPIO_BASE + 0x44)
#define GPIOBDETMODE0		(GPIO_BASE + 0x48)
#define GPIOBDETMODE1		(GPIO_BASE + 0x4C)
#define GPIOBINTENB		(GPIO_BASE + 0x50)
#define GPIOBDET		(GPIO_BASE + 0x54)
#define GPIOBPAD		(GPIO_BASE + 0x58)
#define GPIOBPUENB		(GPIO_BASE + 0x5C)
#define GPIOBALTFN0		(GPIO_BASE + 0x60)
#define GPIOBALTFN1		(GPIO_BASE + 0x64)

#define GPIOCOUT		(GPIO_BASE + 0x80)
#define GPIOCOUTENB		(GPIO_BASE + 0x84)
#define GPIOCDETMODE0		(GPIO_BASE + 0x88)
#define GPIOCDETMODE1		(GPIO_BASE + 0x8C)
#define GPIOCINTENB		(GPIO_BASE + 0x90)
#define GPIOCDET		(GPIO_BASE + 0x94)
#define GPIOCPAD		(GPIO_BASE + 0x98)
#define GPIOCPUENB		(GPIO_BASE + 0x9C)
#define GPIOCALTFN0		(GPIO_BASE + 0xA0)
#define GPIOCALTFN1		(GPIO_BASE + 0xA4)

/* GPIO Alive Registers */
#define GPIO_ALIVE_BASE		0xC0019000
#define ALIVEPWRGATEREG		(GPIO_ALIVE_BASE + 0x00)
#define ALIVEGPIORSTREG		(GPIO_ALIVE_BASE + 0x04)
#define ALIVEGPIOSETREG		(GPIO_ALIVE_BASE + 0x08)
#define ALIVEGPIOREADREG	(GPIO_ALIVE_BASE + 0x0C)
#define ALIVESCRATCHRSTREG	(GPIO_ALIVE_BASE + 0x10)
#define ALIVESCRATCHSETREG	(GPIO_ALIVE_BASE + 0x14)
#define ALIVESCRATCHREADREG	(GPIO_ALIVE_BASE + 0x18)

/* Alive GPIO Gate Register (ALIVEGPIOGATEREG) */
#define NPOWERGATING		0

/* Alive GPIO Register bit names
 * same for ALIVEGPIORSTREG, ALIVEGPIOSETREG and ALIVEGPIOREADREG
 */
#define VDDPWRONSET		7

/* Alive GPIO Read Register (ALIVEGPIOREADREG) */
#define VDDPWRTOGGLE		8

/* Current settings */
#define GPIO_CURRENT_BASE	0xC000F100
#define GPIOAPADSTRENGTH_L	(GPIO_CURRENT_BASE + 0x00)
#define GPIOAPADSTRENGTH_H	(GPIO_CURRENT_BASE + 0x04)
#define GPIOAPBDSTRENGTH_L	(GPIO_CURRENT_BASE + 0x08)
#define GPIOAPBDSTRENGTH_H	(GPIO_CURRENT_BASE + 0x0C)
#define GPIOAPCDSTRENGTH_L	(GPIO_CURRENT_BASE + 0x10)
#define GPIOAPCDSTRENGTH_H	(GPIO_CURRENT_BASE + 0x14)

/* Convenience macros for generating pin configurations for ALTFNn registers */
#define ALTFN0_PIN_CFG(pin, cfg) ((cfg)<<((pin)*2))
#define ALTFN0_PIN_MASK(pin) ALTFN0_PIN_CFG(pin, 0x3)
#define ALTFN1_PIN_CFG(pin, cfg) ((cfg)<<((pin)*2-32))
#define ALTFN1_PIN_MASK(pin) ALTFN1_PIN_CFG(pin, 0x3)


enum gpio_port {
	GPIO_PORT_A = 0,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_ALV,
};

/* Each pin can take one of three different functions */
enum gpio_function {
	GPIO_GPIOFN = 0,
	GPIO_ALT1,
	GPIO_ALT2,
	GPIO_RESERVED,
};

/* Each port has 32 pins */
enum gpio_pin {
	GPIO_PIN0 = 0, GPIO_PIN1, GPIO_PIN2, GPIO_PIN3, GPIO_PIN4, GPIO_PIN5,
	GPIO_PIN6, GPIO_PIN7, GPIO_PIN8, GPIO_PIN9, GPIO_PIN10, GPIO_PIN11,
	GPIO_PIN12, GPIO_PIN13, GPIO_PIN14, GPIO_PIN15, GPIO_PIN16, GPIO_PIN17,
	GPIO_PIN18, GPIO_PIN19, GPIO_PIN20, GPIO_PIN21, GPIO_PIN22, GPIO_PIN23,
	GPIO_PIN24, GPIO_PIN25, GPIO_PIN26, GPIO_PIN27, GPIO_PIN28, GPIO_PIN29,
	GPIO_PIN30, GPIO_PIN31,
};

/* Each pin can interrupt on one of four different events */
enum gpio_interrupt_mode {
	GPIO_IMODE_LOW_LEVEL		= 0,
	GPIO_IMODE_HIGH_LEVEL		= 1,
	GPIO_IMODE_FALLING_EDGE		= 2,
	GPIO_IMODE_RISING_EDGE		= 3,
};

/* Each pin can drive with configurable current */
enum gpio_current {
	GPIO_CURRENT_2MA		= 0,
	GPIO_CURRENT_4MA		= 1,
	GPIO_CURRENT_6MA		= 2,
	GPIO_CURRENT_8MA		= 3,
};

#endif /* __GPIO_H__ */
