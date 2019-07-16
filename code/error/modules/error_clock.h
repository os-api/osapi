// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_CLOCK_H_
#define OSAPI_ERROR_CLOCK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions
#define osapi_clock_error_X(a, b, c) a b,
enum osapi_clock_e_error_X {
	  #include "error/mappings/table_clock.h"
};
#undef osapi_clock_error_X

#endif /* OSAPI_ERROR_CLOCK_H_ */
