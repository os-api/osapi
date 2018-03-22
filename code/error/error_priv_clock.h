/*
 * general_clock_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_PRIV_CLOCK_H_
#define CODE_ERR_ERROR_PRIV_CLOCK_H_

#include <error/error_clock.h>

#define error_clock_X(a, b, c) [a]=c,

static const char * clock_errors[] =
{
  #include <error/table_clock.h>
};

#undef error_clock_X

#endif /* CODE_ERR_ERROR_PRIV_CLOCK_H_ */
