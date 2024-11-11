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

static uint8_t is_leap_year(uint8_t year);

static uint8_t days_in_month(uint8_t month, uint8_t year);


void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
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

static uint8_t is_leap_year(uint8_t year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static uint8_t days_in_month(uint8_t month, uint8_t year) {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && is_leap_year(year)) {
        return 29;
    }
    return days[month - 1];
}

void add_time(sDateTimeConfig_t *dt, uint8_t add_hours, uint8_t add_minutes, uint8_t add_seconds) {
    dt->secs += add_seconds;
    if (dt->secs >= 60) {
        add_minutes += dt->secs / 60;
        dt->secs %= 60;
    }

    dt->mins += add_minutes;
    if (dt->mins >= 60) {
        add_hours += dt->mins / 60;
        dt->mins %= 60;
    }

    dt->hours += add_hours;
    if (dt->hours >= 24) {
        dt->date += dt->hours / 24;
        dt->hours %= 24;
    }

    uint8_t full_year = 2000 + dt->year;
    while (dt->date > days_in_month(dt->month, full_year)) {
        dt->date -= days_in_month(dt->month, full_year);
        dt->month++;
        if (dt->month > 12) {
            dt->month = 1;
            dt->year++;
            full_year = 2000 + dt->year;
        }
    }
}

