// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Common Linux OS declarations
//
// *****************************************************************************************

#ifndef MACHINE_TYPES_LINUX_H_
#define MACHINE_TYPES_LINUX_H_

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
#include "machine/machine_types_posix.h"


// *****************************************************************************************
//
// Section: Macros/Constant definitions
//
// *****************************************************************************************



#endif	// OS Linux

#endif /* MACHINE_TYPES_LINUX_H_ */
