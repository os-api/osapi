/*
 * error_hw.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_IPC_H_
#define CODE_ERR_ERROR_IPC_H_

// Include General error definitions
#include <error/error_def.h>

// Define IO module private errors

#define error_ipc_X(a, b, c) a b,
enum ipc_X {
	  #include <error/table_ipc.h>
};
#undef error_ipc_X

#endif /* CODE_ERR_ERROR_IPC_H_ */
