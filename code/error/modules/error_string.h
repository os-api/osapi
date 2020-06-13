// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_STRING_H_
#define OSAPI_ERROR_STRING_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define osapi_error_string_X(a, b, c) a b,
enum osapi_error_string_E {
	  #include "error/mappings/table_string.h"
};
#undef osapi_error_string_X


#endif /* OSAPI_ERROR_STRING_H_ */
