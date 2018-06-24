// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	HW platform OS selection file
//
// *****************************************************************************************

#ifndef HW_HW_PLATFORM_H_
#define HW_HW_PLATFORM_H_

/* Import OS specific definitions */
#ifdef	OS_LINUX
	#include <machine/machine_linux.h>
#elif OS_SOLARIS
	#include <hw/hw_solaris.h>
#endif


#endif /* HW_HW_PLATFORM_H_ */
