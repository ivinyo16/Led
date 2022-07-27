/**
 * @file rgb_led_state.h
 * @author Ivin Lim (ivin.lim16@gmail.com.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INC_RGB_LED_STATE_H_
#define INC_RGB_LED_STATE_H_

typedef enum
{
    RGB_LED_STATE_OFF = 0,
    RGB_LED_STATE_RED = 1,
    RGB_LED_STATE_GREEN = 2,
    RGB_LED_STATE_BLUE = 3,
    RGB_LED_STATE_UNKNOWN = 4,
}rgb_led_state_t;

rgb_led_state_t rgbLedState_GetState(void);

//setters
int rgbLedState_SetOff(void);
int rgbLedState_SetRed(void);
int rgbLedState_SetBlue(void);
int rgbLedState_SetGreen(void);

void rgbLedStateInit(void);
void rgbLedStateUpdate(void);

#endif /* INC_RGB_LED_STATE_H_ */
