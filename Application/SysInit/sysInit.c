/*
 * sysInit.c
 *
 *  Created on: Nov 9, 2024
 *      Author: Aswin
 */


#include "sysInit.h"
#include "commonDefines.h"
#include "usart.h"
#include "debugUart.h"

uint8_t receptionData = 0;

void systemInit(void)
{
	debugUartInit();

	RTCInit();

	HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, 1);

	HAL_UART_Transmit_IT(&huart3, "System Started\r\n", 16);

	HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN4);
}
