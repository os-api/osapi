// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PROC_H_
#define CODE_ERR_ERROR_PROC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// #include <limits.h> ?

// Include own error definitions

#define error_proc_X(a, b, c) a b,
enum proc_X {
	  #include "error/table_proc.h"
};
#undef error_proc_X

#endif /* CODE_ERR_ERROR_PROC_H_ */
