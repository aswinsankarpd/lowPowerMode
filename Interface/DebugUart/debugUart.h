/*
 * debugUart.h
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */

#ifndef DEBUGUART_DEBUGUART_H_
#define DEBUGUART_DEBUGUART_H_

#include "usart.h"
#include "circularBuffer.h"

void debugUartInit(void);

void debugRxCallback(void);

void debugTxCallback(void);

uint8_t getCmdReceivedFlag(void);

void debugPrint(void);

void setCmdReceivedFlag(uint8_t value);

sCircularBuffer_t * getRxBuffer(void);

#endif /* DEBUGUART_DEBUGUART_H_ */
