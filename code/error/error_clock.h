/*
 * errors_clock.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_CLOCK_H_
#define CODE_ERR_ERROR_CLOCK_H_

// Include General error definitions
#include <error/error_def.h>

#define error_clock_X(a, b, c) a b,
enum clock_X {
	  #include <error/table_clock.h>
};
#undef error_clock_X

#endif /* CODE_ERR_ERROR_CLOCK_H_ */
