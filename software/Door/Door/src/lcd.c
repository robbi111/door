/**
 * \file
 *
 * \brief MEGA LED Example
 *
 * Copyright (C) 2015-2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

/**
 * \mainpage MEGA LED Example
 * See \ref appdoc_main "here" for project documentation.
 * \copydetails appdoc_preface
 *
 *
 * \page appdoc_preface Overview
 * This application demonstrates a simple example to turn on and off the board LED.
 */

/**
 * \page appdoc_main MEGA LED Example
 *
 * Overview:
 * - \ref appdoc_mega_led_app_intro
 * - \ref appdoc_mega_led_app_usage
 * - \ref appdoc_mega_led_app_compinfo
 * - \ref appdoc_mega_led_app_contactinfo
 *
 * \section appdoc_mega_led_app_intro Introduction
 * This application demonstrates a simple example turn on and off the board LED.
 *
 * This application has been tested on following boards:
 * - ATmega328p Xplained Mini
 * - ATmega328pb Xplained Mini
 * - ATmega168pb Xplained Mini
 * - ATmega324pb Xplained PRO
 *
 * \section appdoc_mega_led_app_usage Usage
 * The application uses button to control the LED, 
 * once the button is pressed, LED0 will turn on
 * once the button is released, LED0 will turn off
 *
 * \section appdoc_mega_led_app_compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for MEGA.
 * Other compilers may or may not work.
 *
 * \section appdoc_mega_led_app_contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com">http://www.atmel.com</a>.
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include "lcd1602.h"

void lcd_set_data(uint8_t data)
{
	ioport_set_port_level(LCD_DATA,LCD_DATA_MASK, 0); // clear LCD data bus
	ioport_set_port_level(LCD_DATA,LCD_DATA_MASK & data, 1); // set new data
}

void lcd_init()
{
	delay_ms(LCD_BOOTUP_MS);
	
	ioport_set_pin_low(LCD_RS);
	ioport_set_pin_low(LCD_RW);
	
	lcd_set_data(0x30);
	lcd_enable();
	delay_ms(5);
	
	lcd_enable();
	delay_ms(1);

	lcd_enable();
	delay_ms(1);	

	lcd_set_data(LCD_SET_FUNCTION | LCD_FUNCTION_4BIT);
	lcd_enable();					 
	delay_ms(LCD_SET_4BITMODE_MS);
	
	lcd_write_cmd( LCD_SET_FUNCTION |
	LCD_FUNCTION_4BIT |
	LCD_FUNCTION_2LINE |
	LCD_FUNCTION_5X7 );
	
	lcd_write_cmd( LCD_SET_DISPLAY |
	LCD_DISPLAY_ON |
	LCD_CURSOR_OFF |
	LCD_BLINKING_OFF);
	
	lcd_write_cmd( LCD_SET_ENTRY |
	LCD_ENTRY_INCREASE |
	LCD_ENTRY_NOSHIFT );
				 
	lcd_clear();
}

void lcd_clear()
{
	lcd_write_cmd(LCD_CLEAR_DISPLAY);
	delay_ms(LCD_CLEAR_DISPLAY_MS);
}

void lcd_enable()
{
	ioport_set_pin_high(LCD_E);
	delay_us(LCD_ENABLE_US);
	ioport_set_pin_low(LCD_E);	
}

void lcd_write_cmd(uint8_t data)
{
	ioport_set_pin_low(LCD_RS);
	ioport_set_pin_low(LCD_RW);
		
	lcd_set_data(LCD_DATA_MASK & data);	// upper nibble
	lcd_enable();
	lcd_set_data(data << 4);	// lower nibble
	lcd_enable();
	delay_us(LCD_COMMAND_US);
}

void lcd_write_data(uint8_t data)
{
	ioport_set_pin_high(LCD_RS);
	ioport_set_pin_low(LCD_RW);
	
	lcd_set_data(LCD_DATA_MASK & data);	// upper nibble
	lcd_enable();
	lcd_set_data(data << 4);	// lower nibble
	lcd_enable();
	delay_us(LCD_WRITEDATA_US);
}

void lcd_string( const char *data )
{
	while( *data != '\0' )
	lcd_write_data( *data++ );
}

int main (void)
{
	/* set board io port */
	sysclk_init();
	board_init();
	lcd_init();
	
 	lcd_string("Hallo Welt!");
	while(1){
		LED_Toggle(USER_LED);
		delay_ms(1000);
	}	
}
