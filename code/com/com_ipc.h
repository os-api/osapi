// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide IPC (InterProcess Communication) for COM module API
//
// *****************************************************************************************

#ifndef OSAPI_COM_IPC_H_
#define OSAPI_COM_IPC_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import Standard C headers
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "com/com_platform.h"
#include "com/com_types.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup COM
/// @brief The communication module IPC
///@{
///
/// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API for IPC
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// Functions dealing with semaphores

/// @brief Are semaphores supported in this platform ?
/// @return Supported/Unsupported
t_status com_semaphore_supported( void );

/// @brief Create an IPC semaphore
/// @param [in] key - Semaphore key
/// @param [in] sem_value - Semaphore value
/// @param [in] sem_options - Semaphore options
/// @param [out] semid - Semaphore ID
/// @return Operation status
t_status com_semaphore_create( key_t key, int sem_value, int sem_options, int * semid );

/// @brief Destroys the semaphore identified by "semid"
/// @param [in] semid - Semaphore ID
/// @return Operation status
t_status com_semaphore_destroy( int semid );

/// @brief Returns the semaphore ID for the provided semaphore key
/// @param [in] key - Semaphore key
/// @param [out] semid - Semaphore ID
/// @return Operation status
t_status com_semaphore_open( key_t key, int * semid );

/// @brief Locks a given semaphore
/// @param [in] semid - Semaphore ID
/// @return Operation status
t_status com_semaphore_lock( int semid, bool wait );

/// @brief Unlocks a given semaphore
/// @param [in] semid - Semaphore ID
/// @return Operation status
t_status com_semaphore_unlock( int semid, bool wait );

/// @brief Obtains the semaphore value that corresponds to the given ID
/// @param [in] semid - Semaphore ID
/// @param [out] value - Semaphore value
/// @return Operation status
t_status com_semaphore_getValue( int semid, int * value );


#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_COM_IPC_H_ */
