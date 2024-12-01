/*
 * global.h
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "led7_segment.h"
#include "button.h"

#define INIT 		0
#define EastWest	1
#define	NorthSouth	2
#define RED_MODE	3
#define YELLOW_MODE 4
#define GREEN_MODE  5

extern int timerRed_flag;
extern int timerGreen_flag;
extern int timerEnable_flag;
extern int oneSecond_flag;

extern int TimeRed;
extern int TimeGreen;

extern int state;
extern int stateSeg;

extern int number1;
extern int number2;

extern int button_flag[4];

#endif /* INC_GLOBAL_H_ */
