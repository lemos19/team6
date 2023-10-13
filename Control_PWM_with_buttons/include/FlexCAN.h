#ifndef FLEX_CAN
#define FLEX_CAN
#include <stdint.h>
#define FlEXCAN0_BASE_ADDRESS 0x40024000
#define FlEXCAN1_BASE_ADDRESS 0x40025000
#define FlEXCAN2_BASE_ADDRESS 0x4002B000

typedef struct 
{
    volatile uint32_t MCR;
    volatile uint32_t CTRL1;
    volatile uint32_t TIMER;
    uint32_t Reserved;
    volatile uint32_t RXMGMASK;
    volatile uint32_t RX14MASK;
    volatile uint32_t RX15MASK;
    volatile uint32_t ECR;
    volatile uint32_t ESR1;
    uint32_t Reserved1;
    volatile uint32_t IMASK1;
    uint32_t Reserved2;
    volatile uint32_t IFLAG1;
    volatile uint32_t CTRL2;
    volatile uint32_t ESR2;
    uint32_t Reserved3[2];
    volatile uint32_t CRCR;
    volatile uint32_t RXFGMASK;
    volatile uint32_t RXFIR;
    volatile uint32_t CBT;
    uint32_t Reserved5[523];
    volatile uint32_t RXIMRn[32];
    uint32_t Reserved4[128];
    volatile uint32_t CTRL1_PN;
    volatile uint32_t CTRL2_PN;
    volatile uint32_t WU_MTC;
    volatile uint32_t FLT_ID1;
    volatile uint32_t FLT_DLC;
    volatile uint32_t PL1_LO;
    volatile uint32_t PL1_HI;
    volatile uint32_t FLT_ID2_IDMASK;
    volatile uint32_t PL2_PLMASK_LO;
    volatile uint32_t PL2_PLMASK_HI;
    volatile uint32_t WMB0_CS;
    volatile uint32_t WMB0_ID;
    volatile uint32_t WMB0_D03;
    volatile uint32_t WMB0_D47;
    volatile uint32_t WMB1_CS;
    volatile uint32_t WMB1_ID;
    volatile uint32_t WMB1_D03;
    volatile uint32_t WMB1_D47;
    volatile uint32_t WMB2_CS;
    volatile uint32_t WMB2_ID;
    volatile uint32_t WMB2_D03;
    volatile uint32_t WMB2_D47;
    volatile uint32_t WMB3_CS;
    volatile uint32_t WMB3_ID;
    volatile uint32_t WMB3_D03;
    volatile uint32_t WMB3_D47;
    uint32_t Reserved4[32];
    volatile uint32_t FDCTRL;
    volatile uint32_t FDCBT;
    volatile uint32_t FDCRC;
}FlexCAN_type;
#define CAN0 ((FlexCAN_type*)(FlEXCAN0_BASE_ADDRESS))
#define CAN1 ((FlexCAN_type*)(FlEXCAN1_BASE_ADDRESS))
#define CAN2 ((FlexCAN_type*)(FlEXCAN2_BASE_ADDRESS))
#endif