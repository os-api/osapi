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
#include "general/baseline/general_baseline_unix.h"

// Include platform available version information
#include <linux/version.h>

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


#endif /* OSAPI_GENERAL_BASELINE_LINUX_H_ */
