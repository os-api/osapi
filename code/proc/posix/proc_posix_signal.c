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
#include "status/status.h"
#include "common/common.h"

// Own declarations
#include "proc/proc.h"
#include "error/modules/error_proc.h"
#include "proc/posix/proc_posix.h"
#include "proc/posix/proc_signal_defs.h"


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


t_status proc_signal_getName( t_signal signo, t_char ** p_signal_string )
{
  t_status st;

  status_reset( & st );

  if( signo <= 0 || p_signal_string == (t_char **) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
      *p_signal_string = strsignal( signo );

  return st;
}

t_status proc_signal_sendByName( t_pid pid, t_char * sigName )
{
 t_status 	st;
 int		signal_number = 0;
 char * 	signal_name[2];

 status_reset( & st );

 if( sigName == (t_char *) 0 )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     // Convert from a single pointer to an array of pointers for usage in common_options_get call
     signal_name[0] = sigName;
     signal_name[1] = NULL;

     // Find a matching signal number
     signal_number = common_options_get( osapi_signal, (char **) signal_name );

     // Send signal
     if( signal_number > 0 )
         st = proc_signal_send( pid, signal_number );
   }


 return st;
}

t_status proc_signal_setHandlerByName( t_char * sigName, t_sig_func signal_handler )
{
 t_status 	st;
 int		signal_number = 0;
 char * 	signal_name[2];

 status_reset( & st );

 if( sigName == ((t_char *) 0) || signal_handler == NULL )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     // Convert from a single pointer to an array of pointers for usage in common_options_get call
     signal_name[0] = sigName;
     signal_name[1] = NULL;

     // Find a matching signal number
     signal_number = common_options_get( osapi_signal, (char **) signal_name );

     // Install handler
     if( signal_number > 0 )
	 st = proc_signal_setHandler( signal_number, signal_handler );
   }

 return st;
}

t_status proc_signal_resetHandlerByName( t_char * sigName )
{
 t_status st;
 int		signal_number = 0;
 char * 	signal_name[2];

 status_reset( & st );

 if( sigName == ((t_char *) 0) )
     status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
 else
   {
     // Convert from a single pointer to an array of pointers for usage in common_options_get call
     signal_name[0] = sigName;
     signal_name[1] = NULL;

     // Find a matching signal number
     signal_number = common_options_get( osapi_signal, (char **) signal_name );

     // Reset signal to default
     if( signal_number > 0 )
	 proc_signal_resetHandler( signal_number );
   }


 return st;
}



#endif	// End of POSIX compilation
