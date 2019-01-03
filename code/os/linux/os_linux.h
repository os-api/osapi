// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module declarations for Linux
//
// *****************************************************************************************

#ifndef OSAPI_OS_LINUX_H_
#define OSAPI_OS_LINUX_H_

// Only relevant is OS is Linux
#ifdef OS_LINUX

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import system headers
#include <sys/utsname.h>

// Import own headers
#include "os/linux/os_linux_types.h"
#include "os/posix/os_posix.h"


// *****************************************************************************************
//
// Section: Module Process Linux private declarations
//
// *****************************************************************************************

t_status	os_info_provider_get	( t_osInfo * );





// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif	// End of OS Linux

#endif /* OSAPI_OS_LINUX_H_ */
