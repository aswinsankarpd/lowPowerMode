/*
 * realtimeclock.h
 *
 *  Created on: Nov 10, 2024
 *      Author: Aswin
 */

#ifndef RTC_REALTIMECLOCK_H_
#define RTC_REALTIMECLOCK_H_

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

void setRTCData(sDateTimeConfig_t * rtcDatTime);

void getRTCData(sDateTimeConfig_t * rtcDatTime);

#endif /* RTC_REALTIMECLOCK_H_ */
