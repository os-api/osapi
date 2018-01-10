/*
 * error_hw.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_HW_H_
#define ERROR_HW_H_

// Include General error definitions
#include <error/error_def.h>

// Define IO module private errors

#define error_hw_X(a, b, c) a b,
enum hw_X {
	  #include <error/table_hw.h>
};
#undef error_hw_X

#endif /* ERROR_HW_H_ */
