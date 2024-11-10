/*
 * gpioInt.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Aswin
 */
#include "gpioInt.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_ResumeTick();
}
