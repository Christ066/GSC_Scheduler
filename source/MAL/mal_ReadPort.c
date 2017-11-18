/*
 * mal_ReadPort.c
 *
 *  Created on: 12/11/2017
 *      Author: Christopher Gomez
 */

#include "stdint.h"
#include "stdtypedef.h"
#include "fsl_gpio.h"
#include "mal_ReadPort.h"
#include "..\app\app_LedMode.h"


T_UBYTE rub_ButtonValid = FALSE;
T_UBYTE rub_SkipSong = FALSE;
T_UBYTE rub_FwdSong = FALSE;
T_UBYTE rub_Shutdown = FALSE;
T_UWORD ruw_DbncCounter;


typedef enum
{
	BUTTON_PRESSED = 0u,
	BUTTON_UNPRESSED

}T_BUTTON_STATES;



/*Function called every 5 ms for Debounce Function */

void mal_DebounceConfig()
{
	/*Leer un cero a la entrada del puerto B-8 con el boton presionado*/

	if(GPIO_ReadPinInput(GPIOB, 8u) == BUTTON_PRESSED)
	{
		if(ruw_DbncCounter < 10000u) //Detener contador cuando sea mayor a 10 segundos
		{
			ruw_DbncCounter+=5; //incrementar contador de 5 en 5
		}
			else
			{
				//No hacer nada
			}
	}
	else
	{
		ruw_DbncCounter = 0u; //Si el boton se suelta se limpia el contador de debounce
	}

	/* Verify if counter has reached 50 ms to validate a button */
	if(ruw_DbncCounter >= 50u)
	{
		rub_ButtonValid = TRUE; //Activar bandera de botón válido
	}
		else
		{
			rub_ButtonValid = FALSE; //De lo contrario no activar bandera antes de 50 ms
		}

	/*Verify if the counter has reached 600ms*/
	if(ruw_DbncCounter == 600u)
	{
		rub_SkipSong = TRUE; //Activar bandera para la función de cambiar color de led a los 600ms
	}

		else
		{
			rub_SkipSong = FALSE; //Limpiar bandera de cambio de led a a cualquier otro valor que no sea 600ms
		}

	/*Check if the counter reached 1 seg*/
	if(ruw_DbncCounter >= 1000u)
	{
		rub_FwdSong = TRUE; //Activar bandera para cambio de led cada 500ms
	}

		else
		{
			rub_FwdSong = FALSE; //Limpiar bandera de cambio de leds cada 500 ms
		}

	/* When the counter reaches 10 sec turn off all the leds*/
	if(ruw_DbncCounter >= 10000u)
	{
		rub_Shutdown = TRUE; //Activar bandera para apagar todos los leds
		rub_FwdSong = FALSE; //Limpiar bandera de cambio de leds cada 500ms
	}

		else
		{
			rub_Shutdown = FALSE; //Limpiar bandera de apagado de todos los leds
		}


}

/* Function called when timer reaches 600ms */

void mal_SkipSong()
{

	if(rub_ButtonValid && rub_SkipSong)
	{
		app_SequenceForward(); //Initialize sequence of switching leds
	}
		else
		{
			//No hacer nada
		}

}

/* Function called after been pressed the button for more than 1s,
 * switch color of the led every 500ms */

void mal_ForwardSong()
{
	if(rub_ButtonValid && rub_FwdSong)
	{
		app_SequenceForward(); //Initialize sequence of switching leds
	}
		else
		{
			//No hacer nada
		}
}



/* Turn off all the LEDS when the timer reaches 10seg*/

void mal_ShutdownSystem()
{
	if(rub_ButtonValid && rub_Shutdown)
	{
		app_SequenceTerminated(); //Function for turning off all leds

	}
		else
		{
			//No hacer nada
		}
}

