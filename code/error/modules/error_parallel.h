// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Parallel Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PARALLEL_H_
#define OSAPI_ERROR_PARALLEL_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define osapi_error_par_X(a, b, c) a b,
enum osapi_error_par_E {
	  #include "error/mappings/table_parallel.h"
};
#undef osapi_error_par_X


#endif /* OSAPI_ERROR_PARALLEL_H_ */
