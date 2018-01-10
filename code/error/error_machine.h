/*
 * error_machine.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_MACHINE_H_
#define ERROR_MACHINE_H_

// Include General error definitions
#include <error/error_def.h>

// Define Machine module private errors

#define error_machine_X(a, b, c) a b,
enum machine_X {
	  #include <error/table_machine.h>
};
#undef error_machine_X


#endif /* ERROR_MACHINE_H_ */
