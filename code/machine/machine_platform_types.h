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

/* Import OS specific definitions */
#ifdef	OS_LINUX
 #include "machine/linux/machine_linux_types.h"
#endif


#endif /* OSAPI_MACHINE_PLATFORM_TYPES_H_ */
