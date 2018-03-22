/*
 * error_sec.h
 *
 *  Created on: 03/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_SEC_H_
#define CODE_ERR_ERROR_SEC_H_

// Include General error definitions
#include <error/error_def.h>

// Define SEC module private errors

#define error_sec_X(a, b, c) a b,
enum sec_X {
	  #include <error/table_sec.h>
};
#undef error_sec_X


#endif /* CODE_ERR_ERROR_SEC_H_ */
