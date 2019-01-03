// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	String private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_STRING_H_
#define OSAPI_ERROR_PRIV_STRING_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_string.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define error_string_X(a, b, c) [a]=c,

static const char * string_errors[] =
{
  #include "error/mappings/table_string.h"
};

#undef error_string_X

#endif /* OSAPI_ERROR_PRIV_STRING_H_ */
