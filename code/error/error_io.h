/*
 * error_io.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_IO_H_
#define CODE_ERR_ERROR_IO_H_

// Include General error definitions
#include <error/error_def.h>

// Define IO module private errors

#define error_io_X(a, b, c) a b,
enum io_X {
	  #include <error/table_io.h>
};
#undef error_io_X

#endif /* CODE_ERR_ERROR_IO_H_ */
