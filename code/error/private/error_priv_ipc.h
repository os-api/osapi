// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC private error declarations
//
// *****************************************************************************************

#ifndef OSAPI_ERROR_PRIV_IPC_H_
#define OSAPI_ERROR_PRIV_IPC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/modules/error_ipc.h"

// *****************************************************************************************
//
// Section: IPC Error Definitions
//
// *****************************************************************************************

#define error_ipc_X(a, b, c) [a]=c,

static const char * ipc_errors[] =
{
  #include "error/mappings/table_ipc.h"
};

#undef error_ipc_X

#endif /* OSAPI_ERROR_PRIV_IPC_H_ */
