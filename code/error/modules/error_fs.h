// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Filesystem Error type declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_FS_H_
#define OSAPI_ERROR_FS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_fs_X(a, b, c) a b,
enum fs_X {
	  #include "error/mappings/table_fs.h"
};
#undef error_fs_X

#endif /* OSAPI_ERROR_FS_H_ */
