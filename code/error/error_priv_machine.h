/*
 * status_machine_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_MACHINE_H_
#define ERROR_PRIV_MACHINE_H_

#include <error/error_machine.h>

#define error_machine_X(a, b, c) [a]=c,

static const char * machine_errors[] =
{
  #include <error/table_machine.h>
};

#undef error_machine_X

#endif /* ERROR_PRIV_MACHINE_H_ */
