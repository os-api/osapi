// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IO Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_IO_H_
#define CODE_ERR_ERROR_IO_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_io_X(a, b, c) a b,
enum io_X {
	  #include "error/mappings/table_io.h"
};
#undef error_io_X

#endif /* CODE_ERR_ERROR_IO_H_ */
