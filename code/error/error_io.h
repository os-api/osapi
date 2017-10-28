/*
 * error_io.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_IO_H_
#define ERROR_IO_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define IO module private errors

enum
{
	e_io_generic = OSAPI_ERROR_BASE,
	e_io_support,
	e_io_params,					// Wrong entry parameters
	e_io_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_IO_H_ */
