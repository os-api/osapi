/*
 * error_priv_util.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_UTIL_H_
#define ERROR_PRIV_UTIL_H_

#include <error/error_util.h>

#define error_util_X(a, b, c) [a]=c,

static const char * util_errors[] =
{
  #include <error/table_util.h>
};

#undef error_util_X

#endif /* ERROR_PRIV_UTIL_H_ */
