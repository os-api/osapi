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
#include <dlfcn.h>
#include <stdlib.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "proc/proc_library.h"
#include "error/modules/error_proc.h"
#include "proc/posix/proc_posix.h"


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
