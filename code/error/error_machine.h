/*
 * error_machine.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_MACHINE_H_
#define CODE_ERR_ERROR_MACHINE_H_

// Include General error definitions
#include <error/error_def.h>

// Define Machine module private errors

#define error_machine_X(a, b, c) a b,
enum machine_X {
	  #include <error/table_machine.h>
};
#undef error_machine_X


#endif /* CODE_ERR_ERROR_MACHINE_H_ */
