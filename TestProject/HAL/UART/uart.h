/*
 * uart.h
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */

#ifndef UART_UART_H_
#define UART_UART_H_

#include "usart.h"

void uartInit(void * rxCallbackPtr);

void receptionItrOn(uint8_t * data);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);

#endif /* UART_UART_H_ */
