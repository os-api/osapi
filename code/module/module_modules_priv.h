/*
 * status_modules.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 *      Scope: Private
 */

#ifndef MODULE_MODULES_PRIV_H_
#define MODULE_MODULES_PRIV_H_

// This private header contains the name of all library modules

static const char * module_name[] =
{
		       "NONE",			// = 0
		       "STRING",		// = 1
		       "PROC",			// = 2
		       "MACHINE",		// = 3
		       "HW",			// = 4
		       "OS",			// = 5
		       "IO",			// = 6
		       "SEC",			// = 7
		       "CLOCK",			// = 8
		       "UTIL",			// = 9

		       OSAPI_EMPTY_STRING	// = Last + 1
};


#endif /* MODULE_MODULES_PRIV_H_ */
