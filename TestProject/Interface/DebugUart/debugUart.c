/*
 * debugUart.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */
#include "debugUart.h"
#include "commonDefines.h"
#include "uart.h"
uint8_t data = 0;

void debugUartInit(void)
{
	void * rxCallbackFptr = &debugRxCallback;

	uartInit(rxCallbackFptr);
	receptionItrOn(&data);
}

void debugRxCallback(void)
{
	HAL_UART_Transmit(&huart3, &data, 1, 100);
	receptionItrOn(&data);
}

void debugTxCallback(void)
{

}
