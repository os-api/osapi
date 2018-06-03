/*
 * hw.h
 *
 *  Created on: 29/03/2017
 *      Author: joao
 */

#ifndef IPC_IPC_H_
#define IPC_IPC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif


#include <status/status.h>
#include <ipc/ipc_defs.h>
#include <ipc/ipc_platform.h>

#pragma GCC visibility push(default)		// Start of public interface

// Functions bellow
t_status	ipc_module_supported			( void								);

// Functions dealing with semaphores
t_status	ipc_semaphore_create			( key_t key, int sem_value, int sem_options, int * p_semid	);
t_status	ipc_semaphore_destroy			( int semid							);
t_status	ipc_semaphore_open			( key_t key, int * p_semid 					);
t_status	ipc_semaphore_lock			( int semid 							);
t_status	ipc_semaphore_unlock			( int semid 							);
t_status	ipc_semaphore_getValue			( int semid, int * p_value					);


#pragma GCC visibility pop			// End of public interface

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* IPC_IPC_H_ */
