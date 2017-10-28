/*
 * error_sec.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_SEC_H_
#define ERROR_SEC_H_

// Include General error definitions
#include "../../code/error/error_def.h"

// Define SEC module private errors

enum
{
	e_sec_generic = OSAPI_ERROR_BASE,
	e_sec_support,
	e_sec_params,					// Wrong entry parameters
	e_sec_unknown = OSAPI_ERROR_MAX
};


#endif /* ERROR_SEC_H_ */
