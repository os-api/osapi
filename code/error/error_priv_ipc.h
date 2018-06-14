// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC private error declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_PRIV_IPC_H_
#define CODE_ERR_ERROR_PRIV_IPC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include own error public declarations
#include "error/error_ipc.h"

// *****************************************************************************************
//
// Section: IPC Error Definitions
//
// *****************************************************************************************

#define error_ipc_X(a, b, c) [a]=c,

static const char * ipc_errors[] =
{
  #include "error/table_ipc.h"
};

#undef error_ipc_X

#endif /* CODE_ERR_ERROR_PRIV_IPC_H_ */
