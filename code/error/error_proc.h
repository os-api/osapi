/*
 * error_proc.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_PROC_H_
#define ERROR_PROC_H_

#include <limits.h>

// Include General error definitions
#include <error/error_def.h>

// Define Proc module private errors

#define error_proc_X(a, b, c) a b,
enum proc_X {
	  #include <error/table_proc.h>
};
#undef error_proc_X

#endif /* ERROR_PROC_H_ */
