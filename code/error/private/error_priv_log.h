// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Log private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_LOG_H_
#define OSAPI_ERROR_PRIV_LOG_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_log.h"

// *****************************************************************************************
//
// Section: Log Error Definitions
//
// *****************************************************************************************

#define osapi_log_error_X(a, b, c) [a]=c,

static const char * osapi_log_errors[] = {
  #include "error/mappings/table_log.h"
};

#undef osapi_log_error_X

#endif /* OSAPI_ERROR_PRIV_LOG_H_ */
