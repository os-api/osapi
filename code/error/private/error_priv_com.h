// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Com(munication) private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_COM_H_
#define OSAPI_ERROR_PRIV_COM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_com.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define osapi_error_com_X(a, b, c) [a]=c,

static const char * osapi_com_errors[] =
{
  #include "error/mappings/table_com.h"
};

#undef osapi_error_com_X

#endif /* OSAPI_ERROR_PRIV_COM_H_ */
