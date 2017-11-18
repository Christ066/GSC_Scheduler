/*
 * mal_LedSet.h
 *
 *  Created on: 09/11/2017
 *      Author: Christopher Gomez
 */

#ifndef MAL_MAL_LEDSET_H_
#define MAL_MAL_LEDSET_H_


typedef enum
{
	LED_RED = 0U,
	LED_GREEN,
	LED_BLUE,
	TOTAL_LEDS,

}LED_COLOR;

/*Prototypes*/

extern void mal_TurnOnLeds(LED_COLOR led_color);
extern void mal_TurnOffLeds(LED_COLOR led_color);


#endif /* MAL_MAL_LEDSET_H_ */
