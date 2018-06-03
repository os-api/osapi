/*
 * status_hw_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_PRIV_IPC_H_
#define CODE_ERR_ERROR_PRIV_IPC_H_

#include <error/error_ipc.h>

#define error_ipc_X(a, b, c) [a]=c,

static const char * ipc_errors[] =
{
  #include <error/table_ipc.h>
};

#undef error_ipc_X

#endif /* CODE_ERR_ERROR_PRIV_IPC_H_ */
