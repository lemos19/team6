#include "MacroAndFuntion.h"
#include "LPIT_Type.h"
#include "LPUART.h"
#include <string.h>
#include "LPSPI_Type.h"
#include "ledMax7219.h"
#include "SIM_Type.h"
#include "string.h"
#include "FTM_type.h"

#define CLEAR_FLAG_LPIT_CHANEL(chanel) 	LPIT->MSR.Fields.TIF##chanel = 1;
#define ENABLE_LPIT_CHANEL(chanel)		LPIT->TCTRL##chanel.Fields.T_EN = Enable;
#define DISABLE_LPIT_CHANEL(chanel)		LPIT->TCTRL##chanel.Fields.T_EN = Disable;
#define TOGGLE_STATUS_LPIT_CHANEL0		LPIT->TCTRL0.Fields.T_EN ^= 1;
#define STATUS_LPIT_CHANEL0				LPIT->TCTRL0.Fields.T_EN
#define FLAG_FROM_PTC(pin) 				PORTC->PORT_PCR[pin].Fields.ISF == 1
#define CLEAR_FLAG_PTC(pin) 			PORTC->PORT_PCR[pin].Fields.ISF = 1;


static char buffer[10];
static int8_t buffer_index = 0;
void PORTC_IRQHandler(void);
void LPUART1_RxTx_IRQHandler(void);
void LPIT0_Ch0_IRQHandler(void);
void LPIT0_Ch1_IRQHandler(void);
void LPIT0_Ch2_IRQHandler(void);


static char arr[] = "hello world!!\n";
int main(void)
{
	initializeGPIOandSystick();
	Config_SOSC_CLK();					  // 8Mhz
	Config_SPLL_CLK(SOSC, Div1, Multi20); // 80Mhz
	Config_RCCR(SPLL, 0 /*div core by 1*/, 1 /*div bus by 2*/, 2 /*div slow by 3*/);
	SCG_Asyn_Peripheral_Sources(SOSCDIV2_CLK, Div_By_64); // 125000 Hz
	SCG_Asyn_Peripheral_Sources(FIRCDIV2_CLK, Div_By_1); // 48Mhz

	SCG->SCG_SOSCDIV.Fields.Div1 = Div_By_1;
	FTM_init
	(
		FTM_0,
		SOSCDIV1_CLK,
		Div_128,
		62500-1 		/*modulo value --- clockout = clockin/(pre scale*modulo)*/
	);
	FTM0->CnSC_And_CnV[1].CnV = 31250; /*duti cricle*/
	PORTD->PORT_PCR[16].Fields.MUX = 2; /*FTM0 chanel 1*/
	Start_counter_FTM0(); /*shdaosdhasoidasid*/
	
	Config_LPIT_Chanel
	(
		LPIT_Chanel0,
		SOSCDIV2_CLK, 	/*chose clock source*/
		Enable,		  	/*enable interrupt*/
		20000000	  	/*reset value*/
	);
	Config_LPIT_Chanel(LPIT_Chanel1, SOSCDIV2_CLK, Enable, 20000000);
	Config_LPIT_Chanel(LPIT_Chanel2, SOSCDIV2_CLK, Enable, 20000000);

	Config_LPUART_Chanel
	(
		CHN1,
		FIRCDIV2_CLK,
		500, 			/*baurate = baud clock /(oversameling*500)----baurate: 9600|baud clock: 48Mh|oversameling: 10*/
		ratio10,
		One_Stop_Bit,
		_8BitData,
		Disable 		/*disable parity bit*/
	);

	Enable_LPUART_Interrupts(CHN1, Receiver_Interrupt);
	NVIC_Config_Interrup_Modul(Lpuart1, Enable);
	Enable_LPUART_Pin(Chn1_Tx_PTC7);
	Enable_LPUART_Pin(Chn1_Rx_PTC6);
	Enable_ReceiveData_Chanel(CHN1);

	Send_Message(&arr[0]);

	while (1)
	{
		
		
	}
}
void LPIT0_Ch0_IRQHandler(void)
{
	CLEAR_FLAG_LPIT_CHANEL(0)
	
	
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
		
	}
	else if (FLAG_FROM_PTC(13))
	{
		CLEAR_FLAG_PTC(13)
		
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
		}
		else if (!(strcmp("SW3", buffer)))
		{
		}
		buffer_index = -1;
	}
	buffer_index++;
}
