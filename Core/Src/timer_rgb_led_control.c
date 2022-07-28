/*
 * timer_led_control.c
 *
 *  Created on: Jul 27, 2022
 *      Author: ivinl
 */

#include <timer_rgb_led_control.h>

uint32_t _led_current_period_settings;

rgb_led_state_t timerRgb_getState(timer_rgb_led_handle_t *h)
{
    return h->state;
}

int8_t timerRgb_getRedPercentDuty(timer_rgb_led_handle_t *h)
{
    return h->red.percent_duty;
}
int8_t timerRgb_getGreenPercentDuty(timer_rgb_led_handle_t *h)
{
    return h->green.percent_duty;
}
int8_t timerRgb_getBluePercentDuty(timer_rgb_led_handle_t *h)
{
    return h->blue.percent_duty;
}

/**
 * @brief returns the duty cycle of the active state, if OFF, returns 0
 * 
 * @param h 
 * @return int8_t 
 */
int8_t timerRgb_getPercentDuty(timer_rgb_led_handle_t *h)
{
    switch (h->state)
    {
    case RGB_LED_STATE_OFF:
        return 0;
    case RGB_LED_STATE_RED:
        return timerRgb_getRedPercentDuty(h);
        break;
    case RGB_LED_STATE_GREEN:
        return timerRgb_getGreenPercentDuty(h);
        break;
    case RGB_LED_STATE_BLUE:
        return timerRgb_getBluePercentDuty(h);
        break;
    default:
        return -1;
        break;
    }
}

int timerRgb_setLedRedPercentDuty(timer_rgb_led_handle_t *h, unsigned int duty)
{
    uint32_t register_duty;
	if( duty > 100 )
	{
		return -1;
	}
	_led_current_period_settings = __HAL_TIM_GET_AUTORELOAD(h->timer_handle);
	register_duty = ( _led_current_period_settings * duty ) / 100;
    h->red.percent_duty = duty;

	__HAL_TIM_SET_COMPARE(h->timer_handle, h->red.channel, register_duty);
	return 0;

}

int timerRgb_setLedGreenPercentDuty(timer_rgb_led_handle_t *h, unsigned int duty)
{
    uint32_t register_duty;
	if( duty > 100 )
	{
		return -1;
	}
	_led_current_period_settings = __HAL_TIM_GET_AUTORELOAD(h->timer_handle);
	register_duty = ( _led_current_period_settings * duty ) / 100;
    h->green.percent_duty = duty;

	__HAL_TIM_SET_COMPARE(h->timer_handle, h->green.channel, register_duty);
	return 0;

}

int timerRgb_setLedBluePercentDuty(timer_rgb_led_handle_t *h, unsigned int duty)
{
    uint32_t register_duty;
	if( duty > 100 )
	{
		return -1;
	}
	_led_current_period_settings = __HAL_TIM_GET_AUTORELOAD(h->timer_handle);
	register_duty = ( _led_current_period_settings * duty ) / 100;
    h->blue.percent_duty = duty;

	__HAL_TIM_SET_COMPARE(h->timer_handle, h->blue.channel, register_duty);
	return 0;

}

int timerRgb_setLedPercentDuty(timer_rgb_led_handle_t *h, unsigned int duty)
{
    return (timerRgb_setLedRedPercentDuty(h, duty) && \
    timerRgb_setLedGreenPercentDuty(h, duty) && \
    timerRgb_setLedBluePercentDuty(h, duty));
}


int timerRgb_SetOff(timer_rgb_led_handle_t *h)
{
    if( HAL_TIM_PWM_Stop_IT(h->timer_handle, h->red.channel)  || \
        HAL_TIM_PWM_Stop_IT(h->timer_handle, h->green.channel) || \
        HAL_TIM_PWM_Stop_IT(h->timer_handle, h->blue.channel) != HAL_OK )
    {
        h->state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    h->state = RGB_LED_STATE_OFF;
    return 0;
}

int timerRgb_SetRed(timer_rgb_led_handle_t *h)
{
    if( HAL_TIM_PWM_Start_IT(h->timer_handle, h->red.channel)  || \
        HAL_TIM_PWM_Stop_IT(h->timer_handle, h->green.channel) || \
        HAL_TIM_PWM_Stop_IT(h->timer_handle, h->blue.channel) != HAL_OK )
    {
        h->state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    h->state = RGB_LED_STATE_RED;
    return 0;
}

int timerRgb_SetGreen(timer_rgb_led_handle_t *h)
{
    if( HAL_TIM_PWM_Stop_IT(h->timer_handle, h->red.channel)  || \
        HAL_TIM_PWM_Start_IT(h->timer_handle, h->green.channel) || \
        HAL_TIM_PWM_Stop_IT(h->timer_handle, h->blue.channel) != HAL_OK )
    {
        h->state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    {
        h->state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    h->state = RGB_LED_STATE_GREEN;
    return 0;
}

int timerRgb_SetBlue(timer_rgb_led_handle_t *h)
{
    if( HAL_TIM_PWM_Stop_IT(h->timer_handle, h->red.channel)  || \
        HAL_TIM_PWM_Stop_IT(h->timer_handle, h->green.channel) || \
        HAL_TIM_PWM_Start_IT(h->timer_handle, h->blue.channel) != HAL_OK )
    {
        h->state = RGB_LED_STATE_UNKNOWN;
        return -1;
    }
    h->state = RGB_LED_STATE_BLUE;
    return 0;
}

void timerRgb_Init(timer_rgb_led_handle_t *h)
{
    timerRgb_setLedRedPercentDuty( h , h->red.percent_duty);
    timerRgb_setLedGreenPercentDuty( h , h->green.percent_duty);
    timerRgb_setLedBluePercentDuty( h , h->blue.percent_duty);

    switch (h->state)
    {
    case RGB_LED_STATE_RED:
        timerRgb_SetRed(h);
        break;
    case RGB_LED_STATE_GREEN:
        timerRgb_SetGreen(h);
        break;
    case RGB_LED_STATE_BLUE:
        timerRgb_SetBlue(h);
        break;
    
    default:
        timerRgb_SetOff(h);
        break;
    }
}
