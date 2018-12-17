// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IO private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_IO_H_
#define CODE_ERR_ERROR_PRIV_IO_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include <error/modules/error_io.h>

// *****************************************************************************************
//
// Section: IO Error Definitions
//
// *****************************************************************************************

#define error_io_X(a, b, c) [a]=c,

static const char * io_errors[] =
{
  #include <error/mappings/table_io.h>
};

#undef error_io_X

#endif /* CODE_ERR_ERROR_PRIV_IO_H_ */
