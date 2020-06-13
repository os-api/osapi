// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS (Operating System) module API for CPU information
//
// *****************************************************************************************

#ifndef OSAPI_OS_MEMORY_H_
#define OSAPI_OS_MEMORY_H_

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
#include "common/types/common_type_cpu.h"

// Own declarations


/// *****************************************************************************************
///
///@addtogroup OSAPI
///@{
///@addtogroup OS
/// @brief The Operating System interface module
///@{
///
/// *****************************************************************************************


// *****************************************************************************************
//
// Section: OS module API
//
// *****************************************************************************************

#pragma GCC visibility push(default)		// Start of public interface

/// @brief Get the size of each OS memory page
/// @param [out] size - Size of a memory page
/// @return Operation status
t_status os_memory_getPageSize( uint32_t * size	);

/// @brief Get the number of pages in the memory
/// @param [out] number - Memory pages
/// @return Operation status
t_status os_memory_getNumberOfPages( uint32_t * number	);

/// @brief Get the total memory available to the OS
/// This may not be all machine memory
/// @param [out] size - Size of memory
/// @return Operation status
t_status os_memory_getMax( uint64_t * size	);

#pragma GCC visibility pop			// End of public interface

///@}
///@}

// End of header with C++ declaration
#ifdef __cplusplus
}
#endif


#endif /* OSAPI_OS_MEMORY_H_ */
