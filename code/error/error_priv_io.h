/*
 * status_io_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_IO_H_
#define ERROR_PRIV_IO_H_

#include "../../code/error/error_io.h"

static const char * io_errors[ OSAPI_ERROR_NUMBERS ] =
{
	OSAPI_ERROR_GENERIC,
	OSAPI_ERROR_SUPPORT,
	OSAPI_ERROR_INVPARAM,
	OSAPI_ERROR_UNKNOWN
};

#endif /* ERROR_PRIV_IO_H_ */
