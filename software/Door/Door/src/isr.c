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
#include <util/delay.h>


/*
 * TIMER2 overflow interrupt
 * interrupt every second (32.768 kHz clock with 128 prescaler)
 *
*/
ISR(TIMER2_OVF_vect)
{
	//LED_0_toggle_level();
}


void blink_LED(int interval_ms)
{
	uint8_t i = 0;
	for (i; i++; i<10)
	{
		LED_0_toggle_level();
		_delay_ms(interval_ms);
	}
}

/*
 * Pin change 2 request interrupt
 *
*/
ISR(PCINT0_vect)
{
	_delay_ms(100);
	// check which button was pressed
	while (!BUTTON_MODE_get_level())
	{
		LED_0_toggle_level();
		_delay_ms(500);
	} 
// 	else if (!BUTTON_PLUS_get_level())
// 	{
// 		blink_LED(250);
// 	}
// 	else if (!BUTTON_MINUS_get_level())
// 	{
// 		blink_LED(500);
// 	}
// 	else if (!BUTTON_OK_get_level())
// 	{
// 		blink_LED(1000);
// 	}
}