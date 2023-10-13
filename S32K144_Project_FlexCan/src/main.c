
#include "device_registers.h" 
#include "FlexCAN.h"
#include "clocks_and_modes.h"

void WDOG_disable (void)
{
  WDOG->CNT=0xD928C520;    
  WDOG->TOVAL=0x0000FFFF;   
  WDOG->CS = 0x00002100;    
}

void PORT_init (void)
{
	
	
	
	
	
	
	
	
	
	
  PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK;	
  PORTE->PCR[4] |= PORT_PCR_MUX(5);	
  PORTE->PCR[5] |= PORT_PCR_MUX(5); 

  PCC->PCCn[PCC_PORTD_INDEX]|=PCC_PCCn_CGC_MASK;   
  PORTD->PCR[16] = PORT_PCR_MUX(1); 
  PTD->PDDR |= 1<<16;            	
}

int main(void)
{
	uint32_t rx_msg_count = 0;	

		
	  WDOG_disable();		 
	  SOSC_init_8MHz();     
	  SPLL_init_160MHz();    
	  NormalRUNmode_80MHz(); 

	  FLEXCAN0_init();         
	  PORT_init();            
	
#ifdef NODE_A             
  FLEXCAN0_transmit_msg(); 
#endif

	
	  for (;;)
	  {                        			
		if ((CAN0->IFLAG1 >> 4) & 1) {  
		  FLEXCAN0_receive_msg ();      
		  rx_msg_count++;               

		  if (rx_msg_count == 1000) {   
			PTD->PTOR |= 1<<16;         
			rx_msg_count = 0;          
		  }

		  FLEXCAN0_transmit_msg ();     
		}
	  }
}
