/*
 * error_string.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_STRING_H_
#define ERROR_STRING_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define STRING module private errors

enum
{
	e_string_generic = OSAPI_ERROR_BASE,
	e_string_support,
	e_string_params,					// Wrong entry parameters
	e_string_create,
	e_string_nullPointer,
	e_string_exists,
	e_string_noSpace,
	e_string_sameString,
	e_string_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_STRING_H_ */
