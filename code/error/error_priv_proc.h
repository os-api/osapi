/*
 * status_proc_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_PROC_H_
#define ERROR_PRIV_PROC_H_

#include "../../code/error/error_sec.h"

static const char * proc_errors[ OSAPI_ERROR_NUMBERS ] =
{
	OSAPI_ERROR_GENERIC,
	OSAPI_ERROR_SUPPORT,
	OSAPI_ERROR_INVPARAM,
	OSAPI_ERROR_UNKNOWN
};

#endif /* ERROR_PRIV_PROC_H_ */
