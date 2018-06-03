/*
 * hw_linux.h
 *
 *  Created on: 01/04/2017
 *      Author: joao
 */

#ifndef IPC_IPC_POSIX_H_
#define IPC_IPC_POSIX_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

union semun_posix
{
   int              	val;    /* Value for SETVAL */
   struct semid_ds *	buf;    /* Buffer for IPC_STAT, IPC_SET */
   unsigned short  *	array;  /* Array for GETALL, SETALL */
};

typedef union semun_posix	t_semun_posix;

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* IPC_IPC_POSIX_H_ */
