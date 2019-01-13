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
/// @brief The Inter-Process communication module
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: IPC module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Declares if the module is supported on the current implementation
/// @return SUCCESS or FAILURE
t_status ipc_module_supported( void );

// Functions dealing with semaphores
/// @brief Create an IPC semaphore
/// @param [in] key - Semaphore key
/// @param [in] sem_value - Semaphore value
/// @param [in] sem_options - Semaphore options
/// @param [out] semid - Semaphore ID
/// @return Operation status
t_status ipc_semaphore_create( key_t key, int sem_value, int sem_options, int * semid );

/// @brief Destroys the semaphore identified by "semid"
/// @param [in] semid - Semaphore ID
/// @return Operation status
t_status ipc_semaphore_destroy( int semid );

/// @brief Returns the semaphore ID for the provided semaphore key
/// @param [in] key - Semaphore key
/// @param [out] semid - Semaphore ID
/// @return Operation status
t_status ipc_semaphore_open( key_t key, int * semid );

/// @brief Locks a given semaphore
/// @param [in] semid - Semaphore ID
/// @return Operation status
t_status ipc_semaphore_lock( int semid );

/// @brief Unlocks a given semaphore
/// @param [in] semid - Semaphore ID
/// @return Operation status
t_status ipc_semaphore_unlock( int semid );

/// @brief Obtains the semaphore value that corresponds to the given ID
/// @param [in] semid - Semaphore ID
/// @param [out] value - Semaphore value
/// @return Operation status
t_status ipc_semaphore_getValue( int semid, int * value );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_IPC_H_ */
