/*
 * general_clock_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_CLOCK_H_
#define ERROR_PRIV_CLOCK_H_

#include <error/error_clock.h>

#define error_clock_X(a, b, c) [a]=c,

static const char * clock_errors[] =
{
  #include <error/table_clock.h>
};

#undef error_clock_X

#endif /* ERROR_PRIV_CLOCK_H_ */
