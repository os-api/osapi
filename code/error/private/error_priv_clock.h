// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_CLOCK_H_
#define OSAPI_ERROR_PRIV_CLOCK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_clock.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************


#define osapi_clock_error_X(a, b, c) [a]=c,

static const char * osapi_clock_errors[] =
{
  #include "error/mappings/table_clock.h"
};

#undef osapi_clock_error_X

#endif /* OSAPI_ERROR_PRIV_CLOCK_H_ */
