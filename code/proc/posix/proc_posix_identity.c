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
#include <stdio.h>
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


t_status proc_id_getParent( t_pid pid, t_pid * p_pid )
{
 t_status st;

 status_reset( & st );

 if( pid < 2 || p_pid == (t_pid) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     // If the target process is the current process, use a shortcut to get the parent PID
     if( pid == getpid() )
       {
	 *p_pid = (t_pid) getppid();
	 if( *p_pid == -1 )
	     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
       }
     else
       {	// Parent PID requested for another process
	 posix_get_parent_pid( pid, p_pid );
       }
   }

 return st;
}


t_status proc_id_setSession( void )
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


t_status proc_id_setGroup( t_gid gid )
{
 return set_groupID( gid );
}


t_status proc_id_getGroup( t_pid search_pid, t_gid * p_group_id )
{
 t_status st;

 status_reset( & st );

 if( search_pid < (t_pid) 0 || p_group_id == (t_gid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( search_pid == 0 )
         get_groupID( p_group_id );
     // Otherwise perform more expensive search
     /*
     else
       {
	 if( *p_group_id == -1 )
	     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
       }
     */
   }

 return st;
}



t_status proc_id_setUser( t_uid uid )
{
 return set_userID( uid );
}


t_status proc_id_getUser( t_pid search_pid, t_gid * p_user_id )
{
 t_status st;

 status_reset( & st );

 if( search_pid < (t_pid) 0 || p_user_id == (t_uid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( search_pid == 0 )
         get_userID( p_user_id );

     // Otherwise perform more expensive search
     /*
     else
       {
	 if( *p_group_id == -1 )
	     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
       }
     */
   }

 return st;
}


t_status proc_id_toString( t_pid pid, t_size size, t_char * p_string )
{
 t_status	st;

 status_reset( & st );

 if( pid <= 0 || size <= 0 || p_string == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     int n = snprintf( p_string, size, "%d", pid );
     if( n < 0 )	// Conversion error
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
     else 	// Value was truncated ?
	 if( n >= size ) status_iset( OSAPI_MODULE_PROC, __func__, e_proc_conversion, &st );
   }

 return st;
}


t_status proc_id_fromString( t_char * p_string, t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 if( p_string == NULL || p_pid == (t_pid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     errno = 0;    // To distinguish success/failure after call
     *p_pid = (t_pid) atol( p_string );
     if( errno != 0 )	status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
     else
       if( *p_pid < 0 )	status_iset( OSAPI_MODULE_PROC, __func__, e_proc_pid, &st );
   }

 return st;
}


t_status proc_id_copy( t_pid source, t_pid * p_target )
{
 t_status	st;

 status_reset( & st );

 if( source <= 0 || p_target == (t_pid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
     *p_target = source;

 return st;
}

t_status proc_id_clear( t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 if( p_pid == (t_pid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
     *p_pid = 0;

 return st;
}


#endif	// End of POSIX compilation
