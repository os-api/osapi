/*
 * error_proc.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_PROC_H_
#define CODE_ERR_ERROR_PROC_H_

#include <error/error_def.h>
#include <limits.h>

// Include General error definitions

// Define Proc module private errors

#define error_proc_X(a, b, c) a b,
enum proc_X {
	  #include <error/table_proc.h>
};
#undef error_proc_X

#endif /* CODE_ERR_ERROR_PROC_H_ */
