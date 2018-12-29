// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc(ess) module using a POSIX compliant implementation
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
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "proc/proc.h"
#include "error/modules/error_proc.h"
#include "proc/posix/proc_posix.h"
#include "proc/linux/proc_linux_priv.h"
#include "proc/posix/proc_posix_priv.h"



// *****************************************************************************************
//
// Section: Module Process Lifecycle functions definition
//
// *****************************************************************************************

t_status proc_instance_create( t_proc * p_process )
{
  t_status	st;
  t_pid		pid;

  status_reset( & st );

  if( p_process == (t_proc *) 0 )
    {
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
      return st;
    }

  if( ( pid = fork() ) < 0 )
    {
      status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
      return st;
    }

 if( pid == 0)      /* Child process */
   {
     if( status_success( st ) )       set_groupID( p_process->gid );

     // The user change must be the last before executing the application
     if( status_success( st ) )       set_userID( p_process->uid );

     if( status_success( st ) )       proc_app_launch( p_process );

     // If the application returned, an error occurred
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_exec, &st );
   }
 else
   {
     // Wait sometime to see if child dies

   }

  return st;
}

t_status proc_instance_destroy( t_pid pid, int forced )
{
  t_status	st;
  int		rc = 0;

  status_reset( & st );

  if( pid <= 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_pid, &st );
  else
    {
      if( forced == true ) rc = kill( pid, SIGKILL );
      else		   rc = kill( pid, SIGTERM );

      if( rc == -1 )
	  status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
    }

  return st;
}



t_status proc_instance_clone( int * p_isChild )
{
  t_status	st;
  pid_t		pid;

  status_reset( & st );

  if( p_isChild == (int *) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      if( (pid = fork() ) == -1 )
	  status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
      else
	{
	  if( pid == 0 )	// Child
	      *p_isChild = true;
	  else			// Father
	      *p_isChild = false;
	}
    }

  return st;
}


void proc_instance_terminate( int normal )
{
 int code = EXIT_FAILURE;

  if( normal ) code = EXIT_SUCCESS;

  exit( code );
}



// This call should only be used in single threaded programs
t_status proc_instance_suspendExecution( void )
{
 int		rc = 0;
 sigset_t	set;
 t_status	st;

 status_reset( & st );

 // All signals are allowed during suspension of process execution
 sigemptyset( &set );

 rc = sigsuspend( &set );
 if( rc != -1 )
     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );

 return st;
}

t_status proc_instance_isRunning( t_pid search_pid )
{
  t_status	st;

  status_reset( & st );

  if( search_pid <= (pid_t) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      // Signal 0 to check if a processing is running
      if( kill( search_pid, 0 )  == -1 )
	  // Either the process is not running or the calling process has no permissions to check the process status
	  status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
    }

  return st;
}



t_status proc_instance_getStatus( t_pid target_pid, t_proc_status * p_status )
{
 t_status	st;
 t_pid		pid;

 // Wait for a specific process
 st = proc_status_get( target_pid, &pid, p_status );

 // Extra check
 if( status_success( st ) && target_pid != pid )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_wait, &st );

 return st;
}


t_status proc_instance_getChildStatus( t_pid * p_pid, t_proc_status * p_status )
{
 // Wait for any child process
 return proc_status_get( -1, p_pid, p_status );
}



#endif	// End of POSIX compilation
