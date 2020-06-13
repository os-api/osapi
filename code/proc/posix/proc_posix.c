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
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "proc/proc.h"
#include "error/modules/error_proc.h"


// *****************************************************************************************
//
// Section: Constant declarations/definitions
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************

t_status proc_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports process interface
}


t_status proc_data_setUser( t_uid user, t_proc * p_proc )
{
 t_status st;

 status_reset( & st );

 if( user < ((t_uid) 0) || p_proc == ((t_proc *) 0) )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
     p_proc->uid = user;

 return st;
}


t_status proc_data_setGroup( t_gid group, t_proc * p_proc )
{
 t_status st;

 status_reset( & st );

 if( group < ((t_uid) 0) || p_proc == ((t_proc *) 0) )
     status_iset( OSAPI_MODULE_PROC, __func__, osapi_proc_error_params, &st );
 else
     p_proc->gid = group;

 return st;
}




#endif	// End of POSIX compilation
