/**
 * @file rgb_brightness.c
 * @author Ivin Lim (ivin.lim16@gmail.com)
 * @brief Control LED brightness
 * @version 0.1
 * @date 2022-07-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "rgb_brightness.h"

uint32_t _current_period_settings;

int rgbBrightness_setLedRedBrightness(unsigned int duty)
{
	uint32_t duty_register_value = 0;
	if( duty > 100 )
	{
		return -1;
	}
	_current_period_settings = __HAL_TIM_GET_AUTORELOAD(&htim2);
	duty_register_value = ( _current_period_settings * duty ) / 100;

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, duty_register_value);
	return 0;

}

int rgbBrightness_setLedGreenBrightness(unsigned int duty)
{
	uint32_t duty_register_value = 0;
	if( duty > 100 )
	{
		return -1;
	}
	_current_period_settings = __HAL_TIM_GET_AUTORELOAD(&htim2);
	duty_register_value = ( _current_period_settings * duty ) / 100;

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, duty_register_value);
	return 0;

}

int rgbBrightness_setLedBlueBrightness(unsigned int duty)
{
	uint32_t duty_register_value = 0;
	if( duty > 100 )
	{
		return -1;
	}
	_current_period_settings = __HAL_TIM_GET_AUTORELOAD(&htim2);
	duty_register_value = ( _current_period_settings * duty ) / 100;

	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, duty_register_value);
	return 0;

}

int rgbBrightness_setLedBrightness(unsigned int duty)
{
	return (rgbBrightness_setLedRedBrightness(duty) && \ 
	rgbBrightness_setLedBlueBrightness(duty) && \
	rgbBrightness_setLedGreenBrightness(duty));
}

