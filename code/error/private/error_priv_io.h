// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IO private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_IO_H_
#define OSAPI_ERROR_PRIV_IO_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_io.h"

// *****************************************************************************************
//
// Section: IO Error Definitions
//
// *****************************************************************************************

#define osapi_error_io_X(a, b, c) [a]=c,

static const char * osapi_io_errors[] =
{
  #include "error/mappings/table_io.h"
};

#undef osapi_error_io_X

#endif /* OSAPI_ERROR_PRIV_IO_H_ */
