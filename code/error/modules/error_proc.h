// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PROC_H_
#define OSAPI_ERROR_PROC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_proc_X(a, b, c) a b,
enum proc_X {
	  #include "error/mappings/table_proc.h"
};
#undef error_proc_X

#endif /* OSAPI_ERROR_PROC_H_ */
