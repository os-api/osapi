// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC platform OS selection file
//
// *****************************************************************************************

#ifndef IPC_IPC_PLATFORM_H_
#define IPC_IPC_PLATFORM_H_

/* Import OS specific definitions */
#ifdef OS_LINUX
	#include <ipc/posix/ipc_posix.h>
	#include <ipc/linux/ipc_linux.h>
#endif


#endif /* IPC_IPC_PLATFORM_H_ */
