// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_PROC_H_
#define OSAPI_ERROR_PRIV_PROC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_proc.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define error_proc_X(a, b, c) [a]=c,

static const char * proc_errors[] = {
  #include "error/mappings/table_proc.h"
};

#undef error_proc_X

#endif /* OSAPI_ERROR_PRIV_PROC_H_ */
