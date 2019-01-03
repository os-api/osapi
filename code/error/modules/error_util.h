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

#define error_util_X(a, b, c) a b,
enum util_X {
	  #include "error/mappings/table_util.h"
};
#undef error_util_X


#endif /* OSAPI_ERROR_UTIL_H_ */
