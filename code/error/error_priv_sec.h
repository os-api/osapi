/*
 * status_sec_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_SEC_H_
#define ERROR_PRIV_SEC_H_

#include <error/error_sec.h>

#define error_sec_X(a, b, c) [a]=c,

static const char * sec_errors[] =
{
  #include <error/table_sec.h>
};

#undef error_sec_X

#endif /* ERROR_PRIV_SEC_H_ */
