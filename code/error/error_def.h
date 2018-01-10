/*
 * error_def.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_DEF_H_
#define ERROR_DEF_H_

#include <limits.h>
#include <errno.h>

#define	ERROR_BASE		1
#define ERROR_MAX		INT_MAX

// Define Generic Error strings
#define OSAPI_ERROR_GENERIC	"Generic Error"
#define OSAPI_ERROR_SUPPORT	"Unsupported function"
#define OSAPI_ERROR_INVPARAM	"Invalid Parameter(s)"
#define OSAPI_ERROR_UNKNOWN	"Unknown error"


#endif /* ERROR_DEF_H_ */
