// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IO Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_IO_H_
#define OSAPI_ERROR_IO_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define osapi_error_io_X(a, b, c) a b,
enum osapi_error_io_E {
	  #include "error/mappings/table_io.h"
};
#undef osapi_error_io_X

#endif /* OSAPI_ERROR_IO_H_ */
