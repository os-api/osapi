// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General Pseudo Module implementation
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Own declarations
#include "general/general.h"
#include "general/general_protocol.h"
#include "general/general_priv.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


unsigned long osapi_get_version( void )
{
  return (unsigned long) e_osapi_version;
}

int osapi_get_version_stability( void )
{
  return OSAPI_VERSION_QUALITY;
}


const char * osapi_get_version_string( void )
{
  return osapi_version[ 0 ];	// There is only one member in the array
}


const char * osapi_get_version_stability_string( void )
{
  return osapi_version_quality[ OSAPI_VERSION_QUALITY ];
}


const char * osapi_get_protocol_version_string( t_protocol id )
{
  return osapi_protocol[ id ];
}


// Module related functions

const char * osapi_getModule( t_module module )
{
  if( general_is_valid_module( module ) )
      return module_name[ module ];
  else
      return OSAPI_EMPTY_STRING;
}


