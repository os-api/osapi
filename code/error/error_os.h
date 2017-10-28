/*
 * error_os.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_OS_H_
#define ERROR_OS_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define OS module private errors

enum
{
	e_os_generic = OSAPI_ERROR_BASE,
	e_os_support,
	e_os_params,					// Wrong entry parameters
	e_os_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_OS_H_ */
