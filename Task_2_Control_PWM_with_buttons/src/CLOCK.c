/*
 * CLOCK.c
 *
 *  Created on: 6 thg 10, 2023
 *      Author: DAT
 */
#include "CLOCK.h"

void SOSC_Init_8MHz(void)
{
	SCG->SOSCCSR = 0;					//SOSCEN=0: Disable oscillator
	SCG->SOSCDIV |= ((1<<0)|(1<<8));	//SOSCDIV1 & SOSCDIV2 =1: divide by 1
	SCG->SOSCCFG |= (1u<<2);					//EREFS=1: Input is external XTAL
	SCG->SOSCCFG |= (1u<<3);					//HGO=1: High-gain operator
	SCG->SOSCCFG |= (3u<<4);					//Range=3: High freq

	while(SCG->SOSCCSR & (1u<<23));			//Ensure SOSCCSR unlocked
	SCG->SOSCCSR |= (1u<<0);				//SOSCEN=1: Enable oscillator
	while(!(SCG->SOSCCSR & (1u<<24)));		//Wait for sys OSC clk valid
}

void SPLL_Config_16MHz(void)
{
	while(SCG->SPLLCSR & (1u<<23));			//Ensure SPLLCSR unlocked
	SCG->SPLLCSR &= ~(uint32_t)(1<<0);		//SPLLEN=0: SPLL is disabled

	SCG->SPLLCFG &=~(uint32_t)(1<<0);		//Clock source: System OSC (SOSC)
	SCG->SPLLCFG |= (4u<<8);				//PREDIV = 5
	SCG->SPLLCFG |= (4u<<16);				//MULT = 20
				/* div 5 and multi 20 =  8 * 20 / 5 = 32*/

	SCG->SPLLDIV |= ((2u<<0)|(2u<<8));  // SPLLDIV1 & SPLLDIV2 divide by 2
	while(SCG->SPLLCSR & (1u<<23));			//Ensure SPLLCSR unlocked
	SCG->SPLLCSR |= (1u<<0);				//SPLLEN=1:    Enable SPLL
	while(!(SCG->SPLLCSR & (1u<<24)));		//Wait for SPLL valid
}

