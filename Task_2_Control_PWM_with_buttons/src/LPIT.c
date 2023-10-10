/*
 * LPIT.c
 *
 *  Created on: 6 thg 10, 2023
 *      Author: DAT
 */
#include "LPIT.h"

void LPIT_Init(void)
{
	SCG->FIRCDIV |= (2u << 8);				   // FIRC div 2 = 24Mhz
	PCC->PCC_LPIT |= ((1 << 30) | (3u << 24)); // Enable clock LPIT
	LPIT->MCR |= (1 << 0);					   // Enable peripheral clock to timers
	LPIT->MCR |= (1 << 3);					   // Debug mode

	// Config channel 0
	NVIC->ISER[1] = (1u << (48 % 32));		   // Setting NVIC
	LPIT->MIER |= (1 << 0);					   // Timer Interrupt Enable
	LPIT->TVAL0 = 24000000;					   // Set Timer Value
	LPIT->TCTRL0 &= ~(3u << 2u);			   // 32-bit Periodic Counter
	LPIT->TCTRL0 |= (1 << 0);				   // Enables Timer Channel 0

	// Config channel 1
	NVIC->ISER[1] = (1u << (49 % 32));		   // Setting NVIC
	LPIT->MIER |= (1 << 1);					   // Timer Interrupt Enable
	LPIT->TVAL1 = 12000000;					   // Set Timer Value
	LPIT->TCTRL1 &= ~(3u << 2u);			   // 32-bit Periodic Counter
	LPIT->TCTRL1 |= (1 << 0);				   // Enables Timer Channel 1
}

