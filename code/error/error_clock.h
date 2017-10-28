/*
 * errors_clock.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_CLOCK_H_
#define ERROR_CLOCK_H_

// Include General error definitions
#include "../../code/error/error_def.h"

enum
{
	e_clock_generic = OSAPI_ERROR_BASE,
	e_clock_support,
	e_clock_params,					// Wrong entry parameters
	e_clock_unknown = OSAPI_ERROR_MAX
};



#endif /* ERROR_CLOCK_H_ */
