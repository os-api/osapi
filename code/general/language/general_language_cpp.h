// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	C++ compiler definitions
//		The purpose is to generalize language definitions
//
// ******************************************************************************************************

#ifndef OSAPI_GENERAL_CPP_DEFS_H_
#define OSAPI_GENERAL_CPP_DEFS_H_

// *****************************************************************************************
//
// Section: Generic defines that must present in all language definitions
//
// *****************************************************************************************

// Assertions
#define osapi_static_assert		static_assert

// Functions that don't return
#define OSAPI_NORETURN	[[noreturn]]


#endif // OSAPI_GENERAL_CPP_DEFS_H_
