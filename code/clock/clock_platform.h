/*
 * clock_platform.h
 *
 *  Created on: 04/05/2017
 *      Author: joao
 */

#ifndef CLOCK_PLATFORM_H_
#define CLOCK_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
#include <clock/clock_linux.h>
#elif OS_SOLARIS
#include <clock/clock_solaris.h>
#endif

#endif /* CLOCK_PLATFORM_H_ */
