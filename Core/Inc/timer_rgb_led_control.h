/**
 * @file timer_rgb_led_control.h
 * @author Ivin Lim (ivin.lim16@gmail.com)
 * @brief 
 *      Holds interface towards RGB Led handle to control LED state (OFF, RED, GREEN, BLUE only) and its 5brightness.
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INC_TIMER_RGB_LED_CONTROL_H_
#define INC_TIMER_RGB_LED_CONTROL_H_

#include "tim.h"


typedef enum
{
    RGB_LED_STATE_OFF = 0,
    RGB_LED_STATE_RED = 1,
    RGB_LED_STATE_GREEN = 2,
    RGB_LED_STATE_BLUE = 3,
    RGB_LED_STATE_UNKNOWN = 4,
}rgb_led_state_t;

/**
 * @brief 
 * 
 */
typedef struct
{
    /* data */
    uint32_t channel;                   /* channel number within general timer */
    uint8_t percent_duty;                       /* duty in percent from 0-100 */
}led_handle_t;

typedef struct 
{
    /* data */
    TIM_HandleTypeDef* timer_handle;    /* Interface to the HAL timer handle*/
    led_handle_t red;
    led_handle_t green;
    led_handle_t blue;
    rgb_led_state_t state;

}timer_rgb_led_handle_t;

//Getters
rgb_led_state_t timerRgb_getState(timer_rgb_led_handle_t *h);
int8_t timerRgb_getRedPercentDuty(timer_rgb_led_handle_t *h);
int8_t timerRgb_getGreenPercentDuty(timer_rgb_led_handle_t *h);
int8_t timerRgb_getBluePercentDuty(timer_rgb_led_handle_t *h);

/**
 * @brief returns the duty cycle of the active state, if OFF, returns 0
 * 
 * @param h 
 * @return int8_t 
 */
int8_t timerRgb_getPercentDuty(timer_rgb_led_handle_t *h);

//Setters
int timerRgb_setLedRedPercentDuty(timer_rgb_led_handle_t *h, unsigned int duty);
int timerRgb_setLedGreenPercentDuty(timer_rgb_led_handle_t *h, unsigned int duty);
int timerRgb_setLedBluePercentDuty(timer_rgb_led_handle_t *h, unsigned int duty);
/**
 * @brief 
 * 
 * @param h rgb handle
 * @param duty percent duty from 0-100
 * @return int 
 */
int timerRgb_setLedPercentDuty(timer_rgb_led_handle_t *h, unsigned int duty);
int timerRgb_SetRed(timer_rgb_led_handle_t *h);
int timerRgb_SetGreen(timer_rgb_led_handle_t *h);
int timerRgb_SetBlue(timer_rgb_led_handle_t *h);

void timerRgb_Init(timer_rgb_led_handle_t *h);





#endif /* INC_TIMER_RGB_LED_CONTROL_H_ */
