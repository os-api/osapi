// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_HW_H_
#define CODE_ERR_ERROR_PRIV_HW_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/error_hw.h"

// *****************************************************************************************
//
// Section: HW Error Definitions
//
// *****************************************************************************************

#define error_hw_X(a, b, c) [a]=c,

static const char * hw_errors[] =
{
  #include "error/table_hw.h"
};

#undef error_hw_X

#endif /* CODE_ERR_ERROR_PRIV_HW_H_ */
