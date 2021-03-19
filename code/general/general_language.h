// **************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General language definitions
//		The purpose is to wrapper C/C++ definitions to avoid spreading these in every module
//
// **************************************************************************************************

#ifndef OSAPI_GENERAL_LANGUAGE_H_
#define OSAPI_GENERAL_LANGUAGE_H_


// *****************************************************************************************
//
// Section: Define list of compilation Languages
//
// *****************************************************************************************

#define OSAPI_LANGUAGE_C		1
#define OSAPI_LANGUAGE_C_PLUS_PLUS	2

// *****************************************************************************************
//
// Section: Define language settings
//
// *****************************************************************************************

#ifdef __cplusplus

// *****************************************************************************************
// C++ definitions
// *****************************************************************************************

#define OSAPI_LANGUAGE			OSAPI_LANGUAGE_C_PLUS_PLUS
#define OSAPI_LANGUAGE_VERSION		__cplusplus

#include "general/language/general_language_cpp.h"

#elif	defined (__STDC__)			// C code

// *****************************************************************************************
// C definitions
// *****************************************************************************************

#define OSAPI_LANGUAGE				OSAPI_LANGUAGE_C
#define OSAPI_LANGUAGE_VERSION		__STDC_VERSION__

#include "general/language/general_language_c.h"

#else

// *****************************************************************************************
// Unknown language - Exit
// *****************************************************************************************

#error	"Unknown programming language."

#endif	// Language definitions

#endif /* OSAPI_GENERAL_LANGUAGE_H_ */
