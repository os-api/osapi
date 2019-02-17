// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc Module Linux header
//
// *****************************************************************************************

#ifndef OSAPI_PROC_LINUX_H_
#define OSAPI_PROC_LINUX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// Only relevant is OS is POSIX compliant
#ifdef OS_LINUX


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Force baseline before system headers
#include "general/general_baseline.h"

// System includes
#include <sys/types.h>
#include <sys/wait.h>

// Import own headers
#include "proc/linux/proc_linux_types.h"

// *****************************************************************************************
//
// Section: Function declaration
//
// *****************************************************************************************

t_status proc_status_get	( t_pid, t_pid *, t_proc_status *	);


#endif	// OS_LINUX

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_LINUX_H_ */
