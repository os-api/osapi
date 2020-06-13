// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General compiler definitions
//		The purpose is to wrapper compiler definitions to avoid spreading these in every module
//
// ******************************************************************************************************

#ifndef OSAPI_GENERAL_COMPILER_H_
#define OSAPI_GENERAL_COMPILER_H_


// *****************************************************************************************
//
// Section: Define list of compilers
//
// *****************************************************************************************

// List of compilers
#define OSAPI_COMPILER_GNU		1
#define OSAPI_COMPILER_CLANG		2
#define OSAPI_COMPILER_ICC		3	// Intel C Compiler (icc on Linux / icl on Windows
#define OSAPI_COMPILER_VSC		4	// Vistual Studio compiler
#define OSAPI_COMPILER_UNKNOWN		0

// *****************************************************************************************
//
// Section: Define compiler settings
//
// *****************************************************************************************

#ifdef __clang__

// *****************************************************************************************
// CLANG Compiler settings. CLANG must be before GCC since it exports the same gcc macros
// *****************************************************************************************

  #include "general/compiler/general_compiler_clang.h"

// *****************************************************************************************
// GNU Compiler settings
// *****************************************************************************************
#elif __GNUC__

  #include "general/compiler/general_compiler_gcc.h"

#elif _MSC_VER
  #include "general/compiler/general_compiler_msc.h"

#else
  #define OSAPI_COMPILER		OSAPI_COMPILER_UNKNOWN
#endif


#endif /* OSAPI_GENERAL_COMPILER_H_ */
