// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	POSIX private implementation to support the POSIX PROC module
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// Only relevant is OS is POSIX compliant
#ifdef OSAPI_POSIX

// System includes
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "error/modules/error_proc.h"
#include "proc/posix/proc_posix_priv.h"


// *****************************************************************************************
//
// Section: Module Process internal POSIX functions definition
//
// *****************************************************************************************


 void proc_app_launch( t_proc * p_process )
 {
  int		rc;
  char *		executable;

  if( p_process == (t_proc *) 0 )
      _exit( 1 );

  // In case, a name for the executable was provided, use it
  executable = p_process->args[0];
  if( p_process->name == NULL )
      p_process->args[0] = p_process->name;

  rc = execve( executable, p_process->args, p_process->env );

  // If execution failed, ensure that the child process dies
  _exit( rc );
 }



#endif	// POSIX
