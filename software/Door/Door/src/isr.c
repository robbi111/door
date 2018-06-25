/*
 * isr.c
 *
 * Contains interrupt service routines for TIMER2, button panel, analog compare
 * Created: 25/06/2018 21:25:25
 *  Author: Robert
 */ 

#include <driver_init.h>
#include <compiler.h>
#include "atmel_start_pins.h"


/*
 * TIMER2 overflow interrupt
 * interrupt every second (32.768 kHz clock with 128 prescaler)
 *
*/
ISR(TIMER2_OVF_vect)
{
	LED_0_toggle_level();
}

/*
 * Pin change 2 request interrupt
 *
*/
ISR(PCINT2_vect)
{
	// check which button was pressed	
}