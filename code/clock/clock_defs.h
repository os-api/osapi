/*
 * clock_defs.h
 *
 *  Created on: 29/04/2017
 *      Author: joao
 */

#ifndef CLOCK_DEFS_H_
#define CLOCK_DEFS_H_

// Define function IDs
enum
{
        f_clock_none = 0,
	f_clock_module_supported,
	f_clock_time_set,
	f_clock_time_get,
	f_clock_time_print,
	f_clock_time_diff,
	f_clock_localTime_get,
	f_clock_timeZone_set,
	f_clock_timeZone_get

};


#endif /* CLOCK_DEFS_H_ */
