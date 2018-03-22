/*
 * status_os_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_PRIV_OS_H_
#define CODE_ERR_ERROR_PRIV_OS_H_

#include <error/error_os.h>

#define error_os_X(a, b, c) [a]=c,

static const char * os_errors[] =
{
  #include <error/table_os.h>
};

#undef error_os_X

#endif /* CODE_ERR_ERROR_PRIV_OS_H_ */
