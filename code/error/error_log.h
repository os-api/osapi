// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_LOG_H_
#define CODE_ERR_ERROR_LOG_H_

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
	  #include "error/table_log.h"
};
#undef error_log_X

#endif /* CODE_ERR_ERROR_LOG_H_ */
