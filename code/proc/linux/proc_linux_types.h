// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc module linux type declarations
//
// *****************************************************************************************

#ifndef PROC_PROC_LINUX_TYPES_H_
#define PROC_PROC_LINUX_TYPES_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include Linux specific system headers
#include <linux/limits.h>

// Only relevant is OS is Linux
#ifdef OS_LINUX
 #include "proc/posix/proc_posix_types.h"
#endif	// End of OS Linux


// *****************************************************************************************
//
// Section: Define Linux process related types
//
// *****************************************************************************************


#endif /* PROC_PROC_LINUX_TYPES_H_ */
