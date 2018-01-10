/*
 * error_util.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_UTIL_H_
#define ERROR_UTIL_H_

// Include General error definitions
#include <error/error_def.h>

// Define UTIL module private errors

#define error_util_X(a, b, c) a b,
enum util_X {
	  #include <error/table_util.h>
};
#undef error_util_X


#endif /* ERROR_UTIL_H_ */
