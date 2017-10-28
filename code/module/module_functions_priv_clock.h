/*
 * status_func_clock.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef MODULE_FUNCTIONS_PRIV_CLOCK_H_
#define MODULE_FUNCTIONS_PRIV_CLOCK_H_

// Name of functions of CLOCK Module
static const char * module_func_clock[ OSAPI_MAX_FUNCTIONS ] =
{
	"Call successful",		// = 0
	"module_supported",		// = 1
	"time_set",			// = 2
	"time_get",			// = 3
	"time_print",			// = 4
	"time_diff",			// = 5
	"localTime_get",		// = 6
	"timeZone_set",			// = 7
	"timeZone_get",			// = 8

	OSAPI_EMPTY_STRING
};



#endif /* MODULE_FUNCTIONS_PRIV_CLOCK_H_ */
