// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Util Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_UTIL_H_
#define OSAPI_ERROR_UTIL_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define osapi_error_util_X(a, b, c) a b,
enum osapi_error_util_E {
	  #include "error/mappings/table_util.h"
};
#undef osapi_error_util_X


#endif /* OSAPI_ERROR_UTIL_H_ */
