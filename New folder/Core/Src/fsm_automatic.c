/*
 * fsm_automatic.h
 *
 *  Created on: Dec 1, 2024
 *      Author: ASUS
 */

#include "fsm_automatic.h"

#include "led7_segment.h"


void fsm_automatic_run() {
    switch (state) {
        case INIT:
            // Khởi tạo giá trị ban đầu
            number1 = TimeRed - 1;
            number2 = TimeGreen - 1;

            // Cấu hình đèn: Đèn đỏ và xanh sáng
            HAL_GPIO_WritePin(GPIOA, LED1_Pin, RESET);  // Đỏ
            HAL_GPIO_WritePin(GPIOA, LED2_Pin | LED3_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, LED4_Pin | LED5_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, LED6_Pin, RESET);  // Xanh

            // Khởi động các bộ đếm
            setTimerRed();
            setTimerGreen();
            setOneSecond();

            // Chuyển sang trạng thái East-West
            state = EastWest;
            break;

        case EastWest:
            if (oneSecondFlag() == 1) {
                // Giảm số đếm
                if (number1 > 0) number1--;
                if (number2 > 0) number2--;
                setOneSecond();
            }

            if (greenFlag() == 1) {
                // Chuyển sang đèn xanh
                HAL_GPIO_WritePin(GPIOA, LED4_Pin | LED6_Pin, SET);  // Tắt đèn xanh cũ
                HAL_GPIO_WritePin(GPIOA, LED5_Pin, RESET);        // Bật đèn vàng
                number2 = TimeRed - TimeGreen - 1;
            }

            if (redFlag() == 1) {
                // Chuyển sang trạng thái North-South
                number1 = TimeGreen-1;
                number2 = TimeRed-1;

                HAL_GPIO_WritePin(GPIOA, LED1_Pin | LED2_Pin, SET);  // Tắt đèn đỏ
                HAL_GPIO_WritePin(GPIOA, LED3_Pin, RESET);         // Bật đèn xanh
                HAL_GPIO_WritePin(GPIOA, LED5_Pin | LED6_Pin, SET);  // Tắt đèn vàng
                HAL_GPIO_WritePin(GPIOA, LED4_Pin, RESET);         // Bật đèn xanh

                setTimerRed();
                setTimerGreen();
                setOneSecond();
                state = NorthSouth;
            }

            if (isButtonPressed(MODE_BUTTON)) {
                state = RED_MODE;
            }
            break;

        case NorthSouth:
            if (oneSecondFlag() == 1) {
                // Giảm số đếm
                if (number1 > 0) number1--;
                if (number2 > 0) number2--;
                setOneSecond();
            }

            if (greenFlag() == 1) {
                // Chuyển sang đèn vàng
                HAL_GPIO_WritePin(GPIOA, LED1_Pin | LED3_Pin, SET);  // Tắt đèn xanh
                HAL_GPIO_WritePin(GPIOA, LED2_Pin, RESET);         // Bật đèn vàng
                number1 = TimeRed - TimeGreen - 1;
            }

            if (redFlag() == 1) {
                // Chuyển lại trạng thái East-West
                number1 = TimeRed - 1;
                number2 = TimeGreen - 1;

                HAL_GPIO_WritePin(GPIOA, LED1_Pin, RESET);  // Đỏ
                HAL_GPIO_WritePin(GPIOA, LED2_Pin | LED3_Pin, SET);
                HAL_GPIO_WritePin(GPIOA, LED4_Pin | LED5_Pin, SET);
                HAL_GPIO_WritePin(GPIOA, LED6_Pin, RESET);  // Xanh

                setTimerRed();
                setTimerGreen();
                setOneSecond();
                state = EastWest;
            }

            if (isButtonPressed(MODE_BUTTON)) {
                state = RED_MODE;
            }
            break;


        default:
            break;
    }
}

