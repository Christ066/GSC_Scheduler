/*
 * GPIO_setup.c
 *
 *  Created on: 07/11/2017
 *      Author: Christopher Gomez
 */

#include "hal_GpioSetup.h"
#include "stdio.h"
#include "MKL25Z4.h"
#include "stdtypedef.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"



void hal_InitPort(void)
{


	/* Enable the clock for the modules needed */

	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortD);

	/* PORT Module Configuration */

	port_pin_config_t ls_PortSet;

	ls_PortSet.mux = kPORT_MuxAsGpio;	//Configurar puerto como GPIO
	ls_PortSet.pullSelect = kPORT_PullUp; //Activar resistencia pull-up

	port_pin_config_t *lps_PortSet;

	lps_PortSet = &ls_PortSet;

	PORT_SetPinConfig(PORTB, 8U, lps_PortSet);
	PORT_SetPinConfig(PORTB, 18U, lps_PortSet);
	PORT_SetPinConfig(PORTB, 19U, lps_PortSet);
	PORT_SetPinConfig(PORTD, 1U, lps_PortSet);

	/**********************************/
	/* GPIO Configuration for Inputs */
	/*********************************/

	gpio_pin_config_t ls_GPIOPinSet;

	ls_GPIOPinSet.pinDirection = kGPIO_DigitalInput;
	ls_GPIOPinSet.outputLogic = TRUE;				/* Es necesaria esta linea de codigo? */

	gpio_pin_config_t *lps_GPIOPinSet;

	lps_GPIOPinSet = &ls_GPIOPinSet;

	GPIO_PinInit(GPIOB, 8U, lps_GPIOPinSet);


	/***********************************/
	/* GPIO Configuration for Outputs */
	/*********************************/

	ls_GPIOPinSet.pinDirection = kGPIO_DigitalOutput;
	ls_GPIOPinSet.outputLogic = TRUE; 				//LEDs Off
	GPIO_PinInit(GPIOB, 18U, lps_GPIOPinSet);
	GPIO_PinInit(GPIOB, 19U, lps_GPIOPinSet);
	GPIO_PinInit(GPIOD, 1U, lps_GPIOPinSet);

}


