// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clang compiler definitions
//		The purpose is to generalize compiler definitions
//
// ******************************************************************************************************

#ifndef OSAPI_GENERAL_CLANG_DEFS_H_
#define OSAPI_GENERAL_CLANG_DEFS_H_

// *****************************************************************************************
//
// Section: Generic defines that must present in all C compiler definitions
//
// *****************************************************************************************

// Compiler identification
#define OSAPI_COMPILER 				OSAPI_COMPILER_CLANG
#define OSAPI_COMPILER_VERSION_MAJOR		__clang_major__
#define OSAPI_COMPILER_VERSION_MINOR		__clang_minor__


// *****************************************************************************************
//
// Section: Target CPU architecture (to compile to)
//
// *****************************************************************************************

#ifdef __i386__
  #define OSAPI_CPU_ARCHITECTURE_TARGET		OSAPI_CPU_ARCHITECTURE_X86
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__i386__				// Default version

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
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__sparc__				// Needs confirmation
#endif


// Intel CPU architecture version verification
#ifdef __i486__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__i486__
#elif defined __i586__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__i586__
#elif defined __i686__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__i686__
#endif

// SPARC CPU architecture version verification
#ifdef __sparc_v8__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__sparc_v8__
#elif defined __sparc_v9__
  #define OSAPI_CPU_ARCHITECTURE_VERSION	__sparc_v9__
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
// Needs to be verified...
#define OSAPI_ATTRIBUTE_NOINLINE		__attribute__((noinline))
#define OSAPI_ATTRIBUTE_INLINE			__attribute__((noinline))
#define OSAPI_ATTRIBUTE_ALWAYS_INLINE		__attribute__((noinline))


// *****************************************************************************************
//
// Section: Generic macros that must present in all C compiler definitions
//
// *****************************************************************************************

// Overflow macros
#define osapi_number_add( x, y, r )	__builtin_add_overflow( x, y, r )
#define osapi_number_sub( x, y, r )	__builtin_sub_overflow( x, y, r )
#define osapi_number_mul( x, y, r )	__builtin_mul_overflow( x, y, r )

#endif // OSAPI_GENERAL_COMPILER_CLANG_DEFS_H_
