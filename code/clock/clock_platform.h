// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_PLATFORM_H_
#define OSAPI_CLOCK_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef	OS_LINUX
 #include "clock/linux/clock_linux.h"
#endif

#endif /* OSAPI_CLOCK_PLATFORM_H_ */
