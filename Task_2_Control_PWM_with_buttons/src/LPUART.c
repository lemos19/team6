/*
 * LPUART.c
 *
 *  Created on: 6 thg 10, 2023
 *      Author: DAT
 */
#include "LPUART.h"
void LPUART1_Config(void)
{
	// 1. Setting Tx/Rx pin
	PCC->PCC_PORTC |= (1u << 30);
	PORTC->PCR[6] |= (2u << 8);		// PTD13	LPUART1_RX		ALT2
	PORTC->PCR[7] |= (2u << 8);		// PTD14	LPUART1_TX		ALT2

	// 2. Select source LPUART
	SCG->FIRCDIV |= (2u << 8);			//FIRC div 2 = 24Mhz
	PCC->PCC_LPUART1 |= (3u << 24);		//Clock Source Select FIRC_DIV2
	PCC->PCC_LPUART1 |= (1u << 30);		//Enable clock module LPUART1

	// 3. Setting baud rate
	LPUART1->BAUD |= (15u << 24);
	LPUART1->BAUD |= 156u;			// Baud 115200


	//4. Setting Frame
	LPUART1->BAUD &= ~(1u << 13);	// 1 bit Stop
	LPUART1->CTRL &= ~(1u << 4);	// 8 bit Data
	LPUART1->CTRL &= ~(1u << 1);	// no parity

	// 5. Enable transmitter & receiver
	LPUART1->CTRL |= (1u << 18);		// Receiver enabled.
	LPUART1->CTRL |= (1u << 19);		//Transmitter enabled.
}

void LPUART_sent_char(uint8_t data)
{
	while(!(LPUART1->STAT & (1u << 23)));
	LPUART1->DATA = data;
}

void LPUART_sent_string(char str[])
{
	uint8_t i = 0;
	while (str[i] != '\0')
	{
		LPUART_sent_char(str[i]);
		i++;
	}
}

