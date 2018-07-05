/**
 * LCD control functions
 *
 * LCD data pins [7:4] are connected to PORTD[4:7]. Change pin mask for port D in lcd1602.h if connection changes 
 */

#include "atmel_start_pins.h"
#include "lcd1602.h"
#include <util/delay.h>


void lcd_init()
{
	_delay_ms(LCD_BOOTUP_MS);
	
	LCD_RS_set_level(false);
	LCD_RW_set_level(false);
	
	lcd_set_data(0x30 >> 4);
	lcd_enable();
	_delay_ms(5);
	
	lcd_enable();
	_delay_ms(1);

	lcd_enable();
	_delay_ms(1);	

	lcd_set_data((LCD_SET_FUNCTION | LCD_FUNCTION_4BIT) >> 4);
	lcd_enable();					 
	_delay_ms(LCD_SET_4BITMODE_MS);
	
	lcd_write( LCD_SET_FUNCTION |
	LCD_FUNCTION_4BIT |
	LCD_FUNCTION_2LINE |
	LCD_FUNCTION_5X7, false );
	
	lcd_write( LCD_SET_DISPLAY |
	LCD_DISPLAY_ON |
	LCD_CURSOR_ON |
	LCD_BLINKING_ON, false);
	
	lcd_write( LCD_SET_ENTRY |
	LCD_ENTRY_INCREASE |
	LCD_ENTRY_NOSHIFT , false);
				 
	lcd_clear();
}

void lcd_clear()
{
	lcd_write(LCD_CLEAR_DISPLAY, false);
	_delay_ms(LCD_CLEAR_DISPLAY_MS);
}

void lcd_enable()
{
	LCD_ENABLE_set_level(true);
	_delay_us(LCD_ENABLE_US);
	LCD_ENABLE_set_level(false);
}


// 4-bit data nibble expected in lower part of data byte
void lcd_set_data(uint8_t data)
{
	PORTD_set_port_level(LCD_DATA_MASK, false); // clear
	PORTD_set_port_level(LCD_DATA_MASK & (data << LCD_DATA_LSB), true);
}


void lcd_write(uint8_t data, bool sel_data_cmd)
{
	LCD_RS_set_level(sel_data_cmd);
	LCD_RW_set_level(false);
		
	lcd_set_data((data >> 4) & 0x0f);	// upper nibble
	lcd_enable();
	lcd_set_data(data & 0x0f);	// lower nibble
	lcd_enable();
	if (sel_data_cmd) {
		_delay_us(LCD_WRITEDATA_US);	
	} else {
		_delay_us(LCD_COMMAND_US);	
	}
}

void lcd_string( const char *data )
{
	while( *data != '\0' )
	lcd_write( *data++, true); // write data (character)
}
