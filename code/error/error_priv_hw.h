/*
 * status_hw_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_HW_H_
#define ERROR_PRIV_HW_H_

#include <error/error_hw.h>

#define error_hw_X(a, b, c) [a]=c,

static const char * hw_errors[] =
{
  #include <error/table_hw.h>
};

#undef error_hw_X

#endif /* ERROR_PRIV_HW_H_ */
