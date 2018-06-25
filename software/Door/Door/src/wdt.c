/*
 * wdt.c
 *
 * Created: 25/06/2018 21:18:33
 *  Author: Robert
 */ 

#include "wdt.h"

void WDT_init()
{
	WDT_off();
}

void WDT_off()
{
	__disable_interrupt();
	__watchdog_reset();
	/* Clear WDRF in MCUSR */
	MCUSR &= ~(1<<WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/* Turn off WDT */
	WDTCSR = 0x00;
	__enable_interrupt();
}