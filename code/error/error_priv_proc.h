// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_PROC_H_
#define CODE_ERR_ERROR_PRIV_PROC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/error_proc.h"

// *****************************************************************************************
//
// Section: Clock Error Definitions
//
// *****************************************************************************************

#define error_proc_X(a, b, c) [a]=c,

static const char * proc_errors[] = {
  #include "error/table_proc.h"
};

#undef error_proc_X

#endif /* CODE_ERR_ERROR_PRIV_PROC_H_ */
