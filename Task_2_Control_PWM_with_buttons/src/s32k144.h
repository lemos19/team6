
#ifndef S32K144_H_
#define S32K144_H_

#include "stdint.h"
/*****************************************************************************************************/
/******************************************************************************************************/
typedef struct{
  volatile uint32_t PCC_LPIT;
  volatile uint32_t PCC_FTM0;
  volatile uint32_t PCC_FTM1;
  volatile uint32_t PCC_FTM2;
  volatile uint32_t Reserved[14];
	volatile uint32_t PCC_PORTA;
	volatile uint32_t PCC_PORTB;
	volatile uint32_t PCC_PORTC;
	volatile uint32_t PCC_PORTD;
	volatile uint32_t PCC_PORTE;
  volatile uint32_t RESERVED[28];
  volatile uint32_t PCC_LPUART0;
  volatile uint32_t PCC_LPUART1;
}PCC_Type;
#define PCC_base_address		0x400650DCu
#define PCC  ((PCC_Type*)PCC_base_address)

/******************************************************************************************************/
/******************************************************************************************************/
typedef struct{
	volatile uint32_t PCR[32];
}Port_Type;

#define PORTC_base_address		0x4004B000u
#define PORTC	((Port_Type*)PORTC_base_address)

#define PORTD_base_address		0x4004C000u
#define PORTD	((Port_Type*)PORTD_base_address)

#define PORTE_base_address		0x4004D000u
#define PORTE	((Port_Type*)PORTE_base_address)

/******************************************************************************************************/
/******************************************************************************************************/
typedef struct{
	volatile uint32_t PDOR;
	volatile uint32_t PSOR;
	volatile uint32_t PCOR;
	volatile uint32_t PTOR;
	volatile uint32_t PDIR;
	volatile uint32_t PDDR;
	volatile uint32_t PIDR;
}GPIO_Type;

#define GPIOD_base_address 					0x400FF0C0u
#define	GPIOD ((GPIO_Type*)GPIOD_base_address)

#define GPIOC_base_address 					0x400FF080u
#define	GPIOC ((GPIO_Type*)GPIOC_base_address)

/******************************************************************************************************/
/******************************************************************************************************/
typedef struct{
	volatile uint32_t ISER[8];
	volatile uint32_t ICER[8];
	volatile uint32_t ISPR[8];
	volatile uint32_t ICPR[8];
	volatile uint32_t IABR[8];
	volatile uint32_t IPR[8];
}NVIC_Type;
#define NVIC_BASE          	0xE000E100u
#define NVIC 				((NVIC_Type*)NVIC_BASE)

/******************************************************************************************************/
/******************************************************************************************************/
typedef struct {
  volatile uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  volatile uint8_t RESERVED_0[8];
  volatile uint32_t CSR;                               /**< Clock Status Register, offset: 0x10 */
  volatile uint32_t RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  volatile uint32_t VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  volatile uint32_t HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  volatile uint32_t CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
  volatile uint8_t RESERVED_1[220];
  volatile uint32_t SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  volatile uint32_t SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  volatile uint32_t SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
  volatile uint8_t RESERVED_2[244];
  volatile uint32_t SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  volatile uint32_t SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  volatile uint32_t SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
  volatile uint8_t RESERVED_3[244];
  volatile uint32_t FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  volatile uint32_t FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  volatile uint32_t FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  volatile uint8_t RESERVED_4[756];
  volatile uint32_t SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  volatile uint32_t SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  volatile uint32_t SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type;
#define SCG_base_address		0x40064000
#define SCG 					((SCG_Type*)SCG_base_address)

/******************************************************************************************************/
/******************************************************************************************************/
typedef struct
{
    volatile uint32_t VERID;
    volatile uint32_t PARAM;
    volatile uint32_t MCR;
    volatile uint32_t MSR;
    volatile uint32_t MIER;
    volatile uint32_t SETTEN;
    volatile uint32_t CLRTEN;
    volatile uint32_t Reserved0;
    volatile uint32_t TVAL0;
    volatile uint32_t CVAL0;
    volatile uint32_t TCTRL0;
    volatile uint32_t Reserved1;
    volatile uint32_t TVAL1;
    volatile uint32_t CVAL1;
    volatile uint32_t TCTRL1;
    volatile uint32_t Reserved2;
    volatile uint32_t TVAL2;
    volatile uint32_t CVAL2;
    volatile uint32_t TCTRL2;
    volatile uint32_t Reserved3;
	volatile uint32_t TVAL3;
    volatile uint32_t CVAL3;
    volatile uint32_t TCTRL3;
}LPIT_Type;
#define LPIT_base_address		0x40037000
#define LPIT 					((LPIT_Type*)LPIT_base_address)

/******************************************************************************************************/
/******************************************************************************************************/
/** LPUART - Register Layout Typedef */
typedef struct {
  volatile uint32_t VERID;               /**< Version ID Register, offset: 0x0 */
  volatile uint32_t PARAM;               /**< Parameter Register, offset: 0x4 */
  volatile uint32_t GLOBAL;              /**< LPUART Global Register, offset: 0x8 */
  volatile uint32_t PINCFG;              /**< LPUART Pin Configuration Register, offset: 0xC */
  volatile uint32_t BAUD;                /**< LPUART Baud Rate Register, offset: 0x10 */
  volatile uint32_t STAT;                /**< LPUART Status Register, offset: 0x14 */
  volatile uint32_t CTRL;                /**< LPUART Control Register, offset: 0x18 */
  volatile uint32_t DATA;                /**< LPUART Data Register, offset: 0x1C */
  volatile uint32_t MATCH;               /**< LPUART Match Address Register, offset: 0x20 */
  volatile uint32_t MODIR;               /**< LPUART Modem IrDA Register, offset: 0x24 */
  volatile uint32_t FIFO;                /**< LPUART FIFO Register, offset: 0x28 */
  volatile uint32_t WATER;               /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type;
/* LPUART - Peripheral instance base addresses */
/** Peripheral LPUART0 base address */
#define LPUART0_BASE                             (0x4006A000u)
#define LPUART0                                  ((LPUART_Type *)LPUART0_BASE)

/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x4006B000u)
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)

/** Peripheral LPUART2 base address */
#define LPUART2_BASE                             (0x4006C000u)
#define LPUART2                                  ((LPUART_Type *)LPUART2_BASE)

/******************************************************************************************************/
/******************************************************************************************************/
typedef struct
{
  volatile uint32_t SC;
  volatile uint32_t CNT;
  volatile uint32_t MOD;
  volatile uint32_t C0SC;
  volatile uint32_t C0V;
  volatile uint32_t C1SC;
  volatile uint32_t C1V;
  volatile uint32_t C2SC;
  volatile uint32_t C2V;
  volatile uint32_t C3SC;
  volatile uint32_t C3V;
  volatile uint32_t C4SC;
  volatile uint32_t C4V;
  volatile uint32_t C5SC;
  volatile uint32_t C5V;
  volatile uint32_t C6SC;
  volatile uint32_t C6V;
  volatile uint32_t C7SC;
  volatile uint32_t C7V;
  volatile uint32_t CNTIN;
  volatile uint32_t STATUS;
  volatile uint32_t MODE;
  volatile uint32_t SYNC;
  volatile uint32_t OUTINIT;
  volatile uint32_t OUTMASK;
  volatile uint32_t COMBINE;
  volatile uint32_t DEADTIME;
  volatile uint32_t EXTTRIG;
  volatile uint32_t POL;
  volatile uint32_t FMS;
  volatile uint32_t FILTER;
  volatile uint32_t FLTCTRL;
  volatile uint32_t QDCTRL;
  volatile uint32_t CONF;
  volatile uint32_t FLTPOL;
  volatile uint32_t SYNCONF;
  volatile uint32_t INVCTRL;
  volatile uint32_t SWOCTRL;
  volatile uint32_t PWMLOAD;
  volatile uint32_t HCR;
  volatile uint32_t PAIR0DEADTIME;
  volatile uint32_t RESERVED_0;
  volatile uint32_t PAIR1DEADTIME;
  volatile uint32_t RESERVED_1;
  volatile uint32_t PAIR2DEADTIME;
  volatile uint32_t RESERVED_2;
  volatile uint32_t PAIR3DEADTIME;
  volatile uint32_t RESERVED_4[81];
  volatile uint32_t MOD_MIRROR;
  volatile uint32_t CxV_MIRROR[8];
}FTM_Tye;

#define FTM0_base       0x40038000u
#define FTM0                    ((FTM_Tye*)FTM0_base)

#define FTM1_base       0x40039000u
#define FTM1                    ((FTM_Tye*)FTM1_base)

#define FTM2_base       0x4003A000u
#define FTM2                    ((FTM_Tye*)FTM2_base)

#define FTM3_base       0x40026000u
#define FTM3                    ((FTM_Tye*)FTM3_base)

#define FTM4_base       0x4006E000u
#define FTM4                    ((FTM_Tye*)FTM4_base)

#define FTM5_base       0x4006F000u
#define FTM5                    ((FTM_Tye*)FTM5_base)

#define FTM6_base       0x40070000u
#define FTM6                    ((FTM_Tye*)FTM6_base)

#define FTM7_base       0x40071000u
#define FTM7                   ((FTM_Tye*)FTM7_base)


#endif /* S32K144_H_ */
