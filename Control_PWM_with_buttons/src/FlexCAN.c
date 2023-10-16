#include "FlexCAN.h"
#include "PCC_Type.h"
void FlexCAN0init(void)
{
#define MSG_BUF_SIZE 4
    uint32_t i;
    PCC->PCC_FlexCAN0 = 1u << CGC_SHIFT;
    CAN0->MCR |= CAN_MCR_MDIS_MASK;
    CAN0->CTRL1.Register &= ~CAN_CTRL1_CLKSRC_MASK;
    CAN0->MCR &= ~CAN_MCR_MDIS_MASK;

    while (!((CAN0->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT))
    {
    }
    CAN0->CTRL1.Register = 0;
    CAN0->CTRL1.Fields.PSEG2 = 3;
    CAN0->CTRL1.Fields.PSEG1 = 3;
    CAN0->CTRL1.Fields.PROPSEG = 6;
    CAN0->CTRL1.Fields.RJW = 3;
    CAN0->CTRL1.Fields.SMP = 1;
    for (i = 0; i < 128; i++)
    {
        CAN0->RAMn[i] = 0;
    }
    for (i = 0; i < 16; i++)
    {
        CAN0->RXIMRn[i] = 0xFFFFFFFF;
    }
    CAN0->RXMGMASK = 0x1FFFFFFF;

    CAN0->RAMn[4 * MSG_BUF_SIZE + 0] = 0x04000000; /* Msg Buf 4, word 0: Enable for reception 	*/
                                                   /* EDL,BRS,ESI=0: CANFD not used 				*/
                                                   /* CODE=4: MB set to RX inactive 				*/
                                                   /* IDE=0: Standard ID 							*/
                                                   /* SRR, RTR, TIME STAMP = 0: not applicable 	*/
                                                   /* Node A receives msg with std ID 0x511 		*/
    CAN0->RAMn[4 * MSG_BUF_SIZE + 1] = 0x14440000; /* Msg Buf 4, word 1: Standard ID = 0x111 		*/

    CAN0->MCR = 0x0000001F;
    while ((CAN0->MCR && CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT)
    {
    }
    while ((CAN0->MCR && CAN_MCR_NOTRDY_MASK) >> CAN_MCR_NOTRDY_SHIFT)
    {
    }
}