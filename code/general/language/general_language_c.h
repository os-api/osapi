// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	C compiler definitions
//		The purpose is to generalize language definitions
//
// ******************************************************************************************************

#ifndef OSAPI_GENERAL_LANGUAGE_C_H_
#define OSAPI_GENERAL_LANGUAGE_C_H_

// *****************************************************************************************
//
// Section: Generic defines that must present in all language definitions
//
// *****************************************************************************************

// Assertions
#if __STDC_VERSION__ >= 201112L
  #define osapi_static_assert		_Static_assert
#endif

// Functions that don't return
#define OSAPI_NORETURN	_Noreturn


#endif // OSAPI_GENERAL_LANGUAGE_C_H_
