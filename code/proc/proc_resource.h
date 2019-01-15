// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API
//
// *****************************************************************************************

#ifndef OSAPI_PROC_RESOURCE_H_
#define OSAPI_PROC_RESOURCE_H_

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

// Common includes
#include "common/types/common_types.h"

// Own declarations
#include "proc/proc_types.h"
#include "proc/proc_platform.h"


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup PROC
/// @brief The process management module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: Proc(ess) module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

// + Memory management

/// @brief Allocate memory in the process heap
/// @param [in] size - Required memory size
/// @param [out] location - Address of the new memory block
/// @return Operation status
t_status proc_memory_allocate( t_size size, void ** location );

/// @brief Deallocate a previously allocated heap memory block
/// @param [in] location - Address of the new memory block
/// @return Operation status
t_status proc_memory_deallocate( void * location );

/// @brief Clear contents of memory block
/// @param [in] size - How many bytes have to be cleared
/// @param [out] location - Starting address of memory to clear
/// @return Operation status
t_status proc_memory_clear( t_size size, void * location );

// + Process general information
/// @brief Obtain raw process information
/// This is the function call that allows clients to make a single call and obtain all raw process data
/// @param [in] pid - Process ID
/// @param [out] procInfo - Process information
/// @return Operation status
t_status proc_info_get( t_pid pid, t_proc_info * procInfo );

// + Consumption monitoring
/// @brief Get the size of the process virtual memory
/// @param [in] pid - Process ID
/// @param [out] size - Virtual memory size in bytes
/// @return Operation status
t_status proc_usage_getVirtualMemory( t_pid pid, t_size * size );

/// @brief Get the size of the process real memory, i.e. ram usage
/// @param [in] pid - Process ID
/// @param [out] size - Real memory size in bytes
/// @return Operation status
t_status proc_usage_getRealMemory( t_pid pid, t_size * size );

/// @brief Get the process CPU consumption (summary of user and system)
/// @param [in] pid - Process ID
/// @param [out] size - Percentage of consumed process CPU
/// @return Operation status
t_status proc_usage_getCPU( t_pid pid, t_size * size );

/// @brief Get the number of process kernel threads / LWPs
/// @param [in] pid - Process ID
/// @param [out] number - Number of process threads
/// @return Operation status
t_status proc_usage_getThreads( t_pid pid, t_size * number );

/*
t_status	proc_usage_getIO
t_status	proc_usage_getNetwork
 */


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_RESOURCE_H_ */
