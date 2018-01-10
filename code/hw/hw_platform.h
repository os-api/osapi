/*
 * hw_platform.h
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#ifndef HW_HW_PLATFORM_H_
#define HW_HW_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include <hw/hw_linux.h>
#elif OS_SOLARIS
	#include <hw/hw_solaris.h>
#endif


#endif /* HW_HW_PLATFORM_H_ */
