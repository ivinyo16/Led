/**
 * @file rgb_led_state.c
 * @author Ivin Lim (ivin.lim16@gmail.com.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "rgb_led_state.h"
#include "tim.h"


rgb_led_state_t rgb_led_state = RGB_LED_STATE_OFF;
rgb_led_state_t rgbLedState_GetState(void)
{
    return rgb_led_state;
}

int rgbLedState_SetOff(void)
{
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_1) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_3) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    rgb_led_state = RGB_LED_STATE_OFF;
    return 0;
}

int rgbLedState_SetRed(void)
{
    if( HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_1) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_3) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    rgb_led_state = RGB_LED_STATE_RED;
    return 0;
}

int rgbLedState_SetGreen(void)
{
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_1) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_2) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_3) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    rgb_led_state = RGB_LED_STATE_GREEN;
    return 0;
}

int rgbLedState_SetBlue(void)
{
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_1) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Start_IT(&htim2, TIM_CHANNEL_2) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    if( HAL_TIM_PWM_Stop_IT(&htim2, TIM_CHANNEL_3) != HAL_OK )
    {
        rgb_led_state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    rgb_led_state = RGB_LED_STATE_BLUE;
    return 0;
}

void rgbLedStateInit(void)
{
	rgbLedState_SetRed();
}

void rgbLedStateUpdate(void)
{
    switch (rgb_led_state)
    {
    case RGB_LED_STATE_OFF:
        
        break;
    
    default:
        break;
    }
}
