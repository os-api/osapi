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


#define error_common_X(a, b, c) [a]=c,

static const char * common_errors[] =
{
  #include "error/mappings/table_common.h"
};

#undef error_common_X

#endif /* OSAPI_ERROR_PRIV_COMMON_H_ */
