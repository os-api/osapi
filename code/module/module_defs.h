/*
 * module_defs.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 *      Scope: Public
 */

#ifndef MODULE_DEFS_H_
#define MODULE_DEFS_H_

// The number of bits above results in the maximum values as follows:
#define OSAPI_MAX_MODULES		64 		//2^STATUS_BITS_MODULES;
#define OSAPI_MAX_FUNCTIONS		1024 		// 2^STATUS_BITS_FUNCTIONS;
//#define OSAPI_MAX_CODES		2^STATUS_BITS_CODE;

// List of API Modules (Only up to OSAPI_MAX_MODULES can be defined)
enum
{
	NONE = 0,
	PROC,
	MACHINE,
	HW,
	OS,
	IO,
	SEC,
	CLOCK,
	UTIL,
	STRING
};


#endif /* MODULE_DEFS_H_ */
