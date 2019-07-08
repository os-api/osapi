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

#define osapi_fs_error_X(a, b, c) a b,
enum osapi_fs_e_error_X {
	  #include "error/mappings/table_fs.h"
};
#undef osapi_fs_error_X

#endif /* OSAPI_ERROR_FS_H_ */
