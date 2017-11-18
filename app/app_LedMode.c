/*
 * app_LedMode.c
 *
 *  Created on: 09/11/2017
 *      Author: Christopher Gomez
 */

#include "stdtypedef.h"
#include "..\source\MAL\mal_LedSet.h"

/* Function called to initiate a sequence of switching color of the leds*/

void app_SequenceForward(void)
{
	static T_UBYTE lub_LedSelect;

	switch (lub_LedSelect)
	{
		case LED_RED:	//Solo el led rojo enciende
		{
			lub_LedSelect = LED_GREEN;
			mal_TurnOnLeds(LED_RED);
			mal_TurnOffLeds(LED_GREEN);
			mal_TurnOffLeds(LED_BLUE);
			break;
		}
		case LED_GREEN:	//Solo el led verde enciende
		{
			lub_LedSelect = LED_BLUE;
			mal_TurnOffLeds(LED_RED);
			mal_TurnOnLeds(LED_GREEN);
			mal_TurnOffLeds(LED_BLUE);
			break;
		}

		case LED_BLUE:	//Solo el led azul enciende
		{
			lub_LedSelect = LED_RED;
			mal_TurnOffLeds(LED_RED);
			mal_TurnOffLeds(LED_GREEN);
			mal_TurnOnLeds(LED_BLUE);

			break;
		}
	}
}

/* Function called to turn off all the Leds*/

void app_SequenceTerminated(void)
	{

	mal_TurnOffLeds(LED_RED);
	mal_TurnOffLeds(LED_GREEN);
	mal_TurnOffLeds(LED_BLUE);

	}

