/*
 * lowPowerMode.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Aswin
 */
#include "lowPowerMode.h"
#include "uart.h"


void startLowPowerMode(void)
{
	HAL_UART_MspDeInit(&huart3);

	HAL_SuspendTick();

	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}


void HAL_SuspendTick(void)
{
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

void HAL_ResumeTick(void)
{
  SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}
