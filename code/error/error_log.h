/*
 * error_log.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_LOG_H_
#define CODE_ERR_ERROR_LOG_H_

#include <error/error_def.h>

// Include General error definitions

// Define Proc module private errors

#define error_log_X(a, b, c) a b,
enum log_X {
	  #include <error/table_log.h>
};
#undef error_log_X

#endif /* CODE_ERR_ERROR_LOG_H_ */
