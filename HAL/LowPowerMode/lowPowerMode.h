/*
 * lowPowerMode.h
 *
 *  Created on: Nov 11, 2024
 *      Author: Aswin
 */

#ifndef LOWPOWERMODE_LOWPOWERMODE_H_
#define LOWPOWERMODE_LOWPOWERMODE_H_

#include "stm32h7xx_hal.h"

void startLowPowerMode(void);

void HAL_SuspendTick(void);

void HAL_ResumeTick(void);

#endif /* LOWPOWERMODE_LOWPOWERMODE_H_ */
