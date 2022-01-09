// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Visual Studio compiler definitions
//		The purpose is to generalize compiler definitions
//
// ******************************************************************************************************

#ifndef OSAPI_GENERAL_VSTUDIO_DEFS_H_
#define OSAPI_GENERAL_VSTUDIO_DEFS_H_

// *****************************************************************************************
//
// Section: Generic defines that must present in all C compiler definitions
//
// *****************************************************************************************

// Compiler identification
#define OSAPI_COMPILER 				OSAPI_COMPILER_VSC

#if _MSC_VER >= 1900 && _MSC_VER < 2000
  #define OSAPI_COMPILER_VERSION_MAJOR		( _MSC_VER / 100 )
  #define OSAPI_COMPILER_VERSION_MINOR		( _MSC_VER % 100 )

#else
  #error "Compiler version not yet supported."
#endif


// *****************************************************************************************
//
// Section: Target CPU architecture (to compile to)
//
// *****************************************************************************************

#if defined(_M_I86) || defined(_M_IX86)
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_X86
  #define OSAPI_CPU_ARCHITECTURE_VERSION	_M_IX86					// Needs confirmation

#elif defined _M_AMD64
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_AMD64
  #define OSAPI_CPU_ARCHITECTURE_VERSION	_M_AMD64				// Needs confirmation

#elif defined _M_ALPHA
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_ALPHA
  #define OSAPI_CPU_ARCHITECTURE_VERSION	_M_ALPHA				// Needs confirmation

#elif defined _M_ARM
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_ARM
#define OSAPI_CPU_ARCHITECTURE_VERSION		_M_ARM					// Needs confirmation

#elif defined _M_IA64
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_IA64
  #define OSAPI_CPU_ARCHITECTURE_VERSION	_M_IA64					// Needs confirmation

#elif defined _M_PPC
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_POWERPC
  #define OSAPI_CPU_ARCHITECTURE_VERSION	_M_PPC					// Needs confirmation

#else
  #error "Uknown CPU Architecture"
#endif


// CPU Wordsize
#if defined (_M_AMD64) || defined(_M_IA64) || defined(_M_ALPHA)
  #define OSAPI_CPU_ARCHITECTURE_SIZE		64
#else	// Assume 32 bits
  #define OSAPI_CPU_ARCHITECTURE_SIZE		32
#endif


// *****************************************************************************************
//
// Section: Generic attributes that must present in all C compiler definitions
//
// *****************************************************************************************

#define OSAPI_ATTRIBUTE_NOINLINE			__declspec(noinline)
#define OSAPI_ATTRIBUTE_ALWAYS_INLINE		__forceinline




#endif // OSAPI_GENERAL_VSTUDIO_DEFS_H_
