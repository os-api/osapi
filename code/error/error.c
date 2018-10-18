// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Error module entry point implementation file
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import own module headers
#include "error/error.h"
#include "error/error_priv.h"

// *****************************************************************************************
//
// Section: Local declarations/definitions
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************
#include <stdio.h>

bool error_code_isValid( t_module module, t_error code )
{
  bool valid = false;

  // Verify, for each module, the validity of the error code
  if( code >= OSAPI_ERROR_BASE && code < osapi_error_strings[ module ].topValue )
    {
      fprintf( stderr, "Code (%d) under Max Code (%d) of module: %d\n", code, osapi_error_strings[ module ].topValue, module );
      fflush( stderr );
      valid = true;
    }
     // valid = true;

  return valid;
}

const char * error_string_get( t_module module, t_error code )
{
  if( general_is_valid_module( module ) )
      if( error_code_isValid( module, code ) )
 	  //return osapi_errors[ module ][ code ];
	  return osapi_error_strings[ module ].name[ code ];

  return OSAPI_EMPTY_STRING;
}
