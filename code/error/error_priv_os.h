// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_OS_H_
#define CODE_ERR_ERROR_PRIV_OS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/error_os.h"

// *****************************************************************************************
//
// Section: OS Error Definitions
//
// *****************************************************************************************

#define error_os_X(a, b, c) [a]=c,

static const char * os_errors[] =
{
  #include "error/table_os.h"
};

#undef error_os_X

#endif /* CODE_ERR_ERROR_PRIV_OS_H_ */
