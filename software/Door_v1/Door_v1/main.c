#include <atmel_start.h>

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	cpu_irq_enable();
	
	sleep_set_mode(0 << SM2 | 1 << SM1 | 0 << SM0);
	sleep_enable();

	/* Replace with your application code */
	while (1) {
		sleep_enter();
	}
}
