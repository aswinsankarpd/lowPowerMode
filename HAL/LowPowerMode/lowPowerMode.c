/*
 * lowPowerMode.c
 *
 *  Created on: Nov 11, 2024
 *      Author: Aswin
 */
#include "lowPowerMode.h"
#include "uart.h"
#include "realtimeclock.h"

char res[100] = {0};

static bool standbyModeTriggd = false;

void lowPowerModeTask(void)
{

}


void standbyModeTask(void)
{
	if(standbyModeTriggd == true)
	{
		standbyModeTriggd = false;

//		if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0x500B, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
//		{
//			Error_Handler();
//		}

	    uint16_t length = snprintf(res, 512, "Stop Mode Triggered \r\n");

	    HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN4);

		HAL_UART_Transmit(&huart3, res, length, 100);

		MX_GPIO_DeInit();

		MAX_DMA_DeInit();

		HAL_UART_MspDeInit(&huart3);

		HAL_PWR_EnterSTANDBYMode();

	}
}

void startSleepMode(void)
{
	HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);

	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);

	HAL_SuspendTick();
}

void startStopMode(void)
{
	if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
	{
		Error_Handler();
	}

	HAL_SuspendTick();

	HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
}


void HAL_SuspendTick(void)
{
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

void HAL_ResumeTick(void)
{
  SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}

bool getStndMode(void)
{
	return standbyModeTriggd;
}

void setStndMode(bool flag)
{
	standbyModeTriggd = flag;
}
