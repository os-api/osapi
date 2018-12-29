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
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/modules/error_proc.h"
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
// Section: Module Signal functions definition
//
// *****************************************************************************************


t_status proc_signal_supported( int * p_level )
{
 t_status	st;

 status_reset( & st );

#ifdef SIGRTMAX		// Or POSIX.1b
 *p_level = e_siglevel_realtime;
#else
 *p_level = e_siglevel_posix;
#endif

 return st;	// Minimum is POSIX Standard (reliable) signals
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


t_status proc_signal_setHandler( t_signal signo, t_sig_func dispatcher_function )
{
 t_status	st;
 t_sig_action   action;

 status_reset( & st );

 if( dispatcher_function == NULL || signo <= 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     // Each signal can have a different handler,
     // only block own signal during execution of current handler
     sigemptyset( &( action.sa_mask ) );

     action.sa_flags   = 0;			// Clear options
     action.sa_handler = dispatcher_function;	// Set dispatcher function for signal

     // Set the signal action
     if( sigaction( signo, &action, ( t_sig_action * ) 0 ) < 0 )
         status_iset( OSAPI_MODULE_PROC, __func__, e_proc_setsignal, &st );
   }

 return st;
}

t_status proc_signal_resetHandler( t_signal signo )
{
 t_status	st;
 t_sig_action   action;

 status_reset( & st );

 if( signo <= 0 )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     sigemptyset( &( action.sa_mask ) );

     action.sa_flags   = 0;		// Clear options
     action.sa_handler = SIG_DFL;	// Set signal disposition to the default

     // Set the signal action
     if( sigaction( signo, &action, ( t_sig_action * ) 0 ) < 0 )
         status_iset( OSAPI_MODULE_PROC, __func__, e_proc_setsignal, &st );
   }

 return st;
}


t_status proc_signal_clearAll( void )
{
 t_status	st;
 sigset_t	set;

 status_reset( & st );

 if( sigemptyset( &set) )
     status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
 else
     if( sigprocmask( SIG_SETMASK, &( set ), ( sigset_t * ) 0 ) )
         status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );

 return st;
}




#endif	// End of POSIX compilation
