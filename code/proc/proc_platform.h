// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Proc platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_PROC_PLATFORM_H_
#define OSAPI_PROC_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import Own OS specific definitions */
#ifdef	OS_LINUX
  #include "proc/linux/proc_linux_types.h"
  #include <proc/posix/proc_posix_status.h>
#endif


#endif /* OSAPI_PROC_PLATFORM_H_ */
