// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_COMMON_H_
#define OSAPI_ERROR_PRIV_COMMON_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_common.h"

// *****************************************************************************************
//
// Section: Error Definitions
//
// *****************************************************************************************


#define osapi_common_error_X(a, b, c) [a]=c,

static const char * osapi_common_errors[] =
{
  #include "error/mappings/table_common.h"
};

#undef osapi_common_error_X

#endif /* OSAPI_ERROR_PRIV_COMMON_H_ */
