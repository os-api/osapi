/*
 * error_proc.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_PROC_H_
#define ERROR_PROC_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define Clock module private errors

enum
{
	e_proc_generic = OSAPI_ERROR_BASE,
	e_proc_support,
	e_proc_params,					// Wrong entry parameters
	e_proc_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_PROC_H_ */
