/*
 * status_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef CODE_ERR_ERRORS_PRIV_H_
#define CODE_ERR_ERRORS_PRIV_H_

#include <stddef.h>

// Include module information
#include <error/error_def.h>
#include <error/error_priv_clock.h>
#include <error/error_priv_hw.h>
#include <error/error_priv_io.h>
#include <error/error_priv_machine.h>
#include <error/error_priv_os.h>
#include <error/error_priv_proc.h>
#include <error/error_priv_sec.h>
#include <error/error_priv_string.h>
#include <error/error_priv_util.h>
#include <general/general_defs.h>
#include <general/general_priv.h>

// Include General error definitions

static const char * error_none [] =
{
  "Success",
  NULL
};

// Include errors from all modules



static const char ** osapi_errors[] =
{
  error_none,			// Pseudo-error
  string_errors,
  os_errors,
  machine_errors,
  proc_errors,
  clock_errors,
  sec_errors,
  hw_errors,
  io_errors,
  util_errors,
  NULL
};



#endif /* CODE_ERR_ERRORS_PRIV_H_ */
