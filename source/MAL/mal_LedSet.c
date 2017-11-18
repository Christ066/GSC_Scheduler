/*
 * mal_LedSet.c
 *
 *  Created on: 09/11/2017
 *      Author: Christopher Gomez
 */


#include "MKL25Z4.h"
#include "mal_LedSet.h"
#include "stdtypedef.h"

#define RED				(18)
#define RED_SHIFT		(1 << 18)
#define GREEN			(19)
#define GREEN_SHIFT		(1 << 19)
#define BLUE			(1)
#define BLUE_SHIFT		(1 << 1)

#define RED_OFF			(GPIOB->PSOR = RED_SHIFT)
#define RED_ON			(GPIOB->PCOR = RED_SHIFT)
#define RED_TOGGLE		(GPIOB->PTOR = RED_SHIFT)

#define GREEN_OFF		(GPIOB->PSOR = GREEN_SHIFT)
#define GREEN_ON		(GPIOB->PCOR = GREEN_SHIFT)
#define GREEN_TOGGLE	(GPIOB->PTOR = GREEN_SHIFT)

#define BLUE_OFF		(GPIOD->PSOR = BLUE_SHIFT)
#define BLUE_ON			(GPIOD->PCOR = BLUE_SHIFT)
#define BLUE_TOGGLE		(GPIOD->PTOR = BLUE_SHIFT)

/*Function for only turning on leds*/

void mal_TurnOnLeds(LED_COLOR led_color)
{
	switch(led_color)
	{
		case LED_RED:
		{
			RED_ON;
			break;
		}
		case LED_GREEN:
		{
			GREEN_ON;
			break;
		}
		case LED_BLUE:
		{
			BLUE_ON;
			break;
		}
		case TOTAL_LEDS:
		{
			break;
		}
	}

}

/* Function for only turning off leds */

void mal_TurnOffLeds(LED_COLOR led_color)
{
	switch(led_color)
	{
		case LED_RED:
		{
			RED_OFF;
			break;
		}
		case LED_GREEN:
		{
			GREEN_OFF;
			break;
		}
		case LED_BLUE:
		{
			BLUE_OFF;
			break;
		}
		case TOTAL_LEDS:
		{
			break;
		}

	}

}
