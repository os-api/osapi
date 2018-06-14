// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_CLOCK_H_
#define CODE_ERR_ERROR_PRIV_CLOCK_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/error_clock.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************


#define error_clock_X(a, b, c) [a]=c,

static const char * clock_errors[] =
{
  #include "error/table_clock.h"
};

#undef error_clock_X

#endif /* CODE_ERR_ERROR_PRIV_CLOCK_H_ */
