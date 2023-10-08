#include "MacroAndFuntion.h"
#include "LPIT_Type.h"
#include "LPUART.h"
#include <string.h>
#include "LPSPI_Type.h"
#include "ledMax7219.h"
#include "SIM_Type.h"
#include "string.h"

#define CLEAR_FLAG_LPIT_CHANEL(chanel) 	LPIT->MSR.Fields.TIF##chanel = 1;
#define ENABLE_LPIT_CHANEL(chanel)		LPIT->TCTRL##chanel.Fields.T_EN = Enable;
#define DISABLE_LPIT_CHANEL(chanel)		LPIT->TCTRL##chanel.Fields.T_EN = Disable;
#define TOGGLE_STATUS_LPIT_CHANEL0		LPIT->TCTRL0.Fields.T_EN ^= 1;
#define STATUS_LPIT_CHANEL0				LPIT->TCTRL0.Fields.T_EN
#define FLAG_FROM_PTC(pin) 				PORTC->PORT_PCR[pin].Fields.ISF == 1
#define CLEAR_FLAG_PTC(pin) 			PORTC->PORT_PCR[pin].Fields.ISF = 1;
#define SWITCH_LED(led)				\
	GPIOD->GPIO_PSOR = 0x18001;		\
	GPIOD->GPIO_PCOR = (1u<<led);

static char buffer[10];
static int8_t buffer_index = 0;
void PORTC_IRQHandler(void);
void LPUART1_RxTx_IRQHandler(void);
void LPIT0_Ch0_IRQHandler(void);
void LPIT0_Ch1_IRQHandler(void);
void LPIT0_Ch2_IRQHandler(void);
typedef enum
{
	Red_led = 15,
	Green_led = 16,
	Blu_led = 0
} LED;
static LED switch_led = Red_led;
static uint8_t counter = 10;
static char arr[] = "hello world!!\n";
static uint32_t timeValue = 125000;
int main(void)
{
	initializeGPIOandSystick();
	Config_SOSC_CLK();					  // 8Mhz
	Config_SPLL_CLK(SOSC, Div1, Multi20); // 80Mhz
	Config_RCCR(SPLL, 0 /*div core by 1*/, 1 /*div bus by 2*/, 2 /*div slow by 3*/);
	SCG_Asyn_Peripheral_Sources(SOSCDIV2_CLK, Div_By_64); // 125000 Hz
	SCG_Asyn_Peripheral_Sources(FIRCDIV2_CLK, Div_By_1); // 48Mhz

	Config_LPIT_Chanel
	(
		LPIT_Chanel0,
		SOSCDIV2_CLK, /*chose clock source*/
		Enable,		  /*enable interrupt*/
		timeValue	  /*reset value*/
	);
	Config_LPIT_Chanel(LPIT_Chanel1, SOSCDIV2_CLK, Enable, (timeValue/2));
	Config_LPIT_Chanel(LPIT_Chanel2, SOSCDIV2_CLK, Enable, timeValue);

	Config_LPUART_Chanel
	(
		CHN1,
		FIRCDIV2_CLK,
		500, /*baurate = baud clock /(oversameling*500)----baurate: 9600|baud clock: 48Mh|oversameling: 10*/
		ratio10,
		One_Stop_Bit,
		_8BitData,
		Disable /*disable parity bit*/
	);

	Enable_LPUART_Interrupts(CHN1, Receiver_Interrupt);
	NVIC_Config_Interrup_Modul(Lpuart1, Enable);
	Enable_LPUART_Pin(Chn1_Tx_PTC7);
	Enable_LPUART_Pin(Chn1_Rx_PTC6);
	Enable_ReceiveData_Chanel(CHN1);

	Send_Message(&arr[0]);
	ENABLE_LPIT_CHANEL(0)
	ENABLE_LPIT_CHANEL(1)
	while (1)
	{
		switch (switch_led)
		{
		case Red_led:
			SWITCH_LED(Red_led)
			break;	
		case Green_led:
			SWITCH_LED(Green_led)
			break;
		case Blu_led:
			SWITCH_LED(Blu_led)
			break;
		}
	}
}
void LPIT0_Ch0_IRQHandler(void)
{
	CLEAR_FLAG_LPIT_CHANEL(0)
	if (switch_led == Red_led)
	{
		switch_led = Green_led;
	}
	else if (switch_led == Green_led)
	{
		switch_led = Blu_led;
	}
	else
	{
		switch_led = Red_led;
	}
	
}
void LPIT0_Ch1_IRQHandler(void)
{
	CLEAR_FLAG_LPIT_CHANEL(1)
	
}
void LPIT0_Ch2_IRQHandler(void)
{
	CLEAR_FLAG_LPIT_CHANEL(2)

}
void PORTC_IRQHandler(void)
{
	if (FLAG_FROM_PTC(12))
	{
		CLEAR_FLAG_PTC(12)
		counter++;
		timeValue += 12500;
		LPIT->TVAL0 = timeValue;
	}
	else if (FLAG_FROM_PTC(13))
	{
		CLEAR_FLAG_PTC(13)
		if (STATUS_LPIT_CHANEL0 == Disable)
		{
			if (counter==1)
			{
				/*send uart*/
			}
			else
			{
				counter--;
				timeValue -= 12500;
				LPIT->TVAL0 = timeValue;
			}
		}
		TOGGLE_STATUS_LPIT_CHANEL0	
	}
}

void LPUART1_RxTx_IRQHandler(void)
{
	buffer[buffer_index] = (uint8_t)ReceiveData(CHN1);
	if (buffer[buffer_index] == '.')
	{
		buffer[buffer_index] = '\0';
		if (!(strcmp("SW2", buffer)))
		{
			SWITCH_LED(Red_led)
		}
		else if (!(strcmp("SW3", buffer)))
		{
			SWITCH_LED(Red_led)
		}
		buffer_index = -1;
	}
	buffer_index++;
}
