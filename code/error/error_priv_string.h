/*
 * error_priv_string.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_STRING_H_
#define ERROR_PRIV_STRING_H_

#include <error/error_string.h>

#define error_string_X(a, b, c) [a]=c,

static const char * string_errors[] =
{
  #include <error/table_string.h>
};

#undef error_string_X

#endif /* ERROR_PRIV_STRING_H_ */
