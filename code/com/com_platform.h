// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_COM_PLATFORM_H_
#define OSAPI_COM_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef OS_LINUX
	#include "com/posix/com_posix.h"
	#include "com/linux/com_linux.h"
#endif


#endif /* OSAPI_IPC_PLATFORM_H_ */
