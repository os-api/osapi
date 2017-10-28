/*
 * error_def.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_DEF_H_
#define ERROR_DEF_H_

#include <errno.h>

// Define Lib errors starting at a given point in the range of possible errors (0x0000 to 0xFFFF)
#define OSAPI_ERROR_BASE	0xEEEE
#define OSAPI_ERROR_MAX		0xFFFF
#define OSAPI_ERROR_NUMBERS	(OSAPI_ERROR_MAX - OSAPI_ERROR_BASE)

// Define Generic Error strings
#define OSAPI_ERROR_GENERIC	"Generic Error"
#define OSAPI_ERROR_SUPPORT	"Unsupported function"
#define OSAPI_ERROR_INVPARAM	"Invalid Parameter(s)"
#define OSAPI_ERROR_UNKNOWN	"Unknown error"


#endif /* ERROR_DEF_H_ */
