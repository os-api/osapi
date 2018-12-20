// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IO module entry point for a POSIX implementation
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
#include <unistd.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Own declarations
#include "io/io.h"
#include "error/modules/error_io.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


t_status io_directory_change( t_char * p_dirname )
{
  t_status	st;

  status_reset( & st );

  if( p_dirname == NULL )
      status_iset( OSAPI_MODULE_IO, __func__, e_io_params, &st );
  else
    {
      if( chdir( p_dirname ) == -1 )
	status_eset( OSAPI_MODULE_IO, __func__, errno, &st );
    }

  return st;
}
