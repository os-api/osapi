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
#include <dlfcn.h>

// Generic OSAPI includes
#include "general/general.h"
#include "error/error_proc.h"
#include "status/status.h"

// Own declarations
#include "proc/proc.h"
#include "proc/proc_posix.h"


// *****************************************************************************************
//
// Section: Constant declarations/definitions
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Function declarations (private)
//
// *****************************************************************************************

t_status proc_library_getError( t_size size, char * p_error );


// *****************************************************************************************
//
// Section: Module Function definition
//
// *****************************************************************************************

t_status proc_module_supported( void )
{
  RETURN_STATUS_SUCCESS;	// Posix supports process interface
}


// *****************************************************************************************
//
// Section: Module Identity management functions definition
//
// *****************************************************************************************


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


t_status proc_id_getParent( t_pid * p_pid )
{
 t_status	st;

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



// This call should only be used in single threaded programs
t_status proc_execution_suspend( void )
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



// *****************************************************************************************
//
// Section: Module Library functions definition
//
// *****************************************************************************************


t_status proc_library_supported( void )
{
  RETURN_STATUS_SUCCESS;
}

t_status posix_library_load( const char * pathname, int options, t_library * p_library )
{
  t_status	st;
  void	*	handle = NULL;

  status_reset( & st );

  if( pathname == NULL || p_library == NULL )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      handle = dlopen( pathname, options );
      if( handle != NULL )
	  *p_library = handle;
      else
	{
	  char errorString[ OSAPI_STATUS_STRING_SIZE ];
	  st = proc_library_getError( OSAPI_STATUS_STRING_SIZE, errorString );

	  if( status_success( st ) )	// Success in getting external error information
              status_setString( OSAPI_MODULE_PROC, e_library_loader, __func__, errorString, &st );
	}
    }

  return st;
}

t_status proc_library_unload( t_library library )
{
  t_status	st;
  int		rc;

  status_reset( & st );

  if( library == NULL )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      rc = dlclose( library );
      if( rc != 0 )
	{
	  char errorString[ OSAPI_STATUS_STRING_SIZE ];
	  st = proc_library_getError( OSAPI_STATUS_STRING_SIZE, errorString );

	  if( status_success( st ) )	// Success in getting external error information
              status_setString( OSAPI_MODULE_PROC, e_library_loader, __func__, errorString, &st );
	}
    }

  return st;
}

t_status proc_library_getError( t_size size, char * p_error )
{
  t_status	st;
  char	*	p_libErrorString = NULL;

  status_reset( & st );

  if( size <= 0 || p_error == NULL )
      status_iset( OSAPI_MODULE_PROC, __func__, e_proc_params, &st );
  else
    {
      p_libErrorString = dlerror();
      if( p_libErrorString == NULL )	// No error available
	  status_iset( OSAPI_MODULE_PROC, __func__, e_proc_noerror, &st );
      else
	{
	  if( strncpy( p_error, p_libErrorString, size - 1 ) == NULL )
	      status_eset( OSAPI_MODULE_PROC, __func__, errno, &st );
	  p_error[ size - 1 ] = '\0';		// Null string termination
	}
    }

  return st;
}



#endif	// End of POSIX compilation
