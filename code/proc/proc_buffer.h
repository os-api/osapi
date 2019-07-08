// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API for buffer functionality
//
// *****************************************************************************************

#ifndef OSAPI_PROC_BUFFER_H_
#define OSAPI_PROC_BUFFER_H_

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
#include "common/types/common_types_buffer.h"

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
/// @param [in]  source 	- Address of the source buffer
/// @param [in]  targetSize	- Size of destination memory buffer
/// @param [out] target 	- Raw destination memory address
/// @return Operation status
t_status proc_buffer_copyFrom( const t_buffer * source, t_size targetSize, void * target );

/// @brief Copy from a naked/raw memory into a buffer memory
/// @param [in]  source     - Raw source memory address
/// @param [in]  sourceSize - Size of the source memory content
/// @param [out] target     - Address of the target/destination buffer
/// @return Operation status
t_status proc_buffer_copyTo( const void * source, t_size sourceSize, t_buffer * target );


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_BUFFER_H_ */
