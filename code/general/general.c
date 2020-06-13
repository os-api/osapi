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

#include "general/general_baseline.h"

// Import standard headers
#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>

// Own declarations
#include "general/general.h"
#include "general/general_protocol.h"
#include "general/general_priv.h"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

unsigned long osapi_get_release( void )
{
  return (unsigned long) osapi_release;
}

unsigned long osapi_get_version( void )
{
  return (unsigned long) osapi_version;
}

int osapi_get_version_stability( void )
{
  return OSAPI_VERSION_QUALITY;
}


const char * osapi_get_release_string( void )
{
  return osapi_release_string[ 0 ];	// There is only one member in the array
}


const char * osapi_get_version_string( void )
{
  return osapi_version_string[ 0 ];	// There is only one member in the array
}


const char * osapi_get_version_stability_string( void )
{
  return osapi_version_quality_string[ OSAPI_VERSION_QUALITY ];
}


const char * osapi_get_protocol_string( t_protocol id )
{
  return osapi_protocol_string[ id ];
}


// Module related functions

const char * osapi_module_get( t_module module )
{
  if( general_is_valid_module( module ) )
      return osapi_module_name_string[ module ];
  else
      return OSAPI_EMPTY_STRING;
}


bool osapi_endian_isLittle( void )
{
  unsigned int i = 1;
  unsigned char * c = (unsigned char *) &i;

  return (*c == 1);
}


bool osapi_endian_isBig( void )
{
  unsigned int i = 1;
  unsigned char * c = (unsigned char *) &i;

  return (*c == 0);
}


// Disable Clang warning for this specific case
#if OSAPI_COMPILER == OSAPI_COMPILER_CLANG
 #pragma clang diagnostic push
 #pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

void osapi_trace( const char * func, const char * sep, uint64_t line, const char * fmt, ... )
{
  va_list args;

  fprintf( stderr, "%s%s%" PRIu64, func, sep, line );

  va_start(args, fmt );
  vfprintf( stderr, fmt, args );
  va_end(args);

  fprintf( stderr, "\n" );

  fflush( stderr );
}

#if OSAPI_COMPILER == OSAPI_COMPILER_CLANG
 #pragma clang diagnostic pop
#endif
