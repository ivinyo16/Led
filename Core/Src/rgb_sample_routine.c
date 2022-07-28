/**
 * @file rgb_sample_routine.c
 * @author Ivin Lim (ivin.lim16@gmail.com)
 * @brief Sample RGB application using rgb led control
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "timer_rgb_led_control.h"

timer_rgb_led_handle_t led1 =
{
    .timer_handle = &htim2,
    .red = 
    {
        .channel = TIM_CHANNEL_1,
        .percent_duty = 45,
    },
    .green = 
    {
        .channel = TIM_CHANNEL_3,
        .percent_duty = 100,
    },
    .blue = 
    {
        .channel = TIM_CHANNEL_2,
        .percent_duty = 100,
    },
	.state = RGB_LED_STATE_RED,
};

void ledRoutine_Init(void)
{
	timerRgb_Init(&led1);
}

void ledRoutine_Update(void)
{
    HAL_Delay(1000);
    timerRgb_setLedRedPercentDuty(&led1, 0);
    HAL_Delay(1000);
    timerRgb_setLedRedPercentDuty(&led1, 10);
    HAL_Delay(1000);
    timerRgb_setLedRedPercentDuty(&led1, 30);
    HAL_Delay(1000);
    timerRgb_setLedRedPercentDuty(&led1, 50);
    HAL_Delay(1000);
    timerRgb_setLedRedPercentDuty(&led1, 80);
    HAL_Delay(1000);
    timerRgb_setLedRedPercentDuty(&led1, 100);
}
