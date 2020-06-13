// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_OS_H_
#define OSAPI_ERROR_PRIV_OS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_os.h"

// *****************************************************************************************
//
// Section: OS Error Definitions
//
// *****************************************************************************************

#define osapi_error_os_X(a, b, c) [a]=c,

static const char * osapi_os_errors[] =
{
  #include "error/mappings/table_os.h"
};

#undef osapi_error_os_X

#endif /* OSAPI_ERROR_PRIV_OS_H_ */
