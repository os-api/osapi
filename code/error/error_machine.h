/*
 * error_machine.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_MACHINE_H_
#define ERROR_MACHINE_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define Machine module private errors

enum
{
	e_machine_generic = OSAPI_ERROR_BASE,
	e_machine_support,
	e_machine_params,					// Wrong entry parameters
	e_machine_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_MACHINE_H_ */
