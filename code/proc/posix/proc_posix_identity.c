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
#include <error/modules/error_proc.h>
#include "status/status.h"

// Own declarations
#include "proc/proc.h"
#include "proc/posix/proc_posix.h"


// *****************************************************************************************
//
// Section: Constant declarations/definitions
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Module Identity management functions definition
//
// *****************************************************************************************


t_status proc_id_get( t_pid * p_pid )
{
 t_status st;

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


t_status proc_id_getParent( t_pid * p_pid )
{
 t_status st;

 status_reset( & st );

 if( p_pid == (t_pid) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     *p_pid = (t_pid) getppid();
     if( *p_pid == -1 )
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}


t_status proc_id_setSetssion( void )
{
t_status st;

 status_reset( & st );

 t_pid pid = setsid();
 if( pid == -1 )
     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );

 return st;
}


t_status proc_id_getSession( t_pid search_pid, t_pid * p_session_id )
{
 t_status st;

 status_reset( & st );

 if( search_pid < (t_pid) 0 || p_session_id == (t_pid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     *p_session_id = getsid( search_pid );
     if( *p_session_id == -1 )
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
   }

 return st;
}

#endif	// End of POSIX compilation
