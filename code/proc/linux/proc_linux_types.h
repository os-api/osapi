// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module linux type declarations
//
// *****************************************************************************************

#ifndef OSAPI_PROC_LINUX_TYPES_H_
#define OSAPI_PROC_LINUX_TYPES_H_

// Only relevant is OS is Linux
#ifdef OS_LINUX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include Linux specific system headers
#include <linux/limits.h>
#include <dlfcn.h>

// Import own headers
#include "proc/posix/proc_posix_types.h"




#endif	// End of OS Linux

#endif /* OSAPI_PROC_LINUX_TYPES_H_ */
