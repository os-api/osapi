// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef ERROR_ERROR_H_
#define ERROR_ERROR_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard types
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "general/general_types.h"

// Own declarations
#include "error/error_types.h"

// *****************************************************************************************
//
// Section: Status module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

const char * 	error_string_get	( t_module module, t_error code	);
bool 		error_code_isValid	( t_error code 			);

#pragma GCC visibility pop			// End of public interface


// *****************************************************************************************
//
// Section: Help macros
//
// *****************************************************************************************


// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* ERROR_ERROR_H_ */
