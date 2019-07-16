// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_COMMON_H_
#define OSAPI_ERROR_COMMON_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions
#define osapi_common_error_X(a, b, c) a b,
enum osapi_common_e_error_X {
	  #include "error/mappings/table_common.h"
};
#undef osapi_common_error_X

#endif /* OSAPI_ERROR_COMMON_H_ */
