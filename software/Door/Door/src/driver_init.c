/**
 * \file
 *
 * \brief Driver initialization.
 *
 (c) 2018 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/*
 * Code generated by START.
 *
 * This file will be overwritten when reconfiguring your START project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <system.h>

void EXTERNAL_IRQ_0_initialization(void)
{

	// Set pin direction to input
	SENS_BOTTOM_set_dir(PORT_DIR_IN);

	SENS_BOTTOM_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_OFF);

	// Set pin direction to input
	SENS_TOP_set_dir(PORT_DIR_IN);

	SENS_TOP_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_OFF);

	// Set pin direction to input
	BUTTON_OK_set_dir(PORT_DIR_IN);

	BUTTON_OK_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_UP);

	// Set pin direction to input
	BUTTON_MINUS_set_dir(PORT_DIR_IN);

	BUTTON_MINUS_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_UP);

	// Set pin direction to input
	BUTTON_PLUS_set_dir(PORT_DIR_IN);

	BUTTON_PLUS_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_UP);

	// Set pin direction to input
	BUTTON_MODE_set_dir(PORT_DIR_IN);

	BUTTON_MODE_set_pull_mode(
	    // <y> Pull configuration
	    // <id> pad_pull_config
	    // <PORT_PULL_OFF"> Off
	    // <PORT_PULL_UP"> Pull-up
	    PORT_PULL_UP);

	EXTERNAL_IRQ_0_init();
}

/* Configure pins and initialize registers */
void ADC_0_initialization(void)
{

	ADC_0_init();
}

/* Configure pins and initialize registers */
void AC_0_initialization(void)
{

	AC_0_init();
}

void TIMER_2_initialization(void)
{

	TIMER_2_init();
}


/**
 * \brief System initialization
 */
void system_init()
{
	mcu_init();

	/* PORT setting on PC0 */

	// Disable pull-up.
	//LIGHT_SENS_set_pull_mode(PORT_PULL_OFF);

	/* PORT setting on PC4 */

	// Set pin direction to output
	MOTOR_FWD_set_dir(PORT_DIR_OUT);

	MOTOR_FWD_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PC5 */

	// Set pin direction to output
	MOTOR_REV_set_dir(PORT_DIR_OUT);

	MOTOR_REV_set_level(
	    // <y> Initial level
	    // <id> pad_initial_level
	    // <false"> Low
	    // <true"> High
	    false);

	/* PORT setting on PD0 */

	// Set pin direction to output
// 	LCD_RS_set_dir(PORT_DIR_OUT);
// 
// 	LCD_RS_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD1 */
// 
// 	// Set pin direction to output
// 	LCD_RW_set_dir(PORT_DIR_OUT);
// 
// 	LCD_RW_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD2 */
// 
// 	// Set pin direction to output
// 	LCD_ENABLE_set_dir(PORT_DIR_OUT);
// 
// 	LCD_ENABLE_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD3 */
// 
// 	// Set pin direction to output
// 	LED_0_set_dir(PORT_DIR_OUT);
// 
// 	LED_0_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD4 */
// 
// 	// Set pin direction to output
// 	LCD_DATA0_set_dir(PORT_DIR_OUT);
// 
// 	LCD_DATA0_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD5 */
// 
// 	// Set pin direction to output
// 	LCD_DATA1_set_dir(PORT_DIR_OUT);
// 
// 	LCD_DATA1_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD6 */
// 
// 	// Set pin direction to output
// 	LCD_DATA2_set_dir(PORT_DIR_OUT);
// 
// 	LCD_DATA2_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);
// 
// 	/* PORT setting on PD7 */
// 
// 	// Set pin direction to output
// 	LCD_DATA3_set_dir(PORT_DIR_OUT);
// 
// 	LCD_DATA3_set_level(
// 	    // <y> Initial level
// 	    // <id> pad_initial_level
// 	    // <false"> Low
// 	    // <true"> High
// 	    false);

	sysctrl_init();
	
	WDT_init();

	EXTERNAL_IRQ_0_initialization();

	//ADC_0_initialization();

	//AC_0_initialization();

// 	TIMER_2_initialization();
// 	
// 	lcd_init();

}
