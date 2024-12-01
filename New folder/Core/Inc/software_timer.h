/*
 * software_timer.h
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_
#include "global.h"

int redFlag();

int greenFlag();

int enableFlag();

int oneSecondFlag();

void setTimerGreen();

void setTimerRed();

void setTimerEnable();

void setOneSecond();

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
