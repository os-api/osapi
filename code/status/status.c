/*
 * status.c
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#include "../../code/status/status.h"

#include <stdio.h>
#include <string.h>

#include "../../code/error/errors_priv.h"
#include "../../code/module/module_functions_priv.h"
#include "../../code/module/module_modules_priv.h"


void status_reset( t_status * myStatus )
{
  *myStatus = (t_status) 0;
}

static const char * modName_get( t_status status )
{
  return module_name[ status_to_module( status ) ];
}

static const char * funcName_get( t_status status )
{
  return func_name[status_to_module( status )][status_to_function( status )];
}

static char * codeName_get( t_status status )
{
  int		ec, mod;
  char * 	errorStr = OSAPI_EMPTY_STRING;

  ec  = status_to_code  ( status );
  mod = status_to_module( status );

  if( ec < OSAPI_ERROR_BASE )		// System error
      errorStr = strerror( ec );
  else
    {
      if( ec >= OSAPI_ERROR_BASE && ec <= OSAPI_ERROR_MAX )
	  errorStr = (char *) osapi_errors[ mod ][ ec - OSAPI_ERROR_BASE ];
    }

  // In case there was no error found in the array of system or OSAPI lib errors => unknown error
  if( errorStr == (char *) 0 )
      errorStr = OSAPI_ERROR_UNKNOWN;

  return (char *) errorStr;
}

void status_set( int module, int funcName, unsigned int code, t_status * myStatus)
{
  // Module to be shifted left to the fourth byte
  // Id of function in module to occupy third byte
  // Status code inside function will use the remaining two bytes
  *myStatus = status_from_module( module ) | status_from_function( funcName ) | status_from_code( code );
}

void status_message_print( t_status status )
{
  printf("Module %s, Function %s with Status:%s.\n",
	 modName_get (status),
	 funcName_get (status),
	 codeName_get(status)
	);
}
