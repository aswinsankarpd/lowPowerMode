/*
 * debugUart.h
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */

#ifndef DEBUGUART_DEBUGUART_H_
#define DEBUGUART_DEBUGUART_H_

#include "usart.h"

void debugUartInit(void);

void debugRxCallback(void);

void debugTxCallback(void);

uint8_t getCmdReceivedFlag(void);

void debugPrint(void);

void setCmdReceivedFlag(uint8_t value);

#endif /* DEBUGUART_DEBUGUART_H_ */
