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

// Include platform available standards
#include <linux/version.h>

#include "general/general_language.h"

// *****************************************************************************************
//
// Section: Platform Baseline definition
//
// *****************************************************************************************

// Define OS Baseline
#ifdef 	LINUX_VERSION_CODE
// Need to better fine tune the version according to the required APIs
  osapi_static_assert( LINUX_VERSION_CODE >= KERNEL_VERSION(3,0,0) ,	"Baseline error: Kernel version bellow baseline" );
#else
  #error "Baseline: Linux Kernel information not available"
#endif


// Define C Library baseline
#ifdef __GLIBC__
// Need to better fine tune the version according to the required APIs:
// Support for C11 Threads only appears in version 2.28

  osapi_static_assert( __GLIBC__       >= 2,	"Baseline error: GNU Lib C major version bellow baseline" );
  osapi_static_assert( __GLIBC_MINOR__>= 19,	"Baseline error: GNU Lib C minor version bellow baseline" );
#else
  #error "Baseline: GNU C Library not available"
#endif

#endif /* OSAPI_GENERAL_BASELINE_LINUX_H_ */
