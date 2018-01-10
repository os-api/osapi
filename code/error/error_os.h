/*
 * error_os.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef ERROR_OS_H_
#define ERROR_OS_H_

// Include General error definitions
#include <error/error_def.h>

// Define OS module private errors

#define error_os_X(a, b, c) a b,
enum os_X {
	  #include <error/table_os.h>
};
#undef error_os_X


#endif /* ERROR_OS_H_ */
