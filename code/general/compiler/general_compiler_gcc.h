// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	GNU compiler definitions
//		The purpose is to generalize compiler definitions
//
// ******************************************************************************************************

#ifndef OSAPI_GENERAL_GNU_DEFS_H_
#define OSAPI_GENERAL_GNU_DEFS_H_

// *****************************************************************************************
//
// Section: Generic defines that must present in all C compiler definitions
//
// *****************************************************************************************

// Compiler identification
#define OSAPI_COMPILER 				OSAPI_COMPILER_GNU
#define OSAPI_COMPILER_VERSION_MAJOR		__GNUC__
#define OSAPI_COMPILER_VERSION_MINOR		__GNUC_MINOR__


// *****************************************************************************************
//
// Section: Target CPU architecture (to compile to)
//
// *****************************************************************************************

#ifdef __i386__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_X86
  #define OSAPI_CPU_ARCHITECTURE_VERSION	OSAPI_CPU_ARCHITECTURE_INTEL_386	// Default version, see bellow

#elif defined __amd64__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_AMD64
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__amd64__				// Needs confirmation

#elif defined __alpha__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_ALPHA
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__alpha__				// Needs confirmation

#elif defined __arm__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_ARM
#define OSAPI_CPU_ARCHITECTURE_VERSION		__arm__					// Needs confirmation

#elif defined __hppa__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_HPRISC
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__hppa__				// Needs confirmation

#elif defined __ia64__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_IA64
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__ia64__				// Needs confirmation

#elif defined __mips__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_MIPS
  #define OSAPI_CPU_ARCHITECTURE_VERSION	_MIPS_ISA				// Needs confirmation

#elif defined __powerpc__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_POWERPC
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__powerpc__				// Needs confirmation

#elif defined __sparc__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_SPARC
  #define OSAPI_CPU_ARCHITECTURE_VERSION	OSAPI_CPU_ARCHITECTURE_SPARC_V9		// Default version
#endif


// Intel CPU architecture version verification
#ifdef __i486__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	OSAPI_CPU_ARCHITECTURE_INTEL_486
#elif defined __i586__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	OSAPI_CPU_ARCHITECTURE_INTEL_586
#elif defined __i686__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	OSAPI_CPU_ARCHITECTURE_INTEL_686
#endif

// SPARC CPU architecture version verification
#ifdef __sparc_v8__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	OSAPI_CPU_ARCHITECTURE_SPARC_V8
#endif

// CPU Wordsize
#if defined (__x86_64__) || defined(__powerpc64__) || defined(__ia64__) || defined(__aarch64__) || defined(__amd64__) || defined(__sparc_v9__) || defined(__alpha__)
  #define OSAPI_CPU_ARCHITECTURE_SIZE		64
#else
  #define OSAPI_CPU_ARCHITECTURE_SIZE		32
#endif



// *****************************************************************************************
//
// Section: Generic attributes that must present in all C compiler definitions
//
// *****************************************************************************************

// inline is already part of the C11 Standard
#define OSAPI_ATTRIBUTE_NOINLINE		__attribute__((noinline))
#define OSAPI_ATTRIBUTE_ALWAYS_INLINE	__attribute__((always_inline))





#endif // OSAPI_GENERAL_COMPILER_GNU_DEFS_H_
