// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	IPC POSIX declarations
//
// *****************************************************************************************

#ifndef OSAPI_COM_IPC_POSIX_H_
#define OSAPI_COM_IPC_POSIX_H_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************


// Compile only if is a POSIX implementation
#ifdef OSAPI_POSIX


// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


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

#endif	// End of POSIX declarations

#endif /* OSAPI_COM_IPC_POSIX_H_ */
