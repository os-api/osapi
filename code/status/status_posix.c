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
#include "general/general_priv.h"
#include "status/status.h"

// Import own headers
#include "status/status_posix.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


void status_message_eprint( t_status s )
{
  printf("V%s: Module %s, function %s with status: %s.\n", osapi_get_version_string(),
	 module_name[ s.module ],
	 s.funcname,
	 strerror(s.code) );
}


const char * status_error_getSystem( int error )
{
  return strerror( error );
}





