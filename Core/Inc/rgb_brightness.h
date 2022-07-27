/**
 * @file rgb_brightness.h
 * @author Ivin Lim (ivin.lim16@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INC_RGB_BRIGHTNESS_H_
#define INC_RGB_BRIGHTNESS_H_

#include "tim.h"

int rgbBrightness_setLedRedBrightness(unsigned int duty);
int rgbBrightness_setLedGreenBrightness(unsigned int duty);
int rgbBrightness_setLedBlueBrightness(unsigned int duty);
int rgbBrightness_setLedBrightness(unsigned int duty);


#endif /* INC_RGB_BRIGHTNESS_H_ */
