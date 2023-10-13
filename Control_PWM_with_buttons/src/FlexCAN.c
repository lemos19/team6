#include "FlexCAN.h"
#include "PCC_Type.h"
void FlexCAN0init(void)
{
#define MSG_BUF_SIZE 4
    uint32_t i;
    PCC->PCC_FlexCAN0 = 1u << CGC_SHIFT;
    CAN0->MCR |= CAN_MCR_MDIS_MASK;
    CAN0->CTRL1 &= ~CAN_CTRL1_CLKSRC_MASK;
    CAN0->MCR &= ~CAN_MCR_MDIS_MASK;

    while (!((CAN0->MCR & CAN_MCR_FRZACK_MASK) >> CAN_MCR_FRZACK_SHIFT))  {}

    
}