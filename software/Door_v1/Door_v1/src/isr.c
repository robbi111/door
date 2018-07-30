/*
 * isr.c
 *
 * Created: 06/07/2018 12:38:05
 *  Author: Robert
 */ 
#include <atmel_start.h>


ISR(PCINT0_vect) {
	if (OPEN_CLOSE_get_level()) {	// open door
		while (!TOP_SENS_get_level())	// check if top sensor is reached
		{
			MOTOR_FWD_set_level(true);
			MOTOR_REV_set_level(false);
		}
		MOTOR_FWD_set_level(false);
		MOTOR_REV_set_level(false);
	} else {
		while (!BOTTOM_SENS_get_level())	// check if bottom sensor is reached
		{
			MOTOR_FWD_set_level(false);
			MOTOR_REV_set_level(true);
		}
		MOTOR_FWD_set_level(false);
		MOTOR_REV_set_level(false);
	}
}