/*
 * error_hw.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_HW_H_
#define ERROR_HW_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define HW module private errors

enum
{
	e_hw_generic = OSAPI_ERROR_BASE,
	e_hw_support,
	e_hw_params,					// Wrong entry parameters
	e_hw_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_HW_H_ */
