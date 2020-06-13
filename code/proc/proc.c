// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a C compliant implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <stdlib.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_proc.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "proc/proc.h"


// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************

// First draft
t_status proc_uid_get( t_upid * p_upid )
{
  t_status	st;
  t_pid		pid;
  t_time	info;

  status_reset( & st );

  if( (void *) p_upid == NULL )
    { status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st ); return st; }

  st = proc_id_get( & pid );
  if( status_failure( st ) ) return st;

  // Get Creation Date
  st = proc_time_getStart( pid, &info );
  if( status_failure( st ) ) return st;

  // Generate the UPID
  p_upid->pid  = (int64_t) pid;
  p_upid->time = info.seconds;

  return st;
}
