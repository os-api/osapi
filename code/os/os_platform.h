// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	OS module platform for OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_OS_PLATFORM_H_
#define OSAPI_OS_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include "os/linux/os_linux.h"
#endif


#endif /* OSAPI_OS_PLATFORM_H_ */
