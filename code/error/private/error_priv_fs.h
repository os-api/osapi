// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_FS_H_
#define OSAPI_ERROR_PRIV_FS_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_fs.h"

// *****************************************************************************************
//
// Section: Error Definitions
//
// *****************************************************************************************

#define error_fs_X(a, b, c) [a]=c,

static const char * fs_errors[] =
{
  #include "error/mappings/table_fs.h"
};

#undef error_fs_X

#endif /* OSAPI_ERROR_PRIV_FS_H_ */
