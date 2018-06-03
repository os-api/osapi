/*
 * hw_linux.h
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#ifndef IPC_IPC_LINUX_H_
#define IPC_IPC_LINUX_H_

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


#endif /* IPC_IPC_LINUX_H_ */
