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
#include <common/common_types.h>

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

// Buffer related
/// @brief Allocate memory in the HEAP using a buffer
/// @param [in] bufsize - Size of the buffer to allocate
/// @param [out] buffer - Address of the buffer memory
/// @return Operation status
t_status proc_buffer_allocate( size_t bufsize, t_buffer * buffer );

/// @brief Resize buffer memory
/// @param [in] bufsize - New size of the buffer
/// @param [out] buffer - Address of the buffer memory
/// @return Operation status
t_status proc_buffer_reAllocate( t_size bufsize, t_buffer * buffer );

/// @brief Deallocate buffer memory
/// @param [in] buffer - Address of the buffer memory
/// @return Operation status
t_status proc_buffer_deallocate( t_buffer * buffer );

/// @brief Get the buffer capacity
/// @param [in] buffer - Address of the buffer memory
/// @param [out] size - Buffer capacity
/// @return Operation status
t_status proc_buffer_getCapacity( const t_buffer * buffer, t_size * size );

/// @brief Get the buffer (naked) memory address
/// @param [in] buffer - Address of the buffer memory
/// @param [out] data  - Address of the managed naked/raw HEAP memory
/// @return Operation status
t_status proc_buffer_getData( const t_buffer * buffer, void **  data );

/// @brief Get the current buffer memory usage
/// @param [in] buffer - Address of the buffer memory
/// @param [out] size  - Current memory usage
/// @return Operation status
t_status proc_buffer_getSize( const t_buffer * buffer, t_size * size );

/// @brief Set the current buffer memory usage
/// @param [in] size - New current memory usage
/// @param [out] buffer - Address of the buffer memory
/// @return Operation status
t_status proc_buffer_setSize( t_size size, t_buffer * buffer );

/// @brief Copy two buffer memories
/// Buffers cannot overlap in any way (this generates an error)
/// @param [in] source  - Address of the source buffer
/// @param [out] target - Address of the target/destination buffer
/// @return Operation status
t_status proc_buffer_copy( const t_buffer * source, t_buffer * target );

/// @brief Copy from a buffer to a naked/raw memory location
/// @param [in]  source - Address of the source buffer
/// @param [out] target - Raw destination memory address
/// @return Operation status
t_status proc_buffer_copyFrom( const t_buffer * source, void * target );

/// @brief Copy from a naked/raw memory into a buffer memory
/// @param [in]  source     - Raw source memory address
/// @param [in]  sourceSize - Size of the source memory content
/// @param [out] target     - Address of the target/destination buffer
/// @return Operation status
t_status proc_buffer_copyTo( const void * source, t_size sourceSize, t_buffer * target );


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
