/*
 * status_proc_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERROR_PRIV_LOG_H_
#define CODE_ERR_ERROR_PRIV_LOG_H_

#include <error/error_log.h>

#define error_proc_X(a, b, c) [a]=c,

static const char * log_errors[] = {
  #include <error/table_log.h>
};

#undef error_log_X

#endif /* CODE_ERR_ERROR_PRIV_LOG_H_ */
