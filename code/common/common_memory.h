// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for buffer functionality
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_MEMORY_H_
#define OSAPI_COMMON_MEMORY_H_

// Make sure that header is easily imported from c++
#ifdef __cplusplus
 extern "C" {
#endif

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include standard headers

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "common/types/common_types_memory.h"


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of internal interface

// Memory allocation related
t_status	common_memory_allocate		( size_t size,    t_memory * p_mem					);
t_status	common_memory_reAllocate	( t_size newSize, t_memory * p_mem 					);
t_status	common_memory_deallocate	( t_memory * p_mem							);

// Get information
t_status	common_memory_getCapacity	( const t_memory * p_mem, t_size * p_size 				);
t_status	common_memory_getData		( const t_memory * p_mem, void **  p_data 				);

// Copy between memory areas
t_status	common_memory_copy		( const t_memory * p_source,                    t_memory * p_target	);
t_status	common_memory_copyFrom		( const t_memory * p_source, t_size targetSize, void     * p_target	);
t_status	common_memory_copyTo		( const void     * p_source, t_size sourceSize, t_memory * p_target	);


#pragma GCC visibility pop			// End of internal interface

// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_MEMORY_H_ */
