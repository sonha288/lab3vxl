/*
 * fsm_manual.c
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (state) {
    case RED_MODE:
		number1 = 2;
		number2 = TimeRed;
		if (isButtonPressed(MODE_BUTTON) == 1) {
			state = YELLOW_MODE;
		} else if (isButtonPressed(ADD_BUTTON) == 1) {
			TimeRed++;
			TimeGreen++;
		} else if (isButtonPressed(SUB_BUTTON) == 1) {
			if (TimeRed > 2)
				TimeRed--;
		} else if (isButtonPressed(CON_BUTTON) == 1) {
			state = INIT;
		}
		break;
	case YELLOW_MODE:
		number1 = 3;
		number2 = TimeRed - TimeGreen;
		if (isButtonPressed(MODE_BUTTON) == 1) {
			state = GREEN_MODE;
		} else if (isButtonPressed(ADD_BUTTON) == 1) {
			TimeRed++;
		} else if (isButtonPressed(SUB_BUTTON) == 1) {
			if (TimeRed - TimeGreen > 1) {
				TimeRed--;
			}
		} else if (isButtonPressed(CON_BUTTON) == 1) {
			state = INIT;
		}
		break;
	case GREEN_MODE:
		number1 = 4;
		number2 = TimeGreen;
		if (isButtonPressed(MODE_BUTTON) == 1) {
			state = INIT;
		} else if (isButtonPressed(ADD_BUTTON) == 1) {
			TimeRed++;
			TimeGreen++;
		} else if (isButtonPressed(SUB_BUTTON) == 1) {
			if (TimeGreen > 1)
				TimeGreen--;
		} else if (isButtonPressed(CON_BUTTON) == 1) {
			state = INIT;
		}
		break;
	default:
		break;
	}
}
