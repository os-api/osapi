// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common Linux OS declarations
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_TYPES_LINUX_H_
#define OSAPI_COMMON_TYPES_LINUX_H_

// Only relevant is OS is Linux
#ifdef OS_LINUX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include first the more general POSIX header
#include <common/posix/common_posix_types.h>

// Import Linux specific system headers
#define	__USE_MISC	1	// To select the inclusion of required symbols on the next header
#include <net/if.h>


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************

#define OSAPI_INTERFACE_MAX_NAME_SIZE		(IF_NAMESIZE + 1)


// *****************************************************************************************
//
// Section: Type definitions
//
// *****************************************************************************************


#endif	// OS Linux

#endif /* OSAPI_COMMON_TYPES_LINUX_H_ */
