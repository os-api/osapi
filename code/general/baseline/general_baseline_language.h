// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define the C/C++ language baseline
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_BASELINE_LANGUAGE_H_
#define OSAPI_GENERAL_BASELINE_LANGUAGE_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

#include "general/general_language.h"


// *****************************************************************************************
//
// Section: Compiler Baseline definition
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_LANGUAGE_DISABLE

#if ( OSAPI_LANGUAGE == OSAPI_LANGUAGE_C ) && ( OSAPI_LANGUAGE_VERSION < 201112L )
  #error "C language version bellow baseline."
#endif


#if ( OSAPI_LANGUAGE == OSAPI_LANGUAGE_C_PLUS_PLUS ) && ( OSAPI_LANGUAGE_VERSION < 201103L )
  #error "C++ language version bellow baseline."
#endif


#endif	// If baseline language not disabled

#endif /* OSAPI_BASELINE_GENERAL_BASELINE_LANGUAGE_H_ */
