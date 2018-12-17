// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Clock platform OS selection file
//
// *****************************************************************************************

#ifndef CLOCK_PLATFORM_H_
#define CLOCK_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
 #include <clock/linux/clock_linux.h>
#endif

#endif /* CLOCK_PLATFORM_H_ */
