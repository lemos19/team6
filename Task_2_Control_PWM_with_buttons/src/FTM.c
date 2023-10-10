/*
 * FTM.c
 *
 *  Created on: 6 thg 10, 2023
 *      Author: DAT
 */

#include "FTM.h"
#include "CLOCK.h"

void PORT_init(void)
{
	PCC->PCC_PORTD |= (1u << 30);
	PORTD->PCR[16] |= (2u << 8u);
}

void FTM_Config(void)
{
	PCC->PCC_FTM0 &= ~(1u << 30);
	PCC->PCC_FTM0 |= (1u << 24) | (1u << 30);        //choose SOSC clock source

    FTM0->MODE |= (1u << 2);        /* Write protect to registers disabled */
    FTM0->SC |= (1u << 17);        	/* Enable PWM channel 1 output */
    FTM0->SC |= (1u << 0);          /* PS = 2  */
    FTM0->COMBINE = 0x00000000;	    /* FTM mode settings used: DECAPENx, MCOMBINEx, COMBINEx=0 */
    FTM0->POL = 0x00000000;    	    /* Polarity for all channels is active high (default) */
    FTM0->MOD = 2000-1;				/* clock out = clockin /(Prescale * modulo) */
    FTM0->SC |= (3u << 3);			/* Clock Source Selection: External clock */
}

void FTM0_CH1_PWM_init(void)
{
	/* FTM0, Channel 1 in PWM Mode */
	FTM0->C1SC |= (1u << 3) | (1u << 5);	/* FTM0 ch1: edge-aligned PWM, low true pulses 	*/
											/* MSB:MSA (chan Mode Select)=0b10, Edge Align PWM	*/
	FTM0->C1V = 1000;						/* FTM0 ch1 compare value (50% duty cycle) */
}
