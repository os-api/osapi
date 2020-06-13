// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Machine private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_MACHINE_H_
#define OSAPI_ERROR_PRIV_MACHINE_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_machine.h"

// *****************************************************************************************
//
// Section: Machine Error Definitions
//
// *****************************************************************************************

#define osapi_error_machine_X(a, b, c) [a]=c,

static const char * osapi_machine_errors[] =
{
  #include "error/mappings/table_machine.h"
};

#undef osapi_error_machine_X

#endif /* OSAPI_ERROR_PRIV_MACHINE_H_ */
