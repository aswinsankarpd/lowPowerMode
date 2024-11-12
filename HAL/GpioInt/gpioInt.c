/*
 * gpioInt.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Aswin
 */
#include "gpioInt.h"
#include "uart.h"
#include "dma.h"
#include "commonDefines.h"
#include "stm32h7xx_hal_cortex.h"

char rresponse[100] = {0};

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_ResumeTick();

    uint16_t length = snprintf(rresponse, 512, "Device woken up\r\n");

	HAL_UART_Transmit(&huart3, rresponse, length, 100);

}
