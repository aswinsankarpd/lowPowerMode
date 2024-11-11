/*
 * realtimeclock.c
 *
 *  Created on: Nov 10, 2024
 *      Author: Aswin
 */

#include "realtimeclock.h"
#include "usart.h"

sDateTimeConfig_t defaultDateTime = {
		.date 	= 26,
		.day 	= 2,
		.month	= 6,
		.year	= 1,
		.hours	= 10,
		.mins	= 0,
		.secs	= 21
};

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
  HAL_GPIO_WritePin (GPIOB, GPIO_PIN_0, 1);
}

void RTCInit(void)
{
	if (HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR1) != 0x2346)
	{
		setRTCData(&defaultDateTime);
		HAL_UART_Transmit(&huart3, "RTC Reconfig'd\r\n", 13, 100);
	}
}

void setRTCData(sDateTimeConfig_t * rtcDatTime)
{
	RTC_TimeTypeDef sTime = {0};

	sTime.Hours = rtcDatTime->hours;
	sTime.Minutes = rtcDatTime->mins;
	sTime.Seconds = rtcDatTime->secs;

	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sTime.StoreOperation = RTC_STOREOPERATION_RESET;

	RTC_DateTypeDef sDate = {0};

	sDate.WeekDay = rtcDatTime->day;
	sDate.Month = rtcDatTime->month;
	sDate.Date = rtcDatTime->date;
	sDate.Year = rtcDatTime->year;

	if ((HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) == HAL_OK) && (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) == HAL_OK))
	{
		HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x2345);
	}
}

void getRTCData(sDateTimeConfig_t * rtcDatTime)
{
	  RTC_DateTypeDef gDate;
	  RTC_TimeTypeDef gTime;


	  HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);

	  HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);

	  rtcDatTime->date 	= gDate.Date;
	  rtcDatTime->day 	= gDate.WeekDay;
	  rtcDatTime->month = gDate.Month;
	  rtcDatTime->year 	= gDate.Year;

	  rtcDatTime->hours = gTime.Hours;
	  rtcDatTime->mins 	= gTime.Minutes;
	  rtcDatTime->secs 	= gTime.Seconds;
}

void setRTCAlarm(sDateTimeConfig_t * rtcDatTime)
{
	RTC_AlarmTypeDef sAlarm = {0};
	sAlarm.AlarmTime.Hours = rtcDatTime->hours;
	sAlarm.AlarmTime.Minutes = rtcDatTime->mins;
	sAlarm.AlarmTime.Seconds = rtcDatTime->secs;
	sAlarm.AlarmTime.SubSeconds = 0;
	sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_WEEKDAY;
	sAlarm.AlarmDateWeekDay = rtcDatTime->day;
	sAlarm.Alarm = RTC_ALARM_A;

	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	{
		Error_Handler();
	}
}

