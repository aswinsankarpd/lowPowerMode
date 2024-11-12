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

static bool stopModeTriggered = false;

void lowPowerModeTask(void)
{
//	if(getRtcAlarmStatus() == true)
//	{
//	    uint16_t length = snprintf(res, 512, "RTC Alarm Triggered \r\n");
//
//		HAL_UART_Transmit(&huart3, res, length, 100);
//
//		sDateTimeConfig_t dt = {0};
//
//		getRTCData(&dt);
//
//		add_time(&dt, 0, 0, 5);
//
//		setRTCAlarm(&dt);
//
//		setRtcAlarmStatus(false);
//
//		startSleepMode();
//	}
}


void stopModeTask(void)
{
	if(stopModeTriggered == true)
	{
		stopModeTriggered = false;

		if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0x4E20, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
		{
			Error_Handler();
		}

	    uint16_t length = snprintf(res, 512, "Stop Mode Triggered \r\n");

		HAL_UART_Transmit(&huart3, res, length, 100);

		HAL_SuspendTick();

		HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);


		//<<< Logic after wakeup
		SystemClock_Config();

		HAL_ResumeTick();

		HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);

		for(uint8_t i = 0; i < 5; i++)
		{
			HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);

			HAL_Delay(1000);
		}

	    length = snprintf(res, 512, "System woken up \r\n");

		HAL_UART_Transmit(&huart3, res, length, 100);

	}
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

bool getStopModeFlag(void)
{
	return stopModeTriggered;
}

void setStopModeFlag(bool flag)
{
	stopModeTriggered = flag;
}
