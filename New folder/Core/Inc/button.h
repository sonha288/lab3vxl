/*
 * button.h
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	SET
#define PRESSED_STATE	RESET

#define MODE_BUTTON 0
#define ADD_BUTTON	1
#define CON_BUTTON	2
#define SUB_BUTTON	3

int isButtonPressed(int index);

void subkeyProcess(int index);

void getInputKey();

#endif /* BUTTON_H_ */
