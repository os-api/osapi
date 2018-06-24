// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Status declarations
//
// *****************************************************************************************

#ifndef CODE_ERR_ERRORS_PRIV_H_
#define CODE_ERR_ERRORS_PRIV_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// System headers
#include <stddef.h>

// OSAPI module error information
#include "general/general_types.h"
#include "general/general_priv.h"

// Error information
#include "error/error_types.h"

#include "error/error_priv_clock.h"
#include "error/error_priv_io.h"
#include "error/error_priv_machine.h"
#include "error/error_priv_os.h"
#include "error/error_priv_proc.h"
#include "error/error_priv_sec.h"
#include "error/error_priv_string.h"
#include "error/error_priv_util.h"



// *****************************************************************************************
//
// Section: Error Definitions
//
// *****************************************************************************************

// Generic error definitions

static const char * error_none [] =
{
  "Success",
  NULL
};

// Aggregate errors from all modules
static const char ** osapi_errors[] =
{
  error_none,			// Pseudo-error
  string_errors,
  os_errors,
  machine_errors,
  proc_errors,
  clock_errors,
  sec_errors,
  io_errors,
  util_errors,
  NULL
};



#endif /* CODE_ERR_ERRORS_PRIV_H_ */
