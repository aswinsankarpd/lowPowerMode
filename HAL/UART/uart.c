/*
 * uart.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */

#include "uart.h"

void * rxCalbackFptr = NULL;

typedef void (*rxCallback)(void) ;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	rxCallback fptr = (rxCallback)rxCalbackFptr;

	fptr();
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

}

void uartInit(void * rxCallbackPtr)
{
	rxCalbackFptr = rxCallbackPtr;
}

void receptionItrOn(uint8_t * data)
{
	HAL_UART_Receive_DMA(&huart3, data, sizeof(uint8_t));
}
