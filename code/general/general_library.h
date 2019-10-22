// **************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General C library definitions
//
// **************************************************************************************************

#ifndef OSAPI_GENERAL_LIBRARY_H_
#define OSAPI_GENERAL_LIBRARY_H_



// *****************************************************************************************
//
// Section: Define library: GNU LibC
//
// *****************************************************************************************

#ifdef __GLIBC__

  // Map specific libC versions to internal versions
  #define OSAPI_LIBRARY_MAJOR_VERSION			__GLIBC__
  #define OSAPI_LIBRARY_MINOR_VERSION			__GLIBC_MINOR__

  // Define C Library baseline:
  // Need to better fine tune the version according to the required APIs:
  // Support for C11 Threads only appears in version 2.28

  #define OSAPI_BASELINE_TARGET_MAJOR_VERSION_LIBC	2
  #define OSAPI_BASELINE_TARGET_MINOR_VERSION_LIBC	19


// *****************************************************************************************
// Unknown language - Exit
// *****************************************************************************************


#else
  #error	"C Library: Unknown."

#endif	// Language definitions

#endif /* OSAPI_GENERAL_LIBRARY_H_ */
