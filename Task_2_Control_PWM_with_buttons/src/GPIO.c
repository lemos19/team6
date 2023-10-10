/*
 * GPIO.c
 *
 *  Created on: 6 thg 10, 2023
 *      Author: DAT
 */
#include "GPIO.h"

void Button_Init(void)
{
	NVIC->ISER[1] |= (1 << (61 % 32));
	// Clock
	PCC->PCC_PORTC |= (1u << 30);
	// Set pin as GPIO
	PORTC->PCR[12] |= (1u << 8u);
	PORTC->PCR[13] |= (1u << 8u);
	PORTC->PCR[15] |= (1u << 8u);
	// Set pin as input
	GPIOC->PDDR &= ~(1u << 12);
	GPIOC->PDDR &= ~(1u << 13);
	GPIOC->PDDR &= ~(1u << 15);
	// Pull Enable
	PORTC->PCR[12] |= (1 << 1u);
	PORTC->PCR[13] |= (1 << 1u);
	PORTC->PCR[15] |= (1 << 1u);
	// Pull Select (pull up)
	PORTC->PCR[12] |= (1 << 0u);
	PORTC->PCR[13] |= (1 << 0u);
	PORTC->PCR[15] |= (1 << 0u);
	// Set interrupt rising-edge
	PORTC->PCR[12] |= (9u << 16u);
	PORTC->PCR[13] |= (9u << 16u);
	PORTC->PCR[15] |= (9u << 16u);
}

void Led_Init(void)
{
	PCC->PCC_PORTD |= (1 << 30); // enable clock port D
	// set pin as GPIO
	PORTD->PCR[0] |= (1u << 8u);
	PORTD->PCR[15] |= (1u << 8u);
	PORTD->PCR[16] |= (1u << 8u);
	// set pin as output
	GPIOD->PDDR |= (1 << 0u);
	GPIOD->PDDR |= (1 << 15u);
	GPIOD->PDDR |= (1 << 16u);
	// turn off all led
	GPIOD->PDOR |= (1 << 0u) | (1 << 15u) | (1 << 16u);
}
