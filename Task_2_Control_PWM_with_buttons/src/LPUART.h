/*
 * LPUART.h
 *
 *  Created on: 6 thg 10, 2023
 *      Author: DAT
 */

#ifndef LPUART_H_
#define LPUART_H_
#include "s32k144.h"

void LPUART1_Config(void);
void LPUART_sent_char(uint8_t data);
void LPUART_sent_string(char str[]);


#endif /* LPUART_H_ */
