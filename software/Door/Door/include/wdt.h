/*
 * wdt.h
 *
 * Created: 25/06/2018 21:13:32
 *  Author: Robert
 */ 
#ifdef __cplusplus
extern "C" {
#endif


#ifndef WDT_H_
#define WDT_H_

#include <compiler.h>

#ifdef __cplusplus
extern "C" {
	#endif

		void WDT_init();
		void WDT_off();

	#ifdef __cplusplus
}
#endif


#endif /* WDT_H_ */

