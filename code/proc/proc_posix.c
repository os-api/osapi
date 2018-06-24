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

// System includes
#include <sys/types.h>
#include <signal.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_proc.h"
#include "status/status.h"

// Own declarations
#include "proc/proc.h"

// Only relevant is OS is POSIX compliant
#ifdef OSAPI_POSIX


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

t_status proc_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports process interface
}


t_status proc_id_get( t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 if( p_pid == (t_pid) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     *p_pid = (t_pid) getpid();
     if( *p_pid == -1 )
         status_iset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}


t_status proc_parentID_get( t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 if( p_pid == (t_pid) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     *p_pid = (t_pid) getppid();
     if( *p_pid == -1 )
         status_iset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}


t_status proc_signal_send( t_pid pid, t_signal sig )
{
 t_status	st;

 status_reset( & st );

 if( pid <= (t_pid) 0 || sig <= (t_signal) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( kill( pid, sig ) != 0 )
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}


#endif	// End of POSIX compilation
