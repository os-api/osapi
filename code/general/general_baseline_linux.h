// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Linux baseline specification
//
// *****************************************************************************************



#ifndef OSAPI_GENERAL_BASELINE_LINUX_H_
#define OSAPI_GENERAL_BASELINE_LINUX_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include First the most generic UNIX information
#include "general/general_baseline_unix.h"

// Include platform available version information
#include <linux/version.h>
#include <gnu/libc-version.h>

// Include module headers
#include "general/general_language.h"
#include "general/general_library.h"

// *****************************************************************************************
//
// Section: Platform Baseline definition
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_LINUX_DISABLE

// Define OS Baseline
#ifdef 	LINUX_VERSION_CODE
// Need to better fine tune the version according to the required APIs
  osapi_static_assert( LINUX_VERSION_CODE >= KERNEL_VERSION(3,0,0) ,	"Baseline error: Kernel version bellow baseline" );
#else
  #error "Baseline: Linux Kernel information not available"
#endif

#endif	// If linux baseline is not disabled


#ifndef OSAPI_BASELINE_LIBC_DISABLE

  osapi_static_assert( OSAPI_LIBRARY_MAJOR_VERSION >= OSAPI_BASELINE_TARGET_MAJOR_VERSION_LIBC,	"Baseline error: C library major version bellow baseline" );
  osapi_static_assert( OSAPI_LIBRARY_MINOR_VERSION >= OSAPI_BASELINE_TARGET_MINOR_VERSION_LIBC,	"Baseline error: C library minor version bellow baseline" );

#else	// Baseline is off, so LibC version is irrelevant
  // Set a very high number so as to succeed in runtime version comparison
  #define OSAPI_LIBC_MAJOR_VERSION	9999
  #define OSAPI_LIBC_MINOR_VERSION	9999

#endif	// If standard C library baseline is not disabled

#endif /* OSAPI_GENERAL_BASELINE_LINUX_H_ */
