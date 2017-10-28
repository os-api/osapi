/*
 * error_priv_string.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_STRING_H_
#define ERROR_PRIV_STRING_H_

#include "../../code/error/error_string.h"

static const char * string_errors[ OSAPI_ERROR_NUMBERS ] =
{
	OSAPI_ERROR_GENERIC,
	OSAPI_ERROR_SUPPORT,
	OSAPI_ERROR_INVPARAM,
	"Unable to create string",
	"Empty pointer location",
	"String exists already",
	"Not enough space",
	"The string is the same",
	OSAPI_ERROR_UNKNOWN
};

#endif /* ERROR_PRIV_STRING_H_ */
