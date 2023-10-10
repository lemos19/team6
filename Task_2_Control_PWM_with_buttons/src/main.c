#include "s32k144.h"
#include "stdio.h"
#include "CLOCK.h"
#include "FTM.h"
#include "GPIO.h"
#include "stdbool.h"
#include "LPUART.h"
volatile uint32_t Value = 1000;
volatile bool State = false;
volatile uint8_t DutyCycleValue = 5;
char uartStr[50];
//void PORTC_IRQHandler(void)
//{
///*******************	check button PTC12 **************/
//	if ((PORTC->PCR[12] & (1 << 24)))
//	{
//		PORTC->PCR[12] |= (1 << 24);
//		if (DutyCycleValue == 10){}
//		else
//		{
//			Value += 200;
//			FTM0->C1V = Value;
//			DutyCycleValue++;
//		}
//	}
///*******************	check button PTC13 **************/
//	if ((PORTC->PCR[13] & (1 << 24)))
//	{
//		PORTC->PCR[13] |= (1 << 24);
//		if (DutyCycleValue == 0){}
//		else
//		{
//			Value -= 200;
//			FTM0->C1V = Value;
//			DutyCycleValue--;
//		}
//	}
//
///*******************	check button PTC14 **************/
//	if ((PORTC->PCR[15] & (1 << 24)))
//	{
//		PORTC->PCR[15] |= (1 << 24);
//		State = !State;
//		if (State)
//		{
//			FTM0->SC &= ~(1u << 0);          /* PS = 1  */
//		}
//		else
//		{
//			FTM0->SC |= (1u << 0);          /* PS = 2  */
//		}
//	}
//	sprintf(uartStr, "Duty Cycle: %d\n", (int)DutyCycleValue);
//	LPUART_sent_string(uartStr);
//}

void PORTC_IRQHandler(void)
{
/*******************	check button PTC12 **************/
	if ((PORTC->PCR[12] & (1 << 24)))
	{
		PORTC->PCR[12] |= (1 << 24);
		if (Value < 2000)
		{
			Value += 200;
			FTM0->C1V = Value;
		}
	}
/*******************	check button PTC13 **************/
	if ((PORTC->PCR[13] & (1 << 24)))
	{
		PORTC->PCR[13] |= (1 << 24);
		if (Value > 0)
		{
			Value -= 200;
			FTM0->C1V = Value;
		}
	}

/*******************	check button PTC14 **************/
	if ((PORTC->PCR[15] & (1 << 24)))
	{
		PORTC->PCR[15] |= (1 << 24);
		State = !State;
		if (State)
		{
			FTM0->SC &= ~(1u << 0);          /* PS = 1  */
		}
		else
		{
			FTM0->SC |= (1u << 0);          /* PS = 2  */
		}
	}
	sprintf(uartStr, "Duty Cycle: %d\n", (int)Value/200);
	LPUART_sent_string(uartStr);
}

int main(void)
{
	SOSC_Init_8MHz();
	Button_Init();
	FTM_Config();
	FTM0_CH1_PWM_init();
	PORT_init();
	LPUART1_Config();
	while (1)
	{

	}
}
