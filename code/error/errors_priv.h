/*
 * status_errors.h
 *
 *  Created on: 01/05/2017
 *      Author: joao
 */

#ifndef ERRORS_PRIV_H_
#define ERRORS_PRIV_H_

// Include General error definitions
#include "../../code/error/error_def.h"
#include "../../code/error/error_priv_clock.h"
#include "../../code/error/error_priv_hw.h"
#include "../../code/error/error_priv_io.h"
#include "../../code/error/error_priv_machine.h"
#include "../../code/error/error_priv_os.h"
#include "../../code/error/error_priv_proc.h"
#include "../../code/error/error_priv_sec.h"
#include "../../code/error/error_priv_string.h"
#include "../../code/error/error_priv_util.h"


// Include errors from all modules


static const char ** osapi_errors[] =
{
  0,				// = 0
  proc_errors,			// = 1
  machine_errors,		// = 2
  hw_errors,			// = 3
  os_errors,			// = 4
  io_errors,			// = 5
  sec_errors,			// = 6
  clock_errors,			// = 7
  util_errors,			// = 8
  string_errors,		// = 9
  0				// Last + 1
};

#endif /* ERRORS_PRIV_H_ */
