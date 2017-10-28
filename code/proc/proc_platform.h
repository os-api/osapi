/*
 * proc_platform.h
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#ifndef PROC_PROC_PLATFORM_H_
#define PROC_PROC_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include "../../code/proc/proc_linux.h"
#elif OS_SOLARIS
	#include <proc/proc_solaris.h>
#endif


#endif /* PROC_PROC_PLATFORM_H_ */
