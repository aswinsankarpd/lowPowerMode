/*
 * realtimeclock.h
 *
 *  Created on: Nov 10, 2024
 *      Author: Aswin
 */

#ifndef RTC_REALTIMECLOCK_H_
#define RTC_REALTIMECLOCK_H_

#include "realtimeclock.h"
#include "rtc.h"
#include "commonDefines.h"

typedef struct
{
	uint8_t hours;
	uint8_t mins;
	uint8_t secs;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
}sDateTimeConfig_t;

void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc);

void RTCInit(void);

void setRTCData(sDateTimeConfig_t * rtcDatTime);

void getRTCData(sDateTimeConfig_t * rtcDatTime);

void add_time(sDateTimeConfig_t *dt, uint8_t add_hours, uint8_t add_minutes, uint8_t add_seconds);

void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef * hrtc);

bool getRtcAlarmStatus(void);

void setRtcAlarmStatus(bool flag);

#endif /* RTC_REALTIMECLOCK_H_ */
