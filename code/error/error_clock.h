// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_CLOCK_H_
#define CODE_ERR_ERROR_CLOCK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions
#define error_clock_X(a, b, c) a b,
enum clock_X {
	  #include "error/table_clock.h"
};
#undef error_clock_X

#endif /* CODE_ERR_ERROR_CLOCK_H_ */
