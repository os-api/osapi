/*
 * os_platform.h
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#ifndef OS_OS_PLATFORM_H_
#define OS_OS_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include <os/os_linux.h>
#elif OS_SOLARIS
	#include <os/os_solaris.h>
#endif


#endif /* OS_OS_PLATFORM_H_ */
