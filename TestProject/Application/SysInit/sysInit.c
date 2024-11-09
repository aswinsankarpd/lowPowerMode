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
	HAL_UART_Transmit_IT(&huart3, "System Started\r\n", 16);

	debugUartInit();
}
