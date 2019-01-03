// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC platform OS selection file
//
// *****************************************************************************************

#ifndef OSAPI_IPC_PLATFORM_H_
#define OSAPI_IPC_PLATFORM_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

/* Import OS specific definitions */
#ifdef OS_LINUX
	#include <ipc/posix/ipc_posix.h>
	#include <ipc/linux/ipc_linux.h>
#endif


#endif /* OSAPI_IPC_PLATFORM_H_ */
