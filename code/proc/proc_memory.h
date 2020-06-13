// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Proc(ess) module API for memory related functionality
//
// *****************************************************************************************

#ifndef OSAPI_PROC_MEMORY_H_
#define OSAPI_PROC_MEMORY_H_

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
#include "common/types/common_types_memory.h"

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

// + Raw Memory management

/// @brief Allocate memory in the process heap
/// @param [in] size - Required memory size in bytes
/// @param [in] type - How likely is the memory to be reallocated? Hint to the memory manager
/// @param [out] mem - Memory pointer
/// @return Operation status
t_status proc_rawMemory_allocate	( t_size size,    Byte type, void * mem				);

/// @brief Resize the previously allocated memory in the process heap
/// @param [in]     newSize	- New memory size in bytes
/// @param [in,out] mem		- Memory pointer
/// @return Operation status
t_status proc_rawMemory_reAllocate	( t_size newSize, void * mem 					);

/// @brief Deallocate a previously allocated heap memory block
/// @param [in] mem - Address of the memory to deallocate
/// @return Operation status
t_status proc_rawMemory_deallocate	( void * mem							);

// + Safer Memory management

/// @brief Allocate memory in the process heap
/// @param [in] size - Required memory size in bytes
/// @param [in] type - How likely is the memory to be reallocated? Hint to the memory manager
/// @param [out] mem - Memory descriptor
/// @return Operation status
t_status proc_memory_allocate		( t_size size,    Byte type, t_memory * mem			);

/// @brief Resize the previously allocated memory in the process heap
/// @param [in]     newSize	- New memory size in bytes
/// @param [in,out] mem		- Memory descriptor
/// @return Operation status
t_status proc_memory_reAllocate		( t_size newSize, t_memory * mem 				);

/// @brief Deallocate a previously allocated heap memory block
/// @param [in] location - Address of the new memory block
/// @return Operation status
t_status proc_memory_deallocate		( t_memory * location						);

// Get information
/// @brief Retrieve the total allocated memory size, in bytes
/// @param [in]  mem  - Memory descriptor
/// @param [out] size - Currently allocated memory size in bytes for the provided descriptor
/// @return Operation status
t_status proc_memory_getCapacity	( const t_memory * mem, t_size * size 				);

/// @brief Get the raw memory address for the given memory descriptor
/// @param [in]  mem	- Memory descriptor
/// @param [out] data	- Raw memory address (data contents)
/// @return Operation status
t_status proc_memory_getData		( const t_memory * mem, void **  data				);

// Copy between memory areas
/// @brief Copy between two memories using memory descriptors
/// @param [in]  source - Memory to be copied
/// @param [out] target - Destination of the copy
/// @return Operation status
t_status proc_memory_copy		( const t_memory * source,                    t_memory * target	);

/// @brief Copy from a memory descriptor into a raw memory
/// @param [in]  source		- Memory to be copied
/// @param [in]  targetSize	- Size of the allocated memory destination
/// @param [out] target		- Destination of the copy
/// @return Operation status
t_status proc_memory_copyFrom		( const t_memory * source, t_size targetSize, void     * target	);

/// @brief Copy from a raw source memory into a memory descriptor
/// @param [in]  source		- Raw memory to be copied
/// @param [in]  sourceSize	- Size of the allocated source memory
/// @param [out] target		- Destination of the copy
/// @return Operation status
t_status proc_memory_copyTo		( const void     * source, t_size sourceSize, t_memory * target	);


#pragma GCC visibility pop			// End of public interface


///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif

#endif /* OSAPI_PROC_MEMORY_H_ */
