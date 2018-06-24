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

// *****************************************************************************************
//
// Section: Type definitions
//
// Purpose: Define OSAPI wide static information
//
// *****************************************************************************************

// Version string
#define osapi_version_X(a, b, c) [a]=c,

static const char * osapi_version[] =
{
  #include "general/table_version.h"
};

#undef osapi_version_X


// Version stability string
#define osapi_quality_X(a, b, c) [a]=c,

static const char * osapi_version_quality[] =
{
  #include "general/table_version_quality.h"
};

#undef osapi_quality_X


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


