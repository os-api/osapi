// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General UNIX baseline specification
//
// *****************************************************************************************



#ifndef GENERAL_BASELINE_UNIX_H_
#define GENERAL_BASELINE_UNIX_H_

// Define target UNIX standards
#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE	700

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include platform available standards
#include <unistd.h>

// *****************************************************************************************
//
// Section: Platform Baseline definition
//
// *****************************************************************************************


// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {

   // Define XOPEN && POSIX baselines/constraints
   static_assert( _XOPEN_VERSION == 700,	"Wrong XOPEN version" );
   static_assert( _POSIX_VERSION == 200809L,	"Wrong POSIX version" );

#else	// C Language

   // Define XOPEN && POSIX baselines/constraints
   _Static_assert( _XOPEN_VERSION == 700,	"Wrong XOPEN version" );
   _Static_assert( _POSIX_VERSION == 200809L,	"Wrong POSIX version" );
#endif

// End of header with C++ declaration
#ifdef __cplusplus
  }
#endif

// If compilation reaches this far, them define own POSIX symbol
#define OSAPI_POSIX


#endif /* GENERAL_BASELINE_UNIX_H_ */
