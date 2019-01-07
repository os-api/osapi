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


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup IPC
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: IPC module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @fn t_status ipc_module_supported( void )
/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status	ipc_module_supported	( void								);

// Functions dealing with semaphores
/// @fn t_status ipc_semaphore_create( key_t key, int sem_value, int sem_options, int * semid )
/// @brief Create an IPC semaphore
/// @param in Semaphore key
/// @param in Semaphore value
/// @param in Semaphore options
/// @param out Semaphore ID
/// @return Operation status
t_status	ipc_semaphore_create	( key_t key, int sem_value, int sem_options, int * semid	);

/// @fn t_status ipc_semaphore_destroy( int semid )
/// @brief Destroys the semaphore identified by <semid>
/// @param in Semaphore ID
/// @return Operation status
t_status	ipc_semaphore_destroy	( int semid							);

/// @fn t_status ipc_semaphore_open( key_t key, int * p_semid )
/// @brief Returns the semaphore ID for the provided sempahore key
/// @param in Semaphore key
/// @param out Semaphore ID
/// @return Operation status
t_status	ipc_semaphore_open	( key_t key, int * p_semid 					);

/// @fn t_status ipc_semaphore_lock( int semid )
/// @brief Locks a given semaphore
/// @param in Semaphore ID
/// @return Operation status
t_status	ipc_semaphore_lock	( int semid 							);

/// @fn t_status ipc_semaphore_unlock( int semid )
/// @brief Unlocks a given semaphore
/// @param in Semaphore ID
/// @return Operation status
t_status	ipc_semaphore_unlock	( int semid 							);

/// @fn t_status ipc_semaphore_getValue( int semid, int * p_value )
/// @brief Obtains the semaphore value that corresponds to the given ID
/// @param in Semaphore ID
/// @param out Semaphore value
/// @return Operation status
t_status	ipc_semaphore_getValue	( int semid, int * p_value					);


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_IPC_H_ */
