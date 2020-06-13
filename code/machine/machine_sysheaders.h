// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_MACHINE_PLATFORM_TYPES_H_
#define OSAPI_MACHINE_PLATFORM_TYPES_H_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import Machine specific types
#include "machine/machine_platform.h"

/* Import system headers */
#ifdef	OS_LINUX
 #include "machine/linux/machine_linux.h"
#endif


#endif /* OSAPI_MACHINE_PLATFORM_TYPES_H_ */
