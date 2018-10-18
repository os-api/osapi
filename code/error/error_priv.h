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
#include "error/error_priv_ipc.h"
#include "error/error_priv_net.h"


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


// Aggregate error strings from all modules
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
  ipc_errors,
  net_errors,
  NULL
};


// Aggregate max error codes from all modules

static const t_error osapi_max_errors[ OSAPI_MODULE_MAX ] =
{
  OSAPI_MODULE_NONE,
  e_string_max,
  e_os_max,
  e_machine_max,
  e_proc_max,
  e_clock_max,
  e_sec_max,
  e_io_max,
  e_util_max,
  e_ipc_max,
  e_net_max,

};


// *****************************************************************************************
//
// Section: Macro Definitions
//
// *****************************************************************************************

//#define error_is_valid( x )	( x >= 0 && x )


#endif /* CODE_ERR_ERRORS_PRIV_H_ */
