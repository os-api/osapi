/*
 * status_os_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_OS_H_
#define ERROR_PRIV_OS_H_

#include "../../code/error/error_os.h"

static const char * os_errors[ OSAPI_ERROR_NUMBERS ] =
{
	OSAPI_ERROR_GENERIC,
	OSAPI_ERROR_SUPPORT,
	OSAPI_ERROR_INVPARAM,
	OSAPI_ERROR_UNKNOWN
};

#endif /* ERROR_PRIV_OS_H_ */
