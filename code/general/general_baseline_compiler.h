// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define the compiler baseline
//
// *****************************************************************************************

#ifndef GENERAL_BASELINE_COMPILER_H_
#define GENERAL_BASELINE_COMPILER_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

#include "general/general_language.h"
#include "general/general_compiler.h"


// *****************************************************************************************
//
// Section: Compiler Baseline definition
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_COMPILER_DISABLE

osapi_static_assert( OSAPI_COMPILER != OSAPI_COMPILER_UNKNOWN, 	"Baseline error: Unknown compiler" );

// GNU version 6.5 (at least), supports C11
#if OSAPI_COMPILER == OSAPI_COMPILER_GNU
  osapi_static_assert( OSAPI_COMPILER_VERSION_MAJOR >= 6 , 					" Baseline error: Compiler major version bellow requirements" 	);
  osapi_static_assert( OSAPI_COMPILER_VERSION_MAJOR > 7 || OSAPI_COMPILER_VERSION_MINOR >= 5 , 	" Baseline error: Compiler version bellow requirements" 	);
#elif  OSAPI_COMPILER == OSAPI_COMPILER_CLANG

  // What is the baseline for CLANG?
#endif

#endif	// If compiler baseline is not disabled

#endif /* GENERAL_BASELINE_COMPILER_H_ */
