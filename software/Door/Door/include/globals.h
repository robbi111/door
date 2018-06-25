/*
 * globals.h
 *
 * Created: 25/06/2018 21:27:21
 *  Author: Robert
 */ 


#ifndef GLOBALS_H_
#define GLOBALS_H_

typedef struct  
{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
} time_type;

time_type current_time, open_time, close_time;


#endif /* GLOBALS_H_ */