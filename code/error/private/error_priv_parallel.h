// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Parallel private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_PARALLEL_H_
#define OSAPI_ERROR_PRIV_PARALLEL_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_parallel.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define osapi_error_par_X(a, b, c) [a]=c,

static const char * osapi_parallel_errors[] =
{
  #include "error/mappings/table_parallel.h"
};

#undef osapi_error_par_X

#endif /* OSAPI_ERROR_PRIV_PARALLEL_H_ */
