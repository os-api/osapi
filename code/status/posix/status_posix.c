// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Status module entry point implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System headers
#include <stdio.h>
#include <string.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status.h"

// Import own headers
#include "status/posix/status_posix.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


void status_message_cPrint( t_status s )
{
  printf("V%s: Module %s, function %s with status: %s.\n", osapi_get_version_string(),
	 osapi_getModule( s.module ),
	 s.funcname,
	 strerror(s.code) );
}


const char * status_error_getSystem( int error )
{
  return strerror( error );
}

void status_message_cGet( t_status status, t_size size, t_char * p_message )
{
  if( p_message != OSAPI_NULL_CHAR_POINTER && size > 0 )
      strncpy( p_message, strerror( status.code ), size );
}




