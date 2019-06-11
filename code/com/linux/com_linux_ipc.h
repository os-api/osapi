// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC Linux OS declarations
//
// *****************************************************************************************

#ifndef OSAPI_COM_IPC_LINUX_H_
#define OSAPI_COM_IPC_LINUX_H_

// Only relevant is OS is Linux
#ifdef OS_LINUX

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

union semun_linux
{
 int              	val;    /* Value for SETVAL */
 struct semid_ds *	buf;    /* Buffer for IPC_STAT, IPC_SET */
 unsigned short  *	array;  /* Array for GETALL, SETALL */
 struct seminfo  *	__buf;  /* Buffer for IPC_INFO  (Linux specific) */
};

/* Use Linux instead of Posix type definition if compiling in Linux */

typedef union semun_linux	t_semun;

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif	// End of OS Linux

#endif /* OSAPI_COM_IPC_LINUX_H_ */
