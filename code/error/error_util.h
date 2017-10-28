/*
 * error_util.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_UTIL_H_
#define ERROR_UTIL_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define UTIL module private errors

enum
{
	e_util_generic = OSAPI_ERROR_BASE,
	e_util_support,
	e_util_params,					// Wrong entry parameters
	e_util_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_UTIL_H_ */
