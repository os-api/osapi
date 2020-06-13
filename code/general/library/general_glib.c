// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	GNU Library C functions
//		Functions that must work only with the glibc library
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Enforce first the baseline
#include "general/general_baseline.h"

// Include Standard C headers
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Include module declarations
#include "general/general.h"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

#ifdef OS_LINUX

// Check also the Linux kernel? Is it relevant for the baseline or libc is enough?
bool osapi_verify_baseline( void )
{
  char 		p[ 11 ];	// 10 bytes are more than enough
  char 		*i, *s;
  int 		major = -1;
  int 		minor = -1;

  if( strncpy( p, gnu_get_libc_version(), 10 ) != p ) return false;
  p[ 10 ] = '\0';	// Null terminated

  // Get major version from the initial portion of the string
  errno = 0;
  major=atoi(p);
  if( errno != 0 ) return false;

  // Find separator
  errno = 0;
  i = strtok_r( p , ".", &s );				// First call returns the major version token
  if( errno != 0 || i == NULL ) return false;


  i = strtok_r( NULL , ".", &s );			// Second call returns the minor version token
  if( errno != 0 || i == NULL ) return false;

  // Get minor version from respective token
  errno = 0;
  minor = atoi( i );
  if( errno != 0 ) return false;

  // Compare versions
  if( major >= OSAPI_BASELINE_TARGET_MAJOR_VERSION_LIBC )
      if( minor >= OSAPI_BASELINE_TARGET_MINOR_VERSION_LIBC )
	  return true;

  return false;
}

#endif // OS_LINUX
