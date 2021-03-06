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

#define osapi_error_log_X(a, b, c) a b,
enum osapi_error_log_E {
	  #include "error/mappings/table_log.h"
};
#undef osapi_error_log_X

#endif /* OSAPI_ERROR_LOG_H_ */
