// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common Linux OS declarations
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_LINUX_TYPES_H_
#define OSAPI_MACHINE_LINUX_TYPES_H_

// Only relevant is OS is Linux
#ifdef OS_LINUX

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include System headers
#define	__USE_MISC	1	// To select the inclusion of required symbols on the next header
#include <net/if.h>

// Own headers
#include "machine/posix/machine_posix_types.h"


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************



#endif	// OS Linux

#endif /* OSAPI_MACHINE_LINUX_TYPES_H_ */
