// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC Error type declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERROR_IPC_H_
#define CODE_ERR_ERROR_IPC_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include General error definitions
#include "error/error_types.h"

// Include own error definitions

#define error_ipc_X(a, b, c) a b,
enum ipc_X {
	  #include "error/table_ipc.h"
};
#undef error_ipc_X

#endif /* CODE_ERR_ERROR_IPC_H_ */
