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

void lowPowerModeTask(void)
{
	if(getRtcAlarmStatus() == true)
	{
	    uint16_t length = snprintf(res, 512, "RTC Alarm Triggered \r\n");

		HAL_UART_Transmit(&huart3, res, length, 100);

		sDateTimeConfig_t dt = {0};

		getRTCData(&dt);

		add_time(&dt, 0, 0, 5);

		setRTCAlarm(&dt);

		setRtcAlarmStatus(false);

		startLowPowerMode();
	}
}
void startLowPowerMode(void)
{

    HAL_SuspendTick();

    HAL_PWREx_ClearPendingEvent();

    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON,PWR_SLEEPENTRY_WFI);
}


void HAL_SuspendTick(void)
{
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
}

void HAL_ResumeTick(void)
{
  SysTick->CTRL  |= SysTick_CTRL_TICKINT_Msk;
}
