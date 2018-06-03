/*
 * hw_platform.h
 *
 *  Created on: 05/05/2017
 *      Author: joao
 */

#ifndef IPC_IPC_PLATFORM_H_
#define IPC_IPC_PLATFORM_H_

/* Import OS specific definitions */
#ifdef OS_LINUX
	#include <ipc/ipc_posix.h>
	#include <ipc/ipc_linux.h>
#endif


#endif /* IPC_IPC_PLATFORM_H_ */
