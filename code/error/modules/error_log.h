// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_LOG_H_
#define OSAPI_ERROR_LOG_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_log_X(a, b, c) a b,
enum log_X {
	  #include "error/mappings/table_log.h"
};
#undef error_log_X

#endif /* OSAPI_ERROR_LOG_H_ */
