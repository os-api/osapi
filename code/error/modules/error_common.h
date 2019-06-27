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
#define error_common_X(a, b, c) a b,
enum common_X {
	  #include "error/mappings/table_common.h"
};
#undef error_common_X

#endif /* OSAPI_ERROR_COMMON_H_ */
