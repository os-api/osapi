// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Linux baseline specification
//
// *****************************************************************************************



#ifndef OSAPI_GENERAL_BASELINE_LIBRARY_H_
#define OSAPI_GENERAL_BASELINE_LIBRARY_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include First the most generic UNIX information
#include "general/general_library.h"

// Include platform available version information
#include <gnu/libc-version.h>		// Needs to be here in the Linux baseline


// *****************************************************************************************
//
// Section: Platform Baseline definition
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_LIBC_DISABLE

  osapi_static_assert( OSAPI_LIBRARY_MAJOR_VERSION >= OSAPI_BASELINE_TARGET_MAJOR_VERSION_LIBC,	"Baseline error: C library major version bellow baseline" );
  osapi_static_assert( OSAPI_LIBRARY_MINOR_VERSION >= OSAPI_BASELINE_TARGET_MINOR_VERSION_LIBC,	"Baseline error: C library minor version bellow baseline" );

#else	// Baseline is off, so LibC version is irrelevant
  // Set a very high number so as to succeed in runtime version comparison
  #define OSAPI_LIBC_MAJOR_VERSION	9999
  #define OSAPI_LIBC_MINOR_VERSION	9999

#endif	// If standard C library baseline is not disabled

#endif /* OSAPI_GENERAL_BASELINE_LIBRARY_H_ */
