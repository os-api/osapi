// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide IPC (InterProcess Communication) module API
//
// *****************************************************************************************

#ifndef OSAPI_IPC_H_
#define OSAPI_IPC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "ipc/ipc_types.h"
#include "ipc/ipc_platform.h"


// *****************************************************************************************
//
// Section: IPC module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status	ipc_module_supported	( void								);

// Functions dealing with semaphores
t_status	ipc_semaphore_create	( key_t key, int sem_value, int sem_options, int * p_semid	);
t_status	ipc_semaphore_destroy	( int semid							);
t_status	ipc_semaphore_open	( key_t key, int * p_semid 					);
t_status	ipc_semaphore_lock	( int semid 							);
t_status	ipc_semaphore_unlock	( int semid 							);
t_status	ipc_semaphore_getValue	( int semid, int * p_value					);


#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_IPC_H_ */
