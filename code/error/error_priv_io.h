/*
 * status_io_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERROR_PRIV_IO_H_
#define ERROR_PRIV_IO_H_

#include <error/error_io.h>

#define error_io_X(a, b, c) [a]=c,

static const char * io_errors[] =
{
  #include <error/table_io.h>
};

#undef error_io_X

#endif /* ERROR_PRIV_IO_H_ */
