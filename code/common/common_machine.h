// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Common (cross module) functions API for User related functionality
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_MACHINE_H_
#define OSAPI_COMMON_MACHINE_H_

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
#include <stdbool.h>

// Generic OSAPI includes
#include "general/general.h"
#include "status/status_types.h"

// Own declarations
#include "common/common_types.h"


// *****************************************************************************************
//
// Section: Common module API
//
// *****************************************************************************************

/// @brief Get the number of online Logical CPUs
/// @param [out] ncpus - Number of Logical CPUs available
/// @return Operation status
t_status common_cpu_getAvailable( t_cpu_nlogical * ncpus	);

/// @brief Get the number of present/configured Logical CPUs
/// @param [out] ncpus - Number of Logical CPUs visible by the OS
/// @return Operation status
t_status common_cpu_getPresent( t_cpu_nlogical * ncpus	);

/// @brief Get the maximum number of Logical CPUs that the OS can address
/// @param [out] ncpus - Number of logical CPUs that can be managed by the OS
/// @return Operation status
t_status common_cpu_getMax( t_cpu_nlogical * ncpus	);

/// @brief Get the size of each OS memory page
/// @param [out] size - Size of a memory page
/// @return Operation status
t_status common_memory_getPageSize( uint32_t * size	);

/// @brief Get the number of pages in the memory
/// @param [out] number - Memory pages
/// @return Operation status
t_status common_memory_getNumberOfPages( uint32_t * number	);

/// @brief Get the total memory available to the OS
/// This may not be all machine memory
/// @param [out] size - Size of memory
/// @return Operation status
t_status common_memory_getMax( uint64_t * size	);

/// @brief Execute the CPUID instruction in Intel/AMD CPU architectures
/// Provides raw access to the underline CPUID instruction
/// @param [in]  op       - Specific operation to execute
/// @param [in]  param    - Parameter to the operation
/// @param [out] regs 	  - CPU registers
int common_asm_cpuid( uint32_t op, uint32_t param,  t_cpu_regs * regs );


// End of header with C++ declaration
#ifdef __cplusplus
 }
#endif


#endif /* OSAPI_COMMON_MACHINE_H_ */
