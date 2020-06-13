// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Util private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_UTIL_H_
#define OSAPI_ERROR_PRIV_UTIL_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_util.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define osapi_error_util_X(a, b, c) [a]=c,

static const char * osapi_util_errors[] =
{
  #include "error/mappings/table_util.h"
};

#undef osapi_error_util_X

#endif /* OSAPI_ERROR_PRIV_UTIL_H_ */
