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

#endif /* DEBUGUART_DEBUGUART_H_ */
