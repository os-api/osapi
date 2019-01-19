// **************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General language definitions
//		The purpose is to wrapper C/C++ definitions to avoid spreading these in every module
//
// **************************************************************************************************

#ifndef GENERAL_LANGUAGE_H_
#define GENERAL_LANGUAGE_H_

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

// Assertions
#define osapi_static_assert		static_assert

// Functions that don't return
#define OSAPI_NORETURN	[[noreturn]]

#elif	defined (__STDC__)			// C code

// *****************************************************************************************
// C definitions
// *****************************************************************************************

#define OSAPI_LANGUAGE			OSAPI_LANGUAGE_C
#define OSAPI_LANGUAGE_VERSION		__STDC_VERSION__

// Assertions
#if __STDC_VERSION__ >= 201112L
  #define osapi_static_assert		_Static_assert
#endif

// Functions that don't return
#define OSAPI_NORETURN	_Noreturn

#else

// *****************************************************************************************
// Unknown language - Exit
// *****************************************************************************************

#error	"Unknown programming language."

#endif	// Language definitions

#endif /* GENERAL_LANGUAGE_H_ */
