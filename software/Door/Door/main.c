#include <atmel_start.h>
#include <globals.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	
	//lcd_string("Welt");
	lcd_write('R', true);
	lcd_write('o', true);
	lcd_write('b', true);
	lcd_write('e', true);
	lcd_write('r', true);
	lcd_write('t', true);
	
	/* Replace with your application code */
	while (1) {
		
	}
}
