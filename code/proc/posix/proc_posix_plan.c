// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Implementation of the API to build a process plan
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

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "proc/proc_plan.h"
#include "error/modules/error_proc.h"


// *****************************************************************************************
//
// Section: Definition of Module process planning functions
//
// *****************************************************************************************

t_status proc_data_clear( t_proc * p_proc )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == (t_proc *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     // Make sure that a process plan has default values / initial state
     p_proc->has_pid = false;
     p_proc->pid = 0;		// This is the only property set upon process creation
     p_proc->has_uid = false;
     p_proc->uid = 0;
     p_proc->has_gid = false;
     p_proc->gid = 0;
     p_proc->name = NULL;
     p_proc->nargs = 0;
     p_proc->args = NULL;
     p_proc->nenv = 0;
     p_proc->env = NULL;
   }

 return st;
}


t_status proc_data_getPID( t_proc * p_proc, t_pid * p_pid )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == ((t_proc * ) 0) || p_pid == (t_pid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( p_proc->pid < 2 || (! p_proc->has_pid) )
	 status_iset( OSAPI_MODULE_PROC, __func__, e_proc_pid, &st );
     else
	 *p_pid = p_proc->pid;
   }

 return st;
}



t_status proc_data_getUser( t_proc * p_proc, t_uid * p_uid )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == ((t_proc * ) 0) || p_uid == (t_uid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( p_proc->uid < 0 || (! p_proc->has_uid) )
	 status_iset( OSAPI_MODULE_PROC, __func__, e_proc_pid, &st );
     else
	 *p_uid = p_proc->uid;
   }

 return st;
}


t_status proc_data_getGroup( t_proc * p_proc, t_gid * p_gid )
{
 t_status	st;

 status_reset( & st );

 if( p_proc == ((t_proc * ) 0) || p_gid == (t_gid *) 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     if( p_proc->gid < 0 || (! p_proc->has_gid) )
	 status_iset( OSAPI_MODULE_PROC, __func__, e_proc_pid, &st );
     else
	 *p_gid = p_proc->gid;
   }

 return st;
}





#endif	// End of POSIX implementation
