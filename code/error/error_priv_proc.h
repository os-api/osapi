/*
 * status_proc_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_PRIV_PROC_H_
#define CODE_ERR_ERROR_PRIV_PROC_H_

#include <error/error_proc.h>

#define error_proc_X(a, b, c) [a]=c,

static const char * proc_errors[] = {
  #include <error/table_proc.h>
};

#undef error_proc_X

#endif /* CODE_ERR_ERROR_PRIV_PROC_H_ */
